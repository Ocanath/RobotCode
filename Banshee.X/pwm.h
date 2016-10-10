/*++****************************************************************************
*
*	Name: pwm.h
*   
*	Description:	This module provides defines and structures for the 
*					PWM output interface. 
*
*	Revision History:
*	Date	Who	Comments	
*	------	---	---------------------------------------------------------------
*	100927	RLP	Created
****************************************************************************--*/

#ifndef PWM_H
#define PWM_H


/******************************************************************************
								CONSTANTS AND MACROS
******************************************************************************/

// MACROS

/******************************************************************************
								TYPEDEFS
******************************************************************************/

// structure to configure a MAX541 device. Can have multiple of these structures
// if more than one device is used.
typedef struct
{
	char			devName[7];	// device name
	unsigned char	ocNum;		// out compare device number
	unsigned char	timerNum;	// timer number
} PWMDevInfo;


/******************************************************************************
								FUNCTION PROTOTYPES
******************************************************************************/

// Open device
extern INT16 PWMOpen(	int		ocChan,		// Output Compare Channel #SPI Device, eg SPI_CHANNEL1, SPI_CHANNEL1A, etc
						int		timerNum,	// timer number (2 or 3)
						UINT16	timerMult,	// timer multiplier, eg T2_PS_1_32
						UINT16	countdownVal );	// timer countdown value

extern INT16 PWMWrite(INT16 handle, UINT16 value);

extern INT16 PWMClose( INT16 handle );

/******************************************************************************
								ERROR CODES
******************************************************************************/

#define PWM_SUCCESS						0			// success
#define PWM_BAD_HANDLE					1			// invalid handle

#endif
