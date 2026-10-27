#!/bin/bash
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Formal equivalence check of the whole design (top) between two versions of
# the RTL, with Yosys (read_slang), chip view (SYNTHESIS defined). Use it to
# prove that a cleanup does not change behaviour.
#
# usage:  bash run-leq.sh <gold 1.hw> <gate 1.hw> [sed script]
#         LEQ_EXTRA=<file> bash run-leq.sh ... Yosys commands run after equiv_make,
#                                              e.g. equiv_add for registers that
#                                              were regrouped into a struct
#                                              (gold: name_gold, gate: name_gate):
#           cd eq
#           equiv_add -try \u_x.ng_cur_state_gold \u_x.ng_q_gate[12]
#           cd ..
#   <gold 1.hw>, <gate 1.hw>  copies of 1.hw, e.g. before the change
#                             (from the repo root):
#                             mkdir -p /tmp/gold && git archive HEAD 7.SerDes/3.iclink-sv/1.hw | tar -x -C /tmp/gold
#                             bash 7.SerDes/3.iclink-sv/3.build/run-leq.sh /tmp/gold/7.SerDes/3.iclink-sv/1.hw 7.SerDes/3.iclink-sv/1.hw
#   [sed script]              renames gold objects to their gate names, for a
#                             change that moves logic between modules, e.g.
#                             's|^u_phy\.u_x\.|u_phy.|'
#
# The GateMate primitives (CC_SERDES, CC_PLL, CC_USR_RSTN, CC_BUFG) are black
# boxes turned into ports (expose -evert): their inputs are compared, their
# outputs are shared free inputs. equiv_induct starts from any state, so logic
# that is only constant after reset shows up as unproven and needs a look by
# hand. Only "Equivalence successfully proven" is a pass.
#
# Needs Yosys with read_slang: built into the openXC7 Yosys, a plugin in the
# OSS CAD Suite. When YOSYS_ARGS is not set, it is "" if the Yosys has
# read_slang, else "-m slang". YOSYS and YOSYS_CONFIG override the commands.
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
. "$HERE/sources.sh"
GOLD=$(cd "$1" && pwd); GATE=$(cd "$2" && pwd); MAP=${3:-}
TOP=top
YOSYS=${YOSYS:-yosys}
YOSYS_CONFIG=${YOSYS_CONFIG:-yosys-config}
if [ -z "${YOSYS_ARGS+set}" ]; then
  if "$YOSYS" -p 'help read_slang' 2>/dev/null | grep -q 'read_slang \['; then
    YOSYS_ARGS=""
  else
    YOSYS_ARGS="-m slang"
  fi
fi
W=$(mktemp -d); cd "$W"

# GateMate primitives: the Yosys blackboxes, plus CC_BUFG, which Yosys has
# only as a simulation model
{ cat "$("$YOSYS_CONFIG" --datdir)/gatemate/cells_bb.v"
  printf '(* blackbox *)\nmodule CC_BUFG (input I, output O);\nendmodule\n'
} > bb.v

files() {  # $1 = 1.hw dir
  echo bb.v $(design_rtl "$1" | tr '\n' ' ')
}
BB="t:CC_SERDES t:CC_PLL t:CC_USR_RSTN t:CC_BUFG"
PREP="hierarchy -top $TOP; proc; flatten; memory; async2sync"

REN=""
if [ -n "$MAP" ]; then   # rename gold objects to their gate names (skip names the gold already has)
  cat > names.ys <<EOF
read_slang -D SYNTHESIS --top $TOP $(files $GOLD)
$PREP
tee -q -o names.txt select -list $TOP/w:* $TOP/c:*
EOF
  "$YOSYS" $YOSYS_ARGS -q names.ys >/dev/null
  sed "s|^$TOP/||" names.txt | sed -n "h; $MAP; G; s/\n/ /; p" |
    awk 'NR==FNR {have[$1]=1; next} $1!=$2 && substr($2,1,1)!="$" && !($1 in have) {print "rename \\" $2 " \\" $1}' \
        <(sed "s|^$TOP/||" names.txt) - > ren.ys
  echo "renamed: $(wc -l < ren.ys)"
  REN="cd $TOP; script ren.ys; cd .."
fi

EXTRA=""
[ -n "${LEQ_EXTRA:-}" ] && EXTRA="script $(cd "$(dirname "$LEQ_EXTRA")" && pwd)/$(basename "$LEQ_EXTRA")"

cat > eq.ys <<EOF
read_slang -D SYNTHESIS --top $TOP $(files $GOLD)
$PREP
$REN
expose -evert $BB; opt_clean; rename $TOP gold; design -stash gold
read_slang -D SYNTHESIS --top $TOP $(files $GATE)
$PREP
expose -evert $BB; opt_clean; rename $TOP gate; design -stash gate
design -copy-from gold -as gold gold
design -copy-from gate -as gate gate
equiv_make gold gate eq
hierarchy -top eq
$EXTRA
equiv_simple -seq 3
equiv_induct -seq 3
equiv_status
EOF
rc=0
"$YOSYS" $YOSYS_ARGS -q -l eq.log eq.ys >/dev/null || rc=$?
grep -E "Found [0-9]+ .equiv|Of those cells|Equivalence successfully proven|^ERROR" eq.log | tail -3
grep "Unproven" eq.log | sed -E 's/.*: .([^ ]*)_gold.*/\1/; s/\[[0-9]+\]//g' | sort | uniq -c
echo "log: $W/eq.log"

# Pass only if Yosys got through equiv_status and proved every $equiv cell
unproven=$(sed -nE 's/.*Of those cells [0-9]+ are proven and ([0-9]+) are unproven.*/\1/p' eq.log | tail -1)
if [ $rc -ne 0 ] || [ -z "$unproven" ] || [ "$unproven" -ne 0 ]; then
  echo "LEQ: FAILED (yosys exit $rc, unproven: ${unproven:-no equiv_status result})"
  exit 1
fi
echo "LEQ: PASS"

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
