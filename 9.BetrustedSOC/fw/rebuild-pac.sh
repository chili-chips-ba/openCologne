#!/bin/sh

if [ ! -e betrusted-pac ]
then
   mkdir betrusted-pac
fi
# if we're using an environment that has the build, take the lastest soc.svd
# otherwise, use the one checked into the environment
if [ -e ../build/software/soc.svd ]
then
    cp ../build/software/soc.svd .
fi
cd betrusted-pac
svd2rust --target riscv -i ../soc.svd
rm -rf src; form -i lib.rs -o src/; rm lib.rs
cargo doc
cargo fmt

