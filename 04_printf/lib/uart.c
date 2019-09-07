/**
 * @file uart.c
 * @brief UART制御処理
 */

#include "gpio.h"
#include "aux.h"

/**
 * @fn void mini_uart_init()
 * @brief Mini UART制御の初期化
 * @param[in] なし
 * @param[out] なし
 * @return なし
 * @detail Mini UART制御の初期化
 */
void mini_uart_init()
{
	unsigned int reg;
	int i;

	// --- AUXレジスタ初期設定 ---
	*AUX_ENABLES |= 1;	// Mini UART enable
	*AUX_MU_IER_REG = 0;
	*AUX_MU_IIR_REG = 0x06;	// clear the receive and the transmit FIFO
	*AUX_MU_LCR_REG = 3;	// 8-bit mode
	*AUX_MU_MCR_REG = 0;
	*AUX_MU_CNTL_REG = 0;
	*AUX_MU_BAUD_REG = 270;	// 115200 baud ; (250MHz / 8 / 115200) - 1

	// --- GPIO割り付け ---
	reg = *GPFSEL1;
	reg &= ~((7 << 12) | (7 << 15));	// clear FSEL14, FSEL15
	reg |= ((2 << 12) | (2 << 15));		// set alternate function 5
	*GPFSEL1 = reg;

	// --- GPIO Pull-up/down Clock設定 ---
	*GPPUD = 0;
	i = 150;
	while (i--) {
		asm volatile("nop");
	}
	*GPPUDCLK0 = ((1 << 14) | (1 << 15));	// pin14, pin15
	i = 150;
	while (i--) {
		asm volatile("nop");
	}
	*GPPUDCLK0 = 0;
	*AUX_MU_CNTL_REG = 3;		// Receiver/Transmitter enable

}

/**
 * @fn void mini_uart_send(char ch)
 * @brief 文字送信
 * @param[in] ch 送信する文字
 * @param[out] なし
 * @return なし
 * @detail 文字送信
 */
void mini_uart_send(char ch)
{
	// --- wait Transmitter empty ---
	while (!(*AUX_MU_LSR_REG & 0x20)) {
		asm volatile("nop");
	}

	// --- send ---
	*AUX_MU_IO_REG = ch;
}

/**
 * @fn char mini_uart_recv()
 * @brief 文字受信
 * @param[in] なし
 * @param[out] なし
 * @return 受信した文字
 * @detail 文字受信
 */
char mini_uart_recv()
{
	char ch;

	// --- wait Data ready ---
	while (!(*AUX_MU_LSR_REG & 0x01)) {
		asm volatile("nop");
	}

	// --- receive ---
	ch = (char)(*AUX_MU_IO_REG);

	return ch;
}

/**
 * @fn void mini_uart_puts(char *str)
 * @brief 文字列の送信
 * @param[in] str 送信する文字列
 * @param[out] なし
 * @return なし
 * @detail 文字列の送信
 */
void mini_uart_puts(char *str)
{
	while (*str != '\0') {
		if (*str == '\n') {
			mini_uart_send('\r');
		}
		mini_uart_send(*str++);
	}
}

/**
 * @fn void mini_uart_gets(char *str)
 * @brief 文字列の受信
 * @param[in] なし
 * @param[out] str 受信した文字列を格納するバッファ
 * @return なし
 * @detail 文字列の受信
 */
void mini_uart_gets(volatile char *str)
{
	char ch = 0;

	while (ch != '\r') {
		ch = mini_uart_recv();
		mini_uart_send(ch);
		if (ch == '\r') {
			mini_uart_send('\n');
		} else {
			*str++ = ch;
		}
	}
	*str++ = '\n';
	*str++ = '\0';
}

