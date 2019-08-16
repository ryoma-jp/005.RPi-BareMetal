//--------------------
// LEDを点滅させるアセンブラコードのサンプル
// GPIO21を使う
//--------------------

.section ".text.boot"

.global _start

//--------------------
// パラメータ定義
//--------------------
.equ GPIO_PHYSICAL_ADDR_BASE, 0x3F20	// lsl 16して使う

.equ GPFSEL2, 0x08		// GPFSEL2 Offset
.equ GPFSEL2_BIT3, 0x08		// GPFSEL2[FSEL21]=0b001 にセット

.equ GPSET0, 0x1C		// GPSET0 Offset
.equ GPSET0_BIT21, 0x200000	// GPSET0[SET21]

.equ GPCLR0, 0x28		// GPCLR0 Offset
.equ GPCLR0_BIT21, 0x200000	// GPCLR0[CLR21]

.equ COUNTER, 0xF0000

//--------------------
// スタートラベル
//--------------------
_start:
	mrs x0, MPIDR_EL1
	and x0, x0, #0xFF
	cbz x0, cpuid_eq_0

cpuid_gt_0:
	// --- CPU0以外はイベント待ちで止める ---
	wfe
	b cpuid_gt_0

cpuid_eq_0:
	// --- 初期状態：消灯 ---
	mov x0, GPFSEL2
	movk x0, GPIO_PHYSICAL_ADDR_BASE, lsl 16
	mov w1, GPFSEL2_BIT3
	str w1, [x0]

	mov x0, GPCLR0
	movk x0, GPIO_PHYSICAL_ADDR_BASE, lsl 16
	mov w1, GPCLR0_BIT21
	str w1, [x0]

	// --- 点滅 ---
	mov w2, COUNTER
	led_flashing:
		// --- 点灯 ---
		mov x0, GPSET0
		movk x0, GPIO_PHYSICAL_ADDR_BASE, lsl 16
		mov w1, GPSET0_BIT21
		str w1, [x0]
	
		mov w3, 0
		delay1:
			add w3, w3, #1
			cmp w3, w2
			bne delay1
	
		// --- 消灯 ---
		mov x0, GPCLR0
		movk x0, GPIO_PHYSICAL_ADDR_BASE, lsl 16
		mov w1, GPCLR0_BIT21
		str w1, [x0]

		mov w3, 0
		delay2:
			add w3, w3, #1
			cmp w3, w2
			bne delay2

		b led_flashing

halt:
	// --- フェールセーフ ---
	nop
	nop
	nop
	b halt

