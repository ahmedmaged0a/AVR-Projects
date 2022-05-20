/*
 * ADC_interface.h
 *
 *  Created on: Sep 19, 2021
 *      Author: taqwa
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_0					(0b00000)
#define ADC_1					(0b00001)
#define ADC_2					(0b00010)
#define ADC_3					(0b00011)
#define ADC_4					(0b00100)
#define ADC_5					(0b00101)
#define ADC_6					(0b00110)
#define ADC_7					(0b00111)


void ADC_voidInit(void);

u16 ADC_16ReadChannelADC( u8 Copy_u8Channel_Id );

#endif /* ADC_INTERFACE_H_ */
