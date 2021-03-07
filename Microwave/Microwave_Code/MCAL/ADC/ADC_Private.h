/*************************************************
* AUTHOR : Mario Refaat
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: ADC_Private.h
**************************************************/
#ifndef __ADC__PRIVATE__H
#define __ADC__PRIVATE__H


#define ADMUX		*((volatile u8*) 0x27)
#define ADCSRA		*((volatile u8*) 0x26)
#define ADCH		*((volatile u8*) 0x25)
#define ADCL		*((volatile u8*) 0x24)
#define ADC			*((volatile u16*) 0x24)


#endif
