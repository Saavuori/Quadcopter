void PID_init(){
    //                          Kp,        Ki,         Kd           Lval         Hval    
  pids[PID_PITCH_RATE].SetParameters(PITCH_PID_RATE_KP,PITCH_PID_RATE_KI,PITCH_PID_RATE_KD,PITCH_PID_RATE_MIN,PITCH_PID_RATE_MAX);
  pids[PID_ROLL_RATE].SetParameters(ROLL_PID_RATE_KP,ROLL_PID_RATE_KI,ROLL_PID_RATE_KD,ROLL_PID_RATE_MIN,ROLL_PID_RATE_MAX);
  pids[PID_YAW_RATE].SetParameters(YAW_PID_RATE_KP,YAW_PID_RATE_KI,YAW_PID_RATE_KD,YAW_PID_RATE_MIN,YAW_PID_RATE_MAX);    
  
  Serial1.println("#PID INITIALIZED!");
}

double PID_CHANGE(int i,int j, float k)
{
     pids[i].ChangeParameters(j,k);
 
     Serial1.print(pids[i].getKP());
     Serial1.print(" ");
     Serial1.print(pids[i].getKI());
     Serial1.print(" ");
     Serial1.println(pids[i].getKD());
}

void PID_COMPUTE(){
  
  if(throttle > MOTOR_ZERO_LEVEL)
  {  
    SetX = pids[PID_PITCH_ANGLE].Compute(setPitch-Pitch);    
    SetY = pids[PID_ROLL_ANGLE].Compute(setRoll-Roll);    
    SetZ = pids[PID_YAW_ANGLE].Compute(setYaw-Yaw);
        
    PID_PITCH_RATE_VAL = (int)pids[PID_PITCH_RATE].Compute(SetX-gyroYrate*radToDeg);
    PID_ROLL_RATE_VAL  = (int)pids[PID_ROLL_RATE].Compute(SetY-gyroXrate*radToDeg);
    PID_YAW_RATE_VAL   = (int)pids[PID_YAW_RATE].Compute(SetZ-gyroZrate*radToDeg);   
  }
  else
  {     
     PID_PITCH_RATE_VAL   = 0;
     PID_ROLL_RATE_VAL    = 0;
     PID_YAW_RATE_VAL     = 0; 
  }     
    m[0] = throttle+PID_ROLL_RATE_VAL+PID_PITCH_RATE_VAL+PID_YAW_RATE_VAL;
    m[1] = throttle-PID_ROLL_RATE_VAL+PID_PITCH_RATE_VAL-PID_YAW_RATE_VAL;    
    m[2] = throttle-PID_ROLL_RATE_VAL-PID_PITCH_RATE_VAL+PID_YAW_RATE_VAL; 
    m[3] = throttle+PID_ROLL_RATE_VAL-PID_PITCH_RATE_VAL-PID_YAW_RATE_VAL;
           
    for(int i=0;i<4;i++)
      m[i]=m[i]>MOTOR_MAX_LEVEL?MOTOR_MAX_LEVEL:m[i];
     
    timePID = millis();
   
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

void PID_RESET_I(){
  
      for(int i=0;i<6;i++)
        pids[i].resetI();
}



