
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum{

	DIO_NOK,
	DIO_OK

}DIO_ErrorStatus;


#define DIO_OUTPUT  1
#define DIO_INPUT   0

#define DIO_HIGH    1
#define DIO_LOW     0

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7

/* prototype */
DIO_ErrorStatus DIO_enumSetPortDirection ( u8 Copy_u8Port , u8 Copy_u8Direction );
DIO_ErrorStatus DIO_enumSetPortValue     ( u8 Copy_u8Port , u8 Copy_u8Value );
DIO_ErrorStatus DIO_enumTogPortValue ( u8 Copy_u8Port);

DIO_ErrorStatus DIO_enumSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 Copy_u8Direction );
DIO_ErrorStatus DIO_enumSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 Copy_u8Value     );

DIO_ErrorStatus DIO_enumGetPortValue     ( u8 Copy_u8Port , u8 * Copy_u8ptrData );
DIO_ErrorStatus DIO_enumGetPinValue      ( u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 * Copy_u8ptrData );

#endif
