/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 29/11/2020
* VERION : V0.0 
* DISCRIPTION: DIO_Interface.h
**************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*user define data type*/
#include "../../LIB/STD_Type.h"

/*macros definition*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_PINA 0
#define DIO_PINB 1
#define DIO_PINC 2
#define DIO_PIND 3

#define DIO_DDRA 0
#define DIO_DDRB 1
#define DIO_DDRC 2
#define DIO_DDRD 3


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT 0 
#define DIO_OUTPUT 1


#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT 0x00

#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW 0x00

/*function prototype*/
void DIO_voidSetPinDirection(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8state);
void DIO_voidSetPinValue(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value);
u8   DIO_voidGetPinValue(u8 copy_u8port, u8 copy_u8pin);

void DIO_voidSetPortDirection(u8 copy_u8port, u8 copy_u8state);
void DIO_voidSetPortValue(u8 copy_u8port, u8 copy_u8value);

void DIO_voidTogglePin(u8 copy_u8port, u8 copy_u8pin);

void DIO_voidSetlastnippleDir (u8 copy_u8port, u8 copy_u8state);
void DIO_voidSetfirstnippleDir (u8 copy_u8port, u8 copy_u8state);

void DIO_voidSetFirstNipple(u8 copy_u8port, u8 copy_u8val);
void DIO_voidSetLastNipple(u8 copy_u8port, u8 copy_u8val);

void DIO_voidPlaceFirstNipple(u8 copy_u8port, u8 copy_u8val);
void DIO_voidPLaceLastNipple(u8 copy_u8port, u8 copy_u8val);


#endif

