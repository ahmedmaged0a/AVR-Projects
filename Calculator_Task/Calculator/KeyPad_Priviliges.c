/*
 * KeyPad_Priviliges.c
 *
 *  Created on: Sep 14, 2021
 *      Author: bayer
 */
#include "stdTypes.h"
#include "errorState.h"

#include "DIO_Interface.h"

#include "KeyPad_config.h"
#include "KeyPad_private.h"

#include "util/delay.h"

ES_T KeyPad_enuInit(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(C1_PORT ,C1_PIN, OUTPUT );
	DIO_enuSetPinDirection(C2_PORT ,C2_PIN, OUTPUT );
	DIO_enuSetPinDirection(C3_PORT ,C3_PIN, OUTPUT );
	DIO_enuSetPinDirection(C4_PORT ,C4_PIN, OUTPUT );

	DIO_enuSetPinDirection(R1_PORT ,R1_PIN, INPUT );
	DIO_enuSetPinDirection(R2_PORT ,R2_PIN, INPUT );
	DIO_enuSetPinDirection(R3_PORT ,R3_PIN, INPUT );
	DIO_enuSetPinDirection(R4_PORT ,R4_PIN, INPUT );

	DIO_enuSetPinValue(C1_PORT ,C1_PIN, HIGH);
	DIO_enuSetPinValue(C2_PORT ,C2_PIN, HIGH);
	DIO_enuSetPinValue(C3_PORT ,C3_PIN, HIGH);
	DIO_enuSetPinValue(C4_PORT ,C4_PIN, HIGH);

	DIO_enuSetPinValue(R1_PORT ,R1_PIN, PULL_UP);
	DIO_enuSetPinValue(R2_PORT ,R2_PIN, PULL_UP);
	DIO_enuSetPinValue(R3_PORT ,R3_PIN, PULL_UP);
	DIO_enuSetPinValue(R4_PORT ,R4_PIN, PULL_UP);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_T KeyPad_enuKeyPressed(u8 *Copy_Pu8Value)
{
	*Copy_Pu8Value = 0xff;

	u8 u8ColumnArrPin[KEYPAD_SIZE] = {C1_PIN, C2_PIN, C3_PIN, C4_PIN};

	u8 u8RowArrPin[KEYPAD_SIZE] = {R1_PIN, R2_PIN, R3_PIN, R4_PIN};

	u8 u8ColumnArrPORT[KEYPAD_SIZE] = {C1_PORT, C2_PORT, C3_PORT, C4_PORT};

	u8 u8RowArrPORT[KEYPAD_SIZE] = {R1_PORT, R2_PORT, R3_PORT, R4_PORT};

	ES_T Local_enuErrorState = ES_NOK;
	u8 Local_u8ColumCount=ZERO , Local_u8RowCount=ZERO ;
	u8 Local_u8CheckValue=ZERO;

	if(Copy_Pu8Value != NULL)
	{
		for(Local_u8ColumCount = ZERO; Local_u8ColumCount < KEYPAD_SIZE; Local_u8ColumCount++)
		{
			DIO_enuSetPinValue(u8ColumnArrPORT[Local_u8ColumCount],u8ColumnArrPin[Local_u8ColumCount] , LOW);

			for(Local_u8RowCount = ZERO; Local_u8RowCount < KEYPAD_SIZE; Local_u8RowCount++)
			{
				DIO_enuGetPinValue( u8RowArrPORT[Local_u8RowCount],u8RowArrPin[Local_u8RowCount] , &Local_u8CheckValue);
				if(Local_u8CheckValue == ZERO)
				{
					while(!Local_u8CheckValue)
					{
						DIO_enuGetPinValue( u8RowArrPORT[Local_u8RowCount],u8RowArrPin[Local_u8RowCount] , &Local_u8CheckValue);
					}
					*Copy_Pu8Value = u8ButtonArr[Local_u8ColumCount][Local_u8RowCount];
					break;
				}
			}

			DIO_enuSetPinValue(u8ColumnArrPORT[Local_u8ColumCount],u8ColumnArrPin[Local_u8ColumCount] , HIGH);
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
