#!/bin/bash
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# The SerDes BFM against Cologne Chip's simulation model (NDA, not in this
# repository), in Icarus. The vendor model is read from CCFPGA_SERDES_SRC
# and copied to WORK, outside the repository; nothing of it lands here.
#
#   vendor-check.sh prep                    copy the vendor model to WORK: real-valued
#                                           parameters patched (as openCologne-PCIE's
#                                           run-phy.sh does), and a copy renamed
#                                           ccfpga_serdes_ref for side-by-side runs
#   vendor-check.sh rules DP SLIDE          ../tb_rules.sv on the vendor model; compare
#                                           with make -C .. sim_icarus (the BFM)
#   vendor-check.sh equiv                   tb_equiv.sv, both models side by side, each
#                                           looped and crossed: 9 cases x FAST/ACCURATE
#   vendor-check.sh probe ven|bfm STIM "PARAMS" "PLUSARGS" [CDR]
#                                           probe.sv with stims/STIM.vh on one model
#
# Settings: CCFPGA_SERDES_SRC (default ~/opt/ccfpga_serdes/src),
#           WORK (default ~/.cache/ccfpga-vendor-check), JOBS (default 8).
# Logs: WORK/logs.

set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
BFM_DIR=$(cd "$HERE/.." && pwd)
VEN_SRC=${CCFPGA_SERDES_SRC:-$HOME/opt/ccfpga_serdes/src}
WORK=${WORK:-$HOME/.cache/ccfpga-vendor-check}
JOBS=${JOBS:-8}
BFM="$BFM_DIR/ccfpga_serdes_pkg.sv $BFM_DIR/ccfpga_serdes.sv"
mkdir -p "$WORK/logs" "$WORK/build"

need_prep() {
  [ -f "$WORK/ven.f" ] && [ -f "$WORK/ven_ref.f" ] || { echo "run: $0 prep" >&2; exit 1; }
}

prep() {
  [ -d "$VEN_SRC" ] || { echo "no vendor model in $VEN_SRC (set CCFPGA_SERDES_SRC)" >&2; exit 1; }
  rm -rf "$WORK/ven" "$WORK/ven_ref"
  (cd "$VEN_SRC" && find . -type f \( -name '*.v' -o -name '*.sv' \)) | while read -r f; do
    mkdir -p "$WORK/ven/$(dirname "$f")"
    sed -E 's/^([[:space:]]*)parameter([[:space:]]+)([A-Za-z_][A-Za-z0-9_]*)([[:space:]]*=[[:space:]]*[0-9]+\.[0-9]+)/\1parameter\2real \3\4/' \
      "$VEN_SRC/$f" > "$WORK/ven/$f"
  done
  cp -r "$WORK/ven" "$WORK/ven_ref"
  sed -i -E 's/\bmodule[[:space:]]+ccfpga_serdes[[:space:]]*\(/module ccfpga_serdes_ref (/' "$WORK/ven_ref/ccfpga_serdes.v"
  grep -q 'module ccfpga_serdes_ref' "$WORK/ven_ref/ccfpga_serdes.v" || { echo "rename failed" >&2; exit 1; }
  find "$WORK/ven" -type f \( -name '*.v' -o -name '*.sv' \) | sort > "$WORK/ven.f"
  find "$WORK/ven_ref" -type f \( -name '*.v' -o -name '*.sv' \) | sort > "$WORK/ven_ref.f"
  echo "vendor model: $(wc -l < "$WORK/ven.f") files in $WORK"
}

rules() {  # DP SLIDE
  need_prep
  local b="$WORK/build/rules_$1_$2"; mkdir -p "$b"
  iverilog -g2012 -Ptb_rules.DP=$1 -Ptb_rules.SLIDE=$2 -o "$b/r.vvp" $(cat "$WORK/ven.f") "$BFM_DIR/tb_rules.sv" 2>&1 \
    | grep -v -E "warning|sorry" | head || true
  vvp -n "$b/r.vvp" | grep TB_RULES | tee "$WORK/logs/rules_ven_$1_$2.log"
}

equiv_one() {  # DP HARD LANE PRBS CDR CROSS TAG
  local b="$WORK/build/$7" d="-DCDR_MODEL=$5"; mkdir -p "$b"
  [ "$6" = 1 ] && d="$d -DCROSS"
  iverilog -g2012 $d -Ptb_equiv.DP=$1 -Ptb_equiv.HARD=$2 -Ptb_equiv.COMMA_LANE=$3 -Ptb_equiv.PRBS=$4 \
    -o "$b/e.vvp" $BFM $(cat "$WORK/ven_ref.f") "$HERE/tb_equiv.sv" 2>&1 \
    | grep -v -E "warning|sorry|^\s*$" | head -5 > "$WORK/logs/equiv_$7.log" || true
  vvp -n "$b/e.vvp" | grep -E "EQUIV|DIVERGENCE" >> "$WORK/logs/equiv_$7.log" || true
  rm -f "$b/e.vvp"
}

equiv() {  # cases DP:HARD:LANE:PRBS, each CDR_MODEL FAST/ACCURATE, own loop and crossed
  need_prep
  local dp hard lane prbs
  for c in 3:1:0:0 3:1:3:0 3:1:0:1 1:0:0:0 1:0:1:0 1:1:0:0 0:0:0:0 0:0:1:0 0:1:0:0; do
    IFS=: read -r dp hard lane prbs <<< "$c"
    for m in FAST ACCURATE; do for x in 0 1; do
      while [ "$(jobs -rp | wc -l)" -ge "$JOBS" ]; do wait -n; done
      equiv_one $dp $hard $lane $prbs $m $x "${dp}_${hard}_${lane}_${prbs}_${m}_${x}" &
    done; done
  done
  wait
  grep -h "EQUIV:" "$WORK"/logs/equiv_*.log | sort
}

probe() {  # ven|bfm STIM "PARAMS" "PLUSARGS" [CDR]
  local m=$1 st=$2 prm=$3 pla=$4 cdr=${5:-FAST} src def="" pp=""
  local b; b=$(mktemp -d "$WORK/build/probe.XXXXXX")
  cp "$HERE/stims/$st.vh" "$b/stim.vh"
  for p in $prm; do pp="$pp -Ptb.$p"; done
  if [ "$m" = ven ]; then need_prep; src=$(cat "$WORK/ven.f"); else src=$BFM; def="-DCDR_MODEL=$cdr"; fi
  iverilog -g2012 $def $pp -I"$b" -o "$b/sim.vvp" $src "$HERE/probe.sv" 2>&1 \
    | grep -v -E "sorry: Case unique|warning: Some design elements|: warning: |^\s*$" | head -20 || true
  vvp -n "$b/sim.vvp" $pla | grep -v -E "^VCD|WARNING:.*timescale"
  rm -rf "$b"
}

cmd=${1:-}; shift || true
case $cmd in
  prep|rules|equiv|probe) $cmd "$@" ;;
  *) sed -n '/^#   vendor-check.sh prep/,/^# Logs/p' "$0"; exit 2 ;;
esac

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
