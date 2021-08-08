/*
 * External_Interrupt.c
 *
 * Created: 8/7/2021 9:27:57 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= 1<<PB0;		//Set PBO as output pin 
	DDRB |= 1<<PB2;     //Set PB2 as output pin
	DDRD &=~(1<<PD2);   //PD2 pin as input

    while (1) 
    {
		//Task 1
		if(PIND & (1<<PD2))
		{
			PORTB &= ~(1<<PB2); //LED Low
		}
		else
		{
			PORTB |= (1<<PB2); //LED High
		}
		
		//Task 2
		PORTB |= 1<<PB0;
		_delay_ms(2000);
		PORTB &= ~(1<<PB0);
		_delay_ms(2000);
    }
}

