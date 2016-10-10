#ifndef BOTCONTROL_H
#define	BOTCONTROL_H

#include "RobotKinematics.h"


//Custom for each robot. Example for Twitchy
//void Leg_Limit_Joints(double * Theta);
////void Radians_To_Encoder_Pos(double TW_theta[7][4], TwitchyMotors * T);
//void Radians_To_Encoder_Pos(double TW_theta[7][4], int * b, int * m, int * t, int * claw);

void servoenable( int motornum, int dir);
void move_servos(int * servo_list, int * Enc_list, int cycles);
void move_servos_IK_delay(int * servo_list, int * Enc_list, int cycles, int delay);
void Radians_To_Encoder_Pos(DH_entry * DH_AViCS, int * EncList);




#endif