
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* Register Description */

#define DDRA_REG  *((volatile u8 *)0x3A)
#define PORTA_REG *((volatile u8 *)0x3B)
#define PINA_REG  *((volatile u8 *)0x39)

#define DDRB_REG  *((volatile u8 *)0x37)
#define PORTB_REG *((volatile u8 *)0x38)
#define PINB_REG  *((volatile u8 *)0x36)


#define DDRC_REG  *((volatile u8 *)0x34)
#define PORTC_REG *((volatile u8 *)0x35)
#define PINC_REG  *((volatile u8 *)0x33)

#define DDRD_REG  *((volatile u8 *)0x31)
#define PORTD_REG *((volatile u8 *)0x32)
#define PIND_REG  *((volatile u8 *)0x30)


#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif
