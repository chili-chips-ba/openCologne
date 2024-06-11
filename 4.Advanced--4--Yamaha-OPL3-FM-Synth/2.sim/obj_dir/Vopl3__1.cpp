// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3.h"
#include "Vopl3__Syms.h"

VL_INLINE_OPT void Vopl3::_sequent__TOP__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    SData/*14:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    SData/*14:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    IData/*19:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    IData/*19:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    WData/*159:0*/ __Vtemp12[5];
    // Body
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3796]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3615]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3614]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3792]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3790]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3607]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3787]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3786]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3605]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3784]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3603]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3601]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3780]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3599]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3779]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3778]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3597]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                  >> 7U)))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3774]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3707]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3706]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3705]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3704]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3703]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3702]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3701]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3700]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3699]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3698]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3697]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3696]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3695]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3694]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3693]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3692]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3691]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3690]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3689]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3688]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3687]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3686]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3685]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3684]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3683]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3682]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3681]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3680]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3679]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3678]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3677]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3676]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3675]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3674]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3673]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3672]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3671]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3670]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3669]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3668]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3667]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3666]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3665]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3664]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3663]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3662]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3661]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3660]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3659]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3658]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3657]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3649]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3643]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3642]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3641]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3640]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3638]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3636]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3630]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3628]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3627]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3626]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3625]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3624]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3621]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3618]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3616]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                          >> 5U)))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3613]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3611]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3610]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3609]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3608]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3606]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3604]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3598]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3596]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3595]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3594]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3593]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                    ++(vlSymsp->__Vcoverage[3592]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
        if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
            if ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                if ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                    if ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))) {
                                if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)))) {
                                    ++(vlSymsp->__Vcoverage[3585]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    ++(vlSymsp->__Vcoverage[1857]);
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                ++(vlSymsp->__Vcoverage[1856]);
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((2U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((3U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((4U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((5U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                if ((6U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                    ++(vlSymsp->__Vcoverage[1855]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((2U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((3U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((4U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((5U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                if ((6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                    ++(vlSymsp->__Vcoverage[1854]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((2U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((3U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((4U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                ++(vlSymsp->__Vcoverage[1853]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((0xaU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((0xbU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                ++(vlSymsp->__Vcoverage[1860]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((2U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        ++(vlSymsp->__Vcoverage[1851]);
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            ++(vlSymsp->__Vcoverage[1848]);
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        ++(vlSymsp->__Vcoverage[1858]);
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                ++(vlSymsp->__Vcoverage[1849]);
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((0xaU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            ++(vlSymsp->__Vcoverage[1859]);
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    ++(vlSymsp->__Vcoverage[1850]);
                }
            }
        }
    }
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        if ((0U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
            if ((1U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((2U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((3U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            ++(vlSymsp->__Vcoverage[1852]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((0xaU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((0xbU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((0xcU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                if ((0xdU == (0xfU 
                                              & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                    ++(vlSymsp->__Vcoverage[1861]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((0xaU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((0xbU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((0xcU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                if ((0xdU != (0xfU 
                                              & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                    if ((0xeU == (0xfU 
                                                  & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                        ++(vlSymsp->__Vcoverage[1862]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                        | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                       | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                      | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                     | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                    | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                   | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))))) {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            if ((8U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                if ((9U != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                    if ((0xaU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                        if ((0xbU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                            if ((0xcU != (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                if ((0xdU != (0xfU 
                                              & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                    if ((0xeU != (0xfU 
                                                  & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) {
                                        ++(vlSymsp->__Vcoverage[1863]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                               << 0xfU) | (((0xeU == 
                                             (0xfU 
                                              & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                            << 0xeU) 
                                           | (((0xdU 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                               << 0xdU) 
                                              | (((0xcU 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                  << 0xcU) 
                                                 | (((0xbU 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                     << 0xbU) 
                                                    | (((0xaU 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                        << 0xaU) 
                                                       | (((9U 
                                                            == 
                                                            (0xfU 
                                                             & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                           << 9U) 
                                                          | (((8U 
                                                               == 
                                                               (0xfU 
                                                                & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                              << 8U) 
                                                             | (((7U 
                                                                  == 
                                                                  (0xfU 
                                                                   & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                 << 7U) 
                                                                | (((6U 
                                                                     == 
                                                                     (0xfU 
                                                                      & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                    << 6U) 
                                                                   | (((5U 
                                                                        == 
                                                                        (0xfU 
                                                                         & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                       << 5U) 
                                                                      | (((4U 
                                                                           == 
                                                                           (0xfU 
                                                                            & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                          << 4U) 
                                                                         | (((3U 
                                                                              == 
                                                                              (0xfU 
                                                                               & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                             << 3U) 
                                                                            | (((2U 
                                                                                == 
                                                                                (0xfU 
                                                                                & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                                << 2U) 
                                                                               | (((1U 
                                                                                == 
                                                                                (0xfU 
                                                                                & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0xfU 
                                                                                & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))))))))))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: calc_phase_inc.sv:72: Assertion failed in %Nopl3.channels.control_operators.operator.calc_phase_inc: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/operator/src/calc_phase_inc.sv", 72, "");
        }
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) {
        ++(vlSymsp->__Vcoverage[1907]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)))) {
        ++(vlSymsp->__Vcoverage[1908]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) {
        ++(vlSymsp->__Vcoverage[2039]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en)))) {
        ++(vlSymsp->__Vcoverage[2040]);
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    ++(vlSymsp->__Vcoverage[2128]);
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                ++(vlSymsp->__Vcoverage[2127]);
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((2U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((3U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) {
                        if ((4U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                            >> 6U)))) {
                            if ((5U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                >> 6U)))) {
                                if ((6U != (0xfU & 
                                            ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                             >> 6U)))) {
                                    ++(vlSymsp->__Vcoverage[2126]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((2U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((3U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) {
                        if ((4U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                            >> 6U)))) {
                            if ((5U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                >> 6U)))) {
                                if ((6U == (0xfU & 
                                            ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                             >> 6U)))) {
                                    ++(vlSymsp->__Vcoverage[2125]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((2U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((3U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) {
                        if ((4U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                            >> 6U)))) {
                            if ((5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                >> 6U)))) {
                                ++(vlSymsp->__Vcoverage[2124]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((0xaU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                          >> 6U)))) {
                        if ((0xbU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                              >> 6U)))) {
                            if ((0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                  >> 6U)))) {
                                ++(vlSymsp->__Vcoverage[2131]);
                            }
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((2U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) {
                        ++(vlSymsp->__Vcoverage[2122]);
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            ++(vlSymsp->__Vcoverage[2119]);
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                          >> 6U)))) {
                        ++(vlSymsp->__Vcoverage[2129]);
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                ++(vlSymsp->__Vcoverage[2120]);
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((0xaU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                          >> 6U)))) {
                        if ((0xbU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                              >> 6U)))) {
                            ++(vlSymsp->__Vcoverage[2130]);
                        }
                    }
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    ++(vlSymsp->__Vcoverage[2121]);
                }
            }
        }
    }
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        if ((0U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) {
            if ((1U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((2U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((3U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) {
                        if ((4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                            >> 6U)))) {
                            ++(vlSymsp->__Vcoverage[2123]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((0xaU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                          >> 6U)))) {
                        if ((0xbU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                              >> 6U)))) {
                            if ((0xcU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                  >> 6U)))) {
                                if ((0xdU == (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) {
                                    ++(vlSymsp->__Vcoverage[2132]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((0xaU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                          >> 6U)))) {
                        if ((0xbU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                              >> 6U)))) {
                            if ((0xcU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                  >> 6U)))) {
                                if ((0xdU != (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) {
                                    if ((0xeU == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) {
                                        ++(vlSymsp->__Vcoverage[2133]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U))) | 
                        (1U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 6U)))) | 
                       (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U)))) | 
                      (3U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (4U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                    | (5U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (6U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                  | (7U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U))))))) {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            if ((8U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) {
                if ((9U != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) {
                    if ((0xaU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                          >> 6U)))) {
                        if ((0xbU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                              >> 6U)))) {
                            if ((0xcU != (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                  >> 6U)))) {
                                if ((0xdU != (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) {
                                    if ((0xeU != (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) {
                                        ++(vlSymsp->__Vcoverage[2134]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((0xfU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U))) 
                               << 0xfU) | (((0xeU == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U))) 
                                            << 0xeU) 
                                           | (((0xdU 
                                                == 
                                                (0xfU 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                    >> 6U))) 
                                               << 0xdU) 
                                              | (((0xcU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U))) 
                                                  << 0xcU) 
                                                 | (((0xbU 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                          >> 6U))) 
                                                     << 0xbU) 
                                                    | (((0xaU 
                                                         == 
                                                         (0xfU 
                                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                             >> 6U))) 
                                                        << 0xaU) 
                                                       | (((9U 
                                                            == 
                                                            (0xfU 
                                                             & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                >> 6U))) 
                                                           << 9U) 
                                                          | (((8U 
                                                               == 
                                                               (0xfU 
                                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                   >> 6U))) 
                                                              << 8U) 
                                                             | (((7U 
                                                                  == 
                                                                  (0xfU 
                                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                      >> 6U))) 
                                                                 << 7U) 
                                                                | (((6U 
                                                                     == 
                                                                     (0xfU 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                         >> 6U))) 
                                                                    << 6U) 
                                                                   | (((5U 
                                                                        == 
                                                                        (0xfU 
                                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                            >> 6U))) 
                                                                       << 5U) 
                                                                      | (((4U 
                                                                           == 
                                                                           (0xfU 
                                                                            & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                               >> 6U))) 
                                                                          << 4U) 
                                                                         | (((3U 
                                                                              == 
                                                                              (0xfU 
                                                                               & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                                >> 6U))) 
                                                                             << 3U) 
                                                                            | (((2U 
                                                                                == 
                                                                                (0xfU 
                                                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                                >> 6U))) 
                                                                                << 2U) 
                                                                               | (((1U 
                                                                                == 
                                                                                (0xfU 
                                                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                                >> 6U))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0xfU 
                                                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                                                >> 6U)))))))))))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: ksl_add_rom.sv:63: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator.ksl_add_rom: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/operator/src/ksl_add_rom.sv", 63, "");
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                      & (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)))))) {
            if (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                 | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)))) {
                ++(vlSymsp->__Vcoverage[2058]);
            }
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                      & (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)))))) {
            if ((1U & (~ ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                          | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)))))) {
                ++(vlSymsp->__Vcoverage[2059]);
            }
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        if (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
             & (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)))) {
            ++(vlSymsp->__Vcoverage[2060]);
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                      & (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)))))) {
            if (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                 | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)))) {
                if ((0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1))) {
                    ++(vlSymsp->__Vcoverage[2056]);
                }
            }
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        if ((1U & (~ ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                      & (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)))))) {
            if (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                 | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1) 
                              >> 9U)))) {
                    ++(vlSymsp->__Vcoverage[2057]);
                }
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((3U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                             >> 0x12U))) 
                               << 3U) | (((2U == (3U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                                     >> 0x12U))) 
                                          << 2U) | 
                                         (((1U == (3U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                                      >> 0x12U))) 
                                           << 1U) | 
                                          (0U == (3U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                                     >> 0x12U)))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: phase_generator.sv:271: Assertion failed in %Nopl3.channels.control_operators.operator.phase_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/operator/src/phase_generator.sv", 271, "");
        }
    }
    if ((0U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                      >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[2943]);
    }
    if ((0U != (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                      >> 0x12U)))) {
        if ((1U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                          >> 0x12U)))) {
            ++(vlSymsp->__Vcoverage[2944]);
        }
    }
    if ((0U != (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                      >> 0x12U)))) {
        if ((1U != (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                          >> 0x12U)))) {
            if ((2U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                              >> 0x12U)))) {
                ++(vlSymsp->__Vcoverage[2945]);
            }
        }
    }
    if ((0U != (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                      >> 0x12U)))) {
        if ((1U != (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                          >> 0x12U)))) {
            if ((2U != (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                              >> 0x12U)))) {
                if ((3U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                  >> 0x12U)))) {
                    ++(vlSymsp->__Vcoverage[2946]);
                }
            }
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            ++(vlSymsp->__Vcoverage[421]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U) 
             & (5U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            ++(vlSymsp->__Vcoverage[419]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if ((1U & (~ ((vlTOPp->opl3__DOT__opl3_reg_wr 
                       >> 0x10U) & (4U == (0xffU & 
                                           (vlTOPp->opl3__DOT__opl3_reg_wr 
                                            >> 8U))))))) {
            ++(vlSymsp->__Vcoverage[418]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if ((1U & (~ ((~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                          >> 0x10U)) & (0xbdU == (0xffU 
                                                  & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                     >> 8U))))))) {
            ++(vlSymsp->__Vcoverage[422]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U) 
             & (4U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            ++(vlSymsp->__Vcoverage[417]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if ((1U & (~ ((vlTOPp->opl3__DOT__opl3_reg_wr 
                       >> 0x10U) & (5U == (0xffU & 
                                           (vlTOPp->opl3__DOT__opl3_reg_wr 
                                            >> 8U))))))) {
            ++(vlSymsp->__Vcoverage[420]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        ++(vlSymsp->__Vcoverage[423]);
    }
    if ((1U & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[424]);
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if ((1U & (~ ((~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                          >> 0x10U)) & (8U == (0xffU 
                                               & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                  >> 8U))))))) {
            ++(vlSymsp->__Vcoverage[932]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (8U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            ++(vlSymsp->__Vcoverage[931]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        ++(vlSymsp->__Vcoverage[935]);
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if ((1U & (~ ((~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                          >> 0x10U)) & (0xbdU == (0xffU 
                                                  & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                     >> 8U))))))) {
            ++(vlSymsp->__Vcoverage[934]);
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            ++(vlSymsp->__Vcoverage[933]);
        }
    }
    if ((1U & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[936]);
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb0U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        ++(vlSymsp->__Vcoverage[4009]);
    }
    if ((1U & (~ (((vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x11U) & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                    >> 0x10U))) & (0xb0U 
                                                   == 
                                                   (0xffU 
                                                    & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                       >> 8U))))))) {
        ++(vlSymsp->__Vcoverage[4010]);
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb1U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        ++(vlSymsp->__Vcoverage[4012]);
    }
    if ((1U & (~ (((vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x11U) & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                    >> 0x10U))) & (0xb1U 
                                                   == 
                                                   (0xffU 
                                                    & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                       >> 8U))))))) {
        ++(vlSymsp->__Vcoverage[4013]);
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb2U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        ++(vlSymsp->__Vcoverage[4015]);
    }
    if ((1U & (~ (((vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x11U) & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                    >> 0x10U))) & (0xb2U 
                                                   == 
                                                   (0xffU 
                                                    & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                       >> 8U))))))) {
        ++(vlSymsp->__Vcoverage[4016]);
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb3U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        ++(vlSymsp->__Vcoverage[4018]);
    }
    if ((1U & (~ (((vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x11U) & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                                    >> 0x10U))) & (0xb3U 
                                                   == 
                                                   (0xffU 
                                                    & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                                       >> 8U))))))) {
        ++(vlSymsp->__Vcoverage[4019]);
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1) {
        ++(vlSymsp->__Vcoverage[2521]);
    }
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1)))) {
        ++(vlSymsp->__Vcoverage[2522]);
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        ++(vlSymsp->__Vcoverage[686]);
    }
    if ((1U & (~ (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                          >> 4U))))) {
        ++(vlSymsp->__Vcoverage[687]);
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                      >> 1U)))) {
            if (((4U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                               >> 3U))) | (5U == (7U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                     >> 3U))))) {
                ++(vlSymsp->__Vcoverage[2931]);
            }
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                      >> 1U)))) {
            if ((1U & (~ ((4U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                        >> 3U))) | 
                          (5U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                        >> 3U))))))) {
                ++(vlSymsp->__Vcoverage[2932]);
            }
        }
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        if (VL_GTES_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                        (0xfffffU 
                                                         & vlTOPp->opl3__DOT__channels__DOT__self[0U])))) {
            if (VL_LTES_III(1,32,32, 0xffff8000U, VL_EXTENDS_II(32,20, 
                                                                (0xfffffU 
                                                                 & vlTOPp->opl3__DOT__channels__DOT__self[0U])))) {
                ++(vlSymsp->__Vcoverage[684]);
            }
        }
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        if (VL_GTES_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                        (0xfffffU 
                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             << 0xcU) 
                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                               >> 0x14U)))))) {
            if (VL_LTES_III(1,32,32, 0xffff8000U, VL_EXTENDS_II(32,20, 
                                                                (0xfffffU 
                                                                 & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     << 0xcU) 
                                                                    | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                       >> 0x14U)))))) {
                ++(vlSymsp->__Vcoverage[681]);
            }
        }
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        if (VL_GTES_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                        (0xfffffU 
                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             << 0xcU) 
                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                               >> 0x14U)))))) {
            if (VL_GTS_III(1,32,32, 0xffff8000U, VL_EXTENDS_II(32,20, 
                                                               (0xfffffU 
                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                    << 0xcU) 
                                                                   | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                      >> 0x14U)))))) {
                ++(vlSymsp->__Vcoverage[680]);
            }
        }
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        if (VL_GTES_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                        (0xfffffU 
                                                         & vlTOPp->opl3__DOT__channels__DOT__self[0U])))) {
            if (VL_GTS_III(1,32,32, 0xffff8000U, VL_EXTENDS_II(32,20, 
                                                               (0xfffffU 
                                                                & vlTOPp->opl3__DOT__channels__DOT__self[0U])))) {
                ++(vlSymsp->__Vcoverage[683]);
            }
        }
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        if (VL_LTS_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                       (0xfffffU 
                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                            << 0xcU) 
                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                              >> 0x14U)))))) {
            ++(vlSymsp->__Vcoverage[682]);
        }
    }
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        if (VL_LTS_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                       (0xfffffU 
                                                        & vlTOPp->opl3__DOT__channels__DOT__self[0U])))) {
            ++(vlSymsp->__Vcoverage[685]);
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                ++(vlSymsp->__Vcoverage[962]);
            }
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                               << 0x11U) | (((0xdU 
                                              == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                             << 0x10U) 
                                            | (((8U 
                                                 == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                << 0xfU) 
                                               | (((7U 
                                                    == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                   << 0xeU) 
                                                  | (((6U 
                                                       == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                      << 0xdU) 
                                                     | (((0x11U 
                                                          == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                         << 0xcU) 
                                                        | (((0x10U 
                                                             == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                            << 0xbU) 
                                                           | (((0xfU 
                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                               << 0xaU) 
                                                              | (((0xbU 
                                                                   == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                  << 9U) 
                                                                 | (((0xaU 
                                                                      == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                     << 8U) 
                                                                    | (((9U 
                                                                         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                        << 7U) 
                                                                       | (((5U 
                                                                            == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                           << 6U) 
                                                                          | (((4U 
                                                                               == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                              << 5U) 
                                                                             | (((3U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 4U) 
                                                                                | (((0xcU 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 3U) 
                                                                                | (((2U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 2U) 
                                                                                | (((1U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))))))))))))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: control_operators.sv:380: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 380, "");
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        if ((0xdU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                            if ((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                                ++(vlSymsp->__Vcoverage[970]);
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                 | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
              | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
             | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            ++(vlSymsp->__Vcoverage[959]);
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((8U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        if ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                            ++(vlSymsp->__Vcoverage[969]);
                        }
                    }
                }
            }
        }
    }
    if (((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
          | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
         | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        ++(vlSymsp->__Vcoverage[958]);
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        ++(vlSymsp->__Vcoverage[968]);
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    ++(vlSymsp->__Vcoverage[965]);
                }
            }
        }
    }
    if (Verilated::assertOn()) {
        if (VL_UNLIKELY((1U & (~ ((~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
                                      & (3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) 
                                  | ((vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                      >> 0x13U) & (0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                                       >> 0xdU))))))))) {
            VL_WRITEF("[%0t] %%Error: control_operators.sv:543: Assertion failed in %Nopl3.channels.control_operators.ERROR_operators_not_aligned_for_modulation: 'assert' failed.\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/channels/src/control_operators.sv", 543, "");
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
         != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
        ++(vlSymsp->__Vcoverage[1026]);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
         == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
        ++(vlSymsp->__Vcoverage[1025]);
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                    ++(vlSymsp->__Vcoverage[960]);
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                    ++(vlSymsp->__Vcoverage[961]);
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                        ++(vlSymsp->__Vcoverage[964]);
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                        ++(vlSymsp->__Vcoverage[963]);
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        if ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                            ++(vlSymsp->__Vcoverage[967]);
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ ((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        if ((1U & (~ (((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                             | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                            | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                           | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                          | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                         | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                        | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                       | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                      | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
            if ((6U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                if ((7U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        if ((0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) {
                            ++(vlSymsp->__Vcoverage[966]);
                        }
                    }
                }
            }
        }
    }
    if (((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out) 
           >> 2U) & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        ++(vlSymsp->__Vcoverage[3278]);
    }
    if ((1U & (~ ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out) 
                    >> 2U) & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
                  & (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        ++(vlSymsp->__Vcoverage[3279]);
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        ++(vlSymsp->__Vcoverage[2514]);
    }
    if ((1U & (~ (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
                   & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
                  & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        ++(vlSymsp->__Vcoverage[2515]);
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        ++(vlSymsp->__Vcoverage[3294]);
    }
    if ((1U & (~ (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
                   & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
                  & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))) {
        ++(vlSymsp->__Vcoverage[3295]);
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        if ((0x33ffU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1))) {
            ++(vlSymsp->__Vcoverage[2512]);
        }
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        if ((0x33ffU != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1))) {
            ++(vlSymsp->__Vcoverage[2513]);
        }
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        if ((0U != (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num))) {
            ++(vlSymsp->__Vcoverage[3292]);
        }
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        if ((1U & (~ (IData)((0U != (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num)))))) {
            ++(vlSymsp->__Vcoverage[3293]);
        }
    }
    vlTOPp->__Vdly__opl3__DOT__sample_clk_gen__DOT__counter 
        = ((0xffU == (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter))
            ? 0U : (0xffU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)) 
           | (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                    << 1U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0x7eU & (IData)(vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state;
    if ((1U & (~ VL_ONEHOT_I((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1)) 
                               << 3U) | (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1)) 
                                          << 2U) | 
                                         (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1)) 
                                           << 1U) | 
                                          (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: ksl_add_rom.sv:90: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator.ksl_add_rom: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/operator/src/ksl_add_rom.sv", 90, "");
        }
    }
    if ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2 = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2 
                = (VL_GTES_III(1,32,32, 0U, VL_EXTENDS_II(32,8, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)))
                    ? 0U : (0xffU & (VL_EXTENDS_II(32,8, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)) 
                                     << 1U)));
        } else {
            if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2 
                    = (VL_GTES_III(1,32,32, 0U, VL_EXTENDS_II(32,8, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)))
                        ? 0U : (0xffU & VL_EXTENDS_II(32,8, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1))));
            } else {
                if ((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2 
                        = (VL_GTES_III(1,32,32, 0U, 
                                       VL_EXTENDS_II(32,8, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)))
                            ? 0U : (0xffU & (VL_EXTENDS_II(32,8, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1)) 
                                             << 2U)));
                }
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5 
        = ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
            ? ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                ? ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? 0U : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                     ? 1U : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                              ? 1U : 
                                             ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                               ? 1U
                                               : 2U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? 2U : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                             ? 2U : 3U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? 3U : 4U)) : (
                                                   (4U 
                                                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                      ? 4U
                                                      : 5U)
                                                     : 5U)
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                     ? 6U
                                                     : 7U))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 7U : 8U) : 
                                   ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                     ? 8U : 9U)) : 
                               ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                 ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                     ? 9U : 0xaU) : 
                                ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                  ? 0xaU : 0xbU))) : 
                           ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                             ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                 ? 0xcU : 0xdU) : (
                                                   (2U 
                                                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                     ? 0xeU
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                     ? 0xfU
                                                     : 0x10U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? 0x11U : ((1U 
                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                ? 0x12U
                                                : 0x13U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? 0x14U : ((1U 
                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                ? 0x15U
                                                : 0x16U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? 0x17U : ((1U 
                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                                ? 0x18U
                                                : 0x19U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1aU : 0x1bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1cU : 0x1dU))))))
                : ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1eU : 0x1fU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x20U : 0x21U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x22U : 0x23U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x24U : 0x25U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x26U : 0x27U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x28U : 0x29U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x2aU : 0x2bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x2dU : 0x2eU))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x2fU : 0x30U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x31U : 0x33U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x34U : 0x35U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x37U : 0x38U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x39U : 0x3bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x3cU : 0x3eU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x3fU : 0x40U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x42U : 0x43U)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x45U : 0x46U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x48U : 0x4aU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x4bU : 0x4dU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x4eU : 0x50U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x52U : 0x53U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x55U : 0x57U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x59U : 0x5bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x5cU : 0x5eU))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x60U : 0x62U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x64U : 0x66U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x68U : 0x6aU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x6cU : 0x6eU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x70U : 0x72U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x74U : 0x76U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x78U : 0x7aU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x7dU : 0x7fU)))))))
            : ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                ? ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x81U : 0x83U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x86U : 0x88U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x8aU : 0x8dU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x8fU : 0x92U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x94U : 0x97U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x99U : 0x9cU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x9fU : 0xa1U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xa4U : 0xa7U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xa9U : 0xacU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xafU : 0xb2U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xb5U : 0xb8U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xbbU : 0xbeU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xc1U : 0xc4U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xc7U : 0xcaU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xcdU : 0xd1U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xd4U : 0xd7U)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xdbU : 0xdeU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xe2U : 0xe5U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xe9U : 0xecU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xf0U : 0xf4U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xf8U : 0xfbU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0xffU : 0x103U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x107U : 0x10bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x10fU : 0x114U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x118U : 0x11cU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x121U : 0x125U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x129U : 0x12eU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x133U : 0x137U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x13cU : 0x141U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x146U : 0x14bU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x150U : 0x155U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x15bU : 0x160U))))))
                : ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x166U : 0x16bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x171U : 0x177U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x17cU : 0x182U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x188U : 0x18fU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x195U : 0x19bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1a2U : 0x1a9U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1b0U : 0x1b7U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1beU : 0x1c5U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1cdU : 0x1d4U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1dcU : 0x1e4U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1ecU : 0x1f5U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x1fdU : 0x206U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x20fU : 0x218U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x222U : 0x22cU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x236U : 0x240U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x24bU : 0x256U)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x261U : 0x26dU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x279U : 0x286U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x293U : 0x2a0U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x2afU : 0x2bdU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x2cdU : 0x2dcU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x2edU : 0x2ffU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x311U : 0x324U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x339U : 0x34eU))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x365U : 0x37eU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x398U : 0x3b5U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x3d3U : 0x3f5U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x41aU : 0x443U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x471U : 0x4a6U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x4e4U : 0x52eU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x58bU : 0x607U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta))
                                        ? 0x6c3U : 0x859U))))))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p4;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out) 
                   << 1U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0xeU & (IData)(vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2 
        = (7U & ((0U != (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                               >> 0xaU))) ? (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1))
                  : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                   << 1U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0xeU & (IData)(vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
        = (0xffffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                        << 6U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
        = ((0xffffc0U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out) 
           | (0x3fU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                    << 1U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = ((0x7eU & (IData)(vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1 
            = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_new_p2;
        if ((0x11U >= (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                                >> 5U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                            >> 5U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_new_p2;
        if ((0x11U >= (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                                >> 5U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                            >> 5U));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1 
        = ((0x3cU < ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
                     + (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                                 << 2U)))) ? 0x3cU : 
           (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
                     + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                        << 2U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum;
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) | (1U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                >> 6U)))) | (3U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                 >> 6U)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 6U)))) | (5U == (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                            >> 6U)))) | (7U == (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U))))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1 
            = ((0U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                               >> 6U))) ? 0U : ((1U 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))
                                                 ? 0x20U
                                                 : 
                                                ((2U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U)))
                                                  ? 0x28U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))
                                                   ? 0x2dU
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (0xfU 
                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                        >> 6U)))
                                                    ? 0x30U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (0xfU 
                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                         >> 6U)))
                                                     ? 0x33U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                          >> 6U)))
                                                      ? 0x35U
                                                      : 0x37U)))))));
    } else {
        if (((((((((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) | (9U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                   >> 6U)))) 
                  | (0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                      >> 6U)))) | (0xbU 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                       >> 6U)))) 
                | (0xcU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                    >> 6U)))) | (0xdU 
                                                 == 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                     >> 6U)))) 
              | (0xeU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                  >> 6U)))) | (0xfU 
                                               == (0xfU 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                      >> 6U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1 
                = ((8U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                   >> 6U))) ? 0x38U
                    : ((9U == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                       >> 6U))) ? 0x3aU
                        : ((0xaU == (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                             >> 6U)))
                            ? 0x3bU : ((0xbU == (0xfU 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                    >> 6U)))
                                        ? 0x3cU : (
                                                   (0xcU 
                                                    == 
                                                    (0xfU 
                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                        >> 6U)))
                                                    ? 0x3dU
                                                    : 
                                                   ((0xdU 
                                                     == 
                                                     (0xfU 
                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                         >> 6U)))
                                                     ? 0x3eU
                                                     : 
                                                    ((0xeU 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                                          >> 6U)))
                                                      ? 0x3fU
                                                      : 0x40U)))))));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out)) 
           | (1U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob) 
                    >> 6U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__dvb;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
        = (0x7ffffU & ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p1 
                        * (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1)) 
                       >> 1U));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (8U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__nts 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 6U));
        }
    }
    if ((0U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                      >> 0x12U)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5 
            = (0x7ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5));
    } else {
        if ((1U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                          >> 0x12U)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5 
                = (0x800U | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5));
        } else {
            if ((2U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                              >> 0x12U)))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5 
                    = (0x800U | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5));
            } else {
                if ((3U == (3U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                  >> 0x12U)))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5 
                        = (0x7ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5));
                }
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5 
        = ((0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)) 
           | (0x7ffU & ((0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4)
                         ? ((~ (0xffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                         >> 0xaU))) 
                            << 3U) : (0x7f8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                                >> 7U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2 
        = (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1)
                     ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)
                     : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
                        >> 2U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1 
        = (0x3fU & ((7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                           >> 2U)) - (IData)(8U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6;
    vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1 
        = vlTOPp->opl3__DOT__channels__DOT__channel_valid;
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (0xfU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (0xfU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT__in_r0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__hh;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT__in_r0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tc;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT__in_r0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tom;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT__in_r0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sd;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT__in_r0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bd;
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
        = (0x1fffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                        << 3U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
        = ((0x1ffff8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type));
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb0U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        vlTOPp->led = ((0xeU & (IData)(vlTOPp->led)) 
                       | (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 5U)));
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb1U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        vlTOPp->led = ((0xdU & (IData)(vlTOPp->led)) 
                       | (2U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 4U)));
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb2U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        vlTOPp->led = ((0xbU & (IData)(vlTOPp->led)) 
                       | (4U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 3U)));
    }
    if ((((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x11U) 
          & (~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U))) 
         & (0xb3U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                               >> 8U))))) {
        vlTOPp->led = ((7U & (IData)(vlTOPp->led)) 
                       | (8U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 2U)));
    }
    vlTOPp->opl3__DOT__channels__DOT__ops_done_pulse 
        = (((vlTOPp->opl3__DOT__channels__DOT__operator_out 
             >> 0x13U) & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                          >> 0x12U)) & (0x11U == (0x1fU 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                                     >> 0xdU))));
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U) 
             & (5U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__is_new 
                = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out 
        = (0xfffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                     << 3U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out 
        = ((0xff8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type));
    vlTOPp->opl3__DOT__channels__DOT__state = ((IData)(vlTOPp->opl3__DOT__sample_clk_en)
                                                ? 0U
                                                : vlTOPp->opl3__DOT__channels__DOT__next_state);
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = (0x1fffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                        << 3U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = ((0x1ffff8U & vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0xaU))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0xaU)));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0xaU))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0xaU)));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_p1;
        if ((0x11U >= (0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_p1;
        if ((0x11U >= (0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p6 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ryt_p1 
        = vlTOPp->opl3__DOT__channels__DOT__ryt;
    VL_SHIFTL_WWI(130,130,32, __Vtemp12, vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out, 0x1aU);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[0U] 
        = __Vtemp12[0U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[1U] 
        = __Vtemp12[1U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[2U] 
        = __Vtemp12[2U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[3U] 
        = __Vtemp12[3U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[4U] 
        = (3U & __Vtemp12[4U]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[0U] 
        = ((0xfc000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[0U]) 
           | vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob);
    vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vcellout__bankb_sr__out)) 
           | (1U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                    >> 0x11U)));
    vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_r_p1 
        = (0xffffffU & (VL_EXTENDS_II(24,16, (IData)(vlTOPp->opl3__DOT__channels__DOT__channel_r)) 
                        << 6U));
    vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_l_p1 
        = (0xffffffU & (VL_EXTENDS_II(24,16, (IData)(vlTOPp->opl3__DOT__channels__DOT__channel_l)) 
                        << 6U));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out)) 
           | (1U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                    >> 0x11U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p6 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_out_p6 
        = ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
            ? ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                ? ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0U : 3U) : 
                                   ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                     ? 6U : 8U)) : 
                               ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                 ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                     ? 0xbU : 0xeU)
                                 : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                     ? 0x11U : 0x14U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x16U : 0x19U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1cU : 0x1fU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x22U : 0x25U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x28U : 0x2aU))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2dU : 0x30U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x33U : 0x36U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x39U : 0x3cU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3fU : 0x42U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x45U : 0x48U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x4bU : 0x4eU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x51U : 0x54U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x57U : 0x5aU)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x5dU : 0x60U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x63U : 0x66U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x69U : 0x6cU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x6fU : 0x72U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x75U : 0x78U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x7bU : 0x7eU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x82U : 0x85U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x88U : 0x8bU))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x8eU : 0x91U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x94U : 0x98U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x9bU : 0x9eU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xa1U : 0xa4U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xa8U : 0xabU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xaeU : 0xb1U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xb5U : 0xb8U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xbbU : 0xbeU))))))
                : ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xc2U : 0xc5U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xc8U : 0xccU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xcfU : 0xd2U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xd6U : 0xd9U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xdcU : 0xe0U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xe3U : 0xe7U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xeaU : 0xedU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xf1U : 0xf4U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xf8U : 0xfbU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0xffU : 0x102U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x106U : 0x109U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x10cU : 0x110U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x114U : 0x117U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x11bU : 0x11eU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x122U : 0x125U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x129U : 0x12cU)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x130U : 0x134U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x137U : 0x13bU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x13eU : 0x142U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x146U : 0x149U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x14dU : 0x151U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x154U : 0x158U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x15cU : 0x160U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x163U : 0x167U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x16bU : 0x16fU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x172U : 0x176U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x17aU : 0x17eU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x181U : 0x185U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x189U : 0x18dU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x191U : 0x195U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x199U : 0x19cU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1a0U : 0x1a4U)))))))
            : ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                ? ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1a8U : 0x1acU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1b0U : 0x1b4U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1b8U : 0x1bcU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1c0U : 0x1c4U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1c8U : 0x1ccU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1d0U : 0x1d4U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1d8U : 0x1dcU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1e0U : 0x1e4U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1e8U : 0x1ecU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1f0U : 0x1f5U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x1f9U : 0x1fdU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x201U : 0x205U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x209U : 0x20eU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x212U : 0x216U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x21aU : 0x21eU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x223U : 0x227U)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x22bU : 0x230U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x234U : 0x238U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x23cU : 0x241U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x245U : 0x249U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x24eU : 0x252U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x257U : 0x25bU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x25fU : 0x264U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x268U : 0x26dU))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x271U : 0x276U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x27aU : 0x27fU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x283U : 0x288U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x28cU : 0x291U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x295U : 0x29aU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x29eU : 0x2a3U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2a8U : 0x2acU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2b1U : 0x2b5U))))))
                : ((0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                    ? ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2baU : 0x2bfU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2c4U : 0x2c8U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2cdU : 0x2d2U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2d6U : 0x2dbU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2e0U : 0x2e5U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2e9U : 0x2eeU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2f3U : 0x2f8U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x2fdU : 0x302U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x306U : 0x30bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x310U : 0x315U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x31aU : 0x31fU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x324U : 0x329U)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x32eU : 0x333U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x338U : 0x33dU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x342U : 0x347U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x34cU : 0x351U)))))
                    : ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                        ? ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x356U : 0x35bU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x360U : 0x365U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x36aU : 0x370U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x375U : 0x37aU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x37fU : 0x384U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x38aU : 0x38fU))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x394U : 0x399U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x39fU : 0x3a4U))))
                        : ((8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                            ? ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3a9U : 0x3aeU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3b4U : 0x3b9U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3bfU : 0x3c4U)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3c9U : 0x3cfU)))
                            : ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                ? ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3d4U : 0x3daU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3dfU : 0x3e4U))
                                : ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                    ? ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3eaU : 0x3efU)
                                    : ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5))
                                        ? 0x3f5U : 0x3faU))))))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p5 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out 
        = (0x7fffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                      << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out 
        = ((0x7fe0U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
        = (0xfffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                       << 5U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
        = ((0xfffe0U & vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num;
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
        = (0x7ffffffffULL & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                             << 5U));
    vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
        = ((0x7ffffffe0ULL & vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out) 
           | (IData)((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
        = (0x7ffffffffULL & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                             << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
        = ((0x7ffffffe0ULL & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out) 
           | (IData)((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
        = (0x7ffffffffULL & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
                             << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
        = ((0x7ffffffe0ULL & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out) 
           | (IData)((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1 
        = vlTOPp->opl3__DOT__channels__DOT__connection_sel;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out) 
                   << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out 
        = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1 
        = (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__delay_counter 
        = (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
            == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
           & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__delay_counter)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1 
            = ((0x33ffU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1))
                ? 0U : (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1))));
    }
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num 
            = (0xffffffU & ((0U != (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num))
                             ? (0x400181U ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num 
                                             >> 1U))
                             : (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num 
                                >> 1U)));
    }
    if (((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out) 
           >> 2U) & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_friend 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
    }
    if (((((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           | (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
          | (2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
         | (0xcU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 = 1U;
    } else {
        if ((((((((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                    | (4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                   | (5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                  | (9U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                 | (0xaU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
                | (0xbU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
               | (0xfU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
              | (0x10U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) 
             | (0x11U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 = 0U;
        } else {
            if ((6U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 
                    = (1U & ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                              ? (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                    >> 3U)) : (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel))));
            } else {
                if ((7U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 
                        = (1U & ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                  ? (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                        >> 4U)) : (~ 
                                                   ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                    >> 1U))));
                } else {
                    if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 
                            = (1U & ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                                      ? (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                            >> 5U))
                                      : (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                            >> 2U))));
                    } else {
                        if ((0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 
                                = (1U & (~ ((0x12U 
                                             >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))));
                        } else {
                            if ((0xeU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))) {
                                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1 
                                    = (1U & (~ ((0x12U 
                                                 >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__ryt))));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (vlTOPp->__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2328]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__out 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__out)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p))) {
        ++(vlSymsp->__Vcoverage[2284]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p))) {
        ++(vlSymsp->__Vcoverage[2285]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__reset_mem_done_pulse))) {
        ++(vlSymsp->__Vcoverage[2147]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__reset_mem_done_pulse 
            = (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self))) {
        ++(vlSymsp->__Vcoverage[2161]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self))) {
        ++(vlSymsp->__Vcoverage[2162]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self))) {
        ++(vlSymsp->__Vcoverage[2163]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self))) {
        ++(vlSymsp->__Vcoverage[2164]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self))) {
        ++(vlSymsp->__Vcoverage[2165]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self))) {
        ++(vlSymsp->__Vcoverage[2166]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self)));
    }
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        ++(vlSymsp->__Vcoverage[2180]);
    }
    if ((0U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            ++(vlSymsp->__Vcoverage[2185]);
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state) 
                               << 1U) | (0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: mem_multi_bank_reset.sv:108: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator.state_mem: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/2.sim/../1.hw/modules/misc/src/mem_multi_bank_reset.sv", 108, "");
        }
    }
    if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        ++(vlSymsp->__Vcoverage[2188]);
    }
    if ((1U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        ++(vlSymsp->__Vcoverage[2189]);
    }
    if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        ++(vlSymsp->__Vcoverage[2191]);
    }
    if ((1U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        ++(vlSymsp->__Vcoverage[2192]);
    }
    if ((0U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U == (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                              >> 6U)))) {
                    ++(vlSymsp->__Vcoverage[2182]);
                }
            }
        }
    }
    if ((0U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U == (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                ++(vlSymsp->__Vcoverage[2183]);
            }
        }
    }
    if ((0U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U == (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                if ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self))) {
                    ++(vlSymsp->__Vcoverage[2181]);
                }
            }
        }
    }
    if ((0U != vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U != (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                ++(vlSymsp->__Vcoverage[2184]);
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self;
    if ((0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self = 0U;
    } else {
        if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
            if ((0x11U == (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                    >> 1U)))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self 
                    = (0x41U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self));
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self 
                    = ((0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self))
                        ? (1U | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self))
                        : ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)) 
                           | (0x40U & (((IData)(1U) 
                                        + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                           >> 6U)) 
                                       << 6U))));
            } else {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self 
                    = ((0x41U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self)) 
                       | (0x3eU & (((IData)(1U) + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                                                   >> 1U)) 
                                   << 1U)));
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1 
        = (3U & ((IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem.dob) 
                 >> 6U));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1929]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xfeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1930]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xfdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1931]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xfbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1932]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xf7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1933]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1934]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1935]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0xbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2))) {
        ++(vlSymsp->__Vcoverage[1936]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2 
            = ((0x7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2667]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2668]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2669]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2670]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2671]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xfefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2672]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xfdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2673]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xfbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2674]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xf7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2675]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xeffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2676]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xdffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2677]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0xbffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5))) {
        ++(vlSymsp->__Vcoverage[2678]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5 
            = ((0x7ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2826]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1feU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2827]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1fdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2828]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1fbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2829]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1f7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2830]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1efU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2831]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1dfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2832]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x1bfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2833]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0x17fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5))) {
        ++(vlSymsp->__Vcoverage[2834]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5 
            = ((0xffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p4 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__env_p3;
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2))) {
        ++(vlSymsp->__Vcoverage[1836]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2))) {
        ++(vlSymsp->__Vcoverage[1837]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2))) {
        ++(vlSymsp->__Vcoverage[1838]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__sample_clk_en_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2314]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__sample_clk_en_sr__DOT____Vtogcov__out 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__sample_clk_en_sr__DOT____Vtogcov__out)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2286]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[2287]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea 
        = (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
                  & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)) 
                 >> 1U));
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2083]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out 
            = ((0xfbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2084]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out 
            = ((0xf7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x100000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2085]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out 
            = ((0xefffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out) 
               | (0x100000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x200000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2086]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out 
            = ((0xdfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out) 
               | (0x200000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x400000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2087]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out 
            = ((0xbfffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out) 
               | (0x400000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x800000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                      ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[2088]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out 
            = ((0x7fffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tl_sr__DOT____Vtogcov__out) 
               | (0x800000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2021]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3fffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2022]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3fffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2023]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3fffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2024]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3fff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2025]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3ffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2026]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3ffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2027]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3ffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2028]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3ff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2029]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3feffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2030]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3fdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2031]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3fbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2032]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3f7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2033]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3efffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2034]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3dfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2035]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x3bfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2036]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x37fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2037]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x2ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p))) {
        ++(vlSymsp->__Vcoverage[2038]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p 
            = ((0x1ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sample_clk_en_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[1616]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sample_clk_en_sr__DOT____Vtogcov__out 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sample_clk_en_sr__DOT____Vtogcov__out)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[1312]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[1313]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[1314]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[1315]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[1316]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[1317]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1873]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1874]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1875]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1876]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1877]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1878]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1879]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1880]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1881]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1882]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1883]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1884]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1))) {
        ++(vlSymsp->__Vcoverage[1885]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_new_p2 
        = (0x7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1);
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1))) {
        ++(vlSymsp->__Vcoverage[2208]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1))) {
        ++(vlSymsp->__Vcoverage[2209]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1))) {
        ++(vlSymsp->__Vcoverage[2210]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1))) {
        ++(vlSymsp->__Vcoverage[2211]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1))) {
        ++(vlSymsp->__Vcoverage[2212]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1))) {
        ++(vlSymsp->__Vcoverage[2213]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                >> 7U) ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1))) {
        ++(vlSymsp->__Vcoverage[1887]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1 
            = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1)) 
               | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                        >> 7U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                >> 8U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1 
                          >> 1U)))) {
        ++(vlSymsp->__Vcoverage[1888]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1 
            = ((5U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1)) 
               | (2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                        >> 7U)));
    }
    if ((1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                >> 9U) ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1 
                          >> 2U)))) {
        ++(vlSymsp->__Vcoverage[1889]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1)) 
               | (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                        >> 7U)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1896]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3feU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1897]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3fdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1898]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3fbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1899]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3f7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1900]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3efU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1901]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3dfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1))) {
        ++(vlSymsp->__Vcoverage[1902]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1 
            = ((0x3bfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1 
        = (7U & ((3U == (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                               >> 0xaU))) ? (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                                                   >> 8U))
                  : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                     >> 7U)));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2092]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2093]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x7dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2094]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x7bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2095]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x77U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2096]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x6fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2097]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x5fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1))) {
        ++(vlSymsp->__Vcoverage[2098]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__key_on_pulse_p1)) {
        ++(vlSymsp->__Vcoverage[2300]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__key_on_pulse_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1;
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out))) {
        ++(vlSymsp->__Vcoverage[1866]);
    }
    if ((1U & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out) 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[1867]);
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[1869]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_sr__DOT____Vtogcov__out 
            = ((3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_sr__DOT____Vtogcov__out)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p))) {
        ++(vlSymsp->__Vcoverage[1839]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p))) {
        ++(vlSymsp->__Vcoverage[1840]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p 
            = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sample_clk_en_sr__DOT____Vtogcov__out))) {
        ++(vlSymsp->__Vcoverage[3903]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sample_clk_en_sr__DOT____Vtogcov__out 
            = ((0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sample_clk_en_sr__DOT____Vtogcov__out)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[793]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[794]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[795]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[796]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[797]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p))) {
        ++(vlSymsp->__Vcoverage[798]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__dvb_p1)) {
        ++(vlSymsp->__Vcoverage[1904]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__dvb_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__dvb 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 6U));
        }
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1815]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1816]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1817]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1818]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1819]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1820]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1821]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1822]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1823]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1824]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1825]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1826]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1827]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1828]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1829]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1830]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1831]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1832]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1833]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2))) {
        ++(vlSymsp->__Vcoverage[1834]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0;
    if (((((((((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
               | (1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (3U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
            | (4U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
           | (5U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
          | (6U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
         | (7U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1 
            = ((0U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                ? 1U : ((1U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                         ? 2U : ((2U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                  ? 4U : ((3U == (0xfU 
                                                  & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                           ? 6U : (
                                                   (4U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                                    ? 8U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                                     ? 0xaU
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                                      ? 0xcU
                                                      : 0xeU)))))));
    } else {
        if (((((((((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))) 
                   | (9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                  | (0xaU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                 | (0xbU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
                | (0xcU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
               | (0xdU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
              | (0xeU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))) 
             | (0xfU == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1 
                = ((8U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                    ? 0x10U : ((9U == (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                ? 0x12U : ((0xaU == 
                                            (0xfU & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                            ? 0x14U
                                            : ((0xbU 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                                ? 0x14U
                                                : (
                                                   (0xcU 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                                    ? 0x18U
                                                    : 
                                                   ((0xdU 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlSymsp->TOP__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem.dob)))
                                                     ? 0x18U
                                                     : 0x1eU))))));
        }
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0U])) {
        ++(vlSymsp->__Vcoverage[1292]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [1U])) {
        ++(vlSymsp->__Vcoverage[1293]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [1U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [2U])) {
        ++(vlSymsp->__Vcoverage[1294]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [2U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [3U])) {
        ++(vlSymsp->__Vcoverage[1295]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [3U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [4U])) {
        ++(vlSymsp->__Vcoverage[1296]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [4U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [5U])) {
        ++(vlSymsp->__Vcoverage[1297]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [5U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [6U])) {
        ++(vlSymsp->__Vcoverage[1298]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [6U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [7U])) {
        ++(vlSymsp->__Vcoverage[1299]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [7U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [8U])) {
        ++(vlSymsp->__Vcoverage[1300]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [8U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [0U])) {
        ++(vlSymsp->__Vcoverage[1268]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [0U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [1U])) {
        ++(vlSymsp->__Vcoverage[1269]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [1U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [2U])) {
        ++(vlSymsp->__Vcoverage[1270]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [2U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [3U])) {
        ++(vlSymsp->__Vcoverage[1271]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [3U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [4U])) {
        ++(vlSymsp->__Vcoverage[1272]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [4U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [5U])) {
        ++(vlSymsp->__Vcoverage[1273]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [5U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [6U])) {
        ++(vlSymsp->__Vcoverage[1274]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [6U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [7U])) {
        ++(vlSymsp->__Vcoverage[1275]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [7U];
    }
    if ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
         [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
         [8U])) {
        ++(vlSymsp->__Vcoverage[1276]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
            [8U];
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__nts) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__nts)) {
        ++(vlSymsp->__Vcoverage[915]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__nts 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__nts;
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2782]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2783]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2784]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2785]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2786]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xfefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2787]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xfdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2788]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xfbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2789]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xf7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2790]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xeffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2791]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xdffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2792]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0xbffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5))) {
        ++(vlSymsp->__Vcoverage[2793]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5 
            = ((0x7ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5)));
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2))) {
        ++(vlSymsp->__Vcoverage[1976]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2))) {
        ++(vlSymsp->__Vcoverage[1977]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2))) {
        ++(vlSymsp->__Vcoverage[1978]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2))) {
        ++(vlSymsp->__Vcoverage[1979]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2))) {
        ++(vlSymsp->__Vcoverage[1980]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2))) {
        ++(vlSymsp->__Vcoverage[1981]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__dam;
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1))) {
        ++(vlSymsp->__Vcoverage[2100]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1 
            = ((0x3eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1))) {
        ++(vlSymsp->__Vcoverage[2101]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1 
            = ((0x3dU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1))) {
        ++(vlSymsp->__Vcoverage[2102]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1 
            = ((0x3bU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1))) {
        ++(vlSymsp->__Vcoverage[2103]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1 
            = ((0x37U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1))) {
        ++(vlSymsp->__Vcoverage[2104]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1 
            = ((0x2fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1))) {
        ++(vlSymsp->__Vcoverage[2105]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1 
            = ((0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1 
        = (0xffU & VL_EXTENDS_II(8,7, (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
                                                + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
                                                   << 3U)))));
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[779]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[780]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[781]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[782]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[783]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[784]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[785]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[786]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[787]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[788]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[789]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x1bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[790]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0x17ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1))) {
        ++(vlSymsp->__Vcoverage[791]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1 
            = ((0xfffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1)));
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1) 
         ^ vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT____Vtogcov__sample_valid_opl3_p1)) {
        ++(vlSymsp->__Vcoverage[3954]);
        vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT____Vtogcov__sample_valid_opl3_p1 
            = vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1;
    }
    vlTOPp->sample_valid = vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1;
    vlTOPp->opl3__DOT__channels__DOT__channel_valid 
        = (1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                         >> 4U)));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[1290]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) {
        ++(vlSymsp->__Vcoverage[1266]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1202]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1203]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1204]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1205]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1206]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1207]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1208]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1209]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1210]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1211]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1212]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1213]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1214]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1215]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1216]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1217]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1218]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1219]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1220]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1221]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1222]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1223]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1224]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1225]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1226]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1227]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1228]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1229]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1230]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1231]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1232]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1233]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1234]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1235]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1236]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1237]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1145]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1146]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1147]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [0U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [0U]))) {
        ++(vlSymsp->__Vcoverage[1148]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[0U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [0U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [0U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1149]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1150]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1151]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [1U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [1U]))) {
        ++(vlSymsp->__Vcoverage[1152]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[1U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [1U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [1U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1153]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1154]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1155]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [2U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [2U]))) {
        ++(vlSymsp->__Vcoverage[1156]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[2U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [2U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [2U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1157]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1158]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1159]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [3U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [3U]))) {
        ++(vlSymsp->__Vcoverage[1160]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[3U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [3U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [3U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1161]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1162]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1163]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [4U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [4U]))) {
        ++(vlSymsp->__Vcoverage[1164]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[4U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [4U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [4U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1165]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1166]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1167]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [5U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [5U]))) {
        ++(vlSymsp->__Vcoverage[1168]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[5U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [5U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [5U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1169]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1170]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1171]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [6U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [6U]))) {
        ++(vlSymsp->__Vcoverage[1172]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[6U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [6U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [6U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1173]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1174]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1175]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [7U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [7U]))) {
        ++(vlSymsp->__Vcoverage[1176]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[7U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [7U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [7U]));
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1177]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((0xeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1178]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((0xdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1179]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((0xbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [8U] ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
               [8U]))) {
        ++(vlSymsp->__Vcoverage[1180]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[8U] 
            = ((7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram
                [8U]) | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
                         [8U]));
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3107]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3108]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3109]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3110]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3111]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3112]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3113]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3114]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3115]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3116]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3117]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3118]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3119]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3120]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3121]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3122]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3123]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3124]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3125]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3126]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
    }
    if ((1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3052]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffffeU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (1U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((2U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3053]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffffdU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (2U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((4U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3054]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffffbU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (4U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((8U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3055]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffff7U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x10U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3056]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfffefU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x10U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x20U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3057]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfffdfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x20U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x40U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3058]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfffbfU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x40U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3059]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfff7fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x80U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3060]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffeffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x100U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x200U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3061]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffdffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x200U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x400U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3062]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xffbffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x400U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x800U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3063]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xff7ffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x800U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x1000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3064]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfefffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x1000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x2000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3065]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfdfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x2000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x4000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3066]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xfbfffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x4000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x8000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3067]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xf7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x8000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x10000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3068]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xeffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x10000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x20000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3069]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xdffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x20000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x40000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3070]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0xbffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    if ((0x80000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
                     ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[3071]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob) 
               | (0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT__in_r0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__in_r0)) {
        ++(vlSymsp->__Vcoverage[1759]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__in_r0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT__in_r0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__hh 
                = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT__in_r0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__in_r0)) {
        ++(vlSymsp->__Vcoverage[1743]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__in_r0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT__in_r0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tc 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 1U));
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT__in_r0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__in_r0)) {
        ++(vlSymsp->__Vcoverage[1727]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__in_r0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT__in_r0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tom 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 2U));
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT__in_r0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__in_r0)) {
        ++(vlSymsp->__Vcoverage[1711]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__in_r0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT__in_r0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sd 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 3U));
        }
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT__in_r0) 
         ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__in_r0)) {
        ++(vlSymsp->__Vcoverage[1695]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__in_r0 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT__in_r0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bd 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 4U));
        }
    }
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2419]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2420]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2421]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2422]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2423]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2424]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x40U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2425]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7fbfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x40U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x80U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2426]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7f7fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x100U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2427]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7effU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x100U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x200U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2428]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7dffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x400U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2429]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7bffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x400U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x800U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                   ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2430]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x77ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x800U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x1000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2431]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x6fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x1000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x2000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2432]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x5fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x2000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x4000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                    ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2433]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x3fffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x4000U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2376]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2377]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffdU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2378]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ffbU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((8U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
               ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2379]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7ff7U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x10U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2380]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7fefU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
    if ((0x20U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1) 
                  ^ vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob))) {
        ++(vlSymsp->__Vcoverage[2381]);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob 
            = ((0x7fdfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob)) 
               | (0x20U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1)));
    }
}
