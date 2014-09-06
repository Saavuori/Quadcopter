
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

double dt;
uint32_t t;
unsigned long ts=millis();
unsigned long tf=micros();

double kalAngleX, kalAngleY;


/*****BARO*****/

#define MOVAVG_SIZE 32
float movavg_buff[MOVAVG_SIZE];
int movavg_i=0;

/***************/
void sensorInit()
{
  
  mpu.initialize(); 
  delay(10);  
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000); //+/-2000 deg/s  
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_8); //acc +/- 8g 
<<<<<<< HEAD
  mpu.setDLPFMode(4);
  mpu.setI2CBypassEnabled(true);
=======
  mpu.setDLPFMode(5);
  
  Serial1.println("MPU6050 Initialized!");
 
  mag.begin();
  mag.setRange(HMC5883L_RANGE_1_3GA);
  mag.setMeasurementMode(HMC5883L_CONTINOUS);
  mag.setDataRate(HMC5883L_DATARATE_30HZ);
  mag.setSamples(HMC5883L_SAMPLES_4);
  
  Serial1.println("MAG Initialized!");
  
  bar.init();
  
  
  
}


void updateSensorVal(){
>>>>>>> origin/master
  
  /*
    mpu.setXGyroOffset(GYRO_X_OFFSET);
    mpu.setYGyroOffset(GYRO_Y_OFFSET);
    mpu.setZGyroOffset(GYRO_Z_OFFSET);
    
    mpu.setXAccelOffset(ACC_X_OFFSET);
    mpu.setYAccelOffset(ACC_Y_OFFSET);
    mpu.setZAccelOffset(ACC_Z_OFFSET);
  */  
  baro.init(MS561101BA_ADDR_CSB_LOW); 
      
  delay(100);
  
  
  
  for(int i=0; i<MOVAVG_SIZE; i++) {
    movavg_buff[i] = baro.getPressure(MS561101BA_OSR_4096);
  }
  
  ZeroPressure = getAvg(movavg_buff, MOVAVG_SIZE);
  
  kalmanX.setAngle(0);
  kalmanY.setAngle(0);
   
  Serial1.println("#SENSORS INITIALIZED");
}
   
void updateSensorVal(){
    
     dt = (double)(micros() - t) / 1000000;
     t = micros();
     
     mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz); 
          
     gyroXrate = gx/14.375;
     gyroYrate = gy/14.375;
     gyroZrate = gz/14.375;
 
 
if(millis()-AngleModeTime>SLOWLOOP){

    
    Pitch  = atan2(ax,az)*RadToDeg; 
    Roll = atan(ay/sqrt(pow((az),2)+pow((ax),2)))*RadToDeg; 
        
        if ((Pitch < -90 && kalAngleY > 90) || (Pitch > 90 && kalAngleY < -90))
            kalmanY.setAngle(Pitch); 
        else
           kalAngleY = kalmanY.getAngle(Pitch, gyroYrate, dt); // Calculate the angle using a Kalman filter

        if (abs(Pitch) > 90)
            gyroXrate = -gyroXrate; // Invert rate, so it fits the restriced accelerometer reading
            
            kalAngleX = kalmanX.getAngle(Roll, gyroXrate, dt); // Calculate the angle using a Kalman filter
            
            
     Pitch = kalAngleY;
     Roll = kalAngleX;
      
      
         temperature = baro.getTemperature(MS561101BA_OSR_4096);
         press = baro.getPressure(MS561101BA_OSR_4096);
         pushAvg(press);
        
        press = getAvg(movavg_buff, MOVAVG_SIZE);
         
        Alt = getAltitude(press, temperature);

                            
   AngleModeTime=millis();
        
 }  
  
 gyroXrate=-gyroXrate*dt;
 gyroYrate=-gyroYrate*dt;
 gyroZrate=-gyroZrate*dt;
 
 
 if(millis()-time1>1000){
   time1=millis();
   Serial1.print("A;");
   Serial1.print(Alt);
   Serial1.println(";");
 }
}

float getAltitude(float press, float temp) {
   return ((pow((ZeroPressure / press), 1/5.257) - 1.0) * (temp + 273.15)) / 0.0065;
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




