/*
 * Led_Blink.c
 *
 * Created: 7/17/2021 3:36:28 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    //Setup code

	//Set PB0 pin as output mode
	DDRB = 0b00000001;
	
	//Loop 
    while (1) 
    {
		//Led ON at PB0 pin
		PORTB = 0b00000001;
		//wait for 1s
		_delay_ms(1000);
		//LED Off
		PORTB = 0b00000000;
		//wait for 1s 
		_delay_ms(1000);

    }
}

