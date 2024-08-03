# Extender

This library provides simple code for the PCA9685 16 Channel 12-bit PWM/Servo Driver. The library is based on the Adafruit_PWMServoDriver. You must have this library installed on your computer!

**The library is for Arduino and ESP32.**

## PCA9685

![PCA9685 Image](https://ae01.alicdn.com/kf/S64b630d8040d4b5b90f90b4e7a843e6cX.jpg)

**How to connect it to Arduino:**

The PCA9685 works with the I2C serial communication protocol. When connected to an Arduino, it needs 5V, and when connected to an ESP32, it needs 3.3V.

Connections:
| PCA9685 | Arduino | ESP32 |
| ---- | ------- | ----- |
| GND  | GND     | GND   |
| VCC  | 5V      | 3V3   |
| SCL  | A5      | 22    |
| SDA  | A4      | 21    |
| V+   | 5V~6V  | 6V~6V|

You may want to use the I2C scanner from the wire.h examples to check that the connections are correct and the gyro is intact.

## Code:

### Constructors

#### **`Extender()`**

This is the default constructor.

#### **`Extender(int _in1, int _in2, int _en)`**

This constructor defines motor pins. If you want to use the DC motors function (`L925nWrite`), use this constructor.
- _in1: The **IN1** pin that is connected to the L928n.
- _in2: The **IN2** pin that is connected to the L928n.
- _en: The **EN** pin that is connected to the L928n.

### Begin

#### **`begin()`**

This function **must** be called from `void setup()`.

### Functions

#### **`ServoWrite(int num, int value)`**

- num: The first integer is the number of the port that the servo is connected to.
- value: The second integer is the value that you want to write to the servo.

  This function writes an angle to a servo.
  

#### **`ESCWrite(int num, int value)`**

- num: The first integer is the number of the port that the motor is connected to.
- value: The second integer is the value that you want to write to the motor; this number represents the desired speed of the motor.

This function writes speed to ESC. The motor that you should connect is a brushless motor and ESC (mostly used in drones).


#### **`L925nWrite(int dir, int value)`**

- dir: The direction of the motor.
- value: The speed of the motor (0-255).

| dir | value | outcome  |
| --- | ----- | -------- |
| 1   | x     | Forward  |
| -1  | x     | Backward |
| 0   | 0     | Neutral  |
| 0   | 255   | Brake    |

This function writes speed to the L928n motor driver.
