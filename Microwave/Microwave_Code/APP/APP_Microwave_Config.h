/*************************************************
* AUTHOR : Amira_moustafa Mario_Refaat Moataz_Tarek
* Date   : 2/1/2021
* VERION : V0.0
* DISCRIPTION: Microwave_APP.h
**************************************************/

#ifndef APP_MICROWAVE_CONFIG_H_
#define APP_MICROWAVE_CONFIG_H_
#include "../LIB/STD_Type.h"
typedef struct{
	u8 seconds_count;
	u8 minutes_count;
	u8 hours_count;
}Time_t;

typedef struct{
	u8 temp_sensors;
	u8 weight_sensors;
	u8 door_sensors;
}sensors_t;

#endif /* APP_MICROWAVE_CONFIG_H_ */
