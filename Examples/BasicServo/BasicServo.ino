#include <Extender.h>

Extender servo;

void setup() {
  // put your setup code here, to run once:
  servo.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.ServoWrite(0, 0);
  delay(1000);
  servo.ServoWrite(0, 90);
  delay(1000);
  servo.ServoWrite(0, 180);
  delay(1000);
}
