// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi7.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4431]);
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4429]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4430]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array))) {
        this->__Vlvbound2 = (7U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                   >> 8U));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4361]);
        this->__Vtogcov__ram[0U] = ((6U & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4362]);
        this->__Vtogcov__ram[0U] = ((5U & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4363]);
        this->__Vtogcov__ram[0U] = ((3U & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4364]);
        this->__Vtogcov__ram[1U] = ((6U & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4365]);
        this->__Vtogcov__ram[1U] = ((5U & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4366]);
        this->__Vtogcov__ram[1U] = ((3U & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4367]);
        this->__Vtogcov__ram[2U] = ((6U & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4368]);
        this->__Vtogcov__ram[2U] = ((5U & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4369]);
        this->__Vtogcov__ram[2U] = ((3U & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4370]);
        this->__Vtogcov__ram[3U] = ((6U & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4371]);
        this->__Vtogcov__ram[3U] = ((5U & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4372]);
        this->__Vtogcov__ram[3U] = ((3U & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4373]);
        this->__Vtogcov__ram[4U] = ((6U & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4374]);
        this->__Vtogcov__ram[4U] = ((5U & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4375]);
        this->__Vtogcov__ram[4U] = ((3U & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4376]);
        this->__Vtogcov__ram[5U] = ((6U & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4377]);
        this->__Vtogcov__ram[5U] = ((5U & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4378]);
        this->__Vtogcov__ram[5U] = ((3U & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4379]);
        this->__Vtogcov__ram[6U] = ((6U & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4380]);
        this->__Vtogcov__ram[6U] = ((5U & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4381]);
        this->__Vtogcov__ram[6U] = ((3U & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4382]);
        this->__Vtogcov__ram[7U] = ((6U & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4383]);
        this->__Vtogcov__ram[7U] = ((5U & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4384]);
        this->__Vtogcov__ram[7U] = ((3U & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4385]);
        this->__Vtogcov__ram[8U] = ((6U & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4386]);
        this->__Vtogcov__ram[8U] = ((5U & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4387]);
        this->__Vtogcov__ram[8U] = ((3U & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4388]);
        this->__Vtogcov__ram[9U] = ((6U & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4389]);
        this->__Vtogcov__ram[9U] = ((5U & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4390]);
        this->__Vtogcov__ram[9U] = ((3U & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4391]);
        this->__Vtogcov__ram[0xaU] = ((6U & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4392]);
        this->__Vtogcov__ram[0xaU] = ((5U & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4393]);
        this->__Vtogcov__ram[0xaU] = ((3U & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4394]);
        this->__Vtogcov__ram[0xbU] = ((6U & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4395]);
        this->__Vtogcov__ram[0xbU] = ((5U & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4396]);
        this->__Vtogcov__ram[0xbU] = ((3U & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4397]);
        this->__Vtogcov__ram[0xcU] = ((6U & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4398]);
        this->__Vtogcov__ram[0xcU] = ((5U & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4399]);
        this->__Vtogcov__ram[0xcU] = ((3U & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4400]);
        this->__Vtogcov__ram[0xdU] = ((6U & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4401]);
        this->__Vtogcov__ram[0xdU] = ((5U & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4402]);
        this->__Vtogcov__ram[0xdU] = ((3U & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4403]);
        this->__Vtogcov__ram[0xeU] = ((6U & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4404]);
        this->__Vtogcov__ram[0xeU] = ((5U & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4405]);
        this->__Vtogcov__ram[0xeU] = ((3U & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4406]);
        this->__Vtogcov__ram[0xfU] = ((6U & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4407]);
        this->__Vtogcov__ram[0xfU] = ((5U & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4408]);
        this->__Vtogcov__ram[0xfU] = ((3U & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4409]);
        this->__Vtogcov__ram[0x10U] = ((6U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4410]);
        this->__Vtogcov__ram[0x10U] = ((5U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4411]);
        this->__Vtogcov__ram[0x10U] = ((3U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4412]);
        this->__Vtogcov__ram[0x11U] = ((6U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4413]);
        this->__Vtogcov__ram[0x11U] = ((5U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4414]);
        this->__Vtogcov__ram[0x11U] = ((3U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4415]);
        this->__Vtogcov__ram[0x12U] = ((6U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4416]);
        this->__Vtogcov__ram[0x12U] = ((5U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4417]);
        this->__Vtogcov__ram[0x12U] = ((3U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4418]);
        this->__Vtogcov__ram[0x13U] = ((6U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4419]);
        this->__Vtogcov__ram[0x13U] = ((5U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4420]);
        this->__Vtogcov__ram[0x13U] = ((3U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4421]);
        this->__Vtogcov__ram[0x14U] = ((6U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4422]);
        this->__Vtogcov__ram[0x14U] = ((5U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4423]);
        this->__Vtogcov__ram[0x14U] = ((3U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4424]);
        this->__Vtogcov__ram[0x15U] = ((6U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4425]);
        this->__Vtogcov__ram[0x15U] = ((5U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4426]);
        this->__Vtogcov__ram[0x15U] = ((3U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4357]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array));
    }
    this->dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4358]);
        this->__Vtogcov__dob = ((6U & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4359]);
        this->__Vtogcov__dob = ((5U & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4360]);
        this->__Vtogcov__dob = ((3U & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4431]);
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4429]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4430]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array))) {
        this->__Vlvbound2 = (7U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                   >> 8U));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4361]);
        this->__Vtogcov__ram[0U] = ((6U & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4362]);
        this->__Vtogcov__ram[0U] = ((5U & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4363]);
        this->__Vtogcov__ram[0U] = ((3U & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4364]);
        this->__Vtogcov__ram[1U] = ((6U & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4365]);
        this->__Vtogcov__ram[1U] = ((5U & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4366]);
        this->__Vtogcov__ram[1U] = ((3U & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4367]);
        this->__Vtogcov__ram[2U] = ((6U & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4368]);
        this->__Vtogcov__ram[2U] = ((5U & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4369]);
        this->__Vtogcov__ram[2U] = ((3U & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4370]);
        this->__Vtogcov__ram[3U] = ((6U & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4371]);
        this->__Vtogcov__ram[3U] = ((5U & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4372]);
        this->__Vtogcov__ram[3U] = ((3U & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4373]);
        this->__Vtogcov__ram[4U] = ((6U & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4374]);
        this->__Vtogcov__ram[4U] = ((5U & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4375]);
        this->__Vtogcov__ram[4U] = ((3U & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4376]);
        this->__Vtogcov__ram[5U] = ((6U & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4377]);
        this->__Vtogcov__ram[5U] = ((5U & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4378]);
        this->__Vtogcov__ram[5U] = ((3U & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4379]);
        this->__Vtogcov__ram[6U] = ((6U & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4380]);
        this->__Vtogcov__ram[6U] = ((5U & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4381]);
        this->__Vtogcov__ram[6U] = ((3U & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4382]);
        this->__Vtogcov__ram[7U] = ((6U & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4383]);
        this->__Vtogcov__ram[7U] = ((5U & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4384]);
        this->__Vtogcov__ram[7U] = ((3U & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4385]);
        this->__Vtogcov__ram[8U] = ((6U & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4386]);
        this->__Vtogcov__ram[8U] = ((5U & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4387]);
        this->__Vtogcov__ram[8U] = ((3U & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4388]);
        this->__Vtogcov__ram[9U] = ((6U & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4389]);
        this->__Vtogcov__ram[9U] = ((5U & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4390]);
        this->__Vtogcov__ram[9U] = ((3U & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4391]);
        this->__Vtogcov__ram[0xaU] = ((6U & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4392]);
        this->__Vtogcov__ram[0xaU] = ((5U & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4393]);
        this->__Vtogcov__ram[0xaU] = ((3U & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4394]);
        this->__Vtogcov__ram[0xbU] = ((6U & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4395]);
        this->__Vtogcov__ram[0xbU] = ((5U & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4396]);
        this->__Vtogcov__ram[0xbU] = ((3U & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4397]);
        this->__Vtogcov__ram[0xcU] = ((6U & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4398]);
        this->__Vtogcov__ram[0xcU] = ((5U & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4399]);
        this->__Vtogcov__ram[0xcU] = ((3U & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4400]);
        this->__Vtogcov__ram[0xdU] = ((6U & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4401]);
        this->__Vtogcov__ram[0xdU] = ((5U & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4402]);
        this->__Vtogcov__ram[0xdU] = ((3U & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4403]);
        this->__Vtogcov__ram[0xeU] = ((6U & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4404]);
        this->__Vtogcov__ram[0xeU] = ((5U & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4405]);
        this->__Vtogcov__ram[0xeU] = ((3U & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4406]);
        this->__Vtogcov__ram[0xfU] = ((6U & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4407]);
        this->__Vtogcov__ram[0xfU] = ((5U & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4408]);
        this->__Vtogcov__ram[0xfU] = ((3U & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4409]);
        this->__Vtogcov__ram[0x10U] = ((6U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4410]);
        this->__Vtogcov__ram[0x10U] = ((5U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4411]);
        this->__Vtogcov__ram[0x10U] = ((3U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4412]);
        this->__Vtogcov__ram[0x11U] = ((6U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4413]);
        this->__Vtogcov__ram[0x11U] = ((5U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4414]);
        this->__Vtogcov__ram[0x11U] = ((3U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4415]);
        this->__Vtogcov__ram[0x12U] = ((6U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4416]);
        this->__Vtogcov__ram[0x12U] = ((5U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4417]);
        this->__Vtogcov__ram[0x12U] = ((3U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4418]);
        this->__Vtogcov__ram[0x13U] = ((6U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4419]);
        this->__Vtogcov__ram[0x13U] = ((5U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4420]);
        this->__Vtogcov__ram[0x13U] = ((3U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4421]);
        this->__Vtogcov__ram[0x14U] = ((6U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4422]);
        this->__Vtogcov__ram[0x14U] = ((5U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4423]);
        this->__Vtogcov__ram[0x14U] = ((3U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4424]);
        this->__Vtogcov__ram[0x15U] = ((6U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4425]);
        this->__Vtogcov__ram[0x15U] = ((5U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4426]);
        this->__Vtogcov__ram[0x15U] = ((3U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4357]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
                                      >> 1U));
    }
    this->dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4358]);
        this->__Vtogcov__dob = ((6U & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4359]);
        this->__Vtogcov__dob = ((5U & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4360]);
        this->__Vtogcov__dob = ((3U & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
}
