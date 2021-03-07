/*************************************************
 * AUTHOR : Amira_moustafa Mario_Refaat Moataz_Tarek
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: Microwave_system.h
 **************************************************/
#include "../APP/APP_Microwave_Config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/Keypad_Interface.h"
#include "../HAL/SENSORS/POT/POT_Interface.h"
#include "../HAL/SENSORS/LM35/LM_35_Interface.h"
#include "../MCAL/TIMER/Timer0/Timer_Interface.h"
#include "../MCAL/TIMER/Timer1/timer1_Interface.h"
#include "../HAL/MOTORS/MOTOR_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/BUZZERS/Buzzer_Interface.h"
#include "../MCAL/INTERRUPT/EXIT_Interface.h"
#include "util/delay.h"


u8 Time_value[4]={0};
u8 hours_count = 0;
Time_t microwave_time ;

/******************************************************/
/*          STATIC function prototype                */
/****************************************************/
static u8   power(u8 num , u8 power);
static void Prepare_Time(void);
static void Check_door();
static void Check_weight(void);
static void check_temp(void);
static void System_Stop(void);
static void TurnON_Heater_Fan(u8 copy_u8dutycycle);
static void Time_Update(void);
static void GETTIME(void);
static void System_Cancel(void);

void System_voidInit(void){
	LCD_voidInit();
	SetCallBack(&Time_Update);
	POT_VoidInit();
	LM35_VoidInit();
	MOTOR_voidInit();
	LED_voidInitLed(DIO_PORTD,DIO_PIN0);
	LED_voidInitLed(DIO_PORTD,DIO_PIN1);
	LED_voidInitLed(DIO_PORTD,DIO_PIN3);
	LED_voidOffLed(DIO_PORTD,DIO_PIN0);
	LED_voidOffLed(DIO_PORTD,DIO_PIN1);
	LED_voidOffLed(DIO_PORTD,DIO_PIN3);
	Buzzer_voidInit();
	Buzzer_voidOff();
	EXIT_VidInit();
	EXIT0_Enable();
	timer1_init();
	VECT_INT0_CallBack (&System_Cancel); /*initiate call back function*/
}

void MicroWave_voidStart(void){
	LCD_voidgotorowcolum(0,0);
	LCD_voidSendString("****Welcome****");
	LED_voidOnLed(DIO_PORTD,DIO_PIN1);  /*led yallow to indicate microwave don't turn on*/
	LED_voidOffLed(DIO_PORTD,DIO_PIN3);  /*led green to indicate microwave don't turn on*/
	LED_voidOffLed(DIO_PORTD,DIO_PIN0);  /*led red to indicate microwave don't turn on*/
	_delay_ms(2000);
	Check_weight();
}

static void GETTIME(void){
	LCD_voidgotorowcolum(0,0);
	LCD_voidSendString("ENTER TIME:");
	LCD_voidgotorowcolum(1,5);

	Time_value[0]=KeyPad_getPressedKey(); /*get first digit of min*/
	LCD_1ByteToString(Time_value[0]);

	Time_value[1]=KeyPad_getPressedKey(); /*get second digit of min*/
	LCD_1ByteToString(Time_value[1]);

	LCD_voidSendData(':');


	Time_value[2]=KeyPad_getPressedKey(); /*get first digit of sec*/
	LCD_1ByteToString(Time_value[2]);

	Time_value[3]=KeyPad_getPressedKey();  /*get second digit of sec*/
	LCD_1ByteToString(Time_value[3]);

    _delay_ms(1000);
	Prepare_Time();     /*prepare time which the user entered it*/
	LCD_voidSendCommand(0x01);
	check_temp();

}

static void Check_weight(void){
	LCD_voidSendCommand(0x01);
	while ( POT_U16Read(1) == 0){
		LCD_displayStringRowColum(0,0,"pls Enter Food");
	}
	Check_door();
}

static void check_temp(void){
	u8 temp =0;
	LCD_displayStringRowColum(0,0,"pls Enter Temp");
	_delay_ms(000);
	temp = LM35_U16Read(2);
	LCD_voidSendCommand(0x01);
	LCD_displayStringRowColum(0,0,"temp is ");
	LCD_1ByteToString(temp);
	_delay_ms(2000);
	TurnON_Heater_Fan(temp);
}

static void TurnON_Heater_Fan(u8 copy_u8dutycycle){

	while(KeyPad_getPressedKey() != '=');
	MOTOR_voidGeneratePWM(copy_u8dutycycle);
	MOTOR_voidRotateClkWise(1,0);
	LED_voidOffLed(DIO_PORTD,DIO_PIN1);
	LED_voidOffLed(DIO_PORTD,DIO_PIN3);
	LED_voidOnLed(DIO_PORTD,DIO_PIN0);
	LCD_voidSendCommand(0x01);
	LCD_displayStringRowColum(0,0,"The Reset Time");
	Timer0_voidInit();
	Time_Update();
}



static void Check_door(){
	LCD_voidSendCommand(0x01);
	while( POT_U16Read(0) < 5000){
		LCD_displayStringRowColum(0,0,"Pls Close Door");
	}
	LCD_voidSendCommand(0x01);
	LCD_displayStringRowColum(0,0,"Door is Closed");
	_delay_ms(2000);
	LCD_voidSendCommand(0x01);
	GETTIME();


}
static void System_Stop(void){
	MOTOR_voidStop();
	MOTOR_voidGeneratePWM(0);
	LCD_voidSendCommand(0x01);
	LCD_voidgotorowcolum(0,2);
	LCD_voidSendString("happy meal");
	microwave_time.seconds_count=0;
	microwave_time.minutes_count=0;
	LED_voidOffLed(DIO_PORTD,DIO_PIN0);  /*LED GREEN OFF*/
	LED_voidOffLed(DIO_PORTD,DIO_PIN1);  /*LED YALLOW OFF*/
	LED_voidOnLed(DIO_PORTD,DIO_PIN3);   /*LED RED ON*/
	Buzzer_voidOn();
	_delay_ms(3000);
	Buzzer_voidOff();
	MicroWave_voidStart();

}

static void System_Cancel(void)
{
	MOTOR_voidGeneratePWM(0);
	LCD_voidSendCommand(0x01);
	LCD_voidgotorowcolum(0,2);
	LCD_voidSendString("System Reset");
	_delay_ms(1000);
	MOTOR_voidStop();
	_delay_ms(10);
	LED_voidOffLed(DIO_PORTD,DIO_PIN0);  /*LED GREEN OFF*/
	LED_voidOffLed(DIO_PORTD,DIO_PIN1);  /*LED YALLOW OFF*/
	LED_voidOffLed(DIO_PORTD,DIO_PIN3);   /*LED RED ON*/
	_delay_ms(10);
	microwave_time.seconds_count=0;
	microwave_time.minutes_count=0;
	Buzzer_voidOn();
	LCD_voidSendCommand(0x01);
	LCD_voidgotorowcolum(0,2);
	LCD_voidSendString("BBEB BEEB");
	_delay_ms(1000);
	Buzzer_voidOff();
	MicroWave_voidStart();

}

static void Time_Update(void){
	if(microwave_time.seconds_count == 0 && microwave_time.minutes_count == 0){
		System_Stop();
	}
	if(microwave_time.minutes_count == 0 &&microwave_time.seconds_count > 0 ){
		microwave_time.seconds_count--;
	}
	if(microwave_time.minutes_count > 0){
		if(microwave_time.seconds_count>0){
			microwave_time.seconds_count --;

		}
		if (microwave_time.seconds_count==0){
			microwave_time.seconds_count = 59;
			microwave_time.minutes_count--;
		}
	}
	if(microwave_time.seconds_count < 10 ){
		LCD_voidgotorowcolum(1,4);
		LCD_1ByteToString(0);
		LCD_1ByteToString(microwave_time.seconds_count);
	}

	if( microwave_time.minutes_count < 10  ){
		LCD_voidgotorowcolum(1,1);
		LCD_1ByteToString(0);
		LCD_1ByteToString(microwave_time.minutes_count);

	}
	LCD_voidgotorowcolum(1,3);
	if(microwave_time.minutes_count >= 10){
		LCD_1ByteToString(microwave_time.minutes_count);
	}
	LCD_voidSendData(':');
	if(microwave_time.seconds_count>= 10){
		LCD_1ByteToString(microwave_time.seconds_count);
	}
}
static void Prepare_Time(void){
	u8 x = 1;
	for(u8 k = 0;  k < 2 ; k++){
		microwave_time.minutes_count =microwave_time.minutes_count  + ( Time_value[k] * power(10,x));
		x--;
	}
	x = 1;
	for(u8 k = 2;  k < 4 ; k++){
		microwave_time.seconds_count =  microwave_time.seconds_count + ( Time_value[k] * power(10,x));
		x--;
	}

}
static u8 power(u8 num , u8 power){
	u8 result = 1;
	if(power == 1){
		return num;
	}
	else if(power ==0){
		return 1;
	}
	for(int i = 0; i<power; i++){
		result *= num;

	}
	return result;

}


