# MOBILE_ROBOT_ARM_MANIPULATOR

## Course Information
**Subject:** Microprocessor and Microcontroller Systems and Design
**Institution:** Batangas State University — TNEU - Alangilan
**School Year:** 2022-2023



## Group Members:
- Alcantara, Charles Vincent H.
- Alcantara, Jensen Dayle C.
- Cueto, Mark Andrey R.
- Evengelista, Bryan D.
- Pineda, Rayniel Lester M.


## Project Overview
This project integrates two robotic systems as part of an academic requirement for Micro and Embedded Systems.

The first system is a mobile robot equipped with an IR (infrared) sensor that automatically stops when an obstacle is detected in front of it. The robot can also be manually controlled using an IR remote, allowing movement in four directions (forward, backward, left, and right), with a dedicated stop button (Play/Pause Button).

The second system is a mechanical manipulator, commonly referred to as a robotic arm. It consists of four servo motors positioned at the base, shoulder, elbow, and end effector. The robotic arm is controlled via a mobile phone connected through Wi-Fi using an ESP32 module.

Both systems are integrated by mounting the robotic arm on the rear of the mobile robot. The objective is to navigate through a maze containing marbles placed at various locations, collect the marbles using the robotic arm, and deposit them into designated paper cups distributed throughout the maze. The system requires two operators—one controlling the mobile robot and the other controlling the robotic arm—making coordination essential. After collecting all marbles, the robot must successfully exit the maze within a specified time limit.


## Project Objectives
- Develop a mobile robot using Arduino, integrated with an infrared sensor for obstacle detection and an additional manual control method.
- Develop a robotic arm capable of picking and placing objects using an ESP32.
- Integrate the mobile robot and robotic arm into a single coordinated system.
- Successfully complete a functional project demonstration.


### Hardware (Mobile Robot)
- Arduino Uno R3
- H-bridge Motor Driver (L298N)
- 4 Batteries (AA)
- Ultrasonic Distance Sensor
- IR Sensor
- 2 Hobby Gearmotor

### Hardware (Robot Arm)
- ESP32
- 4 Servomotor

**Note:** The robot casings were designed using SOLIDWORKS and 3D printed by our group.






