// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vopl3.h for the primary calling header

#include "Vopl3.h"
#include "Vopl3__Syms.h"

//==========

void Vopl3::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vopl3::eval\n"); );
    Vopl3__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/top_level/src/opl3.sv", 44, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vopl3::_eval_initial_loop(Vopl3__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/top_level/src/opl3.sv", 44, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__3(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__3\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*15:0*/ __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
    // Body
    __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs 
        = vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
    vlTOPp->__Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 = 0U;
    __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs 
        = ((0xff00U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                       << 8U)) | (IData)(vlTOPp->opl3__DOT__status));
    vlTOPp->opl3__DOT__host_if__DOT__host_status_p1 
        = (0xffU & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs) 
                    >> 8U));
    vlTOPp->opl3__DOT__host_if__DOT__wr_p2 = vlTOPp->opl3__DOT__host_if__DOT__wr_p1;
    vlTOPp->opl3__DOT__host_if__DOT__wr_p1_n = vlTOPp->wr_n;
    vlTOPp->opl3__DOT__host_if__DOT__cs_p1_n = vlTOPp->cs_n;
    if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
         & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
        vlTOPp->__Vdlyvval__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 
            = (((IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1) 
                << 8U) | (IData)(vlTOPp->opl3__DOT__host_if__DOT__din_p1));
        vlTOPp->__Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0 
            = (0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr));
    }
    vlTOPp->opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs 
        = __Vdly__opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
    vlTOPp->opl3__DOT__host_if__DOT__wr_p1 = (1U & 
                                              ((~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__cs_p1_n)) 
                                               & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1_n))));
    vlTOPp->opl3__DOT__host_if__DOT__din_p1 = vlTOPp->din;
    vlTOPp->opl3__DOT__host_if__DOT__address_p1 = vlTOPp->address;
    vlTOPp->dout = ((0U == (IData)(vlTOPp->opl3__DOT__host_if__DOT__address_p1))
                     ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__host_status_p1)
                     : 0xffU);
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__4(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__4\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vtableidx1;
    CData/*7:0*/ __Vtableidx2;
    CData/*7:0*/ __Vdly__opl3__DOT__sample_clk_gen__DOT__counter;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*2:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*2:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*7:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*5:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*5:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    CData/*6:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out;
    CData/*6:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out;
    QData/*34:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out;
    IData/*20:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*3:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
    CData/*2:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*2:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*4:0*/ __Vdlyvdim0__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    SData/*14:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    SData/*14:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    SData/*8:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    SData/*8:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    SData/*12:0*/ __Vdlyvval__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    SData/*12:0*/ __Vdlyvval__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    IData/*19:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    IData/*19:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    IData/*25:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    IData/*25:0*/ __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    WData/*159:0*/ __Vtemp3[5];
    // Body
    __Vdly__opl3__DOT__sample_clk_gen__DOT__counter 
        = vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
    __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 0U;
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
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/ksl_add_rom.sv", 63, "");
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((0xfU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                               << 0xfU) | (((0xeU == 
                                             (0xfU 
                                              & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                            << 0xeU) 
                                           | (((0xdU 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                               << 0xdU) 
                                              | (((0xcU 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                  << 0xcU) 
                                                 | (((0xbU 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                     << 0xbU) 
                                                    | (((0xaU 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                        << 0xaU) 
                                                       | (((9U 
                                                            == 
                                                            (0xfU 
                                                             & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                           << 9U) 
                                                          | (((8U 
                                                               == 
                                                               (0xfU 
                                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                              << 8U) 
                                                             | (((7U 
                                                                  == 
                                                                  (0xfU 
                                                                   & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                 << 7U) 
                                                                | (((6U 
                                                                     == 
                                                                     (0xfU 
                                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                    << 6U) 
                                                                   | (((5U 
                                                                        == 
                                                                        (0xfU 
                                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                       << 5U) 
                                                                      | (((4U 
                                                                           == 
                                                                           (0xfU 
                                                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                          << 4U) 
                                                                         | (((3U 
                                                                              == 
                                                                              (0xfU 
                                                                               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                             << 3U) 
                                                                            | (((2U 
                                                                                == 
                                                                                (0xfU 
                                                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                                << 2U) 
                                                                               | (((1U 
                                                                                == 
                                                                                (0xfU 
                                                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                                                                                << 1U) 
                                                                                | (0U 
                                                                                == 
                                                                                (0xfU 
                                                                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))))))))))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: calc_phase_inc.sv:72: Assertion failed in %Nopl3.channels.control_operators.operator.calc_phase_inc: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/calc_phase_inc.sv", 72, "");
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
            VL_WRITEF("[%0t] %%Error: control_operators.sv:383: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 383, "");
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
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/phase_generator.sv", 271, "");
        }
    }
    __Vdly__opl3__DOT__sample_clk_gen__DOT__counter 
        = ((0xffU == (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter))
            ? 0U : (0xffU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter))));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                        >> 0x19U))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                    >> 0x19U)));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                        >> 0x19U))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                                    >> 0x19U)));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1 
        = vlTOPp->opl3__DOT__channels__DOT__channel_valid;
    VL_SHIFTL_WWI(130,130,32, __Vtemp3, vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out, 0x1aU);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[0U] 
        = __Vtemp3[0U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[1U] 
        = __Vtemp3[1U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[2U] 
        = __Vtemp3[2U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[3U] 
        = __Vtemp3[3U];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[4U] 
        = (3U & __Vtemp3[4U]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[0U] 
        = ((0xfc000000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[0U]) 
           | vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob);
    if ((1U & (~ VL_ONEHOT_I((((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1)) 
                               << 3U) | (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1)) 
                                          << 2U) | 
                                         (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1)) 
                                           << 1U) | 
                                          (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: ksl_add_rom.sv:90: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator.ksl_add_rom: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/ksl_add_rom.sv", 90, "");
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
        = (0xffffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                        << 6U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
        = ((0xffffc0U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out) 
           | (0x3fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__ksl_tl_mem__dob)));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (0x1fffU & vlTOPp->opl3__DOT__channels__DOT__operator_out);
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                >> 0xdU)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                            >> 0xdU));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (0x1fffU & vlTOPp->opl3__DOT__channels__DOT__operator_out);
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                >> 0xdU)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                            >> 0xdU));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p4;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2 
        = (7U & ((0U != (4U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                               >> 0xaU))) ? (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1))
                  : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1)));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_new_p2;
        if ((0x11U >= (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                                >> 5U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
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
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                            >> 5U));
        }
    }
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                    << 1U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0x7eU & (IData)(__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0));
    vlTOPp->opl3__DOT__channels__DOT__ops_done_pulse 
        = (((vlTOPp->opl3__DOT__channels__DOT__operator_out 
             >> 0x13U) & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                          >> 0x12U)) & (0x11U == (0x1fU 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__operator_out 
                                                     >> 0xdU))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1 
        = ((0x3cU < ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
                     + (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                                 << 2U)))) ? 0x3cU : 
           (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0) 
                     + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0) 
                        << 2U))));
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
    vlTOPp->opl3__DOT__channels__DOT__state = ((IData)(vlTOPp->opl3__DOT__sample_clk_en)
                                                ? 0U
                                                : vlTOPp->opl3__DOT__channels__DOT__next_state);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out)) 
           | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob) 
                    >> 6U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)) 
           | (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0)));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out) 
                   << 1U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0xeU & (IData)(__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1 
            = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1)));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1 
        = (0x3fU & ((7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                           >> 2U)) - (IData)(8U)));
    vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_r_p1 
        = (0xffffffU & (VL_EXTENDS_II(24,16, (IData)(vlTOPp->opl3__DOT__channels__DOT__channel_r)) 
                        << 6U));
    vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_l_p1 
        = (0xffffffU & (VL_EXTENDS_II(24,16, (IData)(vlTOPp->opl3__DOT__channels__DOT__channel_l)) 
                        << 6U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                   << 1U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = ((0xeU & (IData)(__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                    << 1U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = ((0x7eU & (IData)(__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out)) 
           | (1U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                    >> 0x11U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
        = (0x7ffffU & ((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p1 
                        * (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1)) 
                       >> 1U));
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x26U)) & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                      >> 0x11U)))) {
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                           >> 0x27U))))
                ? vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [(0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                  >> 0x27U)))] : 0U);
    }
    if ((1U & ((IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                        >> 0x26U)) & (~ (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                         >> 0x11U))))) {
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                           >> 0x27U))))
                ? vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [(0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                  >> 0x27U)))] : 0U);
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out 
        = (0xfffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                     << 3U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out 
        = ((0xff8U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
        = (0x1fffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                        << 3U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
        = ((0x1ffff8U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0xaU))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
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
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0xaU)));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)
                ? 8U : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1));
        if ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra;
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)
                ? 8U : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1));
        if ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra;
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2;
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                                >> 5U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                            >> 5U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2;
        if ((0x11U >= (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                                >> 5U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                            >> 5U));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__dvb;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
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
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (0xfU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
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
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2 
        = (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1)
                     ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1)
                     : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1) 
                        >> 2U)));
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (7U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (7U & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_p1;
        if ((0x11U >= (0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
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
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ryt_p1 
        = vlTOPp->opl3__DOT__channels__DOT__ryt;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0xffU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((0x15U >= (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U));
        }
    }
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p6 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5;
    __Vtableidx2 = (0xffU & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_out_p6 
        = vlTOPp->__Vtable2_opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_out_p6
        [__Vtableidx2];
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0x3fU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2 
            = (0x3fU & vlTOPp->opl3__DOT__opl3_reg_wr);
        if ((8U >= (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                            >> 8U)))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0 
                = (0xfU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                           >> 8U));
        }
    }
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out 
        = (0x7fffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out) 
                      << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out 
        = ((0x7fe0U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out)) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
        = (0x7ffffffffULL & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
                             << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out 
        = ((0x7ffffffe0ULL & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out) 
           | (IData)((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
        = (0x7ffffffffULL & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                             << 5U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
        = ((0x7ffffffe0ULL & __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out) 
           | (IData)((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
        = (0xfffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
                       << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out 
        = ((0xfffe0U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
        = (0x7ffffffffULL & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
                             << 5U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out 
        = ((0x7ffffffe0ULL & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out) 
           | (IData)((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1 
        = vlTOPp->opl3__DOT__channels__DOT__connection_sel;
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(__Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1 
        = (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out 
        = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out) 
                   << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out 
        = ((0xeU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out 
        = (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                    << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out 
        = ((0x7eU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out) 
                 << 1U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out 
        = ((6U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out)) 
           | (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)) 
               & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address]);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address)) 
               & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address]);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address]
                : 0U);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address]
                : 0U);
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__delay_counter 
        = (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state) 
            == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
           & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__delay_counter)));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = (0x1fffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                        << 3U));
    __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = ((0x1ffff8U & __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out) 
           | (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array
              [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))] 
              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)
                  ? 7U : 3U)));
    if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
          & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1 
            = ((0x33ffU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1))
                ? 0U : (0x3fffU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1))));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
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
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                : 0U);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                : 0U);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                : 0U);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                : 0U);
    }
    if (((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out) 
           >> 2U) & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))) 
         & (0xdU == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_friend 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
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
    __Vtableidx1 = (0xffU & ((0x40000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4)
                              ? (~ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                    >> 0xaU)) : (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                                                 >> 0xaU)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5 
        = vlTOPp->__Vtable1_opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5
        [__Vtableidx1];
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                     >> 0x13U));
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0xfU))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0xfU)));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = (1U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                     >> 0x13U));
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0xfU))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0xfU)));
        }
    }
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0x14U))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0x14U)));
        }
    }
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__wea_array))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
        if ((0x11U >= (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                        >> 0x14U))))) {
            __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
            __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 = 1U;
            __Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0 
                = (0x1fU & (IData)((vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
                                    >> 0x14U)));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p6 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p5 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4;
    if (__Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out;
    vlTOPp->sample_valid = vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1;
    vlTOPp->opl3__DOT__channels__DOT__channel_valid 
        = (1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                         >> 4U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1 
        = (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__ksl_tl_mem__dob) 
                 >> 6U));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p4 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__env_p3;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_new_p2 
        = (0x7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1 
        = (7U & ((3U == (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1) 
                               >> 0xaU))) ? (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                                                   >> 8U))
                  : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1) 
                     >> 7U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1 
        = (0xffU & VL_EXTENDS_II(8,7, (0x7fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1) 
                                                + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1) 
                                                   << 3U)))));
    vlTOPp->sample_r = vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_r_p1;
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        vlTOPp->opl3__DOT__channels__DOT__channel_r 
            = (VL_LTS_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                          (0xfffffU 
                                                           & vlTOPp->opl3__DOT__channels__DOT__self[0U])))
                ? 0x7fffU : (VL_GTS_III(1,32,32, 0xffff8000U, 
                                        VL_EXTENDS_II(32,20, 
                                                      (0xfffffU 
                                                       & vlTOPp->opl3__DOT__channels__DOT__self[0U])))
                              ? 0x8000U : (0xffffU 
                                           & vlTOPp->opl3__DOT__channels__DOT__self[0U])));
    }
    vlTOPp->sample_l = vlTOPp->opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_l_p1;
    if ((1U & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                       >> 4U)))) {
        vlTOPp->opl3__DOT__channels__DOT__channel_l 
            = (VL_LTS_III(1,32,32, 0x7fffU, VL_EXTENDS_II(32,20, 
                                                          (0xfffffU 
                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                               << 0xcU) 
                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                 >> 0x14U)))))
                ? 0x7fffU : (VL_GTS_III(1,32,32, 0xffff8000U, 
                                        VL_EXTENDS_II(32,20, 
                                                      (0xfffffU 
                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                           << 0xcU) 
                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                             >> 0x14U)))))
                              ? 0x8000U : (0xffffU 
                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                               << 0xcU) 
                                              | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                 >> 0x14U)))));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea 
        = (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out) 
                  & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out)) 
                 >> 1U));
    if (((((((((0U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
               | (1U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
              | (2U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
             | (3U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
            | (4U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
           | (5U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
          | (6U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
         | (7U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1 
            = ((0U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                ? 1U : ((1U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                         ? 2U : ((2U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                  ? 4U : ((3U == (0xfU 
                                                  & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                           ? 6U : (
                                                   (4U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                                    ? 8U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                                     ? 0xaU
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                                      ? 0xcU
                                                      : 0xeU)))))));
    } else {
        if (((((((((8U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))) 
                   | (9U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
                  | (0xaU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
                 | (0xbU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
                | (0xcU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
               | (0xdU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
              | (0xeU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))) 
             | (0xfU == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1 
                = ((8U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                    ? 0x10U : ((9U == (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                ? 0x12U : ((0xaU == 
                                            (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                            ? 0x14U
                                            : ((0xbU 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                                ? 0x14U
                                                : (
                                                   (0xcU 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                                    ? 0x18U
                                                    : 
                                                   ((0xdU 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob)))
                                                     ? 0x18U
                                                     : 0x1eU))))));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p1 
        = (0xfffffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                       << (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                                 >> 2U))));
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((1U & (~ VL_ONEHOT0_I((((5U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                              >> 6U))) 
                                << 1U) | (4U == (7U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                                    >> 6U)))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: calc_rhythm_phase.sv:94: Assertion failed in %Nopl3.channels.control_operators.operator.phase_generator.calc_rhythm_phase: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/calc_rhythm_phase.sv", 94, "");
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((5U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                             >> 6U))) 
                               << 5U) | (((4U == (7U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                                     >> 6U))) 
                                          << 4U) | 
                                         (((3U == (7U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                                      >> 6U))) 
                                           << 3U) | 
                                          (((2U == 
                                             (7U & 
                                              ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                               >> 6U))) 
                                            << 2U) 
                                           | (((1U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                                    >> 6U))) 
                                               << 1U) 
                                              | (0U 
                                                 == 
                                                 (7U 
                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                                     >> 6U)))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: calc_rhythm_phase.sv:109: Assertion failed in %Nopl3.channels.control_operators.operator.phase_generator.calc_rhythm_phase: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/calc_rhythm_phase.sv", 109, "");
        }
    }
    if ((1U & (~ VL_ONEHOT0_I((((1U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                                              >> 0xfU))) 
                                << 1U) | (0U == (7U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                                                    >> 0xfU)))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: phase_generator.sv:326: Assertion failed in %Nopl3.channels.control_operators.operator.phase_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/phase_generator.sv", 326, "");
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1;
    if ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out))) {
        if (((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
             & (0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2 
                = (0x1ffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1) 
                             - ((IData)(1U) + (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1) 
                                                * (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)) 
                                               >> 3U))));
        } else {
            if (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)) 
                 | (8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1)))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2 
                    = ((0x200U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1))
                        ? 0x1ffU : (0x1ffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1)));
            }
        }
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__dam;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_p1 
        = (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                 >> 5U));
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__hh 
                = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        }
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
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tom 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 2U));
        }
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
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bd 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 4U));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array)) 
           | (1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                    & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array)) 
           | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out)) 
                    << 1U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array)) 
           | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                     >> 5U) & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out) 
                                  >> 5U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array)) 
           | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out) 
                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out)) 
                    >> 4U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U) 
             & (5U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__is_new 
                = (1U & vlTOPp->opl3__DOT__opl3_reg_wr);
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1 
        = (0x3fU & ((0x1aU < (0x3fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1) 
                                       >> 8U))) ? ((IData)(0x34U) 
                                                   + 
                                                   (~ 
                                                    ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1) 
                                                     >> 8U)))
                     : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1) 
                        >> 8U)));
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    }
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
               & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                : 0U);
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    if (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) 
         & (0x12U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1 
            = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num))
                ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram
               [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]
                : 0U);
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3 
        = (0xfffffU & ((2U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                     >> 6U))) ? (2U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num 
                                                    << 1U))
                        : (0x100U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num 
                                     << 8U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
    if ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3 
            = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out))
                ? 0U : (0xfffffU & (((4U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                   >> 3U))) 
                                     | (5U == (7U & 
                                               (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                >> 3U))))
                                     ? (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                                        + (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
                                           << 1U)) : 
                                    (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
                                     + vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2))));
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5 
        = (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p4) 
                  & (~ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
                        >> 0x13U))) ? (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p4))
                  : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p4)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6 
        = (0x1fffU & ((0x80000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p5)
                       ? (~ ((0x1fffU & (((IData)(0x400U) 
                                          + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_out_p6)) 
                                         << 1U)) >> 
                             (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p6) 
                                       >> 8U)))) : 
                      ((0x1fffU & (((IData)(0x400U) 
                                    + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_out_p6)) 
                                   << 1U)) >> (0x1fU 
                                               & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p6) 
                                                  >> 8U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1 
        = (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1)
                  ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1)
                  : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1) 
                     >> 1U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea) 
              & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out) 
                    >> 1U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array)) 
           | (0xfffffffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea) 
                              << 1U) & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out))));
    vlTOPp->opl3__DOT__channels__DOT__operator_mem_out 
        = vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    if (__Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[__Vdlyvdim0__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0] 
            = __Vdlyvval__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array
        [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out) 
                >> 1U))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1)
            ? 0U : (0x7fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array
                    [(1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out) 
                            >> 1U))]));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
        = (0x3ffffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1) 
                       + ((4U | (3U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1))) 
                          << (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1) 
                                      >> 2U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1 
        = (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1 
                 >> 0xfU));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array
        [(1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2 
        = (0xfffffU & ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out))
                        ? (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2 
                           + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2))
                        : vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6 
        = (0x1fffU & (VL_GTS_III(1,32,32, 0U, VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)))
                       ? (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6))
                       : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p6)
            ? (0x1fffU & VL_EXTENDS_II(32,13, (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6)))
            : 0U);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__env_p3 
        = ((0U != (3U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2) 
                         >> 9U))) ? 0x1ffU : (0x1ffU 
                                              & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2)));
    if (vlTOPp->opl3__DOT__sample_clk_en) {
        vlTOPp->opl3__DOT__channels__DOT__self[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__self[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__self[2U] = 0U;
    } else {
        vlTOPp->opl3__DOT__channels__DOT__self[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__next_self[0U];
        vlTOPp->opl3__DOT__channels__DOT__self[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__next_self[1U];
        vlTOPp->opl3__DOT__channels__DOT__self[2U] 
            = vlTOPp->opl3__DOT__channels__DOT__next_self[2U];
    }
    if ((1U & (~ VL_ONEHOT_I((((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state) 
                               << 1U) | (0U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: mem_multi_bank_reset.sv:108: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator.state_mem: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/misc/src/mem_multi_bank_reset.sv", 108, "");
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
    if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra 
            = (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                        >> 1U));
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra 
            = (0x1fU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                        >> 1U));
    } else {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra 
            = (0x1fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out);
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra 
            = (0x1fU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out);
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array)) 
           | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                     >> 1U) & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out) 
                                  >> 1U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array)) 
           | (2U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array)) 
           | (1U & ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)
                     ? (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                           >> 6U)) : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                                      & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out))))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array)) 
           | (2U & (((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state)
                      ? ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self) 
                         >> 6U) : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out) 
                                   & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out))) 
                    << 1U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0;
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0;
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__dam 
                = (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                         >> 7U));
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_on_pulse 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__hh) 
           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT__in_r0)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_on_pulse 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tc) 
           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT__in_r0)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_on_pulse 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__tom) 
           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT__in_r0)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_on_pulse 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sd) 
           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT__in_r0)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_on_pulse 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__bd) 
           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT__in_r0)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
        = (0xfffffU & ((4U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                     >> 6U))) ? ((0U 
                                                  != 
                                                  (0x100U 
                                                   & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_friend))
                                                  ? 0x200U
                                                  : 0x100U)
                        : ((5U == (7U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out) 
                                         >> 6U))) ? vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_friend
                            : vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3 
        = ((0U != (((0x88U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3) 
                    ^ (0x80U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                                << 5U))) | (0x20U & 
                                            (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                                             ^ (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3 
                                                << 2U)))))
            ? 2U : 0U);
    if ((1U & (~ VL_ONEHOT0_I((((7U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                              >> 0xcU))) 
                                << 1U) | (6U == (7U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                    >> 0xcU)))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: phase_generator.sv:282: Assertion failed in %Nopl3.channels.control_operators.operator.phase_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/phase_generator.sv", 282, "");
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((7U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                             >> 0xfU))) 
                               << 7U) | (((6U == (7U 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                     >> 0xfU))) 
                                          << 6U) | 
                                         (((5U == (7U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                      >> 0xfU))) 
                                           << 5U) | 
                                          (((4U == 
                                             (7U & 
                                              (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                               >> 0xfU))) 
                                            << 4U) 
                                           | (((3U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                    >> 0xfU))) 
                                               << 3U) 
                                              | (((2U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                       >> 0xfU))) 
                                                  << 2U) 
                                                 | (((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                          >> 0xfU))) 
                                                     << 1U) 
                                                    | (0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                                           >> 0xfU)))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: phase_generator.sv:314: Assertion failed in %Nopl3.channels.control_operators.operator.phase_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/phase_generator.sv", 314, "");
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5 
        = (0x1fffU & ((6U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                    >> 0xcU))) ? ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                                                  << 3U)
                       : ((7U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out 
                                        >> 0xcU))) ? 
                          ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5) 
                           + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                              << 3U)) : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5) 
                                         + ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5) 
                                            << 3U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p4 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p3;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p4 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p3;
    if ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4 
            = ((4U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out))
                ? 0U : (0xfffffU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3 
                                    + vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3)));
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out;
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6 
        = (0x1fffU & ((0U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                                    >> 0xfU))) ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)
                       : ((1U == (7U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out 
                                        >> 0xfU))) ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6)
                           : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6) 
                              << 1U))));
    vlTOPp->opl3__DOT__sample_clk_en = (0xffU == (IData)(vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1 
        = (0x3ffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1) 
                     + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p3 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__dob_array
        [(1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p3 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__dob_array
        [(1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out))];
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__wea_array)) 
           | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                     >> 3U) & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                  >> 3U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__wea_array)) 
           | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
                    >> 2U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__wea_array)) 
           | (1U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                     >> 4U) & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out) 
                                  >> 4U)))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__wea_array)) 
           | (2U & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out) 
                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out)) 
                    >> 3U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3 
        = (0x7fffffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2) 
                        << 0xaU));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
        = ((0x3ffe000U & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6) 
           | (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__out_p6));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6 
        = ((0x1fffU & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6) 
           | (0x3ffe000U & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[3U] 
                            << 5U)));
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
    vlTOPp->opl3__DOT__sample_clk_gen__DOT__counter 
        = __Vdly__opl3__DOT__sample_clk_gen__DOT__counter;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT____Vcellout__bankb_sr__out;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out 
        = __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT____Vcellout__bankb_sr__out;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__dob_array[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__dob_array[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2 
        = ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1)
            ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1)
            : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1));
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
                                VL_WRITEF("[%0t] %%Error: control_operators.sv:423: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                          64,VL_TIME_UNITED_Q(1000),
                                          vlSymsp->name());
                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 423, "");
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
                                    VL_WRITEF("[%0t] %%Error: control_operators.sv:430: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                              64,VL_TIME_UNITED_Q(1000),
                                              vlSymsp->name());
                                    VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 430, "");
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
                                        VL_WRITEF("[%0t] %%Error: control_operators.sv:437: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                  64,
                                                  VL_TIME_UNITED_Q(1000),
                                                  vlSymsp->name());
                                        VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 437, "");
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
                                            VL_WRITEF("[%0t] %%Error: control_operators.sv:444: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 444, "");
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
                                                VL_WRITEF("[%0t] %%Error: control_operators.sv:451: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                          64,
                                                          VL_TIME_UNITED_Q(1000),
                                                          vlSymsp->name());
                                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 451, "");
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
                                                VL_WRITEF("[%0t] %%Error: control_operators.sv:458: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                                                          64,
                                                          VL_TIME_UNITED_Q(1000),
                                                          vlSymsp->name());
                                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 458, "");
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
            VL_WRITEF("[%0t] %%Error: control_operators.sv:418: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 418, "");
        }
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
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((~ (vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U)) 
             & (0xbdU == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                   >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__ryt = 
                (1U & (vlTOPp->opl3__DOT__opl3_reg_wr 
                       >> 5U));
        }
    }
    if ((0x20000U & vlTOPp->opl3__DOT__opl3_reg_wr)) {
        if (((vlTOPp->opl3__DOT__opl3_reg_wr >> 0x10U) 
             & (4U == (0xffU & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                >> 8U))))) {
            vlTOPp->opl3__DOT__channels__DOT__connection_sel 
                = (0x3fU & vlTOPp->opl3__DOT__opl3_reg_wr);
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state;
    vlTOPp->opl3__DOT__opl3_reg_wr = (0x1ffffU & vlTOPp->opl3__DOT__opl3_reg_wr);
    if ((1U & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty)))) {
        if ((0x100U & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data))) {
            vlTOPp->opl3__DOT__opl3_reg_wr = ((0x3ff00U 
                                               & vlTOPp->opl3__DOT__opl3_reg_wr) 
                                              | (0xffU 
                                                 & (IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data)));
            vlTOPp->opl3__DOT__opl3_reg_wr = (0x20000U 
                                              | vlTOPp->opl3__DOT__opl3_reg_wr);
        } else {
            vlTOPp->opl3__DOT__opl3_reg_wr = ((0x2ffffU 
                                               & vlTOPp->opl3__DOT__opl3_reg_wr) 
                                              | (0x10000U 
                                                 & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data) 
                                                    << 7U)));
            vlTOPp->opl3__DOT__opl3_reg_wr = ((0x300ffU 
                                               & vlTOPp->opl3__DOT__opl3_reg_wr) 
                                              | (0xff00U 
                                                 & ((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data) 
                                                    << 8U)));
        }
    }
    if (vlTOPp->opl3__DOT__reset_sync__DOT__r2) {
        vlTOPp->opl3__DOT__opl3_reg_wr = 0U;
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__next_state 
        = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
            ? (IData)(vlTOPp->opl3__DOT__sample_clk_en)
            : (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en 
        = ((0U != (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state)) 
           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__delay_counter)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num 
        = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
            ? 0U : (0x1fU & ((0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))
                              ? (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state) 
                                  - (IData)(0x12U)) 
                                 - (IData)(1U)) : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state) 
                                                   - (IData)(1U)))));
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
            VL_WRITEF("[%0t] %%Error: control_operators.sv:241: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 241, "");
        }
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
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num];
    } else {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[1U] = 0U;
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
        if (VL_UNLIKELY((1U & (~ VL_ONEHOT0_I((((0x11U 
                                                 == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
                                                << 5U) 
                                               | (((0x10U 
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
                                                              == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)))))))))))) {
            if (VL_UNLIKELY(Verilated::assertOn())) {
                VL_WRITEF("[%0t] %%Error: control_operators.sv:400: Assertion failed in %Nopl3.channels.control_operators: synthesis parallel_case, but multiple matches found\n",
                          64,VL_TIME_UNITED_Q(1000),
                          vlSymsp->name());
                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/control_operators.sv", 400, "");
            }
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array[0U] 
        = ((0x11U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num)) 
           & vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
           [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_num]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array[1U] 
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
    if (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) {
        vlTOPp->opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data 
            = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__mem
            [(0x3fU & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr))];
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
    if ((1U & (~ VL_ONEHOT_I((((8U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                                [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))]) 
                               << 3U) | (((4U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                                           [(0x12U 
                                             < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))]) 
                                          << 2U) | 
                                         (((2U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                                            [(0x12U 
                                              < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))]) 
                                           << 1U) | 
                                          (1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                                           [(0x12U 
                                             < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))])))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: envelope_generator.sv:166: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/envelope_generator.sv", 166, "");
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    if ((0x15U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address];
    } else {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__dob_array[1U] = 0U;
    }
    if ((8U >= (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address];
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address];
    } else {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[0U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[1U] = 0U;
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__wea_array 
        = ((2U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__wea_array)) 
           | ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea) 
              & (~ (vlTOPp->opl3__DOT__opl3_reg_wr 
                    >> 0x10U))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__wea_array 
        = ((1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__wea_array)) 
           | (0x1fffeU & (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea) 
                           << 1U) & (vlTOPp->opl3__DOT__opl3_reg_wr 
                                     >> 0xfU))));
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
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__ksl_tl_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__ar_dr_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sl_rr_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum 
        = ((0x300U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)) 
           | vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array
           [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))]);
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array
        [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))];
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2 
        = (0x7ffU & ((0x80U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))
                      ? ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2) 
                           + (0xfcU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                                       >> 4U))) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2)) 
                         + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2))
                      : (((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2) 
                          + (0xfcU & (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out 
                                      >> 4U))) + (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2))));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum 
        = ((0xffU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum)) 
           | (0x300U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                        << 8U)));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0 
        = ((((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0)) 
             & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                >> 5U)) | ((((((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_on_pulse)) 
                              | ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_on_pulse))) 
                             | ((3U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                                & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_on_pulse))) 
                            | ((5U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                               & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_on_pulse))) 
                           | ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)) 
                              & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_on_pulse)))) 
           & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en));
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0 
        = (0xfU & ((1U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__nts)
                           ? ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                              >> 8U) : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__fnum) 
                                        >> 9U))) | 
                   (0xeU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                            >> 1U))));
    if ((1U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
         [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))])) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
            = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0))
                ? 2U : 1U);
    } else {
        if ((2U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
             [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))])) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
                = (((0x1ffU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0) 
                               >> 4U)) >= (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sl_rr_mem__dob) 
                                                   >> 4U)))
                    ? 4U : 2U);
        } else {
            if ((4U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                 [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))])) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
                    = ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob) 
                         >> 5U) & (0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_type)))
                        ? 4U : 8U);
            } else {
                if ((8U == vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array
                     [(0x12U < (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__state))])) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 = 8U;
                }
            }
        }
    }
    if (vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 
            = ((0U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0))
                ? 2U : 1U);
    } else {
        if ((((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0) 
              & (~ ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob) 
                    >> 5U))) & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0 = 8U;
        }
    }
    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0 
        = (0xfU & ((0x10U & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__am_vib_egt_ksr_mult_mem__dob))
                    ? (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0)
                    : ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0) 
                       >> 2U)));
    if ((1U & (~ VL_ONEHOT_I((((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)) 
                               << 3U) | (((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)) 
                                          << 2U) | 
                                         (((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0)) 
                                           << 1U) | 
                                          (1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: envelope_generator.sv:180: Assertion failed in %Nopl3.channels.control_operators.operator.envelope_generator: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/operator/src/envelope_generator.sv", 180, "");
        }
    }
    if ((1U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
        vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 
            = (0xfU & ((IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__ar_dr_mem__dob) 
                       >> 4U));
    } else {
        if ((2U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
            vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 
                = (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__ar_dr_mem__dob));
        } else {
            if ((4U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 = 0U;
            } else {
                if ((8U == (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0))) {
                    vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0 
                        = (0xfU & (IData)(vlTOPp->opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sl_rr_mem__dob));
                }
            }
        }
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__5(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__5\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__reset_sync__DOT__r2 = (1U & 
                                              ((~ (IData)(vlTOPp->ic_n)) 
                                               | (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r1)));
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
    vlTOPp->opl3__DOT__reset_sync__DOT__r1 = (1U & 
                                              ((~ (IData)(vlTOPp->ic_n)) 
                                               | (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r0)));
    vlTOPp->opl3__DOT__reset_sync__DOT__r0 = (1U & 
                                              (~ (IData)(vlTOPp->ic_n)));
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__6(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__6\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) {
            vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty 
                = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty;
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty = 1U;
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray 
            = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross;
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross 
            = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray;
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray = 0U;
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross = 0U;
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__7(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__7\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->ic_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray 
                = (0x7fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                            ^ (0x3fU & (((IData)(1U) 
                                         + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)) 
                                        >> 1U))));
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray = 0U;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray 
        = ((IData)(vlTOPp->ic_n) ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross)
            : 0U);
    if (vlTOPp->ic_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr 
                = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_wr_addr;
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr = 0U;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross 
        = ((IData)(vlTOPp->ic_n) ? (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray)
            : 0U);
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray) 
           == ((0x60U & ((~ ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray) 
                             >> 5U)) << 5U)) | (0x1fU 
                                                & (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wgray))));
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_wr_addr 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__wr_addr)));
}

VL_INLINE_OPT void Vopl3::_combo__TOP__9(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_combo__TOP__9\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((8U >= (0xfU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                                >> 0x22U))))) {
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[1U] 
            = vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [(0xfU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                              >> 0x22U)))];
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[0U] 
            = vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram
            [(0xfU & (IData)((vlTOPp->opl3__DOT__channels__DOT__signals 
                              >> 0x22U)))];
    } else {
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[1U] = 0U;
        vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[0U] = 0U;
    }
    vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob 
        = vlTOPp->opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array
        [(1U & (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                >> 0x11U))];
    vlTOPp->opl3__DOT__channels__DOT__next_state = vlTOPp->opl3__DOT__channels__DOT__state;
    vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
        = vlTOPp->opl3__DOT__channels__DOT__self[0U];
    vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
        = vlTOPp->opl3__DOT__channels__DOT__self[1U];
    vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
        = vlTOPp->opl3__DOT__channels__DOT__self[2U];
    vlTOPp->opl3__DOT__channels__DOT__signals = 0ULL;
    if (((((((((0U == vlTOPp->opl3__DOT__channels__DOT__state) 
               | (1U == vlTOPp->opl3__DOT__channels__DOT__state)) 
              | (2U == vlTOPp->opl3__DOT__channels__DOT__state)) 
             | (3U == vlTOPp->opl3__DOT__channels__DOT__state)) 
            | (4U == vlTOPp->opl3__DOT__channels__DOT__state)) 
           | (5U == vlTOPp->opl3__DOT__channels__DOT__state)) 
          | (6U == vlTOPp->opl3__DOT__channels__DOT__state)) 
         | (7U == vlTOPp->opl3__DOT__channels__DOT__state))) {
        if ((0U == vlTOPp->opl3__DOT__channels__DOT__state)) {
            if (vlTOPp->opl3__DOT__channels__DOT__ops_done_pulse) {
                vlTOPp->opl3__DOT__channels__DOT__next_state = 1U;
            }
        } else {
            if ((1U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                vlTOPp->opl3__DOT__channels__DOT__next_state = 2U;
                vlTOPp->opl3__DOT__channels__DOT__signals 
                    = ((0x7fffffffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                       | ((QData)((IData)((0x1fU & 
                                           ((IData)(3U) 
                                            + ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                << 0x14U) 
                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                  >> 0xcU)))))) 
                          << 0x27U));
                vlTOPp->opl3__DOT__channels__DOT__signals 
                    = (0x4000000000ULL | vlTOPp->opl3__DOT__channels__DOT__signals);
            } else {
                if ((2U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                    vlTOPp->opl3__DOT__channels__DOT__next_state = 3U;
                    vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                        = ((0x8003ffffU & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                           | (0xfffc0000U & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                             << 0x12U)));
                    vlTOPp->opl3__DOT__channels__DOT__signals 
                        = ((0x7fffffffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                           | ((QData)((IData)((0x1fU 
                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                   << 0x14U) 
                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                     >> 0xcU))))) 
                              << 0x27U));
                    vlTOPp->opl3__DOT__channels__DOT__signals 
                        = (0x4000000000ULL | vlTOPp->opl3__DOT__channels__DOT__signals);
                } else {
                    if ((3U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                        vlTOPp->opl3__DOT__channels__DOT__signals 
                            = ((0xfc3ffffffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                               | ((QData)((IData)((0xfU 
                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                       << 0x18U) 
                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                         >> 8U))))) 
                                  << 0x22U));
                        vlTOPp->opl3__DOT__channels__DOT__signals 
                            = ((0xffc000fffffULL & vlTOPp->opl3__DOT__channels__DOT__signals) 
                               | ((QData)((IData)((0x3fffU 
                                                   & ((1U 
                                                       & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob))
                                                       ? 
                                                      ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                       + 
                                                       (0x1fffU 
                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                            << 0xeU) 
                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                              >> 0x12U))))
                                                       : 
                                                      (0x1fffU 
                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                           << 0xeU) 
                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x12U))))))) 
                                  << 0x14U));
                        if (((IData)(vlTOPp->opl3__DOT__channels__DOT__ryt) 
                             & (~ (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                   >> 0x11U)))) {
                            if ((6U == (0xfU & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                 << 0x18U) 
                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                   >> 8U))))) {
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffc000fffffULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          ((1U 
                                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob))
                                                            ? 
                                                           (0x1fffU 
                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                << 0xeU) 
                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                  >> 0x12U)))
                                                            : (IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out)))) 
                                          << 0x14U));
                            } else {
                                if (((7U == (0xfU & 
                                             ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                               << 0x18U) 
                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                 >> 8U)))) 
                                     | (8U == (0xfU 
                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                     >> 8U)))))) {
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0xffc000fffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0x3fffU 
                                                               & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                  + 
                                                                  (0x1fffU 
                                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                       << 0xeU) 
                                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                         >> 0x12U))))))) 
                                              << 0x14U));
                                }
                            }
                            if ((1U & (~ VL_ONEHOT0_I(
                                                      (((8U 
                                                         == 
                                                         (0xfU 
                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                >> 8U)))) 
                                                        << 2U) 
                                                       | (((7U 
                                                            == 
                                                            (0xfU 
                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                 << 0x18U) 
                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                   >> 8U)))) 
                                                           << 1U) 
                                                          | (6U 
                                                             == 
                                                             (0xfU 
                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                  << 0x18U) 
                                                                 | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                    >> 8U)))))))))) {
                                if (VL_UNLIKELY(Verilated::assertOn())) {
                                    VL_WRITEF("[%0t] %%Error: channels.sv:202: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                              64,VL_TIME_UNITED_Q(1000),
                                              vlSymsp->name());
                                    VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 202, "");
                                }
                            }
                        }
                        if ((3U > (0xfU & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                            << 0x18U) 
                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                              >> 8U))))) {
                            if ((0x20000U & vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffff7ULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                               >> 4U) 
                                                              & (~ 
                                                                 ((5U 
                                                                   >= 
                                                                   (7U 
                                                                    & ((IData)(3U) 
                                                                       + 
                                                                       (0xfU 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))))) 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                     >> 
                                                                     (7U 
                                                                      & ((IData)(3U) 
                                                                         + 
                                                                         (0xfU 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))))) 
                                          << 3U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffbULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                               >> 5U) 
                                                              & (~ 
                                                                 ((5U 
                                                                   >= 
                                                                   (7U 
                                                                    & ((IData)(3U) 
                                                                       + 
                                                                       (0xfU 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))))) 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                     >> 
                                                                     (7U 
                                                                      & ((IData)(3U) 
                                                                         + 
                                                                         (0xfU 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))))) 
                                          << 2U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffdULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                               >> 6U) 
                                                              & (~ 
                                                                 ((5U 
                                                                   >= 
                                                                   (7U 
                                                                    & ((IData)(3U) 
                                                                       + 
                                                                       (0xfU 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))))) 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                     >> 
                                                                     (7U 
                                                                      & ((IData)(3U) 
                                                                         + 
                                                                         (0xfU 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))))) 
                                          << 1U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffeULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | (IData)((IData)(
                                                         (1U 
                                                          & (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                              >> 7U) 
                                                             & (~ 
                                                                ((5U 
                                                                  >= 
                                                                  (7U 
                                                                   & ((IData)(3U) 
                                                                      + 
                                                                      (0xfU 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))))) 
                                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                    >> 
                                                                    (7U 
                                                                     & ((IData)(3U) 
                                                                        + 
                                                                        (0xfU 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U)))))))))))));
                            } else {
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffff7ULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                              | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                  >> 4U) 
                                                                 & (~ 
                                                                    ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U))))))))))) 
                                          << 3U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffbULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                              | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                  >> 5U) 
                                                                 & (~ 
                                                                    ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U))))))))))) 
                                          << 2U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffdULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                              | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                  >> 6U) 
                                                                 & (~ 
                                                                    ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U))))))))))) 
                                          << 1U));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xffffffffffeULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | (IData)((IData)(
                                                         (1U 
                                                          & ((~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new)) 
                                                             | (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                 >> 7U) 
                                                                & (~ 
                                                                   ((5U 
                                                                     >= 
                                                                     (7U 
                                                                      & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                          << 0x18U) 
                                                                         | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                            >> 8U)))) 
                                                                    & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                       >> 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U))))))))))));
                            }
                        } else {
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffff7ULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (1U 
                                                       & (((~ 
                                                            (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x11U)) 
                                                           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                             >> 4U))))) 
                                      << 3U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffffbULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (1U 
                                                       & (((~ 
                                                            (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x11U)) 
                                                           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                             >> 5U))))) 
                                      << 2U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffffdULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (1U 
                                                       & (((~ 
                                                            (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                             >> 0x11U)) 
                                                           & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                          | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                             >> 6U))))) 
                                      << 1U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0xffffffffffeULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | (IData)((IData)(
                                                     (1U 
                                                      & (((~ 
                                                           (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                            >> 0x11U)) 
                                                          & (~ (IData)(vlTOPp->opl3__DOT__channels__DOT__is_new))) 
                                                         | ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                            >> 7U))))));
                        }
                        if (((1U == ((2U & ((IData)(
                                                    (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                     >> 3U)) 
                                            << 1U)) 
                                     | (1U & (IData)(
                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                      >> 1U))))) 
                             | (2U == ((2U & ((IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 3U)) 
                                              << 1U)) 
                                       | (1U & (IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 1U))))))) {
                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                = ((0xfffffU & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                   | (0xfff00000U & 
                                      ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                          << 0xcU) 
                                         | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                            >> 0x14U)) 
                                        + VL_EXTENDS_II(20,14, 
                                                        (0x3fffU 
                                                         & (IData)(
                                                                   (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                    >> 0x14U))))) 
                                       << 0x14U)));
                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                = ((0xffffff00U & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                   | (0xffU & ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                  << 0xcU) 
                                                 | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                    >> 0x14U)) 
                                                + VL_EXTENDS_II(20,14, 
                                                                (0x3fffU 
                                                                 & (IData)(
                                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                            >> 0x14U))))) 
                                               >> 0xcU)));
                        } else {
                            if ((3U == ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 3U)) 
                                               << 1U)) 
                                        | (1U & (IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 1U)))))) {
                                vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                    = ((0xfffffU & 
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                       | (0xfff00000U 
                                          & ((VL_EXTENDS_II(20,20, 
                                                            (0xfffffU 
                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                 << 0xcU) 
                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                   >> 0x14U)))) 
                                              + VL_MULS_III(20,32,32, (IData)(2U), 
                                                            VL_EXTENDS_II(32,14, 
                                                                          (0x3fffU 
                                                                           & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 0x14U)))))) 
                                             << 0x14U)));
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = ((0xffffff00U 
                                        & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                       | (0xffU & (
                                                   (VL_EXTENDS_II(20,20, 
                                                                  (0xfffffU 
                                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                       << 0xcU) 
                                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                         >> 0x14U)))) 
                                                    + 
                                                    VL_MULS_III(20,32,32, (IData)(2U), 
                                                                VL_EXTENDS_II(32,14, 
                                                                              (0x3fffU 
                                                                               & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 0x14U)))))) 
                                                   >> 0xcU)));
                            }
                        }
                        if ((1U & (~ VL_ONEHOT0_I((
                                                   ((3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 3U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(
                                                                   (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                    >> 1U))))) 
                                                    << 2U) 
                                                   | (((2U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(
                                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                      >> 3U)) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (IData)(
                                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                       >> 1U))))) 
                                                       << 1U) 
                                                      | (1U 
                                                         == 
                                                         ((2U 
                                                           & ((IData)(
                                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                       >> 3U)) 
                                                              << 1U)) 
                                                          | (1U 
                                                             & (IData)(
                                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                        >> 1U))))))))))) {
                            if (VL_UNLIKELY(Verilated::assertOn())) {
                                VL_WRITEF("[%0t] %%Error: channels.sv:229: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                          64,VL_TIME_UNITED_Q(1000),
                                          vlSymsp->name());
                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 229, "");
                            }
                        }
                        if (((1U == ((2U & ((IData)(
                                                    (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                     >> 2U)) 
                                            << 1U)) 
                                     | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                             | (2U == ((2U & ((IData)(
                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                       >> 2U)) 
                                              << 1U)) 
                                       | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))) {
                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                = ((0xfff00000U & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                   | (0xfffffU & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                  + 
                                                  VL_EXTENDS_II(20,14, 
                                                                (0x3fffU 
                                                                 & (IData)(
                                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                            >> 0x14U)))))));
                        } else {
                            if ((3U == ((2U & ((IData)(
                                                       (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        >> 2U)) 
                                               << 1U)) 
                                        | (1U & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                    = ((0xfff00000U 
                                        & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                       | (0xfffffU 
                                          & (VL_EXTENDS_II(20,20, 
                                                           (0xfffffU 
                                                            & vlTOPp->opl3__DOT__channels__DOT__self[0U])) 
                                             + VL_MULS_III(20,32,32, (IData)(2U), 
                                                           VL_EXTENDS_II(32,14, 
                                                                         (0x3fffU 
                                                                          & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 0x14U))))))));
                            }
                        }
                        if ((1U & (~ VL_ONEHOT0_I((
                                                   ((3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(
                                                                  (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                   >> 2U)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                    << 2U) 
                                                   | (((2U 
                                                        == 
                                                        ((2U 
                                                          & ((IData)(
                                                                     (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                      >> 2U)) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                       << 1U) 
                                                      | (1U 
                                                         == 
                                                         ((2U 
                                                           & ((IData)(
                                                                      (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                       >> 2U)) 
                                                              << 1U)) 
                                                          | (1U 
                                                             & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))))) {
                            if (VL_UNLIKELY(Verilated::assertOn())) {
                                VL_WRITEF("[%0t] %%Error: channels.sv:235: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                          64,VL_TIME_UNITED_Q(1000),
                                          vlSymsp->name());
                                VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 235, "");
                            }
                        }
                        if ((8U == (0xfU & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                             << 0x18U) 
                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                               >> 8U))))) {
                            if ((0x20000U & vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                vlTOPp->opl3__DOT__channels__DOT__next_state = 4U;
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffe0fffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffff0ffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffdffffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                            } else {
                                vlTOPp->opl3__DOT__channels__DOT__next_state = 1U;
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffe0fffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0x20000U | vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = (0xfffff0ffU 
                                       & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                            }
                        } else {
                            if ((1U & (~ VL_ONEHOT0_I(
                                                      (((5U 
                                                         == 
                                                         (0xfU 
                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                              << 0x18U) 
                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                >> 8U)))) 
                                                        << 1U) 
                                                       | (2U 
                                                          == 
                                                          (0xfU 
                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                               << 0x18U) 
                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                 >> 8U))))))))) {
                                if (VL_UNLIKELY(Verilated::assertOn())) {
                                    VL_WRITEF("[%0t] %%Error: channels.sv:257: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                              64,VL_TIME_UNITED_Q(1000),
                                              vlSymsp->name());
                                    VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 257, "");
                                }
                            }
                            vlTOPp->opl3__DOT__channels__DOT__next_state = 1U;
                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                = ((0xfffe0fffU & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                   | (0xfffff000U & 
                                      (((2U == (0xfU 
                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                      >> 8U))))
                                         ? 6U : ((5U 
                                                  == 
                                                  (0xfU 
                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                       << 0x18U) 
                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                         >> 8U))))
                                                  ? 0xcU
                                                  : 
                                                 (0x1fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                         >> 0xcU)))))) 
                                       << 0xcU)));
                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                = ((0xfffff0ffU & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                   | (0xf00U & (((IData)(1U) 
                                                 + 
                                                 ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                   << 0x18U) 
                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                     >> 8U))) 
                                                << 8U)));
                        }
                    } else {
                        if ((4U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                            vlTOPp->opl3__DOT__channels__DOT__next_state = 5U;
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = ((0x7fffffffffULL 
                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                   | ((QData)((IData)(
                                                      (0x1fU 
                                                       & ((IData)(9U) 
                                                          + 
                                                          (0xfU 
                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                               << 0x18U) 
                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                 >> 8U))))))) 
                                      << 0x27U));
                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                = (0x4000000000ULL 
                                   | vlTOPp->opl3__DOT__channels__DOT__signals);
                        } else {
                            if ((5U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                                vlTOPp->opl3__DOT__channels__DOT__next_state = 6U;
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0x7fffffffffULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (0x1fU 
                                                           & ((IData)(6U) 
                                                              + 
                                                              (0xfU 
                                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                   << 0x18U) 
                                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     >> 8U))))))) 
                                          << 0x27U));
                                vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                    = ((0x7fffffffU 
                                        & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                       | (0x80000000U 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                             << 0x1fU)));
                                vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                                    = ((0x1000U & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]) 
                                       | (0x7fffffffU 
                                          & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                             >> 1U)));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = (0x4000000000ULL 
                                       | vlTOPp->opl3__DOT__channels__DOT__signals);
                                vlTOPp->opl3__DOT__channels__DOT__next_self[2U] 
                                    = ((0xfffU & vlTOPp->opl3__DOT__channels__DOT__next_self[2U]) 
                                       | (0x1000U & 
                                          ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                           << 0xcU)));
                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                    = ((0xfc3ffffffffULL 
                                        & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                       | ((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(3U) 
                                                              + 
                                                              ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                << 0x18U) 
                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                  >> 8U)))))) 
                                          << 0x22U));
                            } else {
                                if ((6U == vlTOPp->opl3__DOT__channels__DOT__state)) {
                                    vlTOPp->opl3__DOT__channels__DOT__next_state = 7U;
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0xfc3ffffffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0xfU 
                                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                   << 0x18U) 
                                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     >> 8U))))) 
                                              << 0x22U));
                                    vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                        = ((0x8003ffffU 
                                            & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                           | (0xfffc0000U 
                                              & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                 << 0x12U)));
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0x7fffffffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0x1fU 
                                                               & ((1U 
                                                                   == 
                                                                   ((2U 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                        << 1U)) 
                                                                    | (1U 
                                                                       & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                          >> 0xcU))))
                                                                   ? 
                                                                  ((IData)(3U) 
                                                                   + 
                                                                   (0xfU 
                                                                    & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                        << 0x18U) 
                                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                          >> 8U))))
                                                                   : 
                                                                  (0xfU 
                                                                   & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                       << 0x18U) 
                                                                      | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                         >> 8U))))))) 
                                              << 0x27U));
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = (0x4000000000ULL 
                                           | vlTOPp->opl3__DOT__channels__DOT__signals);
                                } else {
                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                        = ((0xfc3ffffffffULL 
                                            & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                           | ((QData)((IData)(
                                                              (0xfU 
                                                               & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                   << 0x18U) 
                                                                  | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                     >> 8U))))) 
                                              << 0x22U));
                                    if ((0U == ((2U 
                                                 & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                    << 1U)) 
                                                | (1U 
                                                   & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                      >> 0xcU))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffff0001fULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (0x7fffU 
                                                                   & VL_EXTENDS_II(15,13, 
                                                                                (0x1fffU 
                                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 1U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                  << 5U));
                                    } else {
                                        if ((1U == 
                                             ((2U & 
                                               ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                << 1U)) 
                                              | (1U 
                                                 & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    >> 0xcU))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__signals 
                                                = (
                                                   (0xffffff0001fULL 
                                                    & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                                   | ((QData)((IData)(
                                                                      (0x7fffU 
                                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                          + 
                                                                          (0x1fffU 
                                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                               << 1U) 
                                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                      << 5U));
                                        } else {
                                            if ((2U 
                                                 == 
                                                 ((2U 
                                                   & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                        >> 0xcU))))) {
                                                vlTOPp->opl3__DOT__channels__DOT__signals 
                                                    = 
                                                    ((0xffffff0001fULL 
                                                      & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                                     | ((QData)((IData)(
                                                                        (0x7fffU 
                                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                            + 
                                                                            (0x1fffU 
                                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 1U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                        << 5U));
                                            } else {
                                                if (
                                                    (3U 
                                                     == 
                                                     ((2U 
                                                       & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                            >> 0xcU))))) {
                                                    vlTOPp->opl3__DOT__channels__DOT__signals 
                                                        = 
                                                        ((0xffffff0001fULL 
                                                          & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                                         | ((QData)((IData)(
                                                                            (0x7fffU 
                                                                             & (((IData)(vlTOPp->opl3__DOT__channels__DOT__operator_mem_out) 
                                                                                + 
                                                                                (0x1fffU 
                                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0xeU) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x12U)))) 
                                                                                + 
                                                                                (0x1fffU 
                                                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 1U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 0x1fU))))))) 
                                                            << 5U));
                                                }
                                            }
                                        }
                                    }
                                    if ((1U & (~ VL_ONEHOT_I(
                                                             (((3U 
                                                                == 
                                                                ((2U 
                                                                  & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                     << 1U)) 
                                                                 | (1U 
                                                                    & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                       >> 0xcU)))) 
                                                               << 3U) 
                                                              | (((2U 
                                                                   == 
                                                                   ((2U 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                        << 1U)) 
                                                                    | (1U 
                                                                       & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                          >> 0xcU)))) 
                                                                  << 2U) 
                                                                 | (((1U 
                                                                      == 
                                                                      ((2U 
                                                                        & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                           << 1U)) 
                                                                       | (1U 
                                                                          & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             >> 0xcU)))) 
                                                                     << 1U) 
                                                                    | (0U 
                                                                       == 
                                                                       ((2U 
                                                                         & ((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              >> 0xcU))))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: channels.sv:288: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 288, "");
                                        }
                                    }
                                    if ((0x20000U & 
                                         vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffff7ULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 4U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((IData)(3U) 
                                                                           + 
                                                                           (0xfU 
                                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((IData)(3U) 
                                                                             + 
                                                                             (0xfU 
                                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))) 
                                                  << 3U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffbULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 5U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((IData)(3U) 
                                                                           + 
                                                                           (0xfU 
                                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((IData)(3U) 
                                                                             + 
                                                                             (0xfU 
                                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))) 
                                                  << 2U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffdULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 6U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((IData)(3U) 
                                                                           + 
                                                                           (0xfU 
                                                                            & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                               | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((IData)(3U) 
                                                                             + 
                                                                             (0xfU 
                                                                              & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))) 
                                                  << 1U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffeULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | (IData)((IData)(
                                                                 (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                   >> 7U) 
                                                                  & ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((IData)(3U) 
                                                                          + 
                                                                          (0xfU 
                                                                           & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                               << 0x18U) 
                                                                              | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((IData)(3U) 
                                                                            + 
                                                                            (0xfU 
                                                                             & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                                << 0x18U) 
                                                                                | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))))));
                                    } else {
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffff7ULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 4U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))) 
                                                  << 3U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffbULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 5U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))) 
                                                  << 2U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffdULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                    >> 6U) 
                                                                   & ((5U 
                                                                       >= 
                                                                       (7U 
                                                                        & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                            << 0x18U) 
                                                                           | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                              >> 8U)))) 
                                                                      & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                         >> 
                                                                         (7U 
                                                                          & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                              << 0x18U) 
                                                                             | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                                >> 8U)))))))) 
                                                  << 1U));
                                        vlTOPp->opl3__DOT__channels__DOT__signals 
                                            = ((0xffffffffffeULL 
                                                & vlTOPp->opl3__DOT__channels__DOT__signals) 
                                               | (IData)((IData)(
                                                                 (((IData)(vlTOPp->opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob) 
                                                                   >> 7U) 
                                                                  & ((5U 
                                                                      >= 
                                                                      (7U 
                                                                       & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                           << 0x18U) 
                                                                          | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             >> 8U)))) 
                                                                     & ((IData)(vlTOPp->opl3__DOT__channels__DOT__connection_sel) 
                                                                        >> 
                                                                        (7U 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                                             << 0x18U) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                               >> 8U)))))))));
                                    }
                                    if (((1U == ((2U 
                                                  & ((IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 3U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (IData)(
                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                               >> 1U))))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(
                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                >> 3U)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(
                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                 >> 1U))))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                            = ((0xfffffU 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                               | (0xfff00000U 
                                                  & ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                        << 0xcU) 
                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                          >> 0x14U)) 
                                                      + 
                                                      VL_EXTENDS_II(20,15, 
                                                                    (0x7fffU 
                                                                     & (IData)(
                                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U))))) 
                                                     << 0x14U)));
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                            = ((0xffffff00U 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                               | (0xffU 
                                                  & ((((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                        << 0xcU) 
                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                          >> 0x14U)) 
                                                      + 
                                                      VL_EXTENDS_II(20,15, 
                                                                    (0x7fffU 
                                                                     & (IData)(
                                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U))))) 
                                                     >> 0xcU)));
                                    } else {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 3U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(
                                                           (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                            >> 1U)))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                                = (
                                                   (0xfffffU 
                                                    & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                                   | (0xfff00000U 
                                                      & ((VL_EXTENDS_II(20,20, 
                                                                        (0xfffffU 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             << 0xcU) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                               >> 0x14U)))) 
                                                          + 
                                                          VL_MULS_III(20,32,32, (IData)(2U), 
                                                                      VL_EXTENDS_II(32,15, 
                                                                                (0x7fffU 
                                                                                & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U)))))) 
                                                         << 0x14U)));
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                                = (
                                                   (0xffffff00U 
                                                    & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                                   | (0xffU 
                                                      & ((VL_EXTENDS_II(20,20, 
                                                                        (0xfffffU 
                                                                         & ((vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                                             << 0xcU) 
                                                                            | (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                                               >> 0x14U)))) 
                                                          + 
                                                          VL_MULS_III(20,32,32, (IData)(2U), 
                                                                      VL_EXTENDS_II(32,15, 
                                                                                (0x7fffU 
                                                                                & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U)))))) 
                                                         >> 0xcU)));
                                        }
                                    }
                                    if ((1U & (~ VL_ONEHOT0_I(
                                                              (((3U 
                                                                 == 
                                                                 ((2U 
                                                                   & ((IData)(
                                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                               >> 3U)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 1U))))) 
                                                                << 2U) 
                                                               | (((2U 
                                                                    == 
                                                                    ((2U 
                                                                      & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 3U)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 1U))))) 
                                                                   << 1U) 
                                                                  | (1U 
                                                                     == 
                                                                     ((2U 
                                                                       & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 3U)) 
                                                                          << 1U)) 
                                                                      | (1U 
                                                                         & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 1U))))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: channels.sv:312: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 312, "");
                                        }
                                    }
                                    if (((1U == ((2U 
                                                  & ((IData)(
                                                             (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                              >> 2U)) 
                                                     << 1U)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                         | (2U == (
                                                   (2U 
                                                    & ((IData)(
                                                               (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                >> 2U)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))) {
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                            = ((0xfff00000U 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                               | (0xfffffU 
                                                  & (vlTOPp->opl3__DOT__channels__DOT__self[0U] 
                                                     + 
                                                     VL_EXTENDS_II(20,15, 
                                                                   (0x7fffU 
                                                                    & (IData)(
                                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                               >> 5U)))))));
                                    } else {
                                        if ((3U == 
                                             ((2U & 
                                               ((IData)(
                                                        (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                         >> 2U)) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals))))) {
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] 
                                                = (
                                                   (0xfff00000U 
                                                    & vlTOPp->opl3__DOT__channels__DOT__next_self[0U]) 
                                                   | (0xfffffU 
                                                      & (VL_EXTENDS_II(20,20, 
                                                                       (0xfffffU 
                                                                        & vlTOPp->opl3__DOT__channels__DOT__self[0U])) 
                                                         + 
                                                         VL_MULS_III(20,32,32, (IData)(2U), 
                                                                     VL_EXTENDS_II(32,15, 
                                                                                (0x7fffU 
                                                                                & (IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 5U))))))));
                                        }
                                    }
                                    if ((1U & (~ VL_ONEHOT0_I(
                                                              (((3U 
                                                                 == 
                                                                 ((2U 
                                                                   & ((IData)(
                                                                              (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                               >> 2U)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                                << 2U) 
                                                               | (((2U 
                                                                    == 
                                                                    ((2U 
                                                                      & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 2U)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))) 
                                                                   << 1U) 
                                                                  | (1U 
                                                                     == 
                                                                     ((2U 
                                                                       & ((IData)(
                                                                                (vlTOPp->opl3__DOT__channels__DOT__signals 
                                                                                >> 2U)) 
                                                                          << 1U)) 
                                                                      | (1U 
                                                                         & (IData)(vlTOPp->opl3__DOT__channels__DOT__signals)))))))))) {
                                        if (VL_UNLIKELY(
                                                        Verilated::assertOn())) {
                                            VL_WRITEF("[%0t] %%Error: channels.sv:318: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                                                      64,
                                                      VL_TIME_UNITED_Q(1000),
                                                      vlSymsp->name());
                                            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 318, "");
                                        }
                                    }
                                    if ((2U == (0xfU 
                                                & ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                    << 0x18U) 
                                                   | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                      >> 8U))))) {
                                        if ((0x20000U 
                                             & vlTOPp->opl3__DOT__channels__DOT__self[1U])) {
                                            vlTOPp->opl3__DOT__channels__DOT__next_state = 8U;
                                        } else {
                                            vlTOPp->opl3__DOT__channels__DOT__next_state = 4U;
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                                = (0xfffff0ffU 
                                                   & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                                = (0x20000U 
                                                   | vlTOPp->opl3__DOT__channels__DOT__next_self[1U]);
                                        }
                                    } else {
                                        vlTOPp->opl3__DOT__channels__DOT__next_state = 4U;
                                        vlTOPp->opl3__DOT__channels__DOT__next_self[1U] 
                                            = ((0xfffff0ffU 
                                                & vlTOPp->opl3__DOT__channels__DOT__next_self[1U]) 
                                               | (0xf00U 
                                                  & (((IData)(1U) 
                                                      + 
                                                      ((vlTOPp->opl3__DOT__channels__DOT__self[2U] 
                                                        << 0x18U) 
                                                       | (vlTOPp->opl3__DOT__channels__DOT__self[1U] 
                                                          >> 8U))) 
                                                     << 8U)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == vlTOPp->opl3__DOT__channels__DOT__state)) {
            vlTOPp->opl3__DOT__channels__DOT__next_state = 0U;
            vlTOPp->opl3__DOT__channels__DOT__next_self[0U] = 0U;
            vlTOPp->opl3__DOT__channels__DOT__next_self[1U] = 0U;
            vlTOPp->opl3__DOT__channels__DOT__next_self[2U] = 0U;
            vlTOPp->opl3__DOT__channels__DOT__signals 
                = (0x10ULL | vlTOPp->opl3__DOT__channels__DOT__signals);
        }
    }
    if ((1U & (~ VL_ONEHOT_I((((8U == vlTOPp->opl3__DOT__channels__DOT__state) 
                               << 8U) | (((7U == vlTOPp->opl3__DOT__channels__DOT__state) 
                                          << 7U) | 
                                         (((6U == vlTOPp->opl3__DOT__channels__DOT__state) 
                                           << 6U) | 
                                          (((5U == vlTOPp->opl3__DOT__channels__DOT__state) 
                                            << 5U) 
                                           | (((4U 
                                                == vlTOPp->opl3__DOT__channels__DOT__state) 
                                               << 4U) 
                                              | (((3U 
                                                   == vlTOPp->opl3__DOT__channels__DOT__state) 
                                                  << 3U) 
                                                 | (((2U 
                                                      == vlTOPp->opl3__DOT__channels__DOT__state) 
                                                     << 2U) 
                                                    | (((1U 
                                                         == vlTOPp->opl3__DOT__channels__DOT__state) 
                                                        << 1U) 
                                                       | (0U 
                                                          == vlTOPp->opl3__DOT__channels__DOT__state))))))))))))) {
        if (VL_UNLIKELY(Verilated::assertOn())) {
            VL_WRITEF("[%0t] %%Error: channels.sv:182: Assertion failed in %Nopl3.channels: synthesis parallel_case, but multiple matches found\n",
                      64,VL_TIME_UNITED_Q(1000),vlSymsp->name());
            VL_STOP_MT("/home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv", 182, "");
        }
    }
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__10(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__10\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0) {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__mem[vlTOPp->__Vdlyvdim0__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__opl3__DOT__host_if__DOT__afifo__DOT__mem__v0;
    }
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p1) 
           & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__wr_p2)));
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__11(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__11\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray 
                = (0x7fU & (((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                            ^ (0x3fU & (((IData)(1U) 
                                         + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)) 
                                        >> 1U))));
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray = 0U;
    }
    if (vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n) {
        if (((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read) 
             & (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty)))) {
            vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr 
                = vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_rd_addr;
        }
    } else {
        vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr = 0U;
    }
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_read 
        = (1U & ((IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty) 
                 | (~ (IData)(vlTOPp->opl3__DOT__host_if__DOT__opl3_fifo_empty))));
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty 
        = ((IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray) 
           == (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rgray));
    vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__next_rd_addr 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->opl3__DOT__host_if__DOT__afifo__DOT__rd_addr)));
}

VL_INLINE_OPT void Vopl3::_sequent__TOP__12(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_sequent__TOP__12\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = (1U & (~ (IData)(vlTOPp->opl3__DOT__reset_sync__DOT__r2)));
}

void Vopl3::_eval(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_eval\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    vlTOPp->_combo__TOP__9(vlSymsp);
    if (((IData)(vlTOPp->clk_host) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_host)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->ic_n)) & (IData)(vlTOPp->__Vclklast__TOP__ic_n)))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_host = vlTOPp->clk_host;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__ic_n = vlTOPp->ic_n;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
    vlTOPp->__VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
}

VL_INLINE_OPT QData Vopl3::_change_request(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_change_request\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vopl3::_change_request_1(Vopl3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_change_request_1\n"); );
    Vopl3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n ^ vlTOPp->__Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n)
         | (vlTOPp->opl3__DOT__channels__DOT__signals ^ vlTOPp->__Vchglast__TOP__opl3__DOT__channels__DOT__signals));
    VL_DEBUG_IF( if(__req && ((vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n ^ vlTOPp->__Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n))) VL_DBG_MSGF("        CHANGE: /home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/misc/src/afifo.v:91: opl3.host_if.__Vcellinp__afifo__i_rd_reset_n\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->opl3__DOT__channels__DOT__signals ^ vlTOPp->__Vchglast__TOP__opl3__DOT__channels__DOT__signals))) VL_DBG_MSGF("        CHANGE: /home/user/openCologne/4.Advanced--4--Yamaha-OPL3-FM-Synth/3.build/../1.hw/modules/channels/src/channels.sv:165: opl3.channels.signals\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n 
        = vlTOPp->opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
    vlTOPp->__Vchglast__TOP__opl3__DOT__channels__DOT__signals 
        = vlTOPp->opl3__DOT__channels__DOT__signals;
    return __req;
}

#ifdef VL_DEBUG
void Vopl3::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vopl3::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((clk_host & 0xfeU))) {
        Verilated::overWidthError("clk_host");}
    if (VL_UNLIKELY((clk_dac & 0xfeU))) {
        Verilated::overWidthError("clk_dac");}
    if (VL_UNLIKELY((ic_n & 0xfeU))) {
        Verilated::overWidthError("ic_n");}
    if (VL_UNLIKELY((cs_n & 0xfeU))) {
        Verilated::overWidthError("cs_n");}
    if (VL_UNLIKELY((rd_n & 0xfeU))) {
        Verilated::overWidthError("rd_n");}
    if (VL_UNLIKELY((wr_n & 0xfeU))) {
        Verilated::overWidthError("wr_n");}
    if (VL_UNLIKELY((address & 0xfcU))) {
        Verilated::overWidthError("address");}
}
#endif  // VL_DEBUG
