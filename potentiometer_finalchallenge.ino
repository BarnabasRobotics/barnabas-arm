/*
Last challenge:
- If potentiometer < 200 : say "hello"
- If 200 < potentiometer < 512 : say "hi there"
- If 512 < potentiometer < 900 : say "almost there"
- If 900 < potentiometer < 1023 : say "good bye!"
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potentiometer;
  potentiometer = analogRead(A0);
  
  if (potentiometer < 200) {
    Serial.println("hello");
  }
  else if (potentiometer < 512) {
    Serial.println("hi there");
  }
  else if (potentiometer < 900) {
    Serial.println("almost there");
  }
  else if (potentiometer < 1023) {
    Serial.println("goodbye");
  }
  
  delay(100);
  
}
