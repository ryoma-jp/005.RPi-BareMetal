
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
INC = -I./lib
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# --- フラグ ---
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

# --- 実行タスク ---
.PHONY: all clean
all: clean $(TARGET)

$(STARTUP_OBJ): $(STARTUP)
	$(CC) $(CFLAGS) -c $(STARTUP) -o $(STARTUP_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET): $(STARTUP_OBJ) $(OBJS)
	$(LD) -nostdlib -nostartfiles $(STARTUP_OBJ) $(OBJS) -T link.ld -o $(TARGET_ELF)
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET)

clean:
	$(RM) -f $(TARGET) $(TARGET_ELF) *.o

