/*
 * motor.c
 *
 *  Created on: May 11, 2023
 *      Author: alaa radwan
 */
/************************************************************************************************/
/*										Library Directives										*/
/************************************************************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
/************************************************************************************************/
/*										Delay Library 											*/
/************************************************************************************************/
#include <util/delay.h>
#define F_CPU 8000000UL

/************************************************************************************************/
/*										 DIO Directives											*/
/************************************************************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"
/************************************************************************************************/
/*										 MOTOR Directives				     					    */
/************************************************************************************************/
#include "../include/HAL/MOTOR/motor_interface.h"
#include "../include/HAL/MOTOR/motor_private.h"
#include "../include/HAL/MOTOR/motor_cfg.h"

u8 static arr_motor_pins[MOTOR_PINS_NO]=MOTOR_PINS;


void set_motor(MOTOR_DIRCTION A_motor_dir)
{

if(A_motor_dir==MOTOR_LEFT)
{
	for(u8 i=0 ;i<100;i++)
	{
//		_delay_ms(10);

			//step number 1
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_RESET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);
			_delay_ms(10);

			//step number 2
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_RESET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);
			_delay_ms(10);


			//step number 3
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_RESET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);
			_delay_ms(10);


			//step number 4
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);
			MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_RESET);
			_delay_ms(10);

	}
	}
		else
		{
			for(u8 x=0;x<100;x++)
			{
			//step number 1
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_RESET);
				_delay_ms(10);


			//step number 2
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_RESET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);
				_delay_ms(10);

				//step number 3
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_RESET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);
				_delay_ms(10);

				//step number 4
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_RESET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);
				MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);
				_delay_ms(10);
			}
		}
//	_delay_ms(100);
	}

void clear_motor(void)
{
	MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[0],DIO_SET);

	MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[1],DIO_SET);

	MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[2],DIO_SET);

	MDIO_voidSetPinStatus(MOTOR_PORT,arr_motor_pins[3],DIO_SET);

}







