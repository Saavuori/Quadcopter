unsigned long serialdata;
int inbyte;

void serial()
{
 
   if(Serial1.available())
   {
     time = millis();
     alarm = false;
<<<<<<< HEAD
    
     cmd = Serial1.read();
  
     
      switch(cmd)
=======
   
      getSerial();
   
      switch(serialdata)
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
      {
        case 'S':  //SET
<<<<<<< HEAD
                Serial1.println("SET..");
                Serial1.println(Serial1.available());
                s = Serial1.read();
=======
      
                getSerial();
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
                
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
                
<<<<<<< HEAD
                else if(s == 'P')  //PID VALUE
=======
                if(serialdata == 'P')  //PID VALUE
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
                {
                    pidN  = Serial1.parseInt();
                    PID = Serial1.read();                     
                    pid[pidN][n]= Serial1.parseFloat();        
                }   

<<<<<<< HEAD
               else  if(s =='A')  //START
=======
                if(serialdata =='A')  //START
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
                {                  
                    run = true;
                    Serial1.println("#Start!");                                           
                }
                
<<<<<<< HEAD
               else if(s =='Q')   //STOP
=======
                if(serialdata =='Q')   //STOP
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
                {
                    run = false; 
                    Serial1.println("#STOP!");
                }
               
        break;      
        case 'G':  //GET
<<<<<<< HEAD
                Serial1.println("GET..");
                Serial1.println(Serial1.available());
              if(s =='M')
=======
      
               getSerial();
      
              if(serialdata =='M')
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
              {
                  Serial1.print("1: ");
                  Serial1.println(m1_val);
                  Serial1.print("2: ");
                  Serial1.println(m2_val);
                  Serial1.print("3: ");
                  Serial1.println(m3_val);
                  Serial1.print("4: ");
                  Serial1.println(m4_val);                  
              }                        
        break; 
        
        default:  
        
        Serial1.println("Unkown command"); 
        
        break;
        
     }
     
<<<<<<< HEAD
     Serial1.flush();      
=======
        Serial1.println("Unkown command:");        
     }Serial1.flush();      
>>>>>>> a7d359d5100cf4a6df7f6a7ae9724f62c08fc19c
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
