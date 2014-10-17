// v0.2

//#define DEBUG
#define CALIBRATION
//#define LEDS

//-------PID Config----------

#define PID_PITCH_RATE 0
#define PID_ROLL_RATE 1
#define PID_YAW_RATE 2
#define PID_PITCH_ANGLE 3
#define PID_ROLL_ANGLE 4
#define PID_YAW_ANGLE 5
#define PID_ALTITUDE_HOLD 6

#define ALT_PID_KP 20.000
#define ALT_PID_KI 0.000
#define ALT_PID_KD 0.000

#define ROLL_PID_RATE_KP  0.150
#define ROLL_PID_RATE_KI  0.000
#define ROLL_PID_RATE_KD  0.000

#define PITCH_PID_RATE_KP  0.150
#define PITCH_PID_RATE_KI  0.000
#define PITCH_PID_RATE_KD  0.000

#define YAW_PID_RATE_KP  0.800
#define YAW_PID_RATE_KI  0.000
#define YAW_PID_RATE_KD  0.000

#define ROLL_PID_ANGLE_KP  2.000
#define ROLL_PID_ANGLE_KI  0.000
#define ROLL_PID_ANGLE_KD  0.000

#define PITCH_PID_ANGLE_KP  2.000
#define PITCH_PID_ANGLE_KI  0.000
#define PITCH_PID_ANGLE_KD  0.000

#define YAW_PID_ANGLE_KP  0.000
#define YAW_PID_ANGLE_KI  0.000
#define YAW_PID_ANGLE_KD  0.000

#define PID_MAX  40.0
#define PID_MIN  -40.0

#define PID_ANGLE_MAX 200
#define PID_ANGLE_MIN -200
//-------------------------

//*********Sensor Config****************

//----------------------------------

//***********MOTOR CONFIG**************

#define MOTOR_ZERO_LEVEL  100
#define MOTOR_MAX_LEVEL  255

#define MOTOR4  5     //  1  pun
#define MOTOR3  6    //  4  vih
#define MOTOR2  9     //  2  kel
#define MOTOR1  10    //  3  sin
//--------------------------------------

//.......RX............

#define RX_ROLL 14     //PCINT2 
#define RX_PITCH 16    //PCINT3
#define RX_YAW 15      //PCINT1
#define RX_THROTTLE 8  //PCINT4
//#define RX_AUX1 11
//#define RX_AUX2 2

//........................

//***********LEDS**************

//#define LED_R 2
//#define LED_Y 3
//#define LED_G 4

//-----------------------------------------
//***********SAFETY**************

#define ALARM_LOW 1000
#define ALARM_HIGH 5000
#define ANGLE_ALARM 2000
#define DESCEND_RATE 0,98
//----------------------------------------
#define radToDeg 57,29577



