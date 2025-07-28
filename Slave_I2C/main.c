
/*==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
////#include "avr/io.h"
#include "DIO_Interface.h"
//#include "EXTINT_Interface.h"
//#include "UART_Interface.h"
//#include "SPI_Interface.h"
#include "GIE_Interface.h"
//#include "ADC_Interface.h"
//#include "TMR0_Interface.h"
//#include "KPD_Interface.h"
#include "LCD_Interface.h"
//#include "TIMER1_int.h"
#include "TWI_int.h"
//#include "TWI_private.h"
//#include "EXT_EEPROM_int.h"
//#include"string.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

// ___________SLAVE_CODE___________

int main()
{
	u16 data = 0;
	u8 high_byte = 0;
	u8 low_byte = 0;
	u8 status = 0;
//	u8 old_data;
	LCD_voidInit();
	M_TWI_void_Init();

	DIO_voidSetPinDirection(PORTD_ID, PIN7, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD_ID, PIN6, PIN_OUTPUT);

	DIO_voidSetPinValue(PORTD_ID, PIN7, PIN_LOW);
	DIO_voidSetPinValue(PORTD_ID, PIN6, PIN_LOW);

	GIE_Enable();
	while(1)
	{
		status = M_TWI_SLAVE_ADDRESS_LISTEN();

		if (status == 0){
			// Write
			DIO_voidSetPinValue(PORTD_ID, PIN6, PIN_LOW);
			DIO_voidToggelPin(PORTD_ID, PIN7);

//		    M_TWI_u8_ReadByte(&high_byte);  // Read high byte
		    M_TWI_u8_ReadByte(&low_byte);   // Read low byte
//
//		    data = ((u16)high_byte << 8) | low_byte;
		    LCD_voidClear();
			LCD_voidWriteNumber(low_byte);
		}else if(status == 1){
			// Read
			DIO_voidSetPinValue(PORTD_ID, PIN6, PIN_HIGH);
			DIO_voidToggelPin(PORTD_ID, PIN7);
		}else if(status == 2){
			// Wrong address
			DIO_voidSetPinValue(PORTD_ID, PIN6, PIN_HIGH);
			DIO_voidSetPinValue(PORTD_ID, PIN7, PIN_HIGH);
		}
		_delay_ms(500);
	}/* end of ----->  while(1)*/


	return 0 ;
}

