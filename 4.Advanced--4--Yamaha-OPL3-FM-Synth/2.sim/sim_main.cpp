#include "Vopl3.h"             // This is the Verilator-generated model class for your top module.
#include "verilated.h"        // Includes basic Verilator utilities
#include "verilated_vcd_c.h"  // If you want VCD waveform output
#include "systemc.h"

int main(int argc, char** argv, char** env) {
    if (false && argc && argv && env) {}  // Prevent unused variable warnings
    Verilated::commandArgs(argc, argv);  // Initialize Verilator's variables
    Verilated::traceEverOn(true);        // Enable waveform tracing

    // Create an instance of the top module.
    Vopl3* opl3 = new Vopl3;

    // Create a VCD trace file
    //VerilatedVcdC* vcd = new VerilatedVcdC;
    //opl3->trace(vcd, 99);  // Trace 99 levels of hierarchy
    //vcd->open("opl3.vcd"); // Open the VCD file for dumping

    // Simulation main loop
    for (int i = 0; i < 100; i++) {
        // Toggle clock and evaluate
        opl3->clk = !opl3->clk;  // Toggle the clock input
        opl3->eval();           // Evaluate the model
    }

    // Final model evaluation at end of simulation
    opl3->final();
    delete opl3;    // Cleanup the top instance

    return 0;
}

