CSBP476 Line-Following Robot Project

Group ID: YourGroupID

Project Overview

This project involves a line-following robot built for CSBP476 using an Arduino board. The robot is equipped with three infrared (IR) sensors to detect a black line on a white surface and two motor groups (left and right) for movement. The code is written in C++ for Arduino and controls the robot's movement based on sensor inputs.

How It Works





Sensors: Three IR sensors (left, middle, right) detect the line. They output digital values (0 or 1) based on whether they are over the line or not.



Logic:





If the middle sensor is on the line (0) and the side sensors are off (1), the robot moves forward.



If the left sensor is on the line (0) and the right is off (1), the robot turns left.



If the right sensor is on the line (0) and the left is off (1), the robot turns right.



If all sensors are on the line (0), the robot stops.



For any other sensor combination, the robot also stops.



Motors: The left and right motor groups are controlled via PWM pins for speed and direction pins for movement direction.

Challenges





During testing, the robot tended to go straight without properly following the line, suggesting potential issues with sensor calibration or code logic.



There is a typo in the code: pinMode(INffff1, OUTPUT) should likely be pinMode(IN1, OUTPUT), which may prevent the left motor direction pin from being set correctly.

Video Demonstration

Watch the robot in action: https://youtube.com/shorts/PiVRLGi1k5Q?si=JrW1he8t996XInUU






line_follower.ino: Main Arduino code for the robot.



flowchart.png: Flowchart illustrating the tracking logic.



readme.md: This file, providing an overview and documentation of the project.
