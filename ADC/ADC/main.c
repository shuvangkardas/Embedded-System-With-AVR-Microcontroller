/*
 * ADC.c
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
void adc_init();
uint16_t adc_read(uint8_t channel);

int main(void)
{
    //ADC Initialize
	adc_init();
	uart_init();
    while (1) 
    {
		uint16_t adc0 = adc_read(0);
		uart_send_str("ADC0 : ");
		//uart_send_u16(adc0);
		uart_print_float(123.4);
		uart_send_str("\r\n");
		_delay_ms(50);
    }
}

void adc_init()
{
	ADMUX |= 1<<REFS0;				   //AVCC as reference voltage
	ADCSRA |= (1<<ADPS1) | (1<<ADPS0); //Division factor 8
	ADCSRA |= 1<<ADEN ; //Enable ADC
}

uint16_t adc_read(uint8_t channel)
{
	//by default ADC0 Selected
	ADCSRA |=1<<ADSC; //start conversion
	while(!(ADCSRA &(1<<ADIF))); //wait until conversion completes
	uint16_t adc_value = ADCW; //read adc value
	ADCSRA |= 1<<ADIF; //Clear ADIF by writing 1 to the Flag
	return adc_value;
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

void uart_print_float(float n)
{
	char buf[20];
	sprintf(buf,"%f",n);
	uart_send_str(buf);
}