/*
 * DIO_Interface.h
 *
 * Created: 12/16/2023 1:37:18 PM
 *  Author: aawam
 */ 



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

#define DIO_PIN_INPUT	0
#define DIO_PIN_OUTPUT	1

#define DIO_PIN_LOW		0
#define DIO_PIN_HIGH	1

/****************************	APIS Prototypes	***************************/


/* Port APIs */

void DIO_setPortDirection				(u8 PortID, u8 PortDirection);
void DIO_setPortValue					(u8 PortID, u8 PortValue);
void DIO_getPortValue					(u8 PortID, u8* PortValue);
void DIO_togglePortValue				(u8 PortID);
void DIO_activePortInPullUpResistance	(u8 PortID);

/* PIN APIs */

void DIO_setPinDirection				(u8 PortID, u8 PinID, u8 PinDirection);
void DIO_setPinValue					(u8 PortID, u8 PinID, u8 PinValue);
/*u8 DIO_getPinValue					(u8 PortID, u8 PinID);*/
void DIO_getPinValue					(u8 PortID, u8 PinID, u8* PinValue);
void DIO_togglePinValue					(u8 PortID, u8 PinID);
void DIO_activePinInPullUpResistance	(u8 PortID, u8 PinID);


#endif /* DIO_INTERFACE_H_ */