/*
 * glove.c
 *
 *  Created on: Sep 29, 2021
 *      Author: USER
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Speach.h"

void Gloves_VoidStartWork(u8 Copy_ADC1 ,u8 Copy_ADC2,u8 Copy_ADC3,u8 Copy_ADC4 ,u8 Copy_ADC5)
{
	if(Copy_ADC1> 55 && Copy_ADC2 > 55 && Copy_ADC3 >80 && Copy_ADC4 >80 && Copy_ADC5 > 80)
	{
		LCD_voidSendString(MASSAGE1);
	}
	else if(Copy_ADC1> 80 && Copy_ADC2 > 80 && Copy_ADC3 >80 && Copy_ADC4 >35 && Copy_ADC5 >35)
	{
		LCD_voidSendString(MASSAGE2);
	}
	else if(Copy_ADC1> 35 && Copy_ADC2 > 80 && Copy_ADC3 >80 && Copy_ADC4 >35 && Copy_ADC5 >35)
	{
		LCD_voidSendString(MASSAGE3);
	}
	else if(Copy_ADC1> 50 && Copy_ADC2 > 50 && Copy_ADC3 >35 && Copy_ADC4 >35 && Copy_ADC5 >35)
	{
		LCD_voidSendString(MASSAGE4);
	}
	else
	{
		LCD_voidSendString(MASSAGE5);
	}
}
void Display_SignalValue(u8 Copy_ADC1 ,u8 Copy_ADC2,u8 Copy_ADC3,u8 Copy_ADC4 ,u8 Copy_ADC5)
{
	LCD_voidSendINTNum(Copy_ADC1);
			LCD_enuDisplayChar(' ');
			LCD_voidSendINTNum(Copy_ADC2);
			LCD_enuDisplayChar(' ');
			LCD_voidSendINTNum(Copy_ADC3);
			LCD_enuDisplayChar(' ');
			LCD_voidSendINTNum(Copy_ADC4);
			LCD_enuDisplayChar(' ');
			LCD_voidSendINTNum(Copy_ADC5);
			LCD_enuDisplayChar(' ');
			LCD_voidSetPosition(2,1);
}
