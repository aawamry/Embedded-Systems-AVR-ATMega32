/*
 * ADC_Registers.h
 *
 * Created: 12/27/2023 8:38:21 PM
 *  Author: aawam
 */ 


#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

/************************ ADC Registers ************************/

/* ADC Multiplexer Selection Registers */
#define ADMUX	(*(volatile u8*)0x27)
#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4 
#define ADLAR	5
#define REFS0	6
#define REFS1	7

/* ADC Control and Status Register A */
#define ADCSRA	(*(volatile u8*)0x26)
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7

/* ADC Data Registers */
#define ADC_u16 (*(volatile u16*)0x24)

/* Special FunctionIO Registers*/
#define SFIOR	(*(volatile u8*)0x50)
#define ADTS2	7
#define ADTS1	6
#define ADTS0	5

#endif /* ADC_REGISTERS_H_ */