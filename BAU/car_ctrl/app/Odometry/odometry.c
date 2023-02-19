#include "odometry.h"
#include "node_motor.h"
#include "cli_uart.h"
#include <math.h>


/***********************************************  ���  *****************************************************************/

float position_x=0,position_y=0,oriention=0,velocity_linear=0,velocity_angular=0;

/***********************************************  ����  *****************************************************************/

extern float odometry_right,odometry_left;//���ڵõ����������ٶ�

/***********************************************  ����  *****************************************************************/

float wheel_interval= 170.0859f;//    272.0f;        //  1.0146
//float wheel_interval=276.089f;    //���У��ֵ=ԭ���/0.987

float multiplier=1.0f;           //��Ƶ�� 4
float deceleration_ratio=75.0f;  //���ٱ� 90
float wheel_diameter=65.0f;     //����ֱ������λmm
float pi_1_2=1.570796f;			 //��/2
float pi=3.141593f;              //��
float pi_3_2=4.712389f;			 //��*3/2
float pi_2_1=6.283186f;			 //��*2
float dt=0.005f;                 //����ʱ����5ms  20ms
float line_number=44.0f;       //�������� 4096




//float oriention_1=0;

//uint8_t once=1;

/****************************************************************************************************************/

#if 0
//��̼Ƽ��㺯��
//���� ʵʱת��
void odometry(float right,float left)
{	
	if(once)  //����������һ��
	{
		const_frame=wheel_diameter*pi/(line_number*multiplier*deceleration_ratio);  //v = 2*pi *r*ת��/ת�ٱ�  mm/s
		const_angle=const_frame/wheel_interval;
		once=0;
	}
    
	distance_sum = 0.5f*(right+left);//�ں̵ܶ�ʱ���ڣ�С����ʻ��·��Ϊ�����ٶȺ�    r/min
	distance_diff = right-left;//�ں̵ܶ�ʱ���ڣ�С����ʻ�ĽǶ�Ϊ�����ٶȲ�

    //���������ֵķ��򣬾�����ʱ���ڣ�С����ʻ��·�̺ͽǶ���������
//     odometry_left = 1;
//     odometry_right = 1;
	if((odometry_right>0)&&(odometry_left>0))            //���Ҿ���
	{
		delta_distance = distance_sum;
		delta_oriention = distance_diff;
	}
	else if((odometry_right<0)&&(odometry_left<0))       //���Ҿ���
	{
		delta_distance = -distance_sum;
		delta_oriention = -distance_diff;
	}
	else if((odometry_right<0)&&(odometry_left>0))       //�����Ҹ�
	{
		delta_distance = -distance_diff;
		delta_oriention = -2.0f*distance_sum;		
	}
	else if((odometry_right>0)&&(odometry_left<0))       //������
	{
		delta_distance = distance_diff;
		delta_oriention = 2.0f*distance_sum;
	}
	else
	{
		delta_distance=0;
		delta_oriention=0;
	}
    
	oriention_interval = delta_oriention * const_angle;//����ʱ�����ߵĽǶ�	
	oriention = oriention + oriention_interval;//�������̼Ʒ����
	oriention_1 = oriention + 0.5f * oriention_interval;//��̼Ʒ��������λ���仯���������Ǻ�������
	
    sin_ = sin(oriention_1);//���������ʱ����y����
	cos_ = cos(oriention_1);//���������ʱ����x����
	
    position_x = position_x + delta_distance * cos_ * const_frame;//�������̼�x����
	position_y = position_y + delta_distance * sin_ * const_frame;//�������̼�y����
    
	velocity_linear = delta_distance*const_frame / dt;//�������̼����ٶ�
	velocity_angular = oriention_interval / dt;//�������̼ƽ��ٶ�
	
    //����ǽǶȾ���
	if(oriention > pi)
	{
		oriention -= pi_2_1;
	}
	else
	{
		if(oriention < -pi)
		{
			oriention += pi_2_1;
		}
	}
}
#else
//��̼Ƽ��㺯��
//���� ʵʱת��
void odometry(SPEED_PULSE_CNT *pluse_cnt, MSG_ROS_ODOM_TYPE *odom_type)
{	
	static float oriention_1 = 0;
	static uint8_t once = 1;
	static double const_frame = 0.0f, const_angle = 0.0f, distance_sum = 0.0f;
	float distance_diff = 0;
	float delta_distance = 0, delta_oriention = 0;	 //����ʱ�������˶��ľ���
	float oriention_interval = 0;  //dtʱ���ڷ���仯ֵ
	float sin_=0;		 //�Ƕȼ���ֵ
	float cos_=0;

	if (once)  //����������һ��
	{
		const_frame = wheel_diameter*pi/(line_number*multiplier*deceleration_ratio);  //v = 2*pi *r*ת��/ת�ٱ�  mm/s
		const_angle = const_frame/wheel_interval;
		once=0;
		LOGI("one %lf %lf\r\n", const_angle, const_frame);
	}
//    LOGI("pluse_cnt %d %d", pluse_cnt->right_cnt, pluse_cnt->left_cnt);
	distance_sum = 0.5f * ((int32_t)pluse_cnt->right_cnt + (int32_t)pluse_cnt->left_cnt);//�ں̵ܶ�ʱ���ڣ�С����ʻ��·��Ϊ�����ٶȺ�    r/min
	distance_diff = ((int32_t)pluse_cnt->right_cnt - (int32_t)pluse_cnt->left_cnt);//�ں̵ܶ�ʱ���ڣ�С����ʻ�ĽǶ�Ϊ�����ٶȲ�
	if(distance_diff > 100)
	{
//		distance_diff = 0;
	}

    //���������ֵķ��򣬾�����ʱ���ڣ�С����ʻ��·�̺ͽǶ���������
    
	if((odometry_right>0)&&(odometry_left>0))            //���Ҿ���
	{
		delta_distance = distance_sum;
		delta_oriention = distance_diff;
		//LOGI("pluse_cnt %d %d", pluse_cnt->right_cnt, pluse_cnt->left_cnt);
		//LOGI("delta %f %f\r\n", distance_sum, distance_diff);
		//LOGI("delta %f %f\r\n", delta_distance, delta_oriention);
	}
	else if((odometry_right<0)&&(odometry_left<0))       //���Ҿ���
	{
		delta_distance = -distance_sum;
		delta_oriention = -distance_diff;
	}
	else if((odometry_right<0)&&(odometry_left>0))       //�����Ҹ�
	{
		delta_distance = -distance_diff;
		delta_oriention = -2.0f*distance_sum;		
	}
	else if((odometry_right>0)&&(odometry_left<0))       //������
	{
		delta_distance = distance_diff;
		delta_oriention = 2.0f*distance_sum;
	}
	else
	{
		delta_distance=0;
		delta_oriention=0;
	}
    
	oriention_interval = delta_oriention * const_angle;//����ʱ�����ߵĽǶ�
//	LOGI("int %f\r\n", oriention_interval);
	odom_type->theta_data = odom_type->theta_data + oriention_interval;//�������̼Ʒ����
	oriention_1 = odom_type->theta_data + 0.5f * oriention_interval;//��̼Ʒ��������λ���仯���������Ǻ�������
//	LOGI("oriention_1 %f\r\n", oriention_1);
	
    sin_ = sin(oriention_1);//���������ʱ����y����
	cos_ = cos(oriention_1);//���������ʱ����x����
	
//	LOGI("int %f %f\r\n", sin_, cos_);

	odom_type->x_data = odom_type->x_data + delta_distance * cos_ * const_frame;//�������̼�x����
	odom_type->y_data = odom_type->y_data + delta_distance * sin_ * const_frame;//�������̼�y����
//	LOGI("int %f %f\r\n", odom_type->x_data, odom_type->y_data);

	odom_type->vel_linear = delta_distance*const_frame / dt;//�������̼����ٶ�
	odom_type->vel_angular = oriention_interval / dt;//�������̼ƽ��ٶ�
	
	if (odom_type->theta_data > pi)
	{
		odom_type->theta_data -= pi_2_1;
	}
	else
	{
		if (odom_type->theta_data < -pi)
		{
			odom_type->theta_data += pi_2_1;
		}

	}
	
	
	odom_type->actual_left_speed = ((float)pluse_cnt->left_cnt) * 200* pi * wheel_diameter / (deceleration_ratio *line_number) ;
	odom_type->actual_right_speed = ((float)pluse_cnt->right_cnt) * 200* pi * wheel_diameter / (deceleration_ratio *line_number);	
}

#endif

