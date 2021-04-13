#include <Servo.h>

/*
Challenge #1: Move arm so that it is pointing south, fully retracted, and fully lowered, claw is fully open
Challenge #2: Move arm to move to object, grab it, and pull it all the way back
Challenge #3: Move the object all the way to the north direction
Challenge #4: Move it and make it is still standing when you let go
*/

Servo baseMotor;
Servo extendMotor;
Servo liftMotor;
Servo clawMotor;

//- soft limits for motors
int baseMotorMin = 0;
int baseMotorMax = 180;
int baseMotorMid = ((baseMotorMax - baseMotorMin) / 2) + baseMotorMin;

int extendMotorMax = 150;
int extendMotorMin = 50;
int extendMotorMid = ((extendMotorMax - extendMotorMin) / 2) + extendMotorMin;

int liftMotorMax = 180;
int liftMotorMin = 90;
int liftMotorMid = ((liftMotorMax - liftMotorMin) / 2) + liftMotorMin;

int clawClose = 180;
int clawOpen = 90;

//- speed
int speed = 10;


void setup() {
  baseMotor.attach(9);
  extendMotor.attach(10);
  liftMotor.attach(11);
  clawMotor.attach(6);
  pinMode(2,INPUT_PULLUP);
  
  Serial.begin(9600);
  
  //homePosition();
  
  delay(1000);
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
    //- after the button is pressed, just wait here for 3 seconds
    //- then continue
    delay(3000);
  }
}

void loop() {
  
  //- initial position
  baseMotor.write(baseMotorMax);
  delay(1000);
  extendMotor.write(extendMotorMin);
  delay(1000);
  liftMotor.write(liftMotorMin);
  delay(1000);
  clawMotor.write(clawOpen);
  
  //- turn to grab object
  baseMotor.write(baseMotorMid);
  delay(1000);
  
  //- lift arm to get to position
  liftMotor.write(liftMotorMin+50);
  delay(1000);
  
  //- extend the arm
  extendMotor.write(extendMotorMin+90);
  delay(1000);
  
  //-grab the object
  clawMotor.write(clawClose);
  delay(1000);
  
  extendMotor.write(extendMotorMin);
  delay(1000);
  
  //-move object to north direction
  baseMotor.write(baseMotorMin);
  delay(1000);
  
  //-let go of the object
  clawMotor.write(clawOpen);
  delay(1000);

  
  
  while (1) {
    //-do nothing
  }
  
  /*clawMotor.write(clawOpen);
  delay(1000);
  clawMotor.write(clawClose);
  delay(1000);
*/
}
