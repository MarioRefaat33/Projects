/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 30/1/2021
 * VERION : V0.0
 * DISCRIPTION:  MCAL_EXT_INTERRUPT_EXTI_INGTERFACE_H_
 **************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"

static void (*EXTI0_callBack) (void) =  NULL_PTR ;
static void (*EXTI1_callBack) (void) =  NULL_PTR ;
void EXTI_voidInit(u8 copy_u8EXTILine , u8 copy_u8EXTIMode){
	EXTI -> IMR = 0;
	EXTI -> PR = 0xffffffff;
	SET_BIT(EXTI-> RTSR , copy_u8EXTILine);

	switch(copy_u8EXTIMode){
	case RISING_EDGE:
		SET_BIT(EXTI-> RTSR , copy_u8EXTILine);
		break;

	case FALLING_EDGE:
		SET_BIT( EXTI->FTSR , copy_u8EXTILine );
		CLR_BIT(EXTI-> RTSR , copy_u8EXTILine);
		break;


	case ON_CHANGE:
		SET_BIT( EXTI->RTSR , copy_u8EXTILine);
		SET_BIT( EXTI->FTSR , copy_u8EXTILine );
		break;
	}
	SET_BIT(EXTI -> IMR , copy_u8EXTILine);
}
void EXTI_voidEnable(u8 copy_u8EXTILine){
	SET_BIT(EXTI -> IMR , copy_u8EXTILine);
}
void EXTI_voidDisable(u8 copy_u8EXTILine){
	CLR_BIT(EXTI -> IMR , copy_u8EXTILine);

}
void EXTI_voidSoftwareTrigger(u8 copy_u8EXTILine){
	SET_BIT( EXTI->SWIER , copy_u8EXTILine);

}
void EXTI_voidSetCallBack(void (*ptr) (void)){
	if(ptr !=  NULL_PTR){
		EXTI0_callBack = ptr ;
	}

}
void EXTI1_voidSetCallBack(void (*ptr) (void)){
	if(ptr !=  NULL_PTR){
		EXTI1_callBack = ptr ;
	}

}
void EXTI0_voidSetCallBack(void (*ptr) (void)){
	if(ptr !=  NULL_PTR){
		EXTI0_callBack = ptr ;
	}

}

void EXTI0_IRQHandler(void){
	EXTI0_callBack();  /*POINTER TO FUNCTION TO PERFORM FUNCTION */
	SET_BIT(EXTI -> PR , 0) ;

}

void EXTI1_IRQHandler(void){
	EXTI1_callBack();  /*POINTER TO FUNCTION TO PERFORM FUNCTION */
	SET_BIT(EXTI -> PR , 0) ;

}

