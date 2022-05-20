/*
 * LCD_private.h
 *
 *  Created on: Sep 12, 2021
 *      Author: taqwa
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define EIGHT_BIT	24
#define FOUR_BIT	9

static inline void LCD_invidSendCommend(u8 Copy_u8Command);

static void LCD_voidSendData(u8 copy_u8Data);

#define CLCD_DISPLAY_CLEAR  (0b00000001)




#endif /* LCD_PRIVATE_H_ */
