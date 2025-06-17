#[allow(dead_code)]

/// LCD hardware abstraction layer
/// 
/// The API for the betrusted LCD needs to be security-aware. Untrusted content
/// cannot be rendered into areas reserved for system messages, and untrusted images
/// should be rendered with a distinct border. As a result, the API will model
/// the display as a series of objects that are rendered by the system into a
/// framebuffer. This is less computationally efficient than just handing 
/// processes a "bag of bits" frame buffer, but allows for fine-grained tuning of
/// how the OS manages and displays trusted and untrusted information as we learn
/// more about how the system is used. 
/// 
/// On the other side of the API is the HAL. The system exposes the LCD as a 
/// distinct memory region, along with some CSRs that control the automatic
/// rastering of the memory to the LCD. The LCD itself has the unique property
/// in that it will persistently display the last image sent to it, unless 
/// it is explicitly powered down or cleared.
/// 
/// The BtDisplay and LockedBtDisplay objects are considered to be HAL-layer
/// interfaces. They should not be directly called by untrusted programs, they are intended for
/// the OS to manipluate the frame buffer directly.

extern crate embedded_graphics;
use embedded_graphics::drawable::Pixel;
use embedded_graphics::geometry::Size;
use embedded_graphics::pixelcolor::{BinaryColor};
use embedded_graphics::DrawTarget;
use spin::Mutex;
use core::ops::Deref;
use crate::hal_time::get_time_ms;

/// FIXME: figure out a way to get LCD_FB mapped to the _lcdfb symbol without crashing RLS
const LCD_FB: *mut [u32; FB_SIZE] = 0xB000_0000 as *mut [u32; FB_SIZE];
const FB_WIDTH_WORDS: usize = 11;
const FB_WIDTH_PIXELS: usize = 336;
const FB_LINES: usize = 536;
const FB_SIZE: usize = FB_WIDTH_WORDS * FB_LINES; // 44 bytes by 536 lines

/// BtDisplay abstraction for embedded-graphics library
/// See LockedBtDisplay for API docs
pub struct BtDisplay {
        interface: betrusted_pac::Peripherals,
        fb: [u32; FB_SIZE],
        timestamp: u32,
}

impl BtDisplay {
    pub fn new() -> Self {
        let mut ret: BtDisplay =
        unsafe{
            BtDisplay{
                interface: betrusted_pac::Peripherals::steal(),
                fb: [0xFFFF_FFFF; FB_SIZE],
                timestamp: 0,
            }
        };
        // unset the dirty bits in the local fb array copy
        for words in 0..FB_SIZE {
            if words % FB_WIDTH_WORDS == 10 {
                ret.fb[words] = 0x0000_FFFF;
            }
        }
        ret.timestamp = get_time_ms(&ret.interface);

        ret
    }

    pub fn init(&self, clk_mhz: u32) {
        lcd_init(&self.interface, clk_mhz);
        lcd_sync_clear(&self.interface);
    }

    pub fn flush(&mut self) -> Result<(), ()> {
        if !lcd_busy(&self.interface) {
            if get_time_ms(&self.interface) - self.timestamp > 25 { // limit update rate to 40Hz
                // copy over the local framebuffer, then call an update
                for words in 0..FB_SIZE {
                    unsafe {
                        (*LCD_FB)[words] = self.fb[words];
                    }
                }
                lcd_update_dirty(&self.interface);
                self.timestamp = get_time_ms(&self.interface);

                // clear all the dirty bits, under the theory that it's time-wise cheaper on average
                // to visit every line and clear the dirty bits than it is to do an update_all()
                for lines in 0..FB_LINES {
                    self.fb[lines * FB_WIDTH_WORDS + (FB_WIDTH_WORDS - 1)] &= 0x0000_FFFF;
                }
            }
        }
        Ok(())
    }

    /// Blocking flush for emergency system messages and so forth
    pub fn blocking_flush(&mut self) {
        while lcd_busy(&self.interface) {}  // wait until the last flush is done

        for words in 0..FB_SIZE {
            unsafe {
                (*LCD_FB)[words] = self.fb[words];
            }
        }
        lcd_update_all(&self.interface);
        // clear dirty bits in case there's more to come
        for lines in 0..FB_LINES {
            self.fb[lines * FB_WIDTH_WORDS + (FB_WIDTH_WORDS - 1)] &= 0x0000_FFFF;
        }

        while lcd_busy(&self.interface) {}  // wait until the last flush is done
    }

    pub fn display_bitmap(&mut self, bmp: [u32; FB_SIZE]) {
        for words  in 0..FB_SIZE {
            self.fb[words] = bmp[words];
            // keep fb and hardware buffer in sync
            unsafe {
                (*LCD_FB)[words] = bmp[words];
            }
        }
        lcd_update_all(&self.interface);
        // clear dirty bits in case there's more to come
        for lines in 0..FB_LINES {
            self.fb[lines * FB_WIDTH_WORDS + (FB_WIDTH_WORDS - 1)] &= 0x0000_FFFF;
        }

        while lcd_busy(&self.interface) {}  // wait until the last flush is done
    }

    pub fn clear(&mut self) {
        let mut line_dirty: bool = false;
        for words in 0..FB_SIZE {
            if words % FB_WIDTH_WORDS != 10 {
                if self.fb[words] != 0xFFFF_FFFF {
                    self.fb[words] = 0xFFFF_FFFF;
                    line_dirty = true;
                }
            } else {
                if ((self.fb[words] & 0xFFFF) != 0xFFFF) || line_dirty {
                    self.fb[words] = 0x0001_FFFF;
                }
                line_dirty = false;
            }
        }
    }
}

/// LockedBtDisplay - Mutex-wrapped BtDisplay object
/// 
/// Refer to BtDisplay methods by calling the lock() method.
/// For calls that need a mutable display, use &mut *display.lock()
/// 
/// Before using the display, one needs to call init() with the appropriate
/// CPU clock frequency. This call will also synchronize the on-board framebuffer
/// with the state of the memory cells in the LCD.
pub struct LockedBtDisplay(Mutex<BtDisplay>);

impl LockedBtDisplay {
    pub fn empty() -> LockedBtDisplay {
        LockedBtDisplay(Mutex::new(BtDisplay::new()))
    }

    pub fn new() -> LockedBtDisplay {
        LockedBtDisplay(Mutex::new(BtDisplay::new()))
    }
}

impl Deref for LockedBtDisplay {
    type Target = Mutex<BtDisplay>;

    fn deref(&self) -> &Mutex<BtDisplay> {
        &self.0
    }
}

impl DrawTarget<BinaryColor> for BtDisplay {
    fn size(&self) -> Size {
        Size::new(FB_WIDTH_PIXELS as u32, FB_LINES as u32)
    }

    fn draw_pixel(&mut self, pixel:Pixel<BinaryColor>) {
        let Pixel(coord, color) = pixel;
        match color {
            BinaryColor::Off => 
                self.fb[ (coord.x / 32 + coord.y * FB_WIDTH_WORDS as i32) as usize] |= 
                    1 << (coord.x % 32),
            BinaryColor::On =>
                self.fb[ (coord.x / 32 + coord.y * FB_WIDTH_WORDS as i32) as usize] &= 
                    !(1 << (coord.x % 32)),
        }
        // set the dirty bit on the line
        self.fb[(coord.y * FB_WIDTH_WORDS as i32 + (FB_WIDTH_WORDS as i32 - 1)) as usize] |= 0x1_0000;
    }
}

/// Beneath this line are pure-HAL layer, and should not be user-visible

/// "synchronous clear" -- must be called on init, so that the state of the LCD
/// internal memory is consistent with the state of the frame buffer
fn lcd_sync_clear(p: &betrusted_pac::Peripherals) {
    for words in 0..FB_SIZE {
        if words % FB_WIDTH_WORDS != 10 {
            unsafe{ (*LCD_FB)[words] = 0xFFFF_FFFF; }
        } else {
            unsafe{ (*LCD_FB)[words] = 0x0000_FFFF; } // don't set the dirty bit
        }
    }
    lcd_update_all(p); // because we force an all update here
    while lcd_busy(p) {}
}

fn lcd_update_all(p: &betrusted_pac::Peripherals) {
    p.MEMLCD.command.write( |w| w.update_all().bit(true));
}

fn lcd_update_dirty(p: &betrusted_pac::Peripherals) {
    p.MEMLCD.command.write( |w| w.update_dirty().bit(true));
}

fn lcd_init(p: &betrusted_pac::Peripherals, clk_mhz: u32) {
    unsafe{ p.MEMLCD.prescaler.write( |w| w.bits( (clk_mhz / 2_000_000) - 1) ); }
}

fn lcd_busy(p: &betrusted_pac::Peripherals) -> bool {
    if p.MEMLCD.busy.read().bits() == 1 {
        true
    } else {
        false
    }
}
