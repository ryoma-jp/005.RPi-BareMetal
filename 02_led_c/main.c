/**
 * @file main.c
 * @brief LEDを点灯するメイン処理
 */

#include "gpio.h"

#define INTERVAL	(0xF0000)

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
	unsigned int reg;
	volatile int i;

	// --- GPIO21(GPFSEL2[FSEL21; 5-3])をoutput(0b001)にセット ---
	reg = *GPFSEL2;
	reg &= ~(7 << 3);
	reg |= (1 << 3);
	*GPFSEL2 = reg;

	// --- 点滅 ---
	while (1) {
		// --- 点灯 ---
		*GPSET0=(1 << 21);

		i = 0;
		while (i < INTERVAL) {
			i++;
		}

		// --- 消灯 ---
		*GPCLR0=(1 << 21);

		i = 0;
		while (i < INTERVAL) {
			i++;
		}
	}
}

