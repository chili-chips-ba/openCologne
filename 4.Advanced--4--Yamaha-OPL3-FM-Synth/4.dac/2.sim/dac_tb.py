import cocotb
from cocotb.triggers import RisingEdge, Timer
from cocotb.clock import Clock

@cocotb.test()
async def dac_tb(dut):
   dut._log.info("Test: Starting DAC cocotb simulation")

   await RisingEdge(dut.clk)
#   for i in range(10):
#      dut._log.info(f"Iteration {i+1}")
#      await RisingEdge(dut.clk)
