// (C) Copyright 2009, 2010 Communications Programming, Inc.
/***************************************************************************************************************
*  Name: handle.h
*
*  Description: Defines for functions to allocate and maintain i/o handles
*
*  Revision History:
*  Date    Who  Comments
*  ------  ---  -----------------------------------------------------------------------------------------
*  100928  RLP	Created.
*
***************************************************************************************************************/

// common device control block default struct

typedef struct
{
	char		devName[6];		// device name always first; remaining content device-specific 
} DevInfo;

// function prototypes

extern INT16 handleNumberGet( DevInfo *devInfoBlk );	// stores the devInfoBlk address in the next available
extern DevInfo * handleDevInfoGet( INT16 handle );		// handle returned from handleNumberGet()
extern void handleNumberClose( INT16 handle );	 		// handle returned from handleNumberGet()
