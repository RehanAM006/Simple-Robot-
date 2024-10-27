# Robo Follower

A simple Arduino-based project to create a robotic follower that can follow or avoid a hand based on proximity. The robot uses an ultrasonic sensor for distance measurement, a push button to control activation, RGB LEDs for status indication, and a motor driver to control movement.

## Features
- **Push Button Control**: Change mode.
- **Distance Detection**: Uses an ultrasonic sensor to detect proximity.
- **LED Status Indicator**: RGB LEDs indicate the robot’s state (e.g., evading or following).
- **Motor Control**: Motors are driven to move the robot forward or backward.

## Components Required
- Arduino (any model with sufficient digital pins)
- Ultrasonic sensor (HC-SR04)
- RGB LED (or two separate LEDs if RGB is unavailable)
- Motor driver (L298N or similar)
- Push button
- 4 DC motors
- Wires and power source

## Circuit Diagram
| Component        | Arduino Pin       |
|------------------|-------------------|
| Push Button      | D3                |
| Ultrasonic Echo  | D4                |
| Ultrasonic Trig  | D5                |
| LED Red          | D6                |
| Motor IN1        | D7                |
| Motor IN2        | D8                |
| Motor IN3        | D9                |
| Motor IN4        | D10               |
| LED Blue         | D11               |

## Code Explanation
1. **Push Button**: Reads the state of a button for activation.
2. **Ultrasonic Sensor**: Measures distance to detect obstacles and controls movement.
3. **RGB LEDs**: Shows the robot's status; red indicates "evade" mode, while blue indicates "follow" mode.
4. **Motor Control**: Uses `IN1`, `IN2`, `IN3`, and `IN4` to control two motors for forward and reverse movement.

## Setup Instructions
1. Connect the components to the Arduino following the circuit diagram.
2. Upload the code provided in `Robo_follower.ino` to your Arduino.
3. Power the Arduino and observe the robot's behavior based on proximity.

## Code Snippet

```cpp
// Push Button
#define pushPin  3
int push_button_state = 0;

// Ultrasonic Sensor
#define echo 4
#define trig 5
int distance; // Declare distance globally

// RGB LEDs
#define led_red 6
#define led_blue 11

// Motor Driver Pins
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

// Function declarations and other code logic are included in Robo_follower.ino
