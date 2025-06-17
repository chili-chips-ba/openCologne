#!/bin/bash

# some helper routines to strictly check that vivado didn't fail on timing constraints

# I can't use this anymore, because a timing route failure prior to final route throws a critical warning, even if it is fixed later :( ??
if grep -q "CRITICAL WARNING" build/gateware/vivado.log
then
    echo "Critical warnings found -- likely regressions on XDC timing constraints! Check vivado.log and top.xdc."
    exit 1
fi

if grep -q "VIOLATED" build/gateware/timing-failures.txt
then
    echo "Design did not meet simple timing analysis!"
    exit 2
fi
