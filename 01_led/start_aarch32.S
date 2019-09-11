//--------------------
// LEDを点滅させるアセンブラコードのサンプル
// GPIO21を使う
//--------------------

.section ".text.boot"

.global _start

//--------------------
// パラメータ定義
//--------------------
.equ GPIO_PHYSICAL_ADDR_BASE, 0x20200000

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
	// --- 初期状態：消灯 ---
	ldr r0, =GPIO_PHYSICAL_ADDR_BASE
	ldr r1, =GPFSEL2_BIT3
	str r1, [r0, #GPFSEL2]

	ldr r1, =GPCLR0_BIT21
	str r1, [r0, #GPCLR0]

	// --- 点滅 ---
	ldr r2, =COUNTER
	led_flashing:
		// --- 点灯 ---
		ldr r1, =GPSET0_BIT21
		str r1, [r0, #GPSET0]
	
		ldr r3, =0
		delay1:
			add r3, r3, #1
			cmp r3, r2
			bne delay1
	
		// --- 消灯 ---
		ldr r1, =GPCLR0_BIT21
		str r1, [r0, #GPCLR0]

		ldr r3, =0
		delay2:
			add r3, r3, #1
			cmp r3, r2
			bne delay2

		b led_flashing

halt:
	// --- フェールセーフ ---
	nop
	nop
	nop
	b halt

