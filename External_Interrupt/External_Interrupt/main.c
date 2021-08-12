/*
 * External_Interrupt.c
 *
 * Created: 8/7/2021 9:27:57 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
    DDRB |= 1<<PB0;		//Set PBO as output pin 
	DDRB |= 1<<PB2;     //Set PB2 as output pin
	//DDRD &=~(1<<PD2);   //PD2 pin as input


	//Configure Interrupt
	EICRA |= 1<<ISC01;  //Interrupt on Falling Edge
	EIMSK |= 1<<INT0;  //Enable INT0 external interrupt
	sei(); //Global Interrupt Enable

    while (1) 
    {
		
		//Task 1
		/*
		if(PIND & (1<<PD2))
		{
			PORTB &= ~(1<<PB2); //LED Low
		}
		else
		{
			PORTB |= (1<<PB2); //LED High
		}
		*/

		//Task 2
		PORTB |= 1<<PB0;
		_delay_ms(2000);
		PORTB &= ~(1<<PB0);
		_delay_ms(2000);
    }
}


ISR(INT0_vect)
{
	PORTB ^= 1<<PB2;
}


