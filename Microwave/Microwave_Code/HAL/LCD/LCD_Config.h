/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 2/1/2021
* VERION : V0.0 
* DISCRIPTION: LCD_CONFIG.h
**************************************************/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

 
#define LCD_CONTROL_CONNECTED_PORT		(DIO_PORTC)
#define RS 								(DIO_PIN0)
#define RW								(DIO_PIN1)
#define E 								(DIO_PIN2)


#define LCD_DATA_CONNECTED_PORT			(DIO_PORTC)       	// Change this value (PORT_D) if you connected to a different port of the AVR.
#define LCD_BUSY_FLAG_BIT				(DIO_PIN7)
#define LCD_DATA_PORT_INIT 				(u8)0xFF;

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD Data bits mode configuration */
#define  DATA_BITS_MODE 4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

/* LCD Commands */
#define LCD_COM_CLEAR					(u8)(0x01)
#define LCD_COM_HOME					(u8)(0x02)
#define LCD_COM_ENTRYMODE				(u8)(0x06)
#define LCD_COM_DISPLAY_OFF				(u8)(0x08)
#define LCD_COM_DISPLAY_ON				(u8)(0x0C)
#define LCD_COM_DISPLAY_ON_CURSOR_BLINK	(u8)(0x0D)
#define LCD_COM_CURSOR_SHIFT_LEFT		(u8)(0x10)
#define LCD_COM_CURSOR_SHIFT_RIGHT		(u8)(0x14)
#define LCD_COM_DISPLAY_SHIFT_LEFT		(u8)(0x18)
#define LCD_COM_DISPLAY_SHIFT_RIGHT		(u8)(0x1C)
#define LCD_COM_FUNCTION_RESET			(u8)(0x30)
#define LCD_COM_FUNCTION_SET_8BIT		(u8)(0x38)
#define LCD_COM_SET_CURSOR_FIRST_LINE	(u8)(0x80)
#define LCD_COM_SET_CURSOR_SECOND_LINE	(u8)(0xc0)
#define LCD_FIRST_LINE_BASE_ADDRESS		(u8)0x00
#define LCD_SECOND_LINE_BASE_ADDRESS	(u8)0x40
#define TWO_LINE_LCD_Four_BIT_MODE      (u8)(0x28)
#define LCD_MAX_CHAR_PER_LINE			(u8)16
#define Eight_Bit_Mode 					(u8)(0)
#define Four_Bit_Mode 					(u8)(0x02)
#define LCD_MAX_ASCII_CODE 				(u8)127
#define CURSOR_ON                       (u8)0x0E

#endif /* LCD_CONFIG_H_ */
