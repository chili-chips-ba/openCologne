#![allow(dead_code)]
use rand_core::{RngCore, Error, impls};
use super::hal_xadc::*;

/// This is a "beginner's" RNG just to get API integration working with Rust.
/// Do not use this for anything serious, unless you want to be sad.

pub struct ShittyRng {
    p: betrusted_pac::Peripherals,
    xadc: BtXadc,
    bucket: u64,
    count: u64,  // count of bits of randomness generated since created
}

impl ShittyRng {
    pub fn new() -> Self {
        unsafe { ShittyRng { p: betrusted_pac::Peripherals::steal(), xadc: BtXadc::new(), bucket: 0, count: 0 }}
    }
}

impl ShittyRng {
    pub fn get_bits_generated(&mut self) -> u64 {
        self.count
    }
}

// allow this to be use for testing the crypto functions...
impl rand_core::CryptoRng for ShittyRng {}

impl RngCore for ShittyRng {
    fn next_u32(&mut self) -> u32 {
        self.next_u64() as u32
    }

    fn next_u64(&mut self) -> u64 {
        while self.p.TRNG_KERNEL.status.read().avail().bit_is_clear() {}
        self.bucket ^= self.p.TRNG_KERNEL.data.read().bits() as u64;

        while self.p.TRNG_KERNEL.status.read().avail().bit_is_clear() {}
        self.bucket ^= (self.p.TRNG_KERNEL.data.read().bits() as u64) << 32;

        self.count += 64;

        self.bucket
    }

    fn fill_bytes(&mut self, dest: &mut [u8]) {
        impls::fill_bytes_via_next(self, dest)
    }

    fn try_fill_bytes(&mut self, dest: &mut [u8]) -> Result<(), Error> {
        Ok(self.fill_bytes(dest))
    }
}