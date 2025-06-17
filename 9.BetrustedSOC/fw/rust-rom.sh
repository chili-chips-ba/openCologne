#!/bin/bash

if [ -z "$1" ]
then
    OUTPUT=/tmp/betrusted-soc.bin
else
    OUTPUT=$1
fi

riscv64-unknown-elf-objcopy -O binary ../fw/target/riscv32imac-unknown-none-elf/release/betrusted-soc $OUTPUT
