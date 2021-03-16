/************************************************************/  
/* 	LCD_Interface.h                                        */
/*                                                          */
/*  Created on	: Jan 26, 2021                              */
/*  Author		: Abanoub Raouf                             */
/*	version		: version 2                                 */
/*	LCD_version	: LMB161A									*/
/************************************************************/    

#ifndef _LCD_Interface_H_ 
#define _LCD_Interface_H_ 

#include"LCD_Confg.h"
void LCD_VidInt						(void					);
void LCD_VidSendCommand				(u8 copy_u8Command		);
void LCD_VidSendData				(u8 copy_u8Data			);
void LCD_VidSendString				(u8 copy_u8String[100]	);
void LCD_VidSetPositin 				(u8 row,u8 coulmn		);
void LCD_VidWriteNumber 			(s32 x					);


void LCD_VidSendCommand_FourBit		(u8 copy_u8Command		);
void LCD_VidInt_FourBit				(		void			);
void LCD_VidSendData_FourBit		(u8 copy_u8Data			);
void LCD_VidSendString_FourBit		(u8 copy_u8String[100]	);
void LCD_VidSetPositin_FourBit 		(u8 row,u8 coulmn		);
void LCD_VidWriteNumber_FourBit 	(s32 x					);



#define LCD_CLEAR    			    0b00000001
#define LCD_HOME       				0x02
#define LCD_ENTERYMODE 				0x06
#define LCD_DISPLAYOFF 				0x08
#define LCD_DISPLAYON			 	0x0c
#define LCD_SETCURSER0              0x80
#define LCD_SETCURSER1              0xc0
#define LCD_FUNCTION_RESET  		0x30
#define LCD_FUNCTIONSET_8BIT        0x38
#define LCD_FUNCTIONSET_4BIT        0x28
#define LCD_SHIFT_LEFT				0x18
#define LCD_SHIFT_RIGHT				0x1c
#define LCD_CGRAM_ADD0				0x40
#define LCD_DDRAM_ADD0				0x80
#define LCD_SETCURSER2				0x94
#define LCD_SETCURSER3				0xD4

#endif
