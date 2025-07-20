PACKAGES=libc libcompiler_rt libbase libfatfs liblitespi liblitedram libliteeth liblitesdcard liblitesata bios
PACKAGE_DIRS=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libc /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libcompiler_rt /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libbase /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libfatfs /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitespi /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitedram /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libliteeth /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitesdcard /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitesata /home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/bios
LIBS=libc libcompiler_rt libbase libfatfs liblitespi liblitedram libliteeth liblitesdcard liblitesata
TRIPLE=riscv64-linux-gnu
CPU=vexriscv
CPUFAMILY=riscv
CPUFLAGS=-march=rv32i2p0_m     -mabi=ilp32 -D__vexriscv__
CPUENDIANNESS=little
CLANG=0
CPU_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/cores/cpu/vexriscv
SOC_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc
PICOLIBC_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/pythondata-software-picolibc/pythondata_software_picolibc/data
PICOLIBC_FORMAT=integer
COMPILER_RT_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/pythondata-software-compiler_rt/pythondata_software_compiler_rt/data
export BUILDINC_DIRECTORY
BUILDINC_DIRECTORY=/home/hamed/FPGA/chili-chips/openCologne/7.SerDes/4.liteiclink/3.build/build/colognechip_gatemate_evb/software/include
LIBC_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libc
LIBCOMPILER_RT_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libcompiler_rt
LIBBASE_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libbase
LIBFATFS_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libfatfs
LIBLITESPI_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitespi
LIBLITEDRAM_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitedram
LIBLITEETH_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/libliteeth
LIBLITESDCARD_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitesdcard
LIBLITESATA_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/liblitesata
BIOS_DIRECTORY=/home/hamed/FPGA/Tools/litex-hub/litex/litex/litex/soc/software/bios
LTO=0
BIOS_CONSOLE_FULL=1