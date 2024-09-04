/*
 * LCD_Interface.h
 *
 * Created: 12/23/2023 7:18:30 PM
 *  Author: aawam
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Macros for LCD Shifting Directions*/

#define LCD_SHIFT_LEFT	1
#define LCD_SHIFT_RIGHT 2

/* Macros for LCD Line ID */

#define LCD_LINE_ONE 1
#define LCD_LINE_TWO 2

void LCD_init					(void);
void LCD_sendCMD				(u8 CMD);
void LCD_sendChar				(u8 data);
void LCD_clear					(void);
void LCD_writeString			(u8* string);
void LCD_shift					(u8 shiftingDirection);
void LCD_gotoSpeciicPosition	(u8 LineNumber, u8 Position);
void LCD_writeNumber			(u32 number);

#endif /* LCD_INTERFACE_H_ */