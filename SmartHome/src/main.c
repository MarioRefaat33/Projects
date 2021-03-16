/*************************************************
 * AUTHOR :
 * Date   :
 * VERION : V0.0
 * DISCRIPTION:
 **************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "APP/Samart_Home_Interface.h"

 u8 password_status = 0;

void main (void)
{

	Smart_Home_Init();


	while(1)
	{
		Smart_Home();
	}
}
