// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VOPL3_H_
#define _VOPL3_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class Vopl3__Syms;
class Vopl3_mem_simple_dual_port_async_read__pi4;
class Vopl3_mem_multi_bank__D8_DB16_N2;
class Vopl3_mem_simple_dual_port_async_read__pi7;
class Vopl3_mem_simple_dual_port_async_read__pi8;
class Vopl3_mem_simple_dual_port_async_read__pi3;
class Vopl3_mem_simple_dual_port_async_read__pi13;
class Vopl3_mem_multi_bank__D1_DB12_O2_N2;
class Vopl3_mem_simple_dual_port__pi12;
class Vopl3_mem_simple_dual_port__pi5;


//----------

VL_MODULE(Vopl3) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vopl3_mem_simple_dual_port_async_read__pi4* __PVT__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi4* __PVT__opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_multi_bank__D8_DB16_N2* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__am_vib_egt_ksr_mult_mem;
    Vopl3_mem_multi_bank__D8_DB16_N2* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__ksl_tl_mem;
    Vopl3_mem_multi_bank__D8_DB16_N2* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__ar_dr_mem;
    Vopl3_mem_multi_bank__D8_DB16_N2* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__sl_rr_mem;
    Vopl3_mem_simple_dual_port_async_read__pi7* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi7* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi4* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi4* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi8* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi8* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi3* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi3* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi13* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_simple_dual_port_async_read__pi13* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank;
    Vopl3_mem_multi_bank__D1_DB12_O2_N2* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_msb_mem;
    Vopl3_mem_multi_bank__D1_DB12_O2_N2* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_msb_mem;
    Vopl3_mem_simple_dual_port__pi12* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank;
    Vopl3_mem_simple_dual_port__pi12* __PVT__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank;
    Vopl3_mem_simple_dual_port__pi5* __PVT__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank;
    Vopl3_mem_simple_dual_port__pi5* __PVT__opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(clk_host,0,0);
    VL_IN8(ic_n,0,0);
    VL_IN8(clk_dac,0,0);
    VL_IN8(cs_n,0,0);
    VL_IN8(rd_n,0,0);
    VL_IN8(wr_n,0,0);
    VL_IN8(address,1,0);
    VL_IN8(din,7,0);
    VL_OUT8(dout,7,0);
    VL_OUT8(sample_valid,0,0);
    VL_OUT8(led,3,0);
    VL_OUT8(irq_n,0,0);
    VL_OUT(sample_l,23,0);
    VL_OUT(sample_r,23,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ opl3__DOT__sample_clk_en;
        CData/*7:0*/ opl3__DOT__status;
        CData/*0:0*/ opl3__DOT__reset_sync__DOT__r0;
        CData/*0:0*/ opl3__DOT__reset_sync__DOT__r1;
        CData/*0:0*/ opl3__DOT__reset_sync__DOT__r2;
        CData/*0:0*/ opl3__DOT__host_if__DOT__cs_p1_n;
        CData/*0:0*/ opl3__DOT__host_if__DOT__wr_p1_n;
        CData/*1:0*/ opl3__DOT__host_if__DOT__address_p1;
        CData/*7:0*/ opl3__DOT__host_if__DOT__din_p1;
        CData/*0:0*/ opl3__DOT__host_if__DOT__opl3_fifo_empty;
        CData/*0:0*/ opl3__DOT__host_if__DOT__wr_p1;
        CData/*0:0*/ opl3__DOT__host_if__DOT__wr_p2;
        CData/*7:0*/ opl3__DOT__host_if__DOT__host_status_p1;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT__o_wr_full;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__rd_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__wr_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__rd_wgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__wr_rgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__next_rd_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__next_wr_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__rgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__wgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__rgray_cross;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT__wgray_cross;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT__lcl_read;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_empty;
        SData/*15:0*/ opl3__DOT__host_if__DOT__dout_sync__DOT__sync_regs;
        CData/*7:0*/ opl3__DOT__sample_clk_gen__DOT__counter;
        CData/*0:0*/ opl3__DOT__channels__DOT__channel_valid;
        CData/*0:0*/ opl3__DOT__channels__DOT__ops_done_pulse;
        CData/*5:0*/ opl3__DOT__channels__DOT__connection_sel;
        CData/*0:0*/ opl3__DOT__channels__DOT__is_new;
        CData/*0:0*/ opl3__DOT__channels__DOT__ryt;
        CData/*1:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__delay_counter;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__state;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__next_state;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__bank_num_p1;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__op_num;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__op_num_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__use_feedback_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__op_type;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__op_sample_clk_en;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__connection_sel_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ryt_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator_mem_rd_address;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__cnt1_p1;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_channel_mem_rd_address;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_channel_mem_rd_address;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__cnt1_channel_mem_rd_address;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__nts;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__dvb;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__dam;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__bd;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__sd;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__tom;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__tc;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__hh;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
    };
    struct {
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_on_pulse_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__key_off_pulse_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__rhythm_kon_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__prev_kon_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT__in_r1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_val_p2;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__multiplier_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta1_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__delta2_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__dvb_p1;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__next_state_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_p1;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_p2;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__am_val_p2;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__requested_rate_p0;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__rate_counter_overflow_p1;
        CData/*6:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__rom_out_p1;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp0_p1;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__tmp1_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT__ksl_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__wea_array;
        CData/*6:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__self;
        CData/*6:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_self;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp0_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp1_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__rate_tmp2_p0;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__effective_rate_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__key_on_pulse_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__wea_array;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__am_val_tmp1_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__dam_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p3;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__prev_final_phase_msb_p4;
    };
    struct {
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p3;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p4;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p5;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__is_odd_period_p6;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__ws_post_opl_p0;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
        CData/*1:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT__wea_array;
        CData/*0:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__reb_mem;
        CData/*0:0*/ opl3__DOT__channels__DOT__dac_prep__DOT__sample_valid_opl3_p1;
        SData/*9:0*/ opl3__DOT__host_if__DOT__afifo__DOT__lcl_rd_data;
        SData/*12:0*/ opl3__DOT__channels__DOT__operator_mem_out;
        SData/*15:0*/ opl3__DOT__channels__DOT__channel_l;
        SData/*15:0*/ opl3__DOT__channels__DOT__channel_r;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__modulation_p1;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__out_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__modulation_out_p1;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__env_p3;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_p1;
        IData/*25:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__vibrato_index_p1;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT__fnum_p1;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p0;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p1;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_p2;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_add_p1;
        SData/*10:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_tmp_p2;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_fifo_out_p1;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_p1;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_new_p2;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        SData/*13:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT__tremolo_index_p1;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_out_p5;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p5;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sin_plus_gain_p6;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_out_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out1_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_out2_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws2_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws4_p6;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__tmp_ws7_p5;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p4;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__env_p5;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_p2;
        IData/*17:0*/ opl3__DOT__opl3_reg_wr;
        IData/*19:0*/ opl3__DOT__channels__DOT__operator_out;
        IData/*31:0*/ opl3__DOT__channels__DOT__state;
        IData/*31:0*/ opl3__DOT__channels__DOT__next_state;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_inc_p2;
        IData/*21:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_result_tmp_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p0;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__pre_mult_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__post_mult_p2;
        IData/*31:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__state;
        IData/*31:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__next_state;
    };
    struct {
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__overflow_tmp_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p2;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p4;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__final_phase_p5;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__rhythm_phase_p3;
        IData/*22:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__modulation_shifted_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__dob_p0;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__dob_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__genblk1__DOT__genblk2__DOT__dob_p2;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_friend;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__hh_phase_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__phase_bit_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__noise_bit_p3;
        IData/*23:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__rand_num;
        IData/*23:0*/ opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_l_p1;
        IData/*23:0*/ opl3__DOT__channels__DOT__dac_prep__DOT__sample_opl3_r_p1;
        WData/*76:0*/ opl3__DOT__channels__DOT__self[3];
        WData/*76:0*/ opl3__DOT__channels__DOT__next_self[3];
        QData/*43:0*/ opl3__DOT__channels__DOT__signals;
        SData/*9:0*/ opl3__DOT__host_if__DOT__afifo__DOT__mem[64];
        CData/*7:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT__dob_array[2];
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT__dob_array[2];
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT__dob_array[2];
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT__dob_array[2];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__dob_array[2];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[9];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[9];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__dob_array[2];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[9];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[9];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__dob_array[2];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[18];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram[18];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT__dob_array[2];
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__dob_array[2];
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[18];
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[18];
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT__dob_array[2];
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__dob_array[2];
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[18];
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram[18];
        IData/*25:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT__dob_array[2];
        SData/*12:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT__dob_array[2];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
        CData/*0:0*/ opl3__DOT____Vtogcov__clk;
        CData/*0:0*/ opl3__DOT____Vtogcov__clk_host;
        CData/*0:0*/ opl3__DOT____Vtogcov__clk_dac;
        CData/*0:0*/ opl3__DOT____Vtogcov__ic_n;
        CData/*0:0*/ opl3__DOT____Vtogcov__cs_n;
        CData/*0:0*/ opl3__DOT____Vtogcov__rd_n;
        CData/*0:0*/ opl3__DOT____Vtogcov__wr_n;
        CData/*1:0*/ opl3__DOT____Vtogcov__address;
        CData/*7:0*/ opl3__DOT____Vtogcov__din;
        CData/*7:0*/ opl3__DOT____Vtogcov__dout;
        CData/*0:0*/ opl3__DOT____Vtogcov__sample_valid;
        CData/*3:0*/ opl3__DOT____Vtogcov__led;
        CData/*0:0*/ opl3__DOT____Vtogcov__irq_n;
        CData/*0:0*/ opl3__DOT____Vtogcov__reset;
        CData/*0:0*/ opl3__DOT____Vtogcov__sample_clk_en;
        CData/*7:0*/ opl3__DOT____Vtogcov__status;
        CData/*0:0*/ opl3__DOT____Vtogcov__force_timer_overflow;
        CData/*0:0*/ opl3__DOT__reset_sync__DOT____Vtogcov__r0;
        CData/*0:0*/ opl3__DOT__reset_sync__DOT____Vtogcov__r1;
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr;
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vtogcov__cs_p1_n;
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vtogcov__wr_p1_n;
        CData/*1:0*/ opl3__DOT__host_if__DOT____Vtogcov__address_p1;
        CData/*7:0*/ opl3__DOT__host_if__DOT____Vtogcov__din_p1;
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vtogcov__opl3_fifo_empty;
        CData/*1:0*/ opl3__DOT__host_if__DOT____Vtogcov__opl3_address;
        CData/*7:0*/ opl3__DOT__host_if__DOT____Vtogcov__opl3_data;
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vtogcov__wr_p1;
        CData/*0:0*/ opl3__DOT__host_if__DOT____Vtogcov__wr_p2;
        CData/*7:0*/ opl3__DOT__host_if__DOT____Vtogcov__host_status;
        CData/*7:0*/ opl3__DOT__host_if__DOT____Vtogcov__host_status_p1;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__o_wr_full;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_rd_reset_n;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_rd;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rd_wgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wr_rgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_rd_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__next_wr_addr;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__rgray_cross;
        CData/*6:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__wgray_cross;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_read;
        CData/*0:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_empty;
        SData/*15:0*/ opl3__DOT__host_if__DOT__dout_sync__DOT____Vtogcov__sync_regs;
        CData/*7:0*/ opl3__DOT__sample_clk_gen__DOT____Vtogcov__counter;
        CData/*7:0*/ opl3__DOT__channels__DOT____Vcellout__ch_abcd_cnt_mem__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vcellinp__ch_abcd_cnt_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__channel_valid;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__ops_done_pulse;
        CData/*5:0*/ opl3__DOT__channels__DOT____Vtogcov__connection_sel;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__is_new;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__ryt;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__cha;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__chb;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__chc;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__chd;
        CData/*0:0*/ opl3__DOT__channels__DOT____Vtogcov__cnt;
        CData/*2:0*/ opl3__DOT__channels__DOT____Vtogcov__fb_dummy;
        CData/*1:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vcellout__bankb_sr__out;
    };
    struct {
        CData/*0:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__reb;
        CData/*1:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__bankb_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__am_vib_egt_ksr_mult_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ksl_tl_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ar_dr_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__sl_rr_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__ws_mem__wea;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fnum_low_mem__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fnum_low_mem__wea;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__kon_block_fnum_high_mem__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__kon_block_fnum_high_mem__wea;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__fb_cnt0_mem__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt0_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellinp__fb_cnt1_mem__wea;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__sample_clk_en_sr__out;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__bank_num_sr__out;
        IData/*29:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vcellout__op_num_sr__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__delay_counter;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__state;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__next_state;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__bank_num;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__bank_num_p1;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__use_feedback_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_type;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_sample_clk_en_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__bank_num_p;
        IData/*29:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__op_num_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__connection_sel_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ryt_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__am;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__vib;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__egt;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksr;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__mult;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ksl;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tl;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ar;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dr;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sl;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__rr;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__ws;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__operator_mem_rd_address;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__block;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt0_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_p1;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__kon_block_fnum_channel_mem_rd_address;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fb_cnt0_channel_mem_rd_address;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__cnt1_channel_mem_rd_address;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__nts;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dvb;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__dam;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__bd;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__sd;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tom;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__tc;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__hh;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vcellout__bankb_sr__out;
    };
    struct {
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__bankb_p;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__bankb_p;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__bankb_p;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__bankb_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__bankb_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__sample_clk_en_sr__out;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__bank_num_sr__out;
        IData/*29:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__envelope_generator__egt;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sample_clk_en_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__bank_num_p;
        IData/*29:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__op_num_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__key_on_pulse_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__key_off_pulse_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__bd_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__sd_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__tom_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__tc_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__hh_on_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__rhythm_kon_pulse;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__prev_kon_p0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__kon_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sample_clk_en_sr__DOT____Vtogcov__in;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sample_clk_en_sr__DOT____Vtogcov__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__banka;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__bankb_p;
    };
    struct {
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vcellout__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vlvbound2;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__clk_en;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__bd_edge_detect__DOT____Vtogcov__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__clk_en;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__sd_edge_detect__DOT____Vtogcov__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__clk_en;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tom_edge_detect__DOT____Vtogcov__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__clk_en;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__tc_edge_detect__DOT____Vtogcov__in_r1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__clk_en;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__in_r0;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__hh_edge_detect__DOT____Vtogcov__in_r1;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vcellout__vib_sr__out;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_val_p2;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__vib_p;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__multiplier_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_sr__DOT____Vtogcov__in;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vib_sr__DOT____Vtogcov__out;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta0_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta1_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__delta2_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__dvb_p1;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__bank_num_sr__out;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__tl_sr__out;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__state_mem__dob;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__egt;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__next_state_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__state_p1;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__ksl_add_p2;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__am_val_p2;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__requested_rate_p0;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__rate_counter_overflow_p1;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__sample_clk_en_p;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__bank_num_p;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__op_num_p;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__tl_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__sample_clk_en_sr__DOT____Vtogcov__out;
        CData/*6:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__rom_out_p1;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp0_p1;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__tmp1_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__ksl_add_rom__DOT____Vtogcov__ksl_p1;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__banka;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dia;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__reset_mem_done_pulse;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__bankb_p;
        CData/*6:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__self;
        CData/*6:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__next_self;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__dia;
    };
    struct {
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__addra;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__dia;
        CData/*4:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vcellinp__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__addra;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__sample_clk_en_sr__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__bank_num_sr__out;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__op_num_sr__out;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellout__requested_rate_not_zero_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vcellinp__counter_mem__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp0_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp1_p0;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__rate_tmp2_p0;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__effective_rate_p1;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_shifted_p0;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__requested_rate_not_zero_p;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__sample_clk_en_p;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__bank_num_p;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__op_num_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__key_on_pulse_p1;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__sample_clk_en_sr__DOT____Vtogcov__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__in;
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__requested_rate_not_zero_sr__DOT____Vtogcov__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__banka;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__bankb_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__banka;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__bankb_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__am_val_tmp1_p1;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__dam_p1;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__bank_num_sr__out;
        IData/*29:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_num_sr__out;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__op_type_sr__out;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellinp__log_sine_lut_inst__theta;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__sample_clk_en_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__key_on_pulse_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__prev_final_phase_msb_p2;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__prev_final_phase_msb_p3;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__prev_final_phase_msb_p4;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p2;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p3;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p4;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p5;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__is_odd_period_p6;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p0;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__ws_post_opl_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__bank_num_p;
        IData/*29:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__op_num_p;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__op_type_p;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__sample_clk_en_sr__DOT____Vtogcov__in;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__sample_clk_en_sr__DOT____Vtogcov__out;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__key_on_pulse_sr__DOT____Vtogcov__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__banka;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__wea_array;
    };
    struct {
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__bankb_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__wea;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__reb;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__op_type_sr__out;
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__sample_clk_en_p;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__op_type_p;
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT__sample_clk_en_sr__DOT____Vtogcov__out;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__log_sine_lut_inst__DOT____Vtogcov__theta;
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__exp_lut_inst__DOT____Vtogcov__in;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vcellout__bankb_sr__out;
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__banka;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__bankb_p;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__sample_clk_en_sr__DOT____Vtogcov__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT____Vcellout__bankb_sr__out;
        CData/*1:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__wea_array;
        CData/*1:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__bankb_p;
        CData/*0:0*/ opl3__DOT__channels__DOT__dac_prep__DOT____Vtogcov__sample_valid_opl3_p1;
        CData/*7:0*/ __Vdly__opl3__DOT__sample_clk_gen__DOT__counter;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        IData/*29:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__op_num_sr__out;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT__ram__v0;
        CData/*5:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__sample_clk_en_sr__out;
        SData/*14:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vcellout__op_num_sr__out;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        SData/*11:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__sample_clk_en_sr__out;
        SData/*11:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__key_on_pulse_sr__out;
        IData/*17:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vcellout__ws_post_opl_sr__out;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        CData/*0:0*/ __Vdlyvset__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT__ram__v0;
        CData/*5:0*/ __Vdly__opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vcellout__sample_clk_en_sr__out;
        CData/*0:0*/ __VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__ic_n;
        CData/*0:0*/ __Vclklast__TOP__clk_host;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
        CData/*0:0*/ __Vchglast__TOP__opl3__DOT__host_if__DOT____Vcellinp__afifo__i_rd_reset_n;
        SData/*9:0*/ opl3__DOT__host_if__DOT____Vcellout__afifo__o_rd_data;
        SData/*9:0*/ opl3__DOT__host_if__DOT____Vcellinp__afifo__i_wr_data;
        SData/*9:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__i_wr_data;
        SData/*9:0*/ opl3__DOT__host_if__DOT__afifo__DOT____Vtogcov__lcl_rd_data;
        SData/*12:0*/ opl3__DOT__channels__DOT____Vtogcov__operator_mem_out;
        SData/*15:0*/ opl3__DOT__channels__DOT____Vtogcov__channel_l;
        SData/*15:0*/ opl3__DOT__channels__DOT____Vtogcov__channel_r;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_p1;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__out_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__modulation_out_p1;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT____Vtogcov__fnum;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellinp__phase_generator__modulation_p1;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__env_p3;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_p1;
        IData/*25:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p1;
        IData/*25:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p6;
        WData/*129:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_p[5];
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__vibrato_index_p1;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT__vibrato__DOT____Vtogcov__fnum_p1;
    };
    struct {
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p0;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p1;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_int_p2;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_add_p1;
        SData/*10:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT____Vtogcov__env_tmp_p2;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_fifo_out_p1;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_p1;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__counter_new_p2;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        SData/*13:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__tremolo__DOT____Vtogcov__tremolo_index_p1;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p1;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_out_p5;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p5;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__log_sin_plus_gain_p6;
        SData/*9:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__exp_out_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out0_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out1_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_out2_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws2_p6;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws4_p6;
        SData/*11:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__tmp_ws7_p5;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p4;
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__env_p5;
        SData/*12:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_p2;
        IData/*23:0*/ opl3__DOT____Vtogcov__sample_l;
        IData/*23:0*/ opl3__DOT____Vtogcov__sample_r;
        IData/*17:0*/ opl3__DOT____Vtogcov__opl3_reg_wr;
        IData/*19:0*/ opl3__DOT__channels__DOT____Vtogcov__operator_out;
        IData/*25:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_mem__dob;
        WData/*129:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vcellout__feedback_sr__out[5];
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__phase_inc_p2;
        IData/*21:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT____Vtogcov__feedback_result_tmp_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p0;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__pre_mult_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__calc_phase_inc__DOT____Vtogcov__post_mult_p2;
        IData/*17:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT____Vtogcov__overflow_tmp_p1;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p2;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__phase_acc_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__final_phase_p4;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__final_phase_p5;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__rhythm_phase_p3;
        IData/*22:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT____Vtogcov__modulation_shifted_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__dob_p0;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vlvbound2;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_friend;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__hh_phase_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__phase_bit_p3;
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__noise_bit_p3;
        IData/*23:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__calc_rhythm_phase__DOT____Vtogcov__rand_num;
        IData/*23:0*/ opl3__DOT__channels__DOT__dac_prep__DOT____Vtogcov__sample_opl3_l_p1;
        IData/*23:0*/ opl3__DOT__channels__DOT__dac_prep__DOT____Vtogcov__sample_opl3_r_p1;
        WData/*76:0*/ opl3__DOT__channels__DOT____Vtogcov__self[3];
        WData/*76:0*/ opl3__DOT__channels__DOT____Vtogcov__next_self[3];
        QData/*43:0*/ opl3__DOT__channels__DOT____Vtogcov__signals;
        QData/*43:0*/ __Vchglast__TOP__opl3__DOT__channels__DOT__signals;
    };
    struct {
        CData/*7:0*/ opl3__DOT__channels__DOT__ch_abcd_cnt_mem__DOT____Vtogcov__dob_array[2];
        CData/*2:0*/ opl3__DOT__channels__DOT__control_operators__DOT__ws_mem__DOT____Vtogcov__dob_array[2];
        CData/*7:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fnum_low_mem__DOT____Vtogcov__dob_array[2];
        CData/*5:0*/ opl3__DOT__channels__DOT__control_operators__DOT__kon_block_fnum_high_mem__DOT____Vtogcov__dob_array[2];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT____Vtogcov__dob_array[2];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt0_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT____Vtogcov__dob_array[2];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__0__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__fb_cnt1_mem__DOT__bankgen__BRA__1__KET____DOT__genblk2__DOT__mem_bank__DOT____Vtogcov__ram[9];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT____Vtogcov__dob_array[2];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__0__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__ram[18];
        CData/*0:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__kon_mem__DOT__bankgen__BRA__1__KET____DOT__genblk1__DOT__mem_bank__DOT____Vtogcov__ram[18];
        CData/*3:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__state_mem__DOT____Vtogcov__dob_array[2];
        SData/*14:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_rate_counter__DOT__counter_mem__DOT____Vtogcov__dob_array[2];
        SData/*8:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__envelope_generator__DOT__env_int_mem__DOT____Vtogcov__dob_array[2];
        IData/*19:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__phase_generator__DOT__phase_acc_mem__DOT____Vtogcov__dob_array[2];
        IData/*25:0*/ opl3__DOT__channels__DOT__control_operators__DOT__operator__DOT__feedback_mem__DOT____Vtogcov__dob_array[2];
        SData/*12:0*/ opl3__DOT__channels__DOT__operator_out_mem__DOT____Vtogcov__dob_array[2];
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vopl3__Syms* __VlSymsp;  // Symbol table
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vopl3);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vopl3(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vopl3();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vopl3__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vopl3__Syms* symsp, bool first);
  private:
    static QData _change_request(Vopl3__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vopl3__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__19(Vopl3__Syms* __restrict vlSymsp);
    static void _combo__TOP__2(Vopl3__Syms* __restrict vlSymsp);
    static void _combo__TOP__20(Vopl3__Syms* __restrict vlSymsp);
  private:
    void _configure_coverage(Vopl3__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vopl3__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__25(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__10(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__13(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__14(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__15(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__21(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__22(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__23(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__24(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vopl3__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vopl3__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__16(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__17(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__18(Vopl3__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard