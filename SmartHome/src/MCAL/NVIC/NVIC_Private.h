/*
 * NVIC_Private.h
 *
 *  Created on: Jan 24, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_GROUP4_SUB_0		0x05FA0300
#define NVIC_GROUP3_SUB_1		0x05FA0400
#define NVIC_GROUP2_SUB_2		0x05FA0500
#define NVIC_GROUP1_SUB_3		0x05FA0600
#define NVIC_GROUP0_SUB_4		0x05FA0700

#define NVIC_BASE_ADDRESS		0xE000E100



#define NVIC_ISER0			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x000 ))
#define NVIC_ISER1			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x004 ))
#define NVIC_ISER2			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x008 ))

#define NVIC_ICER0			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x080 ))
#define NVIC_ICER1			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x084 ))
#define NVIC_ICER2			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x088 ))

#define NVIC_ISPR0			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x100 ))
#define NVIC_ISPR1			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x104 ))
#define NVIC_ISPR2			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x108 ))

#define NVIC_ICPR0			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x184 ))
#define NVIC_ICPR2			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x188 ))

#define NVIC_IABR0			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x200 ))
#define NVIC_IABR1			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x204 ))
#define NVIC_IABR2			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x208 ))

#define NVIC_IPR 			  ((volatile u8*)(NVIC_BASE_ADDRESS + 0x300 ))

//#define NVIC_IPR20			*((volatile u32*)(NVIC_BASE_ADDRESS + 0x320 ))

/*
typedef struct{
	volatile u32 IPR[20];
}NVIC_IPR;

#define NVIC ((volatile NVIC_IPR*)(NVIC_BASE_ADDRESS + 0x300 ))
*/


#define NVIC_STIR			*((volatile u32*)(NVIC_BASE_ADDRESS + 0xE00 ))

#define SCB_BASE_ADDRESS		0xE000ED00

#endif /* NVIC_PRIVATE_H_ */
