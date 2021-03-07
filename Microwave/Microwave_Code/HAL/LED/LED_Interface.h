/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: LED_Interface.h
**************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../LIB/STD_Type.h"
void LED_voidInitLed(u8 copy_u8port, u8 copyu8pin);
void LED_voidOnLed(u8 copy_u8port, u8 copyu8pin);
void LED_voidOffLed(u8 copy_u8port, u8 copyu8pin);
void LED_voidToggleLed(u8 copy_u8port, u8 copyu8pin);
#endif /* LED_INTERFACE_H_ */
