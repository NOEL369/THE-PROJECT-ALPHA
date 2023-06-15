#include <joint_value.h>
#include <ros.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define degrees  90
#define SERVOMIN  125
#define SERVOMAX  575

int j1;
int j2;
int j3;
int j4;
int j5;

ros::NodeHandle  nh;
void cmd_joint( const alpha_msg::joint_value& joint_value)

{

  j1 = joint_value.joint_1;
  j2 = joint_value.joint_2;
  j3 = joint_value.joint_3;
  j4 = joint_value.joint_4;
  j5 = joint_value.joint_5;

  int pulselength1 = map(j1, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(0, 0, pulselength1);
  int pulselength2 = map(j2, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(2, 0, pulselength2);
  int pulselength3 = map(j3, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(4, 0, pulselength3);
  int pulselength4 = map(j4, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(6, 0, pulselength4);
  int pulselength5 = map(j5, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(8, 0, pulselength5);
}

ros::Subscriber<alpha_msg::joint_value> sub("alpha_angles",cmd_joint); 

void setup() {
  Serial.begin(9600);
  Serial.println("to");
  pwm.begin();
  pwm.setPWMFreq(60);  
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
}
