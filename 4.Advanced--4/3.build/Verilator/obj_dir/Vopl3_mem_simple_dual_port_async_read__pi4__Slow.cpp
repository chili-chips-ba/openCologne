// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi4.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port_async_read__pi4) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port_async_read__pi4::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port_async_read__pi4::~Vopl3_mem_simple_dual_port_async_read__pi4() {
}

// Coverage
void Vopl3_mem_simple_dual_port_async_read__pi4::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4710]);
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_initial__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_initial__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    this->__PVT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[4705]);
    ++(vlSymsp->__Vcoverage[4706]);
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__19(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__19\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4639]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4640]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4641]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4642]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4643]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4644]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4645]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4646]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4647]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4648]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4649]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4650]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4651]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4652]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4653]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4654]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4655]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4656]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4657]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4658]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4659]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4660]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4661]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4662]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4663]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4664]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4665]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4666]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4667]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4668]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4669]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4670]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4671]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4672]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4673]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4674]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4675]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4676]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4677]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4678]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4679]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4680]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4681]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4682]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4683]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4684]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4685]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4686]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4687]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4688]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4689]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4690]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4691]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4692]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4693]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4694]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4695]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4696]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4697]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4698]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4699]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4700]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4701]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4702]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4703]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4704]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    this->dob = ((8U >= (0xfU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                         >> 0x22U))))
                  ? this->__PVT__ram[(0xfU & (IData)(
                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                      >> 0x22U)))]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
    if ((0x40U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->dob)));
    }
    if ((0x80U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->dob)));
    }
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__20(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__20\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4639]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4640]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4641]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4642]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4643]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4644]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4645]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4646]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4647]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4648]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4649]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4650]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4651]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4652]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4653]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4654]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4655]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4656]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4657]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4658]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4659]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4660]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4661]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4662]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4663]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4664]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4665]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4666]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4667]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4668]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4669]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4670]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4671]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4672]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4673]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4674]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4675]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4676]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4677]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4678]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4679]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4680]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4681]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4682]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4683]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4684]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4685]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4686]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4687]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4688]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4689]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4690]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4691]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4692]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4693]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4694]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4695]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4696]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4697]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4698]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4699]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4700]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4701]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4702]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4703]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4704]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    this->dob = ((8U >= (0xfU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                         >> 0x22U))))
                  ? this->__PVT__ram[(0xfU & (IData)(
                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                      >> 0x22U)))]
                  : 0U);
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array) 
                                      >> 1U));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
    if ((0x40U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->dob)));
    }
    if ((0x80U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->dob)));
    }
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__17(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__17\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4639]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4640]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4641]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4642]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4643]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4644]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4645]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4646]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4647]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4648]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4649]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4650]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4651]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4652]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4653]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4654]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4655]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4656]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4657]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4658]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4659]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4660]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4661]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4662]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4663]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4664]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4665]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4666]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4667]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4668]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4669]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4670]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4671]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4672]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4673]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4674]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4675]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4676]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4677]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4678]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4679]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4680]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4681]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4682]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4683]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4684]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4685]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4686]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4687]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4688]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4689]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4690]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4691]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4692]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4693]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4694]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4695]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4696]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4697]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4698]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4699]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4700]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4701]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4702]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4703]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4704]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    this->dob = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
    if ((0x40U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->dob)));
    }
    if ((0x80U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->dob)));
    }
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__18(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__18\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4633]);
        this->__Vtogcov__ram[0U] = ((0xfeU & this->__Vtogcov__ram
                                     [0U]) | (1U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((2U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4634]);
        this->__Vtogcov__ram[0U] = ((0xfdU & this->__Vtogcov__ram
                                     [0U]) | (2U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((4U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4635]);
        this->__Vtogcov__ram[0U] = ((0xfbU & this->__Vtogcov__ram
                                     [0U]) | (4U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((8U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4636]);
        this->__Vtogcov__ram[0U] = ((0xf7U & this->__Vtogcov__ram
                                     [0U]) | (8U & 
                                              this->__PVT__ram
                                              [0U]));
    }
    if ((0x10U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4637]);
        this->__Vtogcov__ram[0U] = ((0xefU & this->__Vtogcov__ram
                                     [0U]) | (0x10U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x20U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4638]);
        this->__Vtogcov__ram[0U] = ((0xdfU & this->__Vtogcov__ram
                                     [0U]) | (0x20U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x40U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4639]);
        this->__Vtogcov__ram[0U] = ((0xbfU & this->__Vtogcov__ram
                                     [0U]) | (0x40U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((0x80U & (this->__PVT__ram[0U] ^ this->__Vtogcov__ram
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4640]);
        this->__Vtogcov__ram[0U] = ((0x7fU & this->__Vtogcov__ram
                                     [0U]) | (0x80U 
                                              & this->__PVT__ram
                                              [0U]));
    }
    if ((1U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4641]);
        this->__Vtogcov__ram[1U] = ((0xfeU & this->__Vtogcov__ram
                                     [1U]) | (1U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((2U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4642]);
        this->__Vtogcov__ram[1U] = ((0xfdU & this->__Vtogcov__ram
                                     [1U]) | (2U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((4U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4643]);
        this->__Vtogcov__ram[1U] = ((0xfbU & this->__Vtogcov__ram
                                     [1U]) | (4U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((8U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4644]);
        this->__Vtogcov__ram[1U] = ((0xf7U & this->__Vtogcov__ram
                                     [1U]) | (8U & 
                                              this->__PVT__ram
                                              [1U]));
    }
    if ((0x10U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4645]);
        this->__Vtogcov__ram[1U] = ((0xefU & this->__Vtogcov__ram
                                     [1U]) | (0x10U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x20U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4646]);
        this->__Vtogcov__ram[1U] = ((0xdfU & this->__Vtogcov__ram
                                     [1U]) | (0x20U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x40U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4647]);
        this->__Vtogcov__ram[1U] = ((0xbfU & this->__Vtogcov__ram
                                     [1U]) | (0x40U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((0x80U & (this->__PVT__ram[1U] ^ this->__Vtogcov__ram
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4648]);
        this->__Vtogcov__ram[1U] = ((0x7fU & this->__Vtogcov__ram
                                     [1U]) | (0x80U 
                                              & this->__PVT__ram
                                              [1U]));
    }
    if ((1U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4649]);
        this->__Vtogcov__ram[2U] = ((0xfeU & this->__Vtogcov__ram
                                     [2U]) | (1U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((2U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4650]);
        this->__Vtogcov__ram[2U] = ((0xfdU & this->__Vtogcov__ram
                                     [2U]) | (2U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((4U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4651]);
        this->__Vtogcov__ram[2U] = ((0xfbU & this->__Vtogcov__ram
                                     [2U]) | (4U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((8U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[4652]);
        this->__Vtogcov__ram[2U] = ((0xf7U & this->__Vtogcov__ram
                                     [2U]) | (8U & 
                                              this->__PVT__ram
                                              [2U]));
    }
    if ((0x10U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4653]);
        this->__Vtogcov__ram[2U] = ((0xefU & this->__Vtogcov__ram
                                     [2U]) | (0x10U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x20U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4654]);
        this->__Vtogcov__ram[2U] = ((0xdfU & this->__Vtogcov__ram
                                     [2U]) | (0x20U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x40U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4655]);
        this->__Vtogcov__ram[2U] = ((0xbfU & this->__Vtogcov__ram
                                     [2U]) | (0x40U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((0x80U & (this->__PVT__ram[2U] ^ this->__Vtogcov__ram
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[4656]);
        this->__Vtogcov__ram[2U] = ((0x7fU & this->__Vtogcov__ram
                                     [2U]) | (0x80U 
                                              & this->__PVT__ram
                                              [2U]));
    }
    if ((1U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4657]);
        this->__Vtogcov__ram[3U] = ((0xfeU & this->__Vtogcov__ram
                                     [3U]) | (1U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((2U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4658]);
        this->__Vtogcov__ram[3U] = ((0xfdU & this->__Vtogcov__ram
                                     [3U]) | (2U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((4U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4659]);
        this->__Vtogcov__ram[3U] = ((0xfbU & this->__Vtogcov__ram
                                     [3U]) | (4U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((8U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[4660]);
        this->__Vtogcov__ram[3U] = ((0xf7U & this->__Vtogcov__ram
                                     [3U]) | (8U & 
                                              this->__PVT__ram
                                              [3U]));
    }
    if ((0x10U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4661]);
        this->__Vtogcov__ram[3U] = ((0xefU & this->__Vtogcov__ram
                                     [3U]) | (0x10U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x20U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4662]);
        this->__Vtogcov__ram[3U] = ((0xdfU & this->__Vtogcov__ram
                                     [3U]) | (0x20U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x40U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4663]);
        this->__Vtogcov__ram[3U] = ((0xbfU & this->__Vtogcov__ram
                                     [3U]) | (0x40U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((0x80U & (this->__PVT__ram[3U] ^ this->__Vtogcov__ram
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[4664]);
        this->__Vtogcov__ram[3U] = ((0x7fU & this->__Vtogcov__ram
                                     [3U]) | (0x80U 
                                              & this->__PVT__ram
                                              [3U]));
    }
    if ((1U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4665]);
        this->__Vtogcov__ram[4U] = ((0xfeU & this->__Vtogcov__ram
                                     [4U]) | (1U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((2U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4666]);
        this->__Vtogcov__ram[4U] = ((0xfdU & this->__Vtogcov__ram
                                     [4U]) | (2U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((4U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4667]);
        this->__Vtogcov__ram[4U] = ((0xfbU & this->__Vtogcov__ram
                                     [4U]) | (4U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((8U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[4668]);
        this->__Vtogcov__ram[4U] = ((0xf7U & this->__Vtogcov__ram
                                     [4U]) | (8U & 
                                              this->__PVT__ram
                                              [4U]));
    }
    if ((0x10U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4669]);
        this->__Vtogcov__ram[4U] = ((0xefU & this->__Vtogcov__ram
                                     [4U]) | (0x10U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x20U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4670]);
        this->__Vtogcov__ram[4U] = ((0xdfU & this->__Vtogcov__ram
                                     [4U]) | (0x20U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x40U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4671]);
        this->__Vtogcov__ram[4U] = ((0xbfU & this->__Vtogcov__ram
                                     [4U]) | (0x40U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((0x80U & (this->__PVT__ram[4U] ^ this->__Vtogcov__ram
                  [4U]))) {
        ++(vlSymsp->__Vcoverage[4672]);
        this->__Vtogcov__ram[4U] = ((0x7fU & this->__Vtogcov__ram
                                     [4U]) | (0x80U 
                                              & this->__PVT__ram
                                              [4U]));
    }
    if ((1U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4673]);
        this->__Vtogcov__ram[5U] = ((0xfeU & this->__Vtogcov__ram
                                     [5U]) | (1U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((2U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4674]);
        this->__Vtogcov__ram[5U] = ((0xfdU & this->__Vtogcov__ram
                                     [5U]) | (2U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((4U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4675]);
        this->__Vtogcov__ram[5U] = ((0xfbU & this->__Vtogcov__ram
                                     [5U]) | (4U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((8U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[4676]);
        this->__Vtogcov__ram[5U] = ((0xf7U & this->__Vtogcov__ram
                                     [5U]) | (8U & 
                                              this->__PVT__ram
                                              [5U]));
    }
    if ((0x10U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4677]);
        this->__Vtogcov__ram[5U] = ((0xefU & this->__Vtogcov__ram
                                     [5U]) | (0x10U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x20U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4678]);
        this->__Vtogcov__ram[5U] = ((0xdfU & this->__Vtogcov__ram
                                     [5U]) | (0x20U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x40U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4679]);
        this->__Vtogcov__ram[5U] = ((0xbfU & this->__Vtogcov__ram
                                     [5U]) | (0x40U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((0x80U & (this->__PVT__ram[5U] ^ this->__Vtogcov__ram
                  [5U]))) {
        ++(vlSymsp->__Vcoverage[4680]);
        this->__Vtogcov__ram[5U] = ((0x7fU & this->__Vtogcov__ram
                                     [5U]) | (0x80U 
                                              & this->__PVT__ram
                                              [5U]));
    }
    if ((1U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4681]);
        this->__Vtogcov__ram[6U] = ((0xfeU & this->__Vtogcov__ram
                                     [6U]) | (1U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((2U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4682]);
        this->__Vtogcov__ram[6U] = ((0xfdU & this->__Vtogcov__ram
                                     [6U]) | (2U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((4U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4683]);
        this->__Vtogcov__ram[6U] = ((0xfbU & this->__Vtogcov__ram
                                     [6U]) | (4U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((8U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[4684]);
        this->__Vtogcov__ram[6U] = ((0xf7U & this->__Vtogcov__ram
                                     [6U]) | (8U & 
                                              this->__PVT__ram
                                              [6U]));
    }
    if ((0x10U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4685]);
        this->__Vtogcov__ram[6U] = ((0xefU & this->__Vtogcov__ram
                                     [6U]) | (0x10U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x20U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4686]);
        this->__Vtogcov__ram[6U] = ((0xdfU & this->__Vtogcov__ram
                                     [6U]) | (0x20U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x40U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4687]);
        this->__Vtogcov__ram[6U] = ((0xbfU & this->__Vtogcov__ram
                                     [6U]) | (0x40U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((0x80U & (this->__PVT__ram[6U] ^ this->__Vtogcov__ram
                  [6U]))) {
        ++(vlSymsp->__Vcoverage[4688]);
        this->__Vtogcov__ram[6U] = ((0x7fU & this->__Vtogcov__ram
                                     [6U]) | (0x80U 
                                              & this->__PVT__ram
                                              [6U]));
    }
    if ((1U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4689]);
        this->__Vtogcov__ram[7U] = ((0xfeU & this->__Vtogcov__ram
                                     [7U]) | (1U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((2U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4690]);
        this->__Vtogcov__ram[7U] = ((0xfdU & this->__Vtogcov__ram
                                     [7U]) | (2U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((4U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4691]);
        this->__Vtogcov__ram[7U] = ((0xfbU & this->__Vtogcov__ram
                                     [7U]) | (4U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((8U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[4692]);
        this->__Vtogcov__ram[7U] = ((0xf7U & this->__Vtogcov__ram
                                     [7U]) | (8U & 
                                              this->__PVT__ram
                                              [7U]));
    }
    if ((0x10U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4693]);
        this->__Vtogcov__ram[7U] = ((0xefU & this->__Vtogcov__ram
                                     [7U]) | (0x10U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x20U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4694]);
        this->__Vtogcov__ram[7U] = ((0xdfU & this->__Vtogcov__ram
                                     [7U]) | (0x20U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x40U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4695]);
        this->__Vtogcov__ram[7U] = ((0xbfU & this->__Vtogcov__ram
                                     [7U]) | (0x40U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((0x80U & (this->__PVT__ram[7U] ^ this->__Vtogcov__ram
                  [7U]))) {
        ++(vlSymsp->__Vcoverage[4696]);
        this->__Vtogcov__ram[7U] = ((0x7fU & this->__Vtogcov__ram
                                     [7U]) | (0x80U 
                                              & this->__PVT__ram
                                              [7U]));
    }
    if ((1U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4697]);
        this->__Vtogcov__ram[8U] = ((0xfeU & this->__Vtogcov__ram
                                     [8U]) | (1U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((2U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4698]);
        this->__Vtogcov__ram[8U] = ((0xfdU & this->__Vtogcov__ram
                                     [8U]) | (2U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((4U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4699]);
        this->__Vtogcov__ram[8U] = ((0xfbU & this->__Vtogcov__ram
                                     [8U]) | (4U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((8U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[4700]);
        this->__Vtogcov__ram[8U] = ((0xf7U & this->__Vtogcov__ram
                                     [8U]) | (8U & 
                                              this->__PVT__ram
                                              [8U]));
    }
    if ((0x10U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4701]);
        this->__Vtogcov__ram[8U] = ((0xefU & this->__Vtogcov__ram
                                     [8U]) | (0x10U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x20U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4702]);
        this->__Vtogcov__ram[8U] = ((0xdfU & this->__Vtogcov__ram
                                     [8U]) | (0x20U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x40U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4703]);
        this->__Vtogcov__ram[8U] = ((0xbfU & this->__Vtogcov__ram
                                     [8U]) | (0x40U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    if ((0x80U & (this->__PVT__ram[8U] ^ this->__Vtogcov__ram
                  [8U]))) {
        ++(vlSymsp->__Vcoverage[4704]);
        this->__Vtogcov__ram[8U] = ((0x7fU & this->__Vtogcov__ram
                                     [8U]) | (0x80U 
                                              & this->__PVT__ram
                                              [8U]));
    }
    this->dob = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address]
                  : 0U);
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4624]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array) 
                                      >> 1U));
    }
    if ((1U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4625]);
        this->__Vtogcov__dob = ((0xfeU & (IData)(this->__Vtogcov__dob)) 
                                | (1U & (IData)(this->dob)));
    }
    if ((2U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4626]);
        this->__Vtogcov__dob = ((0xfdU & (IData)(this->__Vtogcov__dob)) 
                                | (2U & (IData)(this->dob)));
    }
    if ((4U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4627]);
        this->__Vtogcov__dob = ((0xfbU & (IData)(this->__Vtogcov__dob)) 
                                | (4U & (IData)(this->dob)));
    }
    if ((8U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4628]);
        this->__Vtogcov__dob = ((0xf7U & (IData)(this->__Vtogcov__dob)) 
                                | (8U & (IData)(this->dob)));
    }
    if ((0x10U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4629]);
        this->__Vtogcov__dob = ((0xefU & (IData)(this->__Vtogcov__dob)) 
                                | (0x10U & (IData)(this->dob)));
    }
    if ((0x20U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4630]);
        this->__Vtogcov__dob = ((0xdfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x20U & (IData)(this->dob)));
    }
    if ((0x40U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4631]);
        this->__Vtogcov__dob = ((0xbfU & (IData)(this->__Vtogcov__dob)) 
                                | (0x40U & (IData)(this->dob)));
    }
    if ((0x80U & ((IData)(this->dob) ^ this->__Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[4632]);
        this->__Vtogcov__dob = ((0x7fU & (IData)(this->__Vtogcov__dob)) 
                                | (0x80U & (IData)(this->dob)));
    }
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(4);
    addrb = VL_RAND_RESET_I(4);
    dia = VL_RAND_RESET_I(8);
    dob = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
            __Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vlvbound2 = VL_RAND_RESET_I(8);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(8);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port_async_read__pi4::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi4::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 53, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4624]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 54, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[903]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[904]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[905]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[906]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dia[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4625]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4626]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4627]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4628]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4629]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4630]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4631]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4632]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "dob[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4633]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4634]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4635]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4636]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4637]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4638]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4639]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4640]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[0][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4641]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4642]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4643]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4644]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4645]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4646]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4647]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4648]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[1][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4649]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4650]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4651]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4652]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4653]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4654]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4655]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4656]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[2][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4657]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4658]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4659]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4660]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4661]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4662]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4663]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4664]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[3][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4665]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4666]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4667]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4668]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4669]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4670]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4671]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4672]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[4][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4673]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4674]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4675]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4676]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4677]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4678]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4679]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4680]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[5][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4681]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4682]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4683]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4684]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4685]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4686]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4687]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4688]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[6][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4689]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4690]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4691]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4692]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4693]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4694]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4695]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4696]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[7][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4697]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4698]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4699]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4700]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4701]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4702]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4703]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4704]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi4", "ram[8][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4705]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 71, 9, "", "v_line/mem_simple_dual_port_async_read__pi4", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4706]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 70, 5, "", "v_line/mem_simple_dual_port_async_read__pi4", "block", "70-71");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4707]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 9, "", "v_branch/mem_simple_dual_port_async_read__pi4", "if", "77-78");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4708]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 10, "", "v_branch/mem_simple_dual_port_async_read__pi4", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4709]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 76, 5, "", "v_line/mem_simple_dual_port_async_read__pi4", "block", "76");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4710]), first, "/home/user/openCologne/4.Advanced--4/3.build/Verilator/../../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 82, 5, "", "v_line/mem_simple_dual_port_async_read__pi4", "block", "82-83");
}
