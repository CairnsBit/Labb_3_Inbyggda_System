#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/atomic.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "button.h"

#define NUM_OF_PRESSES 20
#define NUM_OF_NONPRESSES 20

unsigned long lastPushed = 0;
unsigned long debounceDelay = 1000;

int counter = 0;

int stateMessageP = 1;
int stateMessageR = 1;

void main(void) {

	LED_init();
	BUTTON_init();
	uart_init();
	//timer_init();
	millis_init();

	while (1) {
		if ((millis() - lastPushed) > debounceDelay) {
			if (BUTTON_PRESSED) {
				LED_on;
				if (stateMessageP == 1) {
					uart_buttonState();
					stateMessageP = 0;
				}
			}
			else if (!(BUTTON_PRESSED)) {
				LED_off;
				if (stateMessageR == 1) {
					uart_buttonState();
					stateMessageR = 0;
				}

			}
		}
		if (stateMessageP == 0 & stateMessageR == 0) {
			stateMessageP = 1;
			stateMessageR = 1;
		}
	}
}

unsigned long millis() {
	unsigned long millis_return;
	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		millis_return = timer1_millis;
	}
	return millis_return;
}

ISR(TIMER1_COMPA_vect) {
	timer1_millis++;
}

ISR(TIMER0_COMPA_vect) {
	//...
}


