// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_multi_bank__D1_DB12_O2_N2.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    this->__Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    ++(vlSymsp->__Vcoverage[4015]);
    ++(vlSymsp->__Vcoverage[4042]);
    ++(vlSymsp->__Vcoverage[4047]);
    ++(vlSymsp->__Vcoverage[4049]);
    ++(vlSymsp->__Vcoverage[4077]);
    ++(vlSymsp->__Vcoverage[4082]);
    ++(vlSymsp->__Vcoverage[4084]);
    if (this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[4045]);
    }
    if ((1U & (~ (IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[4046]);
    }
    if (this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[4080]);
    }
    if ((1U & (~ (IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[4081]);
    }
    if ((1U & (IData)(this->__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4040]);
    }
    if ((1U & (~ (IData)(this->__PVT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4041]);
    }
    if ((2U & (IData)(this->__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4075]);
    }
    if ((1U & (~ ((IData)(this->__PVT__wea_array) >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4076]);
    }
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((2U & (IData)(this->__PVT__wea_array))) {
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                     >> 0x13U));
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                >> 0xfU)))) {
            this->__Vdlyvval__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            this->__Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            this->__Vdlyvdim0__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                            >> 0xfU));
        }
    }
    if ((1U & (IData)(this->__PVT__wea_array))) {
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                     >> 0x13U));
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                >> 0xfU)))) {
            this->__Vdlyvval__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            this->__Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            this->__Vdlyvdim0__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                            >> 0xfU));
        }
    }
    this->__Vcellout__bankb_sr__out = (3U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                             << 1U));
    this->__Vcellout__bankb_sr__out = ((2U & (IData)(this->__Vcellout__bankb_sr__out)) 
                                       | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if (this->__Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[this->__Vdlyvdim0__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = this->__Vdlyvval__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (this->__Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[this->__Vdlyvdim0__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = this->__Vdlyvval__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4053]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[1U] = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4018]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[0U] = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
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
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                >> 3U) ^ this->__Vtogcov__banka))) {
        ++(vlSymsp->__Vcoverage[4001]);
        this->__Vtogcov__banka = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                        >> 3U));
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
    if ((1U & ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                >> 0x13U) ^ this->__Vtogcov__dia))) {
        ++(vlSymsp->__Vcoverage[2627]);
        this->__Vtogcov__dia = (1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                      >> 0x13U));
    }
    this->dob = this->__PVT__dob_array[(1U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                              >> 1U))];
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
    if (((IData)(this->dob) ^ this->__Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4002]);
        this->__Vtogcov__dob = this->dob;
    }
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    this->__Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    ++(vlSymsp->__Vcoverage[4015]);
    ++(vlSymsp->__Vcoverage[4042]);
    ++(vlSymsp->__Vcoverage[4047]);
    ++(vlSymsp->__Vcoverage[4049]);
    ++(vlSymsp->__Vcoverage[4077]);
    ++(vlSymsp->__Vcoverage[4082]);
    ++(vlSymsp->__Vcoverage[4084]);
    if (this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[4045]);
    }
    if ((1U & (~ (IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[4046]);
    }
    if (this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        ++(vlSymsp->__Vcoverage[4080]);
    }
    if ((1U & (~ (IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem)))) {
        ++(vlSymsp->__Vcoverage[4081]);
    }
    if ((1U & (IData)(this->__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4040]);
    }
    if ((1U & (~ (IData)(this->__PVT__wea_array)))) {
        ++(vlSymsp->__Vcoverage[4041]);
    }
    if ((2U & (IData)(this->__PVT__wea_array))) {
        ++(vlSymsp->__Vcoverage[4075]);
    }
    if ((1U & (~ ((IData)(this->__PVT__wea_array) >> 1U)))) {
        ++(vlSymsp->__Vcoverage[4076]);
    }
    this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((2U & (IData)(this->__PVT__wea_array))) {
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                >> 0x14U)))) {
            this->__Vdlyvval__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            this->__Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            this->__Vdlyvdim0__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                            >> 0x14U));
        }
    }
    if ((1U & (IData)(this->__PVT__wea_array))) {
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                >> 0x14U)))) {
            this->__Vdlyvval__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            this->__Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            this->__Vdlyvdim0__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                            >> 0x14U));
        }
    }
    this->__Vcellout__bankb_sr__out = (3U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                             << 1U));
    this->__Vcellout__bankb_sr__out = ((2U & (IData)(this->__Vcellout__bankb_sr__out)) 
                                       | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if (this->__Vdlyvset__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[this->__Vdlyvdim0__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = this->__Vdlyvval__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (this->__Vdlyvset__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[this->__Vdlyvdim0__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = this->__Vdlyvval__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4053]);
        this->bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[1U] = this->__PVT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2) 
         ^ this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4018]);
        this->bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    }
    this->__PVT__dob_array[0U] = this->__PVT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
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
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__8(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D1_DB12_O2_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__8\n"); );
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
    this->dob = this->__PVT__dob_array[(1U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                              >> 1U))];
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
    if (((IData)(this->dob) ^ this->__Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[4002]);
        this->__Vtogcov__dob = this->dob;
    }
}
