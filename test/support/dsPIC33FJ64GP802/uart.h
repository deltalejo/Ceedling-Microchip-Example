#ifndef UART_H
#define UART_H

void uart_start(void);
void uart_stop(void);
void uart_end(void);
int uart_putchar(int c);

#endif /* UART_H */
