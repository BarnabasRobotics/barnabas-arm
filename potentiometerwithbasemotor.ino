/*

Challenge #1: Display voltage (0 to 5) on Serial Monitor using formula
Challenge #2: Display angle from (0 to 179.82) on Serial Monitor
Challenge #3: Control the base servo motor using the dial
Challenge #4: Control two motors at the same time using the dial
*/

#include <Servo.h>

Servo baseMotor;

void setup() {
  Serial.begin(9600);
  baseMotor.attach(9);
}

void loop() {
  float potentiometer;
  potentiometer = analogRead(A0);
  potentiometer = potentiometer * 180;
  potentiometer = potentiometer / 1024;
  

  Serial.println(potentiometer);
  
  baseMotor.write(potentiometer);
  

  delay(100);
  
}
