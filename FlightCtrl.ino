void FlightControl(){
  
  /*
      if((millis()-time) > ALARM_LOW && !alarm )
      {
          setPitch=0;
          setRoll=0;
          alarm = true;
          Serial1.println("#AlarmLow;");
      }  
      if((millis()-time)>ALARM_HIGH && millis()-timer>1000)
      {  
          timer = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;   //todo: if baro decend
          Serial1.println("#Alarmhigh;");
      }
  */
  motorWrite(m1_val,m2_val,m3_val,m4_val);
    
}


