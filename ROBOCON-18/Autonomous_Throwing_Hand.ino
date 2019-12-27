#define laser 7
#define rel 9
void setup()
{
  pinMode(laser,INPUT);
  pinMode(rel,OUTPUT);
  }
void loop()
{
  if(digitalRead(laser)==LOW)
  {
    delay(5.6);
    digitalWrite(rel,HIGH);
    digitalWrite(6,HIGH);
    delay(1000);
    
    digitalWrite(rel,LOW);
        digitalWrite(6,LOW);
    
  }  
  else
  {
    delay(1);
    }
}
