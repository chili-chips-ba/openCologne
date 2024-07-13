#################################################################################################
#    << CologneChip GateMate ILA control program (ILAcop) - RuntimeInteractionManager >>        #
#    This program handles the interaction of the user with the ILA gateware.                    #
#    at runtime!                                                                                #
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

import sys, os, argparse
from pathlib import Path
from vcd import VCDWriter
import datetime
from communication import Communication
import subprocess
import traceback, threading
from prettytable import PrettyTable
from config import print_note
from config import print_table

def positiv_int(x):
    x = int(x)
    if x <= 0:
        raise argparse.ArgumentTypeError("Invalid value, it must be a positive integer.")
    return x


def get_ch():
    try:
        if os.name == 'nt':  # for Windows
            import msvcrt
            zt = msvcrt.getch().decode('utf-8')
            if ord(zt) == 8:
                return -1
            return zt
        else:  # for Unix (Linux, MacOS, etc.)
            import termios
            import tty
            fd = sys.stdin.fileno()
            old_settings = termios.tcgetattr(fd)
            try:
                tty.setraw(sys.stdin.fileno())
                ch = sys.stdin.read(1)
                if ord(ch) == 127:
                    return -1
                if ord(ch) == 13:
                    ch = '\n'
            finally:
                termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
            return ch
    except Exception as exception:
        print(exception)
        traceback.print_exc()
        return '\n'


def get_input_number(user_output, number_range):
    while 1:
        try:
            usr_in = input(user_output)
            if usr_in == 'e' or usr_in == 'p':
                return False, usr_in
            else:
                return_number = int(usr_in)
            if 0 <= return_number < number_range:
                return True, return_number
            else:
                print("Entered number out of range")
        except:
            print(print_note(["Invalid input. Please enter a valid int value.",
             "Entering 'e' exits the process",
             "Enter 'p' for 'previous' to backtrack a step."
             ],
            " Input ERROR ", '!'))



def openGTKWave(file_name):
    from config import REPRESENTATION_SOFTWARE, REPRESENTATION_FLAGS
    cmd_array = REPRESENTATION_SOFTWARE + [file_name] + REPRESENTATION_FLAGS
    save_dir = os.getcwd()
    save_gl_dir = os.path.dirname(save_dir)
    with open(save_gl_dir + 'waveviewer.log', 'w') as output:
        subprocess.run(cmd_array, stdout=output, stderr=output)


class RuntimeInteractionManager:
    menu_options = ['exit', 'change Trigger', 'start capture',
                    'reset ILA (resets the config of the ILA)']
    trigger = 0         # Trigger Signal Index
    activation = 0      # trigger activation
    trigger_activations = ['falling edge', 'rising edge']
    number_of_iteration = 1
    count_samples = [0, 0]   # [count_samples_before_trigger, count_samples_after_trigger]
    count_samples_total = 0
    signal_names = []
    trigger_iter = [0]
    signal_count = 0
    status = 0
    bytes_per_sample = 0
    bytes_per_msg = 0
    all_signal_names = []
    delta_time_ps = 0           # Time between two samples in picoseconds.
    project_name = ''
    trigger_pattern = ""
    trigger_mask = ""
    const_trigger_all = [{"activation": 0b00000000,
                             "trigger": (0b10010000, 0), "trigger_clear": 0,
                             "pattern_msg": None, "trigger_act": 0}]

    def __init__(self, an_freq=40000000, smp_before=100, smp_after=1000, signale=[], project_name = "test",
                 with_pattern=False, bram_single_wide = 5, bram_matrix_wide = 1, use_reset_function = False):
        self.use_reset_function = use_reset_function
        if self.use_reset_function:
            self.menu_options.append('reset DUT (hold the DUT in reset until the capture starts)')
        self.trigger_all = self.const_trigger_all
        self.project_name = project_name
        self.analysis_frequency = an_freq
        self.count_samples[0] = smp_before
        self.count_samples[1] = smp_after
        self.with_patter = with_pattern
        self.bram_single_wide = bram_single_wide
        self.bram_matrix_wide = bram_matrix_wide
        self.sort_signals(signale)
        if self.with_patter:
            self.trigger_activations.append('pattern')
        self.status = 1
        self.count_samples_total = self.count_samples[0] + self.count_samples[1]
        self.nibbles_per_sample = int(self.signal_count / 4) + int((self.signal_count % 4) > 0)
        self.nibbles_per_msg = self.count_samples_total * self.nibbles_per_sample
        self.bytes_per_msg = (self.nibbles_per_msg / 2) + (self.nibbles_per_msg % 2)
        self.delta_time_ps = int((10 ** 12) / self.analysis_frequency)               # 1 ps
        self.com = Communication(self.bytes_per_msg, self.analysis_frequency)
        self.trigger_pattern = '1' * self.signal_count
        self.trigger_mask = '1' * self.signal_count


    def sort_signals(self, signal_array):
        for signal in signal_array:
            try:
                if signal[1] == 1:
                    self.all_signal_names.append(signal[0])
                elif signal[1] > 1:
                    for signal_count in range(signal[1]):
                        self.all_signal_names.append(signal[0] + "[" + str(signal_count) + "]")
                else:
                    print("wrong Input: " + signal)
                    exit()
                self.signal_names.append([signal[0], signal[1], ""])
                self.signal_count = self.signal_count + signal[1]
            except Exception as exception:
                print("wrong Input: " + signal)
                print(exception)
                traceback.print_exc()
                exit()

    def run(self):
        print(print_note(["Trigger at sample no.: " + str(self.count_samples[0]-9),
                                "Defined analysis frequency: " + str(self.analysis_frequency) + " Hz"]))
        while True:
            try:
                self.print_menu()
                print()
                try:
                    input_entered = input('Enter your choice: ')
                    option = int(input_entered)
                except Exception as exception:
                    print(os.linesep + "wrong Input!")
                    #print(exception)
                    traceback.print_exc()
                    continue
                if option == 0:
                    print('Thank You and Good Bye!')
                    exit()
                elif option == 1:
                    self.change_trigger_config()
                elif option == 2:
                    self.get_signals()
                    self.com.send_reset_ila()
                elif option == 3:
                    self.com.send_reset_ila()
                    self.trigger_all = self.const_trigger_all
                    self.trigger_mask =  '1' * self.signal_count
                elif option == 4 and self.use_reset_function:
                    self.com.reset_DUT()
                else:
                    print(os.linesep + "Value out of range")
                    continue
            except Exception as exception:
                print(exception)
                traceback.print_exc()
                exit()



    def change_pattern(self):
        self.print_signals_test()
        self.trigger_mask = ""
        self.trigger_pattern = ""
        print(print_note(["Define the Bit-Pattern for Trigger Activation",
                                "Set individual bits using '0' and '1'",
                                "Set up a hex pattern using the key 'h' followed by hex values",
                                "skip an indirect number of signals with ‘j’",
                                "set all remaining signals to dont care with 'r'",
                                "all other inputs set a single signal to dc"], " Pattern as trigger ", "!"))

        enter = '\r' if os.name == 'nt' else '\n'
        fill = False
        index_names = 0
        while index_names < len(self.all_signal_names):
            if not fill:
                print(str(index_names) + " = " + self.all_signal_names[index_names] + ": ", end="", flush=True)
                c = get_ch()
                if c == -1:
                    print()
                    if index_names > 0:
                        index_names = index_names - 2
                        self.trigger_mask = self.trigger_mask[1:]
                        self.trigger_pattern = self.trigger_pattern[1:]
                    else:
                        index_names = index_names - 1
                elif c in ['0', '1']:
                    self.trigger_mask = '0' + self.trigger_mask
                    self.trigger_pattern = c + self.trigger_pattern
                    print(c)
                elif c == 'h':
                    print(c, end="", flush=True)
                    hex_string = ""
                    while c != enter:
                        c = get_ch()
                        char_cnt = len(hex_string)
                        if c == -1:
                            if char_cnt > 0:
                                print('\b \b', end='', flush=True)
                                hex_string = hex_string[:-1]
                        elif c in '0123456789abcdefABCDEF':
                            print(c, end="", flush=True)
                            hex_string += c
                        elif char_cnt > 0 and c == enter:
                            binary_string = (bin(int(hex_string, 16))[2:]).zfill(char_cnt*4)
                            fill = True
                            print(os.linesep + str(index_names) + " = " + self.all_signal_names[index_names] + ": " + binary_string[-1])
                            self.trigger_mask = '0' + self.trigger_mask
                            self.trigger_pattern = binary_string[-1] + self.trigger_pattern
                            binary_string = binary_string[:-1]
                elif c == "j":
                    print(c, end="", flush=True)
                    jmp_string = ""
                    while c != enter:
                        c = get_ch()
                        char_cnt = len(jmp_string)
                        if c == -1:
                            if char_cnt > 0:
                                print('\b \b', end='', flush=True)
                                jmp_string = jmp_string[:-1]
                        elif c in '0123456789':
                            print(c, end="", flush=True)
                            jmp_string += c
                        elif char_cnt > 0 and c == enter:
                            jmp_cnt = int(jmp_string)
                            index_names += (jmp_cnt-1)
                            self.trigger_mask = '1' * jmp_cnt + self.trigger_mask
                            self.trigger_pattern = '1' * jmp_cnt + self.trigger_pattern
                            print()


                elif c == "r":
                    self.trigger_mask = self.trigger_mask.rjust(len(self.all_signal_names), '1')
                    self.trigger_pattern = self.trigger_pattern.rjust(len(self.all_signal_names), '1')
                    break
                else:
                    self.trigger_mask = '1' + self.trigger_mask
                    self.trigger_pattern = '1' + self.trigger_pattern
                    print(c)
            else:
                print(str(index_names) + " = " + self.all_signal_names[index_names] + ": " + binary_string[-1])
                self.trigger_mask = '0' + self.trigger_mask
                self.trigger_pattern = binary_string[-1] + self.trigger_pattern
                binary_string = binary_string[:-1]
                if len(binary_string) == 0:
                    fill = False
            index_names = index_names + 1
        extra_bits = 4 - (self.signal_count % 4) if (self.signal_count % 4) != 0 else 0
        send_trigger_mask = '0' * extra_bits + self.trigger_mask
        send_trigger_pattern = '0' * extra_bits + self.trigger_pattern
        send_string = ""
        for i in range(0, len(send_trigger_mask), 4):
            send_string += send_trigger_mask[i:i + 4] + send_trigger_pattern[i:i + 4]
        print(os.linesep)
        change_trigger_pattern = [0b00110011] + [int(send_string[i:i + 8], 2) for i in range(0, len(send_string), 8)]
        #self.com.send_msg(change_trigger_pattern)
        return change_trigger_pattern



    def change_trigger_config(self):
            print(print_note(["Select how many triggers are set directly in succession.",
                              "For each iteration you can select a separate trigger.",
                              "Entering 'e' exits the process",
                              "Enter 'p' for 'previous' to backtrack a step."],
                             " Trigger configuration "))
            step = 0
            all_in = False
            iteration = 1
            count = 0
            while not all_in:
                pattern_msg = None
                try:
                    if step == 0:
                        self.trigger_all = []
                        self.trigger_mask =  '1' * self.signal_count
                        usr_in = input(os.linesep + 'Number of sequences (int, > 0): ')
                        if usr_in == 'e':
                            self.trigger_all = self.const_trigger_all
                            self.trigger_mask =  '1' * self.signal_count
                            return
                        elif usr_in == 'p':
                            continue
                        else:
                            iteration = int(usr_in)
                            if iteration < 1:
                                print("please define a value greater than zero.")
                                continue
                            else:
                                step += 1
                    else:
                        if (step % 2) == 1:
                                print(os.linesep + "###  sequence nr. " + str(count+1) + ": ###")
                                state_in, usr_in = self.change_trigger_activation()
                                if state_in:
                                    trigger_act = usr_in
                        else:
                            if trigger_act == 2:
                                pattern_msg = self.change_pattern()
                                trigger_send = (0b10010000, 0b00000000)
                                trigger = [self.trigger_pattern, self.trigger_mask]
                                state_in = True
                            else:
                                self.print_signals_test()
                                state_in, usr_in = get_input_number(
                                    'Trigger signal? in range [0-' + str(self.signal_count - 1) + ']: ',
                                    self.signal_count)
                                if state_in:
                                    trigger = int(usr_in)
                                    trigger_row = int(trigger / self.bram_single_wide)
                                    trigger_column = trigger % self.bram_single_wide
                                    trigger_send = ((0b10010000 | (trigger_row >> 2)),
                                                    (((trigger_row & 0x3) << 6) | (trigger_column & 0x3F)))
                            if state_in:
                                self.trigger_all.append({"activation" : ((trigger_act << 4) & 0xFF) ,
                                                         "trigger" :  trigger_send, "trigger_clear":trigger,
                                                         "pattern_msg" : pattern_msg, "trigger_act" : trigger_act})
                                count += 1
                        if usr_in == 'e':
                            self.trigger_all =  self.const_trigger_all
                            self.trigger_mask = '1' * self.signal_count
                            return
                        elif usr_in == 'p':
                            if (step % 2) == 1:
                                if count > 0:
                                    count -= 1
                                    self.trigger_all.pop()
                            step -= 1
                        else:
                            if (step / 2) == iteration:
                                all_in = True
                            else:
                                step += 1


                except Exception as exception:
                    traceback.print_exc()
                    print(print_note(["Invalid input. Please enter a valid int value.",
                                      "Entering 'e' exits the process.",
                                      "Enter 'p' for 'previous' to backtrack a step."
                                      ],
                                     " Input ERROR ", '!'))



    def get_signals(self):
        signals, t = self.com.read_spi(self.trigger_all)
        now = datetime.datetime.now()
        time_stamp = now.strftime("%y-%m-%d_%H-%M-%S")
        for runs, signals_seq in enumerate(signals):
            file_name = "vcd_files/ila_" + self.project_name + "_" + time_stamp + "_" + str(runs) + ".vcd"
            self.creatVCD(signals_seq, file_name)
            self.thread = threading.Thread(target=openGTKWave, args=(file_name,))
            self.thread.daemon = True
            self.thread.start()
        if t.is_alive():
            print(os.linesep + "Press Enter to continue")
            while t.is_alive():
                continue


    def change_trigger_activation(self):
        # change Trigger activation
        print(os.linesep + "All possible Trigger activations:")
        for counter, names in enumerate(self.trigger_activations):
            print(str(counter) + ": \t" + names)
        return get_input_number(os.linesep + 'Trigger activation? in range [0-' + str(len(self.trigger_activations) - 1) +
                                     ']: ', len(self.trigger_activations))

    def print_menu(self):
        self.print_signals_test()
        notes = ["Number of sequences: " + str(len(self.trigger_all))]
        for count, trig_set in enumerate(self.trigger_all):
            notes.append("")
            notes.append(" Sequences Number: " + str(count+1))
            notes.append("    trigger activation: " + self.trigger_activations[(trig_set["trigger_act"] & 0x0F)])
            if trig_set["trigger_act"] == 2:
                print_pattern = "|"
                for pattern_bit in range(len(self.all_signal_names)):
                    if trig_set["trigger_clear"][1][pattern_bit] == '1':
                        print_pattern = "|DC" + print_pattern
                    else:
                        print_pattern = "| " + str(trig_set["trigger_clear"][0][pattern_bit]) + print_pattern
                print_pattern = "    trigger patter: " + print_pattern
                notes.append(print_pattern)
            else:
                notes.append("    trigger signal:     " + str(self.all_signal_names[trig_set["trigger_clear"]]))


        print(print_note(notes,
                         " current ILA runtime configuration "))
        print(os.linesep)
        for count in range(len(self.menu_options)):
            out_str = str(count) + ' -- ' + self.menu_options[count]
            print(out_str)


    def print_signals_test(self):
        word = " All Signals "
        table = PrettyTable()
        if self.with_patter:
            table.field_names = ["#", "Name", "Pattern"]
            for counter, names in enumerate(self.all_signal_names, start=1):
                if self.trigger_mask[len(self.all_signal_names) - counter] == '1':
                    table.add_row([(counter - 1), names, "dc"])
                else:
                    table.add_row([(counter-1), names, self.trigger_pattern[len(self.all_signal_names) - counter]])
        else:
            table.field_names = ["#", "Name"]
            for counter, names in enumerate(self.all_signal_names):
                table.add_row([counter, names])
        for field in table.field_names:
            table.align[field] = "r"
        print()
        print_table(word, table)


    def creatVCD(self, byte_arr, file_name):
        print(print_note([file_name],
                         " create vcd file "))
        pathname = os.path.dirname(sys.argv[0])
        path = os.path.abspath(pathname) + "/" + file_name
        file = Path(path)
        writer_signals = []
        with open(file, "w") as f:
            with VCDWriter(f, timescale='1 ps', date='today') as writer:  # notes
                for x in range(len(self.signal_names)):
                    writer_signals.append(writer.register_var('ILA_Signals', self.signal_names[x][0], 'reg',
                                                              size=self.signal_names[x][1]))
                counter_var = writer.register_var('ILA_Signals', 'smp_cnt_ILA', 'integer',
                                                      size=(self.count_samples_total.bit_length() + 1))
                nibbles = []
                start = True
                for bytes in byte_arr:
                    nibble_2 = bytes & 0x0F
                    nibble_1 = (bytes & 0xF0) >> 4
                    if start:
                        if (nibble_1 & 0xF) == 0b1110:
                            start = False
                            nibbles.append(nibble_2)
                        elif (nibble_2 & 0xF) == 0b1110:
                            start = False
                    else:
                        nibbles.append(nibble_1)
                        nibbles.append(nibble_2)

                z = 0
                if len(nibbles) < self.nibbles_per_msg:
                    print("Error during data transmission. The signals may not be recoded correctly. "
                          "confirm with enter to continue.")
                    input()
                    nibbles += ([0b0000] * (self.nibbles_per_msg - len(nibbles) + 1))

                samp_arr = []
                for y in range(self.count_samples_total):
                    samp_arr.append(0)
                    for x in range(self.nibbles_per_sample):
                        samp_arr[y] |= (nibbles[z] << (4 * x))
                        z += 1


                samp_arr = samp_arr[-1:] + samp_arr[:-1]
                for sample_counter in range(len(samp_arr)):  # go through all samples
                    bit_counter = 0
                    for signal_name_index in range(len(self.signal_names)):  # go through all defined signals and vectors
                        self.signal_names[signal_name_index][2] = ""
                        for _ in range(self.signal_names[signal_name_index][1]):
                            self.signal_names[signal_name_index][2] = str((samp_arr[sample_counter] >> bit_counter ) & 1) + \
                                                      self.signal_names[signal_name_index][2]
                            bit_counter = bit_counter + 1
                        writer.change(writer_signals[signal_name_index], self.delta_time_ps * sample_counter, self.signal_names[signal_name_index][2])
                    writer.change(counter_var, self.delta_time_ps * sample_counter, sample_counter)
                    if sample_counter == (self.count_samples_total - 1): # add one more, for better representation
                        for signal_name_index in range(len(self.signal_names)):  # go through all defined signals and vectors
                            writer.change(writer_signals[signal_name_index], self.delta_time_ps * (sample_counter + 1), self.signal_names[signal_name_index][2])
                        writer.change(counter_var, self.delta_time_ps * (sample_counter + 1), (sample_counter + 1))
