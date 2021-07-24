/*
 * LCD.h
 *
 *  Created on: Sep 4, 2020
 *      Author: H
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

/*
 * Poplar Commands For LCD
 */

#define CLEAR_COMMAND 0X01
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define FOUR_BITS_DATA_MODE 0x02
#define SET_CURSOR_LOCATION 0x80

#define FIRST_ROW 1
#define SECOND_ROW 2

#define FIRST_COLUMN 0
#define SECOND_COLUMN 1
#define THIRD_COLUMN 2
#define FOURTH_COLUMN 3
#define FIFTH_COLUMN 4
#define SIXTH_COLUMN 5
#define SEVENTH_COLUMN 6
#define EIGHTH_COLUMN 7
#define NINTH_COLUMN 8
#define TENTH_COLUMN 9
#define ELEVENTH_COLUMN 10
#define TWELFTH_COLUMN 11
#define THIRTEENTH_COLUMN 12
#define FOURTEENTH_COLUMN 13
#define FIFTEENTH_COLUMN 14
#define SIXTEENTH_COLUMN 15
#define SEVENTEENTH_COLUMN 16

/*
 * Init LCD.
 */
void LCD_init();

/*
 * LCD send Command.
 */
void LCD_sendCommand(uint8_t cmd);

/*
 * LCD display Character.
 */
void LCD_displayCharacter(uint8_t character);

/*
 * Go to row column.
 */
void LCD_goToRowColumn(uint8_t row, uint8_t col);


/*
 * Display string at specific location.
 */

void LCD_displayStringRowCol(uint8_t* string, uint8_t row, uint8_t col);


/*
 * Clear Screen.
 */
void LCD_clearScreen();


/*
 * Display string.
 */
void LCD_displayString(uint8_t * string);

/*
 * Integer to ascii.
 */
void LCD_integerToString (uint8_t number);



#endif /* LCD_LCD_H_ */
