/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 10 March 2021
//	Version : V1
//	Module 	: Motor_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Motor_Interface.h" 
#include "Motor_Config.h" 
#include "Motor_Private.h" 
#include "../../MCAL/GPIO/GPIO_Init.h"

void H_Motor_Init()
{
	GPIO_VidSetPinDirection(MOTOR_PORT,MOTOR_PIN,GPIO_OUTPUT_SPEED_2M_PP);
}
void H_Motor_On()
{
	GPIO_VidSetPinValue(MOTOR_PORT,MOTOR_PIN,GPIO_HIGH);
}
void H_Motor_Off()
{
	GPIO_VidSetPinValue(MOTOR_PORT,MOTOR_PIN,GPIO_LOW);
}
