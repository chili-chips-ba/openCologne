from amaranth import *
from amaranth_boards.gatemate_a1_evb import GateMate_A1_EVB
from amaranth.back import verilog

class Blinky(Elaboratable):
    def __init__(self):
        self.clk = Signal()
        self.led = Signal()

        self.counter = Signal(10)

    def elaborate(self, platform):
        m = Module()

        m.d.sync += self.counter.eq(self.counter + 1)
        # Set the LED signal to high
        m.d.comb += self.led.eq(1)
        return m

if __name__ == "__main__":
    
    m = Module()
    platform = GateMate_A1_EVB()
    top = Blinky()
    led0 = platform.request('led', 0)
    m.d.comb += led0.o.eq(top.led)

    ports = [top.clk, top.led, top.counter]
    verilog_code = verilog.convert(top, ports=ports, name="Blinky", platform=platform)  # Pass platform explicitly
    with open("Blinky.v", "w") as f:
        f.write(verilog_code)

    # Uncomment the line below to build the design
    platform.build(top, name="Blinky", do_program=False)
