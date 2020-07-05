#ifndef __CONTROL_MCU_H__
#define __CONTROL_MCU_H__

extern uchar usartbuf[50];

void Control_Mcu();
void goForward();
void backOff();
void turnLeft();
void turnRight();
void stop();

#endif
