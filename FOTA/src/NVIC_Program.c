/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 25/1/2020
 * VERION : V0.0
 * DISCRIPTION: NVIC_PROGRAM.C
 **************************************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"
void MNVIC_voidInit(void){


}
void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber){
	/*37/32 = 1*/
	 ISER1  = 1 << (copy_u8IntNumber %32);

}


