#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;

LiquidCrystal lcd (A0,A1,A2,A3,A4,A5);

#define ContrastPin 9
#define BackLightPin 10

#define R1 31
#define R2 33
#define R3 35
#define R4 37
#define C1 39
#define C2 41
#define C3 43
#define C4 45

#define buzzer 11

char EnterKey[16]={'N','N', 'N', 'N', 'N','N','N','N','N','N','N','N','N','N','N','N'};
char ValidKey[16]={'N','N', 'N', 'N', 'N','N','N','N','N','N','N','N','N','N','N','N'};
char RepeteKey[16]={'N','N', 'N', 'N', 'N','N','N','N','N','N','N','N','N','N','N','N'};

byte ContrastValue = 0;
byte BackLightValue = 0;
byte pointer =0;
unsigned long predictime= 0;

byte SubState = 1 ;
byte State = 1;
byte count = 0;
byte lock = 0;
byte unlock=0;

void setup() 
{
    //Servo
    myservo.attach(22);
    
    // EEPROM
    EEPROM_Restore();  
    //lcd Init
    lcd.begin(16,2);
    analogWrite(ContrastPin, ContrastValue);
    analogWrite(BackLightPin, BackLightValue);
    //Serial Init
    Serial.begin(9600);
    //Keypad Init
    pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(R3,OUTPUT);
    pinMode(R4,OUTPUT);
    pinMode(C1,INPUT_PULLUP);
    pinMode(C2,INPUT_PULLUP);  
    pinMode(C3,INPUT_PULLUP);
    pinMode(C4,INPUT_PULLUP);
}

void loop() 
{
   
  switch(State)
  {
    case 1:
      State_1_function();
      break;
    case 2:
      State_2_function();
      break;
    case 3:
      State_3_function();
      break;
    case 4:
      State_4_function();
      break;
    case 5:
      State_5_function();
      break;
    case 6:
      State_6_function();
      break;
    case 7:
      State_7_function();
      break;
    case 8:
      State_8_function();
      break;
    case 9:
      State_9_function();
      break;
     default:
      State_1_function();
     
  }
}
void State_1_function(void)
{
  
  lcd.clear();
  lcd.print("ENTER PASSWORD:");
  lcd.setCursor(0,1);
  lcd.cursor();
  lcd.blink();
  predictime = millis()+ 10000;

  while(State == 1)
  {
    char Key = Keypad_Scan();
    if (Key == 'N')
    {
     
      
    }
   
    else if( Key=='#')
    {
      analogWrite(BackLightPin,BackLightValue);
      predictime=millis()+10000;
      State = 2;
    }
    else
    {
      analogWrite(BackLightPin,BackLightValue);
      predictime=millis()+10000;
      lcd.print(Key); 
      EnterKey[pointer]= Key;
      pointer++;
    }
    if(predictime<millis())
    {
      analogWrite(BackLightPin, 0);
    }
  }
  
}
void State_2_function(void)
{
  while(State==2)
  {
    byte passtime = 0;
    for(byte i=0;i<16;i++)
    {
      
      if(EnterKey[i]==ValidKey[i])
      {
        passtime++;
      }
    }
    lcd.noBlink();
    lcd.noCursor();
     if(passtime==16)
     {
      lcd.clear();
      lcd.print("    Password    ");
      lcd.setCursor(0,1);
      lcd.print("    Correct!    ");
      count = 0;
      analogWrite(buzzer,0);
      State = 3;
      
     }
     else
     {
      lcd.clear();
      lcd.print("    Password    ");
      lcd.setCursor(0,1);
      lcd.print("   Incorrect!   ");
      count ++;
      if(count>=3)
      {
        for(byte i =0;i<255;i++)
        {
          analogWrite(buzzer,i);
        }
      }
        
      State = 1;
     }
     delay(1000);
     Register_Clear();
     
    
  }
 
  
}
void State_3_function(void)
{
  lcd.clear();
  lcd.print("1.LOCK  2.UNLOCK");
  lcd.setCursor(0,1);
  lcd.print("3.SETT  4.LOGOUT");
      
      
     
  while(State == 3)
  {
    char Key = Keypad_Scan();
    if(Key == '1')
    {
      
      analogWrite(BackLightPin,BackLightValue);
      predictime=millis()+10000;
      State=4;
    }
    else if(Key=='2')
    {
      analogWrite(BackLightPin,BackLightValue);
      predictime=millis()+10000;
      State = 5;
    }
    else if(Key=='3')
    {
      analogWrite(BackLightPin,BackLightValue);
      predictime=millis()+10000;
      State = 6;
    }
    else if(Key=='4')
    {
      analogWrite(BackLightPin,BackLightValue);
      predictime=millis()+10000;
      lcd.clear();
      lcd.print(" LOGGING OUT! ");
      lcd.setCursor(0,1);
      lcd.print("----------------");
      delay(1000);
      State = 1;
    }
    if(predictime<millis())
    {
      analogWrite(BackLightPin, 0);
    }
  }
  
}
void Register_Clear(void)
{
  for(byte i=0;i<16;i++)
  {
    EnterKey[i]='N';
    RepeteKey[i]='N';
  }
  pointer=0;
  }
void State_4_function(void)
{
  lcd.clear();
  lcd.print("   Door LOCK!   ");
  lcd.setCursor(0,1);
  
  for(byte i =0;i<16;i++)
  {
    lcd.print("-");
    delay(200);
  }
  
  for(byte i =0; i <lock;i ++)
  {
    myservo.write(i);
    delay(15);
  }
  EEPROM_Store();
  State = 3;
  
  
    
}
void State_5_function(void)
{
  lcd.clear();
  lcd.print("  Door UNLOCK!  ");
  lcd.setCursor(0,1);
  
  for(byte i =0;i<16;i++)
  {
    lcd.print("-");
    delay(200);
  }
    for( byte i = unlock; i >0;i --)
  {
    myservo.write(i);
    delay(15);
  }
  EEPROM_Store();
  State = 3;
}
void State_6_function(void)
{
  lcd.clear();
  lcd.print("1.PASCN 2.BLKCHN");
  lcd.setCursor(0,1);
  lcd.print("3.CONCHN 4.EXIT ");
  while(State == 6)
  {
    char Key = Keypad_Scan();
    if(Key == '1')
    {
      State=7;
    }
    else if(Key=='2')
    {
      State = 8;
    }
    else if(Key=='3')
    {
      State = 9;
    }
    else if(Key=='4')
    {
      lcd.clear();
      lcd.print("    Exitting    ");
      lcd.setCursor(0,1);
      lcd.print("----------------");
      delay(1000);
      State = 3;
    }
  }
}
void State_7_function(void)
{
  lcd.clear();
  lcd.print("ENTER OLD PASSWD");
  lcd.setCursor(0,1);
  lcd.blink();
  lcd.cursor();
  while(SubState ==1)
  {
      char Key = Keypad_Scan();
      if (Key == 'N')
      {
        // do nothing
      }
      else if( Key=='#')
      {
        SubState = 2;
      }
      else
      {
        lcd.print(Key); 
        EnterKey[pointer]= Key;
        pointer++;
      }
  }
  while(SubState ==2)
  {
      byte passtime = 0;
      for(byte i=0;i<16;i++)
      {
        
        if(EnterKey[i]==ValidKey[i])
        {
          passtime++;
        }
      }
      lcd.noBlink();
      lcd.noCursor();
       if(passtime==16)
       {
        lcd.clear();
        lcd.print("    PASSWORD    ");
        lcd.setCursor(0,1);
        lcd.print("    CORRECT!    ");
        SubState = 3;
        
       }
       else
       {
        lcd.clear();
        lcd.print("    PASSWORD    ");
        lcd.setCursor(0,1);
        lcd.print("   INCORRECT!   ");
        SubState = 1;
       }
       delay(1000);
       Register_Clear();  
  }
  lcd.clear();
  lcd.print("ENTER NEW PASSWD");
  lcd.setCursor(0,1);
  lcd.blink();
  lcd.cursor();
  pointer = 0;
  while(SubState == 3)
  {
      char Key = Keypad_Scan();
      if (Key == 'N')
      {
        // do nothing
      }
      else if( Key=='#')
      {
        SubState = 4;
      }
      else
      {
        lcd.print(Key); 
        EnterKey[pointer]= Key;
        pointer++;
      }
  }
  
  lcd.clear();
  lcd.print("  ENTER AGAIN!  ");
  lcd.setCursor(0,1);
  lcd.blink();
  lcd.cursor();
  pointer = 0;
  while(SubState == 4)
  {
      char Key = Keypad_Scan();
      if (Key == 'N')
      {
        // do nothing
      }
      else if( Key=='#')
      {
        SubState = 5;
      }
      else
      {
        lcd.print(Key); 
        RepeteKey[pointer]= Key;
        pointer++;
      }
  }
   while(SubState ==5)
      {
          byte passtime = 0;
          for(byte i=0;i<16;i++)
          {
            
            if(EnterKey[i]== RepeteKey[i])
            {
              passtime++;
            }
          }
          lcd.noBlink();
          lcd.noCursor();
           if(passtime==16)
           {
            lcd.clear();
            lcd.print("    PASSWORD    ");
            lcd.setCursor(0,1);
            lcd.print("     MATCH!     ");
            SubState = 6;
            
           }
           else
           {
            lcd.clear();
            lcd.print("    PASSWORD    ");
            lcd.setCursor(0,1);
            lcd.print("   NOT MATCH!   ");
            SubState = 3;
           }
           delay(1000);
            
      }
  while (SubState == 6)
  {
      for(byte i = 0; i < 16; i++)
      {
        ValidKey[i] = EnterKey[i];
      }
      Register_Clear();
      EEPROM_Store();
      lcd.clear();
      lcd.print("    PASSWORD    ");
      lcd.setCursor(0,1);
      lcd.print("    CHANGED!    ");
      
      delay(1000);
      SubState = 1;
      State = 1;
      
  }
}
void State_8_function(void)
{
  lcd.clear();
  lcd.print("BACKLIGH CHANGE");
  lcd.setCursor(0,1);
  lcd.print("< >0-9 Press<OK>");
  while(State == 8)
  {
    char Key = Keypad_Scan();
    if(Key=='N'| Key=='*'|Key=='A'|Key=='B'|Key=='C'|Key=='D')
    {
      //Do nothing
    }
    else if (Key == '#')
    {
      lcd.clear();
      lcd.print("BACKLIGHT SAVING");
      EEPROM_Store();
      lcd.setCursor(0,1);
      for(byte i =0;i<16;i++)
      {
        lcd.print(">");
        delay(100);
      }
      State =6;
    }
    else 
    {
      BackLightValue=(Key-48)*25;
      analogWrite(BackLightPin,BackLightValue);
      lcd.setCursor(1,1);
      lcd.print(Key);
      
    }
    
       
  }
  
  
}
void State_9_function(void)
{
 
  lcd.clear();
  lcd.print("CONTRAST CHANGE!");
  lcd.setCursor(0,1);
  lcd.print("< >0-9 Press<OK>");
  while(State == 9)
  {
    char Key = Keypad_Scan();
    if(Key=='N'| Key=='*'|Key=='A'|Key=='B'|Key=='C'|Key=='D')
    {
      //Do nothing
    }
    else if (Key == '#')
    {
      lcd.clear();
      lcd.print("CONTRAST SAVING!");
      EEPROM_Store();
      lcd.setCursor(0,1);
      for(byte i =0;i<16;i++)
      {
        lcd.print(">");
        delay(100);
       
        
      }
      State = 6;
    }
    else 
    {
      lcd.setCursor(1,1);
      lcd.print(Key);
      Key= Key-48;
      ContrastValue=map(Key,0,9,160,70);
      analogWrite(ContrastPin,ContrastValue);
      
      
    }
       
  }
}

