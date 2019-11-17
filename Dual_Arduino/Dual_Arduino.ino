#define a 3
#define b 4
#define c 5
void setup() 
{
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(c,INPUT);
Serial.begin(9600);
}

void loop() {
 byte value=digitalRead(a);
  byte v=digitalRead(b);
  byte val=digitalRead(c);
  if (value==0)
  {
   
    Serial.println('L'); 
    //delay(200);
  }
  else
  {
   
    Serial.println('H');
  // delay(200);
  }
  if (v==0)
  {
   
    Serial.println('B'); 
    //delay(200);
  }
  else
  {
   
    Serial.println('A');
  // delay(200);
  }
  if (val==0)
  {
   
    Serial.println('S'); 
    //delay(200);
  }
  else
  {
   
    Serial.println('D');
  // delay(200);
  }

}
