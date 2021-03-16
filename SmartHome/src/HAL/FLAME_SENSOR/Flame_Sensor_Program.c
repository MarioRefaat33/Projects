/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 10 March 2021
//	Version : V1
//	Module 	: Flame_Sensor_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Flame_Sensor_Interface.h" 
#include "Flame_Sensor_Config.h" 
#include "Flame_Sensor_Private.h" 
#include "../../MCAL/GPIO/GPIO_Init.h"

void H_Flame_Sensor_Init()
{
	GPIO_VidSetPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,GPIO_INPUT_PULLUP_PULLDOWN);
}
u8 	 H_Flame_Sensor_Read()
{
	u8 flame =  0;

	flame = GPIO_U8GetPinValue(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);
	return flame;
}
