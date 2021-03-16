/*
 * KYPD_Prog.c
 *
 *  Created on: Feb 27, 2021
 *      Author:George Ayman
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_Init.h"
#include "../../MCAL/SYSTICK/SysTick_Init.h"
#include "KYPD_Config.h"
#include "KYPD_Private.h"
#include "KYPD_Init.h"

#if ROW_NUM == 4
const u8 Loc_U8RowPins[ROW_NUM]={ROW1_PIN,ROW2_PIN,ROW3_PIN,ROW4_PIN};
#elif ROW_NUM == 3
const u8 Loc_U8RowPins[ROW_NUM]={ROW1_PIN,ROW2_PIN,ROW3_PIN};
#endif

#if COL_NUM == 4
const u8 Loc_U8ColPins[COL_NUM]={COL1_PIN,COL2_PIN,COL3_PIN,COL4_PIN};
#elif COL_NUM == 3
const u8 Loc_U8ColPins[COL_NUM]={COL1_PIN,COL2_PIN,COL3_PIN};
#endif

u8 KYP_U8GetButton(void)
{
	u8 buttonValue=0;
	u8 col=0;
	u8 row=0;
	for(col=0;col<COL_NUM;col++)
	{
		GPIO_VidSetPinValue(COL_PORT,Loc_U8ColPins[col],GPIO_LOW);
		for(row=0;row<ROW_NUM;row++)
		{
			if(GPIO_U8GetPinValue(ROW_PORT,Loc_U8RowPins[row])==0)
			{
				while(GPIO_U8GetPinValue(ROW_PORT,Loc_U8RowPins[row])==0);
				buttonValue=((row*COL_NUM)+col+1);
			}
		}
		GPIO_VidSetPinValue(COL_PORT,Loc_U8ColPins[col],GPIO_HIGH);
		_delay_ms(10);
	}
	return buttonValue;
}
void KYP_VoidInit(void)
{
	GPIO_VidSetPinDirection(COL_PORT,COL1_PIN,GPIO_OUTPUT_SPEED_2M_PP);
		GPIO_VidSetPinDirection(COL_PORT,COL2_PIN,GPIO_OUTPUT_SPEED_2M_PP);
		GPIO_VidSetPinDirection(COL_PORT,COL3_PIN,GPIO_OUTPUT_SPEED_2M_PP);
	#if COL_NUM == 4
		GPIO_VidSetPinDirection(COL_PORT,COL4_PIN,GPIO_OUTPUT_SPEED_2M_PP);
	#endif
		//Make all Col HIGH
		GPIO_VidSetPinValue(COL_PORT,COL1_PIN,GPIO_HIGH);
		GPIO_VidSetPinValue(COL_PORT,COL2_PIN,GPIO_HIGH);
		GPIO_VidSetPinValue(COL_PORT,COL3_PIN,GPIO_HIGH);
	#if COL_NUM == 4
		GPIO_VidSetPinValue(COL_PORT,COL4_PIN,GPIO_HIGH);
	#endif

		//Make all Row  Input
		GPIO_VidSetPinDirection(ROW_PORT,ROW1_PIN,GPIO_INPUT_PULLUP_PULLDOWN);
		GPIO_VidSetPinDirection(ROW_PORT,ROW2_PIN,GPIO_INPUT_PULLUP_PULLDOWN);
		GPIO_VidSetPinDirection(ROW_PORT,ROW3_PIN,GPIO_INPUT_PULLUP_PULLDOWN);
	#if Row_NUM == 4
		GPIO_VidSetPinDirection(ROW_PORT,ROW4_PIN,GPIO_INPUT_PULLUP_PULLDOWN);
	#endif

		//Make All Rows Pull Up
		GPIO_VidSetPinValue(ROW_PORT,ROW1_PIN,GPIO_HIGH);
		GPIO_VidSetPinValue(ROW_PORT,ROW2_PIN,GPIO_HIGH);
		GPIO_VidSetPinValue(ROW_PORT,ROW3_PIN,GPIO_HIGH);
	#if Row_NUM == 4
		GPIO_VidSetPinValue(ROW_PORT,ROW4_PIN,GPIO_HIGH);
	#endif
}

