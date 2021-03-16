/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 06 March 2021
//	Version : V1
//	Module 	: Temreture_Sensor_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Temreture_Sensor_Interface.h" 
#include "Temreture_Sensor_Config.h" 
#include "Temreture_Sensor_Private.h" 
#include "../../MCAL/RCC/RCC_Init.h"
#include "../../MCAL/GPIO/GPIO_Init.h"
#include "../../MCAL/ADC/ADC_Init.h"


void H_TEMP_Vid_Init()
{
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_ADC1);
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_IOPA);
	GPIO_VidSetPinDirection(TEMPRETURE_SENSOR_PORT,TEMPRETURE_SENSOR_PIN,GPIO_INPUT_ANLOG);
	ADC_VidInit();

}
u16 H_TEMP_Get_Temp()
{
	u16 Tempreture = 0;
	Tempreture = ADC_U16StartConversion(TEMPREATURE_SENSOR_CHANNLE);
	Tempreture = ( Tempreture * 330)/4095;

	return Tempreture;
}
