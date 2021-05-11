#include <Servo.h>

const int leftMotorPin = 11;
const int rightMotorPin = 10;
const int baseMotorPin = 3;
const int clawMotorPin = 9;

char receivedChar;
char str[64];
String receivedStr;
int i;

Servo leftMotor;
Servo rightMotor;
Servo baseMotor;
Servo clawMotor;

void lowerL();

void lowerI();



void moveBaseHome() {
  baseMotor.write(60);
}
  
void moveClawHome() {
  clawMotor.write(0);
}

void moveLeftHome() {
}

void moveRightHome() {
}

void grabMarker() {
   clawMotor.write(180);
   delay(1000);
   baseMotor.write(40);
   rightMotor.write(180);
}


void sweepBase() {
  baseMotor.write(60);
  delay(1000);
  baseMotor.write(85);
  delay(1000);
}

void allGoHome() {
  moveBaseHome();
  moveClawHome();
  moveLeftHome();
  moveRightHome();
}

void setup() {
  // put your setup code here, to run once:
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);
  baseMotor.attach(baseMotorPin);
  clawMotor.attach(clawMotorPin);
  allGoHome();
  Serial.begin(9600);
  Serial.println("The arm is ready for commands:");
 
  
}

void clearString() {
  int i;
  
  for (i=0;i<64;i++) {
    str[i]=0;
  }
}

void receiveString() {
  if (Serial.available()>0) {
    // reset the counter
    i=0;
    // loop here until there is nothing left in the serial port
    while (Serial.available()>0){
      delay(10);
      str[i]=Serial.read();
      i++;   
    }
    Serial.print("I just received: ");
    Serial.println(str);
    
    processString();
  }
}

void readOneCharacter() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    Serial.print("I received: ");
    Serial.println(receivedChar);
  }
}

void processString() {
  receivedStr=str;
  if (receivedStr.equals("HELLO")) {
    Serial.print("I received hello!");
  }
  else {
    Serial.print("I don't know this command: ");
    Serial.println(str);
  }
  clearString();
}

void loop() {
  receiveString();
  
  
  
  
  /*
  allGoHome();
  grabMarker();

  delay(1000);
  clawMotor.write(0);
  delay(1000);
  sweepBase();
  delay(1000);
  clawMotor.write(180);
  delay(1000);
  clawMotor.write(0);
  delay(1000);
  
  */
  
}
