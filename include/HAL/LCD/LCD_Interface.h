/*
 * LCD_Interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: Seko
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_
/************************************************************************************************/
/* 										UserDefine For LCD										*/
/************************************************************************************************/
typedef enum
{
	LCD_ROW1 = 1,
	LCD_ROW2
}LCD_ROWS;
/************************************************************************************************/
typedef enum
{
	LCD_COLUMNS1 = 1,
	LCD_COLUMNS2,
	LCD_COLUMNS3,
	LCD_COLUMNS4,
	LCD_COLUMNS5,
	LCD_COLUMNS6,
	LCD_COLUMNS7,
	LCD_COLUMNS8,
	LCD_COLUMNS9,
	LCD_COLUMNS10,
	LCD_COLUMNS11,
	LCD_COLUMNS12,
	LCD_COLUMNS13,
	LCD_COLUMNS14,
	LCD_COLUMNS15,
	LCD_COLUMNS16,
}LCD_COLUMNS;
/************************************************************************************************/
/*											LCD PROTOTYPES										*/
/************************************************************************************************/
void HLCD_voidSendCommand(u8 A_u8Command);
/************************************************************************************************/
void HLCD_voidSendData(u8 A_u8Data);
/************************************************************************************************/
void HLCD_voidInit	(void);
/************************************************************************************************/
void HLCD_voidDisplayString(u8 *A_PTRu8String);
/************************************************************************************************/
void HLCD_voidDisplayClear(void);
/************************************************************************************************/
void HLCD_voidDisplayNumber (s32 A_s32Number);
/************************************************************************************************/
void HLCD_voidGoToPos (LCD_ROWS A_LcdRowNo,LCD_COLUMNS A_LcdColNo);
/************************************************************************************************/
void HLCD_voidSendSpecialCharacter (u8 *A_pu8PatternArr, u8 A_u8PatternNumber,LCD_ROWS A_LcdRowNo,LCD_COLUMNS A_LcdColNo );
/************************************************************************************************/
void HLCD_voidDisplayRealNumber(f32 A_f32Number);
/************************************************************************************************/
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
