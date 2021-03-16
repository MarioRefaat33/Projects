/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 25/1/2020
* VERION : V0.0
* DISCRIPTION: NVIC_Interface.h
**************************************************/

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

/*************************************
 *      OPTIONS:
 *************************************/

/*************************************
 *  PERIPHERAL_INTERRUPTS PRIORITY
 *************************************/
#define PEND_SV            -6
#define SYSTICK            -5
#define SV_CALL            -4
#define MEMORY_MANAGE      -3
#define BUS_FAULT          -2
#define USAGE_FAULT        -1
#define WWDG				0
#define PVD					1
#define TAMPER				2
#define RTC					3
#define FLASH				4
#define RCCINT				5
#define EXTI_0				6
#define EXTI_1				7
#define EXTI_2				8
#define EXTI_3				9
#define EXTI_4				10
#define DMA1_CHANNEL1		11
#define DMA1_CHANNEL2		12
#define DMA1_CHANNEL3		13
#define DMA1_CHANNEL4		14
#define DMA1_CHANNEL5		15
#define DMA1_CHANNEL6		16
#define DMA1_CHANNEL7		17
#define ADC1_2				18
#define USB_HP_CAN_TX		19
#define USB_LP_CAN_RX0		20
#define CAN_RX1				21
#define CAN_SCE				22
#define EXTI9_5				23
#define TIM1_BRK			24
#define TIM1_UP				25
#define TIM1_TRG_COM		26
#define TIM1_CC				27
#define TIM2				28
#define TIM3				29
#define TIM4				30
#define I2C1_EV				31
#define I2C1_ER				32
#define I2C2_EV				33
#define I2C2_ER				34
#define SPI1				35
#define SPI2				36
#define USART1				37
#define USART2				38
#define USART3				39
#define EXTI15_10			40
#define RTCALARM			41
#define USBWAKEUP			42
#define TIM8_BRK			43
#define TIM8_UP				44
#define TIM8_TRG_COM		45
#define TIM8_CC				46
#define ADC3				47
#define FSMC				48
#define SDIO				49
#define TIM5				50
#define SPI3				51
#define UART4				52
#define UART5				53
#define TIM6				54
#define TIM7				55
#define DMA2_CHANNEL1		56
#define DMA2_CHANNEL2		57
#define DMA2_CHANNEL3		58
#define DMA2_CHANNEL4_5		59

/*************************************
 *     PRIORITY_GROUPING
 *************************************/
#define  MNVIC_GROUP4_SUB0  0x05FA0300
#define  MNVIC_GROUP3_SUB1  0x05FA0400
#define  MNVIC_GROUP2_SUB2  0x05FA0500
#define  MNVIC_GROUP1_SUB3  0x05FA0600
#define  MNVIC_GROUP0_SUB4  0x05FA0700

/*******************************
 *OPTIONS :
 *GROUPS FROM 0: 16
 *SUP_GROUP FROM 0:16
 *******************************/
#define GROUP_0   0
#define GROUP_1   1
#define SUB_GROUP_0 0

/*  FUNCTION PROTOTYPE */
void MNVIC_voidInit(void);
void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber);
u8   MNVIC_voidGetActiveFlag(u8 copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 copy_u8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u32 copy_u8group);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
