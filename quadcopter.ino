#include <PID.h>
#include <MS561101BA.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include "Wire.h"
#include "Config.h"
#include "Kalman.h" 

MPU6050 mpu;
MS561101BA baro = MS561101BA();

PID pids[6];  

double SetX=0,SetY=0,SetZ=0;
double gyroXrate;
double gyroYrate;
double gyroZrate;

int PID_PITCH_RATE_VAL,PID_ROLL_RATE_VAL,PID_YAW_RATE_VAL;
int m[4]; //motors

Kalman kalmanX, kalmanY,kalmanZ;

volatile double Pitch,Roll,Yaw;
volatile float Alt;
volatile float ZeroPressure;

float press, temperature;

volatile double setPitch = 0;  //Setpoint Pitch
volatile double setRoll = 0;  //Setpoint Roll
volatile double setYaw = 0;  //Setpoint Yawn
volatile int throttle = 0;

unsigned long time = millis();
unsigned long AngleModeTime = millis();
unsigned long AnglePIDTime = millis();
unsigned long loopTime = millis();
unsigned long timeMotors = millis();
unsigned long timePID= millis();
unsigned long timer = millis();
unsigned long angleTime = millis();
unsigned long time1 = millis();

//States
boolean alarm = false;
boolean run   = false;
boolean tmp   = true;
boolean run_first = true;
boolean stop_first = true;
boolean alarm_low_first = true;
boolean alarm_high_first = true;
boolean MOTOR_INFO = false;
boolean PIDS_ENABLED = false;

unsigned long tp;


int fastLoop;


void setup(){
    
  Wire.begin();  
  
  Serial1.begin(57600);  
  while(!Serial1);
  
   TWBR = 24;
   
  Serial1.println("#STARTING!");
    
    sensorInit();
    PID_init();
    motorInit();
 // LED_INIT();
 
  Serial1.println("#PRESS START TO ACTIVATE QUADCOPTER...");
  
  while(!run) 
  {         
      serial();       
      updateSensorVal();
      PID_COMPUTE();
  }
   
  tp=millis(); 
  timer=millis(); 
  time=millis();
}

void loop() 
{    
    while(run)
    {  
      loopTime = millis();  
          if(run_first)
          { 
              Serial1.println("#START");
              angleTime = millis();     
              PID_RESET_I();     
              run_first = false;
              stop_first = true;
          }
      updateSensorVal();   
      PID_COMPUTE();       
      FlightAlarms();
      serial(); 
      motorWrite(); 
   
      fastLoop = (fastLoop + millis()-loopTime)/2;      
    }     
    
    if(stop_first)
    {      
          Serial1.println("#STOP");
          motorStop();  
          setPitch=0;
          setRoll=0;
          setYaw=0;  
          throttle=0;     
          run_first = true;
          stop_first = false;
    }
        
    updateSensorVal();
    PID_COMPUTE();
    serial();  
    
}
