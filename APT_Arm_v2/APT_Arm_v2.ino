// Arm
#include <Servo.h>
Servo s1, s2;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

  s1.attach(3);
  s2.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ch4 = pulseIn(A4, HIGH);
  int ch6 = pulseIn(A0, HIGH);

  //Arm
  byte pos1 = map(ch6, 900, 2000, 0, 180);
  byte pos2 = map(ch4, 950, 1950, 0, 180);
  Serial.println (pos1);
  s1.write(pos1);
  s2.write(pos2);
  
}
