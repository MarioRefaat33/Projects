/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 11 March 2021
//	Version : V1
//	Module 	: Buzzer_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Buzzer_Interface.h" 
#include "Buzzer_Config.h" 
#include "Buzzer_Private.h"
#include "../../MCAL/GPIO/GPIO_Init.h"

void H_Buzzer_Init()
{
	GPIO_VidSetPinDirection(BUZZER_PORT,BUZZER_PIN,GPIO_OUTPUT_SPEED_2M_PP);

}
void H_Buzzer_ON()
{
	GPIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,GPIO_HIGH);
}
void H_Buzzer_Off()
{
	GPIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,GPIO_LOW);
}
