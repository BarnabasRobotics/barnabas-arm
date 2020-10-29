void setup() {
  pinMode(4,OUTPUT); //-green
  pinMode(5,OUTPUT); //-red
  pinMode(6,OUTPUT); //-blue
}


void loop() {
  
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  delay(500);
  
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(4,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(500);
  
  digitalWrite(6,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  
  delay(500);
  digitalWrite(6,LOW);
  delay(500);

 

} 
