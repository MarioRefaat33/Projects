/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 09 March 2021
//	Version : V1
//	Module 	: Servo_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Servo_Interface.h" 
#include "Servo_Config.h" 
#include "Servo_Private.h" 
#include "../../MCAL/RCC/RCC_Init.h"
#include "../../MCAL/GPIO/GPIO_Init.h"
#include "../../MCAL/PWM/PWM_Init.h"

void Servo_Vid_Init()
{

	RCC_VidInit();
	RCC_VidEnableClock(RCC_APB1,RCC_APB1_TIM4);
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_IOPB);
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_AFIO);
	GPIO_VidSetPinDirection(SERVO_PORT,SERVO_PIN,GPIO_OUTPUT_SPEED_2M_AFPP);

	PWM_VidInit();
}

void Servo_set_position(u8 position)
{
	PWM_VidSetDuty( (u8) position );
}
