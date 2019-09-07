/**
 * @file printf.c
 * @brief UART経由での標準出力処理
 */

#include "uart.h"

#define PRINTF_STRING_BUF_SIZE	(0x10000)
static char printf_string_buf[PRINTF_STRING_BUF_SIZE] = {'\0'};

/**
 * @fn static void parse_string(char* format, __builtin_va_list args)
 * @brief formatを解析して出力文字列を返す
 * @param[in] format 出力する文字列のフォーマット
 * @param[in] args 変数リスト
 * @param[out] dst 出力する文字列を格納するバッファ
 * @return なし
 * @detail formatを解析して出力文字列を返す
 */
static void parse_string(char* format, __builtin_va_list args)
{
	char* dst = printf_string_buf;

	while (*format) {
		*dst++ = *format;
		format++;
	}
	*dst = '\0';
}

/**
 * @fn void printf(char* format, ...)
 * @brief UART経由での標準出力処理
 * @param[in] format 出力する文字列のフォーマット
 * @param[out] なし
 * @return なし
 * @detail UART経由での標準出力処理
 */
void printf(char* format, ...)
{
	__builtin_va_list args;

	__builtin_va_start(args, format);
	parse_string(format, args);
	mini_uart_puts(printf_string_buf);
}


