/*
retract -> 0
extend -> 140
*/

#include <Servo.h>

Servo baseMotor;
Servo armMotor;

int baseMotorAngle;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  baseMotor.attach(9);
  armMotor.attach(10);
}

void extendRetract() {
  armMotor.write(0);
  delay(1000);
  armMotor.write(140);
  delay(1000);
}

void loop() {
  
  baseMotorAngle = 0;
  baseMotor.write(baseMotorAngle);
  delay(1000);
  extendRetract();
  
  for (int i = 0 ; i < 4; i++) {
    baseMotorAngle = baseMotorAngle + 45;
    baseMotor.write(baseMotorAngle);
    delay(1000);
    extendRetract();
  }

}
