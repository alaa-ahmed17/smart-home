
/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


/************************************************************************************************/
/*										Delay Library 											*/
/************************************************************************************************/
#include <util/delay.h>
#define F_CPU 8000000UL

/****************************************************/
/* Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/keybad/KEYBAD_interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/keybad/KEYBAD_interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include "../include/HAL/MOTOR/motor_interface.h"


u16 correct_password=15987;

int main(void)
{
	// Initialize i/o , LCD and ADC
		MDIO_voidInit();
		HLCD_voidInit();
		MADC_voidInit();

		u16 local_u16DigitalValue =0, local_u16AnalgoSignal;

			u8 get1_data,operation=KEYPAD_NOT_PRESSED;
			s32 a1=0;

			HLCD_voidDisplayString("enter password:");
			get1_data=HKEYPAD_u8GetPressedKey();

			while(1)
				{
				if(a1==0)
				{
					HLCD_voidGoToPos(LCD_ROW2,LCD_COLUMNS2);
				}
				if (get1_data!=KEYPAD_NOT_PRESSED)
				{ 		//In case enter number
						if(get1_data>=48&&get1_data<58)
						{
								a1=10*a1+(get1_data-48);
								HLCD_voidSendChar(get1_data);
						}
						else
						{	// in case arithmetic operation
							switch (get1_data)
							{
								case '+':
									operation='+';
									HLCD_voidSendChar(get1_data);
									break;
								case '-':
									operation='-';
									HLCD_voidSendChar(get1_data);
									break;
								case '/':
									operation='/';
									HLCD_voidSendChar(get1_data);
									break;
								case '*':
									operation='*';
									HLCD_voidSendChar(get1_data);
									break;
							}
						}

					if(get1_data=='C')
					{ 	// C refer to confirm the entry
						HLCD_voidDisplayClear();
						// check password
						if(a1==correct_password)
						{
							HLCD_voidDisplayString("loading...");
							HLED_voidSetLedStatus(PORTD,PIN1,LED_TurnON);
							// to flasher buzzer 3 times
							for(u8 i=0;i<3;i++)
							{
								MDIO_voidSetPinStatus(PORTC,PIN0,DIO_SET);
								_delay_ms(300);
								MDIO_voidSetPinStatus(PORTC,PIN0,DIO_RESET);
								_delay_ms(300);

							}
							// to light up the led to indicates the system work
							HLED_voidSetLedStatus(PORTD,PIN1,LED_TurnOFF);


							// to ROTATE motor IN LEFT
							set_motor(MOTOR_LEFT);
							// to ROTATE motor IN RIGHT
							set_motor(MOTOR_RIGHT);
							//to stop the motor
							clear_motor();


							HLCD_voidDisplayClear();
							HLCD_voidDisplayString("temperature :");
							while(1)
							{// to print temperature in LCD
								local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC0);
								local_u16AnalgoSignal = (local_u16DigitalValue * 500) / 1024;
								HLCD_voidGoToPos(LCD_ROW2,LCD_COLUMNS2);
								HLCD_voidDisplayNumber(local_u16AnalgoSignal);
								HLCD_voidDisplayString("C");


								local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC1);
								local_u16AnalgoSignal = (local_u16DigitalValue * 500) / 1024;
								if(local_u16AnalgoSignal==0)
								{// to light all leds
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_SET);

								}
								// to light all except one led
								if(local_u16AnalgoSignal==1)
								{
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_RESET);

								}
								// to light all except two led
								else if (local_u16AnalgoSignal==3)
								{
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_RESET);

								}
								//to light all except 3 led
								else if (local_u16AnalgoSignal==8)
								{
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_RESET);
								}
								// to light up 3
								else if (local_u16AnalgoSignal==16)
								{
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_RESET);

								}
								// to light up 2
								else if (local_u16AnalgoSignal==30)
								{
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_RESET);

								}
								// to light up 1
								else if (local_u16AnalgoSignal>30)
								{
									HLED_voidSetLedStatus(PORTD,PIN2,DIO_SET);
									HLED_voidSetLedStatus(PORTD,PIN3,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN4,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN5,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN6,DIO_RESET);
									HLED_voidSetLedStatus(PORTD,PIN7,DIO_RESET);
								}
						}
					}
						// in case off password is not true
						else
						{
							HLCD_voidDisplayString("incorrect pass ");
							// to light up red led to indicate the password is false
							HLED_voidSetLedStatus(PORTD,PIN0,LED_TurnON);
							// to run buzzer
							MDIO_voidSetPinStatus(PORTC,PIN0,DIO_SET);
							_delay_ms(1000);
							// to turn off the red led
							HLED_voidSetLedStatus(PORTD,PIN0,LED_TurnOFF);
							// to turn off the buzzer
							MDIO_voidSetPinStatus(PORTC,PIN0,DIO_RESET);
							// to clear the lcd
							HLCD_voidDisplayClear();

							HLCD_voidDisplayString("enter password :");
							a1=0;
						}
					}

				}

				get1_data=HKEYPAD_u8GetPressedKey();
			}

}
