const EV_TX: u32 = 1;
const EV_RX: u32 = 2;

use crate::hal_time::get_time_ms;

pub struct BtUart {
    p: betrusted_pac::Peripherals,
}

/// A simple polled implementation of a UART interface
impl BtUart {
    pub fn new() -> Self {
        unsafe {
            BtUart {
                p: betrusted_pac::Peripherals::steal(),
            }
        }
    }

    pub fn init(&mut self) {
            unsafe { self.p.UART.ev_pending.write(|w| w.bits(self.p.UART.ev_pending.read().bits())); }
            unsafe { self.p.UART.ev_enable.write(|w| w.bits(EV_TX | EV_RX)); }
    }
    
    pub fn write(&mut self, c: u8) {
        while self.p.UART.txfull.read().bits() != 0 {}
        unsafe { self.p.UART.rxtx.write(|w| w.bits(c as u32)); }
        unsafe { self.p.UART.ev_pending.write(|w| w.bits(EV_TX)); }
    }

    pub fn read(&mut self) -> u8 {
        let starttime: u32 = get_time_ms(&self.p);

        while (self.p.UART.rxempty.read().bits() != 0) && (get_time_ms(&self.p) - starttime) < 3 {}
        let c: u8 = self.p.UART.rxtx.read().bits() as u8;
        unsafe { self.p.UART.ev_pending.write(|w| w.bits(EV_RX)); }

        c
    }

    pub fn read_nonblock(&self) -> bool {
        self.p.UART.rxempty.read().bits() == 0
    }

    pub fn uart_sync(&self) {
        while self.p.UART.txfull.read().bits() != 0 {}
    }
}