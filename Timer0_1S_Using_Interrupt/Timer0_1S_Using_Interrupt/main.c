/*
 * Timer0_1S_Using_Interrupt.c
 *
 * Created: 8/14/2021 7:53:45 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int overflowCounter = 0;

int main(void)
{
	/*
	Clk = 1MHz
	Prescaler = 1024
	Timer Clock Frequency  = 1MHZ/1024 = 976.5625HZ
	(1/976.57)*256  = 0.261 Second
	For 1 second Overfow count  = 4(almost)
	*/

	DDRB |= 1<<PB0; //Set PB0 as output

	TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS02); //Timer Counter starts with prescaler 1024. 
	TCNT0 = 0; //reset counter

	TIMSK0 |= 1<<TOIE0; //Enable Overflow Interrupt of Timer0
	sei();

	
    while (1) 
    {

		if(overflowCounter == 4)
		{
			PORTB ^= 1<<PB0;
			overflowCounter = 0;
			//4 overflow means timer passed around 1 Second
		}

    }
}

ISR(TIMER0_OVF_vect)
{
	overflowCounter++;
}
