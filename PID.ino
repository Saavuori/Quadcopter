void PID_init(){
    //                          Kp,        Ki,         Kd           Lval         Hval    
  pids[PID_PITCH_RATE].SetParameters(PITCH_PID_RATE_KP,PITCH_PID_RATE_KI,PITCH_PID_RATE_KD,PID_MIN,PID_MAX);
  pids[PID_ROLL_RATE].SetParameters(ROLL_PID_RATE_KP,ROLL_PID_RATE_KI,ROLL_PID_RATE_KD,PID_MIN,PID_MAX);
  pids[PID_YAW_RATE].SetParameters(YAW_PID_RATE_KP,YAW_PID_RATE_KI,YAW_PID_RATE_KD,PID_MIN,PID_MAX);
  
  pids[PID_PITCH_ANGLE].SetParameters(PITCH_PID_ANGLE_KP,PITCH_PID_ANGLE_KI,PITCH_PID_ANGLE_KD,PID_ANGLE_MIN,PID_ANGLE_MAX);
  pids[PID_ROLL_ANGLE].SetParameters(ROLL_PID_ANGLE_KP,ROLL_PID_ANGLE_KI,ROLL_PID_ANGLE_KD,PID_ANGLE_MIN,PID_ANGLE_MAX);
  pids[PID_YAW_ANGLE].SetParameters(YAW_PID_ANGLE_KP,YAW_PID_ANGLE_KI,YAW_PID_ANGLE_KD,PID_ANGLE_MIN,PID_ANGLE_MAX);
  
  pids[PID_ALTITUDE_HOLD].SetParameters(ALT_PID_KP,ALT_PID_KI,ALT_PID_KD,-50,50);
    
  Serial1.println("#PID INITIALIZED!");
}

void PID_CHANGE(int i,int j, float k)
{
     pids[i].ChangeParameters(j,k);
 
     Serial1.print(pids[i].getKP());
     Serial1.print(" ");
     Serial1.print(pids[i].getKI());
     Serial1.print(" ");
     Serial1.println(pids[i].getKD());
}

void PID_COMPUTE()
{
  
  // Rate setpoints. In angle mode the angle loop turns the stick angle in
  // Set[] into a rate. Keep that result out of Set[]: while RX is lost
  // rxValues() does not refresh Set[], and the angle PID would take its own
  // output as the next input and run the setpoint up to PID_ANGLE_MAX.
  int rollRateSet  = Set[0];
  int pitchRateSet = Set[1];
  if(angleMode)
  {
   pitchRateSet = (int)pids[PID_PITCH_ANGLE].Compute(Set[1]+Pitch);
   rollRateSet  = (int)pids[PID_ROLL_ANGLE].Compute(Set[0]-Roll);
  }
    if(millis()-temp>20 && debugMode)
  {
    temp = millis();

       Serial1.print("V;");
       Serial1.print(rollRateSet);
       Serial1.println(";");
       Serial1.print("N;");
       Serial1.print(pitchRateSet);
       Serial1.println(";");
  }
   
    
    if(altitudeHold)
      PID_ALT_VALUE = (int)pids[PID_ALTITUDE_HOLD].Compute(setAltitude-altitude);
    else
      PID_ALT_VALUE = 0;
      
       
    PID_PITCH_RATE_VAL = throttle>MOTOR_ZERO_LEVEL?(int)pids[PID_PITCH_RATE].Compute((double)pitchRateSet-gyroRate[1]):0;
    PID_ROLL_RATE_VAL  = throttle>MOTOR_ZERO_LEVEL?(int)pids[PID_ROLL_RATE].Compute((double)rollRateSet-gyroRate[0]):0;
    PID_YAW_RATE_VAL   = throttle>MOTOR_ZERO_LEVEL?(int)pids[PID_YAW_RATE].Compute((double)Set[2]-gyroRate[2]):0;   
        
    m[0] = throttle+PID_ROLL_RATE_VAL-PID_PITCH_RATE_VAL+PID_YAW_RATE_VAL+PID_ALT_VALUE;
    m[1] = throttle-PID_ROLL_RATE_VAL-PID_PITCH_RATE_VAL-PID_YAW_RATE_VAL+PID_ALT_VALUE;    
    m[2] = throttle-PID_ROLL_RATE_VAL+PID_PITCH_RATE_VAL+PID_YAW_RATE_VAL+PID_ALT_VALUE; 
    m[3] = throttle+PID_ROLL_RATE_VAL+PID_PITCH_RATE_VAL-PID_YAW_RATE_VAL+PID_ALT_VALUE;
           
    // analogWrite() keeps only the low byte, so a negative value would wrap
    // to a high duty cycle. Never command less than the motors-off level.
    for(int i=0;i<4;i++)
      m[i]=constrain(m[i],MOTOR_ZERO_LEVEL,MOTOR_MAX_LEVEL);
        
      printMotors(false); 
}

void PID_RESET_I()
{  
      for(int i=0;i<PID_COUNT;i++)
        pids[i].resetI();
}



