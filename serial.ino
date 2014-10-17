volatile int cmd;
boolean validCMD = false;

void serial()
{  
   if(Serial1.available()>1)
   {     
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
                 
                if(cmd == 'P' && PIDS_ENABLED == true)  PID_CHANGE(Serial1.parseInt(),Serial1.parseInt(),Serial1.parseFloat());                                                                  
                else if(cmd == 'A') run = true;                                                       
                else if(cmd == 'Q') run = false;  
                
                #ifdef CALIBRATION
                else if(cmd =='C')   //CALIBRATION 
                {                    
                    calibrateGYRO();
                    //calibrateACC();
                }       
                #endif
                            
                else if(cmd =='E')  PIDS_ENABLED = PIDS_ENABLED?false:true;
                else if(cmd =='L')  rxLimits[Serial1.parseInt()]=Serial1.parseInt();                
                else if(cmd =='R')  angleMode = angleMode?false:true;
                else if(cmd =='D')  debugMode = debugMode?false:true;
                else if(cmd =='D')  throttleRateMode = throttleRateMode?false:true;

                
                else if(cmd =='H')  
                {
                  altitudeHold = altitudeHold?false:true;
                  setAltitude = altitude;
                } 
                             

                else if(cmd =='M')   //MOTOR TEST
                {    
                    m[0]=MOTOR_ZERO_LEVEL;
                    m[1]=MOTOR_ZERO_LEVEL;    
                    m[2]=MOTOR_ZERO_LEVEL;    
                    m[3]=MOTOR_ZERO_LEVEL;                      
                    for(int i=0;i<4;i++)
                    {
                          delay(1000);
                          m[i]=110;
                          motorWrite();
                          
                    }delay(1000);   
                    motorStop();               
                }      
        
            break;
          //*******************GET****************************      
            case 'G': 
        
              cmd = Serial1.read();
                                        
              if (cmd=='G')
              {  
                for(int i=0;i<3;i++){
                  Serial1.print(gyroRate[i]);
                  Serial1.print("  ");                
                }Serial1.println("");
              }
              else if (cmd=='R')
              {
                     mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz); 
                     mag.getHeading(&mx, &my, &mz);               
                     Serial1.println("# ax ay az    gx gy gz   mx my mz");
                     Serial1.print(ax);
                     Serial1.print(" ");
                     Serial1.print(ay);
                     Serial1.print(" ");
                     Serial1.print(az);
                     Serial1.print("    ");
                     Serial1.print(gx);
                     Serial1.print(" ");
                     Serial1.print(gy);
                     Serial1.print(" ");
                     Serial1.print(gz);
                     Serial1.print("    ");
                     Serial1.print(mx);
                     Serial1.print(" ");
                     Serial1.print(my);
                     Serial1.print(" ");
                     Serial1.println(mz);  
                
              }
              
              else if (cmd=='T')  Serial1.println(looptime);                
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




