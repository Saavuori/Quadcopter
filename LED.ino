void LED_INIT()
{
 pinMode(LED_G, OUTPUT);
 pinMode(LED_Y, OUTPUT);
 pinMode(LED_R, OUTPUT); 
     Serial1.println("#Leds initialized");
}
void LED_ON(int i){  
  digitalWrite(i, HIGH);    
}
void LED_OFF(int i){  
 digitalWrite(i,LOW);   
}
