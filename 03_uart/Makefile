
# --- コマンド ---
CC = aarch64-elf-gcc
LD = aarch64-elf-ld
OBJCOPY = aarch64-elf-objcopy
RM = rm
MKDIR = mkdir

# --- ファイル ---
TARGET = kernel.img
TARGET_ELF = $(TARGET:.img=.elf)
TARGET_MAP = $(TARGET:.img=.map)
OBJ_DIR = ./obj
ASM_DIR = ./asm
STARTUP = start.S
STARTUP_OBJ = $(OBJ_DIR)/start.o
INC = -I./lib
SRCS = $(wildcard *.c) $(wildcard lib/*.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
ASMS = $(SRCS:%.c=$(ASM_DIR)/%.s)

# --- フラグ ---
CFLAGS = -Wall -O2 -ffreestanding -fno-stack-protector -nostdinc -nostdlib -nostartfiles

# --- 実行タスク ---
.PHONY: all clean asm clean_asm

$(TARGET): $(STARTUP_OBJ) $(OBJS)
	$(LD) -nostdlib -nostartfiles $(STARTUP_OBJ) $(OBJS) -T link.ld -o $(TARGET_ELF) -Map $(TARGET_MAP)
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET)

$(STARTUP_OBJ): $(STARTUP)
	$(CC) $(CFLAGS) -c $(STARTUP) -o $(STARTUP_OBJ)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(ASM_DIR)/%.s: %.c
	$(CC) -S $(CFLAGS) $(INC) -c $< -o $@

all: clean $(TARGET)

clean:
	$(RM) -f $(TARGET) $(TARGET_ELF) $(TARGET_MAP) $(STARTUP_OBJ) $(OBJS)

asm: $(ASMS)

clean_asm:
	$(RM) -f $(ASMS)


