#ifndef __ODOMETRY_H
#define __ODOMETRY_H

#include <math.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "node_recv_app.h"
#include "node_motor.h"

//#define ODOMETRY_LENGTH 12;
extern float multiplier;           //��Ƶ�� 4
extern float deceleration_ratio;  //���ٱ� 90
extern float multiplier;           //��Ƶ�� 4
extern float pi_1_2;			 //��/2
extern float pi;              //��
extern float pi_3_2;			 //��*3/2
extern float pi_2_1;			 //��*2
extern float dt;                 //����ʱ����5ms  20ms
extern float wheel_diameter;     //����ֱ������λmmvoid odometry(float right,float left);//��̼Ƽ��㺯��
extern float line_number;

extern void odometry(SPEED_PULSE_CNT *pluse_cnt, MSG_ROS_ODOM_TYPE *odom_type);
#endif
