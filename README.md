# Extender

This library provides simple code for PCA9685 16 Channel 12-bit PWM/Servo Driver.
The library is based on the Adafruit_PWMServoDriver. You must have this library installed on your computer!


**The library is for Arduino and ESP32**

## PCA9685

![a014b023-fd83-4ce7-bfb9-290405aad3fb](https://ae01.alicdn.com/kf/S64b630d8040d4b5b90f90b4e7a843e6cX.jpg)

**How to connect it to arduino:**

The PCA9685PM works with I2C serial communication protocol, When connected to an **Arduino** it needs **5V** and connected to an **ESP32** it needs **3.3V**.

Connections:
Gyro | Arduino | ESP32
-----|---------|----
GND  | GND     | GND
VCC  | 5V      | 3V3
SCL  | A5      | 22
SDA  | A4      | 21
V+   | 3.3~6V | 3.3~6V

You may want to use the I2C scanner from the wire.h examples to check that the conections are correct and the gyro is intact.

## Code:

**`begin()`**

This function **must** be called from `void setup()`.


**`ServoWrite(int num, int value)`**

- num: The first integer is the number of the port that the servo connected to.
- value: The second integer is the value that you want to write to the servo.

  This function write an angle to a servo.
  

**`MotorWrite(int num, int value)`**

- num: The first integer is the number of the port that the motor connected to.
- value: The second integer is the value that you want to write to the motor; this number represents the desired speed that you want the motor.

  This function write speed to a motor. The motor that you should connect is brushless motor and ESC (mostly used in drones)

  
