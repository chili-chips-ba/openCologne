//! An implementation of the Double Ratchet protocol.
//!
//! See the [`Session`] documentation for details.
//!
//! [`Session`]: session/struct.Session.html

#![no_std]

#[cfg(not(test))]
#[macro_use]
extern crate alloc;

extern crate aes;
extern crate block_modes;
extern crate curve25519_dalek;
extern crate ed25519_dalek;
extern crate hkdf;
extern crate hmac;
extern crate orion;
extern crate hashbrown;
extern crate rand;
extern crate rand_core;
extern crate betrusted_hal;
//extern crate sha2;
extern crate x25519_dalek;

extern crate signal_common;

pub mod chains;
pub mod encrypt;
pub mod ratchet;
pub mod session;
pub mod util;

pub use session::*;

#[cfg(test)]
mod tests;
