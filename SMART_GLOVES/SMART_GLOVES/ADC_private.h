/*
 * ADC_private.h
 *
 *  Created on: Sep 19, 2021
 *      Author: taqwa
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADCMUX_REG				*((volatile u8 * ) 0x27 )
#define ADCSRA_REG				*((volatile u8 * ) 0x26 )
#define ADCL_REG				*((volatile u8 * ) 0x24 )
#define ADCH_REG				*((volatile u8 * ) 0x25 )
#define SFIOR_REG				*((volatile u8 * ) 0x50 )


#define ADC_INTERNAL_VCC		(1 << 6 ) | (0 << 7)
#define ADC_INTERNAL_2_56		(1 << 6 ) | (1 << 7)
#define ADC_EXTERNAL_AREF		(0 << 6 ) | (0 << 7)


#define ADC_LEFT_ADJUST_ENABLE 	(1 << 5)
#define ADC_LEFT_ADJUST_DISABEL (0 << 5)

/***********************************/

#define ADC_ENABLE				(1 << 7)
#define ADC_DISABEL				(0 << 7)

#define ADC_ENABLE_INTERRUPT    (1 << 3)
#define ADC_DISABLE_INTERRUPT	(0 << 3)

#define start_con               (1 << 6)


/*  ADC Pre scaler Options  */
#define ADC_CLCK_2						 ( 0b001 )
#define ADC_CLCK_4                       ( 0b010 )
#define ADC_CLCK_8                       ( 0b011 )
#define ADC_CLCK_16                      ( 0b100 )
#define ADC_CLCK_32                      ( 0b101 )
#define ADC_CLCK_64                      ( 0b110 )
#define ADC_CLCK_128                     ( 0b111 )



#endif /* ADC_PRIVATE_H_ */
