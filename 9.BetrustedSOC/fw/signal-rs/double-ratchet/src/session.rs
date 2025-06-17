#[cfg(not(test))]
use alloc::vec::*;
#[cfg(test)]
use std::vec::*;

use hashbrown::HashMap;

#[cfg(not(test))]
use core::ops::Deref;
#[cfg(test)]
use std::ops::Deref;

use rand::{CryptoRng, Rng};

use signal_common::error::Result;
use signal_common::keys::{
    ChainKey,
    RatchetKeyPair,
    MessageKey,
    RatchetKeyPublic,
};

use crate::encrypt::AeadCipher;
use crate::ratchet::DoubleRatchet;

const MAX_SKIP: u32 = 777;

/// A factory for [`Session`]s.
///
/// Make one with [`new`], then build a session.
/// For the initial sender:
///
/// ```ignore
/// let mut alice = SessionBuilder::new(&b"info"[..], root_key)
///     .connect_to(&bob_public_key, &mut csprng);
/// ```
///
/// And for the initial receiver:
///
/// ```ignore
/// let mut bob = SessionBuilder::new(&b"info"[..], root_key)
///     .accept_with(bob_keypair);
/// ```
///
/// [`Session`]: struct.Session.html
/// [`new`]: #method.new
pub struct SessionBuilder<Bytes> {
    info: Bytes,
    root_key: ChainKey,
}

impl<Bytes: Deref<Target=[u8]>> SessionBuilder<Bytes> {
    pub fn new(info: Bytes, root_key: ChainKey) -> SessionBuilder<Bytes> {
        SessionBuilder { info, root_key }
    }

    pub fn connect_to<R: CryptoRng + Rng>(
        self,
        peer: &RatchetKeyPublic,
        csprng: &mut R,
    ) -> Session {
        Session::new(
            DoubleRatchet::with_peer(
                self.info, self.root_key, csprng, peer,
            ),
            Some(peer.clone()),
        )
    }

    pub fn accept_with(self, keypair: RatchetKeyPair) -> Session {
        Session::new(
            DoubleRatchet::with_keypair(
                self.info, self.root_key, keypair,
            ),
            None,
        )
    }
}

/// A message header.
#[derive(Clone)]
pub struct Header {
    /// The public ratchet key currently in use.
    pub public_key: RatchetKeyPublic,
    /// The number of messages in the previous sending chain.
    pub prev_count: u32,
    /// The number of messages in the current sending chain.
    pub count: u32,
}

/// The state of one end of a double ratchet session.
///
/// Build one with a [`SessionBuilder`], and then [`send`] and
/// [`receive`] to encrypt and decrypt.
///
/// [`SessionBuilder`]: struct.SessionBuilder.html
/// [`send`]: #method.send
/// [`receive`]: #method.receive
pub struct Session {
    ratchet: DoubleRatchet,
    last_peer_key: Option<RatchetKeyPublic>,
    ns: u32,
    nr: u32,
    p_ns: u32,
    mk_skipped: HashMap<(RatchetKeyPublic, u32), MessageKey>,
}

impl Session {
    fn new(ratchet: DoubleRatchet, last_peer_key: Option<RatchetKeyPublic>) -> Session {
        Session {
            ratchet,
            last_peer_key,
            ns: 0,
            nr: 0,
            p_ns: 0,
            mk_skipped: HashMap::new(),
        }
    }

    /// Get the receiving chain message key for the message.
    pub fn receive_key<R: CryptoRng + Rng>(
        &mut self,
        header: Header,
        csprng: &mut R,
    ) -> MessageKey {
        let public_clone = header.public_key.clone();

        match self.mk_skipped.remove(&(public_clone, header.count)) {
            Some(mk) => return mk,
            _ => {},
        }

        match self.last_peer_key {
            Some(ref key) if key == &header.public_key => {
                // Still on the same DH ratchet step..
            },
            _ => {
                self.p_ns = self.ns;
                self.skip_message_keys(header.prev_count);
                self.ratchet.ratchet(csprng, &header.public_key);
                self.last_peer_key = Some(header.public_key.clone());
            }
        }

        self.skip_message_keys(header.count);

        let mk = self.ratchet.next_receiving_key().1;
        self.nr += 1;
        mk
    }

    /// Decrypt a message in the session.
    pub fn receive<R: CryptoRng + Rng>(
        &mut self,
        header: Header,
        ciphertext: &[u8],
        csprng: &mut R,
    ) -> Result<Vec<u8>> {
        let key = self.receive_key(header.clone(), csprng);
        let ad = generate_ad(&b"ad"[..], &header);
        let cipher = AeadCipher::new(&b"another info"[..], key, &ad);
        cipher.decrypt(ciphertext)
    }

    /// Encrypt a message in the session.
    pub fn send(
        &mut self,
        plaintext: &[u8],
    ) -> (Header, Vec<u8>) {
        let (header, key) = self.send_key();
        let ad = generate_ad(&b"ad"[..], &header);
        let cipher = AeadCipher::new(&b"another info"[..], key, &ad);
        let msg = cipher.encrypt(plaintext);
        (header, msg)
    }

    fn skip_message_keys(&mut self, count: u32) {
        let skip = count - self.nr;
        if skip > MAX_SKIP {
            // TODO: don't panic!
            panic!("Cannot skip more than {}, tried: {:?}!", MAX_SKIP, skip);
        }

        while self.nr < count {
            self.skip_message_key()
        }
    }

    fn skip_message_key(&mut self) {
        let mk = self.ratchet.next_receiving_key().1;
        let n = self.nr;
        self.nr += 1;
        // TODO: is this unwrap sound?
        self.mk_skipped.insert((self.last_peer_key.clone().unwrap(), n), mk);
    }

    ///  Get the next header and sending chain message key.
    pub fn send_key(&mut self) -> (Header, MessageKey) {
        let mk = self.ratchet.next_sending_key().1;
        let count = self.ns;
        self.ns += 1;
        let h = Header {
            public_key: self.ratchet.public().clone(),
            prev_count: self.p_ns,
            count,
        };
        (h, mk)
    }
}

pub(crate) fn generate_ad(bytes: &[u8], header: &Header) -> Vec<u8> {
    let mut res = vec![];
    res.extend_from_slice(bytes);
    res.extend_from_slice(header.public_key.as_bytes());
    res.extend_from_slice(&slice_word(header.prev_count)[..]);
    res.extend_from_slice(&slice_word(header.count)[..]);
    res
}

fn slice_word(word: u32) -> [u8; 4] {
    [
        ((word >> 24) & 0xFF) as u8,
        ((word >> 16) & 0xFF) as u8,
        ((word >>  8) & 0xFF) as u8,
        ((word >>  0) & 0xFF) as u8,
    ]
}
