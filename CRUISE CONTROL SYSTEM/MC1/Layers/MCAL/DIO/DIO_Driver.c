/***	LIBRARY LAYER	***/
#include "../../LIB/AVR_Reg.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/***	MICROCONTROLLER ABSTRACTION LAYER	***/
#include "Dio_Cfg.h"
#include "Dio.h"

/*______________________________________________________________________________________________*/
/*Description: Set PORT Direction (INPUT or OUTPUT)
 * Input     : Copy_u8PortNB (PORT Number) ,  Copy_u8Dir (PORT Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PORT(uint8_t Copy_u8PortNB, uint8_t Copy_u8Dir)
{
	if (Copy_u8PortNB >= NO_OF_PORTS || Copy_u8Dir > DIO_OUTPUT )
	{
		return ERROR;
	}
	else
	{
		switch (Copy_u8PortNB)
		{
			case DIO_PORT_NO_A:
			if (Copy_u8Dir == DIO_OUTPUT)
			{
				DIRECTION_PORT0 = DIO_ALL;
			}
			else
			{
				DIRECTION_PORT0 = DIO_INPUT;
			}
			break;

			case DIO_PORT_NO_B:
			if (Copy_u8Dir == DIO_OUTPUT)
			{
				DIRECTION_PORT1 = DIO_ALL;
			}
			else
			{
				DIRECTION_PORT1 = DIO_INPUT;
			}
			break;

			case DIO_PORT_NO_C:
			if (Copy_u8Dir == DIO_OUTPUT)
			{
				DIRECTION_PORT2 = DIO_ALL;
			}
			else
			{
				DIRECTION_PORT2 = DIO_INPUT;
			}
			break;

			case DIO_PORT_NO_D:
			if (Copy_u8Dir == DIO_OUTPUT)
			{
				DIRECTION_PORT3 = DIO_ALL;
			}
			else
			{
				DIRECTION_PORT3 = DIO_INPUT;
			}
			break;
		}
		return NO_ERROR;
	}
}

/*______________________________________________________________________________________________*/

/*Description: Set PIN Direction (INPUT or OUTPUT)
 * Input     :Copy_u8PinNB (PIN Number) ,  Copy_u8Dir (PIN Direction)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8Init_PIN(uint8_t Copy_u8PinN, uint8_t Copy_u8Dir)
{
	if (Copy_u8PinN > MAX_PIN_NO || Copy_u8Dir > DIO_OUTPUT)
	{
		return ERROR;
	}
	else if (Copy_u8Dir == DIO_INPUT)
	{
		if (Copy_u8PinN < 8)
		{
			CLEAR_BIT(DIRECTION_PORT0, Copy_u8PinN);
		}
		else if (Copy_u8PinN < 16)
		{
			CLEAR_BIT(DIRECTION_PORT1, Copy_u8PinN % 8);
		}
		else if (Copy_u8PinN < 24)
		{
			CLEAR_BIT(DIRECTION_PORT2, Copy_u8PinN % 16);
		}
		else
		{
			CLEAR_BIT(DIRECTION_PORT3, Copy_u8PinN % 24);
		}
	}
	else
	{
		if (Copy_u8PinN < 8)
		{
			SET_BIT(DIRECTION_PORT0, Copy_u8PinN);
		}
		else if (Copy_u8PinN < 16)
		{
			SET_BIT(DIRECTION_PORT1, Copy_u8PinN % 8);
		}
		else if (Copy_u8PinN < 24)
		{
			SET_BIT(DIRECTION_PORT2, Copy_u8PinN % 16);
		}
		else
		{
			SET_BIT(DIRECTION_PORT3, Copy_u8PinN % 24);
		}
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/

/*Description: Set PORT Value (from 0 to 255)
 * Input     : Copy_u8PortNB (PORT Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortValue(uint8_t Copy_u8PortNB, uint8_t Copy_u8Value)
{
	if (Copy_u8PortNB >= NO_OF_PORTS || Copy_u8Value > DIO_ALL)
	{
		return ERROR;
	}
	else
	{
		switch (Copy_u8PortNB)
		{
		case DIO_PORT_NO_A:
			VALUE_PORT0 = Copy_u8Value;
			break;
		case DIO_PORT_NO_B:
			VALUE_PORT1 = Copy_u8Value;
			break;
		case DIO_PORT_NO_C:
			VALUE_PORT2 = Copy_u8Value;
			break;
		case DIO_PORT_NO_D:
			VALUE_PORT3 = Copy_u8Value;
		}
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/
/*Description: Set PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinNB (PIN Number) , Copy_u8Value (Value)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinValue(uint8_t Copy_u8PinN, uint8_t Copy_u8Value)
{
	if (Copy_u8PinN > MAX_PIN_NO || Copy_u8Value > DIO_HIGH)
	{
		return ERROR;
	}
	if (Copy_u8PinN < 8)
	{
		if ( BIT_IS_CLEAR(DIRECTION_PORT0, Copy_u8PinN) )
		{
			return ERROR;
		}
		else if (Copy_u8Value == DIO_HIGH)
		{
			SET_BIT(VALUE_PORT0, Copy_u8PinN);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT0, Copy_u8PinN);
		}
	}
	else if (Copy_u8PinN < 16)
	{
		if ( BIT_IS_CLEAR(DIRECTION_PORT1, Copy_u8PinN % 8) )
		{
			return ERROR;
		}
		else if (Copy_u8Value == DIO_HIGH)
		{
			SET_BIT(VALUE_PORT1, Copy_u8PinN % 8);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT1, Copy_u8PinN % 8);
		}
	}
	else if (Copy_u8PinN < 24)
	{
		if ( BIT_IS_CLEAR(DIRECTION_PORT2, Copy_u8PinN % 16) )
		{
			return ERROR;
		}
		else if (Copy_u8Value == DIO_HIGH)
		{
			SET_BIT(VALUE_PORT2, Copy_u8PinN % 16);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT2, Copy_u8PinN % 16);
		}
	}
	else
	{
		if ( BIT_IS_CLEAR(DIRECTION_PORT3, Copy_u8PinN % 24) )
		{
			return ERROR;
		}
		else if (Copy_u8Value == DIO_HIGH)
		{
			SET_BIT(VALUE_PORT3, Copy_u8PinN % 24);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT3, Copy_u8PinN % 24);
		}
	}
	return NO_ERROR;
}


/*______________________________________________________________________________________________*/
/*Description: Get PORT Value
 * Input     :  Copy_u8PortNB (PORT Number),*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */

uint8_t DIO_u8GetPortValue( uint8_t Copy_u8PortNB , uint8_t *Copy_u8Value )
{
	if ( (Copy_u8Value != NULL ) && ( Copy_u8PortNB <= MAXIMUM_PORT_NO ) )
	{
		switch (Copy_u8PortNB)
		{
		case DIO_PORT_NO_A  :   if ( DIRECTION_PORT0 == DIO_INPUT )
		{    *Copy_u8Value = READ_PORT0 ;
		return NO_ERROR ;
		} else {return ERROR;}

		case DIO_PORT_NO_B  :   if ( DIRECTION_PORT1 == DIO_INPUT )
		{    *Copy_u8Value = READ_PORT1 ;
		return NO_ERROR ;
		} else {return ERROR;}


		case DIO_PORT_NO_C  :   if ( DIRECTION_PORT2 == DIO_INPUT )
		{    *Copy_u8Value = READ_PORT2 ;
		return NO_ERROR ;
		} else {return ERROR;}


		case DIO_PORT_NO_D  :  if ( DIRECTION_PORT3 == DIO_INPUT )
		{    *Copy_u8Value = READ_PORT3 ;
		return NO_ERROR ;
		} else {return ERROR;}
		}
	}
	else
	{
		return ERROR ;
	}

	return NO_ERROR;
}

/*______________________________________________________________________________________________*/
/*Description: Get PIN Value (HIGH or LOW)
 * Input     : Copy_u8PinN (PIN Number) ,*Copy_u8Value (Pointer to send value to it)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8GetPinValue( uint8_t Copy_u8PinN , uint8_t *Copy_u8Value )
{
	if ( ( Copy_u8Value != NULL ) && ( Copy_u8PinN <= MAX_PIN_NO ) )
	{
		if      ( Copy_u8PinN <= DIO_PIN_NO_7 )
		{
			*Copy_u8Value = GET_BIT( READ_PORT0 , Copy_u8PinN ) ;
			return NO_ERROR ;
		}
		else if ( Copy_u8PinN <= DIO_PIN_NO_15 )
		{
			*Copy_u8Value = GET_BIT( READ_PORT1 ,  ( Copy_u8PinN - DIO_PIN_NO_8) )  ;
			return NO_ERROR ;
		}
		else if ( Copy_u8PinN <= DIO_PIN_NO_23 )
		{
			*Copy_u8Value = GET_BIT( READ_PORT2 , ( Copy_u8PinN - DIO_PIN_NO_16) ) ;
			return NO_ERROR ;
		}
		else
		{
			*Copy_u8Value = GET_BIT( READ_PORT3 , ( Copy_u8PinN - DIO_PIN_NO_24) ) ;
			return NO_ERROR ;
		}
	}

	else
	{
		return ERROR ;
	}
}

/*______________________________________________________________________________________________*/
/*Description: Set PORT Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     :  Copy_u8PortNB (PORT Number),Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPortInputType(uint8_t Copy_u8PortNB, uint8_t Copy_u8InputType)
{
	if(Copy_u8PortNB >= NO_OF_PORTS || Copy_u8InputType > 1)
	{
		return ERROR;
	}
	else
	{
		switch(Copy_u8PortNB)
		{
		case 0:
			if(DIRECTION_PORT0 != DIO_INPUT)
			{
				return ERROR;
			}
			else if (Copy_u8InputType == 1)
			{
				VALUE_PORT0 = DIO_ALL;
			}
			else
			{
				VALUE_PORT0 = 0;
			}
			break;
		case 1:
			if(DIRECTION_PORT1 != DIO_INPUT)
			{
				return ERROR;
			}
			else if (Copy_u8InputType == 1)
			{
				VALUE_PORT1 = DIO_ALL;
			}
			else
			{
				VALUE_PORT1 = 0;
			}
			break;
		case 2:
			if(DIRECTION_PORT2 != DIO_INPUT)
			{
				return ERROR;
			}
			else if (Copy_u8InputType == 1)
			{
				VALUE_PORT2 = DIO_ALL;
			}
			else
			{
				VALUE_PORT2 = 0;
			}
			break;
		case 3:
			if(DIRECTION_PORT3 != DIO_INPUT)
			{
				return ERROR;
			}
			else if (Copy_u8InputType == 1)
			{
				VALUE_PORT3 = DIO_ALL;
			}
			else
			{
				VALUE_PORT3 = 0;
			}
			break;

		}
	}
	return NO_ERROR;
}
/*______________________________________________________________________________________________*/
/*Description: Set PIN Type in case of INPUT Direction (PULL UP or FLOATING)
 * Input     : Copy_u8PinN(PIN NO) ,Copy_u8InputType(1 for PULL UP and 0 for FLOATING)
 * Output    : Return Error Status (Error or NO Error)
 * */
uint8_t DIO_u8SetPinInputType(uint8_t Copy_u8PinN, uint8_t Copy_u8InputType)
{
	if(Copy_u8PinN > MAX_PIN_NO || Copy_u8InputType > 1)
	{
		return ERROR;
	}
	else if (Copy_u8PinN < 8)
	{
		if ( BIT_IS_SET(DIRECTION_PORT0, Copy_u8PinN) )
		{
			return ERROR;
		}
		else if ( Copy_u8InputType == 1 )
		{
			SET_BIT(VALUE_PORT0,Copy_u8PinN);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT0,Copy_u8PinN);
		}
	}
	else if (Copy_u8PinN < 16)
	{
		if ( BIT_IS_SET(DIRECTION_PORT1, Copy_u8PinN % 8) )
		{
			return ERROR;
		}
		else if ( Copy_u8InputType == 1 )
		{
			SET_BIT(VALUE_PORT1,Copy_u8PinN % 8);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT1,Copy_u8PinN % 8);
		}
	}
	else if (Copy_u8PinN < 24)
	{
		if ( BIT_IS_SET(DIRECTION_PORT2, Copy_u8PinN % 16) )
		{
			return ERROR;
		}
		else if ( Copy_u8InputType == 1 )
		{
			SET_BIT(VALUE_PORT2,Copy_u8PinN % 16);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT2,Copy_u8PinN % 16);
		}
	}
	else
	{
		if ( BIT_IS_SET(DIRECTION_PORT3, Copy_u8PinN % 24) )
		{
			return ERROR;
		}
		else if ( Copy_u8InputType == 1 )
		{
			SET_BIT(VALUE_PORT3,Copy_u8PinN % 24);
		}
		else
		{
			CLEAR_BIT(VALUE_PORT3,Copy_u8PinN % 24);
		}
	}
	return NO_ERROR;
}
