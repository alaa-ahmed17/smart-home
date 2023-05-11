/*
 * motor_cfg.h
 *
 *  Created on: May 11, 2023
 *      Author: alaa radwan
 */

#ifndef INCLUDE_HAL_MOTOR_CFG_H_
#define INCLUDE_HAL_MOTOR_CFG_H_
/************************************************************************************************/
/*											MOTOR	DEFINES											*/
/************************************************************************************************/
/*										   MOTOR PORT USED										*/
/************************************************************************************************/
#define MOTOR_PINS_NO 4

#define MOTOR_PORT PORTA
/************************************************************************************************/
/*									MOTOR	4 Bit Mode Data Pins Used								*/
/************************************************************************************************/
#define MOTOR_PIN0 PIN4
#define MOTOR_PIN1 PIN5
#define MOTOR_PIN2 PIN6
#define MOTOR_PIN3 PIN7

#define MOTOR_PINS {MOTOR_PIN0,MOTOR_PIN1,MOTOR_PIN2,MOTOR_PIN3}

#endif /* INCLUDE_HAL_MOTOR_CFG_H_ */
