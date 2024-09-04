/*
 * SWT_Code.c
 *
 * Created: 12/16/2023 6:05:46 PM
 *  Author: aawam
 */ 

#include <stdio.h>
#include "../../Service/STD_DATATYPES.h"
#include "../../Service/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SWT_Interface.h"


#define F_CPU 16000000UL

void SWT_Init(u8 SwitchPort, u8 SwitchPin)
{
	DIO_setPinDirection(SwitchPort, SwitchPin, DIO_PIN_INPUT);
}

void SWT_getState(u8 SwitchPort, u8 SwitchPin, u8* SwitchState)
{
	if(SwitchState != NULL)
	{
		u8 swState = SWT_NOT_PRESSED;
		DIO_getPinValue(SwitchPort, SwitchPin, &swState);
		if(1 == swState)
		{
			*SwitchState = SWT_PRESSED;
		}
		else
		{
			*SwitchState = SWT_NOT_PRESSED;
		}
	}
}