#include "PWM_control.h"

#include <stdio.h>
#include "userLib.h"

void pin_setup()
{
	PORTSetPinsDigitalOut( IOPORT_G, BIT_6 );		//PIN 4
	PORTSetPinsDigitalOut( IOPORT_G, BIT_7 );		//PIN 5
	PORTSetPinsDigitalOut( IOPORT_G, BIT_8 );		//PIN 6
	PORTSetPinsDigitalOut( IOPORT_G, BIT_9 );		// PIN 8
	PORTSetPinsDigitalOut( IOPORT_C, BIT_14 );		//PIN 48
	PORTSetPinsDigitalOut( IOPORT_C, BIT_13 );		//PIN 47
	PORTSetPinsDigitalOut( IOPORT_B, BIT_3 );		//pair for motor 4		: PIN 13
	PORTSetPinsDigitalOut( IOPORT_B, BIT_2 );		//						: PIN 14
	
	
	PORTSetPinsDigitalOut( IOPORT_F, BIT_1 );		//pair for motor 6		: PIN 59
	PORTSetPinsDigitalOut( IOPORT_B, BIT_9 );		//						: PIN 22
	PORTSetPinsDigitalOut( IOPORT_B, BIT_10 );		//pair for motor 7		: PIN 23
	PORTSetPinsDigitalOut( IOPORT_B, BIT_11 );		//						: PIN 24 
	PORTSetPinsDigitalOut( IOPORT_F, BIT_3 );		//pair for motor 8 		: PIN 33
	PORTSetPinsDigitalOut( IOPORT_B, BIT_15 );		//				  		: PIN 30
	PORTSetPinsDigitalOut( IOPORT_D, BIT_8 );		//pair for motor 9
	PORTSetPinsDigitalOut( IOPORT_D, BIT_11 );
	PORTSetPinsDigitalOut( IOPORT_D, BIT_10 );		//pair for motor 10
	PORTSetPinsDigitalOut( IOPORT_D, BIT_9 );		//						: PIN 43
	PORTSetPinsDigitalOut( IOPORT_B, BIT_12 );		//						: PIN 52
	PORTSetPinsDigitalOut( IOPORT_D, BIT_5 );		//						: PIN 53
	PORTSetPinsDigitalOut( IOPORT_B, BIT_13 );		//						: PIN 54
	PORTSetPinsDigitalOut( IOPORT_D, BIT_7 );		//						: PIN 55
	PORTSetPinsDigitalOut( IOPORT_F, BIT_0 );		//						: PIN 58
	PORTSetPinsDigitalOut( IOPORT_B, BIT_5 );
	
	PORTSetPinsDigitalOut( IOPORT_B, BIT_0 );

	PORTSetPinsDigitalOut(IOPORT_B, BIT_13); //28a
	PORTSetPinsDigitalOut(IOPORT_B, BIT_12); //27b
	PORTSetPinsDigitalOut(IOPORT_D, BIT_8); //42c
}


void servoenable(int motornum, int dir)
{
		if(motornum == 0 && dir == 1)
			PORTSetBits( IOPORT_G, BIT_6 );		//pair for motor 1		: PIN 4	
		if(motornum == 0 && dir == 0)
			PORTClearBits(IOPORT_G, BIT_6 );
		if(motornum == 1 && dir == 1)
			PORTSetBits( IOPORT_G, BIT_7 );		//						: PIN 5
		if(motornum == 1 && dir == 0)
			PORTClearBits(IOPORT_G, BIT_7 );
		if(motornum == 2 && dir == 1)
			PORTSetBits( IOPORT_G, BIT_8 );		//pair for motor 2		: PIN 6
		if(motornum == 2 && dir == 0)
			PORTClearBits(IOPORT_G, BIT_8 );
		if(motornum == 3 && dir == 1)
			PORTSetBits( IOPORT_G, BIT_9 );		//		: PIN 8
		if(motornum == 3 && dir == 0)
			PORTClearBits(IOPORT_G, BIT_9 );
		if(motornum == 4 && dir == 1)
			PORTSetBits( IOPORT_C, BIT_14 );		//pair for motor 3 		: PIN 48
		if(motornum == 4 && dir == 0)
			PORTClearBits(IOPORT_C, BIT_14 );

		if(motornum == 5 && dir == 1)
			PORTSetBits( IOPORT_C, BIT_13 );		//						: PIN 47
		if(motornum == 5 && dir == 0)
			PORTClearBits(IOPORT_C, BIT_13 );

		if(motornum == 6 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_5 );		//						: PIN 11
		if(motornum == 6 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_5 );

		if(motornum == 7 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_3 );		//pair for motor 4		: PIN 13
		if(motornum == 7 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_3 );
		if(motornum == 8 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_2 );		//						: PIN 14
		if(motornum == 8 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_2 );
		if(motornum == 9 && dir == 1)
			PORTSetBits( IOPORT_F, BIT_1 );		//pair for motor 6		: PIN 59
		if(motornum == 9 && dir == 0)
			PORTClearBits(IOPORT_F, BIT_1 );
		if(motornum == 10 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_9 );		//						: PIN 22
		if(motornum == 10 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_9 );
		if(motornum == 11 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_10 );		//pair 	: PIN 23
		if(motornum == 11 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_10 );
		if(motornum == 12 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_11 );		//			: PIN 24 
		if(motornum == 12 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_11 );
		if(motornum == 13 && dir == 1)
			PORTSetBits( IOPORT_F, BIT_3 );		//				: PIN 33
		if(motornum == 13 && dir == 0)
			PORTClearBits(IOPORT_F, BIT_3 );
		if(motornum == 14 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_15 );		//				: PIN 30
		if(motornum == 14 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_15);
		if(motornum == 15 && dir == 1)
			PORTSetBits( IOPORT_D, BIT_8 );		//		: PIN 42
		if(motornum == 15 && dir == 0)
			PORTClearBits(IOPORT_D, BIT_8 );

		if(motornum == 16 && dir == 1)				//			: PIN 16
			PORTSetBits( IOPORT_B, BIT_0 );
		if(motornum == 16 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_0 );

		if(motornum == 17 && dir == 1)
			PORTSetBits( IOPORT_D, BIT_10 );		//		:PIN 44
		if(motornum == 17 && dir == 0)
			PORTClearBits(IOPORT_D, BIT_10 );

		if(motornum == 18 && dir == 1)				//43
			PORTSetBits( IOPORT_D, BIT_9 );		
		if(motornum == 18 && dir == 0)
			PORTClearBits(IOPORT_D, BIT_9 );

		if(motornum == 19 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_12 );		// PIN 27		
		if(motornum == 19 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_12 );
		if(motornum == 20 && dir == 1)
			PORTSetBits( IOPORT_D, BIT_5 );		//   pin 53
		if(motornum == 20 && dir == 0)
			PORTClearBits(IOPORT_D, BIT_5 );
		if(motornum == 21 && dir == 1)
			PORTSetBits( IOPORT_B, BIT_13 );		// PIN 28	//originally 54
		if(motornum == 21 && dir == 0)
			PORTClearBits(IOPORT_B, BIT_13 );		
		if(motornum == 22 && dir == 1)
			PORTSetBits( IOPORT_D, BIT_7 );		//PIN 55
		if(motornum == 22 && dir == 0)
			PORTClearBits(IOPORT_D, BIT_7 );
		if(motornum == 23 && dir == 1)
			PORTSetBits( IOPORT_F, BIT_0 );		//PIN 58
		if(motornum == 23 && dir == 0)
			PORTClearBits(IOPORT_F, BIT_0 );

}


void IO_pwm(int * times, int * map, int period, int num_motors, int repeat, int offset)
{
    
    int i;
    for(i = 0; i < num_motors; i++)
        map[i] = i;
    char is_sorted = 0;
    while(!is_sorted)
    {
        is_sorted = 1;
        int i;
        for(i = 1; i < num_motors; i++)
        {
            if(times[i-1] > times[i])
            {
                is_sorted = 0;
                int temp = times[i];
                times[i] = times[i-1];
                times[i-1] = temp;
                temp = map[i-1];
                map[i-1] = map[i];
                map[i] = temp;
                
            }
        }
    }
    int j;
    for(j = 0; j < repeat; j++)
    {
        for( i = 0; i < num_motors; i++)
            servoenable(i+offset, 1);
        delayT1_us(times[0]);
        servoenable(map[0]+offset, 0);
        for(i = 1; i < num_motors; i++)
        {
            delayT1_us(times[i] - times[i-1] );
            servoenable(map[i] + offset,0);
        }
        delayT1_ms( (period - times[num_motors - 1]) / 1000 );
        delayT1_us( (period - times[num_motors - 1]) % 1000 );
        
    }
}




void move_wheels(char dir, int LeftDuty, int RightDuty, int * times, int * map, int num_motors, int num_loops)
{
    times[0] = LeftDuty;
    times[1] = RightDuty;
    //set dir pins
    servoenable(2,  ((dir >> 1)& 0x1) );
    servoenable(3, (dir & 0x1));

    
    //frequency is 1Khz, offset is 0
    IO_pwm(times, map, 1000, num_motors, num_loops, 0);
}