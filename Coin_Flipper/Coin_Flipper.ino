void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  digitalWrite(4,HIGH);

}

void loop() {
 if(digitalRead(4)==LOW)
 {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
 }
 delay (50);
 if(digitalRead(4)==LOW)
 {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
 }
 delay (50);
}
