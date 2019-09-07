/**
 * @file main.c
 * @brief LEDを点灯するメイン処理
 */

#include "uart.h"
#include "printf.h"

#define UART_BUF_SIZE	(128)

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
	char uart_buf[UART_BUF_SIZE];

	mini_uart_init();

	printf("Hello World!\n");
	printf("> ");

	while (1) {
		mini_uart_gets(uart_buf);
		printf(uart_buf);
		printf("> ");
	}
}

