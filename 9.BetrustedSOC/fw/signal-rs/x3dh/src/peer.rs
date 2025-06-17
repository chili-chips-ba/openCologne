//! The state machine of a peer connection in an X3DH exchange.
//!
//! The key echange forms a simple state machine, and
//! so we model it here likewise.  This module is fairly
//! low-level, see `Participant` for the use of this.
#![no_std]

use orion::hazardous::kdf::hkdf;
use rand::{CryptoRng, RngCore};

use signal_common::error::{Error, Result};
use signal_common::keys::{
    EphemeralKeyPair,
    EphemeralKeyPublic,
    IdentityKeyPair,
    IdentityKeyPublic,
    OneTimePrekeyPair,
    SignedPrekeyPair,
    KeyMaterial,
    PrekeyBundle,
};

/// The state of a single peer.
pub enum Peer {
    /// We have never heard of this peer.
    Unknown,
    /// We have this peer's identity key.
    HaveIdentity(IdentityKeyPublic),
    /// We have a prekey bundle for this peer.
    HavePrekeyBundle(PrekeyBundle),
    /// The key exchange has been completed.
    Connected,
}

impl Peer {
    /// Are we connected to the peer?
    pub fn is_connected(&self) -> bool {
        match self {
            Peer::Connected => true,
            _ => false,
        }
    }

    /// Are we ready to send an initial message to make a connection?
    /// First we need the prekey bundle for the peer.
    pub fn ready_to_send(&self) -> bool {
        match self {
            Peer::HavePrekeyBundle(_) => true,
            _ => false,
        }
    }

    /// We've obtained a prekey bundle for this peer, so move to
    /// the ready to send state.
    pub fn accept_prekey_bundle(self, bundle: PrekeyBundle) -> Result<Peer> {
        bundle.ik.verify(bundle.spk.as_bytes(), &bundle.spk_sig)?;

        Ok(Peer::HavePrekeyBundle(bundle))
    }

    /// Derive a key for this peer to use for an initial message.
    /// Requires that we're ready to send.
    pub fn derive_key<R: CryptoRng + RngCore>(
        self,
        csprng: &mut R,
        me: &IdentityKeyPair,
    ) -> Result<(Peer, KeyMaterial, u64, EphemeralKeyPublic)> {
        match self {
            Peer::HavePrekeyBundle(bundle) => {
                let ek = EphemeralKeyPair::generate(csprng);

                let ik = bundle.ik;
                let spk = bundle.spk;

                // TODO: not unwrap
                let opk = bundle.opk.unwrap();

                let dh1 = me.diffie_hellman(&spk)?;
                let dh2 = ek.diffie_hellman(&ik)?;
                let dh3 = ek.diffie_hellman(&spk)?;
                let dh4 = ek.diffie_hellman(&opk)?;

                let sk = kdf(dh1, dh2, dh3, dh4);

                Ok((Peer::Connected, sk, opk.index(), ek.public()))
            },
            _ => Err(Error),
        }
    }

    /// Complete the key exchange initiated by the peer.
    pub fn match_key(
        self,
        ik: &IdentityKeyPair,
        spk: &SignedPrekeyPair,
        opk: &OneTimePrekeyPair,
        ek: &EphemeralKeyPublic,
    ) -> Result<(Peer, KeyMaterial)> {
        let you = match self {
            Peer::HavePrekeyBundle(bundle) => {
                bundle.ik
            },
            Peer::HaveIdentity(pk) => {
                pk
            },
            _ => return Err(Error),
        };

        let dh1 = spk.diffie_hellman(&you)?;
        let dh2 = ik.diffie_hellman(ek)?;
        let dh3 = spk.diffie_hellman(ek)?;
        let dh4 = opk.diffie_hellman(ek)?;

        let sk = kdf(dh1, dh2, dh3, dh4);

        Ok((Peer::Connected, sk))
    }
}

fn kdf(
    dh1: KeyMaterial,
    dh2: KeyMaterial,
    dh3: KeyMaterial,
    dh4: KeyMaterial,
) -> KeyMaterial {
    let input: Vec<u8> = std::iter::repeat(0xFF).take(32)
        .chain(dh1.as_bytes().iter().cloned())
        .chain(dh2.as_bytes().iter().cloned())
        .chain(dh3.as_bytes().iter().cloned())
        .chain(dh4.as_bytes().iter().cloned())
        .collect();

    let mut res = [0u8; 32];

    orion::hazardous::kdf::hkdf::derive_key(&[0; 32], &input, Some(b"this is my info string"), &mut res).unwrap();
    res.into()
}

#[cfg(test)]
mod tests {
    use rand_core::OsRng;

    use signal_common::keys::PrekeyBundle;

    use super::*;

    #[test]
    fn test_key_exchange() {
        let mut csprng = OsRng;

        let (bundle, secrets) = {
            let ik_b = IdentityKeyPair::generate(&mut csprng);
            let spk_b = SignedPrekeyPair::generate(&mut csprng);
            let opk_b = OneTimePrekeyPair::generate(&mut csprng, 0);

            let ik_b_public = ik_b.public();
            let spk_b_public = spk_b.public();
            let opk_b_public = opk_b.public();

            let spk_b_sig = ik_b.sign(spk_b_public.as_bytes());

            (
                PrekeyBundle {
                    ik: ik_b_public,
                    spk: spk_b_public,
                    spk_sig: spk_b_sig,
                    opk: Some(opk_b_public),
                },
                (ik_b, spk_b, opk_b),
            )
        };

        let ik_a = IdentityKeyPair::generate(&mut csprng);

        let peer_b = Peer::HavePrekeyBundle(bundle);

        let (new_peer, sk1, _id, ek) = peer_b.derive_key(&mut csprng, &ik_a).unwrap();

        assert!(new_peer.is_connected());

        let peer_a = Peer::HaveIdentity(ik_a.public());

        let (ik_b, spk_b, opk_b) = secrets;

        let (new_peer, sk2) = peer_a.match_key(&ik_b, &spk_b, &opk_b, &ek).unwrap();

        assert!(new_peer.is_connected());

        assert_eq!(sk1, sk2);
    }
}
