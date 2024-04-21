#include "Extender.h"

Extender motor(3, 2, 1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  motor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.L925nWrite(1, 255); //Full speed forward
}
