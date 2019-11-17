char Keypad_Scan (void)
{
  digitalWrite(R1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  if(!digitalRead(C1))
  {
    delay(300);
    return('1');
  }
  else if(!digitalRead(C2))
  {
    delay(300);
    return('2');
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('3');    
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('A');    
  }

  digitalWrite(R2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  if(!digitalRead(C1))
  {
    delay(300);
    return('4');
  }
  else if(!digitalRead(C2))
  {
    delay(300);
    return('5');
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('6');    
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('B');    
  }

  digitalWrite(R3,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(R1,HIGH);
  digitalWrite(R4,HIGH);
  if(!digitalRead(C1))
  {
    delay(300);
    return('7');
  }
  else if(!digitalRead(C2))
  {
    delay(300);
    return('8');
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('9');    
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('C');    
  }

  digitalWrite(R4,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R1,HIGH);
  if(!digitalRead(C1))
  {
    delay(300);
    return('*');
  }
  else if(!digitalRead(C2))
  {
    delay(300);
    return('0');
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('#');    
  }
  else if(!digitalRead(C3))
  {
    delay(300);
    return('D');    
  }
  else
  {
    return('N');
  }
 }
  void EEPROM_Store(void)
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
   void EEPROM_Restore(void)
  {
        for(byte i =0;i<16;i++)
      {
        ValidKey[i]=EEPROM.read(i);
        delay(10);
      }
      BackLightValue= EEPROM.read(16);
      ContrastValue = EEPROM.read(17);
      lock = EEPROM.read(18);
      unlock = EEPROM.read(19);
  }

