//! An X3DH participant.
//!
//! Manages the state for a single participant, including
//! identity key, signed prekey, one-time prekeys, and peers.
#![no_std]

use alloc::collections::HashMap;

use rand_core::{CryptoRng, RngCore};

use signal_common::error::{Error, Result};
use signal_common::keys::{
    EphemeralKeyPublic,
    IdentityKeyPair,
    IdentityKeyPublic,
    OneTimePrekeyPair,
    OneTimePrekeyPublic,
    PrekeyBundle,
    Signature,
    KeyMaterial,
    SignedPrekeyPair,
    SignedPrekeyPublic,
};

use crate::keyserver::Keyserver;
use crate::peer::{Peer};

/// The state for a participant in an X3DH system.
pub struct Participant {
    ik: IdentityKeyPair,
    spk: SignedPrekeyPair,
    next_opk: u64,
    opks: HashMap<u64, OneTimePrekeyPair>,
    peers: HashMap<IdentityKeyPublic, Peer>,
}

impl Participant {
    /// Initialize a new participant, using the given randomness
    /// to generate keys.
    pub fn new<R: CryptoRng + RngCore>(csprng: &mut R) -> Participant {
        let ik = IdentityKeyPair::generate(csprng);
        let spk = SignedPrekeyPair::generate(csprng);
        let next_opk = 1;
        let opks = HashMap::new();
        let peers = HashMap::new();

        Participant { ik, spk, next_opk, opks, peers }
    }

    // TODO: some way to serialize/deserialize a participant to storage

    /// The participant's public identity key.
    pub fn ik(&self) -> IdentityKeyPublic {
        self.ik.public()
    }

    /// The participant's signed prekey.
    pub fn spk(&self) -> SignedPrekeyPublic {
        self.spk.public()
    }

    /// The signature for the participant's signed prekey.
    pub fn spk_sig(&self) -> Signature {
        self.ik.sign(self.spk().as_bytes())
    }

    /// The participant's signed prekey secret key.  Be careful!
    pub fn spk_pair(&self) -> &SignedPrekeyPair {
        &self.spk
    }

    /// Create a new one-time prekey for this participant.
    pub fn create_opk<R: CryptoRng + RngCore>(&mut self, csprng: &mut R) -> (OneTimePrekeyPublic, Signature) {
        let id = self.next_opk;
        self.next_opk = id + 1;

        let opk = OneTimePrekeyPair::generate(csprng, id);
        let opk_public = opk.public();

        self.opks.insert(id, opk);

        let sig = self.ik.sign(opk_public.as_bytes()).into();
        (opk_public, sig)
    }

    /// Register this participant with the given key server.
    pub fn register(&self, keyserver: &mut Keyserver) -> Result<()> {
        let ik = self.ik.public();
        let spk = self.spk.public();
        let spk_sig = self.ik.sign(spk.as_bytes());

        keyserver.update_identity(&ik, &spk, &spk_sig)
    }

    /// Add a new one-time prekey to the given key server.
    pub fn add_opk<R: CryptoRng + RngCore>(
        &mut self,
        keyserver: &mut Keyserver,
        csprng: &mut R,
    ) -> Result<()> {
        let ik = self.ik.public();
        let opk = self.create_opk(csprng);

        keyserver.add_opk(&ik, &opk.0, &opk.1)
    }

    /// Add a peer, in preparation for future communication.
    pub fn add_peer(&mut self, peer: &IdentityKeyPublic) {
        self.peers.insert(peer.clone(), Peer::HaveIdentity(peer.clone()));
    }

    /// Begin a key agreement exchange with the peer using the keyserver.
    pub fn begin_exchange<R: CryptoRng + RngCore>(
        &mut self,
        peer: &IdentityKeyPublic,
        keyserver: &mut Keyserver,
        csprng: &mut R,
    ) -> Result<(KeyMaterial, u64, EphemeralKeyPublic)> {
        let bundle = match keyserver.prekey_bundle(peer) {
            Some(b) => b,
            None => return Err(Error),
        };

        self.accept_bundle(bundle, csprng)
    }

    /// Begin the key agreement exchange with the peer by accepting a prekey bundle.
    pub fn accept_bundle<R: CryptoRng + RngCore>(
        &mut self,
        bundle: PrekeyBundle,
        csprng: &mut R,
    ) -> Result<(KeyMaterial, u64, EphemeralKeyPublic)> {
        let peer_state = match self.peers.remove(&bundle.ik) {
            Some(s) => s,
            None => return Err(Error),
        };

        let peer = bundle.ik.clone();

        let peer_state = peer_state.accept_prekey_bundle(bundle)?;

        let (peer_state, sk, opk_id, ek) = peer_state.derive_key(csprng, &self.ik)?;

        self.peers.insert(peer, peer_state);

        Ok((sk, opk_id, ek))
    }

    /// Complete a key agreement exchange previously started by a peer.
    pub fn complete_exchange(
        &mut self,
        peer: &IdentityKeyPublic,
        opk_id: u64,
        ek: EphemeralKeyPublic,
    ) -> Result<KeyMaterial> {
        let opk = match self.opks.remove(&opk_id) {
            None => return Err(Error),
            Some(opk) => opk,
        };

        // TODO: this????
        self.add_peer(peer);

        let peer_state = match self.peers.remove(peer) {
            Some(s) => s,
            None => return Err(Error),
        };

        let (peer_state, sk) = peer_state.match_key(&self.ik, &self.spk, &opk, &ek)?;

        self.peers.insert(peer.clone(), peer_state);

        Ok(sk)
    }
}

#[cfg(test)]
mod tests {
    use rand_core::OsRng;

    use crate::keyserver::Keyserver;

    use super::*;

    #[test]
    fn test_exchange() {
        let mut csprng = OsRng;

        let mut server = Keyserver::new();

        let mut alice = Participant::new(&mut csprng);
        alice.register(&mut server).unwrap();

        let mut bob = Participant::new(&mut csprng);
        bob.register(&mut server).unwrap();
        bob.add_opk(&mut server, &mut csprng).unwrap();

        alice.add_peer(&bob.ik());

        let (sk1, opk_id, ek) = alice.begin_exchange(&bob.ik(), &mut server, &mut csprng)
            .unwrap();

        let sk2 = bob.complete_exchange(&alice.ik(), opk_id, ek).unwrap();

        assert_eq!(sk1, sk2);
    }
}
