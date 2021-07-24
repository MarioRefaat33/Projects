/*
 * AVR_Reg.h
 *
 *  Created on: Aug 30, 2020
 *      Author: H
 */

#ifndef DIO_DRIVER_AVR_REG_H_
#define DIO_DRIVER_AVR_REG_H_


/***		WRITE REGISTERS			***/
#define PORTA *((volatile uint8_t*) 0x3B)
#define PORTB *((volatile uint8_t*) 0x38)
#define PORTC *((volatile uint8_t*) 0x35)
#define PORTD *((volatile uint8_t*) 0x32)

/***		READ REGISTERS			***/
#define PINA *((volatile uint8_t*) 0x39)
#define PINB *((volatile uint8_t*) 0x36)
#define PINC *((volatile uint8_t*) 0x33)
#define PIND *((volatile uint8_t*) 0x30)

/***		DIRECTION REGISTERS		***/
#define DDRA *((volatile uint8_t*) 0x3A)
#define DDRB *((volatile uint8_t*) 0x37)
#define DDRC *((volatile uint8_t*) 0x34)
#define DDRD *((volatile uint8_t*) 0x31)

/***		INTERRUPT REGISTERS		***/
#define GICR *((volatile uint8_t*) 0x5B)
#define MCUCR *((volatile uint8_t*) 0x55)
#define SREG *((volatile uint8_t*) 0x5F)

/***		UART REGISTERS		***/
#define UBRRL 	*((volatile uint8_t*)(0x29))
#define UBRRH	*((volatile uint8_t*)(0x40))
#define UCSRA 	*((volatile uint8_t*)(0x2B))
#define UCSRB 	*((volatile uint8_t*)(0x2A))
#define UCSRC 	*((volatile uint8_t*)(0x40))
#define UDR 	*((volatile uint8_t*)(0x2C))


#endif /* DIO_DRIVER_AVR_REG_H_ */
