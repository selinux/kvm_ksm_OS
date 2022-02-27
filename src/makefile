include ../common.mk


ifeq ($(DEBUG),0)
CC_FLAGS=-O3
LD_FLAGS=-T linker.ld
else
CC_FLAGS=-g -O0
LD_FLAGS=-g -T linker.ld
endif


KERNEL_C_SRC=$(shell find . -name *.c)
KERNEL_C_OBJ=$(KERNEL_C_SRC:.c=.o)
KERNEL_ASM_SRC= $(shell find . -name *.asm)
KERNEL_ASM_OBJ=$(KERNEL_ASM_SRC:.asm=.o)

KERNEL_OUT=kernel.elf

all: update_version $(KERNEL_OUT)

update_version:
	./gen_version.sh version.h

%.o: %.asm
	$(AS) -f elf64 $< -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) $(CC_DEFINES) -I. -I./x86_64/ $< -o $@

$(KERNEL_OUT): $(KERNEL_C_OBJ) $(KERNEL_ASM_OBJ)
	$(LD) $^ -o $@ $(LD_FLAGS)

clean:
	@echo delete $(KERNEL_C_OBJ) $(KERNEL_ASM_OBJ)
	@echo delete kernel.elf
	@rm -f $(KERNEL_OUT)
	@find . -name "*.o" -exec rm {} \;
	@find . -name "*.d" -exec rm {} \;


.PHONY: clean
#build-x86_64: $(kernel_object_files) $(x86_64_object_files)
#	mkdir -p dist/x86_64 && \
#	$(LD) -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(x86_64_object_files) && \
#	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
#	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso

