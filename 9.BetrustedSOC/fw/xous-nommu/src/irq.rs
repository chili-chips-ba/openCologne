use crate::definitions::XousError;
use crate::filled_array;
use vexriscv::register::{mstatus, vmim};

static mut IRQ_HANDLERS: [Option<fn(usize)>; 32] = filled_array![None; 32];

pub fn handle(irqs_pending: usize) {
    // Unsafe is required here because we're accessing a static
    // mutable value, and it could be modified from various threads.
    // However, this is fine because this is run from an IRQ context
    // with interrupts disabled.
    // NOTE: This will become an issue when running with multiple cores,
    // so this should be protected by a mutex.
    unsafe {
        for irq_no in 0..IRQ_HANDLERS.len() {
            if irqs_pending & (1 << irq_no) != 0 {
                if let Some(f) = IRQ_HANDLERS[irq_no] {
                    // Call the IRQ handler
                    f(irq_no);
                } else {
                    // If there is no handler, mask this interrupt
                    // to prevent an IRQ storm.  This is considered
                    // an error.
                    vmim::write(vmim::read() | (1 << irq_no));
                }
            }
        }
    }
}

pub fn sys_interrupt_claim(irq: usize, f: fn(usize)) -> Result<(), XousError> {
    // Unsafe is required since we're accessing a static mut array.
    // However, we disable interrupts to prevent contention on this array.
    unsafe {
        mstatus::clear_mie();
        let result = if irq > IRQ_HANDLERS.len() {
            Err(XousError::InterruptNotFound)
        } else if IRQ_HANDLERS[irq].is_some() {
            Err(XousError::InterruptInUse)
        } else {
            IRQ_HANDLERS[irq] = Some(f);
            // Note that the vexriscv "IRQ Mask" register is inverse-logic --
            // that is, setting a bit in the "mask" register unmasks (i.e. enables) it.
            vmim::write(vmim::read() | (1 << irq));
            Ok(())
        };
        mstatus::set_mie();
        result
    }
}
