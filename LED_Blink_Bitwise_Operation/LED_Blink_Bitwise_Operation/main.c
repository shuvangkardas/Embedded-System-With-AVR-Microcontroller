/*
 * LED_Blink_Bitwise_Operation.c
 *
 * Created: 8/12/2021 7:23:41 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Setup code

	//Set PB0 pin as output mode
	//DDRB = 0b00000001;
	DDRB |= (1<<PB0);
	DDRB |= (1<<PB1);
	
	//Loop
	while (1)
	{
	/*
		//Led ON at PB0 pin
		//PORTB = 0b00000001;
		PORTB |= (1<<PORTB0);
		//wait for 1s
		_delay_ms(1000);
		//LED Off
		//PORTB = 0b00000000;
		PORTB &= ~(1<<PORTB0);
		//wait for 1s
		_delay_ms(1000);

*/
		//Toggle bit
		PORTB ^=(1<<PB1);
		_delay_ms(1000);

	}
}
