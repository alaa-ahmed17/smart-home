/*
 * KEYPAY.c
 *
 *  Created on: Apr 19, 2023
 *      Author: alaa radwan
 */
/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"

/************************************************************************************************/
/*										Delay Library 											*/
/************************************************************************************************/
#include <util/delay.h>
#define F_CPU 8000000UL

/****************************************************/
/* KEYBAD Directives		     					    */
/****************************************************/
#include "../include/keybad/KEYBAD_interface.h"
#include "../include/keybad/KEYBAD_Private.h"
#include "../include/keybad/KEYBAD_Cfg.h"

u8 static Global_u8ArrRows [ROWS_NO] = KEYPAD_ROWS;
u8 static Global_u8ArrColumns [COLS_NO] = KEYPAD_COLS;

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8KeyValue = KEYPAD_NOT_PRESSED;

	u8 Local_u8RowCounter =0,Local_u8ColumnCounter = 0,Local_u8Flag = FLAG_DOWN;

	//Loop To check each row in the keypad
	for(Local_u8RowCounter = 0; Local_u8RowCounter < ROWS_NO ; Local_u8RowCounter++)
	{
		//Activate One ROW
		MDIO_voidSetPinStatus(ROW_PORT,Global_u8ArrRows[Local_u8RowCounter],DIO_RESET);
		//Loop To check each column in the keypad
		for(Local_u8ColumnCounter = 0; Local_u8ColumnCounter < COLS_NO ; Local_u8ColumnCounter++)
			{
				//Read Column
				u8 Local_u8PinValue = MDIO_PinStatusGetPinValue(COL_PORT, Global_u8ArrColumns [Local_u8ColumnCounter]);
				if(Local_u8PinValue == KEYPAD_PRESSED)
				{
					//delay for switch Bouncing effect
					_delay_ms(30);
					Local_u8PinValue = MDIO_PinStatusGetPinValue(COL_PORT, Global_u8ArrColumns [Local_u8ColumnCounter]);
					//Check again if user is pressed the key or no
					if(Local_u8PinValue == KEYPAD_PRESSED)
					{
						//if key pressed stack it in a loop till user remove its hand from the switch
						//this loop in order not to repeat the value of pressed switch while key pressed
						while(Local_u8PinValue == KEYPAD_PRESSED)
						{
							//while inside the loop reading the value of pin to renew the value of the pin still pressed or not
							//Update reading of the the pin
							Local_u8PinValue = MDIO_PinStatusGetPinValue(COL_PORT, Global_u8ArrColumns [Local_u8ColumnCounter]);
						}
						//when key not pressed no more update the key value with the value that is in the array of row and column
						Local_u8KeyValue = u8arr_value_keypay[Local_u8RowCounter][Local_u8ColumnCounter];
						//an indicator that when we have a value of key or key pressed get out of all lops and return the value of pressed switch
						Local_u8Flag = FLAG_UP;
						break;
					}
				}
			}//End Column Reading
		//Deactivate The Activated ROW
		MDIO_voidSetPinStatus(ROW_PORT,Global_u8ArrRows[Local_u8RowCounter],DIO_SET);
		if(Local_u8Flag == FLAG_UP)
		{
			break;
		}
	}
	return Local_u8KeyValue;
}
