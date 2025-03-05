import os
import re
import matplotlib.pyplot as plt
import numpy as np


# Directory containing the reports
gowin_rpt_dir = "./gowin_rpt"
# Directory containing the Yosys logs
yosys_log_dir = "./yosys_logs"

# Data storage for Yosys extracted values
yosys_counts = []
yosys_lut_counts = []
yosys_dff_counts = []

# Data storage
counts = []
lut_counts = []
dff_counts = []
bsram_counts = []

# Regular expressions to extract required numbers
lut_pattern = re.compile(r"<td class=\"label\">Logic<\/td>\s*<td>(\d+)\(")
dff_pattern = re.compile(r"<td class=\"label\">&nbsp&nbsp--Register as FF<\/td>\s*<td>(\d+) /")
bsram_pattern = re.compile(r"<td class=\"label\">BSRAM<\/td>\s*<td>(\d+) /")



# Regular expressions to extract LUT and DFF values from Yosys logs
lut_pattern_yosys = re.compile(r"^\s+LUT1\s+(\d+)", re.MULTILINE)
lut2_pattern_yosys = re.compile(r"^\s+LUT2\s+(\d+)", re.MULTILINE)
lut3_pattern_yosys = re.compile(r"^\s+LUT3\s+(\d+)", re.MULTILINE)
lut4_pattern_yosys = re.compile(r"^\s+LUT4\s+(\d+)", re.MULTILINE)
dff_pattern_yosys = re.compile(r"^\s+DFF\s+(\d+)", re.MULTILINE)
dffc_pattern_yosys = re.compile(r"^\s+DFFC\s+(\d+)", re.MULTILINE)
dffe_pattern_yosys = re.compile(r"^\s+DFFE\s+(\d+)", re.MULTILINE)
dffr_pattern_yosys = re.compile(r"^\s+DFFR\s+(\d+)", re.MULTILINE)
dffre_pattern_yosys = re.compile(r"^\s+DFFRE\s+(\d+)", re.MULTILINE)
dffs_pattern_yosys = re.compile(r"^\s+DFFS\s+(\d+)", re.MULTILINE)
dffse_pattern_yosys = re.compile(r"^\s+DFFSE\s+(\d+)", re.MULTILINE)

# Process each Yosys log file
for count in range(1, 51):
    file_path = os.path.join(yosys_log_dir, f"log_{count}")

    if os.path.exists(file_path):
        with open(file_path, "r", encoding="utf-8") as file:
            content = file.read()

            # Extract LUT and DFF counts
            lut1_match = lut_pattern_yosys.search(content)
            lut2_match = lut2_pattern_yosys.search(content)
            lut3_match = lut3_pattern_yosys.search(content)
            lut4_match = lut4_pattern_yosys.search(content)
            dff_match = dff_pattern_yosys.search(content)
            dffc_match = dffc_pattern_yosys.search(content)
            dffe_match = dffe_pattern_yosys.search(content)
            dffr_match = dffr_pattern_yosys.search(content)
            dffre_match = dffre_pattern_yosys.search(content)
            dffs_match = dffs_pattern_yosys.search(content)
            dffse_match = dffse_pattern_yosys.search(content)

            if all([lut1_match, lut2_match, lut3_match, lut4_match, dff_match, dffc_match, dffe_match, dffr_match, dffre_match, dffs_match, dffse_match]):
                yosys_counts.append(count)
                lut_total = sum(int(m.group(1)) for m in [lut1_match, lut2_match, lut3_match, lut4_match])
                dff_total = sum(int(m.group(1)) for m in [dff_match, dffc_match, dffe_match, dffr_match, dffre_match, dffs_match, dffse_match])

                yosys_lut_counts.append(lut_total)
                yosys_dff_counts.append(dff_total)
# Process each file
for count in range(1, 51):
    file_path = os.path.join(gowin_rpt_dir, f"gowin_corescore_syn_rpt_{count}.html")
    
    if os.path.exists(file_path):
        with open(file_path, "r", encoding="utf-8") as file:
            content = file.read()

            lut_match = lut_pattern.search(content)
            dff_match = dff_pattern.search(content)
            bsram_match = bsram_pattern.search(content)

            if lut_match and dff_match and bsram_match:
                counts.append(count)
                lut_counts.append(int(lut_match.group(1)))
                dff_counts.append(int(dff_match.group(1)))
                bsram_counts.append(int(bsram_match.group(1)))

# Compute relative differences (percentage difference)
lut_percentage_diff = [(y - p) / p * 100 for p, y in zip(lut_counts, yosys_lut_counts)]
dff_percentage_diff = [(y - p) / p * 100 for p, y in zip(dff_counts, yosys_dff_counts)]

# Plot results comparing proprietary and Yosys synthesis
plt.figure(figsize=(10, 6))
plt.plot(counts, lut_counts, marker='o', linestyle='-', label="LUT Count (Proprietary)")
plt.plot(yosys_counts, yosys_lut_counts, marker='o', linestyle='--', label="LUT Count (Yosys)")
plt.plot(counts, dff_counts, marker='s', linestyle='-', label="DFF Count (Proprietary)")
plt.plot(yosys_counts, yosys_dff_counts, marker='s', linestyle='--', label="DFF Count (Yosys)")

plt.xlabel("Number of Cores")
plt.ylabel("Count")
plt.title("Resource Utilization vs Number of Cores")
plt.legend()
plt.grid(True)

# Show the updated plot
plt.show()






# Plot relative differences
plt.figure(figsize=(10, 6))
plt.plot(counts, lut_percentage_diff, marker='o', linestyle='-', label="LUT Count Difference (%)")
plt.plot(counts, dff_percentage_diff, marker='s', linestyle='-', label="DFF Count Difference (%)")

plt.xlabel("Number of Cores")
plt.ylabel("Percentage Difference (%)")
plt.title("Percentage Difference: Yosys vs Proprietary Synthesis")
plt.legend()
plt.axhline(0, color='black', linestyle='--', linewidth=0.8)  # Add horizontal line at 0%
plt.grid(True)

# Show the percentage difference plot
plt.show()
