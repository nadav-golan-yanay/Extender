# Extender

This library provides a simple code for PCA9685PW 16 Channel 12-bit PWM/Servo Driver.
The library based on the `Adafruit_PWMServoDriver` librarry  ---------


**The library is for Arduino and ESP32**

## PCA9685PM

![a014b023-fd83-4ce7-bfb9-290405aad3fb](https://ae01.alicdn.com/kf/S64b630d8040d4b5b90f90b4e7a843e6cX.jpg)

**How to connect it to arduino:**

The PCA9685PM works with I2C serial communication protocol, when connected to **arduino** it needs **5V** and connected to **ESP32** it needs **3.3V**.

Connections:
Gyro | Arduino | ESP32
-----|---------|----
GND  | GND     | GND
VCC  | 5V      | 3V3
SCL  | A5      | 22
SDA  | A4      | 21
V+   | 3.3~6V | 3.3~6V

You may want the I2C scanner from the wire.h examples to check that the conections are correct and the gyro is intact.

## Code:

**`begin()`**


This function **must** be called from `void setup()`. ----------
