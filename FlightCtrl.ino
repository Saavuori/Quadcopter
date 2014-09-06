void FlightControl(){

 
 
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
          timer = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;
          Serial1.println("#Alarmhigh;");
      }
        /*
      if( abs(Pitch - setPitch) < 20 && abs(Roll - setRoll) < 20 )
      {
          angleTime = millis();

      }
          
      if( millis() - angleTime > angle_alarm && throttle > MOTOR_ARM_START)
      {
        Serial1.println("Angle and setpoint time alarm!");
        run = false;
      }
      
    
      */
}
