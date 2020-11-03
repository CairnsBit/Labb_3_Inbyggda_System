#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "adc.h"

void adc_init() {
	ADMUX = 0;
	ADMUX |= (1 << REFS0);
	ADMUX |= (1 << ADLAR);
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADIE);
}

const uint8_t convert_range(uint32_t reference_value, uint32_t reference_minimum, uint32_t reference_maximum, uint32_t out_minimum, uint32_t out_maximum) {
	return (reference_value - reference_minimum) * (out_maximum - out_minimum) / (reference_maximum - reference_minimum) + out_minimum;
}
