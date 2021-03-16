/*
 * SysTick_Private.h
 *
 *  *  Created on: Feb 2 , 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define NULL 		0
#define AHB			0
#define AHB_DIV_8	1




void (*CallBackFun) (void) = NULL;
u8 FLAG;
typedef struct{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
	volatile u32 CALIB ;
}STK_St;

#define STK ((volatile STK_St*)0xE000E010)

#endif /* SYSTICK_PRIVATE_H_ */
