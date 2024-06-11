// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_multi_bank__D8_DB16_N2.h"
#include "Vopl3__Syms.h"

//==========

VL_INLINE_OPT void Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4132]);
    this->__Vcellout__bankb_sr__out = (7U & ((IData)(this->__Vcellout__bankb_sr__out) 
                                             << 1U));
    this->__Vcellout__bankb_sr__out = ((6U & (IData)(this->__Vcellout__bankb_sr__out)) 
                                       | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if ((4U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->bankb_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[4130]);
        this->bankb_sr__DOT____Vtogcov__out = ((3U 
                                                & (IData)(this->bankb_sr__DOT____Vtogcov__out)) 
                                               | (4U 
                                                  & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4125]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4126]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__13(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__13\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__wea = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea;
    }
    this->__PVT__wea_array = ((2U & (IData)(this->__PVT__wea_array)) 
                              | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea) 
                                 & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                       >> 0x10U))));
    this->__PVT__wea_array = ((1U & (IData)(this->__PVT__wea_array)) 
                              | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea) 
                                              << 1U) 
                                             & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                >> 0xfU))));
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4107]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4108]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__20(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__20\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__PVT__dob_array[0U] = __PVT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    this->__PVT__dob_array[1U] = __PVT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    if ((1U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4109]);
        this->__Vtogcov__dob_array[0U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (1U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((2U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4110]);
        this->__Vtogcov__dob_array[0U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (2U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((4U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4111]);
        this->__Vtogcov__dob_array[0U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (4U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((8U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4112]);
        this->__Vtogcov__dob_array[0U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (8U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x10U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4113]);
        this->__Vtogcov__dob_array[0U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x20U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4114]);
        this->__Vtogcov__dob_array[0U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x40U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4115]);
        this->__Vtogcov__dob_array[0U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x80U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4116]);
        this->__Vtogcov__dob_array[0U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((1U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4117]);
        this->__Vtogcov__dob_array[1U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (1U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((2U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4118]);
        this->__Vtogcov__dob_array[1U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (2U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((4U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4119]);
        this->__Vtogcov__dob_array[1U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (4U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((8U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4120]);
        this->__Vtogcov__dob_array[1U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (8U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x10U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4121]);
        this->__Vtogcov__dob_array[1U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x20U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4122]);
        this->__Vtogcov__dob_array[1U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x40U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4123]);
        this->__Vtogcov__dob_array[1U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x80U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4124]);
        this->__Vtogcov__dob_array[1U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    this->dob = this->__PVT__dob_array[(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__14(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__14\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__wea = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea;
    }
    this->__PVT__wea_array = ((2U & (IData)(this->__PVT__wea_array)) 
                              | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea) 
                                 & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                       >> 0x10U))));
    this->__PVT__wea_array = ((1U & (IData)(this->__PVT__wea_array)) 
                              | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea) 
                                              << 1U) 
                                             & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                >> 0xfU))));
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4107]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4108]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__15(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__15\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__wea = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea;
    }
    this->__PVT__wea_array = ((2U & (IData)(this->__PVT__wea_array)) 
                              | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea) 
                                 & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                       >> 0x10U))));
    this->__PVT__wea_array = ((1U & (IData)(this->__PVT__wea_array)) 
                              | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea) 
                                              << 1U) 
                                             & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                >> 0xfU))));
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4107]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4108]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
}

VL_INLINE_OPT void Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__16(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_sequent__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__16\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__wea = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea;
    }
    this->__PVT__wea_array = ((2U & (IData)(this->__PVT__wea_array)) 
                              | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea) 
                                 & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                       >> 0x10U))));
    this->__PVT__wea_array = ((1U & (IData)(this->__PVT__wea_array)) 
                              | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea) 
                                              << 1U) 
                                             & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                >> 0xfU))));
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4107]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4108]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
}
