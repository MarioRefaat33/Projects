/*************************************************
 * AUTHOR : Moataz Tarek
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION:timer_interface.h
 **************************************************/

#include"../../MCAL/GIE/GIE_Private.h"
#include"../../LIB/BIT_MATH.h"

void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}

void GIE_Disable(void)
{
	CLEAR_BIT(SREG,7);
}
