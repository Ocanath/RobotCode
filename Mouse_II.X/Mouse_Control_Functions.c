

#include "Mouse_Control_Functions.h"
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



void move_servos(MouseMotors * M, int cycles)
{
	 M->timearr[18] =M->shoulder[1]; //middle 	//pin 43
	 M->timearr[22] =M->shoulder[0]; // top		//pin 55
	 M->timearr[20] = M->upper_arm[0];//bottom 	//pin 53
	 M->timearr[0] = 400;
	 M->timearr[14] = M->upper_arm[1]; //middle	//pin 30
	 M->timearr[12] = M->elbow_upper[0]; // top	//pin 24
	 M->timearr[19] = M->elbow_upper[1]; //bottom     //pin 27                                                                                                                                                                                                                                           
     M->timearr[7] = 400;
	 M->timearr[11] = M->elbow_lower[0]; //middle	//pin 23		
	 M->timearr[13] = M->elbow_lower[1]; // top		//pin 33
	 M->timearr[21] = M->wrist[1]; //bottom		//pin 28
	 M->timearr[9] = 400;
	 M->timearr[1] = M->wrist[0]; //middle	//pin 5	
	 M->timearr[16] = M->blade[0]; // top		//pin 16
	 M->timearr[6] = M->blade[1]; //bottom	//pin 11
	 M->timearr[10] = 400;	
	 M->timearr[2] = M->neck[0]; //top			//pin 6
	 M->timearr[8] = M->neck[1]; // middle	//pin 14
	 M->timearr[3] = M->waist; //bottom	//pin 8
     M->timearr[15] = M->thumb[0];       //pin42
	 M->timearr[23] = M->thumb[1];       //pin58        //CLEAR HEATSHRING
     M->timearr[4] = M->fingers[0];        //pin48
     M->timearr[5] = M->fingers[1];        //pin47      //RED HEATSHRING
     M->timearr[17] = 400;
	hexmotors(cycles, M->timearr, 10);																		//2  
}

void move_servos_IK_delay(MouseMotors * M, int cycles, int delay)
{
	 M->timearr[18] =M->shoulder[1]; //middle 	//pin 43
	 M->timearr[22] =M->shoulder[0]; // top		//pin 55
	 M->timearr[20] = M->upper_arm[0];//bottom 	//pin 53   
	 M->timearr[0] = 400;
	 M->timearr[14] = M->upper_arm[1]; //middle	//pin 30
	 M->timearr[12] = M->elbow_upper[0]; // top	//pin 24
	 M->timearr[19] = M->elbow_upper[1]; //bottom     //pin 27                                                                                                                                                                                                                                           
     M->timearr[7] = 400;
	 M->timearr[11] = M->elbow_lower[0]; //middle	//pin 23		
	 M->timearr[13] = M->elbow_lower[1]; // top		//pin 33
	 M->timearr[21] = M->wrist[1]; //bottom		//pin 28
	 M->timearr[9] = 400;
	 M->timearr[1] = M->wrist[0]; //middle	//pin 5	
	 M->timearr[16] = M->blade[0]; // top		//pin 16
	 M->timearr[6] = M->blade[1]; //bottom	//pin 11
	 M->timearr[10] = 400;	
	 M->timearr[2] = M->neck[0]; //top			//pin 6
	 M->timearr[8] = M->neck[1]; // middle	//pin 14
	 M->timearr[3] = M->waist; //bottom	//pin 8
     M->timearr[15] = M->thumb[0];       //pin42
	 M->timearr[23] = M->thumb[1];       //pin58        //CLEAR HEATSHRING
     M->timearr[4] = M->fingers[0];        //pin48
     M->timearr[5] = M->fingers[1];        //pin47      //RED HEATSHRING
     M->timearr[17] = 400;

     hexmotors(cycles, M->timearr, delay);																		//2  
}



void starting_position( MouseMotors * M)
{    
   M->shoulder[0] = 892;M->shoulder[1] = 1949;
    M->upper_arm[0] = 1502; M->upper_arm[1] = 1247;
    M->elbow_upper[0] = 1216; M->elbow_upper[1] = 1505;
    M->elbow_lower[0] = 1442; M->elbow_lower[1] = 1507;
    M->wrist[0] = 1668; M->wrist[1] = 1093;
    M->blade[0] = 1696;
    M->blade[1] = 565;
    
    M->waist = 1936;
    M->neck[0] = 1492; M->neck[1] = 968;
    
    M->thumb[0] = 1500;
    M->thumb[1] = 1500;
    M->fingers[0] = 1500;
    M->fingers[1] = 1500;
    

}


void Radians_To_Encoder_Pos_II(DH_entry * DH_L, DH_entry * DH_R, MouseMotors * M)
{
    double D1_c = -529.667649529;
    double D2_c = 593.329628;
    double D3_c = -D2_c;
    double D4_c = 579.164838;    
    double D5_c = -579.164838;
        
    M->shoulder[0] = DH_L[1].theta * D1_c  -259.999997;
    M->shoulder[1] = DH_R[1].theta * D1_c  + 2978.99795605;
    
    M->upper_arm[0] = DH_L[2].theta * D2_c + 273; // or 273  2137;
    M->upper_arm[1] = DH_R[2].theta * D2_c + 2458; // or   594;
    
    
    M->elbow_upper[0] = DH_L[3].theta * D3_c + 2387; // 523
    M->elbow_upper[1] = DH_R[3].theta * D3_c + 429; // 2293
    
    M->elbow_lower[0] = DH_L[4].theta * D4_c + 540.25; // 2359.75
    M->elbow_lower[1] = DH_R[4].theta * D4_c + 2355.75; // 536.249999861
    
    M->wrist[0] = DH_L[5].theta * D5_c + 1243;
    M->wrist[1] = DH_R[5].theta * D5_c + 1347;

}


void Radians_To_Encoder_Pos(double * Lm_theta, double * Rm_theta, double * TH_neck, double TH_waist, MouseMotors * M)
{

    double D1_c = -529.667649529;
    double D2_c = 593.329628;
    double D3_c = -D2_c;
    
    double D4_c = 579.164838;
    
    double D5_c = -579.164838;
    
    //double D4_c = ;
    //double D5_c = ;
    
   M->shoulder[0] = Lm_theta[1]*D1_c  -259.999997;
   M->shoulder[1] = Rm_theta[1] * D1_c  + 2978.99795605;
    
    M->upper_arm[0] = Lm_theta[2] * D2_c + 273; // or 273  2137;
    M->upper_arm[1] = Rm_theta[2] * D2_c + 2458; // or   594;
    
    
    M->elbow_upper[0] = Lm_theta[3] * D3_c + 2387; // 523
    M->elbow_upper[1] = Rm_theta[3] * D3_c + 429; // 2293
    
    M->elbow_lower[0] = Lm_theta[4] * D4_c + 540.25; // 2359.75
    M->elbow_lower[1] = Rm_theta[4] * D4_c + 2355.75; // 536.249999861
    
    M->wrist[0] = Lm_theta[5] * D5_c + 1243;
    M->wrist[1] = Rm_theta[5] * D5_c + 1347;
    
    
    
    
    //M->wrist[0] = 1243;
    //M->wrist[1] = 1347;
    
    
    
    
    //M->elbow_lower[0] = 1450;
    //M->elbow_lower[1] = 1446;
    //M->blade[0] = 1696;
    //M->blade[1] = 565;
    //M->waist = 1501;
    //M->neck[0] = 1349;
    //M->neck[1] = 939;
}


void Startup_Animation(unsigned int time,double * Lm_theta, double * Rm_theta,
                        double * LM_xpos, double * LM_ypos, double * LM_zpos,
                            double * RM_xpos, double * RM_ypos,  double * RM_zpos, 
                                unsigned char * left_blade_extend, unsigned char * right_blade_extend, unsigned char * ctl_val, MouseMotors * M)
{
    if(*ctl_val == INTERNAL_CONTROL)
    {
        if(time == 30)
        {
            *left_blade_extend = 1; *right_blade_extend = 1;
            hand_close('l', M);
            hand_close('r', M);
        }
        else if(time == 79)
        {*left_blade_extend = 0; *right_blade_extend = 0;}       
        
        else if(time == 80)
        {
//            *LM_xpos = 120.0; *LM_ypos = 0.0; *LM_zpos = 25.0;
//            *RM_xpos = 80.0; *RM_ypos = 0.0; *RM_zpos = -15.0;          
//            Lm_theta[3] = 1.558083;
//            Rm_theta[3] = -2.435800;   
        }       
        else if (time == 90)
        {
//            hand_open('l', M);
//            hand_close('l', M);
//            hand_open('l', M);
//            hand_close('l', M);
//            *left_blade_extend = 1; *right_blade_extend = 1;
        }
        
        
        
        else if (time == 100)
        {
            *left_blade_extend = 0; *right_blade_extend = 0;
            *ctl_val = USER_CONTROL;
            printf("control passed to user!\r");
        }
        
    }
//    else
//        printf("ERR: STARTUP ANIMATION FAILED. CHANGE CONTROL PERMISSION TO INTERNAL\r");
}



void drive_blades(MouseMotors * M, unsigned char right_blade_extend, unsigned char left_blade_extend)
{
    if(right_blade_extend)
        M->blade[1] = 1789;
    else
        M->blade[1] = 857;

    if(left_blade_extend)
        M->blade[0] = 620;
    else
        M->blade[0] = 1489;
}


void hand_close(char arg,  MouseMotors * M)
{
    
    char thumb_pass = 1;
    if(M->thumb[1] > 2070 && arg == 'l')
    {   
        thumb_pass = 0;
        M->thumb[1] = 2070;
    }
    if(M->thumb[0] < 1365 && arg == 'r')
    {
        thumb_pass = 0;
        M->thumb[0] = 1365;
    }
    
    if(!thumb_pass)
        move_servos(M, 10);
    if(arg == 'l')
        M->fingers[1] = 2250;
    if(arg == 'r')
        M->fingers[0] = 585; 
    move_servos(M, 10);
    if(arg == 'l')
        M->thumb[0] = 1320;
    if(arg == 'r')
        M->thumb[1] = 2100;
    move_servos(M, 10);
    
}



void hand_open(char arg,  MouseMotors * M)
{
    if(arg == 'l')
        M->thumb[1] = 2250;
    else if (arg == 'r')
        M->thumb[0] = 1395;
    move_servos(M, 10);
    if(arg == 'l')
        M->fingers[1] = 1650;
    else if (arg == 'r')
        M->fingers[0] = 1320;
    move_servos(M, 10);    
}






void Keyboard_Control(MouseMotors * M, Waypoint * waypoints, int * waypoint_idx, int waypoints_size )
{
    
    char UART_rd;
    
    int arm_to_control = 1;     //the left arm
    int enable_motors = 1;
    
    
    int step_size = 1;
    
    printf("select arm to control. 1 = left arm, 2 = right arm.\r");
    printf("'a' and 'z' control theta 1, the inner shoulder\r");
    printf("'s' and 'x' control theta 2, the outer shoulder\r");
    printf("'d' and 'c' control theta3, the upper arm\r");
    printf("'f' and 'v' control theta4, the elbow joint\r");
    printf("'g' and 'b' control theta5, the wrist joint\r");
    printf("Press ]/[ to increase/decrease the step size for the motor adjust\r");
    printf("Outputs on\r");
 
    while(1)
    {
        while(!DataRdyUART2())
        {
            if(enable_motors)
                 move_servos(M, 1);
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
        if(UART_rd >= '1' && UART_rd <= '2')
        {
            arm_to_control = UART_rd - '1';
            printf("selected : %d, ");
            if(arm_to_control == 0)
                printf("right arm\r");
            else if (arm_to_control == 1)
                printf("left arm\r");
            else
                printf("Error. This case should never happen\r");
                
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
        
        
        else if (UART_rd == 'a')
        {
           M->shoulder[arm_to_control]-=step_size;
            if(M->shoulder[arm_to_control] < 400)
               M->shoulder[arm_to_control] = 400;
  //          printf("shoulder %d value: %d\r", arm_to_control,M->shoulder[arm_to_control]);
        }
        else if (UART_rd == 'z')
        {
            M->shoulder[arm_to_control]+=step_size;
            if(M->shoulder[arm_to_control] > 2300)
                M->shoulder[arm_to_control] = 2300;
 //           printf("shoulder %d value: %d\r", arm_to_control, M->shoulder[arm_to_control]);
        }
        else if (UART_rd == 's')
        {
            M->upper_arm[arm_to_control]-=step_size;
            if(M->upper_arm[arm_to_control] < 400)
                M->upper_arm[arm_to_control] = 400;
  //           printf("upper arm %d value: %d\r", arm_to_control, M->upper_arm[arm_to_control]);
        }
        else if (UART_rd == 'x')
        {
            M->upper_arm[arm_to_control]+=step_size;
            if(M->upper_arm[arm_to_control] > 2300)
                M->upper_arm[arm_to_control] = 2300;
   //          printf("upper arm %d value: %d\r", arm_to_control, M->upper_arm[arm_to_control]);
        }
        else if (UART_rd == 'd')
        {
            M->elbow_upper[arm_to_control]-=step_size;
            if(M->elbow_upper[arm_to_control] < 400)
                M->elbow_upper[arm_to_control] = 400;
  //           printf("elbow upper %d value: %d\r", arm_to_control, M->elbow_upper[arm_to_control]);
        }
        else if (UART_rd == 'c')
        {
            M->elbow_upper[arm_to_control]+=step_size;
            if(M->elbow_upper[arm_to_control] > 2300)
                M->elbow_upper[arm_to_control] = 2300;
    //         printf("elbow upper %d value: %d\r", arm_to_control, M->elbow_upper[arm_to_control]);
        }  
        else if (UART_rd == 'f')
        {
            M->elbow_lower[arm_to_control]-=step_size;
            if(M->elbow_lower[arm_to_control] < 400)
                M->elbow_lower[arm_to_control] = 400;
   //          printf("elbow lower %d value: %d\r", arm_to_control, M->elbow_lower[arm_to_control]);
        }
        else if (UART_rd == 'v')
        {
            M->elbow_lower[arm_to_control]+=step_size;
            if(M->elbow_lower[arm_to_control] > 2300)
                M->elbow_lower[arm_to_control] = 2300;
   //          printf("elbow lower %d value: %d\r", arm_to_control, M->elbow_lower[arm_to_control]);
        }   
        else if (UART_rd == 'g')
        {
            M->wrist[arm_to_control]-=step_size;
            if(M->wrist[arm_to_control] < 400)
                M->wrist[arm_to_control] = 400;
 //            printf("wrist %d value: %d\r", arm_to_control, M->wrist[arm_to_control]);
        }
        else if (UART_rd == 'b')
        {
            M->wrist[arm_to_control]+=step_size;
            if(M->wrist[arm_to_control] > 2300)
                M->wrist[arm_to_control] = 2300;
 //            printf("wrist %d value: %d\r", arm_to_control, M->wrist[arm_to_control]);
        }
        
        else if (UART_rd == 'j')
        {
            M->neck[0] += step_size;
            if(M->neck[0] > 2300)
                M->neck[0] = 2300;
  //           printf("lower neck value: %d\r", M->neck[0]);
        }
        else if (UART_rd == 'l')
        {
            M->neck[0] -= step_size;
            if(M->neck[0] < 400)
                M->neck[0] = 400;
  //           printf("lower neck value: %d\r", M->neck[0]);
        }
        else if (UART_rd == 'k')
        {
            M->neck[1] += step_size;
            if(M->neck[1] > 2300)
                M->neck[1] = 2300;
   //          printf("upper neck value: %d\r", M->neck[1]);
        }
        else if (UART_rd == 'i')
        {
            M->neck[1] -= step_size;
            if(M->neck[1] < 400)
                M->neck[1] = 400;
  //           printf("upper neck value: %d\r", M->neck[1]);
        }
          
        else if (UART_rd == 'n')
        {
            M->waist -= step_size;
            if(M->waist < 400)
                M->waist = 400;
  //           printf("upper neck value: %d\r", M->neck[1]);
        }
        else if (UART_rd == 'm')
        {
            M->waist += step_size;
            if(M->waist > 2300)
                M->waist = 2300;
        }
        
        
        
        
        
        
        
        
        
        
        else if (UART_rd == 'q')
        {
            M->blade[0] -= step_size;
            if(M->blade[0] < 400)
                M->blade[0] = 400;
  //           printf("upper neck value: %d\r", M->neck[1]);
        }
        else if (UART_rd == 'w')
        {
            M->blade[0] += step_size;
            if(M->blade[0] > 2300)
                M->blade[0] = 2300;
        }
        else if (UART_rd == 'e')
        {
            M->blade[1] -= step_size;
            if(M->blade[1] < 400)
                M->blade[1] = 400;
  //           printf("upper neck value: %d\r", M->neck[1]);
        }
        else if (UART_rd == 'r')
        {
            M->blade[1] += step_size;
            if(M->blade[1] > 2300)
                M->blade[1] = 2300;
        }
        
        
        
        
        else if (UART_rd == 'P')
        {
            printf("s[0] = %d; M->shoulder[1] = %d;\r", M->shoulder[0], M->shoulder[1]);
            printf("M->upper_arm[0] = %d; M->upper_arm[1] = %d;\r", M->upper_arm[0], M->upper_arm[1]);
            printf("M->elbow_upper[0] = %d; M->elbow_upper[1] = %d;\r", M->elbow_upper[0], M->elbow_upper[1]);
            printf("M->elbow_lower[0] = %d; M->elbow_lower[1] = %d;\r", M->elbow_lower[0], M->elbow_lower[1]);            
            printf("M->wrist[0] = %d; M->wrist[1] = %d;\r", M->wrist[0], M->wrist[1]);
            printf("M->blade[0] = %d; M->blade[1] = %d;\r", M->blade[0], M->blade[1]);
            printf("M->waist = %d;\r", M->waist);
            printf("M->neck[0] = %d; M->neck[1] = %d;\r", M->neck[0], M->neck[1]);
        }
        
        
        
        
        
        
        
        
        
        
        
        
    }
    
    
    
}












void neutral_position(MouseMotors * M)
{

	M->shoulder[0] = 1200; 	M->shoulder[1] = 1650;
	M->upper_arm[0] = 1300;	M->upper_arm[1] = 1500;
	M->elbow_upper[0] = 1300;		M->elbow_upper[1] = 1600;
	M->elbow_lower[0] = 1250; M->elbow_lower[1] = 1500;	
	M->wrist[0] = 1500; M->wrist[1] = 1500;
	M->blade[0] = 1500; M->blade[1] = 1500;
	M->neck[0] = 1500;	M->neck[1] = 1500;
	
}










//
//
//
//int zero_to_one(int zeroin)
//{
//	return (2300-zeroin)+400;
//}
//

//
//void right_punch(int * servo_list, int * s, int * u_a, int * el_u, int * el_low, int * w_r, int * blade, int * waist, int * neck, int speed)
//{
//    
//        neutral_position(s, u_a, el_u,  el_low, w_r,  blade, waist, neck);
//	//	neutral_position(s, u_a, el_u,  el_low,  w_r, blade,  neck);		
//		s[1] = zero_to_one(1500)+100;		//1200	//middle
//		M->upper_arm[1] = zero_to_one(1100)+200;
//		M->elbow_lower[1] = zero_to_one(1250+600);		//down (extended)
//		
//        move_servos(servo_list, s, u_a, el_u, el_low, w_r, blade, waist, neck, 10);
//}
//
//
//void left_punch(int * servo_list, int * s, int * u_a, int * el_u, int * el_low, int * w_r, int * blade, int * waist, int * neck, int speed)	//recommended 50
//{
//
//		neutral_position(s, u_a, el_u,  el_low, w_r,  blade, waist, neck);
//
//		M->elbow_lower[0] = 950;
//		M->upper_arm[0] = 1300;
//		//servomove(5);
//        move_servos(servo_list, s, u_a, el_u, el_low, w_r, blade, waist, neck, 5);
//
//		s[0] = 1000;
//
//
//		neutral_position(s, u_a, el_u,  el_low, w_r,  blade, waist, neck);
//		s[0] = 1600;		//1200	//middle
//		M->elbow_lower[0] = 1250+600;		//down (extended)
//		M->upper_arm[0] = 1250;
//		move_servos(servo_list, s, u_a, el_u, el_low, w_r, blade, waist, neck, 10);
//		M->upper_arm[0] = 1100;
//		move_servos(servo_list, s, u_a, el_u, el_low, w_r, blade, waist, neck, speed - 10);
//
//}
//
//
//
//
//
