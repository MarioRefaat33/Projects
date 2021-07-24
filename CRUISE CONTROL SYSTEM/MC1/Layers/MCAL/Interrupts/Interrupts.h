/*
 * header.h
 *
 *  Created on: Sep 4, 2020
 *      Author: Omar Ahmed
 */

#ifndef LAYERS_MCAL_INTERRUPTS_INTERRUPTS_H_
#define LAYERS_MCAL_INTERRUPTS_INTERRUPTS_H_

/*****    INTERRUPT REGISTERS    *****/
#define    MCU_CONTROL_REG                   MCUCR
#define    GENERAL_INTERRUPT_CONTROL_REG     GICR
#define    STATUS_REG						 SREG


/*****     GICR REGISTERS     *****/
#define    INTERRUPT_SW1                     6
#define    INTERRUPT_SW2                     7


/*****     MCUCR REGISTERS    *****/
#define    INTERRUPT_SENSE_CONTROL_0_BIT0    0
#define    INTERRUPT_SENSE_CONTROL_0_BIT1    1
#define    INTERRUPT_SENSE_CONTROL_1_BIT2    2
#define    INTERRUPT_SENSE_CONTROL_1_BIT3    3

/**** INTERRUPTS PROTOTYPES ****/
void INT0_Init(void);
void INT1_Init(void);

#define GIE 7	/* General Interrupt Enable bit */

#endif /* LAYERS_MCAL_INTERRUPTS_INTERRUPTS_H_ */
