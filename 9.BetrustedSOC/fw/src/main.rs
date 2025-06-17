#![no_main]

#![feature(lang_items)]
#![feature(alloc_error_handler)]

#![no_std]

#[export_name = "engine_vectors"]
pub static ENGINE_VECTORS: &[u8; 15652] = include_bytes!("test_vectors.bin");
use volatile::Volatile;

use core::panic::PanicInfo;
use betrusted_rt::entry;
use core::str;

// pull in external symbols to define heap start and stop
// defined in memory.x
extern "C" {
    static _sheap: u8;
    static _heap_size: u8;
}

// Plug in the allocator crate
#[macro_use]
extern crate alloc;
extern crate alloc_riscv;

use alloc_riscv::RiscvHeap;

#[global_allocator]
static ALLOCATOR: RiscvHeap = RiscvHeap::empty();

extern crate betrusted_hal;

const CONFIG_CLOCK_FREQUENCY: u32 = 100_000_000;

// allocate a global, unsafe static string for debug output
#[used] // This is necessary to keep DBGSTR from being optimized out
static mut DBGSTR: [u32; 8] = [0, 0, 0, 0, 0, 0, 0, 0];

macro_rules! readpac32 {
    ($self:ident, $func:ident, $reg:ident) => {
        $self.p.$func.$reg.read().bits()
    };
}
#[allow(unused_macros)]
macro_rules! writepac32 {
    ($data:expr, $self:ident, $func:ident, $reg:ident) => {
        unsafe{ $self.p.$func.$reg.write( |w| w.bits( $dat )); }
    };
}

#[panic_handler]
fn panic(_panic_info: &PanicInfo<'_>) -> ! {
    // if I include this code, the system hangs.
    /*
    let dbg = panic_info.payload().downcast_ref::<&str>();
    match dbg {
        None => unsafe{ DBGSTR[0] = 0xDEADBEEF; }
        _ => unsafe{ DBGSTR[0] = 0xFEEDFACE; }
        _ => unsafe{ DBGSTR[0] = dbg.unwrap().as_ptr() as u32; }  // this causes crashes????
    }
    */
    loop {}
}

#[alloc_error_handler]
fn alloc_error_handler(layout: alloc::alloc::Layout) -> ! {
    unsafe{ DBGSTR[0] = layout.size() as u32; }
    panic!()
}

use betrusted_hal::hal_i2c::*;
use betrusted_hal::hal_time::*;
use betrusted_hal::hal_lcd::*;
use betrusted_hal::hal_com::*;
use betrusted_hal::hal_kbd::*;
use betrusted_hal::hal_xadc::*;
use betrusted_hal::hal_rtc::*;
// use betrusted_hal::hal_aes::*;
use betrusted_hal::hal_shittyrng::*;

//use betrusted_hal::hal_sha2::*;

use embedded_graphics::prelude::*;
use embedded_graphics::egcircle;
use embedded_graphics::pixelcolor::BinaryColor;
use embedded_graphics::fonts::Font12x16;
use embedded_graphics::fonts::Font8x16;
use embedded_graphics::geometry::Point;
use embedded_graphics::primitives::Rectangle;
use embedded_graphics::primitives::Line;
use alloc::vec::Vec;
use alloc::string::String;

#[cfg(any(feature = "dvt", feature = "evt"))]
use betrusted_hal::hal_audio::*;

#[cfg(feature = "pvt")]
use betrusted_hal::hal_tlv320aic3100::*;

use jtag::*;
use efuse_api::*;

#[cfg(feature = "evt")]
use jtag::JtagUartPhy as JtagPhy;

#[cfg(any(feature = "dvt", feature = "pvt"))]
use jtag::JtagGpioPhy as JtagPhy;

use rom_inject::*;

//mod aes_test;
//use aes_test::*;
const SHA_DATA: &[u8; 142] = b"Every one suspects himself of at least one of the cardinal virtues, and this is mine: I am one of the few honest people that I have ever known";
const SHA_DIGEST: [u32; 8] = [0xdc96c23d, 0xaf36e268, 0xcb68ff71, 0xe92f76e2, 0xb8a8379d, 0x426dc745, 0x19f5cff7, 0x4ec9c6d6];

const EC_FLASH_LEN: u32 = 159744;
const EC_FLASH_SRC: u32 = 0x4008_0000;
const EC_GATEWARE_LEN: u32 = 0x1_a000;
const EC_FIRMWARE_LEN: u32 = 48 * 1024;

mod logo;

extern crate digest;
extern crate double_ratchet;
use double_ratchet::ratchet::*;
extern crate signal_common;
use signal_common::keys::{
    ChainKey,
    RatchetKeyPair,
    MessageKey,
//    RatchetKeyPublic,
//    RatchetKeySecret,
//    SessionKey,
};

#[derive(PartialEq)]
pub enum RngType {
    RingOsc,
    Avalanche,
}

pub struct Bounce {
    vector: Point,
    radius: u32,
    bounds: Rectangle<BinaryColor>,
    rand: Vec<i32>,
    rand_index: usize,
    loc: Point,
}

impl Bounce {
    pub fn new(radius: u32, bounds: Rectangle<BinaryColor>) -> Bounce {
        Bounce {
            vector: Point::new(2,3),
            radius: radius,
            bounds: bounds,
            rand: vec![6, 2, 3, 5, 8, 3, 2, 4, 3, 8, 2],
            rand_index: 0,
            loc: Point::new((bounds.bottom_right.x - bounds.top_left.x)/2, (bounds.bottom_right.y - bounds.top_left.y)/2),
        }

    }

    pub fn update(&mut self) -> &mut Self {
        let mut x: i32;
        let mut y: i32;
        // update the new ball location
        x = self.loc.x + self.vector.x; y = self.loc.y + self.vector.y;

        let r: i32 = self.radius as i32;
        if (x >= (self.bounds.bottom_right().x as i32 - r)) ||
           (x <= (self.bounds.top_left().x + r)) ||
           (y >= (self.bounds.bottom_right().y as i32 - r)) ||
           (y <= (self.bounds.top_left().y + r)) {
            if x >= (self.bounds.bottom_right().x as i32 - r - 1) {
                self.vector.x = -self.rand[self.rand_index];
                x = self.bounds.bottom_right().x as i32 - r;
            }
            if x <= self.bounds.top_left().x + r + 1 {
                self.vector.x = self.rand[self.rand_index];
                x = self.bounds.top_left().x + r;
            }
            if y >= (self.bounds.bottom_right().y as i32 - r - 1) {
                self.vector.y = -self.rand[self.rand_index];
                y = self.bounds.bottom_right().y as i32 - r;
            }
            if y <= (self.bounds.top_left().y + r + 1) {
                self.vector.y = self.rand[self.rand_index];
                y = self.bounds.top_left().y + r;
            }
            self.rand_index += 1;
            self.rand_index = self.rand_index % self.rand.len();
        }

        self.loc.x = x;
        self.loc.y = y;

        self
    }
}

pub fn lfsr_next(state: u32) -> u32 {
    let bit = ((state >> 31) ^
               (state >> 21) ^
               (state >>  1) ^
               (state >>  0)) & 1;

    (state << 1) + bit
}

pub struct Repl {
    /// PAC access for commands
    p: betrusted_pac::Peripherals,
    /// current line being typed in
    input: String,
    /// last fully-formed line
    cmd: String,
    /// output response
    text: TextArea,
    /// power state variable
    power: bool,
    /// JTAG state variable
    jtag: JtagMach,
    /// JTAG phy
    jtagphy: JtagPhy,
    /// efuse API
    efuse: EfuseApi,
    /// xadc object
    xadc: BtXadc,
    /// noise arrays
    noise0: [u16; 300],
    noise1: [u16; 300],
    update_noise: bool,
    audio: BtAudio,
    audio_run: bool,
    rtc: BtRtc,
    //aes: BtAes,
    //sha2: BtSha2,
    ssid_print: bool,
    lock: bool,
    flash_wip: u32,
    flash_prog: bool,
    flash_prog_addr: u32,
    flash_prog_len: u32,
}

const PROMPT: &str = "bt> ";
const NUM_LINES: usize = 6;

impl Repl {
    pub fn new() -> Self {
        let mut r: Repl =
            unsafe{
                Repl {
                    p: betrusted_pac::Peripherals::steal(),
                    input: String::from(PROMPT),
                    cmd: String::from(" "),
                    text: TextArea::new(NUM_LINES),
                    power: true,
                    jtag: JtagMach::new(),
                    jtagphy: JtagPhy::new(),
                    efuse: EfuseApi::new(),
                    xadc: BtXadc::new(),
                    noise0: [0; 300],
                    noise1: [0; 300],
                    update_noise: false,
                    audio: BtAudio::new(),
                    audio_run: false,
                    rtc: BtRtc::new(),
                    //aes: BtAes::new(),
                    //sha2: BtSha2::new(),
                    ssid_print: true,
                    lock: false,
                    flash_wip: 0,
                    flash_prog: false,
                    flash_prog_addr: 0x0,
                    flash_prog_len: EC_FLASH_LEN,
                }
            };
        r.text.add_text(&mut String::from("Awaiting input."));

        r
    }

    pub fn get_flash_wip(&self) -> u32 { self.flash_wip }
    pub fn set_flash_wip(&mut self, wip: u32) { self.flash_wip = wip; }
    pub fn get_flash_prog(&self) -> bool { self.flash_prog }
    pub fn set_flash_prog(&mut self, state: bool) { self.flash_prog = state; }
    pub fn get_flash_prog_addr(&self) -> u32 { self.flash_prog_addr }
    pub fn get_flash_prog_len(&self) -> u32 { self.flash_prog_len }

    pub fn unlock(&mut self) {
        self.text.add_text(&mut String::from("System unlocked."));
        self.lock = false;
    }
    pub fn is_locked(&self) -> bool { self.lock }

    pub fn get_ssid_print(&self) -> bool {
        self.ssid_print
    }
    pub fn set_ssid_print(&mut self, state: bool) {
        self.ssid_print = state;
    }

    pub fn input_char(&mut self, c: char) {
        if c.is_ascii() && !c.is_control() {
            self.input.push(c);
        } else if c == 0x8_u8.into() { // backspace
            if self.input.len() > PROMPT.len() {
                self.input.pop();
            }
        } else if c == 0xd_u8.into() { // carriage return
            self.cmd = self.input.clone();
            self.cmd.drain(..PROMPT.len());
            self.input = String::from(PROMPT);

            self.parse_cmd(); // now try parsing the command
        }
    }

    pub fn get_noise0(&self) -> [u16; 300] { self.noise0 }
    pub fn get_noise1(&self) -> [u16; 300] { self.noise1 }
    pub fn get_update_noise(&self) -> bool {self.update_noise}
    pub fn sample_noise(&mut self) {
        self.xadc.noise_only(true); // cut out other round-robin sensor readings
        for i in 0..300 {
            self.xadc.wait_update();
            self.noise0[i] = self.xadc.noise0();
            self.noise1[i] = self.xadc.noise1();
        }
        self.xadc.noise_only(false); // bring them back
    }
    /// here's a thing to be aware of: we are sampling the noise well under its
    /// total bandwidth. Above a certain rate, the noise will look less random because
    /// you have exceeded the bandwidth of the generator. The configuration of the XADC
    /// is about 2-5x under the bandwidth of the noise, so this should effectively "whiten"
    /// the noise at the expense of absolute noise bitrate.
    pub fn dump_noise(&mut self) {
        let mut noise: Vec<u16> = Vec::new();

        self.xadc.noise_only(true); // cut out other round-robin sensor readings

        for _ in 0..100_000 {
            self.xadc.wait_update();
            noise.push(self.xadc.noise0() as u16);
        }
        self.uart_tx_u8(0x4E); // 'N'
        self.uart_tx_u8(0x4F); // 'O'
        for n in noise {
            self.uart_tx_u8((n & 0xFF) as u8);
            self.uart_tx_u8(((n >> 8) & 0xFF) as u8);
        }
        self.uart_tx_u8(0x4F); // 'O'
        self.uart_tx_u8(0x4E); // 'N'

        self.xadc.noise_only(false); // bring them back
    }

    pub fn spi_perftest(&mut self) {
        const SPI_MEM: *const [u32; 0x100_0000] = 0x20000000 as *const [u32; 0x100_0000];
        let time: u32 = readpac32!(self, TICKTIMER, time0);

        let mut sum: u32 = 0;
        for i in 0x0..0x4_0000 {  // 256k words, or 1 megabyte
            unsafe{ sum += (*SPI_MEM)[i]; }
        }

        let endtime: u32 = readpac32!(self, TICKTIMER, time0);

        self.text.add_text(&mut format!("time: {} sum: 0x{:08x}", endtime - time, sum));
    }

    pub fn ram_standby_init(&mut self) -> u32 {
        const TEST_SIZE: usize = 1024 * 1024 * 8 / 4;
        let ram_ptr = 0x4008_0000 as *mut [u32; TEST_SIZE];
        let mut state: u32 = 0xffff_ffff;
        let mut uniques: u32 = 0;
        let mut repeat: bool = false;

        for i in 0..TEST_SIZE {
            unsafe{ (*ram_ptr)[i as usize] = state; }
            state = lfsr_next(state);
            // some code to check that the LFSR isn't broken
            if state == 0xffff_ffff {
                repeat = true;
            }
            if !repeat {
                uniques = uniques + 1;
            }
        }

        uniques
    }

    pub fn ram_check(&mut self) -> u32 {
        const TEST_SIZE: usize = 1024 * 1024 * 8 / 4;
        let ram_ptr = 0x4008_0000 as *mut [u32; TEST_SIZE];
        let mut state: u32 = 0xffff_ffff;
        let mut errors: u32 = 0;
        let mut value: u32;

        for i in 0..TEST_SIZE {
            unsafe{ value = (*ram_ptr)[i as usize]; }
            if value != state {
                errors = errors + 1;
            }
            state = lfsr_next(state);
        }
        errors
    }

    pub fn ram_clear(&mut self) {
        const TEST_SIZE: usize = 1024 * 1024 * 8 / 4;
        let ram_ptr = 0x4008_0000 as *mut [u32; TEST_SIZE];

        for i in 0..TEST_SIZE {
            unsafe{ (*ram_ptr)[i as usize] = 0; }
        }
    }

    pub fn get_avalanche_u32(&mut self) -> u32 {
        let mut r: u16 = 0;
        for _ in 0..4 {
            r <<= 4; // ~4 bits of entropy at a time, concentrated in the LSBs
            self.xadc.wait_update();
            r ^= self.xadc.noise0() ^ self.xadc.noise1();
        }
        let mut ret = r as u32;
        r = 0;
        for _ in 0..4 {
            r <<= 4; // ~4 bits of entropy at a time, concentrated in the LSBs
            self.xadc.wait_update();
            r ^= self.xadc.noise0() ^ self.xadc.noise1();
        }
        ret |= (r as u32) << 16;

        ret
    }

    /*
    pub fn ram_fill_trng(&mut self, do_init: bool, phase: u32, rng_type: RngType) -> u32 {
        const TEST_SIZE: usize = 512 * 1024 / 4;
        let ram_ptr_a = 0x4008_0000 as *mut [u32; TEST_SIZE];
        let ram_ptr_b = 0x4010_0000 as *mut [u32; TEST_SIZE];

        if do_init {
            self.ram_clear();
            let mut phase: u32 = 1;
            unsafe{ self.p.MESSIBLE.in_.write(|w| w.bits(phase)); }

            if rng_type == RngType::RingOsc {
                // start loading the ring osc trng
                unsafe{ self.p.TRNG_OSC.ctl.write(|w|{ w
                    .ena().bit(true)
                    .delay().bits(8)
                    .dwell().bits(100)
                    .gang().bit(true)}); }
            } else {
                    // make sure the noise bias is on for the avalanche TRNG
                    unsafe{ self.p.POWER.power.write(|w| w.noisebias().bit(true).noise().bits(3).self_().bit(true).state().bits(3) ); }
                    delay_ms(&self.p, 100); // definitely wait until stabilized; stabilization test is separate
            }

            self.xadc.noise_only(true);
            for i in 0..TEST_SIZE {
                if rng_type == RngType::RingOsc {
                    while self.p.TRNG_OSC.status.read().fresh().bit_is_clear() {}
                    unsafe{ (*ram_ptr_a)[i as usize] = self.p.TRNG_OSC.rand.read().rand().bits(); }
                } else {
                    unsafe{ (*ram_ptr_a)[i as usize] = self.get_avalanche_u32(); }
                }
            }
            for i in 0..TEST_SIZE {
                if rng_type == RngType::RingOsc {
                    while self.p.TRNG_OSC.status.read().fresh().bit_is_clear() {}
                    unsafe{ (*ram_ptr_b)[i as usize] = self.p.TRNG_OSC.rand.read().rand().bits(); }
                } else {
                    unsafe{ (*ram_ptr_b)[i as usize] = self.get_avalanche_u32(); }
                }
            }
            self.xadc.noise_only(false);
            phase = 2;
            unsafe{ self.p.MESSIBLE.in_.write(|w| w.bits(phase)); }
            return phase;
        } else {
            while phase != self.p.MESSIBLE2.out.read().bits() {
            }
            if phase == 1 {
                if rng_type == RngType::RingOsc {
                    for i in 0..TEST_SIZE {
                        while self.p.TRNG_OSC.status.read().fresh().bit_is_clear() {}
                        unsafe{ (*ram_ptr_a)[i as usize] = self.p.TRNG_OSC.rand.read().rand().bits(); }
                    }
                } else {
                    self.xadc.noise_only(true);
                    for i in 0..TEST_SIZE {
                        unsafe{ (*ram_ptr_a)[i as usize] = self.get_avalanche_u32(); }
                    }
                    self.xadc.noise_only(false);
                }
                unsafe{ self.p.MESSIBLE.in_.write(|w| w.bits(1)); }
                return 2;
            } else {
                if rng_type == RngType::RingOsc {
                    for i in 0..TEST_SIZE {
                        while self.p.TRNG_OSC.status.read().fresh().bit_is_clear() {}
                        unsafe{ (*ram_ptr_b)[i as usize] = self.p.TRNG_OSC.rand.read().rand().bits(); }
                    }
                } else {
                    self.xadc.noise_only(true);
                    for i in 0..TEST_SIZE {
                        unsafe{ (*ram_ptr_b)[i as usize] = self.get_avalanche_u32(); }
                    }
                    self.xadc.noise_only(false);
                }
                // so when messible-out goes to B, read buffer B
                unsafe{ self.p.MESSIBLE.in_.write(|w| w.bits(2)); }
                return 1;
            }
        }
    }*/

    pub fn uart_tx_u8(&mut self, c: u8) {
        while self.p.UART.txfull.read().bits() != 0 {}
        unsafe { self.p.UART.rxtx.write(|w| w.bits(c as u32)); }
        unsafe { self.p.UART.ev_pending.write(|w| w.bits(1)); }
    }

    pub fn get_cmd(&self) -> String {
        self.cmd.clone()
    }

    pub fn get_input(&self) -> String {
        self.input.clone()
    }

    pub fn get_powerstate(self) -> bool {
        self.power
    }

    pub fn force_poweroff(&mut self) {
        self.power = false;
    }

    pub fn rom_read(&mut self, adr: u8) -> u32 {
        unsafe{ self.p.KEYROM.address.write(|w| w.bits(adr as u32)); }

        self.p.KEYROM.data.read().bits()
    }

    pub fn parse_cmd(&mut self) {
        let rom: [u32; 256] = [0; 256];

        let tokens: Vec<&str> = self.cmd.split(' ').collect();
        let command = tokens[0];

        if command.len() == 0 {
            return;
        } else {
            if command.trim() == "shutdown" || command.trim() == "shut" || command.trim() == "sleep" {
                self.text.add_text(&mut String::from("Shutting down system"));
                self.power = false; // the main UI loop needs to pick this up and render the display accordingly
            } else if command.trim() == "reboot" || command.trim() == "reb" {
                self.text.add_text(&mut String::from("Rebooting in 5 seconds")); // can't see the message actually :P
                // set the wakeup alarm
                self.rtc.wakeup_alarm(5);
                // power down
                self.power = false;
            } else if command.trim() == "buzz" {
                self.text.add_text(&mut String::from("Making a buzz"));
                self.p.POWER.vibe.modify(|_r, w| w.vibe().set_bit());
                let time: u32 = get_time_ms(&self.p);
                while get_time_ms(&self.p) - time < 500 { }
                self.p.POWER.vibe.modify(|_r, w| w.vibe().clear_bit());
            } else if command.trim() == "blon" {
                self.text.add_text(&mut String::from("Turning backlight on"));
                com_txrx(&self.p, COM_BL_FULLON, false); // turn on all the backlight to full brightness (31)
            } else if command.trim() == "bloff" {
                self.text.add_text(&mut String::from("Turning backlight off"));
                com_txrx(&self.p, COM_BL_OFF, false);
            } else if command.trim() == "bon" {
                self.text.add_text(&mut String::from("Going boost"));
                com_txrx(&self.p, COM_RESET_LINK as u16, false);  // reset the link
                delay_ms(&self.p, 5); // give it time to reset
                com_txrx(&self.p, COM_BOOST_ON, false);
                delay_ms(&self.p, 8);
                com_txrx(&self.p, COM_RESET_LINK as u16, true);  // reset the link
                delay_ms(&self.p, 5); // give it time to reset
                com_txrx(&self.p, COM_CHARGER_REGDUMP, true);
                com_txrx(&self.p, COM_NEXT_DATA, true); // first value is a pass (wait cycle)
                /*
                unsafe {
                    self.p.GPIO.drive.write(|w| w.bits(0b00_1000));
                    self.p.GPIO.output.write(|w| w.bits(0b00_1000));
                }*/
                self.p.POWER.power.modify(|_r, w| w.boostmode().set_bit());
            for i in 0 .. 0xC {
                    let data = com_txrx(&self.p, COM_NEXT_DATA, true);
                    delay_ms(&self.p, 5);
                    if i == 1 || i == 4 || i == 6 || i == 7 || i == 8 || i == 10 {
                        self.text.add_text(&mut format!("Stat {}: 0x{:2x}", i, data));
                    }
                }

            } else if command.trim() == "boff" {
                /*
                unsafe {
                    self.p.GPIO.drive.write(|w| w.bits(0b00_1000));
                    self.p.GPIO.output.write(|w| w.bits(0b00_0000));
                }*/
                self.p.POWER.power.modify(|_r, w| w.boostmode().clear_bit());
                self.text.add_text(&mut String::from("Boost off"));
                com_txrx(&self.p, COM_BOOST_OFF, true);
            } else if command.trim() == "kill" {
                if cfg!(feature = "pvt") {
                   self.text.add_text(&mut String::from("Self destructing in 3..2..1.."));
                   self.p.POWER.power.modify(|_r,w| w.selfdestruct().set_bit());
                }
            } else if command.trim() == "lock" {
                self.lock = true;
                self.text.add_text(&mut String::from("System locked, ready for updates."));
            } else if command.trim() == "step" {
                self.jtag.step(&mut self.jtagphy);
            } else if command.trim() == "id" {
                self.jtag.reset(&mut self.jtagphy);
                let mut id_leg: JtagLeg = JtagLeg::new(JtagChain::IR, "idcode");
                id_leg.push_u32(0b001001, 6, JtagEndian::Little);
                self.jtag.add(id_leg);
                self.jtag.next(&mut self.jtagphy);
                // NOW: - check the return data on .get() before using it
                if self.jtag.get().is_none() { // discard ID code but check that there's something
                   self.text.add_text(&mut format!("ID instruction not in get queue!"));
                   return;
                }

                let mut data_leg: JtagLeg = JtagLeg::new(JtagChain::DR, "iddata");
                data_leg.push_u32(0, 32, JtagEndian::Little);
                self.jtag.add(data_leg);
                self.jtag.dbg_reset();
                self.jtag.next(&mut self.jtagphy);
                let d: u32 = self.jtag.dbg_get();
                if let Some(mut iddata) = self.jtag.get() { // this contains the actual idcode data
                    self.text.add_text(&mut format!("tag: {}, code: 0x{:08x}, d:{}", iddata.tag(), iddata.pop_u32(32, JtagEndian::Little).unwrap(), d));
                } else {
                    self.text.add_text(&mut format!("ID data not in get queue!"));
                }
                } else if command.trim() == "fk" { // crypto fuse
                self.efuse.fetch(&mut self.jtag, &mut self.jtagphy);
                let key: [u8; 32] = self.efuse.phy_key();
                self.text.add_text(&mut String::from("Key, in hex:"));
                let mut line = String::from("");
                for i in (16..32).rev() {
                    line = line + &format!("{:02x}", key[i]);
                }
                self.text.add_text(&mut line);
                line = String::from("");
                for i in (0..16).rev() {
                    line = line + &format!("{:02x}", key[i]);
                }
                self.text.add_text(&mut line);
            } else if command.trim() == "fu" {
                self.efuse.fetch(&mut self.jtag, &mut self.jtagphy);
                self.text.add_text(&mut format!("user: 0x{:08x}", self.efuse.phy_user()));
            } else if command.trim() == "fc" {
                self.efuse.fetch(&mut self.jtag, &mut self.jtagphy);
                self.text.add_text(&mut format!("cntl: 0x{:02x}", self.efuse.phy_cntl()));
                // comment out burning routines for now
            }  /*else if command.trim() == "burnkey" {
                self.efuse.fetch(&mut self.jtag, &mut self.jtagphy);
                let mut key: [u8; 32] = [0xab, 0x89, 0xaa, 0xaa, 0x9a, 0x78, 0xaa, 0xaa,
                                        0x89, 0x67, 0xaa, 0xaa, 0x78, 0x56, 0xaa, 0xaa,
                                        0x67, 0x45, 0xaa, 0xaa, 0x56, 0x34, 0xaa, 0xaa,
                                        0x45, 0x23, 0xaa, 0xaa, 0x34, 0x12, 0xaa, 0xaa];
                self.efuse.set_key(key);
                if self.efuse.is_valid() {
                    self.text.add_text(&mut format!("Patch is valid."));
                } else {
                    self.text.add_text(&mut format!("Patch is not valid."));
                }
                self.efuse.burn(&mut self.jtag, &mut self.jtagphy);
            }  */ else if command.trim() == "dna" { // dna
                self.jtag.reset(&mut self.jtagphy);
                let mut ir_leg: JtagLeg = JtagLeg::new(JtagChain::IR, "cmd");
                ir_leg.push_u32(0b110010, 6, JtagEndian::Little);
                self.jtag.add(ir_leg);
                self.jtag.next(&mut self.jtagphy);
                if self.jtag.get().is_none() { // discard ID code but check that there's something
                   self.text.add_text(&mut format!("cmd instruction not in get queue!"));
                   return;
                }

                let mut data_leg: JtagLeg = JtagLeg::new(JtagChain::DR, "dna");
                data_leg.push_u128(0, 64, JtagEndian::Little);
                self.jtag.add(data_leg);
                self.jtag.next(&mut self.jtagphy);
                if let Some(mut data) = self.jtag.get() {
                    let dna: u128 = data.pop_u128(64, JtagEndian::Little).unwrap();
                    self.text.add_text(&mut format!("{}/0x{:16x}", data.tag(), dna));
                } else {
                    self.text.add_text(&mut format!("dna data not in queue!"));
                }
            } else if command.trim() == "loop" {
                unsafe { self.p.UART.ev_pending.write(|w| w.bits(self.p.UART.ev_pending.read().bits())); }
                unsafe { self.p.UART.ev_enable.write(|w| w.bits(3)); }

                // send 0-9 as a test
                for _ in 0..10 {
                    for i in 0..10 {
                        while self.p.UART.txfull.read().bits() != 0 {}
                        unsafe { self.p.UART.rxtx.write(|w| w.bits(0x30 + i as u32)); }
                        unsafe { self.p.UART.ev_pending.write(|w| w.bits(1)); }
                    }
                    // crlf
                    unsafe { self.p.UART.rxtx.write(|w| w.bits(0xa as u32)); }
                    unsafe { self.p.UART.rxtx.write(|w| w.bits(0xd as u32)); }
                }
            } else if command.trim() == "xadc" {
                let vccint: u32 = self.p.TRNG.xadc_vccint.read().bits() as u32;
                let vccaux: u32 = self.p.TRNG.xadc_vccaux.read().bits() as u32;
                let vccbram: u32 = self.p.TRNG.xadc_vccbram.read().bits() as u32;
                let temp: u32 = self.p.TRNG.xadc_temperature.read().bits() as u32;

                self.text.add_text(&mut format!("vccint: {:.3}V", (vccint as f64) / 1365.0));
                self.text.add_text(&mut format!("vccaux: {:.3}V", (vccaux as f64) / 1365.0));
                self.text.add_text(&mut format!("vccbram: {:.3}V", (vccbram as f64) / 1365.0));
                self.text.add_text(&mut format!("temp: {:.2}C", ((temp as f64) * 0.12304) - 273.15));
            } else if command.trim() == "sense" {
                self.xadc.wait_update();
                self.text.add_text(&mut format!("int:  {:.3}V  aux: {:.3}V", (self.xadc.vccint() as f64) / 1365.0, (self.xadc.vccaux() as f64) / 1365.0));
                self.text.add_text(&mut format!("bram: {:.3}V temp: {:.2}C",
                                                (self.xadc.vccbram() as f64) / 1365.0,
                                                ((self.xadc.temp() as f64) * 0.12304) - 273.15 ));
                self.text.add_text(&mut format!("vbus: {:4}mV cc1: {:4}mV cc2: {:4}mV",
                                                self.xadc.vbus_mv(),
                                                self.xadc.cc1_mv(),
                                                self.xadc.cc2_mv()  ));
                self.text.add_text(&mut format!("noise0: {:4} noise1: {:4}", self.xadc.noise0(), self.xadc.noise1()));
                self.text.add_text(&mut format!("audio: 0x{:04x}", self.xadc.audio_sample() ));
            } else if command.trim() == "non" || command.trim() == "noiseon" {
                self.text.add_text(&mut format!("TRNG diagnostic display on" ));
                unsafe{ self.p.TRNG_SERVER.control.write(|w| w.powersave().bit(false) ); }
                self.update_noise = true;
            } else if command.trim() == "noff" {
                unsafe{ self.p.TRNG_SERVER.control.write(|w| w.powersave().bit(true) ); }
                self.update_noise = false;
            } else if command.trim() == "flag" {
                self.text.add_text(&mut format!("xadc flags: 0x{:04x}", self.xadc.flags()));
            } else if command.trim() == "rom" || command.trim() == "r" {
                let mut line: [u32; 3] = [0; 3];
                for adr in 0..3 {
                    line[adr] = self.rom_read(adr as u8);
                }
                self.text.add_text(&mut format!("0x00: 0x{:08x} 0x{:08x} 0x{:08x}", line[0], line[1], line[2] ));
                for adr in 0..3 {
                    line[adr] = self.rom_read((adr + 0x40) as u8);
                }
                self.text.add_text(&mut format!("0x40: 0x{:08x} 0x{:08x} 0x{:08x}", line[0], line[1], line[2] ));
                for adr in 0..3 {
                    line[adr] = self.rom_read((adr + 0x80) as u8);
                }
                self.text.add_text(&mut format!("0x80: 0x{:08x} 0x{:08x} 0x{:08x}", line[0], line[1], line[2] ));
                for adr in 0..3 {
                    line[adr] = self.rom_read((adr + 0xFC) as u8);
                }
                self.text.add_text(&mut format!("0xFC: 0x{:08x} 0x{:08x} 0x{:08x}", line[0], line[1], line[2] ));
            } else if command.trim() == "inject" {
                let (val, inv) = patch_frame(0x35e, 0, rom);
                self.text.add_text(&mut format!("inject: 0x35e, 0, ROM: 0x{:08x}/0x{:08x}", val.unwrap(), inv.unwrap() ));
            } else if command.trim() == "dn" { // dump noise
                unsafe{ self.p.TRNG_SERVER.control.write(|w| w.powersave().bit(false) ); }
                delay_ms(&self.p, 200); // let the noise source stabilize
                self.dump_noise();
                unsafe{ self.p.TRNG_SERVER.control.write(|w| w.powersave().bit(true) ); }
            } else if command.trim() == "spi" {
                // spi performance test
                self.spi_perftest();
            } else if command.trim() == "au" {
                // start sampling
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(true).self_().bit(true).state().bits(3)); }
                self.audio.audio_clocks();
                self.audio.audio_ports();
                self.audio.audio_mixer();

                self.audio.audio_i2s_start();
                self.audio_run = true;
            } else if command.trim() == "ao" {
                // stop sampling
                self.audio.audio_i2s_stop();
                self.audio_run = false;
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3)); }
                delay_ms(&self.p, 50); // give it a moment to power on and initialize before blasting data in
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(true).self_().bit(true).state().bits(3)); }
            } else if command.trim() == "aut" { // sample for 10 seconds and report # of samples seen -- for benchmarking sample rate
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3)); }
                delay_ms(&self.p, 50); // give it a moment to power on and initialize before blasting data in
                self.audio.reset_fifos();
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(true).self_().bit(true).state().bits(3)); }
                delay_ms(&self.p, 50); // give it a moment to power on and initialize before blasting data in

                self.audio.audio_clocks();
                self.audio.audio_ports();
                self.audio.audio_mixer();

                self.audio.audio_i2s_start();
                self.audio_run = true;

                let mut samples: u32 = 0;
                let start: u32 = get_time_ms(&self.p);
                let mut toggle: bool = false;
                let mut buf_a: [u32; AUDIO_FIFODEPTH] = [0; AUDIO_FIFODEPTH];
                let mut buf_b: [u32; AUDIO_FIFODEPTH] = [0; AUDIO_FIFODEPTH];
                loop {
                    if get_time_ms(&self.p) - start > 10_000 {
                        break;
                    }
                    if self.audio.audio_loopback_poll(&mut buf_a, &mut buf_b, toggle) {
                        samples = samples + 1;
                        toggle = !toggle;
                    }
                }

                self.text.add_text(&mut format!("{} samples", samples));

                self.audio.audio_i2s_stop();
                self.audio_run = false;

                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3)); }
                delay_ms(&self.p, 50); // give it a moment to power on and initialize before blasting data in
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(true).self_().bit(true).state().bits(3)); }
            } else if command.trim() == "aloop" {
                if tokens.len() != 2 {
                    self.text.add_text(&mut format!("usage: aloop [on/off]"));
                    return;
                }
                if tokens[1].trim() == "on" {
                    self.audio.audio_loopback(true);
                } else {
                    self.audio.audio_loopback(false);
                }
            } else if command.trim() == "resetec" {
                if tokens.len() != 2 {
                    self.text.add_text(&mut format!("usage: resetec [on/off]"));
                    return;
                }
                self.text.add_text(&mut format!("Resetting EC to {}", tokens[1].trim()));
                if tokens[1].trim() == "on" {
                    unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3).reset_ec().bit(true)); }
                } else {
                    unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3).reset_ec().bit(false)); }
                }
            } else if command.trim() == "ecreset" {
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3).reset_ec().bit(true)); }
                delay_ms(&self.p, 50);
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3).reset_ec().bit(false)); }
            } /* else if command.trim() == "aux" { // xadc audio source
                unsafe{ self.p.POWER.power.write(|w| w.audio().bit(true).self_().bit(true).state().bits(3)); }
                self.audio.audio_clocks();
                self.audio.audio_ports();
                self.audio.audio_mixer();

                self.audio.audio_i2s_start();

                self.audio.audio_loopback_xadc(&mut self.xadc);

                self.audio.audio_i2s_stop();
            } */ else if command.trim() == "ramc" {
                self.ram_clear();
                self.text.add_text(&mut format!("RAM cleared."));
            } /* else if command.trim() == "rno" {
                self.ram_clear();
                self.ram_fill_trng(true, 0, RngType::RingOsc);
                let time: u32 = readpac32!(self, TICKTIMER, time0);
                self.ram_fill_trng(false, 0, RngType::RingOsc);
                let endtime: u32 = readpac32!(self, TICKTIMER, time0);
                self.text.add_text(&mut format!("8MiB ring osc done: {}ms", endtime - time));
            } else if command.trim() == "rna" {
                self.ram_clear();
                self.ram_fill_trng(true, 0, RngType::Avalanche);
                let time: u32 = readpac32!(self, TICKTIMER, time0);
                self.ram_fill_trng(false, 0, RngType::Avalanche);
                let endtime: u32 = readpac32!(self, TICKTIMER, time0);
                self.text.add_text(&mut format!("8MiB avalanche done: {}ms", endtime - time));
            } */ else if command.trim() == "ramx" {
                let errors = self.ram_check();
                self.text.add_text(&mut format!("0x{:x} RAM errors.", errors));
            } else if command.trim() == "rami" {
                let len = self.ram_standby_init();
                self.text.add_text(&mut format!("0x{:x} RAM states.", len));
            } else if command.trim() == "rtcinit" {
                self.rtc.rtc_set(0, 0, 0, 29, 5, 20, Weekdays::FRIDAY);
            } else if command.trim() == "rtcset" {
                if tokens.len() != 8 {
                    self.text.add_text(&mut format!("rtcset: WWW DD MM YY hh mm ss"));
                    self.text.add_text(&mut format!("hh is 24-hr, WWW is day (mon, tue...)"));
                } else {
                    let secs: u32 = match tokens[7].trim().parse::<u32>() {
                        Ok(input) => input,
                        Err(_e) => {self.text.add_text(&mut format!("Can't parse {}", tokens[7])); return;}
                    };
                    let mins: u32 = match tokens[6].trim().parse::<u32>() {
                        Ok(input) => input,
                        Err(_e) => {self.text.add_text(&mut format!("Can't parse {}", tokens[6])); return;}
                    };
                    let hours: u32 = match tokens[5].trim().parse::<u32>() {
                        Ok(input) => input,
                        Err(_e) => {self.text.add_text(&mut format!("Can't parse {}", tokens[5])); return;}
                    };
                    let days: u32 = match tokens[2].trim().parse::<u32>() {
                        Ok(input) => input,
                        Err(_e) => {self.text.add_text(&mut format!("Can't parse {}", tokens[2])); return;}
                    };
                    let months: u32 = match tokens[3].trim().parse::<u32>() {
                        Ok(input) => input,
                        Err(_e) => {self.text.add_text(&mut format!("Can't parse {}", tokens[3])); return;}
                    };
                    let years: u32 = match tokens[4].trim().parse::<u32>() {
                        Ok(input) => input,
                        Err(_e) => {self.text.add_text(&mut format!("Can't parse {}", tokens[4])); return;}
                    };
                    let weekday: Weekdays = match tokens[1].trim().to_ascii_lowercase().as_str() {
                        "mon" => Weekdays::MONDAY,
                        "tue" => Weekdays::TUESDAY,
                        "wed" => Weekdays::WEDNESDAY,
                        "thu" => Weekdays::THURSDAY,
                        "fri" => Weekdays::FRIDAY,
                        "sat" => Weekdays::SATURDAY,
                        "sun" => Weekdays::SUNDAY,
                        _ => {self.text.add_text(&mut format!("Can't parse {}", tokens[1])); return;}
                    };

                    self.rtc.rtc_set(secs as u8, mins as u8, hours as u8, days as u8, months as u8, years as u8, weekday);
                }
            } else if command.trim() == "rng" {
                while self.p.TRNG_KERNEL.status.read().avail().bit_is_clear() {}
                self.text.add_text(&mut format!("rng: {:x}", self.p.TRNG_KERNEL.data.read().bits()));
            } /*else if command.trim() == "ae" {
                let (pass, data) = test_aes_enc(&mut self.aes);
                if pass {
                    self.text.add_text(&mut format!("AES Encrypt passed"));
                } else {
                    self.text.add_text(&mut format!("AES Encrypt failed"));
                }
                for i in 0..4 {
                    self.text.add_text(&mut format!("0x{:x} 0x{:x} 0x{:x} 0x{:x}", data[0 + i*4], data[1 + i*4], data[2 + i*4], data[3 + i*4]));
                }
            } else if command.trim() == "ad" {
                let (pass, data) = test_aes_dec(&mut self.aes);
                if pass {
                    self.text.add_text(&mut format!("AES Decrypt passed"));
                } else {
                    self.text.add_text(&mut format!("AES Decrypt failed"));
                }
                for i in 0..4 {
                    self.text.add_text(&mut format!("0x{:x} 0x{:x} 0x{:x} 0x{:x}", data[0 + i*4], data[1 + i*4], data[2 + i*4], data[3 + i*4]));
                }
            } */  /*else if command.trim() == "sh" {
                self.sha2.config = Sha2Config::ENDIAN_SWAP | Sha2Config::DIGEST_SWAP | Sha2Config::SHA256_EN; // Sha2Config::HMAC_EN; // Sha2Config::SHA256_EN;
                self.sha2.keys = [0; 8];
                self.sha2.init();
                self.sha2.update(SHA_DATA);
                let mut digest: [u32; 8] = [0; 8];
                self.sha2.digest(&mut digest);
                let mut pass: bool = true;
                for i in 0..8 {
                    if digest[i] != SHA_DIGEST[i] {
                        pass = false;
                    }
                }
                if pass {
                    self.text.add_text(&mut format!("SHA test passed"));
                } else {
                    self.text.add_text(&mut format!("SHA test failed"));
                }
                for i in 0..4 {
                    self.text.add_text(&mut format!("0x{:x} 0x{:x}", digest[0 + i*2], digest[1 + i*2]));
                }
            } */ else if command.trim() == "sp" {
                com_txrx(&self.p, COM_SHIPMODE, false);  // send the shipmode command
                self.power = false;
            } else if command.trim() == "gginit" {
                com_txrx(&self.p, COM_GG_FACTORY_CAPACITY, false);
                com_txrx(&self.p, 1100, false); // new capacity argument
                let prev_cap = com_txrx(&self.p, COM_NEXT_DATA, true);
                self.text.add_text(&mut format!("GG capacity set. Old cap: {}mAh", prev_cap));
            } else if command.trim() == "ggcap" {
                com_txrx(&self.p, COM_GG_GET_CAPACITY, false);
                let prev_cap = com_txrx(&self.p, COM_NEXT_DATA, true);
                self.text.add_text(&mut format!("GG capacity: {}mAh", prev_cap));
            } else if command.trim() == "ggfull" {
                com_txrx(&self.p, COM_GG_FULL_CAPACITY, false);
                let full_cap = com_txrx(&self.p, COM_NEXT_DATA, true);
                self.text.add_text(&mut format!("Full capacity: {}mAh", full_cap));
            } else if command.trim() == "ggdebug" {
                com_txrx(&self.p, COM_GG_DEBUG, false);
                let dbg = com_txrx(&self.p, COM_NEXT_DATA, true);
                self.text.add_text(&mut format!("GG debug: {}", dbg));
            } else if command.trim() == "acc" {
                com_txrx(&self.p, COM_ACCEL_UPDATE, false);  // update acceleration
                com_txrx(&self.p, COM_ACCEL_FETCH, false);  // now fetch it
                let x = com_txrx(&self.p, COM_NEXT_DATA, true);
                let y = com_txrx(&self.p, COM_NEXT_DATA, true);
                let z = com_txrx(&self.p, COM_NEXT_DATA, true);
                let id = com_txrx(&self.p, COM_NEXT_DATA, true);
                self.text.add_text(&mut format!("x: {}, y: {}, z: {}, id: 0x{:02x}", x, y, z, id));
            } else if command.trim() == "scanon" {
                self.ssid_print = true;
            } else if command.trim() == "scanoff" {
                self.ssid_print = false;
            } else if command.trim() == "rev" {
                if cfg!(feature = "evt") {
                    self.text.add_text(&mut format!("Rev EVT"));
                }
                if cfg!(feature = "dvt") {
                    self.text.add_text(&mut format!("Rev DVT"));
                }
                if cfg!(feature = "pvt") {
                    self.text.add_text(&mut format!("Rev PVT"));
                }
            } else if command.trim() == "dr" {
                fn get_rk() -> ChainKey {
                    let key = core::iter::repeat(0x42).take(32).collect::<Vec<u8>>();
                    ChainKey::from(key.as_slice())
                }

                self.text.add_text(&mut format!("Starting double-ratchet test"));
                // double-ratchet test
                let mut csprng = ShittyRng::new();

                let time: u32 = readpac32!(self, TICKTIMER, time0);
                let info = b"foobar!";
                let bits_start = csprng.get_bits_generated();
                let bob_keys = RatchetKeyPair::generate(&mut csprng);
                let mut alice = DoubleRatchet::with_peer(
                    &info[..], get_rk(), &mut csprng, &bob_keys.public
                );
                let mut bob = DoubleRatchet::with_keypair(
                    &info[..], get_rk(), bob_keys
                );

                let m1_a = alice.next_sending_key();
                let m2_a = alice.next_sending_key();
                bob.ratchet(&mut csprng, alice.public());
                let m1_b = bob.next_receiving_key();
                let m2_b = bob.next_receiving_key();

                let m3_b = bob.next_sending_key();
                let m4_b = bob.next_sending_key();
                alice.ratchet(&mut csprng, bob.public());
                let m3_a = alice.next_receiving_key();
                let m4_a = alice.next_receiving_key();

                // Note: TRNG is left on, fwiw

                if m1_a != m1_b {
                    self.text.add_text(&mut format!("m1_a error"));
                }
                if m2_a != m2_b {
                    self.text.add_text(&mut format!("m2_a error"));
                }
                if m3_a != m3_b {
                    self.text.add_text(&mut format!("m3_a error"));
                }
                if m4_a != m4_b {
                    self.text.add_text(&mut format!("m4_a error"));
                }

                if m1_a.0 != 0 {
                    self.text.add_text(&mut format!("m1_a.0 error"));
                }
                if m2_a.0 != 1 {
                    self.text.add_text(&mut format!("m2_a.0 error"));
                }
                if m3_a.0 != 0 {
                    self.text.add_text(&mut format!("m3_a.0 error"));
                }
                if m4_a.0 != 1 {
                    self.text.add_text(&mut format!("m4_a.0 error"));
                }

                if m1_a.1 == MessageKey::from(&[0; 32][..]) {
                    self.text.add_text(&mut format!("m1_a.1 error"));
                }
                if m2_a.1 == MessageKey::from(&[0; 32][..]) {
                    self.text.add_text(&mut format!("m2_a.1 error"));
                }
                if m3_a.1 == MessageKey::from(&[0; 32][..]) {
                    self.text.add_text(&mut format!("m3_a.1 error"));
                }
                if m4_a.1 == MessageKey::from(&[0; 32][..]) {
                    self.text.add_text(&mut format!("m4_a.1 error"));
                }

                if m1_a.1 == m2_a.1 {
                    self.text.add_text(&mut format!("m1_a.1 != m2_a.1 error"));
                }
                if m1_a.1 == m3_a.1 {
                    self.text.add_text(&mut format!("m1_a.1 != m3_a.1 error"));
                }
                if m1_a.1 == m4_a.1 {
                    self.text.add_text(&mut format!("m1_a.1 != m4_a.1 error"));
                }

                if m2_a.1 == m1_a.1 {
                    self.text.add_text(&mut format!("m2_a.1 != m1_a.1 error"));
                }
                if m2_a.1 == m3_a.1 {
                    self.text.add_text(&mut format!("m2_a.1 != m3_a.1 error"));
                }
                if m2_a.1 == m4_a.1 {
                    self.text.add_text(&mut format!("m2_a.1 != m4_a.1 error"));
                }

                if m3_a.1 == m1_a.1 {
                    self.text.add_text(&mut format!("m3_a.1 != m1_a.1 error"));
                }
                if m3_a.1 == m2_a.1 {
                    self.text.add_text(&mut format!("m3_a.1 != m2_a.1 error"));
                }
                if m3_a.1 == m4_a.1 {
                    self.text.add_text(&mut format!("m3_a.1 != m4_a.1 error"));
                }

                if m4_a.1 == m1_a.1 {
                    self.text.add_text(&mut format!("m4_a.1 != m1_a.1 error"));
                }
                if m4_a.1 == m2_a.1 {
                    self.text.add_text(&mut format!("m4_a.1 != m2_a.1 error"));
                }
                if m4_a.1 == m3_a.1 {
                    self.text.add_text(&mut format!("m4_a.1 != m4_a.1 error"));
                }
                let endtime: u32 = readpac32!(self, TICKTIMER, time0);
                self.text.add_text(&mut format!("Finish time: {} ms", endtime - time));
                self.text.add_text(&mut format!("Entropy used: {} bits", csprng.get_bits_generated() - bits_start ));
            } else if command.trim() == "h5" {
                use digest::Digest;
                use betrusted_hal::hal_sha512::Sha512;

                const K_DATA: &'static [u8; 142] = b"Every one suspects himself of at least one of the cardinal virtues, and this is mine: I am one of the few honest people that I have ever known";
                const K_EXPECTED_DIGEST: [u64; 8] =    [0x02fc78c0d16b727a, 0x18570a3279e6c97b, 0x113b8871b2e92051, 0x4c0947b20169fedf, 0x1a67094ad04ad031, 0xab5f8cc340125001, 0xffbd7d7af36d3a3a, 0xf7e8465d73bbd86d];
                let mut pass: bool = true;

                let mut hasher = Sha512::new();
                for (_reg, chunk) in K_DATA.chunks(16).enumerate() {
                    let mut temp: [u8; 16] = Default::default();
                    if chunk.len() == 16 {
                        temp.copy_from_slice(chunk);
                        hasher.update(temp);
                    } else {
                        for index in 0..chunk.len() {
                            let lone_value: [u8; 1] = [chunk[index]];
                            hasher.update(&lone_value);
                        }
                    }
                }

                let digest = hasher.finalize();

                for i in 0..64 {
                    let byte: u8 = (((K_EXPECTED_DIGEST[i / 8]) >> ((7 - (i % 8)) * 8)) & 0xff) as u8;
                    if digest[i] != byte {
                        pass = false;
                    }
                }
                if pass {
                    self.text.add_text(&mut format!("Sha512 passed."));
                } else {
                    self.text.add_text(&mut format!("Sha512 failed."));
                }
            } else if command.trim() == "e2" {
                fn vector_read(word_offset: usize) -> u32 {
                    let mut bytes: [u8; 4] = [0; 4];
                    for i in 0..4 {
                        bytes[i] = ENGINE_VECTORS[word_offset*4 + i];
                    }
                    u32::from_le_bytes(bytes)
                }

                ///////////////  APPLY AND RUN ARITHMETIC TEST VECTORS
                let microcode_ptr: *mut u32 = 0xe002_0000 as *mut u32;
                let microcode = microcode_ptr as *mut Volatile<u32>;
                let rf_ptr: *mut u32 = 0xe003_0000 as *mut u32;
                let rf = rf_ptr as *mut Volatile<u32>;

                let mut test_offset: usize = 0x0;
                let mut magic_number: u32;
                let mut passes: Vec<usize> = Vec::new();
                let mut fails: Vec<usize> = Vec::new();
                loop {
                    magic_number = vector_read(test_offset);
                    if magic_number != 0x5645_4354 {
                        break;
                    }
                    test_offset += 1;
                    unsafe {
                        let load_addr = (vector_read(test_offset) >> 16) & 0xFFFF;
                        let code_len = vector_read(test_offset) & 0xFFFF;
                        test_offset += 1;
                        let num_args = (vector_read(test_offset) >> 27) & 0x1F;
                        let window = (vector_read(test_offset) >> 23) & 0xF;
                        let num_vectors = (vector_read(test_offset) >> 0) & 0x3F_FFFF;
                        test_offset += 1;
                        for i in 0..code_len as usize {
                            (*(microcode.add(i))).write( vector_read(test_offset) );
                            test_offset += 1;
                        }

                        test_offset = test_offset + (8 - (test_offset % 8)); // skip over padding

                        // copy in the arguments
                        for _vector in 0..num_vectors {
                            for argcnt in 0..num_args {
                                for word in 0..8 {
                                (*( rf.add( (window * 32 * 8 + argcnt * 8 + word) as usize )) ).write( vector_read(test_offset) );
                                test_offset += 1;
                                }
                            }

                            // setup the engine to run
                            self.p.ENGINE.window.write(|w| w.bits(window));
                            self.p.ENGINE.mpstart.write(|w| w.bits(load_addr));
                            self.p.ENGINE.mplen.write(|w| w.bits(code_len));
                            // start the run
                            self.p.ENGINE.control.write(|w| w.go().set_bit());
                            loop {
                                let status = self.p.ENGINE.status.read().bits();
                                if (status & 1) == 0 {
                                    break;
                                }
                            }

                            // check result
                            let mut vect_pass = true;
                            for word in 0..8 {
                                let expect = vector_read(test_offset);
                                test_offset += 1;
                                let actual = (*( rf.add( (window * 32 * 8 + 31 * 8 + word) as usize ))).read();
                                if expect != actual {
                                    vect_pass = false;
                                }
                            }
                            if vect_pass {
                                passes.push(test_offset);
                            } else {
                                fails.push(test_offset);

                            }
                        }
                    }
                }
                if fails.len() > 0 {
                    self.text.add_text(&mut format!("Engine25519 passed {} out of {} tests.", passes.len(), passes.len() + fails.len()));
                    self.text.add_text(&mut format!("Engine25519 test failed at offsets:"));
                    while fails.len() > 0 {
                        self.text.add_text(&mut format!(" 0x{:04x}", fails.pop().unwrap() as u32 * 4));
                    }
                } else {
                    self.text.add_text(&mut format!("Engine25519 passed {} tests.", passes.len()));
                }
            } else if command.trim() == "ecup" {
                if tokens.len() != 2 {
                    self.text.add_text(&mut format!("ecup [all/fw/gw]"));
                    self.text.add_text(&mut format!("Update EC all/firmware/gateware"));
                    self.text.add_text(&mut format!("Requires pre-load RAM image via USB"));
                    return;
                }
                if tokens[1].trim() == "all" {
                    let len: u32 = EC_FLASH_LEN;
                    let addr: u32 = 0x0_0000;
                    self.text.add_text(&mut format!("EC: Erasing {} bytes at 0x{:08x}", len, addr));
                    com_txrx(&self.p, COM_FLASH_ERASE, false);
                    com_txrx(&self.p, (addr >> 16) as u16, false);
                    com_txrx(&self.p, addr as u16, false);
                    com_txrx(&self.p, (len >> 16) as u16, false);
                    com_txrx(&self.p, len as u16, false);

                    while COM_FLASHACK != com_txrx(&self.p, COM_FLASH_WAITACK, true) { }
                    self.flash_prog_addr = 0;
                    self.flash_prog_len = EC_FLASH_LEN;
                    self.text.add_text(&mut format!("EC: Prog {} bytes at 0x{:08x}", self.flash_prog_len, self.flash_prog_addr));
                    self.flash_prog = true; // because this is a long running process, we fold it into the main loop
                    self.flash_wip = 1;
                    com_txrx(&self.p, COM_FLASHLOCK, false); // stop most EC activity while updating
                } else if tokens[1].trim() == "fw" {
                    let len: u32 = EC_FIRMWARE_LEN;
                    let addr: u32 = EC_GATEWARE_LEN;
                    self.text.add_text(&mut format!("EC: Erasing {} bytes at 0x{:08x}", len, addr));
                    com_txrx(&self.p, COM_FLASH_ERASE, false);
                    com_txrx(&self.p, (addr >> 16) as u16, false);
                    com_txrx(&self.p, addr as u16, false);
                    com_txrx(&self.p, (len >> 16) as u16, false);
                    com_txrx(&self.p, len as u16, false);
                    self.flash_wip = 1;
                    while COM_FLASHACK != com_txrx(&self.p, COM_FLASH_WAITACK, true) { }

                    self.flash_prog_addr = EC_GATEWARE_LEN;
                    self.flash_prog_len = EC_FIRMWARE_LEN;
                    self.text.add_text(&mut format!("EC: Prog {} bytes at 0x{:08x}", self.flash_prog_len, self.flash_prog_addr));
                    self.flash_prog = true; // because this is a long running process, we fold it into the main loop
                    self.flash_wip = 1;
                    com_txrx(&self.p, COM_FLASHLOCK, false); // stop most EC activity while updating
                } else if tokens[1].trim() == "gw" {
                    let len: u32 = EC_GATEWARE_LEN;
                    let addr: u32 = 0x0_0000;
                    self.text.add_text(&mut format!("EC: Erasing {} bytes at 0x{:08x}", len, addr));
                    com_txrx(&self.p, COM_FLASH_ERASE, false);
                    com_txrx(&self.p, (addr >> 16) as u16, false);
                    com_txrx(&self.p, addr as u16, false);
                    com_txrx(&self.p, (len >> 16) as u16, false);
                    com_txrx(&self.p, len as u16, false);
                    self.flash_wip = 1;
                    while COM_FLASHACK != com_txrx(&self.p, COM_FLASH_WAITACK, true) { }

                    self.flash_prog_addr = 0;
                    self.flash_prog_len = EC_GATEWARE_LEN;
                    self.text.add_text(&mut format!("EC: Prog {} bytes at 0x{:08x}", self.flash_prog_len, self.flash_prog_addr));
                    self.flash_prog = true; // because this is a long running process, we fold it into the main loop
                    self.flash_wip = 1;
                    com_txrx(&self.p, COM_FLASHLOCK, false); // stop most EC activity while updating
                } else {
                    self.text.add_text(&mut format!("Unrecognized action."));
                }
            } else if command.trim() == "ecerase" {
                let len: u32 = EC_FLASH_LEN;
                let addr: u32 = 0x0_0000;
                self.text.add_text(&mut format!("EC: Erasing {} bytes at 0x{:08x}", len, addr));
                com_txrx(&self.p, COM_FLASH_ERASE, false);
                com_txrx(&self.p, (addr >> 16) as u16, false);
                com_txrx(&self.p, addr as u16, false);
                com_txrx(&self.p, (len >> 16) as u16, false);
                com_txrx(&self.p, len as u16, false);
                self.flash_wip = 1;
            } else if command.trim() == "ecergw" {
                let len: u32 = EC_GATEWARE_LEN;
                let addr: u32 = 0x0_0000;
                self.text.add_text(&mut format!("EC: Erasing {} bytes at 0x{:08x}", len, addr));
                com_txrx(&self.p, COM_FLASH_ERASE, false);
                com_txrx(&self.p, (addr >> 16) as u16, false);
                com_txrx(&self.p, addr as u16, false);
                com_txrx(&self.p, (len >> 16) as u16, false);
                com_txrx(&self.p, len as u16, false);
                self.flash_wip = 1;
            } else if command.trim() == "ecerfw" {
                let len: u32 = EC_FIRMWARE_LEN;
                let addr: u32 = EC_GATEWARE_LEN;
                self.text.add_text(&mut format!("EC: Erasing {} bytes at 0x{:08x}", len, addr));
                com_txrx(&self.p, COM_FLASH_ERASE, false);
                com_txrx(&self.p, (addr >> 16) as u16, false);
                com_txrx(&self.p, addr as u16, false);
                com_txrx(&self.p, (len >> 16) as u16, false);
                com_txrx(&self.p, len as u16, false);
                self.flash_wip = 1;
            } else if command.trim() == "ecprog" {
                self.flash_prog_addr = 0;
                self.flash_prog_len = EC_FLASH_LEN;
                self.text.add_text(&mut format!("EC: Prog {} bytes at 0x{:08x}", self.flash_prog_len, self.flash_prog_addr));
                self.flash_prog = true; // because this is a long running process, we fold it into the main loop
                self.flash_wip = 1;
                com_txrx(&self.p, COM_FLASHLOCK, false); // stop most EC activity while updating
            } else if command.trim() == "ecprgw" {
                self.flash_prog_addr = 0;
                self.flash_prog_len = EC_GATEWARE_LEN;
                self.text.add_text(&mut format!("EC: Prog {} bytes at 0x{:08x}", self.flash_prog_len, self.flash_prog_addr));
                self.flash_prog = true; // because this is a long running process, we fold it into the main loop
                self.flash_wip = 1;
                com_txrx(&self.p, COM_FLASHLOCK, false); // stop most EC activity while updating
            } else if command.trim() == "ecprfw" {
                self.flash_prog_addr = EC_GATEWARE_LEN;
                self.flash_prog_len = EC_FIRMWARE_LEN;
                self.text.add_text(&mut format!("EC: Prog {} bytes at 0x{:08x}", self.flash_prog_len, self.flash_prog_addr));
                self.flash_prog = true; // because this is a long running process, we fold it into the main loop
                self.flash_wip = 1;
                com_txrx(&self.p, COM_FLASHLOCK, false); // stop most EC activity while updating
            } else if command.trim() == "ecprogtest" {
                let addr: u32 = 0x8_0000;
                self.text.add_text(&mut format!("EC: Prog 256 bytes at 0x{:08x}", addr));
                const TEST_SIZE: usize = 256;
                let test_ptr = EC_FLASH_SRC as *mut [u8; TEST_SIZE];
                for i in 0..256 {
                    unsafe{(*test_ptr)[i] = i as u8;}
                }

                let ram_ptr = EC_FLASH_SRC as *mut [u16; TEST_SIZE/2];
                com_txrx(&self.p, COM_FLASH_PP, false);
                com_txrx(&self.p, (addr >> 16) as u16, false);
                com_txrx(&self.p, addr as u16, false);
                for i in 0..128 {
                    com_txrx(&self.p, unsafe{(*ram_ptr)[i as usize]}, false);
                }
                self.flash_wip = 1;
            } else {
                self.text.add_text(&mut format!("{}: not recognized.", command.trim()));
            }
        }
    }

    pub fn get_line(&self, line: usize)-> String {
        self.text.get_line(line)
    }

    // standalone call to debug when the keyboard isn't available to type commands (e.g. oscilloscope probe access required)
    pub fn audio_standalone(&mut self) {
        self.set_ssid_print(false);
        unsafe{ self.p.POWER.power.write(|w| w.audio().bit(false).self_().bit(true).state().bits(3)); }
        delay_ms(&self.p, 50); // give it a moment to power on and initialize before blasting data in
        self.audio.reset_fifos();
        unsafe{ self.p.POWER.power.write(|w| w.audio().bit(true).self_().bit(true).state().bits(3)); }
        delay_ms(&self.p, 50); // give it a moment to power on and initialize before blasting data in

        self.text.add_text(&mut format!("Running audio stand-alone test"));

        self.audio.audio_clocks();
        self.audio.audio_ports();
        self.audio.audio_mixer();

        let code: [u8; 4] = self.audio.get_i2s_config();
        self.text.add_text(&mut format!("I2S code: {:02x} {:02x} {:02x} {:02x} ", code[0], code[1], code[2], code[3]));
        self.text.add_text(&mut format!("Headset code: 0x{:02x}", self.audio.get_headset_code()) );
        //self.text.add_text(&mut format!("Dacflag code: 0x{:02x}", self.audio.get_dacflag_code()) );
        //self.text.add_text(&mut format!("HP pwr code: 0x{:02x}", self.audio.get_hp_status()) );

        let mut samples: u32 = 0;
        let mut toggle: bool = false;
        let mut buf_a: [u32; AUDIO_FIFODEPTH] = [0; AUDIO_FIFODEPTH];
        let mut buf_b: [u32; AUDIO_FIFODEPTH] = [0; AUDIO_FIFODEPTH];

        let start: u32 = get_time_ms(&self.p);
        self.audio.audio_i2s_start();
        self.audio_run = true;
        let mut had_overflow = false;
        let mut rx_error = false;
        loop {
            if self.audio.audio_loopback_poll(&mut buf_a, &mut buf_b, toggle) {
                samples = samples + 1;
                toggle = !toggle;
            } else {
                for i in 0..AUDIO_FIFODEPTH {
                    if buf_a[i] == 0xdeadbeef {
                        had_overflow = true;
                    }
                    if buf_b[i] == 0xdeadbeef {
                        had_overflow = true
                    }
                }
            }
            if (self.p.AUDIO.rx_stat.read().bits() & 0x3) != 0 {
                rx_error = true;
            }
            if get_time_ms(&self.p) - start > 10_000 {
                break;
            }
        }

        self.text.add_text(&mut format!("{} samples", samples));
        self.text.add_text(&mut format!("Overflow flag: {}", had_overflow));
        self.text.add_text(&mut format!("{}, {:08x}, {:08x}", rx_error, self.p.AUDIO.rx_stat.read().bits(), self.p.AUDIO.tx_stat.read().bits()));

        self.audio.audio_i2s_stop();
        self.audio_run = false;
    }
}

pub struct TextArea {
    height_lines: usize,
    text: Vec<String>,
}

impl TextArea {
    pub fn new(lines: usize) -> Self {
        TextArea {
            height_lines: lines,
            text: Vec::new(),
        }
    }

    pub fn get_height(&self) -> usize { self.height_lines }
    pub fn get_width(&self) -> usize { 38 as usize }

    pub fn get_line(&self, line: usize) -> String {
        if line > self.height_lines {
            String::from("")
        } else {
            if let Some(line) = self.text.get(line) {
                line.clone()
            } else {
                String::from("")
            }
        }
    }

    pub fn add_text(&mut self, text: &mut String) {
        // add the new text
        let strbytes = text.as_bytes();
        for chunk in strbytes.chunks(self.get_width()) {
            self.text.insert(0, String::from_utf8(chunk.to_vec()).unwrap());
        }

        // trim the old text
        while self.text.len() > self.height_lines {
            self.text.pop();
        }
    }
}

#[entry]
fn main() -> ! {
    // Initialize the no-MMU version of Xous, which will give us
    // basic access to tasks and interrupts.
    xous_nommu::init();

    let p = betrusted_pac::Peripherals::take().unwrap();
    // note -- leaving audio on for testing, should not be on by default in "normal" systems to save power
    unsafe{ p.POWER.power.write(|w| w.self_().bit(true).state().bits(3).audio().bit(true)); }

    com_txrx(&p, COM_RESET_LINK as u16, false);  // reset the link
    delay_ms(&p, 5); // give it time to reset

    p.SRAM_EXT.read_config.write( |w| w.trigger().bit(true) );  // check SRAM config
    i2c_init(&p, CONFIG_CLOCK_FREQUENCY / 1_000_000);
    time_init(&p);

    let cr = p.SRAM_EXT.config_status.read().bits(); // pull out config params for debug
    unsafe {
        let heap_start = &_sheap as *const u8 as usize;
        let heap_size = &_heap_size as *const u8 as usize;
        ALLOCATOR.init(heap_start, heap_size);
        DBGSTR[4] = heap_start as u32;  // some debug visibility on heap initial parameters
        DBGSTR[6] = heap_size as u32;
        DBGSTR[2] = cr;
    }

    let display: LockedBtDisplay = LockedBtDisplay::new();
    display.lock().init(CONFIG_CLOCK_FREQUENCY);

    let mut keyboard: KeyManager = KeyManager::new();

    // initialize vibe motor patch
/*    unsafe{ p.GPIO.drive.write(|w| w.bits(4)); }
    unsafe{ p.GPIO.output.write(|w| w.bits(0)); }*/

    let radius: u32 = 14;
    let size: Size = display.lock().size();
    let mut cur_time: u32 = get_time_ms(&p);
    let mut _stat_array: [u16; 10] = [0; 10];
    let mut gg_array: [u16; 4] = [0; 4];
    let mut state_of_charge: i16 = 100;
    let mut remaining_capacity: i16 = 1000;
    let mut line_height: i32 = 18;
    let left_margin: i32 = 10;
    let mut bouncy_ball: Bounce = Bounce::new(radius, Rectangle::new(Point::new(0, line_height * 21), Point::new(size.width as i32, size.height as i32 - 1)));
    let mut repl: Repl = Repl::new();
    repl.rtc.clear_alarm(); // clear any RTC wake-up alarm, in case it was set previously

    let mut nd: u8 = 0;
    let mut d1: char = ' ';
    let mut d2: char = ' ';
    let mut nu: u8 = 0;
    let mut u1: char = ' ';
    let mut u2: char = ' ';

    let mut samples: u32 = 0;

    let mut loopstate: u16 = 0;
    let mut loopdelay: u32 = 50;
    let mut testdelay: u32 = get_time_ms(&p);
    let mut com_function: u16 = COM_GASGAUGE;
    let mut flash_prog_ptr: u32 = 0xFFFF_FFFF;

    let mut ssid_list: [[u8; 32]; 6] = [[0; 32]; 6]; // index as ssid_list[6][32]

    let mut first_time: bool = true;
    let mut phase: u32 = 0;
    loop {
        if get_time_ms(&p) - testdelay > 10_000 && false {  // change to true to test RTC self-wakeup loop
            testdelay = get_time_ms(&p);
            repl.rtc.wakeup_alarm(5);
            // power down
            repl.power = false;
        }
        display.lock().clear();
        if repl.power == false {
            p.POWER.power.write(|w| w.ec_snoop().bit(true));
            if get_time_ms(&p) - cur_time > 50 {
                cur_time = get_time_ms(&p);
                repl.xadc.wait_update();
                if repl.xadc.vbus_mv() > 1500 {
                    Font12x16::render_str("Remove charger")
                    .stroke_color(Some(BinaryColor::On))
                    .translate(Point::new(85, 250))
                    .draw(&mut *display.lock());

                    Font12x16::render_str("to enter standby")
                    .stroke_color(Some(BinaryColor::On))
                    .translate(Point::new(70, 270))
                    .draw(&mut *display.lock());

                    display.lock().blocking_flush();
                } else {
                    if false {
                        Font12x16::render_str("Betrusted in Standby")
                        .stroke_color(Some(BinaryColor::On))
                        .translate(Point::new(50, 250))
                        .draw(&mut *display.lock());

                        Font12x16::render_str("Press F1 and F4 to power on")
                        .stroke_color(Some(BinaryColor::On))
                        .translate(Point::new(7, 270))
                        .draw(&mut *display.lock());

                        display.lock().blocking_flush();
                    } else {
                        display.lock().blocking_flush();
                        display.lock().display_bitmap(logo::LOGO_MAP);
                    }

                    unsafe{p.POWER.power.write(|w| w
                        .self_().bit(false)
                        .state().bits(1));} // FIXME: figure out how to float the state bit while system is running...
                    com_txrx(&p, COM_POWERDOWN as u16, false);  // 0x9000 code instructs EC to do a powerdown
                    com_txrx(&p, COM_RESET_LINK as u16, true);  // reset the link
                    delay_ms(&p, 100); // don't DoS the EC

                }
            }
            continue; // this creates the illusion of being powered off even if we're plugged in
        }

        if repl.audio_run {
            if repl.audio.audio_loopback_quick() {
                samples = samples + 1;
                repl.text.add_text(&mut format!("{} samples", samples));
            }
        }

        let mut cur_line: i32 = 5;

        let uptime = format!{"Uptime {}s", (get_time_ms(&p) / 1000) as u32};
        line_height = 18;
        Font12x16::render_str(&uptime)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin,cur_line))
        .draw(&mut *display.lock());
        cur_line += line_height;

        // power state testing ONLY - force a power off in 5 seconds
        /*
        if get_time_ms(&p) > 5000 {
            repl.force_poweroff();
        }
        */

        bouncy_ball.update();
        let circle = egcircle!(bouncy_ball.loc, bouncy_ball.radius,
                               stroke_color = Some(BinaryColor::Off), fill_color = Some(BinaryColor::On));
        circle.draw(&mut *display.lock());

        // ping the EC and update various records over time
        if get_time_ms(&p) - cur_time > loopdelay {
            if repl.get_flash_wip() != 0 {
                if repl.get_flash_prog() {
                    if flash_prog_ptr > repl.get_flash_prog_len() + repl.get_flash_prog_addr() {
                        flash_prog_ptr = repl.get_flash_prog_addr();
                    }
                    loopdelay = 0;
                    repl.text.add_text(&mut format!("EC prog 0x{:06x}", flash_prog_ptr));
                    for _ in 0..4 { // fill in 4k chunks, a compromise between UI updates and fast programming
                        for _ in 0..4 { // FIFO is 1280 deep, so fill it up with 1k of programming data to reduce sync overheads
                            if flash_prog_ptr < repl.get_flash_prog_len() + repl.get_flash_prog_addr() {
                                let addr = flash_prog_ptr;
                                let ram_ptr = (EC_FLASH_SRC + flash_prog_ptr) as *mut [u16; 128];
                                com_txrx(&p, COM_FLASH_PP, false);
                                com_txrx(&p, (addr >> 16) as u16, false);
                                com_txrx(&p, addr as u16, false);
                                for i in 0..128 {
                                    com_txrx(&p, unsafe{(*ram_ptr)[i as usize]}, false);
                                }
                                flash_prog_ptr += 256;
                            }
                        }
                        loop {
                            let ack = com_txrx(&p, COM_FLASH_WAITACK, true);
                            if ack == COM_FLASHACK {
                                break;
                            }
                        }
                    }
                    if flash_prog_ptr >= repl.get_flash_prog_len() + repl.get_flash_prog_addr() {
                        repl.set_flash_wip(0);
                        repl.set_flash_prog(false);
                        flash_prog_ptr = 0xFFFF_FFFF;
                        com_txrx(&p, COM_FLASHUNLOCK, false);
                        loopdelay = 50;
                        repl.text.add_text(&mut format!("Imaging done!"));
                        repl.text.add_text(&mut format!("Type 'ecreset' to load image into EC"));
                    }
                } else {
                    loopdelay = 50;
                    repl.text.add_text(&mut format!("EC flash op pending seq# {}", repl.get_flash_wip()));
                    repl.set_flash_wip(repl.get_flash_wip() + 1);
                    let ack = com_txrx(&p, COM_FLASH_WAITACK, true);
                    if ack == COM_FLASHACK {
                        repl.set_flash_wip(0);
                        repl.text.add_text(&mut format!("Flash op done."));
                    }
                }
            } else {
                if false {  // set to true to debug com bus
                    let mut tx_index: usize = 0;
                    if tx_index % 32  == 0 {
                        gg_array[0] = 0xFACE;
                        com_txrx(&p, 0xFFFF, false); // send link reset command
                        delay_ms(&p, 100);
                        com_txrx(&p, COM_LINK_TEST as u16, true); // restart the link test
                        loopdelay = 1000;
                        tx_index = 0;
                        loopstate = 0;
                    } else {
                        let value: u16 = com_txrx(&p, COM_NEXT_DATA, true) as u16;
                        if ((value - loopstate) > 0) && ((value & 0xFF) == 0xf0) {
                            gg_array[0] = value - loopstate;
                            gg_array[1] = value;
                            loopdelay = 50;
                        } else {
                            gg_array[0] = value;
                            loopdelay = 1000;
                        }
                        loopstate = value;
                    }
                    tx_index += 1;
                } else {
                    // repl.text.add_text(&mut format!("COM: {:04x}", com_function));
                    if com_function == COM_GASGAUGE {
                        com_txrx(&p, COM_GASGAUGE as u16, false);
                        for i in 0..gg_array.len() {
                            gg_array[i] = com_txrx(&p, COM_NEXT_DATA, true) as u16;
                        }
                        loopdelay = 100;
                        com_function = COM_POWER_SOC;
                    } else if com_function == COM_POWER_SOC {
                        com_txrx(&p, COM_POWER_SOC, false);
                        state_of_charge = com_txrx(&p, COM_NEXT_DATA, true) as i16;
                        com_function = COM_POWER_REMAINING;
                        loopdelay = 100;
                    } else if com_function == COM_POWER_REMAINING {
                        com_txrx(&p, COM_POWER_REMAINING, false);
                        remaining_capacity = com_txrx(&p, COM_NEXT_DATA, true) as i16;
                        com_function = COM_USBCC;
                        loopdelay = 100;
                    } else if com_function == COM_USBCC {
                        com_txrx(&p, COM_USBCC as u16, false);
                        let value = com_txrx(&p, COM_NEXT_DATA, true);
                        if value == 1 {
                            repl.text.add_text(&mut format!("USB CC event:"));
                            for i in 0..4 {
                                let value = com_txrx(&p, COM_NEXT_DATA, true);
                            repl.text.add_text(&mut format!("status {}: 0x{:2x}", i, value));
                            }
                        } else if value != 0 { // the link was empty or resetting
                            repl.text.add_text(&mut format!("USBCC error 0x{:4x}", value));
                            com_function = COM_GASGAUGE;
                        } else { // value was 0, pass to next function
                            // regardless, clear the returned data
                            for _ in 0..4 {
                                com_txrx(&p, COM_NEXT_DATA, true);
                            }
                            com_function = COM_SSID_CHECK;
                        }
                        loopdelay = 100;
                    } else if com_function == COM_SSID_CHECK {
                        com_txrx(&p, COM_SSID_CHECK, false);
                        if com_txrx(&p, COM_NEXT_DATA, true) == 1 {
                            com_txrx(&p, COM_SSID_FETCH, false); // pre-prime the pipe, so the next result is what we want
                            loopdelay = 500; // give a bit of extra time for the next fetch to happen
                            com_function = COM_SSID_FETCH;
                        } else {
                            loopdelay = 100;
                            com_function = COM_GASGAUGE;
                        }
                    } else if com_function == COM_SSID_FETCH {
                        // ASSUME: entering this state, the previous caller issued a COM_SSID_FETCH command
                        for i in 0..16 * 6 {
                            let data = com_txrx(&p, COM_NEXT_DATA, true);
                            let mut lsb : u8 = (data & 0xff) as u8;
                            let mut msb : u8 = ((data >> 8) & 0xff) as u8;
                            if lsb == 0 { lsb = 0x20; }
                            if msb == 0 { msb = 0x20; }
                            ssid_list[i / 16][(i % 16) * 2] = lsb;
                            ssid_list[i / 16][(i % 16) * 2 + 1] = msb;
                        }
                        if repl.get_ssid_print() {
                            for i in 0..6 {
                                let ssid = str::from_utf8(&ssid_list[i]);
                                match ssid {
                                    Ok(textid) => repl.text.add_text(&mut format!("{}: {}", i, textid)),
                                    _ => repl.text.add_text(&mut format!("-> SSID parse error")),
                                }
                            }
                        }
                        loopdelay = 100;

                        com_txrx(&p, COM_RESET_LINK, false); // send link reset command
                        delay_ms(&p, 5); // give it time to reset
                        com_function = COM_GASGAUGE;
                    } else {
                        com_function = COM_GASGAUGE;
                        loopdelay = 100;
                    }
                }
            }
            cur_time = get_time_ms(&p);
        }
        /*
        for i in 0..4 {
            // but update the result every loop iteration
            let dbg = format!{"s{}: 0x{:04x}  s{}: 0x{:04x}", i*2, stat_array[i*2], i*2+1, stat_array[i*2+1]};
            Font12x16::render_str(&dbg)
            .stroke_color(Some(BinaryColor::On))
            .translate(Point::new(left_margin, cur_line))
            .draw(&mut *display.lock());
            cur_line += line_height;
        }*/
        let dbg = format!{"avg current: {}mA", (gg_array[0] as i16)};
        //let dbg = format!{"Looptest: 0x{:04x}", (gg_array[0] as i16)};
        Font12x16::render_str(&dbg)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin, cur_line))
        .draw(&mut *display.lock());

        cur_line += line_height;
        let dbg = format!{"sby current: {}mA", (gg_array[1] as i16)};
        //let dbg = format!{"Looptest: 0x{:04x}", (gg_array[1] as i16)};
        Font12x16::render_str(&dbg)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin, cur_line))
        .draw(&mut *display.lock());

        cur_line += line_height;
        let dbg = format!{"{}mV / {}mA / {}%", gg_array[2], remaining_capacity, state_of_charge};
        Font12x16::render_str(&dbg)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin, cur_line))
        .draw(&mut *display.lock());

        if repl.is_locked() {
            delay_ms(&p, 500); // give some time for the key hit to go up
            // clear the key up event
            loop {
                if p.KEYBOARD.ev_pending.read().bits() != 0 {
                    unsafe{ &p.KEYBOARD.ev_pending.write(|w| w.bits(1)); }
                    break;
                }
            }
            // now wait for a keydown event
            loop {
                if p.KEYBOARD.ev_pending.read().bits() != 0 {
                    unsafe{ &p.KEYBOARD.ev_pending.write(|w| w.bits(1)); }
                    repl.unlock();
                    break;
                }
            }
        }
        let (keydown, keyup) = keyboard.update();
        if keydown.is_some() {
            let mut keyvect = keydown.unwrap();
            nd = keyvect.len() as u8;

            if nd >= 1 {
                let (r, c) = keyvect.pop().unwrap();
                let scancode = map_qwerty((r,c));
                let c: char;
                match scancode.key {
                    None => c = ' ',
                    _ => c = scancode.key.unwrap(),
                }
                d1 = c;
                repl.input_char(c);
            }
            if nd >= 2 {
                let (r, c) = keyvect.pop().unwrap();
                let scancode = map_qwerty((r,c));
                let c: char;
                match scancode.key {
                    None => c = ' ',
                    _ => c = scancode.key.unwrap(),
                }
                d2 = c;
            }
        }

        if keyup.is_some() {
            let mut keyvect = keyup.unwrap();
            nu = keyvect.len() as u8;

            if nu >= 1 {
                let (r, c) = keyvect.pop().unwrap();
                let scancode = map_qwerty((r,c));
                let c: char;
                match scancode.key {
                    None => c = ' ',
                    _ => c = scancode.key.unwrap(),
                }
                u1 = c;
            }
            if nu >= 2 {
                let (r, c) = keyvect.pop().unwrap();
                let scancode = map_qwerty((r,c));
                let c: char;
                match scancode.key {
                    None => c = ' ',
                    _ => c = scancode.key.unwrap(),
                }
                u2 = c;
            }
        }

        cur_line += line_height;
        let dbg = format!{"nd:{} d1:{} d2:{}     nu:{} u1:{} u2:{}", nd, d1, d2, nu, u1, u2};
        Font8x16::render_str(&dbg)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin, cur_line))
        .draw(&mut *display.lock());

        if !repl.audio_run {
            cur_line += line_height;
            repl.rtc.rtc_update();
            let dbg = format!{"{:2}:{:02}:{:02}, {:}/{:}/20{:}", repl.rtc.hours, repl.rtc.minutes, repl.rtc.seconds, repl.rtc.months, repl.rtc.days, repl.rtc.years};
            Font12x16::render_str(&dbg)
            .stroke_color(Some(BinaryColor::On))
            .translate(Point::new(left_margin, cur_line))
            .draw(&mut *display.lock());
        } else {
            cur_line += line_height;
            let dbg = format!{"RTC paused for audio"};
            Font12x16::render_str(&dbg)
            .stroke_color(Some(BinaryColor::On))
            .translate(Point::new(left_margin, cur_line))
            .draw(&mut *display.lock());
        }

        // draw a demarcation line
        cur_line += line_height + 2;
        Line::<BinaryColor>::new(Point::new(left_margin, cur_line),
        Point::new(size.width as i32 - left_margin, cur_line))
        .stroke_color(Some(BinaryColor::On))
        .draw(&mut *display.lock());

        // split string into 4 lines and render
        cur_line += 4;
        line_height = 15; // shorter line, smaller font

        for line in (0..NUM_LINES).rev() {
            let out = repl.get_line(line);
            Font8x16::render_str(&out)
            .stroke_color(Some(BinaryColor::On))
            .translate(Point::new(left_margin, cur_line))
            .draw(&mut *display.lock());
            cur_line += line_height;
        }

        let cmd = repl.get_cmd();
        Font8x16::render_str(&cmd)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin, cur_line))
        .draw(&mut *display.lock());

        cur_line += line_height;
        let mut input = repl.get_input();
        if (get_time_ms(&p) / 500) % 2 == 0 {
            input.push('_'); // add an insertion carat
        }
        Font8x16::render_str(&input)
        .stroke_color(Some(BinaryColor::On))
        .translate(Point::new(left_margin, cur_line))
        .draw(&mut *display.lock());

        cur_line += line_height;
        const GRAPH_MARGIN: i32 = 18;
        Line::<BinaryColor>::new(Point::new(GRAPH_MARGIN, cur_line + 128),
        Point::new(size.width as i32 - GRAPH_MARGIN, cur_line + 128))
        .stroke_color(Some(BinaryColor::On))
        .draw(&mut *display.lock());
        Line::<BinaryColor>::new(Point::new(GRAPH_MARGIN, cur_line + 64),
        Point::new(size.width as i32 - GRAPH_MARGIN, cur_line + 64))
        .stroke_color(Some(BinaryColor::On))
        .draw(&mut *display.lock());
        Line::<BinaryColor>::new(Point::new(GRAPH_MARGIN, cur_line + 0),
        Point::new(size.width as i32 - GRAPH_MARGIN, cur_line + 0))
        .stroke_color(Some(BinaryColor::On))
        .draw(&mut *display.lock());
        Line::<BinaryColor>::new(Point::new(size.width as i32 - GRAPH_MARGIN, cur_line),
        Point::new(size.width as i32 - GRAPH_MARGIN, cur_line + 128))
        .stroke_color(Some(BinaryColor::On))
        .draw(&mut *display.lock());
        Line::<BinaryColor>::new(Point::new(GRAPH_MARGIN, cur_line),
        Point::new(GRAPH_MARGIN, cur_line + 128))
        .stroke_color(Some(BinaryColor::On))
        .draw(&mut *display.lock());
        if repl.get_update_noise() {
            repl.sample_noise();
            let noise0: [u16; 300] = repl.get_noise0();
            let noise1: [u16; 300] = repl.get_noise1();
            let mut x = GRAPH_MARGIN;
            for index in 0..299 {
                Line::<BinaryColor>::new(Point::new(x, cur_line + 64 - noise0[index] as i32 / 64),
                Point::new(x+1, cur_line + 64 - noise0[index+1] as i32 / 64))
                .stroke_color(Some(BinaryColor::On))
                .draw(&mut *display.lock());
                x = x + 1;
            }
            x = GRAPH_MARGIN;
            for index in 0..299 {
                Line::<BinaryColor>::new(Point::new(x, cur_line + 128 - noise1[index] as i32 / 64),
                Point::new(x+1, cur_line + 128 - noise1[index+1] as i32 / 64))
                .stroke_color(Some(BinaryColor::On))
                .draw(&mut *display.lock());
                x = x + 1;
            }
        }

        display.lock().flush().unwrap();

        if first_time {
            //phase = repl.ram_fill_trng(true, phase, RngType::Avalanche);
            first_time = false;
        } else {
            //phase = repl.ram_fill_ringosc(false, phase, RngType::Avalanche);
        }
    }
}
