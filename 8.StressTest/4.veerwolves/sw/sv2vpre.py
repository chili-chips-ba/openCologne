import re
import subprocess

def extract_file_paths(tcl_script):
    """Extracts file paths from the read_verilog commands in the given TCL script."""
    file_paths = re.findall(r'read_verilog(?: -sv)? \{([^}]+)\}', tcl_script)
    return file_paths

def generate_svtov(file_paths, output_file="svtov.sv"):
    """Generates a monolithic SystemVerilog file with `include` directives for the extracted file paths."""
    with open(output_file, "w") as f:
        f.write("// Auto-generated SystemVerilog monolithic file\n")
        for file_path in file_paths:
            f.write(f'`include "{file_path}"\n')
    print(f"Generated {output_file} with {len(file_paths)} include directives.")

def convert_sv2v(input_file="svtov.sv"):
    """Runs sv2v conversion on the generated SystemVerilog file."""
    try:
        cmd = [
            "sv2v", 
            "--verbose",
            "-DVERILATOR",
            "--write=out.v",
            "-Isrc/veerwolf-veer_el2_pack_config_0.7.5/", 
            "-Isrc/pulp-platform.org__common_cells_1.20.0/include/", 
            "-Isrc/pulp-platform.org__axi_0.25.0/include/", 
            "-Isrc/veerwolf-intercon_0.7.5/", 
            "-Isrc/veerwolf-wb_nospi_intercon_0.7.5/", 
            "-Isrc/uart16550_1.5.5-r1/rtl/verilog/",
            "--top=veerwolf_pack_cc",
            input_file
        ]
        subprocess.run(cmd, check=True)
        print(f"Converted {input_file} to Verilog using sv2v.")
    except subprocess.CalledProcessError as e:
        print(f"Error during sv2v conversion: {e}")
def modify_read_files(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    
    inside_read_files = False
    modified_lines = []
    
    for line in lines:
        if re.match(r'proc read_files', line):
            inside_read_files = True
            modified_lines.append(line)
            continue
        
        if inside_read_files:
            if re.match(r'\s*read_verilog', line):  # Remove all read_verilog lines
                continue
            if "}" in line:
                inside_read_files = False
                modified_lines.append("    read_verilog -sv out.v\n")
            modified_lines.append(line)
            continue
        
        modified_lines.append(line)
    
    with open(file_path, 'w') as file:
        file.writelines(modified_lines)


# Read the TCL script (assuming it's stored in a file)
tcl_script_file = "edalize_yosys_procs.tcl"  # Change this if needed
with open(tcl_script_file, "r") as f:
    tcl_script = f.read()

# Extract file paths and generate svtov.sv
file_paths = extract_file_paths(tcl_script)
generate_svtov(file_paths)
convert_sv2v()
modify_read_files('edalize_yosys_procs.tcl')


