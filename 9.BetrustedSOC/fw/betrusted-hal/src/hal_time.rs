const TICKS_PER_MS: u32 = 1;

pub fn time_init(p: &betrusted_pac::Peripherals) {
    p.TICKTIMER.control.write( |w| {w.reset().bit(true)});
}

// time APIs needed (ideally)
/// get current time - in milliseconds, as u32
pub fn get_time_ms(p: &betrusted_pac::Peripherals) -> u32 {
    let time: u32;
    
    time = p.TICKTIMER.time0.read().bits();

    time / TICKS_PER_MS
}

pub fn get_ticks(p: &betrusted_pac::Peripherals) -> u64 {
    (p.TICKTIMER.time0.read().bits() as u64) | ((p.TICKTIMER.time1.read().bits() as u64) << 32)
}

/// delay for milliseconds
pub fn delay_ms(p: &betrusted_pac::Peripherals, ms: u32) {
    let starttime: u32 = get_time_ms(p);

    loop {
        if get_time_ms(p) > (starttime + ms) {
            break;
        }
    }
}
