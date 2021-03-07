/*************************************************
 * AUTHOR : Mario Refaat
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: LM_35.c
 **************************************************/

#include "../../../MCAL/DIO/DIO_Interface.h"
#include "../../../MCAL/ADC/ADC_Interface.h"
#include "../../../LIB/STD_Type.h"
void LM35_VoidInit(void)
{
	ADC_VoidInit();
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_INPUT);

}


u16 LM35_U16Read(u8 Copy_u8readchannel)
{
	u32 temp = 0;
	temp = ADC_U16GetChannelReading(Copy_u8readchannel); /* read channel two where the temp sensor is connect */
	temp = (temp*150*5)/(1023*1.5);                      /* calculate the temp from the ADC value*/

	 return temp;
}




