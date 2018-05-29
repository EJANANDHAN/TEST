/*
 * uart_COM.c
 *
 * Created: 3/21/2018 3:09:26 PM
 *  Author: anand
 */ 

#include "uart_COM.h"


void usart_init( uint16_t ubrr) {
	// Set baud rate
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)ubrr;
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// Set frame format: 8data, 1stop bit
	UCSR0C = (1<<UMSEL00)|(3<<UCSZ00);
}




void uartInit( signed int ubrr, unsigned char com )
{
	switch(com)
	{
		
	
	case 1:
		
	//Set baud rate 
	
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	//Enable receiver and transmitter 
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	// Set frame format: 8data, 2stop bit  
	
	//UCSR0C = (1<<USBS0)|(3<<UCSZ00);
	UCSR0C = (3<<UCSZ00);
	
	break;
	
	}		
	
}

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
		while ( !( UCSR0A & (1<<UDRE0)) )
		;
		
/* Put data into buffer, sends the data */
UDR0 = data;

}