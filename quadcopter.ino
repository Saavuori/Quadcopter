


#include <PIDCont.h>
#include <I2Cdev.h>

#include <MPU6050.h>
#include <AK8975.h>

#include "Wire.h"
#include "Config.h"

MPU6050 mpu;
AK8975 mag;
float heading;

PIDCont PIDroll,PIDpitch,PIDyaw;
int PIDroll_val,PIDpitch_val,PIDyaw_val;

int m1_val,m2_val,m3_val, m4_val;

volatile float Pitch,Roll,Yaw;

volatile float pid[4][4];

volatile double setPitch = 0;  //Setpoint Pitch
volatile double setRoll = 0;  //Setpoint Roll
volatile double setYaw = 0;  //Setpoint Yawn
volatile int throttle =0;

unsigned long time = millis();
unsigned long timeMotors = millis();
unsigned long timePID= millis();
unsigned long timer = millis();

volatile boolean alarm = false;
volatile boolean run   = false;
volatile boolean tmp   = true;
volatile boolean first = true;

unsigned long tp;

void setup(){
  
    motorInit();
  
  Wire.begin();  
  
  Serial1.begin(57600);  
  while(!Serial1);
  
 TWBR = ((F_CPU / 400000L) - 16) / 2;
   
  Serial1.println("#STARTING!");
   
  sensorInit();
  PID_init();

  LED_INIT();
  LED_ON(LED_G);
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
  time=millis();
}

void loop() {   
   
  while(run)
  {  
    if(first)
    {      
      LED_ON(LED_G);
      LED_OFF(LED_R);
      PID_RESET_I();   
      first = false;
      Serial1.println("RUN");  
    }
    
    updateSensorVal();    
    PID_COMPUTE();   
    FlightControl();
    serial();     
    
  }
      
      
  updateSensorVal();
    
  PID_COMPUTE();
    
  serial();  
  
  
  
}

