/*** LIBRARY LAYER ***/
#include "../LIB/STD_TYPES.h"

/*** HARDWARE ABSTRACTION LAYER ***/
#include "header.h"

/*** HARDWARE ABSTRACTION LAYER ***/
#include "../HAL/LCD/LCD.h"
#include "../HAL/Motor/Motor.h"

/*** MICROCONTROLLER ABSTRACTION LAYER ***/
#include "../MCAL/UART/UART.h"
#include "../MCAL/UART/UART_reg.h"
#include "../MCAL/PWM/PWM.h"


/* A variable to store current duty cycle */
volatile uint8_t currentDutyCycle;

/* ISR function to assign the received duty cycle from microcontroller 1 */
void ISR_UART_RXC (void)
{
	currentDutyCycle = UDR;
}

int main ()
{
	/********   UART INITIALIZATION  		********/
	UART_init();
	/********   PWM INITIALIZATION  		********/
	PWM0_init();
	/********   MOTOR INITIALIZATION  		********/
	Motor_Init();
	/********   LCD INITIALIZATION  		********/
	LCD_init();

	uint8_t maxFlag = RESET_FLAG; /* Flag to be fired if duty cycle reached 100% */
	LCD_displayString("Duty Cycle: "); /* Begin displaying on the LCD */

	while (1)
	{
		Motor_SetDutyCycle(currentDutyCycle);

		if (currentDutyCycle == MAXIMUM_DUTY_CYCLE)
		{
			maxFlag = SET_FLAG;
		}
		LCD_integerToString(currentDutyCycle); /* Display the current duty cycle on LCD */
		LCD_displayCharacter('%');
		LCD_goToRowColumn(FIRST_ROW,THIRTEENTH_COLUMN);

		/* If duty cycle was 100% before, remove additional '%' character */
		if (maxFlag == SET_FLAG && currentDutyCycle != MAXIMUM_DUTY_CYCLE)
		{
			LCD_goToRowColumn(FIRST_ROW,SIXTEENTH_COLUMN);
			LCD_displayCharacter(' ');
			maxFlag = RESET_FLAG; /* To avoid entering the if body uselessly */
		}
		/* If duty cycle is equal 0%, remove additional '%' character */
		if (currentDutyCycle == MINIMUM_DUTY_CYCLE)
		{
			LCD_goToRowColumn(FIRST_ROW,FIFTEENTH_COLUMN);
			LCD_displayCharacter(' ');
		}
		LCD_goToRowColumn(FIRST_ROW,THIRTEENTH_COLUMN);
	}

	return 0;
}
