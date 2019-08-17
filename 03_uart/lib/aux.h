
#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

/**
* @file aux.h
* @brief AUXのレジスタ定義
*/

#include "common.h"

/**
* @def AUX_IRQ
* @brief Auxiliary Interrupt status
*/
#define AUX_IRQ		((volatile unsigned int*)(MMIO_BASE+0x00215000))

/**
* @def AUX_ENABLES
* @brief Auxiliary enables
*/
#define AUX_ENABLES	((volatile unsigned int*)(MMIO_BASE+0x00215004))

/**
* @def AUX_MU_IO_REG
* @brief Mini Uart I/O Data
*/
#define AUX_MU_IO_REG	((volatile unsigned int*)(MMIO_BASE+0x00215040))

/**
* @def AUX_MU_IER_REG
* @brief Mini Uart Interrupt Enable
*/
#define AUX_MU_IER_REG	((volatile unsigned int*)(MMIO_BASE+0x00215044))

/**
* @def AUX_MU_IIR_REG
* @brief Mini Uart Interrupt Identify
*/
#define AUX_MU_IIR_REG	((volatile unsigned int*)(MMIO_BASE+0x00215048))

/**
* @def AUX_MU_LCR_REG
* @brief Mini Uart Line Control
*/
#define AUX_MU_LCR_REG	((volatile unsigned int*)(MMIO_BASE+0x0021504C))

/**
* @def AUX_MU_MCR_REG
* @brief Mini Uart Modem Control
*/
#define AUX_MU_MCR_REG	((volatile unsigned int*)(MMIO_BASE+0x00215050))

/**
* @def AUX_MU_LSR_REG
* @brief Mini Uart Line Status
*/
#define AUX_MU_LSR_REG	((volatile unsigned int*)(MMIO_BASE+0x00215054))

/**
* @def AUX_MU_MSR_REG
* @brief Mini Uart Modem Status
*/
#define AUX_MU_MSR_REG	((volatile unsigned int*)(MMIO_BASE+0x00215058))

/**
* @def AUX_MU_SCRATCH
* @brief Mini Uart Scratch
*/
#define AUX_MU_SCRATCH	((volatile unsigned int*)(MMIO_BASE+0x0021505C))

/**
* @def AUX_MU_CNTL_REG
* @brief Mini Uart Extra Control
*/
#define AUX_MU_CNTL_REG	((volatile unsigned int*)(MMIO_BASE+0x00215060))

/**
* @def AUX_MU_STAT_REG
* @brief Mini Uart Extra Status
*/
#define AUX_MU_STAT_REG	((volatile unsigned int*)(MMIO_BASE+0x00215064))

/**
* @def AUX_MU_BAUD_REG
* @brief Mini Uart Baudrate
*/
#define AUX_MU_BAUD_REG	((volatile unsigned int*)(MMIO_BASE+0x00215068))

#endif // --- AUX_H_INCLUDED ---

