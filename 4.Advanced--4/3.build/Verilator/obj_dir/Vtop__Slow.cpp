// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

// Coverage
void Vtop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vtop::_settle__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[47]);
    if (((IData)(vlTOPp->clk) ^ vlTOPp->top__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->top__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->reset) ^ vlTOPp->top__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->top__DOT____Vtogcov__reset = vlTOPp->reset;
    }
    if (VL_UNLIKELY((0x32U == vlTOPp->top__DOT__count_c))) {
        VL_WRITEF("[%0t] got 50\n",64,VL_TIME_UNITED_Q(1));
    }
    if (VL_UNLIKELY((0x1f4U == vlTOPp->top__DOT__count_c))) {
        VL_WRITEF("[%0t] got 600\n",64,VL_TIME_UNITED_Q(1));
    }
    if ((0x32U == vlTOPp->top__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[43]);
    }
    if ((0x32U != vlTOPp->top__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[44]);
    }
    if ((0x1f4U == vlTOPp->top__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[45]);
    }
    if ((0x1f4U != vlTOPp->top__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[46]);
    }
    if (((0x32U == vlTOPp->top__DOT__count_c) ^ vlTOPp->top__DOT____Vtogcov__count_hit_50)) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->top__DOT____Vtogcov__count_hit_50 = 
            (0x32U == vlTOPp->top__DOT__count_c);
    }
    if (((0x1f4U == vlTOPp->top__DOT__count_c) ^ vlTOPp->top__DOT____Vtogcov__count_hit_500)) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->top__DOT____Vtogcov__count_hit_500 
            = (0x1f4U == vlTOPp->top__DOT__count_c);
    }
    if ((1U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffffeU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (1U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((2U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffffdU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (2U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((4U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffffbU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (4U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((8U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffff7U 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (8U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x10U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffffefU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x10U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x20U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffffdfU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x20U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x40U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffffbfU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x40U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x80U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffff7fU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x80U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x100U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffeffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x100U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x200U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffdffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x200U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x400U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffffbffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x400U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x800U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffff7ffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x800U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x1000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffefffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x1000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x2000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffdfffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x2000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x4000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffffbfffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x4000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x8000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffff7fffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x8000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x10000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffeffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x10000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x20000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffdffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x20000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x40000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfffbffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x40000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x80000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfff7ffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x80000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x100000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffefffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x100000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x200000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffdfffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x200000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x400000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xffbfffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x400000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x800000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xff7fffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x800000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x1000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfeffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x1000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x2000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfdffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x2000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x4000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xfbffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x4000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x8000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xf7ffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x8000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x10000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xefffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x10000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x20000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xdfffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x20000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x40000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0xbfffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x40000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
    if ((0x80000000U & (vlTOPp->top__DOT__count_c ^ vlTOPp->top__DOT____Vtogcov__count_c))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->top__DOT____Vtogcov__count_c = ((0x7fffffffU 
                                                 & vlTOPp->top__DOT____Vtogcov__count_c) 
                                                | (0x80000000U 
                                                   & vlTOPp->top__DOT__count_c));
    }
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    top__DOT__count_c = VL_RAND_RESET_I(32);
    top__DOT____Vtogcov__clk = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__reset = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__count_c = VL_RAND_RESET_I(32);
    top__DOT____Vtogcov__count_hit_50 = VL_RAND_RESET_I(1);
    top__DOT____Vtogcov__count_hit_500 = VL_RAND_RESET_I(1);
}

void Vtop::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "top.v", 9, 16, ".top", "v_toggle/top", "clk", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "top.v", 10, 16, ".top", "v_toggle/top", "reset", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "top.v", 13, 15, ".top", "v_toggle/top", "count_c[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "top.v", 21, 3, ".top", "v_branch/top", "if", "21-23");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "top.v", 21, 4, ".top", "v_branch/top", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "top.v", 16, 7, ".top", "v_branch/top", "if", "16-17");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "top.v", 16, 8, ".top", "v_branch/top", "else", "19-20");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "top.v", 14, 4, ".top", "v_line/top", "block", "14");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "top.v", 29, 4, ".top", "v_user/top", "cover", "29");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "top.v", 30, 4, ".top", "v_user/top", "cover", "30");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "top.v", 33, 9, ".top", "v_toggle/top", "count_hit_50", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "top.v", 34, 9, ".top", "v_toggle/top", "count_hit_500", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "top.v", 41, 7, ".top", "v_branch/top", "if", "41-42");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "top.v", 41, 8, ".top", "v_branch/top", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "top.v", 44, 7, ".top", "v_branch/top", "if", "44-45");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "top.v", 44, 8, ".top", "v_branch/top", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "top.v", 40, 4, ".top", "v_line/top", "block", "40");
}
