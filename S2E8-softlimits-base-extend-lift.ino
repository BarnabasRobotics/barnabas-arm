#include <Servo.h>

/*
Challenge #1: Create soft limits for all three motors
Challenge #2: Create program to cycle through all the min and max positions
Challenge #3: Add the mid positions using the math formulas and program the kick to happen at the middle of the base motor.
Challenge #4: Modify program so that the motion only happens if you press a button (4-pin button).
*/

Servo baseMotor;
Servo extendMotor;
Servo liftMotor;

//- soft limits for motors
int baseMotorMin = 0;
int baseMotorMax = 180;
int baseMotorMid = (baseMotorMax - baseMotorMin) / 2;

int extendMotorMax = 150;
int extendMotorMin = 80;
int extendMotorMid = (extendMotorMax - extendMotorMin) / 2;

int liftMotorMax = 180;
int liftMotorMin = 90;
int liftMotorMid = (liftMotorMax - liftMotorMin) / 2;


void setup() {
  baseMotor.attach(9);
  extendMotor.attach(10);
  liftMotor.attach(11);
}

void loop() {
  baseMotor.write(baseMotorMin);
  delay(1000);
  baseMotor.write(baseMotorMax);
  delay(1000);
  baseMotor.write(baseMotorMid);
  delay(1000);
  
  extendMotor.write(extendMotorMin);
  delay(1000);
  extendMotor.write(extendMotorMax);
  delay(1000);
  
  liftMotor.write(liftMotorMin);
  delay(1000);
  liftMotor.write(liftMotorMax);
  delay(1000);
  

  
  
  

}
