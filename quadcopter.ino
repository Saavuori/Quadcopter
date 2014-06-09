#include <HMC5883L.h>
#include <PIDCont.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include "Wire.h"
#include "Config.h"

MPU6050 mpu;
HMC5883L mag;

float GYRO_X_OFFSET;
float GYRO_Y_OFFSET;
float GYRO_Z_OFFSET;

int ACC_X_OFFSET;
int ACC_Y_OFFSET;
int ACC_Z_OFFSET;

float heading;

PIDCont PIDroll,PIDpitch,PIDyaw;

int m1_val,m2_val,m3_val,m4_val; // Motor-values

unsigned long tp;

float Pitch,Roll;

float gx_aver=0;
float gy_aver=0;
float gz_aver=0;

int accx_temp=0;
int accy_temp=0;
int accz_temp=0;

char buffer[128];

double pid[8][3];
int i,cmd,pidN,PID,n,s;
int biasAX=0,biasAY=0,biasAZ=0;
int biasGX=0,biasGY=0,biasGZ=0;

int setPitch = 0;  //Setpoint Pitch
int setRoll = 0;  //Setpoint Roll
int setYaw = 0;  //Setpoint Yawn

float accx, accy;

float accPitch=0,gyroPitch=0;
float accRoll2=0,accPitch2=0; //Test
float accRoll=0, gyroRoll=0;

int throttle=MOTOR_ZERO_LEVEL;

unsigned long time = millis();
unsigned long timer = millis();

unsigned long alarmLow  = 5000;
unsigned long alarmHigh = 10000;

boolean alarm = false;
boolean run = false;

void setup(){
  
  
  Wire.begin();  
  Serial1.begin(57600);  
  while(!Serial1);
   
  Serial1.println("#STARTING!");
   
  //sensorInit();
  PID_init();
  motorInit();
  
  Serial1.println("#READY...");
  
  while(!run)
  {     
      serial();  
      
      if(run)  
          motorArm();       
  }
  
  tp=millis();  
  timer=millis(); 
}


void loop() {   
   
  while(run){
      if((millis()-time) > alarmLow && !alarm ){
          setPitch=0;
          setRoll=0;
          alarm = true;
          Serial1.println("#AlarmLow;");
      }  
      if((millis()-time)>alarmHigh && millis()-timer>1000){  
          timer = millis();   
          throttle = throttle*0.95;   //todo: if baro decend
          Serial1.println("#Alarmhigh;");
      }
 
    //updateSensorVal(); 
    FlightControl();
    serial();
  }
  
  motorStop();
  
  setPitch=0;
  setRoll=0;
  setYaw=0;
  throttle=0;
    
  serial();  
}

