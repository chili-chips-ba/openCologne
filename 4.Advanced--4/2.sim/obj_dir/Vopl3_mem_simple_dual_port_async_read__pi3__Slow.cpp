// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi3.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port_async_read__pi3) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port_async_read__pi3::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port_async_read__pi3::~Vopl3_mem_simple_dual_port_async_read__pi3() {
}

// Coverage
void Vopl3_mem_simple_dual_port_async_read__pi3::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port_async_read__pi3::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4802]);
}

void Vopl3_mem_simple_dual_port_async_read__pi3::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__ram[0U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[1U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[2U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[3U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[4U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[5U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[6U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[7U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[8U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[9U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0xaU] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0xbU] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0xcU] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0xdU] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0xeU] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0xfU] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0x10U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    this->__PVT__ram[0x11U] = 8U;
    ++(vlSymsp->__Vcoverage[4797]);
    ++(vlSymsp->__Vcoverage[4798]);
}

void Vopl3_mem_simple_dual_port_async_read__pi3::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4711]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array));
    }
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

void Vopl3_mem_simple_dual_port_async_read__pi3::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4711]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
                                      >> 1U));
    }
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

void Vopl3_mem_simple_dual_port_async_read__pi3::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(4);
    dob = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(4);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__addra = VL_RAND_RESET_I(5);
    __Vtogcov__dia = VL_RAND_RESET_I(4);
    __Vtogcov__dob = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(4);
    }}
    __Vlvbound2 = VL_RAND_RESET_I(4);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(4);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port_async_read__pi3::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi3::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 53, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4711]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 54, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4712]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4713]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4714]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4715]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4716]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4717]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4718]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4719]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4720]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4721]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4722]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4723]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4724]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4725]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4726]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4727]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4728]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[0][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4729]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4730]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4731]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4732]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[1][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4733]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4734]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[2][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4735]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[2][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4736]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[2][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4737]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4738]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[3][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4739]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[3][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4740]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[3][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4741]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4742]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[4][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4743]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[4][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4744]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[4][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4745]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4746]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[5][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4747]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[5][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4748]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[5][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4749]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4750]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[6][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4751]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[6][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4752]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[6][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4753]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4754]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[7][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4755]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[7][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4756]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[7][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4757]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4758]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[8][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4759]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[8][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4760]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[8][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4761]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[9][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4762]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[9][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4763]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[9][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4764]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[9][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4765]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[10][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4766]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[10][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4767]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[10][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4768]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[10][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4769]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[11][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4770]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[11][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4771]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[11][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4772]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[11][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4773]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[12][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4774]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[12][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4775]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[12][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4776]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[12][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4777]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[13][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4778]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[13][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4779]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[13][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4780]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[13][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4781]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[14][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4782]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[14][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4783]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[14][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4784]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[14][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4785]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[15][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4786]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[15][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4787]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[15][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4788]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[15][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4789]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[16][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4790]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[16][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4791]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[16][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4792]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[16][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4793]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[17][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4794]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[17][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4795]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[17][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4796]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi3", "ram[17][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4797]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 71, 9, "", "v_line/mem_simple_dual_port_async_read__pi3", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4798]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 70, 5, "", "v_line/mem_simple_dual_port_async_read__pi3", "block", "70-71");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4799]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 9, "", "v_branch/mem_simple_dual_port_async_read__pi3", "if", "77-78");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4800]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 10, "", "v_branch/mem_simple_dual_port_async_read__pi3", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4801]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 76, 5, "", "v_line/mem_simple_dual_port_async_read__pi3", "block", "76");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4802]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 82, 5, "", "v_line/mem_simple_dual_port_async_read__pi3", "block", "82-83");
}
