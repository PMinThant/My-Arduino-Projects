#include<Servo.h>
Servo s1, s2, s3, s4, s5;

void setup() {
  // put your setup code here, to run once:

  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
}

void loop() {
  int ch3 = pulseIn(A0, HIGH);
  int ch4 = pulseIn(A1, HIGH);
  int ch5 = pulseIn(A4, HIGH);
  byte pos1 = map(ch3, 993, 1489, 0, 180);
  byte pos2 = map(ch3, 1489, 1930, 0, 180);
  byte pos3 = map(ch4, 993, 1483, 0, 180);
  byte pos4 = map(ch4, 1483, 1973, 0, 180);
  byte pos5 = map(ch5, 993, 1985, 0, 180);

  s1.write(pos1);
  s2.write(pos3);
  s3.write(pos2);
  s4.write(pos4);
  s5.write(pos5);

}
