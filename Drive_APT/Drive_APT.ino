
//  DC Motor 1  Pins
#define M1 42  //4
#define M2 40   //5

//  DC Motor 2  Pins

#define M3 50  //6
#define M4 48   //7
#define E1 11
#define E2 10


byte Speed1 = 3;
byte Speed2 = 0;
byte Speed3 = 4;
byte Speed4 = 2;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);


  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
}

//Main Program
void loop() {

  // channels read

  int ch1 = pulseIn(A5, HIGH);
  int ch2 = pulseIn(A4, HIGH);
  int ch4 = pulseIn(A2, HIGH);
  int ch6 = pulseIn(A0, HIGH);
 

 
  
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
    digitalWrite(E1, Speed4);
    digitalWrite(E2, Speed4);
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
    Serial.println("Forward Left");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed2);
    digitalWrite(E2, Speed1);

  }
  if (ch2 > 1600 && ch2 < 2000)
  {
    Serial.println("Forward Right");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed1);
    digitalWrite(E2, Speed2);
  }
  if (ch4 < 1400 && ch4 > 900)
  {

    Serial.println(" Left");
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    digitalWrite(E1, Speed3);
    digitalWrite(E2, Speed3);

   
  }
  if (ch4 > 1600 && ch4 < 2000)
  {
    Serial.println(" Right");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
    digitalWrite(M4, HIGH);
    digitalWrite(E1, Speed3);
    digitalWrite(E2, Speed3);

  }
if (ch6 > 1600 && ch6 < 2000)
  {
    Serial.println(" LED_On");
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(28, HIGH);

  }
  else
  {
    Serial.println(" LED_OFF");
    digitalWrite(22, LOW);
    digitalWrite(24, LOW);
    digitalWrite(26, LOW);
    digitalWrite(28, LOW);

  }
}




