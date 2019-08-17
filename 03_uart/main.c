/**
 * @file main.c
 * @brief LEDを点灯するメイン処理
 */

#include "gpio.h"
#include "uart.h"

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
	mini_uart_init();

	mini_uart_puts("Hello World!\n");

	while (1) {
		asm volatile("nop");
	}
}

