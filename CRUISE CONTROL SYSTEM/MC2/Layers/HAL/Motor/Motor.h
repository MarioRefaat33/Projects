/*
 * Motor.h
 *
 *  Created on: Sep 5, 2020
 *      Author: Omar Fahmy
 */

#ifndef LAYERS_HAL_MOTOR_MOTOR_H_
#define LAYERS_HAL_MOTOR_MOTOR_H_

/*** MOTOR ROTATION DIRECTION ***/
#define MOTOR_CLOCKWISE_ROTATION 		0
#define MOTOR_ANTICLOCKWISE_ROTATION 	1

/*** MOTOR FUNCTIONS PROTOTYPE ***/
uint8_t Motor_Init();
uint8_t Motor_SetDutyCycle(uint8_t Motor_DutyCycle);

/*** OTHER MACROS ***/
#define MAX_DUTY_CYCLE 100


#endif /* LAYERS_HAL_MOTOR_MOTOR_H_ */
