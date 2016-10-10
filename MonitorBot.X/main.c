#include "userLib.h"
#include "picConfig.h"
#include "pwm.h"
#include "PWM_control.h"

#define NUM_WHEEL_PWMS 2
#define NUM_GIMBAL_PWMS 2

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
	uart_init(UART2, 9600, PBCLK);		




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
    
   	pin_setup();			//see Twitchy_Functions.c!!! this sets the servo channels to outputs
    
    LATE = 1;
    delayT1_ms(1000);
    LATE = 0; 
    delayT1_ms(1000);
    LATE = 1;
    printf("HELLO WORLD\r");
    printf("I AM LABMONITOR_BOT\r");

        
    INT16 m1_dir1;
    INT16 m1_dir2;
    INT16 m2_dir1;
    INT16 m2_dir2;
    
    m1_dir1 = PWMOpen( 1, 2, T2_PS_1_32, 0x1694 );
	m1_dir2 = PWMOpen( 2, 2, T2_PS_1_32, 0x1694 );
	m2_dir1 = PWMOpen( 3, 2, T2_PS_1_32, 0x1694 );
	m2_dir2 = PWMOpen( 4, 2, T2_PS_1_32, 0xC000 );


    PWMWrite( m1_dir1, (PR2*128)/255); 
    PWMWrite( m1_dir2, (PR2*512)/1023);     
    PWMWrite( m2_dir1, (PR2*512)/1023); 
    PWMWrite( m2_dir2, (PR2*512)/1023);     

    
    //IF YOU WANT A GIMBAL
    //YOU NEED TO USE IO_PWM SEPARATELY!!!!


    int wheel_map[NUM_WHEEL_PWMS];
    int wheel_times[NUM_WHEEL_PWMS];  
    wheel_times[0] = 900;    //500 microseconds, 1ms period
    wheel_times[1] = 900;    //500 microseconds, 1ms period

    
    char dir = 0;
    int LeftDuty = 0; int RightDuty = 0;
    unsigned long int time = 0;
    int Lspeed = 200; int Rspeed = 200;
    

    while(1)
    {
        while(!DataRdyUART2())
        {
            time++;
            move_wheels(dir, LeftDuty, RightDuty, wheel_times, wheel_map, NUM_WHEEL_PWMS, 1);
            if(time > 2000)
            {
                LeftDuty = 0;
                RightDuty = 0;
            }
        }
        char UART_rd = ReadUART2();
        if(UART_rd == 'i')
        {
            printf("forward\r");
            time = 0;
            dir = 0;
            LeftDuty = Lspeed;
            RightDuty = Rspeed;
        }
        else if (UART_rd == 'k')
        {
            printf("back\r");
            time = 0;
            dir = 3;
            LeftDuty = Lspeed;
            RightDuty = Rspeed;

        }
        else if (UART_rd == 'l')
        {
            printf("right\r");
            time = 0;
            dir = 1;
            LeftDuty = Lspeed;
            RightDuty = Rspeed;
        }
        else if (UART_rd == 'j')
        {           
            printf("left\r");
            time = 0;
            dir = 2;
            LeftDuty = Lspeed;
            RightDuty = Rspeed;
        }
        
        if(UART_rd == ']')
        {
            Lspeed++;
            Rspeed++;
            printf("%d\r", Lspeed);
        }
        else if(UART_rd == '[')
        {
            Lspeed--;
            Rspeed--;
            printf("%d\r", Rspeed);
        }
        
        if(Lspeed < 0)
            Lspeed = 0;
        if(Rspeed < 0)
            Rspeed = 0;
        

        if(UART_rd == ' ')
        {
            printf("stop\r");
            LeftDuty = 0; 
            RightDuty = 0;
        }
        
    }   
    

    
}