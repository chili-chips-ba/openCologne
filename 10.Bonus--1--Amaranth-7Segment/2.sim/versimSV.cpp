///////////////////////////////////////////////////////////////////////////////
//
// SPDX-FileCopyrightText: 2024 Chili.CHIPS
//
// SPDX-License-Identifier: BSD-3-Clause
//-----------------------------------------------------------------------------
// C++ DPI which allows Verilator to use System Verilog behavioral constructs,
//    i.e. create SV testbenches
///////////////////////////////////////////////////////////////////////////////

#include <verilated_fst_c.h>
#include "verilated.h"
#include "Vtb.h" //change to V<projectname>

double sc_time_stamp() { return 0; }

//----------------------------------------
int main(int argc, char** argv, char**) {
   // Setup context, defaults, and parse command line
   Verilated::debug(0);
   const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
   contextp->traceEverOn(true);
   contextp->commandArgs(argc, argv);
   VerilatedFstC *m_trace = new VerilatedFstC;
   
   // Construct the Verilated model, from Vtop.h generated from Verilating
   const std::unique_ptr<Vtb> topp{new Vtb{contextp.get()}};

   m_trace->set_time_resolution("1ps");
   m_trace->set_time_unit("1ps");
   topp->trace(m_trace, 20);
   m_trace->open("wave.fst");

   // Simulate until $finish
   long long int t0 = 0;
   while (!contextp->gotFinish()) {
      // Evaluate model
      topp->eval();
      m_trace->dump(contextp->time());

      // Advance time
      if (!topp->eventsPending()) break;
      contextp->time(topp->nextTimeSlot());
      t0++;
   }

   if (!contextp->gotFinish()) {
      VL_DEBUG_IF(VL_PRINTF("+ Exiting without $finish; no events left\n"););
   }

   m_trace->close();

   // Closing cleanup
   topp->final();
   return 0;
}

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/02/14 TI: initial creation    
*/
