/*************************************************
 * AUTHOR : Moataz Tarek
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION:program.h
 **************************************************/


#include "../../../LIB/STD_Type.h"
#include "../../../LIB/BIT_Math.h"
#include"../../../MCAL/DIO/DIO_Interface.h"
#include "../../../MCAL/GIE/GIE_Interface.h"
#include "Timer_Config.h"
#include "Timer_Private.h"

/*Static Function prototype*/
static void Compare_modes(void);
static void waveform_modes(void);
static void config_prescaler(void);
static void FastPWM_modes(void);

/*globale Variables*/
u16 count = 0 ;
u8 overload = 0;

static volatile void(*callptr)(void) = NULL_PTR;
/*ISR Function Call*/
void __vector_11(void){
	count++;
	if(count == 3906){
		TCNT0 = 192; 		   /* preload value*/
		(*callptr)();         /*To call function*/
		count = 0;
	}

}

void SetCallBack(void(*a_ptr)(void))
{

	callptr = a_ptr; /*give address function processing to the pointer pointer*/
}


void Timer0_voidInit(void){
#if (TIMER_MODE  ==  OVERFLOW_MODE)
	GIE_Disable();                    /*disable interrupt enable*/
	config_prescaler();               /*config prescaler as 8*/
	waveform_modes();                 /*configure normal mode*/
	TCNT0 = 192; 		              /* preload value*/
	GIE_Enable();                     /*set globale interrupt enable*/
	SET_BIT(TIMSK,0);     	          /*timer overflow interrupt enable*/
	Compare_modes();                  /*disconnected*/
	FastPWM_modes();                  /*disconnected*/
#elif (TIMER_MODE == COMPARE_MODE )
	config_prescaler();               /*config prescaler as 8*/
	waveform_modes();                 /*configure comapare mode*/
	Compare_modes();                  /*disconnect OC0*/
	OCR0 = 200;                       /*compare value register*/
	GIE_Enable();                     /*set globale interrupt enable*/
	SET_BIT(TIMSK,1);     	          /*timetr compare interrupt enable*/
#elif PWM_mode
	TCNT0 = 0;                        /*iniate timer register*/
	config_prescaler();               /*config_prescaler 8*/
	waveform_modes();                 /*set  fast pwm mode*/
	FastPWM_modes();                  /*non- inverted mode*/
#endif


}
static void config_prescaler(void){
	/*set prescaler 1024*/
#if  PRESCALER ==  SCALE_1024
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	/*set prescaler 256*/
#elif PRESCALER == SCALE_256
	CLEAR_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	/*set prescaler 64*/
#elif PRESCALER== SCALE_64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	/*set prescaler 64*/
#elif PRESCALER== SCALE_8
	CLEAR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	/*no prescaling*/
#elif PRESCALER== SCALE_NO
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	/*no clocksource*/
#elif PRESCALER == NO_CLOCK
	CLEAR_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
#endif

}

static void waveform_modes(void){
#if WAVEFORM_MODE == NORMAL
	CLEAR_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
#elif WAVEFORM_MODE == PWM_PHASE_CORRECT
	CLEAR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
#elif WAVEFORM_MODE == CTC
	SET_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);
#elif WAVEFORM_MODE ==  FAST_PWM
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
#endif

}

static void Compare_modes(void){
#if COMPARE_MODE_MATCH   == OC0_DISCONNECT
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif COMPARE_MODE_MATCH == OC0_SET
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif COMPARE_MODE_MATCH == OC0_TOGGLE
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
#elif COMPARE_MODE_MATCH   ==  OC0_ClEAR
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#endif

}

/*modes of pwm*/
static void FastPWM_modes(void){
#if WAVEFORM == NON_INVERTED_MODE
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif  WAVEFORM == INVERTED_MODE
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif  WAVEFORM  == OC0_DISCONNECTED
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);

#endif



}

