#include <avr/io.h>
#include <stdio.h>
#include "serial.h"
#include "button.h"

static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

char pushed[20] = "pushed\r\n";
char released[20] = "released\r\n";

void uart_init(void) {
	UBRR0H = (unsigned char)(UBRR >> 8);
	UBRR0L = (unsigned char)(UBRR);
	UCSR0A = 0;
	UCSR0B = (1 << TXEN0 | 1 << RXEN0);
	UCSR0C = (1 << UCSZ01 | 1 << UCSZ00);

	stdout = &uart_stdout;
}

int uart_putchar(char chr, FILE *stream) {
	if (chr == '\n') {
		uart_putchar('\r', NULL);
	}
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = chr;
	return 0;
}

char uart_getchar(void) {
	while (!(UCSR0A & (1 << RXC0)))
		;
	return UDR0;
}

void uart_putstr(const char* str) {
	for (int i=0;str[i]!='\0';i++) {
		uart_putchar(str[i], NULL);
	}
}

void uart_buttonState() {
	if (BUTTON_PRESSED) {
		uart_putstr(pushed);
	}
	if (!(BUTTON_PRESSED)) {
		uart_putstr(released);
	}
}
