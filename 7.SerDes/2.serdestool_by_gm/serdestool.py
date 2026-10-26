#!/usr/bin/env python3
#
#  serdestool -- GateMate FPGA SerDes Toolkit
#
#  Permission to use, copy, modify, and/or distribute this software for any
#  purpose with or without fee is hereby granted, provided that the above
#  copyright notice and this permission notice appear in all copies.
#
#  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
#  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
#  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
#  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
#  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
#  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
#  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
#  Visit https://colognechip.com for more information.
#
#  Copyright (C) 2022 - 2025 Cologne Chip AG <support@colognechip.com>
#  Authors: Patrick Urban
#

import re
import sys
import math
import curses
import random
import signal
import argparse
import datetime
import threading

from time import sleep
from itertools import chain

from pyftdi.ftdi import Ftdi
from pyftdi.jtag import JtagEngine
from pyftdi.usbtools import UsbTools
from pyftdi.bits import BitSequence

Boards_e = ['auto', 'pgm', 'evb']
ArgEpilog = 'example usage: python3 serdestool.py'

SER_CLK_PERIOD_NS = 10.0

class bcolors:
    OK    = '\033[92m' # GREEN
    WARN  = '\033[93m' # YELLOW
    FAIL  = '\033[91m' # RED
    OVR   = '\033[94m' # BLUE
    RESET = '\033[0m'  # RESET COLOR

def ArgHzRegex(value, pat=re.compile(r"^[0-9]+[kM]")):
    if not pat.match(value):
        raise argparse.ArgumentTypeError
    return value

def ArgHzParse(value) -> int:
    freq = 0
    if value.endswith('k'):
        freq = int(value[:-1]) * 1e3
    elif value.endswith('M'):
        freq = int(value[:-1]) * 1e6
    else:
        freq = int(value)
    return freq

def FindAndFormatFtdiAddr(idx=0) -> str:
    ftdiname = {
        0x6010: '2232h',
        0x6014: '232h'
    }
    usb = UsbTools()
    vps_lst = list()
    vps_lst.append((0x0403, 0x6010)) # evb: FT2232H
    vps_lst.append((0x0403, 0x6014)) # pgm: FT232H
    d = usb.find_all(vps=vps_lst)
    if not d:
        raise Exception('Error: No FTDI device found.')
    d = d[idx][0]
    return f'ftdi://ftdi:{ftdiname[d[1]]}/1'

class ColorFormatter:
    pos_cond = ["DONE", "PRESENT", "LOCKED", "IS_ALIGNED", "EN_ADPLL_CTRL", "CONFIG_SEL", "SERDES_ENABLE"]
    neg_cond = ["ERR", "DOWN", "TESTMODE"]
    ovr_cond = ["OVR"]

    @staticmethod
    def get_color_pair(key, value):
        """Returns the curses color pair based on the value conditions."""
        try:
            value = int(value)  # Convert safely to integer
        except ValueError:
            return 0  # Default color if conversion fails

        if any(cond in key for cond in ColorFormatter.pos_cond):
            return 1 if value != 0 else 2  # Green for positive, Yellow for zero
        elif any(cond in key for cond in ColorFormatter.neg_cond) and not any(cond in key for cond in ColorFormatter.ovr_cond):
            return 3 if (value < 1 if key.endswith('_N') else value > 0) else 0  # Red for errors
        elif any(cond in key for cond in ColorFormatter.ovr_cond) and value > 0:
            return 4  # Blue for "OVR" values
        return 0  # Default

class JtagTool:
    CMD_JTAG_ID                = '000000' # 0x00
    CMD_JTAG_BYPASS            = '111111' # 0x3F
    CMD_JTAG_CONFIGURE         = '000110' # 0x06
    CMD_JTAG_WR_SERDES_REGFILE = '100101' # 0x25
    CMD_JTAG_RD_SERDES_REGFILE = '100110' # 0x26

    CMD_JTAG_STATUS_PLL0       = '011100' # 0x1C
    CMD_JTAG_STATUS_PLL1       = '011101' # 0x1D
    CMD_JTAG_STATUS_PLL2       = '011110' # 0x1E
    CMD_JTAG_STATUS_PLL3       = '011111' # 0x1F

    _chain_idx = 0
    _taps_before = 0

    def __init__(self, engine):
        self._engine = engine
        self._chain_idx = args.idx
        self.idcode()

    def write_ir(self, instruction) -> None:
        byp_before = BitSequence('1'*6*self._taps_before, msb=True)
        byp_after = BitSequence('1'*6*self._chain_idx, msb=True)
        self._engine.write_ir(byp_before+instruction+byp_after)

    def write_dr(self, data) -> None:
        byp_before = BitSequence('0'*self._taps_before, msb=True)
        byp_after = BitSequence('0'*self._chain_idx, msb=True)
        self._engine.write_dr(byp_after+data+byp_before)

    def read_dr(self, length: int) -> BitSequence:
        word = self._engine.read_dr(length+self._taps_before)
        if self._chain_idx > 0:
            return word[self._taps_before:-self._chain_idx]
        else:
            return word[self._taps_before:]

    def get_chunk(self, data, start, length):
        return (data >> start) & ((1 << length) - 1)

    # Read the IDCODE right after JTAG reset
    def idcode(self) -> int:
        idcodes = self._engine.read_dr(128)
        self._engine.go_idle()
        chain_len = 0
        for i in range(0, 128, 32):
            chunk_data = self.get_chunk(int(idcodes), i, 32)
            if chunk_data != 0:
                chain_len += 1
        print(f'INFO:  Found {chain_len} device{"s" if chain_len > 1 else ""} in JTAG chain.')
        self._taps_before = chain_len - self._chain_idx - 1
        return chain_len

    # Read the IDCODE using CMD_JTAG_ID
    def idcode_seq(self) -> int:
        self.write_ir(BitSequence(self.CMD_JTAG_ID, msb=True))
        status = self.read_dr(32)
        self._engine.go_idle()
        return int(status)

    # Configure FPGA using CMD_JTAG_CONFIGURE
    def wr_cfg(self, cfg_data):
        a = []
        b = bytearray(cfg_data)

        for i in range(len(b)):
            a.append(int(b[i]))

        seq = BitSequence(bytes_=a[:-1], length=len(b)*8, msb=False, msby=True)

        self.write_ir(BitSequence(self.CMD_JTAG_CONFIGURE, msb=True))
        self.write_dr(seq)
        self._engine.go_idle()

    def wr_serdes_regfile(self, addr, data, mask, wren):
        self.write_ir(BitSequence(self.CMD_JTAG_WR_SERDES_REGFILE, msb=True))
        cmd  = BitSequence(value=addr, length=8,  msb=False, msby=True)
        cmd += BitSequence(value=data, length=16, msb=False, msby=True)
        cmd += BitSequence(value=mask, length=16, msb=False, msby=True)
        cmd += BitSequence(value=wren, length=1, msb=False, msby=True)
        self.write_dr(cmd)
        self._engine.go_idle()

    def rd_serdes_regfile(self):
        self.write_ir(BitSequence(self.CMD_JTAG_RD_SERDES_REGFILE, msb=True))
        word = self.read_dr(16)
        self._engine.go_idle()
        return word

    def rd_status_pll(self, device=1, pll=0, verbose=0):
        bs = BitSequence()
        if pll == 0:
            bs += BitSequence(self.CMD_JTAG_STATUS_PLL0, msb=True)
        elif pll == 1:
            bs += BitSequence(self.CMD_JTAG_STATUS_PLL1, msb=True)
        elif pll == 2:
            bs += BitSequence(self.CMD_JTAG_STATUS_PLL2, msb=True)
        elif pll == 3:
            bs += BitSequence(self.CMD_JTAG_STATUS_PLL3, msb=True)
        else:
            raise JtagError("Invalid PLL number: %s" % pll)
            return 0
        self._engine.write_ir(bs)
        status = self._engine.read_dr(17)
        self._engine.go_idle()

        pll_status_bin = '{:017b}'.format(int(status))
        if verbose:
            print('pll{}: 0x{:05X}'.format(pll, int(status)))
            print('pll%d: 0b%s' %(pll, pll_status_bin))

            #     0: fine tune overflow flag
            #     1: fine tune underflow flag
            # 11: 2: fine tune value
            # 13:12: state
            # 16:14: coarse tune value
            print('pll%d: fine tune overflow flag : %s ' %(pll, pll_status_bin[-1]))
            print('pll%d: fine tune underflow flag : %s ' %(pll, pll_status_bin[-2]))
            print('pll%d: fine tune value : %s ' %(pll, pll_status_bin[-12:-2]))

            #S_IDLE = ‘d0; S_LOCK_IN = ‘d1; S_LOCKED = ‘d2; S_FAST_LOCK = ‘d3;
            if pll_status_bin[-14:-12] == '00':
                print('pll%d: state : %s  -> S_IDLE' %(pll, pll_status_bin[-14:-12]))
            elif pll_status_bin[-14:-12] == '01':
                print('pll%d: state : %s  -> S_LOCK_IN' %(pll, pll_status_bin[-14:-12]))
            elif pll_status_bin[-14:-12] == '10':
                print('pll%d: state : %s  -> S_LOCKED' %(pll, pll_status_bin[-14:-12]))
            elif pll_status_bin[-14:-12] == '11':
                print('pll%d: state : %s  -> S_FAST_LOCK' %(pll, pll_status_bin[-14:-12]))
            print('pll%d: coarse tune value : %s ' %(pll, pll_status_bin[-17:-14]))
        return (pll_status_bin[-14:-12] == '10') # locked

class SerdesRegfile:
    def __init__(self, initial_fields):
        self.fields = initial_fields

class SerdesTool:
    regfile = SerdesRegfile({
        'RX_BUF_RESET_TIME':        {'addr': 0x00, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 3},
        'RX_PCS_RESET_TIME':        {'addr': 0x00, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 3},
        'RX_RESET_TIMER_PRESC':     {'addr': 0x00, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 0},
        'RX_RESET_DONE_GATE':       {'addr': 0x00, 'mode': 'R/W', 'hbit': 15, 'lbit': 15, 'val': 0},
        'RX_CDR_RESET_TIME':        {'addr': 0x01, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 3},
        'RX_EQA_RESET_TIME':        {'addr': 0x01, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 3},
        'RX_PMA_RESET_TIME':        {'addr': 0x01, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 3},
        'RX_WAIT_CDR_LOCK':         {'addr': 0x01, 'mode': 'R/W', 'hbit': 15, 'lbit': 15, 'val': 0},
        'RX_CALIB_EN':              {'addr': 0x02, 'mode': 'W/C', 'hbit':  0, 'lbit':  0, 'val': 0},
        'RX_CALIB_DONE':            {'addr': 0x02, 'mode': 'R',   'hbit':  1, 'lbit':  1, 'val': 1},
        'RX_CALIB_OVR':             {'addr': 0x02, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'RX_CALIB_VAL':             {'addr': 0x02, 'mode': 'R/W', 'hbit':  6, 'lbit':  3, 'val': 0},
        'RX_CALIB_CAL':             {'addr': 0x02, 'mode': 'R',   'hbit': 10, 'lbit':  7, 'val': 0},
        'RX_RTERM_VCMSEL':          {'addr': 0x02, 'mode': 'R/W', 'hbit': 13, 'lbit': 11, 'val': 4},
        'RX_RTERM_PD':              {'addr': 0x02, 'mode': 'R/W', 'hbit': 14, 'lbit': 14, 'val': 0},
        'RX_EQA_CKP_LF':            {'addr': 0x03, 'mode': 'R/W', 'hbit':  7, 'lbit':  0, 'val': 0xA3},
        'RX_EQA_CKP_HF':            {'addr': 0x03, 'mode': 'R/W', 'hbit': 15, 'lbit':  8, 'val': 0xA3},
        'RX_EQA_CKP_OFFSET':        {'addr': 0x04, 'mode': 'R/W', 'hbit':  7, 'lbit':  0, 'val': 1},
        'RX_EN_EQA':                {'addr': 0x04, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'RX_EQA_LOCK_CFG':          {'addr': 0x04, 'mode': 'R/W', 'hbit': 12, 'lbit':  9, 'val': 0},
        'RX_EQA_LOCKED':            {'addr': 0x04, 'mode': 'R',   'hbit': 13, 'lbit': 13, 'val': 0},
        'RX_TH_MON1':               {'addr': 0x05, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 8},
        'RX_EN_EQA_EXT_VALUE[0]':   {'addr': 0x05, 'mode': 'R/W', 'hbit':  5, 'lbit':  5, 'val': 0},
        'RX_TH_MON2':               {'addr': 0x05, 'mode': 'R/W', 'hbit': 10, 'lbit':  6, 'val': 8},
        'RX_EN_EQA_EXT_VALUE[1]':   {'addr': 0x05, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'RX_TAPW':                  {'addr': 0x06, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 8},
        'RX_EN_EQA_EXT_VALUE[2]':   {'addr': 0x06, 'mode': 'R/W', 'hbit':  5, 'lbit':  5, 'val': 0},
        'RX_AFE_OFFSET':            {'addr': 0x06, 'mode': 'R/W', 'hbit': 10, 'lbit':  6, 'val': 8},
        'RX_EN_EQA_EXT_VALUE[3]':   {'addr': 0x06, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'RX_EQA_TAPW':              {'addr': 0x07, 'mode': 'R',   'hbit':  4, 'lbit':  0, 'val': 0},
        'RX_TH_MON':                {'addr': 0x07, 'mode': 'R',   'hbit':  9, 'lbit':  5, 'val': 0},
        'RX_OFFSET':                {'addr': 0x07, 'mode': 'R',   'hbit': 13, 'lbit': 10, 'val': 0},
        'RX_EQA_CONFIG':            {'addr': 0x08, 'mode': 'R/W', 'hbit': 15, 'lbit':  0, 'val': 0x01C0},
        'RX_AFE_PEAK':              {'addr': 0x09, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 15},
        'RX_AFE_GAIN':              {'addr': 0x09, 'mode': 'R/W', 'hbit':  8, 'lbit':  5, 'val': 8},
        'RX_AFE_VCMSEL':            {'addr': 0x09, 'mode': 'R/W', 'hbit': 11, 'lbit':  9, 'val': 4},
        'RX_CDR_CKP':               {'addr': 0x0A, 'mode': 'R/W', 'hbit':  7, 'lbit':  0, 'val': 0xF8},
        'RX_CDR_CKI':               {'addr': 0x0A, 'mode': 'R/W', 'hbit': 15, 'lbit':  8, 'val': 0},
        'RX_CDR_TRANS_TH':          {'addr': 0x0B, 'mode': 'R/W', 'hbit':  8, 'lbit':  0, 'val': 128},
        'RX_CDR_LOCK_CFG':          {'addr': 0x0B, 'mode': 'R/W', 'hbit': 14, 'lbit':  9, 'val': 0x0B},
        'RX_CDR_LOCKED':            {'addr': 0x0B, 'mode': 'R',   'hbit': 15, 'lbit': 15, 'val': 0},
        'RX_CDR_FREQ_ACC_VAL':      {'addr': 0x0C, 'mode': 'R',   'hbit': 14, 'lbit':  0, 'val': 0},
        'RX_CDR_PHASE_ACC_VAL':     {'addr': 0x0D, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_CDR_FREQ_ACC':          {'addr': 0x0E, 'mode': 'R/W', 'hbit': 14, 'lbit':  0, 'val': 0},
        'RX_CDR_PHASE_ACC':         {'addr': 0x0F, 'mode': 'R/W', 'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_CDR_SET_ACC_CONFIG':    {'addr': 0x10, 'mode': 'R/W', 'hbit':  1, 'lbit':  0, 'val': 0},
        'RX_CDR_FORCE_LOCK':        {'addr': 0x10, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'RX_ALIGN_MCOMMA_VALUE':    {'addr': 0x11, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x283},
        'RX_MCOMMA_ALIGN_OVR':      {'addr': 0x11, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 0},
        'RX_MCOMMA_ALIGN':          {'addr': 0x11, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'RX_ALIGN_PCOMMA_VALUE':    {'addr': 0x12, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x17C},
        'RX_PCOMMA_ALIGN_OVR':      {'addr': 0x12, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 0},
        'RX_PCOMMA_ALIGN':          {'addr': 0x12, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'RX_ALIGN_COMMA_WORD':      {'addr': 0x12, 'mode': 'R/W', 'hbit': 13, 'lbit': 12, 'val': 0},
        'RX_ALIGN_COMMA_ENABLE':    {'addr': 0x13, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x3FF},
        'RX_SLIDE_MODE':            {'addr': 0x13, 'mode': 'R/W', 'hbit': 11, 'lbit': 10, 'val': 0},
        'RX_COMMA_DETECT_EN_OVR':   {'addr': 0x13, 'mode': 'R/W', 'hbit': 12, 'lbit': 12, 'val': 0},
        'RX_COMMA_DETECT_EN':       {'addr': 0x13, 'mode': 'R/W', 'hbit': 13, 'lbit': 13, 'val': 0},
        'RX_SLIDE[0]':              {'addr': 0x13, 'mode': 'R/W', 'hbit': 14, 'lbit': 14, 'val': 0},
        'RX_SLIDE[1]':              {'addr': 0x13, 'mode': 'W/C', 'hbit': 15, 'lbit': 15, 'val': 0},
        'RX_EYE_MEAS_EN':           {'addr': 0x14, 'mode': 'W/C', 'hbit':  0, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_CFG':          {'addr': 0x14, 'mode': 'R/W', 'hbit': 15, 'lbit':  1, 'val': 0},
        'RX_MON_PH_OFFSET':         {'addr': 0x15, 'mode': 'R/W', 'hbit':  5, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_CORRECT_11S':  {'addr': 0x16, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_WRONG_11S':    {'addr': 0x17, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_CORRECT_00S':  {'addr': 0x18, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_WRONG_00S':    {'addr': 0x19, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_CORRECT_001S': {'addr': 0x1A, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_WRONG_001S':   {'addr': 0x1B, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_CORRECT_110S': {'addr': 0x1C, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EYE_MEAS_WRONG_110S':   {'addr': 0x1D, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_EI_BIAS':               {'addr': 0x1E, 'mode': 'R/W', 'hbit':  3, 'lbit':  0, 'val': 4},
        'RX_EI_BW_SEL':             {'addr': 0x1E, 'mode': 'R/W', 'hbit':  7, 'lbit':  4, 'val': 4},
        'RX_EN_EI_DETECTOR_OVR':    {'addr': 0x1E, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'RX_EN_EI_DETECTOR':        {'addr': 0x1E, 'mode': 'R/W', 'hbit':  9, 'lbit':  9, 'val': 0},
        'RX_EI_EN':                 {'addr': 0x1E, 'mode': 'R',   'hbit': 10, 'lbit': 10, 'val': 0},
        'RX_PRBS_ERR_CNT':          {'addr': 0x1F, 'mode': 'R',   'hbit': 14, 'lbit':  0, 'val': 0},
        'RX_PRBS_LOCKED':           {'addr': 0x1F, 'mode': 'R',   'hbit': 15, 'lbit': 15, 'val': 0},
        'RX_DATA_SEL':              {'addr': 0x20, 'mode': 'R/W', 'hbit':  0, 'lbit':  0, 'val': 0},
        'RX_DATA[15:0]':            {'addr': 0x20, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_DATA[31:16]':           {'addr': 0x21, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_DATA[47:32]':           {'addr': 0x22, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_DATA[63:48]':           {'addr': 0x23, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_DATA[79:64]':           {'addr': 0x24, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'RX_BUF_BYPASS':            {'addr': 0x25, 'mode': 'R/W', 'hbit':  0, 'lbit':  0, 'val': 0},
        'RX_CLKCOR_USE':            {'addr': 0x25, 'mode': 'R/W', 'hbit':  1, 'lbit':  1, 'val': 0},
        'RX_CLKCOR_MIN_LAT':        {'addr': 0x25, 'mode': 'R/W', 'hbit':  7, 'lbit':  2, 'val': 32},
        'RX_CLKCOR_MAX_LAT':        {'addr': 0x25, 'mode': 'R/W', 'hbit': 13, 'lbit':  8, 'val': 39},
        'RX_CLKCOR_SEQ_1_0':        {'addr': 0x26, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x1F7},
        'RX_CLKCOR_SEQ_1_1':        {'addr': 0x27, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x1F7},
        'RX_CLKCOR_SEQ_1_2':        {'addr': 0x28, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x1F7},
        'RX_CLKCOR_SEQ_1_3':        {'addr': 0x29, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0x1F7},
        'RX_PMA_LOOPBACK':          {'addr': 0x2A, 'mode': 'R/W', 'hbit':  0, 'lbit':  0, 'val': 0},
        'RX_PCS_LOOPBACK':          {'addr': 0x2A, 'mode': 'R/W', 'hbit':  1, 'lbit':  1, 'val': 0},
        'RX_DATAPATH_SEL':          {'addr': 0x2A, 'mode': 'R/W', 'hbit':  3, 'lbit':  2, 'val': 3},
        'RX_PRBS_OVR':              {'addr': 0x2A, 'mode': 'R/W', 'hbit':  4, 'lbit':  4, 'val': 0},
        'RX_PRBS_SEL':              {'addr': 0x2A, 'mode': 'R/W', 'hbit':  7, 'lbit':  5, 'val': 0},
        'RX_LOOPBACK_OVR':          {'addr': 0x2A, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'RX_PRBS_CNT_RESET':        {'addr': 0x2A, 'mode': 'W/C', 'hbit':  9, 'lbit':  9, 'val': 0},
        'RX_POWER_DOWN_OVR':        {'addr': 0x2A, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 0},
        'RX_POWER_DOWN_N':          {'addr': 0x2A, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'RX_PRESENT':               {'addr': 0x2A, 'mode': 'R',   'hbit': 12, 'lbit': 12, 'val': 0},
        'RX_DETECT_DONE':           {'addr': 0x2A, 'mode': 'R',   'hbit': 13, 'lbit': 13, 'val': 0},
        'RX_BUF_ERR':               {'addr': 0x2A, 'mode': 'R',   'hbit': 14, 'lbit': 14, 'val': 0},
        'RX_RESET_OVR':             {'addr': 0x2B, 'mode': 'R/W', 'hbit':  0, 'lbit':  0, 'val': 0},
        'RX_RESET':                 {'addr': 0x2B, 'mode': 'W/C', 'hbit':  1, 'lbit':  1, 'val': 0},
        'RX_PMA_RESET_OVR':         {'addr': 0x2B, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'RX_PMA_RESET':             {'addr': 0x2B, 'mode': 'W/C', 'hbit':  3, 'lbit':  3, 'val': 0},
        'RX_EQA_RESET_OVR':         {'addr': 0x2B, 'mode': 'R/W', 'hbit':  4, 'lbit':  4, 'val': 0},
        'RX_EQA_RESET':             {'addr': 0x2B, 'mode': 'W/C', 'hbit':  5, 'lbit':  5, 'val': 0},
        'RX_CDR_RESET_OVR':         {'addr': 0x2B, 'mode': 'R/W', 'hbit':  6, 'lbit':  6, 'val': 0},
        'RX_CDR_RESET':             {'addr': 0x2B, 'mode': 'W/C', 'hbit':  7, 'lbit':  7, 'val': 0},
        'RX_PCS_RESET_OVR':         {'addr': 0x2B, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'RX_PCS_RESET':             {'addr': 0x2B, 'mode': 'W/C', 'hbit':  9, 'lbit':  9, 'val': 0},
        'RX_BUF_RESET_OVR':         {'addr': 0x2B, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 0},
        'RX_BUF_RESET':             {'addr': 0x2B, 'mode': 'W/C', 'hbit': 11, 'lbit': 11, 'val': 0},
        'RX_POLARITY_OVR':          {'addr': 0x2B, 'mode': 'R/W', 'hbit': 12, 'lbit': 12, 'val': 0},
        'RX_POLARITY':              {'addr': 0x2B, 'mode': 'R/W', 'hbit': 13, 'lbit': 13, 'val': 0},
        'RX_8B10B_EN_OVR':          {'addr': 0x2B, 'mode': 'R/W', 'hbit': 14, 'lbit': 14, 'val': 0},
        'RX_8B10B_EN':              {'addr': 0x2B, 'mode': 'R/W', 'hbit': 15, 'lbit': 15, 'val': 0},
        'RX_8B10B_BYPASS':          {'addr': 0x2C, 'mode': 'R/W', 'hbit':  7, 'lbit':  0, 'val': 0},
        'RX_BYTE_IS_ALIGNED':       {'addr': 0x2C, 'mode': 'R',   'hbit':  8, 'lbit':  8, 'val': 0},
        'RX_BYTE_REALIGN':          {'addr': 0x2C, 'mode': 'R/C', 'hbit':  9, 'lbit':  9, 'val': 0},
        'RX_RESET_DONE':            {'addr': 0x2C, 'mode': 'R',   'hbit': 10, 'lbit': 10, 'val': 0},
        #'RX_DBG_EN':               {'addr': 0x2D, 'mode': 'W/C', 'hbit':  0, 'lbit':  0, 'val': 0},
        #'RX_DBG_SEL':              {'addr': 0x2D, 'mode': 'R/W', 'hbit':  4, 'lbit':  1, 'val': 0},
        #'RX_DBG_MODE':             {'addr': 0x2D, 'mode': 'R/W', 'hbit':  5, 'lbit':  5, 'val': 0},
        #'RX_DBG_SRAM_DELAY':       {'addr': 0x2D, 'mode': 'R/W', 'hbit': 11, 'lbit':  6, 'val': 5},
        #'RX_DBG_ADDR':             {'addr': 0x2E, 'mode': 'R/W', 'hbit':  9, 'lbit':  0, 'val': 0},
        #'RX_DBG_RE':               {'addr': 0x2E, 'mode': 'W/C', 'hbit': 10, 'lbit': 10, 'val': 0},
        #'RX_DBG_WE':               {'addr': 0x2E, 'mode': 'W/C', 'hbit': 11, 'lbit': 11, 'val': 0},
        #'RX_DBG_DATA[3:0]':        {'addr': 0x2E, 'mode': 'R/W', 'hbit': 15, 'lbit': 12, 'val': 0},
        #'RX_DBG_DATA[19:4]':       {'addr': 0x2F, 'mode': 'R/W', 'hbit': 15, 'lbit':  0, 'val': 0},
        'TX_SEL_PRE':               {'addr': 0x30, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_SEL_POST':              {'addr': 0x30, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 0},
        'TX_AMP':                   {'addr': 0x30, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 15},
        'TX_BRANCH_EN_PRE':         {'addr': 0x31, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_BRANCH_EN_MAIN':        {'addr': 0x31, 'mode': 'R/W', 'hbit': 10, 'lbit':  5, 'val': 0x3F},
        'TX_BRANCH_EN_POST':        {'addr': 0x31, 'mode': 'R/W', 'hbit': 15, 'lbit': 11, 'val': 0},
        'TX_TAIL_CASCODE':          {'addr': 0x32, 'mode': 'R/W', 'hbit':  2, 'lbit':  0, 'val': 4},
        'TX_DC_ENABLE':             {'addr': 0x32, 'mode': 'R/W', 'hbit':  9, 'lbit':  3, 'val': 63},
        'TX_DC_OFFSET':             {'addr': 0x32, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 8},
        'TX_CM_RAISE':              {'addr': 0x33, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_CM_THRESHOLD_0':        {'addr': 0x33, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 14},
        'TX_CM_THRESHOLD_1':        {'addr': 0x33, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 16},
        'TX_SEL_PRE_EI':            {'addr': 0x34, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_SEL_POST_EI':           {'addr': 0x34, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 0},
        'TX_AMP_EI':                {'addr': 0x34, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 15},
        'TX_BRANCH_EN_PRE_EI':      {'addr': 0x35, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_BRANCH_EN_MAIN_EI':     {'addr': 0x35, 'mode': 'R/W', 'hbit': 10, 'lbit':  5, 'val': 0x3F},
        'TX_BRANCH_EN_POST_EI':     {'addr': 0x35, 'mode': 'R/W', 'hbit': 15, 'lbit': 11, 'val': 0},
        'TX_TAIL_CASCODE_EI':       {'addr': 0x36, 'mode': 'R/W', 'hbit':  2, 'lbit':  0, 'val': 4},
        'TX_DC_ENABLE_EI':          {'addr': 0x36, 'mode': 'R/W', 'hbit':  9, 'lbit':  3, 'val': 63},
        'TX_DC_OFFSET_EI':          {'addr': 0x36, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 0},
        'TX_CM_RAISE_EI':           {'addr': 0x37, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_CM_THRESHOLD_0_EI':     {'addr': 0x37, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 14},
        'TX_CM_THRESHOLD_1_EI':     {'addr': 0x37, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 16},
        'TX_SEL_PRE_RXDET':         {'addr': 0x38, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_SEL_POST_RXDET':        {'addr': 0x38, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 0},
        'TX_AMP_RXDET':             {'addr': 0x38, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 15},
        'TX_BRANCH_EN_PRE_RXDET':   {'addr': 0x39, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_BRANCH_EN_MAIN_RXDET':  {'addr': 0x39, 'mode': 'R/W', 'hbit': 10, 'lbit':  5, 'val': 0x3F},
        'TX_BRANCH_EN_POST_RXDET':  {'addr': 0x39, 'mode': 'R/W', 'hbit': 15, 'lbit': 11, 'val': 0},
        'TX_TAIL_CASCODE_RXDET':    {'addr': 0x3A, 'mode': 'R/W', 'hbit':  2, 'lbit':  0, 'val': 4},
        'TX_DC_ENABLE_RXDET':       {'addr': 0x3A, 'mode': 'R/W', 'hbit':  9, 'lbit':  3, 'val': 63},
        'TX_DC_OFFSET_RXDET':       {'addr': 0x3A, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 0},
        'TX_CM_RAISE_RXDET':        {'addr': 0x3B, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_CM_THRESHOLD_0_RXDET':  {'addr': 0x3B, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 14},
        'TX_CM_THRESHOLD_1_RXDET':  {'addr': 0x3B, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 16},
        'TX_CALIB_EN':              {'addr': 0x3C, 'mode': 'W/C', 'hbit':  0, 'lbit':  0, 'val': 0},
        'TX_CALIB_DONE':            {'addr': 0x3C, 'mode': 'R',   'hbit':  1, 'lbit':  1, 'val': 1},
        'TX_CALIB_OVR':             {'addr': 0x3C, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'TX_CALIB_VAL':             {'addr': 0x3C, 'mode': 'R/W', 'hbit':  6, 'lbit':  3, 'val': 0},
        'TX_CALIB_CAL':             {'addr': 0x3C, 'mode': 'R',   'hbit': 10, 'lbit':  7, 'val': 0},
        'TX_CM_REG_KI':             {'addr': 0x3D, 'mode': 'R/W', 'hbit':  7, 'lbit':  0, 'val': 0x80},
        'TX_CM_SAR_EN':             {'addr': 0x3D, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'TX_CM_REG_EN':             {'addr': 0x3D, 'mode': 'R/W', 'hbit':  9, 'lbit':  9, 'val': 1},
        'TX_CM_SAR_RESULT_0':       {'addr': 0x3E, 'mode': 'R',   'hbit':  4, 'lbit':  0, 'val': 0},
        'TX_CM_SAR_RESULT_1':       {'addr': 0x3E, 'mode': 'R',   'hbit':  9, 'lbit':  5, 'val': 0},
        'TX_PMA_RESET_TIME':        {'addr': 0x3F, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 3},
        'TX_PCS_RESET_TIME':        {'addr': 0x3F, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 3},
        'TX_PCS_RESET_OVR':         {'addr': 0x3F, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 0},
        'TX_PCS_RESET':             {'addr': 0x3F, 'mode': 'W/C', 'hbit': 11, 'lbit': 11, 'val': 0},
        'TX_PMA_RESET_OVR':         {'addr': 0x3F, 'mode': 'R/W', 'hbit': 12, 'lbit': 12, 'val': 0},
        'TX_PMA_RESET':             {'addr': 0x3F, 'mode': 'W/C', 'hbit': 13, 'lbit': 13, 'val': 0},
        'TX_RESET_OVR':             {'addr': 0x3F, 'mode': 'R/W', 'hbit': 14, 'lbit': 14, 'val': 0},
        'TX_RESET':                 {'addr': 0x3F, 'mode': 'W/C', 'hbit': 15, 'lbit': 15, 'val': 0},
        'TX_PMA_LOOPBACK':          {'addr': 0x40, 'mode': 'R/W', 'hbit':  1, 'lbit':  0, 'val': 0},
        'TX_PCS_LOOPBACK':          {'addr': 0x40, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'TX_DATAPATH_SEL':          {'addr': 0x40, 'mode': 'R/W', 'hbit':  4, 'lbit':  3, 'val': 3},
        'TX_PRBS_OVR':              {'addr': 0x40, 'mode': 'R/W', 'hbit':  5, 'lbit':  5, 'val': 0},
        'TX_PRBS_SEL':              {'addr': 0x40, 'mode': 'R/W', 'hbit':  8, 'lbit':  6, 'val': 0},
        'TX_PRBS_FORCE_ERR':        {'addr': 0x40, 'mode': 'W/C', 'hbit':  9, 'lbit':  9, 'val': 0},
        'TX_LOOPBACK_OVR':          {'addr': 0x40, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 0},
        'TX_POWER_DOWN_OVR':        {'addr': 0x40, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'TX_POWER_DOWN_N':          {'addr': 0x40, 'mode': 'R/W', 'hbit': 12, 'lbit': 12, 'val': 0},
        'TX_ELEC_IDLE_OVR':         {'addr': 0x41, 'mode': 'R/W', 'hbit':  0, 'lbit':  0, 'val': 0},
        'TX_ELEC_IDLE':             {'addr': 0x41, 'mode': 'R/W', 'hbit':  1, 'lbit':  1, 'val': 0},
        'TX_DETECT_RX_OVR':         {'addr': 0x41, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'TX_DETECT_RX':             {'addr': 0x41, 'mode': 'R/W', 'hbit':  3, 'lbit':  3, 'val': 0},
        'TX_POLARITY_OVR':          {'addr': 0x41, 'mode': 'R/W', 'hbit':  4, 'lbit':  4, 'val': 0},
        'TX_POLARITY':              {'addr': 0x41, 'mode': 'R/W', 'hbit':  5, 'lbit':  5, 'val': 0},
        'TX_8B10B_EN_OVR':          {'addr': 0x41, 'mode': 'R/W', 'hbit':  6, 'lbit':  6, 'val': 0},
        'TX_8B10B_EN':              {'addr': 0x41, 'mode': 'R/W', 'hbit':  7, 'lbit':  7, 'val': 0},
        'TX_DATA_OVR':              {'addr': 0x41, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'TX_DATA_CNT':              {'addr': 0x41, 'mode': 'R/W', 'hbit': 11, 'lbit':  9, 'val': 0},
        'TX_DATA_VALID':            {'addr': 0x41, 'mode': 'W/C', 'hbit': 12, 'lbit': 12, 'val': 0},
        'TX_BUF_ERR':               {'addr': 0x41, 'mode': 'R',   'hbit': 13, 'lbit': 13, 'val': 0},
        'TX_RESET_DONE':            {'addr': 0x41, 'mode': 'R',   'hbit': 14, 'lbit': 14, 'val': 0},
        'TX_DATA':                  {'addr': 0x42, 'mode': 'R/W', 'hbit': 15, 'lbit':  0, 'val': 0},
        # 0x43..0x4F unused
        'PLL_EN_ADPLL_CTRL':        {'addr': 0x50, 'mode': 'R/W', 'hbit':  0, 'lbit':  0, 'val': 0},
        'PLL_CONFIG_SEL':           {'addr': 0x50, 'mode': 'R/W', 'hbit':  1, 'lbit':  1, 'val': 1},
        'PLL_SET_OP_LOCK':          {'addr': 0x50, 'mode': 'R/W', 'hbit':  2, 'lbit':  2, 'val': 0},
        'PLL_ENFORCE_LOCK':         {'addr': 0x50, 'mode': 'R/W', 'hbit':  3, 'lbit':  3, 'val': 0},
        'PLL_DISABLE_LOCK':         {'addr': 0x50, 'mode': 'R/W', 'hbit':  4, 'lbit':  4, 'val': 0},
        'PLL_LOCK_WINDOW':          {'addr': 0x50, 'mode': 'R/W', 'hbit':  5, 'lbit':  5, 'val': 1},
        'PLL_FAST_LOCK':            {'addr': 0x50, 'mode': 'R/W', 'hbit':  6, 'lbit':  6, 'val': 1},
        'PLL_SYNC_BYPASS':          {'addr': 0x50, 'mode': 'R/W', 'hbit':  7, 'lbit':  7, 'val': 0},
        'PLL_PFD_SELECT':           {'addr': 0x50, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'PLL_REF_BYPASS':           {'addr': 0x50, 'mode': 'R/W', 'hbit':  9, 'lbit':  9, 'val': 0},
        'PLL_REF_SEL':              {'addr': 0x50, 'mode': 'R/W', 'hbit': 10, 'lbit': 10, 'val': 1},
        'PLL_REF_RTERM':            {'addr': 0x50, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 1},
        'PLL_FCNTRL':               {'addr': 0x51, 'mode': 'R/W', 'hbit':  5, 'lbit':  0, 'val': 58},
        'PLL_MAIN_DIVSEL':          {'addr': 0x51, 'mode': 'R/W', 'hbit': 11, 'lbit':  6, 'val': 27},
        'PLL_OUT_DIVSEL':           {'addr': 0x51, 'mode': 'R/W', 'hbit': 13, 'lbit': 12, 'val': 0},
        'PLL_CI':                   {'addr': 0x52, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 3},
        'PLL_CP':                   {'addr': 0x52, 'mode': 'R/W', 'hbit': 14, 'lbit':  5, 'val': 80},
        'PLL_AO':                   {'addr': 0x53, 'mode': 'R/W', 'hbit':  3, 'lbit':  0, 'val': 0},
        'PLL_SCAP':                 {'addr': 0x53, 'mode': 'R/W', 'hbit':  6, 'lbit':  4, 'val': 0},
        'PLL_FILTER_SHIFT':         {'addr': 0x53, 'mode': 'R/W', 'hbit':  8, 'lbit':  7, 'val': 2},
        'PLL_SAR_LIMIT':            {'addr': 0x53, 'mode': 'R/W', 'hbit': 11, 'lbit':  9, 'val': 2},
        'PLL_FT':                   {'addr': 0x54, 'mode': 'R/W', 'hbit': 10, 'lbit':  0, 'val': 512},
        'PLL_OPEN_LOOP':            {'addr': 0x54, 'mode': 'R/W', 'hbit': 11, 'lbit': 11, 'val': 0},
        'PLL_SCAP_AUTO_CAL':        {'addr': 0x54, 'mode': 'R/W', 'hbit': 12, 'lbit': 12, 'val': 1},
        'PLL_LOCKED':               {'addr': 0x55, 'mode': 'R',   'hbit':  0, 'lbit':  0, 'val': 0},
        'PLL_CAP_FT_OF':            {'addr': 0x55, 'mode': 'R',   'hbit':  1, 'lbit':  1, 'val': 0},
        'PLL_CAP_FT_UF':            {'addr': 0x55, 'mode': 'R',   'hbit':  2, 'lbit':  2, 'val': 0},
        'PLL_CAP_FT':               {'addr': 0x55, 'mode': 'R',   'hbit': 12, 'lbit':  3, 'val': 0},
        'PLL_CAP_STATE':            {'addr': 0x55, 'mode': 'R',   'hbit': 14, 'lbit': 13, 'val': 0},
        'PLL_SYNC_VALUE':           {'addr': 0x56, 'mode': 'R',   'hbit':  7, 'lbit':  0, 'val': 0},
        'PLL_BISC_MODE':            {'addr': 0x57, 'mode': 'R/W', 'hbit':  2, 'lbit':  0, 'val': 4},
        'PLL_BISC_TIMER_MAX':       {'addr': 0x57, 'mode': 'R/W', 'hbit':  6, 'lbit':  3, 'val': 15},
        'PLL_BISC_OPT_DET_IND':     {'addr': 0x57, 'mode': 'R/W', 'hbit':  7, 'lbit':  7, 'val': 0},
        'PLL_BISC_PFD_SEL':         {'addr': 0x57, 'mode': 'R/W', 'hbit':  8, 'lbit':  8, 'val': 0},
        'PLL_BISC_DLY_DIR':         {'addr': 0x57, 'mode': 'R/W', 'hbit':  9, 'lbit':  9, 'val': 0},
        'PLL_BISC_COR_DLY':         {'addr': 0x57, 'mode': 'R/W', 'hbit': 12, 'lbit': 10, 'val': 1},
        'PLL_BISC_CAL_SIGN':        {'addr': 0x57, 'mode': 'R/W', 'hbit': 13, 'lbit': 13, 'val': 0},
        'PLL_BISC_CAL_AUTO':        {'addr': 0x57, 'mode': 'R/W', 'hbit': 14, 'lbit': 14, 'val': 1},
        'PLL_BISC_CP_MIN':          {'addr': 0x58, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 4},
        'PLL_BISC_CP_MAX':          {'addr': 0x58, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 18},
        'PLL_BISC_CP_START':        {'addr': 0x58, 'mode': 'R/W', 'hbit': 14, 'lbit': 10, 'val': 12},
        'PLL_BISC_DLY_PFD_MON_REF': {'addr': 0x59, 'mode': 'R/W', 'hbit':  4, 'lbit':  0, 'val': 0},
        'PLL_BISC_DLY_PFD_MON_DIV': {'addr': 0x59, 'mode': 'R/W', 'hbit':  9, 'lbit':  5, 'val': 2},
        'PLL_BISC_TIMER_DONE':      {'addr': 0x5A, 'mode': 'R',   'hbit':  0, 'lbit':  0, 'val': 0},
        'PLL_BISC_CP':              {'addr': 0x5A, 'mode': 'R',   'hbit':  7, 'lbit':  1, 'val': 0}, # BISC_RESULT[15:1]
        'PLL_BISC_CO':              {'addr': 0x5B, 'mode': 'R',   'hbit': 15, 'lbit':  0, 'val': 0},
        'SERDES_ENABLE':            {'addr': 0x5C, 'mode': 'R/C', 'hbit':  0, 'lbit':  0, 'val': 1},
        'SERDES_AUTO_INIT':         {'addr': 0x5C, 'mode': 'R/C', 'hbit':  1, 'lbit':  1, 'val': 0},
        'SERDES_TESTMODE':          {'addr': 0x5C, 'mode': 'R/C', 'hbit':  2, 'lbit':  2, 'val': 0},
    })

    ports = {
        # name: width
        'TX_DATA_I': 64,
        'TX_RESET_I': 1,
        'TX_PCS_RESET_I': 1,
        'TX_PMA_RESET_I': 1,
        'PLL_RESET_I': 1,
        'TX_POWER_DOWN_N_I': 1,
        'TX_POLARITY_I': 1,
        'TX_PRBS_SEL_I': 3,
        'TX_PRBS_FORCE_ERR_I': 1,
        'TX_8B10B_EN_I': 1,
        'TX_8B10B_BYPASS_I': 8,
        'TX_CHAR_IS_K_I': 8,
        'TX_CHAR_DISPMODE_I': 8,
        'TX_CHAR_DISPVAL_I': 8,
        'TX_ELEC_IDLE_I': 1,
        'TX_DETECT_RX_I': 1,
        'LOOPBACK_I': 3,
        'TX_CLK_I': 1,
        'RX_CLK_I': 1,
        'RX_RESET_I': 1,
        'RX_PMA_RESET_I': 1,
        'RX_EQA_RESET_I': 1,
        'RX_CDR_RESET_I': 1,
        'RX_PCS_RESET_I': 1,
        'RX_BUF_RESET_I': 1,
        'RX_POWER_DOWN_N_I': 1,
        'RX_POLARITY_I': 1,
        'RX_PRBS_SEL_I': 3,
        'RX_PRBS_CNT_RESET_I': 1,
        'RX_8B10B_EN_I': 1,
        'RX_8B10B_BYPASS_I': 8,
        'RX_EN_EI_DETECTOR_I': 1,
        'RX_COMMA_DETECT_EN_I': 1,
        'RX_SLIDE_I': 1,
        'RX_MCOMMA_ALIGN_I': 1,
        'RX_PCOMMA_ALIGN_I': 1,
        'REGFILE_CLK_I': 1,
        'REGFILE_WE_I': 1,
        'REGFILE_EN_I': 1,
        'REGFILE_ADDR_I': 8,
        'REGFILE_DI_I': 16,
        'REGFILE_MASK_I': 16,
        'RX_DATA_O': 64,
        'RX_NOT_IN_TABLE_O': 8,
        'RX_CHAR_IS_COMMA_O': 8,
        'RX_CHAR_IS_K_O': 8,
        'RX_DISP_ERR_O': 8,
        'TX_DETECT_RX_DONE_O': 1,
        'TX_DETECT_RX_PRESENT_O': 1,
        'TX_BUF_ERR_O': 1,
        'TX_RESET_DONE_O': 1,
        'RX_PRBS_ERR_O': 1,
        'RX_BUF_ERR_O': 1,
        'RX_BYTE_IS_ALIGNED_O': 1,
        'RX_BYTE_REALIGN_O': 1,
        'RX_RESET_DONE_O': 1,
        'RX_EI_EN_O': 1,
        'RX_CLK_O': 1,
        'PLL_CLK_O': 1,
        'REGFILE_DO_O': 16,
        'REGFILE_RDY_O': 1
    }

    olclkg = { # open loop clock generator
        # fcntrl : N
         0:    1,  1:     2,  2:    3,  3:  3.5,
         4:  3.5,  5:  3.75,  6:    4,  7:    4,
         8:  4.5,  9:  5.25, 10:    5, 11:  5.5,
        12:  5.5, 13:  5.75, 14:    6, 15:    6,
        16:    6, 17:     7, 18:    6, 19:    7,
        20:    7, 21:   7.5, 22:    8, 23:    8,
        24:    9, 25:  10.5, 26:   10, 27:   11,
        28:   11, 29:  11.5, 30:   12, 31:   12,
        32:    9, 33:  10.5, 34:    9, 35: 10.5,
        36: 10.5, 37: 11.25, 38:   12, 39:   12,
        40: 13.5, 41: 15.75, 42:   15, 43: 16.5,
        44: 16.5, 45: 17.25, 46:   18, 47:   18,
        48:   12, 49:    14, 50:   12, 51:   14,
        52:   14, 53: 15.75, 54: 16.5, 55: 16.5,
        56:   18, 57:    21, 58:   20, 59:   22,
        60:   22, 61:    23, 62:   24, 63:   24,
    }

    # keywords for conditional coloring
    pos_cond = ["DONE", "PRESENT", "LOCKED", "IS_ALIGNED", "EN_ADPLL_CTRL", "CONFIG_SEL", "SERDES_ENABLE"]
    neg_cond = ["ERR", "DOWN", "TESTMODE"]
    ovr_cond = ["OVR"]

    # PFDAC settings
    ADPLL_PFDAC_TIMER    = 12
    ADPLL_PFDAC_COR_DLY  = 1
    ADPLL_PFDAC_CP_MIN   = 6
    ADPLL_PFDAC_CP_MAX   = 30
    ADPLL_PFDAC_CP_START = 6
    ADPLL_PFDAC_CAL_SIGN = 1
    ADPLL_PFDAC_AUTO_CAL = 1

    # Thread-safe lock for updating values
    param_lock = threading.Lock()

    def __init__(self, args, jtag, hwinit):
        if hwinit:
            self._jtag = jtag
            self._board = args.board
            if self._jtag is not None:
                self.configure()

    def configure(self):
        if self._board == Boards_e[0]: # auto
            self._jtag.configure(FindAndFormatFtdiAddr(0))
        elif self._board == Boards_e[1]: # pgm
            self._jtag.configure('ftdi://ftdi:232h/1')
        elif self._board == Boards_e[2]: # evb
            self._jtag.configure('ftdi://ftdi:2232h/1')

        self._jtag.reset()
        self._tool = JtagTool(self._jtag)

    def rd_id(self):
        self._tool.idcode()

    def wr_cfg(self, bitfile):
        self._tool.wr_cfg(bitfile)

    def gen_module_vlog(self, filename):
        print(f'Generate verilog template: {filename}')
        with open(filename, 'w') as file:
            file.write('// CC_SERDES instance generator\n')
            file.write(f'// generated: {datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")}\n')
            file.write('\n')
            file.write('CC_SERDES #(\n')
            for idx, (param, data) in enumerate(self.regfile.fields.items()):
                end = '' if idx == len(self.regfile.fields.items())-1 else ','
                if data['mode'] != 'R':
                    width = data['hbit']-data['lbit']+1
                    file.write(f'    .{param}({width}\'h{data['val']:X}){end}\n')
            file.write(') i_cc_serdes (\n')
            for idx, (port, width) in enumerate(self.ports.items()):
                end = '' if idx == len(self.ports.items())-1 else ','
                if port.endswith('_I'):
                    file.write(f'    .{port}({width}\'h{0:X}){end}\n')
                else: # port.endswith('_O'):
                    file.write(f'    .{port}(){end}\n')
            file.write(');\n')

    def gen_module_vhdl(self, filename):
        print(f'Generate VHDL template: {filename}')
        with open(filename, 'w') as file:
            file.write('-- CC_SERDES instance generator\n')
            file.write(f'-- generated: {datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")}\n')
            # component
            file.write('\n')
            file.write('component CC_SERDES is\n')
            file.write('generic (\n')
            for idx, (param, data) in enumerate(self.regfile.fields.items()):
                end = '' if (idx == len(self.regfile.fields.items())-1) else ';'
                if data['mode'] != 'R':
                    hbit = data['hbit']-data['lbit']
                    file.write(f'    {param} : bit_vector({hbit} downto 0){end}\n')
            file.write(');\n')
            file.write('port (\n')
            for idx, (port, width) in enumerate(self.ports.items()):
                end = '' if idx == len(self.ports.items())-1 else ';'
                if port.endswith('_I'):
                    if width > 1:
                        file.write(f'    {port} : in std_logic_vector({width-1} downto 0){end}\n')
                    else:
                        file.write(f'    {port} : in std_logic{end}\n')
                else: # port.endswith('_O'):
                    if width > 1:
                        file.write(f'    {port} : out std_logic_vector({width-1} downto 0){end}\n')
                    else:
                        file.write(f'    {port} : out std_logic{end}\n')
            file.write(');\n')
            file.write('end component;\n')
            # instance
            file.write('\n')
            file.write('i_cc_serdes: CC_SERDES\n')
            file.write('generic map (\n')
            for idx, (param, data) in enumerate(self.regfile.fields.items()):
                end = '' if (idx == len(self.regfile.fields.items())-1) else ','
                if data['mode'] != 'R':
                    width = data['hbit']-data['lbit']+1
                    file.write(f'    {param} => {width}X"{data['val']:X}"{end}\n')
            file.write(')\n')
            file.write('port map (\n')
            for idx, (port, width) in enumerate(self.ports.items()):
                end = '' if idx == len(self.ports.items())-1 else ','
                if port.endswith('_I'):
                    if width > 1:
                        file.write(f'    {port} => (others => \'0\'){end}\n')
                    else:
                        file.write(f'    {port} => \'{0}\'{end}\n')
                else: # port.endswith('_O'):
                    file.write(f'    {port} => open{end}\n')
            file.write(');\n')

    def fprint(self, key, value, line):
        if any(cond in key for cond in self.pos_cond) and int(value) != 0:
            print(bcolors.OK + line + bcolors.RESET)
        elif any(cond in key for cond in self.pos_cond) and int(value) == 0:
            print(bcolors.WARN + line + bcolors.RESET)
        elif any(cond in key for cond in self.neg_cond) and (int(value) < 1 if key.endswith('_N') else int(value) > 0):
            print(bcolors.FAIL + line + bcolors.RESET)
        elif any(cond in key for cond in self.ovr_cond) and int(value) > 0:
            print(bcolors.OVR + line + bcolors.RESET)
        else:
            print(line)

    def rd_regfile(self, addr) -> int:
        self._tool.wr_serdes_regfile(addr=addr, data=0, mask=0, wren=0)
        return self._tool.rd_serdes_regfile()

    def wr_regfile(self, addr, data, mask):
        self._tool.wr_serdes_regfile(addr=addr, data=data, mask=mask, wren=1)
        self._tool.rd_serdes_regfile()

    def rd_regfile_rx(self, verbose=0):
        for addr in range(0x00, 0x30):
            word = self.rd_regfile(addr)
            if verbose == 1:
                print(f'{addr:02X}: 0x{int(word):04X}')
            elif verbose == 2:
                filtered_entries = {key: value for key, value in self.regfile.fields.items() if value['addr'] == addr}
                for (key, value) in filtered_entries.items():
                    v = word[value['lbit']:value['hbit']+1]
                    line = f'{key:24} {int(v):4X}\'h {int(v):6}\'d'
                    self.fprint(key, v, line)

    def rd_regfile_rx_data(self):
        rxd_80bit = BitSequence()
        for addr in range(0x20, 0x25):
            rxd_80bit += self.rd_regfile(addr)
        rxd_64bit = rxd_80bit[0:7+1] + rxd_80bit[10:17+1] + rxd_80bit[20:27+1] + rxd_80bit[30:37+1] + rxd_80bit[40:47+1] + rxd_80bit[50:57+1] + rxd_80bit[60:67+1] + rxd_80bit[70:77+1]
        return rxd_64bit, rxd_80bit

    def print_regfile_rx_data(self, verbose=0):
        rx_data_80bit = 0
        word_idx = 0
        for addr in range(0x20, 0x25):
            word = self.rd_regfile(addr)
            if verbose == 1:
                print(f'{addr:02X}: 0x{int(word):04X}')
            rx_fields = {
                key: field for key, field in self.regfile.fields.items()
                if field['addr'] == addr and key.startswith('RX_DATA[')
            }
            for field_name, field_info in rx_fields.items():
                # Extract the relevant bits from the word
                bit_slice = word[field_info['lbit']:field_info['hbit'] + 1]
                rx_data_80bit |= int(bit_slice) << (16 * word_idx)
                word_idx += 1

        if verbose == 2:
            print(f'{"RX_DATA[79:0]":24} {rx_data_80bit:020X}\'h')

        # Convert to 64-bit format by packing every 10 bits into bytes
        rx_data_64bit = 0
        byte_position = 0
        for bit_offset in range(0, 80, 10):
            byte_value = (rx_data_80bit >> bit_offset) & 0xFF
            rx_data_64bit |= byte_value << (byte_position * 8)
            byte_position += 1

        if verbose == 2:
            print(f'{"RX_DATA[63:0]":24} {rx_data_64bit:016X}\'h')

        return rx_data_64bit, rx_data_80bit

    def wr_regfile_tx_data(self, data):
        self.wr_regfile(addr=0x41, data=0x1000, mask=0x1F00) # TX_DATA_OVR=1, TX_DATA_CNT=0, TX_DATA_VALID=0
        for i in range(5):
            self.wr_regfile(addr=0x42, data=(data >> 16*i) & 0xFFFF, mask=0xFFFF) # auto inc
        self.wr_regfile(addr=0x41, data=0x1B00, mask=0x1F00) # TX_DATA_OVR=1, TX_DATA_CNT=5, TX_DATA_VALID=1

    def rd_regfile_tx(self, verbose=0):
        for addr in range(0x30, 0x43): # 0x43..0x4F unused
            word = self.rd_regfile(addr)
            if verbose == 1:
                print(f'{addr:02X}: 0x{int(word):04X}')
            elif verbose == 2:
                filtered_entries = {key: value for key, value in self.regfile.fields.items() if value['addr'] == addr}
                for (key, value) in filtered_entries.items():
                    v = word[value['lbit']:value['hbit']+1]
                    line = f'{key:24} {int(v):4X}\'h {int(v):6}\'d'
                    self.fprint(key, v, line)

    def rd_regfile_pll(self, verbose=0):
        for addr in range(0x50, 0x5D):
            word = self.rd_regfile(addr)
            if verbose == 1:
                print(f'{addr:02X}: 0x{int(word):04X}')
            elif verbose == 2:
                filtered_entries = {key: value for key, value in self.regfile.fields.items() if value['addr'] == addr}
                for (key, value) in filtered_entries.items():
                    v = word[value['lbit']:value['hbit']+1]
                    line = f'{key:24} {int(v):4X}\'h {int(v):6}\'d'
                    self.fprint(key, v, line)

    def rd_regfile_pll_div_settings(self):
        word = self.rd_regfile(addr=0x51)
        FCNTRL = word[0:5+1]
        MAIN_DIVSEL = word[6:11+1]
        OUT_DIVSEL = word[12:13+1]
        n1 = MAIN_DIVSEL[2]
        n2 = MAIN_DIVSEL[0:1+1]
        n3 = MAIN_DIVSEL[3:4+1]
        return n1, n2, n3, OUT_DIVSEL

    def rd_regfile_pll_status(self):
        return self.rd_regfile(addr=0x55) + self.rd_regfile(addr=0x56)

    def rd_regfile_pll_bisc_status(self):
        return self.rd_regfile(addr=0x5A) + self.rd_regfile(addr=0x5B)

    def reset_serdes_tx(self):
        print('INFO:  Resetting SerDes TX')

        word = self.rd_regfile(addr=0x5C)
        if (word[0] != 1 or word[2] != 1):
            print(f'ERROR: SerDes not enabled or in testmode. 0x5C=0x{int(word):04X}')
            return

        # TX reset
        self.wr_regfile(addr=0x3F, data=0xC000, mask=0xC000) # TX_RESET_OVR=1, TX_RESET=1
        self.wr_regfile(addr=0x3F, data=0x0000, mask=0xC000) # TX_RESET_OVR=0, TX_RESET=0
        word = self.rd_regfile(addr=0x41)
        timeout = 5
        while timeout > 0:
            if (int(word[14]) != 1): # TX_RESET_DONE
                timeout = timeout - 1
                if timeout == 0:
                    print(f'ERROR: TX_RESET_DONE timeout')
            else:
                break

    def set_serdes_datapath(self, mode=80):
        if mode == 0 or mode == 20:
            self.wr_regfile(addr=0x2A, data=0x0000, mask=0x000C) # RX_DATAPATH_SEL=0
            self.wr_regfile(addr=0x40, data=0x0000, mask=0x0018) # TX_DATAPATH_SEL=0 (16/20)
        elif mode == 1 or mode == 40:
            datapath_sel = 1
            self.wr_regfile(addr=0x2A, data=0x0001, mask=0x000C) # RX_DATAPATH_SEL=1
            self.wr_regfile(addr=0x40, data=0x0008, mask=0x0018) # TX_DATAPATH_SEL=1 (32/40)
        elif mode == 2 or mode == 3 or mode == 80:
            datapath_sel = 3
            self.wr_regfile(addr=0x2A, data=0x000C, mask=0x000C) # RX_DATAPATH_SEL=3
            self.wr_regfile(addr=0x40, data=0x0018, mask=0x0018) # TX_DATAPATH_SEL=3 (64/80)
        else:
            print(f'ERROR: Invalid datapath configruation {mode}')

    def check_serdes_datapath(self, mode):
        check = 3 if mode == 80 else 1 if mode == 40 else 0 if mode == 20 else mode
        word = self.rd_regfile(addr=0x2A)
        if (int(word[2:3+1]) != check):
            print(f'ERROR: RX_DATAPATH_SEL != {check} ({int(word[2:3+1]):2X})')
        word = self.rd_regfile(addr=0x40)
        if (int(word[3:4+1]) != check):
            print(f'ERROR: TX_DATAPATH_SEL != {check} ({int(word[3:4+1]):2X})')

    def reset_serdes_rx(self):
        print('INFO:  Resetting SerDes RX')

        word = self.rd_regfile(addr=0x5C)
        if (word[0] != 1 or word[2] != 1):
            print(f'ERROR: SerDes not enabled or in testmode. 0x5C=0x{int(word):04X}')
            return

        # RX reset
        self.wr_regfile(addr=0x2B, data=0x0003, mask=0x0003) # RX_RESET_OVR=1, RX_RESET=1
        self.wr_regfile(addr=0x3F, data=0x0000, mask=0x0003) # RX_RESET_OVR=0, RX_RESET=0
        word = self.rd_regfile(addr=0x2C)
        timeout = 5
        while timeout > 0:
            if (int(word[10]) != 1): # RX_RESET_DONE
                timeout = timeout - 1
                if timeout == 0:
                    print(f'ERROR: RX_RESET_DONE timeout')
            else:
                break

    def reset_serdes_trx(self):
        self.reset_serdes_tx()
        self.reset_serdes_rx()

    def start_serdes_pll(self, n1=1, n2=2, n3=3, outdiv=4, calib=False):
        print('INFO:  Configuring SerDes ADPLL')

        if (n1 < 1 or n1 > 2):
            print(f'ERROR: Main divider N1 is out of range 1..2')
            return
        if (n2 < 2 or n2 > 5):
            print(f'ERROR: Main divider N2 is out of range 2..5')
            return
        if (n3 < 3 or n3 > 5):
            print(f'ERROR: Main divider N3 is out of range 3..5')
            return
        if (outdiv != 1 and outdiv != 2 and outdiv != 4):
            print(f'ERROR: Output divider N3 is limited to 1, 2 or 4')
            return

        dco = 1000.0 / SER_CLK_PERIOD_NS * n1 * n2 * n3
        freq = dco / outdiv
        print(f'INFO:  SerDes ADPLL frequency / data rate is {freq} MHz / {freq*2} Mbit/s')

        status = self.rd_regfile_pll_status()
        if (status[0] == 1):
            print('INFO:  Disabling SerDes ADPLL')
            self.wr_regfile(addr=0x50, data=0x0000, mask=0x0001)

        if outdiv == 1:
            pll_div = 0x0000
        elif outdiv == 2:
            pll_div = 0x1000
        else:
            pll_div = 0x3000
        if n2 == 5:
            pll_div = (pll_div & ~(0b11 << 6)) | (0b11 << 6)
        elif n2 == 4:
            pll_div = (pll_div & ~(0b11 << 6)) | (0b10 << 6)
        elif n2 == 2:
            pll_div = (pll_div & ~(0b11 << 6)) | (0b01 << 6)
        if n1 == 2:
            pll_div |= (1 << 8)
        if n3 == 5:
            pll_div = (pll_div & ~(0b11 << 9)) | (0b11 << 9)
        elif n3 == 4:
            pll_div = (pll_div & ~(0b11 << 9)) | (0b10 << 9)

        print('INFO:  Writing SerDes ADPLL divider settings')
        self.wr_regfile(addr=0x51, data=pll_div, mask=0x3FC0)

        if (calib):
            print('INFO:  Stopping SerDes ADPLL self-calibration')
            self.wr_regfile(addr=0x57, data=0x0004, mask=0x0007)
            self.wr_regfile(addr=0x57, data=
                ((self.ADPLL_PFDAC_TIMER    & 0x000F) <<  3) |
                ((self.ADPLL_PFDAC_COR_DLY  & 0x0007) << 10) |
                ((self.ADPLL_PFDAC_CAL_SIGN & 0x0001) << 13) |
                ((self.ADPLL_PFDAC_AUTO_CAL & 0x0001) << 14),
                mask=0xFFF8)
            self.wr_regfile(addr=0x58, data=
                ((self.ADPLL_PFDAC_COR_DLY  & 0x001F) << 0) |
                ((self.ADPLL_PFDAC_CAL_SIGN & 0x001F) << 5) |
                ((self.ADPLL_PFDAC_AUTO_CAL & 0x001F) << 10),
                mask=0xFFFF)

        print('INFO:  Starting SerDes ADPLL')
        self.wr_regfile(addr=0x50, data=0x0002, mask=0x0007)
        self.wr_regfile(addr=0x50, data=0x0003, mask=0x0003)

        if (calib):
            print('INFO:  Starting SerDes ADPLL self-calibration')
            self.wr_regfile(addr=0x57, data=0x0004, mask=0x0007)
            self.wr_regfile(addr=0x57, data=0x0005, mask=0x0007) # BISC mode B, enable

        timeout = 5
        while timeout > 0:
            sleep(0.5)
            status = self.rd_regfile_pll_status()
            if (status[0] == 0):
                timeout = timeout - 1
                print(f'INFO:  LCK: {int(status[0]):1d} FTO: {int(status[1]):1d} FTU: {int(status[2]):1d} FT: {int(status[3:12+1]):4d} SY: {int(status[16:23+1]):3d} ST: {int(status[13:14+1]):1d}')
                if timeout == 0:
                    print(f'ERROR: SerDes ADPLL lock timeout')
            else:
                print(f'INFO:  SerDes ADPLL locked')
                break

        if (calib):
            result = self.rd_regfile_pll_bisc_status()
            print(f'INFO:  PFDAC result: max reached: {int(result[0]):1d}, ac_result: {int(result[1:17+1]):6d}, CP: {int(result[18:22+1]):2d}')

        print(f'INFO:  ADPLL status: LCK: {int(status[0]):1d} FTO: {int(status[1]):1d} FTU: {int(status[2]):1d} FT: {int(status[3:12+1]):4d} SY: {int(status[16:23+1]):3d} ST: {int(status[13:14+1]):1d}')

    def tc_prbs(self, force_err=False):
        print(f'INFO:  Starting SerDes PRBS testcases')

        word = self.rd_regfile(addr=0x5C)
        if (word[0] != 1 or word[2] != 1):
            print(f'ERROR: SerDes not enabled or in testmode. 0x5C=0x{int(word):04X}')
            return

        # set 80-bit datapath
        self.set_serdes_datapath(80)

        self.start_serdes_pll(n1=1, n2=5, n3=5, outdiv=4, calib=True) # 1250 Mbit/s, PFDAC=on
        self.reset_serdes_trx()

        # check datapath
        self.check_serdes_datapath(80)

        # disable testmode?
        self.wr_regfile(addr=0x2A, data=0x0210, mask=0x02F0) # RX_PRBS_OVR=1, RX_PRBS_SEL=0, RX_PRBS_CNT_RESET=1

        for i in range(0, 2):
            prbs = 7 if i == 0 else 15 if i == 1 else 23 if i == 2 else 31 if i == 3 else 0
            print(f'INFO:  Setting up PRBS-{prbs}')

            self.wr_regfile(addr=0x40, data=((i+1) << 6) | (1 << 5), mask=0x01E0) # TX_PRBS_OVR=1, TX_PRBS_SEL=i
            word = self.rd_regfile(addr=0x40)
            #if (word[5] == 1):
            #    print(f'ERROR: TX PRBS overwrite is not disabled')
            if (int(word[6:8+1]) != i+1):
                print(f'ERROR: TX PRBS mode is invalid')

            self.wr_regfile(addr=0x2A, data=((i+1) << 5) | (1 << 4), mask=0x00F0) # RX_PRBS_OVR=1, RX_PRBS_SEL=i
            word = self.rd_regfile(addr=0x2A)
            #if (word[4] == 1):
            #    print(f'ERROR: RX PRBS overwrite is not disabled')
            if (word[9] == 1):
                print(f'ERROR: RX_PRBS_CNT_RESET is active')
            if (int(word[5:7+1]) != i+1):
                print(f'ERROR: RX PRBS mode is invalid')

            # send data
            print(f'INFO:  Sending data (this might take a while) ...')
            n = 10
            for i in range(n):
                print(f'INFO:  {i}/{n}')
                sleep(1)

            word = self.rd_regfile(addr=0x1F)
            print(f'INFO:  RX_PRBS_LOCKED: {int(word[15]):1d}, RX_PRBS_ERR_CNT: {int(word[0:14+1]):X}')
            if (word[15] == 0):
                print(f'ERROR: RX PRBS did not lock')
            if (int(word[0:14+1]) > 0):
                print(f'ERROR: RX PRBS errors detected ({int(word[0:14+1])})')

            if (force_err):
                print(f'INFO:  Starting error injection')
                self.wr_regfile(addr=0x40, data=0x0200, mask=0x0200) # TX_PRBS_FORCE_ERR=1
                word = self.rd_regfile(addr=0x1F)
                print(f'INFO:  RX_PRBS_LOCKED: {int(word[15]):1d}, RX_PRBS_ERR_CNT: {int(word[0:14+1]):X}')
                if (int(word[0:14+1]) == 0):
                    print(f'ERROR: RX PRBS error detection failed')

            self.wr_regfile(addr=0x2A, data=0x0210, mask=0x02F0) # RX_PRBS_CNT_RESET=1, RX_PRBS_OVR=1, RX_PRBS_SEL=0
            self.wr_regfile(addr=0x40, data=0x0020, mask=0x01E0) # TX_PRBS_OVR=1, TX_PRBS_SEL=0
        return

    def tc_uipattern(self, mode=0):
        print(f'INFO:  Starting SerDes UI pattern testcase')

        if not mode in [0,2,20,40,80]:
            print(f'ERROR: Invalid UI pattern mode ({mode}), must be in [0,2,20,40,80]')
            return

        word = self.rd_regfile(addr=0x5C)
        if (word[0] != 1 or word[2] != 1):
            print(f'ERROR: SerDes not enabled or in testmode. 0x5C=0x{int(word):04X}')
            return

        # set datapath if mode in [20,40,80]
        self.set_serdes_datapath(mode)

        self.start_serdes_pll(n1=1, n2=2, n3=3, outdiv=4, calib=True) # 300 Mbit/s, PFDAC=on
        self.reset_serdes_trx()

        # check datapath
        self.check_serdes_datapath(mode)

        # disable testmode?
        self.wr_regfile(addr=0x2A, data=0x0210, mask=0x02F0) # RX_PRBS_OVR=1, RX_PRBS_SEL=0, RX_PRBS_CNT_RESET=1

        print(f'INFO:  Setting up {mode} UI square wave')

        i = 5 if mode == 2 else 6 if mode in [20,40,80] else 0
        self.wr_regfile(addr=0x40, data=((i+1) << 6) | (1 << 5), mask=0x01E0) # TX_PRBS_OVR=1, TX_PRBS_SEL=i
        word = self.rd_regfile(addr=0x40)
        if (int(word[6:8+1]) != i+1):
            print(f'ERROR: TX PRBS mode is invalid')

    def tc_eyemeas(self):
        print(f'INFO:  Starting SerDes eye measurement')

        word = self.rd_regfile(addr=0x5C)
        if (word[0] != 1 or word[2] != 1):
            print(f'ERROR: SerDes not enabled or in testmode. 0x5C=0x{int(word):04X}')
            return

    def tc_loopback(self):
        print(f'INFO:  Starting SerDes loopback testcases')

        word = self.rd_regfile(addr=0x5C)
        if (word[0] != 1 or word[2] != 1):
            print(f'ERROR: SerDes not enabled or in testmode. 0x5C=0x{int(word):04X}')
            return

        # testcases:
        #
        # 0: TX PMA (near-end, mode 1: pre-driver), TX_PMA_LOOPBACK=01 or TX_PMA_LOOPBACK=11
        # 1: TX PMA (near-end, mode 2: pad), TX_PMA_LOOPBACK=10, NOTE: requires termination!
        # 3: TX PCS (near-end)
        for j in [0, 1, 3]:
            if (j < 3):
                print(f'\nINFO:  Enabling TX PMA Loopback (Mode {j:1d})')
            else:
                print(f'\nINFO:  Enabling TX PCS Loopback')

            # TX_LOOPBACK_OVR=1 | TX_PMA_LOOPBACK=(001=pma-drv, 011=pma-drv, 010=pma-pad, 100=pcs)
            self.wr_regfile(addr=0x40, data=(0x0400 | (j+1) & 0x7), mask=0x0407)
            word = self.rd_regfile(addr=0x40)
            if (word[10] == 0):
                print(f'ERROR: TX loopback overwrite is not enabled')
            if (int(word[0:1+1]) != j+1 and j < 3):
                print(f'ERROR: TX PMA loopback is not enabled')
            if (word[2] == 0 and j == 3):
                print(f'ERROR: TX PCS loopback is not enabled')

            # turn tx driver off
            if (j == 1 or j == 3):
                self.wr_regfile(addr=0x30, data=0x0000, mask=0x001F) # TODO TX_SEL_PRE=0, TX_SEL_POST=x, TX_AMP=x
                self.wr_regfile(addr=0x31, data=0x07E0, mask=0x07E0) # TX_BRANCH_EN_MAIN=63
                word = self.rd_regfile(addr=0x30)
                if (int(word[0:4+1]) != 0):
                    print(f'ERROR: Invalid TX_SEL_PRE driver setting')
                word = self.rd_regfile(addr=0x31)
                if (int(word[5:10+1]) != 63):
                    print(f'ERROR: Invalid TX_BRANCH_EN_MAIN setting')
            else:
                self.wr_regfile(addr=0x30, data=0x0001, mask=0x001F) # TODO TX_SEL_PRE=1, TX_SEL_POST=x, TX_AMP=x
                self.wr_regfile(addr=0x31, data=0x0000, mask=0x07E0) # TX_BRANCH_EN_MAIN=0
                word = self.rd_regfile(addr=0x30)
                if (int(word[0:4+1]) != 1):
                    print(f'ERROR: Invalid TX_SEL_PRE driver setting')
                word = self.rd_regfile(addr=0x31)
                if (int(word[5:10+1]) != 0):
                    print(f'ERROR: Invalid TX_BRANCH_EN_MAIN setting')

            self.start_serdes_pll(n1=1, n2=5, n3=5, outdiv=4, calib=True) # 1250 Mbit/s, PFDAC=on
            self.reset_serdes_trx()

            self.wr_regfile(addr=0x41, data=0x00C0, mask=0x00C0) # TX_8B10B_EN_OVR=1, TX_8B10B_EN=1
            self.wr_regfile(addr=0x2B, data=0xC000, mask=0xC000) # RX_8B10B_EN_OVR=1, RX_8B10B_EN=1

            # 32-Bit comma alignment test
            self.wr_regfile(addr=0x12, data=0x3000, mask=0x3000) # RX_ALIGN_COMMA_WORD=3 (32 bit)

            # NOTE: Please define position of the k-word using the `TX_CHAR_IS_K_I` input: set to 8'h0000_0001
            self.wr_regfile_tx_data(data=0x1284A1284A1284A128BC) # 64'h4A4A4A4A_4A4A4ABC

            self.wr_regfile(addr=0x11, data=0x0C00, mask=0x0C00) # RX_MCOMMA_ALIGN_OVR=1, RX_MCOMMA_ALIGN=1
            self.wr_regfile(addr=0x12, data=0x0C00, mask=0x0C00) # RX_PCOMMA_ALIGN_OVR=1, RX_PCOMMA_ALIGN=1
            self.wr_regfile(addr=0x13, data=0x3000, mask=0x3000) # RX_COMMA_DETECT_EN_OVR=1, RX_COMMA_DETECT_EN=1

            print(f'INFO:  Sending data (this might take a while) ...')
            sleep(2)

            self.wr_regfile(addr=0x11, data=0x0000, mask=0x0C00) # RX_MCOMMA_ALIGN_OVR=1, RX_MCOMMA_ALIGN=0
            self.wr_regfile(addr=0x12, data=0x0000, mask=0x0C00) # RX_PCOMMA_ALIGN_OVR=1, RX_PCOMMA_ALIGN=0

            print(f'INFO:  Checking 32-Bit comma alignment')
            rx_data, _ = self.rd_regfile_rx_data()
            align_pos = 0 if int(rx_data[0:7+1]) == 0xBC else 1
            rx_recv = 0x4A4A4A4A4A4A4ABC if align_pos == 0 else 0x4A4A4ABC4A4A4A4A

            if (int(rx_data[0:7+1]) != 0xBC and int(rx_data[32:39+1]) != 0xBC):
                print(f'ERROR: Comma is not aligned to 32-Bit boundary')
            if (int(rx_data) != rx_recv):
                print(f'ERROR: Invalid idle sequence received: RX_DATA[63:0]: {int(rx_data):016X}')

            # 16-Bit comma alignment test
            self.reset_serdes_trx()
            self.wr_regfile(addr=0x12, data=0x1000, mask=0x3000) # RX_ALIGN_COMMA_WORD=1 (16 bit)

            # NOTE: Please define position of the k-word using the `TX_CHAR_IS_K_I` input: set to 8'h0000_0001
            self.wr_regfile_tx_data(data=0x1284A1284A1284A128BC) # 64'h4A4A4A4A_4A4A4ABC

            self.wr_regfile(addr=0x11, data=0x0C00, mask=0x0C00) # RX_MCOMMA_ALIGN_OVR=1, RX_MCOMMA_ALIGN=1
            self.wr_regfile(addr=0x12, data=0x0C00, mask=0x0C00) # RX_PCOMMA_ALIGN_OVR=1, RX_PCOMMA_ALIGN=1
            self.wr_regfile(addr=0x13, data=0x3000, mask=0x3000) # RX_COMMA_DETECT_EN_OVR=1, RX_COMMA_DETECT_EN=1

            print(f'INFO:  Sending data (this might take a while) ...')
            sleep(2)

            self.wr_regfile(addr=0x11, data=0x0000, mask=0x0C00) # RX_MCOMMA_ALIGN_OVR=1, RX_MCOMMA_ALIGN=0
            self.wr_regfile(addr=0x12, data=0x0000, mask=0x0C00) # RX_PCOMMA_ALIGN_OVR=1, RX_PCOMMA_ALIGN=0

            print(f'INFO:  Checking 16-Bit comma alignment')
            rx_data, _ = self.rd_regfile_rx_data()
            align_pos = 0 if int(rx_data[  0:7+1]) == 0xBC else \
                        1 if int(rx_data[16:23+1]) == 0xBC else \
                        2 if int(rx_data[32:39+1]) == 0xBC else 3
            rx_recv = 0x4A4A4A4A4A4A4ABC if align_pos == 0 else \
                      0x4A4A4A4A4ABC4A4A if align_pos == 1 else \
                      0x4A4A4ABC4A4A4A4A if align_pos == 2 else 0x4ABC4A4A4A4A4A4A

            if (int(rx_data[0:7+1]) != 0xBC and int(rx_data[16:23+1]) != 0xBC and int(rx_data[32:39+1]) != 0xBC and int(rx_data[48:55+1]) != 0xBC):
                print(f'ERROR: Comma is not aligned to 16-Bit boundary')
            if (int(rx_data) != rx_recv):
                print(f'ERROR: Invalid idle sequence received: RX_DATA[63:0]: {int(rx_data):016X}')

            # 8-Bit comma alignment test
            self.reset_serdes_trx()
            self.wr_regfile(addr=0x12, data=0x0000, mask=0x3000) # RX_ALIGN_COMMA_WORD=0 (8 bit)

            # NOTE: Please define position of the k-word using the `TX_CHAR_IS_K_I` input: set to 8'h0000_0001
            self.wr_regfile_tx_data(data=0x1284A1284A1284A128BC) # 64'h4A4A4A4A_4A4A4ABC

            self.wr_regfile(addr=0x11, data=0x0C00, mask=0x0C00) # RX_MCOMMA_ALIGN_OVR=1, RX_MCOMMA_ALIGN=1
            self.wr_regfile(addr=0x12, data=0x0C00, mask=0x0C00) # RX_PCOMMA_ALIGN_OVR=1, RX_PCOMMA_ALIGN=1
            self.wr_regfile(addr=0x13, data=0x3000, mask=0x3000) # RX_COMMA_DETECT_EN_OVR=1, RX_COMMA_DETECT_EN=1

            print(f'INFO:  Sending data (this might take a while) ...')
            sleep(2)

            self.wr_regfile(addr=0x11, data=0x0000, mask=0x0C00) # RX_MCOMMA_ALIGN_OVR=1, RX_MCOMMA_ALIGN=0
            self.wr_regfile(addr=0x12, data=0x0000, mask=0x0C00) # RX_PCOMMA_ALIGN_OVR=1, RX_PCOMMA_ALIGN=0

            print(f'INFO:  Checking 8-Bit comma alignment')
            rx_data, _ = self.rd_regfile_rx_data()
            align_pos = 0 if int(rx_data[  0:7+1]) == 0xBC else \
                        1 if int(rx_data[ 8:15+1]) == 0xBC else \
                        2 if int(rx_data[16:23+1]) == 0xBC else \
                        3 if int(rx_data[24:31+1]) == 0xBC else \
                        4 if int(rx_data[32:39+1]) == 0xBC else \
                        5 if int(rx_data[40:47+1]) == 0xBC else \
                        6 if int(rx_data[48:55+1]) == 0xBC else 7
            rx_recv = 0x4A4A4A4A4A4A4ABC if align_pos == 0 else \
                      0x4A4A4A4A4A4ABC4A if align_pos == 1 else \
                      0x4A4A4A4A4ABC4A4A if align_pos == 2 else \
                      0x4A4A4A4ABC4A4A4A if align_pos == 3 else \
                      0x4A4A4ABC4A4A4A4A if align_pos == 4 else \
                      0x4A4ABC4A4A4A4A4A if align_pos == 5 else \
                      0x4ABC4A4A4A4A4A4A if align_pos == 6 else 0xBC4A4A4A4A4A4A4A

            if (int(rx_data[0:7+1]) != 0xBC and int(rx_data[ 8:15+1]) != 0xBC and int(rx_data[16:23+1]) != 0xBC and int(rx_data[24:31+1]) != 0xBC and int(rx_data[32:39+1]) != 0xBC and int(rx_data[40:47+1]) != 0xBC and int(rx_data[48:55+1]) != 0xBC and int(rx_data[56:63+1]) != 0xBC):
                print(f'ERROR: Comma is not aligned to 8-Bit boundary')
            if (int(rx_data) != rx_recv):
                print(f'ERROR: Invalid idle sequence received: RX_DATA[63:0]: {int(rx_data):016X}')

    def calc_rxterm_vcm(self, vddio=1.0, vcmsel=None) -> float:
        if vcmsel is None:
            vcmsel = self.rd_regfile(addr=0x02)
            vcmsel = int(vcmsel[11:13+1])
        return (vcmsel/29) * vddio

    def update_values(self):
        while True:
            sleep(0.5) # 500ms update interval
            with self.param_lock:
                #for param in self.regfile.fields:
                #    self.regfile.fields[param]['val'] = random.randint(0, 16)
                for addr in chain(range(0x00, 0x30), range(0x30, 0x43), range(0x50, 0x5D)):
                    word = self.rd_regfile(addr)
                    filtered_entries = {key: value for key, value in self.regfile.fields.items() if value['addr'] == addr}
                    for (key, value) in filtered_entries.items():
                        val = word[value['lbit']:value['hbit']+1]
                        self.regfile.fields[key]['val'] = int(val)

    def draw_parameters(self, stdscr):
        curses.curs_set(0)
        stdscr.keypad(True)
        stdscr.timeout(10) #stdscr.nodelay(True)  # Non-blocking input

        # Initialize colors
        curses.start_color()
        curses.init_pair(1, curses.COLOR_GREEN, curses.COLOR_BLACK)   # OK (Green)
        curses.init_pair(2, curses.COLOR_YELLOW, curses.COLOR_BLACK)  # WARN (Yellow)
        curses.init_pair(3, curses.COLOR_RED, curses.COLOR_BLACK)     # FAIL (Red)
        curses.init_pair(4, curses.COLOR_BLUE, curses.COLOR_BLACK)    # OVR (Blue)
        curses.init_pair(5, curses.COLOR_WHITE, curses.COLOR_BLACK)   # Normal text

        def handle_resize(signum, frame):
            curses.endwin()
            stdscr.refresh()

        signal.signal(signal.SIGWINCH, handle_resize)

        selected_index = 0
        show_hex = False
        search_results = []
        search_index = 0

        while True:
            max_y, max_x = stdscr.getmaxyx()
            max_name_length = max(len(name) for name in self.regfile.fields.keys())
            col_width = max_name_length + 8
            num_columns = max(1, max_x // col_width)
            num_rows = math.ceil(len(self.regfile.fields) / num_columns)
            param_list = list(self.regfile.fields.items())

            # Extract values for bit rate calculation
            PLL_MAIN_DIVSEL = self.regfile.fields.get("PLL_MAIN_DIVSEL", {}).get("val", 0x1B)
            PLL_OUT_DIVSEL = self.regfile.fields.get("PLL_OUT_DIVSEL", {}).get("val", 0x0)
            TX_DATAPATH_SEL = self.regfile.fields.get("TX_DATAPATH_SEL", {}).get("val", 0x0)

            # Decode PLL values
            N3 = {0b00: 3, 0b10: 4, 0b11: 5}.get((PLL_MAIN_DIVSEL >> 3) & 0b11, None)
            N1 = {0b0: 1, 0b1: 2}.get((PLL_MAIN_DIVSEL >> 2) & 0b1, None)
            N2 = {0b00: 3, 0b01: 2, 0b10: 4, 0b11: 5}.get(PLL_MAIN_DIVSEL & 0b11, None)
            OUTDIV = {0b00: 1, 0b01: 2, 0b11: 4}.get(PLL_OUT_DIVSEL, None)

            bit_rate_clock = 2 * 100e6 * N1 * N2 * N3 / OUTDIV if None not in (N1, N2, N3, OUTDIV) else None

            # Decode TX_DATAPATH_SEL
            datapath_mode = (TX_DATAPATH_SEL & 0b10) >> 1  # Extract MSB
            is_64_bit = datapath_mode == 1  # If `1x`, it is 64-bit

            # Determine AddDiv based on OUTDIV
            if is_64_bit:
                AddDiv = {0b00: 2, 0b01: 4, 0b11: 8}.get(PLL_OUT_DIVSEL, None)
            else:
                AddDiv = {0b00: 1, 0b01: 2, 0b11: 4}.get(PLL_OUT_DIVSEL, None)

            PLL_FCNTRL = self.regfile.fields.get("PLL_FCNTRL", {}).get("val", 0x0)
            data_path_clock = (100e6 * N1 * N2 * N3) / (self.olclkg[PLL_FCNTRL] * AddDiv) if None not in (N1, N2, N3, OUTDIV, AddDiv) else None

            bit_rate_str = f"Bit Rate Clock: {bit_rate_clock / 1e6:.2f} MHz" if bit_rate_clock else "Invalid PLL Config"
            data_path_str = f"TX Data Path Clock: {data_path_clock / 1e6:.2f} MHz" if data_path_clock else "Invalid Data Path Config"

            stdscr.clear()
            stdscr.addstr(0, 2, " FPGA SerDes Parameters (Auto-Update Enabled) ", curses.A_BOLD | curses.A_REVERSE)

            with self.param_lock:
                for row in range(num_rows):
                    for col in range(num_columns):
                        index = row + col * num_rows
                        if index >= len(param_list):
                            continue

                        name, data = param_list[index]
                        value = data['val']
                        mode = data['mode']  # Get mode (R/W, W/C, R/C, R)
                        color_pair = ColorFormatter.get_color_pair(name, value)

                        formatted_value = f"0x{value:X}" if show_hex else f"{value}"

                        # Read-only and Write/Clear (dimmed text)
                        text_attr = curses.color_pair(color_pair) | curses.A_DIM if mode in ["R", "R/C"] else curses.color_pair(color_pair)

                        x_pos = col * col_width + 2
                        y_pos = row + 2

                        # Highlight selected row
                        if index == selected_index:
                            stdscr.addstr(y_pos, x_pos, f"{name:<{max_name_length}} {formatted_value:<8}", curses.A_REVERSE)
                        else:
                            # Print parameter name (dimmed for R & W/C)
                            stdscr.addstr(y_pos, x_pos, f"{name:<{max_name_length}}", text_attr)

                            # Print value in color
                            stdscr.addstr(y_pos, x_pos + max_name_length + 1, f"{formatted_value:<8}", curses.color_pair(color_pair))


            stdscr.addstr(max_y - 5, 2, bit_rate_str)
            stdscr.addstr(max_y - 4, 2, data_path_str)

            search_hint = "[n] Next match  |  " if search_results else ""
            stdscr.addstr(max_y - 2, 2, f"{search_hint}[Arrow Keys] Navigate | [Enter] Edit | [/] Find | [h] Toggle HEX/DEC | [q] Quit", curses.A_BOLD)

            stdscr.refresh()

            try:
                key = stdscr.getch()
            except curses.error:
                key = -1  # No input

            if key == ord("h"):
                show_hex = not show_hex
            elif key == curses.KEY_UP and selected_index - 1 >= 0:
                selected_index -= 1
            elif key == curses.KEY_DOWN and selected_index + 1 < len(param_list):
                selected_index += 1
            elif key == curses.KEY_LEFT and selected_index - num_rows >= 0:
                selected_index -= num_rows
            elif key == curses.KEY_RIGHT and selected_index + num_rows < len(param_list):
                selected_index += num_rows
            elif key == ord("\n"):
                if param_list[selected_index][1]['mode'] in ["R", "R/C"]:
                    self.error_message(stdscr, "Cannot edit read-only parameter!")
                else:
                    self.edit_value_popup(stdscr, param_list[selected_index])
            elif key == ord("/"):
                search_results, search_index = self.find_parameter(stdscr, param_list)
                if search_results:
                    selected_index = search_results[search_index]
            elif key == ord("n") and search_results:
                search_index = (search_index + 1) % len(search_results)
                selected_index = search_results[search_index]
            elif key == ord("q"):
                break

    def edit_value_popup(self, stdscr, param):
        name, data = param
        max_y, max_x = stdscr.getmaxyx()

        # Calculate the valid range from `hbit` and `lbit`
        hbit, lbit = data['hbit'], data['lbit']
        mask = ((1 << (hbit - lbit + 1)) - 1) << lbit
        addr = data['addr']
        min_value = 0
        max_value = (1 << (hbit - lbit + 1)) - 1  # Compute max based on bit range

        win_height, win_width = 9, 50
        start_y = (max_y - win_height) // 2
        start_x = (max_x - win_width) // 2

        win = curses.newwin(win_height, win_width, start_y, start_x)
        win.box()
        win.addstr(1, 2, f"Editing:  {name}", curses.A_BOLD)
        win.addstr(2, 2, f"Position: addr=0x{addr:02X} mask=0x{mask:04X}")
        win.addstr(3, 2, f"Current:  {data['val']}  (Range: {min_value} - {max_value})")  # Show valid range
        win.addstr(5, 2, "New value: ")
        win.addstr(7, 2, "[Enter] Save  |  [ESC/q] Cancel", curses.A_DIM)

        win.refresh()
        curses.curs_set(1)
        win.keypad(True)

        curses.echo()
        new_val = ""

        while True:
            key = win.getch()

            if key in (27, ord("q")):
                break
            elif key == ord("\n"):
                try:
                    entered_value = int(new_val, 0)  # Convert input to integer
                    if min_value <= entered_value <= max_value:
                        with self.param_lock:
                            #data['val'] = entered_value  # Apply change if within range
                            self._tool.wr_serdes_regfile(addr=addr, data=entered_value << lbit, mask=mask, wren=1)
                            self._tool.rd_serdes_regfile()
                        break
                    else:
                        win.addstr(6, 2, "Out of range! Try again.", curses.A_BOLD | curses.color_pair(3))
                        win.refresh()
                        time.sleep(1)
                        win.addstr(6, 2, " " * 30)  # Clear error message
                except ValueError:
                    win.addstr(6, 2, "Invalid input!", curses.A_BOLD | curses.color_pair(3))
                    win.refresh()
                    time.sleep(1)
                    win.addstr(6, 2, " " * 30)  # Clear error message
            elif key in (curses.KEY_BACKSPACE, 127):
                new_val = new_val[:-1]
                win.addstr(5, 13, " " * 10)  # Clear previous input
            elif key in range(32, 127):
                new_val += chr(key)

            win.addstr(5, 13, new_val)
            win.refresh()

        curses.noecho()
        curses.curs_set(0)

    def find_parameter(self, stdscr, param_list):
        max_y, max_x = stdscr.getmaxyx()
        win_height, win_width = 4, 50
        start_y = (max_y - win_height) // 2
        start_x = (max_x - win_width) // 2

        win = curses.newwin(win_height, win_width, start_y, start_x)
        win.box()
        win.addstr(1, 2, "Find: ")
        win.addstr(2, 2, "[ESC/q] Cancel", curses.A_DIM)

        win.refresh()
        curses.curs_set(1)
        curses.echo()

        search_term = ""

        while True:
            key = win.getch()

            if key in (27, ord("q")):
                return [], 0
            elif key == ord("\n"):
                break
            elif key in (curses.KEY_BACKSPACE, 127):
                search_term = search_term[:-1]
                win.addstr(1, 8, " " * 40)
            elif key in range(32, 127):
                search_term += chr(key)

            win.addstr(1, 8, search_term)
            win.refresh()

        curses.noecho()
        curses.curs_set(0)

        search_term = search_term.strip().lower()

        if not search_term:
            return [], 0

        matches = [i for i, (name, _) in enumerate(param_list) if search_term in name.lower()]

        if not matches:
            self.error_message(stdscr, "No matches found!")
            return [], 0

        return matches, 0

    def error_message(self, stdscr, message):
        max_y, max_x = stdscr.getmaxyx()
        win_height, win_width = 3, len(message) + 10
        start_y = (max_y - win_height) // 2
        start_x = (max_x - win_width) // 2

        win = curses.newwin(win_height, win_width, start_y, start_x)
        win.box()
        win.addstr(1, 2, message, curses.A_BOLD)

        win.refresh()
        curses.napms(1500)
        del win


if __name__ == '__main__':
    try:
        p = argparse.ArgumentParser(prog='serdestool', description='', epilog=ArgEpilog)

        p.add_argument('-l', '--list', dest='listdev', action='store_true', help='list available boards/programmers and exit')
        p.add_argument('-b', dest='board', type=str, metavar=Boards_e, default=Boards_e[0], required=False, help='select board (default: %(default)s)')
        p.add_argument('--index-chain', dest='idx', default=0, required=False, help='device index in JTAG chain (default: %(default)s)')
        p.add_argument('--freq', type=ArgHzRegex, default='20M', metavar="[0 - 30M]", required=False, help='frequency setting; append "k" to the argument for kilohertz or "M" for megahertz (default: %(default)s)')
        p.add_argument('-m', dest='genmod', type=str, required=False, help='generate verilog or vhdl module and exit; specify the file format with extension .v or .vhd')
        p.add_argument('--rdregrx', dest='rdregrx', action='store_true', help='read rx regfile')
        p.add_argument('--rdregrxdata', dest='rdregrxdata', action='store_true', help='read rx data')
        p.add_argument('--rdregtx', dest='rdregtx', action='store_true', help='read tx regfile')
        p.add_argument('--rdregpll', dest='rdregpll', action='store_true', help='read pll regfile')
        p.add_argument('--rdstatuspll', dest='rdstatuspll', action='store_true', help='read pll status registers')
        p.add_argument('--gui', dest='gui', action='store_true', help='start curses gui')
        p.add_argument('--tcprbs', dest='tcprbs', action='store_true', help='testcase: prbs')
        p.add_argument('--tcloopback', dest='tcloopback', action='store_true', help='testcase: loopback')
        p.add_argument('--tcuipattern', dest='tcuipattern', choices=['0','2','20','40','80'], default=None, required=False, help='testcase: 2,20,40,80 UI square wave pattern')

        args = p.parse_args()
        usb  = UsbTools()
        jtag = JtagEngine(frequency=ArgHzParse(args.freq))

        if args.listdev:
            vps_lst = list()
            vps_lst.append((0x0403, 0x6010)) # evb: FT2232H
            vps_lst.append((0x0403, 0x6014)) # pgm: FT232H
            for line in usb.find_all(vps=vps_lst):
                print(*line)
            sys.exit()

        s = SerdesTool(args, jtag, hwinit=not args.genmod)

        if args.genmod is not None:
            filename = args.genmod.lower()
            if filename.endswith('.v') or filename.endswith('.sv'):
                s.gen_module_vlog(filename)
            elif filename.endswith('.vhd') or filename.endswith('.vhdl'):
                s.gen_module_vhdl(filename)
            sys.exit()

        if args.gui:
            update_thread = threading.Thread(target=s.update_values, daemon=True)
            update_thread.start()
            curses.wrapper(s.draw_parameters)
        else:
            if args.tcprbs:
                s.tc_prbs(force_err=True)
            if args.tcloopback:
                s.tc_loopback()
            if args.tcuipattern is not None:
                s.tc_uipattern(int(args.tcuipattern))
            if args.rdregrx:
                s.rd_regfile_rx(verbose=2)
            if args.rdregrxdata:
                s.print_regfile_rx_data(verbose=2)
            if args.rdregtx:
                s.rd_regfile_tx(verbose=2)
            if args.rdregpll:
                s.rd_regfile_pll(verbose=2)
            if args.rdstatuspll:
                [s._tool.rd_status_pll(pll=i, verbose=1) for i in range(4)]

    except Exception as e:
        print(e)