#ifndef ROBOTKINEMATICS_H
#define ROBOTKINEMATICS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOUSE_ARM_SIZE 5
#define MOUSE_ARM_ARR_SIZE 6


typedef struct DH_entry
{
	double d;
	double a;
	double alpha;
	double theta;
}DH_entry;

typedef struct HTmatrix
{
	double H[4][4];
}HTmatrix;

typedef struct P3D
{
	double x;
	double y;
	double z;
}P3D;

typedef struct Vect3
{
	double u;
	double v;
	double w;
}Vect3;



void copy_HT(HTmatrix * Hsource, HTmatrix * Hdes);
void HT_Multiply(HTmatrix H1, HTmatrix H2, HTmatrix * Hout);
void HT_Inverse(HTmatrix HTin, HTmatrix * HTout);
void HT_Point_Multiply(HTmatrix Hout_in, P3D Pin, P3D * Pout);
void Vect3_CrossProduct(Vect3 in1, Vect3 in2, Vect3 * res);

void init_jacobian(double *** J, double *** J_Transpose, int size);

void JacobianTranspose( double J[6][MOUSE_ARM_SIZE], double J_Transpose[MOUSE_ARM_SIZE][6], int size);
void inverse_kinematics(P3D Pdes, DH_entry * DH_Table, double J[6][MOUSE_ARM_SIZE], double J_Transpose[MOUSE_ARM_SIZE][6], HTmatrix * HTbase, int size, double weight);

void init_forward_kinematics(DH_entry * DH_Table, HTmatrix * HTadj, HTmatrix * HTbase, int size);
void forward_kinematics(DH_entry * DH_Table, HTmatrix * HTadj, HTmatrix * HTbase, int size);



#endif