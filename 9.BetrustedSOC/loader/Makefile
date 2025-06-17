all:
	riscv64-unknown-elf-as -fpic ../../../loader/loader.S -o loader.elf
	riscv64-unknown-elf-objcopy -O binary loader.elf bios.bin
