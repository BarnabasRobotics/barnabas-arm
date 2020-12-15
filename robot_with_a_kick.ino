/*
retract -> 0
extend -> 140

leg kick -> 90
leg lift -> 180

1) Write a function to kick and try it out!
2) Write a function to kick harder and try it out.
3) Move the base motor to 45 degrees, extend out and then kick, and then move the base motor back to 180 degrees and retract.
*/

#include <Servo.h>

Servo baseMotor;
Servo armMotor;
Servo legMotor;

int baseMotorAngle;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  baseMotor.attach(9);
  armMotor.attach(10);
  legMotor.attach(11);
}

void kick() {
  legMotor.write(180);
  delay(500);
  legMotor.write(90);
  delay(500);
}

void kickHard() {
  legMotor.write(180);
  delay(500);
  legMotor.write(0);
  delay(500);
}

void extendRetract() {
  armMotor.write(0);
  delay(1000);
  armMotor.write(140);
  delay(1000);
}

void loop() {
  
  baseMotor.write(45);
  delay(1000);
  
  armMotor.write(0);
  delay(1000);
  
  
  kick();
  delay(1000);
  
  kickHard();
  delay(1000);
  
  baseMotor.write(180);
  delay(1000);
  armMotor.write(140);
  delay(1000);
  
  
  
  /*
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
  */

}
