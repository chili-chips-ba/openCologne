#!/bin/bash

set -e  # exit on any error

UPDATE_FPGA=1
UPDATE_KERNEL=1
FPGA_IMAGE=soc-gw.bin
KERNEL_IMAGE=soc-fw.bin
CSR_CSV=soc-csr.csv
CUSTOM_CSV=0
EC_IMAGE=ec-image.bin
TARGET_DIR="invalid"

POSITIONAL=()
while [[ $# -gt 0 ]]
do
  key="$1"    
  case $key in
      -c|--csr-csv)
	  shift
	  CSR_CSV=$1
	  CUSTOM_CSV=1
	  shift
	  ;;
      -d|--directory)
	  shift
	  TARGET_DIR=$1
	  shift
	  ;;
      -k|--kernel-skip)
	  UPDATE_KERNEL=0
	  shift
	  ;;
      -f|--fpga-skip)
	  UPDATE_FPGA=0
	  shift
	  ;;
      -h|--help)
		echo "$0 provisions betrusted. --kernel-skip skips the kernel, --fpga-skip skips the FPGA."
	  exit 0
	  ;;
      *)
	  POSITIONAL+=("$1")
	  shift
	  ;;
  esac
done

set -- "${POSITIONAL[@]}"

if [ $TARGET_DIR == "invalid" ]
then
    echo "Must specify target directory with -d argument"
    exit 1
fi

if [ $CUSTOM_CSV -eq 1 ]
then
    CSRPATH=$CSR_CSV
else
    CSRPATH=$TARGET_DIR/$CSR_CSV
fi

# strip extra slashes
TARGET_DIR=$(echo $TARGET_DIR | sed 's:/*$::')

md5sum $TARGET_DIR/$FPGA_IMAGE
md5sum $TARGET_DIR/$KERNEL_IMAGE
md5sum $CSRPATH
md5sum $TARGET_DIR/$EC_IMAGE

if [ $UPDATE_KERNEL -eq 1 ]
then
  echo "Burning firmware"
  sudo wishbone-tool --csr-csv $CSRPATH --load-name $TARGET_DIR/$KERNEL_IMAGE --load-address 0x500000 --load-flash
fi
if [ $UPDATE_FPGA -eq 1 ]
then
  echo "Burning FPGA image"
  sudo wishbone-tool --csr-csv $CSRPATH --load-name $TARGET_DIR/$FPGA_IMAGE --load-address 0x0 --load-flash
  echo "*** Manual power cycle required to reload SoC FPGA configuration ***"
  echo " -> Either issue a power cycle command, or insert paper clip in the hole on the right hand side!"
fi

sudo wishbone-tool 0x40080000 --burst-source $TARGET_DIR/$EC_IMAGE
echo "Type 'ecup all' and then 'ecreset' on the Precursor device to update the EC"
