/*
 * header.h
 *
 *  Created on: Sep 6, 2020
 *      Author: Omar Ahmed
 */

#ifndef LAYERS_APP_HEADER_H_
#define LAYERS_APP_HEADER_H_


/*****    DUTY CYCLES LIMITATIONS    *****/
#define MINIMUM_DUTY_CYCLE	0
#define MAXIMUM_DUTY_CYCLE	100

/*****    ISR FUNCTION ATTRIBUTE   *****/
#define ISR_UART_RXC __vector_13
void __vector_13 (void) __attribute__ ((signal,used, externally_visible));

/*****    FLAGS    *****/
#define SET_FLAG 1
#define RESET_FLAG 0


#endif /* LAYERS_APP_HEADER_H_ */
