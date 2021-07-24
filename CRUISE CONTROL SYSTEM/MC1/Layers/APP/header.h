/*
 * header.h
 *
 *  Created on: Sep 4, 2020
 *      Author: Omar Ahmed
 */

#ifndef MC_1_H_
#define MC_1_H_


/*****    DUTY CYCLES LIMITATIONS    *****/
#define    	MAXIMUM_CYCLE    		100
#define    	MINIMUM_CYCLE     		0
#define   	TOTAL_CYCLES      		11
#define   	INITIAL_CYCLE 			50

/*****    ISR FUNCTIONS ATTRIBUTES    *****/
#define ISR_INT0 __vector_1
#define ISR_INT1 __vector_2
void __vector_1 (void) __attribute__ ((signal,used, externally_visible));
void __vector_2 (void) __attribute__ ((signal,used, externally_visible));

/*****    DELAY LIMITATIONS    *****/
#define BEGIN_DELAY 0
#define END_DELAY 150


#endif /* MC_1_H_ */
