#!/bin/bash

if [ "$#" -ne 1 ]
then
    echo "Needs a target directory parameter"
    exit 1
fi
   
TARGET_DIR=$1

# strip extra slashes
TARGET_DIR=$(echo $TARGET_DIR | sed 's:/*$::')

mkdir -p $TARGET_DIR

echo "Remember: this scripts assumes you've already built and tested all the images, and that they are in a consistent state."
cp /tmp/betrusted-soc.bin $TARGET_DIR/soc-fw.bin
cp ../build/csr.csv $TARGET_DIR/soc-csr.csv
cp ../build/software/soc.svd $TARGET_DIR/soc.svd
cp ../build/gateware/encrypted.bin $TARGET_DIR/soc-gw.bin
cp ../../betrusted-ec/target/riscv32i-unknown-none-elf/release/bt-ec.bin $TARGET_DIR/ec-image.bin
cp ../../betrusted-ec/build/csr.csv $TARGET_DIR/ec-csr.csv
cp ../../betrusted-ec/build/software/soc.svd $TARGET_DIR/ec.svd
echo "Done."
