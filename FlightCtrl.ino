void FlightControl(){
<<<<<<< HEAD

 
 
      if((millis()-time) > alarm_low && !alarm )
      {
          setPitch=0;
          setRoll=0;
         // LED_ON(LED_Y);
          alarm = true;
          Serial1.println("#AlarmLow;");
      }  
      if((millis()-time)>alarm_high && millis()-timer>1000)
      {  
         // LED_ON(LED_R);
=======
  
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
>>>>>>> origin/master
          timer = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;
          Serial1.println("#Alarmhigh;");
      }
<<<<<<< HEAD
        /*
      if( abs(Pitch - setPitch) < 20 && abs(Roll - setRoll) < 20 )
      {
          angleTime = millis();

      }
          
      if( millis() - angleTime > angle_alarm && throttle > MOTOR_ARM_START)
=======
      
      
      if( abs(Pitch - setPitch) < 10 || abs(Yaw - setYaw) < 10 )
      {
          angleTime = millis();
      }
          
      if( millis() - angleTime > 2000)
>>>>>>> origin/master
      {
        Serial1.println("Angle and setpoint time alarm!");
        run = false;
      }
<<<<<<< HEAD
      
    
      */
=======
          
          
    //****************************************
    
  
  motorWrite(m1_val,m2_val,m3_val,m4_val);
    
>>>>>>> origin/master
}
