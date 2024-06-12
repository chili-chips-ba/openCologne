// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vopl3__Syms.h"
#include "Vopl3.h"
#include "Vopl3___024unit.h"



// FUNCTIONS
Vopl3__Syms::Vopl3__Syms(Vopl3* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_opl3__channels.configure(this, name(), "opl3.channels", "channels", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators.configure(this, name(), "opl3.channels.control_operators", "control_operators", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators__operator__calc_phase_inc.configure(this, name(), "opl3.channels.control_operators.operator.calc_phase_inc", "calc_phase_inc", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators__operator__envelope_generator.configure(this, name(), "opl3.channels.control_operators.operator.envelope_generator", "envelope_generator", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators__operator__envelope_generator__ksl_add_rom.configure(this, name(), "opl3.channels.control_operators.operator.envelope_generator.ksl_add_rom", "ksl_add_rom", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators__operator__envelope_generator__state_mem.configure(this, name(), "opl3.channels.control_operators.operator.envelope_generator.state_mem", "state_mem", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators__operator__phase_generator.configure(this, name(), "opl3.channels.control_operators.operator.phase_generator", "phase_generator", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_opl3__channels__control_operators__operator__phase_generator__calc_rhythm_phase.configure(this, name(), "opl3.channels.control_operators.operator.phase_generator.calc_rhythm_phase", "calc_rhythm_phase", -9, VerilatedScope::SCOPE_OTHER);
}
