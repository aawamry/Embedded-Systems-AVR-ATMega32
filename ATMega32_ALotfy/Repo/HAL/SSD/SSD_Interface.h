/*
 * SSD_Interface.h
 *
 * Created: 12/17/2023 9:26:24 AM
 *  Author: aawam
 */ 



#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_ONE				1 
#define SSD_TWO				2

void SSD_Init				(void);
void SSD_displayNumber		(u8 ssdID, u8 desiredNumber);
void SSD_displayMultiNumber	(u8 desiredNumber);

#endif /* SSD_INTERFACE_H_ */