
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Type.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/INTERRUPT/EXIT_private.h"
#include "../../MCAL/INTERRUPT/EXIT_Config.h"
#include "../../MCAL/GIE/GIE_Interface.h"

#include <avr/delay.h>


void EXIT_VidInit(void){

#if ISC0== FALLING
	SET_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);
    DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
    DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
	#elif ISC0== RISING
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC0== OCH
	 CLEAR_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC0== LOW_LEVEL
	 CLEAR_BIT(MCUCR,1);
	 CLEAR_BIT(MCUCR,0);

	#endif

	 #if ISC1== FALLING
	 	SET_BIT(MCUCR, 3);
	 	CLEAR_BIT(MCUCR, 2);

	 	#elif ISC1== RISING
	 	SET_BIT(MCUCR,3);
	 	SET_BIT(MCUCR,2);

	 	#elif ISC1== OCH
	 	 CLEAR_BIT(MCUCR,3);
	 	SET_BIT(MCUCR,2);

	 	#elif ISC1== LOW_LEVEL
	 	 CLEAR_BIT(MCUCR,1);
	 	 CLEAR_BIT(MCUCR,0);

	     #endif


	 	#if ISC2== FALLING
	 	CLEAR_BIT(MCUCSR, 6);

	 	#elif ISC2== RISING
	 	SET_BIT(MCUCSR,6);
	 	#endif
}

void EXIT0_Enable(void){
	// PIE=Enable	
	SET_BIT(GICR,6);
	GIE_Enable();
}
void EXIT0_Disable(void){

	// PIE=Disable
		CLEAR_BIT(GICR,6);

}
void EXIT1_Enable(void)
{
	SET_BIT(GICR, 7);
}


void EXIT1_Disable(void)
{
	CLEAR_BIT(GICR, 7);
}


void EXIT2_Enable(void)
{
	SET_BIT(GICR, 5);
}


void EXIT2_Disable(void)
{
	CLEAR_BIT(GICR, 5);
}


static void(*INT0_CallBack)(void) = NULL_PTR ;

void VECT_INT0_CallBack ( void ( *Copy_INT0_PCallBack )( void )  )
{
	INT0_CallBack = Copy_INT0_PCallBack ;

}



void __vector_1(void)
{
	if(INT0_CallBack != NULL_PTR)
		{
			INT0_CallBack() ;
		}
}



void __vector_2(void){

}


void __vector_3(void){

}



