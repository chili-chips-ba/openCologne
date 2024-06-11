// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi8.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port_async_read__pi8) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port_async_read__pi8::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port_async_read__pi8::~Vopl3_mem_simple_dual_port_async_read__pi8() {
}

// Coverage
void Vopl3_mem_simple_dual_port_async_read__pi8::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port_async_read__pi8::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4377]);
}

void Vopl3_mem_simple_dual_port_async_read__pi8::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    this->__PVT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[4372]);
    ++(vlSymsp->__Vcoverage[4373]);
}

void Vopl3_mem_simple_dual_port_async_read__pi8::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    this->dob = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4311]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array));
    }
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

void Vopl3_mem_simple_dual_port_async_read__pi8::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    this->dob = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address]
                  : 0U);
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4311]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
                                      >> 1U));
    }
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

void Vopl3_mem_simple_dual_port_async_read__pi8::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(4);
    addrb = VL_RAND_RESET_I(4);
    dia = VL_RAND_RESET_I(6);
    dob = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(6);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
            __Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(6);
    }}
    __Vlvbound2 = VL_RAND_RESET_I(6);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(6);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port_async_read__pi8::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi8::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 53, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4311]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 54, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[903]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[904]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[905]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[906]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dia[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dia[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4312]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4313]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4314]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4315]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4316]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dob[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4317]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "dob[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4318]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4319]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4320]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4321]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[0][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4322]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[0][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4323]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[0][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4324]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4325]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4326]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4327]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[1][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4328]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[1][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4329]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[1][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4330]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4331]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[2][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4332]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[2][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4333]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[2][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4334]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[2][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4335]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[2][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4336]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4337]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[3][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4338]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[3][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4339]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[3][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4340]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[3][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4341]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[3][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4342]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4343]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[4][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4344]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[4][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4345]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[4][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4346]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[4][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4347]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[4][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4348]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4349]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[5][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4350]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[5][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4351]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[5][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4352]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[5][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4353]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[5][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4354]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4355]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[6][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4356]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[6][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4357]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[6][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4358]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[6][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4359]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[6][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4360]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4361]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[7][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4362]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[7][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4363]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[7][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4364]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[7][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4365]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[7][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4366]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4367]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[8][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4368]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[8][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4369]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[8][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4370]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[8][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4371]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi8", "ram[8][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4372]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 71, 9, "", "v_line/mem_simple_dual_port_async_read__pi8", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4373]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 70, 5, "", "v_line/mem_simple_dual_port_async_read__pi8", "block", "70-71");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4374]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 9, "", "v_branch/mem_simple_dual_port_async_read__pi8", "if", "77-78");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4375]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 10, "", "v_branch/mem_simple_dual_port_async_read__pi8", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4376]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 76, 5, "", "v_line/mem_simple_dual_port_async_read__pi8", "block", "76");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4377]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 82, 5, "", "v_line/mem_simple_dual_port_async_read__pi8", "block", "82-83");
}
