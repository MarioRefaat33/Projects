/************************************************************/ 
/* 	LCD_Program.c											*/
/*                                                          */
/*  Created on	: Jan 26, 2021                              */
/*  Author		: Abanoub Raouf                             */
/*	version		: version 2                                 */
/*	LCD_version	: LMB161A									*/
/************************************************************/ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_Init.h"
#include "../../MCAL/SYSTICK/SysTick_Init.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Confg.h"


#if (mode==8)
void LCD_VidSendCommand(u8 copy_u8Command)
{

	GPIO_VidSetPinValue(Control_Port_RS,RS,GPIO_LOW);
	GPIO_VidSetPinValue(Control_Port_RW,RW,GPIO_LOW);


	GPIO_VidSetPinValue(Data_Port_PIN0,D0,(GET_BIT(copy_u8Command,0)));
	GPIO_VidSetPinValue(Data_Port_PIN1,D1,(GET_BIT(copy_u8Command,1)));
	GPIO_VidSetPinValue(Data_Port_PIN2,D2,(GET_BIT(copy_u8Command,2)));
	GPIO_VidSetPinValue(Data_Port_PIN3,D3,(GET_BIT(copy_u8Command,3)));
	GPIO_VidSetPinValue(Data_Port_PIN4,D4,(GET_BIT(copy_u8Command,4)));
	GPIO_VidSetPinValue(Data_Port_PIN5,D5,(GET_BIT(copy_u8Command,5)));
	GPIO_VidSetPinValue(Data_Port_PIN6,D6,(GET_BIT(copy_u8Command,6)));
	GPIO_VidSetPinValue(Data_Port_PIN7,D7,(GET_BIT(copy_u8Command,7)));
	
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_HIGH);     //enable pin
	__delay_ms(1);
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_LOW);
	__delay_ms(1);
}
void LCD_VidInt(void)
{
	
	GPIO_VidSetPinDirection(Data_Port_PIN0,D0,GPIO_OUTPUT_SPEED_2M_PP);	//make pin0 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN1,D1,GPIO_OUTPUT_SPEED_2M_PP);	//make pin1 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN2,D2,GPIO_OUTPUT_SPEED_2M_PP);	//make pin2 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN3,D3,GPIO_OUTPUT_SPEED_2M_PP);	//make pin3 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN4,D4,GPIO_OUTPUT_SPEED_2M_PP);	//make pin4 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN5,D5,GPIO_OUTPUT_SPEED_2M_PP);	//make pin5 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN6,D6,GPIO_OUTPUT_SPEED_2M_PP);	//make pin6 connect to LCD output
	GPIO_VidSetPinDirection(Data_Port_PIN7,D7,GPIO_OUTPUT_SPEED_2M_PP);	//make pin7 connect to LCD output
	
	
	
	GPIO_VidSetPinDirection(Control_Port_E,E,GPIO_OUTPUT_SPEED_2M_PP);//make enable pin out
	GPIO_VidSetPinDirection(Control_Port_RS,RS,GPIO_OUTPUT_SPEED_2M_PP);//make RS pin out
	GPIO_VidSetPinDirection(Control_Port_RW,RW,GPIO_OUTPUT_SPEED_2M_PP);//make RW pin out

	__delay_ms(40);
	LCD_VidSendCommand(0b00111000);
	__delay_ms(1);
	LCD_VidSendCommand(0b00001100);
	__delay_ms(1);
	LCD_VidSendCommand(0b00000001);
	__delay_ms(2);
}

void LCD_VidSendData(u8 copy_u8Data)
{
	
	GPIO_VidSetPinValue(Control_Port_RS,RS,GPIO_HIGH); //RS=1
	GPIO_VidSetPinValue(Control_Port_RW,RW,GPIO_LOW);  //RW=0

	GPIO_VidSetPinValue(Data_Port_PIN0,D0,(GET_BIT(copy_u8Data,0)));
	GPIO_VidSetPinValue(Data_Port_PIN1,D1,(GET_BIT(copy_u8Data,1)));
	GPIO_VidSetPinValue(Data_Port_PIN2,D2,(GET_BIT(copy_u8Data,2)));
	GPIO_VidSetPinValue(Data_Port_PIN3,D3,(GET_BIT(copy_u8Data,3)));
	GPIO_VidSetPinValue(Data_Port_PIN4,D4,(GET_BIT(copy_u8Data,4)));
	GPIO_VidSetPinValue(Data_Port_PIN5,D5,(GET_BIT(copy_u8Data,5)));
	GPIO_VidSetPinValue(Data_Port_PIN6,D6,(GET_BIT(copy_u8Data,6)));
	GPIO_VidSetPinValue(Data_Port_PIN7,D7,(GET_BIT(copy_u8Data,7)));	

	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_HIGH);//enable pin
	__delay_ms(1);
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_LOW);
	__delay_ms(1);
}
void LCD_VidSendString(u8 copy_u8String[100])
{
	u8 i=0;
	while (copy_u8String[i]!='\0')
		{
			LCD_VidSendData(copy_u8String[i]);
			i++;
		}
}
void LCD_VidSetPositin (u8 row,u8 coulmn)
{
	if(row==0)
		LCD_VidSendCommand (128+coulmn);
	else
		LCD_VidSendCommand (128+64+coulmn);
}
void LCD_VidWriteNumber (s32 x)
{
	s32 y=x;
	u8 counter=0,arr[16];
	if (x<0)
	{
		x=x*-1;
		LCD_VidSendData('-');
		y=x;
	}
	while(y!=0)
	{
		counter++;
		y=y/10;
	}
	if(x==0)
	{
		counter=1;
	}
	for(u8 i=0;i<counter;i++)
	{
		arr[i]=x%10;
		x=x/10;
	}
	for (s8 j=counter-1;j>=0;j--)
	{
		LCD_VidSendData(48+arr[j]);
	}
}
#elif (mode==4)
void LCD_VidSendCommand_FourBit(u8 copy_u8Command)
{
	STK_VidInit();
	u8 copy_u8HalfCommand;
	GPIO_VidSetPinValue(Control_Port_RS,RS,GPIO_LOW); //RS=0      
	GPIO_VidSetPinValue(Control_Port_RW,RW,GPIO_LOW); //RW=0      

	copy_u8HalfCommand=(copy_u8Command & 0xF0);

	GPIO_VidSetPinValue(Data_Port_PIN4,D4,(GET_BIT(copy_u8HalfCommand,4)));
	GPIO_VidSetPinValue(Data_Port_PIN5,D5,(GET_BIT(copy_u8HalfCommand,5)));
	GPIO_VidSetPinValue(Data_Port_PIN6,D6,(GET_BIT(copy_u8HalfCommand,6)));
	GPIO_VidSetPinValue(Data_Port_PIN7,D7,(GET_BIT(copy_u8HalfCommand,7)));
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_HIGH);     //enable pin
	_delay_ms(1);
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_LOW);
	_delay_ms(1);

	copy_u8HalfCommand=(copy_u8Command << 4);

	GPIO_VidSetPinValue(Data_Port_PIN4,D4,(GET_BIT(copy_u8HalfCommand,4)));
	GPIO_VidSetPinValue(Data_Port_PIN5,D5,(GET_BIT(copy_u8HalfCommand,5)));
	GPIO_VidSetPinValue(Data_Port_PIN6,D6,(GET_BIT(copy_u8HalfCommand,6)));
	GPIO_VidSetPinValue(Data_Port_PIN7,D7,(GET_BIT(copy_u8HalfCommand,7)));
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_HIGH);     //enable pin
	_delay_ms(1);
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_LOW);
	_delay_ms(1);
}
void LCD_VidInt_FourBit(void)
{

	GPIO_VidSetPinDirection(Data_Port_PIN4,D4,GPIO_OUTPUT_SPEED_2M_PP);
	GPIO_VidSetPinDirection(Data_Port_PIN5,D5,GPIO_OUTPUT_SPEED_2M_PP);
	GPIO_VidSetPinDirection(Data_Port_PIN6,D6,GPIO_OUTPUT_SPEED_2M_PP);
	GPIO_VidSetPinDirection(Data_Port_PIN7,D7,GPIO_OUTPUT_SPEED_2M_PP);
	
	GPIO_VidSetPinDirection(Control_Port_E,E,GPIO_OUTPUT_SPEED_2M_PP);//make enable pin out
	GPIO_VidSetPinDirection(Control_Port_RS,RS,GPIO_OUTPUT_SPEED_2M_PP);//make RS pin out
	GPIO_VidSetPinDirection(Control_Port_RW,RW,GPIO_OUTPUT_SPEED_2M_PP);//make RW pin out
	_delay_ms(40);

	LCD_VidSendCommand_FourBit(0x02);
	LCD_VidSendCommand_FourBit(0x28);
	_delay_ms(1);
	LCD_VidSendCommand_FourBit(0x0c);
	_delay_ms(1);
	LCD_VidSendCommand_FourBit(0x01);
	_delay_ms(2);
}
void LCD_VidSendData_FourBit(u8 copy_u8Data)
{
	u8 copy_u8HalfData;
	GPIO_VidSetPinValue(Control_Port_RS,RS,GPIO_HIGH); //RS=1      B2
	GPIO_VidSetPinValue(Control_Port_RW,RW,GPIO_LOW); //RW=0      B1
	
	copy_u8HalfData=(copy_u8Data & 0xF0);

	GPIO_VidSetPinValue(Data_Port_PIN4,D4,(GET_BIT(copy_u8HalfData,4)));
	GPIO_VidSetPinValue(Data_Port_PIN5,D5,(GET_BIT(copy_u8HalfData,5)));
	GPIO_VidSetPinValue(Data_Port_PIN6,D6,(GET_BIT(copy_u8HalfData,6)));
	GPIO_VidSetPinValue(Data_Port_PIN7,D7,(GET_BIT(copy_u8HalfData,7)));

	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_HIGH);//enable pin
	_delay_ms(1);
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_LOW);
	_delay_ms(1);

	copy_u8HalfData=(copy_u8Data << 4);

	GPIO_VidSetPinValue(Data_Port_PIN4,D4,(GET_BIT(copy_u8HalfData,4)));
	GPIO_VidSetPinValue(Data_Port_PIN5,D5,(GET_BIT(copy_u8HalfData,5)));
	GPIO_VidSetPinValue(Data_Port_PIN6,D6,(GET_BIT(copy_u8HalfData,6)));
	GPIO_VidSetPinValue(Data_Port_PIN7,D7,(GET_BIT(copy_u8HalfData,7)));
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_HIGH);//enable pin
	_delay_ms(1);
	GPIO_VidSetPinValue(Control_Port_E,E,GPIO_LOW);
	_delay_ms(1);
	
}
void LCD_VidSendString_FourBit(u8 copy_u8String[100])
{
	u8 i=0;
	while (copy_u8String[i]!='\0')
		{
			LCD_VidSendData_FourBit(copy_u8String[i]);
			i++;
		}
}
void LCD_VidSetPositin_FourBit (u8 row,u8 coulmn)
{
	if(row==0)
		LCD_VidSendCommand_FourBit(128+coulmn);
	else
		LCD_VidSendCommand_FourBit(128+64+coulmn);
}
void LCD_VidWriteNumber_FourBit (s32 x)
{
	s32 y=x;
	u8 counter=0,arr[16];
	if (x<0)
	{
		x=x*-1;
		LCD_VidSendData_FourBit('-');
		y=x;
	}
	while(y!=0)
	{
		counter++;
		y=y/10;
	}
	if(x==0)
	{
		counter=1;
	}
	for(u8 i=0;i<counter;i++)
	{
		arr[i]=x%10;
		x=x/10;
	}
	for (s8 j=counter-1;j>=0;j--)
	{
		LCD_VidSendData_FourBit(48+arr[j]);
	}
}
#endif



