/*
 * SysTick_Init.h
 *
 *   Created on: Feb 2 , 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef SYSTICK_INIT_H_
#define SYSTICK_INIT_H_

#define STK_INT_EN   1
#define STK_INT_DIS  0

void STK_VidInit(void);

void STK_VoidSetBusyWait(u32 Copy_U32Ticks);

void STK_VoidSetCallBack(void(*ptr)(void));

void STK_VidSetIntervalSignal(u32 Copy_U32Ticks , void (*Ptr_Fun) (void));

void STK_VidSetIntervalSignalForIR(u32 Copy_U32Ticks , void (*Ptr_Fun) (void));

void STK_VidSetIntervalPeriodic (u32 Copy_U32Ticks, void (*Ptr_Fun) (void));

u32 STK_U32GetRemainingTime(void);

u32 STK_U32GetElapsedTime(void);

void STK_VidStopTimer(void);

void STK_VidStart( u32 Copy_PreloadValue );

void STK_VidINTStatus( u8 Copy_u8Status );

u8 STK_u8ReadFlag( void );

void _delay_ms( u32 Copy_u32Time );

void _delay_us( u32 Copy_u32Time );

#endif /* SYSTICK_INIT_H_ */
