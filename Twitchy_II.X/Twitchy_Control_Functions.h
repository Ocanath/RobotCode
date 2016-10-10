#ifndef TWITCHY_CONTROL_FUNCTIONS_H
#define	TWITCHY_CONTROL_FUNCTIONS_H



void step_coord(char key_press, double * T_xpos, double * T_ypos, double * T_zpos, int legnum);
void Twitchy_Leg_Limit_Joints(double * Theta);

//void Radians_To_Encoder_Pos(double TW_theta[7][4], TwitchyMotors * T);
void Radians_To_Encoder_Pos(double TW_theta[7][4], int * b, int * m, int * t, int * claw);

void servoenable( int motornum, int dir);

//void move_servos(TwitchyMotors * T, int cycles);
void move_servos(int * servo_list, int * b, int * m, int * t, int * c, int cycles);
void move_servos_IK_delay(int * servo_list, int * b, int * m, int * t, int * c, int cycles, int delay);

typedef struct Waypoint
{
    
    int bottomleg_snapshot[6];
    int middleleg_snapshot[6];
    int topleg_snapshot[6];
    int claw_snapshot[6];
    
}Waypoint;


//typedef struct TwitchyMotors
//{        
//    int timearr[24];
//    int b[7];
//    int m[7];
//    int t[7];
//    int c[7];
//}TwitchyMotors;




#endif