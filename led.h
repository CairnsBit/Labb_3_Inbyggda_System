#ifndef _LED_H_
#define _LED_H_		

#define LED_on 		PORTD |= (1 << PORTD6);
#define LED_off 	PORTD &= ~(1 << PORTD6);

void LED_init(void);

uint8_t simple_ramp(void);

#endif // _LED_H_

