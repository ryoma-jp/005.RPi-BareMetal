
# --- コマンド ---
CC = aarch64-elf-gcc
LD = aarch64-elf-ld
OBJCOPY = aarch64-elf-objcopy
RM = rm

# --- ファイル ---
TARGET = kernel.img
TARGET_ELF = $(TARGET:.img=.elf)
OBJ_DIR = ./obj
STARTUP = start.S
STARTUP_OBJ = $(OBJ_DIR)/start.o
INC = -I./lib
SRCS = $(wildcard *.c) $(wildcard lib/*.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# --- フラグ ---
CFLAGS = -Wall -O2 -ffreestanding -fno-stack-protector -nostdinc -nostdlib -nostartfiles

# --- 実行タスク ---
.PHONY: all clean

$(TARGET): $(STARTUP_OBJ) $(OBJS)
	$(LD) -nostdlib -nostartfiles $(STARTUP_OBJ) $(OBJS) -T link.ld -o $(TARGET_ELF)
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET)

$(STARTUP_OBJ): $(STARTUP)
	$(CC) $(CFLAGS) -c $(STARTUP) -o $(STARTUP_OBJ)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: clean $(TARGET)

clean:
	$(RM) -f $(TARGET) $(TARGET_ELF) $(STARTUP_OBJ) $(OBJS)

