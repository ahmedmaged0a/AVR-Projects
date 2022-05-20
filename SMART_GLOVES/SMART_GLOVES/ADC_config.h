/*
 * ADC_config.h
 *
 *  Created on: Sep 19, 2021
 *      Author: taqwa
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*
  	ADC_INTERNAL_VCC
	ADC_INTERNAL_2_56
	ADC_EXTERNAL_AREF
 */
#define ADC_REFERNECE_VOLTAGE 		ADC_INTERNAL_VCC

/*	ADC_LEFT_ADJUST_ENABLE
	ADC_LEFT_ADJUST_DISABEL
*/

#define ADLAR					ADC_LEFT_ADJUST_ENABLE

/*
   ADC_ENABLE
   ADC_DISABEL
 */
#define ADC_STATE			ADC_ENABLE

/**
    ADC_ENABLE_INTERRUPT
    ADC_DISABLE_INTERRUPT
 */

#define ADC_INTERRUPT		ADC_DISABLE_INTERRUPT

/*
ADC_CLCK_2						 ( 0b001 )
ADC_CLCK_4                       ( 0b010 )
ADC_CLCK_8                       ( 0b011 )
ADC_CLCK_16                      ( 0b100 )
ADC_CLCK_32                      ( 0b101 )
ADC_CLCK_64                      ( 0b110 )
ADC_CLCK_128                     ( 0b111 )
 *
 *
 *
 *
 */
#define ADC_CLK						ADC_CLCK_128

#endif /* ADC_CONFIG_H_ */
