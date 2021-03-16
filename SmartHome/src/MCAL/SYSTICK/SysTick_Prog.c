/*
 * SysTick_Prog.c
 *
 *  *  Created on: Feb 2 , 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SysTick_Init.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"



void SysTick_Handler(void)
{
	if (CallBackFun != NULL)
	{CallBackFun();}
	if(!FLAG)
	{
		STK->LOAD=0;
		STK->VAL=0;
	}
	else
	{
		//read interrupt flag to clear it
		u8 x =  GET_BIT(STK->CTRL, 16);
		CLR_BIT(STK->CTRL, 16);
	}
}

void STK_VoidSetCallBack(void(*ptr)(void))
{
	CallBackFun = ptr;
}
void STK_VidInit(void)
{
#if CLOCK_SOURC == AHB
	STK-> CTRL = (1 << 2);
#elif CLOCK_SOURC == AHB_DIV_8
	CLR_BIT(STK->CTRL,2);
#endif
}

void STK_VoidSetBusyWait(u32 Copy_U32Ticks)
{
	STK->LOAD = Copy_U32Ticks;
	CLR_BIT(STK->CTRL,1);
	SET_BIT(STK->CTRL,0);
	while(GET_BIT(STK->CTRL,16) == 0);
	CLR_BIT(STK->CTRL , 0 );
	STK->LOAD=0;
	STK->VAL=0;
}

void STK_VidSetIntervalSignal(u32 Copy_U32Ticks , void (*Ptr_Fun) (void))
{
	/* Disable Timer */
	CLR_BIT(STK->CTRL,0);
	STK -> VAL = 0;
	STK->LOAD = Copy_U32Ticks;
	SET_BIT(STK->CTRL , 0);
	CallBackFun=Ptr_Fun;
	SET_BIT(STK->CTRL , 1);
}

void STK_VidSetIntervalPeriodic (u32 Copy_U32Ticks ,  void (*Ptr_Fun) (void))
{
	STK->LOAD = Copy_U32Ticks;
	SET_BIT(STK->CTRL , 0);
	CallBackFun=Ptr_Fun;
	FLAG=1;
	SET_BIT(STK->CTRL , 1);

}
void STK_VidSetIntervalSignalForIR(u32 Copy_U32Ticks , void (*Ptr_Fun) (void))
{
	CLR_BIT(STK->CTRL,0);
	STK->VAL = 0;
	STK->LOAD = Copy_U32Ticks;
	CallBackFun=Ptr_Fun;
	SET_BIT(STK->CTRL , 1);
	SET_BIT(STK->CTRL , 0);
	FLAG=0;
}

u32 STK_U32GetRemainingTime(void)
{
	return (STK->VAL);

}

u32 STK_U32GetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL);
}

void STK_VidStopTimer(void)
{
	CLR_BIT(STK->CTRL , 0);
}


void STK_VidStart( u32 Copy_PreloadValue ){

	// AHB = EXT = 8MHZ & CLOCK OF MSTK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
	//Load Reload Value
	STK->LOAD = Copy_PreloadValue - 1;
	//Clear Val Register
	STK->VAL  = 0 ;
	//Enable Systick
	SET_BIT( STK->CTRL , 0 );

}

void STK_VidINTStatus( u8 Copy_u8Status ){

	STK->CTRL &= ~( 1 << 1 );
	STK->CTRL |=  ( Copy_u8Status << 1 );

}

u8 STK_u8ReadFlag( void ){

	return ( GET_BIT( STK->CTRL , 16 ) );

}

void _delay_ms( u32 Copy_u32Time ){

	STK_VidInit();
	/* Disable INT */
	STK_VidINTStatus( STK_INT_DIS );
	STK_VidStart( Copy_u32Time * 1000 );
	/* Wiat Flag Polling */
	while( STK_u8ReadFlag() == 0 );

}


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_us( u32 Copy_u32Time ){

	STK_VidInit();
	/* Disable INT */
	STK_VidINTStatus( STK_INT_DIS );
	STK_VidStart( Copy_u32Time );
	/* Wiat Flag Polling */
	while( STK_u8ReadFlag() == 0 );

}
