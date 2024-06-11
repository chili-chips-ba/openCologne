// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3.h"
#include "Vopl3__Syms.h"

VL_INLINE_OPT void Vopl3::_sequent__TOP__11(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__11\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank.dob;
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2150]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2151]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2152]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2153]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[0U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2154]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2155]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2156]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2157]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[1U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2462]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1feU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2463]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1fdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2464]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1fbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2465]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1f7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2466]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1efU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2467]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1dfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2468]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1bfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2469]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x17fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[2470]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2471]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1feU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2472]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1fdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2473]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1fbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2474]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1f7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2475]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1efU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2476]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1dfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2477]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1bfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2478]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x17fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[2479]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1040]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[0U] 
            = ((6U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1041]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[0U] 
            = ((5U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1042]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[0U] 
            = ((3U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1043]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[1U] 
            = ((6U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1044]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[1U] 
            = ((5U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1045]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[1U] 
            = ((3U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1065]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1066]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1067]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1068]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xf7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[1069]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[1070]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[1071]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[1072]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1073]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1074]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1075]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1076]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xf7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[1077]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[1078]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[1079]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[1080]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1094]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3eU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1095]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3dU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1096]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3bU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1097]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x37U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[1098]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x2fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[1099]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1100]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3eU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1101]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3dU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1102]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3bU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1103]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x37U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[1104]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x2fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[1105]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((1U & (~ VL_ONEHOT_I((((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)) 
                               << 3U) | (((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)) 
                                          << 2U) | 
                                         (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)) 
                                           << 1U) | 
                                          (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: envelope_generator.sv:166: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/operator/src/envelope_generator.sv", 166, "");
        }
    }
    if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
        if ((2U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
            if ((4U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
                if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
                    ++(vlSymsp->__Vcoverage[2045]);
                }
            }
        }
    }
    if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
        if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
            ++(vlSymsp->__Vcoverage[2043]);
        }
    }
    if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
        ++(vlSymsp->__Vcoverage[2042]);
    }
    if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
        if ((2U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
            if ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
                ++(vlSymsp->__Vcoverage[2044]);
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0))) {
        ++(vlSymsp->__Vcoverage[1916]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0))) {
        ++(vlSymsp->__Vcoverage[1917]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0))) {
        ++(vlSymsp->__Vcoverage[1918]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0))) {
        ++(vlSymsp->__Vcoverage[1919]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1937]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1feU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1938]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1fdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1939]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1fbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1940]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1f7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1941]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1efU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1942]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1dfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1943]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x1bfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1944]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0x17fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0))) {
        ++(vlSymsp->__Vcoverage[1945]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0 
            = ((0xffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws))) {
        ++(vlSymsp->__Vcoverage[876]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws))) {
        ++(vlSymsp->__Vcoverage[877]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws))) {
        ++(vlSymsp->__Vcoverage[878]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws) 
           & ((IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)
               ? 7U : 3U));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1055]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1056]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1057]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1058]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1059]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1060]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1061]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1062]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum 
        = ((0x300U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob));
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                >> 5U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon))) {
        ++(vlSymsp->__Vcoverage[897]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                     >> 5U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1090]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[1091]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                >> 2U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block))) {
        ++(vlSymsp->__Vcoverage[894]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block)) 
               | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                        >> 2U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                >> 3U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[895]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block)) 
               | (2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                        >> 2U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                >> 4U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block 
                          >> 2U)))) {
        ++(vlSymsp->__Vcoverage[896]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block)) 
               | (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                        >> 2U)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0 
        = (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0) 
            & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                  >> 5U))) & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0 
        = ((((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0)) 
             & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                >> 5U)) | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__rhythm_kon_pulse)) 
           & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum 
        = ((0xffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)) 
           | (0x300U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                        << 8U)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0))) {
        ++(vlSymsp->__Vcoverage[2795]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0))) {
        ++(vlSymsp->__Vcoverage[2796]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0))) {
        ++(vlSymsp->__Vcoverage[2797]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__key_off_pulse_p0)) {
        ++(vlSymsp->__Vcoverage[1375]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__key_off_pulse_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0;
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0) {
        ++(vlSymsp->__Vcoverage[2048]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0)))) {
        if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0) {
            ++(vlSymsp->__Vcoverage[2046]);
        }
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0)))) {
        if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0)))) {
            ++(vlSymsp->__Vcoverage[2047]);
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__key_on_pulse_p0)) {
        ++(vlSymsp->__Vcoverage[1374]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__key_on_pulse_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[884]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3feU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[885]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3fdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[886]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3fbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[887]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3f7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[888]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3efU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[889]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3dfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[890]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x3bfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[891]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x37fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[892]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x2ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum))) {
        ++(vlSymsp->__Vcoverage[893]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum 
            = ((0x1ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp0_p0 
        = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__nts)
                  ? ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                     >> 8U) : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 9U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
        = (0xfffffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                       << (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                                 >> 2U))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp0_p0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp0_p0)) {
        ++(vlSymsp->__Vcoverage[2199]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp0_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp0_p0;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp0_p0) 
                   | (0xeU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                              >> 1U))));
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1774]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1775]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1776]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1777]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1778]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1779]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1780]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1781]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1782]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1783]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1784]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1785]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1786]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1787]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1788]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1789]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1790]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1791]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1792]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0))) {
        ++(vlSymsp->__Vcoverage[1793]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0))) {
        ++(vlSymsp->__Vcoverage[2200]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0))) {
        ++(vlSymsp->__Vcoverage[2201]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0))) {
        ++(vlSymsp->__Vcoverage[2202]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0))) {
        ++(vlSymsp->__Vcoverage[2203]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0)));
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__12(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__12\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                >> 6U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl))) {
        ++(vlSymsp->__Vcoverage[852]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl)) 
               | (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                        >> 6U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                >> 7U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[853]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl)) 
               | (2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                        >> 6U)));
    }
    if ((1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl))) {
        ++(vlSymsp->__Vcoverage[854]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl)) 
               | (1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    }
    if ((2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl))) {
        ++(vlSymsp->__Vcoverage[855]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl)) 
               | (2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    }
    if ((4U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl))) {
        ++(vlSymsp->__Vcoverage[856]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl)) 
               | (4U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    }
    if ((8U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl))) {
        ++(vlSymsp->__Vcoverage[857]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl)) 
               | (8U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    }
    if ((0x10U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl))) {
        ++(vlSymsp->__Vcoverage[858]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl)) 
               | (0x10U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    }
    if ((0x20U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl))) {
        ++(vlSymsp->__Vcoverage[859]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl)) 
               | (0x20U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                >> 4U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar))) {
        ++(vlSymsp->__Vcoverage[860]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar)) 
               | (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                >> 5U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[861]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar)) 
               | (2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                >> 6U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
                          >> 2U)))) {
        ++(vlSymsp->__Vcoverage[862]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar)) 
               | (4U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                >> 7U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
                          >> 3U)))) {
        ++(vlSymsp->__Vcoverage[863]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar)) 
               | (8U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr))) {
        ++(vlSymsp->__Vcoverage[864]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr)) 
               | (1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob)));
    }
    if ((2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr))) {
        ++(vlSymsp->__Vcoverage[865]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr)) 
               | (2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob)));
    }
    if ((4U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr))) {
        ++(vlSymsp->__Vcoverage[866]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr)) 
               | (4U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob)));
    }
    if ((8U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr))) {
        ++(vlSymsp->__Vcoverage[867]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr)) 
               | (8U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                >> 4U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl))) {
        ++(vlSymsp->__Vcoverage[868]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl)) 
               | (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                >> 5U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[869]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl)) 
               | (2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                >> 6U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
                          >> 2U)))) {
        ++(vlSymsp->__Vcoverage[870]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl)) 
               | (4U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                >> 7U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
                          >> 3U)))) {
        ++(vlSymsp->__Vcoverage[871]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl)) 
               | (8U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                        >> 4U)));
    }
    if ((1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr))) {
        ++(vlSymsp->__Vcoverage[872]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr)) 
               | (1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob)));
    }
    if ((2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr))) {
        ++(vlSymsp->__Vcoverage[873]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr)) 
               | (2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob)));
    }
    if ((4U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr))) {
        ++(vlSymsp->__Vcoverage[874]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr)) 
               | (4U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob)));
    }
    if ((8U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr))) {
        ++(vlSymsp->__Vcoverage[875]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr)) 
               | (8U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob)));
    }
    if ((0x80U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) {
        ++(vlSymsp->__Vcoverage[2064]);
    }
    if ((1U & (~ ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                  >> 7U)))) {
        ++(vlSymsp->__Vcoverage[2065]);
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                >> 7U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__am))) {
        ++(vlSymsp->__Vcoverage[844]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__am 
            = (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                     >> 7U));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                >> 6U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__vib))) {
        ++(vlSymsp->__Vcoverage[845]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__vib 
            = (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                     >> 6U));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                >> 5U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__egt))) {
        ++(vlSymsp->__Vcoverage[846]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__egt 
            = (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                     >> 5U));
    }
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                >> 4U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksr))) {
        ++(vlSymsp->__Vcoverage[847]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksr 
            = (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                     >> 4U));
    }
    if ((1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult))) {
        ++(vlSymsp->__Vcoverage[848]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult)) 
               | (1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)));
    }
    if ((2U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult))) {
        ++(vlSymsp->__Vcoverage[849]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult)) 
               | (2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)));
    }
    if ((4U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult))) {
        ++(vlSymsp->__Vcoverage[850]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult)) 
               | (4U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)));
    }
    if ((8U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult))) {
        ++(vlSymsp->__Vcoverage[851]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult)) 
               | (8U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2 
        = (0x7ffU & ((0x80U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))
                      ? ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2) 
                           + (0xfcU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                                       >> 4U))) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)) 
                         + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2))
                      : (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2) 
                          + (0xfcU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                                      >> 4U))) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__envelope_generator__egt 
        = (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
            >> 5U) & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0 
        = (0xfU & ((0x10U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))
                    ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0)
                    : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0) 
                       >> 2U)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1989]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7feU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1990]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7fdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1991]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7fbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1992]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7f7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1993]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7efU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1994]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7dfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1995]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x7bfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1996]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x77fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1997]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x6ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1998]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x5ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2))) {
        ++(vlSymsp->__Vcoverage[1999]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2 
            = ((0x3ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__envelope_generator__egt) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__egt)) {
        ++(vlSymsp->__Vcoverage[1914]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__egt 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__envelope_generator__egt;
    }
    if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
            = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0))
                ? 2U : 1U);
    } else {
        if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
                = (((0x1ffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                               >> 4U)) >= (0xfU & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob) 
                                                   >> 4U)))
                    ? 4U : 2U);
        } else {
            if ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
                    = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__envelope_generator__egt)
                        ? 4U : 8U);
            } else {
                if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 = 8U;
                }
            }
        }
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
            = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0))
                ? 2U : 1U);
    } else {
        if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 = 8U;
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0))) {
        ++(vlSymsp->__Vcoverage[2204]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0))) {
        ++(vlSymsp->__Vcoverage[2205]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0))) {
        ++(vlSymsp->__Vcoverage[2206]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0))) {
        ++(vlSymsp->__Vcoverage[2207]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0)));
    }
    if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
        ++(vlSymsp->__Vcoverage[2050]);
    }
    if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
        if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
            ++(vlSymsp->__Vcoverage[2051]);
        }
    }
    if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
        if ((2U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
            if ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                ++(vlSymsp->__Vcoverage[2052]);
            }
        }
    }
    if ((1U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
        if ((2U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
            if ((4U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                    ++(vlSymsp->__Vcoverage[2053]);
                }
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)) 
                               << 3U) | (((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)) 
                                          << 2U) | 
                                         (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)) 
                                           << 1U) | 
                                          (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: envelope_generator.sv:180: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/operator/src/envelope_generator.sv", 180, "");
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0))) {
        ++(vlSymsp->__Vcoverage[1920]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0))) {
        ++(vlSymsp->__Vcoverage[1921]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0))) {
        ++(vlSymsp->__Vcoverage[1922]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0))) {
        ++(vlSymsp->__Vcoverage[1923]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)));
    }
    if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 
            = (0xfU & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob) 
                       >> 4U));
    } else {
        if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 
                = (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.dob));
        } else {
            if ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 = 0U;
            } else {
                if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 
                        = (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.dob));
                }
            }
        }
    }
    if (((0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__in)) {
        ++(vlSymsp->__Vcoverage[2327]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__in 
            = (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0))) {
        ++(vlSymsp->__Vcoverage[1982]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0))) {
        ++(vlSymsp->__Vcoverage[1983]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0))) {
        ++(vlSymsp->__Vcoverage[1984]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0))) {
        ++(vlSymsp->__Vcoverage[1985]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)));
    }
    if ((1U & ((0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                         << 2U)) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0))) {
        ++(vlSymsp->__Vcoverage[2215]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0)) 
               | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                        << 2U)));
    }
    if ((1U & ((0x1eU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                         << 1U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
                                    >> 1U)))) {
        ++(vlSymsp->__Vcoverage[2216]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
            = (0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0));
    }
    if ((1U & ((0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)) 
               ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
                  >> 2U)))) {
        ++(vlSymsp->__Vcoverage[2217]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0)) 
               | (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                        << 2U)));
    }
    if ((1U & ((7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                      >> 1U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
                                 >> 3U)))) {
        ++(vlSymsp->__Vcoverage[2218]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0)) 
               | (8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                        << 2U)));
    }
    if ((1U & ((3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                      >> 2U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
                                 >> 4U)))) {
        ++(vlSymsp->__Vcoverage[2219]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0)) 
               | (0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                           << 2U)));
    }
    if ((1U & ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                      >> 3U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
                                 >> 5U)))) {
        ++(vlSymsp->__Vcoverage[2220]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0)) 
               | (0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                           << 2U)));
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__13(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__13\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*15:0*/ __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
    CData/*5:0*/ __Vdlyvdim0__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0;
    SData/*9:0*/ __Vdlyvval__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0;
    // Body
    __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs 
        = vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
    ++(vlSymsp->__Vcoverage[281]);
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
         & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
        ++(vlSymsp->__Vcoverage[279]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
                  & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))))) {
        ++(vlSymsp->__Vcoverage[280]);
    }
    ++(vlSymsp->__Vcoverage[167]);
    ++(vlSymsp->__Vcoverage[176]);
    ++(vlSymsp->__Vcoverage[312]);
    __Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 = 0U;
    vlTOPp->opl3__DOT__host_if__DOT__wr_p2 = vlTOPp->opl3__DOT__host_if__DOT__wr_p1;
    vlTOPp->opl3__DOT__host_if__DOT__wr_p1_n = vlTOPp->wr_n;
    vlTOPp->opl3__DOT__host_if__DOT__cs_p1_n = vlTOPp->cs_n;
    __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs 
        = ((0xff00U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                       << 8U)) | (IData)(vlTOPp->opl3__DOT__status));
    vlTOPp->opl3__DOT__host_if__DOT__din_p1 = vlTOPp->din;
    vlTOPp->opl3__DOT__host_if__DOT__host_status_p1 
        = (0xffU & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                    >> 8U));
    vlTOPp->opl3__DOT__host_if__DOT__address_p1 = vlTOPp->address;
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
         & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
        __Vdlyvval__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 
            = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data;
        __Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 = 1U;
        __Vdlyvdim0__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 
            = (0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr));
    }
    vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs 
        = __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
    if (__Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0) {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__mem[__Vdlyvdim0__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0] 
            = __Vdlyvval__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0;
    }
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p2) 
         ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p2)) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p2 
            = vlTOPp->opl3__DOT__host_if__DOT__wr_p2;
    }
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1_n) 
         ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p1_n)) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p1_n 
            = vlTOPp->opl3__DOT__host_if__DOT__wr_p1_n;
    }
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__cs_p1_n) 
         ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__cs_p1_n)) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__cs_p1_n 
            = vlTOPp->opl3__DOT__host_if__DOT__cs_p1_n;
    }
    vlTOPp->opl3__DOT__host_if__DOT__wr_p1 = (1U & 
                                              ((~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__cs_p1_n)) 
                                               & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1_n))));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__din_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 8U) ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                        >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 9U) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                        >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 0xaU) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                            >> 2U)))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                        >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 0xbU) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                            >> 3U)))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                        >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 0xcU) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                            >> 4U)))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                           >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 0xdU) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                            >> 5U)))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                           >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 0xeU) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                            >> 6U)))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                           >> 8U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                >> 0xfU) ^ (vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
                            >> 7U)))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__host_status)) 
               | (0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                           >> 8U)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xfffeU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xfffdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xfffbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xfff7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xffefU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xffdfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xffbfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs 
            = ((0xff7fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__address_p1))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__address_p1 
            = ((2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__address_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1) 
               ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__address_p1))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__address_p1 
            = ((1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__address_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1)));
    }
    vlTOPp->dout = ((0U == (IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1))
                     ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)
                     : 0xffU);
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data 
        = (((IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1) 
            << 8U) | (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1));
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1) 
         ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p1)) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p1 
            = vlTOPp->opl3__DOT__host_if__DOT__wr_p1;
    }
    if ((1U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xfeU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((2U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xfdU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (2U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((4U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xfbU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (4U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((8U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xf7U 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (8U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x10U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xefU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x10U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x20U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xdfU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x20U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x40U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xbfU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x40U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x80U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0x7fU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x80U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3feU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3fdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3fbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3f7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3efU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3dfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3bfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x37fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                   ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x2ffU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                   ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x1ffU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__14(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__14\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[285]);
    ++(vlSymsp->__Vcoverage[292]);
    ++(vlSymsp->__Vcoverage[299]);
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        ++(vlSymsp->__Vcoverage[284]);
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        ++(vlSymsp->__Vcoverage[291]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        ++(vlSymsp->__Vcoverage[290]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        ++(vlSymsp->__Vcoverage[298]);
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) {
            ++(vlSymsp->__Vcoverage[296]);
        }
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read)))) {
            ++(vlSymsp->__Vcoverage[297]);
        }
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
                      & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty)))))) {
            ++(vlSymsp->__Vcoverage[283]);
        }
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty)))) {
            ++(vlSymsp->__Vcoverage[282]);
        }
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) {
            vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty 
                = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty;
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty = 1U;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)
            ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)
            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty) 
         ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__opl3_fifo_empty)) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__opl3_fifo_empty 
            = vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty;
    }
    if ((1U & ((~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty)) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_rd))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_rd 
            = (1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray)));
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)
            ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)
            : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross)));
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__15(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__15\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[278]);
    ++(vlSymsp->__Vcoverage[289]);
    if ((1U & (~ (IData)(vlTOPp->ic_n)))) {
        ++(vlSymsp->__Vcoverage[277]);
    }
    if (vlTOPp->ic_n) {
        ++(vlSymsp->__Vcoverage[288]);
    }
    if ((1U & (~ (IData)(vlTOPp->ic_n)))) {
        ++(vlSymsp->__Vcoverage[287]);
    }
    if (vlTOPp->ic_n) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
                      & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))))) {
            ++(vlSymsp->__Vcoverage[276]);
        }
    }
    if (vlTOPp->ic_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
            ++(vlSymsp->__Vcoverage[275]);
        }
    }
    if (vlTOPp->ic_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray 
                = (0x7fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                            ^ (0x3fU & (((IData)(1U) 
                                         + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                                        >> 1U))));
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray = 0U;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray 
        = ((IData)(vlTOPp->ic_n) ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)
            : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray)));
    }
    if (vlTOPp->ic_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr 
                = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_wr_addr;
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr = 0U;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray)));
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross 
        = ((IData)(vlTOPp->ic_n) ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)
            : 0U);
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
           == ((0x60U & ((~ ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
                             >> 5U)) << 5U)) | (0x1fU 
                                                & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray))));
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full) 
         ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__o_wr_full)) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__o_wr_full 
            = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_wr_addr 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
    }
    if ((1U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (1U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((0x3fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                         >> 1U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
                                    >> 1U)))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (2U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((0x1fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                         >> 2U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
                                    >> 2U)))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (4U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((0xfU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                        >> 3U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
                                   >> 3U)))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (8U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((7U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                      >> 4U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
                                 >> 4U)))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (0x10U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((3U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                      >> 5U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
                                 >> 5U)))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (0x20U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((1U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                      >> 6U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
                                 >> 6U)))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr)) 
               | (0x40U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr))));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)));
    }
}

VL_INLINE_OPT void Vopl3::_combo__TOP__19(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_combo__TOP__19\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((1U & (~ ((1U 
                                                   == 
                                                   ((2U 
                                                     & ((IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 2U)) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                  | (2U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 2U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))) {
                                        if ((3U != 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 2U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                            ++(vlSymsp->__Vcoverage[671]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((1U & (~ ((1U 
                                                   == 
                                                   ((2U 
                                                     & ((IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 3U)) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (IData)(
                                                                 (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                  >> 1U))))) 
                                                  | (2U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 3U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(
                                                                   (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                    >> 1U))))))))) {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 3U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(
                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                            >> 1U)))))) {
                                            ++(vlSymsp->__Vcoverage[667]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if (((1U == ((2U 
                                                  & ((IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 3U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (IData)(
                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                               >> 1U))))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(
                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                >> 3U)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 1U))))))) {
                                        ++(vlSymsp->__Vcoverage[666]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if (((1U == ((2U 
                                                  & ((IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 2U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(
                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                >> 2U)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))) {
                                        ++(vlSymsp->__Vcoverage[669]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((1U & (~ ((1U == ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 3U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(
                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                            >> 1U))))) 
                                      | (2U == ((2U 
                                                 & ((IData)(
                                                            (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                             >> 3U)) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 1U))))))))) {
                            if ((3U != ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 3U)) 
                                               << 1U)) 
                                        | (1U & (IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 1U)))))) {
                                ++(vlSymsp->__Vcoverage[645]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if (((1U == ((2U & ((IData)(
                                                    (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                     >> 2U)) 
                                            << 1U)) 
                                     | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                             | (2U == ((2U & ((IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 2U)) 
                                              << 1U)) 
                                       | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))) {
                            ++(vlSymsp->__Vcoverage[646]);
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((1U & (~ ((1U 
                                                   == 
                                                   ((2U 
                                                     & ((IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 2U)) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                  | (2U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 2U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))) {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 2U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                            ++(vlSymsp->__Vcoverage[670]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((1U & (~ ((1U == ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 3U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(
                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                            >> 1U))))) 
                                      | (2U == ((2U 
                                                 & ((IData)(
                                                            (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                             >> 3U)) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 1U))))))))) {
                            if ((3U == ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 3U)) 
                                               << 1U)) 
                                        | (1U & (IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 1U)))))) {
                                ++(vlSymsp->__Vcoverage[644]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((1U & (~ ((1U 
                                                   == 
                                                   ((2U 
                                                     & ((IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 3U)) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (IData)(
                                                                 (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                  >> 1U))))) 
                                                  | (2U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 3U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(
                                                                   (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                    >> 1U))))))))) {
                                        if ((3U != 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 3U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(
                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                            >> 1U)))))) {
                                            ++(vlSymsp->__Vcoverage[668]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((1U & (~ ((1U == ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 2U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                      | (2U == ((2U 
                                                 & ((IData)(
                                                            (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                             >> 2U)) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))) {
                            if ((3U == ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 2U)) 
                                               << 1U)) 
                                        | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                ++(vlSymsp->__Vcoverage[647]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if (((1U == ((2U & ((IData)(
                                                    (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                     >> 3U)) 
                                            << 1U)) 
                                     | (1U & (IData)(
                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                      >> 1U))))) 
                             | (2U == ((2U & ((IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 3U)) 
                                              << 1U)) 
                                       | (1U & (IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 1U))))))) {
                            ++(vlSymsp->__Vcoverage[643]);
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((1U & (~ ((1U == ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 2U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                      | (2U == ((2U 
                                                 & ((IData)(
                                                            (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                             >> 2U)) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))) {
                            if ((3U != ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 2U)) 
                                               << 1U)) 
                                        | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                ++(vlSymsp->__Vcoverage[648]);
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = (1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                          >> 0x26U)) & (~ (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                           >> 0x11U))));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = (1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                          >> 0x26U)) & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                        >> 0x11U)));
}

VL_INLINE_OPT void Vopl3::_combo__TOP__20(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_combo__TOP__20\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank.dob;
    vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank.dob;
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[693]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfeU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[694]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfdU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[695]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfbU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[696]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xf7U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[697]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xefU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[698]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xdfU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[699]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xbfU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[700]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7fU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[701]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfeU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[702]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfdU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[703]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfbU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[704]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xf7U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[705]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xefU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[706]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xdfU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[707]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xbfU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[708]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7fU & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
        [(1U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                >> 0x11U))];
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((0U != ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                      >> 0xcU))))) {
                                        if ((1U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                << 1U)) 
                                              | (1U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    >> 0xcU))))) {
                                            ++(vlSymsp->__Vcoverage[661]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((0U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                      >> 0xcU))))) {
                                        ++(vlSymsp->__Vcoverage[660]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((0U != ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                      >> 0xcU))))) {
                                        if ((1U != 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                << 1U)) 
                                              | (1U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    >> 0xcU))))) {
                                            if ((2U 
                                                 != 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                        >> 0xcU))))) {
                                                if (
                                                    (3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                            >> 0xcU))))) {
                                                    ++(vlSymsp->__Vcoverage[663]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U != vlTOPp->opl3__DOT__channels__DOT__state)) {
            if ((1U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                if ((2U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                    if ((3U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                        if ((4U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                            if ((5U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                if ((6U != vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    if ((0U != ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                      >> 0xcU))))) {
                                        if ((1U != 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                << 1U)) 
                                              | (1U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    >> 0xcU))))) {
                                            if ((2U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                        >> 0xcU))))) {
                                                ++(vlSymsp->__Vcoverage[662]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 4U) ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__cha))) {
        ++(vlSymsp->__Vcoverage[409]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__cha 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                     >> 4U));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 5U) ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__chb))) {
        ++(vlSymsp->__Vcoverage[410]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__chb 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                     >> 5U));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 6U) ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__chc))) {
        ++(vlSymsp->__Vcoverage[411]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__chc 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                     >> 6U));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 7U) ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__chd))) {
        ++(vlSymsp->__Vcoverage[412]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__chd 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                     >> 7U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__cnt))) {
        ++(vlSymsp->__Vcoverage[413]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__cnt 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy))) {
        ++(vlSymsp->__Vcoverage[414]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy)) 
               | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                        >> 1U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 2U) ^ (vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[415]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy)) 
               | (2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                        >> 1U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                >> 3U) ^ (vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy 
                          >> 2U)))) {
        ++(vlSymsp->__Vcoverage[416]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__fb_dummy)) 
               | (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                        >> 1U)));
    }
    vlTOPp->opl3__DOT__channels__DOT__next_state = vlTOPp->opl3__DOT__channels__DOT__state;
    vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__self[0U];
    vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__self[1U];
    vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
        = vlTOPp->opl3__DOT__channels__DOT__self[2U];
    vlTOPp->opl3__DOT__channels__DOT__signals = 0ULL;
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U == vlTOPp->opl3__DOT__channels__DOT__state)) {
            if (vlTOPp->opl3__DOT__channels__DOT__ops_done_pulse) {
                vlTOPp->opl3__DOT__channels__DOT__next_state = 1U;
            }
        } else {
            if ((1U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                vlTOPp->opl3__DOT__channels__DOT__next_state = 2U;
                vlTOPp->opl3__DOT__channels__DOT__signals 
                    = ((0x7fffffffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                       | ((QData)((IData)((0x1fU & 
                                           ((IData)(3U) 
                                            + ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                << 0x14U) 
                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                  >> 0xcU)))))) 
                          << 0x27U));
                vlTOPp->opl3__DOT__channels__DOT__signals 
                    = (0x4000000000ULL | vlTOPp->opl3__DOT__channels__DOT__signals);
            } else {
                if ((2U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                    vlTOPp->opl3__DOT__channels__DOT__next_state = 3U;
                    vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                        = ((0x8003ffffU & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                           | (0xfffc0000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                             << 0x12U)));
                    vlTOPp->opl3__DOT__channels__DOT__signals 
                        = ((0x7fffffffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                           | ((QData)((IData)((0x1fU 
                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                   << 0x14U) 
                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                     >> 0xcU))))) 
                              << 0x27U));
                    vlTOPp->opl3__DOT__channels__DOT__signals 
                        = (0x4000000000ULL | vlTOPp->opl3__DOT__channels__DOT__signals);
                } else {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        vlTOPp->opl3__DOT__channels__DOT__signals 
                            = ((0xfc3ffffffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                               | ((QData)((IData)((0xfU 
                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                       << 0x18U) 
                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                         >> 8U))))) 
                                  << 0x22U));
                        vlTOPp->opl3__DOT__channels__DOT__signals 
                            = ((0xffc000fffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                               | ((QData)((IData)((0x3fffU 
                                                   & ((1U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob))
                                                       ? 
                                                      ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                       + 
                                                       (0x1fffU 
                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                            << 0xeU) 
                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                              >> 0x12U))))
                                                       : 
                                                      (0x1fffU 
                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                           << 0xeU) 
                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x12U))))))) 
                                  << 0x14U));
                        if (((IData)(vlTOPp->opl3__DOT__channels__DOT__ryt) 
                             & (~ (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                   >> 0x11U)))) {
                            if ((6U == (0xfU & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                 << 0x18U) 
                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                   >> 8U))))) {
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffc000fffffULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          ((1U 
                                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob))
                                                            ? 
                                                           (0x1fffU 
                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                << 0xeU) 
                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                  >> 0x12U)))
                                                            : (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)))) 
                                          << 0x14U));
                            } else {
                                if (((7U == (0xfU & 
                                             ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                               << 0x18U) 
                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                 >> 8U)))) 
                                     | (8U == (0xfU 
                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                     >> 8U)))))) {
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0xffc000fffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0x3fffU 
                                                               & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                  + 
                                                                  (0x1fffU 
                                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                       << 0xeU) 
                                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                         >> 0x12U))))))) 
                                              << 0x14U));
                                }
                            }
                            if ((1U & (~ VL_ONEHOT0_I(
                                                      (((8U 
                                                         == 
                                                         (0xfU 
                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                >> 8U)))) 
                                                        << 2U) 
                                                       | (((7U 
                                                            == 
                                                            (0xfU 
                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                 << 0x18U) 
                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                   >> 8U)))) 
                                                           << 1U) 
                                                          | (6U 
                                                             == 
                                                             (0xfU 
                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                  << 0x18U) 
                                                                 | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                    >> 8U)))))))))) {
                                if (VL_UNLIKELY(Verilated::assertOn())) {
                                    VL_WRITEF("[%0t] %%Error: channels.sv:202: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                              64,VL_TIME_UNITED_Q(1000),
                                              vlSymsp->name());
                                    VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 202, "");
                                }
                            }
                        }
                        if ((3U > (0xfU & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                            << 0x18U) 
                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                              >> 8U))))) {
                            if ((0x20000U & vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffff7ULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                               >> 4U) 
                                                              & (~ 
                                                                 ((5U 
                                                                   >= 
                                                                   (7U 
                                                                    & ((IData)(3U) 
                                                                       + 
                                                                       (0xfU 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))))) 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                     >> 
                                                                     (7U 
                                                                      & ((IData)(3U) 
                                                                         + 
                                                                         (0xfU 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))))) 
                                          << 3U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffbULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                               >> 5U) 
                                                              & (~ 
                                                                 ((5U 
                                                                   >= 
                                                                   (7U 
                                                                    & ((IData)(3U) 
                                                                       + 
                                                                       (0xfU 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))))) 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                     >> 
                                                                     (7U 
                                                                      & ((IData)(3U) 
                                                                         + 
                                                                         (0xfU 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))))) 
                                          << 2U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffdULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                               >> 6U) 
                                                              & (~ 
                                                                 ((5U 
                                                                   >= 
                                                                   (7U 
                                                                    & ((IData)(3U) 
                                                                       + 
                                                                       (0xfU 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))))) 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                     >> 
                                                                     (7U 
                                                                      & ((IData)(3U) 
                                                                         + 
                                                                         (0xfU 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))))) 
                                          << 1U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffeULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | (IData)((IData)(
                                                         (1U 
                                                          & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                              >> 7U) 
                                                             & (~ 
                                                                ((5U 
                                                                  >= 
                                                                  (7U 
                                                                   & ((IData)(3U) 
                                                                      + 
                                                                      (0xfU 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))))) 
                                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                    >> 
                                                                    (7U 
                                                                     & ((IData)(3U) 
                                                                        + 
                                                                        (0xfU 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U)))))))))))));
                            } else {
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffff7ULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                              | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                  >> 4U) 
                                                                 & (~ 
                                                                    ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U))))))))))) 
                                          << 3U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffbULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                              | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                  >> 5U) 
                                                                 & (~ 
                                                                    ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U))))))))))) 
                                          << 2U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffdULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                              | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                  >> 6U) 
                                                                 & (~ 
                                                                    ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U))))))))))) 
                                          << 1U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffeULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | (IData)((IData)(
                                                         (1U 
                                                          & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                             | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                 >> 7U) 
                                                                & (~ 
                                                                   ((5U 
                                                                     >= 
                                                                     (7U 
                                                                      & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                          << 0x18U) 
                                                                         | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                            >> 8U)))) 
                                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                       >> 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U))))))))))));
                            }
                        } else {
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffff7ULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (1U 
                                                       & (((~ 
                                                            (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x11U)) 
                                                           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                             >> 4U))))) 
                                      << 3U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffffbULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (1U 
                                                       & (((~ 
                                                            (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x11U)) 
                                                           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                             >> 5U))))) 
                                      << 2U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffffdULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (1U 
                                                       & (((~ 
                                                            (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x11U)) 
                                                           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                             >> 6U))))) 
                                      << 1U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffffeULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | (IData)((IData)(
                                                     (1U 
                                                      & (((~ 
                                                           (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                            >> 0x11U)) 
                                                          & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                         | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                            >> 7U))))));
                        }
                        if (((1U == ((2U & ((IData)(
                                                    (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                     >> 3U)) 
                                            << 1U)) 
                                     | (1U & (IData)(
                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                      >> 1U))))) 
                             | (2U == ((2U & ((IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 3U)) 
                                              << 1U)) 
                                       | (1U & (IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 1U))))))) {
                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                = ((0xfffffU & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                   | (0xfff00000U & 
                                      ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                          << 0xcU) 
                                         | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                            >> 0x14U)) 
                                        + VL_EXTENDS_II(20,14, 
                                                        (0x3fffU 
                                                         & (IData)(
                                                                   (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                    >> 0x14U))))) 
                                       << 0x14U)));
                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                = ((0xffffff00U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                   | (0xffU & ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                  << 0xcU) 
                                                 | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                    >> 0x14U)) 
                                                + VL_EXTENDS_II(20,14, 
                                                                (0x3fffU 
                                                                 & (IData)(
                                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                            >> 0x14U))))) 
                                               >> 0xcU)));
                        } else {
                            if ((3U == ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 3U)) 
                                               << 1U)) 
                                        | (1U & (IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 1U)))))) {
                                vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                    = ((0xfffffU & 
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                       | (0xfff00000U 
                                          & ((VL_EXTENDS_II(20,20, 
                                                            (0xfffffU 
                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                 << 0xcU) 
                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                   >> 0x14U)))) 
                                              + VL_MULS_III(20,32,32, (IData)(2U), 
                                                            VL_EXTENDS_II(32,14, 
                                                                          (0x3fffU 
                                                                           & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 0x14U)))))) 
                                             << 0x14U)));
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = ((0xffffff00U 
                                        & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                       | (0xffU & (
                                                   (VL_EXTENDS_II(20,20, 
                                                                  (0xfffffU 
                                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                       << 0xcU) 
                                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                         >> 0x14U)))) 
                                                    + 
                                                    VL_MULS_III(20,32,32, (IData)(2U), 
                                                                VL_EXTENDS_II(32,14, 
                                                                              (0x3fffU 
                                                                               & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 0x14U)))))) 
                                                   >> 0xcU)));
                            }
                        }
                        if ((1U & (~ VL_ONEHOT0_I((
                                                   ((3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 3U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(
                                                                   (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                    >> 1U))))) 
                                                    << 2U) 
                                                   | (((2U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(
                                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                      >> 3U)) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (IData)(
                                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                       >> 1U))))) 
                                                       << 1U) 
                                                      | (1U 
                                                         == 
                                                         ((2U 
                                                           & ((IData)(
                                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                       >> 3U)) 
                                                              << 1U)) 
                                                          | (1U 
                                                             & (IData)(
                                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                        >> 1U))))))))))) {
                            if (VL_UNLIKELY(Verilated::assertOn())) {
                                VL_WRITEF("[%0t] %%Error: channels.sv:229: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                          64,VL_TIME_UNITED_Q(1000),
                                          vlSymsp->name());
                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 229, "");
                            }
                        }
                        if (((1U == ((2U & ((IData)(
                                                    (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                     >> 2U)) 
                                            << 1U)) 
                                     | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                             | (2U == ((2U & ((IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 2U)) 
                                              << 1U)) 
                                       | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))) {
                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                = ((0xfff00000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                   | (0xfffffU & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                  + 
                                                  VL_EXTENDS_II(20,14, 
                                                                (0x3fffU 
                                                                 & (IData)(
                                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                            >> 0x14U)))))));
                        } else {
                            if ((3U == ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 2U)) 
                                               << 1U)) 
                                        | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                    = ((0xfff00000U 
                                        & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                       | (0xfffffU 
                                          & (VL_EXTENDS_II(20,20, 
                                                           (0xfffffU 
                                                            & vlTOPp->opl3__DOT__channels__DOT__self[0U])) 
                                             + VL_MULS_III(20,32,32, (IData)(2U), 
                                                           VL_EXTENDS_II(32,14, 
                                                                         (0x3fffU 
                                                                          & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 0x14U))))))));
                            }
                        }
                        if ((1U & (~ VL_ONEHOT0_I((
                                                   ((3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 2U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                    << 2U) 
                                                   | (((2U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(
                                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                      >> 2U)) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                       << 1U) 
                                                      | (1U 
                                                         == 
                                                         ((2U 
                                                           & ((IData)(
                                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                       >> 2U)) 
                                                              << 1U)) 
                                                          | (1U 
                                                             & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))))) {
                            if (VL_UNLIKELY(Verilated::assertOn())) {
                                VL_WRITEF("[%0t] %%Error: channels.sv:235: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                          64,VL_TIME_UNITED_Q(1000),
                                          vlSymsp->name());
                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 235, "");
                            }
                        }
                        if ((8U == (0xfU & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                             << 0x18U) 
                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                               >> 8U))))) {
                            if ((0x20000U & vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                vlTOPp->opl3__DOT__channels__DOT__next_state = 4U;
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffe0fffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffff0ffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffdffffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                            } else {
                                vlTOPp->opl3__DOT__channels__DOT__next_state = 1U;
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffe0fffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0x20000U | vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffff0ffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                            }
                        } else {
                            if ((1U & (~ VL_ONEHOT0_I(
                                                      (((5U 
                                                         == 
                                                         (0xfU 
                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                >> 8U)))) 
                                                        << 1U) 
                                                       | (2U 
                                                          == 
                                                          (0xfU 
                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                               << 0x18U) 
                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                 >> 8U))))))))) {
                                if (VL_UNLIKELY(Verilated::assertOn())) {
                                    VL_WRITEF("[%0t] %%Error: channels.sv:257: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                              64,VL_TIME_UNITED_Q(1000),
                                              vlSymsp->name());
                                    VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 257, "");
                                }
                            }
                            vlTOPp->opl3__DOT__channels__DOT__next_state = 1U;
                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                = ((0xfffe0fffU & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                   | (0xfffff000U & 
                                      (((2U == (0xfU 
                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                      >> 8U))))
                                         ? 6U : ((5U 
                                                  == 
                                                  (0xfU 
                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                       << 0x18U) 
                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                         >> 8U))))
                                                  ? 0xcU
                                                  : 
                                                 (0x1fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                         >> 0xcU)))))) 
                                       << 0xcU)));
                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                = ((0xfffff0ffU & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                   | (0xf00U & (((IData)(1U) 
                                                 + 
                                                 ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                     >> 8U))) 
                                                << 8U)));
                        }
                    } else {
                        if ((4U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                            vlTOPp->opl3__DOT__channels__DOT__next_state = 5U;
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0x7fffffffffULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (0x1fU 
                                                       & ((IData)(9U) 
                                                          + 
                                                          (0xfU 
                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                               << 0x18U) 
                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                 >> 8U))))))) 
                                      << 0x27U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = (0x4000000000ULL 
                                   | vlTOPp->opl3__DOT__channels__DOT__signals);
                        } else {
                            if ((5U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                                vlTOPp->opl3__DOT__channels__DOT__next_state = 6U;
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0x7fffffffffULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (0x1fU 
                                                           & ((IData)(6U) 
                                                              + 
                                                              (0xfU 
                                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                   << 0x18U) 
                                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     >> 8U))))))) 
                                          << 0x27U));
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = ((0x7fffffffU 
                                        & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                       | (0x80000000U 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                             << 0x1fU)));
                                vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                                    = ((0x1000U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]) 
                                       | (0x7fffffffU 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                             >> 1U)));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = (0x4000000000ULL 
                                       | vlTOPp->opl3__DOT__channels__DOT__signals);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                                    = ((0xfffU & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]) 
                                       | (0x1000U & 
                                          ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                           << 0xcU)));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xfc3ffffffffULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(3U) 
                                                              + 
                                                              ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                << 0x18U) 
                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                  >> 8U)))))) 
                                          << 0x22U));
                            } else {
                                if ((6U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    vlTOPp->opl3__DOT__channels__DOT__next_state = 7U;
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0xfc3ffffffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0xfU 
                                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                   << 0x18U) 
                                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     >> 8U))))) 
                                              << 0x22U));
                                    vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                        = ((0x8003ffffU 
                                            & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                           | (0xfffc0000U 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                 << 0x12U)));
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0x7fffffffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0x1fU 
                                                               & ((1U 
                                                                   == 
                                                                   ((2U 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                        << 1U)) 
                                                                    | (1U 
                                                                       & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                          >> 0xcU))))
                                                                   ? 
                                                                  ((IData)(3U) 
                                                                   + 
                                                                   (0xfU 
                                                                    & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                        << 0x18U) 
                                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                          >> 8U))))
                                                                   : 
                                                                  (0xfU 
                                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                       << 0x18U) 
                                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                         >> 8U))))))) 
                                              << 0x27U));
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = (0x4000000000ULL 
                                           | vlTOPp->opl3__DOT__channels__DOT__signals);
                                } else {
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0xfc3ffffffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0xfU 
                                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                   << 0x18U) 
                                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     >> 8U))))) 
                                              << 0x22U));
                                    if ((0U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                      >> 0xcU))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffff0001fULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (0x7fffU 
                                                                   & VL_EXTENDS_II(15,13, 
                                                                                (0x1fffU 
                                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 1U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                  << 5U));
                                    } else {
                                        if ((1U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                << 1U)) 
                                              | (1U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    >> 0xcU))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                                = (
                                                   (0xffffff0001fULL 
                                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                                   | ((QData)((IData)(
                                                                      (0x7fffU 
                                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                          + 
                                                                          (0x1fffU 
                                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                               << 1U) 
                                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                      << 5U));
                                        } else {
                                            if ((2U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                        >> 0xcU))))) {
                                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                                    = 
                                                    ((0xffffff0001fULL 
                                                      & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                                     | ((QData)((IData)(
                                                                        (0x7fffU 
                                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                            + 
                                                                            (0x1fffU 
                                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 1U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                        << 5U));
                                            } else {
                                                if (
                                                    (3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                            >> 0xcU))))) {
                                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        = 
                                                        ((0xffffff0001fULL 
                                                          & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                                         | ((QData)((IData)(
                                                                            (0x7fffU 
                                                                             & (((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                                + 
                                                                                (0x1fffU 
                                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0xeU) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x12U)))) 
                                                                                + 
                                                                                (0x1fffU 
                                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 1U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                            << 5U));
                                                }
                                            }
                                        }
                                    }
                                    if ((1U & (~ VL_ONEHOT_I(
                                                             (((3U 
                                                                == 
                                                                ((2U 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                     << 1U)) 
                                                                 | (1U 
                                                                    & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                       >> 0xcU)))) 
                                                               << 3U) 
                                                              | (((2U 
                                                                   == 
                                                                   ((2U 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                        << 1U)) 
                                                                    | (1U 
                                                                       & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                          >> 0xcU)))) 
                                                                  << 2U) 
                                                                 | (((1U 
                                                                      == 
                                                                      ((2U 
                                                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                           << 1U)) 
                                                                       | (1U 
                                                                          & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             >> 0xcU)))) 
                                                                     << 1U) 
                                                                    | (0U 
                                                                       == 
                                                                       ((2U 
                                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              >> 0xcU))))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: channels.sv:288: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 288, "");
                                        }
                                    }
                                    if ((0x20000U & 
                                         vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffff7ULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 4U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((IData)(3U) 
                                                                           + 
                                                                           (0xfU 
                                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((IData)(3U) 
                                                                             + 
                                                                             (0xfU 
                                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))) 
                                                  << 3U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffbULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 5U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((IData)(3U) 
                                                                           + 
                                                                           (0xfU 
                                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((IData)(3U) 
                                                                             + 
                                                                             (0xfU 
                                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))) 
                                                  << 2U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffdULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 6U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((IData)(3U) 
                                                                           + 
                                                                           (0xfU 
                                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((IData)(3U) 
                                                                             + 
                                                                             (0xfU 
                                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))) 
                                                  << 1U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffeULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | (IData)((IData)(
                                                                 (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                   >> 7U) 
                                                                  & ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((IData)(3U) 
                                                                          + 
                                                                          (0xfU 
                                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                               << 0x18U) 
                                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((IData)(3U) 
                                                                            + 
                                                                            (0xfU 
                                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))));
                                    } else {
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffff7ULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 4U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))) 
                                                  << 3U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffbULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 5U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))) 
                                                  << 2U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffdULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 6U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))) 
                                                  << 1U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffeULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | (IData)((IData)(
                                                                 (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                   >> 7U) 
                                                                  & ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U)))))))));
                                    }
                                    if (((1U == ((2U 
                                                  & ((IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 3U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (IData)(
                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                               >> 1U))))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(
                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                >> 3U)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 1U))))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                            = ((0xfffffU 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                               | (0xfff00000U 
                                                  & ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                        << 0xcU) 
                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                          >> 0x14U)) 
                                                      + 
                                                      VL_EXTENDS_II(20,15, 
                                                                    (0x7fffU 
                                                                     & (IData)(
                                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U))))) 
                                                     << 0x14U)));
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                            = ((0xffffff00U 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                               | (0xffU 
                                                  & ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                        << 0xcU) 
                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                          >> 0x14U)) 
                                                      + 
                                                      VL_EXTENDS_II(20,15, 
                                                                    (0x7fffU 
                                                                     & (IData)(
                                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U))))) 
                                                     >> 0xcU)));
                                    } else {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 3U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(
                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                            >> 1U)))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                                = (
                                                   (0xfffffU 
                                                    & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                                   | (0xfff00000U 
                                                      & ((VL_EXTENDS_II(20,20, 
                                                                        (0xfffffU 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             << 0xcU) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                               >> 0x14U)))) 
                                                          + 
                                                          VL_MULS_III(20,32,32, (IData)(2U), 
                                                                      VL_EXTENDS_II(32,15, 
                                                                                (0x7fffU 
                                                                                & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U)))))) 
                                                         << 0x14U)));
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                                = (
                                                   (0xffffff00U 
                                                    & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                                   | (0xffU 
                                                      & ((VL_EXTENDS_II(20,20, 
                                                                        (0xfffffU 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             << 0xcU) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                               >> 0x14U)))) 
                                                          + 
                                                          VL_MULS_III(20,32,32, (IData)(2U), 
                                                                      VL_EXTENDS_II(32,15, 
                                                                                (0x7fffU 
                                                                                & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U)))))) 
                                                         >> 0xcU)));
                                        }
                                    }
                                    if ((1U & (~ VL_ONEHOT0_I(
                                                              (((3U 
                                                                 == 
                                                                 ((2U 
                                                                   & ((IData)(
                                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                               >> 3U)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 1U))))) 
                                                                << 2U) 
                                                               | (((2U 
                                                                    == 
                                                                    ((2U 
                                                                      & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 3U)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 1U))))) 
                                                                   << 1U) 
                                                                  | (1U 
                                                                     == 
                                                                     ((2U 
                                                                       & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 3U)) 
                                                                          << 1U)) 
                                                                      | (1U 
                                                                         & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 1U))))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: channels.sv:312: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 312, "");
                                        }
                                    }
                                    if (((1U == ((2U 
                                                  & ((IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 2U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(
                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                >> 2U)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                            = ((0xfff00000U 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                               | (0xfffffU 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                     + 
                                                     VL_EXTENDS_II(20,15, 
                                                                   (0x7fffU 
                                                                    & (IData)(
                                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                               >> 5U)))))));
                                    } else {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 2U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                                = (
                                                   (0xfff00000U 
                                                    & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                                   | (0xfffffU 
                                                      & (VL_EXTENDS_II(20,20, 
                                                                       (0xfffffU 
                                                                        & vlTOPp->opl3__DOT__channels__DOT__self[0U])) 
                                                         + 
                                                         VL_MULS_III(20,32,32, (IData)(2U), 
                                                                     VL_EXTENDS_II(32,15, 
                                                                                (0x7fffU 
                                                                                & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U))))))));
                                        }
                                    }
                                    if ((1U & (~ VL_ONEHOT0_I(
                                                              (((3U 
                                                                 == 
                                                                 ((2U 
                                                                   & ((IData)(
                                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                               >> 2U)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                                << 2U) 
                                                               | (((2U 
                                                                    == 
                                                                    ((2U 
                                                                      & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 2U)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                                   << 1U) 
                                                                  | (1U 
                                                                     == 
                                                                     ((2U 
                                                                       & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 2U)) 
                                                                          << 1U)) 
                                                                      | (1U 
                                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: channels.sv:318: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 318, "");
                                        }
                                    }
                                    if ((2U == (0xfU 
                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                      >> 8U))))) {
                                        if ((0x20000U 
                                             & vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                            vlTOPp->opl3__DOT__channels__DOT__next_state = 8U;
                                        } else {
                                            vlTOPp->opl3__DOT__channels__DOT__next_state = 4U;
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                                = (0xfffff0ffU 
                                                   & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                                = (0x20000U 
                                                   | vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                        }
                                    } else {
                                        vlTOPp->opl3__DOT__channels__DOT__next_state = 4U;
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                            = ((0xfffff0ffU 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                               | (0xf00U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                        << 0x18U) 
                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                          >> 8U))) 
                                                     << 8U)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == vlTOPp->opl3__DOT__channels__DOT__state)) {
            vlTOPp->opl3__DOT__channels__DOT__next_state = 0U;
            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] = 0U;
            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] = 0U;
            vlTOPp->opl3__DOT__channels__DOT__next_self[2U] = 0U;
            vlTOPp->opl3__DOT__channels__DOT__signals 
                = (0x10ULL | vlTOPp->opl3__DOT__channels__DOT__signals);
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((8U == vlTOPp->opl3__DOT__channels__DOT__state) 
                               << 8U) | (((7U == vlTOPp->opl3__DOT__channels__DOT__state) 
                                          << 7U) | 
                                         (((6U == vlTOPp->opl3__DOT__channels__DOT__state) 
                                           << 6U) | 
                                          (((5U == vlTOPp->opl3__DOT__channels__DOT__state) 
                                            << 5U) 
                                           | (((4U 
                                                == vlTOPp->opl3__DOT__channels__DOT__state) 
                                               << 4U) 
                                              | (((3U 
                                                   == vlTOPp->opl3__DOT__channels__DOT__state) 
                                                  << 3U) 
                                                 | (((2U 
                                                      == vlTOPp->opl3__DOT__channels__DOT__state) 
                                                     << 2U) 
                                                    | (((1U 
                                                         == vlTOPp->opl3__DOT__channels__DOT__state) 
                                                        << 1U) 
                                                       | (0U 
                                                          == vlTOPp->opl3__DOT__channels__DOT__state))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: channels.sv:182: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv", 182, "");
        }
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[505]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0xfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x80000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[506]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0x7fffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x80000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[507]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1ffeU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[508]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1ffdU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[509]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1ffbU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[510]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1ff7U & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[511]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1fefU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[512]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1fdfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[513]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1fbfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[514]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1f7fU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[515]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1effU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[516]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1dffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[517]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x1bffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]))) {
        ++(vlSymsp->__Vcoverage[518]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U] 
            = ((0x17ffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[2U]) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[519]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffbffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[520]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfff7ffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[521]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffefffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[522]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffdfffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[523]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffbfffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[524]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xff7fffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[525]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfeffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[526]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfdffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x4000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[527]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfbffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x4000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x8000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[528]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xf7ffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x8000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x10000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[529]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xefffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x10000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x20000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[530]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xdfffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x20000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x40000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[531]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xbfffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x40000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[532]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffdffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[533]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffefffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[534]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffdfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[535]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffbfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[536]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffff7fffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[537]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffeffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[538]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffeffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[539]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffdffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[540]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffbffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[541]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffff7ffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[542]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffefffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[543]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffdfffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[544]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffbfffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[545]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xff7fffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[546]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfeffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[547]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfdffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x4000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[548]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfbffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x4000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x8000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[549]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xf7ffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x8000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x10000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[550]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xefffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x10000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x20000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[551]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xdfffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x20000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x40000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[552]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xbfffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x40000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x80000000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[553]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0x7fffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x80000000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[554]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffffeU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[555]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffffdU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[556]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffffbU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[557]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xfffffff7U & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[558]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffffefU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[559]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffffdfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[560]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffffbfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]))) {
        ++(vlSymsp->__Vcoverage[561]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U] 
            = ((0xffffff7fU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[1U]) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[562]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffffeU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[563]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffffdU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[564]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffffbU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[565]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffff7U & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[566]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffffefU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[567]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffffdfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[568]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffffbfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[569]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffff7fU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[570]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffeffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[571]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffdffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[572]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffffbffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[573]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffff7ffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[574]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffefffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[575]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffdfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[576]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffffbfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[577]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xffff7fffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[578]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffeffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[579]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffdffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[580]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfffbffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]))) {
        ++(vlSymsp->__Vcoverage[581]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U] 
            = ((0xfff7ffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__next_self[0U]) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]));
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__21(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__21\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__reset_sync__DOT__r2 = (1U & 
                                              ((~ (IData)(vlTOPp->ic_n)) 
                                               | (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r1)));
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U & (~ (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2)))) {
            ++(vlSymsp->__Vcoverage[2179]);
        }
    }
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if (vlTOPp->opl3__DOT__reset_sync__DOT__r2) {
            ++(vlSymsp->__Vcoverage[2178]);
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2) 
         ^ vlTOPp->opl3__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->opl3__DOT____Vtogcov__reset = vlTOPp->opl3__DOT__reset_sync__DOT__r2;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state;
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if (vlTOPp->opl3__DOT__reset_sync__DOT__r2) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state = 1U;
        }
    } else {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U == (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state = 0U;
                }
            }
        }
    }
    vlTOPp->opl3__DOT__reset_sync__DOT__r1 = (1U & 
                                              ((~ (IData)(vlTOPp->ic_n)) 
                                               | (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r0)));
    if (((IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r1) 
         ^ vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r1)) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r1 
            = vlTOPp->opl3__DOT__reset_sync__DOT__r1;
    }
    vlTOPp->opl3__DOT__reset_sync__DOT__r0 = (1U & 
                                              (~ (IData)(vlTOPp->ic_n)));
    if (((IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r0) 
         ^ vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r0)) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r0 
            = vlTOPp->opl3__DOT__reset_sync__DOT__r0;
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__22(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__22\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1) 
           & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p2)));
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
         ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr)) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr 
            = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr;
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__23(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__23\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray 
                = (0x7fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                            ^ (0x3fU & (((IData)(1U) 
                                         + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                                        >> 1U))));
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray = 0U;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)));
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr 
                = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_rd_addr;
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr = 0U;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
           == (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray));
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read 
        = (1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty) 
                 | (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty))));
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_rd_addr 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
    }
    if ((1U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (1U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if ((1U & ((0x3fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                         >> 1U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
                                    >> 1U)))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (2U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if ((1U & ((0x1fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                         >> 2U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
                                    >> 2U)))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (4U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if ((1U & ((0xfU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                        >> 3U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
                                   >> 3U)))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (8U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if ((1U & ((7U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                      >> 4U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
                                 >> 4U)))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (0x10U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if ((1U & ((3U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                      >> 5U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
                                 >> 5U)))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (0x20U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if ((1U & ((1U & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                      >> 6U)) ^ (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
                                 >> 6U)))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr)) 
               | (0x40U & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))));
    }
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty) 
         ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_empty)) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_empty 
            = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty;
    }
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
         ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_read)) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_read 
            = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read;
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__24(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__24\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = (1U & (~ (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2)));
}

VL_INLINE_OPT void Vopl3::_multiclk__TOP__25(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_multiclk__TOP__25\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data 
        = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__mem
        [(0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))];
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3feU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3fdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3fbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3f7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3efU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3dfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x3bfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x37fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
                   ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x2ffU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data) 
                   ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data 
            = ((0x1ffU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data)));
    }
}

void Vopl3::_eval(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_eval\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__6(vlSymsp);
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->_sequent__TOP__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__17(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__18(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__19(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__20(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__21(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__22(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__23(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__24(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__11(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__12(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__8(vlSymsp);
        vlTOPp->_sequent__TOP__10(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__13(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__14(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__15(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__16(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__9(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__13(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__14(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__15(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__16(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__25(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__26(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__27(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__28(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__29(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__30(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__31(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__32(vlSymsp);
        vlTOPp->_sequent__TOP__11(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__20(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__20(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__20(vlSymsp);
        vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem._sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__20(vlSymsp);
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host)))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    vlTOPp->_combo__TOP__19(vlSymsp);
    vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank._combo__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__11(vlSymsp);
    vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank._combo__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__12(vlSymsp);
    vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank._combo__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__21(vlSymsp);
    vlSymsp->TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank._combo__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__21(vlSymsp);
    vlTOPp->_combo__TOP__20(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__21(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host)))) {
        vlTOPp->_sequent__TOP__22(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        vlTOPp->_sequent__TOP__23(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__24(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host)))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        vlTOPp->_multiclk__TOP__25(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__ic_n = vlTOPp->ic_n;
    vlTOPp->__Vclklast__TOP__clk_host = vlTOPp->clk_host;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
    vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
}

VL_INLINE_OPT QData Vopl3::_change_request(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_change_request\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vopl3::_change_request_1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_change_request_1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n ^ vlTOPp->__Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)
         | (vlTOPp->opl3__DOT__channels__DOT__signals ^ vlTOPp->__Vchglast__TOP__opl3__DOT__channels__DOT__signals));
    VL_DEBUG_IF( if(__req && ((vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n ^ vlTOPp->__Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n))) VL_DBG_MSGF("        CHANGE: /home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/afifo.v:91: opl3.host_if.__Vcellinp__afifo__i_rd_reset_n\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->opl3__DOT__channels__DOT__signals ^ vlTOPp->__Vchglast__TOP__opl3__DOT__channels__DOT__signals))) VL_DBG_MSGF("        CHANGE: /home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/channels.sv:165: opl3.channels.signals\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
    vlTOPp->__Vchglast__TOP__opl3__DOT__channels__DOT__signals 
        = vlTOPp->opl3__DOT__channels__DOT__signals;
    return __req;
}

#ifdef VL_DEBUG
void Vopl3::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((clk_host & 0xfeU))) {
        Verilated::overWidthError("clk_host");}
    if (VL_UNLIKELY((clk_dac & 0xfeU))) {
        Verilated::overWidthError("clk_dac");}
    if (VL_UNLIKELY((ic_n & 0xfeU))) {
        Verilated::overWidthError("ic_n");}
    if (VL_UNLIKELY((cs_n & 0xfeU))) {
        Verilated::overWidthError("cs_n");}
    if (VL_UNLIKELY((rd_n & 0xfeU))) {
        Verilated::overWidthError("rd_n");}
    if (VL_UNLIKELY((wr_n & 0xfeU))) {
        Verilated::overWidthError("wr_n");}
    if (VL_UNLIKELY((address & 0xfcU))) {
        Verilated::overWidthError("address");}
}
#endif  // VL_DEBUG
