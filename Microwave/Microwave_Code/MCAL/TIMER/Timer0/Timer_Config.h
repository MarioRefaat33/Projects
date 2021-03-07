/*************************************************
 * AUTHOR : Moataz Tarek
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION:timer_config.h
 **************************************************/

#ifndef timer_config_H_
#define timer_config_H_

/*preSCALEr options*/
#define SCALE_1024    1024
#define SCALE_256     256
#define SCALE_64      64
#define SCALE_8       8
#define SCALE_NO      1
#define NO_CLOCK      0

#define PRESCALER    SCALE_8

/*timer modes*/
#define OVERFLOW_MODE  1
#define COMPARE_MODE   2
#define PWM_MODE       3

#define  TIMER_MODE    OVERFLOW_MODE

/*waveform genration mode*/
#define NORMAL            1
#define PWM_PHASE_CORRECT 2
#define CTC               3
#define FAST_PWM         4

#define WAVEFORM_MODE     NORMAL

/*compare match modes*/
#define OC0_DISCONNECT    1
#define OC0_TOGGLE        2
#define OC0_ClEAR         3
#define OC0_SET           4

#define COMPARE_MODE_MATCH        OC0_DISCONNECT

/*compare output mode, fast PWM mode */
#define OC0_DISCONNECTED    1
#define NON_INVERTED_MODE   2
#define INVERTED_MODE       3

#define WAVEFORM      OC0_DISCONNECTED




#endif
