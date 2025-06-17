Reset-vector loader for Xous.

Currently, just a couple assembly instructions that put the xous stage 1 args
into register a0 and then jumps to the XIP xous stage 1 image.

Eventually, this is a 32-kiB in-FPGA trusted ROM that will need to do signature
checking on the SPI ROM image, and then jump to the code.

