//  DC Motor 1  Pins
#define M1 22
#define M2 24

//  DC Motor 2  Pins

#define M3 26
#define M4 28
#define E1 2
#define E2 4

#include<Servo.h>
Servo s1, s2, s3, s4, s5;

int Speed1 = 10;
int Speed2 = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  s1.attach(5);
  s2.attach(6);
  s3.attach(7);
  s4.attach(8);
  s5.attach(9);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);

}

//Main Program
void loop() {

  // channels read

  int ch1 = pulseIn(A2, HIGH);
  int ch2 = pulseIn(A3, HIGH);
  int ch3 = pulseIn(A4, HIGH);
  int ch4 = pulseIn(A5, HIGH);
  int ch5 = pulseIn(A6, HIGH);


  //Arm
  byte pos1 = map(ch3, 993, 1489, 0, 180);
  byte pos2 = map(ch3, 1489, 1930, 0, 180);
  byte pos3 = map(ch4, 993, 1483, 0, 180);
  byte pos4 = map(ch4, 1483, 1973, 0, 180);
  byte pos5 = map(ch5, 993, 1985, 0, 180);

  s1.write(pos1);
  s2.write(pos2);
  s3.write(pos3);
  s4.write(pos4);
  s5.write(pos5);

  //Driving
  if (ch1 > 1500)
  {
    forward();
  }
  if (ch1 < 1400)
  {
    backward();
  }
  if (ch1 > 1400 && ch1 < 1500 && ch2 > 1400 && ch2 < 1500)
  {
    sstop();
  }

  ///left right

  if (ch2 < 1400)
  {
    left();
  }
  if (ch2 > 1500)
  {
    right();
  }

}


// functions
void forward ()
{
  Serial.println("FORWARD");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  digitalWrite(E1, Speed1);
  digitalWrite(E2, Speed1);
}

void backward()
{
  Serial.println("BACKWARD");
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  digitalWrite(E1, Speed1);
  digitalWrite(E2, Speed1);
}

void right()
{
  Serial.println("RIGHT");
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  digitalWrite(E1, Speed2);
  digitalWrite(E2, Speed1);
}

void left()
{
  Serial.println("Left");
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  digitalWrite(E1, Speed1);
  digitalWrite(E2, Speed2);
}

void sstop()
{
  Serial.println("stop");
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(E1, Speed2);
  digitalWrite(E2, Speed2);
}

