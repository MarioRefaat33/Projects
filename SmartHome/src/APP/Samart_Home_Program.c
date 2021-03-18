/******************************************************************/
//	Author 	: Mahmoud Amr
//	Date 	: 10 March 2021
//	Version : V1
//	Module 	: Samart_Home_Module
/******************************************************************/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "Samart_Home_Interface.h" 
#include "Samart_Home_Config.h" 
#include "Samart_Home_Private.h" 

#include "../MCAL/RCC/RCC_Init.h"

#include "../HAL/TEMP_SENSOR/Temreture_Sensor_Interface.h"
#include "../HAL/SERVO/Servo_Interface.h"
#include "../HAL/IR/IR_Interface.h"
#include "../HAL/KEYPAD/KYPD_Init.h"
#include "../MCAL/SYSTICK/SysTick_Init.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LED/Led_Interface.h"
#include "../HAL/DC_MOTOR/Motor_Interface.h"
#include "../HAL/FLAME_SENSOR/Flame_Sensor_Interface.h"
#include "../HAL/Gas_Sensor/Gas_Sensor_Interface.h"
#include "../HAL/BUZZER/Buzzer_Interface.h"
#include "../MCAL/GPIO/GPIO_Init.h"
#include "../HAL/WIFI/ESP_Interface.h"
#include "../MCAL/NVIC/NVIC_Init.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/AFIO/AFIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"

u8 password_counter = 0;
u8 IR_Flag = 0,clear_flag = 1 ;
u8 GAS = 0, FLAME = 0;
extern u8 ResponseArray[10000]; /*array which contain the page of hexa  */




volatile u8  u8StartFlag      = 0 ;
volatile u32 u32FrameData[50] = {0};
volatile u8  u8EdgeCounter    = 0 ;
volatile u8 u8Data            = 0 ;


/* IR FUNCTIONS */
void voidPlay(void)
{


	switch (u8Data)
	{
	case ZER0_BUTTON :
		H_Led_Green_ON();
		LCD_VidSetPositin_FourBit(0,0);
		LCD_VidSendString_FourBit("Led_1 ON");
		break;

	case ONE_BUTTON :
		H_Led_Green_Off();
		LCD_VidSetPositin_FourBit(0,0);
		LCD_VidSendString_FourBit("Led_1 OFF");
		break;

	case TWO_BUTTON :
		H_Motor_On();
		LCD_VidSetPositin_FourBit(0,0);
		LCD_VidSendString_FourBit("Fan ON");
		break;

	case THREE_BUTTON:
		H_Motor_Off();
		LCD_VidSetPositin_FourBit(0,0);
		LCD_VidSendString_FourBit("Fan OFF");
		break;

	case FOUR_BUTTON:
		GAS =H_Gas_Sensor_Read();
		if (GAS == 1)
		{
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("Gas Detected !");
			H_Buzzer_ON();
			H_Led_Red_ON();
		}
		else
		{

			if (FLAME != 1)
			{
				H_Led_Red_Off();
				H_Buzzer_Off();
			}
		}
		break;

	case FIVE_BUTTON:
		FLAME = H_Flame_Sensor_Read();
		if (FLAME == 1)
		{
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("Fire Detected !");
			H_Led_Red_ON();
			H_Buzzer_ON();
		}
		else
		{
			if (GAS != 1)
			{
				H_Led_Red_Off();
				H_Buzzer_Off();
			}
		}
		break;

		/*NEW UPDATE ADD LED*/
	case SIX_BUTTON	:
		H_Led_Red_ON();
		LCD_VidSetPositin_FourBit(0,0);
		LCD_VidSendString_FourBit("New Led ON");
		break;

	case SEVEN_BUTTON:
		H_Led_Red_Off();
		LCD_VidSetPositin_FourBit(0,0);
		LCD_VidSendString_FourBit("New Led OFF");
		break;
	case EIGHT_BUTTON:

		break;

	default :
		break;
	}

	clear_flag = 1;
}
void TakeAction (void)
{
	//	asm("NOP");
	u8 i ;
	u8Data = 0 ;
	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for( i=0 ; i<8  ;i++ )
		{
			if((u32FrameData[17+i] >=2000)&&(u32FrameData[17+i] <=2300))
			{
				SET_BIT(u8Data,i);
			}
			else
			{

				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();
	}

	else
	{

	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void GetFrame(void)
{
	if (clear_flag == 1)
	{
		LCD_VidSendCommand_FourBit(LCD_CLEAR);
		clear_flag = 0;
	}

	//asm("NOP");
	if (u8StartFlag == 0)
	{
		// Start Timer
		STK_VidSetIntervalSignal(1000000,TakeAction);
		u8StartFlag = 1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = STK_U32GetElapsedTime();
		STK_VidSetIntervalSignal(1000000,TakeAction);
		u8EdgeCounter++;
	}
}

/* IR FUNCTIONS*/



void Smart_Home_Init()
{
	RCC_VidInit();
	// for servo
	RCC_VidEnableClock(RCC_APB1,RCC_APB1_TIM4);
	// for IR
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_IOPA);
	//for ADC
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_ADC1);
	/*enable clock for UART*/
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_USART);

	RCC_VidEnableClock(RCC_APB2,RCC_APB2_IOPB);
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_IOPC);
	RCC_VidEnableClock(RCC_APB2,RCC_APB2_AFIO);

	//Action_VidSetCallBack(IR_Action);

	/* IR */
	GPIO_VidSetPinDirection(GPIO_PORTA,0,0b1000);
	GPIO_VidSetPinValue(GPIO_PORTA,0,1);
	AFIO_voidSetEXTIConfiguration(EXTI0,0);
	NVIC_VidInit();
	STK_VidInit();

	H_Led_Init();
	KYP_VoidInit();
	H_Motor_Init();
	H_TEMP_Vid_Init();
	H_Gas_Sensor_Init();
	H_Flame_Sensor_Init();
	H_Buzzer_Init();



	LCD_VidInt_FourBit();
	LCD_VidSendCommand_FourBit(LCD_CLEAR);
	LCD_VidSendCommand_FourBit(LCD_SETCURSER0);

	Servo_Vid_Init();
	Servo_set_position(_DOOR_CLOSE);

	LCD_VidSetPositin_FourBit(0,0);
	LCD_VidSendString_FourBit("Hello");
	_delay_ms(2);
	LCD_VidSetPositin_FourBit(1,1);
	LCD_VidSendString_FourBit("There");
	_delay_ms(2000);
	LCD_VidSendCommand_FourBit(LCD_CLEAR);
	LCD_VidSendString_FourBit("SYSTEM LOCKED");
	LCD_VidSetPositin_FourBit(1,0);
	LCD_VidSendString_FourBit("Enter Password : ");

}

void Smart_Home()
{
	u8 LOCKED = 0, UNLOCKED = 1, IR_BTN = 0 ;


	extern  u8 password_status;

	if (password_status == UNLOCKED)
	{

		if (IR_Flag == 1 )
		{
			_delay_ms(2);
			LCD_VidSendCommand_FourBit(LCD_CLEAR);
			LCD_VidSendString_FourBit("Starting System");
			/*wifi init*/
			GPIO_VidSetPinDirection(GPIO_PORTA,9,0b1010);   /* TX AFPP */
			GPIO_VidSetPinDirection(GPIO_PORTA,10,0b0100);  /* RC Input Floating */
			NVIC_VidEnablePeripheralInterrupt(USART1_ID);              /*enable NVIC For uart*/
			MUSART1_voidInit();                         /*init UART */
			WIFImod_voidInit();

			WIFImod_ConnectToNetwork("Elsoudy 2","2512@WiFi97*152");
			LCD_VidSendCommand_FourBit(LCD_CLEAR);
			LCD_VidSendString_FourBit("Connected >>>");
			/*end of wifi init*/

			/*init iri*/
			EXTI0_voidSetCallBack(GetFrame);
			EXTI_voidInit(EXTI0,FALLING_EDGE);
			EXTI_voidEnable(EXTI0);
			NVIC_VidEnablePeripheralInterrupt(EXTI0_ID);
			/*end of ir init*/
			IR_Flag = 0;
		}

		// wifi get code frome server  code
		ESP8266_u8ReceiveHttpReq("abanoub.freevar.com");


		u8 i=0;
		u8 data, data_1,data_2,data_3,data_4;

		do{
			data=ResponseArray[i];
			i++;
		}while(data!=':');

		data_1=ResponseArray[i];
		data_2=ResponseArray[i+1];
		data_3=ResponseArray[i+2];
		data_4=ResponseArray[i+3];



		if(data_1=='0'){
			H_Led_Green_ON();
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("Led_1 ON        ");
		}
		else if(data_1=='1'){
			H_Led_Green_Off();
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("Led_1 OFF       ");
		}
		if (data_2=='2'){
			H_Motor_On();
			LCD_VidSetPositin_FourBit(0,0);			LCD_VidSendString_FourBit("Fan ON          ");
		}
		else if (data_2=='3'){
			H_Motor_Off();
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("Fan OFF         ");
		}
		if (data_3=='4'){
			GAS =H_Gas_Sensor_Read();
			if (GAS == 1)
			{
				LCD_VidSetPositin_FourBit(0,0);
				LCD_VidSendString_FourBit("Gas Detected !  ");
				H_Buzzer_ON();
				H_Led_Red_ON();
			}
			else
			{

				if (FLAME != 1)
				{
					H_Led_Red_Off();
					H_Buzzer_Off();
				}
			}

		}

		else if (data_3=='5')
		{
			FLAME = H_Flame_Sensor_Read();
			if (FLAME == 1)
			{
				LCD_VidSetPositin_FourBit(0,0);
				LCD_VidSendString_FourBit("Fire Detected ! ");
				H_Led_Red_ON();
				H_Buzzer_ON();
			}
			else
			{
				if (GAS != 1)
				{
					H_Led_Red_Off();
					H_Buzzer_Off();
				}
			}
		}
		/*NEW UPDATE ADD LED*/
		if(data_4 ==  '6')
		{
			H_Led_Red_ON();
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("New Led ON      ");
		}

		else if (data_4 ==  '7')
		{
			H_Led_Red_Off();
			LCD_VidSetPositin_FourBit(0,0);
			LCD_VidSendString_FourBit("New Led OFF    ");
		}

		//end of wifi code

	}
	else
	{
		if (password_counter < 3 && Get_Password()  )
		{
			password_status = UNLOCKED ;
			LCD_VidSendCommand_FourBit(LCD_CLEAR);
			LCD_VidSendString_FourBit("Unlocked");
			Servo_set_position(_DOOR_OPEN);
		}
		else
		{
			if(password_counter == 3)
			{

				LCD_VidSendString_FourBit("Max Exeeded");
				LCD_VidSetPositin_FourBit(1,0);
				LCD_VidSendString_FourBit("Reset System     ");
			}
			else
			{
				LCD_VidSendString_FourBit("Wrong Password ");
				LCD_VidSetPositin_FourBit(1,0);
				LCD_VidSendString_FourBit("Try Again :");
				password_status = LOCKED ;
				Servo_set_position(_DOOR_CLOSE);
			}
		}

	}
}

static u8 Get_Password()
{
	u8 password_arr[PASSWORD_LENGTH] ={0},check_arr[PASSWORD_LENGTH] = ENTRY_PASSWORD;
	u8 password = 0;
	for(int i = 0; i <PASSWORD_LENGTH; i++)
	{
		while(password_arr[i] == 0)
		{
			password_arr[i]= KYP_U8GetButton();

			if(password_arr[i] == check_arr[i])
			{
				password ++;
			}
		}
	}
	LCD_VidSendCommand_FourBit(LCD_CLEAR);

	if ( password == PASSWORD_LENGTH)
	{
		IR_Flag = 1;
		return 1 ;
	}
	else
	{
		password_counter ++ ;
		return 0;
	}

}
