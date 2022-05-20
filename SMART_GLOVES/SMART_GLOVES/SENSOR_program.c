/*
 * SENSOR_program.c
 *
 *  Created on: Sep 28, 2021
 *      Author: taqwa
 */
#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "DIO_interface.h"

#include "SENSOR_private.h"
#include "SENSOR_config.h"

void FLEX_SENSOR_voidInit(u8 Copy_u8ChannelNumber)
{
	DIO_enumSetPinDirection(DIO_PORTA, Copy_u8ChannelNumber, DIO_INPUT);
}
u8 FLEX_SNESOR_u8Read(u8 Copy_u8ChannelNumber)
{
	u16 Local_u16ADCValue = 0;
	f32 Local_f32AnalogVolt= 0;
	u8 Local_u8Angle = 0;
	Local_u16ADCValue = ADC_16ReadChannelADC(Copy_u8ChannelNumber);
	Local_f32AnalogVolt = (Local_u16ADCValue * ADC_VCC)/1024.0;
	Local_u8Angle = MAP(Local_f32AnalogVolt, 0, ADC_VCC, 0, 90.0 );
	return Local_u8Angle;
}

f32  static MAP(f32 Copy_f32Value, f32 Copy_f32INStart, f32 Copy_f32INEnd, f32 Copy_f32OutStart, f32 Copy_f3OutEnd)
{
	return ((Copy_f32Value - Copy_f32INStart ) * (Copy_f3OutEnd - Copy_f32OutStart )/(Copy_f32INEnd -Copy_f32INStart ) +Copy_f32OutStart);
}
