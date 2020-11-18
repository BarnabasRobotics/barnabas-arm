#include <Servo.h>

Servo meMotor;
int meBox;

void setup(){
  pinMode(9,OUTPUT);
  meMotor.attach(9);
  meBox = 180;
  pinMode(7, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2, INPUT);
}

void loop(){
 
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
 
  meBox = 0;
  meMotor.write(meBox);
  delay(1000);
 
  //for loop
  for (int i = 0; i < 4; i++){
    meBox = meBox + 45;
    meMotor.write(meBox);
    delay(1000);
  }
 
  for (int i = 4; i > 0; i--){
    meBox = meBox - 45;
    meMotor.write(meBox);
    delay(1000);
  }

  if(digitalRead(2)==(LOW)) {
    digitalWrite(7, HIGH);
    delay(200);
    digitalWrite(7,LOW);
    delay(200);
  }
  else{
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
    delay(1000);
  }  

}
