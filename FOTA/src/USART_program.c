
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x45;

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */
	
	USART1 -> SR = 0;						/* Clearing status register */
}

void MUSART1_voidTransmit(char *arr)
{
	u8 i = 0;
	while(arr[i] != '\0'){
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}
	
}

u8 MUART_u8Recieve(void)
{
	u32 timeout=0;
	u8 Data=0;
	while(GET_BIT(USART1 -> SR,5)==0) //waiting for recieve complete
	{
		timeout++;
		if(timeout==2000000 )
		{
			Data=130;//impossible case out of all ascii
			break;
		}
	}
	if (Data==0){
		Data=USART1 -> DR;
	}

	return Data;
}




















