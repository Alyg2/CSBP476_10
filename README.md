CSBP476 Line-Following Robot
Project Description
This project aims to build a robot that follows a black line on a white surface using infrared sensors. The robot should detect the line and adjust its path by turning left or right as needed.
Current Issue
The robot currently only moves straight and does not follow the line or turn left/right. This suggests a problem with the sensor logic or motor control implementation.
Troubleshooting Attempts

Checked sensor readings via Serial Monitor to ensure they detect the line.
Adjusted motor speed values to initiate turns.
Verified hardware connections (sensors and motors).

Flowchart

Video Demonstration
See the robot’s current behavior: YouTube Video Link
Code Overview
The main_code.py file contains the Python script for controlling the robot. It uses sensor inputs to determine movement, but the turning logic is not functioning as intended.
