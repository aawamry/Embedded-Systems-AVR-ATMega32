/*
 * SWT_Interface.h
 *
 * Created: 12/16/2023 5:59:10 PM
 *  Author: aawam
 */ 


#ifndef SWT_INTERFACE_H_
#define SWT_INTERFACE_H_
	
#define SWT_NOT_PRESSED 0
#define SWT_PRESSED		1

void SWT_Init		(u8 SwtPort, u8 SwtPin);
void SWT_getState	(u8 SwtPort, u8 SwtPin, u8* swState);


#endif /* SWT_INTERFACE_H_ */