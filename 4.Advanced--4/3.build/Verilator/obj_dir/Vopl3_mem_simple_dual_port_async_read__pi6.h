// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vopl3.h for the primary calling header

#ifndef _VOPL3_MEM_SIMPLE_DUAL_PORT_ASYNC_READ__PI6_H_
#define _VOPL3_MEM_SIMPLE_DUAL_PORT_ASYNC_READ__PI6_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vopl3__Syms;

//----------

VL_MODULE(Vopl3_mem_simple_dual_port_async_read__pi6) {
  public:
    
    // PORTS
    VL_IN8(__PVT__clka,0,0);
    VL_IN8(__PVT__wea,0,0);
    VL_IN8(__PVT__addra,4,0);
    VL_IN8(__PVT__addrb,4,0);
    VL_IN8(__PVT__dia,7,0);
    VL_OUT8(__PVT__dob,7,0);
    
    // LOCAL SIGNALS
    CData/*7:0*/ __PVT__ram[22];
    
    // LOCAL VARIABLES
    CData/*0:0*/ __Vtogcov__wea;
    CData/*7:0*/ __Vtogcov__dob;
    CData/*7:0*/ __Vlvbound2;
    CData/*4:0*/ __Vdlyvdim0__ram__v0;
    CData/*7:0*/ __Vdlyvval__ram__v0;
    CData/*0:0*/ __Vdlyvset__ram__v0;
    CData/*7:0*/ __Vtogcov__ram[22];
    
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
    VL_UNCOPYABLE(Vopl3_mem_simple_dual_port_async_read__pi6);  ///< Copying not allowed
  public:
    Vopl3_mem_simple_dual_port_async_read__pi6(const char* name = "TOP");
    ~Vopl3_mem_simple_dual_port_async_read__pi6();
    
    // INTERNAL METHODS
    void __Vconfigure(Vopl3__Syms* symsp, bool first);
  private:
    void _configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    void _initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__15(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__23(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__31(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__24(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__32(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__19(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__27(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__20(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__28(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__17(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__25(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__18(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__26(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__21(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__29(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__22(Vopl3__Syms* __restrict vlSymsp);
    void _sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__30(Vopl3__Syms* __restrict vlSymsp);
    static void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__39(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__41(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__42(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__45(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__46(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__43(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__44(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__47(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    void _settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__48(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
