/*
 * LCD_Code.c
 *
 * Created: 12/23/2023 7:31:30 PM
 *  Author: aawam
 */ 


#define F_CPU 16000000UL

/******* General C Lib ********/

#include <util/delay.h>
#include <stdio.h>

/******* Programmer Defined Libs ********/

/* Service Lib */

#include "../../Service/STD_DATATYPES.h"
#include "../../Service/BIT_MATH.h"

/* MCAL Lib */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Registers.h"

/* HAL Lib */

#include "LCD_Interface.h"
#include "LCD_config.h"

/* Code */

void LCD_init(void)
{
	/* Initialize LCD PINs as Output */
	
	DIO_setPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_E_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_OUTPUT);
	_delay_ms(35);
	
	 /* set RS PIN = 0 (write command) */
	 
	 DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	 
	 /* set RW PIN = 0 (write) */
	 
	 DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	 DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, 0);
	 DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, 1);
	 DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, 0);
	 DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, 0);
	 
	 /* Enable Pulse *//* H => L */
	 
	 DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	 _delay_ms(1);
	 
	 DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_LOW);
	
	 /* Function Set Command 2*16 LCD 4 Bit Mode*/
	 LCD_sendCMD(0b00101000);
	 _delay_ms(45);
	 
	 /* Display on off Control (Display On, Cursor On, Blink On)*/
	 LCD_sendCMD(0b00001111);
	 _delay_ms(45);
	 
	 /* Clear Display */
	 LCD_sendCMD(0b00000001);
	 _delay_ms(45);
	 
	 /* Set Entry (Increment On, Shift Off) */
	 LCD_sendCMD(0b00000110);
	 _delay_ms(45);
}

void LCD_sendCMD(u8 CMD)
{
	/* set RS PIN = 0 (Write Command) */
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	
	/* set RW PIN = 0 (Write) */
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	
	/* Write The Most 4 Bits of Command on Data Pins*/
	DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(CMD, 0));
	DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(CMD, 1));
	DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(CMD, 2));
	DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(CMD, 3));
	
	/* Enable Pulse *//* H => L */
	
	DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_LOW);
}

void LCD_sendChar(u8 data)
{
	/* set RS PIN = 1 (Write Command) */
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	
	/* set RW PIN = 0 (Write) */
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	
	/* Write The Most 4 Bits of Command on Data Pins*/
	DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(data, 4));
	DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(data, 5));
	DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(data, 6));
	DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(data, 7));
	
	/* Enable Pulse *//* H => L */
	
	DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_LOW);

	/* Write The Least 4 Bits of Command on Data Pins*/
	DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(data, 0));
	DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(data, 1));
	DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(data, 2));
	DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(data, 3));
	
	/* Enable Pulse *//* H => L */
	
	DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_LOW);

}

void LCD_clear(void)
{
	LCD_sendCMD(0b00000001);
	_delay_ms(2);
}

void LCD_writeString(u8* string)
{
	if(string != NULL)
	{
		u8 counter = 0;
		while (string[counter] != '\0')
		{
			LCD_sendChar(string[counter]);
			counter++;
		}
	}
}



