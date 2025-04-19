# Line-follower
### **Line Follower Robot 🏎️**

### **Overview**

An autonomous robot powered by an Arduino Mega that follows a black line using two QTR-8 sensor arrays (16 sensors total) and a PID algorithm. It drives with two N20 motors, powered by a 16V 850mAh LiPo battery, showcasing my skills in embedded programming and robotics.

### **Hardware**

**Microcontroller:**  
- Arduino Mega

![Image](https://github.com/user-attachments/assets/7783146d-54a8-4fb7-b2f7-0b544aeee38a)

**Sensors:**  
- 2 QTR-8 sensor arrays (16 infrared sensors total)

![Image](https://github.com/user-attachments/assets/b8b0eb96-c403-4597-8bf3-f333a5a95ff4)

- 2 TCRT5000 sensors


![Image](https://github.com/user-attachments/assets/87a55032-e5e9-4d0d-b26e-08244e6c9386)

- 3 HC-SR04 Ultrasonic Sensor

![Image](https://github.com/user-attachments/assets/b613c182-0e29-486a-b78e-238a48493353)

**Motors:** 
- 2 N20 motors

![Image](https://github.com/user-attachments/assets/9f45f64e-6306-4a94-8cc2-215bacd9cdc5)

**Power Supply:** 
- 16V 850mAh LiPo battery

![Image](https://github.com/user-attachments/assets/999a7abe-62b8-468a-ba88-302c7f93dcc1)

**Motor Driver:**
- Started with the L298 H-bridge then i switched to a dual max14870

![Image](https://github.com/user-attachments/assets/2582827f-f808-4c63-9df8-a22996eb6846)

![Image](https://github.com/user-attachments/assets/498d949f-42a8-4b2b-8a10-59ca6dd600ae)


### **Software**
Language: C++
Environment: Arduino IDE
Algorithm: PID control for precise line tracking
Libraries: QTR Sensors library

### **Mechanical Design on SolidWorks**

The robot's mechanical structure was designed using SolidWorks, leveraging my CSWA certification skills to create a lightweight and efficient chassis. Key design aspects include:

Chassis Design: A compact, rectangular chassis (150mm x 100mm x 50mm) was modeled to house the Arduino Mega, L298 motor driver, and LiPo battery while minimizing weight. The chassis was 3D-printed using PLA for rapid prototyping.

Motor Mounting: The two N20 motors were securely mounted at the rear using custom brackets designed in SolidWorks, ensuring proper alignment for differential drive.

Sensor Placement: The QTR-8 sensor arrays were positioned at the front, 10mm above the ground, with a custom mounting plate to maintain consistent sensor-to-track distance across uneven surfaces.

Below is a screenshot of the 3D model in SolidWorks:

![Image](https://github.com/user-attachments/assets/fc3cf1b2-c106-4563-9cdf-92c1eafd7525)
Mechanical Design using L298 H-bridge

![Image](https://github.com/user-attachments/assets/fe1cf78c-5771-423a-900a-43971c8b5fcc)
Mechanical Design using Dual max14870



### **Features**
- Accurate line tracking with a PID algorithm for smooth navigation.
- Dynamic speed adjustment of N20 motors based on sensor feedback.
- Calibration of QTR-8 sensors for varying track conditions.


### **Evolution and Achievements**
This robot has undergone several upgrades over the past three years, improving its speed, stability, and sensor accuracy. Key milestones include:

- 2022: Initial build with basic line-following capabilities.
- 2023: Optimized PID tuning and upgraded to a 16V LiPo battery for better performance.
- 2024: Enhanced sensor calibration and motor control for sharper turns using the dual max14870.

The robot has competed in various national robotics competitions, achieving:
First Place: 3 times 
Second Place: 2 times

### **Media**
Competition Preparation Videos


Watch my robot in action during preparation for competitions:





Video 1: Testing PID tuning on a practice track for ENSI 2024 (without any condition)


https://github.com/user-attachments/assets/788a56d0-b934-4d62-966a-684a086df3a9

Video 2: Final adjustments before ENIT Robots 2024

https://github.com/user-attachments/assets/c593551d-0183-47d7-a408-2c159b7a5c94

### **Victory Moments**

Photos from my wins at the ENSI Robots 2022 competition:

![Image](https://github.com/user-attachments/assets/1d5bb57a-f4b2-47f3-b076-57121d12c7a7)  ![Image](https://github.com/user-attachments/assets/db6ba8fb-bdd8-4ce8-97bd-2254bace4807)









### **Installation**

1. Clone this repository: git clone https://github.com/sofienbenhamouda/LineFollowingRobot.git
2. Open src/main.ino in the Arduino IDE.
3. Install the required library: QTRSensors (available in the Arduino Library Manager).
4. Connect the hardware as per the schematic in docs/schematics.pdf.
5. Upload the code to your Arduino Mega.

### **Schematic**
![Image](https://github.com/user-attachments/assets/f87c67a6-1f72-4510-a33f-1b9ac16fa90f)




### **Status :**

Project completed (last updated: April 2024).

### **License :**

MIT License


### **Contact :**

📧 sofienbenhamouda.eu@gmail.com

🔗 www.linkedin.com/in/sofien-benhamouda
