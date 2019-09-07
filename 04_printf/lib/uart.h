
#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

/**
* @file uart.h
* @brief UART制御処理の定義
*/

extern void mini_uart_init();
extern void mini_uart_puts(char *str);
extern void mini_uart_gets(char *str);

#endif // --- UART_H_INCLUDED ---
