//! An implementation of the X3DH key agreement algorithm.
//!
//! See the documentation for [`Keyserver`] and [`Participant`]
//! for more details.
//!
//! [`Keyserver`]: keyserver/struct.Keyserver.html
//! [`Participant`]: participant/struct.Participant.html
//!
//! # Examples
//!
//! ```
//! extern crate rand;
//! 
//! extern crate signal_common;
//! extern crate x3dh;
//! 
//! use rand::OsRng;
//! 
//! use signal_common::keys::{ChainKey, RatchetKeyPair};
//! use x3dh::keyserver::Keyserver;
//! use x3dh::participant::Participant;
//! 
//! fn main() {
//!     let mut csprng = OsRng::new().unwrap();
//! 
//!     // First, the key agreement with X3DH.
//! 
//!     let mut server = Keyserver::new();
//! 
//!     let mut alice = Participant::new(&mut csprng);
//!     alice.register(&mut server).unwrap();
//! 
//!     let mut bob = Participant::new(&mut csprng);
//!     bob.register(&mut server).unwrap();
//!     bob.add_opk(&mut server, &mut csprng).unwrap();
//! 
//!     alice.add_peer(&bob.ik());
//! 
//!     let (sk_a, opk_id, ek) = alice.begin_exchange(
//!         &bob.ik(), &mut server, &mut csprng,
//!     ).unwrap();
//! 
//!     let sk_b = bob.complete_exchange(&alice.ik(), opk_id, ek).unwrap();
//! 
//!     assert_eq!(sk_a, sk_b);
//! }
//! ```

#![no_std]

extern crate curve25519_dalek;
extern crate ed25519_dalek;
extern crate orion;
extern crate rand;
extern crate rand_core;
extern crate sha2;
extern crate x25519_dalek;

extern crate signal_common;

pub mod keyserver;
pub mod participant;
pub mod peer;

#[cfg(test)]
pub mod one;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        one::example();
    }
}
