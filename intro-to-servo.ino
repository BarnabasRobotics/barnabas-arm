/*
Challenge #1: 0, 45, 90, 135, 180
Challenge #2: Cycle in between 0, 45, 90, 135, 180 (1 second stop at each point)
Challenge #3: Make it move like a windshield wiper
*/

#include <Servo.h>

Servo edMotor;

void setup() {
  pinMode(9,OUTPUT);
  edMotor.attach(9);
  
}

void loop() {
  
  edMotor.write(0);
  delay(1000);
  
  edMotor.write(90);
  delay(1000);
  
  edMotor.write(180);
  delay(1000);
  
  edMotor.write(90);
  delay(1000);
  
}
