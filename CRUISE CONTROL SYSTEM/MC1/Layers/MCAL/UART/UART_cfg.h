/*
 * UART_cfg.h
 *
 *  Created on: Sep 1, 2020
 *      Author: H
 */

#ifndef UART_DRIVER_UART_CFG_H_
#define UART_DRIVER_UART_CFG_H_

#define MODE ASYNCHRONOUS_NORMAL_MODE
#define FOSC 8000000
#define BAUDRATE 9600
#define DATA_BITS UART_8_DATA_BITS
#define PARITY UART_NO_PARITY
#define STOP_BITS UART_ONE_STOP_BIT
#define FLAG_ACTION UART_INTERRUPT

#ifndef ERROR
#define ERROR 1
#endif

#ifndef NO_ERROR
#define NO_ERROR 0
#endif

#ifndef BIT_NO_0
#define BIT_NO_0 0
#endif

#ifndef BIT_NO_1
#define BIT_NO_1 1
#endif

#ifndef BIT_NO_2
#define BIT_NO_2 2
#endif

#ifndef BIT_NO_3
#define BIT_NO_3 3
#endif

#ifndef BIT_NO_4
#define BIT_NO_4 4
#endif

#ifndef BIT_NO_5
#define BIT_NO_5 5
#endif

#ifndef BIT_NO_6
#define BIT_NO_6 6
#endif

#ifndef BIT_NO_7
#define BIT_NO_7 7
#endif

#endif /* UART_DRIVER_UART_CFG_H_ */
