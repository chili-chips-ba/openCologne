from amaranth import *
from amaranth_boards.gatemate_a1_evb import GateMate_A1_EVB
from amaranth.back import verilog

class Blinky(Elaboratable):
    def __init__(self):
        self.led = Signal()
        self.counter = Signal(20)  

    def elaborate(self, platform):
        m = Module()    

        led0 = platform.request('led', 0)
        
        with m.If(self.counter < 2**20 - 1):
            m.d.sync += self.counter.eq(self.counter + 1)
        with m.Else():
            m.d.sync += self.counter.eq(0)

        m.d.comb += self.led.eq(self.counter[-1]) 
        m.d.comb += led0.o.eq(self.led)
        
        return m

if __name__ == "__main__":
    platform = GateMate_A1_EVB()
    top = Blinky()

    #ports = [top.led]
    #verilog_code = verilog.convert(top, ports=ports, name="Blinky", platform=platform)
    #with open("Blinky.v", "w") as f:
    #    f.write(verilog_code)


    platform.build(top, name="Blinky", do_program=False)
