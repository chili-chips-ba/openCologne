// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vopl3.h for the primary calling header

#ifndef _VOPL3_MEM_SIMPLE_DUAL_PORT__PI12_H_
#define _VOPL3_MEM_SIMPLE_DUAL_PORT__PI12_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vopl3__Syms;

//----------

VL_MODULE(Vopl3_mem_simple_dual_port__pi12) {
  public:
    
    // PORTS
    VL_IN8(clka,0,0);
    VL_IN8(clkb,0,0);
    VL_IN8(wea,0,0);
    VL_IN8(reb,0,0);
    VL_IN8(addra,4,0);
    VL_IN8(addrb,4,0);
    VL_IN(dia,25,0);
    VL_OUT(dob,25,0);
    
    // LOCAL SIGNALS
    IData/*25:0*/ __PVT__dob_p0;
    IData/*25:0*/ __PVT__genblk1__DOT__dob_p1;
    IData/*25:0*/ __PVT__ram[18];
    
    // LOCAL VARIABLES
    CData/*0:0*/ __Vtogcov__wea;
    CData/*0:0*/ __Vtogcov__reb;
    CData/*4:0*/ __Vdlyvdim0__ram__v0;
    CData/*0:0*/ __Vdlyvset__ram__v0;
    IData/*25:0*/ __Vtogcov__dob;
    IData/*25:0*/ __Vtogcov__dob_p0;
    IData/*25:0*/ __Vlvbound2;
    IData/*25:0*/ __Vdlyvval__ram__v0;
    
    // INTERNAL VARIABLES
  private:
    Vopl3__Syms* __VlSymsp;  // Symbol table
  public:
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vopl3_mem_simple_dual_port__pi12);  ///< Copying not allowed
  public:
    Vopl3_mem_simple_dual_port__pi12(const char* name = "TOP");
    ~Vopl3_mem_simple_dual_port__pi12();
    
    // INTERNAL METHODS
    void __Vconfigure(Vopl3__Syms* symsp, bool first);
  private:
    void _configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    void _initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp);
    static void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
