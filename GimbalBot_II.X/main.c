
//
//              Gimbal's control program
//

#include "userLib.h"
#include "picConfig.h"



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
    printf("I am GimbalBot!\r");
    
    pin_setup();
    
    int timearr[24];
	timearr[0] = 2300;	timearr[1] = 500;	timearr[2] = 1500;	timearr[3] = 440;	timearr[4] = 660;	timearr[5] = 500;	timearr[6] = 1230;
	timearr[7] = 500;	timearr[8] = 1500;	timearr[9] = 2400;	timearr[10] = 1400;	timearr[11] = 1100;	timearr[12] = 401;	timearr[13] = 402;
	timearr[14] = 401;	timearr[15] = 430;	timearr[16] = 590;	timearr[17] = 591;	timearr[18] = 400;	timearr[19] = 405;	timearr[20] = 412;
	timearr[21] = 416;	timearr[22] = 522;	timearr[23] = 1105;	timearr[24] = 0;


    int wheels[2];
    int gimbal[2];
    
    wheels[0] = 1500;
    wheels[1] = 1500;
    gimbal[0] = 1500;
    gimbal[1] = 1500;
    

    
    while(1)
    {
                
        //DO SOME STUFF takes time
        
        move_servos(timearr, wheels, gimbal, 1);
        
        
        unsigned char RdyFlag = 0;
        unsigned char FailFlag = 0;
        UINT8 inbuf[20];
        int bufidx = 0;
        
        int i;
        for(i = 0; i < 5; i++ )
            inbuf[i] = 0;
        
        WriteUART1('R');
        while(BusyUART1());
   
        delayT1_us(50);
        
        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);
        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);

        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);
        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);

        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);
        
        if(U1STA & 0x2 != 0)
            U1STA &= (~0x2);   
        
        if(!FailFlag)
        {
            INT16 leftwheel = (inbuf[0] & 0xFF);
            INT16 camtop = (inbuf[1] & 0xFF);
            INT16 rightwheel = (inbuf[2] & 0xFF);
            INT16 cambase = (inbuf[3] & 0xFF);
            //inbuf[4] contains the high bits

            leftwheel |= (inbuf[4] & 0x3) << 8;
            camtop |= ( (inbuf[4] >> 2) & 0x3) << 8;
            rightwheel |= ( (inbuf[4] >> 4) & 0x3) << 8;
            cambase |= ( (inbuf[4] >> 6) & 0x3) << 8;

            //1320
//            wheels[0] = (int)(((((double)(1024 - leftwheel)) * 380.0) / 1024.0) + 1320);
//            wheels[1] = (int)(((((double)rightwheel) * 380.0) / 1024.0) + 1320);
            //EVENTUALLY
            //use the MPU6050 to get the orientation, and then move the robot to match the angle
            //produced by the atan2(leftwheel, rightwheel)

            
            int fb_val_0 = (int)(((((double)(1024 - leftwheel)) * 380.0) / 1024.0) + 1320);
            int fb_val_1 = (int)(((((double)(leftwheel)) * 380.0) / 1024.0) + 1320);
            int lr_val = (int)(((((double)(rightwheel) - 512) * 380) / 1024.0) + 10);

            //both - bc it's a 2 wheel chassis (more same means opposite dirs) 
            wheels[0] = fb_val_0 + lr_val;
            wheels[1] = fb_val_1 + lr_val;

            
            
            gimbal[0] = (int)(((((double)cambase) * 1900.0) / 1024.0) + 400) - 100;
            gimbal[1] = (int)(((((double)(1024 - camtop)) * 1900.0) / 1024.0) + 400) - 200;

            
            
            if(wheels[0] < 1550 && wheels[0] > 1475)
                wheels[0] = 1500;
            if(wheels[1] < 1525 && wheels[1] > 1475)
                wheels[1] = 1500;
            
            
            //printf("L: %d,    R: %d\r", wheels[0], wheels[1]);
//            printf("L: %d,    R: %d\r", leftwheel, rightwheel);
//            if(leftwheel != 510 || rightwheel != 355)
//                printf("error\r");
        }

        //Output to motors
        
        
        
    }
   
    
}
