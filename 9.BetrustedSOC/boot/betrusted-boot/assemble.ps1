# remove existing blobs because otherwise this will append object files to the old blobs
Remove-Item -Force bin/*.a

$crate = "betrusted-boot"

riscv64-unknown-elf-gcc -ggdb3 -c -mabi=ilp32 -march=rv32imac src/asm.S -o bin/$crate.o
riscv64-unknown-elf-ar crs bin/riscv32imac-unknown-none-elf.a bin/$crate.o
riscv64-unknown-elf-ar crs bin/riscv32imc-unknown-none-elf.a bin/$crate.o

riscv64-unknown-elf-gcc -ggdb3 -c -mabi=ilp32 -march=rv32i src/asm.S -DSKIP_MULTICORE -o bin/$crate.o
riscv64-unknown-elf-ar crs bin/riscv32i-unknown-none-elf.a bin/$crate.o

riscv64-unknown-elf-gcc -ggdb3 -c -mabi=lp64 -march=rv64imac src/asm.S -o bin/$crate.o
riscv64-unknown-elf-ar crs bin/riscv64imac-unknown-none-elf.a bin/$crate.o
riscv64-unknown-elf-ar crs bin/riscv64gc-unknown-none-elf.a bin/$crate.o

Remove-Item bin/$crate.o
