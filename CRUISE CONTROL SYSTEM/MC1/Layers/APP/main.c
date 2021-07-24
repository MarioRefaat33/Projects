/*
 * main.c
 *
 *  Created on: Sep 4, 2020
 *      Author: Omar Ahmed
 */

/***	LIBRARY LAYER	***/
#include "../LIB/STD_TYPES.h"

/*** APPLICATION LAYER ***/
#include "header.h"

/***	MICROCONTROLLER ABSTRACTION LAYER	***/
#include "../MCAL/UART/UART.h"
#include "../MCAL/Interrupts/Interrupts.h"


/*** Array of Duty Cycles ***/
const uint8_t cyclesArr[TOTAL_CYCLES] = {0,10,20,30,40,50,60,70,80,90,100};

/*** Pointer to a Duty Cycle ***/
const uint8_t *cyclePointer = cyclesArr + INITIAL_CYCLE / 10;

/**************************************************************/
/* 	ISR function that increments the cyclePointer (UP TO 100) */
/*  then send *cyclePointer using UART			              */
/**************************************************************/
void ISR_INT0 (void)
{
	if( *cyclePointer < MAXIMUM_CYCLE )
	{
		++cyclePointer;
		UART_sendByte(*cyclePointer);
	}
}
/*************************************************************/


/**************************************************************/
/* 	ISR function that decrements the cyclePointer (DOWN TO 0) */
/*  then send *cyclePointer using UART			              */
/**************************************************************/
void ISR_INT1 (void)
{
	if( *cyclePointer > MINIMUM_CYCLE )
	{
		--cyclePointer;
		UART_sendByte(*cyclePointer);
	}
}
/*************************************************************/


sint32_t main(void)
{
	/********   UART INITIALIZATION  		********/
	UART_init();
	/********   INTERRUPTS INITIALIZATION  	********/
	INT0_Init();
	INT1_Init();

	/*Short delay to ensure all configurations are set on both microcontrollers */
	for (uint8_t delay = BEGIN_DELAY; delay < END_DELAY; delay++);

	/* Send initial duty cycle */
	UART_sendByte(*cyclePointer);

	while (1)
	{

	}

	return 0;
}
