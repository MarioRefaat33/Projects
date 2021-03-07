/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Amira Moustafa
 *
 *******************************************************************************/
#include "../../LIB/BIT_Math.h"
#include "../../HAL/KEYPAD/Keypad_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"

/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

#if (N_col == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static u8 KeyPad_4x3_adjustKeyNumber(u8 button_number);
#elif (N_col == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number);
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
u8 KeyPad_getPressedKey(void){
	u8 col,row;
	while(1){

		for(col=0;col<N_col;col++) /* loop for columns */
		{

			 DIO_voidSetPortDirection(1, 0b00010000<<col);
			  DIO_voidSetPortValue(1, (~(0b00010000<<col)) );
			for(row=0;row<N_row;row++) /* loop for rows */
			{
				if(  IS_BIT_CLEAR(KEYPAD_PORT_IN,row))
				{
					while(  IS_BIT_CLEAR(KEYPAD_PORT_IN,row));
#if (N_col == 3)
					 return KeyPad_4x3_adjustKeyNumber((row*N_col)+col+1);

#elif (N_col == 4)
					return  KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);
#endif
				}
			}
		}

	}

}

#if (N_col == 3) 

static u8 KeyPad_4x3_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
	case 10: return '*'; // ASCII Code of =
	break;
	case 11: return 0;
	break;
	case 12: return '#'; // ASCII Code of +
	break;
	default: return button_number;
	}
} 

#elif (N_col == 4)

static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
	case 1: return 7;
	break;
	case 2: return 8;
	break;
	case 3: return 9;
	break;
	case 4: return '%'; // ASCII Code of %
	break;
	case 5: return 4;
	break;
	case 6: return 5;
	break;
	case 7: return 6;
	break;
	case 8: return '*'; /* ASCII Code of '*' */
	break;
	case 9: return 1;
	break;
	case 10: return 2;
	break;
	case 11: return 3;
	break;
	case 12: return '-'; /* ASCII Code of '-' */
	break;
	case 13: return 'c';  /* ASCII of Enter */
	break;
	case 14: return 0;
	break;
	case 15: return '='; /* ASCII Code of '=' */
	break;
	case 16: return '+'; /* ASCII Code of '+' */
	break;
	default: return button_number;
	}
} 

#endif
