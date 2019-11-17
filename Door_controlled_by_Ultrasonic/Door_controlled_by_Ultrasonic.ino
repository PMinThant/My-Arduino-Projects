#define TrigPin 2
#define EchoPin 3
#include<Servo.h>

long duration, inches;
Servo myservo;

int pos;

void setup()
{
 pinMode(TrigPin,OUTPUT);
 pinMode(EchoPin,INPUT);
 myservo.attach(4);
 Serial.begin(9600);
}   
void loop() 
{
  get_distance();
  move_servo();

}
