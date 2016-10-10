#include "Twitchy_Math.h"


void Twitchy_Leg_Forward_Kinematics(double * Theta, double H0_1[4][4], double H1_2[4][4], double H2_3[4][4], double alpha1, double alpha2, double alpha3, double a1, double a2, double a3, double H0_2[4][4], double H0_3[4][4])
{
	H0_1[0][0] = cos(Theta[1]);		H0_1[0][1] = -sin(Theta[1])*cos(alpha1);		H0_1[0][2] = sin(Theta[1])*sin(alpha1); 	H0_1[0][3] = a1*cos(Theta[1]);
	H0_1[1][0] = sin(Theta[1]);		H0_1[1][1] = cos(Theta[1])*cos(alpha1);		H0_1[1][2] = -cos(Theta[1])*sin(alpha1);	H0_1[1][3] = a1*sin(Theta[1]);
										
	
	H1_2[0][0] = cos(Theta[2]);		H1_2[0][1] = -sin(Theta[2])*cos(alpha2);		H1_2[0][2] = sin(Theta[2])*sin(alpha2); 	H1_2[0][3] = a2*cos(Theta[2]);
	H1_2[1][0] = sin(Theta[2]);		H1_2[1][1] = cos(Theta[2])*cos(alpha2);		H1_2[1][2] = -cos(Theta[2])*sin(alpha2);	H1_2[1][3] = a2*sin(Theta[2]);
	
	
	H2_3[0][0] = cos(Theta[3]);		H2_3[0][1] = -sin(Theta[3])*cos(alpha3);		H2_3[0][2] = sin(Theta[3])*sin(alpha3); 	H2_3[0][3] = a3*cos(Theta[3]);
	H2_3[1][0] = sin(Theta[3]);		H2_3[1][1] = cos(Theta[3])*cos(alpha3);		H2_3[1][2] = -cos(Theta[3])*sin(alpha3);	H2_3[1][3] = a3*sin(Theta[3]);
			

	Multiply_HT_Matrices(H0_1, H1_2, H0_2);
	Multiply_HT_Matrices(H0_2, H2_3, H0_3);

}


void Twitchy_Leg_Inverse_Kinematics(double X_desired, double Y_desired, double Z_desired, double XROT_desired, double YROT_desired, double ZROT_desired,
	double Theta[4], double Theta_previous[4],
	double H0_1[4][4], double H0_2[4][4], double H0_3[4][4],
	double J[6][3], double J_T[3][6],
	double * XVS, double * YVS, double * ZVS, double * XROTVS, double * YROTVS, double * ZROTVS, double weight)
{


	double d1[3]; double d2[3]; double d3[3]; 
	double z0[3]; double z1[3]; double z2[3]; 

	z0[0] = 0; z0[1] = 0; z0[2] = 1;


	z1[0] = H0_1[0][2]; z1[1] = H0_1[1][2]; z1[2] = H0_1[2][2];
	z2[0] = H0_2[0][2]; z2[1] = H0_2[1][2]; z2[2] = H0_2[2][2];
	
	int i;
	for (i = 0; i < 3; i++)
	{
		d1[i] = H0_3[i][3];
		d2[i] = H0_3[i][3] - H0_1[i][3];
		d3[i] = H0_3[i][3] - H0_2[i][3];
	}

	double res[3];
	Cross_Product(z0, d1, res);
	for (i = 0; i < 3; i++)
		J[i][0] = res[i];
	for (i = 3; i < 6; i++)
		J[i][0] = z0[i];

	Cross_Product(z1, d2, res);
	for (i = 0; i < 3; i++)
		J[i][1] = res[i];
	for (i = 3; i < 6; i++)
		J[i][1] = z1[i];

	Cross_Product(z2, d3, res);
	for (i = 0; i < 3; i++)
		J[i][2] = res[i];
	for (i = 3; i < 6; i++)
		J[i][2] = z2[i];

	double JointVel[6];
	for (i = 1; i < 6; i++)
		JointVel[i] = Theta[i] - Theta_previous[i];


		
	TwitchyJacobianTranspose(J, J_T);



	*XVS = weight*(X_desired - H0_3[0][3]); *YVS = weight*(Y_desired - H0_3[1][3]); *ZVS = weight*(Z_desired - H0_3[2][3]);
	*XROTVS = 0; *YROTVS = 0; *ZROTVS = 0;



}


void TwitchyJacobianTranspose(double HTin[6][3], double HTout[3][6])
{
    int r, c;
	for (r = 0; r < 6; r++)
	{
		for (c = 0; c < 3; c++)
		{
			HTout[r][c] = HTin[c][r];
		}
	}
}


void HT_Inverse(double HTin[4][4], double HTout[4][4])
{
    int r, c;
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 3; c++)
		{
			HTout[r][c] = HTin[c][r];
		}
	}
	HTout[0][3] = -(HTout[0][0] * HTin[0][3] + HTout[0][1] * HTin[1][3] + HTout[0][2] * HTin[2][3]);
	HTout[1][3] = -(HTout[1][0] * HTin[0][3] + HTout[1][1] * HTin[1][3] + HTout[1][2] * HTin[2][3]);
	HTout[2][3] = -(HTout[2][0] * HTin[0][3] + HTout[2][1] * HTin[1][3] + HTout[2][2] * HTin[2][3]);

	HTout[3][0] = 0; HTout[3][1] = 0; HTout[3][2] = 0; HTout[3][3] = 1.0;
		
}




void Cross_Product(double * u, double * v, double * res)
{
	res[0] = u[1] * v[2] - u[2] * v[1];
	res[1] = u[2]*v[0] - u[0]*v[2];
	res[2] = u[0] * v[1] - u[1] * v[0];
}





void Multiply_HT_Matrices(double H1[4][4], double H2[4][4], double Hout[4][4])
{
    int out_r, out_c;
	for ( out_r = 0; out_r < 4; out_r++)
	{
		for (out_c = 0; out_c < 4; out_c++)
		{
			double tmp = 0;
            int i;
			for (i = 0; i < 4; i++)
			{
				//tmp.append(" + ");
				//tmp.append(H1[out_r][i]);
				//tmp.append("*");
				//tmp.append(H2[i][out_c]);
				tmp = tmp + H1[out_r][i] * H2[i][out_c];

			}

			Hout[out_r][out_c] = tmp;
		}
	}
	//Hout[3][0] = 0.0; Hout[3][1] = 0.0; Hout[3][2] = 0.0; Hout[3][3] = 1.0;

}






void HT_Matrix_Vect_Multiply(double H[4][4], double x, double y, double z, double * xout, double * yout, double * zout)
{

	*xout = H[0][0] * x + H[0][1] * y + H[0][2] * z + H[0][3];		//last number of the input 4 vector is always 1
	*yout = H[1][0] * x + H[1][1] * y + H[1][2] * z + H[1][3];
	*zout = H[2][0] * x + H[2][1] * y + H[2][2] * z + H[2][3];

}


