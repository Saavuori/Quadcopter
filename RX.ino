PROGMEM const byte rxPins[4]={RX_YAW,RX_ROLL,RX_PITCH, RX_THROTTLE};

volatile byte rxState[4]={0,0,0,0};
volatile int rxPrev[4]={0,0,0,0};

void rxInit()
{
  for(byte i=0;i<4;i++){
    pinMode(pgm_read_byte(&rxPins[i]),INPUT); 
    digitalWrite(pgm_read_byte(&rxPins[i]),HIGH);
  }
  PCICR |= (1 << PCIE0); 
  PCMSK0 |= (1 << PCINT1)|(1 << PCINT2)|(1 << PCINT3)|(1 << PCINT4); 
  sei();
}

ISR(PCINT0_vect) 
{ 
  for(byte i=0;i<4;i++){
    byte rxtemp=digitalRead(pgm_read_byte(&rxPins[i]));
    if((rxState[i] == 0) & (rxtemp==1)){
      rxPrev[i]=micros();
      rxState[i]=1;
    }
    else if((rxState[i] == 1) & (rxtemp==0)){
      rxVal[i]=micros()-rxPrev[i];
      rxState[i]=0;
    }
  }  
 
 flightAlarm1=millis();
 alarm=false;
  
}

void rxValues()
{  
  if(!alarm)
  {
    if(!altitudeHold)      
      throttle=map(rxVal[0],1100,1900,50,rxLimits[0]);  
      
    Set[0]=map(rxVal[1],1100,1900,-rxLimits[1],rxLimits[1]);    
    Set[1]=map(rxVal[2],1100,1900,-rxLimits[1],rxLimits[1]); 
    
    Set[2]=map(rxVal[3],1100,1900,rxLimits[2],-rxLimits[2]);  
  }
}
