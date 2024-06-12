// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vopl3.h for the primary calling header

#ifndef _VOPL3___024UNIT_H_
#define _VOPL3___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vopl3__Syms;

//----------

VL_MODULE(Vopl3___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vopl3__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vopl3___024unit);  ///< Copying not allowed
  public:
    Vopl3___024unit(const char* name = "TOP");
    ~Vopl3___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vopl3__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
