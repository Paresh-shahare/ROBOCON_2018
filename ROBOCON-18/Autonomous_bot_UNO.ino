#define i1 A3                      //gripper
#define i2 A2
#define en1 11


#define i3 A0                      //stop
#define i4 A1
#define en2 10

#define la2 13
int z=0;
int k=0;
void setup()
{
  pinMode(en1,OUTPUT);
  pinMode(i1,OUTPUT);
  pinMode(i2,OUTPUT);
   pinMode(en2,OUTPUT);
  pinMode(i3,OUTPUT);
  pinMode(i4,OUTPUT);
  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
    
  pinMode(A4,OUTPUT);
  pinMode(9,OUTPUT);

 pinMode(la2, OUTPUT);
 pinMode(2,INPUT);
 pinMode(4,OUTPUT);

   
  digitalWrite(A4,LOW);                                        //initial direction and pwm of throw motor
  analogWrite(9,0);

digitalWrite(7,HIGH);                                           //indicating led set to low
digitalWrite(8,HIGH );

  
 digitalWrite(i1,LOW);                                          //gripper direction
 digitalWrite(i2,LOW);
 analogWrite(9,00);                                             //initially setting all pwm to 0
 analogWrite(11,0);
 analogWrite(10,0);
k=0;
    Serial.begin(9600);

      while(1)
  {
    Serial.println("In");
   /* if(digitalRead(2)==HIGH)
    {
      z++;
      delay(15);
    }

    else
    {
      z=0;
    }*/

    
    if(digitalRead(2)==HIGH)                                     //signal from mega                                        
    {
      Serial.println("Outtttttttttt"); 
    digitalWrite(i3,HIGH);                                       //stop  direction
    digitalWrite(i4,LOW);
    digitalWrite(A4,HIGH);                         
    analogWrite(9,29);                                           //throw motor pwm
    analogWrite(en2,100);                                        //stop pwm
    delay(1550);
    analogWrite(en2,0);
    //delay(8000);                                               //Extra change for checking
    z=0;
    k=0;
    break;
    }

    else
    {
    digitalWrite(A4,HIGH); 
    analogWrite(9,29);
    analogWrite(en2,0); 
    }
  }

analogWrite(en2,00);
 }
                                                                   //-------- Reached loading point
  
  
  void loop()
  {
   
    if(digitalRead(2)==HIGH)                                        //signal from mega to move towards tz2
    {
      z++;
      delay(20);
    }
    else
    {
      z=0;
    }





    if((z>=5) && (k==0))
    {
      Serial.println("K=0");
     digitalWrite(i1,HIGH);                                          //gripper
    digitalWrite(i2,LOW);
    analogWrite(en1,80);
    delay(360);                                                       //gripper closing delay         430
    analogWrite(en1,0);
    k=1;
    digitalWrite(A4,HIGH);                                            //slight torque in arm motor
    analogWrite(9,18);
    delay(200);

    digitalWrite(i3,HIGH);                                            //opening of stop motor during travelling          
    digitalWrite(i4,LOW);
    analogWrite(en2,100);
    
    delay(1800);
    analogWrite(en2,0);                           
    
    }

    else if((z>=5)&& (k==1))                                            //Again a digital signal from mega
    {
      Serial.println("K=1");
    digitalWrite(A4,HIGH);                                              //arm holding shuttlecock
    analogWrite(9,16);
    digitalWrite(i1,LOW);                             
    digitalWrite(i2,HIGH);                                              //opening of gripper at throw position
    analogWrite(en1,80);
    /*digitalWrite(i3,HIGH);
    digitalWrite(i4,LOW);
    
    analogWrite(en2,100);*/
   
    delay(450);                                                          //Addition equals to 1800     530
    
    analogWrite(en1,0);
    
    //delay(1270);
    //analogWrite(en2,0);
    k=0; 
    delay(300);
    digitalWrite(7,HIGH);                                                 //glowing of indication led
    digitalWrite(8,LOW);


    
                                                               //-----------Throwing should start here --------------------     
digitalWrite(A4,HIGH);
for(float i=22;i<215;i=i+1.4)                                               //Acceration of arm    
{
analogWrite(9,i);
delay(9);
}
delay(1400);
digitalWrite(la2,HIGH);                                                      //laser signal
delay(300);
digitalWrite(la2,LOW);

analogWrite(9,31);                                                            //stop arm

delay(1000);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH );

digitalWrite(4,HIGH);                                                           //signal to mega to start return pid
delay(500);
digitalWrite(4,LOW);
delay(250); 
digitalWrite(A4,HIGH);                                                         //slight torque to stop at initial postition
analogWrite(9,31);  
                  

    
 
    
    digitalWrite(i3,LOW);                                                       //adjustment of stop motor
    digitalWrite(i4,HIGH);
    analogWrite(en2,100);
    delay(1700);
    analogWrite(en2,0);
    
    }
else
{
  analogWrite(en1,0);
}
    

    


     
}
