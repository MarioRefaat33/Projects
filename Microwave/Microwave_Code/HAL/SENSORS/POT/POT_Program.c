/*************************************************
* AUTHOR : Mario Refaat
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: LM_35.h
**************************************************/

#include "../../../MCAL/DIO/DIO_Interface.h"
#include "../../../MCAL/ADC/ADC_Interface.h"
#include "../../../LIB/STD_Type.h"


void POT_VoidInit()
{
	ADC_VoidInit();
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_INPUT);

}
u16 POT_U16Read(u8 Copy_u8ReadPOT35Channal)
{

	u16 Dig_ADC=ADC_U16GetChannelReading(Copy_u8ReadPOT35Channal);
	u16 Anl_ADC=(Dig_ADC * 5000UL )/1023;
	return Anl_ADC;

}



















