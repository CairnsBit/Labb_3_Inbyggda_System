#ifndef _TIMER_H_
#define _TIMER_H_

volatile unsigned long timer1_millis;

void timer_init(void);

void millis_init(void);

unsigned long millis();

#endif // _TIMER_H_
