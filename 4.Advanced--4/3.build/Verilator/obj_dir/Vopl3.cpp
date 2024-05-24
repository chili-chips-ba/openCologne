// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3.h"
#include "Vopl3__Syms.h"

//==========

void Vopl3::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vopl3::eval\n"); );
    Vopl3__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/top_level/src/opl3.sv", 44, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vopl3::_eval_initial_loop(Vopl3__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/top_level/src/opl3.sv", 44, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vopl3::_combo__TOP__2(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_combo__TOP__2\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) 
         ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_rd_reset_n)) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_rd_reset_n 
            = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x27U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[582]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xf7fffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x28U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[583]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xeffffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x29U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[584]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xdffffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x2aU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[585]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xbffffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x2bU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[586]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0x7ffffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x26U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[587]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfbfffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x22U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[588]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffbffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x23U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[589]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xff7ffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x24U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[590]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfefffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x25U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[591]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfdfffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x14U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[592]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffefffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x15U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[593]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffdfffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x16U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[594]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffbfffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x17U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[595]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffff7fffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x18U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[596]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffeffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x19U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[597]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffdffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x1aU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[598]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffbffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x1bU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[599]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffff7ffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x1cU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[600]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffefffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x1dU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[601]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffdfffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x1eU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[602]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffbfffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x1fU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[603]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfff7fffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x20U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[604]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffeffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x21U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[605]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffdffffffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 5U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[606]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffffdfULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 6U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[607]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffffbfULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 7U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[608]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffff7fULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 8U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[609]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffeffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 9U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[610]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffdffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0xaU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[611]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffbffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0xbU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[612]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffff7ffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0xcU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[613]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffefffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0xdU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[614]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffdfffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0xeU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[615]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffbfffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0xfU)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[616]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffff7fffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x10U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[617]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffeffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x11U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[618]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffdffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x12U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[619]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffbffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x13U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[620]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffff7ffffULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 4U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[621]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xfffffffffefULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 3U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[622]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffff7ULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 2U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[623]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffffbULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 1U)) ^ (IData)((vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[624]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffffdULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__signals) 
               ^ (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals)))) {
        ++(vlSymsp->__Vcoverage[625]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals 
            = ((0xffffffffffeULL & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__signals) 
               | (IData)((IData)((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))));
    }
    if (((IData)(vlTOPp->clk) ^ vlTOPp->opl3__DOT____Vtogcov__clk)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->opl3__DOT____Vtogcov__clk = vlTOPp->clk;
    }
    if (((IData)(vlTOPp->clk_host) ^ vlTOPp->opl3__DOT____Vtogcov__clk_host)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->opl3__DOT____Vtogcov__clk_host = vlTOPp->clk_host;
    }
    if (((IData)(vlTOPp->clk_dac) ^ vlTOPp->opl3__DOT____Vtogcov__clk_dac)) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->opl3__DOT____Vtogcov__clk_dac = vlTOPp->clk_dac;
    }
    if (((IData)(vlTOPp->ic_n) ^ vlTOPp->opl3__DOT____Vtogcov__ic_n)) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->opl3__DOT____Vtogcov__ic_n = vlTOPp->ic_n;
    }
    if (((IData)(vlTOPp->cs_n) ^ vlTOPp->opl3__DOT____Vtogcov__cs_n)) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->opl3__DOT____Vtogcov__cs_n = vlTOPp->cs_n;
    }
    if (((IData)(vlTOPp->rd_n) ^ vlTOPp->opl3__DOT____Vtogcov__rd_n)) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->opl3__DOT____Vtogcov__rd_n = vlTOPp->rd_n;
    }
    if (((IData)(vlTOPp->wr_n) ^ vlTOPp->opl3__DOT____Vtogcov__wr_n)) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->opl3__DOT____Vtogcov__wr_n = vlTOPp->wr_n;
    }
    if ((1U & ((IData)(vlTOPp->address) ^ vlTOPp->opl3__DOT____Vtogcov__address))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->opl3__DOT____Vtogcov__address = ((2U 
                                                  & (IData)(vlTOPp->opl3__DOT____Vtogcov__address)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->address)));
    }
    if ((2U & ((IData)(vlTOPp->address) ^ vlTOPp->opl3__DOT____Vtogcov__address))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->opl3__DOT____Vtogcov__address = ((1U 
                                                  & (IData)(vlTOPp->opl3__DOT____Vtogcov__address)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->address)));
    }
    if ((1U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xfeU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (1U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((2U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xfdU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (2U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((4U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xfbU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (4U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((8U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xf7U 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (8U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((0x10U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xefU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (0x10U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((0x20U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xdfU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (0x20U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((0x40U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0xbfU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (0x40U 
                                                & (IData)(vlTOPp->din)));
    }
    if ((0x80U & ((IData)(vlTOPp->din) ^ vlTOPp->opl3__DOT____Vtogcov__din))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->opl3__DOT____Vtogcov__din = ((0x7fU 
                                              & (IData)(vlTOPp->opl3__DOT____Vtogcov__din)) 
                                             | (0x80U 
                                                & (IData)(vlTOPp->din)));
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__4(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__4\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[116]);
    if ((1U & (~ (IData)(vlTOPp->ic_n)))) {
        ++(vlSymsp->__Vcoverage[114]);
    }
    if (vlTOPp->ic_n) {
        ++(vlSymsp->__Vcoverage[115]);
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__opl3__DOT__sample_clk_gen__DOT__counter 
        = vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out;
    ++(vlSymsp->__Vcoverage[175]);
    ++(vlSymsp->__Vcoverage[302]);
    ++(vlSymsp->__Vcoverage[326]);
    ++(vlSymsp->__Vcoverage[327]);
    ++(vlSymsp->__Vcoverage[425]);
    ++(vlSymsp->__Vcoverage[628]);
    ++(vlSymsp->__Vcoverage[679]);
    ++(vlSymsp->__Vcoverage[688]);
    ++(vlSymsp->__Vcoverage[715]);
    ++(vlSymsp->__Vcoverage[937]);
    ++(vlSymsp->__Vcoverage[971]);
    ++(vlSymsp->__Vcoverage[981]);
    ++(vlSymsp->__Vcoverage[1017]);
    ++(vlSymsp->__Vcoverage[1027]);
    ++(vlSymsp->__Vcoverage[1034]);
    ++(vlSymsp->__Vcoverage[1036]);
    ++(vlSymsp->__Vcoverage[1052]);
    ++(vlSymsp->__Vcoverage[1086]);
    ++(vlSymsp->__Vcoverage[1110]);
    ++(vlSymsp->__Vcoverage[1130]);
    ++(vlSymsp->__Vcoverage[1181]);
    ++(vlSymsp->__Vcoverage[1186]);
    ++(vlSymsp->__Vcoverage[1238]);
    ++(vlSymsp->__Vcoverage[1243]);
    ++(vlSymsp->__Vcoverage[1258]);
    ++(vlSymsp->__Vcoverage[1276]);
    ++(vlSymsp->__Vcoverage[1281]);
    ++(vlSymsp->__Vcoverage[1300]);
    ++(vlSymsp->__Vcoverage[1305]);
    ++(vlSymsp->__Vcoverage[1605]);
    ++(vlSymsp->__Vcoverage[1619]);
    ++(vlSymsp->__Vcoverage[1621]);
    ++(vlSymsp->__Vcoverage[1623]);
    ++(vlSymsp->__Vcoverage[1635]);
    ++(vlSymsp->__Vcoverage[1660]);
    ++(vlSymsp->__Vcoverage[1686]);
    ++(vlSymsp->__Vcoverage[1696]);
    ++(vlSymsp->__Vcoverage[1697]);
    ++(vlSymsp->__Vcoverage[1712]);
    ++(vlSymsp->__Vcoverage[1713]);
    ++(vlSymsp->__Vcoverage[1728]);
    ++(vlSymsp->__Vcoverage[1729]);
    ++(vlSymsp->__Vcoverage[1744]);
    ++(vlSymsp->__Vcoverage[1745]);
    ++(vlSymsp->__Vcoverage[1760]);
    ++(vlSymsp->__Vcoverage[1761]);
    ++(vlSymsp->__Vcoverage[1859]);
    ++(vlSymsp->__Vcoverage[1860]);
    ++(vlSymsp->__Vcoverage[1868]);
    ++(vlSymsp->__Vcoverage[1903]);
    ++(vlSymsp->__Vcoverage[1906]);
    ++(vlSymsp->__Vcoverage[1910]);
    ++(vlSymsp->__Vcoverage[2038]);
    ++(vlSymsp->__Vcoverage[2060]);
    ++(vlSymsp->__Vcoverage[2066]);
    ++(vlSymsp->__Vcoverage[2071]);
    ++(vlSymsp->__Vcoverage[2073]);
    ++(vlSymsp->__Vcoverage[2075]);
    ++(vlSymsp->__Vcoverage[2077]);
    ++(vlSymsp->__Vcoverage[2122]);
    ++(vlSymsp->__Vcoverage[2123]);
    ++(vlSymsp->__Vcoverage[2129]);
    ++(vlSymsp->__Vcoverage[2164]);
    ++(vlSymsp->__Vcoverage[2165]);
    ++(vlSymsp->__Vcoverage[2184]);
    ++(vlSymsp->__Vcoverage[2295]);
    ++(vlSymsp->__Vcoverage[2298]);
    ++(vlSymsp->__Vcoverage[2300]);
    ++(vlSymsp->__Vcoverage[2304]);
    ++(vlSymsp->__Vcoverage[2306]);
    ++(vlSymsp->__Vcoverage[2308]);
    ++(vlSymsp->__Vcoverage[2314]);
    ++(vlSymsp->__Vcoverage[2357]);
    ++(vlSymsp->__Vcoverage[2394]);
    ++(vlSymsp->__Vcoverage[2399]);
    ++(vlSymsp->__Vcoverage[2437]);
    ++(vlSymsp->__Vcoverage[2442]);
    ++(vlSymsp->__Vcoverage[2471]);
    ++(vlSymsp->__Vcoverage[2500]);
    ++(vlSymsp->__Vcoverage[2507]);
    ++(vlSymsp->__Vcoverage[2913]);
    ++(vlSymsp->__Vcoverage[2914]);
    ++(vlSymsp->__Vcoverage[2920]);
    ++(vlSymsp->__Vcoverage[2925]);
    ++(vlSymsp->__Vcoverage[2926]);
    ++(vlSymsp->__Vcoverage[2931]);
    ++(vlSymsp->__Vcoverage[2936]);
    ++(vlSymsp->__Vcoverage[2964]);
    ++(vlSymsp->__Vcoverage[2972]);
    ++(vlSymsp->__Vcoverage[2974]);
    ++(vlSymsp->__Vcoverage[2976]);
    ++(vlSymsp->__Vcoverage[2978]);
    ++(vlSymsp->__Vcoverage[2980]);
    ++(vlSymsp->__Vcoverage[3032]);
    ++(vlSymsp->__Vcoverage[3079]);
    ++(vlSymsp->__Vcoverage[3084]);
    ++(vlSymsp->__Vcoverage[3086]);
    ++(vlSymsp->__Vcoverage[3134]);
    ++(vlSymsp->__Vcoverage[3139]);
    ++(vlSymsp->__Vcoverage[3141]);
    ++(vlSymsp->__Vcoverage[3263]);
    ++(vlSymsp->__Vcoverage[3279]);
    ++(vlSymsp->__Vcoverage[3284]);
    ++(vlSymsp->__Vcoverage[3286]);
    ++(vlSymsp->__Vcoverage[3552]);
    ++(vlSymsp->__Vcoverage[3818]);
    ++(vlSymsp->__Vcoverage[3882]);
    ++(vlSymsp->__Vcoverage[3884]);
    ++(vlSymsp->__Vcoverage[3892]);
    ++(vlSymsp->__Vcoverage[3894]);
    ++(vlSymsp->__Vcoverage[3896]);
    ++(vlSymsp->__Vcoverage[3933]);
    ++(vlSymsp->__Vcoverage[3986]);
    ++(vlSymsp->__Vcoverage[3991]);
    ++(vlSymsp->__Vcoverage[3994]);
    ++(vlSymsp->__Vcoverage[3997]);
    ++(vlSymsp->__Vcoverage[4000]);
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[1184]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[1185]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[1241]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[1242]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[1279]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[1280]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[1303]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[1304]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[2397]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[2398]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[2440]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[2441]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[3082]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[3083]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[3137]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[3138]);
    }
    if (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) {
        ++(vlSymsp->__Vcoverage[300]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read)))) {
        ++(vlSymsp->__Vcoverage[301]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[1179]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[1180]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[1236]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[1237]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[1274]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[1275]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[1298]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[1299]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[1658]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[1659]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[1684]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[1685]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[2392]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[2393]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[2435]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[2436]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[3077]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[3078]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[3132]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[3133]);
    }
    if (vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty) {
        ++(vlSymsp->__Vcoverage[172]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty)))) {
        ++(vlSymsp->__Vcoverage[171]);
    }
    if (vlTOPp->opl3__DOT__reset_sync__DOT__r2) {
        ++(vlSymsp->__Vcoverage[173]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2)))) {
        ++(vlSymsp->__Vcoverage[174]);
    }
    if ((0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
        if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
            if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
                ++(vlSymsp->__Vcoverage[2127]);
            }
        }
    }
    if ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
        ++(vlSymsp->__Vcoverage[2125]);
    }
    if ((0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
        if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
            ++(vlSymsp->__Vcoverage[2126]);
        }
    }
    if ((0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
        if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
            if ((2U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
                if ((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
                    ++(vlSymsp->__Vcoverage[2128]);
                }
            }
        }
    }
    if ((0xffU == (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter))) {
        ++(vlSymsp->__Vcoverage[324]);
    }
    if ((0xffU != (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter))) {
        ++(vlSymsp->__Vcoverage[325]);
    }
    if ((0x3cU < ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
                  + (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                              << 2U))))) {
        ++(vlSymsp->__Vcoverage[2293]);
    }
    if ((0x3cU >= ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
                   + (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                               << 2U))))) {
        ++(vlSymsp->__Vcoverage[2294]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out)))) {
        ++(vlSymsp->__Vcoverage[2059]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        ++(vlSymsp->__Vcoverage[2058]);
    }
    if ((0U != (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                      >> 9U)))) {
        ++(vlSymsp->__Vcoverage[2064]);
    }
    if ((0U == (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                      >> 9U)))) {
        ++(vlSymsp->__Vcoverage[2065]);
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3424]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3426]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3427]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3430]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3431]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3432]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3435]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3439]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3444]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3445]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3451]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3455]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3456]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3458]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3459]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3462]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3463]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3464]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3469]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3470]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3471]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3472]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3473]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3474]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3475]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3476]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3477]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3478]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3296]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3479]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3297]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3298]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3480]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3299]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3481]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3300]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3482]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3483]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3302]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3484]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3303]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3485]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3486]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3304]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3487]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3305]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3306]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3307]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3488]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3489]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3442]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3528]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3443]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3529]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3348]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3530]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3531]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3350]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3449]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3492]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3355]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3493]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3450]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3536]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3537]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3452]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3538]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3453]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3539]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3454]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3497]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3316]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3349]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3550]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3368]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3507]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3551]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3369]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3351]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3465]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3370]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3499]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3318]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3509]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3542]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3360]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3446]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3532]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3371]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3466]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3328]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3543]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3361]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3447]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3533]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3510]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3549]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3467]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3372]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3511]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3457]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3362]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3501]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3534]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3353]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3491]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3448]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3535]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3468]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3425]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3548]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3367]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3505]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3347]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3441]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3461]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3366]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3504]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3440]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3527]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3460]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3547]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3526]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3345]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3546]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3364]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3525]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3545]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3544]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3363]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3541]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3498]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3540]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3524]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3438]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3437]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3523]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3436]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3522]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3521]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3520]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3434]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3339]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3433]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3338]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3519]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3518]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3336]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3517]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3516]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3335]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3429]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3428]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3515]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3514]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3333]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3513]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3512]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3331]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3330]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3508]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3506]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3323]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3503]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3502]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3321]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3500]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3319]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3317]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3496]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3315]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3495]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3494]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3313]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3490]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3423]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3422]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3421]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3420]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3419]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3418]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3417]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3416]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3415]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3414]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3413]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3412]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3411]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3410]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3409]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3408]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3407]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3406]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3405]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3404]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3403]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3402]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3401]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3400]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3399]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3398]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3397]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3396]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3395]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3394]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3393]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3392]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3391]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3390]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3389]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3388]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3387]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3386]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3385]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3384]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3383]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3382]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3381]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3380]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3379]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3378]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3377]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3376]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3375]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3374]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3373]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3365]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3359]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3358]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3357]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3356]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3354]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3352]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3346]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3344]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3343]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3342]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3341]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3340]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3337]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3334]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3332]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3329]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3327]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3326]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3325]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3324]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3322]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3320]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3314]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3312]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3311]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3310]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3309]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)))) {
                                    ++(vlSymsp->__Vcoverage[3308]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))) {
                                    ++(vlSymsp->__Vcoverage[3301]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[2919]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        ++(vlSymsp->__Vcoverage[2918]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                  >> 2U)))) {
        ++(vlSymsp->__Vcoverage[2924]);
    }
    if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        ++(vlSymsp->__Vcoverage[2923]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__sample_clk_en)))) {
        ++(vlSymsp->__Vcoverage[627]);
    }
    if (vlTOPp->opl3__DOT__sample_clk_en) {
        ++(vlSymsp->__Vcoverage[626]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty)))) {
        if ((0x100U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data))) {
            ++(vlSymsp->__Vcoverage[170]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data) 
                      >> 8U)))) {
            ++(vlSymsp->__Vcoverage[169]);
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
            ++(vlSymsp->__Vcoverage[2917]);
        }
    }
    if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
            ++(vlSymsp->__Vcoverage[2921]);
        }
    }
    if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                      >> 2U)))) {
            ++(vlSymsp->__Vcoverage[2922]);
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3690]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3692]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3693]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3696]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3697]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3698]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3701]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3705]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3710]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3711]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3717]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3721]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3722]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3724]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3725]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3728]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3729]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3730]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3735]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3736]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3737]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3738]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3739]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3740]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3741]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3742]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3743]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3744]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3562]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3745]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3563]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3564]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3746]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3565]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3747]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3566]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3748]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3749]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3568]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3750]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3569]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3751]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3752]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3570]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3753]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3571]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3572]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3573]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3754]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3755]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3708]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3794]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3709]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3795]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3614]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3796]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3797]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3616]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3715]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3758]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3621]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3759]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3716]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3802]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3803]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3718]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3804]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3719]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3805]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3720]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3763]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3582]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3615]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3816]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3634]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3773]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3817]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3635]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3617]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3731]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3636]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3765]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3584]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3775]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3808]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3626]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3712]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3798]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3637]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3732]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3594]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3809]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3627]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3713]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3799]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3776]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3815]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3733]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3638]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3777]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3723]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3628]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3767]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3800]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3619]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3757]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3714]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3801]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3734]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3691]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3814]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3633]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3771]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3613]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3707]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3727]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3632]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3770]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3706]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3793]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3726]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3813]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3792]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3611]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3812]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3630]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3791]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3811]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3810]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3629]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3807]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3764]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3806]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3790]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3704]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3703]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3789]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3702]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3788]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3787]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3786]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3700]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3605]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3699]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3604]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3785]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3784]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3602]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3783]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3782]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3601]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3695]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3694]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3781]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3780]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3599]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3779]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
