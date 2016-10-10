
//
//                 Snowflake's Control Program
//
#include "userLib.h"
#include "picConfig.h"
#include "a2d.h"

#include "Snowflake_Control_Functions.h"
#include "Snowflake_Math.h"
#include "Movement.h"


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


	_TRISB14 = 0;						// set UART3B TX pin as output
	_TRISB8 = 1;						// set RX pin as input
	uart_init(UART3B, 230400, PBCLK);

	_TRISF5 = 0;						// set UART3A TX pin as output
	_TRISF4 = 1;						// set RX pin as input
	uart_init(UART3A, 9600, PBCLK);		




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






int main()
{


	int	rc;				// function return code
	rc = initialize();			// set up hardware
	checkrc(rc);			//check if successful hardwarecheck
    
	pin_setup();			//see Snowflake_Functions.c!!! this sets the servo channels to outputs

	UINT16 value =0x00;


	/********************************************************************************************
	code for setting up pwm outputs. 
	pwm1Handle = PWMOpen ( 1, 2, T2_PS_1_32, 65535);
	PWMWrite ( pwm1Handle, PR2/5 );
	
	UART recieve from the XCTU
	char x;
	x = _mon_getc(0);
	*********************************************************************************************/


	INT16 motor1;	INT16 motor2;	INT16 motor3;	INT16 motor4;	
	

	LATE = 5;
    delayT1_ms(1000);
    LATE = 0; 
    delayT1_ms(1000);
    LATE = 5;


	printf("Hello, World!\r");
	printf("I AM SNOWFLAKE\r");
	//PORTSetPinsDigitalIn( IOPORT_F, BIT_3);

    //SnowflakeMotors T;
    
    int timearr[24];
	timearr[0] = 2300;	timearr[1] = 500;	timearr[2] = 2200;	timearr[3] = 440;	timearr[4] = 660;	timearr[5] = 500;	timearr[6] = 1230;
	timearr[7] = 500;	timearr[8] = 400;	timearr[9] = 2400;	timearr[10] = 1400;	timearr[11] = 1100;	timearr[12] = 401;	timearr[13] = 402;
	timearr[14] = 401;	timearr[15] = 430;	timearr[16] = 590;	timearr[17] = 591;	timearr[18] = 400;	timearr[19] = 405;	timearr[20] = 412;
	timearr[21] = 416;	timearr[22] = 522;	timearr[23] = 1105;	timearr[24] = 0;
    
    int b[7];
    int m[7];
    int t[7];
    int c[7];
    
    
    
    

	int m_deploy = 1700; int t_deploy = 1900;
	int m_raise = 2200; int t_raise = 2000;


	neutral_position(150, b, m, t);
    
    /*
     * b: 1421, m: 820, t: 1020, 1
      .b: 1140, m: 820, t: 960, 2
      .b: 1300, m: 800, t: 960, 3
      .b: 1720, m: 740, t: 860, 4
      .b: 1280, m: 760, t: 980, 5
      .b: 1200, m: 840, t: 980, 6
     * 
     * 
     * 
      b: 1457, m: 1480, t: 1720
      b: 828, m: 1520, t: 1800
      b: 700, m: 1500, t: 1660
      b: 2300, m: 1316, t: 1560
      b: 1520, m: 1400, t: 1620
      b: 972, m: 1440, t: 1640
     */

    b[1] = 1421; m[1] = 1480; t[1] = 1720; c[1] = 587;
    b[2] = 1140; m[2] = 1478; t[2] = 1716; c[2] = 587;
    b[3] = 1300; m[3] = 1500; t[3] = 1660; c[3] = 587;
    b[4] = 1720; m[4] = 1440; t[4] = 1560; c[4] = 587;
    b[5] = 1364; m[5] = 1517; t[5] = 1726; c[5] = 587;
    b[6] = 1200; m[6] = 1498; t[6] = 1680; c[6] = 587;

    

    Waypoint waypoints[50];
    waypoints[0].bottomleg_snapshot[1] = 1421; 
    waypoints[0].bottomleg_snapshot[2] = 1140;
    waypoints[0].bottomleg_snapshot[3] = 1300;
    waypoints[0].bottomleg_snapshot[4] = 1720;
    waypoints[0].bottomleg_snapshot[5] = 1364;
    waypoints[0].bottomleg_snapshot[6] = 1200;
    
    waypoints[0].middleleg_snapshot[1] = 1480;
    waypoints[0].middleleg_snapshot[2] = 1478;
    waypoints[0].middleleg_snapshot[3] = 1500;    
    waypoints[0].middleleg_snapshot[4] = 1440;
    waypoints[0].middleleg_snapshot[5] = 1517;
    waypoints[0].middleleg_snapshot[6] = 1498;    

    waypoints[0].topleg_snapshot[1] = 1720;
    waypoints[0].topleg_snapshot[2] = 1716;
    waypoints[0].topleg_snapshot[3] = 1660;
    waypoints[0].topleg_snapshot[4] = 1560;
    waypoints[0].topleg_snapshot[5] = 1726;
    waypoints[0].topleg_snapshot[6] = 1680;
   
    
    waypoints[0].claw_snapshot[1] = 587;
    waypoints[0].claw_snapshot[2] = 587;
    waypoints[0].claw_snapshot[3] = 587;
    waypoints[0].claw_snapshot[4] = 587;
    waypoints[0].claw_snapshot[5] = 587;
    waypoints[0].claw_snapshot[6] = 587;
   
    
   
    
    
    
    
	////////////////////////////////////////////Snowflake-style leg


	double TW_theta[7][4];	//also because of the fucking shit c32 compiler in mplabx. sorry
	int i;
	for (i = 1; i <= 6; i++)
	{
		TW_theta[i][1] = 3.14159265359;
		TW_theta[i][2] = 3.14159265359;
		TW_theta[i][3] = -1.57079632679;
	}
	double TW_prev_theta[7][4];	//also because of the fucking shit c32 compiler in mplabx. sorry

	for (i = 1; i <= 6; i++)
	{
		TW_prev_theta[i][1] = 3.14159265359;
		TW_prev_theta[i][2] = 3.14159265359;
		TW_prev_theta[i][3] = 1.57079632679;
	}

    //CRITICAL SECTION: DETERMINES THE DH PARAMETERS OF EACH LEG. 
	double TW_d1 = -55.095; double TW_d2 = 5.505; double TW_d3 = -5.5;
	double TW_a1 = -20.32; double TW_a2 = 95.482; double TW_a3 = 154.938;
	double TW_alpha1 = -1.57079632679; double TW_alpha2 = 0.0; double TW_alpha3 = 0.0;

	//the 7 is because of the c32 compiler in mplab x. it won't actually allocate the seventh block of memory on the stack
	//i indexes the leg number. All remaining numbers refer to the coordinate frame in question. Each leg has the same DH convention
	double TLG0_1[7][4][4];
	for (i = 1; i <= 6; i++)			//0_1, DH entry 1
	{
		TLG0_1[i][0][0] = cos(TW_theta[i][1]);		TLG0_1[i][0][1] = -sin(TW_theta[i][1])*cos(TW_alpha1);		TLG0_1[i][0][2] = sin(TW_theta[i][1])*sin(TW_alpha1); 	TLG0_1[i][0][3] = TW_a1*cos(TW_theta[i][1]);
		TLG0_1[i][1][0] = sin(TW_theta[i][1]);		TLG0_1[i][1][1] = cos(TW_theta[i][1])*cos(TW_alpha1);		TLG0_1[i][1][2] = -cos(TW_theta[i][1])*sin(TW_alpha1);	TLG0_1[i][1][3] = TW_a1*sin(TW_theta[i][1]);
		TLG0_1[i][2][0] = 0;						TLG0_1[i][2][1] = sin(TW_alpha1);						TLG0_1[i][2][2] = cos(TW_alpha1);						TLG0_1[i][2][3] = TW_d1;
		TLG0_1[i][3][0] = 0;						TLG0_1[i][3][1] = 0;										TLG0_1[i][3][2] = 0;									TLG0_1[i][3][3] = 1.0;
	}
	double TLG1_2[7][4][4];
	for (i = 1; i <= 6; i++)	//DH entry 2
	{
		TLG1_2[i][0][0] = cos(TW_theta[i][2]);		TLG1_2[i][0][1] = -sin(TW_theta[i][2])*cos(TW_alpha2);		TLG1_2[i][0][2] = sin(TW_theta[i][2])*sin(TW_alpha2); 	TLG1_2[i][0][3] = TW_a2*cos(TW_theta[i][2]);
		TLG1_2[i][1][0] = sin(TW_theta[i][2]);		TLG1_2[i][1][1] = cos(TW_theta[i][2])*cos(TW_alpha2);		TLG1_2[i][1][2] = -cos(TW_theta[i][2])*sin(TW_alpha2);	TLG1_2[i][1][3] = TW_a2*sin(TW_theta[i][2]);
		TLG1_2[i][2][0] = 0;						TLG1_2[i][2][1] = sin(TW_alpha2);						TLG1_2[i][2][2] = cos(TW_alpha2);						TLG1_2[i][2][3] = TW_d2;
		TLG1_2[i][3][0] = 0;						TLG1_2[i][3][1] = 0;										TLG1_2[i][3][2] = 0;									TLG1_2[i][3][3] = 1.0;
	}
	double TLG2_3[7][4][4];
	for (i = 1; i <= 6; i++)	//DH entry 3
	{
		TLG2_3[i][0][0] = cos(TW_theta[i][3]);		TLG2_3[i][0][1] = -sin(TW_theta[i][3])*cos(TW_alpha3);		TLG2_3[i][0][2] = sin(TW_theta[i][3])*sin(TW_alpha3); 	TLG2_3[i][0][3] = TW_a3*cos(TW_theta[i][3]);
		TLG2_3[i][1][0] = sin(TW_theta[i][3]);		TLG2_3[i][1][1] = cos(TW_theta[i][3])*cos(TW_alpha3);		TLG2_3[i][1][2] = -cos(TW_theta[i][3])*sin(TW_alpha3);	TLG2_3[i][1][3] = TW_a3*sin(TW_theta[i][3]);
		TLG2_3[i][2][0] = 0;						TLG2_3[i][2][1] = sin(TW_alpha3);						TLG2_3[i][2][2] = cos(TW_alpha3);						TLG2_3[i][2][3] = TW_d3;
		TLG2_3[i][3][0] = 0;						TLG2_3[i][3][1] = 0;										TLG2_3[i][3][2] = 0;									TLG2_3[i][3][3] = 1.0;
	}

	//Establish the zero frames in the base frame
	//78.047 is the normal radius
    //CRITICAL SECTION: DESCRIBES THE LEGS RELATIVE TO THE BODY CENTER
	double TTr_0[4][4];
	TTr_0[0][0] = 1.0;	TTr_0[0][1] = 0;		TTr_0[0][2] = 0;		TTr_0[0][3] = 78.047;
	TTr_0[1][0] = 0;	TTr_0[1][1] = 1.0;		TTr_0[1][2] = 0;		TTr_0[1][3] = 0;
	TTr_0[2][0] = 0;	TTr_0[2][1] = 0;		TTr_0[2][2] = 1.0;		TTr_0[2][3] = 0;
	TTr_0[3][0] = 0;	TTr_0[3][1] = 0;		TTr_0[3][2] = 0;		TTr_0[3][3] = 1.0;
	double Base_to_0_angle = 0.0;
	double TB_0[7][4][4];
	double T0_B[7][4][4];
	for (i = 1; i <= 6; i++)
	{
		TB_0[i][0][0] = cos(Base_to_0_angle);		TB_0[i][0][1] = -sin(Base_to_0_angle);		TB_0[i][0][2] = 0;		TB_0[i][0][3] = 0;
		TB_0[i][1][0] = sin(Base_to_0_angle);		TB_0[i][1][1] = cos(Base_to_0_angle);		TB_0[i][1][2] = 0;		TB_0[i][1][3] = 0;
		TB_0[i][2][0] = 0;							TB_0[i][2][1] = 0;							TB_0[i][2][2] = 1.0;	TB_0[i][2][3] = 0;
		TB_0[i][3][0] = 0;							TB_0[i][3][1] = 0;							TB_0[i][3][2] = 0;		TB_0[i][3][3] = 1.0;
		Multiply_HT_Matrices(TB_0[i], TTr_0, TB_0[i]);
		HT_Inverse(TB_0[i], T0_B[i]);
		Base_to_0_angle += 3.14159265359 / 3;
	}
    
    init_walk(T0_B, 0);
//	double TW_0[7][4][4];
//	for (i = 1; i <= 6; i++)
//		Multiply_HT_Matrices(TW_B, TB_0[i], TW_0[i]);



    
	double T_xpos[7];	double T_ypos[7];	double T_zpos[7];
	double T_xOrient[7]; double T_yOrient[7]; double T_zOrient[7];

	for (i = 1; i <= 6; i++)
	{
		T_xpos[i] = 100.0; T_ypos[i] = 0.0; T_zpos[i] = -200.0;
		T_xOrient[i] = 0.0; T_yOrient[i] = 0.0; T_zOrient[i] = 0.0;
	}

    
	////////////////////////////////////////////end of twitchy-style leg




    b[1] = 1421; m[1] = 1480; t[1] = 1720; c[1] = 587;
    b[2] = 1140; m[2] = 1478; t[2] = 1716; c[2] = 587;
    b[3] = 1300; m[3] = 1500; t[3] = 1660; c[3] = 587;
    b[4] = 1720; m[4] = 1440; t[4] = 1560; c[4] = 587;
    b[5] = 1364; m[5] = 1517; t[5] = 1726; c[5] = 587;
    b[6] = 1200; m[6] = 1498; t[6] = 1680; c[6] = 587;


    Radians_To_Encoder_Pos(TW_theta, b,  m, t, c);
    
    int legnum = 1;   
       
//    int waypoints_size = 50; int waypoint_idx = 1;
//    //keyboard_user_control(timearr, b, m, t, c, waypoints, &waypoint_idx, waypoints_size);
//    for(i = 1; i <=6; i++)
//        printf("leg %d: b: %d, m: %d, t: %d \r", i, b[i], m[i], t[i] );
//    
//    
//    while(1)
//        move_servos(timearr, b, m, t, c, 1);
//    
    unsigned int ts = 0;
    
    
    while(1)
    {       
        
        while(!DataRdyUART2())
        {

                /////////SNOWFLAKE CODES
            i = 1; //for loop here
            for (i = 1; i <= 6; i++)
            {
                double TLG0_2[7][4][4]; double TLG0_3[7][4][4];

                Snowflake_Leg_Forward_Kinematics(TW_theta[i],
                    TLG0_1[i], TLG1_2[i], TLG2_3[i],
                    TW_alpha1, TW_alpha2, TW_alpha3, TW_a1, TW_a2, TW_a3,
                    TLG0_2[i], TLG0_3[i]);

                double SNOWFLAKE_J[6][3]; //six rows five cols
                double TRANSPOS_SNOWFLAKE_J[3][6];
                double TXV, TYV, TZV, TXR, TYR, TZR;
                Snowflake_Leg_Inverse_Kinematics(T_xpos[i], T_ypos[i], T_zpos[i], T_xOrient[i], T_yOrient[i], T_zOrient[i],
                    TW_theta[i], TW_prev_theta[i], TLG0_1[i], TLG0_2[i], TLG0_3[i],
                    SNOWFLAKE_J, TRANSPOS_SNOWFLAKE_J,
                    &TXV, &TYV, &TZV, &TXR, &TYR, &TZR, .000015);		//for mouse, 2 orders of magnitude smaller!!!! i.e. divide by 100 at least

                int j;
                for (j = 1; j <= 3; j++)
                {
                    TW_theta[i][j] += TRANSPOS_SNOWFLAKE_J[j - 1][0] * TXV + TRANSPOS_SNOWFLAKE_J[j - 1][1] * TYV + TRANSPOS_SNOWFLAKE_J[j - 1][2] * TZV;
                    TW_prev_theta[i][j] = TW_theta[i][j];
                }
                Snowflake_Leg_Limit_Joints(TW_theta[i]);
            }
            
            Radians_To_Encoder_Pos(TW_theta, b,  m, t, c);
            move_servos_IK_delay(timearr, b, m, t, c, 1, 5);
           
            
            
            ts++;
        	Walk(ts, T_xpos, T_ypos, T_zpos);

        }

        
        char buf_string[20];
        int string_idx = 0;
        double Xin = 11.11, Yin = 12.12, Zin = 7.77;    
        char UART_rd = ReadUART2();
        if(UART_rd == 'p')
        {
            
            printf("\renter X:\r");
            unsigned char exit_flag = 0;
            string_idx = 0;
            while(!exit_flag)
            {
              while(!DataRdyUART2())
              {
                move_servos(timearr, b, m, t, c, 1); 
              }
              UART_rd = ReadUART2();
              if(UART_rd == 0xD)
                  exit_flag = 1;
              else if(UART_rd == '-')
              {
                  buf_string[string_idx] = UART_rd;
                  string_idx++;
              }
              else if (UART_rd >= '0' && UART_rd <= '9')
              {
                  buf_string[string_idx] = UART_rd;
                  string_idx++;
              }              
            }
            if(string_idx > 0)
                Xin = string_to_num(buf_string, string_idx);     //load into x
    
            printf("enter Y:\r");
            exit_flag = 0;
            string_idx = 0;
            while(!exit_flag)
            {
              while(!DataRdyUART2())
              {
                  move_servos(timearr, b, m, t, c, 1); 
              }
              UART_rd = ReadUART2();
              if(UART_rd == 0xD)
                  exit_flag = 1;
              else if(UART_rd == '-')
              {
                  buf_string[string_idx] = UART_rd;
                  string_idx++;
              }
              else if (UART_rd >= '0' && UART_rd <= '9')
              {
                  buf_string[string_idx] = UART_rd;
                  string_idx++;
              }              
            }
            if(string_idx > 0)
                Yin = string_to_num(buf_string, string_idx);     //load into x
               
            printf("enter Z:\r");
            exit_flag = 0;
            string_idx = 0;
            while(!exit_flag)
            {
              while(!DataRdyUART2())
              {
                  move_servos(timearr, b, m, t, c, 1); 
              }
              UART_rd = ReadUART2();
              if(UART_rd == 0xD)
                  exit_flag = 1;
              else if(UART_rd == '-')
              {
                  buf_string[string_idx] = UART_rd;
                  string_idx++;
              }
              else if (UART_rd >= '0' && UART_rd <= '9')
              {
                  buf_string[string_idx] = UART_rd;
                  string_idx++;
              }              
            }
            if(string_idx > 0)
                Zin = string_to_num(buf_string, string_idx);     //load into x
           

            
            printf("enter leg num, or a:\r");
            exit_flag = 0;
            string_idx = 0;
            while(!exit_flag)
            {
              while(!DataRdyUART2())
              {
                  move_servos(timearr, b, m, t, c, 1); 
              }
              UART_rd = ReadUART2();
              if(UART_rd == 0xD)
                  exit_flag = 1;
              else if (UART_rd == 'a')
              {
                  for(i = 1; i <= 6; i++)
                  {
                      T_xpos[i] = Xin;
                      T_ypos[i] = Yin;
                      T_zpos[i] = Zin;                      
                  }
              }
              else if (UART_rd >= '1' && UART_rd <= '6')
              {
                      T_xpos[UART_rd-'0'] = Xin;
                      T_ypos[UART_rd-'0'] = Yin;
                      T_zpos[UART_rd-'0'] = Zin;                      
              }

              
            }
        }

        else if(UART_rd >= '1' && UART_rd <= '7')
            legnum = UART_rd - '0';
        
        else
            step_coord(UART_rd, T_xpos, T_ypos, T_zpos, legnum);
        
    }
    
        
    
}
