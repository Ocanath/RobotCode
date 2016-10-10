#include "Twitchy_Control_Functions.h"
#include <stdio.h>
#include "userLib.h"

#include "Twitchy_Postures.h"

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

void hexmotors(int timeIn, int *timeArPtr, int delay)
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
		delayT1_ms(delay);     //try changing this. looks like you can reduce this!!! 		
	
	}

}



void move_servos(int * servo_list, int * b, int * m, int * t, int * c, int cycles)
{
	servo_list[18] = m[1]; //middle 	//pin 43
	servo_list[22] = t[1]; // top		//pin 55
	servo_list[20] = b[1];//bottom 	//pin 53
    servo_list[0] = c[1];
	
    
	servo_list[14] = m[6]; //middle	
	servo_list[12] = t[6] + 75; // top
	servo_list[19] = b[6]; //bottom     //pin 27                                                                                                                                                                                                                                           
    servo_list[7] = c[6];
	
	servo_list[11] = m[5]; //middle			
	servo_list[13] = t[5]; // top
	servo_list[21] = b[5]; //bottom
	servo_list[9] = c[5];
	
    
	servo_list[1] = m[4]; //middle	//pin 5	
	servo_list[16] = t[4]-15; // top		//pin 16
	servo_list[6] = b[4]; //bottom	//pin 11
    servo_list[10] = c[4];
	
    
	servo_list[2] = t[3]; //top			//pin 6
	servo_list[8] = m[3]; // middle	//pin 14
	servo_list[3] = b[3]; //bottom	//pin 8
    servo_list[15] = c[3];
	
    
    
    servo_list[23] = m[2]; //middle	//pin 23
	servo_list[4] = t[2]; // top	//pin 48
	servo_list[5] = b[2]; //bottom	//pin 37
	servo_list[17] = c[2];
	
    
	hexmotors(cycles, servo_list, 10);																		//2
      
}

void move_servos_IK_delay(int * servo_list, int * b, int * m, int * t, int * c, int cycles, int delay)
{
	servo_list[18] = m[1]; //middle 	//pin 43
	servo_list[22] = t[1]; // top		//pin 55
	servo_list[20] = b[1];//bottom 	//pin 53
    servo_list[0] = c[1];
	
    
	servo_list[14] = m[6]; //middle	
	servo_list[12] = t[6] + 75; // top
	servo_list[19] = b[6]; //bottom     //pin 27                                                                                                                                                                                                                                           
    servo_list[7] = c[6];
	
	servo_list[11] = m[5]; //middle			
	servo_list[13] = t[5]; // top
	servo_list[21] = b[5]; //bottom
	servo_list[9] = c[5];
	
    
	servo_list[1] = m[4]; //middle	//pin 5	
	servo_list[16] = t[4]-15; // top		//pin 16
	servo_list[6] = b[4]; //bottom	//pin 11
    servo_list[10] = c[4];
	
    
	servo_list[2] = t[3]; //top			//pin 6
	servo_list[8] = m[3]; // middle	//pin 14
	servo_list[3] = b[3]; //bottom	//pin 8
    servo_list[15] = c[3];
	
    
    
    servo_list[23] = m[2]; //middle	//pin 23
	servo_list[4] = t[2]; // top	//pin 48
	servo_list[5] = b[2]; //bottom	//pin 37
	servo_list[17] = c[2];
	
    
	hexmotors(cycles, servo_list, delay);																		//2
      
}







int eye;
int bottomleg1;
int middleleg1;
int topleg1;
void neutral_position(int duration, int *bottomlegg, int *middlelegg, int *toplegg)
{
	bottomleg1 = 1500;
	middleleg1 = 1700;
	topleg1 = 1900;
	for( eye = 1; eye <=6; eye++)
	{
		bottomlegg[eye] = bottomleg1;
		middlelegg[eye] = middleleg1;
		toplegg[eye] = topleg1;
	}
	//servomove(duration);
}

void neutral_position_setup(int *bottomlegg, int *middlelegg, int *toplegg)
{
	bottomleg1 = 1500;
	middleleg1 = 1300;
	topleg1 = 1450;
	for( eye = 1; eye <=23; eye++)
	{
		bottomlegg[eye] = bottomleg1;
		middlelegg[eye] = middleleg1;
		toplegg[eye] = topleg1;
	}
}

void step_coord(char key_press, double * T_xpos, double * T_ypos, double * T_zpos, int legnum)
{	
    int i;
    if (key_press == 'T')
    {
        if (legnum == 7)
        {
            for (i = 1; i <= 6; i++)
                T_xpos[i]+=5;
        }
        else
            T_xpos[legnum] += 5;
    }
    else if (key_press == 'G')
    {
        if (legnum == 7)
        {
            for (i = 1; i <= 6; i++)
                T_xpos[i] -= 5;
        }
        else
            T_xpos[legnum] -= 5;
    }
    else if (key_press == 'F')
    {
        if (legnum == 7)
        {
            for (i = 1; i <= 6; i++)
                T_ypos[i] += 5;
        }
        else
            T_ypos[legnum] += 5;
    }
    else if (key_press == 'H')
    {
        if (legnum == 7)
        {
            for (i = 1; i <= 6; i++)
                T_ypos[i] -= 5;
        }
        else
            T_ypos[legnum] -= 5;
    }

    else if (key_press == 'E')
    {
        if (legnum == 7)
        {
            for (i = 1; i <= 6; i++)
                T_zpos[i] += 5;
        }
        else
            T_zpos[legnum] += 5;
    }
    else if (key_press == 'D')
    {
        if (legnum == 7)
        {
            for (i = 1; i <= 6; i++)
                T_zpos[i] -= 5;
        }
        else
            T_zpos[legnum] -= 5;
    }
}



void Twitchy_Leg_Limit_Joints(double * Theta)
{
	

	if (Theta[1] > 3.14159265359 + 1.57079632679 - .01)
		Theta[1] = 3.14159265359 + 1.57079632679 - .01;
	else if (Theta[1] < 3.14159265359 - 1.57079632679 + .01)
		Theta[1] = 3.14159265359 - 1.57079632679 + .01;
	
	if (Theta[2] > 3.14159265359 + 1.57079632679 - .01)
		Theta[2] = 3.14159265359 + 1.57079632679 - .01;
	else if (Theta[2] < 3.14159265359 - 1.57079632679 + .01)
		Theta[2] = 3.14159265359 - 1.57079632679 + .01;

	if (Theta[3] > -1.57079632679 + 1.57079632679 - .01)
		Theta[3] = -1.57079632679 + 1.57079632679 - .01;
	else if (Theta[3] < -1.57079632679 - 1.57079632679 + .01)
		Theta[3] = -1.57079632679 - 1.57079632679 + .01;

}



void Radians_To_Encoder_Pos(double TW_theta[7][4], int * b, int * m, int * t, int * claw)
{

    double D_c = 593.329628;
    
    int legnum = 1;
    b[legnum] = (TW_theta[legnum][1] * D_c - 443.0);
    m[legnum] = (TW_theta[legnum][2] * D_c - 384.0);
    t[legnum] = (TW_theta[legnum][3] * -D_c + 787.999999762);
    
    
    
    legnum = 2;
    b[legnum] = (TW_theta[legnum][1] * D_c - 724.0);
    m[legnum] = (TW_theta[legnum][2] * D_c - 386.0);
    t[legnum] = (TW_theta[legnum][3] * -D_c + 783.999999762);

    //b: 1300 - 3.14159265359*593.329628
    //m: 1500 - 3.14159265359*593.329628
    //t: 1660 - (-1.57079632679)*(-593.329628)
       
    legnum = 3;
    b[legnum] = (TW_theta[legnum][1] * D_c - 564.0);
    m[legnum] = (TW_theta[legnum][2] * D_c -364.0);
    t[legnum] = (TW_theta[legnum][3] * -D_c + 727.999999762);
    
    //b: 1720 - 3.14159265359*593.329628
    //m: 1440 - 3.14159265359*593.329628    
    //t: 1560 - (-1.57079632679)*(-593.329628)
    
    legnum = 4;
    b[legnum] = (TW_theta[legnum][1] * D_c - 144.000000482);
    m[legnum] = (TW_theta[legnum][2] * D_c - 424.000000482);
    t[legnum] = (TW_theta[legnum][3] * -D_c + 627.999999762);

    //b: 1364 - 3.14159265359*593.329628
    //m: 1517 - 3.14159265359*593.329628
    //t: 1726 - (-1.57079632679)*(-593.329628)
    
    
    legnum = 5;
    b[legnum] = (TW_theta[legnum][1] * D_c - 500.000000482);
    m[legnum] = (TW_theta[legnum][2] * D_c - 347.000000482);
    t[legnum] = (TW_theta[legnum][3] * -D_c + 793.999999762);
    
    //b: 1200 - 3.14159265359*593.329628
    //m: 1498 - 3.14159265359*593.329628
    //t: 1680 - (-1.57079632679)*(-593.329628)
    
    
    legnum = 6;
    b[legnum] = (TW_theta[legnum][1] * D_c - 664.000000482);
    m[legnum] = (TW_theta[legnum][2] * D_c - 366.000000482);
    t[legnum] = (TW_theta[legnum][3] * -D_c + 747.999999762);

    
    
}





void keyboard_user_control(int * servo_list, int * bottomleg, int * middleleg, int * topleg, int * claw, Waypoint * waypoints, int * waypoint_idx, int waypoints_size)
{
    
    char UART_rd;
    
    
    printf("Select leg number. n/m control bottomleg, h/y control middleleg, j/u control topleg, z/x control claws\r");
    printf("Press ]/[ to increase/decrease the step size for the motor adjust\r");
    printf("Press space to toggle motor outputs\r");
    printf("Press d to display current encoder values\r");
    printf("Press w to save a waypoint\r");
    printf("Press p to iterate through the waveform list\r");
    printf("Press D for a complete list of waypoints (recommend disable outputs first!)\r");
    printf("Press e to edit a user specified waypoint.\r");
    printf("Press s to jump to a particular waypoint.\r");
    printf("Press H to view this message again.\r");
    printf("Press C to enter a string designating a posture.\r");
    
    int leg_to_control = 1;
    int mult_leg_boolean_flags[6];
    int i;
    for(i = 1; i <= 6; i++)
        mult_leg_boolean_flags[i] = 0;

    int step_size = 1;
    
    
    int enable_motors = 1;
    printf("Outputs on\r");
    while(1)
    {
        //if(enable_motors)
        //    move_servos(servo_list, bottomleg, middleleg, topleg, 1);
        
        while(!DataRdyUART2())
        {
            if(enable_motors)
                move_servos(servo_list, bottomleg, middleleg, topleg, claw, 1);
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
        
        if(UART_rd >= 49 && UART_rd <= 54)
        {
            UART_rd -= 48;
            leg_to_control = UART_rd;
            printf("Selected: %d\r", leg_to_control);
        }

        else if (UART_rd == ']')
        {
            step_size++;
            printf("inc: %d\r", step_size);
        }
        else if (UART_rd == '[')
        {
            step_size--;
            printf("inc: %d\r", step_size);
        }
        
        else if (UART_rd == 'm')
        {
            bottomleg[leg_to_control]-=step_size;
            if(bottomleg[leg_to_control] < 400)
                bottomleg[leg_to_control] = 400;
            printf("%d", bottomleg[leg_to_control]);
            
        }
        else if (UART_rd == 'n')
        {
            bottomleg[leg_to_control]+=step_size;
            if(bottomleg[leg_to_control] > 2300)
                bottomleg[leg_to_control] = 2300;
            printf("%d", bottomleg[leg_to_control]);
        }
        else if (UART_rd == 'h')
        {
            middleleg[leg_to_control]-= step_size;
            if(middleleg[leg_to_control] < 400)
                middleleg[leg_to_control] = 400;
            printf("%d", middleleg[leg_to_control]);
        }
        else if(UART_rd == 'y')
        {
            middleleg[leg_to_control]+=step_size;
            if(middleleg[leg_to_control] > 2300)
                middleleg[leg_to_control] = 2300;
            printf("%d", middleleg[leg_to_control]);
        }
        else if (UART_rd == 'j')
        {
            topleg[leg_to_control]-=step_size;
            if(topleg[leg_to_control] < 400)
                topleg[leg_to_control] = 400;
            printf("%d", topleg[leg_to_control]);
        
        }
        else if (UART_rd == 'u')
        {
            topleg[leg_to_control]+=step_size;
            if(topleg[leg_to_control] > 2300)
                topleg[leg_to_control] = 2300;  
            printf("%d", topleg[leg_to_control]);
        }
        else if (UART_rd == 'z')
        {
            claw[leg_to_control]+=step_size;
            if(claw[leg_to_control] > 2500)
                claw[leg_to_control] = 2500;  
            printf("%d", claw[leg_to_control]);
        }
        else if (UART_rd == 'x')
        {
            claw[leg_to_control]-=step_size;
            if(claw[leg_to_control] < 0)
                claw[leg_to_control] = 0;  
            printf("%d", claw[leg_to_control]);
        }

        else if (UART_rd == 'd')
        {
            int idx;
            for(idx = 1; idx <=6; idx++)
                printf("b[%d] = %d; m[%d] = %d; t[%d] = %d; c[%d] = %d;\r", idx, bottomleg[idx], idx, middleleg[idx], idx, topleg[idx], idx, claw[idx]);
        }
        
        else if (UART_rd == 'C')
        {
            printf("\rEnter command and hit enter.\rOptions are:\r");
            printf("sit\r");
            char in_buf[32];
            int buf_idx = 0;
            int break_flag = 0;
            in_buf[buf_idx] = 0;
            while(break_flag == 0 && buf_idx <= 32)
            {
                while(!DataRdyUART2())
                {
                    if(enable_motors)
                        move_servos(servo_list, bottomleg, middleleg, topleg, claw, 1);
             
                }
                in_buf[buf_idx] = ReadUART2();
                if(in_buf[buf_idx] == '\r')
                    break_flag = 1;
                buf_idx++;
            }
            if(in_buf[0] == 's' && in_buf[1] == 'i' && in_buf[2] == 't')
                sit(bottomleg, middleleg, topleg, claw);
            else
                printf("command not recognized\r");
            
            
        }
        
        
        else if (UART_rd == 'H')
        {
            printf("Select leg number. n/m control bottomleg, h/y control middleleg, j/u control topleg, z/x control claws\r");
            printf("Press ]/[ to increase/decrease the step size for the motor adjust\r");
            printf("Press space to toggle motor outputs\r");
            printf("Press d to display current encoder values\r");
            printf("Press w to save a waypoint\r");
            printf("Press p to iterate through the waveform list\r");
            printf("Press D for a complete list of waypoints (recommend disable outputs first!)\r");
            printf("Press e to edit a user specified waypoint.\r");
            printf("Press s to jump to a particular waypoint.\r");
            printf("Press i to view this message again.\r");
        }
        
        else if (UART_rd == 'w')
        {
            printf("saving waypoint %d\r", *waypoint_idx);
            if(*waypoint_idx <= waypoints_size)
            {
                for(i = 1; i <= 6; i++)
                {
                    waypoints[*waypoint_idx].bottomleg_snapshot[i] = bottomleg[i];
                    waypoints[*waypoint_idx].middleleg_snapshot[i] = middleleg[i];
                    waypoints[*waypoint_idx].topleg_snapshot[i] = topleg[i];
                    waypoints[*waypoint_idx].claw_snapshot[i] = claw[i];
                    
                }
                (*waypoint_idx) = (*waypoint_idx) + 1;
            }
            
            printf("done.");            
        } 
        
        else if (UART_rd == 'p')
        {                              
            
            printf("Playing waypoints:\r");
            
            int idx, j;
            for(j = 0; j < *waypoint_idx; j++)
            {
                printf("moving to waypoint: %d:\r", j);                
                for(idx = 1; idx <= 6; idx++)
                {
                    bottomleg[idx] = waypoints[j].bottomleg_snapshot[idx];
                    middleleg[idx] = waypoints[j].middleleg_snapshot[idx];
                    topleg[idx] = waypoints[j].topleg_snapshot[idx];
                    claw[idx] = waypoints[j].claw_snapshot[idx];
                }
                move_servos(servo_list, bottomleg, middleleg, topleg, claw, 130);
                printf("done.\r");
            }
            
        }
        else if (UART_rd == 'D')
        {                              
            printf("waypoint data:\r");

            int idx, j;
            for(j = 0; j < *waypoint_idx; j++)
            {
                printf("waypoint index: %d:\r", j);
                for(idx = 1; idx <= 6; idx++)
                {
                    printf("b[%d] = %d; m[%d] = %d; t[%d] = %d; c[%d] = %d;\r", idx, waypoints[j].bottomleg_snapshot[idx], idx, waypoints[j].middleleg_snapshot[idx], idx, waypoints[j].topleg_snapshot[idx], idx, waypoints[j].claw_snapshot[idx]);
                }
            }
            
        }
        else if (UART_rd == 'e')
        {
            printf("Enter index of waypoint to edit and hit enter. \rPress x to exit. \r");
            int in_buf_flag = 1;
            int exit_flag = 0;
            char buf[10];
            int buf_idx = 0;
            while(in_buf_flag)
            {
                while(!DataRdyUART2())
                {
                    if(enable_motors)
                        move_servos(servo_list, bottomleg, middleleg, topleg, claw, 1);
                }
                char inpt = ReadUART2();
                if(inpt == 13)
                    in_buf_flag = 0;
                else if(inpt == 'x')
                {
                    in_buf_flag = 0;
                    exit_flag = 1;
                    
                }
                else
                {
                    inpt-=48;
                    if(inpt >= 0 && inpt <= 9)
                        buf[buf_idx] = inpt;                
                    buf_idx++;                
                }
                
            }
            if(exit_flag == 0)
            {
                int index = 0;
                int j;
                for(j = 0; j < buf_idx; j++)
                    index += buf[j] * ten_to_power(buf_idx - 1 - j);
                printf("index = %d\r", index);

                if(index >= *waypoint_idx)
                    printf("index out of range\r");

                else
                {
                    printf("Are you sure you want to edit value in index %d?\r Press 'y' or 'n'\r", index);
                    while(!DataRdyUART2())
                    {
                        if(enable_motors)
                            move_servos(servo_list, bottomleg, middleleg, topleg, claw, 1);
                    }
                    char check_YN_val = ReadUART2();
                    if(check_YN_val == 'y')
                    {                    
                        printf("editing waypoint %d\r", index);
                        if(index <= waypoints_size)
                        {
                            for(i = 1; i <= 6; i++)
                            {
                                waypoints[index].bottomleg_snapshot[i] = bottomleg[i];
                                waypoints[index].middleleg_snapshot[i] = middleleg[i];
                                waypoints[index].topleg_snapshot[i] = topleg[i];
                                waypoints[index].claw_snapshot[i] = claw[i];

                            }
                        }
                        printf("done.");            
                    }
                    else if(check_YN_val == 'n')
                        printf("Exiting.\r");
                }
            }
            else
                printf("Exiting.\r");
                
        }
        else if (UART_rd == 's')
        {   
            printf("Enter index of waypoint to move to and hit enter\r");
            int in_buf_flag = 1;
            char buf[10];
            int buf_idx = 0;
            while(in_buf_flag)
            {
                while(!DataRdyUART2())
                {
                    if(enable_motors)
                        move_servos(servo_list, bottomleg, middleleg, topleg, claw, 1);
                }
                char inpt = ReadUART2();
                if(inpt == 13)
                    in_buf_flag = 0;
                else
                {
                    inpt-=48;
                    if(inpt >= 0 && inpt <= 9)
                        buf[buf_idx] = inpt;                
                    buf_idx++;                
                }
            }
            int index = 0;
            int j;
            for(j = 0; j < buf_idx; j++)
                index += buf[j] * ten_to_power(buf_idx - 1 - j);
            printf("index = %d\r", index);
            
            if(index >= *waypoint_idx)
                printf("index out of range\r");

            else
            {
                printf("Are you sure you want to go to waypoint in index %d?\r Press 'y' or 'n'\r", index);
                while(!DataRdyUART2())
                {
                    if(enable_motors)
                        move_servos(servo_list, bottomleg, middleleg, topleg, claw, 1);
                }
                char check_YN_val = ReadUART2();
                if(check_YN_val == 'y')
                {                               
                    printf("moving to waypoint: %d:\r", index);                
                    int idx;
                    for(idx = 1; idx <= 6; idx++)
                    {
                        bottomleg[idx] = waypoints[index].bottomleg_snapshot[idx];
                        middleleg[idx] = waypoints[index].middleleg_snapshot[idx];
                        topleg[idx] = waypoints[index].topleg_snapshot[idx];
                        claw[idx] = waypoints[index].claw_snapshot[idx];
                    }
                    move_servos(servo_list, bottomleg, middleleg, topleg, claw, 150);
                    printf("done.\r");
                }
                else if(check_YN_val == 'n')
                    printf("Exiting.\r");
            }
            
        }

        
       
    }
}







void servo_move_speed(int *btlg, int *tplg, int *mdlg, int *btlg_dest, int *tplg_dest, int *mdlg_dest, int delay, int step)
{
	int i;
	int flag = 0;
	int bflag = 0; int tflag = 0; int mflag = 0;

	while(flag == 0)
	{
		bflag = 1; tflag = 1; mflag = 1;
		for(i = 1; i <= 6; i++)
		{
			if(btlg[i] < btlg_dest[i]-step || btlg[i] > btlg_dest[i]+step)	
				bflag = 0;		
			if(btlg[i] < btlg_dest[i] - step)
				btlg[i]+=step;
			if(btlg[i] > btlg_dest[i]+step)
				btlg[i]-=step;
			
			if(tplg[i] < tplg_dest[i]-step || tplg[i] > tplg_dest[i]+step)	
				tflag = 0;		
			if(tplg[i] < tplg_dest[i]-step)
				tplg[i]+=step;
			if(tplg[i] > tplg_dest[i]+step)
				tplg[i]-step;
			
			if(mdlg[i] < mdlg_dest[i]-step || mdlg[i] > mdlg_dest[i]+step)	
				mflag = 0;		
			if(mdlg[i] < mdlg_dest[i]-step)
				mdlg[i]+=step;
			if(mdlg[i] > mdlg_dest[i]+step)
				mdlg[i]-=step;
			
			if(mflag == 1 && tflag == 1 && bflag == 1)
				flag = 1;
			//servomove(delay);
				
		}
	
	}

}


UINT16 leg_move;
UINT16 leg_move_1;
double anaval;
double motor_cast;
int motor_control_num;

void ana_leg_move(int *bottomlegg, int *middlelegg, int *toplegg)//THUMB UP IS POSITIVE
{

	bottomleg1 = 1500;
	middleleg1 = 1700;
	topleg1 = 1700;
	for( eye = 0; eye <=23; eye++)
	{
		bottomlegg[eye] = bottomleg1;
		middlelegg[eye] = middleleg1;
		toplegg[eye] = topleg1;
	}
	//bottomlegg[4] = 1850;
	//middlelegg[4] = 1655;	
	//toplegg[4] = 1855;

	//bottomlegg[2] = 1150;
	//middlelegg[2] = 1655;	
	//toplegg[2] = 1855;

	motor_control_num = 1;	//following three segments control leg 1
	PORTClearBits(IOPORT_B, BIT_13); //28a
	PORTClearBits(IOPORT_B, BIT_12); //27b
	PORTClearBits(IOPORT_D, BIT_8); //42c
	A2D_read(1, &leg_move);
	anaval = leg_move;
	motor_cast = (((1900.0-((1900.0/1023.0)*anaval)))+400.0);				 //+600
	bottomlegg[motor_control_num] = motor_cast;
	
	//printf("anabot=%d \n",bottomlegg[motor_control_num]);

	PORTSetBits(IOPORT_B, BIT_13); //28a
	PORTClearBits(IOPORT_B, BIT_12); //27b
	PORTClearBits(IOPORT_D, BIT_8); //42c
	A2D_read(1, &leg_move_1);
	anaval = leg_move_1;
	motor_cast = (((1900.0-((1900.0/1023.0)*anaval)))+400.0);				 //+600
	middlelegg[motor_control_num] = motor_cast;				
	
	//printf("anamid=%d\r ", middlelegg[motor_control_num]);
	
	PORTClearBits(IOPORT_B, BIT_13); //28a
	PORTSetBits(IOPORT_B, BIT_12); //27b
	PORTClearBits(IOPORT_D, BIT_8); //42c
	A2D_read(1, &leg_move);
	anaval = leg_move;
	motor_cast = (((1900.0-((1900.0/1023.0)*anaval)))+400.0);				 //+600
	toplegg[motor_control_num] = motor_cast;					

//	printf("anatop=%f\r", motor_cast);

	motor_control_num = 3;		//the following three segments control leg three
	PORTSetBits(IOPORT_B, BIT_13); //28a
	PORTSetBits(IOPORT_B, BIT_12); //27b
	PORTClearBits(IOPORT_D, BIT_8); //42c								//	28a,   27b,  42c
	A2D_read(1, &leg_move);
	anaval = leg_move;
	motor_cast = (((1900.0-((1900.0/1023.0)*anaval)))+400.0);				 //+600
	bottomlegg[motor_control_num] = motor_cast;

	PORTClearBits(IOPORT_B, BIT_13); //28a
	PORTClearBits(IOPORT_B, BIT_12); //27b
	PORTSetBits(IOPORT_D, BIT_8); //42c
	A2D_read(1, &leg_move);
	anaval = leg_move;
	motor_cast = (((1900.0-((1900.0/1023.0)*anaval)))+400.0);				 //+600
	middlelegg[motor_control_num] = motor_cast;

	PORTSetBits(IOPORT_B, BIT_13); //28a
	PORTClearBits(IOPORT_B, BIT_12); //27b
	PORTSetBits(IOPORT_D, BIT_8); //42c
	A2D_read(1, &leg_move);
 	anaval = leg_move;
	motor_cast = (((1900.0-((1900.0/1023.0)*anaval)))+400.0);				 //+600
	toplegg[motor_control_num] = motor_cast;

//	printf("bot:%d, mid:%d, top:%d\r", bottomlegg[1], middlelegg[1], toplegg[1]);
	//servomove(1);
	
}




//TRY IT MAN

int walk(int rotate_amount, int delay, int numtimes, int *bottomlegg, int *middlelegg, int *toplegg, int first_delay) //suggested inputs: rotate_amount = +-300, delay = 10
{

	int i;

	int m_deploy = 1700; int t_deploy = 1900;
	int m_raise = 2200; int t_raise = 2000;

	if(bottomlegg[1] != 1500 && bottomlegg[2] != 1500 && bottomlegg[3] != 1500 && bottomlegg[4] != 1500 && bottomlegg[5] != 1500 && bottomlegg[6] != 1500 && toplegg[1] != t_deploy && toplegg[2] != t_deploy && toplegg[3] != t_deploy && toplegg[4] != t_deploy && toplegg[5] != t_deploy && toplegg[6] != t_deploy && middlelegg[1] != m_deploy && middlelegg[2] != m_deploy && middlelegg[3] != m_deploy && middlelegg[4] != m_deploy && middlelegg[5] != m_deploy && middlelegg[6] != m_deploy)
	{
		bottomlegg[1] = 1500;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;			//for loop next of course 
		bottomlegg[2] = 1500;	toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;	toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;	toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(first_delay);														//starting position all deploy
	}
	for(i = 0; i < numtimes; i++)
	{
		bottomlegg[1] = 1500;	toplegg[1] = t_raise;	middlelegg[1] = m_raise;
		bottomlegg[2] = 1500;	toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;	toplegg[3] = t_raise;	middlelegg[3] = m_raise;
		bottomlegg[4] = 1500;	toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;	toplegg[5] = t_raise;	middlelegg[5] = m_raise;
		bottomlegg[6] = 1500;	toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// 2,4,6 deploy 1,3,5 lift,
	
		bottomlegg[1] = 1500+rotate_amount;	toplegg[1] = t_raise;	middlelegg[1] = m_raise;
		bottomlegg[2] = 1500;				toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500+rotate_amount;	toplegg[3] = t_raise;	middlelegg[3] = m_raise;
		bottomlegg[4] = 1500;				toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500+rotate_amount;	toplegg[5] = t_raise;	middlelegg[5] = m_raise;
		bottomlegg[6] = 1500;				toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// 2,4,6 deploy 1,3,5 swing thumb up positive,
	
		bottomlegg[1] = 1500+rotate_amount;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500;				toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500+rotate_amount;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;				toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500+rotate_amount;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;				toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// all deploy 1,3,5 rotated
	
		bottomlegg[1] = 1500+rotate_amount;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500;				toplegg[2] = t_raise;	middlelegg[2] = m_raise;	
		bottomlegg[3] = 1500+rotate_amount;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;				toplegg[4] = t_raise;	middlelegg[4] = m_raise;
		bottomlegg[5] = 1500+rotate_amount;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;				toplegg[6] = t_raise;	middlelegg[6] = m_raise;
		//servomove(delay);														// 2,4,6 lift 1,3,5 deploy rotated
		
		bottomlegg[1] = 1500;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500;	toplegg[2] = t_raise;	middlelegg[2] = m_raise;	
		bottomlegg[3] = 1500;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;	toplegg[4] = t_raise;	middlelegg[4] = m_raise;
		bottomlegg[5] = 1500;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;	toplegg[6] = t_raise;	middlelegg[6] = m_raise;
		//servomove(delay);														// 2,4,6 lift 1,3,5 deploy rotate back
	

	
		bottomlegg[1] = 1500;					toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500+rotate_amount;		toplegg[2] = t_raise;	middlelegg[2] = m_raise;	
		bottomlegg[3] = 1500;					toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500+rotate_amount;		toplegg[4] = t_raise;	middlelegg[4] = m_raise;
		bottomlegg[5] = 1500;					toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500+rotate_amount;		toplegg[6] = t_raise;	middlelegg[6] = m_raise;
		//servomove(delay);														// 1,3,5 deploy 2,4,6 swing thumb up positive,
	
		bottomlegg[1] = 1500;					toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500+rotate_amount;		toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;					toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500+rotate_amount;		toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;					toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500+rotate_amount;		toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// all deploy 2,4,6 rotated
	
		bottomlegg[1] = 1500;					toplegg[1] = t_raise;	middlelegg[1] = m_raise;
		bottomlegg[2] = 1500+rotate_amount;		toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;					toplegg[3] = t_raise;	middlelegg[3] = m_raise;
		bottomlegg[4] = 1500+rotate_amount;		toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;					toplegg[5] = t_raise;	middlelegg[5] = m_raise;
		bottomlegg[6] = 1500+rotate_amount;		toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// 1,3,5 lift 2,4,6 deploy rotated
		
	
	}	

}



int rotate(int rotate_amount, int delay, int numtimes, int *bottomlegg, int *middlelegg, int *toplegg, int first_delay) //suggested inputs: rotate_amount = +-300, delay = 10
{

	int i;

	int m_deploy = 1700; int t_deploy = 1900;
	int m_raise = 2200; int t_raise = 2000;

	if(bottomlegg[1] != 1500 && bottomlegg[2] != 1500 && bottomlegg[3] != 1500 && bottomlegg[4] != 1500 && bottomlegg[5] != 1500 && bottomlegg[6] != 1500 && toplegg[1] != t_deploy && toplegg[2] != t_deploy && toplegg[3] != t_deploy && toplegg[4] != t_deploy && toplegg[5] != t_deploy && toplegg[6] != t_deploy && middlelegg[1] != m_deploy && middlelegg[2] != m_deploy && middlelegg[3] != m_deploy && middlelegg[4] != m_deploy && middlelegg[5] != m_deploy && middlelegg[6] != m_deploy)
	{
		bottomlegg[1] = 1500;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;			//for loop next of course 
		bottomlegg[2] = 1500;	toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;	toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;	toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(first_delay);														//starting position all deploy
	}
	for(i = 0; i < numtimes; i++)
	{
		bottomlegg[1] = 1500;	toplegg[1] = t_raise;	middlelegg[1] = m_raise;
		bottomlegg[2] = 1500;	toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;	toplegg[3] = t_raise;	middlelegg[3] = m_raise;
		bottomlegg[4] = 1500;	toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;	toplegg[5] = t_raise;	middlelegg[5] = m_raise;
		bottomlegg[6] = 1500;	toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// 2,4,6 deploy 1,3,5 lift,
	
		bottomlegg[1] = 1500+rotate_amount;	toplegg[1] = t_raise;	middlelegg[1] = m_raise;
		bottomlegg[2] = 1500;				toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500+rotate_amount;	toplegg[3] = t_raise;	middlelegg[3] = m_raise;
		bottomlegg[4] = 1500;				toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500+rotate_amount;	toplegg[5] = t_raise;	middlelegg[5] = m_raise;
		bottomlegg[6] = 1500;				toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// 2,4,6 deploy 1,3,5 swing thumb up positive,
	
		bottomlegg[1] = 1500+rotate_amount;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500;				toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500+rotate_amount;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;				toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500+rotate_amount;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;				toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// all deploy 1,3,5 rotated
	
		bottomlegg[1] = 1500+rotate_amount;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500;				toplegg[2] = t_raise;	middlelegg[2] = m_raise;	
		bottomlegg[3] = 1500+rotate_amount;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;				toplegg[4] = t_raise;	middlelegg[4] = m_raise;
		bottomlegg[5] = 1500+rotate_amount;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;				toplegg[6] = t_raise;	middlelegg[6] = m_raise;
		//servomove(delay);														// 2,4,6 lift 1,3,5 deploy rotated
		
		bottomlegg[1] = 1500;	toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500;	toplegg[2] = t_raise;	middlelegg[2] = m_raise;	
		bottomlegg[3] = 1500;	toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500;	toplegg[4] = t_raise;	middlelegg[4] = m_raise;
		bottomlegg[5] = 1500;	toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500;	toplegg[6] = t_raise;	middlelegg[6] = m_raise;
		//servomove(delay);														// 2,4,6 lift 1,3,5 deploy rotate back
	

	
		bottomlegg[1] = 1500;					toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500+rotate_amount;		toplegg[2] = t_raise;	middlelegg[2] = m_raise;	
		bottomlegg[3] = 1500;					toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500+rotate_amount;		toplegg[4] = t_raise;	middlelegg[4] = m_raise;
		bottomlegg[5] = 1500;					toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500+rotate_amount;		toplegg[6] = t_raise;	middlelegg[6] = m_raise;
		//servomove(delay);														// 1,3,5 deploy 2,4,6 swing thumb up positive,
	
		bottomlegg[1] = 1500;					toplegg[1] = t_deploy;	middlelegg[1] = m_deploy;
		bottomlegg[2] = 1500+rotate_amount;		toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;					toplegg[3] = t_deploy;	middlelegg[3] = m_deploy;
		bottomlegg[4] = 1500+rotate_amount;		toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;					toplegg[5] = t_deploy;	middlelegg[5] = m_deploy;
		bottomlegg[6] = 1500+rotate_amount;		toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// all deploy 2,4,6 rotated
	
		bottomlegg[1] = 1500;					toplegg[1] = t_raise;	middlelegg[1] = m_raise;
		bottomlegg[2] = 1500+rotate_amount;		toplegg[2] = t_deploy;	middlelegg[2] = m_deploy;	
		bottomlegg[3] = 1500;					toplegg[3] = t_raise;	middlelegg[3] = m_raise;
		bottomlegg[4] = 1500+rotate_amount;		toplegg[4] = t_deploy;	middlelegg[4] = m_deploy;
		bottomlegg[5] = 1500;					toplegg[5] = t_raise;	middlelegg[5] = m_raise;
		bottomlegg[6] = 1500+rotate_amount;		toplegg[6] = t_deploy;	middlelegg[6] = m_deploy;
		//servomove(delay);														// 1,3,5 lift 2,4,6 deploy rotated
		
	
	}	

}

int stand(int add_neutral_val, int delay, int numtimes, int *bottomlegg, int *middlelegg, int *toplegg)		//recommended inputs: -1000, 1, 300, b/m/t   
{
	int m_deploy = 1700; int t_deploy = 1900;
	int m_raise = 2200; int t_raise = 2000;
	
	int i;
	for(i = 0; i < numtimes; i++)
	{
		bottomlegg[1] = 1500;	toplegg[1] = t_deploy+add_neutral_val;	middlelegg[1] = m_deploy+add_neutral_val;
		bottomlegg[2] = 1500;	toplegg[2] = t_deploy+add_neutral_val;	middlelegg[2] = m_deploy+add_neutral_val;	
		bottomlegg[3] = 1500;	toplegg[3] = t_deploy+add_neutral_val;	middlelegg[3] = m_deploy+add_neutral_val;
		bottomlegg[4] = 1500;	toplegg[4] = t_deploy+add_neutral_val;	middlelegg[4] = m_deploy+add_neutral_val;
		bottomlegg[5] = 1500;	toplegg[5] = t_deploy+add_neutral_val;	middlelegg[5] = m_deploy+add_neutral_val;
		bottomlegg[6] = 1500;	toplegg[6] = t_deploy+add_neutral_val;	middlelegg[6] = m_deploy+add_neutral_val;
		//servomove(delay);
	}
	
}






/*


int leg_num_1; int leg_num_2; int leg_num_3;
int leg_num_4; int leg_num_5; int leg_num_6;

void leg_lift_setup(leg_num_1, leg_num_2, leg_num_3, leg_num_4, leg_num_5, leg_num_6)
{
	neutral_position_setup();
	middlelegg[leg_num_1] = 1700;
	middlelegg[leg_num_2] = 1700;
	middlelegg[leg_num_3] = 1700;
}

void forward_leg_setup(leg_num_1, leg_num_2, leg_num_3, leg_num_4, leg_num_5, leg_num_6)	//bottom two are a pair, first is by itself for tripod
{

	toplegg[6] = 1450;  	//neutral_position_setup(); 
	middlelegg[leg_num_1] = 1700;
	middlelegg[leg_num_2] = 1700;
	middlelegg[leg_num_3] = 1700;

	bottomlegg[leg_num_4] = 1800; //2
	bottomlegg[leg_num_5] = 1200;
	bottomlegg[leg_num_6] = 1200;
}

void lift_leg_reverse_setup(leg_num_1, leg_num_2, leg_num_3, leg_num_4, leg_num_5, leg_num_6)
{
	toplegg[6] = 1450;  	//neutral_position_setup(); 
	middlelegg[leg_num_1] = 1300;
	middlelegg[leg_num_2] = 1300;
	middlelegg[leg_num_3] = 1300;
	bottomlegg[leg_num_4] = 1800;//2
	bottomlegg[leg_num_5] = 1200;
	bottomlegg[leg_num_6] = 1200;

	middlelegg[leg_num_1] = 1700;
	middlelegg[leg_num_2] = 1700;
	middlelegg[leg_num_3] = 1700;
}





void ana_leg_setup()
{
	bottomleg1 = 1500;
	middleleg1 = 1800;
	topleg1 = 1800;
	for( eye = 0; eye <=23; eye++)
	{
		bottomlegg[eye] = bottomleg1;
		middlelegg[eye] = middleleg1;
		toplegg[eye] = topleg1;
	}
	middlelegg[1] = 1300; middlelegg[3] = 1300; toplegg[1] = 1300; toplegg[3] = 1300;
	//servomove(15);

	bottomleg1 = 1500;
	middleleg1 = 1800;
	topleg1 = 1800;
	for( eye = 0; eye <=23; eye++)
	{
		bottomlegg[eye] = bottomleg1;
		middlelegg[eye] = middleleg1;
		toplegg[eye] = topleg1;
	}
	bottomlegg[4] = 1850;	bottomlegg[2] = 1150;
	//servomove(15);	



	bottomleg1 = 1500;
	middleleg1 = 1800;
	topleg1 = 1800;
	for( eye = 0; eye <=23; eye++)
	{
		bottomlegg[eye] = bottomleg1;
		middlelegg[eye] = middleleg1;
		toplegg[eye] = topleg1;
	}
	bottomlegg[4] = 1850; middlelegg[4] = 1655;	toplegg[4] = 1855;
	bottomlegg[2] = 1150; middlelegg[2] = 1655;	toplegg[2] = 1855;
	//servomove(15);	


}

*/





