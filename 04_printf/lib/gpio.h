
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/**
* @file gpio.h
* @brief GPIOピンアドレスの定義
*/

#include "common.h"

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

/**
* @def GPPUD
* @brief GPIO Pin Pull-up/down Enable
*/
#define GPPUD		((volatile unsigned int*)(MMIO_BASE+0x00200094))

/**
* @def GPPUDCLK
* @brief GPIO Pin Pull-up/down Enable Clock
*/
#define GPPUDCLK0	((volatile unsigned int*)(MMIO_BASE+0x00200098))
#define GPPUDCLK1	((volatile unsigned int*)(MMIO_BASE+0x0020009C))

#endif // --- GPIO_H_INCLUDED ---
