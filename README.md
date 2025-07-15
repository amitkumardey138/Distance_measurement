# Arduino-Based Distance Measurement System

This project is a simple distance measurement system developed as part of the **Measurement and Instrumentation** course. It uses an Arduino Uno, an HC-SR04 ultrasonic sensor, a TP223 capacitive touch sensor, and an I2C 16x2 LCD display to measure and display distances in real time.

---

## Features
- Capacitive touch sensor toggles ON/OFF state
- Ultrasonic sensor measures distance in centimeters
- Real-time distance shown on I2C LCD display
- Debugging output via Serial Monitor

---

## Hardware Required
- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor
- TP223 Capacitive Touch Sensor Module
- I2C 16x2 LCD Display
- Jumper Wires
- Breadboard

---

## Circuit Diagram

![Circuit Diagram](circuit_image.png)

> 📌 **Note**: Ensure the following pin connections:
> - **HC-SR04**: `Trig → D9`, `Echo → D10`
> - **TP223 Touch Sensor**: `OUT → D2`
> - **I2C LCD**: Uses `A4 (SDA)` and `A5 (SCL)` on Arduino Uno

---

## 📄 License

This project is licensed under the **Creative Commons** — you are free to use, modify, and distribute it for educational or non-commercial purposes, with proper attribution.

---

### 👥 Authors

- **Amit Kumar Dey**  
  Student ID: 2102033  
  Department of Electrical and Electronic Engineering  
  Chittagong University of Engineering and Technology (CUET)  

- **Md. Zuhayr Akhtab**  
  Student ID: 2102046  
  Department of Electrical and Electronic Engineering  
  Chittagong University of Engineering and Technology (CUET)

---

© 2025 Amit Kumar Dey and Md. Zuhayr Akhtab. All rights reserved.
