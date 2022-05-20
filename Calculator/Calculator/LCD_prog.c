/*
 * LCD_prog.c
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorState.h"

#include "DIO_Interface.h"

#include "LCD_config.h"
#include "LCD_priv.h"

#include "util/delay.h"

ES_T LCD_enuInit(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);

	_delay_ms(35);

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);

	//function set
	LCD_invidSendCommend(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_invidSendCommend(0x28);
#endif
	_delay_ms(1);
	LCD_invidSendCommend(0x0f);
	_delay_ms(1);
	LCD_invidSendCommend(0x01);
	_delay_ms(2);
	LCD_invidSendCommend(0x06);

	return Local_enuErrorState;
}

ES_T LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_T Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);

	LCD_vidLatch(Copy_u8Data);

	return Local_enuErrorState;
}

ES_T LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_T Local_enuErrorState = ES_NOK;

	// set rs as command
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);

	LCD_vidLatch(Copy_u8Command);


	return Local_enuErrorState;
}


ES_T LCD_enuDisplayIntegerNum(s32 Copy_s32Num)
{
	ES_T Local_enuErrorState = ES_NOK;
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
	s32 Local_s32Reverse=0;
	u8 Local_u8Remainder=0 , Local_u8NumDigit=0;

	if(Copy_s32Num <0)
	{
		LCD_vidLatch('-');
		Copy_s32Num *= -1 ;
	}
	if(Copy_s32Num !=0)
	{
	while (Copy_s32Num)
	{
		Local_u8Remainder = Copy_s32Num % 10;
		Local_s32Reverse = Local_s32Reverse * 10 + Local_u8Remainder;
		Copy_s32Num /=10;
		Local_u8NumDigit ++;
	}

	while (Local_u8NumDigit)
	{
		Local_u8Remainder = Local_s32Reverse % 10;
		LCD_vidLatch(Local_u8Remainder + '0');
		Local_s32Reverse /= 10;
		Local_u8NumDigit --;
	}
	}
	else
	{
		LCD_vidLatch('0');
	}

	return Local_enuErrorState;
}

ES_T LCD_enuDisplayExtraChar(u8* Copy_pu8Character,u8 Copy_u8CharNum ,u8 Copy_u8Position , u8 Copy_u8Entry)
{
	ES_T Local_enuErrorState = ES_NOK;

	if (Copy_u8CharNum <= 8)
	{
		LCD_invidSendCommend(0x40);
		u8 Local_u8Iter ;
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		for (Local_u8Iter=0 ; Local_u8Iter < (Copy_u8CharNum *8) ;Local_u8Iter ++)
		{
			LCD_vidLatch(Copy_pu8Character[Local_u8Iter]);
		}
		if (Copy_u8Entry == 0x04)
		{
			LCD_invidSendCommend(Copy_u8Position);
			LCD_invidSendCommend(Copy_u8Entry);
		}\
		for (Local_u8Iter=0 ; Local_u8Iter < Copy_u8CharNum  ;Local_u8Iter ++)
		{
			DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
			LCD_vidLatch(Local_u8Iter);
		}
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}

static void LCD_vidLatch(u8 Copy_u8Data)
{
	// set rw as write operation , EN is low
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);
	//write Data
	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data>>4)&1));

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Data>>0)&1));

#elif LCD_MODE == FOUR_BIT
	if (Copy_u8Data == 0x28)
	{
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
		_delay_ms(10);
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

		_delay_ms(10);

		DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data>>7)&1));
		DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data>>6)&1));
		DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data>>5)&1));
		DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data>>4)&1));
	}

	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);


	_delay_ms(10);
	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data>>0)&1));
#endif

	// Enable latch
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);


	_delay_ms(10);
}


static inline void LCD_invidSendCommend(u8 Copy_u8Command)
{
	// set rs as command
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	// set rw as write operation , EN is low
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);
	//write Data
	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Command>>7)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Command>>6)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Command>>5)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Command>>4)&1));
#if LCD_MODE == EIGHT_BIT
	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Command>>3)&1));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Command>>2)&1));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Command>>1)&1));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Command>>0)&1));

#elif LCD_MODE == FOUR_BIT

	if(Copy_u8Command == 0x28)
	{
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
		_delay_ms(10);
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

		DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Command>>7)&1));
		DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Command>>6)&1));
		DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Command>>5)&1));
		DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Command>>4)&1));
	}
	// Enable latch
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Command>>3)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Command>>2)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Command>>1)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Command>>0)&1));

#endif
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);
}
ES_T LCD_enuDisplayFloatNum(f32 Copy_f32Num)
{
	ES_T Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);

	s32 Local_s32ReverseINT=0;
	s32 Local_s32ReverseDEC=0;
	u8 Local_u8RemainderINT=0 ,Local_u8RemainderDEC=0, Local_u8NumDigitINT=0 , Local_u8NumDigitDEC=0;

	u32 Local_u32IntPart1=0 ; f32 Local_f32FloatPart=0.0 ;
	u32 Local_u32IntPart2=0 ;
	Local_u32IntPart1 = (u32) Copy_f32Num;

	Local_f32FloatPart = Copy_f32Num - Local_u32IntPart1;
	Local_u32IntPart2 = Local_f32FloatPart * 10000;
	if(Copy_f32Num <0)
	{
		LCD_vidLatch('-');
		Copy_f32Num *= -1 ;
	}
	while (Local_u32IntPart1)
	{
		Local_u8RemainderINT = Local_u32IntPart1 % 10;
		Local_s32ReverseINT = Local_s32ReverseINT * 10 + Local_u8RemainderINT;
		Local_u32IntPart1 /=10;
		Local_u8NumDigitINT ++;
	}
	while (Local_u32IntPart2)
	{
		Local_u8RemainderDEC = Local_u32IntPart2 % 10;
		Local_s32ReverseDEC = Local_s32ReverseDEC * 10 + Local_u8RemainderDEC;
		Local_u32IntPart2 /=10;
		Local_u8NumDigitDEC ++;
	}
	while (Local_u8NumDigitINT)
	{
		Local_u8RemainderINT = Local_s32ReverseINT % 10;
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_vidLatch(Local_u8RemainderINT + '0');
		Local_s32ReverseINT /= 10;
		Local_u8NumDigitINT --;
	}
	LCD_vidLatch('.');
	while (Local_u8NumDigitDEC)
	{
		Local_u8RemainderDEC = Local_s32ReverseDEC % 10;
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_vidLatch(Local_u8RemainderDEC + '0');
		Local_s32ReverseDEC /= 10;
		Local_u8NumDigitDEC --;
	}
	return Local_enuErrorState;
}
