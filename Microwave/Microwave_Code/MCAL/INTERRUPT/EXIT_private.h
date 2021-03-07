#ifndef _EXIT_REGISTER_H
#define _EXIT_REGISTER_H

#define MCUCR  *((u8*)0x55)
#define GICR   *((u8*)0x5B)
#define SREG   *((u8*)0x5F)
#define MCUCSR *((u8*) 0x54)

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#endif
