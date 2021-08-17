/*
 * UART_Module.c
 *
 * Created: 8/16/2021 9:37:38 PM
 * Author : Shuvangkar
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void uart_init();
void uart_send_char(char c);
void uart_send_str(char *str);
void uart_send_u16(uint16_t n);

#define UBRR_VALUE 12
//#define UBRR_VALUE 300 //Just for example
//0000 0001 0010 1100
//0000 0001 0010 1100>>8
//0000 0000 0000 0001

int main(void)
{

	uart_init();

	uint16_t value = 0 ;
	while (1)
	{
		//uart_send_str("SHUVANGKAR\r\n");
		uart_send_u16(value);
		value++;
		uart_send_str("\r\n");
		_delay_ms(1000);
		
	}
}


void uart_init()
{
	UBRR0L = (uint8_t)UBRR_VALUE;
	UBRR0H = (uint8_t)(UBRR_VALUE>>8); ///Baud Rate 4800
	
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00); //8 bit data, 1 stop bit
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0); //Enable Receiver and Transmitter
}

void uart_send_char(char c)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

void uart_send_str(char *str)
{
	//sampleStr = "SHUVANGKAR"; '\0'
	while(*str !='\0')
	{
		uart_send_char(*str);
		str++;
	}
}

void uart_send_u16(uint16_t n)
{
	char buf[10];
	sprintf(buf,"%d",n);
	uart_send_str(buf);
}