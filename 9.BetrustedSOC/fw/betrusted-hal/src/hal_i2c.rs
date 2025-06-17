use crate::hal_time::get_time_ms;

pub fn i2c_init(p: &betrusted_pac::Peripherals, clock_mhz: u32) {
    let clkcode: u32 = (clock_mhz * 1_000_000) / (5 * 100_000) - 1;

    // set the prescale assuming 100MHz cpu operation: 100MHz / ( 5 * 100kHz ) - 1 = 199
    unsafe{p.I2C.prescale.write( |w| {w.bits(clkcode & 0xFFFF)}); }

    // enable the block
    p.I2C.control.write( |w| {w.en().bit(true)});
}

// [FIXME] this is a stupid polled implementation of I2C transmission. Once we have
// threads and interurpts, this should be refactored to be asynchronous
/// Wait until a transaction in progress ends. [FIXME] would be good to yield here once threading is enabled.
fn i2c_tip_wait(p: &betrusted_pac::Peripherals, timeout_ms: u32) -> u32 {
    let starttime: u32 = get_time_ms(p);

    // wait for TIP to go high
    loop {
        if p.I2C.status.read().tip().bit() == true {
            break;
        }
        if get_time_ms(p) > starttime + timeout_ms {
            unsafe{p.I2C.command.write( |w| {w.bits(0)}); }
            return 1;
        }
    }

    // wait for tip to go low
    loop {
        if p.I2C.status.read().tip().bit() == false {
            break;
        }
        if get_time_ms(p) > starttime + timeout_ms {
            unsafe{p.I2C.command.write( |w| {w.bits(0)}); }
            return 1;
        }
    }
    unsafe{p.I2C.command.write( |w| {w.bits(0)}); }

    0
}

/// The primary I2C interface call. This version currently blocks until the transaction is done.
pub fn i2c_controller(p: &betrusted_pac::Peripherals, addr: u8, txbuf: Option<&[u8]>, rxbuf: Option<&mut [u8]>, timeout_ms: u32) -> u32 {
    let mut ret: u32 = 0;

    // write half
    if txbuf.is_some() {
        let txbuf_checked : &[u8] = txbuf.unwrap();
        unsafe{ p.I2C.txr.write( |w| {w.bits( (addr << 1 | 0) as u32 )}); }
        p.I2C.command.write( |w| {w.sta().bit(true).wr().bit(true)});

        ret += i2c_tip_wait(p, timeout_ms);

        let mut i: usize = 0;
        loop {
            if i == txbuf_checked.len() as usize {
                break;
            }
            if p.I2C.status.read().rx_ack().bit() {
                ret += 1;
            }
            unsafe{ p.I2C.txr.write( |w| {w.bits( (txbuf_checked[i]) as u32 )}); }
            if i == txbuf_checked.len() - 1 && rxbuf.is_none() {
                p.I2C.command.write( |w| {w.wr().bit(true).sto().bit(true)});
            } else {
                p.I2C.command.write( |w| {w.wr().bit(true)});
            }
            ret += i2c_tip_wait(p, timeout_ms);
            i += 1;
        }
        if p.I2C.status.read().rx_ack().bit() {
            ret += 1;
        }
    }

    // read half
    if rxbuf.is_some() {
        let rxbuf_checked : &mut [u8] = rxbuf.unwrap();
        unsafe{ p.I2C.txr.write( |w| {w.bits( (addr << 1 | 1) as u32 )}); }
        p.I2C.command.write( |w| {w.sta().bit(true).wr().bit(true)});

        ret += i2c_tip_wait(p, timeout_ms);

        let mut i: usize = 0;
        loop {
            if i == rxbuf_checked.len() as usize {
                break;
            }
            if i == rxbuf_checked.len() - 1 {
                p.I2C.command.write( |w| {w.rd().bit(true).ack().bit(true).sto().bit(true)});
            } else {
                p.I2C.command.write( |w| {w.rd().bit(true)});
            }
            ret += i2c_tip_wait(p, timeout_ms);
            rxbuf_checked[i] = p.I2C.rxr.read().bits() as u8;
            i += 1;
        }
    }

    ret
}