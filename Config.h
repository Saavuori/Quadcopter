//-------PID Config----------

#define ROLL_PID_KP  0.250
#define ROLL_PID_KI  0.950
#define ROLL_PID_KD  0.011
#define ROLL_PID_MIN  -50.0
#define ROLL_PID_MAX  50.0

#define PITCH_PID_KP  0.250
#define PITCH_PID_KI  0.950
#define PITCH_PID_KD  0.011
#define PITCH_PID_MIN  -50.0
#define PITCH_PID_MAX  50.0

#define YAW_PID_KP  0.680
#define YAW_PID_KI  0.500
#define YAW_PID_KD  0.0001
#define YAW_PID_MIN  -50.0
#define YAW_PID_MAX  50.0
//-------------------------

//*********Sensor Config****************

#define  SPLIT  0.90 //COMP-filter nr
#define  RadToDeg 180.0/PI 
#define  ACC_HPF_NR  10  //high pass filter nr
#define  GYRO_MAF_NR  3  //Moving average filter nr
//*************************************

//***********MOTOR CONFIG**************

//Motor PWM Levels
#define MOTOR_ZERO_LEVEL  125
#define MOTOR_ARM_START  140
#define MOTOR_MAX_LEVEL  254

//Motor Pins
#define MOTOR1  3
#define MOTOR2  5
#define MOTOR3  6
#define MOTOR4  9

//*************************************

//***********LEDS**************

#define LED_R 10
#define LED_Y 11
#define LED_G 12

//*************************************


//***********SAFETY**************

#define ALARM_LOW 10000
#define ALARM_HIGH 20000
#define DESCEND_RATE 0.95 // per/s

//*************************************


