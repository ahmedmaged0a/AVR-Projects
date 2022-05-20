/*
 * main.c
 *
 *  Created on: Sep 14, 2021
 *      Author: Ahmed Maged
 */

#include "stdTypes.h"
#include "errorState.h"

#include "Calculator_Interface.h"

#include "LCD_int.h"

#include "KeyPad_Interface.h"

#include "util/delay.h"

int main (void)
{
	LCD_enuInit();
	KeyPad_enuInit();
	s16 Local_s16Number1 = 0 ,Local_s16Number2 = 0;
	s8 Local_s8Operator = 0 ;
	u8 Local_u8GetState=0 ;
	while (1){
		KeyPad_enuKeyPressed(&Local_u8GetState);
		if(Local_u8GetState >=0 && Local_u8GetState <=9)
		{
			LCD_enuDisplayIntegerNum(Local_u8GetState);
			if(Local_s8Operator == 0)
			{
				Local_s16Number1 = Local_s16Number1*10;
				Local_s16Number1 += Local_u8GetState;
			}
			else
			{
				Local_s16Number2 = Local_s16Number2*10;
				Local_s16Number2 += Local_u8GetState;
			}
			Local_u8GetState = 0;
		}
		else if(Local_u8GetState == '+' || Local_u8GetState == '*' || Local_u8GetState == '/' ||Local_u8GetState == '-')
		{
			LCD_enuDisplayChar(Local_u8GetState);
			Local_s8Operator = Local_u8GetState;
			Local_u8GetState = 0;
		}
		else if (Local_u8GetState == '=')
		{
			LCD_enuDisplayChar(Local_u8GetState);
			CLC_enuStartCalculation(Local_s16Number1 , Local_s16Number2 ,Local_s8Operator);
		}
		else if (Local_u8GetState == 'C')
		{
			Local_s16Number1 = 0;
			Local_s16Number2 = 0;
			Local_s8Operator = 0;
			Local_u8GetState = 0;
			LCD_enuSendCommand(0x01);

		}

	}
	return 0;
}


