// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi8.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4376]);
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4374]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4375]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array))) {
        this->__Vlvbound2 = (0x3fU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                  >> 8U));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4318]);
        this->__Vtogcov__ram[0U] = ((0x3eU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4319]);
        this->__Vtogcov__ram[0U] = ((0x3dU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4320]);
        this->__Vtogcov__ram[0U] = ((0x3bU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4321]);
        this->__Vtogcov__ram[0U] = ((0x37U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4322]);
        this->__Vtogcov__ram[0U] = ((0x2fU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4323]);
        this->__Vtogcov__ram[0U] = ((0x1fU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4324]);
        this->__Vtogcov__ram[1U] = ((0x3eU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4325]);
        this->__Vtogcov__ram[1U] = ((0x3dU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4326]);
        this->__Vtogcov__ram[1U] = ((0x3bU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4327]);
        this->__Vtogcov__ram[1U] = ((0x37U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4328]);
        this->__Vtogcov__ram[1U] = ((0x2fU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4329]);
        this->__Vtogcov__ram[1U] = ((0x1fU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4330]);
        this->__Vtogcov__ram[2U] = ((0x3eU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4331]);
        this->__Vtogcov__ram[2U] = ((0x3dU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4332]);
        this->__Vtogcov__ram[2U] = ((0x3bU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4333]);
        this->__Vtogcov__ram[2U] = ((0x37U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4334]);
        this->__Vtogcov__ram[2U] = ((0x2fU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4335]);
        this->__Vtogcov__ram[2U] = ((0x1fU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4336]);
        this->__Vtogcov__ram[3U] = ((0x3eU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4337]);
        this->__Vtogcov__ram[3U] = ((0x3dU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4338]);
        this->__Vtogcov__ram[3U] = ((0x3bU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4339]);
        this->__Vtogcov__ram[3U] = ((0x37U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4340]);
        this->__Vtogcov__ram[3U] = ((0x2fU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4341]);
        this->__Vtogcov__ram[3U] = ((0x1fU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4342]);
        this->__Vtogcov__ram[4U] = ((0x3eU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4343]);
        this->__Vtogcov__ram[4U] = ((0x3dU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4344]);
        this->__Vtogcov__ram[4U] = ((0x3bU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4345]);
        this->__Vtogcov__ram[4U] = ((0x37U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4346]);
        this->__Vtogcov__ram[4U] = ((0x2fU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4347]);
        this->__Vtogcov__ram[4U] = ((0x1fU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4348]);
        this->__Vtogcov__ram[5U] = ((0x3eU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4349]);
        this->__Vtogcov__ram[5U] = ((0x3dU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4350]);
        this->__Vtogcov__ram[5U] = ((0x3bU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4351]);
        this->__Vtogcov__ram[5U] = ((0x37U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4352]);
        this->__Vtogcov__ram[5U] = ((0x2fU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4353]);
        this->__Vtogcov__ram[5U] = ((0x1fU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4354]);
        this->__Vtogcov__ram[6U] = ((0x3eU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4355]);
        this->__Vtogcov__ram[6U] = ((0x3dU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4356]);
        this->__Vtogcov__ram[6U] = ((0x3bU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4357]);
        this->__Vtogcov__ram[6U] = ((0x37U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4358]);
        this->__Vtogcov__ram[6U] = ((0x2fU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4359]);
        this->__Vtogcov__ram[6U] = ((0x1fU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4360]);
        this->__Vtogcov__ram[7U] = ((0x3eU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4361]);
        this->__Vtogcov__ram[7U] = ((0x3dU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4362]);
        this->__Vtogcov__ram[7U] = ((0x3bU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4363]);
        this->__Vtogcov__ram[7U] = ((0x37U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4364]);
        this->__Vtogcov__ram[7U] = ((0x2fU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4365]);
        this->__Vtogcov__ram[7U] = ((0x1fU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4366]);
        this->__Vtogcov__ram[8U] = ((0x3eU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4367]);
        this->__Vtogcov__ram[8U] = ((0x3dU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4368]);
        this->__Vtogcov__ram[8U] = ((0x3bU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4369]);
        this->__Vtogcov__ram[8U] = ((0x37U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4370]);
        this->__Vtogcov__ram[8U] = ((0x2fU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4371]);
        this->__Vtogcov__ram[8U] = ((0x1fU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4311]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array));
    }
    this->dob = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4312]);
        this->__Vtogcov__dob = ((0x3eU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4313]);
        this->__Vtogcov__dob = ((0x3dU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4314]);
        this->__Vtogcov__dob = ((0x3bU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4315]);
        this->__Vtogcov__dob = ((0x37U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4316]);
        this->__Vtogcov__dob = ((0x2fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4317]);
        this->__Vtogcov__dob = ((0x1fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4376]);
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4374]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4375]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array))) {
        this->__Vlvbound2 = (0x3fU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                  >> 8U));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4318]);
        this->__Vtogcov__ram[0U] = ((0x3eU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4319]);
        this->__Vtogcov__ram[0U] = ((0x3dU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4320]);
        this->__Vtogcov__ram[0U] = ((0x3bU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4321]);
        this->__Vtogcov__ram[0U] = ((0x37U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4322]);
        this->__Vtogcov__ram[0U] = ((0x2fU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4323]);
        this->__Vtogcov__ram[0U] = ((0x1fU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4324]);
        this->__Vtogcov__ram[1U] = ((0x3eU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4325]);
        this->__Vtogcov__ram[1U] = ((0x3dU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4326]);
        this->__Vtogcov__ram[1U] = ((0x3bU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4327]);
        this->__Vtogcov__ram[1U] = ((0x37U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4328]);
        this->__Vtogcov__ram[1U] = ((0x2fU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4329]);
        this->__Vtogcov__ram[1U] = ((0x1fU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4330]);
        this->__Vtogcov__ram[2U] = ((0x3eU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4331]);
        this->__Vtogcov__ram[2U] = ((0x3dU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4332]);
        this->__Vtogcov__ram[2U] = ((0x3bU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4333]);
        this->__Vtogcov__ram[2U] = ((0x37U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4334]);
        this->__Vtogcov__ram[2U] = ((0x2fU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4335]);
        this->__Vtogcov__ram[2U] = ((0x1fU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4336]);
        this->__Vtogcov__ram[3U] = ((0x3eU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4337]);
        this->__Vtogcov__ram[3U] = ((0x3dU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4338]);
        this->__Vtogcov__ram[3U] = ((0x3bU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4339]);
        this->__Vtogcov__ram[3U] = ((0x37U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4340]);
        this->__Vtogcov__ram[3U] = ((0x2fU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4341]);
        this->__Vtogcov__ram[3U] = ((0x1fU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4342]);
        this->__Vtogcov__ram[4U] = ((0x3eU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4343]);
        this->__Vtogcov__ram[4U] = ((0x3dU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4344]);
        this->__Vtogcov__ram[4U] = ((0x3bU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4345]);
        this->__Vtogcov__ram[4U] = ((0x37U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4346]);
        this->__Vtogcov__ram[4U] = ((0x2fU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4347]);
        this->__Vtogcov__ram[4U] = ((0x1fU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4348]);
        this->__Vtogcov__ram[5U] = ((0x3eU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4349]);
        this->__Vtogcov__ram[5U] = ((0x3dU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4350]);
        this->__Vtogcov__ram[5U] = ((0x3bU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4351]);
        this->__Vtogcov__ram[5U] = ((0x37U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4352]);
        this->__Vtogcov__ram[5U] = ((0x2fU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4353]);
        this->__Vtogcov__ram[5U] = ((0x1fU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4354]);
        this->__Vtogcov__ram[6U] = ((0x3eU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4355]);
        this->__Vtogcov__ram[6U] = ((0x3dU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4356]);
        this->__Vtogcov__ram[6U] = ((0x3bU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4357]);
        this->__Vtogcov__ram[6U] = ((0x37U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4358]);
        this->__Vtogcov__ram[6U] = ((0x2fU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4359]);
        this->__Vtogcov__ram[6U] = ((0x1fU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4360]);
        this->__Vtogcov__ram[7U] = ((0x3eU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4361]);
        this->__Vtogcov__ram[7U] = ((0x3dU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4362]);
        this->__Vtogcov__ram[7U] = ((0x3bU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4363]);
        this->__Vtogcov__ram[7U] = ((0x37U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4364]);
        this->__Vtogcov__ram[7U] = ((0x2fU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4365]);
        this->__Vtogcov__ram[7U] = ((0x1fU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4366]);
        this->__Vtogcov__ram[8U] = ((0x3eU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4367]);
        this->__Vtogcov__ram[8U] = ((0x3dU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4368]);
        this->__Vtogcov__ram[8U] = ((0x3bU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4369]);
        this->__Vtogcov__ram[8U] = ((0x37U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4370]);
        this->__Vtogcov__ram[8U] = ((0x2fU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4371]);
        this->__Vtogcov__ram[8U] = ((0x1fU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4311]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
                                      >> 1U));
    }
    this->dob = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4312]);
        this->__Vtogcov__dob = ((0x3eU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4313]);
        this->__Vtogcov__dob = ((0x3dU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4314]);
        this->__Vtogcov__dob = ((0x3bU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4315]);
        this->__Vtogcov__dob = ((0x37U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4316]);
        this->__Vtogcov__dob = ((0x2fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4317]);
        this->__Vtogcov__dob = ((0x1fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
}
