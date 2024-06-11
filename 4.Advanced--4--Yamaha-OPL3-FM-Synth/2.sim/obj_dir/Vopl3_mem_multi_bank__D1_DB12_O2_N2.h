// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vopl3.h for the primary calling header

#ifndef _VOPL3_MEM_MULTI_BANK__D1_DB12_O2_N2_H_
#define _VOPL3_MEM_MULTI_BANK__D1_DB12_O2_N2_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vopl3__Syms;

//----------

VL_MODULE(Vopl3_mem_multi_bank__D1_DB12_O2_N2) {
  public:
    
    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(wea,0,0);
    VL_IN8(reb,0,0);
    VL_IN8(banka,0,0);
    VL_IN8(addra,4,0);
    VL_IN8(bankb,0,0);
    VL_IN8(addrb,4,0);
    VL_IN8(dia,0,0);
    VL_OUT8(dob,0,0);
    
    // LOCAL SIGNALS
    CData/*1:0*/ __PVT__wea_array;
    CData/*0:0*/ __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    CData/*0:0*/ __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    CData/*0:0*/ __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    CData/*0:0*/ __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    CData/*0:0*/ __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    CData/*0:0*/ __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    CData/*0:0*/ __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    CData/*0:0*/ __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    CData/*0:0*/ __PVT__dob_array[2];
    CData/*0:0*/ __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[18];
    CData/*0:0*/ __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[18];
    
    // LOCAL VARIABLES
    CData/*2:0*/ __Vcellout__bankb_sr__out;
    CData/*0:0*/ __Vtogcov__dia;
    CData/*0:0*/ __Vtogcov__dob;
    CData/*1:0*/ __Vtogcov__wea_array;
    CData/*1:0*/ __Vtogcov__bankb_p;
    CData/*2:0*/ bankb_sr__DOT____Vtogcov__out;
    CData/*0:0*/ bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
    CData/*0:0*/ bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
    CData/*0:0*/ bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
    CData/*0:0*/ bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
    CData/*0:0*/ bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
    CData/*0:0*/ bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
    CData/*0:0*/ bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
    CData/*0:0*/ bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
    CData/*0:0*/ bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
    CData/*0:0*/ bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
    CData/*4:0*/ __Vdlyvdim0__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vtogcov__dob_array[2];
    CData/*0:0*/ bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[18];
    CData/*0:0*/ bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[18];
    
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
    VL_UNCOPYABLE(Vopl3_mem_multi_bank__D1_DB12_O2_N2);  ///< Copying not allowed
  public:
    Vopl3_mem_multi_bank__D1_DB12_O2_N2(const char* name = "TOP");
    ~Vopl3_mem_multi_bank__D1_DB12_O2_N2();
    
    // INTERNAL METHODS
    void __Vconfigure(Vopl3__Syms* symsp, bool first);
  private:
    void _configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    void _initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__3(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__5(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__7(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__9(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__6(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__8(Vopl3__Syms* __restrict vlSymsp);
    static void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__1(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__11(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__12(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
