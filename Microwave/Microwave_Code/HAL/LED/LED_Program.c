/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: LED_Program.c
 **************************************************/
#include "../../LIB/STD_Type.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void LED_voidInitLed(u8 copy_u8port, u8 copyu8pin){
#if LED_MODE ==   ACTIVE_HIGH
	DIO_voidSetPinDirection(copy_u8port,copyu8pin,DIO_OUTPUT);
	DIO_voidSetPinValue(copy_u8port,copyu8pin,DIO_LOW);

#elif LED_MODE == ACTIVE_LOW
	DIO_voidSetPinDirection(copy_u8port,copyu8pin,DIO_OUTPUT);
	DIO_voidSetPinValue(copy_u8port,copyu8pin,DIO_HIGH);

#endif

}
void LED_voidOnLed(u8 copy_u8port, u8 copyu8pin){
#if LED_MODE ==   ACTIVE_HIGH

	DIO_voidSetPinValue(copy_u8port,copyu8pin,DIO_HIGH);

#elif LED_MODE == ACTIVE_LOW

	DIO_voidSetPinValue(copy_u8port,copyu8pin,DIO_LOW);

#endif

}
void LED_voidOffLed(u8 copy_u8port, u8 copyu8pin){
#if LED_MODE ==   ACTIVE_HIGH

	DIO_voidSetPinValue(copy_u8port,copyu8pin,DIO_LOW);

#elif LED_MODE == ACTIVE_LOW
	DIO_voidSetPinValue(copy_u8port,copyu8pin,DIO_HIGH);

#endif

}
void LED_voidToggleLed(u8 copy_u8port, u8 copyu8pin){
	DIO_voidTogglePin(copy_u8port,  copyu8pin);
}
