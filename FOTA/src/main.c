/*
 * main.c
 *
 *  Created on: Mar 7, 2021
 *      Author: Al Badr
 */


/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: Ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "USART_interface.h"
#include "FPEC_interface.h"
#include "ESP_Interface.h"

void Parser_voidParseRecord(u8* Copy_u8BufData);

extern volatile u8 ResponseArray[10000]; /*array which contain the page of hexa  */

volatile u8  u8RecBuffer[100] = {0}  ;
volatile u16  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)
	SCB_VTOR = 0x08001000;
	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();
}
void dividepage_parselines(void){
	u8 j= 0;
	/*count until arrive to :*/
	u8RecCounter=0;
	for(int x=0;x<=100;x++){
		u8RecBuffer[x] =0;
	}
	while(ResponseArray [u8RecCounter] != ':'){
		u8RecCounter++; /*do nothing*/
	}
	u8RecCounter++;
	while ( ResponseArray [u8RecCounter] != '\n'   ){
		u8RecBuffer[j] = ResponseArray [u8RecCounter];
		j++; /*counter of small array*/
		u8RecCounter++; /*counter of big array*/
	}

	Parser_voidParseRecord(u8RecBuffer); /*parse first line of page*/
	u8RecCounter++;
	while (ResponseArray [u8RecCounter] == ':') {
		j =0 ; /*over write again to small array to parse  next line*/
		while (ResponseArray[u8RecCounter] != '\n'){
			u8RecBuffer[j] = ResponseArray [u8RecCounter];
			j++;    /*counter of small array*/
			u8RecCounter++; /*counter of big array*/
		}
		Parser_voidParseRecord(u8RecBuffer); /*parse next line*/
		u8RecCounter++;
	}


}



int main(void)
{

	u8 page_array[3]={0};
	u8 page_number=0;


	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,14); /* USART1 */
	RCC_voidEnableClock(RCC_APB2,2);  /* PortA  */
	RCC_voidEnableClock(RCC_AHB,4);   /* FPEC   */


	MGPIO_VidSetPinDirection(GPIOA,9,0b1010);   /* TX AFPP */
	MGPIO_VidSetPinDirection(GPIOA,10,0b0100);  /* RC Input Floating */

	MUSART1_voidInit();

	MSTK_voidInit();

	WIFImod_voidInit();
	WIFImod_ConnectToNetwork("1234","11111111");
	ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");
	while(ResponseArray [u8RecCounter] != ':'){
		u8RecCounter++; /*do nothing*/
	}
	u8RecCounter++;
	if(ResponseArray [u8RecCounter] == '1'){
		func();
	}
	else {
		FPEC_voidEraseAppArea(); /*erase FPEC*/


		page_number=ESP8266_u8ReceivePageNumber("abanoub.freevar.com");

		for(u8 i=1;i<=page_number;i++){
			if ((i>=1 )&&( i<10)){

				page_array[0]=i+48;
				page_array[1]='\0';

				ESP8266_u8SendHttpReq(page_array);
				MSTK_voidSetBusyWait(10000000);

				ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");
				/*burn page*/

				/*parse page line line */
				dividepage_parselines();
			}
			else if (10<=i){

				page_array[0]=1+48;
				page_array[1]=((i%10)+48);
				page_array[2]='\0';

				ESP8266_u8SendHttpReq_overpage(page_array);
				MSTK_voidSetBusyWait(10000000);

				//WIFImod_SendCharsNumbers("43" );
				ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");
				/*burn page*/
				/*parse page line line */
				dividepage_parselines();
			}
		}
		func();

	}

	return 0;
}
