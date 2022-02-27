
COMMON_FLAGS=-ffreestanding -nostdlib -fno-builtin -fno-stack-protector -static# -fPIE # -fno-pie
CC=gcc -std=gnu11 $(COMMON_FLAGS) -Wall -Wextra -MMD -c

AS=nasm
LD=ld
#LD=gcc
