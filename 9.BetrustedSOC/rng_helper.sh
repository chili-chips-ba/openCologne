#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 [filename_root] <iterations>"
    echo "If no iterations specified, a single iteration is assumed"
    exit 1
fi

if [ "$#" -eq 2 ]; then
    ITERATIONS=$2
    echo "Running $ITERATIONS iterations of dump..."
else
    ITERATIONS=1
fi

i=0

while [ $i -le $ITERATIONS ]
	 do
	     SUFFIX=$(date +'%s')
	     NAME=$1_$SUFFIX
	     echo "Iteration $i: Dumping memory to $NAME"
	     yes | riscv64-unknown-elf-gdb -ex 'file /home/bunnie/code/betrusted-soc/fw/target/riscv32imac-unknown-none-elf/release/betrusted-soc' -ex 'target remote 10.0.245.90:3333' -ex 'mon reset' -ex 'quit'
	     # takes 36 seconds to run the avalanche generator on boot
	     # sleep 40
	     # takes 80 seconds to run the ring oscillator generator on boot
	     sleep 90 
	     # sleep 4
	     yes | riscv64-unknown-elf-gdb -ex 'file /home/bunnie/code/betrusted-soc/fw/target/riscv32imac-unknown-none-elf/release/betrusted-soc' -ex 'target remote 10.0.245.90:3333' -ex "dump memory $NAME 0x40080000 0x40880000" -ex 'quit'
	     ((i++))
done
