/**
 * @file main.c
 * @brief LEDを点灯するメイン処理
 */

#include "gpio.h"
#include "uart.h"

#define UART_BUF_SIZE	(128)

char uart_buf[UART_BUF_SIZE];	// __stack_chk_guardの未定義エラーが解決できなかったので暫定

/**
 * @fn void main()
 * @brief メイン関数
 * @param[in] なし
 * @param[out] なし
 * @return なし
 * @detail LEDを点灯するメイン処理
 */
void main()
{
//	char uart_buf[UART_BUF_SIZE];	// __stack_chk_guardの未定義エラーが発生

	mini_uart_init();

	mini_uart_puts("Hello World!\n");
	mini_uart_puts("> ");

	while (1) {
		mini_uart_gets(uart_buf);
		mini_uart_puts(uart_buf);
		mini_uart_puts("> ");
	}
}

