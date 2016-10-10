#ifndef MOUSE_CONTROL_FUNCTIONS_H
#define	MOUSE_CONTROL_FUNCTIONS_H

#include "RobotKinematics.h"

#define MOUSE_NECK_STEP 10
#define FINGERS_STEP 15
#define THUMB_STEP 15
#define INTERNAL_CONTROL 0x49   //'I'
#define USER_CONTROL 0x55   //'U'


typedef struct Waypoint
{  
    int s_snapshot[1];
    int u_a_snapshot[1];
    int el_u_snapshot[1];
    int el_low_snapshot[1];
    int w_r_snapshot[1];
    int blade_snapshot[1];
    int neck_snapshot[1];

    int waist_snapshot;
 
    
}Waypoint;

typedef struct MouseMotors
{  
    int timearr[24];
    int shoulder[2];
	int upper_arm[2];
	int elbow_upper[2];
	int elbow_lower[2];
	int wrist[2];
	int blade[2];
	int waist;
	int neck[2];
    int thumb[2];
    int fingers[2];
    
}MouseMotors;


void hexmotors(int timeIn, int *timeArPtr, int delay);

void servoenable(int motornum, int dir);

void Radians_To_Encoder_Pos_II(DH_entry * DH_L, DH_entry * DH_R, MouseMotors * M);

void Radians_To_Encoder_Pos(double * Lm_theta, double * Rm_theta, double * TH_neck, double TH_waist, MouseMotors * M);
void move_servos(MouseMotors * M, int cycles);
void move_servos_IK_delay(MouseMotors * M, int cycles, int delay);


//
//void move_servos(int * servo_list, int * s, int * u_a, int * el_u, int * el_low, int * w_r, int * blade, int * waist, int * neck, int * thumb, int * fingers, int cycles);

void Keyboard_Control(MouseMotors * M, Waypoint * waypoints, int * waypoint_idx, int waypoints_size );

void drive_blades(MouseMotors * M, unsigned char right_blade_extend, unsigned char left_blade_extend);

void Startup_Animation(unsigned int time,double * Lm_theta, double * Rm_theta,
                        double * LM_xpos, double * LM_ypos, double * LM_zpos,
                            double * RM_xpos, double * RM_ypos,  double * RM_zpos, 
                                unsigned char * left_blade_extend, unsigned char * right_blade_extend, unsigned char * ctl_val, MouseMotors * M);

void starting_position(MouseMotors * M);
void neutral_position(MouseMotors * M);
void hand_close(char arg, MouseMotors * M);
void hand_open(char arg,  MouseMotors * M);

#endif	/* MOUSE_CONTROL_FUNCTIONS_H */

