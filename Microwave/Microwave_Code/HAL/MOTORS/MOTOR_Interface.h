/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: MOTOTR_Interface.c
 **************************************************/

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_



void MOTOR_voidInit(void);
void MOTOR_voidRotateClkWise(u8 copy_u8top,u8 copy_u8down);
void MOTOR_voidRotateAntiClkWise(u8 copy_u8top,u8 copy_u8down);
void MOTOR_voidGeneratePWM(u8 copy_u8dutycycle);
void MOTOR_voidStop(void);
#endif /* MOTOR_INTERFACE_H_ */
