# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# The RTL file lists, one place for run-lint.sh, run-format.sh and run-leq.sh.
# The design is 1.hw/top.filelist; the SerWB link layer, also linted on its
# own, is 1.hw/serwb.filelist. Source this file, then call a function with the
# 1.hw (or 2.sim) directory:
#
#   design_rtl <1.hw>   every .sv/.v file of top, in filelist order
#   serwb_rtl <1.hw>    every .sv file of the SerWB link layer, in order
#   own_rtl <1.hw>      our own RTL, both lists: what run-format.sh formats and
#                       the verible phase lints. All of it for now;
#                       LiteX-generated Verilog, once in, is linted but not
#                       formatted.
#   ref_rtl <2.sim>     the simulation-only reference RTL, the LiteX 8b/10b
#                       port: linted and formatted like our own, not in top

filelist_rtl() {  # <1.hw> <filelist>
  sed -e 's/\r$//' -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//' "$1/$2" |
    grep -E '^[^#+].*\.s?v$' | sed -e "s|\${HW_SRC}|$1|"
}

design_rtl() {
  filelist_rtl "$1" top.filelist
}

serwb_rtl() {
  filelist_rtl "$1" serwb.filelist
}

ref_rtl() {
  printf '%s\n' "$1/iclink_8b10b_pkg.sv" "$1/iclink_8b10b_enc.sv" "$1/iclink_8b10b_dec.sv"
}

own_rtl() {
  { design_rtl "$1"; serwb_rtl "$1"; } | awk '!seen[$0]++'
}

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
