//--------------------
// LEDを点滅させるアセンブラコードのサンプル
// GPIO21を使う
//--------------------

.section ".text.boot"

.global _start

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
	// --- main関数をコール ---
	bl main
	b halt

halt:
	// --- フェールセーフ ---
	wfe
	b halt

