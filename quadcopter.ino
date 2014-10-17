#include <AK8975.h>
#include <PID.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <MS561101BA.h>
#include "Wire.h"
#include "Config.h"
#include "kalman.h"

//RX
volatile int rxVal[4];
double rxLimits[3] = {255,90,90};

//Gyro
int Set[3];
double gyroRate[3];
int gx_offset,gy_offset,gz_offset;
//ACC
int ax_offset,ay_offset,az_offset;
//Pids
PID pids[7];  
int PID_PITCH_RATE_VAL,PID_ROLL_RATE_VAL,PID_YAW_RATE_VAL,PID_PITCH_ANGLE_VAL,PID_ROLL_ANGLE_VAL,PID_YAW_ANGLE_VAL,PID_ALT_VALUE;

//times
unsigned long Time = millis();
unsigned long timeMotors = millis();
unsigned long flightAlarm1 = millis();
unsigned long flightAlarm2 = millis();
unsigned long tp;
unsigned long looptime=micros();
unsigned long timePC = millis();
unsigned long timeAccUpdate = millis();
unsigned long timeBaroUpdate = millis();
unsigned long temp = millis();


//States
boolean alarm = false;
boolean run   = false;
boolean tmp   = true;
boolean run_first = true;
boolean stop_first = true;
boolean PIDS_ENABLED = false;
boolean debugMode = false;

//Flight Modes
boolean angleMode = true;
boolean altitudeHold = false;

//Other
int m[4]; //motors
volatile int throttle = 0;
double altitude=0,setAltitude=0;
volatile float sea_press= 1013.25;

double Pitch,Roll;

Kalman kalmanX,kalmanY, kalmanA;


void setup()
{    
  
  Wire.begin();  
  TWBR = 12;
  Serial1.begin(57600);       
  Serial1.println("#STARTING!");
    
  sensorInit();
  PID_init();
  motorInit();
  rxInit();    
 
  Serial1.println("#PRESS START TO ACTIVATE QUADCOPTER...");
  
    while(!run)
  {
    rxValues();
    updateSensorVal(); 
    PID_COMPUTE(); 
    serial(); 
    
      if(rxVal[0]<1250&&rxVal[0]>1100&&rxVal[1]<1200&&rxVal[2]<1200 )
        run = true;
  }
     
  tp=millis(); 
  flightAlarm1=millis();
}

void loop() 
{    
    while(run)
    {  
      Time = micros();  
          if(run_first)
          {                         
              PID_RESET_I();
              run_first = false;
              stop_first = true;
              Serial1.println("#START");
          }
      rxValues();
      updateSensorVal();   
      PID_COMPUTE();       
      FlightAlarms();
      serial();
      motorWrite(); 
      looptime = micros()-Time;
    }
   
    if(stop_first)
    {      
          Serial1.println("#STOP");
          motorStop();
          throttle=0;     
          run_first = true;
          stop_first = false;
    }
      rxValues();
      updateSensorVal();   
      PID_COMPUTE();       
     // FlightAlarms();
      serial();
     // motorWrite(); 
    
}
