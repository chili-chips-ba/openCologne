#![no_std]
mod definitions;
mod irq;
mod macros;
pub mod syscalls;

use vexriscv::register::{mcause, mie, mstatus, vmim, vmip};

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}

pub fn init() {
    unsafe {
        vmim::write(0); // Disable all machine interrupts
        mie::set_msoft();
        mie::set_mtimer();
        mie::set_mext();
        mstatus::set_mie(); // Enable CPU interrupts
    }
}

#[no_mangle]
pub fn trap_handler() {
    let mc = mcause::read();
    let irqs_pending = vmip::read();

    if mc.is_exception() {
        loop {}
    }

    if irqs_pending != 0 {
        irq::handle(irqs_pending);
    }
}
