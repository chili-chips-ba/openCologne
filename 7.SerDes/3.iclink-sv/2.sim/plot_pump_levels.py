#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2026 Chili.CHIPS
#
# SPDX-License-Identifier: BSD-3-Clause
#
# End2End Flow chart: the FIFO levels of tb_serwb_pump phase 2 (B stops
# reading, A floods, B reads again), from pump_levels.csv.
#
# usage: plot_pump_levels.py [pump_levels.csv] [images/pump-levels.png]

import csv
import sys

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt

DEPTH, XOFF, XON = 1024, 832, 512  # W = 2: XOFF = DEPTH - 96*W
CLK_NS = 32.0

SURFACE, INK, INK2, MUTED, GRID, AXIS = "#fcfcfb", "#0b0b0b", "#52514e", "#898781", "#e1e0d9", "#c3c2b7"
B_RX, A_TX = "#2a78d6", "#eb6834"  # categorical slots 1 and 2


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else "pump_levels.csv"
    out = sys.argv[2] if len(sys.argv) > 2 else "images/pump-levels.png"
    rows = list(csv.DictReader(open(src)))
    t0   = int(rows[0]["time_ps"])
    t    = [(int(r["time_ps"]) - t0) / 1e6 for r in rows]  # us
    b_rx = [int(r["b_rx_used"]) for r in rows]
    a_tx = [int(r["a_tx_used"]) for r in rows]
    bp   = [int(r["b_pause"]) for r in rows]
    ap   = [int(r["a_paused"]) for r in rows]

    def first(pred, start=0):
        return next(i for i in range(start, len(rows)) if pred(i))

    i_xoff  = first(lambda i: bp[i] == 1)
    i_stop  = first(lambda i: ap[i] == 1)
    i_go    = first(lambda i: ap[i] == 0, i_stop)
    i_peak  = max(range(i_xoff, i_go), key=lambda i: b_rx[i])  # while A is paused
    i_full  = first(lambda i: a_tx[i] >= DEPTH)
    i_read  = first(lambda i: b_rx[i] < b_rx[i_peak] - 4, i_peak)
    i_xon   = first(lambda i: bp[i] == 0, i_xoff)

    plt.rcParams.update({"font.family": "DejaVu Sans", "font.size": 10})
    fig, ax = plt.subplots(figsize=(10, 4.6), dpi=150)
    fig.patch.set_facecolor(SURFACE)
    ax.set_facecolor(SURFACE)

    # A paused by B (between XOFF and XON arriving at A): a light band
    ax.axvspan(t[i_stop], t[i_go], color=GRID, alpha=0.6, lw=0, zorder=0)
    ax.text((t[i_stop] + t[i_go]) / 2, 40, "A paused by B (XOFF ... XON)", color=INK2,
            ha="center", va="bottom", fontsize=9)

    for y, name in ((DEPTH, "FIFO depth 1024"), (XOFF, "XOFF level 832"), (XON, "XON level 512")):
        ax.axhline(y, color=MUTED, lw=1, ls=(0, (4, 3)), zorder=1)
        ax.text(t[-1], y + 8, name, color=INK2, ha="right", va="bottom", fontsize=9)

    ax.plot(t, b_rx, color=B_RX, lw=2, zorder=3, label="B RX FIFO (receiver)")
    ax.plot(t, a_tx, color=A_TX, lw=2, zorder=3, label="A TX FIFO (sender)")

    i_cyc = max(range(i_go, len(rows)), key=lambda i: b_rx[i])  # first refill peak after XON

    def mark(i, y, n, dx=7, dy=4):
        ax.plot([t[i]], [y], "o", ms=8, mfc=SURFACE, mec=INK, mew=1.5, zorder=4)
        ax.annotate(str(n), (t[i], y), xytext=(dx, dy), textcoords="offset points", color=INK,
                    fontsize=10, fontweight="bold")

    mark(i_xoff, b_rx[i_xoff], 1, -14, -6)
    mark(i_peak, b_rx[i_peak], 2, -14, 2)
    mark(i_full, a_tx[i_full], 3, 4, -16)
    mark(i_read, b_rx[i_read], 4, 6, 4)
    mark(i_xon, b_rx[i_xon], 5, 6, -14)
    mark(i_cyc, b_rx[i_cyc], 6, 6, 2)

    ax.set_xlim(0, t[-1])
    ax.set_ylim(0, DEPTH + 90)
    ax.set_xlabel("time since B stopped reading (us)", color=INK2)
    ax.set_ylabel("words in FIFO", color=INK2)
    ax.set_yticks([0, 256, 512, 768, 1024])
    ax.grid(axis="y", color=GRID, lw=0.8)
    for s in ("top", "right"):
        ax.spines[s].set_visible(False)
    for s in ("left", "bottom"):
        ax.spines[s].set_color(AXIS)
    ax.tick_params(colors=MUTED)
    ax.set_title("FIFO pump flow control, measured (tb_serwb_pump, 2.5 Gb/s, line 29 clocks)",
                 color=INK, loc="left", fontsize=11)
    leg = ax.legend(loc="upper left", bbox_to_anchor=(0.0, -0.13), ncol=2, frameon=False)
    for txt in leg.get_texts():
        txt.set_color(INK)
    fig.tight_layout()
    fig.savefig(out, facecolor=SURFACE)
    print(f"cycle peak {b_rx[i_cyc]} at {t[i_cyc]:.1f} us")
    print(f"{out}: XOFF at clk {i_xoff}, A stops +{i_stop - i_xoff}, peak {b_rx[i_peak]} "
          f"+{i_peak - i_xoff} clk, XON at {b_rx[i_xon]}, A resumes +{i_go - i_xon} clk")


if __name__ == "__main__":
    main()
