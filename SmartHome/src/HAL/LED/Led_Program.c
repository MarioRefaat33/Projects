/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 10 March 2021
//	Version : V1
//	Module 	: Led_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Led_Interface.h" 
#include "Led_Config.h" 
#include "Led_Private.h" 
#include "../../MCAL/GPIO/GPIO_Init.h"

void H_Led_Init()
{

	GPIO_VidSetPinDirection(LED_PORT,LED_GREEN_PIN,GPIO_OUTPUT_SPEED_2M_PP);
	GPIO_VidSetPinDirection(LED_PORT,LED_RED_PIN,GPIO_OUTPUT_SPEED_2M_PP);

	GPIO_VidSetPinValue(LED_PORT,LED_GREEN_PIN,GPIO_LOW);
	GPIO_VidSetPinValue(LED_PORT,LED_RED_PIN,GPIO_LOW);

}
void H_Led_Green_ON()
{
	GPIO_VidSetPinValue(LED_PORT,LED_GREEN_PIN,GPIO_HIGH);
}
void H_Led_Green_Off()
{
	GPIO_VidSetPinValue(LED_PORT,LED_GREEN_PIN,GPIO_LOW);
}
void H_Led_Red_ON()
{
	GPIO_VidSetPinValue(LED_PORT,LED_RED_PIN,GPIO_HIGH);
}

void H_Led_Red_Off()
{
	GPIO_VidSetPinValue(LED_PORT,LED_RED_PIN,GPIO_LOW);
}
