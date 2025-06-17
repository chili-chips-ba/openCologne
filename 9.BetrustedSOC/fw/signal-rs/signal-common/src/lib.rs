//! Shared utilities for Signal crates.
//!
//! The modules contained here provide basic types that are shared among
//! other crates in the Signal project.

#![no_std]

extern crate alloc;

extern crate curve25519_dalek;
extern crate ed25519_dalek;
extern crate rand;
extern crate rand_core;
extern crate sha2;
extern crate x25519_dalek;
extern crate no_std_compat;

pub mod convert;
pub mod error;
pub mod keys;
