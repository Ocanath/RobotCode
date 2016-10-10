#include "MCAP_I2C_Utils.h"
#include "userLib.h"

void Open_I2CPort_1_100Khz()
{
    //////////////double check this config!!!
    I2C1CON = 1 << 0x0000000F;    
    I2C1BRG = 0x170;
}


void WaitToSend_I2CPort_1()
{
    int x = 0;
    while((I2C1CON & 0x1) || (I2C1CON & 0x4) || (I2C1CON & 0x8) || (I2C1CON & 0x10) ||  I2C1STAT & 0x4000)
    {
        x++;
    }
}

void Start_Cond_I2CPort_1()
{
  I2C1CONSET = 0x00000001;
  WaitToSend_I2CPort_1();
}

void Stop_Cond_I2CPort_1()
{
    I2C1CONSET = 0x00000004;
    WaitToSend_I2CPort_1();
}

void MasterWriteByte_I2CPort_1(unsigned char byte, char * ACK_STATUS)
{
	
    I2C1TRN = byte;
    WaitToSend_I2CPort_1();
    *ACK_STATUS = 0;
    if( !(I2C1STATbits.ACKSTAT) )
    	*ACK_STATUS = 1;

}


unsigned char MasterReadByte_I2CPort_1()
{
	
    I2C1CONSET = 0x8;  //or 0x8. 
    unsigned char byte = I2C1RCV;        
//    WaitToSend_I2CPort_1();
    return byte;
}

