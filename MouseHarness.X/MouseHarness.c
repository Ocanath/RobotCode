#include "MouseHarness.h"


void AnaRadians(Harness * MH)
{
    int i;
    for(i = 1; i <= NUM_ARM_JOINTS; i++)
    {
        MH->thetaL[i] = MH->G[i]*MH->aL[i-1] + MH->O[i];
        MH->thetaR[i] = MH->G[i]*MH->aR[i-1] + MH->O[i];
    }
}
