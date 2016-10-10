#include "BotControl.h"
#include <stdio.h>
#include "userLib.h"
#include "RobotKinematics.h"

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



void Radians_To_Encoder_Pos(DH_entry * DH_AViCS, int * EncList)
{
    //e 1214->0, 400->pi/2
    double D1_c = -518.208494;
    //1280->pi/2, 490->0
    double D2_c = 502.92962;
    //880->0, 1630->(-pi/2)
    double D3_c = -477.464829;
    //1340->0, 2300->(-pi/2)
    double D4_c = -611.154981;
    //1410->0,  2415->(-pi/2))
    double D5_c = -639.802871;
    //1270->(-pi/2),  2180->0
    double D6_c = 579.323992854;
    
    EncList[1] = DH_AViCS[1].theta*D1_c + 1214;
    EncList[2] = DH_AViCS[2].theta*D2_c + 490;
    EncList[3] = DH_AViCS[3].theta*D3_c + 880;
    EncList[4] = DH_AViCS[4].theta*D4_c + 1340;
    EncList[5] = DH_AViCS[5].theta*D5_c + 1410;
    EncList[6] = DH_AViCS[6].theta*D6_c + 2180;
    
    
}


void move_servos(int * servo_list, int * Enc_list, int cycles)
{
    servo_list[0] = Enc_list[1];   //pin 4
	servo_list[1] = Enc_list[2];   //pin 5	
    servo_list[2] = Enc_list[3]; //top			//pin 6
	servo_list[3] = Enc_list[4]; //bottom	//pin 8
	servo_list[6] = Enc_list[5]; //bottom	//pin 11
    servo_list[8] = Enc_list[6]; // middle	//pin 14
    
    
	servo_list[4] = 400; // top	//pin 48
	servo_list[5] = 400; //bottom	//pin 37
    servo_list[7] = 400;
	servo_list[18] = 400; //middle 	//pin 43
	servo_list[22] = 400; // top		//pin 55
	servo_list[20] = 400;//bottom 	//pin 53
	servo_list[14] = 400; //middle	
	servo_list[12] = 400; // top
	servo_list[19] = 400; //bottom     //pin 
	servo_list[11] = 400; //middle			
	servo_list[13] = 400; // top
	servo_list[21] = 400; //bottom
	servo_list[9] = 400;
	servo_list[16] = 400; // top		//pin 16
    servo_list[10] = 400;
    servo_list[15] = 400;
    servo_list[23] = 400; //middle	//pin 23
	servo_list[17] = 400;
	
    
	hexmotors(cycles, servo_list, 10);																		//2
      
}

void move_servos_IK_delay(int * servo_list, int * Enc_list, int cycles, int delay)
{
    servo_list[0] = Enc_list[1];   //pin 4
	servo_list[1] = Enc_list[2];   //pin 5	
    servo_list[2] = Enc_list[3]; //top			//pin 6
	servo_list[3] = Enc_list[4]; //bottom	//pin 8
	servo_list[6] = Enc_list[5]; //bottom	//pin 11
    servo_list[8] = Enc_list[6]; // middle	//pin 14
    
	servo_list[4] = 400; // top	//pin 48
	servo_list[5] = 400; //bottom	//pin 37
    servo_list[7] = 400;
	servo_list[18] = 400; //middle 	//pin 43
	servo_list[22] = 400; // top		//pin 55
	servo_list[20] = 400;//bottom 	//pin 53
	servo_list[14] = 400; //middle	
	servo_list[12] = 400; // top
	servo_list[19] = 400; //bottom     //pin 
	servo_list[11] = 400; //middle			
	servo_list[13] = 400; // top
	servo_list[21] = 400; //bottom
	servo_list[9] = 400;
	servo_list[16] = 400; // top		//pin 16
    servo_list[10] = 400;
    servo_list[15] = 400;
    servo_list[23] = 400; //middle	//pin 23
	servo_list[17] = 400;
    
	hexmotors(cycles, servo_list, delay);																		//2
      
}

//EXAMPLE of necessary custom functions. maybe move to a file called ROBOTNAME_Helper

//
//void Twitchy_Leg_Limit_Joints(double * Theta)
//{
//	
//
//	if (Theta[1] > 3.14159265359 + 1.57079632679 - .01)
//		Theta[1] = 3.14159265359 + 1.57079632679 - .01;
//	else if (Theta[1] < 3.14159265359 - 1.57079632679 + .01)
//		Theta[1] = 3.14159265359 - 1.57079632679 + .01;
//	
//	if (Theta[2] > 3.14159265359 + 1.57079632679 - .01)
//		Theta[2] = 3.14159265359 + 1.57079632679 - .01;
//	else if (Theta[2] < 3.14159265359 - 1.57079632679 + .01)
//		Theta[2] = 3.14159265359 - 1.57079632679 + .01;
//
//	if (Theta[3] > -1.57079632679 + 1.57079632679 - .01)
//		Theta[3] = -1.57079632679 + 1.57079632679 - .01;
//	else if (Theta[3] < -1.57079632679 - 1.57079632679 + .01)
//		Theta[3] = -1.57079632679 - 1.57079632679 + .01;
//
//}
//
//
//void Radians_To_Encoder_Pos(double TW_theta[7][4], int * b, int * m, int * t, int * claw)
//{
//
//    double D_c = 593.329628;
//    
//    int legnum = 1;
//    b[legnum] = (TW_theta[legnum][1] * D_c - 443.0);
//    m[legnum] = (TW_theta[legnum][2] * D_c - 384.0);
//    t[legnum] = (TW_theta[legnum][3] * -D_c + 787.999999762);
//    
//    
//    
//    legnum = 2;
//    b[legnum] = (TW_theta[legnum][1] * D_c - 724.0);
//    m[legnum] = (TW_theta[legnum][2] * D_c - 386.0);
//    t[legnum] = (TW_theta[legnum][3] * -D_c + 783.999999762);
//
//    //b: 1300 - 3.14159265359*593.329628
//    //m: 1500 - 3.14159265359*593.329628
//    //t: 1660 - (-1.57079632679)*(-593.329628)
//       
//    legnum = 3;
//    b[legnum] = (TW_theta[legnum][1] * D_c - 564.0);
//    m[legnum] = (TW_theta[legnum][2] * D_c -364.0);
//    t[legnum] = (TW_theta[legnum][3] * -D_c + 727.999999762);
//    
//    //b: 1720 - 3.14159265359*593.329628
//    //m: 1440 - 3.14159265359*593.329628    
//    //t: 1560 - (-1.57079632679)*(-593.329628)
//    
//    legnum = 4;
//    b[legnum] = (TW_theta[legnum][1] * D_c - 144.000000482);
//    m[legnum] = (TW_theta[legnum][2] * D_c - 424.000000482);
//    t[legnum] = (TW_theta[legnum][3] * -D_c + 627.999999762);
//
//    //b: 1364 - 3.14159265359*593.329628
//    //m: 1517 - 3.14159265359*593.329628
//    //t: 1726 - (-1.57079632679)*(-593.329628)
//    
//    
//    legnum = 5;
//    b[legnum] = (TW_theta[legnum][1] * D_c - 500.000000482);
//    m[legnum] = (TW_theta[legnum][2] * D_c - 347.000000482);
//    t[legnum] = (TW_theta[legnum][3] * -D_c + 793.999999762);
//    
//    //b: 1200 - 3.14159265359*593.329628
//    //m: 1498 - 3.14159265359*593.329628
//    //t: 1680 - (-1.57079632679)*(-593.329628)
//    
//    
//    legnum = 6;
//    b[legnum] = (TW_theta[legnum][1] * D_c - 664.000000482);
//    m[legnum] = (TW_theta[legnum][2] * D_c - 366.000000482);
//    t[legnum] = (TW_theta[legnum][3] * -D_c + 747.999999762);
//
//    
//    
//}
//
