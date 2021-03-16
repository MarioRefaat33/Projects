/*
 * ADC_Init.h
 *
 *  Created on: Feb 27, 2021
 *      Author:George Ayman
 */

#ifndef ADC_INIT_H_
#define ADC_INIT_H_

#define ADC_CHANNLE0		0
#define ADC_CHANNLE1		1
#define ADC_CHANNLE2		2
#define ADC_CHANNLE3		3
#define ADC_CHANNLE4		4
#define ADC_CHANNLE5		5
#define ADC_CHANNLE6		6
#define ADC_CHANNLE7		7
#define ADC_CHANNLE8		8
#define ADC_CHANNLE9		9
void ADC_VidInit(void);
u16 ADC_U16StartConversion(u8 Copy_U8Channle);


#endif /* ADC_INIT_H_ */
