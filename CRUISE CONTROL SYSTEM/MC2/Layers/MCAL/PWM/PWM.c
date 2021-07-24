/*
 * PWM0.c
 *
 *      Author: Aya
 */
/*** LIBRARY LAYER ***/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/AVR_Reg.h"

/*** MICROCONTROLLER ABSTRACTION LAYER ***/
#include "PWM.h"


void PWM0_init(void)
{
#if    PWM_CHANNEL == TIMER0

	TCCR0 =(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01)|(1<<CS00);     //fast PWM, prescaling = 64
	TCNT0 = 0;
	OCR0  = 0;
	DDRB |=(1<<3);

#elif  PWM_CHANNEL == TIMER1

	TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);          //fast PWM 8-bits
	TCCR1B = (1<<WGM12 )|( 1<<CS10 );                     //No prescaling
	TCNT1  = 0;
	OCR1A  = 0;
	OCR1B  = 0;
	DDRB  |=(1<<PB3);

#elif  PWM_CHANNEL == TIMER2

	TCCR2 =(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS20);     //fast PWM, NO prescaling
	TCNT2 = 0;
	OCR2  = 0;
	DDRB |=(1<<PB3);

#else

#error ("Invalid Timer Channel");

#endif
}

void PWM0_DutyCycle(unsigned char DutyCycle)
{
	DutyCycle = ( (float)DutyCycle / 100 ) * 255;

#if    PWM_CHANNEL == TIMER0

	OCR0 = DutyCycle;

#elif  PWM_CHANNEL == TIMER1

	OCR1A = DutyCycle;
	OCR1B = DutyCycle;

#elif  PWM_CHANNEL == TIMER2

	OCR2 = DutyCycle;

#else

#error ("Invalid Timer Channel");

#endif


}
