
#include "STD_TYPES.h"


#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"


DIO_ErrorStatus DIO_enumSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Direction ){

	DIO_ErrorStatus LOC_enumState = DIO_OK ;
 if(Copy_u8Port<=DIO_PORTD){

		switch( Copy_u8Port ){

		case DIO_PORTA: DDRA_REG = Copy_u8Direction   ;  break;
		case DIO_PORTB: DDRB_REG = Copy_u8Direction   ;  break;
		case DIO_PORTC: DDRC_REG = Copy_u8Direction   ;  break;
		case DIO_PORTD: DDRD_REG = Copy_u8Direction   ;  break;
		default       : LOC_enumState = DIO_NOK   ;  break;

		}

 }
 else {
	 LOC_enumState = DIO_NOK;
 }
	return LOC_enumState ;

}


DIO_ErrorStatus DIO_enumSetPortValue    ( u8 Copy_u8Port , u8 Copy_u8Value ){

	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	 if(Copy_u8Port<=DIO_PORTD){
	switch( Copy_u8Port ){

	case DIO_PORTA: PORTA_REG = Copy_u8Value     ;  break;
	case DIO_PORTB: PORTB_REG = Copy_u8Value     ;  break;
	case DIO_PORTC: PORTC_REG = Copy_u8Value     ;  break;
	case DIO_PORTD: PORTD_REG = Copy_u8Value     ;  break;
	default       : LOC_enumState = DIO_NOK  ;  break;

	}
	 }
	 else {
	 	 LOC_enumState = DIO_NOK;
	  }

	return LOC_enumState ;

}

DIO_ErrorStatus DIO_enumTogPortValue    ( u8 Copy_u8Port ){

	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	 if(Copy_u8Port<=DIO_PORTD){
	switch( Copy_u8Port ){

	case DIO_PORTA: PORTA_REG =   ~ PORTA_REG     ;  break;
	case DIO_PORTB: PORTB_REG =   ~ PORTB_REG     ;  break;
	case DIO_PORTC: PORTC_REG =   ~ PORTC_REG     ;  break;
	case DIO_PORTD: PORTD_REG =   ~PORTD_REG     ;  break;
	default       : LOC_enumState = DIO_NOK     ;  break;

	}
	 }
	 else {
	 	 LOC_enumState = DIO_NOK;
	  }

	return LOC_enumState ;

}

DIO_ErrorStatus DIO_enumGetPortValue     ( u8 Copy_u8Port , u8 * Copy_u8ptrData ){

	DIO_ErrorStatus LOC_enumState = DIO_OK;
	 if(Copy_u8Port<=DIO_PORTD){
	switch( Copy_u8Port ){

	case DIO_PORTA : *Copy_u8ptrData = PINA_REG ; break;
	case DIO_PORTB : *Copy_u8ptrData = PINB_REG ; break;
	case DIO_PORTC : *Copy_u8ptrData = PINC_REG ; break;
	case DIO_PORTD : *Copy_u8ptrData = PIND_REG ; break;
	default        : LOC_enumState = DIO_NOK    ; break;

	}
	 }
	 else {
	 	 	 LOC_enumState = DIO_NOK;
	 	  }
	return LOC_enumState ;

}


DIO_ErrorStatus DIO_enumSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 Copy_u8Direction ){

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if((Copy_u8Port<=DIO_PORTD) && ( Copy_u8PinNumber >= DIO_PIN0 ) && ( Copy_u8PinNumber <= DIO_PIN7 ) ){

		switch( Copy_u8Port ){

		case DIO_PORTA:

			if      ( Copy_u8Direction == DIO_OUTPUT ){ (DDRA_REG |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Direction == DIO_INPUT  ){(DDRA_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;

		case DIO_PORTB:

			if      ( Copy_u8Direction == DIO_OUTPUT ){ (DDRB_REG |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Direction == DIO_INPUT  ){(DDRB_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;
		case DIO_PORTC:

			if      ( Copy_u8Direction == DIO_OUTPUT ){ (DDRC_REG |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Direction == DIO_INPUT  ){ (DDRC_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;
		case DIO_PORTD:

			if      ( Copy_u8Direction == DIO_OUTPUT ){ (DDRD_REG |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Direction == DIO_INPUT  ){ (DDRD_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;

		default      : LOC_enumState = DIO_NOK ; break;

		}

	}else{ LOC_enumState = DIO_NOK ; }

	return LOC_enumState ;
}
DIO_ErrorStatus DIO_enumSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 Copy_u8Value     ){

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if((Copy_u8Port<=DIO_PORTD) && ( Copy_u8PinNumber >= DIO_PIN0 ) && ( Copy_u8PinNumber <= DIO_PIN7 ) ){

		switch( Copy_u8Port ){

		case DIO_PORTA:

			if      ( Copy_u8Value == DIO_HIGH ){ (PORTA_REG  |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Value == DIO_LOW   ){ (PORTA_REG &= ~ (1<<Copy_u8PinNumber));}

			else{ LOC_enumState = DIO_NOK ; }

			break;

		case DIO_PORTB:

			if      ( Copy_u8Value == DIO_HIGH ){ (PORTB_REG  |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Value == DIO_LOW  ){(PORTB_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;
		case DIO_PORTC:

			if      ( Copy_u8Value == DIO_HIGH ){ (PORTC_REG  |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Value == DIO_LOW  ){ (PORTC_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;
		case DIO_PORTD:

			if      ( Copy_u8Value == DIO_HIGH ){ (PORTD_REG  |=  (1<<Copy_u8PinNumber)); }

			else if ( Copy_u8Value == DIO_LOW  ){ (PORTD_REG &= ~ (1<<Copy_u8PinNumber)); }

			else{ LOC_enumState = DIO_NOK ; }

			break;

		}

	}else{ LOC_enumState = DIO_NOK ; }

	return LOC_enumState ;

}

DIO_ErrorStatus DIO_enumTogPinValue      ( u8 Copy_u8Port , u8 Copy_u8PinNumber  ){

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if((Copy_u8Port<=DIO_PORTD) && ( Copy_u8PinNumber >= DIO_PIN0 ) && ( Copy_u8PinNumber <= DIO_PIN7 ) ){

		switch( Copy_u8Port ){

		case DIO_PORTA:


			break;

		case DIO_PORTB:


			break;
		case DIO_PORTC:


			break;
		case DIO_PORTD:


			break;

		}

	}else{ LOC_enumState = DIO_NOK ; }

	return LOC_enumState ;

}



DIO_ErrorStatus DIO_enumGetPinValue      ( u8 Copy_u8Port , u8 Copy_u8PinNumber , u8 * Copy_u8ptrData ){

	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if( (Copy_u8Port<=DIO_PORTD) &&( Copy_u8PinNumber >= DIO_PIN0 ) && ( Copy_u8PinNumber <= DIO_PIN7 ) ){

		switch( Copy_u8Port ){

		case DIO_PORTA : *Copy_u8ptrData = ((PINA_REG >> (Copy_u8PinNumber)) & 1) ; break;
		case DIO_PORTB : *Copy_u8ptrData = ((PINB_REG >> (Copy_u8PinNumber)) & 1) ; break;
		case DIO_PORTC : *Copy_u8ptrData = ((PINC_REG >> (Copy_u8PinNumber)) & 1) ; break;
		case DIO_PORTD : *Copy_u8ptrData = ((PIND_REG >> (Copy_u8PinNumber)) & 1) ; break;
		default        : LOC_enumState = DIO_NOK    ; break;

		}

	}
	else{ LOC_enumState = DIO_NOK    ; }

	return LOC_enumState ;

}


