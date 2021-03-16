
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
volatile void (* MUSART1_CallBack )(void) =NULL_PTR;
void MUSART1_voidSetCallBack(void (*ptr) (void) ){
   MUSART1_CallBack = ptr;
}
void USART1_IRQHandler(void){
	USART1 -> SR= 0;
	MUSART1_CallBack();
}


void MUSART1_voidInit(void)
{
	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x45;
	SET_BIT((USART1-> CR[0]), 5 );
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
	return USART1 -> DR;

}
void MUSART1_VidClearFlags( void ){
	/* Clear all flags */
	USART1 -> SR = 0;						/* Clearing status register */
}





















