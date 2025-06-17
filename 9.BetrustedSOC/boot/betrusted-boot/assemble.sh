#!/bin/bash

set -euxo pipefail

crate=betrusted-boot

# remove existing blobs because otherwise this will append object files to the old blobs
mkdir -p bin
rm -f bin/*.a

riscv64-unknown-elf-gcc -ggdb3 -c -mabi=ilp32 -march=rv32imac src/asm.S -o bin/$crate.o
ar crs bin/riscv32imac-unknown-none-elf.a bin/$crate.o
ar crs bin/riscv32imc-unknown-none-elf.a bin/$crate.o

riscv64-unknown-elf-gcc -ggdb3 -c -mabi=ilp32 -march=rv32i src/asm.S -DSKIP_MULTICORE -o bin/$crate.o
ar crs bin/riscv32i-unknown-none-elf.a bin/$crate.o

riscv64-unknown-elf-gcc -ggdb3 -c -mabi=lp64 -march=rv64imac src/asm.S -o bin/$crate.o
ar crs bin/riscv64imac-unknown-none-elf.a bin/$crate.o
ar crs bin/riscv64gc-unknown-none-elf.a bin/$crate.o

rm bin/$crate.o
