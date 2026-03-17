# Dual-Joystick Bluetooth Robotic Collector 🤖🔵

A mechatronics project featuring a robotic rover controlled via Bluetooth, designed for precision ball collection, internal storage, and controlled release.

##  Project Overview
This robot integrates embedded software with mechanical engineering to solve a retrieval and storage challenge. It uses **Serial Communication** to receive commands from a mobile app, translating user inputs into complex motor and servo movements.

##  Key Features
* **Precision Steering:** Uses a **Dual-Joystick (Dual-Pad) interface**. One vertical axis for forward/backward movement and a separate horizontal axis for independent left/right steering.
* **Variable Speed Control:** Real-time PWM adjustment via an in-app slider for smooth or high-speed navigation.
* **Servo-Actuated Collection:** A dedicated hook system driven by a servomotor to pull objects into the chassis.
* **Automated Storage Gate:** A second independent servo controls a hatch for organized object release.

##  Tech Stack
* **Microcontroller:** Arduino (Atmega328P)
* **Communication:** Bluetooth Module (HC-05/HC-06)
* **Language:** C++ / Arduino Sketch
* **Actuators:** DC Motors (Traction) + 2x Servomotors (Mechanisms)
* **UI:** Custom Mobile App (Joystick & Slider Interface)

##  Repository Structure
* `/firmware`: Main `.ino` or `.cpp` source code for the Arduino.
* `/docs`: Wiring diagrams, circuit schematics, and mechanical design notes.
* `/media`: Photos and videos of the robot in action.

##  How to Run
1.  Upload the code in the `/firmware` folder to your Arduino.
2.  Connect the Bluetooth module to the Serial pins (RX/TX).
3.  Pair your smartphone with the robot and open the controller app.
4.  Use the left pad for drive and the right pad for steering.

---
*Developed as part of my Mechatronics (IFRS) and Computer Science (UFFS) journey.*
