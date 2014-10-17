void FlightAlarms()
{
       if((millis()-flightAlarm1) > ALARM_LOW && !alarm )
      {
          alarm = true;
          Serial1.println("#AlarmLow;");
          altitudeHold = false;
      }       
      if((millis()-flightAlarm1)>ALARM_HIGH && millis()-flightAlarm2>1000)
      {  
          flightAlarm2 = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;
          Serial1.println("#Alarmhigh;");
      }    
}
