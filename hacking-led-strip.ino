/*

1) Flip the logic.  Press -> LED OFF, No Press -> LED ON
1A) Do challenge 1 a second way
2) Press -> Blink the LED, No Press -> LED off
3) Press -> Blink fast, No Press -> Blink slowly

*/


void setup()
{
  pinMode(7,OUTPUT);
  pinMode(2,INPUT);
}

//- HINT FOR CHALLENGE #1
//- Change 1 line of code

void loop()
{

  //- if I press the button
  if (digitalRead(2) == HIGH) {
  //- then turn the light on
    digitalWrite(7,HIGH);
  }
  //- else turn the light off
  else {
    digitalWrite(7,LOW);
  }
}









































