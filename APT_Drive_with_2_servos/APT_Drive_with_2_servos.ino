// Arm
#include <Servo.h>
Servo s1, s2;

//  DC Motor 1  Pins
#define M1 4
#define M2 5

//  DC Motor 2  Pins

#define M3 6
#define M4 7
#define E1 11
#define E2 10



byte Speed1 = 2;
byte Speed2 = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  s1.attach(3);
  s2.attach(9);

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

  int ch1 = pulseIn(A5, HIGH);
  int ch2 = pulseIn(A4, HIGH);
  int ch3 = pulseIn(A3, HIGH);
  int ch6 = pulseIn(A0, HIGH);

//Arm
  byte pos1 = map(ch6, 900, 2000, 0, 180);
  byte pos2 = map(ch3, 950, 1950, 0, 180);
  s1.write(pos1);
  s2.write(pos2);
  
  //Driving
  if (ch1 > 1600 && ch1 < 2000)
  {
    Serial.println("FORWARD");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed1);
    digitalWrite(E2, Speed1);
  }
  if (ch1 < 1400 & ch1 > 900)
  {
    Serial.println("BACKWARD");
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(M3, LOW);
    digitalWrite(M4, HIGH);
    digitalWrite(E1, Speed1);
    digitalWrite(E2, Speed1);
  }
  if (ch1 > 1450 && ch1 < 1550 && ch2 > 1450 && ch2 < 1550)
  {
    Serial.println("stop");
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(E1, Speed2);
    digitalWrite(E2, Speed2);
  }

  ///left right

  if (ch2 < 1400 && ch2 > 900)
  {
    Serial.println("Left");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed2);
    digitalWrite(E2, Speed1);
  }
  if (ch2 > 1600 && ch2 < 2000)
  {
    Serial.println("RIGHT");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed1);
    digitalWrite(E2, Speed2);
  }
  // forward right/ forward left
  if (ch1 < 2000 && ch1 > 1800 && ch2 < 2000 && ch2 > 1800)
  {
    Serial.println("Forward Right");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed2);
    digitalWrite(E2, Speed1);
  }
  if (ch1 > 1800 && ch1 < 2000 && ch2 < 1200 && ch2 > 900)
  {
    Serial.println("FORWARD LEFT");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed1);
    digitalWrite(E2, Speed2);
  }

  // backward right/ backward left
  if (ch1 < 1200 && ch1 > 900 && ch2 < 2000 && ch2 > 1800)
  {
    Serial.println("Backward Right");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, HIGH);
    digitalWrite(E1, Speed2);
    digitalWrite(E2, Speed1);
  }
  if (ch1 > 900 && ch1 < 1200 && ch2 < 1200 && ch2 > 900)
  {
    Serial.println("Backward Left");
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed1);
    digitalWrite(E2, Speed2);
  }
}




