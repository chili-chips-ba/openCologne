// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi3.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4801]);
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4799]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4800]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array))) {
        this->__Vlvbound2 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia;
        if ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra;
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4725]);
        this->__Vtogcov__ram[0U] = ((0xeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4726]);
        this->__Vtogcov__ram[0U] = ((0xdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4727]);
        this->__Vtogcov__ram[0U] = ((0xbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4728]);
        this->__Vtogcov__ram[0U] = ((7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4729]);
        this->__Vtogcov__ram[1U] = ((0xeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4730]);
        this->__Vtogcov__ram[1U] = ((0xdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4731]);
        this->__Vtogcov__ram[1U] = ((0xbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4732]);
        this->__Vtogcov__ram[1U] = ((7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4733]);
        this->__Vtogcov__ram[2U] = ((0xeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4734]);
        this->__Vtogcov__ram[2U] = ((0xdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4735]);
        this->__Vtogcov__ram[2U] = ((0xbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4736]);
        this->__Vtogcov__ram[2U] = ((7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4737]);
        this->__Vtogcov__ram[3U] = ((0xeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4738]);
        this->__Vtogcov__ram[3U] = ((0xdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4739]);
        this->__Vtogcov__ram[3U] = ((0xbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4740]);
        this->__Vtogcov__ram[3U] = ((7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4741]);
        this->__Vtogcov__ram[4U] = ((0xeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4742]);
        this->__Vtogcov__ram[4U] = ((0xdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4743]);
        this->__Vtogcov__ram[4U] = ((0xbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4744]);
        this->__Vtogcov__ram[4U] = ((7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4745]);
        this->__Vtogcov__ram[5U] = ((0xeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4746]);
        this->__Vtogcov__ram[5U] = ((0xdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4747]);
        this->__Vtogcov__ram[5U] = ((0xbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4748]);
        this->__Vtogcov__ram[5U] = ((7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4749]);
        this->__Vtogcov__ram[6U] = ((0xeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4750]);
        this->__Vtogcov__ram[6U] = ((0xdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4751]);
        this->__Vtogcov__ram[6U] = ((0xbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4752]);
        this->__Vtogcov__ram[6U] = ((7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4753]);
        this->__Vtogcov__ram[7U] = ((0xeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4754]);
        this->__Vtogcov__ram[7U] = ((0xdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4755]);
        this->__Vtogcov__ram[7U] = ((0xbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4756]);
        this->__Vtogcov__ram[7U] = ((7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4757]);
        this->__Vtogcov__ram[8U] = ((0xeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4758]);
        this->__Vtogcov__ram[8U] = ((0xdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4759]);
        this->__Vtogcov__ram[8U] = ((0xbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4760]);
        this->__Vtogcov__ram[8U] = ((7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4761]);
        this->__Vtogcov__ram[9U] = ((0xeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4762]);
        this->__Vtogcov__ram[9U] = ((0xdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4763]);
        this->__Vtogcov__ram[9U] = ((0xbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4764]);
        this->__Vtogcov__ram[9U] = ((7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4765]);
        this->__Vtogcov__ram[0xaU] = ((0xeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4766]);
        this->__Vtogcov__ram[0xaU] = ((0xdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4767]);
        this->__Vtogcov__ram[0xaU] = ((0xbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4768]);
        this->__Vtogcov__ram[0xaU] = ((7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4769]);
        this->__Vtogcov__ram[0xbU] = ((0xeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4770]);
        this->__Vtogcov__ram[0xbU] = ((0xdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4771]);
        this->__Vtogcov__ram[0xbU] = ((0xbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4772]);
        this->__Vtogcov__ram[0xbU] = ((7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4773]);
        this->__Vtogcov__ram[0xcU] = ((0xeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4774]);
        this->__Vtogcov__ram[0xcU] = ((0xdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4775]);
        this->__Vtogcov__ram[0xcU] = ((0xbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4776]);
        this->__Vtogcov__ram[0xcU] = ((7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4777]);
        this->__Vtogcov__ram[0xdU] = ((0xeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4778]);
        this->__Vtogcov__ram[0xdU] = ((0xdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4779]);
        this->__Vtogcov__ram[0xdU] = ((0xbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4780]);
        this->__Vtogcov__ram[0xdU] = ((7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4781]);
        this->__Vtogcov__ram[0xeU] = ((0xeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4782]);
        this->__Vtogcov__ram[0xeU] = ((0xdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4783]);
        this->__Vtogcov__ram[0xeU] = ((0xbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4784]);
        this->__Vtogcov__ram[0xeU] = ((7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4785]);
        this->__Vtogcov__ram[0xfU] = ((0xeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4786]);
        this->__Vtogcov__ram[0xfU] = ((0xdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4787]);
        this->__Vtogcov__ram[0xfU] = ((0xbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4788]);
        this->__Vtogcov__ram[0xfU] = ((7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4789]);
        this->__Vtogcov__ram[0x10U] = ((0xeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4790]);
        this->__Vtogcov__ram[0x10U] = ((0xdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4791]);
        this->__Vtogcov__ram[0x10U] = ((0xbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4792]);
        this->__Vtogcov__ram[0x10U] = ((7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4793]);
        this->__Vtogcov__ram[0x11U] = ((0xeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4794]);
        this->__Vtogcov__ram[0x11U] = ((0xdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4795]);
        this->__Vtogcov__ram[0x11U] = ((0xbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4796]);
        this->__Vtogcov__ram[0x11U] = ((7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4712]);
        this->__Vtogcov__addra = ((0x1eU & (IData)(this->__Vtogcov__addra)) 
                                  | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4713]);
        this->__Vtogcov__addra = ((0x1dU & (IData)(this->__Vtogcov__addra)) 
                                  | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4714]);
        this->__Vtogcov__addra = ((0x1bU & (IData)(this->__Vtogcov__addra)) 
                                  | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4715]);
        this->__Vtogcov__addra = ((0x17U & (IData)(this->__Vtogcov__addra)) 
                                  | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra) 
                  ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4716]);
        this->__Vtogcov__addra = ((0xfU & (IData)(this->__Vtogcov__addra)) 
                                  | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4711]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array));
    }
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4717]);
        this->__Vtogcov__dia = ((0xeU & (IData)(this->__Vtogcov__dia)) 
                                | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4718]);
        this->__Vtogcov__dia = ((0xdU & (IData)(this->__Vtogcov__dia)) 
                                | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4719]);
        this->__Vtogcov__dia = ((0xbU & (IData)(this->__Vtogcov__dia)) 
                                | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4720]);
        this->__Vtogcov__dia = ((7U & (IData)(this->__Vtogcov__dia)) 
                                | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4721]);
        this->__Vtogcov__dob = ((0xeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4722]);
        this->__Vtogcov__dob = ((0xdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4723]);
        this->__Vtogcov__dob = ((0xbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4724]);
        this->__Vtogcov__dob = ((7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4801]);
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4799]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4800]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array))) {
        this->__Vlvbound2 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia;
        if ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra;
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4725]);
        this->__Vtogcov__ram[0U] = ((0xeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4726]);
        this->__Vtogcov__ram[0U] = ((0xdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4727]);
        this->__Vtogcov__ram[0U] = ((0xbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4728]);
        this->__Vtogcov__ram[0U] = ((7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4729]);
        this->__Vtogcov__ram[1U] = ((0xeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4730]);
        this->__Vtogcov__ram[1U] = ((0xdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4731]);
        this->__Vtogcov__ram[1U] = ((0xbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4732]);
        this->__Vtogcov__ram[1U] = ((7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4733]);
        this->__Vtogcov__ram[2U] = ((0xeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4734]);
        this->__Vtogcov__ram[2U] = ((0xdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4735]);
        this->__Vtogcov__ram[2U] = ((0xbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4736]);
        this->__Vtogcov__ram[2U] = ((7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4737]);
        this->__Vtogcov__ram[3U] = ((0xeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4738]);
        this->__Vtogcov__ram[3U] = ((0xdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4739]);
        this->__Vtogcov__ram[3U] = ((0xbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4740]);
        this->__Vtogcov__ram[3U] = ((7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4741]);
        this->__Vtogcov__ram[4U] = ((0xeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4742]);
        this->__Vtogcov__ram[4U] = ((0xdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4743]);
        this->__Vtogcov__ram[4U] = ((0xbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4744]);
        this->__Vtogcov__ram[4U] = ((7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4745]);
        this->__Vtogcov__ram[5U] = ((0xeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4746]);
        this->__Vtogcov__ram[5U] = ((0xdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4747]);
        this->__Vtogcov__ram[5U] = ((0xbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4748]);
        this->__Vtogcov__ram[5U] = ((7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4749]);
        this->__Vtogcov__ram[6U] = ((0xeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4750]);
        this->__Vtogcov__ram[6U] = ((0xdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4751]);
        this->__Vtogcov__ram[6U] = ((0xbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4752]);
        this->__Vtogcov__ram[6U] = ((7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4753]);
        this->__Vtogcov__ram[7U] = ((0xeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4754]);
        this->__Vtogcov__ram[7U] = ((0xdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4755]);
        this->__Vtogcov__ram[7U] = ((0xbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4756]);
        this->__Vtogcov__ram[7U] = ((7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4757]);
        this->__Vtogcov__ram[8U] = ((0xeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4758]);
        this->__Vtogcov__ram[8U] = ((0xdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4759]);
        this->__Vtogcov__ram[8U] = ((0xbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4760]);
        this->__Vtogcov__ram[8U] = ((7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4761]);
        this->__Vtogcov__ram[9U] = ((0xeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4762]);
        this->__Vtogcov__ram[9U] = ((0xdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4763]);
        this->__Vtogcov__ram[9U] = ((0xbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4764]);
        this->__Vtogcov__ram[9U] = ((7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4765]);
        this->__Vtogcov__ram[0xaU] = ((0xeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4766]);
        this->__Vtogcov__ram[0xaU] = ((0xdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4767]);
        this->__Vtogcov__ram[0xaU] = ((0xbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4768]);
        this->__Vtogcov__ram[0xaU] = ((7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4769]);
        this->__Vtogcov__ram[0xbU] = ((0xeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4770]);
        this->__Vtogcov__ram[0xbU] = ((0xdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4771]);
        this->__Vtogcov__ram[0xbU] = ((0xbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4772]);
        this->__Vtogcov__ram[0xbU] = ((7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4773]);
        this->__Vtogcov__ram[0xcU] = ((0xeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4774]);
        this->__Vtogcov__ram[0xcU] = ((0xdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4775]);
        this->__Vtogcov__ram[0xcU] = ((0xbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4776]);
        this->__Vtogcov__ram[0xcU] = ((7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4777]);
        this->__Vtogcov__ram[0xdU] = ((0xeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4778]);
        this->__Vtogcov__ram[0xdU] = ((0xdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4779]);
        this->__Vtogcov__ram[0xdU] = ((0xbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4780]);
        this->__Vtogcov__ram[0xdU] = ((7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4781]);
        this->__Vtogcov__ram[0xeU] = ((0xeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4782]);
        this->__Vtogcov__ram[0xeU] = ((0xdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4783]);
        this->__Vtogcov__ram[0xeU] = ((0xbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4784]);
        this->__Vtogcov__ram[0xeU] = ((7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4785]);
        this->__Vtogcov__ram[0xfU] = ((0xeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4786]);
        this->__Vtogcov__ram[0xfU] = ((0xdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4787]);
        this->__Vtogcov__ram[0xfU] = ((0xbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4788]);
        this->__Vtogcov__ram[0xfU] = ((7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4789]);
        this->__Vtogcov__ram[0x10U] = ((0xeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4790]);
        this->__Vtogcov__ram[0x10U] = ((0xdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4791]);
        this->__Vtogcov__ram[0x10U] = ((0xbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4792]);
        this->__Vtogcov__ram[0x10U] = ((7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4793]);
        this->__Vtogcov__ram[0x11U] = ((0xeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4794]);
        this->__Vtogcov__ram[0x11U] = ((0xdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4795]);
        this->__Vtogcov__ram[0x11U] = ((0xbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4796]);
        this->__Vtogcov__ram[0x11U] = ((7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4712]);
        this->__Vtogcov__addra = ((0x1eU & (IData)(this->__Vtogcov__addra)) 
                                  | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4713]);
        this->__Vtogcov__addra = ((0x1dU & (IData)(this->__Vtogcov__addra)) 
                                  | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4714]);
        this->__Vtogcov__addra = ((0x1bU & (IData)(this->__Vtogcov__addra)) 
                                  | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra) 
               ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4715]);
        this->__Vtogcov__addra = ((0x17U & (IData)(this->__Vtogcov__addra)) 
                                  | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra) 
                  ^ this->__Vtogcov__addra))) {
        ++(vlSymsp->__Vcoverage[4716]);
        this->__Vtogcov__addra = ((0xfU & (IData)(this->__Vtogcov__addra)) 
                                  | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4711]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
                                      >> 1U));
    }
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4717]);
        this->__Vtogcov__dia = ((0xeU & (IData)(this->__Vtogcov__dia)) 
                                | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4718]);
        this->__Vtogcov__dia = ((0xdU & (IData)(this->__Vtogcov__dia)) 
                                | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4719]);
        this->__Vtogcov__dia = ((0xbU & (IData)(this->__Vtogcov__dia)) 
                                | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia) 
               ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[4720]);
        this->__Vtogcov__dia = ((7U & (IData)(this->__Vtogcov__dia)) 
                                | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia)));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4721]);
        this->__Vtogcov__dob = ((0xeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4722]);
        this->__Vtogcov__dob = ((0xdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4723]);
        this->__Vtogcov__dob = ((0xbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4724]);
        this->__Vtogcov__dob = ((7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
}
