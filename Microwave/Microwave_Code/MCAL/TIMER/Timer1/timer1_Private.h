/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 18/12/2020
 * VERION : V0.0
 * DISCRIPTION: timer1_Private.h
 **************************************************/

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define TCCR1A 		*((volatile u8*) 0x4F)
#define TCCR1B 		*((volatile u8*) 0x4E)

#define TCNT1H		*((volatile u8*) 0x4D)
#define TCNT1L		*((volatile u8*) 0x4C)
#define TCNT1		*((volatile u16*)0x4C)

#define ICR1H 		*((volatile u8*) 0x47)
#define ICR1L	 	*((volatile u8*) 0x46)
#define ICR1	 	*((volatile u16*) 0x46)  /* For 2 bytes */

#define OCR1AH 		*((volatile u8*) 0x4B)
#define OCR1AL 		*((volatile u8*) 0x4A)
#define OCR1A 		*((volatile u16*) 0x4A)  /* For 2 bytes */


#define OCR1BH 		*((volatile u8*) 0x49)
#define OCR1BL 		*((volatile u8*) 0x48)
#define OCR1B 		*((volatile u16*) 0x48)  /* For 2 bytes */

#endif /* TIMER1_PRIVATE_H_ */
