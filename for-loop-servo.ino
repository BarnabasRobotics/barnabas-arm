/*

Variables = Box
Value depends on the LAST set value

*/
#include <Servo.h>

Servo edMotor;
int edBox;

void setup() {
  pinMode(9,OUTPUT);
  edMotor.attach(9);
  edBox = 180; 
  
}

void loop() {

  edBox = 0; 
  edMotor.write(edBox);
  delay(1000);
  
  //- for loop
  for (int i = 0; i < 2; i++) {
    edBox = edBox + 45;
    edMotor.write(edBox);
    delay(1000);
  }
  
  /** Challenges 
   *  1) What should we change (i < 2) to if we want it to just go to 135 and then come back.
   *  2) If I want to change the speed so that it is faster, how I can I do that
   *     by just changing 1 line of code
   *  3) Can you write code using the for loop to reverse the motion.
   */
  
}
