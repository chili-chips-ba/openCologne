// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi13.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4309]);
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4307]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4308]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array))) {
        this->__Vlvbound2 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2;
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                                >> 5U)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                                                   >> 5U));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4143]);
        this->__Vtogcov__ram[0U] = ((0x1feU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4144]);
        this->__Vtogcov__ram[0U] = ((0x1fdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4145]);
        this->__Vtogcov__ram[0U] = ((0x1fbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4146]);
        this->__Vtogcov__ram[0U] = ((0x1f7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4147]);
        this->__Vtogcov__ram[0U] = ((0x1efU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4148]);
        this->__Vtogcov__ram[0U] = ((0x1dfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4149]);
        this->__Vtogcov__ram[0U] = ((0x1bfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4150]);
        this->__Vtogcov__ram[0U] = ((0x17fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x100U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4151]);
        this->__Vtogcov__ram[0U] = ((0xffU & this->__Vtogcov__ram
                                     [0U]) | (0x100U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4152]);
        this->__Vtogcov__ram[1U] = ((0x1feU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4153]);
        this->__Vtogcov__ram[1U] = ((0x1fdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4154]);
        this->__Vtogcov__ram[1U] = ((0x1fbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4155]);
        this->__Vtogcov__ram[1U] = ((0x1f7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4156]);
        this->__Vtogcov__ram[1U] = ((0x1efU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4157]);
        this->__Vtogcov__ram[1U] = ((0x1dfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4158]);
        this->__Vtogcov__ram[1U] = ((0x1bfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4159]);
        this->__Vtogcov__ram[1U] = ((0x17fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x100U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4160]);
        this->__Vtogcov__ram[1U] = ((0xffU & this->__Vtogcov__ram
                                     [1U]) | (0x100U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4161]);
        this->__Vtogcov__ram[2U] = ((0x1feU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4162]);
        this->__Vtogcov__ram[2U] = ((0x1fdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4163]);
        this->__Vtogcov__ram[2U] = ((0x1fbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4164]);
        this->__Vtogcov__ram[2U] = ((0x1f7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4165]);
        this->__Vtogcov__ram[2U] = ((0x1efU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4166]);
        this->__Vtogcov__ram[2U] = ((0x1dfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4167]);
        this->__Vtogcov__ram[2U] = ((0x1bfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4168]);
        this->__Vtogcov__ram[2U] = ((0x17fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x100U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4169]);
        this->__Vtogcov__ram[2U] = ((0xffU & this->__Vtogcov__ram
                                     [2U]) | (0x100U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4170]);
        this->__Vtogcov__ram[3U] = ((0x1feU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4171]);
        this->__Vtogcov__ram[3U] = ((0x1fdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4172]);
        this->__Vtogcov__ram[3U] = ((0x1fbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4173]);
        this->__Vtogcov__ram[3U] = ((0x1f7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4174]);
        this->__Vtogcov__ram[3U] = ((0x1efU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4175]);
        this->__Vtogcov__ram[3U] = ((0x1dfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4176]);
        this->__Vtogcov__ram[3U] = ((0x1bfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4177]);
        this->__Vtogcov__ram[3U] = ((0x17fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x100U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4178]);
        this->__Vtogcov__ram[3U] = ((0xffU & this->__Vtogcov__ram
                                     [3U]) | (0x100U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4179]);
        this->__Vtogcov__ram[4U] = ((0x1feU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4180]);
        this->__Vtogcov__ram[4U] = ((0x1fdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4181]);
        this->__Vtogcov__ram[4U] = ((0x1fbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4182]);
        this->__Vtogcov__ram[4U] = ((0x1f7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4183]);
        this->__Vtogcov__ram[4U] = ((0x1efU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4184]);
        this->__Vtogcov__ram[4U] = ((0x1dfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4185]);
        this->__Vtogcov__ram[4U] = ((0x1bfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4186]);
        this->__Vtogcov__ram[4U] = ((0x17fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x100U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4187]);
        this->__Vtogcov__ram[4U] = ((0xffU & this->__Vtogcov__ram
                                     [4U]) | (0x100U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4188]);
        this->__Vtogcov__ram[5U] = ((0x1feU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4189]);
        this->__Vtogcov__ram[5U] = ((0x1fdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4190]);
        this->__Vtogcov__ram[5U] = ((0x1fbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4191]);
        this->__Vtogcov__ram[5U] = ((0x1f7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4192]);
        this->__Vtogcov__ram[5U] = ((0x1efU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4193]);
        this->__Vtogcov__ram[5U] = ((0x1dfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4194]);
        this->__Vtogcov__ram[5U] = ((0x1bfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4195]);
        this->__Vtogcov__ram[5U] = ((0x17fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x100U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4196]);
        this->__Vtogcov__ram[5U] = ((0xffU & this->__Vtogcov__ram
                                     [5U]) | (0x100U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4197]);
        this->__Vtogcov__ram[6U] = ((0x1feU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4198]);
        this->__Vtogcov__ram[6U] = ((0x1fdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4199]);
        this->__Vtogcov__ram[6U] = ((0x1fbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4200]);
        this->__Vtogcov__ram[6U] = ((0x1f7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4201]);
        this->__Vtogcov__ram[6U] = ((0x1efU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4202]);
        this->__Vtogcov__ram[6U] = ((0x1dfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4203]);
        this->__Vtogcov__ram[6U] = ((0x1bfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4204]);
        this->__Vtogcov__ram[6U] = ((0x17fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x100U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[4205]);
        this->__Vtogcov__ram[6U] = ((0xffU & this->__Vtogcov__ram
                                     [6U]) | (0x100U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4206]);
        this->__Vtogcov__ram[7U] = ((0x1feU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4207]);
        this->__Vtogcov__ram[7U] = ((0x1fdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4208]);
        this->__Vtogcov__ram[7U] = ((0x1fbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4209]);
        this->__Vtogcov__ram[7U] = ((0x1f7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4210]);
        this->__Vtogcov__ram[7U] = ((0x1efU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4211]);
        this->__Vtogcov__ram[7U] = ((0x1dfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4212]);
        this->__Vtogcov__ram[7U] = ((0x1bfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4213]);
        this->__Vtogcov__ram[7U] = ((0x17fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x100U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[4214]);
        this->__Vtogcov__ram[7U] = ((0xffU & this->__Vtogcov__ram
                                     [7U]) | (0x100U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4215]);
        this->__Vtogcov__ram[8U] = ((0x1feU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4216]);
        this->__Vtogcov__ram[8U] = ((0x1fdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4217]);
        this->__Vtogcov__ram[8U] = ((0x1fbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4218]);
        this->__Vtogcov__ram[8U] = ((0x1f7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4219]);
        this->__Vtogcov__ram[8U] = ((0x1efU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4220]);
        this->__Vtogcov__ram[8U] = ((0x1dfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4221]);
        this->__Vtogcov__ram[8U] = ((0x1bfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4222]);
        this->__Vtogcov__ram[8U] = ((0x17fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x100U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[4223]);
        this->__Vtogcov__ram[8U] = ((0xffU & this->__Vtogcov__ram
                                     [8U]) | (0x100U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4224]);
        this->__Vtogcov__ram[9U] = ((0x1feU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4225]);
        this->__Vtogcov__ram[9U] = ((0x1fdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4226]);
        this->__Vtogcov__ram[9U] = ((0x1fbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4227]);
        this->__Vtogcov__ram[9U] = ((0x1f7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4228]);
        this->__Vtogcov__ram[9U] = ((0x1efU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4229]);
        this->__Vtogcov__ram[9U] = ((0x1dfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4230]);
        this->__Vtogcov__ram[9U] = ((0x1bfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4231]);
        this->__Vtogcov__ram[9U] = ((0x17fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x100U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[4232]);
        this->__Vtogcov__ram[9U] = ((0xffU & this->__Vtogcov__ram
                                     [9U]) | (0x100U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4233]);
        this->__Vtogcov__ram[0xaU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4234]);
        this->__Vtogcov__ram[0xaU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4235]);
        this->__Vtogcov__ram[0xaU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4236]);
        this->__Vtogcov__ram[0xaU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4237]);
        this->__Vtogcov__ram[0xaU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4238]);
        this->__Vtogcov__ram[0xaU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4239]);
        this->__Vtogcov__ram[0xaU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4240]);
        this->__Vtogcov__ram[0xaU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x100U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4241]);
        this->__Vtogcov__ram[0xaU] = ((0xffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4242]);
        this->__Vtogcov__ram[0xbU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4243]);
        this->__Vtogcov__ram[0xbU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4244]);
        this->__Vtogcov__ram[0xbU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4245]);
        this->__Vtogcov__ram[0xbU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4246]);
        this->__Vtogcov__ram[0xbU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4247]);
        this->__Vtogcov__ram[0xbU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4248]);
        this->__Vtogcov__ram[0xbU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4249]);
        this->__Vtogcov__ram[0xbU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x100U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4250]);
        this->__Vtogcov__ram[0xbU] = ((0xffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4251]);
        this->__Vtogcov__ram[0xcU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4252]);
        this->__Vtogcov__ram[0xcU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4253]);
        this->__Vtogcov__ram[0xcU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4254]);
        this->__Vtogcov__ram[0xcU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4255]);
        this->__Vtogcov__ram[0xcU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4256]);
        this->__Vtogcov__ram[0xcU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4257]);
        this->__Vtogcov__ram[0xcU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4258]);
        this->__Vtogcov__ram[0xcU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x100U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4259]);
        this->__Vtogcov__ram[0xcU] = ((0xffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4260]);
        this->__Vtogcov__ram[0xdU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4261]);
        this->__Vtogcov__ram[0xdU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4262]);
        this->__Vtogcov__ram[0xdU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4263]);
        this->__Vtogcov__ram[0xdU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4264]);
        this->__Vtogcov__ram[0xdU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4265]);
        this->__Vtogcov__ram[0xdU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4266]);
        this->__Vtogcov__ram[0xdU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4267]);
        this->__Vtogcov__ram[0xdU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x100U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4268]);
        this->__Vtogcov__ram[0xdU] = ((0xffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4269]);
        this->__Vtogcov__ram[0xeU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4270]);
        this->__Vtogcov__ram[0xeU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4271]);
        this->__Vtogcov__ram[0xeU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4272]);
        this->__Vtogcov__ram[0xeU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4273]);
        this->__Vtogcov__ram[0xeU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4274]);
        this->__Vtogcov__ram[0xeU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4275]);
        this->__Vtogcov__ram[0xeU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4276]);
        this->__Vtogcov__ram[0xeU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x100U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4277]);
        this->__Vtogcov__ram[0xeU] = ((0xffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4278]);
        this->__Vtogcov__ram[0xfU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4279]);
        this->__Vtogcov__ram[0xfU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4280]);
        this->__Vtogcov__ram[0xfU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4281]);
        this->__Vtogcov__ram[0xfU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4282]);
        this->__Vtogcov__ram[0xfU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4283]);
        this->__Vtogcov__ram[0xfU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4284]);
        this->__Vtogcov__ram[0xfU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4285]);
        this->__Vtogcov__ram[0xfU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x100U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4286]);
        this->__Vtogcov__ram[0xfU] = ((0xffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4287]);
        this->__Vtogcov__ram[0x10U] = ((0x1feU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4288]);
        this->__Vtogcov__ram[0x10U] = ((0x1fdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4289]);
        this->__Vtogcov__ram[0x10U] = ((0x1fbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4290]);
        this->__Vtogcov__ram[0x10U] = ((0x1f7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4291]);
        this->__Vtogcov__ram[0x10U] = ((0x1efU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4292]);
        this->__Vtogcov__ram[0x10U] = ((0x1dfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4293]);
        this->__Vtogcov__ram[0x10U] = ((0x1bfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4294]);
        this->__Vtogcov__ram[0x10U] = ((0x17fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x100U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4295]);
        this->__Vtogcov__ram[0x10U] = ((0xffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4296]);
        this->__Vtogcov__ram[0x11U] = ((0x1feU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4297]);
        this->__Vtogcov__ram[0x11U] = ((0x1fdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4298]);
        this->__Vtogcov__ram[0x11U] = ((0x1fbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4299]);
        this->__Vtogcov__ram[0x11U] = ((0x1f7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4300]);
        this->__Vtogcov__ram[0x11U] = ((0x1efU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4301]);
        this->__Vtogcov__ram[0x11U] = ((0x1dfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4302]);
        this->__Vtogcov__ram[0x11U] = ((0x1bfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4303]);
        this->__Vtogcov__ram[0x11U] = ((0x17fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x100U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4304]);
        this->__Vtogcov__ram[0x11U] = ((0xffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x11U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4133]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array));
    }
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4134]);
        this->__Vtogcov__dob = ((0x1feU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4135]);
        this->__Vtogcov__dob = ((0x1fdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4136]);
        this->__Vtogcov__dob = ((0x1fbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4137]);
        this->__Vtogcov__dob = ((0x1f7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4138]);
        this->__Vtogcov__dob = ((0x1efU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4139]);
        this->__Vtogcov__dob = ((0x1dfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
    if ((0x40U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4140]);
        this->__Vtogcov__dob = ((0x1bfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->dob)));
    }
    if ((0x80U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4141]);
        this->__Vtogcov__dob = ((0x17fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->dob)));
    }
    if ((0x100U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4142]);
        this->__Vtogcov__dob = ((0xffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x100U & (IData)(this->dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4309]);
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4307]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4308]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array))) {
        this->__Vlvbound2 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2;
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                                >> 5U)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                                                   >> 5U));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4143]);
        this->__Vtogcov__ram[0U] = ((0x1feU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4144]);
        this->__Vtogcov__ram[0U] = ((0x1fdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4145]);
        this->__Vtogcov__ram[0U] = ((0x1fbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4146]);
        this->__Vtogcov__ram[0U] = ((0x1f7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4147]);
        this->__Vtogcov__ram[0U] = ((0x1efU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4148]);
        this->__Vtogcov__ram[0U] = ((0x1dfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4149]);
        this->__Vtogcov__ram[0U] = ((0x1bfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4150]);
        this->__Vtogcov__ram[0U] = ((0x17fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x100U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4151]);
        this->__Vtogcov__ram[0U] = ((0xffU & this->__Vtogcov__ram
                                     [0U]) | (0x100U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4152]);
        this->__Vtogcov__ram[1U] = ((0x1feU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4153]);
        this->__Vtogcov__ram[1U] = ((0x1fdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4154]);
        this->__Vtogcov__ram[1U] = ((0x1fbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4155]);
        this->__Vtogcov__ram[1U] = ((0x1f7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4156]);
        this->__Vtogcov__ram[1U] = ((0x1efU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4157]);
        this->__Vtogcov__ram[1U] = ((0x1dfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4158]);
        this->__Vtogcov__ram[1U] = ((0x1bfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4159]);
        this->__Vtogcov__ram[1U] = ((0x17fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x100U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4160]);
        this->__Vtogcov__ram[1U] = ((0xffU & this->__Vtogcov__ram
                                     [1U]) | (0x100U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4161]);
        this->__Vtogcov__ram[2U] = ((0x1feU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4162]);
        this->__Vtogcov__ram[2U] = ((0x1fdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4163]);
        this->__Vtogcov__ram[2U] = ((0x1fbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4164]);
        this->__Vtogcov__ram[2U] = ((0x1f7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4165]);
        this->__Vtogcov__ram[2U] = ((0x1efU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4166]);
        this->__Vtogcov__ram[2U] = ((0x1dfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4167]);
        this->__Vtogcov__ram[2U] = ((0x1bfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4168]);
        this->__Vtogcov__ram[2U] = ((0x17fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x100U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4169]);
        this->__Vtogcov__ram[2U] = ((0xffU & this->__Vtogcov__ram
                                     [2U]) | (0x100U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4170]);
        this->__Vtogcov__ram[3U] = ((0x1feU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4171]);
        this->__Vtogcov__ram[3U] = ((0x1fdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4172]);
        this->__Vtogcov__ram[3U] = ((0x1fbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4173]);
        this->__Vtogcov__ram[3U] = ((0x1f7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4174]);
        this->__Vtogcov__ram[3U] = ((0x1efU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4175]);
        this->__Vtogcov__ram[3U] = ((0x1dfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4176]);
        this->__Vtogcov__ram[3U] = ((0x1bfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4177]);
        this->__Vtogcov__ram[3U] = ((0x17fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x100U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4178]);
        this->__Vtogcov__ram[3U] = ((0xffU & this->__Vtogcov__ram
                                     [3U]) | (0x100U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4179]);
        this->__Vtogcov__ram[4U] = ((0x1feU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4180]);
        this->__Vtogcov__ram[4U] = ((0x1fdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4181]);
        this->__Vtogcov__ram[4U] = ((0x1fbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4182]);
        this->__Vtogcov__ram[4U] = ((0x1f7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4183]);
        this->__Vtogcov__ram[4U] = ((0x1efU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4184]);
        this->__Vtogcov__ram[4U] = ((0x1dfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4185]);
        this->__Vtogcov__ram[4U] = ((0x1bfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4186]);
        this->__Vtogcov__ram[4U] = ((0x17fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x100U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4187]);
        this->__Vtogcov__ram[4U] = ((0xffU & this->__Vtogcov__ram
                                     [4U]) | (0x100U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4188]);
        this->__Vtogcov__ram[5U] = ((0x1feU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4189]);
        this->__Vtogcov__ram[5U] = ((0x1fdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4190]);
        this->__Vtogcov__ram[5U] = ((0x1fbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4191]);
        this->__Vtogcov__ram[5U] = ((0x1f7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4192]);
        this->__Vtogcov__ram[5U] = ((0x1efU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4193]);
        this->__Vtogcov__ram[5U] = ((0x1dfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4194]);
        this->__Vtogcov__ram[5U] = ((0x1bfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4195]);
        this->__Vtogcov__ram[5U] = ((0x17fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x100U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4196]);
        this->__Vtogcov__ram[5U] = ((0xffU & this->__Vtogcov__ram
                                     [5U]) | (0x100U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4197]);
        this->__Vtogcov__ram[6U] = ((0x1feU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4198]);
        this->__Vtogcov__ram[6U] = ((0x1fdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4199]);
        this->__Vtogcov__ram[6U] = ((0x1fbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4200]);
        this->__Vtogcov__ram[6U] = ((0x1f7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4201]);
        this->__Vtogcov__ram[6U] = ((0x1efU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4202]);
        this->__Vtogcov__ram[6U] = ((0x1dfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4203]);
        this->__Vtogcov__ram[6U] = ((0x1bfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4204]);
        this->__Vtogcov__ram[6U] = ((0x17fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x100U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[4205]);
        this->__Vtogcov__ram[6U] = ((0xffU & this->__Vtogcov__ram
                                     [6U]) | (0x100U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4206]);
        this->__Vtogcov__ram[7U] = ((0x1feU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4207]);
        this->__Vtogcov__ram[7U] = ((0x1fdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4208]);
        this->__Vtogcov__ram[7U] = ((0x1fbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4209]);
        this->__Vtogcov__ram[7U] = ((0x1f7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4210]);
        this->__Vtogcov__ram[7U] = ((0x1efU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4211]);
        this->__Vtogcov__ram[7U] = ((0x1dfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4212]);
        this->__Vtogcov__ram[7U] = ((0x1bfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4213]);
        this->__Vtogcov__ram[7U] = ((0x17fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x100U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[4214]);
        this->__Vtogcov__ram[7U] = ((0xffU & this->__Vtogcov__ram
                                     [7U]) | (0x100U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4215]);
        this->__Vtogcov__ram[8U] = ((0x1feU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4216]);
        this->__Vtogcov__ram[8U] = ((0x1fdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4217]);
        this->__Vtogcov__ram[8U] = ((0x1fbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4218]);
        this->__Vtogcov__ram[8U] = ((0x1f7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4219]);
        this->__Vtogcov__ram[8U] = ((0x1efU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4220]);
        this->__Vtogcov__ram[8U] = ((0x1dfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4221]);
        this->__Vtogcov__ram[8U] = ((0x1bfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4222]);
        this->__Vtogcov__ram[8U] = ((0x17fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x100U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[4223]);
        this->__Vtogcov__ram[8U] = ((0xffU & this->__Vtogcov__ram
                                     [8U]) | (0x100U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4224]);
        this->__Vtogcov__ram[9U] = ((0x1feU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4225]);
        this->__Vtogcov__ram[9U] = ((0x1fdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4226]);
        this->__Vtogcov__ram[9U] = ((0x1fbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4227]);
        this->__Vtogcov__ram[9U] = ((0x1f7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4228]);
        this->__Vtogcov__ram[9U] = ((0x1efU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4229]);
        this->__Vtogcov__ram[9U] = ((0x1dfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4230]);
        this->__Vtogcov__ram[9U] = ((0x1bfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4231]);
        this->__Vtogcov__ram[9U] = ((0x17fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x100U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[4232]);
        this->__Vtogcov__ram[9U] = ((0xffU & this->__Vtogcov__ram
                                     [9U]) | (0x100U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4233]);
        this->__Vtogcov__ram[0xaU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4234]);
        this->__Vtogcov__ram[0xaU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4235]);
        this->__Vtogcov__ram[0xaU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4236]);
        this->__Vtogcov__ram[0xaU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4237]);
        this->__Vtogcov__ram[0xaU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4238]);
        this->__Vtogcov__ram[0xaU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4239]);
        this->__Vtogcov__ram[0xaU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4240]);
        this->__Vtogcov__ram[0xaU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x100U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4241]);
        this->__Vtogcov__ram[0xaU] = ((0xffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4242]);
        this->__Vtogcov__ram[0xbU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4243]);
        this->__Vtogcov__ram[0xbU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4244]);
        this->__Vtogcov__ram[0xbU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4245]);
        this->__Vtogcov__ram[0xbU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4246]);
        this->__Vtogcov__ram[0xbU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4247]);
        this->__Vtogcov__ram[0xbU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4248]);
        this->__Vtogcov__ram[0xbU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4249]);
        this->__Vtogcov__ram[0xbU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x100U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4250]);
        this->__Vtogcov__ram[0xbU] = ((0xffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4251]);
        this->__Vtogcov__ram[0xcU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4252]);
        this->__Vtogcov__ram[0xcU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4253]);
        this->__Vtogcov__ram[0xcU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4254]);
        this->__Vtogcov__ram[0xcU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4255]);
        this->__Vtogcov__ram[0xcU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4256]);
        this->__Vtogcov__ram[0xcU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4257]);
        this->__Vtogcov__ram[0xcU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4258]);
        this->__Vtogcov__ram[0xcU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x100U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4259]);
        this->__Vtogcov__ram[0xcU] = ((0xffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4260]);
        this->__Vtogcov__ram[0xdU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4261]);
        this->__Vtogcov__ram[0xdU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4262]);
        this->__Vtogcov__ram[0xdU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4263]);
        this->__Vtogcov__ram[0xdU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4264]);
        this->__Vtogcov__ram[0xdU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4265]);
        this->__Vtogcov__ram[0xdU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4266]);
        this->__Vtogcov__ram[0xdU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4267]);
        this->__Vtogcov__ram[0xdU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x100U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4268]);
        this->__Vtogcov__ram[0xdU] = ((0xffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4269]);
        this->__Vtogcov__ram[0xeU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4270]);
        this->__Vtogcov__ram[0xeU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4271]);
        this->__Vtogcov__ram[0xeU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4272]);
        this->__Vtogcov__ram[0xeU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4273]);
        this->__Vtogcov__ram[0xeU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4274]);
        this->__Vtogcov__ram[0xeU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4275]);
        this->__Vtogcov__ram[0xeU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4276]);
        this->__Vtogcov__ram[0xeU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x100U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4277]);
        this->__Vtogcov__ram[0xeU] = ((0xffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4278]);
        this->__Vtogcov__ram[0xfU] = ((0x1feU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4279]);
        this->__Vtogcov__ram[0xfU] = ((0x1fdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4280]);
        this->__Vtogcov__ram[0xfU] = ((0x1fbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4281]);
        this->__Vtogcov__ram[0xfU] = ((0x1f7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4282]);
        this->__Vtogcov__ram[0xfU] = ((0x1efU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4283]);
        this->__Vtogcov__ram[0xfU] = ((0x1dfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4284]);
        this->__Vtogcov__ram[0xfU] = ((0x1bfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4285]);
        this->__Vtogcov__ram[0xfU] = ((0x17fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x100U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4286]);
        this->__Vtogcov__ram[0xfU] = ((0xffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4287]);
        this->__Vtogcov__ram[0x10U] = ((0x1feU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4288]);
        this->__Vtogcov__ram[0x10U] = ((0x1fdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4289]);
        this->__Vtogcov__ram[0x10U] = ((0x1fbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4290]);
        this->__Vtogcov__ram[0x10U] = ((0x1f7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4291]);
        this->__Vtogcov__ram[0x10U] = ((0x1efU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4292]);
        this->__Vtogcov__ram[0x10U] = ((0x1dfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4293]);
        this->__Vtogcov__ram[0x10U] = ((0x1bfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4294]);
        this->__Vtogcov__ram[0x10U] = ((0x17fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x100U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4295]);
        this->__Vtogcov__ram[0x10U] = ((0xffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4296]);
        this->__Vtogcov__ram[0x11U] = ((0x1feU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4297]);
        this->__Vtogcov__ram[0x11U] = ((0x1fdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4298]);
        this->__Vtogcov__ram[0x11U] = ((0x1fbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4299]);
        this->__Vtogcov__ram[0x11U] = ((0x1f7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4300]);
        this->__Vtogcov__ram[0x11U] = ((0x1efU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4301]);
        this->__Vtogcov__ram[0x11U] = ((0x1dfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4302]);
        this->__Vtogcov__ram[0x11U] = ((0x1bfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4303]);
        this->__Vtogcov__ram[0x11U] = ((0x17fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x100U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4304]);
        this->__Vtogcov__ram[0x11U] = ((0xffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x11U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__8\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4133]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
                                      >> 1U));
    }
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4134]);
        this->__Vtogcov__dob = ((0x1feU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4135]);
        this->__Vtogcov__dob = ((0x1fdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4136]);
        this->__Vtogcov__dob = ((0x1fbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4137]);
        this->__Vtogcov__dob = ((0x1f7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4138]);
        this->__Vtogcov__dob = ((0x1efU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4139]);
        this->__Vtogcov__dob = ((0x1dfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
    if ((0x40U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4140]);
        this->__Vtogcov__dob = ((0x1bfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->dob)));
    }
    if ((0x80U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4141]);
        this->__Vtogcov__dob = ((0x17fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->dob)));
    }
    if ((0x100U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4142]);
        this->__Vtogcov__dob = ((0xffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x100U & (IData)(this->dob)));
    }
}
