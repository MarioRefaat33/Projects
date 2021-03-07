/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 29/11/2020
* VERION : V0.0
* DISCRIPTION: LCD_Interface.h
**************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../LIB/STD_Type.h"

/*function prototype*/
void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_U8Data);
void LCD_voidSendCommand(u8 Copy_U8Command);
void LCD_voidSendString(u8 Copy_U8String);
void LCD_voidgotorowcolum(u8 copy_u8row, u8 copy_u8colum);
void LCD_displayStringRowColum(u8 copy_u8row, u8 copy_u8colum, u32 *string);
void LCD_4ByteToString(u32 copy_u8num);
void LCD_1ByteToString(u8 copy_u8num);
void LCD_DeleteChar(void);
#endif /* LCD_INTERFACE_H_ */
