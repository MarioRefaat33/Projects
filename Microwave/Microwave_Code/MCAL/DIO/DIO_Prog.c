/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: DIO_Interface.h
 **************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Type.h"
#include "../../MCAL/DIO/DIO_Private.h"

/*function definition*/
void DIO_voidSetPinDirection(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8state){
	if(1 ==  copy_u8state){
		switch(copy_u8port){
		case 0:  SET_BIT(DDRA, copy_u8pin); break;
		case 1:  SET_BIT(DDRB, copy_u8pin); break;
		case 2:  SET_BIT(DDRC, copy_u8pin); break;
		case 3:  SET_BIT(DDRD, copy_u8pin); break;
		}
	}
	else if(0 == copy_u8state){
		switch(copy_u8port){
		case 0:  CLEAR_BIT(DDRA, copy_u8pin); break;
		case 1:  CLEAR_BIT(DDRB, copy_u8pin); break;
		case 2:  CLEAR_BIT(DDRC, copy_u8pin); break;
		case 3:  CLEAR_BIT(DDRD, copy_u8pin); break;
		}
	}
	else {


	}		
}
void DIO_voidSetPinValue(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value){
	if(1 == copy_u8value){

		switch(copy_u8port){
		case 0:  SET_BIT(PORTA, copy_u8pin); break;
		case 1:  SET_BIT(PORTB, copy_u8pin); break;
		case 2:  SET_BIT(PORTC, copy_u8pin); break;
		case 3:  SET_BIT(PORTD, copy_u8pin); break;
		}
	}
	else if(0 == copy_u8value){
		switch(copy_u8port){
		case 0:  CLEAR_BIT(PORTA, copy_u8pin); break;
		case 1:  CLEAR_BIT(PORTB, copy_u8pin); break;
		case 2:  CLEAR_BIT(PORTC, copy_u8pin); break;
		case 3:  CLEAR_BIT(PORTD, copy_u8pin); break;
		}
	}
	else {


	}


}
u8 DIO_voidGetPinValue(u8 copy_u8port, u8 copy_u8pin){

	int result = 0;
	switch(copy_u8port){

	case 0: result =  IS_BIT_SET(PINA, copy_u8pin); break;
	case 1: result =  IS_BIT_SET(PINB, copy_u8pin); break;
	case 2: result =  IS_BIT_SET(PINC, copy_u8pin); break;
	case 3: result =  IS_BIT_SET(PIND, copy_u8pin); break;

	}	
	return result;
}
void DIO_voidSetPortDirection(u8 copy_u8port, u8 copy_u8state){
	switch(copy_u8port)
	{
	case 0: DDRA=copy_u8state; break;
	case 1: DDRB=copy_u8state; break;
	case 2: DDRC=copy_u8state; break;
	case 3: DDRD=copy_u8state; break;
	}
}
void DIO_voidSetPortValue(u8 copy_u8port, u8 copy_u8value){
	switch(copy_u8port)
	{
	case 0: PORTA=copy_u8value; break;
	case 1: PORTB=copy_u8value; break;
	case 2: PORTC=copy_u8value; break;
	case 3: PORTD=copy_u8value; break;
	}

}
void  DIO_voidTogglePin(u8 copy_u8port, u8 copy_u8pin){
	switch(copy_u8port){
	case 0: TOGGLE_BIT(PORTA, copy_u8pin); break;
	case 1: TOGGLE_BIT(PORTB, copy_u8pin); break;
	case 2: TOGGLE_BIT(PORTC, copy_u8pin); break;
	case 3: TOGGLE_BIT(PORTD, copy_u8pin); break;
	}

}
void  DIO_voidSetfirstnippleDir(u8 copy_u8port, u8 copy_u8state){
	if(copy_u8state == 1){
		switch(copy_u8port){
		case 0:  DDRA |= 0x0f; break;
		case 1:  DDRB |= 0x0f; break;
		case 2:  DDRC |= 0x0f; break;
		case 3:  DDRD |= 0x0f; break;
		}
	}
	else if(copy_u8state == 0){
		switch(copy_u8port){
		case 0:  DDRA &=~ 0xf0; break;
		case 1:  DDRB &=~ 0xf0; break;
		case 2:  DDRC &=~ 0xf0; break;
		case 3:  DDRD &=~ 0xf0; break;
		}

	}
}
void DIO_voidSetlastnippleDir(u8 copy_u8port, u8 copy_u8state){
	if(copy_u8state == 1){
		switch(copy_u8port){
		case 0:  DDRA |= 0xf0; break;
		case 1:  DDRB |= 0xf0; break;
		case 2:  DDRC |= 0xf0; break;
		case 3:  DDRD |= 0xf0; break;
		}
	}
	else if(copy_u8state == 0){
		switch(copy_u8port){
		case 0:  DDRA &=~ 0xf0; break;
		case 1:  DDRB &=~ 0xf0; break;
		case 2:  DDRC &=~ 0xf0; break;
		case 3:  DDRD &=~ 0xf0; break;
		}
	}

}

void DIO_voidSetFirstNipple(u8 copy_u8port, u8 copy_u8val){
	switch(copy_u8port){
	case 0: PORTA = (PORTA & 0xf0) | (copy_u8val & 0x0f);  break;
	case 1: PORTB = (PORTB & 0xf0) | (copy_u8val & 0x0f);  break;
	case 2: PORTC = (PORTC & 0xf0) | (copy_u8val & 0x0f);  break;
	case 3: PORTD = (PORTD & 0xf0) | (copy_u8val & 0x0f);  break;
	}
}

void  DIO_voidSetLastNipple(u8 copy_u8port, u8 copy_u8val){
	switch(copy_u8port){
	case 0: PORTA = (PORTA & 0x0f) | (copy_u8val & 0xF0);  break;
	case 1: PORTB = (PORTB & 0x0f) | (copy_u8val & 0xF0);  break;
	case 2: PORTC = (PORTC & 0x0f) | (copy_u8val & 0xF0);  break;
	case 3: PORTD = (PORTD & 0x0f) | (copy_u8val & 0xF0);  break;
	}
}
void DIO_voidPlaceFirstNipple(u8 copy_u8port, u8 copy_u8val){

	switch(copy_u8port){
	case 0: PORTA = (PORTA & 0x0f) | ((copy_u8val & 0x0f)<<4);  break;
	case 1: PORTB = (PORTB & 0x0f) | ((copy_u8val & 0x0f)<<4);  break;
	case 2: PORTC = (PORTC & 0x0f) | ((copy_u8val & 0x0f)<<4);  break;
	case 3: PORTD = (PORTD & 0x0f) | ((copy_u8val & 0x0f)<<4);  break;
	}
}

void DIO_voidPLaceLastNipple(u8 copy_u8port, u8 copy_u8val){
	switch(copy_u8port){
	case 0: PORTA = (PORTA & 0x0F) | ((copy_u8val & 0xf0)>>4);  break;
	case 1: PORTB = (PORTB & 0x0f) | ((copy_u8val & 0xf0)>>4);  break;
	case 2: PORTC = (PORTC & 0x0f) | ((copy_u8val & 0xf0)>>4);  break;
	case 3: PORTD = (PORTD & 0x0f) | ((copy_u8val & 0xf0)>>4);  break;
	}
}
