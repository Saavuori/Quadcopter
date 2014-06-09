unsigned long serialdata;
int inbyte;

void serial()
{
 
   if(Serial1.available())
   {
     time = millis();
     alarm = false;
   
      getSerial();
   
      switch(serialdata)
      {
      
        case 'S':  //SET
      
                getSerial();
                
                if(serialdata == 'S')    //SET POINT
                {                
                   s = Serial1.read();
                   
                      if(s=='P')
                          setPitch = Serial1.parseFloat(); 
                      if(s=='R')
                          setRoll  = Serial1.parseFloat(); 
                      if(s=='Y')
                          setYaw  = Serial1.parseFloat(); 
                }     
                
                if(serialdata == 'P')  //PID VALUE
                {
                    pidN  = Serial1.parseInt();
                    PID = Serial1.read();                     
                    pid[pidN][n]= Serial1.parseFloat();        
                }   

                if(serialdata =='A')  //START
                {                  
                    run = true;
                    Serial1.println("#Start!;");                                           
                }
                
                if(serialdata =='Q')   //STOP
                {
                    run = false; 
                    Serial1.println("#STOP!");
                }
               
        break;      
        case 'G':  //GET
      
               getSerial();
      
              if(serialdata =='M')
              {
                  Serial1.print(m1_val);
                  Serial1.print(" ");
                  Serial1.print(m2_val);
                  Serial1.print(" ");
                  Serial1.print(m3_val);
                  Serial1.print(" ");
                  Serial1.println(m4_val);
              }
                        
        break;  
     
        Serial1.println("Unkown command:");        
     }Serial1.flush();      
   }  
}

long getSerial()
{
  serialdata = 0;
  while (inbyte != '/')
  {
    inbyte = Serial.read(); 
    if (inbyte > 0 && inbyte != '/')
    {
     
      serialdata = serialdata * 10 + inbyte - '0';
    }
  }
  inbyte = 0;
  return serialdata;
}
