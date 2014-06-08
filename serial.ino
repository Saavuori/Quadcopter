void serial()
{
 
   if(Serial1.available())
   {
     time = millis();
     alarm = false;
   
     cmd   = Serial1.read();
   
      switch(cmd)
      {
      
        case 'S':  //SET
      
                s = Serial1.read();
                
                if(s == 'S')    //SET POINT
                {                
                   s = Serial1.read();
                   
                      if(s=='P')
                          setPitch = Serial1.parseFloat(); 
                      if(s=='R')
                          setRoll  = Serial1.parseFloat(); 
                      if(s=='Y')
                          setYaw  = Serial1.parseFloat(); 
                }     
                
                if(s == 'P')  //PID VALUE
                {
                    pidN  = Serial1.parseInt();
                    PID = Serial1.read();                     
                    pid[pidN][n]= Serial1.parseFloat();        
                }   

                if(s =='A')  //START
                {                  
                    run = true;
                    Serial1.println("#Start!;");                                           
                }
                
                if(s =='Q')   //STOP
                {
                    run = false; 
                    Serial1.println("#STOP!");
                }
               
        break;      
        case 'G':  //GET
      
               s = Serial1.read();
      
              if(s =='M')
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
     
        Serial1.println("Unkown command: "+ cmd);        
     }Serial1.flush();      
   }  
}
