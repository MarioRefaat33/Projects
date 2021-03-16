/*
 * ADC_Private.h
 *
 *  Created on: Feb 27, 2021
 *      Author:George Ayman
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define DISABLE	0
#define ENABLE	1

typedef struct{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR1;
	volatile u32 SMPR2;
	volatile u32 JOFR1;
	volatile u32 JOFR2;
	volatile u32 JOFR3;
	volatile u32 JOFR4;
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR1;
	volatile u32 SQR2;
	volatile u32 SQR3;
	volatile u32 JSQR;
	volatile u32 JDR1;
	volatile u32 JDR2;
	volatile u32 JDR3;
	volatile u32 JDR4;
	volatile u32 DR;
}ADC_St;

#define ADC  ((volatile ADC_St*)0x40012400)

#endif /* ADC_PRIVATE_H_ */
