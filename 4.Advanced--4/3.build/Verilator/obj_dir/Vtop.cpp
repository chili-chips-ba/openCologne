// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) ^ vlTOPp->top__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->top__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->reset) ^ vlTOPp->top__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->top__DOT____Vtogcov__reset = vlTOPp->reset;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__top__DOT__count_c;
    // Body
    __Vdly__top__DOT__count_c = vlTOPp->top__DOT__count_c;
    ++(vlSymsp->__Vcoverage[38]);
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        ++(vlSymsp->__Vcoverage[37]);
    }
    if (vlTOPp->reset) {
        ++(vlSymsp->__Vcoverage[36]);
    }
    if ((0x1eU == vlTOPp->top__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[39]);
    }
    if ((0x12cU == vlTOPp->top__DOT__count_c)) {
        ++(vlSymsp->__Vcoverage[40]);
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if ((0x63U <= vlTOPp->top__DOT__count_c)) {
            ++(vlSymsp->__Vcoverage[34]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if ((0x63U > vlTOPp->top__DOT__count_c)) {
            ++(vlSymsp->__Vcoverage[35]);
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top__DOT__count_c = 0U;
    } else {
        __Vdly__top__DOT__count_c = ((IData)(1U) + vlTOPp->top__DOT__count_c);
        if (VL_UNLIKELY((0x63U <= vlTOPp->top__DOT__count_c))) {
            VL_WRITEF("*-* All Finished *-*\n");
            VL_FINISH_MT("top.v", 23, "");
        }
    }
    vlTOPp->top__DOT__count_c = __Vdly__top__DOT__count_c;
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

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
