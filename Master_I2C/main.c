
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
#include "ADC_Interface.h"
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

// ___________MASTER_CODE___________

int main()
{
	u16 data = 0;
	u8 data_high;
	u8 data_low;
//	u8 address = 0;
//	u8 old_data;
	M_TWI_void_Init();
	LCD_voidInit();

	ADC_voidInit();
	ADC_voidChannelSellect(CHANNEL_1);

	DIO_voidSetPinDirection(PORTA_ID, PIN1, PIN_INPUT);
//	DIO_voidSetPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);

	GIE_Enable();
	while(1)
	{
		ADC_StartConversionBoling(&data);
		LCD_voidClear();
		LCD_voidGoToXY(0,0);
		LCD_voidWriteNumber(data);
		data_high = (data >> 8) & 0xFF;  // Extract upper 8 bits
		data_low  = data & 0xFF;

		TWI_ERROR_STATUS error;

		if ((error = M_TWI_u8_StartCondition()) != NO_ERROR) {
		    LCD_voidWriteString((u8 *)"StartErr");
		    goto stop;
		}
		_delay_ms(1);
		if ((error = M_TWI_u8_SendSlaveAddressWrite(1)) != NO_ERROR) {
		    LCD_voidWriteString((u8 *)"AddrErr");
		    goto stop;
		}
		_delay_ms(1);
		if ((error = M_TWI_u8_SendByte(data_high)) != NO_ERROR) {
		    LCD_voidWriteString((u8 *)"HighErr");
		    goto stop;
		}
		_delay_ms(1);
		if ((error = M_TWI_u8_SendByte(data_low)) != NO_ERROR) {
		    LCD_voidWriteString((u8 *)"LowErr");
		    goto stop;
		}
		_delay_ms(1);
		stop:
		M_TWI_void_StopCondition();

		_delay_ms(100);

	}/* end of ----->  while(1)*/


	return 0 ;
}

