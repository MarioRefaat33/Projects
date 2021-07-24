/*
 * header.h
 *
 *  Created on: Sep 4, 2020
 *      Author: Omar Ahmed
 */

/***	LIBRARY LAYER	***/
#include "../../LIB/AVR_Reg.h"
#include "../../LIB/STD_TYPES.h"

/***	MICROCONTROLLER ABSTRACTION LAYER	***/
#include "Interrupts.h"

/*** EXTERNAL INTERRUPT 0 INITIALIZATION ***/
void INT0_Init(void)
{
	GENERAL_INTERRUPT_CONTROL_REG |= (1<<INTERRUPT_SW1);
	MCU_CONTROL_REG               |= (1<<INTERRUPT_SENSE_CONTROL_0_BIT1); //falling edge
	STATUS_REG |= (1<<GIE);
}

/*** EXTERNAL INTERRUPT 1 INITIALIZATION ***/
void INT1_Init(void)
{
	GENERAL_INTERRUPT_CONTROL_REG |= (1<<INTERRUPT_SW2);
	MCU_CONTROL_REG               |= (1<<INTERRUPT_SENSE_CONTROL_1_BIT3); //falling edge
	STATUS_REG |= (1<<GIE);
}

