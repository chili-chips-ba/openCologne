// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi7.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port_async_read__pi7) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port_async_read__pi7::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port_async_read__pi7::~Vopl3_mem_simple_dual_port_async_read__pi7() {
}

// Coverage
void Vopl3_mem_simple_dual_port_async_read__pi7::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port_async_read__pi7::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4453]);
}

void Vopl3_mem_simple_dual_port_async_read__pi7::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[9U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0xaU] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0xbU] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0xcU] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0xdU] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0xeU] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0xfU] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0x10U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0x11U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0x12U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0x13U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0x14U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    this->__PVT__ram[0x15U] = 0U;
    ++(vlSymsp->__Vcoverage[4448]);
    ++(vlSymsp->__Vcoverage[4449]);
}

void Vopl3_mem_simple_dual_port_async_read__pi7::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4382]);
        this->__Vtogcov__ram[0U] = ((6U & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4383]);
        this->__Vtogcov__ram[0U] = ((5U & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4384]);
        this->__Vtogcov__ram[0U] = ((3U & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4385]);
        this->__Vtogcov__ram[1U] = ((6U & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4386]);
        this->__Vtogcov__ram[1U] = ((5U & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4387]);
        this->__Vtogcov__ram[1U] = ((3U & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4388]);
        this->__Vtogcov__ram[2U] = ((6U & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4389]);
        this->__Vtogcov__ram[2U] = ((5U & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4390]);
        this->__Vtogcov__ram[2U] = ((3U & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4391]);
        this->__Vtogcov__ram[3U] = ((6U & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4392]);
        this->__Vtogcov__ram[3U] = ((5U & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4393]);
        this->__Vtogcov__ram[3U] = ((3U & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4394]);
        this->__Vtogcov__ram[4U] = ((6U & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4395]);
        this->__Vtogcov__ram[4U] = ((5U & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4396]);
        this->__Vtogcov__ram[4U] = ((3U & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4397]);
        this->__Vtogcov__ram[5U] = ((6U & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4398]);
        this->__Vtogcov__ram[5U] = ((5U & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4399]);
        this->__Vtogcov__ram[5U] = ((3U & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4400]);
        this->__Vtogcov__ram[6U] = ((6U & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4401]);
        this->__Vtogcov__ram[6U] = ((5U & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4402]);
        this->__Vtogcov__ram[6U] = ((3U & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4403]);
        this->__Vtogcov__ram[7U] = ((6U & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4404]);
        this->__Vtogcov__ram[7U] = ((5U & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4405]);
        this->__Vtogcov__ram[7U] = ((3U & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4406]);
        this->__Vtogcov__ram[8U] = ((6U & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4407]);
        this->__Vtogcov__ram[8U] = ((5U & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4408]);
        this->__Vtogcov__ram[8U] = ((3U & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4409]);
        this->__Vtogcov__ram[9U] = ((6U & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4410]);
        this->__Vtogcov__ram[9U] = ((5U & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4411]);
        this->__Vtogcov__ram[9U] = ((3U & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4412]);
        this->__Vtogcov__ram[0xaU] = ((6U & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4413]);
        this->__Vtogcov__ram[0xaU] = ((5U & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4414]);
        this->__Vtogcov__ram[0xaU] = ((3U & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4415]);
        this->__Vtogcov__ram[0xbU] = ((6U & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4416]);
        this->__Vtogcov__ram[0xbU] = ((5U & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4417]);
        this->__Vtogcov__ram[0xbU] = ((3U & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4418]);
        this->__Vtogcov__ram[0xcU] = ((6U & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4419]);
        this->__Vtogcov__ram[0xcU] = ((5U & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4420]);
        this->__Vtogcov__ram[0xcU] = ((3U & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4421]);
        this->__Vtogcov__ram[0xdU] = ((6U & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4422]);
        this->__Vtogcov__ram[0xdU] = ((5U & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4423]);
        this->__Vtogcov__ram[0xdU] = ((3U & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4424]);
        this->__Vtogcov__ram[0xeU] = ((6U & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4425]);
        this->__Vtogcov__ram[0xeU] = ((5U & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4426]);
        this->__Vtogcov__ram[0xeU] = ((3U & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4427]);
        this->__Vtogcov__ram[0xfU] = ((6U & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4428]);
        this->__Vtogcov__ram[0xfU] = ((5U & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4429]);
        this->__Vtogcov__ram[0xfU] = ((3U & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4430]);
        this->__Vtogcov__ram[0x10U] = ((6U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4431]);
        this->__Vtogcov__ram[0x10U] = ((5U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4432]);
        this->__Vtogcov__ram[0x10U] = ((3U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4433]);
        this->__Vtogcov__ram[0x11U] = ((6U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4434]);
        this->__Vtogcov__ram[0x11U] = ((5U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4435]);
        this->__Vtogcov__ram[0x11U] = ((3U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4436]);
        this->__Vtogcov__ram[0x12U] = ((6U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4437]);
        this->__Vtogcov__ram[0x12U] = ((5U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4438]);
        this->__Vtogcov__ram[0x12U] = ((3U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4439]);
        this->__Vtogcov__ram[0x13U] = ((6U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4440]);
        this->__Vtogcov__ram[0x13U] = ((5U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4441]);
        this->__Vtogcov__ram[0x13U] = ((3U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4442]);
        this->__Vtogcov__ram[0x14U] = ((6U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4443]);
        this->__Vtogcov__ram[0x14U] = ((5U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4444]);
        this->__Vtogcov__ram[0x14U] = ((3U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4445]);
        this->__Vtogcov__ram[0x15U] = ((6U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4446]);
        this->__Vtogcov__ram[0x15U] = ((5U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4447]);
        this->__Vtogcov__ram[0x15U] = ((3U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
    this->dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4378]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4379]);
        this->__Vtogcov__dob = ((6U & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4380]);
        this->__Vtogcov__dob = ((5U & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4381]);
        this->__Vtogcov__dob = ((3U & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
}

void Vopl3_mem_simple_dual_port_async_read__pi7::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4382]);
        this->__Vtogcov__ram[0U] = ((6U & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4383]);
        this->__Vtogcov__ram[0U] = ((5U & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4384]);
        this->__Vtogcov__ram[0U] = ((3U & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4385]);
        this->__Vtogcov__ram[1U] = ((6U & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4386]);
        this->__Vtogcov__ram[1U] = ((5U & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4387]);
        this->__Vtogcov__ram[1U] = ((3U & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4388]);
        this->__Vtogcov__ram[2U] = ((6U & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4389]);
        this->__Vtogcov__ram[2U] = ((5U & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4390]);
        this->__Vtogcov__ram[2U] = ((3U & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4391]);
        this->__Vtogcov__ram[3U] = ((6U & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4392]);
        this->__Vtogcov__ram[3U] = ((5U & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4393]);
        this->__Vtogcov__ram[3U] = ((3U & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4394]);
        this->__Vtogcov__ram[4U] = ((6U & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4395]);
        this->__Vtogcov__ram[4U] = ((5U & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4396]);
        this->__Vtogcov__ram[4U] = ((3U & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4397]);
        this->__Vtogcov__ram[5U] = ((6U & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4398]);
        this->__Vtogcov__ram[5U] = ((5U & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4399]);
        this->__Vtogcov__ram[5U] = ((3U & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4400]);
        this->__Vtogcov__ram[6U] = ((6U & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4401]);
        this->__Vtogcov__ram[6U] = ((5U & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4402]);
        this->__Vtogcov__ram[6U] = ((3U & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4403]);
        this->__Vtogcov__ram[7U] = ((6U & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4404]);
        this->__Vtogcov__ram[7U] = ((5U & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4405]);
        this->__Vtogcov__ram[7U] = ((3U & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4406]);
        this->__Vtogcov__ram[8U] = ((6U & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4407]);
        this->__Vtogcov__ram[8U] = ((5U & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4408]);
        this->__Vtogcov__ram[8U] = ((3U & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((1U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4409]);
        this->__Vtogcov__ram[9U] = ((6U & this->__Vtogcov__ram
                                     [9U]) | (1U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((2U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4410]);
        this->__Vtogcov__ram[9U] = ((5U & this->__Vtogcov__ram
                                     [9U]) | (2U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((4U & (this->__PVT__ram[9U] ^ this->__Vtogcov__ram
               [9U]))) {
        ++(vlSymsp->__Vcoverage[4411]);
        this->__Vtogcov__ram[9U] = ((3U & this->__Vtogcov__ram
                                     [9U]) | (4U & 
                                              this->__PVT__ram
                                              [9U]));
    }
    if ((1U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4412]);
        this->__Vtogcov__ram[0xaU] = ((6U & this->__Vtogcov__ram
                                       [0xaU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((2U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4413]);
        this->__Vtogcov__ram[0xaU] = ((5U & this->__Vtogcov__ram
                                       [0xaU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((4U & (this->__PVT__ram[0xaU] ^ this->__Vtogcov__ram
               [0xaU]))) {
        ++(vlSymsp->__Vcoverage[4414]);
        this->__Vtogcov__ram[0xaU] = ((3U & this->__Vtogcov__ram
                                       [0xaU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xaU]));
    }
    if ((1U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4415]);
        this->__Vtogcov__ram[0xbU] = ((6U & this->__Vtogcov__ram
                                       [0xbU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((2U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4416]);
        this->__Vtogcov__ram[0xbU] = ((5U & this->__Vtogcov__ram
                                       [0xbU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((4U & (this->__PVT__ram[0xbU] ^ this->__Vtogcov__ram
               [0xbU]))) {
        ++(vlSymsp->__Vcoverage[4417]);
        this->__Vtogcov__ram[0xbU] = ((3U & this->__Vtogcov__ram
                                       [0xbU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xbU]));
    }
    if ((1U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4418]);
        this->__Vtogcov__ram[0xcU] = ((6U & this->__Vtogcov__ram
                                       [0xcU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((2U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4419]);
        this->__Vtogcov__ram[0xcU] = ((5U & this->__Vtogcov__ram
                                       [0xcU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((4U & (this->__PVT__ram[0xcU] ^ this->__Vtogcov__ram
               [0xcU]))) {
        ++(vlSymsp->__Vcoverage[4420]);
        this->__Vtogcov__ram[0xcU] = ((3U & this->__Vtogcov__ram
                                       [0xcU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xcU]));
    }
    if ((1U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4421]);
        this->__Vtogcov__ram[0xdU] = ((6U & this->__Vtogcov__ram
                                       [0xdU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((2U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4422]);
        this->__Vtogcov__ram[0xdU] = ((5U & this->__Vtogcov__ram
                                       [0xdU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((4U & (this->__PVT__ram[0xdU] ^ this->__Vtogcov__ram
               [0xdU]))) {
        ++(vlSymsp->__Vcoverage[4423]);
        this->__Vtogcov__ram[0xdU] = ((3U & this->__Vtogcov__ram
                                       [0xdU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xdU]));
    }
    if ((1U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4424]);
        this->__Vtogcov__ram[0xeU] = ((6U & this->__Vtogcov__ram
                                       [0xeU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((2U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4425]);
        this->__Vtogcov__ram[0xeU] = ((5U & this->__Vtogcov__ram
                                       [0xeU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((4U & (this->__PVT__ram[0xeU] ^ this->__Vtogcov__ram
               [0xeU]))) {
        ++(vlSymsp->__Vcoverage[4426]);
        this->__Vtogcov__ram[0xeU] = ((3U & this->__Vtogcov__ram
                                       [0xeU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xeU]));
    }
    if ((1U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4427]);
        this->__Vtogcov__ram[0xfU] = ((6U & this->__Vtogcov__ram
                                       [0xfU]) | (1U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((2U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4428]);
        this->__Vtogcov__ram[0xfU] = ((5U & this->__Vtogcov__ram
                                       [0xfU]) | (2U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((4U & (this->__PVT__ram[0xfU] ^ this->__Vtogcov__ram
               [0xfU]))) {
        ++(vlSymsp->__Vcoverage[4429]);
        this->__Vtogcov__ram[0xfU] = ((3U & this->__Vtogcov__ram
                                       [0xfU]) | (4U 
                                                  & this->__PVT__ram
                                                  [0xfU]));
    }
    if ((1U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4430]);
        this->__Vtogcov__ram[0x10U] = ((6U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (1U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((2U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4431]);
        this->__Vtogcov__ram[0x10U] = ((5U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (2U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((4U & (this->__PVT__ram[0x10U] ^ this->__Vtogcov__ram
               [0x10U]))) {
        ++(vlSymsp->__Vcoverage[4432]);
        this->__Vtogcov__ram[0x10U] = ((3U & this->__Vtogcov__ram
                                        [0x10U]) | 
                                       (4U & this->__PVT__ram
                                        [0x10U]));
    }
    if ((1U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4433]);
        this->__Vtogcov__ram[0x11U] = ((6U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (1U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((2U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4434]);
        this->__Vtogcov__ram[0x11U] = ((5U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (2U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((4U & (this->__PVT__ram[0x11U] ^ this->__Vtogcov__ram
               [0x11U]))) {
        ++(vlSymsp->__Vcoverage[4435]);
        this->__Vtogcov__ram[0x11U] = ((3U & this->__Vtogcov__ram
                                        [0x11U]) | 
                                       (4U & this->__PVT__ram
                                        [0x11U]));
    }
    if ((1U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4436]);
        this->__Vtogcov__ram[0x12U] = ((6U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (1U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((2U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4437]);
        this->__Vtogcov__ram[0x12U] = ((5U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (2U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((4U & (this->__PVT__ram[0x12U] ^ this->__Vtogcov__ram
               [0x12U]))) {
        ++(vlSymsp->__Vcoverage[4438]);
        this->__Vtogcov__ram[0x12U] = ((3U & this->__Vtogcov__ram
                                        [0x12U]) | 
                                       (4U & this->__PVT__ram
                                        [0x12U]));
    }
    if ((1U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4439]);
        this->__Vtogcov__ram[0x13U] = ((6U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (1U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((2U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4440]);
        this->__Vtogcov__ram[0x13U] = ((5U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (2U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((4U & (this->__PVT__ram[0x13U] ^ this->__Vtogcov__ram
               [0x13U]))) {
        ++(vlSymsp->__Vcoverage[4441]);
        this->__Vtogcov__ram[0x13U] = ((3U & this->__Vtogcov__ram
                                        [0x13U]) | 
                                       (4U & this->__PVT__ram
                                        [0x13U]));
    }
    if ((1U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4442]);
        this->__Vtogcov__ram[0x14U] = ((6U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (1U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((2U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4443]);
        this->__Vtogcov__ram[0x14U] = ((5U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (2U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((4U & (this->__PVT__ram[0x14U] ^ this->__Vtogcov__ram
               [0x14U]))) {
        ++(vlSymsp->__Vcoverage[4444]);
        this->__Vtogcov__ram[0x14U] = ((3U & this->__Vtogcov__ram
                                        [0x14U]) | 
                                       (4U & this->__PVT__ram
                                        [0x14U]));
    }
    if ((1U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4445]);
        this->__Vtogcov__ram[0x15U] = ((6U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (1U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((2U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4446]);
        this->__Vtogcov__ram[0x15U] = ((5U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (2U & this->__PVT__ram
                                        [0x15U]));
    }
    if ((4U & (this->__PVT__ram[0x15U] ^ this->__Vtogcov__ram
               [0x15U]))) {
        ++(vlSymsp->__Vcoverage[4447]);
        this->__Vtogcov__ram[0x15U] = ((3U & this->__Vtogcov__ram
                                        [0x15U]) | 
                                       (4U & this->__PVT__ram
                                        [0x15U]));
    }
    this->dob = ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address]
                  : 0U);
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4378]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
                                      >> 1U));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4379]);
        this->__Vtogcov__dob = ((6U & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4380]);
        this->__Vtogcov__dob = ((5U & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4381]);
        this->__Vtogcov__dob = ((3U & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
}

void Vopl3_mem_simple_dual_port_async_read__pi7::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(3);
    dob = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<22; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(3);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<22; ++__Vi0) {
            __Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(3);
    }}
    __Vlvbound2 = VL_RAND_RESET_I(3);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(3);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port_async_read__pi7::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi7::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 53, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4378]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 54, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[879]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[880]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[881]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[882]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[883]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4379]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4380]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4381]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4382]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4383]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4384]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4385]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4386]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4387]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4388]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4389]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[2][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4390]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[2][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4391]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4392]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[3][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4393]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[3][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4394]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4395]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[4][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4396]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[4][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4397]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4398]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[5][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4399]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[5][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4400]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4401]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[6][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4402]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[6][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4403]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4404]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[7][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4405]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[7][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4406]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4407]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[8][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4408]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[8][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4409]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[9][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4410]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[9][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4411]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[9][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4412]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[10][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4413]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[10][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4414]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[10][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4415]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[11][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4416]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[11][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4417]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[11][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4418]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[12][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4419]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[12][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4420]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[12][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4421]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[13][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4422]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[13][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4423]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[13][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4424]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[14][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4425]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[14][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4426]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[14][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4427]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[15][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4428]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[15][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4429]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[15][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4430]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[16][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4431]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[16][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4432]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[16][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4433]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[17][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4434]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[17][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4435]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[17][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4436]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[18][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4437]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[18][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4438]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[18][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4439]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[19][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4440]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[19][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4441]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[19][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4442]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[20][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4443]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[20][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4444]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[20][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4445]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[21][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4446]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[21][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4447]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi7", "ram[21][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4448]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 71, 9, "", "v_line/mem_simple_dual_port_async_read__pi7", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4449]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 70, 5, "", "v_line/mem_simple_dual_port_async_read__pi7", "block", "70-71");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4450]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 9, "", "v_branch/mem_simple_dual_port_async_read__pi7", "if", "77-78");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4451]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 10, "", "v_branch/mem_simple_dual_port_async_read__pi7", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4452]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 76, 5, "", "v_line/mem_simple_dual_port_async_read__pi7", "block", "76");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4453]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 82, 5, "", "v_line/mem_simple_dual_port_async_read__pi7", "block", "82-83");
}
