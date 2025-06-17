#![no_std]

/// Simple JTAG machine implementation
/// 
/// Applications calling this implementation first loads queries into the JtagMach pending queue.
/// Queries are structured as JtagLeg, which is a bit-vector that corresponds to either an IR
/// or DR sequencee. Reads of the DR should include a dummy "input vector" of corresponding to
/// the length of the DR readback they are expecting. 
/// 
/// At any time, the machine can be asked to step() or next(), which will try to take the
/// oldest query added to the pending queue and execute it. step() will move one or two JTAG
/// PHY cycles, whereas next() will attempt to complete the execution of the latest pending
/// leg, if any are available or in-flight.
/// 
/// Legs that have been executed are added to the "done" queue. The calling code can add a
/// "tag" to the JtagLegs to help decode what data or command they corresponded to. 
/// 

// Plug in the allocator crate
extern crate alloc;
extern crate alloc_riscv;

#[cfg(feature = "evt")]
use betrusted_hal::hal_uart::*;

use betrusted_hal::hal_time::*;
use alloc::vec::Vec;
use alloc::string::String;

pub enum JtagState {
    TestReset,
    RunIdle,
    Select,
    Capture,
    Shift,
    Exit1,
    Pause,
    Exit2,
    Update,
}

#[derive(Copy, Clone)]
pub enum JtagChain {
    DR,
    IR,
}

pub enum JtagEndian {
    Big,    // MSB-first shiftout
    Little   // LSB-first shiftout
}

/// option 1: make a "leg" machine that contains the shift-in/shift-out records specific to each leg
/// option 2: make a comprehensive machine that receives meta-commands to transition between states
/// 
/// I think we want a machine that has a Vector which holds a set of instructions that encapsulate either
/// data to send into the IR or DR. There should be a state bit that indicates if the data has been
/// executed; after execution, there is a result vector that is now valid.
/// 
#[derive(Clone)]
pub struct JtagLeg {
    /// which chain (DR or IR)
    c: JtagChain,
    /// output bit vector to device; chain length is defined by vector length
    o: Vec<bool>,
    /// input bit vector from device; length is dynamically allocated as leg traverses
    i: Vec<bool>,
    /// a tag for the leg, to be used by higher level logic to track pending/done entries
    tag: String,
}

impl JtagLeg {
    pub fn new(chain_type: JtagChain, mytag: &str) -> Self {
        JtagLeg {
            c: chain_type,
            o: Vec::new(),
            i: Vec::new(),
            tag: String::from(mytag),
        }
    }

    /// `push` will take data in the form of an unsigned int (either u128 or u32)
    /// and append it to the JTAG input vector in preparation for sending. 
    /// "count" specifies the number of bits of the vector that are valid, and 
    /// "endian" specifies if the MSB or LSB first should be pushed into the JTAG 
    /// chain. 
    /// 
    /// In the case that "count" is less than the full data length and MSB first
    /// order is requested, `push` first discards the left-most unused bits and
    /// then starts push from the remaining MSB. e.g., to push the number
    /// `101100` into the JTAG chain MSB first, store 0x2C into "data" and specify
    /// a "count" of 6, and an "endian" of JtagEndian::Big. Do not shift
    /// data all the way to the MSB of the containing "data" parameter in this case!
    pub fn push_u128(&mut self, data: u128, count: usize, endian: JtagEndian) {
        assert!(count <= 128);
        for i in 0..count {
            match endian {
                JtagEndian::Big => {
                    if (data & (1 << i)) == 0 { self.i.push(false) } else { self.i.push(true) }
                },
                JtagEndian::Little => {
                    if (data & (1 << (count-1-i))) == 0 { self.i.push(false) } else { self.i.push(true) }
                },
            }
        }
    }

    pub fn push_u32(&mut self, data: u32, count: usize, endian: JtagEndian) {
        assert!(count <= 32);
        for i in 0..count {
            match endian {
                JtagEndian::Big => {
                    if (data & (1 << i)) == 0 { self.i.push(false) } else { self.i.push(true) }
                },
                JtagEndian::Little => {
                    if (data & (1 << (count-1-i))) == 0 { self.i.push(false) } else { self.i.push(true) }
                },
            }
        }
    }

    pub fn push_u8(&mut self, data: u8, count: usize, endian: JtagEndian) {
        assert!(count <= 8);
        for i in 0..count {
            match endian {
                JtagEndian::Big => {
                    if (data & (1 << i)) == 0 { self.i.push(false) } else { self.i.push(true) }
                },
                JtagEndian::Little => {
                    if (data & (1 << (count-1-i))) == 0 { self.i.push(false) } else { self.i.push(true) }
                },
            }
        }
    }

    pub fn pop_u32(&mut self, count: usize, endian: JtagEndian) -> Option<u32> {
        if self.o.len() < count {
            // error out before trying to touch the vector, so that in case
            // of a parameter error we can try again without having lost our data
            // in general, "count" should be very well specified in this protocol.
            return None;
        }

        let mut data: u32 = 0;
        for _ in 0..count {
            match endian {
                JtagEndian::Little => {
                    data <<= 1;
                    if self.o.pop().unwrap() { data |= 0x1; }
                }
                JtagEndian::Big => {
                    data >>= 1;
                    if self.o.pop().unwrap() { data |= 0x8000_0000; }
                }
            }
        }

        Some(data)
    }

    /// pop_u128 does a "Best effort" to return up to count_req elements, will return what is
    /// available if less is available
    pub fn pop_u128(&mut self, count_req: usize, endian: JtagEndian) -> Option<u128> {
        let mut count: usize = count_req;
        if self.o.len() == 0 {
            return None;
        } else if self.o.len() < count_req {
            count = self.o.len();
        }

        let mut data: u128 = 0;
        for _ in 0..count {
            match endian {
                JtagEndian::Little => {
                    data <<= 1;
                    if self.o.pop().unwrap() { data |= 0x1; }
                },
                JtagEndian::Big => {
                    data >>= 1;
                    if self.o.pop().unwrap() { data |= 0x8000_0000_0000_0000_0000_0000_0000_0000; }
                }
            }
        }

        Some(data)
    }

    pub fn pop_u8(&mut self, count: usize, endian: JtagEndian) -> Option<u8> {
        if self.o.len() < count {
            // error out before trying to touch the vector, so that in case
            // of a parameter error we can try again without having lost our data
            // in general, "count" should be very well specified in this protocol.
            return None;
        }

        let mut data: u8 = 0;
        for _ in 0..count {
            match endian {
                JtagEndian::Little => {
                    data <<= 1;
                    if self.o.pop().unwrap() { data |= 0x1; }
                }
                JtagEndian::Big => {
                    data >>= 1;
                    if self.o.pop().unwrap() { data |= 0x80; }
                }
            }
        }

        Some(data)
    }


    pub fn tag(&self) -> String {
        self.tag.clone()
    }

    pub fn dbg_i_len(&self) -> usize {
        self.i.len()
    }
    pub fn dbg_o_len(&self) -> usize {
        self.o.len()
    }
}

pub trait JtagPhy {
    fn sync(&mut self, tdi: bool, tms: bool) -> bool; 
    fn nosync(&mut self, tdi: bool, tms: bool, tck: bool) -> bool;
    fn pause(&mut self, us: u32);
}

#[cfg(feature = "evt")]
pub struct JtagUartPhy {
    uart: BtUart,
}

#[cfg(feature = "evt")]
impl JtagUartPhy {
    const SYNC_UART_CODE: u8 = 0x60;
    const ASYNC_UART_CODE: u8 = 0x40;
    const MASK_TCK: u8 = 0x4;
    const MASK_TMS: u8 = 0x2;
    const MASK_TDI: u8 = 0x1;

    pub fn new() -> Self {
        let mut ret: JtagUartPhy = 
        JtagUartPhy {
            uart: BtUart::new(),
        };

        ret.uart.init();
        ret
    }
}

#[cfg(feature = "evt")]
impl JtagPhy for JtagUartPhy {
    /// pause for a given number of microseconds.
    fn pause(&mut self, us: u32) {
        let mut delay: u32 = us/1000;
        if delay == 0 {
            delay = 1;
        }
        unsafe {
            let p: betrusted_pac::Peripherals = betrusted_pac::Peripherals::steal();
            delay_ms(&p, delay);
        }
}

    /// given a tdi and tms value, pulse the clock, and then return the tdo that comes out 
    fn sync(&mut self, tdi: bool, tms: bool) -> bool {
        let mut c: u8 = JtagUartPhy::SYNC_UART_CODE;
        if tdi { c |= JtagUartPhy::MASK_TDI; }
        if tms { c |= JtagUartPhy::MASK_TMS; }
        self.uart.write(c);

        if self.uart.read() == 0x31 {  // 0x31 is '1', incidentally
            true
        } else {
            false
        }
        //false
    }

    fn nosync(&mut self, tdi: bool, tms: bool, tck: bool) -> bool {
        let mut c: u8 = JtagUartPhy::ASYNC_UART_CODE;
        if tdi { c |= JtagUartPhy::MASK_TDI; }
        if tms { c |= JtagUartPhy::MASK_TMS; }
        if tck { c |= JtagUartPhy::MASK_TCK; }
        self.uart.write(c);

        if self.uart.read() == 0x31 {
            true
        } else {
            false
        }
    }
}


#[cfg(any(feature = "dvt", feature = "pvt"))]
pub struct JtagGpioPhy {
    p: betrusted_pac::Peripherals,
}

#[cfg(any(feature = "dvt", feature = "pvt"))]
impl JtagGpioPhy {
    pub fn new() -> Self {
        unsafe {
            JtagGpioPhy {
                p: betrusted_pac::Peripherals::steal(),
            }
        }
    }
}

#[cfg(any(feature = "dvt", feature = "pvt"))]
impl JtagPhy for JtagGpioPhy {
    /// pause for a given number of microseconds.
    fn pause(&mut self, us: u32) {
        let mut delay: u32 = us/1000;
        if delay == 0 {
            delay = 1;
        }
        delay_ms(&self.p, delay);
}

    /// given a tdi and tms value, pulse the clock, and then return the tdo that comes out
    fn sync(&mut self, tdi: bool, tms: bool) -> bool {

        self.p.JTAG.next.write(|w| w.tdi().bit(tdi).tms().bit(tms) ); // update tdi/tms, which automatically clocks tck
        while !self.p.JTAG.tdo.read().ready().bit() { }  // make sure we are in a ready/tdo valid state
        let ret = self.p.JTAG.tdo.read().tdo().bit(); // this is the TDO value from /prior/ to the TCK rise
        // note: the hardware already guarantees TDO sample timing relative to TCK edge: in other words,
        // TDO is sampled before the TCK edge is allowed to rise

        ret
    }

    fn nosync(&mut self, _tdi: bool, _tms: bool, _tck: bool) -> bool {
        // we just don't offer this method for this PHY
        unimplemented!();
    }
}

pub struct JtagMach {
    /// current state (could be in one of two generics, or in DR/IR chain; check top of Vector for current chain)
    s: JtagState,
    /// a vector of legs to traverse. An entry stays in pending until the traversal is complete. Aborted
    /// traversals leave the leg in place
    pending: Vec<JtagLeg>,
    /// a vector of legs traversed. An entry is only put into the done vector once its traversal is completed.
    done: Vec<JtagLeg>,
    /// the current leg being processed
    current: Option<JtagLeg>,
    /// an integer for debug help
    debug: u32,
}

impl JtagMach {
    pub fn new() -> Self {
        JtagMach {
            s: JtagState::TestReset,
            pending: Vec::new(),
            done: Vec::new(),
            current: None,
            debug: 0,
        }
    }

    /// add() -- add a leg to the pending queue
    pub fn add(&mut self, leg: JtagLeg) {
        self.pending.push(leg);
    }

    /// get() -- get the oldest result in the done queue. Returns an option.
    pub fn get(&mut self) -> Option<JtagLeg> {
        if self.done.len() > 0 {
            Some(self.done.remove(0))
        } else {
            None
        }
    }

    /// has_pending() -- tells if the jtag machine has a pending leg to traverse. Returns the tag of the pending item, or None.
    pub fn has_pending(&self) -> bool {
        if self.pending.len() > 0 {
            true
        } else {
            false
        }
    }

    /// has_done() -- tells if the jtag machine has any legs that are done to read out. Returns the tag of the done item, or None.
    pub fn has_done(&self) -> bool {
        if self.done.len() > 0 {
            true
        } else {
            false
        }
    }

    /// for debug
    pub fn pending_len(&self) -> usize {
        self.pending.len()
    }
    /// for debug
    pub fn done_len(&self) -> usize {
        self.done.len()
    }
    pub fn dbg_reset(&mut self) {
        self.debug = 0;
    }
    pub fn dbg_get(&self) -> u32 {
        self.debug
    }

    /// step() -- move state machine by one cycle
    /// if there is nothing in the pending queue, stay in idle
    /// if something in the pending queue, traverse to execute it
    pub fn step<T: JtagPhy>(&mut self, phy: &mut T) {
        self.s = match self.s {
            JtagState::TestReset => {
                phy.sync(false, false);
                JtagState::RunIdle
            },
            JtagState::RunIdle => {
                // we have a current item, traverse to the correct tree based on the type
                if let Some(ref mut cur) = self.current {
                    match cur.c {
                        JtagChain::DR => {
                            self.debug = 2;
                            phy.sync(false, true);
                        },
                        JtagChain::IR => {
                            self.debug = 3;
                            // must be IR -- do two TMS high pulses to get to the IR leg
                            phy.sync(false, true);
                            phy.sync(false, true);
                        }
                    }
                    JtagState::Select
                } else {
                    if self.pending.len() > 0 {
                        // nothing current, but has pending --> assign a current
                        // don't pop the entry, though, until we are finished traversing the leg,
                        // hence we make a clone of the entry
                        self.current = Some(self.pending[0].clone());
                    } else {
                        // nothing pending, nothing current
                        // stay in the current state
                        phy.sync(false, false);
                    }
                    JtagState::RunIdle
                }
            },
            JtagState::Select => {
                phy.sync(false, false);
                JtagState::Capture
            },
            JtagState::Capture => {
                // always move to shift, because leg structures always have data
                phy.sync(false, false);
                JtagState::Shift
            },
            JtagState::Shift => {
                // shift data until the input vector is exhausted
                if let Some(ref mut cur) = self.current {
                    if let Some(tdi) = cur.i.pop() {
                        if cur.i.len() > 0 {
                            let tdo: bool = phy.sync(tdi, false);
                            cur.o.push(tdo);
                            self.current = Some(cur.clone());
                            JtagState::Shift
                        } else {
                            // last element should leave the state
                            let tdo: bool = phy.sync(tdi, true);
                            cur.o.push(tdo);
                            self.current = Some(cur.clone());
                            JtagState::Exit1
                        }
                    } else {
                        // Shouldn't happen: no "i", but move on gracefully
                        JtagState::Exit1
                    }
                } else {
                    // Shouldn't happen: No "Current", but move on gracefully
                    JtagState::Exit1
                }
            },
            JtagState::Exit1 => {
                phy.sync(false, true);
                JtagState::Update
            },
            JtagState::Pause => {
                phy.sync(false, true);
                JtagState::Exit2
            },
            JtagState::Exit2 => {
                phy.sync(false, true);
                JtagState::Update
            },
            JtagState::Update => {
                phy.sync(false, false);

                self.pending.remove(0); // remove the oldest entry
                if let Some(next) = self.current.take() {
                    self.done.push(next);
                }
                JtagState::RunIdle
            }
        }
    }

    /// reset() -- bring the state machine back to the TEST_RESET state
    pub fn reset<T: JtagPhy>(&mut self, phy: &mut T) {
        // regardless of what state we are in, 5 cycles of TMS=1 will bring us to RESET
        for _ in 0..5 {
            phy.sync(false, true);
        }
        self.s = JtagState::TestReset;
    }

    /// next() -- advance until a RUN_IDLE state. If currently RUN_IDLE, traverse the next available leg, if one exists
    pub fn next<T: JtagPhy>(&mut self, phy: &mut T) {
        match self.s {
            JtagState::RunIdle | JtagState::TestReset => {
                if self.has_pending() {
                    // if pending, step until we're into a leg
                    loop {
                        match self.s {
                            JtagState::RunIdle | JtagState::TestReset => self.step(phy),
                            _ => break,
                        }
                    }
                    // then step until we're out of the leg
                    loop {
                        match self.s {
                            JtagState::RunIdle | JtagState::TestReset => break,
                            _ => self.step(phy),
                        }
                    }
                } else {
                    self.step(phy); // this should be a single step with no state change
                }
            },
            _ => {
                // in the case that we're not already in idle or reset, run the machine until we get to idle or reset
                loop {
                    match self.s {
                        JtagState::RunIdle | JtagState::TestReset => break,
                        _ => self.step(phy),
                    }
                }
            },
        }
    }
}