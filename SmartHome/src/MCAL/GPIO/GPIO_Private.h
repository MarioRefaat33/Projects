/*
 * GPIO_Private.h
 *
 *  Created on: Jan 19, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO;


#define GPIOA ((volatile GPIO*)0x40010800)
#define GPIOB ((volatile GPIO*)0x40010C00)
#define GPIOC ((volatile GPIO*)0x40011000)

#endif /* GPIO_PRIVATE_H_ */
