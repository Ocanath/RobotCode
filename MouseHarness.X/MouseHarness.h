#ifndef MOUSEHARNESS_H
#define	MOUSEHARNESS_H



#define NUM_ARM_JOINTS 5
#define NUM_JOINTS_ARR 6

typedef struct Harness
{
    int aL[NUM_JOINTS_ARR];
    int aR[NUM_JOINTS_ARR];
    double thetaL[NUM_JOINTS_ARR];
    double thetaR[NUM_JOINTS_ARR];
    
    double G[NUM_JOINTS_ARR];
    double O[NUM_JOINTS_ARR];
    
    
}Harness;



#endif	/* MOUSEHARNESS_H */

