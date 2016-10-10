#ifndef TWITCHY_MATH_H
#define	TWITCHY_MATH_H

#include <math.h>


void Multiply_HT_Matrices(double H1[4][4], double H2[4][4], double Hout[4][4]);
void Cross_Product(double * u, double * v, double * res);

void HT_Inverse(double HTin[4][4], double HTout[4][4]);
void HT_Matrix_Vect_Multiply(double H[4][4], double x, double y, double z, double * xout, double * yout, double * zout);



void Twitchy_Leg_Forward_Kinematics(double * Theta,
				double H0_1[4][4], double H1_2[4][4], double H2_3[4][4], 
				double alpha1, double alpha2, double alpha3, double a1, double a2, double a3, 
				double H0_2[4][4], double H0_3[4][4]);

void Twitchy_Leg_Inverse_Kinematics(double X_desired, double Y_desired, double Z_desired, double XROT_desired, double YROT_desired, double ZROT_desired,
	double Theta[4], double Theta_previous[4],
	double H0_1[4][4], double H0_2[4][4], double H0_3[4][4],
	double J[6][3], double J_T[3][6],
	double * XVS, double * YVS, double * ZVS, double * XROTVS, double * YROTVS, double * ZROTVS, double weight);

void TwitchyJacobianTranspose(double HTin[6][3], double HTout[3][6]);


#endif	/* TWITCHY_MATH_H */
