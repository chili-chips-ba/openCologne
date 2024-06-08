// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3___024unit.h"
#include "Vopl3__Syms.h"

//==========

VL_CTOR_IMP(Vopl3___024unit) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vopl3___024unit::__Vconfigure(Vopl3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
}

Vopl3___024unit::~Vopl3___024unit() {
}

// Coverage
void Vopl3___024unit::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void Vopl3___024unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vopl3___024unit::_ctor_var_reset\n"); );
}

void Vopl3___024unit::_configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vopl3___024unit::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
}
