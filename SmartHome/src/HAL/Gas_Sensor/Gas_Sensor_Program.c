/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 10 March 2021
//	Version : V1
//	Module 	: Gas_Sensor_Module
/******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Gas_Sensor_Interface.h" 
#include "Gas_Sensor_Config.h" 
#include "Gas_Sensor_Private.h" 
#include "../../MCAL/GPIO/GPIO_Init.h"

void H_Gas_Sensor_Init()
{
	GPIO_VidSetPinDirection(GAS_SENSOR_PORT,GAS_SENSOR_PIN,GPIO_INPUT_PULLUP_PULLDOWN);
}
u8 	 H_Gas_Sensor_Read()
{
	u8 gas = 0;

	gas = GPIO_U8GetPinValue(GAS_SENSOR_PORT,GAS_SENSOR_PIN);
	return gas;
}

