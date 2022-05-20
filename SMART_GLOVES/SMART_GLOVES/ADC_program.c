/*
 * ADC_program.c
 *
 *  Created on: Sep 19, 2021
 *      Author: taqwa
 */

#include"STD_TYPES.h"

#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_config.h"


void ADC_voidInit(void)
{

	ADCMUX_REG |= ADC_REFERNECE_VOLTAGE | ADLAR;
	ADCSRA_REG |= ADC_STATE | ADC_INTERRUPT | ADC_CLK;


}

u16 ADC_16ReadChannelADC( u8 Copy_u8Channel_Id )

{

	u16 Result = 0;
	ADCMUX_REG &=~(0b11111);
	ADCMUX_REG |= Copy_u8Channel_Id; // select Channel
	// Start Conversion
	ADCSRA_REG |= start_con;
	while( ( (ADCSRA_REG >> 4)& 1) == 0 ) // wait the flag to be set
	{

	}
#if ADLAR == ADC_LEFT_ADJUST_DISABEL
	Result = ADCL_REG | (ADCH_REG <<8 );

#elif ADLAR == ADC_LEFT_ADJUST_ENABLE
	Result = (ADCH_REG << 2);
#endif
	// clear flag
		ADCSRA_REG |= (1 << 4);
	return Result;

}
