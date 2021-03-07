/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 18/12/2020
 * VERION : V0.0
 * DISCRIPTION: timer1_Progame.h
 **************************************************/


#include "../../../LIB/STD_Type.h"
#include "../../../LIB/BIT_Math.h"
#include "timer1_Private.h"
#include "timer1_Config.h"
#include "../../../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"

void config_prescaler(void){

#if  prescaler  ==   NO_clock

	CLEAR_BIT(TCCR1B,0); // CS00
	CLEAR_BIT(TCCR1B,1); // CS01
	CLEAR_BIT(TCCR1B,2); // CS02


#elif  prescaler  == scale_NO
	SET_BIT(TCCR1B,0); // CS00
	CLEAR_BIT(TCCR1B,1); // CS01
	CLEAR_BIT(TCCR1B,2); // CS02

#elif prescaler  == scale_8
	CLEAR_BIT(TCCR1B,0); // CS00
	SET_BIT(TCCR1B,1); // CS01
	CLEAR_BIT(TCCR1B,2); // CS02

#elif  prescaler  ==  scale_64
	SET_BIT(TCCR1B,0); // CS00
	SET_BIT(TCCR1B,1); // CS01
	CLEAR_BIT(TCCR1B,2); // CS02


#elif prescaler  ==  scale_256
	CLEAR_BIT(TCCR1B,0); // CS00
	CLEAR_BIT(TCCR1B,1); // CS01
	SET_BIT(TCCR1B,2); // CS02


#elif  prescaler ==   scale_1024
	SET_BIT(TCCR1B,0); // CS00
	CLEAR_BIT(TCCR1B,1); // CS01
	SET_BIT(TCCR1B,2); // CS02
#endif

}
void Waveform_GenerationMode(void){

#if Waveform_Generation_Mode == Normal
	CLEAR_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_8_bit
	SET_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_9_bit
	CLEAR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_10_bit
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif Waveform_Generation_Mode == CTC_OCR1A
	CLEAR_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_8_bit
	SET_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif Waveform_Generation_Mode == Fast_PWM_9_bit
	CLEAR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_10_bit
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	CLEAR_BIT(TCCR1B,4); // WGM13


#elif Waveform_Generation_Mode == Phase_and_Frequency_Correct_ICR1
	CLEAR_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_and_Frequency_Correct_OCR1A
	SET_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_ICR1
	CLEAR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Phase_Correct_OCR1A
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	CLEAR_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == CTC_ICR1
	CLEAR_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Reserved
	SET_BIT(TCCR1A,0); // WGM10
	CLEAR_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13


#elif  Waveform_Generation_Mode == Fast_PWM_ICR1
	CLEAR_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13
	ICR1 = ICR1_Value;



#elif  Waveform_Generation_Mode == Fast_PWM_OCR1A
	SET_BIT(TCCR1A,0); // WGM10
	SET_BIT(TCCR1A,1); // WGM11
	SET_BIT(TCCR1B,3); // WGM12
	SET_BIT(TCCR1B,4); // WGM13

#endif
}

void comape_output_mode(void){
	/*fast PWM or PWM or compare mode or compare match*/
#if  Channel_number ==  Channel_A
#if  comape_mode ==  Non_Inverting_mode
	CLEAR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
#elif comape_mode  == Inverting_mode
	SET_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
#elif comape_mode == toggle_compare_match
	SET_BIT(TCCR1A,6);
	CLEAR_BIT(TCCR1A,7);
#elif comape_mode    ==    Normal
	CLEAR_BIT(TCCR1A,6);
	CLEAR_BIT(TCCR1A,7);
#endif


#elif Channel_number ==  Channel_B

#if  comape_mode == Non-Inverting_mode
	CLEAR_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
#elif comape_mode == Inverting_mode
	SET_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
#elif comape_mode == toggle_compare_match
	SET_BIT(TCCR1A,4);
	CLEAR_BIT(TCCR1A,5);
#elif comape_mode    ==    Normal
	CLEAR_BIT(TCCR1A,4);
	CLEAR_BIT(TCCR1A,5);
#endif

#endif
}



void timer1_init(){
#if  Waveform_Generation_Mode == Fast_PWM_ICR1
	config_prescaler();       /*config prescaler 256*/
	Waveform_GenerationMode();/*fast pwm mode*/
	comape_output_mode();     /*output mode is inverting mode*/

#elif

#endif

}

void Timer1_Load_OCR1 (u16 Copy_U8_OCR1)
{
#if  Channel_number ==  Channel_A
	TCNT1 =0;
	OCR1A= Copy_U8_OCR1 ;
#elif Channel_number ==  Channel_B
	TCNT1 = 0 ;
	OCR1B = Copy_U8_OCR1 ;

#endif
}
