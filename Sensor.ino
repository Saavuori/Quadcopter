int16_t gx, gy, gz,ax,ay,az,mx,my,mz;

double MX,MY;

MPU6050 mpu;
AK8975 mag(0x0C);

float heading;

//--------Baro-------//

#define MOVAVG_SIZE 32
MS561101BA baro = MS561101BA();
float movavg_buff[MOVAVG_SIZE];
int movavg_i=0;
float pressure, temperature;
//-------------------//

double dt;
uint32_t t;

void sensorInit()
{  
  mpu.initialize(); 
  mpu.setI2CBypassEnabled(true);
  
  delay(100);
  
  if(mpu.testConnection())
  {    
    Serial1.println("#MPU6050 connected succesfully!");
    
    delay(10);  
    mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000); //+/-2000 deg/s  
    mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_8); //acc +/- 8g 
    mpu.setDLPFMode(4);   
       
    mag.initialize();
     
    baro.init(MS561101BA_ADDR_CSB_LOW);     
    delay(100);
    
  int i=0;
  while(i<MOVAVG_SIZE){
    movavg_buff[i] = baro.getPressure(MS561101BA_OSR_4096); 
      if(movavg_buff[i])
        i++;
   delay(5); 
  } 
  sea_press = getAvg(movavg_buff, MOVAVG_SIZE);   
               
     kalmanX.setAngle(0);
     kalmanY.setAngle(0);

    Serial1.println("#SENSORS INITIALIZED");
  }
  else
  {  
    Serial1.println("#MPU6050 connection failed");
  }
}
   
void updateSensorVal()
{      

    dt = (double)(micros() - t) / 1000000;
    t = micros();    
    mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz); 
          
    gyroRate[0] = ((gx+gx_offset)/14.375);    
    gyroRate[1] = ((gy+gy_offset)/14.375);    
    gyroRate[2] = ((gz+gz_offset)/14.375);
          
    if(millis()-timeAccUpdate>1)
    {
                                               
         Pitch  = atan2(ax,az)*radToDeg; 
         Roll = atan(ay/sqrt(pow((az),2)+pow((ax),2)))*radToDeg;                    
         Pitch = kalmanX.getAngle(Pitch, -gyroRate[1], dt);
         Roll = kalmanY.getAngle(Roll, -gyroRate[0], dt); 
                                                                               
         timeAccUpdate=millis();       
    } 
        if(millis()-timeBaroUpdate>10)
    {
      
         temperature = baro.getTemperature(MS561101BA_OSR_4096);
         pressure = baro.getPressure(MS561101BA_OSR_4096);
         pushAvg(pressure);        
         pressure = getAvg(movavg_buff, MOVAVG_SIZE); 
         altitude = getAltitude(pressure, temperature); 
                  
         timeBaroUpdate=millis();
    }
 
    if(millis()-timePC>20 && debugMode)
    {
       timePC=millis();
       
       Serial1.print("A;");
       Serial1.print(altitude);
       Serial1.println(";");
       
       Serial1.print("T;");
       Serial1.print(temperature);
       Serial1.println(";");

       Serial1.print("R;");
       Serial1.print(Roll);
       Serial1.println(";");
       
       Serial1.print("P;");      
       Serial1.print(Pitch);
       Serial1.println(";");       
       
       Serial1.print("S;");
       if(run)
          Serial1.print("1");
       else
          Serial1.print("0");          
       Serial1.println(";");   

      
    }          
}

float getAltitude(float press, float temp) { 
  return ((pow((sea_press / press), 1/5.257) - 1.0) * (temp + 273.15)) / 0.0065;
}

void pushAvg(float val) {
  movavg_buff[movavg_i] = val;
  movavg_i = (movavg_i + 1) % MOVAVG_SIZE;
}

float getAvg(float * buff, int size) {
  float sum = 0.0;
  for(int i=0; i<size; i++) {
    sum += buff[i];
  }
  return sum / size;
}
