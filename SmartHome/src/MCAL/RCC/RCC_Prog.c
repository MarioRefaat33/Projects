/*
 * RCC_Prog.c
 *
 *  Created on: Jan 17, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "RCC_Init.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


void RCC_VidInit(void)
{
	u32 TimeOut_Count = 0; // counter to count the Time out of clock to be stable
	/* Selects System Clock */
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC->CR  =0x00010000;
	RCC->CFGR=0x00000001;
	/*Polling with Time Out */
	while(((GET_BIT(RCC->CR,17))==0) && (TimeOut_Count<10000))
	{
		TimeOut_Count++;
	}
	if(TimeOut_Count >= 10000)
	//{ /*TimeOut*/ }
#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC->CR  =0x00050080;
	RCC->CFGR=0x00000001;
	/*Polling with Time Out */
	while(((GET_BIT(RCC->CR ,17))==0) && (TimeOut_Count<10000))
	{
		TimeOut_Count++;
	}
	if(TimeOut_Count >= 10000)
	{ /*TimeOut*/ }

#elif RCC_CLOCK_TYPE == RCC_HSI
	RCC->CR  =0x00000081;
	RCC->CFGR=0x00000000;
	/*Polling with Time Out */
	while(((GET_BIT(RCC->CR ,1))==0) && (TimeOut_Count<10000))
	{
		TimeOut_Count++;
	}
	if(TimeOut_Count >= 10000)
	{ /*TimeOut*/ }


#elif  RCC_CLOCK_TYPE == RCC_PLL

#if RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_2
	CLR_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_3
	SET_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_4
	CLR_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_5
	SET_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_6
	CLR_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_7
	SET_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_8
	CLR_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_9
	SET_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	CLR_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_10
	CLR_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_11
	SET_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_12
	CLR_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_13
	SET_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	CLR_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_14
	CLR_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_15
	SET_BIT(RCC->CFGR,18);
	CLR_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#elif RCC_PLL_MULTIBLE == RCC_PLL_MULTIPLE_16
	CLR_BIT(RCC->CFGR,18);
	SET_BIT(RCC->CFGR,19);
	SET_BIT(RCC->CFGR,20);
	SET_BIT(RCC->CFGR,21);
#else ("Wrong Choice of RCC PLL MULTIBLE Type")
#endif

#if RCC_PLL_SRS == RCC_HSE
	/* Selects System Clock to HSE */
	SET_BIT(RCC->CR,16);
	/* Seleccts PLL Clock */
	SET_BIT(RCC->CFGR,16);
#elif RCC_PLL_SRS == RCC_HSE_DIV_2
	/* Selects System Clock to HSE */
	SET_BIT(RCC->CR,16);
	/* Seleccts PLL Clock */
	SET_BIT(RCC->CFGR,16);
	/* Selects HSE/2 */
	SET_BIT(RCC->CFGR,7);
#elif RCC_PLL_SRS == RCC_HSI_DIV_2
	/* Selects HSI/2 */
	CLR_BIT(RCC->CFGR,16);
#else
#error ("Wrong Choice of RCC PLL Source Type")
#endif

	SET_BIT(RCC->CFGR,1);
	SET_BIT(RCC->CR,24);

	/*Polling with Time Out */
	while(((GET_BIT(RCC->CR ,25))==0) && (TimeOut_Count<10000))
	{
		TimeOut_Count++;
	}
	if(TimeOut_Count >= 10000)
	{ /*TimeOut*/ }
#else
#error	("Wrong Choice of RCC Clock Type")
#endif
	/* For Clock Security System */
#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM
	SET_BIT(RCC->CR,19);
#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM
	CLR_BIT(RCC->CR,19);
#else
#error " Wrong Clock Security System Configuration Choice "
#endif

}
void RCC_VidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	/*Enable RCC For Peripheral = Enable Peripheral Clock */
	/*Range Check */
	if ( (Copy_u8PeripheralID <32) )
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB   : SET_BIT(RCC->AHBENR,Copy_u8PeripheralID); break;
		case RCC_APB1  : SET_BIT(RCC->APB1ENR,Copy_u8PeripheralID);break;
		case RCC_APB2  : SET_BIT(RCC->APB2ENR,Copy_u8PeripheralID);break;
		}
	}
	else
	{
		/*Return Error */
	}
}
void RCC_VidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	/*Disable RCC For Peripheral = Disable Peripheral Clock */
	/*Range Check */
	if ( (Copy_u8PeripheralID <32) )
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB   : CLR_BIT(RCC->AHBENR,Copy_u8PeripheralID); break;
		case RCC_APB1  : CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralID);break;
		case RCC_APB2  : CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralID);break;
		}
	}
	else
	{
		/*Return Error */
	}
}


