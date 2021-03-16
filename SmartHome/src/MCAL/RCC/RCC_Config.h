/*
 * RCC_Config.h
 *
 *  Created on: Jan 17, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_



/* RCC Can be :
 *
 * 				1- RCC_HSE_CRYSTAL
 * 				2- RCC_HSE_RC
 * 				3- RCC_HSI
 * 				4- RCC_PLL
 */
#define RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL


#if RCC_CLOCK_TYPE == RCC_PLL
/* RCC PLL SRS Can Be:
 * 			    1-RCC_HSE
 * 				2-RCC_HSE_DIV_2
 * 				3-RCC_HSI_DIV_2
 *
 */
#define RCC_PLL_SRS  RCC_HSE



/* RCC_PLL_MULTIBLE can be :
 *               1-RCC_PLL_MULTIPLE_2
 *               2-RCC_PLL_MULTIPLE_3
 *               3-RCC_PLL_MULTIPLE_4
 *               4-RCC_PLL_MULTIPLE_5
 *               5-RCC_PLL_MULTIPLE_6
 *               6-RCC_PLL_MULTIPLE_7
 *               7-RCC_PLL_MULTIPLE_8
 *               8-RCC_PLL_MULTIPLE_9
 *               9-RCC_PLL_MULTIPLE_10
 *               10-RCC_PLL_MULTIPLE_11
 *               11-RCC_PLL_MULTIPLE_12
 *               12-RCC_PLL_MULTIPLE_13
 *               13-RCC_PLL_MULTIPLE_14
 *               14-RCC_PLL_MULTIPLE_15
 *               15-RCC_PLL_MULTIPLE_16
 */

#define RCC_PLL_MULTIBLE     RCC_PLL_MULTIPLE_16

#endif

/* RCC PLL SRS Can Be:
 * 			    1-ENABLE_CLOCK_SECURITY_SYSTEM
 * 				2-DISABLE_CLOCK_SECURITY_SYSTEM
 *
 */
#define CLOCK_SECURITY_SYSTEM	DISABLE_CLOCK_SECURITY_SYSTEM
#endif /* RCC_CONFIG_H_ */
