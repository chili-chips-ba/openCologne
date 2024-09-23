#!/bin/sh
make clean && make all && putty -serial /dev/ttyACM0 -sercfg 115200,8,n,1,N

