
void motorInit()
{
  pinMode(MOTOR1,OUTPUT); 
  pinMode(MOTOR2,OUTPUT);
  pinMode(MOTOR3,OUTPUT);
  pinMode(MOTOR4,OUTPUT);
  
  for(int i=0;i<4;i++)
    m[i]=MOTOR_ZERO_LEVEL;
  
  motorWrite();
 
  Serial1.println("#MOTORS INITIALIZED!");
}

void motorStop()
{
  for(int i=0;i<4;i++)
    m[i]=MOTOR_ZERO_LEVEL;
  
  motorWrite();  
  
  Serial1.println("#MOTORS STOPPED");
}

void motorWrite()
{      

  analogWrite(MOTOR1,m[0]);
  analogWrite(MOTOR2,m[1]);
  analogWrite(MOTOR3,m[2]);
  analogWrite(MOTOR4,m[3]);  

   
   if(MOTOR_INFO && millis()-timeMotors > 100)
   {
      timeMotors=millis();          
      Serial1.print("M");
      for(int i=0;i<4;i++)
          {
             Serial1.print(m[i]);
             Serial1.print(";");
          } 
      Serial1.print("\n"); 
   }  
}


