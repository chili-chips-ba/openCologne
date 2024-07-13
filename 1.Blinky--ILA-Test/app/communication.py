#################################################################################################
#    << CologneChip GateMate ILA control program (ILAcop) - communication >>                    #
#    This program controls the communication with the gateware of the ILA on the FPGA.          #
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

from pyftdi.ftdi import Ftdi
import io, threading, time
from contextlib import redirect_stdout
from pyftdi.spi import SpiController
from time import sleep
import re, os
import traceback
from config import print_note, CON_DEVICE, DIRTYJTAG_CMD, DIRTYJTAG_VID, DIRTYJTAG_PID, DIRTYJTAG_SIG, DIRTYJTAG_WRITE_EP, DIRTYJTAG_READ_EP, DIRTYJTAG_TIMEOUT, JTAG_freg
import usb.core
import usb.util
import sys

class ThreadWithReturnValue(threading.Thread):
    def __init__(self, group=None, target=None, name=None, args=(), kwargs={}):
        threading.Thread.__init__(self, group, target, name, args, kwargs)
        self._return = None

    def run(self):
        if self._target is not None:
            self._return = self._target(*self._args, **self._kwargs)

    def join(self, *args):
        threading.Thread.join(self, *args)
        return self._return


def interrupt_input():
    return input()


class Communication:
    def __init__(self, count_bytes, frequency):
        from config import CON_DEVICE
        self.count_bytes_all = int(count_bytes) + 15
        if CON_DEVICE == 'oli':
            self.dev = usb.core.find(idVendor=DIRTYJTAG_VID, idProduct=DIRTYJTAG_PID)
            if self.dev is None:
                raise ValueError("Gerät nicht gefunden")
            #self.dev.set_configuration()
            buf = bytearray([
                DIRTYJTAG_CMD["CMD_FREQ"],
                ((JTAG_freg // 1000) >> 8) & 0xff,
                (JTAG_freg // 1000) & 0xff,
                DIRTYJTAG_CMD["CMD_STOP"]
            ])
            try:
                self.dev.write(DIRTYJTAG_WRITE_EP, buf, DIRTYJTAG_TIMEOUT)
            except usb.core.USBError as e:
                print(f"setClkFreq: usb bulk write failed {e}")
                exit()
            sleep(0.1)
            self.toggle_clk(1, 0, 16)
            ret = self.send_msg([0b01100000])
            #hex_output = ' '.join(format(byte, '02x') for byte in ret)
            #print(f"Empfangene Daten (Hex): {hex_output}")
            #print()
            self.send_reset_ila()

        else:
            with io.StringIO() as buf, redirect_stdout(buf):
                Ftdi.show_devices()
                output = buf.getvalue()
            devices = re.findall(r'ftdi://\S+', output)
            if len(devices) <= 1:
                print("No device found!"+os.linesep+"To be able to use this programme, you have to connect an FTDI device.")
                print("Please connect a device and restart the programme")
            else:
                try:
                    ftdi = Ftdi()
                    ftdi.open_from_url(devices[0])
                    ftdi.reset()
                    ftdi.close()
                    spi = SpiController()
                    from config import CON_DEVICE, CON_LINK, freq_max
                    spi.configure(CON_LINK, turbo=True) # , turbo=True
                    if frequency >= freq_max:
                        self.port = spi.get_port(cs=0, freq=freq_max, mode=0)
                       #print("feq set to: " + str(freq_max))
                    else:
                        self.port = spi.get_port(cs=0, freq=frequency, mode=0)
                        #print("feq set to: " + str(frequency))
                    self.max_payload = spi.PAYLOAD_MAX_LENGTH
                    self.gpio = spi.get_gpio()
                    if CON_DEVICE == 'evb':
                        self.gpio.set_direction(pins=0x09F0, direction=0x0110)
                        self.gpio.write(0x0010)
                    elif CON_DEVICE == 'pgm':
                        self.gpio.set_direction(pins=0x17F0, direction=0x1710)
                        self.gpio.write(0x0210)
                    elif CON_DEVICE == 'cust':
                        from config import cust_gpio_direction_pins, cust_gpio_direction, cust_gpio_write
                        self.gpio.set_direction(pins=cust_gpio_direction_pins, direction=cust_gpio_direction)
                        self.gpio.write(cust_gpio_write)
                    self.paket_size = int(self.count_bytes_all / self.max_payload)
                    self.paket_rest = self.count_bytes_all % self.max_payload
                    sleep(0.1)
                    self.port.read(10)
                    reply = self.port.exchange(bytearray([0b01100110]), start = False, stop = False, duplex=True)
                    reply = self.port.exchange(bytearray([0b01100110]), duplex=True)
                    self.send_reset_ila()
                except Exception as exception:
                    print("connection failed")
                    print(exception)
                    print("All found FTDI devices:")
                    print(output)
                    traceback.print_exc()

    def send_reset_ila(self):
        trys = 0
        while True:
            if CON_DEVICE == 'oli':
                self.toggle_clk(1, 0, 8)
                self.toggle_clk(0, 0, 8)
            # answer = self.write_tdi(send_bytes, tdi_size)
            # self.toggle_clk(1, 0, 8)
            msg = bytearray([0b01100000])
            ret = self.send_msg(msg)
            if self.check_msg(msg[0], ret[0]):
                break
            else:
                if trys == 3:
                    print("Communication to the board has failed!")
                    print("Ensure that the board is properly connected and configured with the ILA.")
                    hex_output = ' '.join(format(byte, '02x') for byte in ret)
                    print("receive: " + hex_output)
                    hex_output = ' '.join(format(byte, '02x') for byte in msg)
                    print("send: " + str(hex_output))
                    print("press enter to try again!")
                    dummy = input()
                else:
                    time.sleep(0.1)
                    trys += 1
        return


    def write_tdi(self, tx, length):
        tx_cpy = bytearray(length)
        tx_cpy[:len(tx)] = tx
        tx_buf = bytearray(64)  # 62 Byte + 2 byte
        rx_arr = []
        tx_buf[0] = DIRTYJTAG_CMD["CMD_XFER"]
        tx_start_byte = 0

        while tx_start_byte < length:
            byte_to_send = min((length - tx_start_byte), 62) # 62 Bytes real_bit_len, 496
            if byte_to_send > 32:
                tx_buf[0] |= 0x40  # EXTEND_LENGTH
                tx_buf[1] = (byte_to_send*8) - 256
            else:
                tx_buf[0] &= ~0x40  # EXTEND_LENGTH
                tx_buf[1] = (byte_to_send*8)

            tx_buf[2:2 + byte_to_send] = tx_cpy[tx_start_byte:(byte_to_send + tx_start_byte)]
            try:
                ret = self.dev.write(DIRTYJTAG_WRITE_EP, tx_buf[:(byte_to_send + 2)], DIRTYJTAG_TIMEOUT)
                if ret < byte_to_send:
                    byte_to_send = ret
                    print("ERROR different sizes by: " + str(tx_start_byte))


            except usb.core.USBError as e:
                print(f"writeTDI: fill: usb bulk write failed {e}")
                return -1

            transfer_length = byte_to_send if byte_to_send > 32 else 32
            
            while True:
                try:
                    ret = self.dev.read(DIRTYJTAG_READ_EP, transfer_length, DIRTYJTAG_TIMEOUT)
                    if len(ret) > 0:
                        #hex_output = ' '.join(format(byte, '02x') for byte in ret)
                        #print(f"Empfangene Daten (Hex): {hex_output}")
                        #print("empfangen größe = " + str(len(ret)))
                        rx_arr += ret[:byte_to_send]
                        break
                except usb.core.USBError as e:
                    print(f"writeTDI: read: usb bulk read failed {e}")
                    return -1
                
            tx_start_byte += byte_to_send

        return rx_arr

    def cmd_set_signal(self, signals, values):
        buf = bytearray([
            DIRTYJTAG_CMD["CMD_SETSIG"],
            (signals & 0xFF),
            (values & 0xFF),
            DIRTYJTAG_CMD["CMD_STOP"]
        ])
        try:
            self.dev.write(DIRTYJTAG_WRITE_EP, buf, DIRTYJTAG_TIMEOUT)
        except usb.core.USBError as e:
            print(f"toggleClk: usb bulk write failed {e}")
            return -1


    def toggle_clk(self, tms, tdi, clk_len):
        while clk_len > 0:
            buf = [
                DIRTYJTAG_CMD["CMD_CLK"],
                ((DIRTYJTAG_SIG["SIG_TMS"] if tms else 0) | (DIRTYJTAG_SIG["SIG_TDI"] if tdi else 0)),
                min(clk_len, 64),
                DIRTYJTAG_CMD["CMD_STOP"]
            ]

            try:
                self.dev.write(DIRTYJTAG_WRITE_EP, buf, DIRTYJTAG_TIMEOUT)
            except usb.core.USBError as e:
                print(f"toggleClk: usb bulk write failed {e}")
                return -1

            clk_len -= buf[2]


        return 0


    def reset_FPGA(self):
        from config import CON_DEVICE
        if CON_DEVICE == 'evb':
            self.gpio.write(0x0000)
            sleep(0.01)
            self.gpio.write(0x0010)
            sleep(0.01)
        elif CON_DEVICE == 'pgm':
           self.gpio.write(0x0010)
           sleep(0.01)
           self.gpio.write(0x0210)
           sleep(0.01)
        elif CON_DEVICE == 'oli':
            self.cmd_set_signal(DIRTYJTAG_SIG["SIG_SRST"], 0)
            sleep(0.01)
            self.cmd_set_signal(DIRTYJTAG_SIG["SIG_SRST"], DIRTYJTAG_SIG["SIG_SRST"])
        



    def send_msg(self, send_bytes, tdi_size = None):
        if CON_DEVICE == 'oli':
            if tdi_size is None:
                tdi_size = len(send_bytes)
            #self.toggle_clk(0, 0, 8)
            answer = self.write_tdi(send_bytes, tdi_size)
            #self.toggle_clk(1, 0, 8)
            return answer
        else:
            return self.port.exchange(send_bytes, duplex=True)


    def check_msg(self, send, reply):
        lower_4_bits_reply = reply & 0x0F
        upper_4_bits_send = (send & 0xF0) >> 4
        if lower_4_bits_reply != upper_4_bits_send:
            return False
        else:
            return True
#

    def read_spi(self, trigger):
        t = ThreadWithReturnValue(target=interrupt_input)
        t.start()
        print(print_note(["Waiting for device. Press Enter to interrupt."],
                         " start Capture "))
        answer_all = []
        times_mess = []
        for seq, trig in enumerate(trigger):
            if trig["pattern_msg"] is not None:
                self.send_msg(trig["pattern_msg"])
            send_msg_m = list(trig["trigger"]) + [trig["activation"]]

            self.send_msg(list(send_msg_m))
            start_time = time.perf_counter()
            while 1:
                received = self.send_msg([0b00000000])
                if int(received[0]) == 170:
                    rec_time = time.perf_counter()
                    times_mess.append((rec_time - start_time))
                    start_time = rec_time
                    if CON_DEVICE == 'oli':
                        answer_all.append(self.send_msg([0b00001100], self.count_bytes_all))
                    else:
                        answer = self.port.exchange(bytearray([0b00001100]), int(self.paket_rest))
                        for read_package in range(self.paket_size):
                            answer = answer + self.port.read(self.max_payload)
                        answer_all.append(answer)
                    break
                elif not t.is_alive():
                    print(print_note(["Stopped by sequence number: " + str(seq)], "user capture stop"))
                    return answer_all, t
            self.send_reset_ila()
        output_time = ["Duration between start and first trigger: " + str(round(times_mess[0], 6)) + " s"]
        times_mess.pop(0)
        for times_m in times_mess:
            output_time.append(("Duration until the next triggering of the trigger: " + str(round(times_m, 6)) + " s"))
        print(print_note(output_time, " Duration between captures "))
        return answer_all, t



    def reset_DUT(self):
        return self.send_msg([0b10100000])



