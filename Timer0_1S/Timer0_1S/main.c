/*
 * Timer0_1S.c
 *
 * Created: 8/14/2021 5:58:18 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>


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

	int overflowCounter = 0;
    while (1) 
    {
		if(TCNT0 >= 254)
		{
			overflowCounter++;
		}

		if(overflowCounter == 4)
		{
			PORTB ^= 1<<PB0;
			overflowCounter = 0;
			//4 overflow means timer passed around 1 Second
		}

    }
}

