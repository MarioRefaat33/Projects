/*
 * ESP_Interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Al Badr
 */

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_

void WIFImod_voidInit(void);
void WIFImod_ConnectToNetwork(u8* SSID,u8* Password);
void WIFImod_ConnectToServer(u8* Copy_u8Domain, u8* Copy_u8Port);
void  WIFImod_SendCharsNumbers(u8 * Copy_u8Length );
void ESP8266_u8ReceiveHttpReq( u8 * Copy_u8ChannelID );
u16    ESP8266_u8ReceivePageNumber( u8 * Copy_u8ChannelID);
void    ESP8266_u8SendHttpReq( u8 * Copy_u8ChannelID );
void ESP8266_u8SendHttpReq_overpage( u8 * Copy_u8PageID );

#endif /* ESP_INTERFACE_H_ */
