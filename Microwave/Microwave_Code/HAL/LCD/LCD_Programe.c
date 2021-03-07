/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 29/11/2020
 * VERION : V0.0
 * DISCRIPTION: LCD_Program.h
 **************************************************/

#include "../../LIB/STD_Type.h"
#include "../../HAL/LCD/LCD_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>


void LCD_voidSendCommand(u8 Copy_U8Command)
{
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, RS, DIO_LOW);	//RS = 0	D0
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, RW, DIO_LOW);	//RW = 0	D1
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E, DIO_HIGH); // Enable = 1
	_delay_ms(1);

#if (DATA_BITS_MODE == 4)
	/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS

	DIO_voidSetLastNipple(LCD_DATA_CONNECTED_PORT,Copy_U8Command);
	_delay_ms(1);

#else
	DIO_voidPLaceLastnipple(LCD_DATA_CONNECTED_PORT,Copy_U8Command);
	_delay_ms(1);
#endif

	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E, DIO_LOW); // Enable = 0
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E, DIO_HIGH); // Enable = 1
	_delay_ms(1);

	/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS

	DIO_voidPlaceFirstNipple(LCD_DATA_CONNECTED_PORT,Copy_U8Command);

#else

	DIO_voidSetFirstNipple(LCD_DATA_CONNECTED_PORT,Copy_U8Command);

#endif
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E, DIO_LOW); // Enable = 0
	_delay_ms(1);
#elif (DATA_BITS_MODE == 8)
	DIO_SetPortValue(DIO_DDRC,Copy_U8Command);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E, DIO_LOW); // Enable = 0
	_delay_ms(1);
#endif

}

void LCD_voidSendData(char Copy_U8Data)
{
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, RS,DIO_HIGH);	//RS = 1	D0
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, RW,DIO_LOW);	//RW = 0	D1
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E,DIO_HIGH);
	_delay_ms(1);
#if (DATA_BITS_MODE == 4)
	/* out the highest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS

	DIO_voidSetLastNipple(LCD_DATA_CONNECTED_PORT,  Copy_U8Data);


#else
	DIO_voidPLaceLastnipple(LCD_DATA_CONNECTED_PORT, Copy_U8Data);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E,DIO_LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E,DIO_HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
	DIO_voidPlaceFirstNipple(LCD_DATA_CONNECTED_PORT,  Copy_U8Data );
	_delay_ms(1);
#else
	DIO_voidSetFirstNipple(LCD_DATA_CONNECTED_PORT,  Copy_U8Data);
#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E,DIO_LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#elif (DATA_BITS_MODE == 8)

	DIO_SetPortValue(DIO_DDRC,Copy_U8Data);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_CONTROL_CONNECTED_PORT, E,DIO_LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}


void LCD_voidInit(void)
{
	DIO_voidSetPinDirection(LCD_CONTROL_CONNECTED_PORT, RS, DIO_OUTPUT);  // RS = output
	DIO_voidSetPinDirection(LCD_CONTROL_CONNECTED_PORT, RW, DIO_OUTPUT);  // RE = output
	DIO_voidSetPinDirection(LCD_CONTROL_CONNECTED_PORT, E,  DIO_OUTPUT);   // E  = output
#if (DATA_BITS_MODE == 4)
#ifdef UPPER_PORT_PINS
	DIO_voidSetlastnippleDir (LCD_DATA_CONNECTED_PORT, 1);
#else
	DIO_SetfirstnippleDir(LCD_DATA_CONNECTED_PORT, 1);
#endif
	LCD_voidSendCommand( Four_Bit_Mode); /* initialize LCD in 4-bit mode */
	LCD_voidSendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode +
5*7 dot display Mode */
#elif ( DATA_BITS_MODE == 8)
	DIO_SetPortDirection(LCD_DATA_CONNECTED_PORT, DIO_PORT_OUTPUT); /* Configure the data port as output port */
	LCD_voidSendCommand(Eight_Bit_Mode); /* use 2-line lcd + 8-bit Data Mode + 5*7
dot display Mode */
#endif

	LCD_voidSendCommand(LCD_COM_DISPLAY_ON	); /* cursor off */
	LCD_voidSendCommand(LCD_COM_CLEAR); /* clear LCD at the beginning */

}





void LCD_voidSendString( char * Copy_U8String)
{
	u8 i = 0 ;
	while(Copy_U8String[i] != '\0'){
		LCD_voidSendData(Copy_U8String[i]);
		i++;
	}
}
void LCD_voidgotorowcolum(u8 copy_u8row, u8 copy_u8colum){

	u8 Address;
	switch(copy_u8row)
	{
	case 0:	 Address = copy_u8colum;  break;
	case 1:  Address = copy_u8colum + 0x40;  break;

	}

	LCD_voidSendCommand(Address |0x80);

}
void LCD_displayStringRowColum(u8 copy_u8row, u8 copy_u8colum, u32 *string){
	LCD_voidgotorowcolum(copy_u8row, copy_u8colum);
	LCD_voidSendString(string);

}

void LCD_1ByteToString(u8 copy_u8num){
	int i, rem, len = 0, n;
	u8 str[11]={0};
	n = copy_u8num;
	if(copy_u8num == 0){
		LCD_voidSendData('0');
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = copy_u8num % 10;
		copy_u8num = copy_u8num / 10;
		str[len - (i + 1)] = rem + '0';
	}

	str[len] = '\0';
	LCD_voidSendString(str);


}

void LCD_4ByteToString(u32 copy_u8num){
	u32 i, rem, len = 0, n;
	u8 str[11]={0};
	n = copy_u8num;
	if(copy_u8num == 0){
		LCD_voidSendData('0');
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = copy_u8num % 10;
		copy_u8num = copy_u8num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	LCD_voidSendString(str);

}

void LCD_DeleteChar(void){
	LCD_voidSendCommand(CURSOR_ON);
	LCD_voidSendCommand(0x10); //shift cursor left
	LCD_voidSendData(' ');
	_delay_ms(10);
	LCD_voidSendCommand(0x10);
}

