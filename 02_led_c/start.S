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
	b halt

cpuid_eq_0:
	// --- スタックポインタをセット ---
	ldr x1, =_start
	mov sp, x1

	// --- bss領域を初期化 ---
init_bss:
	ldr x1, =__bss_start
	ldr w2, =__bss_size
	cbz w2, init_bss_end
init_bss_loop:
	str xzr, [x1], #8
	sub w2, w2, #1
	cbnz w2, init_bss_loop
init_bss_end:

//	mov x0, GPFSEL2
//	movk x0, GPIO_PHYSICAL_ADDR_BASE, lsl 16
//	mov w1, GPFSEL2_BIT3
//	str w1, [x0]
//    
//	mov x0, GPSET0
//	movk x0, GPIO_PHYSICAL_ADDR_BASE, lsl 16
//	mov w1, GPSET0_BIT21
//	str w1, [x0]
//	
//	b halt

	// --- main関数をコール ---
	bl main
	b halt

halt:
	// --- フェールセーフ ---
	wfe
	b halt

