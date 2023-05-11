
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
/*										 DIO Directives										*/
/************************************************************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/DIO/DIO_Private.h"
#include "../include/MCAL/DIO/DIO_Cfg.h"
/************************************************************************************************/
/*										 LCD Directives										*/
/************************************************************************************************/
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LCD/LCD_Private.h"
#include "../include/HAL/LCD/LCD_Cfg.h"
/************************************************************************************************/
static u8 InitStepFinished = 0;
/************************************************************************************************/
/*										LCD IMPLEMENTATION										*/
/************************************************************************************************/
void HLCD_voidSendCommand(u8 A_u8Command)
{
	//To Write Command RS -> 0 , RW -> 0

		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_RESET);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);

		#if LCD_MODE == 0

		//Set Data Port with First Nibble of Command
		//Value Of Pin 0 of data port equal to the first bit of the command that send
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN0,GET_BIT(A_u8Command,PIN4));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN1,GET_BIT(A_u8Command,PIN5));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN2,GET_BIT(A_u8Command,PIN6));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN3,GET_BIT(A_u8Command,PIN7));

		//Set Pulse on E pin with 2ms delay
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
		_delay_ms(2);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

		if(InitStepFinished)
		{
		//Set Data Port with First Nibble of Command
		//Value Of Pin 0 of data port equal to the first bit of the command that send
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN0,GET_BIT(A_u8Command,PIN0));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN1,GET_BIT(A_u8Command,PIN1));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN2,GET_BIT(A_u8Command,PIN2));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN3,GET_BIT(A_u8Command,PIN3));
		//Set Pulse on E pin with 2ms delay
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
		_delay_ms(2);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

		}
		#elif LCD_MODE == 1
		//Set Data Port with Command
		MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);
		//Set Pulse on E pin with 2ms delay
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
		_delay_ms(2);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);
		#endif

	_delay_ms(2);

}
/************************************************************************************************/
void HLCD_voidSendData(u8 A_u8Data)
{

	//To Write Command RS -> 0 , RW -> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_SET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);
	#if LCD_MODE == 0

	//Set Data Port with First Nibble of Command
	//Value Of Pin 0 of data port equal to the first bit of the command that send
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN0,GET_BIT(A_u8Data,PIN4));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN1,GET_BIT(A_u8Data,PIN5));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN2,GET_BIT(A_u8Data,PIN6));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN3,GET_BIT(A_u8Data,PIN7));

	//Set Pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

	//Set Data Port with First Nibble of Command
	//Value Of Pin 0 of data port equal to the first bit of the command that send
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN0,GET_BIT(A_u8Data,PIN0));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN1,GET_BIT(A_u8Data,PIN1));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN2,GET_BIT(A_u8Data,PIN2));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN3,GET_BIT(A_u8Data,PIN3));

	#elif LCD_MODE == 1
	//Set Data Port with Command
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);
	#endif
	//Set Pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

}
/************************************************************************************************/
void HLCD_voidInit	(void)
{
	#if LCD_MODE == 0
	//wait for more than 30 ms
	_delay_ms(32);
	//Function Set Command
	HLCD_voidSendCommand(MODE_4BIT_FUNCTION_SET_1);
	HLCD_voidSendCommand(MODE_4BIT_FUNCTION_SET_1);
	HLCD_voidSendCommand(MODE_4BIT_FUNCTION_SET_2);
	//wait for more than 39 us
	_delay_ms(1);
	//Display On/Off control
	HLCD_voidSendCommand(MODE_4BIT_DISPLAY_ON_OFF_CONTROL_1);
	HLCD_voidSendCommand(MODE_4BIT_DISPLAY_ON_OFF_CONTROL_2);
	//wait for more than 39 us
	_delay_ms(1);
	//Display clear
	HLCD_voidSendCommand(MODE_4BIT_DISPLAY_CLEAR_1);
	HLCD_voidSendCommand(MODE_4BIT_DISPLAY_CLEAR_2);
	//wait for more than 1.53 ms
	_delay_ms(2);
	HLCD_voidSendCommand(MODE_4BIT_ENTRY_MODE_SET_1);
	HLCD_voidSendCommand(MODE_4BIT_ENTRY_MODE_SET_2);
	InitStepFinished = 1;
	#elif LCD_MODE == 1
	//wait for more than 30 ms
	_delay_ms(32);
	//Function Set Command
	HLCD_voidSendCommand(MODE_8BIT_FUNCTION_SET);
	//wait for more than 39 us
	_delay_ms(1);
	//Display On/Off control
	HLCD_voidSendCommand(MODE_8BIT_DISPLAY_ON_OFF_CONTROL);
	//wait for more than 39 us
	_delay_ms(1);
	//Display clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
	HLCD_voidSendCommand(MODE_8BIT_ENTRY_MODE_SET);
	#endif
}

/************************************************************************************************/
void HLCD_voidDisplayString(u8 *A_PTRu8String)
{

	//Loop till the String element not null if not null display the string/character
	while (*A_PTRu8String > 0)
	{
		//Each string when display it increment to the next character to check is null or not
		HLCD_voidSendData(*A_PTRu8String++);
	}
}
/************************************************************************************************/
void HLCD_voidDisplayNumber (s32 A_s32Number)
{
	u32 local_u32Number=1;
	if (A_s32Number==0)
	{
		HLCD_voidSendData('0');
	}

	if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number *= -1;
	}

	while (A_s32Number != 0)
	{
		local_u32Number = ((local_u32Number*10)+ (A_s32Number%10));
		A_s32Number /= 10;
	}
	while (local_u32Number!= 1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number /= 10;
	}
}
/************************************************************************************************/
void HLCD_voidDisplayRealNumber(f32 A_f32Number)
{
	//Left number to the decimal point
	s32 left = (s32)A_f32Number;
	//calculation to the Right number to the decimal point
	u8 right = (f32)(A_f32Number - left) * 100;
	//Display Left number to the decimal point
	HLCD_voidDisplayNumber(left);
	//Display the decimal point
	HLCD_voidSendData('.');
	//Display the Right number to the decimal point
	HLCD_voidDisplayNumber(right);
}
/************************************************************************************************/
void HLCD_voidGoToPos (LCD_ROWS A_LcdRowNo,LCD_COLUMNS A_LcdColNo)
{
	switch (A_LcdRowNo)
	{
	case LCD_ROW1: HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_LcdColNo); break;
	case LCD_ROW2: HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_LcdColNo); break;
	default: break;
	}
	_delay_ms(1);
}
/************************************************************************************************/
void HLCD_voidDisplayClear(void)
{
	_delay_ms(100);
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
}
/************************************************************************************************/
void HLCD_voidSendSpecialCharacter (u8 *A_pu8PatternArr, u8 A_u8PatternNumber,LCD_ROWS A_LcdRowNo,LCD_COLUMNS A_LcdColNo )
{
	u8 local_u8CGRamAddress = 0;
		// Calculate CGRAM Address = Pattern No. * 8
		local_u8CGRamAddress = A_u8PatternNumber * 8;
		SET_BIT (local_u8CGRamAddress,6);

		// Send CGRAM Write Command
		HLCD_voidSendCommand(local_u8CGRamAddress);

		for (u8 i=0; i<8; i++)
		{
			HLCD_voidSendData(A_pu8PatternArr[i]);
		}

		HLCD_voidGoToPos(A_LcdRowNo,A_LcdColNo);

		// Display Pattern
		HLCD_voidSendData (A_u8PatternNumber);
}
/************************************************************************************************/

void HLCD_voidSendChar(u8 A_Pu8String)
{

		HLCD_voidSendData(A_Pu8String);

}

