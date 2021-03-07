/*************************************************
* AUTHOR : Mario Refaat
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: ADC_Program
**************************************************/
#include"../../LIB/STD_Type.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../MCAL/ADC/ADC_Private.h"
#include"../../MCAL/ADC/ADC_Interface.h"
#include"../../MCAL/ADC/ADC_Config.h"

void ADC_VoidInit(void)
{

#if ADC_VREF == INTERNAL_OFF
	CLEAR_BIT( ADMUX , 6 ) ;  /*REFS0*/
	CLEAR_BIT( ADMUX , 7 ) ;  /*REFS1*/

#elif ADC_VREF == EXTERNAL_AVCC
	SET_BIT( ADMUX , 6 ) ;   /*REFS0*/
	CLEAR_BIT( ADMUX , 7 ) ; /*REFS1*/

#elif ADC_VREF == RESERVED
	CLEAR_BIT( ADMUX , 6 ) ; /*REFS0*/
	SET_BIT( ADMUX , 7 ) ;   /*REFS1*/

#elif ADC_VREF == INTERNAL_VOLTAGE
	SET_BIT( ADMUX , 6 ) ;   /*REFS0*/
	SET_BIT( ADMUX , 7 ) ;   /*REFS1*/

#endif


#if ADC_ADJ	== RIGHT_ADJ
	CLEAR_BIT( ADMUX , 5 ) ; /*ADLAR*/

#elif ADC_ADJ == LEFT_ADJ
	SET_BIT( ADMUX , 5 ) ;

#endif


#if ADC_PRESCALER == PRESCALER_2
	SET_BIT(ADCSRA, 0);
	CLEAR_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,2);

#elif ADC_PRESCALER == PRESCALER_4
	CLEAR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	CLEAR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_8
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	CLEAR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_16
	CLEAR_BIT( ADCSRA , 0 ) ;
	CLEAR_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_32
	SET_BIT( ADCSRA , 0 ) ;
	CLEAR_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_64
	CLEAR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_128
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#endif
	SET_BIT( ADCSRA , 7 ) ;       /*Enable ADC*/
}


u16 ADC_U16GetChannelReading(u8 Channel)
{
	u16 Relult = 0 ;
	ADMUX&= 0XE0 ;                      /*0b11100000*/
	ADMUX |= Channel ;
	SET_BIT(ADCSRA,6);                  /* Start Conversion*/
	while(IS_BIT_CLEAR(ADCSRA,4));     	/*polling on the conversion complete flag*/
	SET_BIT(ADCSRA,4);                  /*CLEAR THE FLAG*/
	Relult = ADC;                       /*get the result*/
	return Relult;
}
