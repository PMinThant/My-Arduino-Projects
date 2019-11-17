void setup()
{
  Serial.begin(9600);
  for(byte i=11;i<14;i++)
  {
  pinMode(i, OUTPUT);
  }
}

void loop()
{
  if (Serial.available())
  {
    char data = Serial.read();

    if (data == 'H')
    {
     
      digitalWrite(13, HIGH);
     
      //delay(200);
    }
    else if(data=='L')
    {
      
      digitalWrite(13, LOW);
      //delay(200);
    }
    if (data == 'A')
    {
     
      digitalWrite(12, HIGH);
     
      //delay(200);
    }
    else if(data=='B')
    {
      
      digitalWrite(12, LOW);
      //delay(200);
    }
    if (data == 'D')
    {
     
      digitalWrite(11, HIGH);
     
      //delay(200);
    }
    else if(data=='S')
    {
      
      digitalWrite(11, LOW);
      //delay(200);
    }
  }
  }
