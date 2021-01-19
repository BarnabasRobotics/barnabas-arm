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

void blink(int color) {
  digitalWrite(color,HIGH);
  delay(200);
  digitalWrite(color,LOW);
  delay(200);
}

void loop() {
  baseMotor.write(0);
  blink(greenPin);
  blink(greenPin);
  blink(greenPin);
  
  delay(1000);
  
  baseMotor.write(90);
  blink(yellowPin);
  blink(yellowPin);
  blink(yellowPin);
  
  delay(1000);
  
  baseMotor.write(175);
  blink(redPin);
  blink(redPin);
  blink(redPin);
  
  delay(1000);
  
}
