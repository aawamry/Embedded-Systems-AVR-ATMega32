/*
 * LED_Code.c
 *
 * Created: 12/16/2023 5:13:05 PM
 *  Author: aawam
 */ 

#define F_CPU 16000000UL

#include "../../Service/STD_DATATYPES.h"
#include "../../Service/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Registers.h"
#include "LED_Interface.h"



void LED_Init(u8 LedPort, u8 LedPin)
{
	DIO_setPinDirection(LedPort, LedPin, DIO_PIN_OUTPUT);
}

void LED_On(u8 LedPort, u8 LedPin)
{
	DIO_setPinValue(LedPort, LedPin, DIO_PIN_HIGH);
}

void LED_Off(u8 LedPort, u8 LedPin)
{
	DIO_setPinValue(LedPort, LedPin, DIO_PIN_LOW);
}

void LED_Toggle(u8 LedPort, u8 LedPin)
{
	DIO_togglePinValue(LedPort, LedPin);
}