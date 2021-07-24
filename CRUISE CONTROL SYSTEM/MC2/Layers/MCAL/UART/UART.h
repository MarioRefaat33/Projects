/*
 * UART.h
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */

#ifndef UART_DRIVER_UART_H_
#define UART_DRIVER_UART_H_

#define ASYNCHRONOUS_NORMAL_MODE 0
#define ASYNCHRONOUS_DOUBLE_SPEED_MODE 1
#define SYNCHRONOUS_MASTER_MODE 2


/*- FUNCTION-LIKE MACROS -----------------------------------*/
#define DISABLE       					0U
#define ENABLE        					1U

#define UART_ONE_STOP_BIT  				0U
#define UART_TWO_STOP_BITS 				1U


#define UART_POLLING 					0U
#define UART_INTERRUPT 					1U


#define UART_FLAG_ACTION 				4U
#define UART_ALL_INTERRUPT_DISABLED 	5U

#define UART_PARITY_EVEN 				0U
#define UART_PARITY_ODD 				1U
#define UART_NO_PARITY 					2U

#define UART_5_BIT_MODE 				0
#define UART_6_BIT_MODE 				1
#define UART_7_BIT_MODE 				2
#define UART_8_BIT_MODE 				3
#define UART_9_BIT_MODE 				7

#define UART_5_DATA_BITS 				5
#define UART_6_DATA_BITS 				6
#define UART_7_DATA_BITS 				7
#define UART_8_DATA_BITS 				8
#define UART_9_DATA_BITS 				9


/*- FUNCTION DECLARATIONS ----------------------------------*/
/*************************************************************
*Description: Initialization of Uart Module
* Input     : nothing
* Output    : Error Status
* */
extern uint8_t UART_init(void);

/*************************************************************
*Description: Sending byte of data
* Input     : u16Data to send
* Output    : Error Status
* */
extern uint8_t UART_sendByte( uint8_t u8_Data);

/*************************************************************
*Description: Receiving byte of data
* Input     : pointer to u16Data
* Output    : Error Status
* */
extern uint8_t UART_recieveByte(uint8_t *u8_Data);


/*************************************************************
*Description: Receiving Flag used in Case of Polling
* Input     : pointer to u8Data
* Output    : No Return
* */
extern uint8_t UART_GetPollingFlag(uint8_t *u8_Data);

/*************************************************************
*Description: Call Back for function to send to ISR
* Input     : pointer to function
* Output    : ERROR Status
* */
extern uint8_t UART_TX_SetCallBack(void (*Copy_FunctionAddress)(void));
/*
*Description: Call Back for function to Receive Data
* Input     : pointer to function
* Output    : ERROR Status
* */
extern uint8_t UART_RX_SetCallBack(void (*Copy_FunctionAddress)(void));

#endif /* UART_DRIVER_UART_H_ */
