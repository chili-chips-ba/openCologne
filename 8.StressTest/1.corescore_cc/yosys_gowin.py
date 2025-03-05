#--------------------------------------------------------------
#python script to run yosys vs gowin synth testing on corescore
#--------------------------------------------------------------

import yaml
import subprocess
import shutil
import os

# Load the YAML file
input_file = "./fusesoc_libraries/corescore/corescore.core"
yosys_log_dir = "./yosys_logs"
gowin_src_dir = "./gowin/gowin_corescore/src/"
gowin_rpt_dir = "./gowin_rpt"
os.makedirs(yosys_log_dir, exist_ok=True)
os.makedirs(gowin_rpt_dir, exist_ok=True)

with open(input_file, "r") as f:
    data = yaml.safe_load(f)

# Ensure the structure exists
if "targets" in data and "gowin_yosys" in data["targets"]:
    for count in range(1, 51):
        data["targets"]["gowin_yosys"]["generate"] = [{"corescorecore": {"count": count}}]
        
        # Save modifications back to the same file
        with open(input_file, "w") as f:
            yaml.dump(data, f, default_flow_style=False)
        print(f"Updated count to {count}")
        
        # Run fusesoc command
        subprocess.run(["fusesoc", "run", "--target=gowin_yosys", "corescore"], check=True)
        
        # Copy yosys log file
        source_log = "./build/corescore_0/gowin_yosys-yosys/yosys.log"
        destination_log = os.path.join(yosys_log_dir, f"log_{count}")
        if os.path.exists(source_log):
            shutil.copy(source_log, destination_log)
            print(f"Copied {source_log} to {destination_log}")
        else:
            print(f"Warning: {source_log} not found, skipping copy.")
        
        # Copy corecore-corecorecore_0 folder
        source_folder = "./build/corescore_0/gowin_yosys-yosys/src/corescore-corescorecore_0"
        destination_folder = os.path.join(gowin_src_dir, "corescore-corescorecore_0")
        if os.path.exists(source_folder):
            if os.path.exists(destination_folder):
                shutil.rmtree(destination_folder)
            shutil.copytree(source_folder, destination_folder)
            print(f"Copied {source_folder} to {destination_folder}")
        else:
            print(f"Warning: {source_folder} not found, skipping copy.")
        
        # Run Gowin script
        os.chdir("gowin")
        subprocess.run(["gw_sh", "gowin.tcl"], check=True)
        os.chdir("..")
        
        # Copy Gowin synthesis report
        source_rpt = "./gowin/gowin_corescore/impl/gwsynthesis/gowin_corescore_syn.rpt.html"
        destination_rpt = os.path.join(gowin_rpt_dir, f"gowin_corescore_syn_rpt_{count}.html")
        if os.path.exists(source_rpt):
            shutil.copy(source_rpt, destination_rpt)
            print(f"Copied {source_rpt} to {destination_rpt}")
        else:
            print(f"Warning: {source_rpt} not found, skipping copy.")
else:
    print("Error: Required target structure not found in YAML file.")


