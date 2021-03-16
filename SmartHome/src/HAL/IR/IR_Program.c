/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 29/11/2020
 * VERION : V0.0
 * DISCRIPTION: Program.C
 **************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/SYSTICK/SysTick_Init.h"
#include "../../MCAL/NVIC/NVIC_Init.h"
#include "../../MCAL/GPIO/GPIO_Init.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/AFIO/AFIO_Interface.h"

#include "IR_Config.h"
#include "IR_Interface.h"
#include "IR_Private.h"

volatile u8 start = 0;
volatile u8 ir_counter = 0;
volatile u32 codeSample[100] = {0};
volatile u8 Data = 0;
volatile u8 i = 0;
void IR_voidInit(void){

	/*SET IR PIN AS INPUT to DETECT FALLING EDGE*/
	GPIO_VidSetPinDirection(IR_PORT, IR_PIN ,GPIO_INPUT_FLOATING);
	/*TRUN ON NVIC TO SET PRIORITY AND ENABLE PERIPHERAL*/
	/*SET ID OF PERIPHERAL ,,, GROUP NUM , SUB GROUP , SHAP OF SYS*/
	/*ENABLE NVIC*/
	NVIC_VidEnablePeripheralInterrupt(EXTI0_ID);
	AFIO_voidSetEXTIConfiguration(EXTI_LINE0,IR_PORT );
	NVIC_VidSetPriority(EXTI0_ID,GROUP_1,SUB_GROUP_0 );
	EXTI0_voidSetCallBack(Read_callBack);
	/*INIT LINE FROM (0 :15) , MODE (FALLING OR RISING, ..)*/
	EXTI_voidInit(EXTI_LINE0, FALLING_EDGE);
	/*MUST SET CALL BAC BEFORE INIT SYS YICK*/
	STK_VoidSetCallBack(Timer_ResetCallBack);
	STK_VidInit();

}
u8 IR_u8GetCode(void){
	u8 ret =0 ;
	while (start !=2);
	ret  = Data;
	start = 0;
	ir_counter = 0;
	Data = 0;
	NVIC_VidEnablePeripheralInterrupt(EXTI0_ID);
	return ret;
}
void Read_callBack(void){
	if(start == 0){
		/*FIRST FALLING EDGE OF FRAM */
		STK_VidStart(TIMER_VALUE);
		start =1 ;
	}
	else if (start == 1){
		codeSample [ir_counter] = STK_U32GetRemainingTime();
		ir_counter++;
		STK_VidStart(TIMER_VALUE);
	}
	if(ir_counter == END_OF_CODE){
		for ( i = 0; i<END_OF_CODE; i++){
			codeSample[i]=TIMER_VALUE -codeSample[i];

		}
		for ( i = DATA_COMMEND_START_EDGE; i< DATA_COMMEND_END_EDGE; i++){
			if(codeSample [i] >= LOGIC1_RANGE){
				SET_BIT(Data, (i- DATA_COMMEND_START_EDGE));

			}
		}
		NVIC_VidDisablePeripheralInterrupt(EXTI0_ID);
		start = 2;
	}
}
void Timer_ResetCallBack(void){
	/*RESET LOAD REG AND VAL REG AND REG
	 * BEFORE START OF ANY OPERATION*/
	STK_VidStopTimer();
	start = 0;
	ir_counter = 0;
	Data = 0;

}
