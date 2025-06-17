//! A key server providing escrow features for X3DH.
//!
//! To enable a user to initiate a key exchange with another
//! user, even one who is offline, X3DH makes use of a key escrow
//! server to transmit public keys between peers.
#![no_std]

use alloc::collections::HashMap;

use signal_common::error::{Error, Result};
use signal_common::keys::{
    IdentityKeyPublic,
    SignedPrekeyPublic,
    OneTimePrekeyPublic,
    PrekeyBundle,
    Signature,
};

/// An entry for a single participant in the key server.
pub struct KeyEntry {
    spk: SignedPrekeyPublic,
    spk_sig: Signature,
    opks: Vec<OneTimePrekeyPublic>,
}

/// A server storing public keys and prekey material of participants.
pub struct Keyserver {
    entries: HashMap<IdentityKeyPublic, KeyEntry>,
}

impl Keyserver {
    /// Initialize a new key server.
    pub fn new() -> Keyserver {
        Keyserver { entries: HashMap::new() }
    }

    /// Get the prekey bundle for a participant based on their public key.
    pub fn prekey_bundle(&mut self, ik: &IdentityKeyPublic) -> Option<PrekeyBundle> {
        self.entries.get_mut(ik).map(|entry| {
            let opk = if entry.opks.len() > 0 {
                let mine = entry.opks.pop().unwrap();
                Some(mine)
            } else {
                None
            };
            PrekeyBundle {
                ik: ik.clone(),
                spk: entry.spk.clone(),
                spk_sig: entry.spk_sig.clone(),
                opk,
            }
        })
    }

    /// Add the identity of a new participant to the server, along with
    /// their initial signed prekey.
    pub fn update_identity(
        &mut self,
        ik: &IdentityKeyPublic,
        spk: &SignedPrekeyPublic,
        spk_sig: &Signature,
    ) -> Result<()> {
        ik.verify(spk.as_bytes(), spk_sig)?;

        self.entries.insert(ik.clone(), KeyEntry {
            spk: spk.clone(),
            spk_sig: spk_sig.clone(),
            opks: vec![],
        });

        Ok(())
    }

/*
    /// Update a participant's signed prekey in the keyserver.
    pub fn update_spk(
        &mut self,
        ik: &PublicKey,
        spk: &PublicKey,
        spk_sig: &Signature,
    ) -> Result<(), CryptoError> {
        ik.verify(spk.as_bytes(), spk_sig)?;

        match self.entries.get_mut(ik) {
            None => Err(CryptoError),
            Some(entry) => {
                entry.spk = spk.clone();
                entry.spk_sig = spk_sig.clone();
                Ok(())
            },
        }
    }
*/

    /// Add a one-time prekey to the server for a participant.
    pub fn add_opk(
        &mut self,
        ik: &IdentityKeyPublic,
        opk: &OneTimePrekeyPublic,
        opk_sig: &Signature,
    ) -> Result<()> {
        ik.verify(opk.as_bytes(), opk_sig)?;

        match self.entries.get_mut(ik) {
            None => Err(Error),
            Some(entry) => {
                entry.opks.push(opk.clone());
                Ok(())
            },
        }
    }
}

#[cfg(test)]
mod tests {
    use rand_core::OsRng;

    use signal_common::keys::{
        IdentityKeyPair,
        SignedPrekeyPair,
        OneTimePrekeyPair,
        Signature,
    };

    use super::*;

    #[test]
    fn test_keyserver() {
        let mut csprng = OsRng;

        let mut server = Keyserver::new();

        let (ik_b, spk_b, spk_b_sig, opk_b, opk_b_sig) = {
            let ik_b = IdentityKeyPair::generate(&mut csprng);
            let spk_b = SignedPrekeyPair::generate(&mut csprng);
            let opk_b = OneTimePrekeyPair::generate(&mut csprng, 0);

            let ik_b_public = ik_b.public();
            let spk_b_public = spk_b.public();
            let opk_b_public = opk_b.public();

            let spk_b_sig = ik_b.sign(spk_b_public.as_bytes());
            let opk_b_sig = ik_b.sign(opk_b_public.as_bytes());

            (ik_b_public, spk_b_public, spk_b_sig, opk_b_public, opk_b_sig)
        };

        server.update_identity(&ik_b, &spk_b, &spk_b_sig).unwrap();
        server.add_opk(&ik_b, &opk_b, &opk_b_sig).unwrap();

        let pkb = server.prekey_bundle(&ik_b).unwrap();
        let opk = pkb.opk.unwrap();

        assert_eq!(pkb.ik, ik_b);
        assert_eq!(pkb.spk, spk_b);
        assert_eq!(opk, opk_b);

        ik_b.verify(pkb.spk.as_bytes(), &spk_b_sig).unwrap();
        ik_b.verify(opk.as_bytes(), &opk_b_sig).unwrap();

        assert_eq!(opk.index(), 0);
    }

    #[test]
    fn test_rejects_bad_sigs() {
        let mut csprng = OsRng;

        let mut server = Keyserver::new();

        let (ik_b, spk_b, spk_b_sig, opk_b, opk_b_sig, spk2_b, spk2_b_sig) = {
            let ik_b = IdentityKeyPair::generate(&mut csprng);
            let spk_b = SignedPrekeyPair::generate(&mut csprng);
            let opk_b = OneTimePrekeyPair::generate(&mut csprng, 0);
            let spk2_b = SignedPrekeyPair::generate(&mut csprng);

            let ik_b_public = ik_b.public();
            let spk_b_public = spk_b.public();
            let opk_b_public = opk_b.public();
            let spk2_b_public = spk2_b.public();

            let spk_b_sig = ik_b.sign(spk_b_public.as_bytes());
            let opk_b_sig = ik_b.sign(opk_b_public.as_bytes());
            let spk2_b_sig = ik_b.sign(spk2_b_public.as_bytes());

            (
                ik_b_public,
                spk_b_public, spk_b_sig,
                opk_b_public, opk_b_sig,
                spk2_b_public, spk2_b_sig,
            )
        };

        let bad_sig = Signature::from_bytes([0; 64]).unwrap();
        assert!(server.update_identity(&ik_b, &spk_b, &bad_sig).is_err());

        server.update_identity(&ik_b, &spk_b, &spk_b_sig).unwrap();

        assert!(server.add_opk(&ik_b, &opk_b, &bad_sig).is_err());

        server.add_opk(&ik_b, &opk_b, &opk_b_sig).unwrap();

        assert!(server.update_identity(&ik_b, &spk2_b, &bad_sig).is_err());

        server.update_identity(&ik_b, &spk2_b, &spk2_b_sig).unwrap();
    }
}
