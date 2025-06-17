#[allow(dead_code)]

use crate::hal_time::*;

pub const COM_GASGAUGE: u16 = 0x7000;
pub const COM_USBCC: u16 = 0xB000;
pub const COM_BL_FULLON: u16 = 0x6BFF;
pub const COM_BL_OFF: u16 = 0x6800;
pub const COM_BOOST_ON: u16 = 0x5ABB;
pub const COM_BOOST_OFF: u16 = 0x5AFE;
pub const COM_CHARGE_START: u16 = 0x5A00;
pub const COM_SHIPMODE: u16 = 0x9200;
pub const COM_ACCEL_UPDATE: u16 = 0xA000;
pub const COM_ACCEL_FETCH: u16 = 0xA100;
pub const COM_NEXT_DATA: u16 = 0xF0F0;
pub const COM_RESET_LINK: u16 = 0xFFFF;
pub const COM_POWERDOWN: u16 = 0x9000;
pub const COM_LINK_TEST: u16 = 0x4000;
pub const COM_ERR_UNDERFLOW: u16 = 0xDDDD;
pub const COM_CHARGER_REGDUMP: u16 = 0x8000;
pub const COM_SSID_CHECK: u16 = 0x2000;
pub const COM_SSID_FETCH: u16 = 0x2100;
pub const COM_IDLE: u16 = 0x07E4; // 2020 decimal
pub const COM_POWER_SOC: u16 = 0x7300;
pub const COM_POWER_REMAINING: u16 = 0x7400;
pub const COM_GG_FULL_CAPACITY: u16 = 0x7402;
pub const COM_GG_DEBUG: u16 = 0x7200;
pub const COM_GG_FACTORY_CAPACITY: u16 = 0x7676;
pub const COM_GG_GET_CAPACITY: u16 = 0x7600;

pub const COM_FLASH_ERASE: u16 = 0x3200;
pub const COM_FLASH_WAITACK: u16 = 0x3000;
pub const COM_FLASH_PP: u16 = 0x3300;
pub const COM_FLASHACK: u16 = 0x3CC3;
pub const COM_FLASHLOCK: u16 = 0x3400;
pub const COM_FLASHUNLOCK: u16 = 0x3434;

/// com_txrx is a polled-implementation of an atomic TX/RX swap operation
/// assumes that transaction is *not* in progress on entry to this function
/// this invariant is enforced by the function itself, but if another routine
/// is used to access the block make sure to leave that function with the
/// transaction finished.
pub fn com_txrx(p: &betrusted_pac::Peripherals, tx: u16, waithold: bool) -> u16 {
    if waithold {
        let curtime = get_time_ms(p);
        let mut timeout = false;
        // timeout after 0.25 second to avoid hangs in case of a bug in the protocol
        while com_hold_active(p) & !timeout {
            if (get_time_ms(p) - curtime) > 250 {
                timeout = true;
            }
        }
        if timeout {
            // push a link reset before issuing the next command
            unsafe{ p.COM.tx.write(|w| w.bits(COM_RESET_LINK as u32)); } // transaction is automatically iniated on write
            delay_ms(p, 15);
        }

    }
    // load the TX register
    unsafe{ p.COM.tx.write(|w| w.bits(tx as u32)); } // transaction is automatically iniated on write

    // wait while transaction is in progress
    while p.COM.status.read().tip().bit() { }

    // grab the RX value and return it
    let rx: u16 = p.COM.rx.read().bits() as u16;
    rx
}

pub fn com_hold_active(p: &betrusted_pac::Peripherals) -> bool {
    p.COM.status.read().hold().bit_is_set()
}
