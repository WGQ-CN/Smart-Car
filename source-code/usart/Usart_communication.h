#ifndef __USART_COMMUNICATION_H__
#define __USART_COMMUNICATION_H__

#include "Smart_Usart.h"
#include "Control_Mcu.h"

extern uchar usartbuf[50];

extern uchar mcu_send_1[115];
extern uchar mcu_send_2[9];
extern uchar mcu_send_3[11];
extern uchar mcu_send_4[11];
extern uchar mcu_send_5[9];
extern uchar mcu_send_6[10];
extern uchar mcu_send_8[9];
extern uchar mcu_send_9[10];
extern uchar mcu_send_12[9];

void Usart_Communication();

#endif
