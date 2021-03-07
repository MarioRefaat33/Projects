/*************************************************
* AUTHOR : Amira Moustafa
* Date   : 18/12/2020
* VERION : V0.0
* DISCRIPTION: timer1_Private.h
**************************************************/
#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/*prescaler menu*/
#define scale_1024    1024
#define scale_256     256
#define scale_64      64
#define scale_8       8
#define scale_NO      1
#define NO_clock      0

#define prescaler     scale_256

/*timer modes*/
#define Normal                 				    0
#define	Phase_Correct_8_bit    		     		1
#define	Phase_Correct_9_bit   				    2
#define	Phase_Correct_10_bit  				    3
#define	CTC_OCR1A                   			4
#define Fast_PWM_8_bit		  				 	5
#define	Fast_PWM_9_bit		  			 		6
#define	Fast_PWM_10_bit		  				 	7
#define	Phase_and_Frequency_Correct_ICR1	 	8
#define	Phase_and_Frequency_Correct_OCR1A  		9
#define	Phase_Correct_ICR1                    	10
#define	Phase_Correct_OCR1A                		11
#define	CTC_ICR1						 		12
#define	Reserved						 		13
#define	Fast_PWM_ICR1					 		14
#define	Fast_PWM_OCR1A					 		15

#define    Waveform_Generation_Mode             Fast_PWM_ICR1


/*Compare Output Mode,channelA Fast PWM*/
#define Normal  								0
#define toggle_compare_match                    1
#define Non_Inverting_mode                      2
#define Inverting_mode                    		3

/*choose channel */
#define Channel_A                               1
#define Channel_B                               2

 #define Channel_number                         Channel_A


#define comape_mode                            Non_Inverting_mode
#define ICR1_Value           		           624


#endif /* TIMER1_CONFIG_H_ */
