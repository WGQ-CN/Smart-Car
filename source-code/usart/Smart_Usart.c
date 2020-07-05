#include "Usart_communication.h"
 
/*初始化函数*/
void Usart_Init()
{
	TMOD=0x21;					//定时器0工作方式1，定时器1工作方式2
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	TH1=0xFD;
	TL1=0xFD;
	TR0=1;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;

	key_config_Ap=1;
	key_config_Air=1;	
}

void Usart_SendMcu1()
{
	unsigned char i;
	for(i=0;i<115;i++)
	{
		ES=0;
		SBUF=mcu_send_1[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu2()
{
	unsigned char i;
	for(i=0;i<9;i++)
	{
		ES=0;
		SBUF=mcu_send_2[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu3()
{
	unsigned char i;
	for(i=0;i<11;i++)
	{
		ES=0;
		SBUF=mcu_send_3[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu4()
{
	unsigned char i;
	for(i=0;i<11;i++)
	{
		ES=0;
		SBUF=mcu_send_4[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu5()
{
	unsigned char i;
	for(i=0;i<9;i++)
	{
		ES=0;
		SBUF=mcu_send_5[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu6()
{
	unsigned char i;
	for(i=0;i<10;i++)
	{
		ES=0;
		SBUF=mcu_send_6[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu8()
{
	unsigned char i;
	for(i=0;i<9;i++)
	{
		ES=0;
		SBUF=mcu_send_8[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu9()
{
	unsigned char i;
	for(i=0;i<10;i++)
	{
		ES=0;
		SBUF=mcu_send_9[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

void Usart_SendMcu12()
{
	unsigned char i;
	for(i=0;i<9;i++)
	{
		ES=0;
		SBUF=mcu_send_12[i];
		while(!TI);
		TI=0;
		ES=1;
	}
}

/*定时器0中断*/
void Timer0_Int() interrupt 1
{
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	num_usart++;
}

/*串口中断函数*/
void Usart_Int() interrupt 4
{
	num_usart=0;
	ET0=1;
	usartbuf[usrtlen++]=SBUF;
	if(usrtlen==2)
	{
		if(usartbuf[0]!=0xff||usartbuf[1]!=0xff)
		{
			usrtlen=0;
		}
	}
	RI=0;
}
