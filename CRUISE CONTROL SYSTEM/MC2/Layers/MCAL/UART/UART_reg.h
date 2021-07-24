#ifndef _UART_REG_H_
#define _UART_REG_H_


#define UBRRL 	*((volatile uint8_t*)(0x29))

#define UBRRH	*((volatile uint8_t*)(0x40))

#define UCSRA 	*((volatile uint8_t*)(0x2B))

#define UCSRB 	*((volatile uint8_t*)(0x2A))

#define UCSRC 	*((volatile uint8_t*)(0x40))

#define UDR 	*((volatile uint8_t*)(0x2C))


#endif
