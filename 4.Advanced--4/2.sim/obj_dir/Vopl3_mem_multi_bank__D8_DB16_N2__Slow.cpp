// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3_mem_multi_bank__D8_DB16_N2.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3_mem_multi_bank__D8_DB16_N2) {
    VL_CELL(__PVT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank, Vopl3_mem_simple_dual_port_async_read__pi6);
    VL_CELL(__PVT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank, Vopl3_mem_simple_dual_port_async_read__pi6);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3_mem_multi_bank__D8_DB16_N2::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3_mem_multi_bank__D8_DB16_N2::~Vopl3_mem_multi_bank__D8_DB16_N2() {
}

// Coverage
void Vopl3_mem_multi_bank__D8_DB16_N2::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[4107]);
    ++(vlSymsp->__Vcoverage[4108]);
    ++(vlSymsp->__Vcoverage[4109]);
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_initial__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    this->__Vcellout__bankb_sr__out = 0U;
    ++(vlSymsp->__Vcoverage[4110]);
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__21(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__21\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4105]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4086]);
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
    this->__PVT__dob_array[0U] = __PVT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    this->__PVT__dob_array[1U] = __PVT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4087]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4088]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
    if ((1U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4089]);
        this->__Vtogcov__dob_array[0U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (1U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((2U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4090]);
        this->__Vtogcov__dob_array[0U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (2U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((4U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4091]);
        this->__Vtogcov__dob_array[0U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (4U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((8U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4092]);
        this->__Vtogcov__dob_array[0U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (8U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x10U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4093]);
        this->__Vtogcov__dob_array[0U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x20U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4094]);
        this->__Vtogcov__dob_array[0U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x40U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4095]);
        this->__Vtogcov__dob_array[0U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x80U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4096]);
        this->__Vtogcov__dob_array[0U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((1U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4097]);
        this->__Vtogcov__dob_array[1U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (1U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((2U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4098]);
        this->__Vtogcov__dob_array[1U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (2U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((4U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4099]);
        this->__Vtogcov__dob_array[1U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (4U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((8U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4100]);
        this->__Vtogcov__dob_array[1U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (8U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x10U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4101]);
        this->__Vtogcov__dob_array[1U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x20U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4102]);
        this->__Vtogcov__dob_array[1U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x40U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4103]);
        this->__Vtogcov__dob_array[1U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x80U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4104]);
        this->__Vtogcov__dob_array[1U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    this->dob = this->__PVT__dob_array[(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__22(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__22\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4105]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4086]);
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
    this->__PVT__dob_array[0U] = __PVT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    this->__PVT__dob_array[1U] = __PVT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4087]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4088]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
    if ((1U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4089]);
        this->__Vtogcov__dob_array[0U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (1U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((2U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4090]);
        this->__Vtogcov__dob_array[0U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (2U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((4U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4091]);
        this->__Vtogcov__dob_array[0U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (4U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((8U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4092]);
        this->__Vtogcov__dob_array[0U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (8U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x10U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4093]);
        this->__Vtogcov__dob_array[0U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x20U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4094]);
        this->__Vtogcov__dob_array[0U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x40U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4095]);
        this->__Vtogcov__dob_array[0U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x80U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4096]);
        this->__Vtogcov__dob_array[0U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((1U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4097]);
        this->__Vtogcov__dob_array[1U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (1U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((2U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4098]);
        this->__Vtogcov__dob_array[1U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (2U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((4U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4099]);
        this->__Vtogcov__dob_array[1U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (4U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((8U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4100]);
        this->__Vtogcov__dob_array[1U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (8U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x10U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4101]);
        this->__Vtogcov__dob_array[1U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x20U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4102]);
        this->__Vtogcov__dob_array[1U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x40U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4103]);
        this->__Vtogcov__dob_array[1U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x80U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4104]);
        this->__Vtogcov__dob_array[1U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    this->dob = this->__PVT__dob_array[(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__23(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__23\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4105]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4086]);
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
    this->__PVT__dob_array[0U] = __PVT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    this->__PVT__dob_array[1U] = __PVT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4087]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4088]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
    if ((1U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4089]);
        this->__Vtogcov__dob_array[0U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (1U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((2U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4090]);
        this->__Vtogcov__dob_array[0U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (2U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((4U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4091]);
        this->__Vtogcov__dob_array[0U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (4U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((8U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4092]);
        this->__Vtogcov__dob_array[0U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (8U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x10U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4093]);
        this->__Vtogcov__dob_array[0U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x20U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4094]);
        this->__Vtogcov__dob_array[0U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x40U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4095]);
        this->__Vtogcov__dob_array[0U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x80U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4096]);
        this->__Vtogcov__dob_array[0U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((1U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4097]);
        this->__Vtogcov__dob_array[1U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (1U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((2U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4098]);
        this->__Vtogcov__dob_array[1U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (2U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((4U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4099]);
        this->__Vtogcov__dob_array[1U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (4U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((8U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4100]);
        this->__Vtogcov__dob_array[1U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (8U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x10U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4101]);
        this->__Vtogcov__dob_array[1U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x20U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4102]);
        this->__Vtogcov__dob_array[1U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x40U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4103]);
        this->__Vtogcov__dob_array[1U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x80U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4104]);
        this->__Vtogcov__dob_array[1U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    this->dob = this->__PVT__dob_array[(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__24(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_settle__TOP__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__24\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4105]);
        this->__Vtogcov__bankb_p = ((2U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (1U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if ((2U & ((IData)(this->__Vcellout__bankb_sr__out) 
               ^ this->__Vtogcov__bankb_p))) {
        ++(vlSymsp->__Vcoverage[4106]);
        this->__Vtogcov__bankb_p = ((1U & (IData)(this->__Vtogcov__bankb_p)) 
                                    | (2U & (IData)(this->__Vcellout__bankb_sr__out)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea) 
         ^ this->__Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[4086]);
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
    this->__PVT__dob_array[0U] = __PVT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    this->__PVT__dob_array[1U] = __PVT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank->__PVT__dob;
    if ((1U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4087]);
        this->__Vtogcov__wea_array = ((2U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (1U & (IData)(this->__PVT__wea_array)));
    }
    if ((2U & ((IData)(this->__PVT__wea_array) ^ this->__Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[4088]);
        this->__Vtogcov__wea_array = ((1U & (IData)(this->__Vtogcov__wea_array)) 
                                      | (2U & (IData)(this->__PVT__wea_array)));
    }
    if ((1U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4089]);
        this->__Vtogcov__dob_array[0U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (1U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((2U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4090]);
        this->__Vtogcov__dob_array[0U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (2U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((4U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4091]);
        this->__Vtogcov__dob_array[0U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (4U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((8U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[4092]);
        this->__Vtogcov__dob_array[0U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (8U & this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x10U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4093]);
        this->__Vtogcov__dob_array[0U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x20U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4094]);
        this->__Vtogcov__dob_array[0U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x40U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4095]);
        this->__Vtogcov__dob_array[0U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((0x80U & (this->__PVT__dob_array[0U] ^ this->__Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[4096]);
        this->__Vtogcov__dob_array[0U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [0U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [0U]));
    }
    if ((1U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4097]);
        this->__Vtogcov__dob_array[1U] = ((0xfeU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (1U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((2U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4098]);
        this->__Vtogcov__dob_array[1U] = ((0xfdU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (2U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((4U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4099]);
        this->__Vtogcov__dob_array[1U] = ((0xfbU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (4U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((8U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[4100]);
        this->__Vtogcov__dob_array[1U] = ((0xf7U & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (8U & this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x10U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4101]);
        this->__Vtogcov__dob_array[1U] = ((0xefU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x10U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x20U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4102]);
        this->__Vtogcov__dob_array[1U] = ((0xdfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x20U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x40U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4103]);
        this->__Vtogcov__dob_array[1U] = ((0xbfU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x40U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    if ((0x80U & (this->__PVT__dob_array[1U] ^ this->__Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[4104]);
        this->__Vtogcov__dob_array[1U] = ((0x7fU & 
                                           this->__Vtogcov__dob_array
                                           [1U]) | 
                                          (0x80U & 
                                           this->__PVT__dob_array
                                           [1U]));
    }
    this->dob = this->__PVT__dob_array[(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    wea = VL_RAND_RESET_I(1);
    reb = VL_RAND_RESET_I(1);
    banka = VL_RAND_RESET_I(1);
    addra = VL_RAND_RESET_I(5);
    bankb = VL_RAND_RESET_I(1);
    addrb = VL_RAND_RESET_I(5);
    dia = VL_RAND_RESET_I(8);
    dob = VL_RAND_RESET_I(8);
    __PVT__wea_array = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __PVT__dob_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vcellout__bankb_sr__out = VL_RAND_RESET_I(2);
    __Vtogcov__wea = VL_RAND_RESET_I(1);
    __Vtogcov__wea_array = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vtogcov__dob_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vtogcov__bankb_p = VL_RAND_RESET_I(2);
}

void Vopl3_mem_multi_bank__D8_DB16_N2::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+                  Vopl3_mem_multi_bank__D8_DB16_N2::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 52, 16, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "clk", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4086]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 53, 16, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "wea", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[792]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 54, 16, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "reb", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 55, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "banka[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addra[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addra[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addra[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addra[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 56, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addra[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[733]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 57, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "bankb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[879]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addrb[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[880]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addrb[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[881]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addrb[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[882]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addrb[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[883]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 58, 36, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "addrb[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 59, 33, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dia[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[872]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[873]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[874]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[875]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[868]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[869]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[870]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[871]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 60, 35, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4087]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 64, 27, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "wea_array[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4088]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 64, 27, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "wea_array[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4089]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4090]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4091]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4092]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4093]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4094]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4095]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4096]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[0][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4097]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4098]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4099]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4100]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4101]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4102]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4103]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4104]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 65, 28, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "dob_array[1][7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4105]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 66, 47, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "bankb_p[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4106]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 66, 47, "", "v_toggle/mem_multi_bank__D8_DB16_N2", "bankb_p[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4107]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 80, 9, "", "v_line/mem_multi_bank__D8_DB16_N2", "block", "79-80");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4108]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 80, 9, "", "v_line/mem_multi_bank__D8_DB16_N2", "block", "79-80");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4109]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/mem_multi_bank.sv", 119, 9, "", "v_line/mem_multi_bank__D8_DB16_N2", "block", "119");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 50, 16, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "clk", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[733]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 51, 33, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "in[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4105]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 52, 65, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "out[1][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4106]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 52, 65, ".bankb_sr", "v_toggle/pipeline_sr__D1_E2", "out[2][0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4110]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 52, 71, ".bankb_sr", "v_line/pipeline_sr__D1_E2", "block", "52");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4111]), first, "/home/user/openCologne/4.Advanced--4/2.sim/../1.hw/modules/misc/src/pipeline_sr.sv", 54, 5, ".bankb_sr", "v_line/pipeline_sr__D1_E2", "block", "54-56");
}
