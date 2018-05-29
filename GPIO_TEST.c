#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "uart_COM.h"

#define RELAY PORTB0
#define BUZZER PORTC5

#define LED1 PORTC0
#define LED2 PORTC1
#define LED3 PORTC2

//#define RELAYPORT PORTB
//#define LEDPORT PORTB

#define SETPIN	(PORT,PIN)		(PORT |= (1<<PIN))
#define CLEARPIN(PORT,PIN)		(PORT &= ~(1<<PIN))

int t=55;


int main(void)
{
	DDRB= 0XFF;
	DDRC= 0XFF;
	
	CLEARPIN(PORTB, LED1);
	_delay_ms( 500 );
	

    while(1)
    {
      	SETPIN(PORTC, LED1);
		SETPIN(PORTC, LED2);
		SETPIN(PORTC, LED3);
		SETPIN(PORTC, BUZZER);
		SETPIN(PORTB, RELAY);
				
 		//USART_Transmit(5);
		 
		_delay_ms(1000 );
		
		CLEARPIN(PORTC, LED1);
		CLEARPIN(PORTC, LED2);
		CLEARPIN(PORTC, LED3);
		CLEARPIN(PORTC, BUZZER);
		CLEARPIN(PORTB, RELAY);
		
		_delay_ms(1000);
	}
}
