/*************************************************
* AUTHOR : Mario Refaat
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: ADC_Interface.h
**************************************************/
#ifndef __ADC__INTERFACE__H
#define __ADC__INTERFACE__H


#define PRESCALER_2			0
#define PRESCALER_4			1
#define PRESCALER_8			2
#define PRESCALER_16		3
#define PRESCALER_32		4
#define PRESCALER_64		5
#define PRESCALER_128		6

#define INTERNAL_OFF		0
#define EXTERNAL_AVCC		1
#define RESERVED			2
#define INTERNAL_VOLTAGE	3

#define	RIGHT_ADJ			0
#define	LEFT_ADJ			1

#define FREE_RUNNING_MODE				0
#define ANALOG_COMPARATOR_MODE			1
#define EXTERNAL_INTERRUPT_MODE			2
#define TIMER0_COMP_MODE				3
#define TIMER0_OVF_MODE					4
#define TIMER1_COMP_B_MODE				5
#define TIMER1_OVF_MODE					6
#define TIMER1_CAPTURE_EVENT_MODE		7






void ADC_VoidInit(void);


u16 ADC_U16GetChannelReading(u8 Channel);


/*void ADC_Enable(void);

void ADC_Disable(void);*/

/*void ADC_SelectChannel(u8 Copy_U8Channel);

void ADC_Read(u16 * Copy_ReadValue);

void ADC_InterruptFlagPolling(void);*/




#endif
