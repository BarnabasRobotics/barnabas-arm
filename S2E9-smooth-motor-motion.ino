#include <Servo.h>

/*
Challenge #1: Move base motor slowly back and forth
Challenge #2: Move extend motor slowly back and forth
Challenge #3: Move lift motor slowly back and forth 
Challenge #4: Move fast or slow based on button press
Challenge #5: Cause motors to move slowly right when you press the button so that you don't need to wait.
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

//- speed
int speed = 0;


void setup() {
  baseMotor.attach(9);
  extendMotor.attach(10);
  liftMotor.attach(11);
  pinMode(2,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void routine() {
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

void slowRoutine() {
  
  
  baseMotor.write(baseMotorMin);
  
  //- moves base motor CCW
  for (int i = baseMotorMin; i<baseMotorMax; i++) {
    baseMotor.write(i);
    Serial.println(i);
    delay(speed);
  }
  
  //- moves base motor CW
  for (int i = baseMotorMax; i>baseMotorMin; i--) {
    baseMotor.write(i);
    Serial.println(i);
    delay(speed);
  }
  
  //- extend motor code
  extendMotor.write(extendMotorMin);
  
  //- moves extend motor out
  for (int i = extendMotorMin; i<extendMotorMax; i++) {
    extendMotor.write(i);
    Serial.println(i);
    delay(speed);
  }
  
  //- moves extend motor in
  for (int i = extendMotorMax; i>extendMotorMin; i--) {
    extendMotor.write(i);
    Serial.println(i);
    delay(speed);
  }
  
  
  
  /*
  
  baseMotor.write(baseMotorMin);
  delay(1000);
  baseMotor.write(baseMotorMax);
  delay(1000);
  baseMotor.write(baseMotorMid);
  delay(1000);
  
  */

}

void loop() {
  
  //- when I press the button
  if (digitalRead(2)==LOW) {
    speed = 50;
    slowRoutine();
  }
  else {
    speed = 0;
    slowRoutine();
  }
  
  
  
}
