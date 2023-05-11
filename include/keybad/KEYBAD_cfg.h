/*
 * KEYPAY_cfg.h
 *
 *  Created on: Apr 19, 2023
 *      Author: alaa radwan
 */

#ifndef INCLUDE_KEYBAD_KEYBAD_CFG_H_
#define INCLUDE_KEYBAD_KEYBAD_CFG_H_

#define ROWS_NO 4
#define COLS_NO 4


u8 u8arr_value_keypay [ROWS_NO][COLS_NO]={
												{'7','8','9','/'},
												{'4','5','6','*'},
												{'1','2','3','-'},
												{'C','0','=','+'}
											};

#define ROW_PORT PORTB
#define COL_PORT PORTB

#define KEY_NOT_PRESSWD 255

#define ROW1_keybad PIN0
#define ROW2_keybad PIN1
#define ROW3_keybad PIN2
#define ROW4_keybad PIN3

#define COL1 PIN4
#define COL2 PIN5
#define COL3 PIN6
#define COL4 PIN7




#define KEYPAD_ROWS {ROW1_keybad,ROW2_keybad,ROW3_keybad,ROW4_keybad}

#define KEYPAD_COLS {COL1,COL2,COL3,COL4}


#endif /* INCLUDE_KEYBAD_KEYBAD_CFG_H_ */
