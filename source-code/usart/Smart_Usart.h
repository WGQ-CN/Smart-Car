#ifndef __SMART_USART__
#define __SMART_USART__

#include <reg52.h>

#define uint unsigned int
#define uchar unsigned char

sbit key_config_Ap=P3^2;
sbit key_config_Air=P3^3;

sbit IN1=P1^1;
sbit IN2=P1^2;
sbit IN3=P1^3;
sbit IN4=P1^4;

sbit ENA=P1^0;
sbit ENB=P1^5;

sbit Ap=P1^6;
sbit Air=P1^7;

extern uchar usartbuf[50];

extern uchar sn,checksum,usrtlen,usarrtflag,num_usart;
extern uchar send_6_config,send_9_error,send_3_dev,send_4_dev;

void Usart_Init();
void Usart_SendMcu1();
void Usart_SendMcu2();
void Usart_SendMcu3();
void Usart_SendMcu4();
void Usart_SendMcu5();
void Usart_SendMcu6();
void Usart_SendMcu8();
void Usart_SendMcu9();
void Usart_SendMcu12();

#endif
