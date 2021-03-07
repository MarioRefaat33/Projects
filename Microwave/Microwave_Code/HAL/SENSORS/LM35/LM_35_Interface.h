/*************************************************
* AUTHOR : Mario Refaat
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: LM_35.h
**************************************************/

#ifndef LM_35_INTERFACE_H_
#define LM_35_INTERFACE_H_

#include "../../../LIB/STD_Type.h"

/*Function Prototype*/
u16 LM35_U16Read(u8  Copy_u8readchannel);
void LM35_VoidInit(void);

#endif /* LM_35_INTERFACE_H_ */
