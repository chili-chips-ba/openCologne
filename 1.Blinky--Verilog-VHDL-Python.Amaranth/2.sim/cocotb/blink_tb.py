import cocotb
from cocotb.triggers import RisingEdge, Timer
from cocotb.clock import Clock

@cocotb.test()

async def blink_test(dut):

   for _ in range(10):
      await RisingEdge(dut.clk)
