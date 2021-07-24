/***	LIBRARY LAYER	***/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/AVR_Reg.h"

/***	MICROCONTROLLER ABSTRACTION LAYER	***/
#include "UART_cfg.h"
#include "UART.h"

uint8_t UART_init()
{
	/*****                           OPERATING MODE                              *****/
#if MODE == ASYNCHRONOUS_NORMAL_MODE
#define MYUBRR (FOSC/16/BAUDRATE)-1
#elif MODE == ASYNCHRONOUS_DOUBLE_SPEED_MODE
#define MYUBRR (FOSC/8/BAUDRATE)-1
#elif MODE == SYNCHRONOUS_MASTER_MODE
#define MYUBRR (FOSC/2/BAUDRATE)-1
#else
	return ERROR;
#endif

	UBRRL = (uint8_t)(MYUBRR); //Send the low 8 bits of the UBRR
	UBRRH = (uint8_t)( (MYUBRR) >> 8 ); //Send the high 4 bits of the UBRR

	SET_BIT(UCSRC,BIT_NO_7); //To allow writing in UCSRC instead of UBRRH
	SET_BIT(UCSRB,BIT_NO_3); //Enable Transmission
	SET_BIT(UCSRB,BIT_NO_4); //Enable Receiving


	/*****                           DATA BITS                                  *****/
#if DATA_BITS == UART_5_DATA_BITS
	//Nothing need to be done, bits are set to 0 by default
#elif DATA_BITS == UART_6_DATA_BITS
	SET_BIT(UCSRC,BIT_NO_1);
#elif DATA_BITS == UART_7_DATA_BITS
	SET_BIT(UCSRC,BIT_NO_2);
#elif DATA_BITS == UART_8_DATA_BITS
	SET_BIT(UCSRC,BIT_NO_1);
	SET_BIT(UCSRC,BIT_NO_2);
#elif DATA_BITS == UART_9_DATA_BITS
	SET_BIT(UCSRB,BIT_NO_2);
	SET_BIT(UCSRC,BIT_NO_1);
	SET_BIT(UCSRC,BIT_NO_2);
#else
	return ERROR;
#endif

	/*****                           STOP BITS                              *****/
#if	STOP_BITS == UART_ONE_STOP_BIT
	//One stop bit - bit is set to 0 by default
#elif STOP_BITS == UART_TWO_STOP_BIT
	SET_BIT(UCSRC,BIT_NO_3); //Two stop bits
#else
	return ERROR;
#endif

	/*****                           PARITY MODE                             *****/
#if PARITY == UART_PARITY_EVEN
	SET_BIT(UCSRC,BIT_NO_5);
	CLEAR_BIT(UCSRC,BIT_NO_4);
#elif PARITY == UART_PARITY_ODD
	SET_BIT(UCSRC,BIT_NO_5);
	SET_BIT(UCSRC,BIT_NO_4);
#elif PARITY == UART_NO_PARITY
	//No parity - bits are set to 0 by default
#else
	return ERROR;
#endif

#if FLAG_ACTION == UART_INTERRUPT
	SET_BIT(UCSRB, BIT_NO_7);
	SREG |= (1<<7);
#elif FLAG_ACTION == UART_POLLING
	/* RXCIE and TXCIE Initially zero */
#else
	return ERROR;
#endif

	return NO_ERROR;
}
/*************************************************************/

/*************************************************************
 *Description: Sending byte of data
 * Input     : u16Data to send
 * Output    : Error Status
 * */

uint8_t UART_sendByte(const uint8_t u8_Data)
{
	//Wait until buffer is empty
	while ( BIT_IS_CLEAR(UCSRA,BIT_NO_5) );
	UDR = u8_Data;
	return NO_ERROR;
}
/*************************************************************/

/*************************************************************
 *Description: Receiving byte of data
 * Input     : pointer to u16Data
 * Output    : Error Status
 * */
uint8_t UART_recieveByte(uint8_t *u8_Data)
{
	if (u8_Data == NULL)
	{
		return ERROR;
	}
	//Wait until receiving is complete
	while ( BIT_IS_CLEAR(UCSRA,BIT_NO_7) );
	*u8_Data = UDR;
	return NO_ERROR;
}
/*************************************************************/

/*************************************************************
 *Description: Receiving Flag used in Case of Polling
 * Input     : pointer to u8Data
 * Output    : Return ERROR status
 * */
extern uint8_t UART_GetPollingFlag(uint8_t *u8_Data)
{
	uint8_t PollingFlag ;

	if (u8_Data != NULL)
	{
		PollingFlag = (UCSRA >> BIT_NO_7);          //PollingFlag indicates if the UART Receive Complete flag is set or not
		*u8_Data    = PollingFlag;            //Return Flag value
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}

}

/*************************************************************/
