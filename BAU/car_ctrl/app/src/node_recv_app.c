#include "node_recv_app.h"
#include "cli_uart.h"

/***********************************************  ˵��  *****************************************************************
*
*   1.���ڽ���
*    ��1�����ݣ�С���������ٶ�,��λ:mm/s���������ݶ�Ϊ   float�ͣ�float��ռ4�ֽڣ�
*    ��2����ʽ��10�ֽ� [�����ٶ�4�ֽ�][�����ٶ�4�ֽ�][������"\r\n"2�ֽ�]
*		 [��ʼ��1�ֽ�][�����1�ֽ�][����2�ֽ�][�����ٶ�4�ֽ�][�����ٶ�4�ֽ�] [������"\r\n"2�ֽ�]  14�ֽ�
*		  0xfa cmd len
*   2.���ڷ���
*    ��1�����ݣ���̼ƣ�x,y���ꡢ���ٶȡ����ٶȺͷ���ǣ���λ����Ϊ��mm,mm,mm/s,rad/s,rad���������ݶ�Ϊfloat�ͣ�float��ռ4�ֽڣ�
*    ��2����ʽ��21�ֽ� [x����4�ֽ�][y����4�ֽ�][�����4�ֽ�][���ٶ�4�ֽ�][���ٶ�4�ֽ�][������"\n"1�ֽ�]
*
************************************************************************************************************************/

MSG_ROS_SPEED_TYPE ros_speed_data;

uint32_t parse_speed_cmd(RX_BUF_TYPE *p_parse_buf)
{
	MSG_ROS_HEAD head;
	uint16_t head_len = 0;	
//	uint16_t buf_len = 0;
	uint16_t payload_len = 0;
	uint16_t msg_id = 0;
	head_len = sizeof(head);

	memset(&head, 0, sizeof(head));
	while ((p_parse_buf->pWritePtr - p_parse_buf->pReadPtr) >= head_len)
	{
//		LOGI("func head_len %d\r\n", head_len);
		memcpy(&head, p_parse_buf->rx_buf + p_parse_buf->pReadPtr, head_len);
		if (ROS_MAGIC == head.magic)
		{
//			LOGI("func head.magic %d", head.magic);
			msg_id = head.cmd;
			payload_len = head.len;
			if ((p_parse_buf->pWritePtr - p_parse_buf->pReadPtr) < (payload_len + head_len + 2))
			{
				break;
			}
			if(msg_id == 0x02)  /***�ٶȿ���*/
			{
				memcpy(&ros_speed_data, p_parse_buf->rx_buf + p_parse_buf->pReadPtr + head_len, payload_len);
				LOGI("receive ROS_MAGIC head.cmd %d head.len:%d %d %d \r\n", head.cmd, head.len, p_parse_buf->pWritePtr, p_parse_buf->pReadPtr);
				LOGI("func %s left_motor_data %f right_motor_data %f", __FUNCTION__, ros_speed_data.left_motor_data, ros_speed_data.right_motor_data);
			}
			p_parse_buf->pReadPtr += payload_len + head_len + 2;
			
		}
		else
		{
			p_parse_buf->pReadPtr += 1;
		}
	}

	if (p_parse_buf->pReadPtr != 0)
	{
		if ((p_parse_buf->pWritePtr - p_parse_buf->pReadPtr) > 0)
		{
			memmove(p_parse_buf->rx_buf, p_parse_buf->rx_buf + p_parse_buf->pReadPtr, p_parse_buf->pWritePtr - p_parse_buf->pReadPtr);
			p_parse_buf->pWritePtr -= p_parse_buf->pReadPtr;
			p_parse_buf->pReadPtr = 0;
		}
		else
		{
			p_parse_buf->pWritePtr = 0;
			p_parse_buf->pReadPtr = 0;
		}
	}
	LOGI("receive ROS_MAGIC head.cmd %d head.len:%d %d %d \r\n", head.cmd, head.len, p_parse_buf->pWritePtr, p_parse_buf->pReadPtr);	
	
	return 0;
}



uint32_t get_data_from_rx_buf(RX_BUF_TYPE *p_rx_buf, uint8_t *buf, uint16_t buf_len)
{
	uint32_t cpy_len;
	uint32_t cpy_total_len = 0;

	if (buf_len == 0)
	{
		return 0;
	}
	if (p_rx_buf->pWritePtr > p_rx_buf->pReadPtr)
	{
		cpy_len = p_rx_buf->pWritePtr - p_rx_buf->pReadPtr;
		if (cpy_len > buf_len)
		{
			cpy_len = buf_len;
		}
		memcpy(buf, p_rx_buf->rx_buf + p_rx_buf->pReadPtr, cpy_len);
		p_rx_buf->pReadPtr += cpy_len;

		if (p_rx_buf->pReadPtr >= p_rx_buf->rx_size)
		{
			p_rx_buf->pReadPtr -= p_rx_buf->rx_size;
		}
		cpy_total_len += cpy_len;
	}
	else if (p_rx_buf->pWritePtr < p_rx_buf->pReadPtr)   // 12  126
	{
		cpy_len = p_rx_buf->rx_size - p_rx_buf->pReadPtr;
		if (cpy_len > buf_len)
		{
			cpy_len = buf_len;
		}

		memcpy(buf, p_rx_buf->rx_buf + p_rx_buf->pReadPtr, cpy_len);
		p_rx_buf->pReadPtr += cpy_len;//   128 2

		if (p_rx_buf->pReadPtr>= p_rx_buf->rx_size)
		{
			p_rx_buf->pReadPtr -= p_rx_buf->rx_size; //0 
		}
		cpy_total_len += cpy_len;// 2

		if(p_rx_buf->pWritePtr != 0)
		{
			cpy_len = p_rx_buf->pWritePtr; //12
			if (cpy_total_len + cpy_len > buf_len)
			{
				cpy_len = buf_len - cpy_total_len;
			}
			if (cpy_len != 0)
			{
				memcpy(buf + cpy_total_len, p_rx_buf->rx_buf, cpy_len);
				p_rx_buf->pReadPtr += cpy_len;
				if (p_rx_buf->pReadPtr >= p_rx_buf->rx_size)
				{
					p_rx_buf->pReadPtr -= p_rx_buf->rx_size;
				}
			}
			cpy_total_len += cpy_len;
		}
	}

	return cpy_total_len;
}


