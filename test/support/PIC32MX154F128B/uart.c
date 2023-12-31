#include <stdbool.h>

#include <xc.h>

#include "uart.h"

void uart_end(void);

void uart_start(void)
{
	SYSKEY = 0;
	SYSKEY = 0xAA996655;
	SYSKEY = 0x556699AA;
	CFGCONbits.IOLOCK = 0;
	
	U1RXRbits.U1RXR = 1;
	RPB7Rbits.RPB7R = 1;
	
	CFGCONbits.IOLOCK = 1;
	SYSKEY = 0;
	
	U1MODEbits.BRGH = 1;
	U1BRG = 155;
	
	U1MODEbits.ON = 1;
	U1STAbits.UTXEN = 1;
}

void uart_stop(void)
{
	while (!U1STAbits.TRMT);
	
	U1STAbits.UTXEN = 0;
	U1MODEbits.ON = 0;
	
	uart_end();
}

void uart_end(void)
{
	while (true);
}

int uart_putchar(int c)
{
	while (!IFS1bits.U1TXIF);
	U1TXREG = c;
	IFS1bits.U1TXIF = 0;
	return c;
}
