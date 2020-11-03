#ifndef _BUTTON_H_
#define _BUTTON_H_

#define BUTTON_PRESSED			PIND & (1 << PIND2)

void BUTTON_init(void);

#endif // _BUTTON_H_
