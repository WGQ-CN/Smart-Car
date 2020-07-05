#include "Smart_Usart.h"
#include "delay.h"
#include "Key_Config.h"

void Key_Usart_Config()
{
	uchar i;
	checksum=0;
	if(key_config_Ap==0)									//SoftAp配置模式
	{
		Delay_ms(10);
		if(key_config_Ap==0)
		{	
			Ap=~Ap;
			REN=0;
			sn=0x00;
			mcu_send_6[5]=sn;
			for(i=2;i<9;i++)
			{
				checksum=checksum+mcu_send_6[i];
			}
			checksum=checksum%256;
			mcu_send_6[9]=checksum;
			send_6_config=1;
			mcu_send_6[8]=send_6_config;
			Usart_SendMcu6();
			while(key_config_Ap==0);
			REN=1;
		}	
	}

	if(key_config_Air==0)									//AirLink配置模式
	{
		Delay_ms(10);
		if(key_config_Air==0)
		{	
			Air=~Air;
			REN=0;
			sn=0x00;
			mcu_send_6[5]=sn;
			for(i=2;i<9;i++)
			{
				checksum=checksum+mcu_send_6[i];
			}
			checksum=checksum%256;
			mcu_send_6[9]=checksum;
			send_6_config=2;
			mcu_send_6[8]=send_6_config;
			Usart_SendMcu6();
			while(key_config_Air==0);
			REN=1;
		}	
	}	
}
