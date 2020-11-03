#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdint.h>
#include <util/atomic.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"
#include "adc.h"

volatile uint16_t adcValue;


void main(void) {
	LED_init();
	BUTTON_init();
	uart_init();
	adc_init();
	timer0_init();
	timer2_init();

	while (1) {
	}
}


ISR(ADC_vect) {
	adcValue = ADC;
}

ISR(TIMER2_COMPA_vect) {
	ADCSRA |= (1 << ADSC);
	ADMUX = 0;
	uint32_t currentAdcValue = convert_range(adcValue, 0, 1023, 0,  255);

	if (currentAdcValue == 0) {
		LED_off;

	}
	else {
		OCR0A = currentAdcValue;
	}
}


