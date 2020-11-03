#ifndef _TIMER_H_
#define _TIMER_H_
#define F_CPU 16000000UL
volatile unsigned long timer1_millis;

void timer0_init(void);

void timer2_init(void);

#endif // _TIMER_H_
