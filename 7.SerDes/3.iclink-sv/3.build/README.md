<!--
SPDX-FileCopyrightText: 2026 Chili.CHIPS

SPDX-License-Identifier: BSD-3-Clause
-->

# Build and QA

The bitstream for the GateMate EVB, open-source flow only, and the RTL QA scripts. Back to [3.iclink-sv](../README.md).

```
make -C 7.SerDes/3.iclink-sv/3.build                   # build/top.bit, 2.5 Gb/s
make -C 7.SerDes/3.iclink-sv/3.build LINE_RATE=5000    # 1250, 2500 or 5000 Mb/s
make -C 7.SerDes/3.iclink-sv/3.build SEED=2            # another place-and-route seed
make -C 7.SerDes/3.iclink-sv/3.build load              # program the EVB over JTAG
```

A new `LINE_RATE` synthesizes again; a new `SEED` or `FREQ` places and routes again (`build/synth.opts`, `build/pnr.opts`).

## From the legacy GateMate tools to Project Peppercorn

The older openCologne examples build with Cologne Chip's own tools: their Yosys and the proprietary `p_r` place & route (`CC_TOOL`). We found `p_r` [unreliable](https://github.com/chili-chips-ba/openCologne/issues/30), with weak [timing reports](https://github.com/chili-chips-ba/openCologne/issues/35). 7.SerDes uses the fully open-source flow only:

| Step | Legacy | Now |
|---|---|---|
| Synthesis | Cologne Chip's Yosys build | Yosys `synth_gatemate` |
| Place & route | `p_r` (proprietary) | nextpnr-himbaechel, `gatemate` uarch |
| Bitstream | `p_r` | `gmpack`, [Project Peppercorn](https://github.com/YosysHQ/prjpeppercorn) |
| Programming | openFPGALoader | openFPGALoader |

Our versions (a blinky and a `CC_SERDES` design pack to bitstreams): Yosys 0.69, nextpnr main `6b438a1c` (built with `-DHIMBAECHEL_UARCH=gatemate`, installed as `nextpnr-himbaechel-gatemate`) and Project Peppercorn v1.14. No vendor tools.

The core builds two ways, so it is usable with or without LiteX.

## Standalone, without LiteX

The SV core is plain RTL: drop it into any GateMate design. What the Makefile runs, for the EVB (`CCGM1A1`), sources from [`../1.hw/top.filelist`](../1.hw/top.filelist), pins from `GateMateA1-EVB.ccf`:

```
yosys -p "read_slang -D SYNTHESIS -G LINE_RATE=2500 --top top $(yosys-config --datdir)/gatemate/cells_bb.v <sources>; \
    synth_gatemate -top top -luttree -nomx8 -json top.json"
printf 'ctx.addClock("clk_core", 31.25)\n' > clocks.py      # LINE_RATE / 80, MHz
nextpnr-himbaechel-gatemate --device CCGM1A1 --json top.json --vopt ccf=GateMateA1-EVB.ccf \
    --vopt out=top.txt --pre-pack clocks.py --router router2 --freq 10 --seed 1
gmpack top.txt top.bit
openFPGALoader -b gatemate_evb_jtag top.bit
```

`clocks.py` constrains the SerDes core clock by its net name; `--freq` covers the rest, the 10 MHz EVB clock. Unlike LiteX, we leave out `--timing-allow-fail`: a timing failure stops the build.

## Within LiteX

LiteX takes the SV core through its Migen wrapper, [`../4.litex`](../4.litex/README.md): `SerDesGateMate`, with the interface of LiteICLink's transceiver PHYs, and a demo SoC on the EVB that builds in about 1 minute. LiteX's GateMate platform has both flows: `toolchain="colognechip"` (Yosys + `p_r`) and `toolchain="peppercorn"` (Yosys + nextpnr + `gmpack`); LiteX-Boards' GateMate targets default to `peppercorn`. For example, LiteX's own EVB SoC:

```
python3 -m litex_boards.targets.colognechip_gatemate_evb --toolchain peppercorn --cpu-type serv --build
```

LiteX writes `build/<target>/gateware/build_<target>.sh` and runs it. For the EVB SoC it is:

```
yosys -l <target>.rpt <target>.ys        # read_verilog ...; synth_gatemate -luttree -nomx8 -top <target>
nextpnr-himbaechel-gatemate --json <target>.json --vopt out=<target>.txt --device CCGM1A1 \
    --vopt ccf=<target>.ccf --router router2 --timing-allow-fail --seed 1 --freq 24
gmpack <target>.txt <target>.bit
```

LiteX picks `nextpnr-himbaechel-gatemate` from `PATH` when it exists, else `nextpnr-himbaechel`. Its BIOS needs a RISC-V GCC on `PATH` (e.g. `riscv-none-elf-gcc`). That SoC builds in 36 s. Our versions: LiteX `d2b47282a`, LiteICLink `8ef8d79`, litex-boards `448c5c1a` (2026-10-21).

## Timing results

`clk_core` Fmax of the board top, after place and route. The one table of record; the other READMEs link here.

| Build | Line rate | Needed | Fmax |
|---|---|---|---|
| board top: PHY, PRBS, FIFO pump at W = 2, clock correction, sticky LED error | 2.5 Gb/s | 31.25 MHz | 38.4 (seed 1), 38.3 MHz (seed 2) |
| the same, before the sticky LED error and saturating counters | 2.5 Gb/s | 31.25 MHz | 38.2 (seed 1), 40.8 MHz (seed 2) |
| the same, before clock correction | 2.5 Gb/s | 31.25 MHz | 38.2 to 41.4 MHz (seeds 1 to 4) |
| the same, with the fabric 8b/10b encoder | 2.5 Gb/s | 31.25 MHz | 32.4 to 35.3 MHz |
| board top without the pump (it needs half `clk_core` at W = 4: not in the top yet) | 5 Gb/s | 62.5 MHz | 67.7 MHz (seed 1) |
| LiteX demo SoC, PHY only ([4.litex](../4.litex/README.md#demo-build)) | 2.5 Gb/s | 31.25 MHz | 61.3 MHz (seed 1) |

1.25 Gb/s runs `clk_core` at 15.625 MHz, half the 2.5 Gb/s clock: the 2.5 Gb/s builds cover it.

## RTL quality assurance

Our standard RTL QA flow, on the [RTL coding rules](../../../RTL-CODING-RULES.md). Sources: [`sources.sh`](sources.sh), from `../1.hw/top.filelist` (the PHY, the FIFO pump and the board top), `../1.hw/serwb.filelist` (SerWB, FIFO pump, gearbox) and the 8b/10b reference in `../2.sim`. Lint and format cover all three; lint also takes the pump, the gearbox and the 8b/10b encoder and decoder as their own tops. LEQ covers the board top. Run from the repo root:

| Command | Checks |
|---|---|
| `bash 7.SerDes/3.iclink-sv/3.build/run-lint.sh` | Lint, 0 findings to pass: `/*LINT:OK*/` tags, Verilator `-Wall`, Yosys `check` (loops, drivers, latches), slang `-Wextra`, Verible style rules. Waivers: `run-lint-waivers.txt` |
| `bash 7.SerDes/3.iclink-sv/3.build/run-format.sh [--check]` | Verible format in the project style (`begin`/`end`, alignment, 100 columns); `--check` only lists unformatted files |
| `bash 7.SerDes/3.iclink-sv/3.build/run-leq.sh <gold 1.hw> <gate 1.hw>` | Yosys formal equivalence of two RTL versions: proves a cleanup changes no behaviour |

Tools: Yosys with read_slang (openXC7 or OSS CAD Suite), Verilator, Verible, python3. CI runs lint (`.github/workflows/lint.yml`) and Verible (`verible.yml`) on every push and pull request.

#### End-of-Document
