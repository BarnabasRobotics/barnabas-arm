#include <Servo.h>

Servo baseMotor;
Servo extendMotor;
Servo liftMotor;
Servo clawMotor;

//- soft limits for motors
int baseMotorMin = 0;
int baseMotorMax = 180;
int baseMotorMid = ((baseMotorMax - baseMotorMin) / 2) + baseMotorMin;
int baseMotorPosition = 90;

int extendMotorMax = 150;
int extendMotorMin = 50;
int extendMotorMid = ((extendMotorMax - extendMotorMin) / 2) + extendMotorMin;
int extendMotorPosition = 90;

int liftMotorMax = 180;
int liftMotorMin = 90;
int liftMotorMid = ((liftMotorMax - liftMotorMin) / 2) + liftMotorMin;
int liftMotorPosition = 90;


int clawClose = 180;
int clawOpen = 90;
int clawPosition = 90;

//- speed
int speed = 10;

void clawMoveInc(int incrementAngle) {
  clawPosition = clawPosition + incrementAngle;
  Serial.print("my new claw position is: ");
  Serial.println(clawPosition);
  clawMotor.write(clawPosition); 
}

void baseMoveInc(int incrementAngle) {
  baseMotorPosition = baseMotorPosition + incrementAngle;
  Serial.print("my new base motor position is: ");
  Serial.println(baseMotorPosition);
  baseMotor.write(baseMotorPosition); 
}

void extendMoveInc(int incrementAngle) {
  extendMotorPosition = extendMotorPosition + incrementAngle;
  Serial.print("my new extend motor position is: ");
  Serial.println(extendMotorPosition);
  extendMotor.write(extendMotorPosition); 
}

void liftMoveInc(int incrementAngle) {
  liftMotorPosition = liftMotorPosition + incrementAngle;
  Serial.print("my new lift motor position is: ");
  Serial.println(liftMotorPosition);
  liftMotor.write(liftMotorPosition); 
}


void setup() {
  
  baseMotor.attach(9);
  extendMotor.attach(10);
  liftMotor.attach(11);
  clawMotor.attach(6);
  
  pinMode(2,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  //Serial.println("Hello I am a robot arm.");
  
  while (Serial.available()>0) {
    char myLetter;
    myLetter = Serial.read(); //- read 1 character
    
    Serial.print("I just received: ");
    Serial.println(myLetter);
    
    if (myLetter == '1') {
      //-open the claw
      clawMotor.write(clawOpen);
      Serial.println("opening the claw!");
    }
    if (myLetter == '2') {
      //-close the claw
      clawMotor.write(clawClose);
      Serial.println("closing the claw!");
    }
    if (myLetter == 'q') {
      //-increment move
      clawMoveInc(5);
      Serial.println("inc mode move 5!");
    }
    if (myLetter == 'w') {
      clawMoveInc(-5);
      Serial.println("inc mode move -5!");
    }
    
    
    
    
    if (myLetter == 'a') {
      baseMotor.write(baseMotorMin);
      Serial.println("Moving base motor to min!");
    }
    if (myLetter == 'b') {
      baseMotor.write(baseMotorMid);
      Serial.println("Moving base motor to mid!");
    }
    if (myLetter == 'c') {
      baseMotor.write(baseMotorMax);
      Serial.println("Moving base motor to max!");
    }
    if (myLetter == 'o') {
      baseMoveInc(5);
    }
    if (myLetter == 'p') {
      baseMoveInc(-5);
    }
    
    if (myLetter == '5') {
      liftMotor.write(liftMotorMin);
      Serial.println("Moving lift motor to min!");
    }
    if (myLetter == '6') {
      liftMotor.write(liftMotorMid);
      Serial.println("Moving lift motor to mid!");
    }
    if (myLetter == '7') {
      liftMotor.write(liftMotorMax);
      Serial.println("Moving lift motor to max!");
    }
    if (myLetter == 'n') {
      liftMoveInc(5);
    }
    if (myLetter == 'm') {
      liftMoveInc(-5);
    }
    
    if (myLetter == 'z') {
      extendMoveInc(5);
    }
    
    if (myLetter == 'x') {
      extendMoveInc(-5);
    }
    
    
    
  }
  
  delay(100);
}
