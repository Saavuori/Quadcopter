//#define DEBUG
//#define CALIBRATION
//#define LEDS


//-------PID Config----------

#define PID_PITCH_RATE 0
#define PID_ROLL_RATE 1
#define PID_YAW_RATE 2

#define PID_PITCH_ANGLE 3
#define PID_ROLL_ANGLE 4
#define PID_YAW_ANGLE 5


#define ROLL_PID_RATE_KP  0.000
#define ROLL_PID_RATE_KI  0.000
#define ROLL_PID_RATE_KD  0.000

#define ROLL_PID_RATE_MIN  -40.0
#define ROLL_PID_RATE_MAX  40.0

#define PITCH_PID_RATE_KP  0.000
#define PITCH_PID_RATE_KI  0.000
#define PITCH_PID_RATE_KD  0.000

#define PITCH_PID_RATE_MIN  -40.0
#define PITCH_PID_RATE_MAX  40.0


#define YAW_PID_RATE_KP  0.000
#define YAW_PID_RATE_KI  0.000
#define YAW_PID_RATE_KD  0.000

#define YAW_PID_RATE_MIN  -40.0
#define YAW_PID_RATE_MAX  40.0

#define PID_MIN  -40.0
#define PID_MAX   40.0
//-------------------------

//*********Sensor Config****************

#define  SPLIT  0.90 //COMP-filter nr
#define  RadToDeg 180.0/PI
#define  ACC_HPF_NR  10  //high pass filter nr
#define  GYRO_MAF_NR  3  //Moving average filter nr

#define ACC_X_OFFSET -2363
#define ACC_Y_OFFSET 872
#define ACC_Z_OFFSET 6468

#define GYRO_X_OFFSET 58
#define GYRO_Y_OFFSET 0
#define GYRO_Z_OFFSET -43


//----------------------------------

//***********MOTOR CONFIG**************

//Motor PWM Levels
#define MOTOR_ZERO_LEVEL  100
#define MOTOR_MAX_LEVEL  255

//Motor Pins
#define MOTOR1  9     //  1  pun
#define MOTOR2  10    //  4  vih
#define MOTOR4  6     //  2  kel
#define MOTOR3  13    //  3  sin


//--------------------------------------

//***********LEDS**************

#define LED_R 2
#define LED_Y 3
#define LED_G 4

//-----------------------------------------


//***********SAFETY**************

#define ALARM_LOW 10000
#define ALARM_HIGH 20000
#define ANGLE_ALARM 2000
#define DESCEND_RATE 0.99


//----------------------------------------
#define radToDeg 180.0/PI


#define SLOWLOOP 5
