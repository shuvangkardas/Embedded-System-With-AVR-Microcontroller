/*
 * Button_Input.c
 *
 * Created: 8/7/2021 12:09:34 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>


int main(void)
{
    
	DDRB |= 1<<PB0;		//PBO as output pin 
	DDRD &=~(1<<PD2);   //PD2 pin as input

	/*
	PD2 = 2
	0000 00001<<2	 => 0000 0100
	~(1<<PD2)		 => 1111 1011
	DDRD &=~(1<<PD2) => DDRD = DDRD & ~(1<<PD2);

	DDRD = 0111 1101
		 & 1111 1011
		---------------
		   0111 1001
	*/

    while (1) 
    {
		//button pressed : PIND = 0b0001 0000 & 0b0000 0100 = 0b0000 0000
		//button released: PIND = 0b0001 0100 & 0b0000 0100 = 0b0000 0100

		if(PIND & (1<<PD2))
		{
			PORTB &= ~(1<<PB0); //LED Low
		}
		else
		{
			PORTB |= (1<<PB0); //LED High
		}
		
    }
}

