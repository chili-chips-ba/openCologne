// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port__pi12.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port__pi12) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port__pi12::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port__pi12::~Vopl3_mem_simple_dual_port__pi12() {
}

// Coverage
void Vopl3_mem_simple_dual_port__pi12::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port__pi12::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4862]);
    ++(vlSymsp->__Vcoverage[4867]);
}

void Vopl3_mem_simple_dual_port__pi12::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[9U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0xaU] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0xbU] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0xcU] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0xdU] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0xeU] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0xfU] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0x10U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    this->__PVT__ram[0x11U] = 0U;
    ++(vlSymsp->__Vcoverage[4857]);
    ++(vlSymsp->__Vcoverage[4858]);
    this->__PVT__genblk1__DOT__dob_p1 = 0U;
    ++(vlSymsp->__Vcoverage[4863]);
}

void Vopl3_mem_simple_dual_port__pi12::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4805]);
        this->__Vtogcov__dob = ((0x3fffffeU & this->__Vtogcov__dob) 
                                | (1U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((2U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4806]);
        this->__Vtogcov__dob = ((0x3fffffdU & this->__Vtogcov__dob) 
                                | (2U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((4U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4807]);
        this->__Vtogcov__dob = ((0x3fffffbU & this->__Vtogcov__dob) 
                                | (4U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((8U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4808]);
        this->__Vtogcov__dob = ((0x3fffff7U & this->__Vtogcov__dob) 
                                | (8U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4809]);
        this->__Vtogcov__dob = ((0x3ffffefU & this->__Vtogcov__dob) 
                                | (0x10U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4810]);
        this->__Vtogcov__dob = ((0x3ffffdfU & this->__Vtogcov__dob) 
                                | (0x20U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4811]);
        this->__Vtogcov__dob = ((0x3ffffbfU & this->__Vtogcov__dob) 
                                | (0x40U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4812]);
        this->__Vtogcov__dob = ((0x3ffff7fU & this->__Vtogcov__dob) 
                                | (0x80U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4813]);
        this->__Vtogcov__dob = ((0x3fffeffU & this->__Vtogcov__dob) 
                                | (0x100U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4814]);
        this->__Vtogcov__dob = ((0x3fffdffU & this->__Vtogcov__dob) 
                                | (0x200U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4815]);
        this->__Vtogcov__dob = ((0x3fffbffU & this->__Vtogcov__dob) 
                                | (0x400U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4816]);
        this->__Vtogcov__dob = ((0x3fff7ffU & this->__Vtogcov__dob) 
                                | (0x800U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4817]);
        this->__Vtogcov__dob = ((0x3ffefffU & this->__Vtogcov__dob) 
                                | (0x1000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4818]);
        this->__Vtogcov__dob = ((0x3ffdfffU & this->__Vtogcov__dob) 
                                | (0x2000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x4000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4819]);
        this->__Vtogcov__dob = ((0x3ffbfffU & this->__Vtogcov__dob) 
                                | (0x4000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x8000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4820]);
        this->__Vtogcov__dob = ((0x3ff7fffU & this->__Vtogcov__dob) 
                                | (0x8000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4821]);
        this->__Vtogcov__dob = ((0x3feffffU & this->__Vtogcov__dob) 
                                | (0x10000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4822]);
        this->__Vtogcov__dob = ((0x3fdffffU & this->__Vtogcov__dob) 
                                | (0x20000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4823]);
        this->__Vtogcov__dob = ((0x3fbffffU & this->__Vtogcov__dob) 
                                | (0x40000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4824]);
        this->__Vtogcov__dob = ((0x3f7ffffU & this->__Vtogcov__dob) 
                                | (0x80000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4825]);
        this->__Vtogcov__dob = ((0x3efffffU & this->__Vtogcov__dob) 
                                | (0x100000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4826]);
        this->__Vtogcov__dob = ((0x3dfffffU & this->__Vtogcov__dob) 
                                | (0x200000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4827]);
        this->__Vtogcov__dob = ((0x3bfffffU & this->__Vtogcov__dob) 
                                | (0x400000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4828]);
        this->__Vtogcov__dob = ((0x37fffffU & this->__Vtogcov__dob) 
                                | (0x800000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4829]);
        this->__Vtogcov__dob = ((0x2ffffffU & this->__Vtogcov__dob) 
                                | (0x1000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4830]);
        this->__Vtogcov__dob = ((0x1ffffffU & this->__Vtogcov__dob) 
                                | (0x2000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4803]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array));
    }
    this->__PVT__dob_p0 = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                            ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->__Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4804]);
        this->__Vtogcov__reb = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4831]);
        this->__Vtogcov__dob_p0 = ((0x3fffffeU & this->__Vtogcov__dob_p0) 
                                   | (1U & this->__PVT__dob_p0));
    }
    if ((2U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4832]);
        this->__Vtogcov__dob_p0 = ((0x3fffffdU & this->__Vtogcov__dob_p0) 
                                   | (2U & this->__PVT__dob_p0));
    }
    if ((4U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4833]);
        this->__Vtogcov__dob_p0 = ((0x3fffffbU & this->__Vtogcov__dob_p0) 
                                   | (4U & this->__PVT__dob_p0));
    }
    if ((8U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4834]);
        this->__Vtogcov__dob_p0 = ((0x3fffff7U & this->__Vtogcov__dob_p0) 
                                   | (8U & this->__PVT__dob_p0));
    }
    if ((0x10U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4835]);
        this->__Vtogcov__dob_p0 = ((0x3ffffefU & this->__Vtogcov__dob_p0) 
                                   | (0x10U & this->__PVT__dob_p0));
    }
    if ((0x20U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4836]);
        this->__Vtogcov__dob_p0 = ((0x3ffffdfU & this->__Vtogcov__dob_p0) 
                                   | (0x20U & this->__PVT__dob_p0));
    }
    if ((0x40U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4837]);
        this->__Vtogcov__dob_p0 = ((0x3ffffbfU & this->__Vtogcov__dob_p0) 
                                   | (0x40U & this->__PVT__dob_p0));
    }
    if ((0x80U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4838]);
        this->__Vtogcov__dob_p0 = ((0x3ffff7fU & this->__Vtogcov__dob_p0) 
                                   | (0x80U & this->__PVT__dob_p0));
    }
    if ((0x100U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4839]);
        this->__Vtogcov__dob_p0 = ((0x3fffeffU & this->__Vtogcov__dob_p0) 
                                   | (0x100U & this->__PVT__dob_p0));
    }
    if ((0x200U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4840]);
        this->__Vtogcov__dob_p0 = ((0x3fffdffU & this->__Vtogcov__dob_p0) 
                                   | (0x200U & this->__PVT__dob_p0));
    }
    if ((0x400U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4841]);
        this->__Vtogcov__dob_p0 = ((0x3fffbffU & this->__Vtogcov__dob_p0) 
                                   | (0x400U & this->__PVT__dob_p0));
    }
    if ((0x800U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4842]);
        this->__Vtogcov__dob_p0 = ((0x3fff7ffU & this->__Vtogcov__dob_p0) 
                                   | (0x800U & this->__PVT__dob_p0));
    }
    if ((0x1000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4843]);
        this->__Vtogcov__dob_p0 = ((0x3ffefffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000U & this->__PVT__dob_p0));
    }
    if ((0x2000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4844]);
        this->__Vtogcov__dob_p0 = ((0x3ffdfffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000U & this->__PVT__dob_p0));
    }
    if ((0x4000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4845]);
        this->__Vtogcov__dob_p0 = ((0x3ffbfffU & this->__Vtogcov__dob_p0) 
                                   | (0x4000U & this->__PVT__dob_p0));
    }
    if ((0x8000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4846]);
        this->__Vtogcov__dob_p0 = ((0x3ff7fffU & this->__Vtogcov__dob_p0) 
                                   | (0x8000U & this->__PVT__dob_p0));
    }
    if ((0x10000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4847]);
        this->__Vtogcov__dob_p0 = ((0x3feffffU & this->__Vtogcov__dob_p0) 
                                   | (0x10000U & this->__PVT__dob_p0));
    }
    if ((0x20000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4848]);
        this->__Vtogcov__dob_p0 = ((0x3fdffffU & this->__Vtogcov__dob_p0) 
                                   | (0x20000U & this->__PVT__dob_p0));
    }
    if ((0x40000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4849]);
        this->__Vtogcov__dob_p0 = ((0x3fbffffU & this->__Vtogcov__dob_p0) 
                                   | (0x40000U & this->__PVT__dob_p0));
    }
    if ((0x80000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4850]);
        this->__Vtogcov__dob_p0 = ((0x3f7ffffU & this->__Vtogcov__dob_p0) 
                                   | (0x80000U & this->__PVT__dob_p0));
    }
    if ((0x100000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4851]);
        this->__Vtogcov__dob_p0 = ((0x3efffffU & this->__Vtogcov__dob_p0) 
                                   | (0x100000U & this->__PVT__dob_p0));
    }
    if ((0x200000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4852]);
        this->__Vtogcov__dob_p0 = ((0x3dfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x200000U & this->__PVT__dob_p0));
    }
    if ((0x400000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4853]);
        this->__Vtogcov__dob_p0 = ((0x3bfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x400000U & this->__PVT__dob_p0));
    }
    if ((0x800000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4854]);
        this->__Vtogcov__dob_p0 = ((0x37fffffU & this->__Vtogcov__dob_p0) 
                                   | (0x800000U & this->__PVT__dob_p0));
    }
    if ((0x1000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4855]);
        this->__Vtogcov__dob_p0 = ((0x2ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000000U & this->__PVT__dob_p0));
    }
    if ((0x2000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4856]);
        this->__Vtogcov__dob_p0 = ((0x1ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000000U & this->__PVT__dob_p0));
    }
}

void Vopl3_mem_simple_dual_port__pi12::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4805]);
        this->__Vtogcov__dob = ((0x3fffffeU & this->__Vtogcov__dob) 
                                | (1U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((2U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4806]);
        this->__Vtogcov__dob = ((0x3fffffdU & this->__Vtogcov__dob) 
                                | (2U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((4U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4807]);
        this->__Vtogcov__dob = ((0x3fffffbU & this->__Vtogcov__dob) 
                                | (4U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((8U & (this->__PVT__genblk1__DOT__dob_p1 ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4808]);
        this->__Vtogcov__dob = ((0x3fffff7U & this->__Vtogcov__dob) 
                                | (8U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4809]);
        this->__Vtogcov__dob = ((0x3ffffefU & this->__Vtogcov__dob) 
                                | (0x10U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4810]);
        this->__Vtogcov__dob = ((0x3ffffdfU & this->__Vtogcov__dob) 
                                | (0x20U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4811]);
        this->__Vtogcov__dob = ((0x3ffffbfU & this->__Vtogcov__dob) 
                                | (0x40U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80U & (this->__PVT__genblk1__DOT__dob_p1 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4812]);
        this->__Vtogcov__dob = ((0x3ffff7fU & this->__Vtogcov__dob) 
                                | (0x80U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4813]);
        this->__Vtogcov__dob = ((0x3fffeffU & this->__Vtogcov__dob) 
                                | (0x100U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4814]);
        this->__Vtogcov__dob = ((0x3fffdffU & this->__Vtogcov__dob) 
                                | (0x200U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4815]);
        this->__Vtogcov__dob = ((0x3fffbffU & this->__Vtogcov__dob) 
                                | (0x400U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800U & (this->__PVT__genblk1__DOT__dob_p1 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4816]);
        this->__Vtogcov__dob = ((0x3fff7ffU & this->__Vtogcov__dob) 
                                | (0x800U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4817]);
        this->__Vtogcov__dob = ((0x3ffefffU & this->__Vtogcov__dob) 
                                | (0x1000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4818]);
        this->__Vtogcov__dob = ((0x3ffdfffU & this->__Vtogcov__dob) 
                                | (0x2000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x4000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4819]);
        this->__Vtogcov__dob = ((0x3ffbfffU & this->__Vtogcov__dob) 
                                | (0x4000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x8000U & (this->__PVT__genblk1__DOT__dob_p1 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4820]);
        this->__Vtogcov__dob = ((0x3ff7fffU & this->__Vtogcov__dob) 
                                | (0x8000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x10000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4821]);
        this->__Vtogcov__dob = ((0x3feffffU & this->__Vtogcov__dob) 
                                | (0x10000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x20000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4822]);
        this->__Vtogcov__dob = ((0x3fdffffU & this->__Vtogcov__dob) 
                                | (0x20000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x40000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4823]);
        this->__Vtogcov__dob = ((0x3fbffffU & this->__Vtogcov__dob) 
                                | (0x40000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x80000U & (this->__PVT__genblk1__DOT__dob_p1 
                     ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4824]);
        this->__Vtogcov__dob = ((0x3f7ffffU & this->__Vtogcov__dob) 
                                | (0x80000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x100000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4825]);
        this->__Vtogcov__dob = ((0x3efffffU & this->__Vtogcov__dob) 
                                | (0x100000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x200000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4826]);
        this->__Vtogcov__dob = ((0x3dfffffU & this->__Vtogcov__dob) 
                                | (0x200000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x400000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4827]);
        this->__Vtogcov__dob = ((0x3bfffffU & this->__Vtogcov__dob) 
                                | (0x400000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x800000U & (this->__PVT__genblk1__DOT__dob_p1 
                      ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4828]);
        this->__Vtogcov__dob = ((0x37fffffU & this->__Vtogcov__dob) 
                                | (0x800000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x1000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4829]);
        this->__Vtogcov__dob = ((0x2ffffffU & this->__Vtogcov__dob) 
                                | (0x1000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((0x2000000U & (this->__PVT__genblk1__DOT__dob_p1 
                       ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4830]);
        this->__Vtogcov__dob = ((0x1ffffffU & this->__Vtogcov__dob) 
                                | (0x2000000U & this->__PVT__genblk1__DOT__dob_p1));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4803]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
                                      >> 1U));
    }
    this->__PVT__dob_p0 = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                            ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->__Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4804]);
        this->__Vtogcov__reb = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4831]);
        this->__Vtogcov__dob_p0 = ((0x3fffffeU & this->__Vtogcov__dob_p0) 
                                   | (1U & this->__PVT__dob_p0));
    }
    if ((2U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4832]);
        this->__Vtogcov__dob_p0 = ((0x3fffffdU & this->__Vtogcov__dob_p0) 
                                   | (2U & this->__PVT__dob_p0));
    }
    if ((4U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4833]);
        this->__Vtogcov__dob_p0 = ((0x3fffffbU & this->__Vtogcov__dob_p0) 
                                   | (4U & this->__PVT__dob_p0));
    }
    if ((8U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4834]);
        this->__Vtogcov__dob_p0 = ((0x3fffff7U & this->__Vtogcov__dob_p0) 
                                   | (8U & this->__PVT__dob_p0));
    }
    if ((0x10U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4835]);
        this->__Vtogcov__dob_p0 = ((0x3ffffefU & this->__Vtogcov__dob_p0) 
                                   | (0x10U & this->__PVT__dob_p0));
    }
    if ((0x20U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4836]);
        this->__Vtogcov__dob_p0 = ((0x3ffffdfU & this->__Vtogcov__dob_p0) 
                                   | (0x20U & this->__PVT__dob_p0));
    }
    if ((0x40U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4837]);
        this->__Vtogcov__dob_p0 = ((0x3ffffbfU & this->__Vtogcov__dob_p0) 
                                   | (0x40U & this->__PVT__dob_p0));
    }
    if ((0x80U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4838]);
        this->__Vtogcov__dob_p0 = ((0x3ffff7fU & this->__Vtogcov__dob_p0) 
                                   | (0x80U & this->__PVT__dob_p0));
    }
    if ((0x100U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4839]);
        this->__Vtogcov__dob_p0 = ((0x3fffeffU & this->__Vtogcov__dob_p0) 
                                   | (0x100U & this->__PVT__dob_p0));
    }
    if ((0x200U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4840]);
        this->__Vtogcov__dob_p0 = ((0x3fffdffU & this->__Vtogcov__dob_p0) 
                                   | (0x200U & this->__PVT__dob_p0));
    }
    if ((0x400U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4841]);
        this->__Vtogcov__dob_p0 = ((0x3fffbffU & this->__Vtogcov__dob_p0) 
                                   | (0x400U & this->__PVT__dob_p0));
    }
    if ((0x800U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4842]);
        this->__Vtogcov__dob_p0 = ((0x3fff7ffU & this->__Vtogcov__dob_p0) 
                                   | (0x800U & this->__PVT__dob_p0));
    }
    if ((0x1000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4843]);
        this->__Vtogcov__dob_p0 = ((0x3ffefffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000U & this->__PVT__dob_p0));
    }
    if ((0x2000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4844]);
        this->__Vtogcov__dob_p0 = ((0x3ffdfffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000U & this->__PVT__dob_p0));
    }
    if ((0x4000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4845]);
        this->__Vtogcov__dob_p0 = ((0x3ffbfffU & this->__Vtogcov__dob_p0) 
                                   | (0x4000U & this->__PVT__dob_p0));
    }
    if ((0x8000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4846]);
        this->__Vtogcov__dob_p0 = ((0x3ff7fffU & this->__Vtogcov__dob_p0) 
                                   | (0x8000U & this->__PVT__dob_p0));
    }
    if ((0x10000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4847]);
        this->__Vtogcov__dob_p0 = ((0x3feffffU & this->__Vtogcov__dob_p0) 
                                   | (0x10000U & this->__PVT__dob_p0));
    }
    if ((0x20000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4848]);
        this->__Vtogcov__dob_p0 = ((0x3fdffffU & this->__Vtogcov__dob_p0) 
                                   | (0x20000U & this->__PVT__dob_p0));
    }
    if ((0x40000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4849]);
        this->__Vtogcov__dob_p0 = ((0x3fbffffU & this->__Vtogcov__dob_p0) 
                                   | (0x40000U & this->__PVT__dob_p0));
    }
    if ((0x80000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4850]);
        this->__Vtogcov__dob_p0 = ((0x3f7ffffU & this->__Vtogcov__dob_p0) 
                                   | (0x80000U & this->__PVT__dob_p0));
    }
    if ((0x100000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4851]);
        this->__Vtogcov__dob_p0 = ((0x3efffffU & this->__Vtogcov__dob_p0) 
                                   | (0x100000U & this->__PVT__dob_p0));
    }
    if ((0x200000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4852]);
        this->__Vtogcov__dob_p0 = ((0x3dfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x200000U & this->__PVT__dob_p0));
    }
    if ((0x400000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4853]);
        this->__Vtogcov__dob_p0 = ((0x3bfffffU & this->__Vtogcov__dob_p0) 
                                   | (0x400000U & this->__PVT__dob_p0));
    }
    if ((0x800000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4854]);
        this->__Vtogcov__dob_p0 = ((0x37fffffU & this->__Vtogcov__dob_p0) 
                                   | (0x800000U & this->__PVT__dob_p0));
    }
    if ((0x1000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4855]);
        this->__Vtogcov__dob_p0 = ((0x2ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x1000000U & this->__PVT__dob_p0));
    }
    if ((0x2000000U & (this->__PVT__dob_p0 ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4856]);
        this->__Vtogcov__dob_p0 = ((0x1ffffffU & this->__Vtogcov__dob_p0) 
                                   | (0x2000000U & this->__PVT__dob_p0));
    }
}

void Vopl3_mem_simple_dual_port__pi12::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    clkb = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    reb = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(26);
    dob = VL_RAND_RESET_I(26);
    __PVT__dob_p0 = VL_RAND_RESET_I(26);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(26);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__reb = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(26);
    __Vtogcov__dob_p0 = VL_RAND_RESET_I(26);
    __PVT__genblk1__DOT__dob_p1 = VL_RAND_RESET_I(26);
    __Vlvbound2 = VL_RAND_RESET_I(26);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(26);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port__pi12::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi12::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 50, 16, "", "v_toggle/mem_simple_dual_port__pi12", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 51, 16, "", "v_toggle/mem_simple_dual_port__pi12", "clkb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4803]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 52, 16, "", "v_toggle/mem_simple_dual_port__pi12", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4804]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 53, 16, "", "v_toggle/mem_simple_dual_port__pi12", "reb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1344]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1345]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1346]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1347]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1348]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi12", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1449]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1450]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1451]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1452]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1453]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1454]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1455]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1456]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1457]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1458]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1459]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1460]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1461]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1462]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1463]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1464]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1465]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1466]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1467]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1468]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1469]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1470]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1471]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1472]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1473]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1474]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi12", "dia[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4805]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4806]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4807]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4808]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4809]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4810]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4811]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4812]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4813]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4814]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4815]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4816]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4817]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4818]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4819]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4820]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4821]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4822]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4823]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4824]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4825]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4826]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4827]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4828]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4829]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4830]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi12", "dob[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4831]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4832]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4833]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4834]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4835]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4836]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4837]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4838]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4839]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4840]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4841]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4842]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4843]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4844]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4845]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4846]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4847]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4848]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4849]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4850]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4851]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4852]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4853]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4854]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4855]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4856]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi12", "dob_p0[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4857]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 72, 9, "", "v_line/mem_simple_dual_port__pi12", "block", "72-73");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4858]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 71, 5, "", "v_line/mem_simple_dual_port__pi12", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4859]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 9, "", "v_branch/mem_simple_dual_port__pi12", "if", "78-79");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4860]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 10, "", "v_branch/mem_simple_dual_port__pi12", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4861]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 77, 5, "", "v_line/mem_simple_dual_port__pi12", "block", "77");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4862]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 81, 5, "", "v_line/mem_simple_dual_port__pi12", "block", "81");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4863]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 85, 41, "", "v_line/mem_simple_dual_port__pi12", "block", "85");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4864]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 13, "", "v_branch/mem_simple_dual_port__pi12", "if", "88-89");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4865]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 14, "", "v_branch/mem_simple_dual_port__pi12", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4866]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 87, 9, "", "v_line/mem_simple_dual_port__pi12", "block", "87");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4867]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port.sv", 92, 13, "", "v_line/mem_simple_dual_port__pi12", "block", "92");
}
