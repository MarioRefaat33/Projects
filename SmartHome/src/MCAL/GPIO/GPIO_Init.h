/*
 * GPIO_Init.h
 *
 *  Created on: Jan 19, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef GPIO_INIT_H_
#define GPIO_INIT_H_

#define GPIO_PORTA 	0
#define GPIO_PORTB 	1
#define GPIO_PORTC 	2


#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

#define GPIO_OUTPUT_SPEED_10M_PP			0b0001
#define GPIO_OUTPUT_SPEED_10M_OD			0b0101
#define GPIO_OUTPUT_SPEED_10M_AFPP			0b1001
#define GPIO_OUTPUT_SPEED_10M_AFOD			0b1101

#define GPIO_OUTPUT_SPEED_2M_PP				0b0010
#define GPIO_OUTPUT_SPEED_2M_OD				0b0110
#define GPIO_OUTPUT_SPEED_2M_AFPP			0b1010
#define GPIO_OUTPUT_SPEED_2M_AFOD			0b1110

#define GPIO_OUTPUT_SPEED_50M_PP			0b0011
#define GPIO_OUTPUT_SPEED_50M_OD			0b0111
#define GPIO_OUTPUT_SPEED_50M_AFPP			0b1011
#define GPIO_OUTPUT_SPEED_50M_AFOD			0b1111

#define GPIO_INPUT_ANLOG               		0b0000
#define GPIO_INPUT_FLOATING            	 	0b0100
#define GPIO_INPUT_PULLUP_PULLDOWN     		0b1000

#define GPIO_LOW	0
#define GPIO_HIGH	1

#define GPIO_POS_LOW	0
#define GPIO_POS_HIGH	1

void GPIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin , u8 Copy_U8Mode);

void GPIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin , u8 Copy_U8Value);

u8 GPIO_U8GetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin );

void GPIO_VidSetPortDirection( u8 Copy_U8Port , u8 Copy_U8Mode );

void GPIO_VidSetPortValue( u8 Copy_U8Port , u16 Copy_U8Value );

u16 GPIO_u16GetPortValue( u8 Copy_U8Port );

void GPIO_VidSetPinValueFaster(u8 Copy_U8Port, u8 Copy_U8Pin , u8 Copy_U8Value);

void GPIO_VidSetPin(u8 Copy_U8Port, u8 Copy_U8Pin);

void GPIO_VidClrPin(u8 Copy_U8Port, u8 Copy_U8Pin);

void GPIO_VidSetPortValueFaster(u8 Copy_U8Port, u8 Copy_U8Value);

void GPIO_VidClrPortPins(u8 Copy_U8Port, u8 Copy_U8Value);

void GPIO_VidSetPortPositionDirection( u8 Copy_U8Port , u8 Copy_U8Mode , u8 Copy_U8Position );

void GPIO_VidSetPortPositionValue( u8 Copy_U8Port , u16 Copy_U8Value , u8 Copy_U8Position );

void GPIO_VidSendLCD_8_bit(u8 Copy_U8Port , u8 *Ptr_Pins ,u8 Copy_U8Value);

void GPIO_VidSendLCD_4_bit(u8 Copy_U8Port , u8 *Ptr_Pins ,u8 Copy_U8Value);

#endif /* GPIO_INIT_H_ */
