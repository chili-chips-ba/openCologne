import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles

async def reset(dut, duration=5):
    dut.rst <= 1
    await ClockCycles(dut.clk, duration)
    dut.rst <= 0
    await RisingEdge(dut.clk)
    dut._log.info("Reset complete")

@cocotb.coroutine
async def run_test(dut, module_type):
    """ Common test for both VHDL and SystemVerilog modules """
    cocotb.fork(Clock(dut.clk, 10, units="ns").start())
    await reset(dut)

    # Initialize inputs
    dut.pcm_in <= 0
    dut.cw_freq <= 0

    # Test different input values
    for i in range(-32767, 32768, 1000):
        dut.pcm_in <= i
        dut.cw_freq <= i

        await RisingEdge(dut.clk)

        output = dut.fm_out.value
        dut._log.info(f"{module_type} Module - Input: {i}, Output: {output}")

    dut._log.info(f"{module_type} Module Test completed successfully")

@cocotb.test()
async def fmgen_vhdl_test(dut):
    """ Test the fmgen VHDL module """
    await run_test(dut, "VHDL")

@cocotb.test()
async def fmgen_sv_test(dut):
    """ Test the fmgen SystemVerilog module """
    await run_test(dut, "SystemVerilog")
