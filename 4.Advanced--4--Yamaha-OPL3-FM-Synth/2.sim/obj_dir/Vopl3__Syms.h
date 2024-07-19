// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VOPL3__SYMS_H_
#define VERILATED_VOPL3__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vopl3.h"

// INCLUDE MODULE CLASSES
#include "Vopl3___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vopl3__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vopl3* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vopl3___024root                TOP;

    // CONSTRUCTORS
    Vopl3__Syms(VerilatedContext* contextp, const char* namep, Vopl3* modelp);
    ~Vopl3__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
