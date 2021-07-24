/*
 * PWM0.h
 *
 *      Author: Aya
 */

#ifndef PWM_H_
#define PWM_H_

#define PWM_CHANNEL TIMER0

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

#define WGM00 6
#define WGM01 3
#define COM01 5
#define CS01 1
#define CS00 0
#define CS10 0

void PWM0_init(void);
void PWM0_DutyCycle(uint8_t DutyCycle);

#endif /* PWM_H_ */
