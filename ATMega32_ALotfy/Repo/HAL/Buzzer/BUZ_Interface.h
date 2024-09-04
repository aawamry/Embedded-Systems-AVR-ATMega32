/*
 * BUZ_Interface.h
 *
 * Created: 12/16/2023 5:36:21 PM
 *  Author: aawam
 */ 



#ifndef BUZ_INTERFACE_H_
#define BUZ_INTERFACE_H_

void BUZ_Init	(u8 BuzPort, u8 BuzPin);
void BUZ_On		(u8 BuzPort, u8 BuzPin);
void BUZ_Off	(u8 BuzPort, u8 BuzPin);
void BUZ_Toggle	(u8 BuzPort, u8 BuzPin);


#endif /* BUZ_INTERFACE_H_ */