int i=0;
int k=0;
int x=0;
int y = 0;
int start;    
int l=0;
#define echoPin   23  //27
#define trigPin   25  //29
//#define  th  A9
//#define  re  A8
int duration;
int distance;
                
float P1=0, D1=0, PD_value1=0;
float error1=0, previous_error1=0;
float readVal1,positionVal1;

float P2=0, D2=0, PD_value2=0;
float error2=0, previous_error2=0;
float readVal2,positionVal2;

float P3=0, D3=0, PD_value3=0;
float error3=0, previous_error3=0;
float readVal3,positionVal3;

float P4=0, D4=0, PD_value4=0;
float readVal4,positionVal4;

float P5=0, D5=0, PD_value5=0;
float readVal5,positionVal5;

float P6=0, D6=0, PD_value6=0;
float readVal6,positionValU6;

float P7=0, D7=0, PD_value7=0;
float readVal7,positionVal7;

float P8=0, D8=0, PD_value8=0;
float readVal8,positionVal8;

float P9=0, D9=0, PD_value9=0;
float readVal9,positionVal9;

float P10=0, D10=0, PD_value10=0;
float readVal10,positionVal10;

float P11=0, D11=0, PD_value11=0;
float readVal11,positionVal11;


float P12=0, D12=0, PD_value12=0;
float readVal12,positionVal12;


float P13=0, D13=0, PD_value13=0;
float readVal13,positionVal13;


float P14=0, D14=0, PD_value14=0;
float readVal14,positionVal14;


float P15=0, D15=0, PD_value15=0;
float readVal15,positionVal15;

int pwm1=8;
int pwm2=6;
int pwm3=3;
int pwm4=5;

int dir1=9;
int dir2=7;
int dir3=2;
int dir4=4;

#define sensor_2 A5
#define sensor_1 A2 
//#define sensor_3 A15 

int JP1=A1;
int JP2=A4;
int JP3=A7;




int TZ1=42;
int TZ2=43;
int TZ3=44;

void ultrasonic_sensor(void)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  }
   
void read_sensor_values1(void)
  {
  readVal1 = analogRead(A0);    
  positionVal1 = ((float)readVal1/921)*70;
  error1=(positionVal1-35)/5;
  }
  
  void read_sensor_values2(void)
  {
  readVal2 = analogRead(A3);    
  positionVal2 = ((float)readVal2/921)*70;
  error2=(positionVal2-35)/5;
  }
  
  void read_sensor_values3(void)
  {
  readVal3 = analogRead(A6);    
  positionVal3 = ((float)readVal3/921)*70;
  error3=(positionVal3-35)/5;
  }
  
  void read_sensor_values4(void)
  {
  readVal4 = analogRead(A6);    
  positionVal4 = ((float)readVal4/921)*70;
  }

  


  
  
void motor_control1(void)
{
    P1 = error2;
    D1 = error2 - previous_error2;  
    PD_value1 = (17*P1) + (0.6*D1);                        //150  17
    previous_error2 = error2;
  
    int left_motor_speed1 = 150 + PD_value1;
    int right_motor_speed1 = 150 - PD_value1;
    if (error2<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,left_motor_speed1);   
    analogWrite(pwm4,150); 
    analogWrite(pwm1,150);
    
    analogWrite(pwm2,150);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,150);   
    analogWrite(pwm4,right_motor_speed1); 
    analogWrite(pwm1,150);
    analogWrite(pwm2,150);
    }
  }




  
void motor_control2(void)
{
    P2 = error1;
    D2 = error1 - previous_error1;  
    PD_value2 = (10*P2) + (0.6*D2);    
    previous_error1 = error1;

   int left_motor_speed2 = 120 + PD_value2;
    int right_motor_speed2 = 120 - PD_value2;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,120);   
    analogWrite(pwm4,120); 
    analogWrite(pwm1,120);
    analogWrite(pwm2,left_motor_speed2);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed2);   
    analogWrite(pwm4,120); 
    analogWrite(pwm1,120);
    analogWrite(pwm2,120);
    }
   
  }




void motor_control3(void)
{
      P3 = error1;
    D3 = error1 - previous_error1;  
    PD_value3 = (6*P3) + (0.6*D3);    
    previous_error1 = error1;

   int left_motor_speed3 = 80 + PD_value3;
    int right_motor_speed3 = 80 - PD_value3;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,80);   
    analogWrite(pwm4,80); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,left_motor_speed3);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed3);   
    analogWrite(pwm4,80); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,80);
    }
  }

  


void motor_control4(void)
{
      P4 = error1;
    D4 = error1 - previous_error1;  
    PD_value4 = (5*P4) + (0.6*D4);    
    previous_error1 = error1;

   int left_motor_speed4 = 40 + PD_value4;
    int right_motor_speed4 = 40 - PD_value4;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,40);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,left_motor_speed4);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed4);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,40);
    }
  }

  


void motor_control5(void)
{
      P5 = error3;
    D5 = error3 - previous_error3;  
    PD_value5 = (10*P5) + (0.6*D5);    
    previous_error3 = error3;

   int left_motor_speed5 = 120 + PD_value5;
    int right_motor_speed5 = 120 - PD_value5;
    if (error3<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,120);   
    analogWrite(pwm4,left_motor_speed5); 
    analogWrite(pwm1,120);
    analogWrite(pwm2,120);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,120);   
    analogWrite(pwm4,120); 
    analogWrite(pwm1,right_motor_speed5);
    analogWrite(pwm2,120);
    }
  }




void motor_control6(void)
{
      P6 = error3;
    D6 = error3 - previous_error3;  
    PD_value6 = (2*P6) + (0.6*D6);    
    previous_error3 = error3;

   int left_motor_speed6 = 40 + PD_value6;
    int right_motor_speed6 = 40 - PD_value6;
    if (error3<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,40);   
    analogWrite(pwm4,left_motor_speed6); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,40);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,40);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,right_motor_speed6);
    analogWrite(pwm2,40);
    }
  }





void motor_control7(void)
{
    P7 = error2;
    D7 = error2 - previous_error2;  
    PD_value7 = (10*P7) + (0.6*D7);    
    previous_error2 = error2;
  
    int left_motor_speed7 = 100 + PD_value7;
    int right_motor_speed7 = 100 - PD_value7;
    if (error2<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,left_motor_speed7);   
    analogWrite(pwm4,100); 
    analogWrite(pwm1,100);
    analogWrite(pwm2,100);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,100);   
    analogWrite(pwm4,right_motor_speed7); 
    analogWrite(pwm1,100);
    analogWrite(pwm2,100);
    }
  }







void motor_control8(void)
{
      P8 = error1;
    D8 = error1 - previous_error1;  
    PD_value8 = (22*P8) + (0.6*D8);    
    previous_error1 = error1;

   int left_motor_speed8 = 200 + PD_value8;
    int right_motor_speed8 = 200 - PD_value8;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,200);   
    analogWrite(pwm4,200); 
    analogWrite(pwm1,200);
    analogWrite(pwm2,left_motor_speed8);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed8);   
    analogWrite(pwm4,200); 
    analogWrite(pwm1,200);
    analogWrite(pwm2,200);
    }
  }

  


void motor_control9(void)
{
      P9 = error1;
    D9 = error1 - previous_error1;  
    PD_value9 = (17*P9) + (0.6*D9);    
    previous_error1 = error1;

   int left_motor_speed9 = 150 + PD_value9;
    int right_motor_speed9 = 150 - PD_value9;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,150);   
    analogWrite(pwm4,150); 
    analogWrite(pwm1,150);
    analogWrite(pwm2,left_motor_speed9);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed9);   
    analogWrite(pwm4,150); 
    analogWrite(pwm1,150);
    analogWrite(pwm2,150);
    }
  }




void motor_control10(void)
{
      P10 = error1;
    D10 = error1 - previous_error1;  
    PD_value10 = (12*P10) + (0.6*D10);    
    previous_error1 = error1;

   int left_motor_speed10 = 80 + PD_value10;
    int right_motor_speed10 = 80 - PD_value10;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,80);   
    analogWrite(pwm4,80); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,left_motor_speed10);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed10);   
    analogWrite(pwm4,80); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,80);
    }
  }




void motor_control11(void)
{
      P11 = error1;
    D11 = error1 - previous_error1;  
    PD_value11 = (6*P11) + (0.6*D11);    
    previous_error1 = error1;

   int left_motor_speed11 = 40 + PD_value11;
    int right_motor_speed11 = 40 - PD_value11;
    if (error1<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,40);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,left_motor_speed11);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,right_motor_speed11);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,40);
    }
  }




void motor_control12(void)
{
      P12 = error3;
    D12 = error3 - previous_error3;  
    PD_value12 = (22*P12) + (0.6*D12);    
    previous_error3 = error3;

   int left_motor_speed12 = 200 + PD_value12;
    int right_motor_speed12 = 200 - PD_value12;
    if (error3<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,200);   
    analogWrite(pwm4,left_motor_speed12); 
    analogWrite(pwm1,200);
    analogWrite(pwm2,200);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,200);   
    analogWrite(pwm4,200); 
    analogWrite(pwm1,right_motor_speed12);
    analogWrite(pwm2,200);
    }
  }






void motor_control13(void)
{
      P13 = error3;
    D13 = error3 - previous_error3;  
    PD_value13 = (17*P13) + (0.6*D13);    
    previous_error3 = error3;

   int left_motor_speed13 = 150 + PD_value13;
    int right_motor_speed13 = 150 - PD_value13;
    if (error3<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,150);   
    analogWrite(pwm4,left_motor_speed13); 
    analogWrite(pwm1,150);
    analogWrite(pwm2,150);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,150);   
    analogWrite(pwm4,150); 
    analogWrite(pwm1,right_motor_speed13);
    analogWrite(pwm2,150);
    }
  }






void motor_control14(void)
{
      P14 = error3;
    D14 = error3 - previous_error3;  
    PD_value14 = (6*P14) + (0.6*D14);    
    previous_error3 = error3;

   int left_motor_speed14 = 40 + PD_value14;
    int right_motor_speed14 = 40 - PD_value14;
    if (error3<=0)
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,40);   
    analogWrite(pwm4,left_motor_speed14); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,40);
    }
    else
    {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,40);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,right_motor_speed14);
    analogWrite(pwm2,40);
    }
  }






void motor_control15(void)
{
      P15 = error2;
    D15 = error2 - previous_error2;  
    PD_value15 = (12*P15) + (0.6*D15);    
    previous_error2 = error2;

   int left_motor_speed15 = 80 + PD_value15;
    int right_motor_speed15 = 80 - PD_value15;
    if (error2<=0)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,left_motor_speed15);   
    analogWrite(pwm4,80); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,80);
    }
    else
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,80);   
    analogWrite(pwm4,right_motor_speed15); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,80);
    }
}


void setup()
{
 
Serial.begin(9600);      
pinMode(A2,INPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(pwm1,OUTPUT);

pinMode(pwm2,OUTPUT);
pinMode(pwm3,OUTPUT);
pinMode(pwm4,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
pinMode(dir3,OUTPUT);
pinMode(dir4,OUTPUT);
pinMode(sensor_1, INPUT);
pinMode(sensor_2, INPUT);
//pinMode(sensor_3, INPUT);
pinMode(JP1, INPUT);
pinMode(JP2, INPUT);
pinMode(JP3, INPUT);
pinMode(start,INPUT);
pinMode(TZ1,INPUT);
pinMode(TZ2,INPUT);
pinMode(TZ3,INPUT);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A11, OUTPUT);
  pinMode(A10, INPUT);
pinMode(8,OUTPUT);
digitalWrite(8,LOW);
pinMode(A8, OUTPUT);
    analogWrite(pwm3,0);   
    analogWrite(pwm4,0); 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);

    
   /* 
   while(1)
    {
      read_sensor_values1();
      Serial.println(positionVal1);
      }
        */

        /*while(1)
        {
          Serial.println(digitalRead(A1));
        }*/

while(1)
{
ultrasonic_sensor();

  if(distance>140)
{

  digitalWrite(A8,HIGH);                    //first signal
  delay(250);
  digitalWrite(A8,LOW);
  
  
    Serial.println("fgh");
    
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,25);   
    analogWrite(pwm4,25); 
    analogWrite(pwm1,25);
    analogWrite(pwm2,25);


while(digitalRead(A5)!=HIGH)                               //_____________STARTING________________ 
{
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);                                      //CHECKPOINT 1
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    
    analogWrite(pwm3,80);   
    analogWrite(pwm4,80); 
    analogWrite(pwm1,80);
    analogWrite(pwm2,80);
}

    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,25);   
    analogWrite(pwm4,25); 
    analogWrite(pwm1,25);
    analogWrite(pwm2,25);                                          //------------- STOPPING AT POINT 1 --------------
    delay(300);
    analogWrite(pwm3,0);   
    analogWrite(pwm4,0); 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    delay(400);
digitalWrite(A8,LOW);
  while(digitalRead(JP2)!=HIGH)
  {
    read_sensor_values2();
    motor_control1();
 
  }
  delay(200);
// while(digitalRead(sensor_1)!=HIGH)
 /* {
    analogWrite(pwm3,40);   
    analogWrite(pwm4,40); 
    analogWrite(pwm1,40);
    analogWrite(pwm2,40);
  }*/

     y=0;
    x=0;
    
    while(digitalRead(JP2)!=HIGH)
  {
    read_sensor_values2();
    motor_control7();
  }

    while(digitalRead(sensor_1)!=HIGH)
  {
    analogWrite(pwm3,35);   
    analogWrite(pwm4,35); 
    analogWrite(pwm1,35);
    analogWrite(pwm2,35);
  }
  
    analogWrite(pwm3,0);   
    analogWrite(pwm4,0); 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
  
    break;
  }
 else
  {
    analogWrite(pwm3,0);   
    analogWrite(pwm4,0); 
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
  }
  
  
}
}







void loop()
{
ultrasonic_sensor();
read_sensor_values1();


while((positionVal1 <=33)  || (positionVal1 >=38))
{
read_sensor_values1();
if(positionVal1 >38)
{
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
  
analogWrite(pwm2,40);
analogWrite(pwm3,40);
analogWrite(pwm1,00);
analogWrite(pwm4,00);
}
else if(positionVal1<33)
{
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
  
analogWrite(pwm2,43);
analogWrite(pwm3,43);
analogWrite(pwm1,00);
analogWrite(pwm4,00);
}
else
{
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,0);
analogWrite(pwm4,0); 
}
}


if(distance<20 && distance>0)
{
  while(1)
  {
    ultrasonic_sensor();
    if(distance>40)
    {
      digitalWrite(A8,HIGH);                                    //second signal to uno
      delay(250);
      digitalWrite(A8,LOW);

      delay(500);
      
      
       int j=0;                                                //       INITIALLY INCREASING SPEED IN Y DIRECTION
   /* for(i=0;i<120;i++)
    {
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm3,i);   
    analogWrite(pwm4,i); 
    analogWrite(pwm1,i);
    analogWrite(pwm2,i);
    delay(0.32);
    }*/

     
   while (j!=1)                                         // CHECKPOINT 3 TO POINT_4 WITH INITIAL SPEED 200 PID OF SENSOR 1 TILL JP OF SENSOR 1
  {
      if(digitalRead(JP1)==HIGH)
      {
        j++;
        delay(150);
      } 
    else
    {
     read_sensor_values1();  
     read_sensor_values3();   
     motor_control2();
    }
 }


 
   while (j!=2)                                         // PPOINT_4  TO CHECKPOINT_4 REDUCTION OF SPEED TILL DIGITAL SIGNAL FROM SENSOR_2 WITH PID WITH INITIAL SPEED OF 28
  {
      if(digitalRead(JP1)==HIGH)
      {
        j++;
        delay(5);
        
      } 
    else
    {
     read_sensor_values1();
     motor_control3();
    }
 }


while (digitalRead(sensor_2)!=HIGH)
{
     read_sensor_values1();
     motor_control4();
}
analogWrite(pwm1,0);
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm4,0);

                                                                 //Gripper plus throwing mechanism

digitalWrite(A8,HIGH);                                        //third signal to UNO
delay(250);
digitalWrite(A8,LOW);


while(digitalRead(A9)!=HIGH)
{
read_sensor_values3();
if(positionVal3 >65)
{
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
  
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,30);
analogWrite(pwm4,30);
}
else if(positionVal3<45)
{
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
  
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,40);
analogWrite(pwm4,40);
}
else if(50 < positionVal3 < 55)
{
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
  
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,20);
analogWrite(pwm4,20);
}
else if(45 < positionVal3 <50)
{
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
  
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,20);
analogWrite(pwm4,20);
}
else
{
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,0);
analogWrite(pwm4,0); 
}



read_sensor_values1();
while((positionVal1 <=49)  || (positionVal1 >=51))
{
read_sensor_values1();
if(positionVal1 >51)
{
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
  
analogWrite(pwm2,40);
analogWrite(pwm3,40);
analogWrite(pwm1,00);
analogWrite(pwm4,00);
}
else if(positionVal1<49)
{
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,HIGH);
  
analogWrite(pwm2,43);
analogWrite(pwm3,43);
analogWrite(pwm1,00);
analogWrite(pwm4,00);
}
else
{
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,0);
analogWrite(pwm4,0); 
}
}


}

analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,0);
analogWrite(pwm4,0);
delay(200);
/*read_sensor_values3();
while((positionVal3) != 35)
{
  read_sensor_values3();
  
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,HIGH);
    digitalWrite(dir4,LOW);
  
analogWrite(pwm2,0);
analogWrite(pwm3,0);
analogWrite(pwm1,30);
analogWrite(pwm4,30);


}    
digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
    analogWrite(pwm3,30);   
    analogWrite(pwm4,30); 
    analogWrite(pwm1,30);
    analogWrite(pwm2,30);*/
    delay(200);

   while (j!=0)                                         // PPOINT_4  TO CHECKPOINT_4 REDUCTION OF SPEED TILL DIGITAL SIGNAL FROM SENSOR_2 WITH PID WITH INITIAL SPEED OF 28
  {
      if(digitalRead(JP3)==HIGH)
      {
        j--;
        delay(250);
        
      } 
    else
    {
     read_sensor_values3();
     motor_control5();
    }
 }

 while (digitalRead(sensor_2)!=HIGH)
 {
     read_sensor_values3();
     motor_control6();
 }
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
 break;
 
 
    }
  
/*else
    {
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
    }*/




else
{
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);  
}
  }
}
}
