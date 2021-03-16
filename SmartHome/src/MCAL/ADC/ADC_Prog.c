/*
 * ADC_Prog.c
 *
 *  Created on: Feb 27, 2021
 *      Author:George Ayman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../RCC/RCC_Init.h"
#include "../GPIO/GPIO_Init.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Init.h"

void ADC_VidInit(void)
{


	//ADC converter ON/OFF --> 1: Enable ADC and to start conversion
	SET_BIT(ADC->CR2,0); //ADON
#if INTERRUPT == ENABLE
	// Interrupt enable for EOC
	SET_BIT(ADC->CR1,5);
#endif
	//Data alignment -->0: Right Alignment
	CLR_BIT(ADC->CR2,11);
	//Select Channel 1 Sample time selection -- > 001: 7.5 cycles
	SET_BIT(ADC-> SMPR2 , 3);
	CLR_BIT(ADC-> SMPR2 , 4);
	CLR_BIT(ADC-> SMPR2 , 5);
	//External event select for regular group --> 111: SWSTART
	SET_BIT(ADC->CR2 ,17);
	SET_BIT(ADC->CR2 ,18);
	SET_BIT(ADC->CR2 ,19);
	//External trigger conversion mode for regular channels -- >
	//1: Conversion on external event enabled
	SET_BIT(ADC->CR2 , 20);
}

u16 ADC_U16StartConversion(u8 Copy_U8Channle)
{
	u16 Loc_Data;
	// Select Channle
	ADC->SQR1=0x00000000;
	ADC->SQR3=Copy_U8Channle;
	//CONT =0 --> For Single Conversion
	CLR_BIT(ADC->CR2,1);//CONT
	//Start Conversion -->Start conversion of regular channels
	SET_BIT(ADC->CR2,22);
	//Wait for End of Conversion
	while ( GET_BIT(ADC->SR , 1) == 0);
	Loc_Data=(ADC->DR & 0x00000FFF);
	return Loc_Data;
}
