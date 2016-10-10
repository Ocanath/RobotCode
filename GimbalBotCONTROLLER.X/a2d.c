// (C) Copyright 2009, 2010 Communications Programming, Inc.
/***************************************************************************************************************
*  Name: a2d.c
*
*  Description: Function to initialize and read analog inputs
*
*  Calling Parameters:
*  
* void	A2D_init( UINT16	chanMask )	// Analog channel mask
*										// bit N corresponds to analog chan N+1
*										// for example, chanMask = 6 enables AN2 and AN3
*
*
*
* INT16 A2D_read(	int		chan,	// channel
*					UINT16 *value )	// returned digital 10-bit value
*
*	Returns 0 for success, or non-0 error codes in pwm.h if failed
*
*  Revision History:
*  Date    Who  Comments
*  ------  ---  -----------------------------------------------------------------------------------------
*  101121  RLP	Created.
*
***************************************************************************************************************/

#include <stdlib.h>
#include <plib.h>
#include <userLib.h>
#include <a2d\a2d.h>

 void A2D_init( UINT16	chanMask )	// Analog channel mask
{
	UINT16	trisb = 0;

	chanMask &= 0xFF;			// limit to 8 bits
	trisb = TRISB;				// set correspond bits as input, preserving others
	trisb &= 0x0000;	//I CHANGED THIS LOOK HERE ORIGINALLY THIS WAS SET TO EQUAL 0xFF00		// preserve bits 15-8, clear bits 7-0
	trisb |= chanMask;			// set bits 7-0 according to chan mask
	TRISB = trisb;				// apply settings
	chanMask ^= 0xFFFF;			// set correspon AD1PCFG bits to 0
	AD1PCFG = chanMask;
	AD1CON1 = 0x00E0;			// auto convert after sampling
	AD1CSSL = 0;				// no scanning req'd
	AD1CON2 = 0;				// use MUXA, AVdd and AVss as Vref+/-
	AD1CON3 = 0x1F3F;			// Tsamp = 32 x Tad
	AD1CON1bits.ADON = 1;		// Turn on A2D			
}

INT16 A2D_read(	int		chan,	// channel #
				UINT16 *value )	// returned digital 10-bit value
{
	if( chan > 7 )
	{
		*value = 0;				// invalid chan
		return( A2D_INVALID_CHAN );
	} 

	AD1CHSbits.CH0SA = chan;			// sets channel
	AD1CON1bits.SAMP = 1;		// start sample
	while( !AD1CON1bits.DONE )	// loop til sampling complete
	{}
	*value = ADC1BUF0;			// return value
	return(A2D_SUCCESS);			
}
