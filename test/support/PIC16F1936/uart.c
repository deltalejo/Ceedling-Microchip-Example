#include <xc.h>

#include "uart.h"

static inline void poll_tx_complete(void)
{
	while (!PIR1bits.TXIF);
}

static void uart_output_complete()
{
	NOP();
}

void uart_start(void)
{
	RCSTAbits.SPEN = 1;
	TXSTAbits.TXEN = 1;
}

void uart_end(void)
{
	poll_tx_complete();
	TXSTAbits.TXEN = 0;
	RCSTAbits.SPEN = 0;
	uart_output_complete();
}

int uart_putchar(int c)
{
	TXREG = (unsigned char) c;
	NOP();
	poll_tx_complete();
	return c;
}

void putch(char c)
{
	(void) uart_putchar(c);
}
