#include <LCD_I2C.h>
// #include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <Servo.h>
#include <Wire.h>


const int soilSensorPin = A0;
const int TrigPin = 9;
const int EchoPin = 10;

const int irSensorPin = 8;
//const int servoMotorPin = 6;
const int ledPin = 13;
int pos;

LCD_I2C lcd(0x27);
Servo servoMotor;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(6);

  lcd.begin();
  lcd.backlight();
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  pinMode(irSensorPin, INPUT);  // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT);   
  
  
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);
  int soilMoisture = analogRead(soilSensorPin);
  float distance1 = getUltrasonicDistance(TrigPin, EchoPin);  // Distance from first ultrasonic sensor
  // float distance2 = getUltrasonicDistance(TrigPin2, EchoPin2);  // Distance from second ultrasonic sensor
  float distanceThreshold = 10.0;  // Set detection range from 0 to 10 cm TRASH RANGE
  if (sensorValue == LOW) {
    Serial.println("Trash detected");
    delay(2000);
    if (soilMoisture > 1000) {
      if(distance1>10)
        {
        servoMotor.attach(6);
        Serial.println("Dry - Sliding to the right");
        lcd.clear();
        lcd.setCursor(6, 0);
        lcd.print("Dry");
        lcd.setCursor(5, 1);
        lcd.print("Waste");
        // servoMotor.write(90);
        // servoMotor.detach();
        // delay(5000);
        
        // servoMotor.attach(6);
        // servoMotor.write(110);
        slideToRight();
        delay(5);
        servoMotor.detach();
        
 

        }
      else {
      Serial.println("Trash can full");
      }
    } else {
      servoMotor.attach(6);
      Serial.println("Wet - Sliding to the left");
      lcd.clear();
      lcd.setCursor(6, 0);
	    lcd.print("Wet");
	    lcd.setCursor(5, 1);
     	lcd.print("Waste");
      slideToLeft();
      delay(5);
      servoMotor.detach();

    }
    Serial.print("Moisture: ");
    Serial.println(soilMoisture);
    Serial.print("Distance: ");
    Serial.print(distance1);
    Serial.println(" cm");
  } else {
    Serial.println("No trash detected");
    lcd.clear();
    lcd.setCursor(2, 0);
	  lcd.print("Wet and Dry");
	  lcd.setCursor(2, 1);
   	lcd.print(" Segregator");
  }
  delay(5000);
  
}

float getUltrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance_cm = duration * 0.0343 / 2.0;  // Use 2.0 for accurate floating-point division
  return distance_cm;
}


void slideToRight() {
  for (pos = 0; pos <= 300; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(9);               
                    // waits 15ms for the servo to reach the position
  }


}


void slideToLeft() {
  for (pos = 230; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servoMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}