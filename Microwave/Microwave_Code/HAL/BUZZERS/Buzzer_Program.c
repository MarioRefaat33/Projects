/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 5/1/2021
* VERION : V0.0
* DISCRIPTION: Buzzer_Program.h
**************************************************/

#include "../../LIB/STD_Type.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/BUZZERS/Buzzer_Config.h"

void Buzzer_voidInit(void){
	DIO_voidSetPinDirection(BUZZER_PORT,BUZZER_PIN,DIO_OUTPUT);
}

void Buzzer_voidOn(void){
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_HIGH);
}
void Buzzer_voidOff(void){
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_LOW);
}
