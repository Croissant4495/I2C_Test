
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
//#include "TWI_int.h"
//#include "TWI_private.h"
//#include "EXT_EEPROM_int.h"
//#include <avr/interrupt.h>
//#include"string.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

int main()
{
	u8 data = 2;
//	u8 old_data;
	LCD_voidInit();
//	M_TWI_void_Init();

//
//	EXTINT_voidInit(EXT0_ID,FALLING_EDGE);
//	EXTINT_voidSetCallBack(toggle_LED, EXT0_ID);

//	ADC_voidInit();
//	ADC_voidChannelSellect(CHANNEL_1);

//	DIO_voidSetPinDirection(PORTB_ID, PIN2, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);

//	ADC_StartConversion()
	LCD_voidClear();
	LCD_voidGoToXY(0,0);
	LCD_voidWriteNumber(0);
	_delay_ms(500);

//	GIE_Enable();
	while(1)
	{
//		ADC_StartConversionBoling(&data);
//		data = ADC_Mapping(0, 1023, 0, 100);


		UART_U8ReceiveChar(&data);
		LCD_voidClear();
		LCD_voidGoToXY(0,0);
		LCD_voidWriteNumber(data);
		_delay_ms(200);
//			old_data = data
//
//			TIMER0_VoidSetPWMCompareMatch(data);
////			TIMER0_VoidInit();
////			TIMER0_VoidStart();
////			_delay_ms(200);
//		while(M_TWI_u8_SendSlaveAddressRead((data + count)) != NO_ERROR);
//		while()
		LCD_voidClear();
		LCD_voidGoToXY(0,0);
//		LCD_voidWriteNumber(*(data + count));
//		count = (count + 1) % 10;
//		M_TWI_u8_ReadByte();


	}/* end of ----->  while(1)*/


	return 0 ;
}

