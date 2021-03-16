/*
 * NVIC_Init.h
 *
 *  Created on: Jan 24, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef NVIC_INIT_H_
#define NVIC_INIT_H_

#define GROUP3		0x05FA0300  // 4 bits for Group (IPR) => group
#define GROUP4		0x05FA0400	//3 bits for Group and 1 bit for sub group
#define GROUP5		0x05FA0500	//2 bits for Group and 2 bits for sub group
#define GROUP6		0x05FA0600	//1 bit for Group and 3 bits for sub group
#define GROUP7		0x05FA0700	//0 bit for Group and 4 bits for sub group

#define GROUP_1		1
#define SUB_GROUP_0	0

#define WWDG_ID					0
#define PVD_ID					1
#define TAMPERG_ID				2
#define RTC_ID					3
#define FLASH_ID				4
#define RCC_ID					5
#define EXTI0_ID				6
#define EXTI1_ID				7
#define EXTI2_ID				8
#define EXTI3_ID				9
#define EXTI4_ID				10
#define DMA1_Channel1_ID		11
#define DMA1_Channel2_ID		12
#define DMA1_Channel3_ID		13
#define DMA1_Channel4_ID		14
#define DMA1_Channel5_ID		15
#define DMA1_Channel6_ID		16
#define DMA1_Channel7_ID		17
#define ADC1_2_ID				18
#define USB_HP_CAN_TX_ID		19
#define USB_HP_CAN_RX0_ID		20
#define CAN_RX1_ID				21
#define CAN_SCE_ID				22
#define EXTI9_5_ID				23
#define TIM1_BRK_ID				24
#define TIM1_UP_ID				25
#define TIM1_TRG_COM_ID			26
#define TIM1_CC_ID				27
#define TIM2_ID					28
#define TIM3_ID					29
#define TIM4_ID					30
#define I2C1_EV_ID				31
#define I2C1_ER_ID				32
#define I2C2_EV					33
#define I2C2_ER					34
#define SPI1_ID					35
#define SPI2_ID					36
#define USART1_ID				37
#define USART2_ID				38
#define USART3_ID				39
#define EXTI15_10_ID			40
#define RTCAlarm_ID				41
#define USBWakeup_ID			42
#define TIM8_BRK_ID				43
#define TIM8_UP_ID				44
#define TIM8_TRG_COM_ID			45
#define TIM8_CC_ID				46
#define ADC3_ID					47
#define FSMC_ID					48
#define SDIO_ID					49
#define TIM5_ID					50
#define SPI3_ID					51
#define UART4_ID				52
#define UART5_ID				53
#define TIM6_ID					54
#define TIM7_ID					55
#define DMA2_Channel1_ID		56
#define DMA2_Channel2_ID		57
#define DMA3_Channel2_ID		58
#define DMA2_Channel4_5_ID		59



void NVIC_VidInit(void);

void NVIC_VidSetPriority (s8 Copy_S8PeripheralID , u8 Copy_U8GroupPriority , u8 Copy_U8SubPriority  );

void NVIC_VidEnablePeripheralInterrupt(u8 Copy_U8IntNumber);

void NVIC_VidDisablePeripheralInterrupt(u8 Copy_U8IntNumber);

void NVIC_VidSetPendingFlag (u8 Copy_U8IntNumber);

void NVIC_VidClearPendingFlag (u8 Copy_U8IntNumber);

u8 NVIC_U8GetActiveFlag(u8 Copy_U8IntNumber);

//void NVIC_VidSetPriority (s8 Copy_S8IntID , u8 Copy_U8GroupPriority , u8 Copy_U8SubPriority , u32 Copy_U32Group );


#endif /* NVIC_INIT_H_ */
