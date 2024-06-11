// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3.h"
#include "Vopl3__Syms.h"

void Vopl3::_settle__TOP__17(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_settle__TOP__17\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[459]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffeffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[460]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffeffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[461]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffdffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[462]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffbffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[463]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffff7ffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[464]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffefffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[465]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffdfffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[466]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffbfffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                      ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[467]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xff7fffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[468]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfeffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[469]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfdffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x4000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[470]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfbffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x4000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x8000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                       ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[471]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xf7ffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x8000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x10000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[472]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xefffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x10000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x20000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[473]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xdfffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x20000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x40000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[474]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xbfffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x40000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x80000000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                        ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[475]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0x7fffffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x80000000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[476]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffffeU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[477]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffffdU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[478]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffffbU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[479]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xfffffff7U & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[480]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xffffffefU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[481]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xffffffdfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[482]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xffffffbfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]))) {
        ++(vlSymsp->__Vcoverage[483]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U] 
            = ((0xffffff7fU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[1U]) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__self[1U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[484]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffffeU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[485]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffffdU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[486]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffffbU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[487]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffff7U & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[488]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffffefU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[489]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffffdfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[490]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffffbfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[491]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffff7fU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[492]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffeffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[493]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffdffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[494]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffffbffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[495]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffff7ffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[496]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffefffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[497]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffdfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[498]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffffbfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[499]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xffff7fffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[500]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffeffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[501]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffdffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[502]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfffbffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]))) {
        ++(vlSymsp->__Vcoverage[503]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U] 
            = ((0xfff7ffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__self[0U]) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__self[0U]));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p3) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__prev_final_phase_msb_p3)) {
        ++(vlSymsp->__Vcoverage[2634]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__prev_final_phase_msb_p3 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p3;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p3) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p3)) {
        ++(vlSymsp->__Vcoverage[2639]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p3 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p3;
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__sample_clk_en_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2972]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__sample_clk_en_sr__DOT____Vtogcov__out 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__sample_clk_en_sr__DOT____Vtogcov__out)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p))) {
        ++(vlSymsp->__Vcoverage[2544]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p))) {
        ++(vlSymsp->__Vcoverage[2545]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p))) {
        ++(vlSymsp->__Vcoverage[2546]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p))) {
        ++(vlSymsp->__Vcoverage[2547]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p))) {
        ++(vlSymsp->__Vcoverage[2548]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p))) {
        ++(vlSymsp->__Vcoverage[2549]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if (((IData)(vlTOPp->opl3__DOT__sample_clk_en) 
         ^ vlTOPp->opl3__DOT____Vtogcov__sample_clk_en)) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->opl3__DOT____Vtogcov__sample_clk_en 
            = vlTOPp->opl3__DOT__sample_clk_en;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state 
        = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
            ? (IData)(vlTOPp->opl3__DOT__sample_clk_en)
            : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state));
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__key_on_pulse_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2975]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__key_on_pulse_sr__DOT____Vtogcov__out 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__key_on_pulse_sr__DOT____Vtogcov__out)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2538]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2539]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2540]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2541]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2542]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2543]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array)) 
           | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                     >> 2U) & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                  >> 2U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array)) 
           | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
                    >> 1U)));
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2886]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2887]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2888]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2889]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2890]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2891]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2892]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2893]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2894]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2895]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2896]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2897]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7ff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2898]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2899]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2900]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7fbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2901]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7f7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2902]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7effffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2903]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7dffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2904]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x7bffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2905]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x77ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2906]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x6fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2907]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x5fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3))) {
        ++(vlSymsp->__Vcoverage[2908]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3 
            = ((0x3fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                     ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x1ffffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                     ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x2ffffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x10000U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3feffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x100U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3fdffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x200U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3fbffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x400U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3f7ffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x800U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                    ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3efffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x1000U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                    ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3dfffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x2000U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                    ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3bfffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x4000U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                    ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x37fffU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x8000U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((1U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3fffeU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (1U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((2U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3fffdU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (2U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((4U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3fffbU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (4U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((8U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3fff7U & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (8U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3ffefU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x10U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3ffdfU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x20U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3ffbfU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x40U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__opl3_reg_wr ^ vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr = 
            ((0x3ff7fU & vlTOPp->opl3__DOT____Vtogcov__opl3_reg_wr) 
             | (0x80U & vlTOPp->opl3__DOT__opl3_reg_wr));
    }
    vlTOPp->opl3__DOT__channels__DOT____Vcellinp__ch_abcd_cnt_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0xc0U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0xc8U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0x20U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0x35U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0x40U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0x55U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0x60U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0x75U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0x80U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0x95U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ws_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0xe0U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0xf5U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fnum_low_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0xa0U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0xa8U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__kon_block_fnum_high_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0xb0U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0xb8U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt0_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0xc0U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0xc8U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt1_mem__wea 
        = (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
            & (0xc0U <= (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                  >> 8U)))) & (0xc8U 
                                               >= (0xffU 
                                                   & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                      >> 8U))));
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = (1U & (~ (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2)));
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U & (~ (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2)))) {
            ++(vlSymsp->__Vcoverage[2179]);
        }
    }
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if (vlTOPp->opl3__DOT__reset_sync__DOT__r2) {
            ++(vlSymsp->__Vcoverage[2178]);
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2) 
         ^ vlTOPp->opl3__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->opl3__DOT____Vtogcov__reset = vlTOPp->opl3__DOT__reset_sync__DOT__r2;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state;
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if (vlTOPp->opl3__DOT__reset_sync__DOT__r2) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state = 1U;
        }
    } else {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U == (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state = 0U;
                }
            }
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
               ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
               ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
               ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
               ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
                  ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
                  ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
                  ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter) 
                  ^ vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2872]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2873]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2874]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2875]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2876]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2877]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2878]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2879]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2880]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2881]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2882]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2883]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2))) {
        ++(vlSymsp->__Vcoverage[2884]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2)));
    }
    if (((IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r1) 
         ^ vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r1)) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r1 
            = vlTOPp->opl3__DOT__reset_sync__DOT__r1;
    }
    if (((IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r0) 
         ^ vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r0)) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->opl3__DOT__reset_sync__DOT____Vtogcov__r0 
            = vlTOPp->opl3__DOT__reset_sync__DOT__r0;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank.__PVT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank.__PVT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array[0U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank.__PVT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array[1U] 
        = vlSymsp->TOP__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank.__PVT__genblk1__DOT__dob_p1;
    if (((IData)(vlTOPp->sample_valid) ^ vlTOPp->opl3__DOT____Vtogcov__sample_valid)) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->opl3__DOT____Vtogcov__sample_valid 
            = vlTOPp->sample_valid;
    }
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1) 
         ^ vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p1)) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->opl3__DOT__host_if__DOT____Vtogcov__wr_p1 
            = vlTOPp->opl3__DOT__host_if__DOT__wr_p1;
    }
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1) 
           & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p2)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2107]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2108]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2109]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2110]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2111]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2112]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2113]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2114]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)));
    }
    if ((1U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xfeU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((2U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xfdU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (2U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((4U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xfbU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (4U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((8U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xf7U 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (8U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x10U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xefU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x10U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x20U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xdfU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x20U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x40U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0xbfU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x40U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((0x80U & ((IData)(vlTOPp->dout) ^ vlTOPp->opl3__DOT____Vtogcov__dout))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->opl3__DOT____Vtogcov__dout = ((0x7fU 
                                               & (IData)(vlTOPp->opl3__DOT____Vtogcov__dout)) 
                                              | (0x80U 
                                                 & (IData)(vlTOPp->dout)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3feU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3fdU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3fbU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
               ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3f7U & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3efU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3dfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x3bfU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                  ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x37fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                   ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x2ffU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data) 
                   ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data 
            = ((0x1ffU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2168]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2169]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2170]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2171]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2172]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2173]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self))) {
        ++(vlSymsp->__Vcoverage[2174]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)));
    }
    if ((1U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffffeU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (1U 
                                                     & vlTOPp->sample_l));
    }
    if ((2U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffffdU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (2U 
                                                     & vlTOPp->sample_l));
    }
    if ((4U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffffbU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (4U 
                                                     & vlTOPp->sample_l));
    }
    if ((8U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffff7U 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (8U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x10U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffffefU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x10U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x20U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffffdfU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x20U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x40U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffffbfU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x40U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x80U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffff7fU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x80U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x100U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffeffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x100U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x200U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffdffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x200U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x400U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfffbffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x400U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x800U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfff7ffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x800U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x1000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffefffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x1000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x2000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffdfffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x2000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x4000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xffbfffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x4000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x8000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xff7fffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x8000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x10000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfeffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x10000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x20000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfdffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x20000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x40000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xfbffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x40000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x80000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xf7ffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x80000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x100000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xefffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x100000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x200000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xdfffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x200000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x400000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0xbfffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x400000U 
                                                     & vlTOPp->sample_l));
    }
    if ((0x800000U & (vlTOPp->sample_l ^ vlTOPp->opl3__DOT____Vtogcov__sample_l))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->opl3__DOT____Vtogcov__sample_l = ((0x7fffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_l) 
                                                  | (0x800000U 
                                                     & vlTOPp->sample_l));
    }
    if ((1U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffffeU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (1U 
                                                     & vlTOPp->sample_r));
    }
    if ((2U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffffdU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (2U 
                                                     & vlTOPp->sample_r));
    }
    if ((4U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffffbU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (4U 
                                                     & vlTOPp->sample_r));
    }
    if ((8U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffff7U 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (8U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x10U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffffefU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x10U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x20U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffffdfU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x20U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x40U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffffbfU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x40U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x80U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffff7fU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x80U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x100U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffeffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x100U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x200U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffdffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x200U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x400U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfffbffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x400U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x800U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfff7ffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x800U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x1000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffefffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x1000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x2000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffdfffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x2000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x4000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xffbfffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x4000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x8000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xff7fffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x8000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x10000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfeffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x10000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x20000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfdffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x20000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x40000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xfbffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x40000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x80000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xf7ffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x80000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x100000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xefffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x100000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x200000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xdfffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x200000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x400000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0xbfffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x400000U 
                                                     & vlTOPp->sample_r));
    }
    if ((0x800000U & (vlTOPp->sample_r ^ vlTOPp->opl3__DOT____Vtogcov__sample_r))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->opl3__DOT____Vtogcov__sample_r = ((0x7fffffU 
                                                   & vlTOPp->opl3__DOT____Vtogcov__sample_r) 
                                                  | (0x800000U 
                                                     & vlTOPp->sample_r));
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array
         [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__dob_array
         [0U])) {
        ++(vlSymsp->__Vcoverage[1252]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array
            [0U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array
         [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__dob_array
         [1U])) {
        ++(vlSymsp->__Vcoverage[1253]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array
            [1U];
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3000]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3001]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3002]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3003]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3004]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3005]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3006]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3007]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3008]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3009]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3010]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3011]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3012]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3013]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3014]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3015]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3016]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3017]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3018]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3019]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3020]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3021]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3022]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3023]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3024]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3025]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3026]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3027]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3028]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3029]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3030]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3031]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3032]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3033]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3034]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3035]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3036]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3037]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3038]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3039]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
        [(1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2334]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7ffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2335]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7ffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2336]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7ffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[2337]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7ff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2338]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7fefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2339]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7fdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2340]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7fbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[2341]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7f7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[2342]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7effU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[2343]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7dffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[2344]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x7bffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[2345]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x77ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[2346]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x6fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[2347]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x5fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[2348]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2349]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7ffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2350]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7ffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2351]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7ffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[2352]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7ff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2353]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7fefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2354]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7fdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2355]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7fbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[2356]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7f7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[2357]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7effU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[2358]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7dffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[2359]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x7bffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[2360]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x77ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[2361]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x6fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[2362]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x5fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[2363]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1117]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1118]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1119]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1120]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[0U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1121]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1122]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1123]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1124]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[1U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2730]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2731]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2732]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2733]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2734]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2735]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2736]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2737]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2738]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2739]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2740]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2741]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6))) {
        ++(vlSymsp->__Vcoverage[2742]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6 
        = (0x1fffU & (VL_GTS_III(1,32,32, 0U, VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)))
                       ? (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6))
                       : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p6)
            ? (0x1fffU & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)))
            : 0U);
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[2331]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea) 
              & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out) 
                    >> 1U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)) 
           | (0xfffffffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea) 
                              << 1U) & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out))));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[1641]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[1667]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1629]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1630]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[3837]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[3838]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1))) {
        ++(vlSymsp->__Vcoverage[1890]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1))) {
        ++(vlSymsp->__Vcoverage[1891]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1))) {
        ++(vlSymsp->__Vcoverage[1892]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1)
                  ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1)
                  : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1) 
                     >> 1U)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2504]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2505]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2506]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2507]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2508]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1))) {
        ++(vlSymsp->__Vcoverage[2509]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1354]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1355]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1356]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1357]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1358]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1359]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1360]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1361]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1362]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1363]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1364]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1365]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1366]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1367]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1368]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1369]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1370]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1371]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1372]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2))) {
        ++(vlSymsp->__Vcoverage[1373]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_on_pulse) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__bd_on_pulse)) {
        ++(vlSymsp->__Vcoverage[1420]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__bd_on_pulse 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_on_pulse;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_on_pulse) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sd_on_pulse)) {
        ++(vlSymsp->__Vcoverage[1421]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sd_on_pulse 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_on_pulse;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_on_pulse) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__tom_on_pulse)) {
        ++(vlSymsp->__Vcoverage[1422]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__tom_on_pulse 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_on_pulse;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_on_pulse) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__tc_on_pulse)) {
        ++(vlSymsp->__Vcoverage[1423]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__tc_on_pulse 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_on_pulse;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_on_pulse) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__hh_on_pulse)) {
        ++(vlSymsp->__Vcoverage[1424]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__hh_on_pulse 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_on_pulse;
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3221]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3222]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3223]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3224]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3225]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3226]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3227]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3228]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3229]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3230]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3231]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3232]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3233]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3234]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3235]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3236]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3237]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3238]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3239]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3240]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3181]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3182]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3183]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3184]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3185]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3186]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3187]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3188]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3189]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3190]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3191]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3192]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3193]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3194]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3195]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3196]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3197]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3198]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3199]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3))) {
        ++(vlSymsp->__Vcoverage[3200]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3201]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3202]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3203]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3204]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3205]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3206]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3207]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3208]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3209]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3210]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3211]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3212]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3213]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3214]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3215]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3216]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3217]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3218]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3219]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3))) {
        ++(vlSymsp->__Vcoverage[3220]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3));
    }
    if ((0U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                      >> 6U)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
    } else {
        if ((1U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                          >> 6U)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
        } else {
            if ((2U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                              >> 6U)))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                    = (0xfffffU & ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                                    << 8U) | ((0x1fU 
                                               >= (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                                                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3))
                                               ? ((IData)(0x34U) 
                                                  << 
                                                  (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
                                                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3))
                                               : 0U)));
            } else {
                if ((3U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                  >> 6U)))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
                } else {
                    if ((4U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                      >> 6U)))) {
                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                            = (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3);
                    } else {
                        if ((5U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                          >> 6U)))) {
                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                                = (0xfffffU & (((IData)(1U) 
                                                + vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3) 
                                               << 8U));
                        }
                    }
                }
            }
        }
    }
    if ((6U > (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
        ++(vlSymsp->__Vcoverage[940]);
    }
    if ((6U <= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
        if ((0xcU > (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
            ++(vlSymsp->__Vcoverage[938]);
        }
    }
    if ((6U <= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
        if ((0xcU <= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
            ++(vlSymsp->__Vcoverage[939]);
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if ((1U & (~ ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                      | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                            if (((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                 | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                                ++(vlSymsp->__Vcoverage[953]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if (((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                            ++(vlSymsp->__Vcoverage[950]);
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if ((1U & (~ ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                      | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                            if ((1U & (~ ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                          | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                                if ((1U & (~ ((0xcU 
                                               == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                              | (0xfU 
                                                 == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                                    ++(vlSymsp->__Vcoverage[955]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if (((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                        ++(vlSymsp->__Vcoverage[947]);
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                ++(vlSymsp->__Vcoverage[943]);
            }
        }
    }
    if ((1U & (~ (((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                           | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                       | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                      | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                     | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                        | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                    | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                       | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                   | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                  | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                     | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))))) {
        if (((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            ++(vlSymsp->__Vcoverage[956]);
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                     | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                    ++(vlSymsp->__Vcoverage[944]);
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if (((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            ++(vlSymsp->__Vcoverage[942]);
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if ((1U & (~ ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                      | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                            if ((1U & (~ ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                          | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                                if (((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                     | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                                    ++(vlSymsp->__Vcoverage[954]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                               << 0x11U) | (((0xeU 
                                              == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                             << 0x10U) 
                                            | (((0x10U 
                                                 == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                << 0xfU) 
                                               | (((0xdU 
                                                    == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                   << 0xeU) 
                                                  | (((0xfU 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                      << 0xdU) 
                                                     | (((0xcU 
                                                          == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                         << 0xcU) 
                                                        | (((0xbU 
                                                             == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                            << 0xbU) 
                                                           | (((8U 
                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                               << 0xaU) 
                                                              | (((0xaU 
                                                                   == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                  << 9U) 
                                                                 | (((7U 
                                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                     << 8U) 
                                                                    | (((9U 
                                                                         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                        << 7U) 
                                                                       | (((6U 
                                                                            == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                           << 6U) 
                                                                          | (((5U 
                                                                               == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                              << 5U) 
                                                                             | (((2U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 4U) 
                                                                                | (((4U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 3U) 
                                                                                | (((1U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 2U) 
                                                                                | (((3U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))))))))))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: control_operators.sv:238: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 238, "");
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if (((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                        if ((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                            ++(vlSymsp->__Vcoverage[945]);
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if ((1U & (~ ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                      | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                            if (((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                 | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                                if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                                    ++(vlSymsp->__Vcoverage[952]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if (((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                            if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                                ++(vlSymsp->__Vcoverage[949]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if ((1U & (~ ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                      | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                            if (((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                 | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                                if ((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                                    ++(vlSymsp->__Vcoverage[951]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if ((1U & (~ ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                        if (((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                            if ((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                                ++(vlSymsp->__Vcoverage[948]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if (((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                        if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                            ++(vlSymsp->__Vcoverage[946]);
                        }
                    }
                }
            }
        }
    }
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        if ((1U & (~ ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((0xdU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((0xeU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((0x10U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        if ((0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                            ++(vlSymsp->__Vcoverage[976]);
                        }
                    }
                }
            }
        }
    }
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        if ((1U & (~ ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((0xdU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((0xeU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        ++(vlSymsp->__Vcoverage[975]);
                    }
                }
            }
        }
    }
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        if ((1U & (~ ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((0xdU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    ++(vlSymsp->__Vcoverage[974]);
                }
            }
        }
    }
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        if ((1U & (~ ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                ++(vlSymsp->__Vcoverage[973]);
            }
        }
    }
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        if ((1U & (~ ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((0xdU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((0xeU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((0x10U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        if ((0x11U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                            ++(vlSymsp->__Vcoverage[977]);
                        }
                    }
                }
            }
        }
    }
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        if (((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            ++(vlSymsp->__Vcoverage[972]);
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num))) {
        ++(vlSymsp->__Vcoverage[736]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num 
            = ((0x1eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num))) {
        ++(vlSymsp->__Vcoverage[737]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num 
            = ((0x1dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num))) {
        ++(vlSymsp->__Vcoverage[738]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num 
            = ((0x1bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num))) {
        ++(vlSymsp->__Vcoverage[739]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num 
            = ((0x17U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num))) {
        ++(vlSymsp->__Vcoverage[740]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num 
            = ((0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address = 0U;
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        if ((1U & (~ ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                      | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                          | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                              | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
                    if (((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address = 3U;
                    } else {
                        if (((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address = 4U;
                            if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address = 4U;
                            }
                        } else {
                            if (((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                 | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address = 5U;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address 
            = (((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                ? 0U : (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                         ? 1U : (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                  ? 2U : (0xfU & ((
                                                   (6U 
                                                    == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                   | (9U 
                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                   ? 
                                                  ((0x12U 
                                                    < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                     ? 0U
                                                     : 3U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                     ? 0U
                                                     : 3U))
                                                   : 
                                                  (((7U 
                                                     == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                    | (0xaU 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                    ? 
                                                   ((0x12U 
                                                     < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                      ? 1U
                                                      : 4U)
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                      ? 1U
                                                      : 4U))
                                                    : 
                                                   (((8U 
                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                     | (0xbU 
                                                        == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                     ? 
                                                    ((0x12U 
                                                      < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                       ? 2U
                                                       : 5U)
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                       ? 2U
                                                       : 5U))
                                                     : 
                                                    (((0xcU 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                      | (0xfU 
                                                         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                      ? 6U
                                                      : 7U))))))));
    } else {
        if (((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address = 8U;
        }
    }
    if ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
    } else {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = 0U;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type = 0U;
    if (((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
         & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type 
            = (((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                ? 1U : ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                         ? 2U : ((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                                  ? 3U : ((0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                                           ? 4U : (
                                                   (0x11U 
                                                    == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                                                    ? 5U
                                                    : 0U)))));
        if ((1U & (~ VL_ONEHOT0_I((((0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                    << 5U) | (((0x10U 
                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                               << 4U) 
                                              | (((0xeU 
                                                   == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                  << 3U) 
                                                 | (((0xdU 
                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                     << 2U) 
                                                    | (((0xfU 
                                                         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                        << 1U) 
                                                       | (0xcU 
                                                          == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))))))))) {
            if (VL_UNLIKELY(Verilated::assertOn())) {
                VL_WRITEF("[%0t] %%Error: control_operators.sv:397: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                          64,VL_TIME_UNITED_Q(1000),
                          vlSymsp->name());
                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 397, "");
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dob 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dob 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address 
        = (0x1fU & ((6U > (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                     ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)
                     : ((0xcU > (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                         ? ((IData)(2U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                         : ((IData)(4U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))));
    if ((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                  | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
              | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                 | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
             | ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
            | ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
           | ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
              | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
          | ((0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
         | ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
            | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address 
            = (((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                | (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                ? 0U : (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                         | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                         ? 1U : (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                  | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                  ? 2U : (0xfU & ((
                                                   (6U 
                                                    == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                   | (9U 
                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                   ? 
                                                  ((0x12U 
                                                    < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                     ? 0U
                                                     : 3U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                     ? 0U
                                                     : 3U))
                                                   : 
                                                  (((7U 
                                                     == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                    | (0xaU 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                    ? 
                                                   ((0x12U 
                                                     < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                      ? 1U
                                                      : 4U)
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                      ? 1U
                                                      : 4U))
                                                    : 
                                                   (((8U 
                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                     | (0xbU 
                                                        == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                     ? 
                                                    ((0x12U 
                                                      < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                                      ? 
                                                     ((0x20U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                       ? 2U
                                                       : 5U)
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))
                                                       ? 2U
                                                       : 5U))
                                                     : 
                                                    (((0xcU 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                      | (0xfU 
                                                         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))
                                                      ? 6U
                                                      : 7U))))))));
    } else {
        if (((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
             | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address = 8U;
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en)) {
        ++(vlSymsp->__Vcoverage[792]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
           & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2460]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2461]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2148]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2149]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3305]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3306]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3307]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3308]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3309]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3310]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3311]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta))) {
        ++(vlSymsp->__Vcoverage[3312]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta)));
    }
    if ((1U & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in))) {
        ++(vlSymsp->__Vcoverage[3571]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 1U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 1U)))) {
        ++(vlSymsp->__Vcoverage[3572]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (2U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                            >> 1U)) << 1U)));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 2U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 2U)))) {
        ++(vlSymsp->__Vcoverage[3573]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (4U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                            >> 2U)) << 2U)));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 3U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 3U)))) {
        ++(vlSymsp->__Vcoverage[3574]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (8U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                            >> 3U)) << 3U)));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 4U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 4U)))) {
        ++(vlSymsp->__Vcoverage[3575]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (0x10U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                               >> 4U)) << 4U)));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 5U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 5U)))) {
        ++(vlSymsp->__Vcoverage[3576]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (0x20U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                               >> 5U)) << 5U)));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 6U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 6U)))) {
        ++(vlSymsp->__Vcoverage[3577]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (0x40U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                               >> 6U)) << 6U)));
    }
    if ((1U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   >> 7U)) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
                              >> 7U)))) {
        ++(vlSymsp->__Vcoverage[3578]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in)) 
               | (0x80U & ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                               >> 7U)) << 7U)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2679]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2680]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2681]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2682]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2683]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2684]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2685]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2686]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2687]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2688]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2689]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2690]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5))) {
        ++(vlSymsp->__Vcoverage[2691]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state))) {
        ++(vlSymsp->__Vcoverage[727]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state))) {
        ++(vlSymsp->__Vcoverage[728]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state))) {
        ++(vlSymsp->__Vcoverage[729]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state))) {
        ++(vlSymsp->__Vcoverage[730]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state))) {
        ++(vlSymsp->__Vcoverage[731]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state))) {
        ++(vlSymsp->__Vcoverage[732]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[3050]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[3105]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2998]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2999]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellinp__ch_abcd_cnt_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[689]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT____Vcellinp__ch_abcd_cnt_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellinp__ch_abcd_cnt_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellinp__ch_abcd_cnt_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ws_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[1037]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ws_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ws_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ws_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fnum_low_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[1054]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fnum_low_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fnum_low_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fnum_low_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__kon_block_fnum_high_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[1089]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__kon_block_fnum_high_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__kon_block_fnum_high_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__kon_block_fnum_high_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt0_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[1114]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt0_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt0_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt0_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt1_mem__wea) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea)) {
        ++(vlSymsp->__Vcoverage[1249]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt1_mem__wea;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt1_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt1_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3839]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3840]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3841]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3842]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3843]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3844]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3845]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3846]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3847]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3848]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3849]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3850]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3851]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3852]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3853]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ffbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3854]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3ff7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3855]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3feffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3856]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3857]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3fbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [0U]))) {
        ++(vlSymsp->__Vcoverage[3858]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3f7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [0U]))) {
        ++(vlSymsp->__Vcoverage[3859]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3efffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [0U]))) {
        ++(vlSymsp->__Vcoverage[3860]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3dfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [0U]))) {
        ++(vlSymsp->__Vcoverage[3861]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x3bfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [0U]))) {
        ++(vlSymsp->__Vcoverage[3862]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x37fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                       [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                       [0U]))) {
        ++(vlSymsp->__Vcoverage[3863]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x2ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                       [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                       [0U]))) {
        ++(vlSymsp->__Vcoverage[3864]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3865]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3866]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3867]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3868]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3869]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3870]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3871]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3872]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3873]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3874]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3875]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3876]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3877]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3878]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3879]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ffbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3880]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3ff7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3881]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3feffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3882]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3883]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3fbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                     [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                     [1U]))) {
        ++(vlSymsp->__Vcoverage[3884]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3f7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [1U]))) {
        ++(vlSymsp->__Vcoverage[3885]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3efffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [1U]))) {
        ++(vlSymsp->__Vcoverage[3886]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3dfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [1U]))) {
        ++(vlSymsp->__Vcoverage[3887]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x3bfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                      [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                      [1U]))) {
        ++(vlSymsp->__Vcoverage[3888]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x37fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                       [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                       [1U]))) {
        ++(vlSymsp->__Vcoverage[3889]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x2ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                       [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                       [1U]))) {
        ++(vlSymsp->__Vcoverage[3890]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3918]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1ffeU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3919]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1ffdU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3920]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1ffbU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [0U]))) {
        ++(vlSymsp->__Vcoverage[3921]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1ff7U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3922]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1fefU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3923]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1fdfU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3924]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1fbfU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[3925]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1f7fU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3926]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1effU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3927]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1dffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3928]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x1bffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [0U]))) {
        ++(vlSymsp->__Vcoverage[3929]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0x17ffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                    [0U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                    [0U]))) {
        ++(vlSymsp->__Vcoverage[3930]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[0U] 
            = ((0xfffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [0U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3931]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1ffeU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3932]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1ffdU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3933]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1ffbU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
               [1U]))) {
        ++(vlSymsp->__Vcoverage[3934]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1ff7U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3935]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1fefU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x10U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3936]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1fdfU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x20U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3937]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1fbfU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x40U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                  [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[3938]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1f7fU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x80U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3939]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1effU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x100U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3940]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1dffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x200U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3941]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x1bffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x400U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                   [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                   [1U]))) {
        ++(vlSymsp->__Vcoverage[3942]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0x17ffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x800U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                    [1U] ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                    [1U]))) {
        ++(vlSymsp->__Vcoverage[3943]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[1U] 
            = ((0xfffU & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array
                [1U]) | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
                         [1U]));
    }
    vlTOPp->opl3__DOT__channels__DOT__operator_mem_out 
        = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
         ^ vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr)) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr 
            = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_p1)) {
        ++(vlSymsp->__Vcoverage[902]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1;
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2550]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2551]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2552]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2553]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2554]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2555]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2556]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2557]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2558]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2559]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2560]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2561]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2562]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2563]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2564]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2565]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2566]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2567]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2568]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2))) {
        ++(vlSymsp->__Vcoverage[2569]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2221]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2222]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2223]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2224]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2225]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2226]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2227]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2228]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2229]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2230]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2231]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x7bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2232]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x77ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2233]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x6fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x2000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2234]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x5fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x2000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    if ((0x4000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1))) {
        ++(vlSymsp->__Vcoverage[2235]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1 
            = ((0x3fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1)) 
               | (0x4000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1)
            ? 0U : (0x7fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
        = (0x3ffffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                       + ((4U | (3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1))) 
                          << (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
                                      >> 2U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1 
        = (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                 >> 0xfU));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt0_p1))) {
        ++(vlSymsp->__Vcoverage[901]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt0_p1 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob));
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1)) 
                                           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                 >> 3U))))) {
                                    if ((1U & (~ ((
                                                   (0U 
                                                    == 
                                                    ((2U 
                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                         << 1U)) 
                                                     | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                   | (1U 
                                                      == 
                                                      ((2U 
                                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                           << 1U)) 
                                                       | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                                  | (2U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                          << 1U)) 
                                                      | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))))) {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                            ++(vlSymsp->__Vcoverage[1000]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                           >> 2U)) 
                                       | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                             >> 5U))))) {
                                if ((1U & (~ (((0U 
                                                == 
                                                ((2U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                               | (2U 
                                                  == 
                                                  ((2U 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                       << 1U)) 
                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                              | (3U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))))) {
                                    if ((1U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                        ++(vlSymsp->__Vcoverage[995]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                           >> 2U)) 
                                       | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                             >> 5U))))) {
                                if ((((0U == ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                      | (2U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                     | (3U == ((2U 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                               | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                    ++(vlSymsp->__Vcoverage[994]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1)) 
                                           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                 >> 3U))))) {
                                    if ((((0U == ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                          | (1U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                       << 1U)) 
                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                        ++(vlSymsp->__Vcoverage[999]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                       >> 1U)) | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 4U))))) {
                            if ((1U & (~ (((0U == (
                                                   (2U 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                       << 1U)) 
                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                           | (2U == 
                                              ((2U 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                               | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                          | (3U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))))) {
                                if ((1U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                            | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                    ++(vlSymsp->__Vcoverage[990]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1)) 
                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                     >> 3U))))) {
                        if ((((0U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                             << 1U)) 
                                      | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                              | (2U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                               << 1U)) 
                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                             | (3U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                              << 1U)) 
                                       | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                            ++(vlSymsp->__Vcoverage[984]);
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1)) 
                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                     >> 3U))))) {
                        if ((1U & (~ (((0U == ((2U 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                               | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                       | (2U == ((2U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                      | (3U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))))) {
                            if ((1U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                               << 1U)) 
                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                ++(vlSymsp->__Vcoverage[985]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((9U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                   >> 1U)) 
                                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 4U))))) {
                                        if ((1U & (~ 
                                                   (((0U 
                                                      == 
                                                      ((2U 
                                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                           << 1U)) 
                                                       | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                     | (1U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                             << 1U)) 
                                                         | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                                    | (2U 
                                                       == 
                                                       ((2U 
                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                            << 1U)) 
                                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))))) {
                                            if ((3U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                                ++(vlSymsp->__Vcoverage[1005]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                       >> 1U)) | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 4U))))) {
                            if ((((0U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                 << 1U)) 
                                          | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                  | (2U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                            | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                 | (3U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                  << 1U)) 
                                           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                ++(vlSymsp->__Vcoverage[989]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((9U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                   >> 1U)) 
                                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 4U))))) {
                                        if ((((0U == 
                                               ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                              | (1U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                             | (2U 
                                                == 
                                                ((2U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                            ++(vlSymsp->__Vcoverage[1004]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((9U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((0xaU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                   >> 2U)) 
                                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 5U))))) {
                                        if ((((0U == 
                                               ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                              | (1U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                             | (2U 
                                                == 
                                                ((2U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                            ++(vlSymsp->__Vcoverage[1009]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if ((1U & (~ ((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                          | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                         | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                        | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                       | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                      | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
            if ((1U & (~ ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                            | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                           | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                          | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))))) {
                if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((9U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((0xaU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                   >> 2U)) 
                                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 5U))))) {
                                        if ((1U & (~ 
                                                   (((0U 
                                                      == 
                                                      ((2U 
                                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                           << 1U)) 
                                                       | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                     | (1U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                             << 1U)) 
                                                         | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                                    | (2U 
                                                       == 
                                                       ((2U 
                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                            << 1U)) 
                                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))))) {
                                            if ((3U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                                ++(vlSymsp->__Vcoverage[1010]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1))) {
        ++(vlSymsp->__Vcoverage[898]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1)) 
               | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                        >> 1U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                >> 2U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[899]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1)) 
               | (2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                        >> 1U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                >> 3U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1 
                          >> 2U)))) {
        ++(vlSymsp->__Vcoverage[900]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1)) 
               | (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                        >> 1U)));
    }
    if ((((((((((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) 
              | (6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
            | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
        if (((((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                 | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
               | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
              | (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
             | (0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
        } else {
            if (((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                   | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                  | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) 
                 | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                    = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob))
                        ? 0U : (0x1fffU & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1))));
            } else {
                if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1)) 
                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                     >> 3U))))) {
                        if ((((0U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                             << 1U)) 
                                      | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                              | (2U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                               << 1U)) 
                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                             | (3U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                              << 1U)) 
                                       | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
                        } else {
                            if ((1U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                               << 1U)) 
                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                            }
                        }
                        if ((1U & (~ VL_ONEHOT_I(((
                                                   (1U 
                                                    == 
                                                    ((2U 
                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                         << 1U)) 
                                                     | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                   << 3U) 
                                                  | (((3U 
                                                       == 
                                                       ((2U 
                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                            << 1U)) 
                                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                      << 2U) 
                                                     | (((2U 
                                                          == 
                                                          ((2U 
                                                            & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                               << 1U)) 
                                                           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                         << 1U) 
                                                        | (0U 
                                                           == 
                                                           ((2U 
                                                             & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                << 1U)) 
                                                            | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))))))))) {
                            if (VL_UNLIKELY(Verilated::assertOn())) {
                                VL_WRITEF("[%0t] %%Error: control_operators.sv:420: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                          64,VL_TIME_UNITED_Q(1000),
                                          vlSymsp->name());
                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 420, "");
                            }
                        }
                    } else {
                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                    }
                } else {
                    if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                        if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                       >> 1U)) | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 4U))))) {
                            if ((1U & (~ VL_ONEHOT_I(
                                                     (((1U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                             << 1U)) 
                                                         | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                       << 3U) 
                                                      | (((3U 
                                                           == 
                                                           ((2U 
                                                             & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                << 1U)) 
                                                            | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                          << 2U) 
                                                         | (((2U 
                                                              == 
                                                              ((2U 
                                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                   << 1U)) 
                                                               | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                             << 1U) 
                                                            | (0U 
                                                               == 
                                                               ((2U 
                                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                    << 1U)) 
                                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))))))))) {
                                if (VL_UNLIKELY(Verilated::assertOn())) {
                                    VL_WRITEF("[%0t] %%Error: control_operators.sv:427: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                              64,VL_TIME_UNITED_Q(1000),
                                              vlSymsp->name());
                                    VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 427, "");
                                }
                            }
                            if ((((0U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                 << 1U)) 
                                          | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                  | (2U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                            | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                 | (3U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                  << 1U)) 
                                           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                    = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
                            } else {
                                if ((1U == ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                            | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                                }
                            }
                        } else {
                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                        }
                    } else {
                        if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                            if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                           >> 2U)) 
                                       | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                             >> 5U))))) {
                                if ((1U & (~ VL_ONEHOT_I(
                                                         (((1U 
                                                            == 
                                                            ((2U 
                                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                 << 1U)) 
                                                             | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                           << 3U) 
                                                          | (((3U 
                                                               == 
                                                               ((2U 
                                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                    << 1U)) 
                                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                              << 2U) 
                                                             | (((2U 
                                                                  == 
                                                                  ((2U 
                                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                       << 1U)) 
                                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                 << 1U) 
                                                                | (0U 
                                                                   == 
                                                                   ((2U 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                        << 1U)) 
                                                                    | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))))))))) {
                                    if (VL_UNLIKELY(
                                                    Verilated::assertOn())) {
                                        VL_WRITEF("[%0t] %%Error: control_operators.sv:434: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                  64,
                                                  VL_TIME_UNITED_Q(1000),
                                                  vlSymsp->name());
                                        VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 434, "");
                                    }
                                }
                                if ((((0U == ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                      | (2U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                     | (3U == ((2U 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                   << 1U)) 
                                               | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
                                } else {
                                    if ((1U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                                    }
                                }
                            } else {
                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                            }
                        } else {
                            if ((9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1)) 
                                           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                 >> 3U))))) {
                                    if ((1U & (~ VL_ONEHOT_I(
                                                             (((3U 
                                                                == 
                                                                ((2U 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                     << 1U)) 
                                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                               << 3U) 
                                                              | (((2U 
                                                                   == 
                                                                   ((2U 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                        << 1U)) 
                                                                    | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                  << 2U) 
                                                                 | (((1U 
                                                                      == 
                                                                      ((2U 
                                                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                           << 1U)) 
                                                                       | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                     << 1U) 
                                                                    | (0U 
                                                                       == 
                                                                       ((2U 
                                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                            << 1U)) 
                                                                        | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: control_operators.sv:441: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 441, "");
                                        }
                                    }
                                    if ((((0U == ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                          | (1U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                       << 1U)) 
                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
                                    } else {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                << 1U)) 
                                              | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                                        }
                                    }
                                } else {
                                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob))
                                            ? 0U : 
                                           (0x1fffU 
                                            & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1))));
                                }
                            } else {
                                if ((0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                   >> 1U)) 
                                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 4U))))) {
                                        if ((1U & (~ 
                                                   VL_ONEHOT_I(
                                                               (((3U 
                                                                  == 
                                                                  ((2U 
                                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                       << 1U)) 
                                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                 << 3U) 
                                                                | (((2U 
                                                                     == 
                                                                     ((2U 
                                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                          << 1U)) 
                                                                      | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                    << 2U) 
                                                                   | (((1U 
                                                                        == 
                                                                        ((2U 
                                                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                             << 1U)) 
                                                                         | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                       << 1U) 
                                                                      | (0U 
                                                                         == 
                                                                         ((2U 
                                                                           & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                              << 1U)) 
                                                                          | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))))))))) {
                                            if (VL_UNLIKELY(
                                                            Verilated::assertOn())) {
                                                VL_WRITEF("[%0t] %%Error: control_operators.sv:448: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                          64,
                                                          VL_TIME_UNITED_Q(1000),
                                                          vlSymsp->name());
                                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 448, "");
                                            }
                                        }
                                        if ((((0U == 
                                               ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                              | (1U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                             | (2U 
                                                == 
                                                ((2U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
                                        } else {
                                            if ((3U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                            = ((1U 
                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob))
                                                ? 0U
                                                : (0x1fffU 
                                                   & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1))));
                                    }
                                } else {
                                    if ((1U & (((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)) 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                   >> 2U)) 
                                               | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1) 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1) 
                                                     >> 5U))))) {
                                        if ((1U & (~ 
                                                   VL_ONEHOT_I(
                                                               (((3U 
                                                                  == 
                                                                  ((2U 
                                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                       << 1U)) 
                                                                   | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                 << 3U) 
                                                                | (((2U 
                                                                     == 
                                                                     ((2U 
                                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                          << 1U)) 
                                                                      | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                    << 2U) 
                                                                   | (((1U 
                                                                        == 
                                                                        ((2U 
                                                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                             << 1U)) 
                                                                         | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                                                       << 1U) 
                                                                      | (0U 
                                                                         == 
                                                                         ((2U 
                                                                           & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                                              << 1U)) 
                                                                          | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))))))))) {
                                            if (VL_UNLIKELY(
                                                            Verilated::assertOn())) {
                                                VL_WRITEF("[%0t] %%Error: control_operators.sv:455: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                          64,
                                                          VL_TIME_UNITED_Q(1000),
                                                          vlSymsp->name());
                                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 455, "");
                                            }
                                        }
                                        if ((((0U == 
                                               ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    << 1U)) 
                                                | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))) 
                                              | (1U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) 
                                             | (2U 
                                                == 
                                                ((2U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
                                        } else {
                                            if ((3U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                      << 1U)) 
                                                  | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1)))) {
                                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 = 0U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                                            = ((1U 
                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob))
                                                ? 0U
                                                : (0x1fffU 
                                                   & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1))));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                = ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ryt_p1) 
                             & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)))))
                    ? 0U : (0x1fffU & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1))));
        } else {
            if ((0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1 
                    = ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                              | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ryt_p1) 
                                 & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1)))))
                        ? 0U : (0x1fffU & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1))));
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                               << 0x11U) | (((0x10U 
                                              == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                             << 0x10U) 
                                            | (((0xbU 
                                                 == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                << 0xfU) 
                                               | (((0xaU 
                                                    == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                   << 0xeU) 
                                                  | (((9U 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                      << 0xdU) 
                                                     | (((8U 
                                                          == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                         << 0xcU) 
                                                        | (((7U 
                                                             == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                            << 0xbU) 
                                                           | (((6U 
                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                               << 0xaU) 
                                                              | (((0xfU 
                                                                   == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                  << 9U) 
                                                                 | (((5U 
                                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                     << 8U) 
                                                                    | (((4U 
                                                                         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                        << 7U) 
                                                                       | (((3U 
                                                                            == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                           << 6U) 
                                                                          | (((0xeU 
                                                                               == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                              << 5U) 
                                                                             | (((0xdU 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                                << 4U) 
                                                                                | (((0xcU 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1)) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1))))))))))))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: control_operators.sv:415: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 415, "");
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2756]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2757]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2758]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2759]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2760]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2761]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2762]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2763]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2764]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2765]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2766]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2767]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6))) {
        ++(vlSymsp->__Vcoverage[2768]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2769]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2770]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2771]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2772]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2773]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2774]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2775]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2776]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2777]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2778]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2779]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2780]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6))) {
        ++(vlSymsp->__Vcoverage[2781]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)));
    }
    if (((((((((0U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                             >> 0xfU))) | (1U == (7U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                     >> 0xfU)))) 
              | (2U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                              >> 0xfU)))) | (3U == 
                                             (7U & 
                                              (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                               >> 0xfU)))) 
            | (4U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                            >> 0xfU)))) | (5U == (7U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                     >> 0xfU)))) 
          | (6U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                          >> 0xfU)))) | (7U == (7U 
                                                & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                   >> 0xfU))))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6 
            = (0x1fffU & ((0U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                        >> 0xfU))) ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)
                           : ((1U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                            >> 0xfU)))
                               ? (VL_GTS_III(1,32,32, 0U, 
                                             VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)))
                                   ? 0U : VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)))
                               : ((2U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                >> 0xfU)))
                                   ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)
                                   : ((3U == (7U & 
                                              (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                               >> 0xfU)))
                                       ? ((0x40000U 
                                           & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p5)
                                           ? 0U : VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6)))
                                       : ((4U == (7U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                     >> 0xfU)))
                                           ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)
                                           : ((5U == 
                                               (7U 
                                                & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                   >> 0xfU)))
                                               ? (VL_GTS_III(1,32,32, 0U, 
                                                             VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6)))
                                                   ? 
                                                  (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6))
                                                   : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6))
                                               : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6))))))));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[2374]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[2417]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2332]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[2333]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1))) {
        ++(vlSymsp->__Vcoverage[1893]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1))) {
        ++(vlSymsp->__Vcoverage[1894]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1))) {
        ++(vlSymsp->__Vcoverage[1895]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1)));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2647]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2648]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2649]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2650]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2651]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2652]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2653]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2654]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2655]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2656]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2657]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2658]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2659]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2660]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2661]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2662]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2663]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2664]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2665]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3))) {
        ++(vlSymsp->__Vcoverage[2666]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[911]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[912]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[913]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[914]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
        = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)) 
           & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
        = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)) 
           & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address]);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[907]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[908]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[909]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[910]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address)));
    }
    if ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address];
    } else {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 = 0U;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2391]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2392]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2393]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2394]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2395]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2396]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2397]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2398]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2399]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2400]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2401]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2402]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x77ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2403]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x6fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x2000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2404]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x5fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x2000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x4000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2405]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x3fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x4000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2434]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2435]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2436]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2437]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2438]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2439]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2440]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2441]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2442]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2443]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2444]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2445]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x77ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2446]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x6fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x2000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2447]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x5fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x2000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((0x4000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[2448]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x3fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (0x4000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3072]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3073]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3074]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3075]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3076]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3077]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3078]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3079]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3080]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3081]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3082]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3083]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3084]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3085]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3086]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3087]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3088]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3089]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3090]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3091]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3127]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3128]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3129]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3130]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3131]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3132]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3133]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3134]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3135]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3136]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3137]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3138]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3139]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3140]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3141]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3142]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3143]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3144]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3145]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[3146]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0));
    }
    if ((((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
          & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__clk_en)) {
        ++(vlSymsp->__Vcoverage[1693]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__clk_en 
            = ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    }
    if ((((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
          & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__clk_en)) {
        ++(vlSymsp->__Vcoverage[1709]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__clk_en 
            = ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    }
    if ((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
          & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__clk_en)) {
        ++(vlSymsp->__Vcoverage[1725]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__clk_en 
            = ((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    }
    if ((((5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
          & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__clk_en)) {
        ++(vlSymsp->__Vcoverage[1741]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__clk_en 
            = ((5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    }
    if ((((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
          & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__clk_en)) {
        ++(vlSymsp->__Vcoverage[1757]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__clk_en 
            = ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type))) {
        ++(vlSymsp->__Vcoverage[763]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type))) {
        ++(vlSymsp->__Vcoverage[764]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type))) {
        ++(vlSymsp->__Vcoverage[765]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__rhythm_kon_pulse 
        = ((((((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_on_pulse)) 
              | ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_on_pulse))) 
             | ((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_on_pulse))) 
            | ((5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_on_pulse))) 
           | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
              & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_on_pulse)));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dob) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[1642]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__dob 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dob;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dob;
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dob) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[1668]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__dob 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dob;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dob;
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[879]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address 
            = ((0x1eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[880]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address 
            = ((0x1dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[881]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address 
            = ((0x1bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[882]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address 
            = ((0x17U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[883]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address 
            = ((0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[903]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[904]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[905]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address))) {
        ++(vlSymsp->__Vcoverage[906]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[1136]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[1193]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[1265]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[1289]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[2375]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[2418]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[3051]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb)) {
        ++(vlSymsp->__Vcoverage[3106]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[691]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[692]);
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1038]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1039]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1063]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1064]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1092]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1093]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[1135]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[1192]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1115]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1116]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[1264]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array) 
                >> 1U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea))) {
        ++(vlSymsp->__Vcoverage[1288]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea 
            = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array) 
                     >> 1U));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1250]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[1251]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array)));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1428]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1429]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1430]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1431]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1432]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1433]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1434]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1435]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1436]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1437]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1438]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1439]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1440]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1441]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1442]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ffbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1443]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3ff7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1444]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3feffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1445]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1446]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3fbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1447]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3f7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1448]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3efffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1449]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3dfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1450]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x3bfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1451]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x37fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                       ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1452]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x2ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                       ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1))) {
        ++(vlSymsp->__Vcoverage[1453]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1 
            = ((0x1ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1) 
               | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
        = ((0U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                         >> 1U))) ? 0U : (0x3fffffU 
                                          & ((VL_EXTENDS_II(32,13, 
                                                            (0x1fffU 
                                                             & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob)) 
                                              + VL_EXTENDS_II(32,13, 
                                                              (0x1fffU 
                                                               & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
                                                                  >> 0xdU)))) 
                                             << (7U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob) 
                                                    >> 1U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1 
        = (0x1fffU & VL_SHIFTRS_III(22,22,32, vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1, 9U));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[348]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[349]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[350]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[351]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[352]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[353]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[354]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[355]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[356]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[357]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[358]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[359]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out))) {
        ++(vlSymsp->__Vcoverage[360]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_mem_out)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1))) {
        ++(vlSymsp->__Vcoverage[1986]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1))) {
        ++(vlSymsp->__Vcoverage[1987]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1))) {
        ++(vlSymsp->__Vcoverage[1988]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1 
        = (0x3ffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1) 
                     + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2236]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2237]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2238]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2239]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2240]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2241]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2242]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2243]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2244]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2245]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2246]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x7bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2247]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x77ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2248]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x6fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x2000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2249]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x5fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x2000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((0x4000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1))) {
        ++(vlSymsp->__Vcoverage[2250]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1 
            = ((0x3fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1)) 
               | (0x4000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1)));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2266]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3fffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2267]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3fffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2268]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3fffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2269]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3fff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2270]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3ffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2271]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3ffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2272]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3ffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2273]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3ff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2274]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3feffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2275]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3fdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2276]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3fbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2277]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3f7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2278]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3efffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2279]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3dfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2280]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x3bfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2281]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x37fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2282]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x2ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[2283]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1 
            = ((0x1ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[749]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[750]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[751]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[752]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[753]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[754]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[755]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[756]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[757]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[758]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[759]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[760]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[761]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2743]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2744]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2745]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2746]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2747]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2748]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2749]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2750]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2751]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2752]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2753]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2754]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6))) {
        ++(vlSymsp->__Vcoverage[2755]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6 
        = (0x1fffU & ((0U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                                    >> 0xfU))) ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)
                       : ((1U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                                        >> 0xfU))) ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)
                           : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                              << 1U))));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) {
        ++(vlSymsp->__Vcoverage[1267]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) {
        ++(vlSymsp->__Vcoverage[1291]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1141]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1142]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1143]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1144]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1198]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1199]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1200]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((0xbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0))) {
        ++(vlSymsp->__Vcoverage[1201]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0 
            = ((7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__rhythm_kon_pulse) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__rhythm_kon_pulse)) {
        ++(vlSymsp->__Vcoverage[1425]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__rhythm_kon_pulse 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__rhythm_kon_pulse;
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array
         [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__dob_array
         [0U])) {
        ++(vlSymsp->__Vcoverage[1631]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array
            [0U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array
         [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__dob_array
         [1U])) {
        ++(vlSymsp->__Vcoverage[1632]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array
            [1U];
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1398]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1399]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1400]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1401]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1402]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1403]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1404]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1405]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1406]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1407]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1408]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1409]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3ff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1410]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1411]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1412]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3fbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1413]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3f7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1414]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3effffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1415]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3dffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1416]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x3bffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1417]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x37ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1418]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x2fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1))) {
        ++(vlSymsp->__Vcoverage[1419]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1 
            = ((0x1fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1385]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1386]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1387]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1388]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1389]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1390]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1391]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1392]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1393]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1394]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1395]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1396]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1))) {
        ++(vlSymsp->__Vcoverage[1397]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1)
            ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)
            : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1966]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3feU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1967]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3fdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1968]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3fbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1969]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3f7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1970]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3efU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1971]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3dfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1972]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x3bfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1973]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x37fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1974]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x2ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1))) {
        ++(vlSymsp->__Vcoverage[1975]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1 
            = ((0x1ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[766]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[767]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[768]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[769]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[770]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[771]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[772]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[773]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[774]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[775]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[776]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[777]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6))) {
        ++(vlSymsp->__Vcoverage[778]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6)));
    }
    vlTOPp->opl3__DOT__channels__DOT__operator_out 
        = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__operator_out) 
           | (0x80000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
                          << 0xeU)));
    vlTOPp->opl3__DOT__channels__DOT__operator_out 
        = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__operator_out) 
           | (0x40000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out) 
                          << 0xdU)));
    vlTOPp->opl3__DOT__channels__DOT__operator_out 
        = ((0xc1fffU & vlTOPp->opl3__DOT__channels__DOT__operator_out) 
           | (0x3e000U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
                                   >> 0x19U)) << 0xdU)));
    vlTOPp->opl3__DOT__channels__DOT__operator_out 
        = ((0xfe000U & vlTOPp->opl3__DOT__channels__DOT__operator_out) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
        = ((0x3ffe000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
        = ((0x1fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6) 
           | (0x3ffe000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[3U] 
                            << 5U)));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__prev_kon_p0)) {
        ++(vlSymsp->__Vcoverage[1426]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__prev_kon_p0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2524]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2525]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2526]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2527]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2528]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2529]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2530]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2531]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2532]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2533]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2534]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2535]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1))) {
        ++(vlSymsp->__Vcoverage[2536]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1)));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                     ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[336]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
               ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[339]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[340]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[341]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                  ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[342]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[343]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[344]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[345]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                   ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[346]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                    ^ vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out))) {
        ++(vlSymsp->__Vcoverage[347]);
        vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT____Vtogcov__operator_out) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__operator_out));
    }
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array)) 
           | (1U & ((vlTOPp->opl3__DOT__channels__DOT__operator_out 
                     >> 0x13U) & (~ (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                     >> 0x12U)))));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array)) 
           | (2U & ((vlTOPp->opl3__DOT__channels__DOT__operator_out 
                     >> 0x12U) & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                  >> 0x11U))));
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1454]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1455]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1456]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1457]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1458]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1459]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1460]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1461]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1462]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1463]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1464]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1465]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1466]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1467]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1468]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ffbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1469]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3ff7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1470]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3feffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1471]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1472]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3fbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1473]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3f7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1474]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3efffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1475]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3dfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1476]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x3bfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1477]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x37fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x1000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                       ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1478]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x2ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x1000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((0x2000000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
                       ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6))) {
        ++(vlSymsp->__Vcoverage[1479]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6 
            = ((0x1ffffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6) 
               | (0x2000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[3916]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array) 
               ^ vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array))) {
        ++(vlSymsp->__Vcoverage[3917]);
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array)));
    }
}
