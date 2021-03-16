 /*************************************************
* AUTHOR : Amira Moustafa
* Date   : 30/1/2021
* VERION : V0.0
* DISCRIPTION:  MCAL_EXT_INTERRUPT_EXTI_INGTERFACE_H_
**************************************************/
#ifndef MCAL_EXT_INTERRUPT_EXTI_INTERFACE_H_
#define MCAL_EXT_INTERRUPT_EXTI_INTERFACE_H_

/*external interrupt modes*/
#define RISING_EDGE  0
#define FALLING_EDGE 1
#define ON_CHANGE    2

/*port options*/
#define PORTA 0
#define PORTB 1
#define PORTC 2

/*EXTERNAL INTERRUPT LINES*/
#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3

#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7

#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11

#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15


/*external interrupt numbers */
#define EXTI0IRQn     6
#define EXTI1IRQn     7
#define EXTI2IRQn     8
#define EXTI3IRQn     9
#define EXTI4IRQn     10

#define EXTI5IRQn     23
#define EXTI6IRQn     23
#define EXTI7IRQn     23
#define EXTI8IRQn     23
#define EXTI9IRQn     23

#define EXTI10IRQn    40
#define EXTI11IRQn    40
#define EXTI12IRQn    40
#define EXTI13IRQn    40
#define EXTI14IRQn    40
#define EXTI15IRQn    40

/*function prototype*/
void EXTI_voidInit(u8 copy_u8EXTILine , u8 copy_u8EXTIMode);
void EXTI_voidEnable(u8 copy_u8EXTILine);
void EXTI_voidDisable(u8 copy_u8EXTILine);
void EXTI_voidSoftwareTrigger(u8 copy_u8EXTILine);
void EXTI_voidSetCallBack(void (*ptr) (void));
void EXTI1_voidSetCallBack(void (*ptr) (void));
void EXTI0_voidSetCallBack(void (*ptr) (void));
#endif /* MCAL_EXT_INTERRUPT_EXTI_INTERFACE_H_ */
