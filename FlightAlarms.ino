void FlightAlarms()
{
       // flightAlarm1 is updated by the RX pin-change ISR. Read its four bytes
       // with interrupts off: a torn read can look like a timestamp far in the
       // future, which makes millis()-flightAlarm1 wrap and trips both alarms.
       noInterrupts();
       unsigned long lastRxPulse = flightAlarm1;
       interrupts();
       unsigned long sinceRx = millis()-lastRxPulse;

       if(sinceRx > ALARM_LOW && !alarm )
      {
          alarm = true;
          Serial1.println("#AlarmLow;");
          altitudeHold = false;
      }       
      if(sinceRx>ALARM_HIGH &&millis()-flightAlarm2>1000)
      {  
          flightAlarm2 = millis();   
          throttle = throttle>MOTOR_ZERO_LEVEL?throttle*DESCEND_RATE:MOTOR_ZERO_LEVEL;
          Serial1.println("#Alarmhigh;");
      }    
}
