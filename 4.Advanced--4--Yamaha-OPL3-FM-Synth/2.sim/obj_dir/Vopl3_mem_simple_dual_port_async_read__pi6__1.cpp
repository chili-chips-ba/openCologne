// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi6.h"
#include "Vopl3__Syms.h"

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__27(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__27\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                         ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                         : 0U);
    if ((1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4454]);
        this->__Vtogcov__wea = (1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array));
    }
    if ((1U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4455]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->__PVT__dob)));
    }
    if ((2U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4456]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->__PVT__dob)));
    }
    if ((4U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4457]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->__PVT__dob)));
    }
    if ((8U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4458]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->__PVT__dob)));
    }
    if ((0x10U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4459]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->__PVT__dob)));
    }
    if ((0x20U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4460]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->__PVT__dob)));
    }
    if ((0x40U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4461]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->__PVT__dob)));
    }
    if ((0x80U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4462]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->__PVT__dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__20(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__20\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4643]);
    if ((2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4641]);
    }
    if ((1U & (~ ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4642]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array))) {
        this->__Vlvbound2 = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
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
        ++(vlSymsp->__Vcoverage[4463]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4464]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4465]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4466]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4467]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4468]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4469]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4470]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4471]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4472]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4473]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4474]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4475]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4476]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4477]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4478]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4479]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4480]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4481]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4482]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4483]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4484]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4485]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4486]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4487]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4488]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4489]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4490]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4491]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4492]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4493]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4494]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4495]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4496]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4497]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4498]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4499]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4500]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4501]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4502]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4503]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4504]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4505]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4506]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4507]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4508]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4509]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4510]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4511]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4512]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4513]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4514]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4515]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4516]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4517]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4518]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4519]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4520]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4521]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4522]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4523]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4524]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4525]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4526]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4527]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4528]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4529]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4530]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4531]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4532]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4533]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4534]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4535]);
        this->__Vtogcov__ram[9U] = ((0xfeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4536]);
        this->__Vtogcov__ram[9U] = ((0xfdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4537]);
        this->__Vtogcov__ram[9U] = ((0xfbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4538]);
        this->__Vtogcov__ram[9U] = ((0xf7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4539]);
        this->__Vtogcov__ram[9U] = ((0xefU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4540]);
        this->__Vtogcov__ram[9U] = ((0xdfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4541]);
        this->__Vtogcov__ram[9U] = ((0xbfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4542]);
        this->__Vtogcov__ram[9U] = ((0x7fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4543]);
        this->__Vtogcov__ram[0xaU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4544]);
        this->__Vtogcov__ram[0xaU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4545]);
        this->__Vtogcov__ram[0xaU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4546]);
        this->__Vtogcov__ram[0xaU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4547]);
        this->__Vtogcov__ram[0xaU] = ((0xefU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4548]);
        this->__Vtogcov__ram[0xaU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4549]);
        this->__Vtogcov__ram[0xaU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4550]);
        this->__Vtogcov__ram[0xaU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4551]);
        this->__Vtogcov__ram[0xbU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4552]);
        this->__Vtogcov__ram[0xbU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4553]);
        this->__Vtogcov__ram[0xbU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4554]);
        this->__Vtogcov__ram[0xbU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4555]);
        this->__Vtogcov__ram[0xbU] = ((0xefU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4556]);
        this->__Vtogcov__ram[0xbU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4557]);
        this->__Vtogcov__ram[0xbU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4558]);
        this->__Vtogcov__ram[0xbU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4559]);
        this->__Vtogcov__ram[0xcU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4560]);
        this->__Vtogcov__ram[0xcU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4561]);
        this->__Vtogcov__ram[0xcU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4562]);
        this->__Vtogcov__ram[0xcU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4563]);
        this->__Vtogcov__ram[0xcU] = ((0xefU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4564]);
        this->__Vtogcov__ram[0xcU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4565]);
        this->__Vtogcov__ram[0xcU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4566]);
        this->__Vtogcov__ram[0xcU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4567]);
        this->__Vtogcov__ram[0xdU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4568]);
        this->__Vtogcov__ram[0xdU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4569]);
        this->__Vtogcov__ram[0xdU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4570]);
        this->__Vtogcov__ram[0xdU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4571]);
        this->__Vtogcov__ram[0xdU] = ((0xefU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4572]);
        this->__Vtogcov__ram[0xdU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4573]);
        this->__Vtogcov__ram[0xdU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4574]);
        this->__Vtogcov__ram[0xdU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4575]);
        this->__Vtogcov__ram[0xeU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4576]);
        this->__Vtogcov__ram[0xeU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4577]);
        this->__Vtogcov__ram[0xeU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4578]);
        this->__Vtogcov__ram[0xeU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4579]);
        this->__Vtogcov__ram[0xeU] = ((0xefU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4580]);
        this->__Vtogcov__ram[0xeU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4581]);
        this->__Vtogcov__ram[0xeU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4582]);
        this->__Vtogcov__ram[0xeU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4583]);
        this->__Vtogcov__ram[0xfU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4584]);
        this->__Vtogcov__ram[0xfU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4585]);
        this->__Vtogcov__ram[0xfU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4586]);
        this->__Vtogcov__ram[0xfU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4587]);
        this->__Vtogcov__ram[0xfU] = ((0xefU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4588]);
        this->__Vtogcov__ram[0xfU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4589]);
        this->__Vtogcov__ram[0xfU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4590]);
        this->__Vtogcov__ram[0xfU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4591]);
        this->__Vtogcov__ram[0x10U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4592]);
        this->__Vtogcov__ram[0x10U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4593]);
        this->__Vtogcov__ram[0x10U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4594]);
        this->__Vtogcov__ram[0x10U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4595]);
        this->__Vtogcov__ram[0x10U] = ((0xefU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4596]);
        this->__Vtogcov__ram[0x10U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4597]);
        this->__Vtogcov__ram[0x10U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4598]);
        this->__Vtogcov__ram[0x10U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4599]);
        this->__Vtogcov__ram[0x11U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4600]);
        this->__Vtogcov__ram[0x11U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4601]);
        this->__Vtogcov__ram[0x11U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4602]);
        this->__Vtogcov__ram[0x11U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4603]);
        this->__Vtogcov__ram[0x11U] = ((0xefU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4604]);
        this->__Vtogcov__ram[0x11U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4605]);
        this->__Vtogcov__ram[0x11U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4606]);
        this->__Vtogcov__ram[0x11U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4607]);
        this->__Vtogcov__ram[0x12U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4608]);
        this->__Vtogcov__ram[0x12U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4609]);
        this->__Vtogcov__ram[0x12U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((8U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4610]);
        this->__Vtogcov__ram[0x12U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (8U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x10U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4611]);
        this->__Vtogcov__ram[0x12U] = ((0xefU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x20U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4612]);
        this->__Vtogcov__ram[0x12U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x40U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4613]);
        this->__Vtogcov__ram[0x12U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x80U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4614]);
        this->__Vtogcov__ram[0x12U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4615]);
        this->__Vtogcov__ram[0x13U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4616]);
        this->__Vtogcov__ram[0x13U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4617]);
        this->__Vtogcov__ram[0x13U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((8U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4618]);
        this->__Vtogcov__ram[0x13U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (8U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x10U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4619]);
        this->__Vtogcov__ram[0x13U] = ((0xefU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x20U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4620]);
        this->__Vtogcov__ram[0x13U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x40U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4621]);
        this->__Vtogcov__ram[0x13U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x80U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4622]);
        this->__Vtogcov__ram[0x13U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4623]);
        this->__Vtogcov__ram[0x14U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__ram[0x14U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__ram[0x14U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((8U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__ram[0x14U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (8U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x10U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__ram[0x14U] = ((0xefU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x20U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__ram[0x14U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x40U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__ram[0x14U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x80U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__ram[0x14U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__ram[0x15U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__ram[0x15U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0x15U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((8U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0x15U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (8U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x10U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0x15U] = ((0xefU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x20U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0x15U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x40U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0x15U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x80U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0x15U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x15U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__28(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__28\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                         ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                         : 0U);
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4454]);
        this->__Vtogcov__wea = (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem.__PVT__wea_array) 
                                      >> 1U));
    }
    if ((1U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4455]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->__PVT__dob)));
    }
    if ((2U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4456]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->__PVT__dob)));
    }
    if ((4U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4457]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->__PVT__dob)));
    }
    if ((8U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4458]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->__PVT__dob)));
    }
    if ((0x10U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4459]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->__PVT__dob)));
    }
    if ((0x20U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4460]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->__PVT__dob)));
    }
    if ((0x40U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4461]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->__PVT__dob)));
    }
    if ((0x80U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4462]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->__PVT__dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__21(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__21\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4643]);
    if ((1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4641]);
    }
    if ((1U & (~ (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4642]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array))) {
        this->__Vlvbound2 = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
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
        ++(vlSymsp->__Vcoverage[4463]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4464]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4465]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4466]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4467]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4468]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4469]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4470]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4471]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4472]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4473]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4474]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4475]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4476]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4477]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4478]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4479]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4480]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4481]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4482]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4483]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4484]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4485]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4486]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4487]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4488]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4489]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4490]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4491]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4492]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4493]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4494]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4495]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4496]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4497]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4498]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4499]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4500]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4501]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4502]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4503]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4504]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4505]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4506]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4507]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4508]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4509]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4510]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4511]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4512]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4513]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4514]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4515]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4516]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4517]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4518]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4519]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4520]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4521]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4522]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4523]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4524]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4525]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4526]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4527]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4528]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4529]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4530]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4531]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4532]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4533]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4534]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4535]);
        this->__Vtogcov__ram[9U] = ((0xfeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4536]);
        this->__Vtogcov__ram[9U] = ((0xfdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4537]);
        this->__Vtogcov__ram[9U] = ((0xfbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4538]);
        this->__Vtogcov__ram[9U] = ((0xf7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4539]);
        this->__Vtogcov__ram[9U] = ((0xefU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4540]);
        this->__Vtogcov__ram[9U] = ((0xdfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4541]);
        this->__Vtogcov__ram[9U] = ((0xbfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4542]);
        this->__Vtogcov__ram[9U] = ((0x7fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4543]);
        this->__Vtogcov__ram[0xaU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4544]);
        this->__Vtogcov__ram[0xaU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4545]);
        this->__Vtogcov__ram[0xaU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4546]);
        this->__Vtogcov__ram[0xaU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4547]);
        this->__Vtogcov__ram[0xaU] = ((0xefU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4548]);
        this->__Vtogcov__ram[0xaU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4549]);
        this->__Vtogcov__ram[0xaU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4550]);
        this->__Vtogcov__ram[0xaU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4551]);
        this->__Vtogcov__ram[0xbU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4552]);
        this->__Vtogcov__ram[0xbU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4553]);
        this->__Vtogcov__ram[0xbU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4554]);
        this->__Vtogcov__ram[0xbU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4555]);
        this->__Vtogcov__ram[0xbU] = ((0xefU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4556]);
        this->__Vtogcov__ram[0xbU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4557]);
        this->__Vtogcov__ram[0xbU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4558]);
        this->__Vtogcov__ram[0xbU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4559]);
        this->__Vtogcov__ram[0xcU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4560]);
        this->__Vtogcov__ram[0xcU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4561]);
        this->__Vtogcov__ram[0xcU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4562]);
        this->__Vtogcov__ram[0xcU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4563]);
        this->__Vtogcov__ram[0xcU] = ((0xefU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4564]);
        this->__Vtogcov__ram[0xcU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4565]);
        this->__Vtogcov__ram[0xcU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4566]);
        this->__Vtogcov__ram[0xcU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4567]);
        this->__Vtogcov__ram[0xdU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4568]);
        this->__Vtogcov__ram[0xdU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4569]);
        this->__Vtogcov__ram[0xdU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4570]);
        this->__Vtogcov__ram[0xdU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4571]);
        this->__Vtogcov__ram[0xdU] = ((0xefU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4572]);
        this->__Vtogcov__ram[0xdU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4573]);
        this->__Vtogcov__ram[0xdU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4574]);
        this->__Vtogcov__ram[0xdU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4575]);
        this->__Vtogcov__ram[0xeU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4576]);
        this->__Vtogcov__ram[0xeU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4577]);
        this->__Vtogcov__ram[0xeU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4578]);
        this->__Vtogcov__ram[0xeU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4579]);
        this->__Vtogcov__ram[0xeU] = ((0xefU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4580]);
        this->__Vtogcov__ram[0xeU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4581]);
        this->__Vtogcov__ram[0xeU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4582]);
        this->__Vtogcov__ram[0xeU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4583]);
        this->__Vtogcov__ram[0xfU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4584]);
        this->__Vtogcov__ram[0xfU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4585]);
        this->__Vtogcov__ram[0xfU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4586]);
        this->__Vtogcov__ram[0xfU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4587]);
        this->__Vtogcov__ram[0xfU] = ((0xefU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4588]);
        this->__Vtogcov__ram[0xfU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4589]);
        this->__Vtogcov__ram[0xfU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4590]);
        this->__Vtogcov__ram[0xfU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4591]);
        this->__Vtogcov__ram[0x10U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4592]);
        this->__Vtogcov__ram[0x10U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4593]);
        this->__Vtogcov__ram[0x10U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4594]);
        this->__Vtogcov__ram[0x10U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4595]);
        this->__Vtogcov__ram[0x10U] = ((0xefU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4596]);
        this->__Vtogcov__ram[0x10U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4597]);
        this->__Vtogcov__ram[0x10U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4598]);
        this->__Vtogcov__ram[0x10U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4599]);
        this->__Vtogcov__ram[0x11U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4600]);
        this->__Vtogcov__ram[0x11U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4601]);
        this->__Vtogcov__ram[0x11U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4602]);
        this->__Vtogcov__ram[0x11U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4603]);
        this->__Vtogcov__ram[0x11U] = ((0xefU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4604]);
        this->__Vtogcov__ram[0x11U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4605]);
        this->__Vtogcov__ram[0x11U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4606]);
        this->__Vtogcov__ram[0x11U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4607]);
        this->__Vtogcov__ram[0x12U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4608]);
        this->__Vtogcov__ram[0x12U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4609]);
        this->__Vtogcov__ram[0x12U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((8U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4610]);
        this->__Vtogcov__ram[0x12U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (8U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x10U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4611]);
        this->__Vtogcov__ram[0x12U] = ((0xefU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x20U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4612]);
        this->__Vtogcov__ram[0x12U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x40U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4613]);
        this->__Vtogcov__ram[0x12U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x80U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4614]);
        this->__Vtogcov__ram[0x12U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4615]);
        this->__Vtogcov__ram[0x13U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4616]);
        this->__Vtogcov__ram[0x13U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4617]);
        this->__Vtogcov__ram[0x13U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((8U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4618]);
        this->__Vtogcov__ram[0x13U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (8U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x10U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4619]);
        this->__Vtogcov__ram[0x13U] = ((0xefU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x20U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4620]);
        this->__Vtogcov__ram[0x13U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x40U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4621]);
        this->__Vtogcov__ram[0x13U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x80U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4622]);
        this->__Vtogcov__ram[0x13U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4623]);
        this->__Vtogcov__ram[0x14U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__ram[0x14U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__ram[0x14U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((8U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__ram[0x14U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (8U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x10U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__ram[0x14U] = ((0xefU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x20U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__ram[0x14U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x40U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__ram[0x14U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x80U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__ram[0x14U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__ram[0x15U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__ram[0x15U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0x15U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((8U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0x15U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (8U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x10U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0x15U] = ((0xefU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x20U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0x15U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x40U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0x15U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x80U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0x15U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x15U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__29(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__29\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                         ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                         : 0U);
    if ((1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4454]);
        this->__Vtogcov__wea = (1U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array));
    }
    if ((1U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4455]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->__PVT__dob)));
    }
    if ((2U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4456]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->__PVT__dob)));
    }
    if ((4U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4457]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->__PVT__dob)));
    }
    if ((8U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4458]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->__PVT__dob)));
    }
    if ((0x10U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4459]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->__PVT__dob)));
    }
    if ((0x20U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4460]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->__PVT__dob)));
    }
    if ((0x40U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4461]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->__PVT__dob)));
    }
    if ((0x80U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4462]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->__PVT__dob)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__22(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__22\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4643]);
    if ((2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4641]);
    }
    if ((1U & (~ ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4642]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if ((2U & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array))) {
        this->__Vlvbound2 = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
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
        ++(vlSymsp->__Vcoverage[4463]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4464]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4465]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4466]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4467]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4468]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4469]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4470]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4471]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4472]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4473]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4474]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4475]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4476]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4477]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4478]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4479]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4480]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4481]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4482]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4483]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4484]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4485]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4486]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4487]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4488]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4489]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4490]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4491]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4492]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4493]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4494]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4495]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4496]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4497]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4498]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4499]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4500]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4501]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4502]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4503]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4504]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4505]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4506]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4507]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4508]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4509]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4510]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4511]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4512]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4513]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4514]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4515]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4516]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4517]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4518]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4519]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4520]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4521]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4522]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4523]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4524]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4525]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4526]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4527]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4528]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4529]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4530]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4531]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4532]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4533]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4534]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4535]);
        this->__Vtogcov__ram[9U] = ((0xfeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4536]);
        this->__Vtogcov__ram[9U] = ((0xfdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4537]);
        this->__Vtogcov__ram[9U] = ((0xfbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4538]);
        this->__Vtogcov__ram[9U] = ((0xf7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4539]);
        this->__Vtogcov__ram[9U] = ((0xefU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4540]);
        this->__Vtogcov__ram[9U] = ((0xdfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4541]);
        this->__Vtogcov__ram[9U] = ((0xbfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[4542]);
        this->__Vtogcov__ram[9U] = ((0x7fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4543]);
        this->__Vtogcov__ram[0xaU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4544]);
        this->__Vtogcov__ram[0xaU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4545]);
        this->__Vtogcov__ram[0xaU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4546]);
        this->__Vtogcov__ram[0xaU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4547]);
        this->__Vtogcov__ram[0xaU] = ((0xefU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4548]);
        this->__Vtogcov__ram[0xaU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4549]);
        this->__Vtogcov__ram[0xaU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4550]);
        this->__Vtogcov__ram[0xaU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4551]);
        this->__Vtogcov__ram[0xbU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4552]);
        this->__Vtogcov__ram[0xbU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4553]);
        this->__Vtogcov__ram[0xbU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4554]);
        this->__Vtogcov__ram[0xbU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4555]);
        this->__Vtogcov__ram[0xbU] = ((0xefU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4556]);
        this->__Vtogcov__ram[0xbU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4557]);
        this->__Vtogcov__ram[0xbU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4558]);
        this->__Vtogcov__ram[0xbU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4559]);
        this->__Vtogcov__ram[0xcU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4560]);
        this->__Vtogcov__ram[0xcU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4561]);
        this->__Vtogcov__ram[0xcU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4562]);
        this->__Vtogcov__ram[0xcU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4563]);
        this->__Vtogcov__ram[0xcU] = ((0xefU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4564]);
        this->__Vtogcov__ram[0xcU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4565]);
        this->__Vtogcov__ram[0xcU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4566]);
        this->__Vtogcov__ram[0xcU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4567]);
        this->__Vtogcov__ram[0xdU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4568]);
        this->__Vtogcov__ram[0xdU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4569]);
        this->__Vtogcov__ram[0xdU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4570]);
        this->__Vtogcov__ram[0xdU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4571]);
        this->__Vtogcov__ram[0xdU] = ((0xefU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4572]);
        this->__Vtogcov__ram[0xdU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4573]);
        this->__Vtogcov__ram[0xdU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4574]);
        this->__Vtogcov__ram[0xdU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4575]);
        this->__Vtogcov__ram[0xeU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4576]);
        this->__Vtogcov__ram[0xeU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4577]);
        this->__Vtogcov__ram[0xeU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4578]);
        this->__Vtogcov__ram[0xeU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4579]);
        this->__Vtogcov__ram[0xeU] = ((0xefU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4580]);
        this->__Vtogcov__ram[0xeU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4581]);
        this->__Vtogcov__ram[0xeU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4582]);
        this->__Vtogcov__ram[0xeU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4583]);
        this->__Vtogcov__ram[0xfU] = ((0xfeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4584]);
        this->__Vtogcov__ram[0xfU] = ((0xfdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4585]);
        this->__Vtogcov__ram[0xfU] = ((0xfbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4586]);
        this->__Vtogcov__ram[0xfU] = ((0xf7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4587]);
        this->__Vtogcov__ram[0xfU] = ((0xefU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4588]);
        this->__Vtogcov__ram[0xfU] = ((0xdfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4589]);
        this->__Vtogcov__ram[0xfU] = ((0xbfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4590]);
        this->__Vtogcov__ram[0xfU] = ((0x7fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4591]);
        this->__Vtogcov__ram[0x10U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4592]);
        this->__Vtogcov__ram[0x10U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4593]);
        this->__Vtogcov__ram[0x10U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4594]);
        this->__Vtogcov__ram[0x10U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4595]);
        this->__Vtogcov__ram[0x10U] = ((0xefU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4596]);
        this->__Vtogcov__ram[0x10U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4597]);
        this->__Vtogcov__ram[0x10U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4598]);
        this->__Vtogcov__ram[0x10U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4599]);
        this->__Vtogcov__ram[0x11U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4600]);
        this->__Vtogcov__ram[0x11U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4601]);
        this->__Vtogcov__ram[0x11U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4602]);
        this->__Vtogcov__ram[0x11U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4603]);
        this->__Vtogcov__ram[0x11U] = ((0xefU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4604]);
        this->__Vtogcov__ram[0x11U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4605]);
        this->__Vtogcov__ram[0x11U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4606]);
        this->__Vtogcov__ram[0x11U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4607]);
        this->__Vtogcov__ram[0x12U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4608]);
        this->__Vtogcov__ram[0x12U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4609]);
        this->__Vtogcov__ram[0x12U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((8U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4610]);
        this->__Vtogcov__ram[0x12U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (8U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x10U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4611]);
        this->__Vtogcov__ram[0x12U] = ((0xefU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x20U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4612]);
        this->__Vtogcov__ram[0x12U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x40U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4613]);
        this->__Vtogcov__ram[0x12U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((0x80U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
                  [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4614]);
        this->__Vtogcov__ram[0x12U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4615]);
        this->__Vtogcov__ram[0x13U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4616]);
        this->__Vtogcov__ram[0x13U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4617]);
        this->__Vtogcov__ram[0x13U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((8U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4618]);
        this->__Vtogcov__ram[0x13U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (8U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x10U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4619]);
        this->__Vtogcov__ram[0x13U] = ((0xefU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x20U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4620]);
        this->__Vtogcov__ram[0x13U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x40U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4621]);
        this->__Vtogcov__ram[0x13U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((0x80U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
                  [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4622]);
        this->__Vtogcov__ram[0x13U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4623]);
        this->__Vtogcov__ram[0x14U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__ram[0x14U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__ram[0x14U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((8U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__ram[0x14U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (8U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x10U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__ram[0x14U] = ((0xefU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x20U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__ram[0x14U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x40U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__ram[0x14U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((0x80U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
                  [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__ram[0x14U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__ram[0x15U] = ((0xfeU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__ram[0x15U] = ((0xfdU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0x15U] = ((0xfbU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((8U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0x15U] = ((0xf7U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (8U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x10U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0x15U] = ((0xefU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x20U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0x15U] = ((0xdfU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x40U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0x15U] = ((0xbfU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((0x80U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
                  [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0x15U] = ((0x7fU & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x15U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__30(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi6::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__30\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                         ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                         : 0U);
    if ((1U & (((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4454]);
        this->__Vtogcov__wea = (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem.__PVT__wea_array) 
                                      >> 1U));
    }
    if ((1U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4455]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->__PVT__dob)));
    }
    if ((2U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4456]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->__PVT__dob)));
    }
    if ((4U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4457]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->__PVT__dob)));
    }
    if ((8U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4458]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->__PVT__dob)));
    }
    if ((0x10U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4459]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->__PVT__dob)));
    }
    if ((0x20U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4460]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->__PVT__dob)));
    }
    if ((0x40U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4461]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->__PVT__dob)));
    }
    if ((0x80U & ((IData)(this->__PVT__dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4462]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->__PVT__dob)));
    }
}
