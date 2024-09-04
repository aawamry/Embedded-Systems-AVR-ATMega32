/*
 * SSD_Code.c
 *
 * Created: 12/17/2023 9:31:40 AM
 *  Author: aawam
 */ 
#define F_CPU 16000000UL


#include <util/delay.h>
#include "../../Service/STD_DATATYPES.h"
#include "../../Service/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SSD_Interface.h"


#define F_CPU 16000000UL

void SSD_Init(void)
{
	DIO_setPinDirection(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN7, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
}

void SSD_displayNumber(u8 ssdID, u8 desiredNumber)
{
	if(desiredNumber <= 9)
	{
		switch(ssdID)
		{
			case SSD_ONE:
			DIO_setPinValue(DIO_PORTA, DIO_PIN4, GET_BIT(desiredNumber, 0));
			DIO_setPinValue(DIO_PORTA, DIO_PIN5, GET_BIT(desiredNumber, 1));
			DIO_setPinValue(DIO_PORTA, DIO_PIN6, GET_BIT(desiredNumber, 2));
			DIO_setPinValue(DIO_PORTA, DIO_PIN7, GET_BIT(desiredNumber, 3));
			DIO_setPinValue(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);
			break;
			
			case SSD_TWO:
			DIO_setPinValue(DIO_PORTA, DIO_PIN4, GET_BIT(desiredNumber, 0));
			DIO_setPinValue(DIO_PORTA, DIO_PIN5, GET_BIT(desiredNumber, 1));
			DIO_setPinValue(DIO_PORTA, DIO_PIN6, GET_BIT(desiredNumber, 2));
			DIO_setPinValue(DIO_PORTA, DIO_PIN7, GET_BIT(desiredNumber, 3));
			DIO_setPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_HIGH);
			break;
		}
	}
	
}

void SSD_displayMultiNumber(u8 desiredNumber)
{
	if(desiredNumber <= 99)
	{
		u8 ones, tens;
		tens = desiredNumber/10;
		ones = desiredNumber%10;
		
		DIO_setPinValue(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
		
		DIO_setPinValue(DIO_PORTA, DIO_PIN4, GET_BIT(tens,0));
		DIO_setPinValue(DIO_PORTA, DIO_PIN5, GET_BIT(tens,1));
		DIO_setPinValue(DIO_PORTA, DIO_PIN6, GET_BIT(tens,2));
		DIO_setPinValue(DIO_PORTA, DIO_PIN7, GET_BIT(tens,3));
		_delay_ms(10);
		DIO_setPinValue(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
		
		DIO_setPinValue(DIO_PORTA, DIO_PIN4, GET_BIT(ones,0));
		DIO_setPinValue(DIO_PORTA, DIO_PIN5, GET_BIT(ones,1));
		DIO_setPinValue(DIO_PORTA, DIO_PIN6, GET_BIT(ones,2));
		DIO_setPinValue(DIO_PORTA, DIO_PIN7, GET_BIT(ones,3));
		_delay_ms(10);
		DIO_setPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
	}
}