import time

# Helper function to format seconds into minutes and seconds
def format_time(seconds):
    minutes = int(seconds // 60)
    seconds = seconds % 60
    if minutes == 0:
        return f"{seconds:.2f}s"
    else:
        return f"{minutes}m {seconds:.2f}s"

# This script is used to calculate the number of unique functions that can be implemented using LUTs.
def l2t5():
    from itertools import product

    def lut_output(lut, x, y):
        idx = (x << 1) + y
        return (lut >> (3 - idx)) & 1

    unique_functions = set()

    for lut1, lut2, lut3, lut4 in product(range(16), repeat=4):
        truth_table = 0
        for a, b, c, d in product([0, 1], repeat=4):
            out1 = lut_output(lut1, a, b)
            out2 = lut_output(lut2, c, d)
            out3 = lut_output(lut3, out1, out2)
            final_out = lut_output(lut4, out3, a)
            input_idx = (a << 3) | (b << 2) | (c << 1) | d
            truth_table |= final_out << (15 - input_idx)
        unique_functions.add(truth_table)

    return len(unique_functions)

def l2t4():
    from itertools import product

    def lut_output(lut, x, y):
        idx = (x << 1) + y
        return (lut >> (3 - idx)) & 1

    unique_functions = set()

    for lut1, lut2, lut3 in product(range(16), repeat=3):
        truth_table = 0
        for a, b, c, d in product([0, 1], repeat=4):
            out1 = lut_output(lut1, a, b)
            out2 = lut_output(lut2, c, d)
            out3 = lut_output(lut3, out1, out2)
            input_idx = (a << 3) | (b << 2) | (c << 1) | d
            truth_table |= out3 << (15 - input_idx)
        unique_functions.add(truth_table)

    return len(unique_functions)

def lut4():
    from itertools import product

    def lut4_output(lut, x1, x2, x3, x4):
        idx = (x4 << 3) + (x3 << 2) + (x2 << 1) + x1
        return (lut >> (15 - idx)) & 1

    unique_functions = set()

    for lut in range(2**16):
        truth_table = 0
        for x1, x2, x3, x4 in product([0, 1], repeat=4):
            outx = lut4_output(lut, x1, x2, x3, x4)
            idx = (x4 << 3) | (x3 << 2) | (x2 << 1) | x1
            truth_table |= outx << (15 - idx)
        unique_functions.add(truth_table)
    return len(unique_functions)

# Measure and print results with runtime
print("Number of distinct 4-input logic functions that can be implemented in:")

start = time.time()
lut4_result = lut4()
lut4_time = format_time(time.time() - start)

start = time.time()
l2t4_result = l2t5()  # Note: This calls l2t5() for L2T4 as per original code
l2t4_time = format_time(time.time() - start)

start = time.time()
l2t5_result = l2t4()  # Note: This calls l2t4() for L2T5 as per original code
l2t5_time = format_time(time.time() - start)

print(f"LUT4: {lut4_result} (runtime: {lut4_time})")
print(f"L2T4: {l2t4_result} (runtime: {l2t4_time})")
print(f"L2T5: {l2t5_result} (runtime: {l2t5_time})")