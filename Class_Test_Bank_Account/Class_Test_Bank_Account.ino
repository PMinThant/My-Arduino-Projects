
class Account
{
    public:
      long AccountCheck (long AccNo,long AccPass)
      {
          if(AccNo==AccountNo && AccPass == AccountPass)
          {
                Serial.println("Account Checked");
                return(Balance);
          }
          else
          {
                Serial.println("Invalid User Information");
          }
      }
      void AccountDeposit (long AccNo,long AccPass,long DepoAmount)
      {
          if(AccNo==AccountNo && AccPass == AccountPass)
          {
                Balance += DepoAmount;
                Serial.println("Account Deposited");
          }
          else
          {
                Serial.println("Invalid User Information");
          }
      }
      void AccountWithdrawal (long AccNo,long AccPass,long WitdrAmount)
      {
          if(AccNo==AccountNo && AccPass == AccountPass)
          {
                Balance -= WitdrAmount;
                Serial.println("Account Withdrawaled");
          }
          else
          {
                Serial.println("Invalid User Information");
          }
      }
    private:
      long Balance = 100000;
      long AccountNo   = 1893745;
      long AccountPass = 8179384;
};



Account ZWE;

void setup() 
{
    Serial.begin(9600);

    ZWE.AccountNo = 100000;
    
    long CurrentValue = ZWE.AccountCheck(1893745,8179384);
    Serial.println(CurrentValue);
    
    ZWE.AccountWithdrawal(1893745,8179384,1000);
    
    CurrentValue = ZWE.AccountCheck(1893745,8179384);
    Serial.println(CurrentValue);

    ZWE.AccountDeposit(1893745,8179384,3000);
    
    CurrentValue = ZWE.AccountCheck(1893745,8179384);
    Serial.println(CurrentValue);
    
}

void loop() 
{

}
