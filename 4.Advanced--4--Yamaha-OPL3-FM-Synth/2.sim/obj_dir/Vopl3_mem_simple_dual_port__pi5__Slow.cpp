// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port__pi5.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port__pi5) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port__pi5::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port__pi5::~Vopl3_mem_simple_dual_port__pi5() {
}

// Coverage
void Vopl3_mem_simple_dual_port__pi5::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port__pi5::_settle__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_settle__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[5156]);
    ++(vlSymsp->__Vcoverage[5161]);
}

void Vopl3_mem_simple_dual_port__pi5::_initial__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_initial__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__genblk1__DOT__dob_p1 = 0U;
    ++(vlSymsp->__Vcoverage[5157]);
    this->__PVT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[9U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0xaU] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0xbU] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0xcU] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0xdU] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0xeU] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0xfU] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0x10U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    this->__PVT__ram[0x11U] = 0U;
    ++(vlSymsp->__Vcoverage[5151]);
    ++(vlSymsp->__Vcoverage[5152]);
}

void Vopl3_mem_simple_dual_port__pi5::_settle__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_settle__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4889]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array));
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

void Vopl3_mem_simple_dual_port__pi5::_settle__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_settle__TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4889]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
                                      >> 1U));
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

void Vopl3_mem_simple_dual_port__pi5::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    clkb = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    reb = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(13);
    dob = VL_RAND_RESET_I(13);
    __PVT__dob_p0 = VL_RAND_RESET_I(13);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(13);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__reb = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(13);
    __Vtogcov__dob_p0 = VL_RAND_RESET_I(13);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(13);
    }}
    __PVT__genblk1__DOT__dob_p1 = VL_RAND_RESET_I(13);
    __Vlvbound2 = VL_RAND_RESET_I(13);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(13);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port__pi5::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port__pi5::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 50, 16, "", "v_toggle/mem_simple_dual_port__pi5", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 51, 16, "", "v_toggle/mem_simple_dual_port__pi5", "clkb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4889]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 52, 16, "", "v_toggle/mem_simple_dual_port__pi5", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4890]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 53, 16, "", "v_toggle/mem_simple_dual_port__pi5", "reb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[330]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[331]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[332]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[333]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[334]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[582]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[583]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[584]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[585]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[586]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, "", "v_toggle/mem_simple_dual_port__pi5", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[335]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[336]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[337]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[338]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[339]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[340]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[341]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[342]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[343]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[344]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[345]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[346]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[347]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, "", "v_toggle/mem_simple_dual_port__pi5", "dia[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4891]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4892]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4893]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4894]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4895]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4896]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4897]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4898]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4899]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4900]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4901]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4902]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4903]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, "", "v_toggle/mem_simple_dual_port__pi5", "dob[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4904]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4905]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4906]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4907]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4908]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4909]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4910]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4911]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4912]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4913]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4914]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4915]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4916]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, "", "v_toggle/mem_simple_dual_port__pi5", "dob_p0[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4917]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4918]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4919]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4920]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4921]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4922]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4923]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4924]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4925]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4926]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4927]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4928]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4929]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[0][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4930]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4931]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4932]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4933]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4934]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4935]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4936]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4937]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4938]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4939]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4940]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4941]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4942]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[1][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4943]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4944]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4945]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4946]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4947]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4948]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4949]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4950]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4951]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4952]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4953]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4954]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4955]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[2][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4956]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4957]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4958]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4959]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4960]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4961]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4962]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4963]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4964]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4965]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4966]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4967]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4968]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[3][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4969]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4970]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4971]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4972]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4973]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4974]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4975]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4976]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4977]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4978]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4979]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4980]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4981]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[4][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4982]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4983]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4984]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4985]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4986]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4987]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4988]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4989]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4990]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4991]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4992]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4993]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4994]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[5][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4995]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4996]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4997]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4998]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4999]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5000]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5001]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5002]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5003]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5004]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5005]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5006]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5007]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[6][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5008]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5009]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5010]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5011]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5012]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5013]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5014]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5015]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5016]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5017]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5018]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5019]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5020]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[7][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5021]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5022]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5023]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5024]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5025]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5026]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5027]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5028]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5029]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5030]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5031]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5032]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5033]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[8][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5034]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5035]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5036]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5037]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5038]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5039]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5040]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5041]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5042]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5043]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5044]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5045]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5046]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[9][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5047]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5048]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5049]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5050]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5051]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5052]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5053]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5054]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5055]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5056]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5057]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5058]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5059]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[10][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5060]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5061]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5062]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5063]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5064]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5065]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5066]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5067]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5068]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5069]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5070]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5071]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5072]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[11][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5073]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5074]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5075]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5076]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5077]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5078]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5079]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5080]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5081]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5082]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5083]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5084]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5085]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[12][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5086]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5087]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5088]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5089]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5090]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5091]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5092]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5093]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5094]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5095]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5096]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5097]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5098]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[13][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5099]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5100]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5101]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5102]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5103]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5104]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5105]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5106]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5107]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5108]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5109]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5110]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5111]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[14][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5112]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5113]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5114]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5115]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5116]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5117]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5118]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5119]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5120]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5121]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5122]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5123]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5124]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[15][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5125]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5126]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5127]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5128]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5129]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5130]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5131]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5132]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5133]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5134]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5135]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5136]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5137]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[16][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5138]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5139]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5140]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5141]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5142]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5143]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5144]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5145]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5146]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5147]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5148]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5149]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5150]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, "", "v_toggle/mem_simple_dual_port__pi5", "ram[17][12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5151]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 72, 9, "", "v_line/mem_simple_dual_port__pi5", "block", "72-73");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5152]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 71, 5, "", "v_line/mem_simple_dual_port__pi5", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5153]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 9, "", "v_branch/mem_simple_dual_port__pi5", "if", "78-79");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5154]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 10, "", "v_branch/mem_simple_dual_port__pi5", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5155]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 77, 5, "", "v_line/mem_simple_dual_port__pi5", "block", "77");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5156]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 81, 5, "", "v_line/mem_simple_dual_port__pi5", "block", "81");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5157]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 85, 41, "", "v_line/mem_simple_dual_port__pi5", "block", "85");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5158]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 13, "", "v_branch/mem_simple_dual_port__pi5", "if", "88-89");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5159]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 14, "", "v_branch/mem_simple_dual_port__pi5", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5160]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 87, 9, "", "v_line/mem_simple_dual_port__pi5", "block", "87");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5161]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 92, 13, "", "v_line/mem_simple_dual_port__pi5", "block", "92");
}
