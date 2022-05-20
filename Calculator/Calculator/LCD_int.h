/*
 * LCD_int.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_T LCD_enuInit(void);

ES_T LCD_enuDisplayChar(u8 Copy_u8Data);

ES_T LCD_enuSendCommand(u8 Copy_u8Command);


ES_T LCD_enuDisplayExtraChar(u8* Copy_pu8Character,u8 Copy_u8CharNum ,u8 Copy_u8Position , u8 Copy_u8Entry);


ES_T LCD_enuDisplayIntegerNum(s32 Copy_s32Num);


ES_T LCD_enuDisplayFloatNum(f32 Copy_s32Num);

#endif /* LCD_INT_H_ */
