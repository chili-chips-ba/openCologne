	lui  a0, 0x20980   	    # form address 0x2098_0000: a0 arg for xous-kernel.bin
	lui  a2, 0x20501        # form address 0x2050_1000: location of xous-loader.bin (stage 1)
	#lui  a2, 0x20D00        # form address 0x20D0_0000: test bootloader location - not part of Xous, it's a spot we can place some code in FLASH so we don't have to rebuild the SoC for small code changes during SoC bootloader dev
	jalr x0, a2, 0          # jump to xous-loader.bin
