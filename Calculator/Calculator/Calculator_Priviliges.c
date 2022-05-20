/*
 * Calculator_Priviliges.c
 *
 *  Created on: Sep 21, 2021
 *      Author: bayer
 */
#include "stdTypes.h"
#include "errorState.h"

#include "LCD_int.h"

#include "Calculator_Private.h"

ES_T CLC_enuStartCalculation(s16 Copy_s16NUM1 , s16 Copy_s16NUM2 ,s8 Copy_s8Operator)
{
	ES_T Local_enuErrorState = ES_NOK;
	s32 Local_s32Result = 0;
	switch(Copy_s8Operator)
	{
	case '+':
		Local_s32Result = Copy_s16NUM1 + Copy_s16NUM2;
		LCD_enuDisplayIntegerNum(Local_s32Result);
		Local_enuErrorState = ES_OK;
		break;
	case '-':
		Local_s32Result = Copy_s16NUM1 - Copy_s16NUM2;
		LCD_enuDisplayIntegerNum(Local_s32Result);
		Local_enuErrorState = ES_OK;
		break;
	case '*':
		Local_s32Result = Copy_s16NUM1 * Copy_s16NUM2;
		LCD_enuDisplayIntegerNum(Local_s32Result);
		Local_enuErrorState = ES_OK;
		break;
	case '/':
		if(Copy_s16NUM2 != 0)
		{
		Local_s32Result = Copy_s16NUM1 / Copy_s16NUM2;
		LCD_enuDisplayIntegerNum(Local_s32Result);
		Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NOK;
			LCD_enuDisplayChar('E');
			LCD_enuDisplayChar('R');
			LCD_enuDisplayChar('R');
			LCD_enuDisplayChar('O');
			LCD_enuDisplayChar('R');
		}
		break;
	default:
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}

