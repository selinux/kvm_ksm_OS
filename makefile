SYSTEM?=UEFI
PLATFORM?=QEMU

GRUB_CONF=grub/grub.cfg
GRUB_MKRESCUE_ARGS=/usr/lib/grub/i386-pc

QEMU=qemu-system-x86_64 -enable-kvm -m 128
ISO_NAME=yoctos.iso
FS_NAME=fs.img


help:
	@echo "Available targets:"
	@echo "run      build the OS ISO image (+ filsystem) and run it in QEMU"
	@echo "iso      build the OS ISO image (+ filesystem)"
	@echo "kernel   build the kernel only"
	@echo "debug    build the OS ISO image (+ filsystem) and run it in QEMU for debugging"
	@echo "clean    clean up everything"
	@echo ""
	@echo "Available variables:"
	@echo "SYSTEM   target system type, either UEFI or BIOS (default: UEFI)"
	@echo "PLATFORM target platform type, either QEMU or PC (default: QEMU)"
	@echo "DEBUG    whether to generate debug code, either on or off (default: on)"
	@echo ""
	@echo "Usage examples:"
	@echo "make run"
	@echo "make run SYSTEM=BIOS PLATFORM=QEMU"

iso: $(ISO_NAME) $(FS_NAME)

msg:
	@echo "================================================="
	@echo "Build targeting a $(PLATFORM)/$(SYSTEM) platform"
	@echo "================================================="

run: $(ISO_NAME)
	$(QEMU) -cdrom $< -drive file=$(FS_NAME),index=0,media=disk,format=raw

$(ISO_NAME): msg $(GRUB_CONF) kernel fs
	mkdir -p build/boot/grub
	mkdir -p build/fs/
	cp $(FS_NAME) build/fs/
	cp $(GRUB_CONF) build/boot/grub/
	cp src/kernel.elf build/boot/
	grub-mkrescue $(GRUB_MKRESCUE_ARGS) -o $@ build
	@echo "Built the $@ image for a $(SYSTEM) system."

kernel:
	$(MAKE) -C src

fs: $(FS_NAME)

$(FS_NAME): tools $(wildcard resources/*)
	$(MAKE) -C common
	$(MAKE) -C tools
	tools/fs_create MyFS 1024 100 2000 $@
	for i in resources/*; do tools/fs_add $$i $@; done


clean:
	/bin/rm -rf build
	/bin/rm -f $(ISO_NAME) $(FS_NAME)
	$(MAKE) -C src clean
	$(MAKE) -C tools clean
	$(MAKE) -C common clean


.PHONY: clean kernel