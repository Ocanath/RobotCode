
#include "Mouse_Math.h"
#include <math.h>




void Mouse_Left_Arm_Forward_Kinematics(double * M_theta, double H0_1[4][4], double H1_2[4][4], double H2_3[4][4], double H3_4[4][4], double H4_5[4][4], double M_a1, double M_a2, double M_a3, double M_a4, double H0_2[4][4], double H0_3[4][4], double H0_4[4][4], double H0_5[4][4])
{
	H0_1[0][0] = cos(M_theta[1]);		H0_1[0][2] = -sin(M_theta[1]);		H0_1[0][3] = M_a1*cos(M_theta[1]);
	H0_1[1][0] = sin(M_theta[1]);		H0_1[1][2] = cos(M_theta[1]);		H0_1[1][3] = M_a1*sin(M_theta[1]);

	H1_2[0][0] = cos(M_theta[2]);		H1_2[0][2] = -sin(M_theta[2]);		H1_2[0][3] = M_a2*cos(M_theta[2]);
	H1_2[1][0] = sin(M_theta[2]);		H1_2[1][2] = cos(M_theta[2]);		H1_2[1][3] = M_a2*sin(M_theta[2]);
	H2_3[0][0] = cos(M_theta[3]);		H2_3[0][2] = -sin(M_theta[3]);		H2_3[0][3] = M_a3*cos(M_theta[3]);
	H2_3[1][0] = sin(M_theta[3]);		H2_3[1][2] = cos(M_theta[3]);		H2_3[1][3] = M_a3*sin(M_theta[3]);
	H3_4[0][0] = cos(M_theta[4]);		H3_4[0][2] = -sin(M_theta[4]);		H3_4[0][3] = M_a4*cos(M_theta[4]);
	H3_4[1][0] = sin(M_theta[4]);		H3_4[1][2] = cos(M_theta[4]);		H3_4[1][3] = M_a4*sin(M_theta[4]);
	H4_5[0][0] = cos(M_theta[5]);		H4_5[0][1] = -sin(M_theta[5]);
	H4_5[1][0] = sin(M_theta[5]);		H4_5[1][1] = cos(M_theta[5]);


	//	double HW_1[4][4];
	//	Multiply_HT_Matrices(HW_0, H0_1, HW_1);

	Multiply_HT_Matrices(H0_1, H1_2, H0_2);
	Multiply_HT_Matrices(H0_2, H2_3, H0_3);
	Multiply_HT_Matrices(H0_3, H3_4, H0_4);
	Multiply_HT_Matrices(H0_4, H4_5, H0_5);


}

void Limit_Left_Arm_Joints(double * Lm_theta)
{
	if (Lm_theta[1] > -1.57079632679){ Lm_theta[1] = -1.57079632679; }
	else if (Lm_theta[1] < -3 * 1.57079632679){ Lm_theta[1] = -3 * 1.57079632679; }
	if (Lm_theta[2] < 1.17079632679){ Lm_theta[2] = 1.17079632679; }
	else if (Lm_theta[2] > 1.17079632679 + 2 * 1.57079632679){ Lm_theta[2] = 1.17079632679 + 2 * 1.57079632679; }
	if (Lm_theta[3] < 0){ Lm_theta[3] = 0; }
	else if (Lm_theta[3] > 2 * 1.57079632679){ Lm_theta[3] = 2 * 1.57079632679; }
	if (Lm_theta[3] < 0){ Lm_theta[3] = 0; }
	else if (Lm_theta[3] > 2 * 1.57079632679){ Lm_theta[3] = 2 * 1.57079632679; }
	if (Lm_theta[4] < 0.1){ Lm_theta[4] = 0.1; }    //was zero
	else if (Lm_theta[4] > 2 * 1.57079632679){ Lm_theta[4] = 2 * 1.57079632679; }
	if (Lm_theta[5] < -1.57079632679){ Lm_theta[5] = -1.57079632679; }
	else if (Lm_theta[5] > 1.57079632679){ Lm_theta[5] = 1.57079632679; }
}

void Limit_Right_Arm_Joints(double * Rm_theta)
{
	if (Rm_theta[1] < 1.57079632679){ Rm_theta[1] = 1.57079632679; }
	else if (Rm_theta[1] > 3 * 1.57079632679){ Rm_theta[1] = 3 * 1.57079632679; }
	if (Rm_theta[2] > -1.17079632679){ Rm_theta[2] = -1.17079632679; }
	else if (Rm_theta[2] < -(1.17079632679 + 2 * 1.57079632679)){ Rm_theta[2] = -(1.17079632679 + 2 * 1.57079632679); }
	if (Rm_theta[3] > 0){ Rm_theta[3] = 0; }
	else if (Rm_theta[3] < -2 * 1.57079632679){ Rm_theta[3] = -2 * 1.57079632679; }
	if (Rm_theta[4] > 0){ Rm_theta[4] = 0; }
	else if (Rm_theta[4] < -2 * 1.57079632679){ Rm_theta[4] = -2 * 1.57079632679; }
	if (Rm_theta[5] > 1.57079632679){ Rm_theta[5] = 1.57079632679; }
	else if (Rm_theta[5] < -1.57079632679){ Rm_theta[5] = -1.57079632679; }
}

void Mouse_Right_Arm_Forward_Kinematics(double * M_theta, double H0_1[4][4], double H1_2[4][4], double H2_3[4][4], double H3_4[4][4], double H4_5[4][4], double M_a1, double M_a2, double M_a3, double M_a4, double H0_2[4][4], double H0_3[4][4], double H0_4[4][4], double H0_5[4][4])
{
	H0_1[0][0] = cos(M_theta[1]);		H0_1[0][2] = sin(M_theta[1]);		H0_1[0][3] = M_a1*cos(M_theta[1]);
	H0_1[1][0] = sin(M_theta[1]);		H0_1[1][2] = -cos(M_theta[1]);		H0_1[1][3] = M_a1*sin(M_theta[1]);

	H1_2[0][0] = cos(M_theta[2]);		H1_2[0][2] = sin(M_theta[2]);		H1_2[0][3] = M_a2*cos(M_theta[2]);
	H1_2[1][0] = sin(M_theta[2]);		H1_2[1][2] = -cos(M_theta[2]);		H1_2[1][3] = M_a2*sin(M_theta[2]);

	H2_3[0][0] = cos(M_theta[3]);		H2_3[0][2] = sin(M_theta[3]);		H2_3[0][3] = M_a3*cos(M_theta[3]);
	H2_3[1][0] = sin(M_theta[3]);		H2_3[1][2] = -cos(M_theta[3]);		H2_3[1][3] = M_a3*sin(M_theta[3]);

	H3_4[0][0] = cos(M_theta[4]);		H3_4[0][2] = sin(M_theta[4]);		H3_4[0][3] = M_a4*cos(M_theta[4]);
	H3_4[1][0] = sin(M_theta[4]);		H3_4[1][2] = -cos(M_theta[4]);		H3_4[1][3] = M_a4*sin(M_theta[4]);

	H4_5[0][0] = cos(M_theta[5]);		H4_5[0][1] = sin(M_theta[5]);
	H4_5[1][0] = sin(M_theta[5]);		H4_5[1][1] = -cos(M_theta[5]);


//	double HW_1[4][4];
//	Multiply_HT_Matrices(HW_0, H0_1, HW_1);
	
	Multiply_HT_Matrices(H0_1, H1_2, H0_2);
	Multiply_HT_Matrices(H0_2, H2_3, H0_3);
	Multiply_HT_Matrices(H0_3, H3_4, H0_4);
	Multiply_HT_Matrices(H0_4, H4_5, H0_5);
	

}
void Mouse_Arm_Inverse_Kinematics(double X_desired, double Y_desired, double Z_desired, double XROT_desired, double YROT_desired, double ZROT_desired, 
									double M_theta[6], double M_theta_previous[6],
									double H0_1[4][4], double H0_2[4][4], double H0_3[4][4], double H0_4[4][4], double H0_5[4][4], 
									double M_J[6][5], double TM_J[5][6],
									double * XVS, double * YVS, double * ZVS, double * XROTVS, double * YROTVS, double * ZROTVS, double weight)
{
	
	double d1[3]; double d2[3]; double d3[3]; double d4[3]; double d5[3];
	double z0[3]; double z1[3]; double z2[3]; double z3[3]; double z4[3];

	z0[0] = 0; z0[1] = 0; z0[2] = 1;


	z1[0] = H0_1[0][2]; z1[1] = H0_1[1][2]; z1[2] = H0_1[2][2];
	z2[0] = H0_2[0][2]; z2[1] = H0_2[1][2]; z2[2] = H0_2[2][2];
	z3[0] = H0_3[0][2]; z3[1] = H0_3[1][2]; z3[2] = H0_3[2][2];
	z4[0] = H0_4[0][2]; z4[1] = H0_4[1][2]; z4[2] = H0_4[2][2];
		
	int i;
	for (i = 0; i < 3; i++)
	{
		d1[i] = H0_5[i][3];
		d2[i] = H0_5[i][3] - H0_1[i][3];
		d3[i] = H0_5[i][3] - H0_2[i][3];
		d4[i] = H0_5[i][3] - H0_3[i][3];
		d5[i] = H0_5[i][3] - H0_4[i][3];
	}

	double res[3];
	Cross_Product(z0, d1, res);
	for (i = 0; i < 3; i++)
		M_J[i][0] = res[i];
	for (i = 3; i < 6; i++)
		M_J[i][0] = z0[i];

	Cross_Product(z1, d2, res);
	for (i = 0; i < 3; i++)
		M_J[i][1] = res[i];
	for (i = 3; i < 6; i++)
		M_J[i][1] = z1[i];

	Cross_Product(z2, d3, res);
	for (i = 0; i < 3; i++)
		M_J[i][2] = res[i];
	for (i = 3; i < 6; i++)
		M_J[i][2] = z2[i];

	Cross_Product(z3, d4, res);
	for (i = 0; i < 3; i++)
		M_J[i][3] = res[i];
	for (i = 3; i < 6; i++)
		M_J[i][3] = z3[i];

	Cross_Product(z4, d5, res);
	for (i = 0; i < 3; i++)
		M_J[i][4] = res[i];
	for (i = 3; i < 6; i++)
		M_J[i][4] = z4[i];


	double JointVel[6];
	for (i = 1; i < 6; i++)
		JointVel[i] = M_theta[i] - M_theta_previous[i];



	///////////////////////////////jacobian transpose/joint angle updates



	/////////////////Linear Velocity Calkoo-layshun
	//double Rxv = M_J[0][0] * JointVel[1] + M_J[0][1] * JointVel[2] + M_J[0][2] * JointVel[3] + M_J[0][3] * JointVel[4] + M_J[0][4] * JointVel[5];
	//double Ryv = M_J[1][0] * JointVel[1] + M_J[1][1] * JointVel[2] + M_J[1][2] * JointVel[3] + M_J[1][3] * JointVel[4] + M_J[1][4] * JointVel[5];
	//double Rzv = M_J[2][0] * JointVel[1] + M_J[2][1] * JointVel[2] + M_J[2][2] * JointVel[3] + M_J[2][3] * JointVel[4] + M_J[2][4] * JointVel[5];


	
	//double Transp_J[5][6];
	MouseJacobianTranspose(M_J, TM_J);
	
	*XVS = weight*(X_desired - H0_5[0][3]); *YVS = weight*(Y_desired - H0_5[1][3]); *ZVS = weight*(Z_desired - H0_5[2][3]);
	*XROTVS= 0; *YROTVS = 0; *ZROTVS = 0;
	
	
	//double THsteps[6];
	//THsteps[1] = Transp_J[0][0] * Rx_des + Transp_J[0][1] * Ry_des + Transp_J[0][2] * Rz_des;	// + RTransp_J[0][3] * Rxrot_des + ...
	//THsteps[2] = Transp_J[1][0] * Rx_des + Transp_J[1][1] * Ry_des + Transp_J[1][2] * Rz_des;
	//THsteps[3] = Transp_J[2][0] * Rx_des + Transp_J[2][1] * Ry_des + Transp_J[2][2] * Rz_des;
	//THsteps[4] = Transp_J[3][0] * Rx_des + Transp_J[3][1] * Ry_des + Transp_J[3][2] * Rz_des;
	//THsteps[5] = Transp_J[4][0] * Rx_des + Transp_J[4][1] * Ry_des + Transp_J[4][2] * Rz_des;

	//for (i = 1; i <= 5; i++)
	//	cout << THsteps[i] << endl;
	
	

}


//EVERYTHING IN THE 

void HT_inverse(double HTin[4][4], double HTout[4][4])
{
    int r; int c;
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

void MouseJacobianTranspose(double HTin[6][5], double HTout[5][6])
{
    int r; int c;
	for (r = 0; r < 6; r++)
	{
		for (c = 0; c < 5; c++)
		{
			HTout[r][c] = HTin[c][r];
		}
	}
}


void Cross_Product(double * u, double * v, double * res)
{
	res[0] = u[1] * v[2] - u[2] * v[1];
	res[1] = u[2]*v[0] - u[0]*v[2];
	res[2] = u[0] * v[1] - u[1] * v[0];
}



void Multiply_HT_Matrices(double H1[4][4], double H2[4][4], double Hout[4][4])
{
    int out_r; int out_c;
	for (out_r = 0; out_r < 4; out_r++)
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




void update_R(double R[3][3], double theta1, double theta2, double theta3)
{		
	R[0][0] = cos(theta1)*cos(theta2)*cos(theta3) - sin(theta1) * sin(theta3);							R[0][1] = -cos(theta1)*cos(theta2)*sin(theta3) - sin(theta1)*cos(theta3);					R[0][2] = cos(theta1)*sin(theta2);
	R[1][0] = sin(theta1)*cos(theta2)*cos(theta3) + cos(theta1)*sin(theta3);							R[1][1] = -sin(theta1)*cos(theta2)*sin(theta3) + cos(theta1)*cos(theta3);					R[1][2] = sin(theta1)*sin(theta2);
	R[2][0] = -sin(theta2)*cos(theta3);																	R[2][1] = sin(theta2)*sin(theta3);															R[2][2] = cos(theta2);
}





