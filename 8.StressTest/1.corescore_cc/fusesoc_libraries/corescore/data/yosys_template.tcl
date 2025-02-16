yosys -import
source edalize_yosys_procs.tcl

verilog_defaults -push
verilog_defaults -add -defer

set_defines
set_incdirs
read_files
set_params

verilog_defaults -pop

synth $top

write_verilog corescore_0_synth.v

# --- Post-Processing (in-place editing) ---
set file_name "corescore_0_synth.v"

# Read the entire file content
set fin [open $file_name r]
set lines [split [read $fin] "\n"]
close $fin

# Filter out lines based on the criteria
set new_lines {}
foreach line $lines {
    # Skip line if it contains "$write"
    if { [regexp {\$write} $line] } {
        continue
    }
    # Skip if line begins with "initial" or "if" (ignoring leading whitespace)
    if { [regexp {^\s*(initial|if)} $line] } {
        continue
    }
    # If line begins with "end" (ignoring whitespace) but is not exactly "endmodule", skip it.
    if { [regexp {^\s*end} $line] && ![regexp {^\s*endmodule\s*$} $line] } {
        continue
    }
    lappend new_lines $line
}

# Write the filtered lines back to the same file
set fout [open $file_name w]
puts $fout [join $new_lines "\n"]
close $fout

puts "Cleaned netlist written to $file_name"