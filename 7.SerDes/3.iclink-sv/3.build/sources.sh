# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# The RTL file lists, one place for run-lint.sh, run-format.sh and run-leq.sh.
# The design is 1.hw/top.filelist. Source this file, then call a function with
# the 1.hw directory:
#
#   design_rtl <1.hw>   every .sv/.v file of top, in filelist order
#   own_rtl <1.hw>      our own RTL: what run-format.sh formats and the verible
#                       phase lints. All of it for now; LiteX-generated
#                       Verilog, once in, is linted but not formatted.

design_rtl() {
  sed -e 's/\r$//' -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//' "$1/top.filelist" |
    grep -E '^[^#+].*\.s?v$' | sed -e "s|\${HW_SRC}|$1|"
}

own_rtl() {
  design_rtl "$1"
}

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
