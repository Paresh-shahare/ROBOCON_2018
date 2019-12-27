 #define PS2_DAT             25
  #define PS2_CMD             8  
  #define PS2_SEL             9  
  #define PS2_CLK             23  
  #define pwm1                10
  #define dir1                49
  #define pwm2                 11
  #define dir2                 43
  #define pwm3                 13
  #define dir3                 A5
  #define pwm4                 12
  #define dir4                 A4
  #define peum1               A0
  #define peum2               A1
  
  #define lift_en1            A9
  #define lift_dir1            A8

  
  #define lift_en2               A11
  #define lift_dir2              A10

  
  #define in1                 27      
  #define load1               A3
  #define load2               A2          
  #define in2                 29                 
  #define in3                 31
  #define in4                 33
  #define en1                 5
  #define en2                 4

  
  #define in5                 35                 
  #define in6                 37                 
  #define in7                 39
  #define in8                 41
  #define en3                 3
  #define en4                 2



#define boost 52
#define con1 50
#define grp1 48
#define grp2 46
#define con2 44
#define forward 42
#define right 40
#define rev_dir 38
#define back 36
#define left 34
#define str_right 32
#define pneu2 30
#define str_left 28
#define pneu1 26

int k=0;
int j=0;
int q=0;
int p=0;
int x=0;
int y=0;
int z=0;
int m=0;
int n=0;
int r=0;
int s=0;




void setup() {
 Serial.begin(9600);
    pinMode(pwm1,OUTPUT);
    pinMode(pwm2,OUTPUT);
    pinMode(dir1,OUTPUT);
    pinMode(dir2,OUTPUT);
    pinMode(pwm3,OUTPUT);
    pinMode(pwm4,OUTPUT);
    pinMode(dir3,OUTPUT);       
    pinMode(load1 ,OUTPUT);
    pinMode(load2, OUTPUT);       
    pinMode(dir4,OUTPUT);
    pinMode(peum1,OUTPUT);
    pinMode(peum2,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    pinMode(en1,OUTPUT);
    pinMode(en2,OUTPUT);
    pinMode(in5,OUTPUT);
    pinMode(in6,OUTPUT);
    pinMode(in7,OUTPUT);
    pinMode(in8,OUTPUT);
    pinMode(en3,OUTPUT);
    pinMode(en4,OUTPUT);
    pinMode(A15, OUTPUT);
    pinMode(lift_en1, OUTPUT);
    pinMode(lift_en2, OUTPUT);
    pinMode(lift_dir1, OUTPUT);
    pinMode(lift_dir2, OUTPUT);

    
    digitalWrite(peum1,LOW);
    digitalWrite(peum2,LOW);
    digitalWrite(en1,LOW);
    digitalWrite(en2,LOW);
  
 
  for(int i=22;i<=52;i=i+2)
  {
    pinMode(i,INPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(A15));
  if (digitalRead(A15)==HIGH)
  {
    Serial.println(digitalRead(A15));
      if (digitalRead(boost)==HIGH)
  {
    k=1;
    Serial.println("Boost");
  }
  else
  {
    k=0;
  }






 if((digitalRead(back)==HIGH)&&(k==0))
  {
    Serial.println("Slow Back");
    p=1;
    //for(int i=30;i<50;i=i+3)
      //{
       digitalWrite(dir3,HIGH);
       analogWrite(pwm3,50); 
       
       digitalWrite(dir4,LOW);
       analogWrite(pwm4,50);  
       
       delay(1);
      //}
  }
  else if((digitalRead(back)==HIGH)&&(k==1))
  {
    Serial.println("Fast Back");
    p=1;
    digitalWrite(dir3,HIGH);
       analogWrite(pwm3,200); 
       
       digitalWrite(dir4,LOW);
       analogWrite(pwm4,200);  
  }  
  else if(q==0)
  {
    j=0;
    p=0;
    
       analogWrite(pwm3,0); 
       analogWrite(pwm4,0);  
  }
  else
  {
    j=0;
    p=0;
  }




  

  if((digitalRead(forward)==HIGH)&&(k==0))
  {
    Serial.println("Slow Forward");
    // for(int i=30;i<50;i=i+3)
      //{
       digitalWrite(dir3,LOW);
       analogWrite(pwm3,50); 
       digitalWrite(dir4,HIGH);
       analogWrite(pwm4,50);  
       
       delay(1);
      //}
    q=1;
  }
  
  else if((digitalRead(forward)==HIGH)&&(k==1))
  {
    Serial.println("Fast Forward");
    digitalWrite(dir3,LOW);
       analogWrite(pwm3,200); 
       digitalWrite(dir4,HIGH);
       analogWrite(pwm4,200); 
    q=1;
  }
  else if (p==0)
  {
    j=0;
    q=0;    
       analogWrite(pwm3,0);        
       analogWrite(pwm4,0);
  }
  else
  {
    j=0;
    q=0;
  }







  

  

  if((digitalRead(left)==HIGH)&&(k==0))
  {
    Serial.println("Slow Left");
    y=1;
    for(int i=50;i<80;i=i+3)
      {
       digitalWrite(dir1,LOW);
       analogWrite(pwm1,i); 
       digitalWrite(dir2,LOW);
       analogWrite(pwm2,i);  
       
      }
  }
  else if((digitalRead(left)==HIGH)&&(k==1))
  {
    Serial.println("Fast Left");
    y=1;
    digitalWrite(dir1,LOW);
       analogWrite(pwm1,150); 
       digitalWrite(dir2,LOW);
       analogWrite(pwm2,150);
  }  
  else if((m==0) && (n==0) && (r==0) && (s==0) && (z==0))
  {
    j=0;
    y=0;
       analogWrite(pwm1,0);       
       analogWrite(pwm2,0);
  }
  else
  {
    y=0;
    
  }












    if((digitalRead(right)==HIGH)&&(k==0))
  {
    Serial.println("Slow Right");
    z=1;
      for(int i=50;i<80;i=i+3)
      {
       digitalWrite(dir1,HIGH);
       analogWrite(pwm1,i); 
       digitalWrite(dir2,HIGH);
       analogWrite(pwm2,i);  
        
       delay(1);
      }
  }
  else if((digitalRead(right)==HIGH)&&(k==1))
  {
    Serial.println("Fast Right");
    z=1;
    digitalWrite(dir1,HIGH);
       analogWrite(pwm1,150); 
       digitalWrite(dir2,HIGH);
       analogWrite(pwm2,150);
  }  
  else if((m==0) && (n==0) && (r==0) && (s==0) && (y==0))
  {
    j=0;
    z=0;
       analogWrite(pwm1,0);
       analogWrite(pwm2,0);
  }
  else
  {
    z=0;
    
  }












  











  
   if((digitalRead(str_left)==HIGH)&&(q==0)&&(p==0))
  {
    Serial.println("Stop stear left");
    m=1;
    digitalWrite(dir2,LOW);
          analogWrite(pwm2,150);
    
  }
  else if((digitalRead(str_left)==HIGH)&&(q==1))
  {
    Serial.println("Forward stear left");
    m=1;
    digitalWrite(dir2,LOW);
          analogWrite(pwm2,150);
    
  }  
  
  else if((y==0) && (z==0) && (n==0))
  {
    j=0;
    m=0;
    
          analogWrite(pwm2,0);
    
  }
  else
  {
    m=0;
  }










     if((digitalRead(str_right)==HIGH)&&(q==0)&&(p==0))
  {
    Serial.println("Stop stear right");
    n=1;
    digitalWrite(dir2,HIGH);
         analogWrite(pwm2,150);
    
  }
  else if((digitalRead(str_right)==HIGH)&&(q==1))
  {
    Serial.println("Forward stear right");
    digitalWrite(dir2,HIGH);
         analogWrite(pwm2,150);
    n=1;
    
  }  
 
  else if((y==0) && (z==0) && (m==0))
  {
    j=0;
    n=0;
    
         analogWrite(pwm2,0);
    
  }
  else
  {
    n=0;
  }










 if((digitalRead(str_left)==HIGH)&&(p==1))
  {
    Serial.println("backward stear left");
    s=1;
    digitalWrite(dir1,LOW);
          analogWrite(pwm1,150);
  }  
  
  else if((y==0) && (z==0) && (r==0))
  {
    j=0;
    s=0;
    
          analogWrite(pwm1,0);
  }
  else 
  {
    s=0;
  }








 if((digitalRead(str_right)==HIGH)&&(p==1))
  {
    Serial.println("backward stear right");
    r=1;
    digitalWrite(dir1,HIGH);
         analogWrite(pwm1,150);
  }  
 
  else if((y==0) && (z==0) && (s==0))
  {
    j=0;
    r=0;
   
         analogWrite(pwm1,0);
    
  }
  else
  {
    r=0;
  }









  if (digitalRead(pneu1)==HIGH)
  {
    Serial.println("pneu1");
    digitalWrite(load1,HIGH);
  }

  else
  {
    digitalWrite(load1,LOW);
  }

  
  if(digitalRead(pneu2)==HIGH)
  {
    Serial.println("pneu2");
    digitalWrite(load2,HIGH);
  }
  else
  {
    j=0;
    digitalWrite(load2,LOW);
  }










if(digitalRead(rev_dir)==LOW)
{
  
  x=0;
}
else
{
  Serial.println("rev_dir");
  x=1;
}


if((digitalRead(con1)==HIGH) && (x==0))
{
Serial.println("clock conv1");
digitalWrite(in5,HIGH);
          digitalWrite(in6,LOW);
          analogWrite(en3,220); 
}
else if((digitalRead(con1)==HIGH) && (x==1))
{
Serial.println("anticlock conv1");
digitalWrite(in5,LOW);
          digitalWrite(in6,HIGH);
          analogWrite(en3,220); 
}
else
{
  j=0;
  analogWrite(en3,0);
}







if((digitalRead(con2)==HIGH) && (x==0))
{
  Serial.println("clock conv2");
 digitalWrite(in7,LOW);
          digitalWrite(in8,HIGH);
          analogWrite(en4,120); 
}
else if((digitalRead(con2)==HIGH) && (x==1))
{
  Serial.println("anticlock conv2");
  digitalWrite(in7,HIGH);
          digitalWrite(in8,LOW);
          analogWrite(en4,120); 
}
else
{
  j=0;
  analogWrite(en4,0);
  
}










if((digitalRead(grp2)==HIGH) && (x==0))
{
  Serial.println("clock grp1");
  digitalWrite(in3,LOW);
          digitalWrite(in4,HIGH);
          analogWrite(en2,65); 
}
else if((digitalRead(grp2)==HIGH) && (x==1))
{
  Serial.println("anticlock grp1");
  digitalWrite(in3,HIGH);
          digitalWrite(in4,LOW);
          analogWrite(en2,65); 
}
else
{
  j=0;
  analogWrite(en2,0);
}


if((digitalRead(grp1)==HIGH) && (x==0))
{
  Serial.println("clock grp2");
  digitalWrite(in1,HIGH);
          digitalWrite(in2,LOW);
         analogWrite(en1,65); 
}
else if((digitalRead(grp1)==HIGH) && (x==1))
{
  Serial.println("anticlock grp2");
  digitalWrite(in1,LOW);
          digitalWrite(in2,HIGH);
         analogWrite(en1,65); 
}
else
{
  j=0;
  analogWrite(en1,0);
}
  }











































































  
  else
  {
    Serial.println(digitalRead(A15));
     if (digitalRead(boost)==HIGH)
     
  {
    k=1;
    Serial.println("Boost");
  }
  else
  {
    k=0;
  }






 if((digitalRead(forward)==HIGH)&&(k==0))         /////////////
  {
    Serial.println("Slow Back");
    p=1;
    //for(int i=30;i<50;i=i+3)
      //{
       digitalWrite(dir3,HIGH);
       analogWrite(pwm3,50); 
       
       digitalWrite(dir4,LOW);
       analogWrite(pwm4,50);  
       
       delay(1);
      //}
  }
  else if((digitalRead(forward)==HIGH)&&(k==1))             ////////
  {
    Serial.println("Fast Back");
    p=1;
    digitalWrite(dir3,HIGH);
       analogWrite(pwm3,200); 
       
       digitalWrite(dir4,LOW);
       analogWrite(pwm4,200);  
  }  
  else if(q==0)
  {
    j=0;
    p=0;
    
       analogWrite(pwm3,0); 
       analogWrite(pwm4,0);  
  }
  else
  {
    j=0;
    p=0;
  }




  

  if((digitalRead(back)==HIGH)&&(k==0))             //////////
  {
    Serial.println("Slow Forward");
    // for(int i=30;i<50;i=i+3)
      //{
       digitalWrite(dir3,LOW);
       analogWrite(pwm3,50); 
       digitalWrite(dir4,HIGH);
       analogWrite(pwm4,50);  
       
       delay(1);
      //}
    q=1;
  }
  
  else if((digitalRead(back)==HIGH)&&(k==1))        //////////////
  {
    Serial.println("Fast Forward");
    digitalWrite(dir3,LOW);
       analogWrite(pwm3,200); 
       digitalWrite(dir4,HIGH);
       analogWrite(pwm4,200); 
    q=1;
  }
  else if (p==0)
  {
    j=0;
    q=0;    
       analogWrite(pwm3,0);        
       analogWrite(pwm4,0);
  }
  else
  {
    j=0;
    q=0;
  }







  

  

  if((digitalRead(right)==HIGH)&&(k==0))              /////////
  {
    Serial.println("Slow Left");
    y=1;
    for(int i=50;i<80;i=i+3)
      {
       digitalWrite(dir1,LOW);
       analogWrite(pwm1,i); 
       digitalWrite(dir2,LOW);
       analogWrite(pwm2,i);  
       
      }
  }
  else if((digitalRead(right)==HIGH)&&(k==1))      ////////////
  {
    Serial.println("Fast Left");
    y=1;
    digitalWrite(dir1,LOW);
       analogWrite(pwm1,150); 
       digitalWrite(dir2,LOW);
       analogWrite(pwm2,150);
  }  
  else if((m==0) && (n==0) && (r==0) && (s==0) && (z==0))
  {
    j=0;
    y=0;
       analogWrite(pwm1,0);       
       analogWrite(pwm2,0);
  }
  else
  {
    y=0;
    
  }












    if((digitalRead(left)==HIGH)&&(k==0))         ///////////////
  {
    Serial.println("Slow Right");
    z=1;
      for(int i=50;i<80;i=i+3)
      {
       digitalWrite(dir1,HIGH);
       analogWrite(pwm1,i); 
       digitalWrite(dir2,HIGH);
       analogWrite(pwm2,i);  
        
       delay(1);
      }
  }
  else if((digitalRead(left)==HIGH)&&(k==1))          //////////////
  {
    Serial.println("Fast Right");
    z=1;
    digitalWrite(dir1,HIGH);
       analogWrite(pwm1,150); 
       digitalWrite(dir2,HIGH);
       analogWrite(pwm2,150);
  }  
  else if((m==0) && (n==0) && (r==0) && (s==0) && (y==0))
  {
    j=0;
    z=0;
       analogWrite(pwm1,0);
       analogWrite(pwm2,0);
  }
  else
  {
    z=0;
    
  }












  











  
   if((digitalRead(str_right)==HIGH)&&(q==0)&&(p==0))           ///////////
  {
    Serial.println("Stop stear left");
    m=1;
    digitalWrite(dir1,LOW);
          analogWrite(pwm1,150);
    
  }
  else if((digitalRead(str_right)==HIGH)&&(q==1))       ///////////
  {
    Serial.println("Forward stear left");
    m=1;
    digitalWrite(dir2,LOW);
          analogWrite(pwm2,150);
    
  }  
  
  else if((y==0) && (z==0) && (n==0))
  {
    j=0;
    m=0;
    
          analogWrite(pwm2,0);
    
  }
  else
  {
    m=0;
  }










     if((digitalRead(str_left)==HIGH)&&(q==0)&&(p==0))       ///////
  {
    Serial.println("Stop stear right");
    n=1;
    digitalWrite(dir1,HIGH);
         analogWrite(pwm1,150);
    
  }
  else if((digitalRead(str_left)==HIGH)&&(q==1))      ////////////
  {
    Serial.println("Forward stear right");
    digitalWrite(dir2,HIGH);
         analogWrite(pwm2,150);
    n=1;
    
  }  
 
  else if((y==0) && (z==0) && (m==0))
  {
    j=0;
    n=0;
    
         analogWrite(pwm2,0);
    
  }
  else
  {
    n=0;
  }










 if((digitalRead(str_right)==HIGH)&&(p==1))        /////////////
  {
    Serial.println("backward stear left");
    s=1;
    digitalWrite(dir1,LOW);
          analogWrite(pwm1,150);
  }  
  
  else if((y==0) && (z==0) && (r==0) && (m==0) && (n==0))
  {
    j=0;
    s=0;
    
          analogWrite(pwm1,0);
  }
  else 
  {
    s=0;
  }








 if((digitalRead(str_left)==HIGH)&&(p==1))          //////////
  {
    Serial.println("backward stear right");
    r=1;
    digitalWrite(dir1,HIGH);
         analogWrite(pwm1,150);
  }  
 
  else if((y==0) && (z==0) && (s==0) && (m==0) && (n==0))
  {
    j=0;
    r=0;
   
         analogWrite(pwm1,0);
    
  }
  else
  {
    r=0;
  }









 










if(digitalRead(rev_dir)==LOW)
{
  
  x=0;
}
else
{
  Serial.println("rev_dir");
  x=1;
}


if((digitalRead(con2)==HIGH) && (x==0))     //////////
{
Serial.println("clock conv1");
digitalWrite(in5,HIGH);
          digitalWrite(in6,LOW);
          analogWrite(en3,220); 
}
else if((digitalRead(con2)==HIGH) && (x==1))          ////////
{
Serial.println("anticlock conv1");
digitalWrite(in5,LOW);
          digitalWrite(in6,HIGH);
          analogWrite(en3,220); 
}
else
{
  j=0;
  analogWrite(en3,0);
}







if((digitalRead(con1)==HIGH) && (x==0))           ////////////
{
  Serial.println("clock conv2");
 digitalWrite(in7,LOW);
          digitalWrite(in8,HIGH);
          analogWrite(en4,120); 
}
else if((digitalRead(con1)==HIGH) && (x==1)  )          ///////////
{
  Serial.println("anticlock conv2");
  digitalWrite(in7,HIGH);
          digitalWrite(in8,LOW);
          analogWrite(en4,120); 
}
else
{
  j=0;
  analogWrite(en4,0);
  
}










if((digitalRead(grp1)==HIGH) && (x==0))           /////////
{
  Serial.println("clock grp1");
  digitalWrite(in3,LOW);
          digitalWrite(in4,HIGH);
          analogWrite(en2,65); 
}
else if((digitalRead(grp1)==HIGH) && (x==1))        /////////
{
  Serial.println("anticlock grp1");
  digitalWrite(in3,HIGH);
          digitalWrite(in4,LOW);
          analogWrite(en2,65); 
}
else
{
  j=0;
  analogWrite(en2,0);
}


if((digitalRead(grp2)==HIGH) && (x==0))     ///////////
{
  Serial.println("clock grp2");
  digitalWrite(in1,HIGH);
          digitalWrite(in2,LOW);
         analogWrite(en1,65); 
}
else if((digitalRead(grp2)==HIGH) && (x==1))     //////////
{
  Serial.println("anticlock grp2");
  digitalWrite(in1,LOW);
          digitalWrite(in2,HIGH);
         analogWrite(en1,65); 
}
else
{
  j=0;
  analogWrite(en1,0);
}


/*if((digitalRead(pneu1)==HIGH) && (x==0))
  {
    Serial.println("lift_dir2");
    digitalWrite(lift_dir2,HIGH);
    digitalWrite(lift_en2, HIGH);
    //delay(100);
    //digitalWrite(lift_en2, LOW);
    //delay(20); 
  }
  
  else if((digitalRead(pneu1)==HIGH) && (x==1))
  {
    Serial.println("reverse lift_dir2");
    digitalWrite(lift_dir2,LOW);
    digitalWrite(lift_en2, HIGH);
    //delay(100);
    //digitalWrite(lift_en2, LOW);
    //delay(20);
  }
  else
  {
    j=0;
    digitalWrite(lift_en2,LOW);
  }*/






 if ((digitalRead(pneu1)==HIGH)  && (x==0))              /////////////
  {
    Serial.println("lift_dir1");
    digitalWrite(lift_dir1,LOW);
    digitalWrite(lift_en1, HIGH);
    //delay(100);
    //digitalWrite(lift_en1, LOW);
    //delay(20);
  }
  else if((digitalRead(pneu1)==HIGH)  && (x==1))
  {
Serial.println("reverse lift_dir1");
       digitalWrite(lift_dir1,HIGH);
    digitalWrite(lift_en1, HIGH);
    //delay(100);
    //digitalWrite(lift_en1, LOW);
    //delay(20); 
  }

  else
  {
    digitalWrite(lift_en1,LOW);
  }


if ((digitalRead(pneu2)==HIGH)  && (x==0))              /////////////
  {
    Serial.println("lift_dir1");
    digitalWrite(lift_dir2,LOW);
    digitalWrite(lift_en2, HIGH);
    //delay(100);
    //digitalWrite(lift_en1, LOW);
    //delay(20);
  }
  else if((digitalRead(pneu2)==HIGH)  && (x==1))
  {
Serial.println("reverse lift_dir1");
       digitalWrite(lift_dir2,HIGH);
    digitalWrite(lift_en2, HIGH);
    //delay(100);
    //digitalWrite(lift_en1, LOW);
    //delay(20); 
  }

  else
  {
    digitalWrite(lift_en2,LOW);
  }
  
  
  


  }
  

}
