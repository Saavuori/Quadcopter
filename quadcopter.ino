#include <I2Cdev.h>
#include "Wire.h"
#include "Config.h"
#include <MPU6050.h>
MPU6050 mpu;

int16_t r[9]; 

//RX
volatile int rxVal[6] = {0,0,0,0,0,0};
double rxLimits[3] = {255,45,45};
//Gyro
double gyroRate[6];
//Pids
volatile int PID_PITCH_VAL,PID_ROLL_VAL,PID_YAW_VAL,PID_ALT_VALUE;

//times
volatile unsigned long Timer[5] = {millis(),millis(),millis(),millis(),millis()};
volatile unsigned long TimerUpdate[5] = {5,20,20,0,0};


volatile unsigned long Time = millis();
volatile unsigned long flightAlarm1 = millis();
volatile unsigned long flightAlarm2 = millis();
volatile unsigned long tp;
volatile unsigned long looptime=micros();
//volatile unsigned long timePC = millis();
volatile unsigned long timeSerial = millis();

//States
volatile boolean alarm = true;
volatile boolean run   = false;
volatile boolean run_first = true;
volatile boolean stop_first = true;
volatile boolean PIDS_ENABLED = false;
volatile boolean debugMode = false;
volatile boolean debugMotors = false;
volatile boolean debugRx = false;
volatile boolean debugRaw = false;
volatile boolean pidResetI = false;
//Flight Modes
volatile boolean angleMode = true;
volatile boolean altitudeHold = false;
//Other
volatile double data[DATASIZE];
volatile int m[4] = {0,0,0,0}; //motors
volatile int Set[5] = {0,0,0,0,0};
double setAltitude=0;

void setup()
{      
  Wire.begin();  
  Serial1.begin(115200);   
  delay(100);
  Serial1.println("*****************");
  Serial1.println("#INITIAL SETUP...");
    
  sensorInit();
  PID_init();
  motorInit();
  rxInit();
      
  //led_init();  
  //led_ON(LED_G); 
  Serial1.println("#PRESS START TO ACTIVATE QUADCOPTER...");
  
    while(!run)
  {
    Time = micros();  
    rxValues();
    updateSensorVal(); 
    PID_COMPUTE(); 
    serial();
    telemetry();
             
    data[LOOPTIME] = micros()-Time;
  }
     
  tp=millis(); 
  flightAlarm1=millis();
}

void loop() 
{    
  Time = micros();  
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
      FlightAlarms(); 
      updateSensorVal(); 
      
     if(millis()-Timer[MAIN]>TimerUpdate[MAIN])
     {
      Timer[MAIN]=millis();
      PID_COMPUTE();       
      motorWrite();
     }
      
      telemetry();
      serial();
      
      data[LOOPTIME] = micros()-Time;
           
    }
   
    if(stop_first)
    {     
          Serial1.println("#STOP");
          motorStop();
          data[THROTTLE]=0;     
          run_first = true;
          stop_first = false;
    }
      rxValues();
      updateSensorVal();   
      PID_COMPUTE();       
      serial();
      telemetry();
      
  data[LOOPTIME] = micros()-Time;
}
