#include "Vtop.h"             // This is the Verilator-generated model class for your top module.
#include "verilated.h"        // Includes basic Verilator utilities
#include "verilated_vcd_c.h"  // If you want VCD waveform output

int main(int argc, char** argv, char** env) {
    if (false && argc && argv && env) {}  // Prevent unused variable warnings
    Verilated::commandArgs(argc, argv);  // Initialize Verilator's variables
    Verilated::traceEverOn(true);        // Enable waveform tracing

    // Create an instance of the top module.
    Vtop* top = new Vtop;

    // Create a VCD trace file
    VerilatedVcdC* vcd = new VerilatedVcdC;
    top->trace(vcd, 99);  // Trace 99 levels of hierarchy
    vcd->open("top.vcd"); // Open the VCD file for dumping

    // Simulation main loop
    for (int i = 0; i < 100; i++) {
        // Toggle clock and evaluate
        top->clk = !top->clk;  // Toggle the clock input
        top->eval();           // Evaluate the model

        // Dump VCD waveform trace
        vcd->dump(i * 10 - 2); // Dump the negative edge at a time slightly before the actual edge
        top->eval();           // Evaluate the model at clock edge
        vcd->dump(i * 10);     // Dump the positive or negative edge

        // Additional stimulus: add your code here to modify inputs
        if (i == 10) {
            top->reset = 1;   // Assert reset
        } else if (i == 15) {
            top->reset = 0;   // De-assert reset
        }

        top->eval();           // Evaluate the model after changing inputs
        vcd->dump(i * 10 + 5); // Dump midway through the cycle
        vcd->flush();          // Flush any pending waveform data
    }

    // Final model evaluation at end of simulation
    top->final();
    vcd->close();  // Close the VCD file
    delete top;    // Cleanup the top instance
    delete vcd;    // Cleanup VCD trace

    return 0;
}

