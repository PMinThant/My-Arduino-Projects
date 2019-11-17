void get_distance (void)
{
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(TrigPin,LOW);

  duration = pulseIn(EchoPin,HIGH);

  inches=duration/74/2;
  
  delay (60);
  Serial.println(inches);
}

