/*************************************************
 * AUTHOR :  Moataz Tarek -Mario refaat - Abanob Raoof - Amira Moustafa
 * Date   : 8/3/2021
 * VERION : V0.8
 * DISCRIPTION: WIFI_Pragram.c
 **************************************************/

#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "USART_interface.h"
#include "ESP_Private.h"
#include "ESP_Interface.h"
#include "STK_Interface.h"
#include "DIO_Interface.h"

u8 ResponseArray[10000]={0};
u16  counter = 0;
void MUSART_CallBack(void){
	ResponseArray[counter] =   MUART_u8Recieve();
	/*if (Iterator== 200){
		Iterator=0;
	}*/
	counter++;
	MUSART1_VidClearFlags();

}


void WIFImod_voidInit(void){
	MUSART1_voidSetCallBack(MUSART_CallBack);
	u8 state=0;
	/*while (state==0){
		MUSART1_voidTransmit("AT\r\n");
		MSTK_voidSetBusyWait( 3000000 );

		state=validate();
	}
	state=0;*/
	counter=0;

	while (state==0){
		MUSART1_voidTransmit("AT+CWMODE=3\r\n");
		MSTK_voidSetBusyWait( 3000000 );
		state=validate();
	}
	state=0;
	counter=0;


	while (state==0){
		MUSART1_voidTransmit("AT+CIPMODE=0\r\n");
		MSTK_voidSetBusyWait( 3000000 );
		state=validate();
	}

}

void WIFImod_ConnectToNetwork(char* SSID,char* Password){
	u8 state=0;
	counter=0;

	while (state==0){
		MUSART1_voidTransmit("AT+CWJAP=\"" );
		MUSART1_voidTransmit( SSID );
		MUSART1_voidTransmit(  "\",\"" );
		MUSART1_voidTransmit(  Password);
		MUSART1_voidTransmit(  "\"\r\n");
		MSTK_voidSetBusyWait( 5000000 );
		state=validate();

	}
}

void WIFImod_ConnectToServer(char* Copy_u8Domain, char* Copy_u8Port){
	u8 state=0;
	counter=0;

	 while (state==0){
		MUSART1_voidTransmit(  "AT+CIPSTART=\"TCP\",\"" );
		MUSART1_voidTransmit(  Copy_u8Domain );
		MUSART1_voidTransmit(  "\"," );
		MUSART1_voidTransmit( Copy_u8Port );
		MUSART1_voidTransmit(  "\r\n" );
		MSTK_voidSetBusyWait( 3000000 );

		state=validate();
	}
}
void WIFImod_SendCharsNumbers(char * Copy_u8Length ){
	u8 state=0;
	counter=0;

	 if (state==0){
		MUSART1_voidTransmit(  "AT+CIPSEND=" );
		MUSART1_voidTransmit( Copy_u8Length );
		MUSART1_voidTransmit(  "\r\n" );
		MSTK_voidSetBusyWait( 3000000 );

		//state=validate();
	}
}
void ESP8266_u8ReceiveHttpReq( char * Copy_u8ChannelID ){
	u8 state=0;
	counter=0;

	 while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");
		WIFImod_SendCharsNumbers("43" );
		MUSART1_voidTransmit(  "GET http://" );
		MUSART1_voidTransmit( Copy_u8ChannelID );
		MUSART1_voidTransmit( "/buffer.txt\r\n" );
		MSTK_voidSetBusyWait( 90000000 );
		state=validate();
	}
}
u16 ESP8266_u8ReceivePageNumber(char * Copy_u8ChannelID){
	 u8  page_number_1=0;
	 u8 page_number_2=0;
	 u8 i=0;
	u8 data=0;
	u16 page_number=0;
	u8 state=0;
	 while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");
		WIFImod_SendCharsNumbers("49" );
		MUSART1_voidTransmit(  "GET http://" );
		MUSART1_voidTransmit( Copy_u8ChannelID );
		MUSART1_voidTransmit( "/number_pages.txt\r\n" );
		MSTK_voidSetBusyWait( 80000000 );
		state=validate();
	}
	do{
		data=ResponseArray[i];
		i++;
	}while(data!=':');
	page_number_1=((u8)ResponseArray[i]-48);
	page_number_2=((u8)ResponseArray[i+1]-48);
	page_number=((page_number_1*10)+page_number_2);
	return page_number;
}
void ESP8266_u8SendHttpReq( char * Copy_u8PageID ){
	u8 state=0;
	 while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");
		WIFImod_SendCharsNumbers("75");
		MUSART1_voidTransmit(  "GET /script.php?command=1&page_no=");
		MUSART1_voidTransmit(Copy_u8PageID);
		MUSART1_voidTransmit(" HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n" );
		MSTK_voidSetBusyWait( 4000000 );

		state=validate();
	}


}
void ESP8266_u8SendHttpReq_clear_buffer( void ){

	u8 state=0;
	counter=0;

	 while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");
		WIFImod_SendCharsNumbers("65");
		MUSART1_voidTransmit(  "GET /script.php?command=2 HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n");
		MSTK_voidSetBusyWait( 20000000 );
		state=validate();
	}

}
void ESP8266_u8SendHttpReq_overpage(char * Copy_u8PageID ){
	u8 state=0;
	 while (state==0){
		WIFImod_ConnectToServer("162.253.155.226", "80");
		WIFImod_SendCharsNumbers("76");
		MUSART1_voidTransmit(  "GET /script.php?command=1&page_no=");
		MUSART1_voidTransmit(Copy_u8PageID);
		MUSART1_voidTransmit(" HTTP/1.1\r\nHost: abanoub.freevar.com\r\n\r\n" );
		MSTK_voidSetBusyWait( 3000000 );
		state=validate();
	}

}

static u8 validate(void)
{
	//u8 temp=0;
	/*while(temp!=130)
	{
		temp= MUART_u8Recieve();
		ResponseArray[counter]=temp;
		counter++;
	}*/
	if((ResponseArray[counter-21]=='C' )&&(ResponseArray[counter-20]=='O')){
		return 1;
	}
	else if(((ResponseArray[54]== '+') && (ResponseArray[55]=='I') )|| ((ResponseArray[30]== '+')&& (ResponseArray[31]=='I'))){
		return 2;
	}
	else if(((ResponseArray[counter-4]== 'O')&& (ResponseArray[counter-3]=='K'))){
		return 2;
	}
	else if((ResponseArray[counter-7]== 'O') && (ResponseArray[counter-6]=='K')){
		return 3;
	}
	else{
		return 0;
	}
}

