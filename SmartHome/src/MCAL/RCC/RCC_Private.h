/*
 * RCC_Private.h
 *
 *  Created on: Jan 17, 2021
 *      Author:George Ayman
 *      Version: 01V
 */


#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_



typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_ST;
#define RCC ((volatile RCC_ST*)0x40021000)

/*
#define RCC_BASE_ADD 	(0x40021000)

#define RCC_CR			*((volatile u32*) (RCC_BASE_ADD +0x00))
#define RCC_CFGR		*((volatile u32*) (RCC_BASE_ADD +0x04))
#define RCC_CIR			*((volatile u32*) (RCC_BASE_ADD +0x08))
#define RCC_APB2RSTR	*((volatile u32*) (RCC_BASE_ADD +0x0C))
#define RCC_APB1RSTR	*((volatile u32*) (RCC_BASE_ADD +0x10))
#define RCC_AHBENR		*((volatile u32*) (RCC_BASE_ADD +0x14))
#define RCC_APB2ENR		*((volatile u32*) (RCC_BASE_ADD +0x18))
#define RCC_APB1ENR		*((volatile u32*) (RCC_BASE_ADD +0x1c))
#define RCC_BDCR		*((volatile u32*) (RCC_BASE_ADD +0x20))
#define RCC_CSR			*((volatile u32*) (RCC_BASE_ADD +0x24))
*/
#define RCC_HSE_CRYSTAL		0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3

#define RCC_HSE				0
#define RCC_HSE_DIV_2		1
#define RCC_HSI_DIV_2		2


#define RCC_PLL_MULTIPLE_2   1
#define RCC_PLL_MULTIPLE_3   2
#define RCC_PLL_MULTIPLE_4   3
#define RCC_PLL_MULTIPLE_5   4
#define RCC_PLL_MULTIPLE_6   5
#define RCC_PLL_MULTIPLE_7   6
#define RCC_PLL_MULTIPLE_8   7
#define RCC_PLL_MULTIPLE_9   8
#define RCC_PLL_MULTIPLE_10  9
#define RCC_PLL_MULTIPLE_11  10
#define RCC_PLL_MULTIPLE_12  11
#define RCC_PLL_MULTIPLE_13  12
#define RCC_PLL_MULTIPLE_14  13
#define RCC_PLL_MULTIPLE_15  14
#define RCC_PLL_MULTIPLE_16  15

#define DISABLE_CLOCK_SECURITY_SYSTEM   0
#define ENABLE_CLOCK_SECURITY_SYSTEM	1




#endif /* RCC_PRIVATE_H_ */
