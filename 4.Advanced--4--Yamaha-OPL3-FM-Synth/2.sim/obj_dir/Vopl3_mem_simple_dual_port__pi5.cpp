// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port__pi5.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[5160]);
    if (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[5158]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[5159]);
    }
    ++(vlSymsp->__Vcoverage[5155]);
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[5153]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[5154]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__genblk1__DOT__dob_p1 = this->__PVT__dob_p0;
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array))) {
        this->__Vlvbound2 = (0x1fffU & vlTOPp->opl3__DOT__channels__DOT__operator_out);
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                >> 0xdU)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                                   >> 0xdU));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4891]);
        this->__Vtogcov__dob = ((0x1ffeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((2U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4892]);
        this->__Vtogcov__dob = ((0x1ffdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((4U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4893]);
        this->__Vtogcov__dob = ((0x1ffbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((8U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4894]);
        this->__Vtogcov__dob = ((0x1ff7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x10U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4895]);
        this->__Vtogcov__dob = ((0x1fefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x20U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4896]);
        this->__Vtogcov__dob = ((0x1fdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x40U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4897]);
        this->__Vtogcov__dob = ((0x1fbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x80U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4898]);
        this->__Vtogcov__dob = ((0x1f7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x100U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4899]);
        this->__Vtogcov__dob = ((0x1effU & (IData)(this->__Vtogcov__dob)) 
                                | (0x100U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x200U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4900]);
        this->__Vtogcov__dob = ((0x1dffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x200U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x400U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4901]);
        this->__Vtogcov__dob = ((0x1bffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x400U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x800U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4902]);
        this->__Vtogcov__dob = ((0x17ffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x800U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x1000U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4903]);
        this->__Vtogcov__dob = ((0xfffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x1000U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4917]);
        this->__Vtogcov__ram[0U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4918]);
        this->__Vtogcov__ram[0U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4919]);
        this->__Vtogcov__ram[0U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4920]);
        this->__Vtogcov__ram[0U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4921]);
        this->__Vtogcov__ram[0U] = ((0x1fefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4922]);
        this->__Vtogcov__ram[0U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4923]);
        this->__Vtogcov__ram[0U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4924]);
        this->__Vtogcov__ram[0U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x100U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4925]);
        this->__Vtogcov__ram[0U] = ((0x1effU & this->__Vtogcov__ram
                                     [0U]) | (0x100U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x200U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4926]);
        this->__Vtogcov__ram[0U] = ((0x1dffU & this->__Vtogcov__ram
                                     [0U]) | (0x200U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x400U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4927]);
        this->__Vtogcov__ram[0U] = ((0x1bffU & this->__Vtogcov__ram
                                     [0U]) | (0x400U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x800U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4928]);
        this->__Vtogcov__ram[0U] = ((0x17ffU & this->__Vtogcov__ram
                                     [0U]) | (0x800U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x1000U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[4929]);
        this->__Vtogcov__ram[0U] = ((0xfffU & this->__Vtogcov__ram
                                     [0U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4930]);
        this->__Vtogcov__ram[1U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4931]);
        this->__Vtogcov__ram[1U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4932]);
        this->__Vtogcov__ram[1U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4933]);
        this->__Vtogcov__ram[1U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4934]);
        this->__Vtogcov__ram[1U] = ((0x1fefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4935]);
        this->__Vtogcov__ram[1U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4936]);
        this->__Vtogcov__ram[1U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4937]);
        this->__Vtogcov__ram[1U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x100U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4938]);
        this->__Vtogcov__ram[1U] = ((0x1effU & this->__Vtogcov__ram
                                     [1U]) | (0x100U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x200U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4939]);
        this->__Vtogcov__ram[1U] = ((0x1dffU & this->__Vtogcov__ram
                                     [1U]) | (0x200U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x400U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4940]);
        this->__Vtogcov__ram[1U] = ((0x1bffU & this->__Vtogcov__ram
                                     [1U]) | (0x400U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x800U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4941]);
        this->__Vtogcov__ram[1U] = ((0x17ffU & this->__Vtogcov__ram
                                     [1U]) | (0x800U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x1000U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[4942]);
        this->__Vtogcov__ram[1U] = ((0xfffU & this->__Vtogcov__ram
                                     [1U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4943]);
        this->__Vtogcov__ram[2U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4944]);
        this->__Vtogcov__ram[2U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4945]);
        this->__Vtogcov__ram[2U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4946]);
        this->__Vtogcov__ram[2U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4947]);
        this->__Vtogcov__ram[2U] = ((0x1fefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4948]);
        this->__Vtogcov__ram[2U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4949]);
        this->__Vtogcov__ram[2U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4950]);
        this->__Vtogcov__ram[2U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x100U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4951]);
        this->__Vtogcov__ram[2U] = ((0x1effU & this->__Vtogcov__ram
                                     [2U]) | (0x100U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x200U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4952]);
        this->__Vtogcov__ram[2U] = ((0x1dffU & this->__Vtogcov__ram
                                     [2U]) | (0x200U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x400U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4953]);
        this->__Vtogcov__ram[2U] = ((0x1bffU & this->__Vtogcov__ram
                                     [2U]) | (0x400U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x800U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4954]);
        this->__Vtogcov__ram[2U] = ((0x17ffU & this->__Vtogcov__ram
                                     [2U]) | (0x800U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x1000U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                    [2U]))) {
        ++(vlSymsp->__Vcoverage[4955]);
        this->__Vtogcov__ram[2U] = ((0xfffU & this->__Vtogcov__ram
                                     [2U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4956]);
        this->__Vtogcov__ram[3U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4957]);
        this->__Vtogcov__ram[3U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4958]);
        this->__Vtogcov__ram[3U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4959]);
        this->__Vtogcov__ram[3U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4960]);
        this->__Vtogcov__ram[3U] = ((0x1fefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4961]);
        this->__Vtogcov__ram[3U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4962]);
        this->__Vtogcov__ram[3U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4963]);
        this->__Vtogcov__ram[3U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x100U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4964]);
        this->__Vtogcov__ram[3U] = ((0x1effU & this->__Vtogcov__ram
                                     [3U]) | (0x100U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x200U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4965]);
        this->__Vtogcov__ram[3U] = ((0x1dffU & this->__Vtogcov__ram
                                     [3U]) | (0x200U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x400U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4966]);
        this->__Vtogcov__ram[3U] = ((0x1bffU & this->__Vtogcov__ram
                                     [3U]) | (0x400U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x800U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4967]);
        this->__Vtogcov__ram[3U] = ((0x17ffU & this->__Vtogcov__ram
                                     [3U]) | (0x800U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x1000U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                    [3U]))) {
        ++(vlSymsp->__Vcoverage[4968]);
        this->__Vtogcov__ram[3U] = ((0xfffU & this->__Vtogcov__ram
                                     [3U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4969]);
        this->__Vtogcov__ram[4U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4970]);
        this->__Vtogcov__ram[4U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4971]);
        this->__Vtogcov__ram[4U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4972]);
        this->__Vtogcov__ram[4U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4973]);
        this->__Vtogcov__ram[4U] = ((0x1fefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4974]);
        this->__Vtogcov__ram[4U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4975]);
        this->__Vtogcov__ram[4U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4976]);
        this->__Vtogcov__ram[4U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x100U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4977]);
        this->__Vtogcov__ram[4U] = ((0x1effU & this->__Vtogcov__ram
                                     [4U]) | (0x100U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x200U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4978]);
        this->__Vtogcov__ram[4U] = ((0x1dffU & this->__Vtogcov__ram
                                     [4U]) | (0x200U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x400U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4979]);
        this->__Vtogcov__ram[4U] = ((0x1bffU & this->__Vtogcov__ram
                                     [4U]) | (0x400U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x800U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4980]);
        this->__Vtogcov__ram[4U] = ((0x17ffU & this->__Vtogcov__ram
                                     [4U]) | (0x800U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x1000U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                    [4U]))) {
        ++(vlSymsp->__Vcoverage[4981]);
        this->__Vtogcov__ram[4U] = ((0xfffU & this->__Vtogcov__ram
                                     [4U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4982]);
        this->__Vtogcov__ram[5U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4983]);
        this->__Vtogcov__ram[5U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4984]);
        this->__Vtogcov__ram[5U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4985]);
        this->__Vtogcov__ram[5U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4986]);
        this->__Vtogcov__ram[5U] = ((0x1fefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4987]);
        this->__Vtogcov__ram[5U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4988]);
        this->__Vtogcov__ram[5U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4989]);
        this->__Vtogcov__ram[5U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x100U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4990]);
        this->__Vtogcov__ram[5U] = ((0x1effU & this->__Vtogcov__ram
                                     [5U]) | (0x100U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x200U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4991]);
        this->__Vtogcov__ram[5U] = ((0x1dffU & this->__Vtogcov__ram
                                     [5U]) | (0x200U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x400U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4992]);
        this->__Vtogcov__ram[5U] = ((0x1bffU & this->__Vtogcov__ram
                                     [5U]) | (0x400U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x800U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4993]);
        this->__Vtogcov__ram[5U] = ((0x17ffU & this->__Vtogcov__ram
                                     [5U]) | (0x800U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x1000U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                    [5U]))) {
        ++(vlSymsp->__Vcoverage[4994]);
        this->__Vtogcov__ram[5U] = ((0xfffU & this->__Vtogcov__ram
                                     [5U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4995]);
        this->__Vtogcov__ram[6U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4996]);
        this->__Vtogcov__ram[6U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4997]);
        this->__Vtogcov__ram[6U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4998]);
        this->__Vtogcov__ram[6U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4999]);
        this->__Vtogcov__ram[6U] = ((0x1fefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[5000]);
        this->__Vtogcov__ram[6U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[5001]);
        this->__Vtogcov__ram[6U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[5002]);
        this->__Vtogcov__ram[6U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x100U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5003]);
        this->__Vtogcov__ram[6U] = ((0x1effU & this->__Vtogcov__ram
                                     [6U]) | (0x100U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x200U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5004]);
        this->__Vtogcov__ram[6U] = ((0x1dffU & this->__Vtogcov__ram
                                     [6U]) | (0x200U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x400U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5005]);
        this->__Vtogcov__ram[6U] = ((0x1bffU & this->__Vtogcov__ram
                                     [6U]) | (0x400U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x800U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5006]);
        this->__Vtogcov__ram[6U] = ((0x17ffU & this->__Vtogcov__ram
                                     [6U]) | (0x800U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x1000U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                    [6U]))) {
        ++(vlSymsp->__Vcoverage[5007]);
        this->__Vtogcov__ram[6U] = ((0xfffU & this->__Vtogcov__ram
                                     [6U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5008]);
        this->__Vtogcov__ram[7U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5009]);
        this->__Vtogcov__ram[7U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5010]);
        this->__Vtogcov__ram[7U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5011]);
        this->__Vtogcov__ram[7U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5012]);
        this->__Vtogcov__ram[7U] = ((0x1fefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5013]);
        this->__Vtogcov__ram[7U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5014]);
        this->__Vtogcov__ram[7U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5015]);
        this->__Vtogcov__ram[7U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x100U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5016]);
        this->__Vtogcov__ram[7U] = ((0x1effU & this->__Vtogcov__ram
                                     [7U]) | (0x100U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x200U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5017]);
        this->__Vtogcov__ram[7U] = ((0x1dffU & this->__Vtogcov__ram
                                     [7U]) | (0x200U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x400U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5018]);
        this->__Vtogcov__ram[7U] = ((0x1bffU & this->__Vtogcov__ram
                                     [7U]) | (0x400U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x800U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5019]);
        this->__Vtogcov__ram[7U] = ((0x17ffU & this->__Vtogcov__ram
                                     [7U]) | (0x800U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x1000U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                    [7U]))) {
        ++(vlSymsp->__Vcoverage[5020]);
        this->__Vtogcov__ram[7U] = ((0xfffU & this->__Vtogcov__ram
                                     [7U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5021]);
        this->__Vtogcov__ram[8U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5022]);
        this->__Vtogcov__ram[8U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5023]);
        this->__Vtogcov__ram[8U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5024]);
        this->__Vtogcov__ram[8U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5025]);
        this->__Vtogcov__ram[8U] = ((0x1fefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5026]);
        this->__Vtogcov__ram[8U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5027]);
        this->__Vtogcov__ram[8U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5028]);
        this->__Vtogcov__ram[8U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x100U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5029]);
        this->__Vtogcov__ram[8U] = ((0x1effU & this->__Vtogcov__ram
                                     [8U]) | (0x100U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x200U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5030]);
        this->__Vtogcov__ram[8U] = ((0x1dffU & this->__Vtogcov__ram
                                     [8U]) | (0x200U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x400U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5031]);
        this->__Vtogcov__ram[8U] = ((0x1bffU & this->__Vtogcov__ram
                                     [8U]) | (0x400U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x800U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5032]);
        this->__Vtogcov__ram[8U] = ((0x17ffU & this->__Vtogcov__ram
                                     [8U]) | (0x800U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x1000U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                    [8U]))) {
        ++(vlSymsp->__Vcoverage[5033]);
        this->__Vtogcov__ram[8U] = ((0xfffU & this->__Vtogcov__ram
                                     [8U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5034]);
        this->__Vtogcov__ram[9U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5035]);
        this->__Vtogcov__ram[9U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5036]);
        this->__Vtogcov__ram[9U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5037]);
        this->__Vtogcov__ram[9U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5038]);
        this->__Vtogcov__ram[9U] = ((0x1fefU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5039]);
        this->__Vtogcov__ram[9U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5040]);
        this->__Vtogcov__ram[9U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5041]);
        this->__Vtogcov__ram[9U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x100U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5042]);
        this->__Vtogcov__ram[9U] = ((0x1effU & this->__Vtogcov__ram
                                     [9U]) | (0x100U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x200U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5043]);
        this->__Vtogcov__ram[9U] = ((0x1dffU & this->__Vtogcov__ram
                                     [9U]) | (0x200U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x400U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5044]);
        this->__Vtogcov__ram[9U] = ((0x1bffU & this->__Vtogcov__ram
                                     [9U]) | (0x400U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x800U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5045]);
        this->__Vtogcov__ram[9U] = ((0x17ffU & this->__Vtogcov__ram
                                     [9U]) | (0x800U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x1000U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                    [9U]))) {
        ++(vlSymsp->__Vcoverage[5046]);
        this->__Vtogcov__ram[9U] = ((0xfffU & this->__Vtogcov__ram
                                     [9U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5047]);
        this->__Vtogcov__ram[0xaU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5048]);
        this->__Vtogcov__ram[0xaU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5049]);
        this->__Vtogcov__ram[0xaU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5050]);
        this->__Vtogcov__ram[0xaU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5051]);
        this->__Vtogcov__ram[0xaU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5052]);
        this->__Vtogcov__ram[0xaU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5053]);
        this->__Vtogcov__ram[0xaU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5054]);
        this->__Vtogcov__ram[0xaU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x100U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5055]);
        this->__Vtogcov__ram[0xaU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xaU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x200U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5056]);
        this->__Vtogcov__ram[0xaU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x400U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5057]);
        this->__Vtogcov__ram[0xaU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x800U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5058]);
        this->__Vtogcov__ram[0xaU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                    [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5059]);
        this->__Vtogcov__ram[0xaU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5060]);
        this->__Vtogcov__ram[0xbU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5061]);
        this->__Vtogcov__ram[0xbU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5062]);
        this->__Vtogcov__ram[0xbU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5063]);
        this->__Vtogcov__ram[0xbU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5064]);
        this->__Vtogcov__ram[0xbU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5065]);
        this->__Vtogcov__ram[0xbU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5066]);
        this->__Vtogcov__ram[0xbU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5067]);
        this->__Vtogcov__ram[0xbU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x100U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5068]);
        this->__Vtogcov__ram[0xbU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xbU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x200U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5069]);
        this->__Vtogcov__ram[0xbU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x400U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5070]);
        this->__Vtogcov__ram[0xbU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x800U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5071]);
        this->__Vtogcov__ram[0xbU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                    [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5072]);
        this->__Vtogcov__ram[0xbU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5073]);
        this->__Vtogcov__ram[0xcU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5074]);
        this->__Vtogcov__ram[0xcU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5075]);
        this->__Vtogcov__ram[0xcU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5076]);
        this->__Vtogcov__ram[0xcU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5077]);
        this->__Vtogcov__ram[0xcU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5078]);
        this->__Vtogcov__ram[0xcU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5079]);
        this->__Vtogcov__ram[0xcU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5080]);
        this->__Vtogcov__ram[0xcU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x100U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5081]);
        this->__Vtogcov__ram[0xcU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xcU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x200U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5082]);
        this->__Vtogcov__ram[0xcU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x400U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5083]);
        this->__Vtogcov__ram[0xcU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x800U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5084]);
        this->__Vtogcov__ram[0xcU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                    [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5085]);
        this->__Vtogcov__ram[0xcU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5086]);
        this->__Vtogcov__ram[0xdU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5087]);
        this->__Vtogcov__ram[0xdU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5088]);
        this->__Vtogcov__ram[0xdU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5089]);
        this->__Vtogcov__ram[0xdU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5090]);
        this->__Vtogcov__ram[0xdU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5091]);
        this->__Vtogcov__ram[0xdU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5092]);
        this->__Vtogcov__ram[0xdU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5093]);
        this->__Vtogcov__ram[0xdU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x100U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5094]);
        this->__Vtogcov__ram[0xdU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xdU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x200U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5095]);
        this->__Vtogcov__ram[0xdU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x400U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5096]);
        this->__Vtogcov__ram[0xdU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x800U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5097]);
        this->__Vtogcov__ram[0xdU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                    [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5098]);
        this->__Vtogcov__ram[0xdU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5099]);
        this->__Vtogcov__ram[0xeU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5100]);
        this->__Vtogcov__ram[0xeU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5101]);
        this->__Vtogcov__ram[0xeU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5102]);
        this->__Vtogcov__ram[0xeU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5103]);
        this->__Vtogcov__ram[0xeU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5104]);
        this->__Vtogcov__ram[0xeU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5105]);
        this->__Vtogcov__ram[0xeU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5106]);
        this->__Vtogcov__ram[0xeU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x100U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5107]);
        this->__Vtogcov__ram[0xeU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xeU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x200U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5108]);
        this->__Vtogcov__ram[0xeU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x400U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5109]);
        this->__Vtogcov__ram[0xeU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x800U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5110]);
        this->__Vtogcov__ram[0xeU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                    [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5111]);
        this->__Vtogcov__ram[0xeU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5112]);
        this->__Vtogcov__ram[0xfU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5113]);
        this->__Vtogcov__ram[0xfU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5114]);
        this->__Vtogcov__ram[0xfU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5115]);
        this->__Vtogcov__ram[0xfU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5116]);
        this->__Vtogcov__ram[0xfU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5117]);
        this->__Vtogcov__ram[0xfU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5118]);
        this->__Vtogcov__ram[0xfU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5119]);
        this->__Vtogcov__ram[0xfU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x100U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5120]);
        this->__Vtogcov__ram[0xfU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xfU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x200U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5121]);
        this->__Vtogcov__ram[0xfU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x400U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5122]);
        this->__Vtogcov__ram[0xfU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x800U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5123]);
        this->__Vtogcov__ram[0xfU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                    [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5124]);
        this->__Vtogcov__ram[0xfU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5125]);
        this->__Vtogcov__ram[0x10U] = ((0x1ffeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5126]);
        this->__Vtogcov__ram[0x10U] = ((0x1ffdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5127]);
        this->__Vtogcov__ram[0x10U] = ((0x1ffbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5128]);
        this->__Vtogcov__ram[0x10U] = ((0x1ff7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5129]);
        this->__Vtogcov__ram[0x10U] = ((0x1fefU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5130]);
        this->__Vtogcov__ram[0x10U] = ((0x1fdfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5131]);
        this->__Vtogcov__ram[0x10U] = ((0x1fbfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5132]);
        this->__Vtogcov__ram[0x10U] = ((0x1f7fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x100U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5133]);
        this->__Vtogcov__ram[0x10U] = ((0x1effU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x200U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5134]);
        this->__Vtogcov__ram[0x10U] = ((0x1dffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x200U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x400U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5135]);
        this->__Vtogcov__ram[0x10U] = ((0x1bffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x400U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x800U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5136]);
        this->__Vtogcov__ram[0x10U] = ((0x17ffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x800U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x1000U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                    [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5137]);
        this->__Vtogcov__ram[0x10U] = ((0xfffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x1000U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5138]);
        this->__Vtogcov__ram[0x11U] = ((0x1ffeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5139]);
        this->__Vtogcov__ram[0x11U] = ((0x1ffdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5140]);
        this->__Vtogcov__ram[0x11U] = ((0x1ffbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5141]);
        this->__Vtogcov__ram[0x11U] = ((0x1ff7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5142]);
        this->__Vtogcov__ram[0x11U] = ((0x1fefU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5143]);
        this->__Vtogcov__ram[0x11U] = ((0x1fdfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5144]);
        this->__Vtogcov__ram[0x11U] = ((0x1fbfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5145]);
        this->__Vtogcov__ram[0x11U] = ((0x1f7fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x100U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5146]);
        this->__Vtogcov__ram[0x11U] = ((0x1effU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x200U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5147]);
        this->__Vtogcov__ram[0x11U] = ((0x1dffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x200U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x400U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5148]);
        this->__Vtogcov__ram[0x11U] = ((0x1bffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x400U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x800U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5149]);
        this->__Vtogcov__ram[0x11U] = ((0x17ffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x800U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x1000U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                    [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5150]);
        this->__Vtogcov__ram[0x11U] = ((0xfffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x1000U & this->__PVT__ram
                                        [0x11U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4889]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi5::_combo__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__11(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_combo__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__11\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob_p0 = ((0x11U >= (0x1fU & (IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 0x27U))))
                            ? this->__PVT__ram[(0x1fU 
                                                & (IData)(
                                                          (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                           >> 0x27U)))]
                            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->__Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4890]);
        this->__Vtogcov__reb = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4904]);
        this->__Vtogcov__dob_p0 = ((0x1ffeU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (1U & (IData)(this->__PVT__dob_p0)));
    }
    if ((2U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4905]);
        this->__Vtogcov__dob_p0 = ((0x1ffdU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (2U & (IData)(this->__PVT__dob_p0)));
    }
    if ((4U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4906]);
        this->__Vtogcov__dob_p0 = ((0x1ffbU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (4U & (IData)(this->__PVT__dob_p0)));
    }
    if ((8U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4907]);
        this->__Vtogcov__dob_p0 = ((0x1ff7U & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (8U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x10U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4908]);
        this->__Vtogcov__dob_p0 = ((0x1fefU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x10U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x20U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4909]);
        this->__Vtogcov__dob_p0 = ((0x1fdfU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x20U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x40U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4910]);
        this->__Vtogcov__dob_p0 = ((0x1fbfU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x40U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x80U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4911]);
        this->__Vtogcov__dob_p0 = ((0x1f7fU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x80U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x100U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4912]);
        this->__Vtogcov__dob_p0 = ((0x1effU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x100U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x200U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4913]);
        this->__Vtogcov__dob_p0 = ((0x1dffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x200U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x400U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4914]);
        this->__Vtogcov__dob_p0 = ((0x1bffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x400U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x800U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4915]);
        this->__Vtogcov__dob_p0 = ((0x17ffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x800U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x1000U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4916]);
        this->__Vtogcov__dob_p0 = ((0xfffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x1000U & (IData)(this->__PVT__dob_p0)));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[5160]);
    if (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[5158]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[5159]);
    }
    ++(vlSymsp->__Vcoverage[5155]);
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array))) {
        ++(vlSymsp->__Vcoverage[5153]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[5154]);
    }
    this->__Vdlyvset__ram__v0 = 0U;
    if (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__genblk1__DOT__dob_p1 = this->__PVT__dob_p0;
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array))) {
        this->__Vlvbound2 = (0x1fffU & vlTOPp->opl3__DOT__channels__DOT__operator_out);
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                >> 0xdU)))) {
            this->__Vdlyvval__ram__v0 = this->__Vlvbound2;
            this->__Vdlyvset__ram__v0 = 1U;
            this->__Vdlyvdim0__ram__v0 = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                                   >> 0xdU));
        }
    }
    if (this->__Vdlyvset__ram__v0) {
        this->__PVT__ram[this->__Vdlyvdim0__ram__v0] 
            = this->__Vdlyvval__ram__v0;
    }
    if ((1U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4891]);
        this->__Vtogcov__dob = ((0x1ffeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((2U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4892]);
        this->__Vtogcov__dob = ((0x1ffdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((4U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4893]);
        this->__Vtogcov__dob = ((0x1ffbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((8U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
               ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4894]);
        this->__Vtogcov__dob = ((0x1ff7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x10U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4895]);
        this->__Vtogcov__dob = ((0x1fefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x20U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4896]);
        this->__Vtogcov__dob = ((0x1fdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x40U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4897]);
        this->__Vtogcov__dob = ((0x1fbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x80U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                  ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4898]);
        this->__Vtogcov__dob = ((0x1f7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x100U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4899]);
        this->__Vtogcov__dob = ((0x1effU & (IData)(this->__Vtogcov__dob)) 
                                | (0x100U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x200U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4900]);
        this->__Vtogcov__dob = ((0x1dffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x200U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x400U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4901]);
        this->__Vtogcov__dob = ((0x1bffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x400U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x800U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                   ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4902]);
        this->__Vtogcov__dob = ((0x17ffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x800U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((0x1000U & ((IData)(this->__PVT__genblk1__DOT__dob_p1) 
                    ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4903]);
        this->__Vtogcov__dob = ((0xfffU & (IData)(this->__Vtogcov__dob)) 
                                | (0x1000U & (IData)(this->__PVT__genblk1__DOT__dob_p1)));
    }
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4917]);
        this->__Vtogcov__ram[0U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4918]);
        this->__Vtogcov__ram[0U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4919]);
        this->__Vtogcov__ram[0U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4920]);
        this->__Vtogcov__ram[0U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4921]);
        this->__Vtogcov__ram[0U] = ((0x1fefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4922]);
        this->__Vtogcov__ram[0U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4923]);
        this->__Vtogcov__ram[0U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4924]);
        this->__Vtogcov__ram[0U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x100U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4925]);
        this->__Vtogcov__ram[0U] = ((0x1effU & this->__Vtogcov__ram
                                     [0U]) | (0x100U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x200U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4926]);
        this->__Vtogcov__ram[0U] = ((0x1dffU & this->__Vtogcov__ram
                                     [0U]) | (0x200U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x400U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4927]);
        this->__Vtogcov__ram[0U] = ((0x1bffU & this->__Vtogcov__ram
                                     [0U]) | (0x400U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x800U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[4928]);
        this->__Vtogcov__ram[0U] = ((0x17ffU & this->__Vtogcov__ram
                                     [0U]) | (0x800U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x1000U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[4929]);
        this->__Vtogcov__ram[0U] = ((0xfffU & this->__Vtogcov__ram
                                     [0U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4930]);
        this->__Vtogcov__ram[1U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4931]);
        this->__Vtogcov__ram[1U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4932]);
        this->__Vtogcov__ram[1U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4933]);
        this->__Vtogcov__ram[1U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4934]);
        this->__Vtogcov__ram[1U] = ((0x1fefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4935]);
        this->__Vtogcov__ram[1U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4936]);
        this->__Vtogcov__ram[1U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4937]);
        this->__Vtogcov__ram[1U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x100U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4938]);
        this->__Vtogcov__ram[1U] = ((0x1effU & this->__Vtogcov__ram
                                     [1U]) | (0x100U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x200U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4939]);
        this->__Vtogcov__ram[1U] = ((0x1dffU & this->__Vtogcov__ram
                                     [1U]) | (0x200U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x400U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4940]);
        this->__Vtogcov__ram[1U] = ((0x1bffU & this->__Vtogcov__ram
                                     [1U]) | (0x400U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x800U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[4941]);
        this->__Vtogcov__ram[1U] = ((0x17ffU & this->__Vtogcov__ram
                                     [1U]) | (0x800U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x1000U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[4942]);
        this->__Vtogcov__ram[1U] = ((0xfffU & this->__Vtogcov__ram
                                     [1U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4943]);
        this->__Vtogcov__ram[2U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4944]);
        this->__Vtogcov__ram[2U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4945]);
        this->__Vtogcov__ram[2U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4946]);
        this->__Vtogcov__ram[2U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4947]);
        this->__Vtogcov__ram[2U] = ((0x1fefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4948]);
        this->__Vtogcov__ram[2U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4949]);
        this->__Vtogcov__ram[2U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4950]);
        this->__Vtogcov__ram[2U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x100U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4951]);
        this->__Vtogcov__ram[2U] = ((0x1effU & this->__Vtogcov__ram
                                     [2U]) | (0x100U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x200U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4952]);
        this->__Vtogcov__ram[2U] = ((0x1dffU & this->__Vtogcov__ram
                                     [2U]) | (0x200U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x400U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4953]);
        this->__Vtogcov__ram[2U] = ((0x1bffU & this->__Vtogcov__ram
                                     [2U]) | (0x400U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x800U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                   [2U]))) {
        ++(vlSymsp->__Vcoverage[4954]);
        this->__Vtogcov__ram[2U] = ((0x17ffU & this->__Vtogcov__ram
                                     [2U]) | (0x800U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x1000U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                    [2U]))) {
        ++(vlSymsp->__Vcoverage[4955]);
        this->__Vtogcov__ram[2U] = ((0xfffU & this->__Vtogcov__ram
                                     [2U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4956]);
        this->__Vtogcov__ram[3U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4957]);
        this->__Vtogcov__ram[3U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4958]);
        this->__Vtogcov__ram[3U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4959]);
        this->__Vtogcov__ram[3U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4960]);
        this->__Vtogcov__ram[3U] = ((0x1fefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4961]);
        this->__Vtogcov__ram[3U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4962]);
        this->__Vtogcov__ram[3U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4963]);
        this->__Vtogcov__ram[3U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x100U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4964]);
        this->__Vtogcov__ram[3U] = ((0x1effU & this->__Vtogcov__ram
                                     [3U]) | (0x100U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x200U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4965]);
        this->__Vtogcov__ram[3U] = ((0x1dffU & this->__Vtogcov__ram
                                     [3U]) | (0x200U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x400U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4966]);
        this->__Vtogcov__ram[3U] = ((0x1bffU & this->__Vtogcov__ram
                                     [3U]) | (0x400U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x800U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                   [3U]))) {
        ++(vlSymsp->__Vcoverage[4967]);
        this->__Vtogcov__ram[3U] = ((0x17ffU & this->__Vtogcov__ram
                                     [3U]) | (0x800U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x1000U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                    [3U]))) {
        ++(vlSymsp->__Vcoverage[4968]);
        this->__Vtogcov__ram[3U] = ((0xfffU & this->__Vtogcov__ram
                                     [3U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4969]);
        this->__Vtogcov__ram[4U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4970]);
        this->__Vtogcov__ram[4U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4971]);
        this->__Vtogcov__ram[4U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4972]);
        this->__Vtogcov__ram[4U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4973]);
        this->__Vtogcov__ram[4U] = ((0x1fefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4974]);
        this->__Vtogcov__ram[4U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4975]);
        this->__Vtogcov__ram[4U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4976]);
        this->__Vtogcov__ram[4U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x100U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4977]);
        this->__Vtogcov__ram[4U] = ((0x1effU & this->__Vtogcov__ram
                                     [4U]) | (0x100U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x200U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4978]);
        this->__Vtogcov__ram[4U] = ((0x1dffU & this->__Vtogcov__ram
                                     [4U]) | (0x200U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x400U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4979]);
        this->__Vtogcov__ram[4U] = ((0x1bffU & this->__Vtogcov__ram
                                     [4U]) | (0x400U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x800U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                   [4U]))) {
        ++(vlSymsp->__Vcoverage[4980]);
        this->__Vtogcov__ram[4U] = ((0x17ffU & this->__Vtogcov__ram
                                     [4U]) | (0x800U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x1000U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                    [4U]))) {
        ++(vlSymsp->__Vcoverage[4981]);
        this->__Vtogcov__ram[4U] = ((0xfffU & this->__Vtogcov__ram
                                     [4U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4982]);
        this->__Vtogcov__ram[5U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4983]);
        this->__Vtogcov__ram[5U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4984]);
        this->__Vtogcov__ram[5U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4985]);
        this->__Vtogcov__ram[5U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4986]);
        this->__Vtogcov__ram[5U] = ((0x1fefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4987]);
        this->__Vtogcov__ram[5U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4988]);
        this->__Vtogcov__ram[5U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4989]);
        this->__Vtogcov__ram[5U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x100U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4990]);
        this->__Vtogcov__ram[5U] = ((0x1effU & this->__Vtogcov__ram
                                     [5U]) | (0x100U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x200U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4991]);
        this->__Vtogcov__ram[5U] = ((0x1dffU & this->__Vtogcov__ram
                                     [5U]) | (0x200U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x400U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4992]);
        this->__Vtogcov__ram[5U] = ((0x1bffU & this->__Vtogcov__ram
                                     [5U]) | (0x400U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x800U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                   [5U]))) {
        ++(vlSymsp->__Vcoverage[4993]);
        this->__Vtogcov__ram[5U] = ((0x17ffU & this->__Vtogcov__ram
                                     [5U]) | (0x800U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x1000U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                    [5U]))) {
        ++(vlSymsp->__Vcoverage[4994]);
        this->__Vtogcov__ram[5U] = ((0xfffU & this->__Vtogcov__ram
                                     [5U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4995]);
        this->__Vtogcov__ram[6U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4996]);
        this->__Vtogcov__ram[6U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4997]);
        this->__Vtogcov__ram[6U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4998]);
        this->__Vtogcov__ram[6U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4999]);
        this->__Vtogcov__ram[6U] = ((0x1fefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[5000]);
        this->__Vtogcov__ram[6U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[5001]);
        this->__Vtogcov__ram[6U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[5002]);
        this->__Vtogcov__ram[6U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x100U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5003]);
        this->__Vtogcov__ram[6U] = ((0x1effU & this->__Vtogcov__ram
                                     [6U]) | (0x100U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x200U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5004]);
        this->__Vtogcov__ram[6U] = ((0x1dffU & this->__Vtogcov__ram
                                     [6U]) | (0x200U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x400U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5005]);
        this->__Vtogcov__ram[6U] = ((0x1bffU & this->__Vtogcov__ram
                                     [6U]) | (0x400U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x800U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                   [6U]))) {
        ++(vlSymsp->__Vcoverage[5006]);
        this->__Vtogcov__ram[6U] = ((0x17ffU & this->__Vtogcov__ram
                                     [6U]) | (0x800U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x1000U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                    [6U]))) {
        ++(vlSymsp->__Vcoverage[5007]);
        this->__Vtogcov__ram[6U] = ((0xfffU & this->__Vtogcov__ram
                                     [6U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5008]);
        this->__Vtogcov__ram[7U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5009]);
        this->__Vtogcov__ram[7U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5010]);
        this->__Vtogcov__ram[7U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[5011]);
        this->__Vtogcov__ram[7U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5012]);
        this->__Vtogcov__ram[7U] = ((0x1fefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5013]);
        this->__Vtogcov__ram[7U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5014]);
        this->__Vtogcov__ram[7U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[5015]);
        this->__Vtogcov__ram[7U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x100U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5016]);
        this->__Vtogcov__ram[7U] = ((0x1effU & this->__Vtogcov__ram
                                     [7U]) | (0x100U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x200U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5017]);
        this->__Vtogcov__ram[7U] = ((0x1dffU & this->__Vtogcov__ram
                                     [7U]) | (0x200U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x400U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5018]);
        this->__Vtogcov__ram[7U] = ((0x1bffU & this->__Vtogcov__ram
                                     [7U]) | (0x400U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x800U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                   [7U]))) {
        ++(vlSymsp->__Vcoverage[5019]);
        this->__Vtogcov__ram[7U] = ((0x17ffU & this->__Vtogcov__ram
                                     [7U]) | (0x800U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x1000U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                    [7U]))) {
        ++(vlSymsp->__Vcoverage[5020]);
        this->__Vtogcov__ram[7U] = ((0xfffU & this->__Vtogcov__ram
                                     [7U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5021]);
        this->__Vtogcov__ram[8U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5022]);
        this->__Vtogcov__ram[8U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5023]);
        this->__Vtogcov__ram[8U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[5024]);
        this->__Vtogcov__ram[8U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5025]);
        this->__Vtogcov__ram[8U] = ((0x1fefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5026]);
        this->__Vtogcov__ram[8U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5027]);
        this->__Vtogcov__ram[8U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[5028]);
        this->__Vtogcov__ram[8U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x100U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5029]);
        this->__Vtogcov__ram[8U] = ((0x1effU & this->__Vtogcov__ram
                                     [8U]) | (0x100U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x200U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5030]);
        this->__Vtogcov__ram[8U] = ((0x1dffU & this->__Vtogcov__ram
                                     [8U]) | (0x200U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x400U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5031]);
        this->__Vtogcov__ram[8U] = ((0x1bffU & this->__Vtogcov__ram
                                     [8U]) | (0x400U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x800U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                   [8U]))) {
        ++(vlSymsp->__Vcoverage[5032]);
        this->__Vtogcov__ram[8U] = ((0x17ffU & this->__Vtogcov__ram
                                     [8U]) | (0x800U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x1000U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                    [8U]))) {
        ++(vlSymsp->__Vcoverage[5033]);
        this->__Vtogcov__ram[8U] = ((0xfffU & this->__Vtogcov__ram
                                     [8U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5034]);
        this->__Vtogcov__ram[9U] = ((0x1ffeU & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5035]);
        this->__Vtogcov__ram[9U] = ((0x1ffdU & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5036]);
        this->__Vtogcov__ram[9U] = ((0x1ffbU & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((8U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[5037]);
        this->__Vtogcov__ram[9U] = ((0x1ff7U & this->__Vtogcov__ram
                                     [9U]) | (8U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((0x10U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5038]);
        this->__Vtogcov__ram[9U] = ((0x1fefU & this->__Vtogcov__ram
                                     [9U]) | (0x10U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x20U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5039]);
        this->__Vtogcov__ram[9U] = ((0x1fdfU & this->__Vtogcov__ram
                                     [9U]) | (0x20U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x40U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5040]);
        this->__Vtogcov__ram[9U] = ((0x1fbfU & this->__Vtogcov__ram
                                     [9U]) | (0x40U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x80U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                  [9U]))) {
        ++(vlSymsp->__Vcoverage[5041]);
        this->__Vtogcov__ram[9U] = ((0x1f7fU & this->__Vtogcov__ram
                                     [9U]) | (0x80U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x100U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5042]);
        this->__Vtogcov__ram[9U] = ((0x1effU & this->__Vtogcov__ram
                                     [9U]) | (0x100U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x200U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5043]);
        this->__Vtogcov__ram[9U] = ((0x1dffU & this->__Vtogcov__ram
                                     [9U]) | (0x200U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x400U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5044]);
        this->__Vtogcov__ram[9U] = ((0x1bffU & this->__Vtogcov__ram
                                     [9U]) | (0x400U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x800U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                   [9U]))) {
        ++(vlSymsp->__Vcoverage[5045]);
        this->__Vtogcov__ram[9U] = ((0x17ffU & this->__Vtogcov__ram
                                     [9U]) | (0x800U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((0x1000U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
                    [9U]))) {
        ++(vlSymsp->__Vcoverage[5046]);
        this->__Vtogcov__ram[9U] = ((0xfffU & this->__Vtogcov__ram
                                     [9U]) | (0x1000U 
                                              & this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5047]);
        this->__Vtogcov__ram[0xaU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5048]);
        this->__Vtogcov__ram[0xaU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5049]);
        this->__Vtogcov__ram[0xaU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((8U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5050]);
        this->__Vtogcov__ram[0xaU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xaU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x10U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5051]);
        this->__Vtogcov__ram[0xaU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xaU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x20U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5052]);
        this->__Vtogcov__ram[0xaU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x40U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5053]);
        this->__Vtogcov__ram[0xaU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xaU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x80U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                  [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5054]);
        this->__Vtogcov__ram[0xaU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xaU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x100U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5055]);
        this->__Vtogcov__ram[0xaU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xaU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x200U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5056]);
        this->__Vtogcov__ram[0xaU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x400U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5057]);
        this->__Vtogcov__ram[0xaU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x800U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                   [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5058]);
        this->__Vtogcov__ram[0xaU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
                    [0xaU]))) {
        ++(vlSymsp->__Vcoverage[5059]);
        this->__Vtogcov__ram[0xaU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xaU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5060]);
        this->__Vtogcov__ram[0xbU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5061]);
        this->__Vtogcov__ram[0xbU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5062]);
        this->__Vtogcov__ram[0xbU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((8U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5063]);
        this->__Vtogcov__ram[0xbU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xbU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x10U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5064]);
        this->__Vtogcov__ram[0xbU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xbU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x20U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5065]);
        this->__Vtogcov__ram[0xbU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x40U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5066]);
        this->__Vtogcov__ram[0xbU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xbU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x80U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                  [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5067]);
        this->__Vtogcov__ram[0xbU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xbU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x100U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5068]);
        this->__Vtogcov__ram[0xbU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xbU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x200U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5069]);
        this->__Vtogcov__ram[0xbU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x400U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5070]);
        this->__Vtogcov__ram[0xbU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x800U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                   [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5071]);
        this->__Vtogcov__ram[0xbU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
                    [0xbU]))) {
        ++(vlSymsp->__Vcoverage[5072]);
        this->__Vtogcov__ram[0xbU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xbU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5073]);
        this->__Vtogcov__ram[0xcU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5074]);
        this->__Vtogcov__ram[0xcU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5075]);
        this->__Vtogcov__ram[0xcU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((8U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5076]);
        this->__Vtogcov__ram[0xcU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xcU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x10U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5077]);
        this->__Vtogcov__ram[0xcU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xcU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x20U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5078]);
        this->__Vtogcov__ram[0xcU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x40U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5079]);
        this->__Vtogcov__ram[0xcU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xcU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x80U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                  [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5080]);
        this->__Vtogcov__ram[0xcU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xcU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x100U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5081]);
        this->__Vtogcov__ram[0xcU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xcU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x200U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5082]);
        this->__Vtogcov__ram[0xcU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x400U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5083]);
        this->__Vtogcov__ram[0xcU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x800U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                   [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5084]);
        this->__Vtogcov__ram[0xcU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
                    [0xcU]))) {
        ++(vlSymsp->__Vcoverage[5085]);
        this->__Vtogcov__ram[0xcU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xcU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5086]);
        this->__Vtogcov__ram[0xdU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5087]);
        this->__Vtogcov__ram[0xdU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5088]);
        this->__Vtogcov__ram[0xdU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((8U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5089]);
        this->__Vtogcov__ram[0xdU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xdU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x10U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5090]);
        this->__Vtogcov__ram[0xdU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xdU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x20U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5091]);
        this->__Vtogcov__ram[0xdU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x40U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5092]);
        this->__Vtogcov__ram[0xdU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xdU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x80U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                  [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5093]);
        this->__Vtogcov__ram[0xdU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xdU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x100U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5094]);
        this->__Vtogcov__ram[0xdU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xdU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x200U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5095]);
        this->__Vtogcov__ram[0xdU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x400U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5096]);
        this->__Vtogcov__ram[0xdU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x800U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                   [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5097]);
        this->__Vtogcov__ram[0xdU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
                    [0xdU]))) {
        ++(vlSymsp->__Vcoverage[5098]);
        this->__Vtogcov__ram[0xdU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xdU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5099]);
        this->__Vtogcov__ram[0xeU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5100]);
        this->__Vtogcov__ram[0xeU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5101]);
        this->__Vtogcov__ram[0xeU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((8U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5102]);
        this->__Vtogcov__ram[0xeU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xeU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x10U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5103]);
        this->__Vtogcov__ram[0xeU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xeU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x20U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5104]);
        this->__Vtogcov__ram[0xeU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x40U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5105]);
        this->__Vtogcov__ram[0xeU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xeU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x80U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                  [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5106]);
        this->__Vtogcov__ram[0xeU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xeU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x100U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5107]);
        this->__Vtogcov__ram[0xeU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xeU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x200U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5108]);
        this->__Vtogcov__ram[0xeU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x400U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5109]);
        this->__Vtogcov__ram[0xeU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x800U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                   [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5110]);
        this->__Vtogcov__ram[0xeU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
                    [0xeU]))) {
        ++(vlSymsp->__Vcoverage[5111]);
        this->__Vtogcov__ram[0xeU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xeU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5112]);
        this->__Vtogcov__ram[0xfU] = ((0x1ffeU & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5113]);
        this->__Vtogcov__ram[0xfU] = ((0x1ffdU & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5114]);
        this->__Vtogcov__ram[0xfU] = ((0x1ffbU & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((8U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5115]);
        this->__Vtogcov__ram[0xfU] = ((0x1ff7U & this->__Vtogcov__ram
                                       [0xfU]) | (8U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x10U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5116]);
        this->__Vtogcov__ram[0xfU] = ((0x1fefU & this->__Vtogcov__ram
                                       [0xfU]) | (0x10U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x20U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5117]);
        this->__Vtogcov__ram[0xfU] = ((0x1fdfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x20U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x40U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5118]);
        this->__Vtogcov__ram[0xfU] = ((0x1fbfU & this->__Vtogcov__ram
                                       [0xfU]) | (0x40U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x80U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                  [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5119]);
        this->__Vtogcov__ram[0xfU] = ((0x1f7fU & this->__Vtogcov__ram
                                       [0xfU]) | (0x80U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x100U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5120]);
        this->__Vtogcov__ram[0xfU] = ((0x1effU & this->__Vtogcov__ram
                                       [0xfU]) | (0x100U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x200U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5121]);
        this->__Vtogcov__ram[0xfU] = ((0x1dffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x200U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x400U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5122]);
        this->__Vtogcov__ram[0xfU] = ((0x1bffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x400U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x800U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                   [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5123]);
        this->__Vtogcov__ram[0xfU] = ((0x17ffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x800U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((0x1000U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
                    [0xfU]))) {
        ++(vlSymsp->__Vcoverage[5124]);
        this->__Vtogcov__ram[0xfU] = ((0xfffU & this->__Vtogcov__ram
                                       [0xfU]) | (0x1000U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5125]);
        this->__Vtogcov__ram[0x10U] = ((0x1ffeU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5126]);
        this->__Vtogcov__ram[0x10U] = ((0x1ffdU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5127]);
        this->__Vtogcov__ram[0x10U] = ((0x1ffbU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((8U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5128]);
        this->__Vtogcov__ram[0x10U] = ((0x1ff7U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (8U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x10U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5129]);
        this->__Vtogcov__ram[0x10U] = ((0x1fefU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x20U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5130]);
        this->__Vtogcov__ram[0x10U] = ((0x1fdfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x40U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5131]);
        this->__Vtogcov__ram[0x10U] = ((0x1fbfU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x80U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                  [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5132]);
        this->__Vtogcov__ram[0x10U] = ((0x1f7fU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x100U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5133]);
        this->__Vtogcov__ram[0x10U] = ((0x1effU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x200U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5134]);
        this->__Vtogcov__ram[0x10U] = ((0x1dffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x200U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x400U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5135]);
        this->__Vtogcov__ram[0x10U] = ((0x1bffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x400U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x800U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                   [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5136]);
        this->__Vtogcov__ram[0x10U] = ((0x17ffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x800U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((0x1000U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
                    [0x10U]))) {
        ++(vlSymsp->__Vcoverage[5137]);
        this->__Vtogcov__ram[0x10U] = ((0xfffU & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (0x1000U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5138]);
        this->__Vtogcov__ram[0x11U] = ((0x1ffeU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5139]);
        this->__Vtogcov__ram[0x11U] = ((0x1ffdU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5140]);
        this->__Vtogcov__ram[0x11U] = ((0x1ffbU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((8U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5141]);
        this->__Vtogcov__ram[0x11U] = ((0x1ff7U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (8U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x10U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5142]);
        this->__Vtogcov__ram[0x11U] = ((0x1fefU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x10U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x20U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5143]);
        this->__Vtogcov__ram[0x11U] = ((0x1fdfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x20U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x40U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5144]);
        this->__Vtogcov__ram[0x11U] = ((0x1fbfU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x40U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x80U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                  [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5145]);
        this->__Vtogcov__ram[0x11U] = ((0x1f7fU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x80U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x100U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5146]);
        this->__Vtogcov__ram[0x11U] = ((0x1effU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x100U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x200U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5147]);
        this->__Vtogcov__ram[0x11U] = ((0x1dffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x200U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x400U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5148]);
        this->__Vtogcov__ram[0x11U] = ((0x1bffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x400U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x800U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                   [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5149]);
        this->__Vtogcov__ram[0x11U] = ((0x17ffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x800U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((0x1000U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
                    [0x11U]))) {
        ++(vlSymsp->__Vcoverage[5150]);
        this->__Vtogcov__ram[0x11U] = ((0xfffU & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (0x1000U & this->__PVT__ram
                                        [0x11U]));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_sequent__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__8\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4889]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
                                      >> 1U));
    }
}

VL_INLINE_OPT void Vopl3_mem_simple_dual_port__pi5::_combo__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__12(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_combo__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__12\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob_p0 = ((0x11U >= (0x1fU & (IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 0x27U))))
                            ? this->__PVT__ram[(0x1fU 
                                                & (IData)(
                                                          (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                           >> 0x27U)))]
                            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->__Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4890]);
        this->__Vtogcov__reb = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4904]);
        this->__Vtogcov__dob_p0 = ((0x1ffeU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (1U & (IData)(this->__PVT__dob_p0)));
    }
    if ((2U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4905]);
        this->__Vtogcov__dob_p0 = ((0x1ffdU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (2U & (IData)(this->__PVT__dob_p0)));
    }
    if ((4U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4906]);
        this->__Vtogcov__dob_p0 = ((0x1ffbU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (4U & (IData)(this->__PVT__dob_p0)));
    }
    if ((8U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4907]);
        this->__Vtogcov__dob_p0 = ((0x1ff7U & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (8U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x10U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4908]);
        this->__Vtogcov__dob_p0 = ((0x1fefU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x10U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x20U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4909]);
        this->__Vtogcov__dob_p0 = ((0x1fdfU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x20U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x40U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4910]);
        this->__Vtogcov__dob_p0 = ((0x1fbfU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x40U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x80U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4911]);
        this->__Vtogcov__dob_p0 = ((0x1f7fU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x80U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x100U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4912]);
        this->__Vtogcov__dob_p0 = ((0x1effU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x100U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x200U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4913]);
        this->__Vtogcov__dob_p0 = ((0x1dffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x200U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x400U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4914]);
        this->__Vtogcov__dob_p0 = ((0x1bffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x400U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x800U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4915]);
        this->__Vtogcov__dob_p0 = ((0x17ffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x800U & (IData)(this->__PVT__dob_p0)));
    }
    if ((0x1000U & ((IData)(this->__PVT__dob_p0) ^ this->__Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[4916]);
        this->__Vtogcov__dob_p0 = ((0xfffU & (IData)(this->__Vtogcov__dob_p0)) 
                                   | (0x1000U & (IData)(this->__PVT__dob_p0)));
    }
}
