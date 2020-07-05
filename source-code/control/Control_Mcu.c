#include "Smart_Usart.h"
#include "Control_Mcu.h"

void Control_Mcu()
{
	switch(usartbuf[9])
	{
		case 0x01:
			if(usartbuf[10]==0x01)
			{
				goForward();
			}
			else if(usartbuf[10]==0)
			{
				stop();
			}
			break;

		case 0x02:
			if(usartbuf[10]==0x02)
			{
				backOff();
			}
			else if(usartbuf[10]==0)
			{
				stop();
			}
			break;

		case 0x04:
			if(usartbuf[10]==0x04)
			{
				turnLeft();
			}
			else if(usartbuf[10]==0)
			{
				stop();
			}
			break;

		case 0x08:
			if(usartbuf[10]==0x08)
			{
				turnRight();
			}
			else if(usartbuf[10]==0)
			{
				stop();
			}
			break;
	}
}

void goForward()
{
	IN1=1;
	IN2=0;
	IN3=0;
	IN4=1;
}

void backOff()
{
	IN1=0;
	IN2=1;
	IN3=1;
	IN4=0;
}

void turnLeft()
{
	IN1=0;
	IN2=1;
	IN3=0;
	IN4=1;
}

void turnRight()
{
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
}

void stop()
{
	IN1=0;
	IN2=0;
	IN3=0;
	IN4=0;
}
