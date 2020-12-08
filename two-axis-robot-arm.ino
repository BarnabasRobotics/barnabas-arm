/*

Retract - 180 degrees
Extend - 10 degrees

Challenge #1) Find retract & extend angles
Challenge #2) Move between 0, 90, 180 while extended
Challenge #3) Move between 0, 90, 180 while retracted
Challenge #4) Move between 0, 90, 180 with extend / retract
Challenge #5) Trigger motion by button
Challenge #6) Move between 0, 45, 90, 135, 180 with extend / retract
*/

#include <Servo.h>

Servo baseMotor;
Servo armMotor;

void setup() {
  pinMode(2,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  baseMotor.attach(9);
  armMotor.attach(10);
  
}

void loop() {
  
  if (digitalRead(2)==LOW) {
    //move the motor
    armMotor.write(180);
  
    baseMotor.write(0);
    delay(1000);
    armMotor.write(10);
    delay(1000);
    armMotor.write(180);
    delay(1000);
    
    
    baseMotor.write(90);
    delay(1000);
    armMotor.write(10);
    delay(1000);
    armMotor.write(180);
    delay(1000);
    
    
    baseMotor.write(180);
    delay(1000);
    armMotor.write(10);
    delay(1000);
    armMotor.write(180);
    delay(1000);
    
    baseMotor.write(90);
    delay(1000);
    armMotor.write(10);
    delay(1000);
    armMotor.write(180);
    delay(1000);
    
    baseMotor.write(0);
    delay(1000);
    armMotor.write(10);
    delay(1000);
    armMotor.write(180);
    delay(1000);
  
  
  }
  else {
    //do nothing
  }
  
  
  
  
}
