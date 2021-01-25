/*
Challenges
1) Create variables for each color pin
2) Blink Green, Red and then Yellow
3) Do challenge 2 but using the blink function that includes a parameter
4) Blink 10 x at each angle (0, 90, 180)
5) Do challenge 4 but with for loops.
*/

#include <Servo.h>

int redPin = 6;
int greenPin = 7;
int yellowPin = 8;
int baseMotorPin = 9;

Servo baseMotor;

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  
  pinMode(baseMotorPin,OUTPUT);
  baseMotor.attach(baseMotorPin);
}

//- parameter
void blink(int color) {
  digitalWrite(color, HIGH);
  delay(200);
  digitalWrite(color,LOW);
  delay(200);
}


void loop() {
  
  //- go to angle 0
  baseMotor.write(0);
  
  for (int i=0;i<20;i++) {
    blink(greenPin);
  } 
  
  //- go to angle 90
  baseMotor.write(90);
  
  
  for (int i=0;i<20;i++) {
    blink(redPin);
  }
  
  //- got to angle 180
  baseMotor.write(180);
  
  for (int i=0;i<20;i++) {
    blink(yellowPin);
  }
  
}
