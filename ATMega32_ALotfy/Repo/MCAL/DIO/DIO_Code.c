/*
 * DIO_Interfacing.c
 *
 * Created: 12/16/2023 2:27:25 PM
 *  Author: aawam
 */
 
#define F_CPU 16000000UL

#include <stddef.h>
#include "../../Service/STD_DATATYPES.h"
#include "../../Service/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Registers.h"

void DIO_setPintDirection(u8 PortID, u8 PinID, u8 PinDirection)
{
	if(((PortID<=3)&&(PinID<=7))&&((PinDirection == DIO_PIN_INPUT)||(PinDirection == DIO_PIN_OUTPUT)))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRA, PinID);
			}
			else
			{
				CLR_BIT(DDRA, PinID);
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRB, PinID);
			}
			else
			{
				CLR_BIT(DDRB, PinID);
			}
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRC, PinID);
			}
			else
			{
				CLR_BIT(DDRC, PinID);
			}
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_OUTPUT == PinDirection)
			{
				SET_BIT(DDRD, PinID);
			}
			else
			{
				CLR_BIT(DDRD, PinID);
			}
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}

void DIO_setPinValue(u8 PortID, u8 PinID, u8 PinValue)
{
	if(((PortID<=3)&&(PinID<=7))&&((PinValue == DIO_PIN_HIGH)||(PinValue == DIO_PIN_LOW)))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			if(PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTA, PinID);
			}
			else
			{
				CLR_BIT(PORTA, PinID);
			}
			break;
			
			case DIO_PORTB:
			if(PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTB, PinID);
			}
			else
			{
				CLR_BIT(PORTB, PinID);
			}
			break;
			
			case DIO_PORTC:
			if(PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTC, PinID);
			}
			else
			{
				CLR_BIT(PORTC, PinID);
			}
			break;
			
			case DIO_PORTD:
			if(PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTD, PinID);
			}
			else
			{
				CLR_BIT(PORTD, PinID);
			}
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}

/*u8 DIO_getPinValue(u8 PortID, u8 PinID)
{
	if((PortID<=3)&&(PinID<=7))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			return (GET_BIT(PINA, PinID));
			break;
			
			case DIO_PORTB:
			return (GET_BIT(PINB, PinID));
			break;	
			
			case DIO_PORTC:
			return (GET_BIT(PINC, PinID));
			break;
			
			case DIO_PORTD:
			return (GET_BIT(PIND, PinID));
			break;
		}
	}
	else
	{
		Do Nothing
	}
	return 0;
}*/

void DIO_getPinValue(u8 PortID, u8 PinID, u8* PinValue)
{
	if((PortID<=3)&&(PinID<=7)&&(PinValue!=NULL))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			*PinValue = GET_BIT(PINA, PinID);
			break;
			
			case DIO_PORTB:
			*PinValue = GET_BIT(PINB, PinID);
			break;
			
			case DIO_PORTC:
			*PinValue = GET_BIT(PINC, PinID);
			break;
			
			case DIO_PORTD:
			*PinValue = GET_BIT(PIND, PinID);
			break;
		}
	}
	else
	{
		/* Do Nothing*/
	}
}

void DIO_togglePinValue(u8 PortID, u8 PinID)
{
	if((PortID<=3)&&(PinID<=7))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA, PinID);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB, PinID);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC, PinID);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD, PinID);
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}

void DIO_activePinInPullUpResistance(u8 PortID, u8 PinID)
{
	if((PortID<=3)&&(PinID<=7))
	{
		switch(PortID)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, PinID);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB, PinID);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC, PinID);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD, PinID);
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}