// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_simple_dual_port_async_read__pi13.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_simple_dual_port_async_read__pi13) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_simple_dual_port_async_read__pi13::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_simple_dual_port_async_read__pi13::~Vopl3_mem_simple_dual_port_async_read__pi13() {
}

// Coverage
void Vopl3_mem_simple_dual_port_async_read__pi13::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_simple_dual_port_async_read__pi13::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4310]);
}

void Vopl3_mem_simple_dual_port_async_read__pi13::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__ram[0U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[1U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[2U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[3U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[4U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[5U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[6U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[7U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[8U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[9U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0xaU] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0xbU] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0xcU] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0xdU] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0xeU] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0xfU] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0x10U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    this->__PVT__ram[0x11U] = 0x1ffU;
    ++(vlSymsp->__Vcoverage[4305]);
    ++(vlSymsp->__Vcoverage[4306]);
}

void Vopl3_mem_simple_dual_port_async_read__pi13::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
               ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4133]);
        this->__Vtogcov__wea = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array));
    }
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

void Vopl3_mem_simple_dual_port_async_read__pi13::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    this->dob = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                  ? this->__PVT__ram[vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                  : 0U);
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
                >> 1U) ^ this->__Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4133]);
        this->__Vtogcov__wea = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
                                      >> 1U));
    }
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

void Vopl3_mem_simple_dual_port_async_read__pi13::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_ctor_var_reset\n"); );
    // Body
    clka = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(9);
    dob = VL_RAND_RESET_I(9);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __PVT__ram[__Vi0] = VL_RAND_RESET_I(9);
    }}
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(9);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(9);
    }}
    __Vlvbound2 = VL_RAND_RESET_I(9);
    __Vdlyvdim0__ram__v0 = 0;
    __Vdlyvval__ram__v0 = VL_RAND_RESET_I(9);
    __Vdlyvset__ram__v0 = 0;
}

void Vopl3_mem_simple_dual_port_async_read__pi13::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                    Vopl3_mem_simple_dual_port_async_read__pi13::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 53, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4133]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 54, 16, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2011]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2012]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2013]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2014]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2015]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 55, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 56, 36, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1956]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1957]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1958]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1959]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1960]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1961]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1962]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1963]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1964]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 57, 33, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dia[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4134]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4135]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4136]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4137]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4138]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4139]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4140]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4141]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4142]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 58, 35, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "dob[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4143]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4144]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4145]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4146]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4147]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4148]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4149]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4150]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4151]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[0][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4152]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4153]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4154]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4155]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4156]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4157]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4158]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4159]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4160]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[1][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4161]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4162]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4163]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4164]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4165]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4166]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4167]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4168]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4169]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[2][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4170]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4171]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4172]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4173]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4174]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4175]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4176]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4177]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4178]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[3][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4179]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4180]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4181]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4182]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4183]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4184]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4185]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4186]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4187]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[4][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4188]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4189]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4190]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4191]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4192]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4193]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4194]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4195]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4196]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[5][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4197]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4198]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4199]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4200]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4201]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4202]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4203]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4204]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4205]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[6][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4206]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4207]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4208]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4209]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4210]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4211]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4212]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4213]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4214]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[7][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4215]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4216]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4217]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4218]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4219]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4220]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4221]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4222]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4223]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[8][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4224]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4225]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4226]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4227]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4228]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4229]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4230]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4231]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4232]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[9][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4233]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4234]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4235]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4236]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4237]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4238]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4239]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4240]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4241]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[10][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4242]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4243]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4244]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4245]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4246]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4247]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4248]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4249]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4250]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[11][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4251]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4252]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4253]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4254]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4255]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4256]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4257]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4258]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4259]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[12][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4260]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4261]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4262]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4263]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4264]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4265]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4266]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4267]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4268]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[13][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4269]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4270]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4271]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4272]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4273]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4274]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4275]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4276]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4277]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[14][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4278]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4279]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4280]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4281]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4282]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4283]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4284]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4285]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4286]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[15][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4287]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4288]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4289]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4290]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4291]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4292]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4293]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4294]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4295]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[16][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4296]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4297]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4298]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4299]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4300]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4301]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4302]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4303]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4304]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 68, 28, "", "v_toggle/mem_simple_dual_port_async_read__pi13", "ram[17][8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4305]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 71, 9, "", "v_line/mem_simple_dual_port_async_read__pi13", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4306]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 70, 5, "", "v_line/mem_simple_dual_port_async_read__pi13", "block", "70-71");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4307]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 9, "", "v_branch/mem_simple_dual_port_async_read__pi13", "if", "77-78");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4308]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 77, 10, "", "v_branch/mem_simple_dual_port_async_read__pi13", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4309]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 76, 5, "", "v_line/mem_simple_dual_port_async_read__pi13", "block", "76");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4310]), first, "/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port_async_read.sv", 82, 5, "", "v_line/mem_simple_dual_port_async_read__pi13", "block", "82-83");
}
