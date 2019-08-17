
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/**
* @file gpio.h
* @brief GPIOピンアドレスの定義
*/

/**
* @def MMIO_BASE
* @brief Memory Mapped I/O(Peripheral Bus)のベースアドレス
*/
#define MMIO_BASE	(0x3F000000)

/**
* @def GPFSEL
* @brief GPIO Function Select
*/
#define GPFSEL0		((volatile unsigned int*)(MMIO_BASE+0x00200000))
#define GPFSEL1		((volatile unsigned int*)(MMIO_BASE+0x00200004))
#define GPFSEL2		((volatile unsigned int*)(MMIO_BASE+0x00200008))
#define GPFSEL3		((volatile unsigned int*)(MMIO_BASE+0x0020000C))
#define GPFSEL4		((volatile unsigned int*)(MMIO_BASE+0x00200010))
#define GPFSEL5		((volatile unsigned int*)(MMIO_BASE+0x00200014))

/**
* @def GPSET
* @brief GPIO Pin Output Set
*/
#define GPSET0		((volatile unsigned int*)(MMIO_BASE+0x0020001C))
#define GPSET1		((volatile unsigned int*)(MMIO_BASE+0x00200020))

/**
* @def GPCLR
* @brief GPIO Pin Output Clear
*/
#define GPCLR0		((volatile unsigned int*)(MMIO_BASE+0x00200028))
#define GPCLR1		((volatile unsigned int*)(MMIO_BASE+0x0020002C))

#endif // --- GPIO_H_INCLUDED ---
