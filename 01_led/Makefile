
# --- コマンド ---
CC = aarch64-elf-gcc
LD = aarch64-elf-ld
OBJCOPY = aarch64-elf-objcopy
RM = rm

# --- ファイル ---
TARGET = kernel.img
TARGET_ELF = $(TARGET:.img=.elf)
STARTUP = start.S
STARTUP_OBJ = $(STARTUP:.S=.o)

# --- フラグ ---
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

# --- 実行タスク ---
.PHONY: all clean
all: clean $(TARGET)

$(STARTUP_OBJ): $(STARTUP)
	$(CC) $(CFLAGS) -c $(STARTUP) -o $(STARTUP_OBJ)

$(TARGET): $(STARTUP_OBJ)
	$(LD) -nostdlib -nostartfiles $(STARTUP_OBJ) -T link.ld -o $(TARGET_ELF)
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET)

clean:
	$(RM) -f $(TARGET) $(TARGET_ELF) $(STARTUP_OBJ)

run:
	qemu-system-aarch64 -M raspi3 -kernel $(TARGET) -d in_asm

