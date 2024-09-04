/*
 * LED_Interface.h
 *
 * Created: 12/16/2023 5:04:36 PM
 *  Author: aawam
 */ 



#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void LED_Init	(u8 LedPort, u8 LedPin);
void LED_On		(u8 LedPort, u8 LedPin);
void LED_Off	(u8 LedPort, u8 LedPin);
void LED_Toggle	(u8 LedPort, u8 LedPin);



#endif /* LED_INTERFACE_H_ */