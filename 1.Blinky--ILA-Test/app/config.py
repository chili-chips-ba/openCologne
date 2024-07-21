#################################################################################################
#    << CologneChip GateMate ILA control program (ILAcop) - config >>                           #
#    In this section, all relevant constants for the runtime of ILAcop are defined.             #
#    These constants influence the configuration and communication of the gateware.             #
# ********************************************************************************************* #
#    Copyright (C) 2023 Cologne Chip AG <support@colognechip.com>                               #
#    Developed by Dave Fohrn                                                                    #
#                                                                                               #
#    This program is free software: you can redistribute it and/or modify                       #
#    it under the terms of the GNU General Public License as published by                       #
#    the Free Software Foundation, either version 3 of the License, or                          #
#    (at your option) any later version.                                                        #
#                                                                                               #
#    This program is distributed in the hope that it will be useful,                            #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#    GNU General Public License for more details.                                               #
#                                                                                               #
#    You should have received a copy of the GNU General Public License                          #
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.                     #
#                                                                                               #
# ********************************************************************************************* #
#################################################################################################

#YOSYS = 'yosys'
YOSYS = '/home/user/FPGA/Boards/GateMate/cc-toolchain-linux/bin/yosys/yosys'
YOSYS_FLAGS = '-nomx8'
PR = 'p_r'
PR_FLAGS = '-sp -cCP +uCIO ' # The removal of the +uCIO flag is not permissible. The ccf file is automatically appended
UPLOAD = 'openFPGALoader'
#UPLOAD = '/home/user/FPGA/tools/openFPGALoader/build/openFPGALoader'
UPLOAD_FLAGS = ' -b olimex_gatemateevb ' # gatemate_evb_jtag,  olimex_gatemateevb
REPRESENTATION_SOFTWARE = ['gtkwave']
REPRESENTATION_FLAGS = ['--save', 'save.gtkw']
CON_DEVICE = 'oli' # GateMate Evaluation Board = 'evb', GateMate Programmer = 'pgm', Olimex = 'oli'  freely customisable mode = 'cust', without leveshifter 'free'
CON_LINK = 'ftdi://ftdi:2232h/1' # evb = 'ftdi://ftdi:2232h/1', pgm = 'ftdi://ftdi:232h/1',
available_BRAM = 60
freq_max = 10000000     # Maximum SPI communication frequency for interfacing with the ILA gateware.
cust_gpio_direction_pins = 0x17F0
cust_gpio_direction = 0x1710
cust_gpio_write = 0x0210
# dirty JTAG config
DIRTYJTAG_CMD = {"CMD_STOP" : 0x00, "CMD_INFO" : 0x01,
                  "CMD_FREQ" : 0x02, "CMD_XFER" : 0x03,
                  "CMD_SETSIG": 0x04, "CMD_GETSIG" : 0x05, "CMD_CLK" : 0x06 }
DIRTYJTAG_VID = 0x1209
DIRTYJTAG_PID = 0xC0CA

DIRTYJTAG_SIG = {
    "SIG_TCK" : 1 << 1,
    "SIG_TDI" : 1 << 2,
    "SIG_TDO" : 1 << 3,
    "SIG_TMS" : 1 << 4,
    "SIG_TRST" : 1 << 5,
    "SIG_SRST" : 1 << 6
}
DIRTYJTAG_TIMEOUT = 1000

DIRTYJTAG_WRITE_EP = 0x01
DIRTYJTAG_READ_EP = 0x82

JTAG_freg = 6000000


def print_table(word, table):
    table_string = table.get_string()
    max_width = max(len(line) for line in table_string.splitlines())
    half_width = (max_width - len(word)) // 2
    remaining_width = max_width - half_width - len(word)
    result_string = '-' * half_width + word + '-' * remaining_width
    print(result_string)
    print(table)

def print_note(text_g, string_m =" CONFIGURATION NOTE ", character='#'):
    import os
    max_range = max(len(s) for s in text_g)
    if max_range < 41:
        max_range = 41
    text = ""
    for s in text_g:
        text += character + " " + s.ljust(max_range) + " " + character + os.linesep
    frame = character * (
            max_range + 4)
    le = ' ' * (max_range + 2)
    m_haupt = len(frame) // 2
    m_part = len(string_m) // 2
    start_pos = m_haupt - m_part
    end_pos = start_pos + len(string_m)
    start_str = frame[:start_pos] + string_m + frame[end_pos:]
    return f"{os.linesep}{start_str}{os.linesep}{character}{le}{character}{os.linesep}{text}{character}{le}{character}{os.linesep}{frame}{os.linesep}"