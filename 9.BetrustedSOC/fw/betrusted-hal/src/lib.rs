#![no_std]

#[macro_use]
extern crate alloc;
extern crate bitflags;
extern crate volatile;
extern crate rand_core;
extern crate digest;

pub mod hal_i2c;
pub mod hal_time;
pub mod hal_lcd;
pub mod hal_com;
pub mod hal_kbd;
pub mod hal_uart;
pub mod hal_xadc;

#[cfg(feature = "pvt")]
pub mod hal_tlv320aic3100;
#[cfg(not(feature = "pvt"))]
pub mod hal_audio;

pub mod hal_rtc;
//pub mod hal_aes;
//pub mod hal_sha2;
pub mod hal_shittyrng;
pub mod hal_sha512;

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
