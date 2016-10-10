

#include "GimbalBotControl_II.h"
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





int temp_inc;
int sorted_flag;
int hm_i;
int temp_A;
int temp_B;
int motorarr[24];

void hexmotors(int timeIn, int *timeArPtr)
{
	sorted_flag = 0;
	
	for(hm_i = 0; hm_i < 24; hm_i++)
	{
		motorarr[hm_i] = hm_i;
	}

	while(sorted_flag == 0)
	{
		sorted_flag = 1;
		for( hm_i = 1; hm_i < 24; hm_i++)
		{

			if( timeArPtr[hm_i] < timeArPtr[hm_i-1])
			{
				sorted_flag = 0;	
				temp_A = timeArPtr[hm_i];
				temp_B = motorarr[hm_i];
				timeArPtr[hm_i] = timeArPtr[hm_i-1];
				motorarr[hm_i] = motorarr[hm_i-1];
				timeArPtr[hm_i-1] = temp_A;
				motorarr[hm_i-1] = temp_B; 
			}

		}

	}

	for(temp_inc = 0; temp_inc < timeIn; temp_inc++)
	{


		for(hm_i = 0; hm_i < 24; hm_i++)
		{
			servoenable(hm_i, 1);
		}

		delayT1_us(timeArPtr[0]);
		servoenable(motorarr[0], 0);

		for(hm_i = 1; hm_i < 24; hm_i++)
		{
			delayT1_us(timeArPtr[hm_i]-timeArPtr[hm_i-1]);
			servoenable(motorarr[hm_i], 0);
		}
		delayT1_ms(10);     //try changing this. looks like you can reduce this!!! 		
	
	}

}








void move_servos(int * servo_list, int * wheels, int * gimbal, int cycles)
{
    
    
	servo_list[18] = 400; //middle 	//pin 43
	servo_list[22] = wheels[1]; // top		//pin 55
	servo_list[20] = wheels[0];//bottom 	//pin 53
    
	servo_list[0] = 400;
    
	servo_list[14] = gimbal[0]; //middle	//pin 30
	servo_list[12] = 400; // top	//pin 24
	servo_list[19] = 400; //bottom     //pin 27                                                                                                                                                                                                                                           
    servo_list[7] = 400;
    
	servo_list[11] = 400; //middle	//pin 23		
	servo_list[13] = 400; // top		//pin 33
	servo_list[21] = 400; //bottom		//pin 28
	servo_list[9] = 400;
    
	servo_list[1] = gimbal[1]; //middle	//pin 5	
	servo_list[16] = 400; // top		//pin 16
	servo_list[6] = 400; //bottom	//pin 11
	servo_list[10] = 400;	
    
    
	servo_list[2] = 400; //top			//pin 6
	servo_list[8] = 400; // middle	//pin 14
    
	servo_list[3] = 400; //bottom	//pin 8
    
    servo_list[15] = 400;
	servo_list[23] = 400;
    servo_list[4] = 400;
    servo_list[5] = 400;
    servo_list[17] = 400;
    
    
	hexmotors(cycles, servo_list);																		//2  
}






void Keyboard_Control(int * servo_list, int * wheels, int * gimbal)
{
    
    char UART_rd;
    
    printf("w is forward, a to turn, etc. i,j,k,l to control gimbal. temporary\n");
    
    int arm_to_control = 1;     //the left arm
    int enable_motors = 1;
    printf("Outputs on\r");
    
    int step_size = 1;
    
    
    while(1)
    {
        while(!DataRdyUART2())
        {
            if(enable_motors)
                 move_servos(servo_list, wheels, gimbal, 1);
        }
        UART_rd = ReadUART2();
        
        if(UART_rd == ' ')
        {
            enable_motors = !enable_motors;
            if(enable_motors)
                printf("Outputs on\r");
            else
                printf("Outputs off\r");
        }
        
        if(UART_rd == 'w')
        {
            wheels[1] = 2300;
            wheels[0] = 400;
        }
        if (UART_rd == 'a')
        {
            wheels[1] = 2300;
            wheels[0] = 2300;
        }    
        if (UART_rd == 'd')
        {
            wheels[1] = 400;
            wheels[0] = 400;
        }
        
        if (UART_rd == 's')
        {
            wheels[1] = 400;
            wheels[0] = 2300;
        }
        if(UART_rd == 'b')
        {
            wheels[1] = 1500;
            wheels[0] = 1500;
        }
        
        
        
        if(UART_rd == 'j')
        {
            gimbal[0] += 20;
        }
        if (UART_rd == 'k')
        {
            gimbal[1] += 20;
        }
        if (UART_rd == 'l')
        {
            gimbal[0] -= 20;
        }
        if (UART_rd == 'i')
        {
            gimbal[1]-=20;
        }
    }
    
    
    
}




char Gimbal_Get_Byte()
{
    while(!DataRdyUART2());
    char readv = ReadUART2();
    return readv;

}









