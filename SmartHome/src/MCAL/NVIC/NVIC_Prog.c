/*
 * NVIC_Prog.c
 *
 *  Created on: Jan 24, 2021
 *      Author:George Ayman
 *      Version: 01V
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "NVIC_Init.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

void NVIC_VidInit(void)
{
#define SCB_AIRCR				*((volatile u32*)(SCB_BASE_ADDRESS + 0x0C ))
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}

void NVIC_VidSetPriority (s8 Copy_S8PeripheralID , u8 Copy_U8GroupPriority , u8 Copy_U8SubPriority  )
{
	u8 Local_U8Priority = ( Copy_U8SubPriority | ( Copy_U8GroupPriority << ((NVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256)));
	// Check if Id is to Core Peripheral or External Peripheral
	if (Copy_S8PeripheralID >= 0 && Copy_S8PeripheralID < 60 ) //External Peripheral
	{
		NVIC_IPR[Copy_S8PeripheralID]=( Local_U8Priority << 4 );
	}
}
void NVIC_VidEnablePeripheralInterrupt(u8 Copy_U8IntNumber)
{
	if(Copy_U8IntNumber <= 31)
	{
		NVIC_ISER0 = (1<<Copy_U8IntNumber );
	}
	else if( Copy_U8IntNumber <60)
	{
		Copy_U8IntNumber-=32;
		NVIC_ISER1 = (1<<Copy_U8IntNumber );
	}
}


void NVIC_VidDisablePeripheralInterrupt(u8 Copy_U8IntNumber)
{
	if(Copy_U8IntNumber <= 31)
	{
		NVIC_ICER0 = (1<<Copy_U8IntNumber );
	}
	else if( Copy_U8IntNumber <60)
	{
		Copy_U8IntNumber-=32;
		NVIC_ICER1 = (1<<Copy_U8IntNumber );
	}
}


void NVIC_VidSetPendingFlag (u8 Copy_U8IntNumber)
{
	if(Copy_U8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1<<Copy_U8IntNumber );
	}
	else if( Copy_U8IntNumber <60)
	{
		Copy_U8IntNumber-=32;
		NVIC_ISPR1 = (1<<Copy_U8IntNumber );
	}
}


void NVIC_VidClearPendingFlag (u8 Copy_U8IntNumber)
{
	if(Copy_U8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1<<Copy_U8IntNumber );
	}
	else if( Copy_U8IntNumber <60)
	{
		Copy_U8IntNumber-=32;
		NVIC_ICPR0 = (1<<Copy_U8IntNumber );
	}
}

u8 NVIC_U8GetActiveFlag(u8 Copy_U8IntNumber)
{
	u8 Local_U8Result = 0;
	if(Copy_U8IntNumber <= 31)
	{
		Local_U8Result = GET_BIT(NVIC_IABR0	, Copy_U8IntNumber);
	}
	else if( Copy_U8IntNumber <60)
	{
		Copy_U8IntNumber-=32;
		Local_U8Result = GET_BIT(NVIC_IABR1	, Copy_U8IntNumber);
	}
	return Local_U8Result;
}

/*
void NVIC_VidSetPriority (s8 Copy_S8IntID , u8 Copy_U8GroupPriority , u8 Copy_U8SubPriority , u32 Copy_U32Group )
{
	u8 Local_U8Priority = ( Copy_U8SubPriority | ( Copy_U8GroupPriority << ((Copy_U32Group - 0x05FA0300)/256)));
	// Check if Id is to Core Peripheral or External Peripheral
	if (Copy_S8IntID >= 0) //External Peripheral
	{
		NVIC_IPR[Copy_S8IntID]=( Local_U8Priority << 4 );
	}
	SCB_AIRCR = Copy_U32Group ;
}
*/
