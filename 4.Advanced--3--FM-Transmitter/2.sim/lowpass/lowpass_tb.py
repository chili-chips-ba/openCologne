import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random

@cocotb.test()
async def test_lowpass(dut):
    """ Test the lowpass filter """

    # Create a clock
    clock = Clock(dut.clock, 10, units="ns")  # Create a clock with 100 MHz frequency
    cocotb.start_soon(clock.start())  # Start the clock

    # Reset the DUT
    dut.enable.value = 0
    dut.data_in.value = 0
    dut.data_out.value = 0
    dut.sum.value = 0
    dut.R_data_in.value = 0

    # Let the clock run for a few cycles
    await Timer(100, units="ns")

    # Enable the DUT
    dut.enable.value = 1
    BITS_IN = 12
    BITS_OUT = 16

    await RisingEdge(dut.clock)

    # Apply some test vectors
    for _ in range(60):
        # Apply random input data
        data_in = random.randint(-(2**(BITS_IN - 1)), 2**(BITS_IN - 1) - 1)
        dut.data_in.value = data_in

        # Wait for a clock cycle
        await RisingEdge(dut.clock)

        # Capture the output
        if "x" not in str(dut.data_out.value):
            data_out = dut.data_out.value.signed_integer
        else:
            data_out = None

        # Display the inputs and outputs
        dut._log.info(f"Input: {data_in}, Output: {data_out}")
        dut._log.info(f"r_data_in: {dut.R_data_in.value.signed_integer}")
        dut._log.info(f"Sum: {dut.sum.value.signed_integer}")
        # Simple check: the output should be within the range of the BITS_OUT if not 'x'
        if data_out is not None:
            assert -(2**(BITS_OUT - 1)) <= data_out <= 2**(BITS_OUT - 1) - 1, f"Output {data_out} is out of range!"

    # Let the clock run for a few more cycles to observe the final output
    await Timer(100, units="ns")
