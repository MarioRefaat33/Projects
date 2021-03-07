/*************************************************
 * AUTHOR : Moataz Tarek
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION:timer_Private.h
 **************************************************/
#ifndef timer_Private_H_
#define timer_Private__H_
#define TCNT0 		*((volatile u8*) 0x52)
#define TCCR0 		*((volatile u8*) 0x53)
#define TIMSK 		*((volatile u8*) 0x59)
#define OCR0 		*((volatile u8*) 0x5C)

/*ISR Prototype*/
void __vector_11(void) __attribute__((signal));  /*for timer overflow*/
void __vector_10(void) __attribute__((signal)); /*for compare mode*/

#endif
