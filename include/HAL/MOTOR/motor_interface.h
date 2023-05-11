/*
 * motor_interface.c
 *
 *  Created on: May 11, 2023
 *      Author: alaa radwan
 */

#ifndef INCLUDE_HAL_MOTOR_MOTOR_INTERFACE_C_
#define INCLUDE_HAL_MOTOR_MOTOR_INTERFACE_C_

/************************************************************************************************/
/* 										UserDefine For MOTOR										*/
/************************************************************************************************/
typedef enum
{
	MOTOR_LEFT=0,
	MOTOR_RIGHT
}MOTOR_DIRCTION;

/************************************************************************************************/
/*											MOTOR PROTOTYPES										*/
/************************************************************************************************/
void set_motor(MOTOR_DIRCTION A_motor_dir);
void clear_motor(void);

#endif /* INCLUDE_HAL_MOTOR_MOTOR_INTERFACE_C_ */
