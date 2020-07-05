#include "Usart_communication.h"

void Usart_Communication()
{
	uchar i;
	if(num_usart==10)
	{
		ET0=0;
		num_usart=0;
		usarrtflag=1;
		REN=0;
	}
	if(usarrtflag)
	{
		sn=usartbuf[5];
		checksum=0;
		switch(usartbuf[4])
		{
			case 0x01:
				mcu_send_1[5]=sn;
				for(i=2;i<114;i++)
				{
					checksum=checksum+mcu_send_1[i];
				}
				checksum=checksum%256;
				mcu_send_1[114]=checksum;
				Usart_SendMcu1();
				break;

			case 0x03:
				if(usartbuf[3]=0x06&&usartbuf[8]==0x02)
				{
					mcu_send_3[5]=sn;
					send_3_dev=~P1;
					mcu_send_3[9]=send_3_dev;
					for(i=2;i<10;i++)
					{
						checksum=checksum+mcu_send_3[i];
					}
					checksum=checksum%256;
					mcu_send_3[10]=checksum;
					Usart_SendMcu3();
					break;
				}
				if(usartbuf[3]=0x08&&usartbuf[8]==0x01)
				{
					Control_Mcu();								//收到数据后，mcu控制设备函数
					
					mcu_send_2[5]=sn;
					for(i=2;i<8;i++)
					{
						checksum=checksum+mcu_send_2[i];
					}
					checksum=checksum%256;
					mcu_send_2[8]=checksum;
					Usart_SendMcu2();			//mcu回复

					mcu_send_4[5]=sn;
					send_4_dev=~P1;
					mcu_send_4[9]=send_4_dev;
					for(i=2;i<10;i++)
					{
						checksum=checksum+mcu_send_4[i];
					}
					checksum=checksum%256;
					mcu_send_4[10]=checksum;
					Usart_SendMcu4();			//mcu主动上报设备状态					
					break;	
				}
			
			case 0x07:
				mcu_send_5[5]=sn;
				for(i=2;i<8;i++)
				{
					checksum=checksum+mcu_send_5[i];
				}
				checksum=checksum%256;
				mcu_send_5[8]=checksum;
				Usart_SendMcu5();
				break;	

			case 0x0a:
				break;

			case 0x0c:
				break;

			case 0x0d:
				mcu_send_8[5]=sn;
				for(i=2;i<8;i++)
				{
					checksum=checksum+mcu_send_8[i];
				}
				checksum=checksum%256;
				mcu_send_8[8]=checksum;
				Usart_SendMcu8();
				break;

			case 0x11:
				mcu_send_9[5]=sn;
				send_9_error=usartbuf[8];
				mcu_send_9[8]=send_9_error;
				for(i=2;i<9;i++)
				{
					checksum=checksum+mcu_send_9[i];
				}
				checksum=checksum%256;
				mcu_send_9[9]=checksum;
				Usart_SendMcu9();
				break;
			
			case 0x16:
				break;
			
			case 0x2a:
				break;
			
			case 0x0f:
				mcu_send_12[5]=sn;
				for(i=2;i<8;i++)
				{
					checksum=checksum+mcu_send_12[i];
				}
				checksum=checksum%256;
				mcu_send_12[8]=checksum;
				Usart_SendMcu12();
				break;	
		}
		usrtlen=0;
		usarrtflag=0;
		REN=1;
	}	
}
