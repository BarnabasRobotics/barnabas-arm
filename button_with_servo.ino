/*
Challenge 1: Press button -> 45, Don't Press button -> 135
Challenge 2: Press button -> 0, 45, 90, 135, 180 ...  Don't Press button 0
Challenge 3: Press button (2 sec) -> 0 , Press (< 2 sec) -> 90 ... Don't Press button -> 180 

*/

#include <Servo.h>

Servo edMotor;
int edBox;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
  edMotor.attach(9);
}

void loop() {
  
  
  if (digitalRead(2)==LOW) {
    
    delay(2000);
    
    if (digitalRead(2)==LOW) {
      edMotor.write(0);
    }
    else {
      //-do nothing
    }
    
    /*
    //do something
    edBox = 180;
    edMotor.write(edBox);
    delay(1000);
    for (int i=0;i<4;i++) {
      edBox = edBox - 45;
      edMotor.write(edBox);
      delay(1000);
    }
    */
    
  }
  else {
    
    edMotor.write(180);
    
    /*
    edBox = 0;
    edMotor.write(edBox);
    */
    //do something else
  }
}
