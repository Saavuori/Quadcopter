void serial()
{
   
    
   if(Serial1.available()>1)
   {
     
     time = millis();
     alarm = false;
     getSerial();
       
      switch(cmd)
      {
        case 'S':  //SET
                
                getSerial();   
                              
                if(cmd == 'S')    //SET POINT
                {                
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
        
              getSerial();         
              if(cmd =='M')
              {
                  Serial1.print("M");
                  Serial1.print(m1_val);
                  Serial1.print(" ");
                  Serial1.print(m2_val);
                  Serial1.print(" ");
                  Serial1.print(m3_val);
                  Serial1.print(" ");
                  Serial1.println(m4_val);                  
              }
              else if (cmd=='S')
              {                          
                  Serial1.print("SetPitch: ");
                  Serial1.println(setPitch);
                  Serial1.print("SetRoll: ");
                  Serial1.println(setRoll);
                  Serial1.print("SetYaw: ");
                  Serial1.println(setYaw);
                  Serial1.print("SetThorttle: ");
                  Serial1.println(throttle);  
              }
              else if (cmd=='A')
              {                          
                  Serial1.print("Pitch: ");
                  Serial1.print(Pitch);
                  Serial1.print(" Roll: ");
                  Serial1.println(Roll);
               //  Serial1.print("Yaw: ");
               //  Serial1.println(Yaw);
              }
              else if (cmd=='G')
              {                          
                  Serial1.print(" ");
                  Serial1.print(gx_aver);
                  Serial1.print("  ");
                  Serial1.print(gy_aver);
                  Serial1.print("  ");
                  Serial1.print(gz_aver);
                  
                  Serial1.print(" ");
                  Serial1.print(gx_aver);
                  Serial1.print("  ");
                  Serial1.print(gy_aver);
                  Serial1.print("  ");
                  Serial1.print(gz_aver);
                  
              }       
        else if (cmd=='C')
              {                          
                  Serial1.print(" ");
                  Serial1.print((float)ax);
                  Serial1.print("  ");
                  Serial1.print((float)ay);
                  Serial1.print("  ");
                  Serial1.print((float)az);
                  
                  Serial1.print("  ");
                  Serial1.print((float)axf);
                  Serial1.print("  ");
                  Serial1.print((float)ayf);
                  Serial1.print("  ");
                  Serial1.println((float)azf);


              }                         
        break;      
     }  
     Serial1.flush();   
   }
}


void getSerial()
{ 
  cmd = 0;
  
  while(Serial1.available() && (cmd == NULL || cmd== 0))  
      cmd = Serial1.read(); 
    
}


