
//
//                 Mouse's Control Program
//
#include "userLib.h"
#include "picConfig.h"
#include "i2c_utils.h"
#include "MCAP_I2C_Utils.h"

#define MPU6050_ADDR 0x68


#define BRG_VAL 55


INT16 initialize()      // establish PBCLK, init timer / peripheral devices
{

   picInit(SYSCLK);          

// setup io ports to control led for debugging purposes

   DDPCONbits.JTAGEN = 0;   // this will disable JTAG port
   
	// set PIC pin mode: examples

//    TRISA = 0;         // all PORTA as output (0) or input (1)
//    _TRISA1 = 0;       // PORTA bit 1 as output (0) or input (1)
//    TRISB = 0;         // all PORTB as output (0) or input (1)
//    TRISC = 0;         // all PORTC as output (0) or input (1)
//    TRISD = 0;         // all PORTD as output (0) or input (1)
//   mPORTESetPinsDigitalOut(BIT_0 | BIT_1 | BIT_2 | BIT_3 | BIT_4 | BIT_5 | BIT_6 | BIT_7);
//   LATE = 0;				// Sets ALL port E bits = 0 
//   LATE = 0xFF;			// Sets All port E bits = 1
//   PORTEbits.RE0 = 1;     // Sets Port E Bit 0 = 1
//	 _LATE0 = 1;			// Also Sets Port E Bit 0 = 1 // alternative syntax

   
   
   	TRISE = 0;         // all PORTE as output: for LEDss
	//TRIS = 0;




   // select the desired options by deleting the // at start-of-line

   // timers for delay functions															IMPORTANT!!!!

   delayT1_init();      // enables use of Timer1 for delay functions
//   delayT2_init();      // enables use of Timer2 for delay functions
//   delayT3_init();      // enables use of Timer3 for delay functions
//   delayT4_init();      // enables use of Timer4 for delay functions
//   delayT5_init();      // enables use of Timer5 for delay functions

  	// timers for timeElapsed functions
	
//	OpenTimer23(T2_ON | T2_SOURCE_INT | T23_PRESCALER | T2_32BIT_MODE_ON, 0xFFFFFFFF);
	OpenTimer45(T4_ON | T4_SOURCE_INT | T45_PRESCALER | T4_32BIT_MODE_ON, 0xFFFFFFFF);

	// UART device selection
	// Param1 = port #: UART1A, UART2A, UART3A, etc
	// Param2 = data rate (bps) data
	// Param3 = PBCLK


	_TRISD3 = 0;						// set  TX pin as output
	_TRISD2 = 1;						// set RX pin as input
	uart_init(UART1, 9600, PBCLK);


    
	_TRISF5 = 0;						// set UART3A TX pin as output
	_TRISF4 = 1;						// set RX pin as input
	uart_init(UART2, 9600, PBCLK);		


    _TRISD9 = 0;
    _LATD9 = 0;
//this is for board 3B

	//setbuf() specifies no stdout buffering: all chars output immediately

	setbuf(stdout,NULL);            // specify no buffering on output  

//buffer area memory that holds content

// PWM
/*
	pwm1Handle = PWMOpen( 1, 2, T2_PS_1_32, 0xC000 );		// PWM open port OC1, Timer 2
	if(pwm1Handle == -1)
		return(-1);
*/




// analog to digital inputs

	//A2D_init(0xFF);			// parm = ANx bits to enable as inputs 							TURN BACK ON
    
    
   
    
    
	return(0);

	INT32 rc; 
	
	
}







void Get_Accel_Temp_Gyro(UINT8 * I2C_IMU_Mailbox)
{
    unsigned char w_val;
    unsigned char send_success;
    unsigned char MPU_addr = 0x68;
    
    unsigned char info_addr;
    for(info_addr = 0x3B; info_addr <= 0x48; info_addr++)
    {

        Start_Cond_I2CPort_1();                                         //START COND:
        //MasterWriteByte_I2CPort_1(0b10010000, &send_success);
        w_val = MPU_addr << 1 | 0;                                     //DEVICE ADDRESS: R/W = 0
        MasterWriteByte_I2CPort_1(w_val, &send_success);               //SEND THE DEVICE ADDRESSS
        w_val = info_addr;                                                  //0x3B: START ADDRESS OF THE ACCELEROMETER DATAS
        MasterWriteByte_I2CPort_1(w_val, &send_success);               //WRITE THE WHOLE THING 

        Start_Cond_I2CPort_1();                                         //REPEATED START    
        w_val = MPU_addr << 1 | 1;                                      //DEVICE ADDRESS
        MasterWriteByte_I2CPort_1(w_val, &send_success);            


            
        //void MasterReadByte_I2CPort_1(unsigned char * byte, char * ACK_STATUS)
        I2C_IMU_Mailbox[info_addr-0x3B] = MasterReadByte_I2CPort_1();            
        //I2C_IMU_Mailbox[info_addr-0x3B] = MasterReadI2C1();             //read!!! check other one
        WaitToSend_I2CPort_1();        


            
        Stop_Cond_I2CPort_1();        

    }
    
}











 
void checkrc(int rc)			//check function return
{	
	if(!rc) 
		return;
	LATE = (rc & 0xFF);
	while(1)
	{}
}

void async_get_byte( UINT8 * inbuf, int * bufidx, unsigned char * RdyFlag, unsigned char * FailFlag)
{
    char UART_rd;
    int i;
    
    *RdyFlag = 0;
    for(i = 0; i < 10; i++)
    {
        if(!DataRdyUART1())
            *RdyFlag = 0;
        else
        {
            *RdyFlag = 1;
            break;
        }
    }
    if(*RdyFlag && !(*FailFlag))
    {
        UART_rd = ReadUART1();
        inbuf[(*bufidx)] = UART_rd;
        (*bufidx)++;
                
    }
    else if (*RdyFlag == 0)
        *FailFlag = 1;
         
      
}


int main()
{




    

	int	rc;				// function return code
	rc = initialize();			// set up hardware
	checkrc(rc);			//check if successful hardwarecheck
    
    LATE = 1; 
    delayT1_ms(1000);
    LATE = 0; 
    delayT1_ms(1000);
    LATE = 1;
    printf("Hello world\r");
    printf("I am Mouse's control interface!\r");
    
    
    
    
    
    unsigned char MPU_addr = 0x68;
    
    
    //
    //I2CUtils_InitPort(1, PBCLK, 0);
    char send_success = 0;
    
    ////////////PUT BACK
    
    Open_I2CPort_1_100Khz();
    
    
    //for DMP:
    //set clock source
    //?set full scale gyro range
    //?set full scale gyro range
    //?disable sleep
    //
    //reset the device
    //wait 30ms
    //disable sleep
    //?set memory bank 0x10, true, true (CHECK FN)
    //?read from 0x6
    //?Set 0, false false
    //?get otp bank valid
    //?get gyro offsets for x, y, and z. I think this is a self-test
    //NOW FOR THE MAGIC:
    //dump dmpMemory with writeProgramMemoryBlock...
    //dmp config
    //set sample rate, etc. reference the dmp initialize code.
    //.
    //.
    //.
    //complicated. revisit if time
    //
    
    unsigned char w_val = MPU_addr << 1 | 0;
    Start_Cond_I2CPort_1();
    MasterWriteByte_I2CPort_1(w_val, &send_success);
    MasterWriteByte_I2CPort_1(0x6B, &send_success);
    //1 uses PLL with x axis gyroscope as reference. Otherwise select 0, which is the
    //8mhz internal oscillator
    MasterWriteByte_I2CPort_1(1, &send_success);
    Stop_Cond_I2CPort_1();
    
    if(!send_success)
    {
        printf("Slave generated non-acknowledge bit\r");
    }
    
    INT16 a_x; INT16 a_y; INT16 a_z;
    INT16 g_x; INT16 g_y; INT16 g_z;
    
    INT16 a_x_prev = 0;
    INT16 a_y_prev = 0;
    INT16 a_z_prev = 0;
    
    
    INT16 VxR = 0;
    INT16 VyR = 0;
    INT16 VzR = 0;
    
    UINT8 I2C_IMU_Mailbox[14];

    
    unsigned int time = 0;
    ////////////PUT BACK
    while(1)
    { 

        a_x = 0; a_y = 0; a_z = 0;
        g_x = 0; g_y = 0; g_z = 0;
    
        Get_Accel_Temp_Gyro(I2C_IMU_Mailbox);
        
        a_x = (INT16)I2C_IMU_Mailbox[1];
        a_x <<= 8;
        a_x |= I2C_IMU_Mailbox[0];       
        a_y = (INT16)I2C_IMU_Mailbox[3];
        a_y <<= 8;
        a_y |= I2C_IMU_Mailbox[2];
        a_z = (INT16)I2C_IMU_Mailbox[5];
        a_z <<= 8;
        a_z |= I2C_IMU_Mailbox[4];
        
        g_x = (INT16)I2C_IMU_Mailbox[9];
        g_x <<= 8;
        g_x |= I2C_IMU_Mailbox[8];       
        g_y = (INT16)I2C_IMU_Mailbox[11];
        g_y <<= 8;
        g_y |= I2C_IMU_Mailbox[10];
        g_z = (INT16)I2C_IMU_Mailbox[13];
        g_z <<= 8;
        g_z |= I2C_IMU_Mailbox[12];
        

       // printf("x:%dy:%dz:%dgx:%dgy:%dgz:%d\r", a_x, a_y, a_z, g_x, g_y, g_z);
       // printf("x:%d \r", a_x);
        //printf("xH: %x, xL: %x  \r",I2C_IMU_Mailbox[0], I2C_IMU_Mailbox[1] );
        
        VxR += a_x;
        VyR += a_y;
        VzR += a_z;
        
        
//        VxR = (INT16)(((double)VxR/33000.0)*150.0);
//        VyR = (INT16)(((double)VyR/33000.0)*150.0);
//        VzR = (INT16)(((double)VzR/33000.0)*150.0);
//        VzR -= 71;
        VxR = (INT16)(((double)VxR/33000.0)*511.0);
        VyR = (INT16)(((double)VyR/33000.0)*511.0);
        VzR = (INT16)(((double)VzR/33000.0)*511.0);
        VzR -= 245;

        
//        printf("x:%d   ", VxR);
//        printf("y:%d   ", VyR);
//        printf("z:%d\r", VzR);
        
        unsigned char RdyFlag = 0;
        unsigned char FailFlag = 0;
        char inbuf[20];
        int bufidx = 0;            
        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);

        //... don't question it. i have no idea what the fuck is going on either. this is now a necessary hack
        //to load 'L's data whenever you get a R request. WTF
        
        //ACTUALLY R
//        if(!FailFlag && inbuf[0] == 'R')
//        {
//            INT16 Rx = 0; INT16 Ry = 0; INT16 Rz = 0;
//            Rx = VxR;
//            Ry = VyR;
//            Rz = VzR;
//            UINT8 outbuf[4];
//            outbuf[0] = (Rx & 0xFF);
//            outbuf[1] = (Ry & 0xFF);
//            outbuf[2] = (Rz & 0xFF);
//            outbuf[3] =  ( ((Rz & 0x300)>>8) << 4) | ( ((Ry & 0x300)>>8) << 2) | ((Rx & 0x300) >> 8);
//            time++;
//            if(time >= 511)
//                time = 0;
//            int i;
//            for(i = 0; i < 4; i++)
//            {
//                U1TXREG = outbuf[i];
//                while(U1STA & 0x100 == 0);
//            }
//        }
        if(!FailFlag && inbuf[0] == 'L')
        {
            INT16 Lx = 0; INT16 Ly = 0; INT16 Lz = 0;
            Lx = VxR;
            Ly = VyR;
            Lz = VzR;
            UINT8 outbuf[4];
            outbuf[0] = (Lx & 0xFF);
            outbuf[1] = (Ly & 0xFF);
            outbuf[2] = (Lz & 0xFF);
            outbuf[3] =  ( ((Lz & 0x300)>>8) << 4) | ( ((Ly & 0x300)>>8) << 2) | ((Lx & 0x300) >> 8);
            time++;
            if(time >= 511)
                time = 0;
            int i;
            for(i = 0; i < 4; i++)
            {
                U1TXREG = outbuf[i];
                while(U1STA & 0x100 == 0);
            }
        }
        
        if(U1STA & 0x2 != 0)
            U1STA &= (~0x2);   
        if(U1STA & 0x1 != 0)
            U1STA &= (~0x1);   


            
            
    }
    
   
    
}







//        else if(LR_MODE == 0)
//        {
//            if(!FailFlag && inbuf[0] == 'L')
//            {
//                INT16 Lx = 0; INT16 Ly = 0; INT16 Lz = 0;
//                Lx = 12;
//                Ly = -17;
//                Lz = 511 - time;
//                UINT8 outbuf[4];
//                outbuf[0] = (Lx & 0xFF);
//                outbuf[1] = (Ly & 0xFF);
//                outbuf[2] = (Lz & 0xFF);
//                outbuf[3] =  ( ((Lz & 0x300)>>8) << 4) | ( ((Ly & 0x300)>>8) << 2) | ((Lx & 0x300) >> 8);
//
//                time++;
//                if(time >= 511)
//                    time = 0;
//                int i;
//                for(i = 0; i < 4; i++)
//                {
//                    U1TXREG = outbuf[i];
//                    while(U1STA & 0x100 == 0);
//                }
//            }
//        }
