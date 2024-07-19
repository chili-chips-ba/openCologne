// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vopl3__pch.h"

//============================================================
// Constructors

Vopl3::Vopl3(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vopl3__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , clk_host{vlSymsp->TOP.clk_host}
    , ic_n{vlSymsp->TOP.ic_n}
    , clk_dac{vlSymsp->TOP.clk_dac}
    , cs_n{vlSymsp->TOP.cs_n}
    , rd_n{vlSymsp->TOP.rd_n}
    , wr_n{vlSymsp->TOP.wr_n}
    , address{vlSymsp->TOP.address}
    , din{vlSymsp->TOP.din}
    , dout{vlSymsp->TOP.dout}
    , sample_valid{vlSymsp->TOP.sample_valid}
    , led{vlSymsp->TOP.led}
    , irq_n{vlSymsp->TOP.irq_n}
    , sample_l{vlSymsp->TOP.sample_l}
    , sample_r{vlSymsp->TOP.sample_r}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vopl3::Vopl3(const char* _vcname__)
    : Vopl3(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vopl3::~Vopl3() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vopl3___024root___eval_debug_assertions(Vopl3___024root* vlSelf);
#endif  // VL_DEBUG
void Vopl3___024root___eval_static(Vopl3___024root* vlSelf);
void Vopl3___024root___eval_initial(Vopl3___024root* vlSelf);
void Vopl3___024root___eval_settle(Vopl3___024root* vlSelf);
void Vopl3___024root___eval(Vopl3___024root* vlSelf);

void Vopl3::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vopl3::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vopl3___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vopl3___024root___eval_static(&(vlSymsp->TOP));
        Vopl3___024root___eval_initial(&(vlSymsp->TOP));
        Vopl3___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vopl3___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vopl3::eventsPending() { return false; }

uint64_t Vopl3::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vopl3::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vopl3___024root___eval_final(Vopl3___024root* vlSelf);

VL_ATTR_COLD void Vopl3::final() {
    Vopl3___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vopl3::hierName() const { return vlSymsp->name(); }
const char* Vopl3::modelName() const { return "Vopl3"; }
unsigned Vopl3::threads() const { return 1; }
void Vopl3::prepareClone() const { contextp()->prepareClone(); }
void Vopl3::atClone() const {
    contextp()->threadPoolpOnClone();
}
