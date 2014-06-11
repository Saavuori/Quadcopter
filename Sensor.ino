float gx_temp[GYRO_MAF_NR]={
  0.0,0.0};
float gy_temp[GYRO_MAF_NR]={
  0.0,0.0};
float gz_temp[GYRO_MAF_NR]={
  0.0,0.0};
  
int ax, ay, az;
int gx, gy, gz;

float axf,ayf,azf,gxf,gyf,gzf;

float dt;
unsigned long ts=millis();
unsigned long tf=micros();
unsigned long t;


void sensorInit()
{
  
  mpu.initialize();     
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000); //+/-2000 deg/s  
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_8); //acc +/- 8g 
  mpu.setDLPFMode(5);
 
  mag.begin();
  mag.setRange(HMC5883L_RANGE_1_3GA);
  mag.setMeasurementMode(HMC5883L_CONTINOUS);
  mag.setDataRate(HMC5883L_DATARATE_30HZ);
  mag.setSamples(HMC5883L_SAMPLES_4);
}


void updateSensorVal(){
  
  mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);   
  
  Vector norm = mag.readNormalize();
  
  filterACC();  
  
  heading = atan2(norm.YAxis, norm.XAxis)*RadToDeg;
  
  t = millis();
  dt = (float)(t-tp)/1000.0;
    
  accPitch   = atan2(ay,sqrt(pow((az),2)+pow((ax),2)))*RadToDeg; 
  //accRoll    = atan2(ax,sqrt(pow((az),2)+pow((ay),2)))*RadToDeg; 
  
  //accPitch2  = atan2(ay,az)*RadToDeg; 
  accRoll2   = atan2(ax,az)*RadToDeg; 
    
  Pitch = SPLIT*(-gx/14.375*dt+Pitch)+(1.0-SPLIT)*accPitch;    //gyroPitch += (-gx/14.375)*dt;
  Roll  = SPLIT*( gy/14.375*dt+Roll)+(1.0-SPLIT)*accRoll2;      //gyroRoll  += ( gy/14.375)*dt;
  
  tp=t; 
  
  
}

void filterACC()
{  
  axf=((ACC_HPF_NR*axf)+((100-ACC_HPF_NR)*(float)ax))/100;
  ayf=((ACC_HPF_NR*ayf)+((100-ACC_HPF_NR)*(float)ay))/100;
  azf=((ACC_HPF_NR*azf)+((100-ACC_HPF_NR)*(float)az))/100; 
}


