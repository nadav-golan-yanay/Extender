#include "Extender.h"

#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

/*int IN1;
int IN2;
int EN;*/

Extender::Extender(){
}

Extender::Extender(int dirA, int dirB, int speed){
  in1 = dirA;
  in2 = dirB;
  en = speed;

  /*Serial.println(IN1);
  Serial.println(IN2);
  Serial.println(EN);

  delay(2000);*/
}

void Extender::begin() {
  // put your setup code here, to run once:
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  Serial.print("in1 = ");  
  Serial.println(in1);
  Serial.print("in2 = ");  
  Serial.println(in2);
  Serial.print("en = ");  
  Serial.println(en);
}

void Extender::ServoWrite(int num, int value) {
  if(value < SERVOMIN)
  {  // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
    if(value < 0) value = 0;
    if(value > 180) value = 180;
    value = map(value, 0, 180, 544,  2400);
  }
  pwm.writeMicroseconds(num, value);
}

void Extender::L925nWrite(int dir, int value) { //DC motor via L982n motor Driver
  Serial.println(in1);
  Serial.println(in2);
  Serial.println(en);
  if (dir > 0){
    pwm.setPWM(in1, 0, 4095);
    pwm.setPWM(in2, 0, 0);
  } else if (dir < 0){
    pwm.setPWM(in1, 0, 0);
    pwm.setPWM(in2, 0, 4095);
  } else if (dir == 0){
    pwm.setPWM(in1, 0, 0);
    pwm.setPWM(in2, 0, 0);
  } else if (dir == 0 && value == 255){
    pwm.setPWM(in1, 0, 4095);
    pwm.setPWM(in2, 0, 4095);
  }
  value = map(value, 0, 255, 0, 4095);
  pwm.setPWM(en, 0, value);
}

void Extender::ESCWrite(int num, int value) { //Drone motors
  if(value < SERVOMIN)
  {  // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
    if(value < 0) value = 0;
    if(value > 180) value = 180;
    value = map(value, 1000, 2000, 544,  2400);
  }
  pwm.writeMicroseconds(num, value);
  //Serial.print(value);
  //Serial.print(" | ");
}
