#include "Vopl3.h"
#include "verilated.h"

Vopl3* top;                    // Instantiation of module

unsigned int main_time = 0;     // Current simulation time

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);   // Remember args

    top = new Vopl3;             // Create instance

    top->clk = 0;                // Set initial clock value

    while (!Verilated::gotFinish() && main_time < 100) { // Run simulation for 100 time units
        if ((main_time % 10) == 1) {
            top->clk = 1;       // Toggle clock
        }
        if ((main_time % 10) == 6) {
            top->clk = 0;
        }

        top->eval();            // Evaluate model
        main_time++;            // Time passes...
    }

    top->final();               // Done simulating

    delete top;                 // Cleanup
    return 0;
}

