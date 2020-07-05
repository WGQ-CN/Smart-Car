#include <reg52.h>
#include "Smart_Usart.h"
#include "Usart_communication.h"
#include "Key_Config.h"
#include "delay.h"

void main()
{
	Usart_Init();

	while(1)
	{
		Key_Usart_Config();
		Usart_Communication();
	}
}
