/*
 * LCD_config.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*			LCD_MODE		*/
#define LCD_MODE		EIGHT_BIT

/*			Control Pins	*/
#define RS_PORT		DIO_u8PORTA
#define RS_PIN		DIO_u8PIN0

#define RW_PORT		DIO_u8PORTA
#define RW_PIN		DIO_u8PIN1

#define EN_PORT		DIO_u8PORTA
#define EN_PIN		DIO_u8PIN2

/*			Data Pins		*/
#define D7_PORT		DIO_u8PORTA
#define D7_PIN		DIO_u8PIN3

#define D6_PORT		DIO_u8PORTA
#define D6_PIN		DIO_u8PIN4

#define D5_PORT		DIO_u8PORTA
#define D5_PIN		DIO_u8PIN5

#define D4_PORT		DIO_u8PORTA
#define D4_PIN		DIO_u8PIN6

#define D3_PORT		DIO_u8PORTA
#define D3_PIN		DIO_u8PIN7

#define D2_PORT		DIO_u8PORTB
#define D2_PIN		DIO_u8PIN0

#define D1_PORT		DIO_u8PORTB
#define D1_PIN		DIO_u8PIN1

#define D0_PORT		DIO_u8PORTB
#define D0_PIN		DIO_u8PIN2

/*'A'
 65 - 0x41
 0b01000001
 */
/* 0b0000 0001*/
/* 0b1000 0000*/
#endif /* LCD_CONFIG_H_ */
