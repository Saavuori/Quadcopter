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

volatile float gx_aver=0;
volatile float gy_aver=0;
volatile float gz_aver=0;

int accx_temp=0;
int accy_temp=0;
int accz_temp=0;

char buffer[128];

double pid[8][3];
int serialdata;
int inbyte;
volatile int cmd;
int i,pidN,PID,n,s;
int biasAX=0,biasAY=0,biasAZ=0;
int biasGX=0,biasGY=0,biasGZ=0;

int setPitch = 0;  //Setpoint Pitch
int setRoll = 0;  //Setpoint Roll
int setYaw = 0;  //Setpoint Yawn
int throttle =0;


float accx, accy;

float accPitch=0,gyroPitch=0;
float accRoll2=0,accPitch2=0; //Test
float accRoll=0, gyroRoll=0;

unsigned long time = millis();
unsigned long timer = millis();

boolean alarm = false;
boolean run = false;

void setup(){
  
  
  Wire.begin();  
  
  Serial1.begin(57600);  
  while(!Serial1);
  
  TWBR = ((F_CPU / 400000L) - 16) / 2;
   
  Serial1.println("#STARTING!");
   
  sensorInit();
  PID_init();
  motorInit();
  LED_INIT();
  ledON(LED_G);
  Serial1.println("#READY...");
  
  while(!run)
  {     
      serial();  
      LED_ON(LED_Y);
      if(run) 
          motorArm();           
  }LED_OFF(LED_Y);
  
  tp=millis();  
  timer=millis(); 
}

void loop() {   
   
  while(run){
    
    LED_ON(LED_G);
    LED_OFF(LED_R);    
    
    if((millis()-time) > ALARM_LOW && !alarm ){
          setPitch=0;
          setRoll=0;
          alarm = true;
          Serial1.println("#AlarmLow;");
      }  
      if((millis()-time)>ALARM_HIGH && millis()-timer>1000){  
          timer = millis();   
          throttle = throttle*DESCEND_RATE;   //todo: if baro decend
          Serial1.println("#Alarmhigh;");
      }
 
    updateSensorVal(); 
    
    FlightControl();
    
    serial();
   

    
  }
  LED_ON(LED_R);
  LED_OFF(LED_G);
  motorStop();
  
  setPitch=0;
  setRoll=0;
  setYaw=0;
  throttle=0;
    
  serial();  
}

