// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_multi_bank__D1_DB12_O2_N2.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_multi_bank__D1_DB12_O2_N2) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_multi_bank__D1_DB12_O2_N2::~Vopl3_mem_multi_bank__D1_DB12_O2_N2() {
}

// Coverage
void Vopl3_mem_multi_bank__D1_DB12_O2_N2::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4009]);
    ++(vlSymsp->__Vcoverage[4010]);
    ++(vlSymsp->__Vcoverage[4011]);
    ++(vlSymsp->__Vcoverage[4012]);
    ++(vlSymsp->__Vcoverage[4013]);
    ++(vlSymsp->__Vcoverage[4043]);
    ++(vlSymsp->__Vcoverage[4050]);
    ++(vlSymsp->__Vcoverage[4078]);
    ++(vlSymsp->__Vcoverage[4085]);
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 = 0U;
    ++(vlSymsp->__Vcoverage[4048]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 = 0U;
    ++(vlSymsp->__Vcoverage[4083]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[9U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xaU] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xbU] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xcU] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xdU] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xeU] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xfU] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0x10U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0x11U] = 0U;
    ++(vlSymsp->__Vcoverage[4038]);
    ++(vlSymsp->__Vcoverage[4039]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[1U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[2U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[3U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[4U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[5U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[6U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[7U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[8U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[9U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xaU] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xbU] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xcU] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xdU] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xeU] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0xfU] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0x10U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[0x11U] = 0U;
    ++(vlSymsp->__Vcoverage[4073]);
    ++(vlSymsp->__Vcoverage[4074]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 = 0U;
    ++(vlSymsp->__Vcoverage[4044]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 = 0U;
    ++(vlSymsp->__Vcoverage[4079]);
    this->__Vcellout__bankb_sr__out = 0U;
    ++(vlSymsp->__Vcoverage[4014]);
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__11(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__11\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                >> 3U) ^ this->__Vtogcov__banka))) {
        ++(vlSymsp->__Vcoverage[4001]);
        this->__Vtogcov__banka = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                        >> 3U));
    }
    if ((1U & ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                >> 0x13U) ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[2627]);
        this->__Vtogcov__dia = (1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                      >> 0x13U));
    }
    this->__PVT__wea_array = ((2U & (IData)(this->__PVT__wea_array)) 
                              | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                                        >> 3U) & (~ 
                                                  ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                                   >> 3U)))));
    this->__PVT__wea_array = ((1U & (IData)(this->__PVT__wea_array)) 
                              | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                                        & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
                                       >> 2U)));
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4018]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[0U] = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4053]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[1U] = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0U])) {
        ++(vlSymsp->__Vcoverage[4020]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [1U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [1U])) {
        ++(vlSymsp->__Vcoverage[4021]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [1U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [2U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [2U])) {
        ++(vlSymsp->__Vcoverage[4022]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [2U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [3U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [3U])) {
        ++(vlSymsp->__Vcoverage[4023]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [3U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [4U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [4U])) {
        ++(vlSymsp->__Vcoverage[4024]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [4U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [5U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [5U])) {
        ++(vlSymsp->__Vcoverage[4025]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [5U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [6U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [6U])) {
        ++(vlSymsp->__Vcoverage[4026]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [6U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [7U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [7U])) {
        ++(vlSymsp->__Vcoverage[4027]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [7U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [8U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [8U])) {
        ++(vlSymsp->__Vcoverage[4028]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [8U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [9U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [9U])) {
        ++(vlSymsp->__Vcoverage[4029]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [9U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xaU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xaU])) {
        ++(vlSymsp->__Vcoverage[4030]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xaU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xaU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xbU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xbU])) {
        ++(vlSymsp->__Vcoverage[4031]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xbU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xbU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xcU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xcU])) {
        ++(vlSymsp->__Vcoverage[4032]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xcU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xcU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xdU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xdU])) {
        ++(vlSymsp->__Vcoverage[4033]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xdU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xdU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xeU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xeU])) {
        ++(vlSymsp->__Vcoverage[4034]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xeU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xeU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xfU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xfU])) {
        ++(vlSymsp->__Vcoverage[4035]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xfU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xfU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x10U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x10U])) {
        ++(vlSymsp->__Vcoverage[4036]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x10U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x10U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x11U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x11U])) {
        ++(vlSymsp->__Vcoverage[4037]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x11U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x11U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0U])) {
        ++(vlSymsp->__Vcoverage[4055]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [1U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [1U])) {
        ++(vlSymsp->__Vcoverage[4056]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [1U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [2U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [2U])) {
        ++(vlSymsp->__Vcoverage[4057]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [2U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [3U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [3U])) {
        ++(vlSymsp->__Vcoverage[4058]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [3U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [4U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [4U])) {
        ++(vlSymsp->__Vcoverage[4059]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [4U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [5U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [5U])) {
        ++(vlSymsp->__Vcoverage[4060]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [5U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [6U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [6U])) {
        ++(vlSymsp->__Vcoverage[4061]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [6U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [7U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [7U])) {
        ++(vlSymsp->__Vcoverage[4062]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [7U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [8U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [8U])) {
        ++(vlSymsp->__Vcoverage[4063]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [8U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [9U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [9U])) {
        ++(vlSymsp->__Vcoverage[4064]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [9U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xaU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xaU])) {
        ++(vlSymsp->__Vcoverage[4065]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xaU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xaU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xbU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xbU])) {
        ++(vlSymsp->__Vcoverage[4066]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xbU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xbU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xcU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xcU])) {
        ++(vlSymsp->__Vcoverage[4067]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xcU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xcU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xdU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xdU])) {
        ++(vlSymsp->__Vcoverage[4068]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xdU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xdU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xeU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xeU])) {
        ++(vlSymsp->__Vcoverage[4069]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xeU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xeU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xfU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xfU])) {
        ++(vlSymsp->__Vcoverage[4070]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xfU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xfU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x10U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x10U])) {
        ++(vlSymsp->__Vcoverage[4071]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x10U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x10U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x11U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x11U])) {
        ++(vlSymsp->__Vcoverage[4072]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x11U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x11U];
    }
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4007]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4008]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4016]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(this->__PVT__wea_array));
    }
    if ((1U & (((IData)(this->__PVT__wea_array) >> 1U) 
               ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4051]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(this->__PVT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4003]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4004]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
    if ((this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
         [0U])) {
        ++(vlSymsp->__Vcoverage[4005]);
        this->__Vtogcov__dob_array[0U] = this->__PVT__dob_array
            [0U];
    }
    if ((this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
         [1U])) {
        ++(vlSymsp->__Vcoverage[4006]);
        this->__Vtogcov__dob_array[1U] = this->__PVT__dob_array
            [1U];
    }
    this->dob = this->__PVT__dob_array[(1U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                              >> 1U))];
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) {
        ++(vlSymsp->__Vcoverage[4019]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) {
        ++(vlSymsp->__Vcoverage[4054]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4017]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4052]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(this->dob) ^ this->__Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4002]);
        this->__Vtogcov__dob = this->dob;
    }
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__12(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__12\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                >> 4U) ^ this->__Vtogcov__banka))) {
        ++(vlSymsp->__Vcoverage[4001]);
        this->__Vtogcov__banka = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                        >> 4U));
    }
    this->__PVT__wea_array = ((2U & (IData)(this->__PVT__wea_array)) 
                              | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                                        >> 4U) & (~ 
                                                  ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                                   >> 4U)))));
    this->__PVT__wea_array = ((1U & (IData)(this->__PVT__wea_array)) 
                              | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                                        & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
                                       >> 3U)));
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4018]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[0U] = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4053]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[1U] = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0U])) {
        ++(vlSymsp->__Vcoverage[4020]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [1U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [1U])) {
        ++(vlSymsp->__Vcoverage[4021]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [1U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [2U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [2U])) {
        ++(vlSymsp->__Vcoverage[4022]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [2U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [3U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [3U])) {
        ++(vlSymsp->__Vcoverage[4023]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [3U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [4U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [4U])) {
        ++(vlSymsp->__Vcoverage[4024]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [4U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [5U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [5U])) {
        ++(vlSymsp->__Vcoverage[4025]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [5U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [6U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [6U])) {
        ++(vlSymsp->__Vcoverage[4026]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [6U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [7U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [7U])) {
        ++(vlSymsp->__Vcoverage[4027]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [7U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [8U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [8U])) {
        ++(vlSymsp->__Vcoverage[4028]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [8U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [9U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [9U])) {
        ++(vlSymsp->__Vcoverage[4029]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [9U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xaU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xaU])) {
        ++(vlSymsp->__Vcoverage[4030]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xaU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xaU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xbU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xbU])) {
        ++(vlSymsp->__Vcoverage[4031]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xbU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xbU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xcU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xcU])) {
        ++(vlSymsp->__Vcoverage[4032]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xcU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xcU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xdU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xdU])) {
        ++(vlSymsp->__Vcoverage[4033]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xdU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xdU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xeU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xeU])) {
        ++(vlSymsp->__Vcoverage[4034]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xeU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xeU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xfU] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xfU])) {
        ++(vlSymsp->__Vcoverage[4035]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xfU] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xfU];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x10U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x10U])) {
        ++(vlSymsp->__Vcoverage[4036]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x10U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x10U];
    }
    if ((this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x11U] ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x11U])) {
        ++(vlSymsp->__Vcoverage[4037]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x11U] 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x11U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0U])) {
        ++(vlSymsp->__Vcoverage[4055]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [1U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [1U])) {
        ++(vlSymsp->__Vcoverage[4056]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [1U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [2U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [2U])) {
        ++(vlSymsp->__Vcoverage[4057]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [2U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [3U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [3U])) {
        ++(vlSymsp->__Vcoverage[4058]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [3U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [4U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [4U])) {
        ++(vlSymsp->__Vcoverage[4059]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [4U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [5U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [5U])) {
        ++(vlSymsp->__Vcoverage[4060]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [5U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [6U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [6U])) {
        ++(vlSymsp->__Vcoverage[4061]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [6U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [7U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [7U])) {
        ++(vlSymsp->__Vcoverage[4062]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [7U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [8U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [8U])) {
        ++(vlSymsp->__Vcoverage[4063]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [8U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [9U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [9U])) {
        ++(vlSymsp->__Vcoverage[4064]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [9U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xaU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xaU])) {
        ++(vlSymsp->__Vcoverage[4065]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xaU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xaU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xbU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xbU])) {
        ++(vlSymsp->__Vcoverage[4066]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xbU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xbU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xcU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xcU])) {
        ++(vlSymsp->__Vcoverage[4067]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xcU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xcU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xdU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xdU])) {
        ++(vlSymsp->__Vcoverage[4068]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xdU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xdU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xeU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xeU])) {
        ++(vlSymsp->__Vcoverage[4069]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xeU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xeU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0xfU] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0xfU])) {
        ++(vlSymsp->__Vcoverage[4070]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0xfU] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0xfU];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x10U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x10U])) {
        ++(vlSymsp->__Vcoverage[4071]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x10U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x10U];
    }
    if ((this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0x11U] ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0x11U])) {
        ++(vlSymsp->__Vcoverage[4072]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0x11U] 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0x11U];
    }
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4007]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4008]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4016]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(this->__PVT__wea_array));
    }
    if ((1U & (((IData)(this->__PVT__wea_array) >> 1U) 
               ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[4051]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(this->__PVT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4003]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4004]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
    if ((this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
         [0U])) {
        ++(vlSymsp->__Vcoverage[4005]);
        this->__Vtogcov__dob_array[0U] = this->__PVT__dob_array
            [0U];
    }
    if ((this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
         [1U])) {
        ++(vlSymsp->__Vcoverage[4006]);
        this->__Vtogcov__dob_array[1U] = this->__PVT__dob_array
            [1U];
    }
    this->dob = this->__PVT__dob_array[(1U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                              >> 1U))];
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) {
        ++(vlSymsp->__Vcoverage[4019]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) {
        ++(vlSymsp->__Vcoverage[4054]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4017]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[4052]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(this->dob) ^ this->__Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4002]);
        this->__Vtogcov__dob = this->dob;
    }
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    reb = VL_RAND_RESET_I(1);
    banka = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    bankb = VL_RAND_RESET_I(1);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(1);
    dob = VL_RAND_RESET_I(1);
    __PVT__wea_array = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __PVT__dob_array[__Vi0] = VL_RAND_RESET_I(1);
    }}
    __Vcellout__bankb_sr__out = VL_RAND_RESET_I(2);
    __Vtogcov__banka = VL_RAND_RESET_I(1);
    __Vtogcov__dia = VL_RAND_RESET_I(1);
    __Vtogcov__dob = VL_RAND_RESET_I(1);
    __Vtogcov__wea_array = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vtogcov__dob_array[__Vi0] = VL_RAND_RESET_I(1);
    }}
    __Vtogcov__bankb_p = VL_RAND_RESET_I(2);
    __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem = VL_RAND_RESET_I(1);
    __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem = VL_RAND_RESET_I(1);
    __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vi0] = VL_RAND_RESET_I(1);
    }}
    bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea = VL_RAND_RESET_I(1);
    bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb = VL_RAND_RESET_I(1);
    bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob = VL_RAND_RESET_I(1);
    bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(1);
    }}
    __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 = VL_RAND_RESET_I(1);
    __PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 = VL_RAND_RESET_I(1);
    bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 = VL_RAND_RESET_I(1);
    __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vi0] = VL_RAND_RESET_I(1);
    }}
    bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea = VL_RAND_RESET_I(1);
    bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb = VL_RAND_RESET_I(1);
    bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob = VL_RAND_RESET_I(1);
    bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<18; ++__Vi0) {
            bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[__Vi0] = VL_RAND_RESET_I(1);
    }}
    __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 = VL_RAND_RESET_I(1);
    __PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 = VL_RAND_RESET_I(1);
    bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 = VL_RAND_RESET_I(1);
    __Vdlyvdim0__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0;
    __Vdlyvval__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0;
    __Vdlyvdim0__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0;
    __Vdlyvval__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0;
}

void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 52, 16, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "clk", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2526]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 53, 16, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[792]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 54, 16, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "reb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4001]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 55, 33, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "banka[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2846]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2847]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2848]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2849]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2850]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[733]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 57, 33, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "bankb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2627]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4002]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4003]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 64, 27, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "wea_array[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4004]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 64, 27, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "wea_array[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4005]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "dob_array[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4006]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "dob_array[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4007]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 66, 47, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "bankb_p[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4008]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 66, 47, "", "v_toggle/mem_multi_bank__D1_DB12_O2_N2", "bankb_p[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4009]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 80, 9, "", "v_line/mem_multi_bank__D1_DB12_O2_N2", "block", "79-80");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4010]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 98, 13, "", "v_line/mem_multi_bank__D1_DB12_O2_N2", "block", "79,98");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4011]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 80, 9, "", "v_line/mem_multi_bank__D1_DB12_O2_N2", "block", "79-80");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4012]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 98, 13, "", "v_line/mem_multi_bank__D1_DB12_O2_N2", "block", "79,98");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4013]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 121, 9, "", "v_line/mem_multi_bank__D1_DB12_O2_N2", "block", "121");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 50, 16, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "clk", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[733]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 51, 33, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "in[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4007]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 52, 65, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "out[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4008]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 52, 65, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "out[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4014]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 52, 71, ".bankb_sr", "v_line/pipeline_sr__D1_E2", "block", "52");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4015]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 54, 5, ".bankb_sr", "v_line/pipeline_sr__D1_E2", "block", "54-56");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 50, 16, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 51, 16, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "clkb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4016]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 52, 16, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4017]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 53, 16, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "reb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2846]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2847]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2848]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2849]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2850]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2627]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4018]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4019]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "dob_p0[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4020]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4021]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4022]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4023]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4024]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4025]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4026]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4027]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4028]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4029]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[9][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4030]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[10][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4031]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[11][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4032]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[12][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4033]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[13][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4034]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[14][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4035]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[15][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4036]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[16][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4037]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[0].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[17][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4038]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 72, 9, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "72-73");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4039]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 71, 5, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4040]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 9, ".bankgen[0].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "if", "78-79");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4041]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 10, ".bankgen[0].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4042]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 77, 5, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "77");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4043]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 81, 5, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "81");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4044]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 85, 41, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "85");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4045]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 13, ".bankgen[0].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "if", "88-89");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4046]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 14, ".bankgen[0].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4047]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 87, 9, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "87");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4048]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 94, 45, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "94");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4049]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 96, 13, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "96-97");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4050]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 99, 13, ".bankgen[0].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "99");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 50, 16, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "clka", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 51, 16, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "clkb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4051]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 52, 16, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4052]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 53, 16, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "reb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2846]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2847]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2848]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2849]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2850]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 54, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[736]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[737]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[738]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[739]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[740]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 55, 36, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2627]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 56, 33, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4053]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 57, 35, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4054]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 59, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "dob_p0[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4055]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4056]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4057]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4058]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[3][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4059]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[4][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4060]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[5][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4061]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[6][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4062]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[7][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4063]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[8][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4064]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[9][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4065]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[10][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4066]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[11][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4067]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[12][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4068]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[13][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4069]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[14][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4070]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[15][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4071]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[16][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4072]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 69, 28, ".bankgen[1].genblk2.mem_bank", "v_toggle/mem_simple_dual_port__pi15", "ram[17][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4073]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 72, 9, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "72-73");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4074]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 71, 5, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "71-72");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4075]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 9, ".bankgen[1].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "if", "78-79");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4076]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 78, 10, ".bankgen[1].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4077]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 77, 5, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "77");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4078]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 81, 5, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "81");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4079]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 85, 41, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "85");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4080]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 13, ".bankgen[1].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "if", "88-89");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4081]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 88, 14, ".bankgen[1].genblk2.mem_bank", "v_branch/mem_simple_dual_port__pi15", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4082]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 87, 9, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "87");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4083]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 94, 45, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "94");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4084]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 96, 13, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "96-97");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4085]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_simple_dual_port.sv", 99, 13, ".bankgen[1].genblk2.mem_bank", "v_line/mem_simple_dual_port__pi15", "block", "99");
}
