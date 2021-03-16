/*
 * ESP_Interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Al Badr
 */

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_

void WIFImod_voidInit(void);
void WIFImod_ConnectToNetwork(char* SSID,char* Password);
void WIFImod_ConnectToServer(char* Copy_u8Domain, char* Copy_u8Port);
void WIFImod_SendCharsNumbers(char * Copy_u8Length );
void ESP8266_u8ReceiveHttpReq( char * Copy_u8ChannelID );
u16  ESP8266_u8ReceivePageNumber( char * Copy_u8ChannelID);
void ESP8266_u8SendHttpReq( char * Copy_u8ChannelID );
void ESP8266_u8SendHttpReq_overpage( char * Copy_u8PageID );
void ESP8266_u8SendHttpReq_clear_buffer( void );
void WIFI_Array_Clear(void);
void ESP8266_voidClearBuffer(void);

#endif /* ESP_INTERFACE_H_ */
