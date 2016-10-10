#include "Movement.h"

//good HIGH settings
#define STEPSIZE_HIGH 50
#define OUTSIZE_HIGH 20
#define RAIZE_LEVEL_HIGH -225
#define TOUCH_LEVEL_HIGH -275
//good LOW settings
#define STEPSIZE_LOW 50
#define OUTSIZE_LOW 20
#define RAIZE_LEVEL_LOW -120
#define TOUCH_LEVEL_LOW -160

#define NUM_CONFIGS 4


typedef struct
{
	double x;
	double y;
	double z;	
}Point_3d;

Point_3d WALK_kp[4][7];

//establish keypoints. label them with configuration numbers
void init_walk(double T0_B[7][4][4], int mode)
{
    int StepSize;   int OutSize;    int Raize_Level;    int Touch_Level;
    if(mode == 0)
    { StepSize = STEPSIZE_LOW; OutSize = OUTSIZE_LOW; Raize_Level = RAIZE_LEVEL_LOW; Touch_Level = TOUCH_LEVEL_LOW;   }
    else if(mode == 1)
    { StepSize = STEPSIZE_HIGH; OutSize = OUTSIZE_HIGH; Raize_Level = RAIZE_LEVEL_HIGH; Touch_Level = TOUCH_LEVEL_HIGH;   }        
        
        
	int cf_id = 0;
	WALK_kp[cf_id][1].x = 178;				WALK_kp[cf_id][1].y = 0;					WALK_kp[cf_id][1].z = Raize_Level;
	WALK_kp[cf_id][2].x = 89 + OutSize;		WALK_kp[cf_id][2].y = 154 + StepSize;		WALK_kp[cf_id][2].z = Touch_Level;
	WALK_kp[cf_id][3].x = -89;				WALK_kp[cf_id][3].y = 154;					WALK_kp[cf_id][3].z = Raize_Level;
	WALK_kp[cf_id][4].x = -178 - OutSize;	WALK_kp[cf_id][4].y = 0 + StepSize;			WALK_kp[cf_id][4].z = Touch_Level;
	WALK_kp[cf_id][5].x = -89;				WALK_kp[cf_id][5].y = -154;					WALK_kp[cf_id][5].z = Raize_Level;
	WALK_kp[cf_id][6].x = 89 + OutSize;		WALK_kp[cf_id][6].y = -154 + StepSize;		WALK_kp[cf_id][6].z = Touch_Level;
	
	cf_id = 1;
	WALK_kp[cf_id][1].x = 178 + OutSize;	WALK_kp[cf_id][1].y = 0 + StepSize;			WALK_kp[cf_id][1].z = Raize_Level;
	WALK_kp[cf_id][2].x = 89 + OutSize;		WALK_kp[cf_id][2].y = 154 - StepSize;		WALK_kp[cf_id][2].z = Touch_Level;
	WALK_kp[cf_id][3].x = -89 - OutSize;	WALK_kp[cf_id][3].y = 154 + StepSize;		WALK_kp[cf_id][3].z = Raize_Level;
	WALK_kp[cf_id][4].x = -178 - OutSize;	WALK_kp[cf_id][4].y = 0 - StepSize;			WALK_kp[cf_id][4].z = Touch_Level;
	WALK_kp[cf_id][5].x = -89 - OutSize;	WALK_kp[cf_id][5].y = -154 + StepSize;		WALK_kp[cf_id][5].z = Raize_Level;
	WALK_kp[cf_id][6].x = 89 + OutSize;		WALK_kp[cf_id][6].y = -154 - StepSize;		WALK_kp[cf_id][6].z = Touch_Level;	

	cf_id = 2;
	WALK_kp[cf_id][1].x = 178 + OutSize;	WALK_kp[cf_id][1].y = 0 + StepSize;			WALK_kp[cf_id][1].z = Touch_Level;
	WALK_kp[cf_id][2].x = 89;				WALK_kp[cf_id][2].y = 154;					WALK_kp[cf_id][2].z = Raize_Level;
	WALK_kp[cf_id][3].x = -89 - OutSize;	WALK_kp[cf_id][3].y = 154 + StepSize;		WALK_kp[cf_id][3].z = Touch_Level;
	WALK_kp[cf_id][4].x = -178;				WALK_kp[cf_id][4].y = 0;					WALK_kp[cf_id][4].z = Raize_Level;
	WALK_kp[cf_id][5].x = -89 - OutSize;	WALK_kp[cf_id][5].y = -154 + StepSize;		WALK_kp[cf_id][5].z = Touch_Level;
	WALK_kp[cf_id][6].x = 89;				WALK_kp[cf_id][6].y = -154;					WALK_kp[cf_id][6].z = Raize_Level;

	cf_id = 3;
	WALK_kp[cf_id][1].x = 178 + OutSize;	WALK_kp[cf_id][1].y = 0 - StepSize;			WALK_kp[cf_id][1].z = Touch_Level;
	WALK_kp[cf_id][2].x = 89 + OutSize;		WALK_kp[cf_id][2].y = 154 + StepSize;		WALK_kp[cf_id][2].z = Raize_Level;
	WALK_kp[cf_id][3].x = -89 - OutSize;	WALK_kp[cf_id][3].y = 154 - StepSize;		WALK_kp[cf_id][3].z = Touch_Level;
	WALK_kp[cf_id][4].x = -178 - OutSize;	WALK_kp[cf_id][4].y = 0 + StepSize;			WALK_kp[cf_id][4].z = Raize_Level;
	WALK_kp[cf_id][5].x = -89 - OutSize;	WALK_kp[cf_id][5].y = -154 - StepSize;		WALK_kp[cf_id][5].z = Touch_Level;
	WALK_kp[cf_id][6].x = 89 + OutSize;		WALK_kp[cf_id][6].y = -154 + StepSize;		WALK_kp[cf_id][6].z = Raize_Level;

	int i, legnum;
	for (i = 0; i < NUM_CONFIGS; i++)
	{
		for (legnum = 1; legnum <= 6; legnum++)
			HT_Matrix_Vect_Multiply(T0_B[legnum], WALK_kp[i][legnum].x, WALK_kp[i][legnum].y, WALK_kp[i][legnum].z, &WALK_kp[i][legnum].x, &WALK_kp[i][legnum].y, &WALK_kp[i][legnum].z);
	}

}

//for now, just move to the keypoits.
//next step: use the keypoints to establish lines, and establish a function of 
// the time that iterates through the line. this will be k*(KP1-KP2)+KP2, where k is
//a function of time, and kp1 and kp2 are two keypoints forming a line for a given leg
void Walk(unsigned int time_step, double * xDes, double * yDes, double * zDes)
{
	if (time_step > 100)
	{
		int i;
		int config_num;
		config_num = (time_step /20) % NUM_CONFIGS;
		for (i = 1; i <= 6; i++)
		{
			xDes[i] = WALK_kp[config_num][i].x;		yDes[i] = WALK_kp[config_num][i].y;		zDes[i] = WALK_kp[config_num][i].z;
		}
	}
}


