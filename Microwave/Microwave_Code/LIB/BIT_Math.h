/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 2/1/2021
* VERION : V0.0 
* DISCRIPTION: BIT_MATH.h
**************************************************/
#ifndef  BIT_MATH_H
#define  BIT_MATH_H

#define SET_BIT(REG,BIT_NUM)      (REG  |=  (1<< BIT_NUM) )
#define CLEAR_BIT(REG,BIT_NUM)    (REG  &= ~(1<< BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)   (REG  ^=  (1<< BIT_NUM) )
#define IS_BIT_SET(REG,BIT_NUM)   (REG  &   (1 << BIT_NUM) )
#define IS_BIT_CLEAR(REG,BIT_NUM) (!(REG &  (1<< BIT_NUM)) )


#endif
