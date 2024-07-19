// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vopl3__pch.h"
#include "Vopl3.h"
#include "Vopl3___024root.h"

// FUNCTIONS
Vopl3__Syms::~Vopl3__Syms()
{
}

Vopl3__Syms::Vopl3__Syms(VerilatedContext* contextp, const char* namep, Vopl3* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(599);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
