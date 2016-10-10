// userLib.h
// (C) Copyright 2009, 2010 Communications Programming, Inc.

#include <p32xxxx.h>
#include <plib.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handle.h"

// defines 

// set TxCON reg for timer on, prescalars value for 8:1
// note that these values are different depending on timer

#define T1CON_VAL	0x8010
#define T2CON_VAL	0x8030
#define T3CON_VAL	0x8030
#define T4CON_VAL	0x8030
#define T5CON_VAL	0x8030
#define T23_PRESCALER T2_PS_1_8
#define T45_PRESCALER T4_PS_1_8

#define PRINTF_BAUDRATE	230400				// baud rate for printf output

#define I2C_CLOCK_FREQ	400000				// I2C bus clock freq = 400KHz

// global variables

extern UINT16 TimerTicksPerMicrosec;		// used in timer funcs eg delayTx
extern UINT32 PBCLK;						// Peripheral Bus Clock

// userLib.c function prototypes

extern void picInit( UINT32 primaryClockSpeed );

// delay and timer functions using selected timer, eg T1, T2...

extern void delayT1_init();
extern void delayT1_us( UINT16 us );
extern void delayT1_ms( UINT16 ms );
extern void delayT2_init();
extern void delayT2_us( UINT16 us );
extern void delayT2_ms( UINT16 ms );
extern void delayT3_init();
extern void delayT3_us( UINT16 us );
extern void delayT3_ms( UINT16 ms );
extern void delayT4_init();
extern void delayT4_us( UINT16 us );
extern void delayT4_ms( UINT16 ms );
extern void delayT5_init();
extern void delayT5_us( UINT16 us );
extern void delayT5_ms( UINT16 ms );
extern double elapsedTime23();
extern double elapsedTime45();

// UART functions

extern void uart_init(INT16 uartNum, UINT32 bps, UINT32 pbClk);
extern INT16 getLine( char *buf, INT16 maxLen );

// i2c functions

extern int I2C_init( I2C_MODULE id );
extern int I2C_writeBytes( I2C_MODULE id,		// device ID
 						    unsigned char *buf, // buffer of data to write
						 	unsigned char len );// number of bytes in buffer to write							

extern int writeBytesI2C1( unsigned char *buf, 	
					 	   unsigned char len );	
extern int writeBytesI2C2( unsigned char *buf, 	
					 	   unsigned char len );	
extern int maxim517DA1( unsigned char port, 
           	    		unsigned char val );
extern int maxim517DA2( unsigned char port, 
                 		unsigned char val );
