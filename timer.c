#include <avr/io.h>
#include "timer.h"
#include <avr/interrupt.h>
#include <util/atomic.h>


void timer_init() {
	OCR0A = 152;
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02) | (1 << CS00);
	TIMSK0 |= (1 << OCIE0A);
	sei();
}

void millis_init() {
	unsigned long ctc_match_overflow;
	ctc_match_overflow = ((16000000 / 1000) / 8);
	TCCR1B |= (1 << WGM12) | (1 << CS11);
	OCR1AH = (ctc_match_overflow >> 8);
	OCR1AL = ctc_match_overflow;
	TIMSK1 |= (1 << OCIE1A);
	sei();
}

