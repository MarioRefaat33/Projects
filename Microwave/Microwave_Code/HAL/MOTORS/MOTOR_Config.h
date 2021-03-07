/*************************************************
 * AUTHOR : Amira Moustafa
 * Date   : 2/1/2021
 * VERION : V0.0
 * DISCRIPTION: MOTOTR_Config.c
 **************************************************/
#ifndef MOTOR_CONFIG_H_
#define MOTOR_CONFIG_H_

/*choose num of motors*/

#define CONNECT_TWO_MOTOR    0
#define CONNECT_ONE_MOTOR    1
#define  MOTOR_Generate_pwm  2
#define  MOTOR_STATE  MOTOR_Generate_pwm
#define NUM_OF_MOTORS  CONNECT_ONE_MOTOR


/* top MOTOR */
#define MOTOR1_PORT DIO_PORTA
#define MOTOR1_PIN1 DIO_PIN3
#define MOTOR1_PIN2 DIO_PIN4
#define MOTOR1_ENABLE DIO_PIN5


/*down MOTOR*/
#define MOTOR2_PORT   DIO_PORTD
#define MOTOR2_PIN1   DIO_PIN5
#define MOTOR2_PIN2   DIO_PIN6
#define MOTOR2_ENABLE DIO_PIN7


/*MOTOR GENERATE PWM*/
#define MOTOR_PORT   DIO_PORTD
#define MOTOR_PIN1   DIO_PIN5
#define MOTOR_PIN2   DIO_PIN6
#define MOTOR_ENABLE DIO_PIN7




#endif /* MOTOR_CONFIG_H_ */
