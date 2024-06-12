// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VOPL3__SYMS_H_
#define _VOPL3__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vopl3.h"
#include "Vopl3___024unit.h"

// SYMS CLASS
class Vopl3__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vopl3*                         TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_opl3__channels;
    VerilatedScope __Vscope_opl3__channels__control_operators;
    VerilatedScope __Vscope_opl3__channels__control_operators__operator__calc_phase_inc;
    VerilatedScope __Vscope_opl3__channels__control_operators__operator__envelope_generator;
    VerilatedScope __Vscope_opl3__channels__control_operators__operator__envelope_generator__ksl_add_rom;
    VerilatedScope __Vscope_opl3__channels__control_operators__operator__envelope_generator__state_mem;
    VerilatedScope __Vscope_opl3__channels__control_operators__operator__phase_generator;
    VerilatedScope __Vscope_opl3__channels__control_operators__operator__phase_generator__calc_rhythm_phase;
    
    // CREATORS
    Vopl3__Syms(Vopl3* topp, const char* namep);
    ~Vopl3__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
