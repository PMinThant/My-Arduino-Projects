void move_servo (void)
{
  if(inches<=15&&inches>=1)
  {
    for(pos=1; pos<=175; pos++)
    {
    
    myservo.write(pos);
    delay(6);
    }
  }
  
  
}

