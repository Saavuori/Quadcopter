void FlightControl(){

  int PIDroll_val  = (int)PIDroll.Compute((float)setRoll-gy_aver);
  int PIDpitch_val = (int)PIDpitch.Compute((float)setPitch-gx_aver);
  int PIDyaw_val   = (int)PIDyaw.Compute((float)setYaw-gz_aver);

  m1_val=throttle+PIDroll_val+PIDpitch_val+PIDyaw_val;
  m2_val=throttle-PIDroll_val+PIDpitch_val-PIDyaw_val;
  m3_val=throttle+PIDroll_val-PIDpitch_val-PIDyaw_val;
  m4_val=throttle-PIDroll_val-PIDpitch_val+PIDyaw_val;

  analogWrite(MOTOR1,m1_val);
  analogWrite(MOTOR2,m2_val);
  analogWrite(MOTOR3,m3_val);
  analogWrite(MOTOR4,m4_val);
  
  

}


