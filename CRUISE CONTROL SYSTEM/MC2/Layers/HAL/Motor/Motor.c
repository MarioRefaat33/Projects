/*** LIBRARY LAYER ***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/AVR_Reg.h"

/*** HARDWARE ABSTRACTION LAYER ***/
#include "Motor_Cfg.h"
#include "Motor.h"

/*** MICROCONTROLLER ABSTRACTION LAYER ***/
#include "../../MCAL/DIO/Dio_Cfg.h"
#include "../../MCAL/DIO/Dio.h"
#include "../../MCAL/PWM/PWM.h"


uint8_t Motor_Init()
{
	DIO_u8Init_PIN(MOTOR_INPUT_2,DIO_OUTPUT);
	DIO_u8Init_PIN(MOTOR_INPUT_1,DIO_OUTPUT);

#if MOTOR_ROTATION == MOTOR_CLOCKWISE_ROTATION
	DIO_u8SetPinValue(MOTOR_INPUT_1,DIO_HIGH);
#elif MOTOR_ROTATION == MOTOR_ANTICLOCKWISE_ROTATION
	DIO_u8SetPinValue(MOTOR_INPUT_2,DIO_HIGH);
#endif
	return NO_ERROR;
}

uint8_t Motor_SetDutyCycle(uint8_t Motor_DutyCycle)
{
	if (Motor_DutyCycle < MAX_DUTY_CYCLE)
	{
		PWM0_DutyCycle(Motor_DutyCycle);
	}
	else
	{
		return ERROR;
	}
	return NO_ERROR;
}

