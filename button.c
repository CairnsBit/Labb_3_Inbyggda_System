#include <avr/io.h>
#include "button.h"

void BUTTON_init() {
	DDRD &= ~(1 << PORTD2);
}