/*
 * LCD_config.h
 *
 *  Created on: Sep 12, 2021
 *      Author: taqwa
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*			LCD_MODE		*/
#define LCD_MODE		EIGHT_BIT

/*			Control Pins	*/
#define RS_PORT		DIO_PORTD
#define RS_PIN		DIO_PIN0

#define RW_PORT		DIO_PORTD
#define RW_PIN		DIO_PIN1

#define EN_PORT		DIO_PORTD
#define EN_PIN		DIO_PIN2

/*			Data Pins		*/
#define D0_PORT		DIO_PORTC
#define D0_PIN		DIO_PIN0

#define D1_PORT		DIO_PORTC
#define D1_PIN		DIO_PIN1

#define D2_PORT		DIO_PORTC
#define D2_PIN		DIO_PIN2

#define D3_PORT		DIO_PORTC
#define D3_PIN		DIO_PIN3

#define D4_PORT		DIO_PORTC
#define D4_PIN		DIO_PIN4

#define D5_PORT		DIO_PORTC
#define D5_PIN		DIO_PIN5

#define D6_PORT		DIO_PORTC
#define D6_PIN		DIO_PIN6

#define D7_PORT		DIO_PORTC
#define D7_PIN		DIO_PIN7


#endif /* LCD_CONFIG_H_ */
