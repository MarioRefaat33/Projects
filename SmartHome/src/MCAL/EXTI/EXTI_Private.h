/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 30/1/2021
 * VERION : V0.0
 * DISCRIPTION: MCAL_EXT_INTERRUPT_EXTI_PRIVATE_H_
 **************************************************/
#ifndef MCAL_EXT_INTERRUPT_EXTI_PRIVATE_H_
#define MCAL_EXT_INTERRUPT_EXTI_PRIVATE_H_

typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_Type;

/*base address of EXTI*/
#define EXTI ((volatile EXTI_Type *) 0x40010400)


#endif /* MCAL_EXT_INTERRUPT_EXTI_PRIVATE_H_ */
