void FlightControl(){
  
  
      if((millis()-time) > ALARM_LOW && !alarm )
      {
          setPitch=0;
          setRoll=0;
          LED_ON(LED_Y);
          alarm = true;
          Serial1.println("#AlarmLow;");
      }  
      if((millis()-time)>ALARM_HIGH && millis()-timer>1000)
      {  
          LED_ON(LED_R);
          timer = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;
          Serial1.println("#Alarmhigh;");
      }
  
  motorWrite(m1_val,m2_val,m3_val,m4_val);
    
}


