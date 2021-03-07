/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: MOTOTR_Program.c
 **************************************************/

#include "../../LIB/STD_Type.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER/Timer1/timer1_Interface.h"
#include "../../HAL/MOTORS/MOTOR_Config.h"
void MOTOR_voidInit(void){
#if  NUM_OF_MOTORS == CONNECT_TWO_MOTOR
/*INIATE MOTOR ONE ON H-BRIDGE*/
DIO_voidSetPinDirection (MOTOR1_PORT, MOTOR1_PIN1,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR1_PORT,  MOTOR1_PIN2,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR1_PORT,MOTOR1_ENABLE,DIO_OUTPUT);

/*INIATE MOTOR TWO ON H-BRIDGE*/
DIO_voidSetPinDirection (MOTOR2_PORT, MOTOR2_PIN1,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR2_PORT,  MOTOR2_PIN2,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR2_PORT,MOTOR2_ENABLE,DIO_OUTPUT);

#elif  NUM_OF_MOTORS ==  CONNECT_ONE_MOTOR
/*INIATE MOTOR ONE ON H-BRIDGE*/
DIO_voidSetPinDirection (MOTOR1_PORT, MOTOR1_PIN1,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR1_PORT,  MOTOR1_PIN2,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR1_PORT,MOTOR1_ENABLE,DIO_OUTPUT);

#endif
#if MOTOR_STATE ==  MOTOR_Generate_pwm
DIO_voidSetPinDirection (MOTOR_PORT, MOTOR_PIN1,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR_PORT,  MOTOR_PIN2,DIO_OUTPUT);
DIO_voidSetPinDirection(MOTOR_PORT,MOTOR1_ENABLE,DIO_OUTPUT);
DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1,DIO_HIGH);
DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2,DIO_LOW);
#else
#endif
}

void MOTOR_voidRotateClkWise(u8 copy_u8top,u8 copy_u8down){
	if(copy_u8top == 1){
		/*INIATE MOTOR ONE ON H-BRIDGE*/
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN1,DIO_HIGH);
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN2,DIO_LOW);
		DIO_voidSetPinValue(MOTOR1_PORT,MOTOR1_ENABLE, DIO_HIGH);
	}
	else if(copy_u8top == 0){
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN2,DIO_LOW);
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN2,DIO_LOW);
	}
	/*INIATE MOTOR ONE ON H-BRIDGE*/
	if(copy_u8down== 1){
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_PIN1,DIO_HIGH);
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_PIN2,DIO_LOW);
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_ENABLE, DIO_HIGH);
	}
	else if(copy_u8top == 0){
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN2,DIO_LOW);
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN2,DIO_LOW);
	}

}
void MOTOR_voidRotateAntiClkWise(u8 copy_u8top,u8 copy_u8down){
	if (copy_u8top == 1){
		/*INIATE MOTOR ONE ON H-BRIDGE*/
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN1,DIO_LOW);
		DIO_voidSetPinValue(MOTOR1_PORT,  MOTOR1_PIN2,DIO_HIGH);
		DIO_voidSetPinValue(MOTOR1_PORT,MOTOR1_ENABLE,DIO_HIGH);
		/*INIATE MOTOR ONE ON H-BRIDGE*/
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_PIN1,DIO_LOW);
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_PIN2,DIO_HIGH);
		DIO_voidSetPinValue(MOTOR2_PORT, MOTOR2_ENABLE,DIO_HIGH);
	}
	else if(copy_u8top== 0){
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN1,DIO_LOW);
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN2,DIO_LOW);
	}

	else if(copy_u8down == 0 ){
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_PIN1,DIO_LOW);
		DIO_voidSetPinValue(MOTOR2_PORT,MOTOR2_PIN2,DIO_LOW);
	}


}

void MOTOR_voidGeneratePWM(u8 copy_u8dutycycle){
	Timer1_Load_OCR1(copy_u8dutycycle);
}
void MOTOR_voidStop(void){
	DIO_voidSetPinValue( MOTOR1_PORT,MOTOR1_ENABLE,DIO_LOW);
	DIO_voidSetPinValue( MOTOR2_PORT,MOTOR2_ENABLE,DIO_LOW);
}
