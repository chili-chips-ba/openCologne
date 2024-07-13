import argparse, os, sys
from argparse import RawTextHelpFormatter
from RuntimeInteractionManager import RuntimeInteractionManager
from ILAConfig import ILAConfig
from pyftdi.ftdi import Ftdi
from config import print_note

__version__ = '1.1.0'
actions = ['config', 'reconfig', 'start']
ArgEpilog ='''
example usage:
python3 ILAcop.py [Commands]

Commands:
  config:   Configure the ILA.
             -vlog SOURCE    Paths to the Verilog source code files.
             -vhd SOURCE     Paths to the VHDL source code files.
             -t NAME         Top level entity of the design under test.
             -ccf SOURCE     Folder containing the .ccf file of the design under test. 
             -f MHz          Defines the external clock frequency in MHz (default is 10.0 MHz).
             -sync LEVEL     Number of register levels via which the SUT are synchronised.
             -d DELAY        ILA PLL Phase shift of sampling frequency. 0=0°, 1=90°, 2=180°, 3=270° (default: 2).
             -opt            Optimizes the design by deleting all unused signals before design evaluation.
          (optional) Subcommands config: 
                -create_json: Creates a JSON file in which the logic analyzer can be configured.
            NOTE: Without the subcommand the configurations are requested step by step via the terminal.
  
  reconfig: Configures the ILA based on a JSON file. With this option you have to specify a JSON file with -l [filename].json.
  
  start     Starts the communication to the ILA with the last uploaded config

'''
p = argparse.ArgumentParser(prog='ILAcop.py', description='GateMate ILA control program. With this script, '
                            'you can configure and execute the ILA with a design under test (DUT).',
                            epilog=ArgEpilog, formatter_class=RawTextHelpFormatter)
p.add_argument('--version', action='version', version='%(prog)s ' + __version__)
p.add_argument('--clean', dest='clean', action='store_true', help='Deletes all output files created by the program.')
p.add_argument('--showdev', dest='showdev', action='store_true', help='Outputs all found FTDI ports.')

Modes_delay = [0,1,2,3]


p.add_argument('-wd', dest='work_dir', type=str, required=False,
                                   help='Folder from which Yosys should be started for the synthesis of the Design Under Test.')

main_actions = p.add_subparsers(title="main_actions", dest='main_action')

main_actions_config_parser = main_actions.add_parser(actions[0])


main_actions_config_parser.add_argument('-create_json', dest='create_json', action='store_true', help='creates a JSON '
                                                    'file in which the logic analyzer can be configured afterwards')

group = main_actions_config_parser.add_mutually_exclusive_group(required=True)
group.add_argument('-vlog', dest='verilog_source', nargs='+', type=str, required=False,
                                   help='paths to the folder containing the Verilog source code files')
group.add_argument('-vhd', dest='vhdl_source', nargs='+', type=str, required=False, help='paths to the folder '
                                                                                         'containing the '
                                                                                         'VHDL source code files')
main_actions_config_parser.add_argument('-t', dest='top', type=str, required=False,
                                        help='name of the top level entity of the design to be tested')
main_actions_config_parser.add_argument('-ccf', dest='ccf', type=str, required=False,
                                        help='Folder containing the .ccf file.')
main_actions_config_parser.add_argument('-f', dest="fsource", type=str, default="10.0",
                                        help="defines the external clock frequency in MHz as float")

main_actions_config_parser.add_argument('-d', dest='delay', type=int, metavar=Modes_delay, default=Modes_delay[2], required=False,
            help='Set the phase shift of the sampling frequency. 0 = 0°, 1 = 90°, 2 = 180° and 3 = 270° (default: 2).')


def positive_int(value):
    try:
        ivalue = int(value)
    except ValueError:
        raise argparse.ArgumentTypeError(f"{value} is an invalid integer value")

    if ivalue < 0:
        raise argparse.ArgumentTypeError(f"{value} is an invalid positive integer value")
    return ivalue


main_actions_config_parser.add_argument('-sync', dest='sync', type=positive_int, default=0, required=False,
               help='Determines the number of register levels via which the signals to be analysed are synchronised.')

main_actions_config_parser.add_argument('-opt', dest='opt', action='store_true', default=False, required=False,
               help='This optimizes the design by deleting all unused signals before signal evaluation.')

main_actions_reconfig_parser_start = main_actions.add_parser(actions[2])
main_actions_reconfig_parser_start.add_argument('-s', dest='swc', action='store_true', default=False, required=False,
                                                help='starts the ILA runtime environment without reconfiguring the FPGA')
main_actions_reconfig_parser_reconfig = main_actions.add_parser(actions[1])
main_actions_reconfig_parser_reconfig.add_argument('-l', dest='load', type=str, metavar='[filename].json', required=False,
               help='JSON file containing the configurations of the ILA')
args = p.parse_args()

lizenz = '''
#################################################################################################
#                   Cologne Chip GateMate ILA control program (ILAcop)                          #
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
'''

print(lizenz)

config_FPGA = True

if len(sys.argv) == 1:
    p.print_help(sys.stderr)
    exit()

if args.showdev:
    Ftdi.show_devices()
    exit()


req_dirs = ["../net/", "../log/", "save_config/", "../p_r_out/", "vcd_files/", "config_design/"]
for del_dir in req_dirs:
    if not os.path.isdir(del_dir):
        print("ERROR! Either the specified folder structure has not been adhered to, or you are not starting the "
              "programme from the 'app' folder. Please make sure that both conditions are fulfilled!")
        exit()

if args.clean:
    req_dirs = ["../net/", "../log/", "save_config/", "../p_r_out/", "vcd_files/", "config_design/"]
    for del_dir in req_dirs:
        for filename in os.listdir(del_dir):
            if ".gitkeep" not in filename:
                os.remove(os.path.join(del_dir, filename))
        print("All files in directory "+ del_dir +" deleted.")
    exit()

if args.main_action == actions[0]: # config
    ILA_config_instance = ILAConfig()
    ILA_config_instance.set_DUT_top(args.top)
    ILA_config_instance.set_external_clk_freq(args.fsource)
    ILA_config_instance.set_ILA_clk_delay(args.delay)
    ILA_config_instance.set_ILA_opt(args.opt)
    ILA_config_instance.set_sync_level(args.sync)
    # finding all Verilog files
    if args.verilog_source:
        ILA_config_instance.set_verilog(args.verilog_source)
        sources = args.verilog_source
    # finding all VHDL Files
    if args.vhdl_source:
        ILA_config_instance.set_VHDL(args.vhdl_source)
        sources = args.vhdl_source
    if args.ccf:
        ccf_found = ILA_config_instance.set_DUT_ccf(args.ccf)
    else:
        ccf_found = ILA_config_instance.set_DUT_ccf(sources[0])
    if not ccf_found:
        exit()
    if not ILA_config_instance.flat_DUT(args.work_dir):
        exit()
    code_lines = ILA_config_instance.get_DUT_flat_code()
    found_element = ILA_config_instance.parse_DUT(code_lines)

    if args.create_json:
        usr_in = ILA_config_instance.choose_clk_source(found_element["pll"])

        if usr_in == 'e':
            exit()
        usr_in = ILA_config_instance.choose_reset(found_element["reset"])
        if usr_in == 'e':
            exit()
        file_name = ILA_config_instance.save_to_json()
        print(print_note(["Edit configurations in the created .json file and start the configuration:",
                          "python3 ILAcop.py reconfig -l " + file_name], " Create json ", "#"))
        exit()
    else:
        set_correct = ILA_config_instance.user_config_loop(found_element["pll"], found_element["reset"])
        if not set_correct:
            file_name = ILA_config_instance.save_to_json()
            print(print_note(["Configurations for the DUT can be changed in: ",
                              file_name], " Create json ", "#"))
            exit()
        ILA_config_instance.create_DUT(code_lines, found_element)
        ILA_config_instance.set_config_ILA()


elif args.main_action == actions[1]: # reconfig
    file_name = args.load
    print(file_name)
    if file_name == None:
        with open("last_upload.txt", 'r') as file:
            content = file.read()
            if len(content) > 5:
                file_name = content
                ILA_config_instance, config_check = ILAConfig.load_from_json(content)
            else:
                print("No configuration file was found for the ILA!")
    elif not os.path.exists(file_name):
        print("ERROR! No correct file was passed!")
        exit()
    ILA_config_instance, config_check = ILAConfig.load_from_json(file_name)
    if not config_check:
        exit()
    if not ILA_config_instance.flat_DUT(args.work_dir):
        exit()
    code_lines = ILA_config_instance.get_DUT_flat_code()
    found_element = ILA_config_instance.parse_DUT(code_lines, False)
    total_size = ILA_config_instance.create_DUT(code_lines, found_element)
    if total_size == 0:
        print("!ERROR!")
        if total_size == 0:
            print("You must select at least one signal for analysis in the JSON file.")
        exit()
    usr_in = ILA_config_instance.choose_Capture_time(total_size)
    if usr_in in ['e', 'p']:
        exit()
    ILA_config_instance.set_config_ILA()


elif args.main_action == actions[2]: # start
    with open("last_upload.txt", 'r') as file:
        content = file.read()
        if len(content) > 5:
            file_name = content
            ILA_config_instance, config_check = ILAConfig.load_from_json(content)
        else:
            print("No configuration file was found for the ILA!")
    if args.swc:
        config_FPGA = False

else:
    p.print_help(sys.stderr)
    exit()

if args.main_action != actions[2]:
    if not ILA_config_instance.executing_toolchain():
        if args.main_action != actions[1]:
            file_name = ILA_config_instance.save_to_json()
            print(print_note(["An error has occurred.", "All configurations for the given DUT have been saved in the following JSON file: ", file_name], " Error ", "#"))
        else:
            print(print_note(["An error has occurred."], " Error ", "#"))

        exit()
    else:
        if args.main_action == actions[0]:
            file_name = ILA_config_instance.save_to_json()
            print(print_note([file_name], " Configuration File ", "#"))
        else:
            ILA_config_instance.save_to_json(file_name)
        with open("last_upload.txt", 'w') as file:
            file.write(file_name)


if config_FPGA:
    if not ILA_config_instance.upload():
        exit()

ILA_user = RuntimeInteractionManager(int(float(ILA_config_instance.ILA_sampling_freq_MHz) * 1000000),
                                     ILA_config_instance.samples_count_before_trigger,
                                     (2**ILA_config_instance.bits_samples_count) - ILA_config_instance.samples_count_before_trigger,
               ILA_config_instance.get_Signals_run(), ILA_config_instance.SUT_top_name, ILA_config_instance.sample_compare_pattern,
                                     ILA_config_instance.bram_single_wide, ILA_config_instance.bram_matrix_wide,
                                     ILA_config_instance.use_reset_fuction)
ILA_user.run()

