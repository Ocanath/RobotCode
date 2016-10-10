#include "userLib.h"
#include "picConfig.h"
#include "a2d.h"
#include "MouseHarness.h"

#define TR_CONST 511000
#define MOTION_CTL_MODE 0
#define PI  3.14159265359

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
	//uart_init(UART1, 9600, PBCLK);
    U1BRG = ((PBCLK / 9600)/16)-1;
    U1MODE |= 0x8000;
    U1STA |= 0x400;
    U1STA |= 0x1000;
    
    
    

    
    
//230400
    
	_TRISF5 = 0;						// set UART3A TX pin as output
	_TRISF4 = 1;						// set RX pin as input
	uart_init(UART2, 230400, PBCLK);		




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

	A2D_init(0xFF);			// parm = ANx bits to enable as inputs 							TURN BACK ON

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


 


int main()
{
    
    
	int	rc;				// function return code
	rc = initialize();			// set up hardware
	checkrc(rc);			//check if successful hardwarecheck
    
	LATE = 5;
	delayT1_ms(1000);
	LATE = 2;
	delayT1_ms(1000);
	printf("Hello, World!\r");
	printf("I AM MOUSEHARNESS\r");
	//PORTSetPinsDigitalIn( IOPORT_F, BIT_3);
	LATE = 5;
    int i;
    
    UINT16 val;
    Harness MH;
    
    LATE = 1;
    while(1)
    {
//        for(i = 0; i < 5; i++)
//        {
//            LATE = i << 3 | i;
            A2D_read(0, &val);
            printf("aL = %d;\r ", val);
//            MH.aL[i+1] = val;
//            A2D_read(1, &val);
//            MH.aR[i+1] = val;
//            delayT1_ms(10);
//        }
        
        //AnaRadians(&MH);
//        for(i = 1; i <= NUM_ARM_JOINTS; i++)
//        {
//            printf("aL[%d] = %d;\r ", i, MH.aL[i]);
////            printf("aL[%d] = %d;\r", i, MH.aR[i]);
//        }
    }

    
    
}