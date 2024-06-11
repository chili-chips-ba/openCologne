// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port__pi12.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4882]);
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4880]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4881]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    ++(vlSymsp->__Vcoverage[4887]);
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[4885]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[4886]);
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array))) {
        this->__Vlvbound2 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                        >> 0x19U))))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (IData)(
                                                          (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                                           >> 0x19U)));
        }
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__genblk1__DOT__dob_p1 = this->__PVT__dob_p0;
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4826]);
        this->__Vtogcov__dob = ((0x3fffffeU & this->__Vtogcov__dob) 
                                | (1U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((2U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4827]);
        this->__Vtogcov__dob = ((0x3fffffdU & this->__Vtogcov__dob) 
                                | (2U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((4U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4828]);
        this->__Vtogcov__dob = ((0x3fffffbU & this->__Vtogcov__dob) 
                                | (4U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((8U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4829]);
        this->__Vtogcov__dob = ((0x3fffff7U & this->__Vtogcov__dob) 
                                | (8U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4830]);
        this->__Vtogcov__dob = ((0x3ffffefU & this->__Vtogcov__dob) 
                                | (0x10U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4831]);
        this->__Vtogcov__dob = ((0x3ffffdfU & this->__Vtogcov__dob) 
                                | (0x20U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4832]);
        this->__Vtogcov__dob = ((0x3ffffbfU & this->__Vtogcov__dob) 
                                | (0x40U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4833]);
        this->__Vtogcov__dob = ((0x3ffff7fU & this->__Vtogcov__dob) 
                                | (0x80U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4834]);
        this->__Vtogcov__dob = ((0x3fffeffU & this->__Vtogcov__dob) 
                                | (0x100U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4835]);
        this->__Vtogcov__dob = ((0x3fffdffU & this->__Vtogcov__dob) 
                                | (0x200U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4836]);
        this->__Vtogcov__dob = ((0x3fffbffU & this->__Vtogcov__dob) 
                                | (0x400U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4837]);
        this->__Vtogcov__dob = ((0x3fff7ffU & this->__Vtogcov__dob) 
                                | (0x800U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4838]);
        this->__Vtogcov__dob = ((0x3ffefffU & this->__Vtogcov__dob) 
                                | (0x1000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4839]);
        this->__Vtogcov__dob = ((0x3ffdfffU & this->__Vtogcov__dob) 
                                | (0x2000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x4000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4840]);
        this->__Vtogcov__dob = ((0x3ffbfffU & this->__Vtogcov__dob) 
                                | (0x4000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x8000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4841]);
        this->__Vtogcov__dob = ((0x3ff7fffU & this->__Vtogcov__dob) 
                                | (0x8000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4842]);
        this->__Vtogcov__dob = ((0x3feffffU & this->__Vtogcov__dob) 
                                | (0x10000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4843]);
        this->__Vtogcov__dob = ((0x3fdffffU & this->__Vtogcov__dob) 
                                | (0x20000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4844]);
        this->__Vtogcov__dob = ((0x3fbffffU & this->__Vtogcov__dob) 
                                | (0x40000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4845]);
        this->__Vtogcov__dob = ((0x3f7ffffU & this->__Vtogcov__dob) 
                                | (0x80000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4846]);
        this->__Vtogcov__dob = ((0x3efffffU & this->__Vtogcov__dob) 
                                | (0x100000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4847]);
        this->__Vtogcov__dob = ((0x3dfffffU & this->__Vtogcov__dob) 
                                | (0x200000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4848]);
        this->__Vtogcov__dob = ((0x3bfffffU & this->__Vtogcov__dob) 
                                | (0x400000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4849]);
        this->__Vtogcov__dob = ((0x37fffffU & this->__Vtogcov__dob) 
                                | (0x800000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4850]);
        this->__Vtogcov__dob = ((0x2ffffffU & this->__Vtogcov__dob) 
                                | (0x1000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4851]);
        this->__Vtogcov__dob = ((0x1ffffffU & this->__Vtogcov__dob) 
                                | (0x2000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4824]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array));
    }
    this->__PVT__dob_p0 = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                            ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->__Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4825]);
        this->__Vtogcov__reb = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4852]);
        this->__Vtogcov__dob_p0 = ((0x3fffffeU & this->__Vtogcov__dob_p0) 
                                   | (1U & this->__PVT__dob_p0));
    }
    if ((2U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4853]);
        this->__Vtogcov__dob_p0 = ((0x3fffffdU & this->__Vtogcov__dob_p0) 
                                   | (2U & this->__PVT__dob_p0));
    }
    if ((4U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4854]);
        this->__Vtogcov__dob_p0 = ((0x3fffffbU & this->__Vtogcov__dob_p0) 
                                   | (4U & this->__PVT__dob_p0));
    }
    if ((8U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4855]);
        this->__Vtogcov__dob_p0 = ((0x3fffff7U & this->__Vtogcov__dob_p0) 
                                   | (8U & this->__PVT__dob_p0));
    }
    if ((0x10U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4856]);
        this->__Vtogcov__dob_p0 = ((0x3ffffefU & this->__Vtogcov__dob_p0) 
                                   | (0x10U & this->__PVT__dob_p0));
    }
    if ((0x20U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4857]);
        this->__Vtogcov__dob_p0 = ((0x3ffffdfU & this->__Vtogcov__dob_p0) 
                                   | (0x20U & this->__PVT__dob_p0));
    }
    if ((0x40U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4858]);
        this->__Vtogcov__dob_p0 = ((0x3ffffbfU & this->__Vtogcov__dob_p0) 
                                   | (0x40U & this->__PVT__dob_p0));
    }
    if ((0x80U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4859]);
        this->__Vtogcov__dob_p0 = ((0x3ffff7fU & this->__Vtogcov__dob_p0) 
                                   | (0x80U & this->__PVT__dob_p0));
    }
    if ((0x100U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4860]);
        this->__Vtogcov__dob_p0 = ((0x3fffeffU & this->__Vtogcov__dob_p0) 
                                   | (0x100U & this->__PVT__dob_p0));
    }
    if ((0x200U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4861]);
        this->__Vtogcov__dob_p0 = ((0x3fffdffU & this->__Vtogcov__dob_p0) 
                                   | (0x200U & this->__PVT__dob_p0));
    }
    if ((0x400U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4862]);
        this->__Vtogcov__dob_p0 = ((0x3fffbffU & this->__Vtogcov__dob_p0) 
                                   | (0x400U & this->__PVT__dob_p0));
    }
    if ((0x800U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4863]);
        this->__Vtogcov__dob_p0 = ((0x3fff7ffU & this->__Vtogcov__dob_p0) 
                                   | (0x800U & this->__PVT__dob_p0));
    }
    if ((0x1000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4864]);
        this->__Vtogcov__dob_p0 = ((0x3ffefffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000U & this->__PVT__dob_p0));
    }
    if ((0x2000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4865]);
        this->__Vtogcov__dob_p0 = ((0x3ffdfffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000U & this->__PVT__dob_p0));
    }
    if ((0x4000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4866]);
        this->__Vtogcov__dob_p0 = ((0x3ffbfffU & this->__Vtogcov__dob_p0) 
                                   | (0x4000U & this->__PVT__dob_p0));
    }
    if ((0x8000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4867]);
        this->__Vtogcov__dob_p0 = ((0x3ff7fffU & this->__Vtogcov__dob_p0) 
                                   | (0x8000U & this->__PVT__dob_p0));
    }
    if ((0x10000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4868]);
        this->__Vtogcov__dob_p0 = ((0x3feffffU & this->__Vtogcov__dob_p0) 
                                   | (0x10000U & this->__PVT__dob_p0));
    }
    if ((0x20000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4869]);
        this->__Vtogcov__dob_p0 = ((0x3fdffffU & this->__Vtogcov__dob_p0) 
                                   | (0x20000U & this->__PVT__dob_p0));
    }
    if ((0x40000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4870]);
        this->__Vtogcov__dob_p0 = ((0x3fbffffU & this->__Vtogcov__dob_p0) 
                                   | (0x40000U & this->__PVT__dob_p0));
    }
    if ((0x80000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4871]);
        this->__Vtogcov__dob_p0 = ((0x3f7ffffU & this->__Vtogcov__dob_p0) 
                                   | (0x80000U & this->__PVT__dob_p0));
    }
    if ((0x100000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4872]);
        this->__Vtogcov__dob_p0 = ((0x3efffffU & this->__Vtogcov__dob_p0) 
                                   | (0x100000U & this->__PVT__dob_p0));
    }
    if ((0x200000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4873]);
        this->__Vtogcov__dob_p0 = ((0x3dfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x200000U & this->__PVT__dob_p0));
    }
    if ((0x400000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4874]);
        this->__Vtogcov__dob_p0 = ((0x3bfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x400000U & this->__PVT__dob_p0));
    }
    if ((0x800000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4875]);
        this->__Vtogcov__dob_p0 = ((0x37fffffU & this->__Vtogcov__dob_p0) 
                                   | (0x800000U & this->__PVT__dob_p0));
    }
    if ((0x1000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4876]);
        this->__Vtogcov__dob_p0 = ((0x2ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000000U & this->__PVT__dob_p0));
    }
    if ((0x2000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4877]);
        this->__Vtogcov__dob_p0 = ((0x1ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000000U & this->__PVT__dob_p0));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4882]);
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4880]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4881]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    ++(vlSymsp->__Vcoverage[4887]);
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[4885]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[4886]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array))) {
        this->__Vlvbound2 = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                        >> 0x19U))))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (IData)(
                                                          (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                                           >> 0x19U)));
        }
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__genblk1__DOT__dob_p1 = this->__PVT__dob_p0;
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4826]);
        this->__Vtogcov__dob = ((0x3fffffeU & this->__Vtogcov__dob) 
                                | (1U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((2U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4827]);
        this->__Vtogcov__dob = ((0x3fffffdU & this->__Vtogcov__dob) 
                                | (2U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((4U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4828]);
        this->__Vtogcov__dob = ((0x3fffffbU & this->__Vtogcov__dob) 
                                | (4U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((8U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4829]);
        this->__Vtogcov__dob = ((0x3fffff7U & this->__Vtogcov__dob) 
                                | (8U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4830]);
        this->__Vtogcov__dob = ((0x3ffffefU & this->__Vtogcov__dob) 
                                | (0x10U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4831]);
        this->__Vtogcov__dob = ((0x3ffffdfU & this->__Vtogcov__dob) 
                                | (0x20U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4832]);
        this->__Vtogcov__dob = ((0x3ffffbfU & this->__Vtogcov__dob) 
                                | (0x40U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4833]);
        this->__Vtogcov__dob = ((0x3ffff7fU & this->__Vtogcov__dob) 
                                | (0x80U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4834]);
        this->__Vtogcov__dob = ((0x3fffeffU & this->__Vtogcov__dob) 
                                | (0x100U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4835]);
        this->__Vtogcov__dob = ((0x3fffdffU & this->__Vtogcov__dob) 
                                | (0x200U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4836]);
        this->__Vtogcov__dob = ((0x3fffbffU & this->__Vtogcov__dob) 
                                | (0x400U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4837]);
        this->__Vtogcov__dob = ((0x3fff7ffU & this->__Vtogcov__dob) 
                                | (0x800U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4838]);
        this->__Vtogcov__dob = ((0x3ffefffU & this->__Vtogcov__dob) 
                                | (0x1000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4839]);
        this->__Vtogcov__dob = ((0x3ffdfffU & this->__Vtogcov__dob) 
                                | (0x2000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x4000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4840]);
        this->__Vtogcov__dob = ((0x3ffbfffU & this->__Vtogcov__dob) 
                                | (0x4000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x8000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4841]);
        this->__Vtogcov__dob = ((0x3ff7fffU & this->__Vtogcov__dob) 
                                | (0x8000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4842]);
        this->__Vtogcov__dob = ((0x3feffffU & this->__Vtogcov__dob) 
                                | (0x10000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4843]);
        this->__Vtogcov__dob = ((0x3fdffffU & this->__Vtogcov__dob) 
                                | (0x20000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4844]);
        this->__Vtogcov__dob = ((0x3fbffffU & this->__Vtogcov__dob) 
                                | (0x40000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4845]);
        this->__Vtogcov__dob = ((0x3f7ffffU & this->__Vtogcov__dob) 
                                | (0x80000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4846]);
        this->__Vtogcov__dob = ((0x3efffffU & this->__Vtogcov__dob) 
                                | (0x100000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4847]);
        this->__Vtogcov__dob = ((0x3dfffffU & this->__Vtogcov__dob) 
                                | (0x200000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4848]);
        this->__Vtogcov__dob = ((0x3bfffffU & this->__Vtogcov__dob) 
                                | (0x400000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4849]);
        this->__Vtogcov__dob = ((0x37fffffU & this->__Vtogcov__dob) 
                                | (0x800000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4850]);
        this->__Vtogcov__dob = ((0x2ffffffU & this->__Vtogcov__dob) 
                                | (0x1000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4851]);
        this->__Vtogcov__dob = ((0x1ffffffU & this->__Vtogcov__dob) 
                                | (0x2000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4824]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
                                      >> 1U));
    }
    this->__PVT__dob_p0 = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                            ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->__Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4825]);
        this->__Vtogcov__reb = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4852]);
        this->__Vtogcov__dob_p0 = ((0x3fffffeU & this->__Vtogcov__dob_p0) 
                                   | (1U & this->__PVT__dob_p0));
    }
    if ((2U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4853]);
        this->__Vtogcov__dob_p0 = ((0x3fffffdU & this->__Vtogcov__dob_p0) 
                                   | (2U & this->__PVT__dob_p0));
    }
    if ((4U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4854]);
        this->__Vtogcov__dob_p0 = ((0x3fffffbU & this->__Vtogcov__dob_p0) 
                                   | (4U & this->__PVT__dob_p0));
    }
    if ((8U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4855]);
        this->__Vtogcov__dob_p0 = ((0x3fffff7U & this->__Vtogcov__dob_p0) 
                                   | (8U & this->__PVT__dob_p0));
    }
    if ((0x10U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4856]);
        this->__Vtogcov__dob_p0 = ((0x3ffffefU & this->__Vtogcov__dob_p0) 
                                   | (0x10U & this->__PVT__dob_p0));
    }
    if ((0x20U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4857]);
        this->__Vtogcov__dob_p0 = ((0x3ffffdfU & this->__Vtogcov__dob_p0) 
                                   | (0x20U & this->__PVT__dob_p0));
    }
    if ((0x40U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4858]);
        this->__Vtogcov__dob_p0 = ((0x3ffffbfU & this->__Vtogcov__dob_p0) 
                                   | (0x40U & this->__PVT__dob_p0));
    }
    if ((0x80U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4859]);
        this->__Vtogcov__dob_p0 = ((0x3ffff7fU & this->__Vtogcov__dob_p0) 
                                   | (0x80U & this->__PVT__dob_p0));
    }
    if ((0x100U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4860]);
        this->__Vtogcov__dob_p0 = ((0x3fffeffU & this->__Vtogcov__dob_p0) 
                                   | (0x100U & this->__PVT__dob_p0));
    }
    if ((0x200U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4861]);
        this->__Vtogcov__dob_p0 = ((0x3fffdffU & this->__Vtogcov__dob_p0) 
                                   | (0x200U & this->__PVT__dob_p0));
    }
    if ((0x400U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4862]);
        this->__Vtogcov__dob_p0 = ((0x3fffbffU & this->__Vtogcov__dob_p0) 
                                   | (0x400U & this->__PVT__dob_p0));
    }
    if ((0x800U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4863]);
        this->__Vtogcov__dob_p0 = ((0x3fff7ffU & this->__Vtogcov__dob_p0) 
                                   | (0x800U & this->__PVT__dob_p0));
    }
    if ((0x1000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4864]);
        this->__Vtogcov__dob_p0 = ((0x3ffefffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000U & this->__PVT__dob_p0));
    }
    if ((0x2000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4865]);
        this->__Vtogcov__dob_p0 = ((0x3ffdfffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000U & this->__PVT__dob_p0));
    }
    if ((0x4000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4866]);
        this->__Vtogcov__dob_p0 = ((0x3ffbfffU & this->__Vtogcov__dob_p0) 
                                   | (0x4000U & this->__PVT__dob_p0));
    }
    if ((0x8000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4867]);
        this->__Vtogcov__dob_p0 = ((0x3ff7fffU & this->__Vtogcov__dob_p0) 
                                   | (0x8000U & this->__PVT__dob_p0));
    }
    if ((0x10000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4868]);
        this->__Vtogcov__dob_p0 = ((0x3feffffU & this->__Vtogcov__dob_p0) 
                                   | (0x10000U & this->__PVT__dob_p0));
    }
    if ((0x20000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4869]);
        this->__Vtogcov__dob_p0 = ((0x3fdffffU & this->__Vtogcov__dob_p0) 
                                   | (0x20000U & this->__PVT__dob_p0));
    }
    if ((0x40000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4870]);
        this->__Vtogcov__dob_p0 = ((0x3fbffffU & this->__Vtogcov__dob_p0) 
                                   | (0x40000U & this->__PVT__dob_p0));
    }
    if ((0x80000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4871]);
        this->__Vtogcov__dob_p0 = ((0x3f7ffffU & this->__Vtogcov__dob_p0) 
                                   | (0x80000U & this->__PVT__dob_p0));
    }
    if ((0x100000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4872]);
        this->__Vtogcov__dob_p0 = ((0x3efffffU & this->__Vtogcov__dob_p0) 
                                   | (0x100000U & this->__PVT__dob_p0));
    }
    if ((0x200000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4873]);
        this->__Vtogcov__dob_p0 = ((0x3dfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x200000U & this->__PVT__dob_p0));
    }
    if ((0x400000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4874]);
        this->__Vtogcov__dob_p0 = ((0x3bfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x400000U & this->__PVT__dob_p0));
    }
    if ((0x800000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4875]);
        this->__Vtogcov__dob_p0 = ((0x37fffffU & this->__Vtogcov__dob_p0) 
                                   | (0x800000U & this->__PVT__dob_p0));
    }
    if ((0x1000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4876]);
        this->__Vtogcov__dob_p0 = ((0x2ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000000U & this->__PVT__dob_p0));
    }
    if ((0x2000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4877]);
        this->__Vtogcov__dob_p0 = ((0x1ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000000U & this->__PVT__dob_p0));
    }
}
