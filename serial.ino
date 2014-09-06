volatile int cmd;
boolean validCMD = false;

void serial()
{  
   if(Serial1.available()>1)
   {     
     time = millis();
     alarm = false;     
     cmd = Serial1.read();

    if(cmd == 'S' || cmd == 'G')    
      validCMD = true;
    else
      validCMD = false;
            
      if(validCMD)
      {
          switch(cmd)
          {
            //*******************SET****************************
              case 'S':  
         
                cmd = Serial1.read();
                  
                if(cmd == 'S')    //SET POINT
                {                
<<<<<<< HEAD
                      cmd = Serial1.read();                             
                      if(cmd=='P') setPitch = Serial1.parseFloat();                        
                      if(cmd=='R') setRoll  = Serial1.parseFloat(); 
                      if(cmd=='Y') setYaw   = Serial1.parseFloat(); 
                      if(cmd=='T') throttle = Serial1.parseInt();                                                                         
                }                   
                else if(cmd == 'P' && PIDS_ENABLED == true)  PID_CHANGE(Serial1.parseInt(),Serial1.parseInt(),Serial1.parseFloat());                                                                  
                else if(cmd == 'A') run = true;                                                       
                else if(cmd == 'Q') run = false;  
                
                #ifdef CALIBRATION
                else if(cmd =='C')   //CALIBRATION 
                {                    
                    calibrateGYRO();
                    calibrateACC();
                }       
                #endif
                
                else if(cmd =='R')  ZeroPressure = getAvg(movavg_buff, MOVAVG_SIZE);                
                else if(cmd =='E')  PIDS_ENABLED = PIDS_ENABLED?false:true; 
                

                else if(cmd =='M')   //MOTOR TEST
                {                       
                    for(int i=0;i<4;i++)
                    {
                          delay(2000);
                          m[i]=115;
                          motorWrite();
                          
                    }delay(2000);                    
                }      
=======
                       getSerial();
                        
                      if(cmd=='P')
                          setPitch = Serial1.parseFloat(); 
                      if(cmd=='R')
                          setRoll  = Serial1.parseFloat(); 
                      if(cmd=='Y')
                          setYaw  = Serial1.parseFloat(); 
                      if(cmd=='T')
                          throttle = Serial1.parseInt();
                }                  
                else if(cmd =='A')  //START
                {                  
                    run = true;
                    Serial1.println("#Start!");                                           
                }                
                else if(cmd =='Q')   //STOP
                {
                    run = false; 
                    Serial1.println("#STOP!");
                }
                #ifdef DEBUG
                else if(cmd == 'P')  //PID VALUE
                {
                    pidN  = Serial1.parseInt();
                    PID = Serial1.read();                     
                    pid[pidN][n]= Serial1.parseFloat();        
                } 
               #endif
        break;      
        case 'G':  //GET
>>>>>>> origin/master
        
            break;
          //*******************GET****************************      
            case 'G': 
        
              cmd = Serial1.read();
                                        
              if (cmd=='S')
              {                          
                  Serial1.print(Pitch);
                  Serial1.print("   ");
                  Serial1.println(Roll);
              }            
              else if (cmd=='A')
              {                          
                  Serial1.print("setPitch: ");
                  Serial1.println(setPitch);
                  Serial1.print("setRoll: ");
                  Serial1.println(setRoll);
                  Serial1.print("setYaw: ");
                  Serial1.println(setYaw);                
              }

              else if (cmd=='R')
              {   
                  mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);                                
                  Serial1.print(ax);
                  Serial1.print(" ");
                  Serial1.print(ay);
                  Serial1.print(" ");
                  Serial1.print(az);
                  Serial1.print(" ");
                  Serial1.print(" ");
                  Serial1.print(gx);
                  Serial1.print(" ");
                  Serial1.print(gy);
                  Serial1.print(" ");
                  Serial1.println(gz);                            
              }
              else if (cmd=='M')  MOTOR_INFO=MOTOR_INFO?false:true;              
              else if (cmd=='B')  Serial1.println(baro.getPressure(MS561101BA_OSR_4096));
              else if (cmd=='T')  Serial1.println(fastLoop);                
            break;      
         }        
       } 
    Serial1.flush();
   }     
}

void  getSerial()
{    
  while(Serial1.available() && (cmd == NULL || cmd == '\r' || cmd == '\n' || cmd==' '))  
      cmd = Serial1.read();            
}




