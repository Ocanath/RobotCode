#ifndef MOUSE_MATH_H
#define MOUSE_MATH_H


void Open_I2CPort_1_100Khz();
void WaitToSend_I2CPort_1();
void Start_Cond_I2CPort_1();
void Stop_Cond_I2CPort_1();
unsigned char MasterReadByte_I2CPort_1();

#endif
