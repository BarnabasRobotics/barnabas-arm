#include <Servo.h>

/*
Challenge #1: Add home position function
Challenge #2: Add emergency stop so that it stops right away
Challenge #3: Add emergency stop so that it stops right away, and then starts again in 3 seconds
*/

Servo baseMotor;
Servo extendMotor;
Servo liftMotor;

//- soft limits for motors
int baseMotorMin = 0;
int baseMotorMax = 180;
int baseMotorMid = ((baseMotorMax - baseMotorMin) / 2) + baseMotorMin;

int extendMotorMax = 150;
int extendMotorMin = 80;
int extendMotorMid = ((extendMotorMax - extendMotorMin) / 2) + extendMotorMin;

int liftMotorMax = 180;
int liftMotorMin = 90;
int liftMotorMid = ((liftMotorMax - liftMotorMin) / 2) + liftMotorMin;

//- speed
int speed = 25;


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
  checkEmergencyStop();
  
  //- moves base motor CCW
  for (int i = baseMotorMin; i<baseMotorMax; i++) {
    baseMotor.write(i);
    checkEmergencyStop();
    Serial.println(i);
    delay(speed);
  }
  
  //- moves base motor CW
  for (int i = baseMotorMax; i>baseMotorMin; i--) {
    baseMotor.write(i);
    checkEmergencyStop();
    Serial.println(i);
    delay(speed);
  }
  
  //- extend motor code
  extendMotor.write(extendMotorMin);
  checkEmergencyStop();
  
  //- moves extend motor out
  for (int i = extendMotorMin; i<extendMotorMax; i++) {
    extendMotor.write(i);
    checkEmergencyStop();
    Serial.println(i);
    delay(speed);
  }
  
  //- moves extend motor in
  for (int i = extendMotorMax; i>extendMotorMin; i--) {
    extendMotor.write(i);
    checkEmergencyStop();
    Serial.println(i);
    delay(speed);
  }
  
  
  //- lift motor code
  liftMotor.write(liftMotorMin);
  checkEmergencyStop();
  
  //- moves lift motor out
  for (int i = liftMotorMin; i<liftMotorMax; i++) {
    liftMotor.write(i);
    checkEmergencyStop();
    Serial.println(i);
    delay(speed);
  }
  
  //- moves lift motor in
  for (int i = liftMotorMax; i>liftMotorMin; i--) {
    liftMotor.write(i);
    checkEmergencyStop();
    Serial.println(i);
    delay(speed);
  }
  

}

void homePosition() {
  baseMotor.write(baseMotorMid);
  extendMotor.write(extendMotorMid);
  liftMotor.write(liftMotorMid);
  checkEmergencyStop();
}

void checkEmergencyStop() {
  if (digitalRead(2)==LOW) {
    while (true) {
      //- do nothing
    }
  }
}

void loop() {
  
  homePosition();

  delay(1000);
  
  slowRoutine();
  
}
