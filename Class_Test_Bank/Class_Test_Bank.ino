class Account
{
  public:
    long AccountCheck (long AccNo, long AccPass)
    {
      if (AccNo == AccountNo && AccPass == AccountPass)
      {
        Serial.println("Account Checked");
        return (Balance);
      }
      else
      {
        Serial.println("Invaild User Information");
      }
    }
      void AccountDeposit (long AccNo, long AccPass, long DepoAmount)
      {
        if (AccNo == AccountNo && AccPass == AccountPass)
        {
          Balance += DepoAmount;
          Serial.println("Account Deposited");
        }
        else
        {
          Serial.println("Invaild User Information");
        }
      }
        void AccountWithdrawal (long AccNo, long AccPass, long WitdrAmount)
        {
          if (AccNo == AccountNo && AccPass == AccountPass)
          {
            Balance -= WitdrAmount;
            Serial.println("Account Deposited");
          }
          else
          {
            Serial.println("Invaild User Information");
          }

        };


      
private:
       
        long Balance = 100000;
       
        long AccountNo = 1893745;
        long AccountPass = 8179384;



      };

      Account Phyoe;

      void setup()
      {
        Serial.begin(9600);
        
        //Phyoe.AccountNo = 100000;
        
        long CurrentValue = Phyoe.AccountCheck(1893745, 8179384);
        Serial.println(CurrentValue);
        
        Phyoe.AccountWithdrawal(1893745, 8179384, 1000);

        CurrentValue = Phyoe.AccountCheck(1893745, 8179384);
        Serial.println(CurrentValue);

        Phyoe.AccountDeposit(1893745, 8179384, 3000);

        CurrentValue = Phyoe.AccountCheck(1893745, 8179384);
        Serial.println(CurrentValue);
      };


      void loop()
      {
              
      }



