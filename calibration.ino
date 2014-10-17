#ifdef CALIBRATION

float gX,gY,gZ,aX,aY,aZ;

void calibrateGYRO()
{    
  int i=0;
  gX=0;
  gY=0;
  gZ=0;  
  
 Serial1.println("Calibrating gyro. Dont move the board!");
 delay(10);
  while(i<500){ 
    
    mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
        
    gX+=gx;
    gY+=gy;
    gZ+=gz;    
    i++;
    delay(4);
  }         
          
    gx_offset = -gX/i;
    gy_offset = -gY/i;
    gz_offset = -gZ/i;
 
  Serial1.println("#GYRO Ready;");
}
/*

void calibrateACC(){  
  int i=0;
  aX=0;
  aY=0;
  aZ=0;

    
 Serial1.println("#Calibrating accelometer. Dont move the board!;");
 
    Serial1.println("Offset before calibration...");    //Default 644  -1567  1532
    Serial1.print(mpu.getXAccelOffset());
    Serial1.print("  ");
    Serial1.print(mpu.getYAccelOffset());
    Serial1.print("  ");
    Serial1.println(mpu.getZAccelOffset());    
 
 
    Serial1.println("Set offset to zero");
    mpu.setXAccelOffset(0);
    mpu.setYAccelOffset(0);
    mpu.setZAccelOffset(0);
   Serial1.println("RAW values:");
   
   delay(50);
   
     mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);                
     Serial1.println("# ax ay az    gx gy gz ");
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
   
  while(i<500){ 
    
    mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
    
    aX+=ax;
    aY+=ay;
    aZ+=az;    
    i++;
    delay(10);
  }         
    Serial1.print("aX:");
    Serial1.println(aX);
    
    Serial1.print("aY:");
    Serial1.println(aY);
    
    Serial1.print("aZ:");
    Serial1.println(aZ);
    
    
    mpu.setXAccelOffset((int)aX/i);
    mpu.setYAccelOffset((int)aY/i);
    mpu.setZAccelOffset((int)aZ/i-4096);   
    
    
    mpu.setXAccelOffset(-2373);
    mpu.setYAccelOffset(874);
    mpu.setZAccelOffset(6467);
    
    Serial1.println("Offset after calibration...");    
    Serial1.print(mpu.getXAccelOffset());
    Serial1.print("  ");
    Serial1.print(mpu.getYAccelOffset());
    Serial1.print("  ");
    Serial1.println(mpu.getZAccelOffset());       
    
  Serial1.println("#ACC Ready");
  
}
*/

#endif
