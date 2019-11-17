#include <EEPROM.h>


char ValidKey[16]={'1','3','4','6','N','N','N','N','N','N','N','N','N','N','N','N'};
byte ContrastValue = 140;
byte BackLightValue = 255;
byte lock = 175;
byte unlock = 0;

void setup() 
{
  for(byte i =0;i<16;i++)
  {
    EEPROM.write(i,ValidKey[i]);
    delay(10);
  }
  
  
  EEPROM.write(16,BackLightValue);
  EEPROM.write(17,ContrastValue);
  EEPROM.write(18,lock);
  EEPROM.write(19,unlock);
}

void loop() 
{
  

}
