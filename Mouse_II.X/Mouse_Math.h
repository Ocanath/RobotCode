#ifndef MOUSE_MATH_H
#define MOUSE_MATH_H

#include <math.h>




void Multiply_HT_Matrices(double H1[4][4], double H2[4][4], double Hout[4][4]);
void Cross_Product(double * u, double * v, double * res);
void MouseJacobianTranspose(double HTin[6][5], double HTout[5][6]);
void HT_inverse(double HTin[4][4], double HTout[4][4]);
void HT_Matrix_Vect_Multiply(double H[4][4], double x, double y, double z, double * xout, double * yout, double * zout);

void Limit_Left_Arm_Joints(double * Lm_theta);
void Limit_Right_Arm_Joints(double * Rm_theta);

void Mouse_Left_Arm_Forward_Kinematics(double * M_theta, double H0_1[4][4], double H1_2[4][4], double H2_3[4][4], double H3_4[4][4], double H4_5[4][4], double M_a1, double M_a2, double M_a3, double M_a4, double H0_2[4][4], double H0_3[4][4], double H0_4[4][4], double H0_5[4][4]);
void Mouse_Right_Arm_Forward_Kinematics(double * M_theta, double H0_1[4][4], double H1_2[4][4], double H2_3[4][4], double H3_4[4][4], double H4_5[4][4], double M_a1, double M_a2, double M_a3, double M_a4, double H0_2[4][4], double H0_3[4][4], double H0_4[4][4], double H0_5[4][4]);

void Mouse_Arm_Inverse_Kinematics(double X_desired, double Y_desired, double Z_desired, double XROT_desired, double YROT_desired, double ZROT_desired,
	double M_theta[6], double M_theta_previous[6],
	double H0_1[4][4], double H0_2[4][4], double H0_3[4][4], double H0_4[4][4], double H0_5[4][4],
	double M_J[6][5], double TM_J[5][6],
	double * XVS, double * YVS, double * ZVS, double * XROTVS, double * YROTVS, double * ZROTVS, double weight);



#endif 