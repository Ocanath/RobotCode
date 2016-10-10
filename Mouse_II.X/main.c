
//
//                 Mouse's Control Program
//
#include "userLib.h"
#include "picConfig.h"
#include "a2d.h"

#include "Mouse_Control_Functions.h"
#include "Mouse_Math.h"
#include "RobotKinematics.h"


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



int string_to_num(char * instring, int len)
{
	int st_base = 0;
	if (instring[0] == '-')
		st_base = 1;

	int retval = 0;
	int i;
	int tenpow = 1;
	for (i = len - 1; i >= st_base; i--)
	{
		if (instring[i] >= '0' && instring[i] <= '9')
		{
			retval += (instring[i] - '0')*tenpow;
			tenpow *= 10;
		}
	}
	if (st_base == 0)
		return retval;
	else
		return -retval;

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

//char inbuf[25];
void Get_input(char * inbuf, char arg, char * failed)
{            
    WriteUART1(arg);
    while(BusyUART1());
    int numbytes = 4;
    int i;
    for(i = 0; i < numbytes; i++)
    {
        inbuf[i] = 0;
        int j;
        for(j = 0; j < 5; j++)
        {
            if(U1STA & 1 != 0)
                break;
        }
        if(j == 5)
            *failed = 1;
        inbuf[i] = (UINT8)U1RXREG;                 

    } 
}



int main()
{ 
    
   
    
	int	rc;				// function return code
	rc = initialize();			// set up hardware
	checkrc(rc);			//check if successful hardwarecheck
    
    
	pin_setup();			//see Twitchy_Functions.c!!! this sets the servo channels to outputs
   
    
	LATE = 5;
	delayT1_ms(1000);
	LATE = 2;
	delayT1_ms(1000);
	printf("Hello, World!\r");
	printf("I AM MOUSADILLO\r");
    printf("Control code v2\r");
	//PORTSetPinsDigitalIn( IOPORT_F, BIT_3);
	LATE = 5;

    
    
    
 
    MouseMotors M;
	M.timearr[0] = 2300;	M.timearr[1] = 500;	M.timearr[2] = 1500;	M.timearr[3] = 440;	M.timearr[4] = 660;	M.timearr[5] = 500;	M.timearr[6] = 1230;
	M.timearr[7] = 500;	M.timearr[8] = 1500;	M.timearr[9] = 2400;	M.timearr[10] = 1400;	M.timearr[11] = 1100;	M.timearr[12] = 401;	M.timearr[13] = 402;
	M.timearr[14] = 401;	M.timearr[15] = 430;	M.timearr[16] = 590;	M.timearr[17] = 591;	M.timearr[18] = 400;	M.timearr[19] = 405;	M.timearr[20] = 412;
	M.timearr[21] = 416;	M.timearr[22] = 522;	M.timearr[23] = 1105;	M.timearr[24] = 0;
    

    M.thumb[0] = 1500;
    M.thumb[1] = 1500;
    M.fingers[0] = 1500;
    M.fingers[1] = 1500;
    starting_position(&M);
    
    
    M.neck[0] = 1000-200;
    M.neck[1] = 1000;
    move_servos(&M, 15);
    M.neck[1] = 800;
    move_servos(&M, 15);
    M.neck[0] = 1500+200;    
    move_servos(&M, 15);
    M.neck[1] = 1000;
    move_servos(&M, 15);
    M.neck[0] = 1382; M.neck[1] = 788;
    move_servos(&M, 15);
    starting_position(&M);
       
    HTmatrix HTrot_x_neg_90;
	double xrot_val = -PI / 2;
	HTrot_x_neg_90.H[0][0] = 1; HTrot_x_neg_90.H[0][1] = 0;				HTrot_x_neg_90.H[0][2] = 0;					HTrot_x_neg_90.H[0][3] = 0;
	HTrot_x_neg_90.H[1][0] = 0; HTrot_x_neg_90.H[1][1] = cos(xrot_val);	HTrot_x_neg_90.H[1][2] = -sin(xrot_val);	HTrot_x_neg_90.H[1][3] = 0;
	HTrot_x_neg_90.H[2][0] = 0; HTrot_x_neg_90.H[2][1] = sin(xrot_val);	HTrot_x_neg_90.H[2][2] = cos(xrot_val);		HTrot_x_neg_90.H[2][3] = 0;
	HTrot_x_neg_90.H[3][0] = 0; HTrot_x_neg_90.H[3][1] = 0;				HTrot_x_neg_90.H[3][2] = 0;					HTrot_x_neg_90.H[3][3] = 1;
	HTmatrix HTrot_x_pos_90;
	xrot_val = PI / 2;
	HTrot_x_pos_90.H[0][0] = 1; HTrot_x_pos_90.H[0][1] = 0;				HTrot_x_pos_90.H[0][2] = 0;					HTrot_x_pos_90.H[0][3] = 0;
	HTrot_x_pos_90.H[1][0] = 0; HTrot_x_pos_90.H[1][1] = cos(xrot_val);	HTrot_x_pos_90.H[1][2] = -sin(xrot_val);	HTrot_x_pos_90.H[1][3] = 0;
	HTrot_x_pos_90.H[2][0] = 0; HTrot_x_pos_90.H[2][1] = sin(xrot_val);	HTrot_x_pos_90.H[2][2] = cos(xrot_val);		HTrot_x_pos_90.H[2][3] = 0;
	HTrot_x_pos_90.H[3][0] = 0; HTrot_x_pos_90.H[3][1] = 0;				HTrot_x_pos_90.H[3][2] = 0;					HTrot_x_pos_90.H[3][3] = 1;
	HTmatrix Identity_H;
	Identity_H.H[0][0] = 1.0;	Identity_H.H[0][1] = 0;			Identity_H.H[0][2] = 0;		Identity_H.H[0][3] = 0;
	Identity_H.H[1][0] = 0;		Identity_H.H[1][1] = 1.0;		Identity_H.H[1][2] = 0;		Identity_H.H[1][3] = 0;
	Identity_H.H[2][0] = 0;		Identity_H.H[2][1] = 0;			Identity_H.H[2][2] = 1.0;	Identity_H.H[2][3] = 0;
	Identity_H.H[3][0] = 0;		Identity_H.H[3][1] = 0;			Identity_H.H[3][2] = 0;		Identity_H.H[3][3] = 1.0;

   
    
	//Left Mouse Arm Initialization
    HTmatrix HMW_B;
	copy_HT(&HMW_B, &Identity_H);
	//Mouse Base to 0
	HTmatrix LMB_0;
	copy_HT(&LMB_0, &Identity_H);
	HT_Multiply(HTrot_x_neg_90, LMB_0, &LMB_0);
	LMB_0.H[1][3] = 86.18;
	HTmatrix LMW_0;
	HT_Multiply(HMW_B, LMB_0, &LMW_0);
	//forward K setup, DH table
	DH_entry DH_LMouse[MOUSE_ARM_ARR_SIZE];
	DH_LMouse[1].d = 14.564;	DH_LMouse[1].a = -11.471;		DH_LMouse[1].alpha = PI / 2;	
	DH_LMouse[2].d = 11.246;	DH_LMouse[2].a = -10.16;		DH_LMouse[2].alpha = PI / 2;		
	DH_LMouse[3].d = 98.709;	DH_LMouse[3].a = -10.59;		DH_LMouse[3].alpha = PI / 2;	
	DH_LMouse[4].d = 7.08;		DH_LMouse[4].a = -5.99;			DH_LMouse[4].alpha = PI / 2;		
	DH_LMouse[5].d = 146.469;	DH_LMouse[5].a = 0;				DH_LMouse[5].alpha = -PI / 2;		
	DH_LMouse[1].theta = -PI / 2;	DH_LMouse[2].theta = -PI / 2;	DH_LMouse[3].theta = PI / 2;
	DH_LMouse[4].theta = -PI / 2;	DH_LMouse[5].theta = 0;
	HTmatrix LMouseAdj[MOUSE_ARM_ARR_SIZE];
	HTmatrix LMouseBase[MOUSE_ARM_ARR_SIZE];
	init_forward_kinematics(DH_LMouse, LMouseAdj, LMouseBase, MOUSE_ARM_SIZE);
    double LJ[6][MOUSE_ARM_SIZE]; double LJ_Transpose[MOUSE_ARM_SIZE][6];
	P3D LMouseDes;
	LMouseDes.x = 50; LMouseDes.y = 0; LMouseDes.z = 50;
    LMouseDes.x = LMouseBase[5].H[0][3]; LMouseDes.y = LMouseBase[5].H[1][3]; LMouseDes.z = LMouseBase[5].H[2][3];


	//Right Mouse Initialization
	HTmatrix RMB_0;
	copy_HT(&RMB_0, &Identity_H);
	HT_Multiply(HTrot_x_pos_90, RMB_0, &RMB_0);
	RMB_0.H[1][3] = -86.18;
	HTmatrix RMW_0;
	HT_Multiply(HMW_B, RMB_0, &RMW_0);
	// forward K setup, DH table
	DH_entry DH_RMouse[MOUSE_ARM_ARR_SIZE];
	DH_RMouse[1].d = 14.564;	DH_RMouse[1].a = -11.471;	DH_RMouse[1].alpha = -PI / 2;
	DH_RMouse[2].d = 11.246;	DH_RMouse[2].a = -10.16;	DH_RMouse[2].alpha = -PI / 2;
	DH_RMouse[3].d = 98.709;	DH_RMouse[3].a = -10.59;	DH_RMouse[3].alpha = -PI / 2;
	DH_RMouse[4].d = 7.08;		DH_RMouse[4].a = -5.99;		DH_RMouse[4].alpha = -PI / 2;
	DH_RMouse[5].d = 146.469;	DH_RMouse[5].a = 0;			DH_RMouse[5].alpha = PI / 2;
	DH_RMouse[1].theta = PI/2; DH_RMouse[2].theta = PI/2; DH_RMouse[3].theta = -PI/2;
	DH_RMouse[4].theta = PI/2; DH_RMouse[5].theta = 0;
	HTmatrix RMouseAdj[MOUSE_ARM_ARR_SIZE];
	HTmatrix RMouseBase[MOUSE_ARM_ARR_SIZE];
	init_forward_kinematics(DH_RMouse, RMouseAdj, RMouseBase, MOUSE_ARM_SIZE);
	double RJ[6][MOUSE_ARM_SIZE]; double RJ_Transpose[MOUSE_ARM_SIZE][6];
	P3D RMouseDes;
	RMouseDes.x = 50; RMouseDes.y = 0; RMouseDes.z = 50;
    RMouseDes.x = RMouseBase[5].H[0][3]; RMouseDes.y = RMouseBase[5].H[1][3]; RMouseDes.z = RMouseBase[5].H[2][3];

    
    
    
    
    unsigned char right_blade_extend = 0;
    unsigned char left_blade_extend = 0;
    
    unsigned int time = 0;
    char ctl_val = INTERNAL_CONTROL;
    M.neck[0] = 1382; M.neck[1] = 788;
    int sel_joint = 0;
    
    while(1)
    {
       // Keyboard_Control(timearr, shoulder, upper_arm, elbow_upper,  elbow_lower, wrist, blade, &waist, neck, waypoints, 0, 10);
        while(!DataRdyUART2())
        {
            time ++;
            
            M.waist = 1750;
            forward_kinematics(DH_RMouse, RMouseAdj, RMouseBase, MOUSE_ARM_SIZE);
            inverse_kinematics(RMouseDes, DH_RMouse, RJ, RJ_Transpose, RMouseBase, MOUSE_ARM_SIZE, .000015);
    
            forward_kinematics(DH_LMouse, LMouseAdj, LMouseBase, MOUSE_ARM_SIZE);
    		inverse_kinematics(LMouseDes, DH_LMouse, LJ, LJ_Transpose, LMouseBase, MOUSE_ARM_SIZE, .000015);
                
            //Radians_To_Encoder_Pos_II(DH_LMouse, DH_RMouse, &M);
            move_servos_IK_delay(&M, 1, 10);
            //function to update the blades based on user input
            drive_blades(&M, right_blade_extend, left_blade_extend);
            //startup animation.
//            Startup_Animation(time, Lm_theta, Rm_theta,
//                                &LM_xpos, &LM_ypos, &LM_zpos,
//                                    &RM_xpos, &RM_ypos, &RM_zpos,
//                                        &left_blade_extend, &right_blade_extend, &ctl_val, &M);
//            
            /////////////////////////////////////////////////////////////////////////////////
        }
        //end of IK loop. Enters below code
        //whenever you receive a byte over UART2, the terminal UART.        
        char UART_rd = ReadUART2();
        if(UART_rd == 'q')
            M.shoulder[0]++;
        else if(UART_rd == 'a')
            M.shoulder[0]--;
        if(UART_rd == 'w')
            M.upper_arm[0]++;
        else if(UART_rd == 's')
            M.upper_arm[0]--;
        if(UART_rd == 'e')
            M.elbow_upper[0]++;
        else if(UART_rd == 'd')
            M.elbow_upper[0]--;        
        if(UART_rd == 'r')
            M.elbow_lower[0]++;
        else if(UART_rd == 'f')
            M.elbow_lower[0]--;
        if(UART_rd == 't')
            M.wrist[0]++;
        else if(UART_rd == 'g')
            M.wrist[0]--;        
        if(UART_rd == 'Q')
            M.shoulder[1]++;
        else if(UART_rd == 'A')
            M.shoulder[1]--;
        if(UART_rd == 'W')
            M.upper_arm[1]++;
        else if(UART_rd == 'S')
            M.upper_arm[1]--;
        if(UART_rd == 'E')
            M.elbow_upper[1]++;
        else if(UART_rd == 'D')
            M.elbow_upper[1]--;        
        if(UART_rd == 'R')
            M.elbow_lower[1]++;
        else if(UART_rd == 'F')
            M.elbow_lower[1]--;
        if(UART_rd == 'T')
            M.wrist[1]++;
        else if(UART_rd == 'G')
            M.wrist[1]--;        
        if(UART_rd == 'p')
        {
            printf("L1 = %d, L2 = %d, L3 = %d, L4 = %d, L5 = %d ", M.shoulder[0], M.upper_arm[0], M.elbow_upper[0], M.elbow_lower[0], M.wrist[0]);
            printf("R1 = %d, R2 = %d, R3 = %d, R4 = %d, R5 = %d ", M.shoulder[1], M.upper_arm[1], M.elbow_upper[1], M.elbow_lower[1], M.wrist[1]);
        }
//        if(UART_rd >=1 && UART_rd <=5)
//            sel_joint = UART_rd;
//        if(UART_rd == 'r')
//        {
//            DH_LMouse[sel_joint].theta += .01;
//            DH_RMouse[sel_joint].theta -= .01;
//        }
//        else if(UART_rd == 'f')
//        {
//            DH_LMouse[sel_joint].theta -= .01;
//            DH_RMouse[sel_joint].theta += .01;
//        }        
//        if (UART_rd == 't')
//            right_blade_extend = !right_blade_extend;
//        else if (UART_rd == 'y')
//            left_blade_extend = !left_blade_extend;
//        
//        if (UART_rd == 'l')
//            M.neck[0] += MOUSE_NECK_STEP;
//        else if (UART_rd == 'k')
//            M.neck[1] += MOUSE_NECK_STEP;
//        else if (UART_rd == 'i')
//            M.neck[1] -= MOUSE_NECK_STEP;
//        else if (UART_rd == 'j')
//            M.neck[0] -= MOUSE_NECK_STEP;
//
//        if (UART_rd == 'A')
//            M.thumb[0] += THUMB_STEP;
//        else if (UART_rd == 'Z')
//            M.thumb[0] -= THUMB_STEP;
//        else if (UART_rd == 'S')
//            M.thumb[1] += THUMB_STEP;
//        else if (UART_rd == 'X')
//            M.thumb[1] -= THUMB_STEP;
//
//        if (UART_rd == 'K')
//            M.fingers[0] += FINGERS_STEP;
//        else if (UART_rd == 'M')
//            M.fingers[0] -= FINGERS_STEP;
//        else if (UART_rd == 'J')
//            M.fingers[1] += FINGERS_STEP;
//        else if (UART_rd == 'N')
//            M.fingers[1] -= FINGERS_STEP;
//
        else if (UART_rd == 'P')
        {
            printf("M.fingers[0] = %d; M.fingers[1] = %d;\r", M.fingers[0], M.fingers[1]);
            printf("M.thumb[0] = %d; M.thumb[1] = %d;\r", M.thumb[0], M.thumb[1]);
            printf("M.neck[0] = %d; M.neck[1] = %d;\r", M.neck[0], M.neck[1]);
            printf("M.blade[0] = %d; M.blade[1] = %d;\r", M.blade[0], M.blade[1]);
        }
        

        
    }    
    
}


