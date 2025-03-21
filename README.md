# Smart Waste Segregator

## Introduction
The **Smart Waste Segregator** is an innovative solution designed to automate waste management by efficiently segregating waste into distinct categories. This project leverages sensors  to identify and classify waste as wet or dry contributing to a cleaner and more sustainable environment.

## Features
- **Automated Waste Classification**: Uses sensors  to identify waste type.
- **Efficient Sorting Mechanism**: Automatically separates waste into appropriate bins.
- **Eco-Friendly Design**: Promotes sustainable waste management practices.
- **Mobile Application Integration**: Tracks waste levels and alerts when bins are full.

## Components Used
- Arduino 
- Ultrasonic Sensor
- IR Sensor
- Servo Motors
- Moisture sensor

## Libraries Required
Ensure the following libraries are installed for Arduino:
- `IRremote`
- `LCD_I2C`
- `LiquidCrystal`
- `Servo`

## Working Principle
1. **Detection**: The waste is placed on the platform.
2. **Classification**: The sensors classify the waste into wet and dry
3. **Segregation**: Servo motors move the waste to the appropriate bin.
4. **Monitoring**: Ultrasonic sensors measure the bin levels, giving alerts

![image](https://github.com/user-attachments/assets/c8921496-712d-40fa-a3dc-347cd365c510)

## Installation and Setup
1. Clone the repository:
    ```bash
    git clone https://github.com/JyiaJain/smart-waste-segregator.git
    ```
2. Install dependencies:
    ```bash
    pip install -r requirements.txt
    ```
3. Connect the hardware components as per the circuit diagram.
4. Run the application:
    ```bash
    python main.py
    ```

## Usage
- Place waste on the detection platform.
- Alerts when bins are full.

## Future Enhancements
- Implement machine learning algorithms to detect biodegradable, non-biodegradable, or recyclable waste
- Integrate solar power for sustainable operation.
- Expand waste data analytics for environmental insights.

## Contributing
Contributions are welcome! Please fork the repository, create a new branch, and submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).

## Acknowledgments
- Team Members: Likhitha Kc,Jiya Jain
- Special thanks to our mentors and peers for their support.

---
**Contact:** For any inquiries, please reach out at likhithakchiranjeevi@gmail.com kjainjiya04@gmail.com

