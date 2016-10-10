
//
//              Gimbal's control program
//

#include <plib.h>
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



void async_get_byte( char * inbuf, int * bufidx, unsigned char * RdyFlag, unsigned char * FailFlag)
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
    printf("I am Gimbal's Controller\r");
    
    
    
    A2D_init(0xFF);			//alternative to setting the bits yourself
    
//    Try this later
//    AD1CON1 = 0x84E6;
//    AD1CON2 = 0x0;
//    AD1CON3 = 0x8100;
//    AD1CHS = 0x0;
//    AD1PCFG = 0x0;

    unsigned int count = 0;
    while(1)
    {
        //DO SOME STUFF takes time
  //      delayT1_ms(1);
        
        //get analog input
//        int a0 = ADC1BUF0;
//        int a1 = ADC1BUF1;
        //int a2;
        //int a3;
        UINT16 a0; UINT16 a1; UINT16 a2; UINT16 a3;
        A2D_read(0, &a0);   A2D_read(1, &a1);
        A2D_read(2, &a2);   A2D_read(3, &a3);        

        //printf(",  3: %d,    4: %d\r", a2, a3);
//        a0 = 511;
//        a1 = 355;
        printf("1: %d,    2: %d\r", a0, a1);
//        delayT1_ms(10);
        
        UINT8 a3210_highbits;
        UINT8 a0_lowbits = (a0 & 0xFF);
        UINT8 a1_lowbits = (a1 & 0xFF);
        UINT8 a2_lowbits = (a2 & 0xFF);
        UINT8 a3_lowbits = (a3 & 0xFF);

        a3210_highbits = 0x0;
        a3210_highbits = a3210_highbits | ((a0 >> 8) & 0x3);
        a3210_highbits = a3210_highbits | (((a1 >> 8) & 0x3) << 2);
        a3210_highbits = a3210_highbits | (((a2 >> 8) & 0x3) << 4);
        a3210_highbits = a3210_highbits | (((a3 >> 8) & 0x3) << 6);
        
                
        unsigned char RdyFlag = 0;
        unsigned char FailFlag = 0;
        char inbuf[20];
        int bufidx = 0;
            
        async_get_byte( inbuf, &bufidx, &RdyFlag, &FailFlag);

        if(inbuf[0] == 'R')
        {
            WriteUART1(a0_lowbits);
            while(BusyUART1());

            WriteUART1(a1_lowbits);
            while(BusyUART1());

            WriteUART1(a2_lowbits);
            while(BusyUART1());

            WriteUART1(a3_lowbits);
            while(BusyUART1());

            WriteUART1(a3210_highbits);
            while(BusyUART1());


            if(U1STA & 0x2 != 0)
                U1STA &= (~0x2);   

            //Output to motors
        }
        
    }
    
   
    
}
