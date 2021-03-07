/*************************************************
 * AUTHOR : Moataz Tarek
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION:timer_interface.h
 **************************************************/

#ifndef timer_Interface_H_
#define timer_Interface_H_


/*Function Prototype*/
void Timer0_voidInit(void);
void Timer_voidDutyCycles(u8 Duty_Cycle);
void SetCallBack(void(*a_ptr)(void));


#endif
