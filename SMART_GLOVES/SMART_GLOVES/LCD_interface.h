/*
 * LCD_interface.h
 *
 *  Created on: Sep 12, 2021
 *      Author: taqwa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
DIO_ErrorStatus LCD_enuInit(void);

DIO_ErrorStatus LCD_enuDisplayChar(u8 Copy_u8Data);

DIO_ErrorStatus LCD_enuSendCommand(u8 Copy_u8Command);

void LCD_voidSendString  ( u8 * Copy_u8ptrString );
void LCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col );

void LCD_voidSendINTNum(u32 copy_u32Num);
void LCD_voidSendExtraChar(u8 *copy_u8Parr,u8 copy_u8CharNum,u8 copy_u8position,u8 copy_u8EntryMode);
void LCD_voidSendFloatNumber(f64 Copy_f32Number);
void LCD_voidClearScreen(void);
#define LCD_ROW_1     1
#define LCD_ROW_2     2

#define LCD_COL_1      1
#define LCD_COL_2      2
#define LCD_COL_3      3
#define LCD_COL_4      4
#define LCD_COL_5      5
#define LCD_COL_6      6
#define LCD_COL_7      7
#define LCD_COL_8      8
#define LCD_COL_9      9
#define LCD_COL_10     10
#define LCD_COL_11     11
#define LCD_COL_12     12
#define LCD_COL_13     13
#define LCD_COL_14     14
#define LCD_COL_15     15
#define LCD_COL_16     16

#define CLCD_SHIFT_LEFT					0b00000111

#endif /* LCD_INTERFACE_H_ */
