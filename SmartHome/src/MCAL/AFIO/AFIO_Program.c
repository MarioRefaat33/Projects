/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 30/1/2021
 * VERION : V0.0
 * DISCRIPTION: MCAL_AFIO_AFIO_PROGRAM.C
 **************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "AFIO_Config.h"
#include "AFIO_Interface.h"
#include "AFIO_Private.h"

void AFIO_voidSetEXTIConfiguration( u8 copy_u8EXTILine , u8 copy_u8PortMap ){
	u8 RegIndex = 0;
	if(copy_u8EXTILine <= 3 ){
		RegIndex = 0;
	}
	else if(copy_u8EXTILine <= 7){
		RegIndex = 1;
		RegIndex = -4;
	}
	else if(copy_u8EXTILine <= 11){
		RegIndex = 2;
		RegIndex -= 8;
	}
	else if(copy_u8EXTILine <= 15){
		RegIndex = 3;
		RegIndex -= 12;
	}
	AFIO -> EXTICRx[RegIndex] &=~ ((0b1111) << (copy_u8EXTILine * 4));
	AFIO -> EXTICRx[RegIndex] |=  ((copy_u8PortMap) << (copy_u8EXTILine * 4));
}
