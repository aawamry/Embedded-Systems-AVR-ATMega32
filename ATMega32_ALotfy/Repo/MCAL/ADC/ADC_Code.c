/*
 * ADC_Code.c
 *
 * Created: 12/27/2023 8:38:03 PM
 *  Author: aawam
 */ 

/* Service Library */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD_DATATYPES.h"

/* MCAL */

#include "ADC_Registers.h"
#include "ADC_Interface.h"

void ADC_init(u8 referenceVoltage)
{
	switch(referenceVoltage)
	{
		/* Select Vref = AVCC */
		case ADC_REFERENCE_AVCC:
		SET_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);
		break;
		
		/* Select Vref = AREF */
		case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);
		break;
		
		/* Select Vref = 2.56V internal */
		case ADC_REFERENCE_INTERNAL:
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);
		break;
	}
	
	/* Select Right Adjustment */
	CLR_BIT(ADMUX, ADLAR);
	
	/* Single Conversation Mode */
	CLR_BIT(ADCSRA, ADATE);
	
	/* Disable ADC Interrupt */
	CLR_BIT(ADCSRA, ADIE);
	
	/* Prescaler 128 for 16MHz (125 KHz) */
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS0);
	
	/* ADC Enable */
	SET_BIT(ADCSRA, ADEN);
}

u16 ADC_getDigitalValue(u8 channelNum)
{
	if(channelNum < 32)
	{
		/* Clear ADMUX Channel Bits */
		ADMUX &= 0xE0; /* 0b11100000 */
		
		/* Select Channel Number */
		ADMUX |= channelNum;
		
		/* Start Conversition */
		SET_BIT(ADCSRA, ADSC);
		
		/* Busy wait on ADC flag */
		while(0 == GET_BIT(ADCSRA, ADIF));
		
		/* Clear Flag (Write one to Clear) */
		SET_BIT(ADCSRA, ADIF);
		
		return ADC_u16;
	}
	else
	{
		return 0;
	}
}