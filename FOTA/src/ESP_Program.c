/*
 * ESP_Program.c
 *
 *  Created on: Feb 8, 2021
 *      Author: Al Badr
 */


#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "USART_interface.h"
#include "ESP_Private.h"
#include "ESP_Interface.h"
#include "STK_Interface.h"
#include "DIO_Interface.h"

volatile u8 ResponseArray[5000]={0};
void WIFI_Array_Clear(void){

	for(int x=0;x<=2000;x++){
		ResponseArray[x]=0;
	}
}
void WIFImod_voidInit(void){
	u8 state=0;



	//state=validate();
	while (state==0)
	{
		//MSTK_voidSetBusyWait(3000000);
		/*ENABLE ECHO TO SEE THROW YAT PROGRAM */
		MUSART1_voidTransmit("ATE1\r\n");
		state=validate();
	}
	state=0;//RETURN STATE TO DEFUALT VALUE AGAIN
	while (state==0)
	{		//MSTK_voidSetBusyWait(3000000);
	/*  SET WIFI MODE   */
	MUSART1_voidTransmit("AT+CWMODE=1\r\n");

	state=validate();
	}
}

void WIFImod_ConnectToNetwork(u8* SSID,u8* Password)
{ u8 state=0;
while (state==0)
{
	/*CONNECT TO WIFI*/
	//MSTK_voidSetBusyWait(5000000);
	//MSTK_voidSetBusyWait(5000000);
	MUSART1_voidTransmit("AT+CWJAP=\"" );
	MUSART1_voidTransmit( SSID );
	MUSART1_voidTransmit(  "\",\"" );
	MUSART1_voidTransmit(  Password);
	MUSART1_voidTransmit(  "\"\r\n");
	state=validate();

}
}

void WIFImod_ConnectToServer(u8* Copy_u8Domain, u8* Copy_u8Port)
{	u8 state=0;


while (state==0){

	//MSTK_voidSetBusyWait(3000000);
	/*CONNECT TO IP OF SERVER THROW TCP PROTOCOL*/
	MUSART1_voidTransmit(  "AT+CIPSTART=\"TCP\",\"" );
	MUSART1_voidTransmit(  Copy_u8Domain );
	MUSART1_voidTransmit(  "\"," );
	MUSART1_voidTransmit( Copy_u8Port );
	MUSART1_voidTransmit(  "\r\n" );

	state=validate();

}
}
void  WIFImod_SendCharsNumbers(u8 * Copy_u8Length )
{u8 state=0;
while (state==0){
	//MSTK_voidSetBusyWait(6000000);
	/*NUMBER OF CARACTERS WILL SEND AFTER THIS COMMAND*/
	MUSART1_voidTransmit(  "AT+CIPSEND=" );
	MUSART1_voidTransmit( Copy_u8Length );//the length of character
	MUSART1_voidTransmit(  "\r\n" );

	state=validate();

}

}
void    ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID )
{
	//u8 data=0;
	u8 state=0;
	//u32 counter=0;
	//u8 temp=0;
	while (state==0){
		//MSTK_voidSetBusyWait(3000000);
		WIFImod_ConnectToServer("162.253.155.226", "80");

		WIFImod_SendCharsNumbers("43" );

		/*SEND REQUEST TO READ DATA FROM BUFFER.txt */
		MUSART1_voidTransmit(  "GET http://" );
		MUSART1_voidTransmit( Copy_u8ChannelID );   //WEBSITE that will write in the request to accuses
		MUSART1_voidTransmit( "/buffer.txt\r\n" );

		state=validate();
	}
	/*TAKE THE HEXLINES FROM ARRAY *****************(lsa m5lstsh)*/
	/*do{
		data=(u8) MUART_u8Recieve();
	}while(data!=':');
	data=(u8) MUART_u8Recieve();
	ResponseArray[counter]=data;
	while(temp!=130)
	{	ResponseArray[counter]=data;
	temp= MUART_u8Recieve();
	ResponseArray[counter]=temp;
	counter++;
	}*/
}
u16    ESP8266_u8ReceivePageNumber( u8 * Copy_u8ChannelID)
{
	u8 data=0;
	u16 page_number=0;
	volatile u8  page_number_1=0;
	volatile u8 page_number_2=0;

	u8 state=0;
	//u32 counter=0;
	u8 temp=0;
	while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");

		//MSTK_voidSetBusyWait(3000000);
		WIFImod_SendCharsNumbers("49" );

		/*GET REQUEST TO GET NUMBER OF PAGES*/
		MUSART1_voidTransmit(  "GET http://" );
		MUSART1_voidTransmit( Copy_u8ChannelID ); //WEBSITE that will write in the request to accuses
		MUSART1_voidTransmit( "/number_pages.txt\r\n" );
		data=(u8) MUART_u8Recieve();

		state=validate();
	}
	/*PART OF CODE TO EXTRACT NUMBER OF PAGES FROM ARRAY*/
	volatile u8 i=0;
	do{
		data=ResponseArray[i];
		i++;
	}while(data!=':');

	page_number_1=((u8)ResponseArray[i]-48);
	page_number_2=((u8)ResponseArray[i+1]-48);
	page_number=((page_number_1*10)+page_number_2);

	return page_number;


}
void ESP8266_u8SendHttpReq( u8 * Copy_u8PageID ){
	//u8 data=0;
	u8 state=0;
	while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");

		WIFImod_SendCharsNumbers("75");
		//MSTK_voidSetBusyWait(3000000);

		/*SEND REQUEST TO PHP WITH NUMBER OF PAGE I WANT TO READ */
		MUSART1_voidTransmit(  "GET /script.php?command=1&page_no=");
		MUSART1_voidTransmit(Copy_u8PageID); // no. of page want to get data from
		MUSART1_voidTransmit(" HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n" );
		//MUSART1_voidTransmit(  "GET /test.php?apples=56&oranges=23 HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n" );
		state=validate();
	}
	 WIFI_Array_Clear();

}
void ESP8266_u8SendHttpReq_clear_buffer( void ){

	u8 state=0;
	while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");

		WIFImod_SendCharsNumbers("65");
		//MSTK_voidSetBusyWait(3000000);

		/*SEND REQUEST TO PHP WITH NUMBER OF PAGE I WANT TO READ */
		MUSART1_voidTransmit(  "GET /script.php?command=2 HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n");
		state=validate();
	}
	 WIFI_Array_Clear();

}
void ESP8266_u8SendHttpReq_overpage( u8 * Copy_u8PageID ){
	//u8 data=0;
	u8 state=0;
	while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");

		WIFImod_SendCharsNumbers("76");
		//MSTK_voidSetBusyWait(3000000);

		/*SEND REQUEST TO PHP WITH NUMBER OF PAGE I WANT TO READ */
		MUSART1_voidTransmit(  "GET /script.php?command=1&page_no=");
		MUSART1_voidTransmit(Copy_u8PageID); // no. of page want to get data from
		MUSART1_voidTransmit(" HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n" );
		//MUSART1_voidTransmit(  "GET /test.php?apples=56&oranges=23 HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n" );
		state=validate();
	}
	 WIFI_Array_Clear();

}
static u8 validate(void)
{
	u16 counter=0;
	u8 temp=0;
	while(temp!=130)
	{
		temp= MUART_u8Recieve();
		ResponseArray[counter]=temp;
		//MUSART1_voidTransmit(temp);
		counter++;
	}
	//CHECKING FOR RESPONE->OK
	//WIFICONNECTED //WIFI GOT IP
	if((ResponseArray[counter-21]=='C' )&&(ResponseArray[counter-20]=='O'))
	{
		return 1;
	}
	//Checking that we receive data and connection close

	else if((ResponseArray[29]== '+')&& (ResponseArray[30]=='I') ||(ResponseArray[30]== '+')&& (ResponseArray[31]=='I'))

	{
		return 2;

	}
	else if((ResponseArray[counter-5]== 'O')&& (ResponseArray[counter-4]=='K'))
	{
		return 2;

	}
	//Checking for GOT IP
	else if((ResponseArray[counter-7]== 'O') && (ResponseArray[counter-6]=='K')){
		return 3;

	}
	else
	{
		return 0;

	}
}
/*
static u8 result(void){
	u8 ResponseArray[30]={0};


	u8 counter=0;
	u8 temp=0;
	while(temp!=130)
	{
		temp= MUART_u8Recieve();
		ResponseArray[counter]=temp;
		counter++;
	}
	return ResponseArray[7] ;

}
*/
