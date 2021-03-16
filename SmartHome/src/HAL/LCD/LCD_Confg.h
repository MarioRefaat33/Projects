/************************************************************/  
/* 	LCD_Config.h	                                        */
/*                                                          */
/*  Created on	: Jan 26, 2021                              */
/*  Author		: Abanoub Raouf                             */
/*	version		: version 2                                 */
/*	LCD_version	: LMB161A									*/
/************************************************************/    

#ifndef _LCD_Config_H_
#define _LCD_Config_H_


#define Four_bit	 	4
#define Eight_bit		8
#define mode		Four_bit




#if (mode==8)


#define Data_Port_PIN0					GPIO_PORTA
#define Data_Port_PIN1					GPIO_PORTA
#define Data_Port_PIN2					GPIO_PORTA
#define Data_Port_PIN3					GPIO_PORTA
#define Data_Port_PIN4					GPIO_PORTA
#define Data_Port_PIN5					GPIO_PORTA
#define Data_Port_PIN6					GPIO_PORTA
#define Data_Port_PIN7					GPIO_PORTA


#define D0							GPIO_PIN0
#define D1                          GPIO_PIN1
#define D2                          GPIO_PIN2
#define D3                          GPIO_PIN3
#define D4                          GPIO_PIN4
#define D5                          GPIO_PIN5
#define D6                          GPIO_PIN6
#define D7                          GPIO_PIN7

#define Control_Port_RS				GPIO_PORTC
#define Control_Port_RW				GPIO_PORTC
#define Control_Port_E				GPIO_PORTC

#define RS 							GPIO_PIN13
#define RW 							GPIO_PIN14
#define E 							GPIO_PIN15


#elif (mode==4)

#define Data_Port_PIN4 				GPIO_PORTB
#define Data_Port_PIN5              GPIO_PORTB
#define Data_Port_PIN6              GPIO_PORTB
#define Data_Port_PIN7              GPIO_PORTB
#define D4							GPIO_PIN12
#define D5                          GPIO_PIN13
#define D6                          GPIO_PIN14
#define D7                          GPIO_PIN15

#define Control_Port_RS				GPIO_PORTB
#define Control_Port_RW				GPIO_PORTB
#define Control_Port_E				GPIO_PORTB

#define RS 							GPIO_PIN9
#define RW 							GPIO_PIN10
#define E 							GPIO_PIN11

#endif



#endif
