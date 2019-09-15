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
	// --- スタックポインタをセット ---
	ldr r1, =_start
	mov sp, r1

	// --- bss領域を初期化 ---
init_bss:
	ldr r1, =__bss_start
	ldr r2, =__bss_size
	cmp r2, #0
	beq init_bss_end
//	cbz r2, init_bss_end
	ldr r3, =#0
init_bss_loop:
	str r3, [r1], #4
	sub r2, r2, #1
	cmp r2, #0
	bne init_bss_loop
//	cbnz r2, init_bss_loop
init_bss_end:

	// --- main関数をコール ---
	bl main
	b halt

//	// --- 初期状態：消灯 ---
//	ldr r0, =GPIO_PHYSICAL_ADDR_BASE
//	ldr r1, =GPFSEL2_BIT3
//	str r1, [r0, #GPFSEL2]
//
//	ldr r1, =GPCLR0_BIT21
//	str r1, [r0, #GPCLR0]
//
//	// --- 点滅 ---
//	ldr r2, =COUNTER
//	led_flashing:
//		// --- 点灯 ---
//		ldr r1, =GPSET0_BIT21
//		str r1, [r0, #GPSET0]
//	
//		ldr r3, =0
//		delay1:
//			add r3, r3, #1
//			cmp r3, r2
//			bne delay1
//	
//		// --- 消灯 ---
//		ldr r1, =GPCLR0_BIT21
//		str r1, [r0, #GPCLR0]
//
//		ldr r3, =0
//		delay2:
//			add r3, r3, #1
//			cmp r3, r2
//			bne delay2
//
//		b led_flashing

halt:
	// --- フェールセーフ ---
	wfe
	b halt

