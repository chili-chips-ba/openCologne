#!/bin/bash
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Lint of the RTL of top (1.hw/top.filelist, via sources.sh), and of the
# SerWB link layer, not in top yet (1.hw/serwb.filelist; tops
# iclink_serwb_pump and iclink_gearbox): syntax and limited semantic checks
# with a set of opensource tools, run in this order:
#
#   tags       every /*LINT:OK*/ sits on an output port (no tool needed)
#   verilator  Verilator --lint-only -Wall: unused/undriven signals, widths,
#              implicit nets, multiple drivers, blocking vs non-blocking, case
#   yosys      Yosys check on the read_slang netlist: combinational loops,
#              conflicting drivers, used-but-undriven wires, latches
#   slang      read_slang -Wextra: strict IEEE parse, second opinion
#   verible    Verible style rules (run-lint.verible) on our own RTL: our case
#              rule -- signals and ports lower case, constants UPPER case --
#              and Verible's defaults
#
# The chip view is linted (SYNTHESIS defined). There is no opensource CDC
# checker mature enough to replace openPCIE's Vivado cdc phase.
#
# usage:  bash run-lint.sh [phase ...]    default: all phases
#
# A phase whose tool is not found is skipped. The tool commands can be
# overridden: VERILATOR, YOSYS (+ YOSYS_ARGS), YOSYS_CONFIG, PYTHON, VERIBLE.
# read_slang is built into the openXC7 Yosys and a plugin in the OSS CAD
# Suite: when YOSYS_ARGS is not set, it is "" if the Yosys has read_slang,
# else "-m slang". The GateMate primitives (CC_SERDES, CC_PLL, ...) come from
# the Yosys library (yosys-config --datdir), as blackboxes.
#
# Sources are copied into a work directory (LINT_WORK, default mktemp -d) and
# every tool gets relative paths. Logs stay there: <phase>.log is the tool
# output, <phase>.findings the findings left after the waivers.
#
# Accepted findings are waived in two ways, each one reviewed:
#   - inline, on an unused output of an instance:  .PIN (/*LINT:OK*/)
#     waives the findings about that pin, from any phase; the tags phase flags
#     a /*LINT:OK*/ on an input, so it cannot hide a floating input
#   - run-lint-waivers.txt (or LINT_WAIVERS=<file>), for findings without a
#     source line of ours (generated code, ...)
# Exit status is non-zero when any phase has findings that are not waived.

set -u
HERE=$(cd "$(dirname "$0")" && pwd)
HW=$HERE/../1.hw
. "$HERE/sources.sh"
TOP=top
VERILATOR=${VERILATOR:-verilator}
YOSYS=${YOSYS:-yosys}
YOSYS_CONFIG=${YOSYS_CONFIG:-yosys-config}
PYTHON=${PYTHON:-python3}
VERIBLE=${VERIBLE:-verible-verilog-lint}
if [ -z "${YOSYS_ARGS+set}" ]; then
  if "$YOSYS" -p 'help read_slang' 2>/dev/null | grep -q 'read_slang \['; then
    YOSYS_ARGS=""
  else
    YOSYS_ARGS="-m slang"
  fi
fi

WAIVERS=${LINT_WAIVERS:-$HERE/run-lint-waivers.txt}
PHASES=${*:-tags verilator yosys slang verible}
W=${LINT_WORK:-$(mktemp -d)}
mkdir -p "$W"

# ---- work copy ----------------------------------------------------------------
rm -rf "$W/1.hw"
cp -r "$HW" "$W/1.hw"
cd "$W"
SV=$(design_rtl 1.hw | tr '\n' ' ')
SERWB=$(serwb_rtl 1.hw | tr '\n' ' ')
OWN=$(own_rtl 1.hw | tr '\n' ' ')
# the designs the verilator, yosys and slang phases lint: top, sources
DESIGNS=("top:$SV" "iclink_serwb_pump:$SERWB" "iclink_gearbox:$SERWB")

have() { command -v "$1" >/dev/null 2>&1; }
declare -A RESULT
skip() { RESULT[$1]="skipped ($2)"; echo "-- $1: skipped, $2"; }

# waiver regexes of one phase: the lines "<phase> <regex>" of the waivers file;
# a regex that never matches keeps grep -v -f from dropping every line when
# the phase has no waiver
waivers() {
  echo '^$'
  [ -f "$WAIVERS" ] || return 0
  awk -v ph="$1" '{ sub(/\r$/, "") } $1 == ph { sub(/^[ \t]*[^ \t]+[ \t]+/, ""); print }' "$WAIVERS"
}

# inline waivers .PIN (/*LINT:OK*/), as file:line:PIN (the first line keeps
# awk's NR==FNR test working when there is none)
{ echo "#"
  grep -n -o -E '\.[A-Za-z_][A-Za-z0-9_]*[[:space:]]*\([[:space:]]*/\*LINT:OK\*/[[:space:]]*\)' $OWN |
    sed -E 's/^([^:]*:[0-9]+):\.([A-Za-z0-9_]*).*/\1:\2/'
} > lint_ok.txt

found() {  # $1 phase; one finding per line on stdin (not a pipe: RESULT must stay in this shell)
  cat > $1.all
  # drop findings about a pin waived inline: file:line plus the 'PIN' the tools
  # quote (Windows tools print \ in paths)
  awk 'NR == FNR { ok[$0] = 1; next }
       { l = $0; gsub(/\\/, "/", l)
         if (match(l, /[A-Za-z0-9_.\/-]+\.s?v:[0-9]+/)) {
           k = substr(l, RSTART, RLENGTH)
           if (match(l, /\047[A-Za-z_][A-Za-z0-9_]*\047/) && (k ":" substr(l, RSTART + 1, RLENGTH - 2)) in ok) next
         }
         print }' lint_ok.txt $1.all > $1.inline
  grep -E -v -f <(waivers $1) $1.inline > $1.findings
  local n=$(wc -l < $1.findings) t=$(wc -l < $1.all) i=$(wc -l < $1.inline)
  RESULT[$1]="$n finding(s), $((t - n)) waived ($((t - i)) inline), see $W/$1.findings"
  echo "-- $1: $n finding(s), $((t - n)) waived ($((t - i)) inline)"
}

# GateMate primitive stubs, for the tags, Verilator, Yosys and slang phases:
# the Yosys blackboxes, plus CC_BUFG, which Yosys has only as a simulation
# model
bb() {
  [ -s bb.v ] && return 0
  have "$YOSYS_CONFIG" || return 1
  { cat "$("$YOSYS_CONFIG" --datdir)/gatemate/cells_bb.v"
    printf '(* blackbox *)\nmodule CC_BUFG (input I, output O);\nendmodule\n'
  } > bb.v
}

# /*LINT:OK*/ on anything but an output port; the port directions come from the
# module headers of the design and the primitive stubs
run_tags() {
  bb || { skip tags "no GateMate stubs (yosys-config)"; return; }
  "$PYTHON" - bb.v -- $OWN > tags.log <<'EOF'
import re, sys
ports_only = sys.argv[1:sys.argv.index('--')]
files = sys.argv[sys.argv.index('--') + 1:]
text = {f: open(f).read() for f in ports_only + files}
types = {'logic', 'wire', 'reg', 'signed', 'unsigned', 'var', 'bit', 'integer', 'tri'}
dirs = {}
for t in text.values():
    t = re.sub(r'//[^\n]*|/\*.*?\*/', '', t, flags=re.S)
    for m in re.finditer(r'\bmodule\s+(\w+)(.*?)\bendmodule', t, flags=re.S):
        d = dirs.setdefault(m.group(1), {})
        for p in re.finditer(r'\b(input|output|inout)\b(.*?)(?=\b(?:input|output|inout)\b|[;()]|$)',
                             m.group(2), flags=re.S):
            for part in re.sub(r'\[[^\]]*\]', ' ', p.group(2)).split(','):
                w = [x for x in re.findall(r'[A-Za-z_]\w*', part) if x not in types]
                if w:
                    d.setdefault(w[-1], p.group(1))
tag  = re.compile(r'\.(\w+)\s*\(\s*/\*LINT:OK\*/\s*\)')
inst = re.compile(r'\s*([A-Za-z_]\w*)\s*(#|\s\w+\s*\()')
kw   = {'if', 'else', 'for', 'begin', 'end', 'case', 'assign', 'module', 'always', 'always_ff',
        'always_comb', 'initial', 'function', 'task', 'return', 'generate'}
for f in files:
    lines = text[f].split('\n')
    for n, line in enumerate(lines, 1):
        for m in tag.finditer(line):
            typ = next((t.group(1) for i in range(n - 1, -1, -1)
                        for t in [inst.match(lines[i])] if t and t.group(1) not in kw), None)
            d = dirs.get(typ, {}).get(m.group(1))
            if d != 'output':
                print(f'{f}:{n}: LINT:OK on {d or "unknown"} port {typ}.{m.group(1)}')
EOF
  found tags < tags.log
}

run_verilator() {
  have "$VERILATOR" || { skip verilator "$VERILATOR not found"; return; }
  bb || { skip verilator "no GateMate stubs (yosys-config)"; return; }
  cat > waive.vlt <<'VLT'
`verilator_config
lint_off -file "*bb.v"
VLT
  : > verilator.log
  for d in "${DESIGNS[@]}"; do
    "$VERILATOR" --lint-only -Wall -Wno-fatal --timing --top-module ${d%%:*} -DSYNTHESIS \
      waive.vlt bb.v ${d#*:} >> verilator.log 2>&1
  done
  found verilator < <(grep -E '^%(Warning|Error)' verilator.log)
}

run_yosys() {
  have "$YOSYS" || { skip yosys "$YOSYS not found"; return; }
  bb || { skip yosys "no GateMate stubs"; return; }
  : > yosys.log
  for d in "${DESIGNS[@]}"; do
    "$YOSYS" $YOSYS_ARGS -q -l yosys.one.log -p "read_slang -D SYNTHESIS --top ${d%%:*} bb.v ${d#*:}; \
        hierarchy -check -top ${d%%:*}; proc; check -nolatches -initdrv" >/dev/null 2>&1
    cat yosys.one.log >> yosys.log
  done
  if grep -q '^ERROR' yosys.log; then
    RESULT[yosys]="error, see $W/yosys.log"; echo "-- yosys: error"; return
  fi
  # read_slang's own warnings are the slang phase's business; take check's
  found yosys < <(awk '/Executing CHECK pass/ { c = 1 } c && /^Warning:/' yosys.log)
}

run_slang() {
  have "$YOSYS" || { skip slang "$YOSYS not found"; return; }
  bb || { skip slang "no GateMate stubs"; return; }
  : > slang.log
  for d in "${DESIGNS[@]}"; do
    "$YOSYS" $YOSYS_ARGS -q -l slang.one.log \
        -p "read_slang -D SYNTHESIS --top ${d%%:*} -Wextra bb.v ${d#*:}" >/dev/null 2>&1
    cat slang.one.log >> slang.log
  done
  if grep -q '^ERROR' slang.log; then
    RESULT[slang]="error, see $W/slang.log"; echo "-- slang: error"; return
  fi
  # the yosys-slang plugin prints "file:line: Warning:", the built-in read_slang
  # "file:line:col: warning:"; bring both to the second form so the waivers
  # match either. Paths come relative to the work directory, after any ../
  found slang < <(sed -E 's#^(\.\./)+[^ ]*/1\.hw/#1.hw/#;
                          s/^([^ :]+:[0-9]+): Warning:/\1:0: warning:/;
                          s/^([^ :]+:[0-9]+): Error:/\1:0: error:/' slang.log |
                  grep -E 'warning:|error:' | grep -v -E '^bb\.v')
}

run_verible() {
  have "$VERIBLE" || { skip verible "$VERIBLE not found"; return; }
  cp "$HERE/run-lint.verible" .
  "$VERIBLE" --rules_config=run-lint.verible $OWN > verible.log 2>&1
  found verible < <(grep -E ':[0-9]+:[0-9]+' verible.log)
}

for ph in $PHASES; do
  case $ph in
    tags|verilator|yosys|slang|verible) echo "== $ph"; run_$ph ;;
    *) echo "unknown phase: $ph (tags verilator yosys slang verible)"; exit 2 ;;
  esac
done

echo; echo "== summary  ($W)"
FAIL=0
for ph in $PHASES; do
  printf '  %-10s %s\n' "$ph" "${RESULT[$ph]}"
  case ${RESULT[$ph]} in skipped*|"0 finding"*) ;; *) FAIL=1 ;; esac
done
exit $FAIL

# -----------------------------------------------------------------------------
# Project:     openCologne
# Description: NLnet-sponsored open-source design ware for GateMate
# -----------------------------------------------------------------------------
