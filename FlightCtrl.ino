void FlightControl(){
  
    //---------------SAFETY----------------------
  
      if((millis()-time) > ALARM_LOW && !alarm )      // LOW ALARM
      {
          setPitch=0;
          setRoll=0;
          LED_ON(LED_Y);
          alarm = true;
          Serial1.println("#AlarmLow;");
      }  
      if((millis()-time)>ALARM_HIGH && millis()-timer>1000) // HIGH ALARM
      {  
          LED_ON(LED_R);
          timer = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;
          Serial1.println("#Alarmhigh;");
      }
      
      
      if( abs(Pitch - setPitch) < 10 || abs(Yaw - setYaw) < 10 )
      {
          angleTime = millis();
      }
          
      if( millis() - angleTime > 2000)
      {
        Serial1.println("Angle and setpoint time alarm!");
        run = false;
      }
          
          
    //****************************************
    
  
  motorWrite(m1_val,m2_val,m3_val,m4_val);
    
}


