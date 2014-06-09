int gX,gY,gZ,aX,aY,aZ;

void calibrateGYRO(){  
/*    
  i=0;
  gX=0;
  gY=0;
  gZ=0;

 Serial1.println("Calibrating....Dont move the board!TESDT");
  while(i<500){ 
    
    mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
    
    gX+=gx;
    gY+=gy;
    gZ+=gz;    
    i++;
  }      
    
    GYRO_X_OFFSET=(float)gX/i;
    GYRO_Y_OFFSET=(float)gY/i;
    GYRO_Z_OFFSET=(float)gZ/i;  
    
    mpu.setXGyroOffset(GYRO_X_OFFSET);
    mpu.setYGyroOffset(GYRO_Y_OFFSET);
    mpu.setZGyroOffset(GYRO_Z_OFFSET);
    
    Serial1.print(mpu.getXGyroOffset());
    Serial1.print("  ");
    Serial1.print(mpu.getYGyroOffset());
    Serial1.print("  ");
    Serial1.println(mpu.getZGyroOffset());       
    
  Serial1.println("#Ready;");
}

void calibrateACC(){  
  i=0;
  aX=0;
  aY=0;
  aZ=0;

    
 Serial1.println("#Calibrating....Dont move the board!;");
 
    Serial1.println("Offset before calibration...");    //Default 644  -1567  1532
    Serial1.print(mpu.getXAccelOffset());
    Serial1.print("  ");
    Serial1.print(mpu.getYAccelOffset());
    Serial1.print("  ");
    Serial1.println(mpu.getZAccelOffset());    
 
 
    mpu.setXAccelOffset(0);
    mpu.setYAccelOffset(0);
    mpu.setZAccelOffset(0);
 
 
  while(i<500){ 
    
    mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
    
    aX+=ax;
    aY+=ay;
    aZ+=az;    
    i++;
    delay(2);
  }      
    
    ACC_X_OFFSET=aX/i;
    ACC_Y_OFFSET=aY/i;
    ACC_Z_OFFSET=aZ/i-4096;  
    
    mpu.setXAccelOffset(ACC_X_OFFSET);
    mpu.setYAccelOffset(ACC_Y_OFFSET);
    mpu.setZAccelOffset(ACC_Z_OFFSET);
  
    Serial1.println("Offset after calibration...");    
    Serial1.print(mpu.getXAccelOffset());
    Serial1.print("  ");
    Serial1.print(mpu.getYAccelOffset());
    Serial1.print("  ");
    Serial1.println(mpu.getZAccelOffset());       
    
  Serial1.println("Ready");
  
  */
}
