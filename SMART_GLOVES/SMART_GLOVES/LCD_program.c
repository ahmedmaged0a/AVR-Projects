/*
 * LCD_program.c
 *
 *  Created on: Sep 12, 2021
 *      Author: taqwa
 */
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#include "util/delay.h"





DIO_ErrorStatus LCD_enuInit(void)
{
	DIO_ErrorStatus LOC_enumState  = DIO_OK;

	DIO_enumSetPinDirection(RS_PORT, RS_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(RW_PORT, RW_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(EN_PORT, EN_PIN, DIO_OUTPUT);

	DIO_enumSetPinDirection(D7_PORT, D7_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D6_PORT, D6_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D5_PORT, D5_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D4_PORT, D4_PIN, DIO_OUTPUT);

	_delay_ms(30);

#if LCD_MODE == EIGHT_BIT
	DIO_enumSetPinDirection(D3_PORT, D3_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D2_PORT, D2_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D1_PORT, D1_PIN, DIO_OUTPUT);
	DIO_enumSetPinDirection(D0_PORT, D0_PIN, DIO_OUTPUT);

	//function set
	LCD_invidSendCommend(0x38);

#elif LCD_MODE == FOUR_BIT

#endif
	_delay_ms(1);
	//Display on off
	LCD_invidSendCommend(0x0f);
	_delay_ms(1);
	//clear display
	LCD_invidSendCommend(0x01);
	_delay_ms(2);
	//entry mode
	LCD_invidSendCommend(0x06);

	return LOC_enumState;
}


DIO_ErrorStatus LCD_enuDisplayChar(u8 Copy_u8Data)
{
	DIO_ErrorStatus LOC_enumState  = DIO_OK;

	//set RS as data
	DIO_enumSetPinValue(RS_PORT, RS_PIN,DIO_HIGH);
	LCD_voidSendData( Copy_u8Data);


	return LOC_enumState;
}

DIO_ErrorStatus LCD_enuSendCommand(u8 Copy_u8Command)
{
	DIO_ErrorStatus LOC_enumState  = DIO_OK;
	//set RS as command
	DIO_enumSetPinValue(RS_PORT, RS_PIN,DIO_LOW);

	LCD_voidSendData( Copy_u8Command);

	return LOC_enumState;
}

static void LCD_voidSendData(u8 copy_u8Data)
{


	// set RW as  write operation,EN LOW
	DIO_enumSetPinValue(RW_PORT, RW_PIN,DIO_LOW);
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);

	// write data
	DIO_enumSetPinValue(D7_PORT, D7_PIN,(copy_u8Data>>7)&1);
	DIO_enumSetPinValue(D6_PORT, D6_PIN,(copy_u8Data>>6)&1);
	DIO_enumSetPinValue(D5_PORT, D5_PIN,(copy_u8Data>>5)&1);
	DIO_enumSetPinValue(D4_PORT, D4_PIN,(copy_u8Data>>4)&1);
#if LCD_MODE == EIGHT_BIT
	DIO_enumSetPinValue(D3_PORT, D3_PIN,(copy_u8Data>>3)&1);
	DIO_enumSetPinValue(D2_PORT, D2_PIN,(copy_u8Data>>2)&1);
	DIO_enumSetPinValue(D1_PORT, D1_PIN,(copy_u8Data>>1)&1);
	DIO_enumSetPinValue(D0_PORT, D0_PIN,(copy_u8Data>>0)&1);
#elif LCD_MODE == FOUR_BIT
	if (copy_u8Data==0x28)
	{
		// falling edge
		DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_HIGH);
		_delay_ms(10);
		DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);


		DIO_enumSetPinValue(D7_PORT, D7_PIN,(copy_u8Data>>7)&1);
		DIO_enumSetPinValue(D6_PORT, D6_PIN,(copy_u8Data>>6)&1);
		DIO_enumSetPinValue(D5_PORT, D5_PIN,(copy_u8Data>>5)&1);
		DIO_enumSetPinValue(D4_PORT, D4_PIN,(copy_u8Data>>4)&1);
	}



	// falling edge
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_HIGH);
	_delay_ms(10);
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);

	DIO_enumSetPinValue(D7_PORT, D7_PIN,(copy_u8Data>>3)&1);
	DIO_enumSetPinValue(D6_PORT, D6_PIN,(copy_u8Data>>2)&1);
	DIO_enumSetPinValue(D5_PORT, D5_PIN,(copy_u8Data>>1)&1);
	DIO_enumSetPinValue(D4_PORT, D4_PIN,(copy_u8Data>>0)&1);

#endif
	// falling edge
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_HIGH);
	_delay_ms(10);
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);


}
static inline void LCD_invidSendCommend(u8 Copy_u8Command)
{
	//set RS as command
	DIO_enumSetPinValue(RS_PORT, RS_PIN,DIO_LOW);

	// set RW as  write operation,EN LOW
	DIO_enumSetPinValue(RW_PORT, RW_PIN,DIO_LOW);
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);

	// write data
	DIO_enumSetPinValue(D7_PORT, D7_PIN,(Copy_u8Command>>7)&1);
	DIO_enumSetPinValue(D6_PORT, D6_PIN,(Copy_u8Command>>6)&1);
	DIO_enumSetPinValue(D5_PORT, D5_PIN,(Copy_u8Command>>5)&1);
	DIO_enumSetPinValue(D4_PORT, D4_PIN,(Copy_u8Command>>4)&1);



#if LCD_MODE == EIGHT_BIT
	DIO_enumSetPinValue(D3_PORT, D3_PIN,(Copy_u8Command>>3)&1);
	DIO_enumSetPinValue(D2_PORT, D2_PIN,(Copy_u8Command>>2)&1);
	DIO_enumSetPinValue(D1_PORT, D1_PIN,(Copy_u8Command>>1)&1);
	DIO_enumSetPinValue(D0_PORT, D0_PIN,(Copy_u8Command>>0)&1);
#elif LCD_MODE == FOUR_BIT
	if (Copy_u8Command==0x28)
	{
		// falling edge
		DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_HIGH);
		_delay_ms(10);
		DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);


		DIO_enumSetPinValue(D7_PORT, D7_PIN,(Copy_u8Command>>7)&1);
		DIO_enumSetPinValue(D6_PORT, D6_PIN,(Copy_u8Command>>6)&1);
		DIO_enumSetPinValue(D5_PORT, D5_PIN,(Copy_u8Command>>5)&1);
		DIO_enumSetPinValue(D4_PORT, D4_PIN,(Copy_u8Command>>4)&1);
	}

	// falling edge
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_HIGH);
	_delay_ms(10);
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);

	DIO_enumSetPinValue(D7_PORT, D7_PIN,(Copy_u8Command>>3)&1);
	DIO_enumSetPinValue(D6_PORT, D6_PIN,(Copy_u8Command>>2)&1);
	DIO_enumSetPinValue(D5_PORT, D5_PIN,(Copy_u8Command>>1)&1);
	DIO_enumSetPinValue(D4_PORT, D4_PIN,(Copy_u8Command>>0)&1);
#else
#error wrong selection

#endif
	// falling edge
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_HIGH);
	_delay_ms(10);
	DIO_enumSetPinValue(EN_PORT, EN_PIN,DIO_LOW);




}


void LCD_voidSendString  ( u8 * Copy_u8ptrString )
{


	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[ LOC_u8Iterator ] != '\0' ){

		LCD_enuDisplayChar( Copy_u8ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator ++ ;
	}



}

void LCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	if( Copy_u8Row == LCD_ROW_1 ){

		LCD_invidSendCommend( (0x80) + ( Copy_u8Col - 1 ) );

	}else if( Copy_u8Row == LCD_ROW_2  ){

		LCD_invidSendCommend( (0x80) + 64 + ( Copy_u8Col - 1 ) );

	}

}

void LCD_voidSendINTNum(u32 copy_u32Num)
{

	u32 rev=0,rem, remmeber= copy_u32Num;
	u8 i;
	for(i=0; copy_u32Num!=0;i++)
	{
		copy_u32Num/=10;
	}
	copy_u32Num=remmeber;
	while(copy_u32Num !=0)
	{
		rem=copy_u32Num%10;
		rev=rev*10+rem;
		copy_u32Num/=10;
	}

	while(rev!=0 || i>0)
	{
		rem=rev%10;
		LCD_enuDisplayChar(rem+'0');
		rev/=10;
		i--;

	}

}



void LCD_voidSendExtraChar(u8 *copy_u8Parr,u8 copy_u8CharNum,u8 copy_u8position,u8 copy_u8EntryMode)
{
	DIO_ErrorStatus LOC_enumState  = DIO_OK;

	if(copy_u8CharNum<=8){
		//go to CGRAM
	LCD_invidSendCommend(0x40);

	u8 LOC_u8Iterator;
	DIO_enumSetPinValue(RS_PORT, RS_PIN,DIO_HIGH);
	//Draw Character
	for(LOC_u8Iterator=0;LOC_u8Iterator<(copy_u8CharNum*8);LOC_u8Iterator++)
	{
		LCD_voidSendData(copy_u8Parr[LOC_u8Iterator]);
	}
	if(copy_u8EntryMode==0x04)
	{
         //return to DDRAM
		LCD_invidSendCommend(copy_u8position);
		LCD_invidSendCommend(copy_u8EntryMode);


	}
	for(LOC_u8Iterator=0;LOC_u8Iterator<copy_u8CharNum;LOC_u8Iterator++)
		{
		DIO_enumSetPinValue(RS_PORT, RS_PIN,DIO_HIGH);
		LCD_voidSendData(LOC_u8Iterator);


		}

	}
	else
	{
		 LOC_enumState  = DIO_NOK;

	}


}


void LCD_voidSendFloatNumber(f64 Copy_f32Number)
{
	// Cast the float Number to Integer value (ex: 25.6942325 --> 25)
	LCD_voidSendINTNum((u64)Copy_f32Number ); // Send the integer Number to the LCD
	LCD_enuDisplayChar('.'); // Send the decimal point

	// Multiply the Float Number by 10^6 so the decimal number becomes part of the number
	//(ex: 25.6942325--> 25694232.5
	// save the result as integer"saved in u64" (ex: 25.6942325--> 25694232
	u64 Local_u64tempNumber = Copy_f32Number*1000000;

	// if the first digit is greater than or equal 5
	if( Local_u64tempNumber%10 >=5 )
	{
		// then divide the number by 10  (ex : 25694236 ---> 2569423 )
		// add 1 to the number to round the number up
		//then module the number by 100000  (ex : 2569423 ---> 69424 )
		LCD_voidSendINTNum((u64)((( Local_u64tempNumber/10)+1) % 100000));
	}
	else
	{
		// then divide the number by 10  (ex : 25694232 ---> 2569423)
		// then module the number by 100000  (ex : 25694232 ---> 69423
		// Display the number
		LCD_voidSendINTNum((u64)(( Local_u64tempNumber/10) % 100000)); // Function to send the integer number
	}

}
void LCD_voidClearScreen(void)
{
	LCD_invidSendCommend(CLCD_DISPLAY_CLEAR);
	_delay_ms(2);
}
