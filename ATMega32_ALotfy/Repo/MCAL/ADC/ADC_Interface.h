/*
 * ADC_Interface.h
 *
 * Created: 12/27/2023 8:38:42 PM
 *  Author: aawam
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* Macros for ADC channels */

#define ADC_CHANNEL_0			0
#define ADC_CHANNEL_1			1
#define ADC_CHANNEL_2			2
#define ADC_CHANNEL_3			3
#define ADC_CHANNEL_4			4
#define ADC_CHANNEL_5			5
#define ADC_CHANNEL_6			6
#define ADC_CHANNEL_7			7

/* Macros for ADC reference voltage type */
#define ADC_REFERENCE_AVCC		1
#define ADC_REFERENCE_AREF		2
#define ADC_REFERENCE_INTERNAL	3

/****************************** APIS Prototypes ******************************/ 

void	ADC_init			(u8 referenceVoltage);
u16		ADC_getDigitalValue	(u8 channelNum);



#endif /* ADC_INTERFACE_H_ */