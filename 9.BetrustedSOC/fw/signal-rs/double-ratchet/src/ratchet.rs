#[cfg(not(test))]
use core::ops::Deref;
#[cfg(test)]
use std::ops::Deref;

use rand::{Rng};
use rand_core::CryptoRng;

use signal_common::keys::{
    ChainKey,
    RatchetKeyPair,
    MessageKey,
    RatchetKeyPublic,
    RatchetKeySecret,
    SessionKey,
};

use crate::chains::Chains;

/// The state of one end of a double ratchet session.
///
/// Maintains the several KDF chains used in the double ratchet algorithm,
/// advancing each as necessary with the appropriate keys.
///
/// There is an asymmetry to the protocol startup.  The participant who
/// initiates the session needs to have the public key for the other
/// participant.  The session can then be created with:
///
/// ```ignore
/// # extern crate curve25519_dalek;
/// # extern crate double_ratchet;
/// # extern crate rand;
/// # use curve25519_dalek::edwards::CompressedEdwardsY;
/// # use double_ratchet::keys::{ChainKey, RatchetKeyPublic};
/// # use double_ratchet::ratchet::DoubleRatchet;
/// # use rand::OsRng;
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let bob_public_key = RatchetKeyPublic::from(&CompressedEdwardsY::from_slice(&[0; 32][..]).decompress().unwrap().to_montgomery());
/// # let mut csprng = OsRng::new().unwrap();
/// #
/// let mut alice = DoubleRatchet::<OsRng, _>::with_peer(&[1, 2, 3][..], root_key, &mut csprng, &bob_public_key);
/// ```
///
/// The participant receiving the first message must have the secret key
/// corresponding to the public key that the other participant has.  The
/// second session can be created with:
///
/// ```ignore
/// # extern crate double_ratchet;
/// # extern crate rand;
/// # use double_ratchet::keys::{ChainKey, RatchetKeyPair};
/// # use double_ratchet::ratchet::DoubleRatchet;
/// # use rand::OsRng;
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let bob_keypair = RatchetKeyPair::generate(&mut OsRng::new().unwrap());
/// # let mut csprng = OsRng::new().unwrap();
/// #
/// let mut bob = DoubleRatchet::<OsRng, _>::with_keypair(&[1, 2, 3][..], root_key, &mut csprng, bob_keypair);
/// ```
///
/// After that the participants operate the same.  Upon receipt of a
/// message with a new public key, perform a Diffie-Hellman ratchet.
/// Then get the message key to decrypt with:
///
/// ```ignore
/// # extern crate curve25519_dalek;
/// # extern crate double_ratchet;
/// # extern crate rand;
/// # use curve25519_dalek::edwards::CompressedEdwardsY;
/// # use double_ratchet::keys::{ChainKey, RatchetKeyPair, RatchetKeyPublic};
/// # use double_ratchet::ratchet::DoubleRatchet;
/// # use rand::OsRng;
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let mut csprng = OsRng::new().unwrap();
/// # let bob_keypair = RatchetKeyPair::generate(&mut csprng);
/// # let mut csprng = OsRng::new().unwrap();
/// # let mut bob = DoubleRatchet::<OsRng, _>::with_keypair(&[1, 2, 3][..], root_key, &mut csprng, bob_keypair);
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let mut csprng = OsRng::new().unwrap();
/// # let mut alice = DoubleRatchet::<OsRng, _>::with_peer(&[1, 2, 3][..], root_key, &mut csprng, bob.public());
/// #
/// bob.ratchet(alice.public());
/// let message_key = bob.next_receiving_key();
///
/// alice.ratchet(bob.public());
/// let message_key = alice.next_receiving_key();
/// ```
///
/// Upon receipt of a message with the same public key as a prior one,
/// perform a symmetric ratchet by just asking for the next key:
///
/// ```ignore
/// # extern crate curve25519_dalek;
/// # extern crate double_ratchet;
/// # extern crate rand;
/// # use curve25519_dalek::edwards::CompressedEdwardsY;
/// # use double_ratchet::keys::{ChainKey, RatchetKeyPair, RatchetKeyPublic};
/// # use double_ratchet::ratchet::DoubleRatchet;
/// # use rand::OsRng;
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let mut csprng = OsRng::new().unwrap();
/// # let bob_keypair = RatchetKeyPair::generate(&mut csprng);
/// # let mut csprng = OsRng::new().unwrap();
/// # let mut bob = DoubleRatchet::<OsRng, _>::with_keypair(&[1, 2, 3][..], root_key, &mut csprng, bob_keypair);
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let mut csprng = OsRng::new().unwrap();
/// # let mut alice = DoubleRatchet::<OsRng, _>::with_peer(&[1, 2, 3][..], root_key, &mut csprng, bob.public());
/// # bob.ratchet(alice.public());
/// #
/// let message_key = alice.next_receiving_key();
/// let message_key = alice.next_receiving_key();
/// let message_key = alice.next_receiving_key();
/// ```
///
/// To send a message, perform a symmetric ratchet on the sending chain
/// by requesting the next sending key:
///
/// ```ignore
/// # extern crate curve25519_dalek;
/// # extern crate double_ratchet;
/// # extern crate rand;
/// # use curve25519_dalek::edwards::CompressedEdwardsY;
/// # use double_ratchet::keys::{ChainKey, RatchetKeyPair, RatchetKeyPublic};
/// # use double_ratchet::ratchet::DoubleRatchet;
/// # use rand::OsRng;
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let bob_keypair = RatchetKeyPair::generate(&mut OsRng::new().unwrap());
/// # let mut csprng = OsRng::new().unwrap();
/// # let mut bob = DoubleRatchet::<OsRng, _>::with_keypair(&[1, 2, 3][..], root_key, &mut csprng, bob_keypair);
/// # let root_key = ChainKey::from(&[0; 32][..]);
/// # let mut csprng = OsRng::new().unwrap();
/// # let mut alice = DoubleRatchet::<OsRng, _>::with_peer(&[1, 2, 3][..], root_key, &mut csprng, bob.public());
/// # bob.ratchet(alice.public());
/// #
/// let message_key = bob.next_sending_key();
/// ```
pub struct DoubleRatchet {
    chains: Chains,
    keypair: Option<RatchetKeyPair>,
}

impl DoubleRatchet {
    pub fn with_peer<Bytes: Deref<Target=[u8]>, R: CryptoRng + Rng>(
        info: Bytes,
        root_key: ChainKey,
        csprng: &mut R,
        peer: &RatchetKeyPublic,
    ) -> DoubleRatchet {
        let mut session = DoubleRatchet {
            chains: Chains::init(info, root_key),
            keypair: None,
        };
        session.half_ratchet(csprng, peer);
        session
    }

    pub fn with_keypair<Bytes: Deref<Target=[u8]>>(
        info: Bytes,
        root_key: ChainKey,
        keypair: RatchetKeyPair,
    ) -> DoubleRatchet {
        DoubleRatchet {
            chains: Chains::init(info, root_key),
            keypair: Some(keypair),
        }
    }

    fn generate_keypair<R: CryptoRng + Rng>(&mut self, csprng: &mut R) {
        self.keypair = Some(RatchetKeyPair::generate(csprng));
    }

    fn secret(&self) -> &RatchetKeySecret {
        match self.keypair {
            None => panic!("DoubleRatchet has no secret key initialized!"),
            Some(ref keypair) => &(*keypair).secret,
        }
    }

    pub fn public(&self) -> &RatchetKeyPublic {
        match self.keypair {
            None => panic!("DoubleRatchet has no secret key initialized!"),
            Some(ref keypair) => &(*keypair).public,
        }
    }

    fn half_ratchet<R: CryptoRng + Rng>(&mut self, csprng: &mut R, peer: &RatchetKeyPublic) {
        if self.keypair.is_some() {
            panic!("DoubleRatchet can only perform half-ratchet on init!");
        }

        self.generate_keypair(csprng);

        let sk = dh(peer, self.secret());
        self.chains.next_sending_chain(sk);
    }

    pub fn ratchet<R: CryptoRng + Rng>(&mut self, csprng: &mut R, peer: &RatchetKeyPublic) {
        if self.keypair.is_none() {
            panic!("DoubleRatchet can only perform full ratchet after init!");
        }

        let sk = dh(peer, self.secret());
        self.chains.next_receiving_chain(sk);

        self.generate_keypair(csprng);

        let sk = dh(peer, self.secret());
        self.chains.next_sending_chain(sk);
    }

    pub fn next_sending_key(&mut self) -> (u32, MessageKey) {
        self.chains.next_sending_key()
    }

    pub fn next_receiving_key(&mut self) -> (u32, MessageKey) {
        self.chains.next_receiving_key()
    }
}

pub fn dh(peer: &RatchetKeyPublic, me: &RatchetKeySecret) -> SessionKey {
    let peer = x25519_dalek::PublicKey::from(*peer.as_bytes());
    let shared = x25519_dalek::StaticSecret::from(*me.as_bytes()).diffie_hellman(&peer);

    SessionKey::from(&shared.as_bytes()[..])
}
