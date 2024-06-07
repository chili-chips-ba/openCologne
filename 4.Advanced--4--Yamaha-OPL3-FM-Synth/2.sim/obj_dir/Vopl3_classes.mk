# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vopl3.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (from --threads, --trace-threads or use of classes)
VM_C11 = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 1
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Threaded output mode?  0/1/N threads (from --threads)
VM_THREADS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing threaded output mode?  0/1/N threads (from --trace-thread)
VM_TRACE_THREADS = 0
# Separate FST writer thread? 0/1 (from --trace-fst with --trace-thread > 0)
VM_TRACE_FST_WRITER_THREAD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vopl3 \
	Vopl3__1 \
	Vopl3__2 \
	Vopl3__3 \
	Vopl3__4 \
	Vopl3___024unit \
	Vopl3_mem_multi_bank__D1_DB12_O2_N2 \
	Vopl3_mem_multi_bank__D8_DB16_N2 \
	Vopl3_mem_simple_dual_port_async_read__pi13 \
	Vopl3_mem_simple_dual_port_async_read__pi8 \
	Vopl3_mem_simple_dual_port_async_read__pi7 \
	Vopl3_mem_simple_dual_port_async_read__pi6 \
	Vopl3_mem_simple_dual_port_async_read__pi6__1 \
	Vopl3_mem_simple_dual_port_async_read__pi4 \
	Vopl3_mem_simple_dual_port_async_read__pi3 \
	Vopl3_mem_simple_dual_port__pi12 \
	Vopl3_mem_simple_dual_port__pi5 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vopl3__Slow \
	Vopl3__1__Slow \
	Vopl3__2__Slow \
	Vopl3___024unit__Slow \
	Vopl3_mem_multi_bank__D1_DB12_O2_N2__Slow \
	Vopl3_mem_multi_bank__D8_DB16_N2__Slow \
	Vopl3_mem_simple_dual_port_async_read__pi13__Slow \
	Vopl3_mem_simple_dual_port_async_read__pi8__Slow \
	Vopl3_mem_simple_dual_port_async_read__pi7__Slow \
	Vopl3_mem_simple_dual_port_async_read__pi6__Slow \
	Vopl3_mem_simple_dual_port_async_read__pi4__Slow \
	Vopl3_mem_simple_dual_port_async_read__pi3__Slow \
	Vopl3_mem_simple_dual_port__pi12__Slow \
	Vopl3_mem_simple_dual_port__pi5__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vopl3__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_cov \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
