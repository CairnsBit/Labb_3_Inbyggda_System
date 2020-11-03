#include <avr/io.h>
#include "timer.h"
#include <avr/interrupt.h>
#include <util/atomic.h>


void timer0_init() {
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
	TCCR0B |= (1 << CS01) | (1 << CS00);
	TIMSK0 |= (1 << OCIE0A);
}
void timer2_init() {
	TCCR2A |= (1 << WGM21);
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
	TIMSK2 |= (1 << TOIE2);
	TIMSK2 |= (1 << OCIE2A);
	OCR2A = (F_CPU / 1024 / 1000 - 1);
	sei();
}