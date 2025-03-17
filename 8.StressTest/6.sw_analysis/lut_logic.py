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
    print(unique_functions)
    return len(unique_functions)


import torch
from itertools import product

# Check for GPU availability
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Using device: {device}")

# Precompute all input combinations (8 inputs)
input_combinations = list(product([0, 1], repeat=8))
inputs_tensor = torch.tensor(input_combinations, dtype=torch.long, device=device)

# Split inputs into individual bits
a, b, c, d, e, f, g, h = (inputs_tensor[:, i] for i in range(8))

# Precompute LUT output cache (16 LUTs × 4 input combinations)
lut_cache = torch.zeros((16, 2, 2), dtype=torch.long, device=device)
for lut in range(16):
    for x in range(2):
        for y in range(2):
            idx = (x << 1) + y
            lut_cache[lut, x, y] = (lut >> (3 - idx)) & 1

# Batch processing parameters
BATCH_SIZE = 1024
total_configs = 16**7
num_batches = (total_configs + BATCH_SIZE - 1) // BATCH_SIZE

def process_batch(batch):
    configs = torch.tensor(batch, dtype=torch.long, device=device)
    batch_size = configs.size(0)
    
    # Expand dimensions for broadcasting
    configs = configs.view(-1, 7, 1).expand(-1, -1, 256)  # [batch_size, 7, 256]
    
    # Layer 1 processing
    l1_out1 = lut_cache[configs[:, 0], a, b]  # [batch_size, 256]
    l1_out2 = lut_cache[configs[:, 1], c, d]
    l1_out3 = lut_cache[configs[:, 2], e, f]
    l1_out4 = lut_cache[configs[:, 3], g, h]
    
    # Layer 2 processing
    l2_out1 = lut_cache[configs[:, 4], l1_out1, l1_out2]
    l2_out2 = lut_cache[configs[:, 5], l1_out3, l1_out4]
    
    # Final layer processing
    final_out = lut_cache[configs[:, 6], l2_out1, l2_out2]  # [batch_size, 256]
    
    # Convert to numpy and create tuples
    return final_out.cpu().numpy()

def l2t8_gpu():
    unique_functions = set()
    config_generator = product(range(16), repeat=7)
    
    for batch_idx in range(num_batches):
        #print(f"Processing batch {batch_idx+1}/{num_batches}")
        batch = [next(config_generator) for _ in range(BATCH_SIZE)]
        
        batch_results = process_batch(batch)
        for row in batch_results:
            # Convert to tuple of 256 bits
            unique_functions.add(tuple(row.astype(int).tolist()))
        
        torch.cuda.empty_cache()
    
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

if __name__ == '__main__':
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

   start = time.time()
#    l2t8_result = l2t8_gpu()  # Note: This calls l2t4() for L2T5 as per original code
   l2t8_time = format_time(time.time() - start)

   print(f"LUT4: {lut4_result} (runtime: {lut4_time})")
   print(f"L2T4: {l2t4_result} (runtime: {l2t4_time})")
   print(f"L2T5: {l2t5_result} (runtime: {l2t5_time})")
#    print(f"L2T8: {l2t8_result} (runtime: {l2t8_time})")