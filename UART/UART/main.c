/*
 * UART.c
 *
 * Created: 8/15/2021 12:21:22 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define UBRR_VALUE 12
//#define UBRR_VALUE 300 //Just for example
//0000 0001 0010 1100
//0000 0001 0010 1100>>8
//0000 0000 0000 0001 

int main(void)
{
	UBRR0L = (uint8_t)UBRR_VALUE;
	UBRR0H = (uint8_t)(UBRR_VALUE>>8); ///Baud Rate 4800
	
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00); //8 bit data, 1 stop bit
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0); //Enable Receiver and Transmitter



    while (1) 
    {
		char data = 'BUET';
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
		_delay_ms(1000);
		
    }
}


