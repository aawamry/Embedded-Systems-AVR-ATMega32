/*
 * BUZ_Code.c
 *
 * Created: 12/16/2023 5:42:23 PM
 *  Author: aawam
 */ 

#define F_CPU 16000000UL

#include "../../Service/STD_DATATYPES.h"
#include "../../Service/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "BUZ_Interface.h"



void BUZ_Init(u8 BuzPort, u8 BuzPin)
{
	DIO_setPinDirection(BuzPort, BuzPin, DIO_PIN_OUTPUT);
}

void BUZ_On(u8 BuzPort, u8 BuzPin)
{
	DIO_setPinValue(BuzPort, BuzPin, DIO_PIN_HIGH);
}

void BUZ_Off(u8 BuzPort, u8 BuzPin)
{
	DIO_setPinValue(BuzPort, BuzPin, DIO_PIN_LOW);
}

void BUZ_Toggle	(u8 BuzPort, u8 BuzPin)
{
	DIO_togglePinValue(BuzPort, BuzPin);
}