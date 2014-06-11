
void motorInit(){
  pinMode(MOTOR1,OUTPUT); 
  pinMode(MOTOR2,OUTPUT);
  pinMode(MOTOR3,OUTPUT);
  pinMode(MOTOR4,OUTPUT);
  
  analogWrite(MOTOR1,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR2,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR3,MOTOR_ZERO_LEVEL);
  analogWrite(MOTOR4,MOTOR_ZERO_LEVEL);
 
  Serial1.println("#Motors initialized!");
}

void motorArm(){
  analogWrite(MOTOR1,MOTOR_ARM_START);
  analogWrite(MOTOR2,MOTOR_ARM_START);
  analogWrite(MOTOR3,MOTOR_ARM_START);
  analogWrite(MOTOR4,MOTOR_ARM_START);
  
  throttle = MOTOR_ARM_START;
  Serial1.println("#Motors armed!");
}

void motorStop(){
  analogWrite(MOTOR1,0);
  analogWrite(MOTOR2,0);
  analogWrite(MOTOR3,0);
  analogWrite(MOTOR4,0); 
}


