void serial()
{
 
   if(Serial1.available())
   {
     time = millis();
     alarm = false;
    
     cmd = Serial1.read();
  
     
      switch(cmd)
      {
        case 'S':  //SET
                Serial1.println("SET..");
                Serial1.println(Serial1.available());
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
                
                else if(s == 'P')  //PID VALUE
                {
                    pidN  = Serial1.parseInt();
                    PID = Serial1.read();                     
                    pid[pidN][n]= Serial1.parseFloat();        
                }   

               else  if(s =='A')  //START
                {                  
                    run = true;
                    Serial1.println("#Start!");                                           
                }
                
               else if(s =='Q')   //STOP
                {
                    run = false; 
                    Serial1.println("#STOP!");
                }
               
        break;      
        case 'G':  //GET
                Serial1.println("GET..");
                Serial1.println(Serial1.available());
              if(s =='M')
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
     
     Serial1.flush();      
   }  
   
   
}
