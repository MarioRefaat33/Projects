/*************************************************
 * AUTHOR : Moataz Tarek -Mario refaat - Abanob Raoof - Amira Moustafa
 * Date   : 8/3/2021
 * VERION : V0.8
 * DISCRIPTION:  FOTA (Flash On the Air)
 **************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "USART_interface.h"
#include "FPEC_interface.h"
#include "ESP_Interface.h"
#include "NVIC_Interface.h"
#include "parse.h"

extern u8 ResponseArray[10000]; /*array which contain the page of hexa  */
 u8  u8RecBuffer[100]   ;
u16  u8RecCounter = 0   ;
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
	u8RecCounter=0;
	while(ResponseArray [u8RecCounter] != ':'){/*count until arrive to :*/
		u8RecCounter++; /*do nothing*/
	}
	u8RecCounter++;
	/*while ( ResponseArray [u8RecCounter] != '\n'   ){
		u8RecBuffer[j] = ResponseArray [u8RecCounter];
		j++; //counter of small array
		u8RecCounter++; //counter of big array
	}

	Parser_voidParseRecord(u8RecBuffer); //parse first line of page
	u8RecCounter++;*/
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

		for(u16 i=0;i<10000;i++){
			ResponseArray[i]=0;
		}

}



int main(void){
	char page_array[3]={0};                       /*array of page number*/
	u8 page_number=0;

	RCC_voidInitSysClock();                     /*enable clock for system */
	RCC_voidEnableClock(RCC_APB2,14);           /*enable clock for UART*/
	RCC_voidEnableClock(RCC_APB2,2);            /*enable clock for GPIOA*/
	RCC_voidEnableClock(RCC_AHB,4);             /*enable clock for FPIC*/

	MGPIO_VidSetPinDirection(GPIOA,9,0b1010);   /* TX AFPP */
	MGPIO_VidSetPinDirection(GPIOA,10,0b0100);  /* RC Input Floating */

	MNVIC_voidEnableInterrupt(USART1);              /*enable NVIC For uart*/
	MUSART1_voidInit();                         /*init UART */
	MSTK_voidInit();                            /*init timer*/

	WIFImod_voidInit();                         /*init WIFI */
	WIFImod_ConnectToNetwork("1234","11111111");
	ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");
	/*to Read text file and check if user want to burn new application or execute old application */
	while(ResponseArray [u8RecCounter] != ':'){
		u8RecCounter++; /*do nothing*/
	}
	u8RecCounter++;
	/* user chose to burn old application*/
	if(ResponseArray [u8RecCounter] == '1'){
		func();
	}
	else {
		FPEC_voidEraseAppArea();          /*erase memory to burn new application*/
		page_number=ESP8266_u8ReceivePageNumber("abanoub.freevar.com"); /*receive page number*/
		for(u8 i=1;i<=page_number;i++){
			if ((i>=1 )&&( i<10)){
				page_array[0]=i+48;
				page_array[1]='\0';
				ESP8266_u8SendHttpReq(page_array);
				ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");
				dividepage_parselines();
			}
			else if (10<=i){
				page_array[0]=1+48;
				page_array[1]=((i%10)+48);
				page_array[2]='\0';
				ESP8266_u8SendHttpReq_overpage(page_array);
				ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");
				dividepage_parselines();
			}
		}
		ESP8266_u8SendHttpReq_clear_buffer();
		func();
	}

	return 0;
}
