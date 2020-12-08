#include <Servo.h>

#define CLAWMOTOR_MAX 90
#define CLAWMOTOR_MIN 65
#define CLAWMOTOR_MID (CLAWMOTOR_MAX + CLAWMOTOR_MIN)/2

#define TILTMOTOR_MAX 155
#define TILTMOTOR_MIN 80
#define TILTMOTOR_MID (TILTMOTOR_MAX + TILTMOTOR_MIN)/2

#define EXTENDMOTOR_MAX 105
#define EXTENDMOTOR_MIN 10
#define EXTENDMOTOR_MID (EXTENDMOTOR_MAX + EXTENDMOTOR_MIN)/2

#define PANMOTOR_MAX 180
#define PANMOTOR_MIN 0
#define PANMOTOR_MID (PANMOTOR_MAX + PANMOTOR_MIN)/2

Servo panMotor;
Servo tiltMotor;
Servo extendMotor;
Servo clawMotor;

int potPin1 = 0;
int potPin2 = 1;
int potPin3 = 2;
int potPin4 = 3;

int panMotorPin = 6;
int tiltMotorPin = 9;
int extendMotorPin = 10;
int clawMotorPin = 11;

void setup() {
  // put your setup code here, to run once:
  panMotor.attach(panMotorPin);
  tiltMotor.attach(tiltMotorPin);
  extendMotor.attach(extendMotorPin);
  clawMotor.attach(clawMotorPin);
  Serial.begin(9600);
}

void printPotStatus() {
  Serial.print("Pot1 = " + String(analogRead(potPin1)));
  Serial.print(" Pot2 = " + String(analogRead(potPin2)));
  Serial.print(" Pot3 = " + String(analogRead(potPin3)));
  Serial.println(" Pot4 = " + String(analogRead(potPin4)));
}


void processPot() {
  int panMotorAngle = map(analogRead(potPin1),0,1023,0,180);
  panMotor.write(panMotorAngle);

  int tiltMotorAngle = map(analogRead(potPin2),0,1023,0,180);
  tiltMotor.write(tiltMotorAngle);

  int extendMotorAngle = map(analogRead(potPin3),0,1023,0,180);
  extendMotor.write(extendMotorAngle);

  int clawMotorAngle = map(analogRead(potPin4),0,1023,0,180);
  clawMotor.write(clawMotorAngle);

  //Serial.println(panMotorAngle);
}

void loop() {
  
  printPotStatus();
  delay(100);
  processPot();
    
  
}
