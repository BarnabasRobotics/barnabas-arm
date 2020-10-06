//- 1) What delay value can you use to make it blink the fastest. Answer is inbetween 1-100.
//  2) Short blink -> delay 100 ms, After a letter -> 1000 ms, At the end of a word -> 3000 ms
//  3) Create morse code for FOX
//  4) Create morse code for your name

void setup() {
  pinMode(7,OUTPUT);
}


void loop() {
  
  //- First letter (3 dots)
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  
  //- 1 second delay after a letter
  delay(1000);
  
  //- Second letter (3 dashes)
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
  
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
  
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
  
  delay(1000);
  
  //- Third letter (3 dots)
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
  
  delay(1000);
  
  //- the end of the word
  delay(3000);
  
  

}
