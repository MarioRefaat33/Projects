/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 30/1/2021
 * VERION : V0.0
 * DISCRIPTION:MCAL_AFIO_AFIO_PRIVATE_H_
 **************************************************/
#ifndef MCAL_AFIO_AFIO_PRIVATE_H_
#define MCAL_AFIO_AFIO_PRIVATE_H_

typedef struct{

	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICRx[4];
	volatile u32 MAPR2;

}AFIO_Type;


#define AFIO ((volatile AFIO_Type*) 0x40010000)

#endif /* MCAL_AFIO_AFIO_PRIVATE_H_ */
