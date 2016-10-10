//
//                 AvICS's Control Program
//       [articulated versatile integrated camera system]
#include "userLib.h"
#include "picConfig.h"
#include "BotControl.h"
#include "RobotKinematics.h"
//#include <plib.h>




INT16 initialize()      // establish PBCLK, init timer / peripheral devices
{

   picInit(SYSCLK);          
   DDPCONbits.JTAGEN = 0;   // this will disable JTAG port
   
   TRISE = 0;         // all PORTE as output: for LEDss
   delayT1_init();      // enables use of Timer1 for delay functions
	OpenTimer45(T4_ON | T4_SOURCE_INT | T45_PRESCALER | T4_32BIT_MODE_ON, 0xFFFFFFFF);
	_TRISB14 = 0;						// set UART3B TX pin as output
	_TRISB8 = 1;						// set RX pin as input
	uart_init(UART3B, 230400, PBCLK);

	_TRISF5 = 0;						// set UART3A TX pin as output
	_TRISF4 = 1;						// set RX pin as input
	uart_init(UART3A, 9600, PBCLK);		

	setbuf(stdout,NULL);            // specify no buffering on output  
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
    
    pin_setup();

   	LATE = 5;
    delayT1_ms(1000);
    LATE = 0; 
    delayT1_ms(1000);
    LATE = 5;

	printf("Hello, World!\r");
	printf("I AM AViCS\r");
    
    
    
    HTmatrix AViCS_HW_B;	HTmatrix AVIiCS_HB_0;
	AViCS_HW_B.H[0][0] = 1;	AViCS_HW_B.H[0][1] = 0; AViCS_HW_B.H[0][2] = 0; AViCS_HW_B.H[0][3] = 0;
	AViCS_HW_B.H[1][0] = 0; AViCS_HW_B.H[1][1] = 1; AViCS_HW_B.H[1][2] = 0; AViCS_HW_B.H[1][3] = 0;
	AViCS_HW_B.H[2][0] = 0; AViCS_HW_B.H[2][1] = 0; AViCS_HW_B.H[2][2] = 1; AViCS_HW_B.H[2][3] = 0;
	AViCS_HW_B.H[3][0] = 0;	AViCS_HW_B.H[3][1] = 0; AViCS_HW_B.H[3][2] = 0; AViCS_HW_B.H[3][3] = 1;

	AVIiCS_HB_0.H[0][0] = 1; AVIiCS_HB_0.H[0][1] = 0; AVIiCS_HB_0.H[0][2] = 0; AVIiCS_HB_0.H[0][3] = 0;
	AVIiCS_HB_0.H[1][0] = 0; AVIiCS_HB_0.H[1][1] = 1; AVIiCS_HB_0.H[1][2] = 0; AVIiCS_HB_0.H[1][3] = 0;
	AVIiCS_HB_0.H[2][0] = 0; AVIiCS_HB_0.H[2][1] = 0; AVIiCS_HB_0.H[2][2] = 1; AVIiCS_HB_0.H[2][3] = 0;
	AVIiCS_HB_0.H[3][0] = 0; AVIiCS_HB_0.H[3][1] = 0; AVIiCS_HB_0.H[3][2] = 0; AVIiCS_HB_0.H[3][3] = 1;

	DH_entry DH_AViCS[AVICS_ARR_SIZE];
	DH_AViCS[1].d = 21.01;	DH_AViCS[1].a = 0;			DH_AViCS[1].alpha = 3.14159265359 / 2;
	DH_AViCS[2].d = 0;		DH_AViCS[2].a = 88.269;		DH_AViCS[2].alpha = 0;
	DH_AViCS[3].d = 0;		DH_AViCS[3].a = 0.779;		DH_AViCS[3].alpha = -3.14159265359 / 2;
	DH_AViCS[4].d = 73.976;	DH_AViCS[4].a = 0;			DH_AViCS[4].alpha = 3.14159265359 / 2;
	DH_AViCS[5].d = 0;		DH_AViCS[5].a = 0;			DH_AViCS[5].alpha = -3.14159265359 / 2;
	DH_AViCS[6].d = 50.13;	DH_AViCS[6].a = 0;			DH_AViCS[6].alpha = 3.14159265359 / 2;
	double pi_v = 3.14159265359;
	DH_AViCS[1].theta = 0;	DH_AViCS[2].theta = pi_v/2;	DH_AViCS[3].theta = 0;	
	DH_AViCS[4].theta = 0;	DH_AViCS[5].theta = 0;	DH_AViCS[6].theta = -pi_v/2;
	HTmatrix AViCS_Hadj[AVICS_ARR_SIZE];	HTmatrix AViCS_Hzero[AVICS_ARR_SIZE];
	init_forward_kinematics(DH_AViCS, AViCS_Hadj, AViCS_Hzero, AVICS_NUM_DOFS);
	//double ** AViCS_J; double ** AViCS_J_Transpose; 
	//init_jacobian(&AViCS_J, &AViCS_J_Transpose, AVICS_NUM_DOFS);
    //NOTE: unfortunately, for embedded systems malloc does not always work (see above function). for this reason, 
    //the library must sometimes be modified so that 
    double AViCS_J[6][AVICS_NUM_DOFS]; double AViCS_J_Transpose[AVICS_NUM_DOFS][6]; 
	P3D AViCS_des;
	AViCS_des.x = AViCS_Hzero[6].H[0][3]; AViCS_des.y = AViCS_Hzero[6].H[1][3]; AViCS_des.z = AViCS_Hzero[6].H[2][3];
	double AViCS_Xrot = 0; double AViCS_Yrot = 0;	double AViCS_Zrot = 0;
	int AViCS_LinkNum = 1;

    
    
    int EncList[AVICS_ARR_SIZE];
    int timearr[24];
    int i;
    EncList[1] = 1224;
    EncList[2] = 936;
    EncList[3] = 546;
    EncList[4] = 1398;
    EncList[5] = 1398;
    EncList[6] = 1194;
    
    int sel_num = 1;
    int step_val = 1;
    
    AViCS_des.x = -116.280586; AViCS_des.y = 0.038099; AViCS_des.z = 10.592713;
    DH_AViCS[1].theta = -0.000403;  DH_AViCS[2].theta = 2.148064;  DH_AViCS[3].theta = 0.734308;
    DH_AViCS[4].theta = -0.000202;  DH_AViCS[5].theta = -1.047637;  DH_AViCS[6].theta = -1.570796;

    while(1)
    {
                    
        //main control loop
        while(!DataRdyUART2())
        {
            forward_kinematics(DH_AViCS, AViCS_Hadj, AViCS_Hzero, AVICS_NUM_DOFS);
            inverse_kinematics(AViCS_des, DH_AViCS, AViCS_J, AViCS_J_Transpose, AViCS_Hzero, AVICS_NUM_DOFS, .00002);
            Radians_To_Encoder_Pos(DH_AViCS, EncList);
            move_servos(timearr, EncList, 1);
        }
        
        char UART_rd = ReadUART2();
        if(UART_rd >= '1' && UART_rd <= '6')
            sel_num = UART_rd - '0';
        else if(UART_rd == 'r')
            DH_AViCS[sel_num].theta+=.1;
        else if(UART_rd == 'f')
            DH_AViCS[sel_num].theta-=.1;

        //ONE PUUUNNNCCCHHHH
        
        P3D Pstep6;
        Pstep6.x = 0; Pstep6.y = 0; Pstep6.z = 0; 
        P3D Pstep1;
        Pstep1.x = 0; Pstep1.y = 0; Pstep1.z = 0;
        if(UART_rd == 'i')
            AViCS_des.z += 10;
        else if(UART_rd == 'k')
            AViCS_des.z += -10;
        else if(UART_rd == 'n')
        {
            //AViCS_des.x += 10;
            P3D Cur1;
            HTmatrix AViCS_H1_0;
            HT_Inverse(AViCS_Hzero[1], &AViCS_H1_0);
            HT_Point_Multiply(AViCS_H1_0, AViCS_des, &Cur1 );
            Cur1.x+=10;
            HT_Point_Multiply(AViCS_Hzero[1], Cur1, &AViCS_des);
        }
        else if(UART_rd == 'm')
        {
            //AViCS_des.x += -10;
            P3D Cur1; 
            HTmatrix AViCS_H1_0;
            HT_Inverse(AViCS_Hzero[1], &AViCS_H1_0);
            HT_Point_Multiply(AViCS_H1_0, AViCS_des, &Cur1);
            Cur1.x-=10;
            HT_Point_Multiply(AViCS_Hzero[1], Cur1, &AViCS_des);
        }
        else if(UART_rd == 'g')
        {
            Pstep6.x = 10;
            HT_Point_Multiply(AViCS_Hzero[6], Pstep6, &AViCS_des);
        }
        else if(UART_rd == 'h')
        {
            Pstep6.x = -10;
            HT_Point_Multiply(AViCS_Hzero[6], Pstep6, &AViCS_des);
        }        

        else if (UART_rd == 'j')
        {
            DH_AViCS[1].theta += .05;
            forward_kinematics(DH_AViCS, AViCS_Hadj, AViCS_Hzero, AVICS_NUM_DOFS);
            AViCS_des.x = AViCS_Hzero[6].H[0][3];   AViCS_des.y = AViCS_Hzero[6].H[1][3];   AViCS_des.z = AViCS_Hzero[6].H[2][3];
        }
        else if (UART_rd == 'l')
        {
            DH_AViCS[1].theta -= .05;
            forward_kinematics(DH_AViCS, AViCS_Hadj, AViCS_Hzero, AVICS_NUM_DOFS);
            AViCS_des.x = AViCS_Hzero[6].H[0][3];   AViCS_des.y = AViCS_Hzero[6].H[1][3];   AViCS_des.z = AViCS_Hzero[6].H[2][3];        
        }

        
        if(UART_rd == 'p')
        {
            printf("AViCS_des.x = %f; AViCS_des.y = %f; AViCS_des.z = %f;\r", AViCS_des.x, AViCS_des.y, AViCS_des.z);
            for(i = 1; i <= AVICS_NUM_DOFS; i++)
                printf("DH_AViCS[%d].theta = %f;\r", i, DH_AViCS[i].theta);
        }
        else if (UART_rd == ' ')
        {
            AViCS_des.x = -116.280586; AViCS_des.y = 0.038099; AViCS_des.z = 10.592713;
            DH_AViCS[1].theta = -0.000403;  DH_AViCS[2].theta = 2.148064;  DH_AViCS[3].theta = 0.734308;
            DH_AViCS[4].theta = -0.000202;  DH_AViCS[5].theta = -1.047637;  DH_AViCS[6].theta = -1.570796;
        }
        
    }

}



