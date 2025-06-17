//! Key types used by the signal protocol.
//!
//! We use a number of specific type wrappers to differentiate
//! between the many different keys we need to manage over the
//! course of the key exchange and double ratchet.  These
//! semantic keys ultimately wrap either a signing key or a
//! key exchange key, but it's easier to keep them all straight
//! this way.

use no_std_compat::hash::{Hash, Hasher};

use curve25519_dalek::montgomery::MontgomeryPoint;
use rand_core::{CryptoRng, RngCore};

use crate::error::{Error, Result};

use alloc::borrow::ToOwned;

/// A free signature of some bytes.
///
/// The only signing key in this scheme is the identity key of
/// X3DH.  The standard specifies a process of signing the
/// signed prekey, and the extensions here also sign the one-time
/// prekey to prove validity.  So this signature is from either
/// an SPK or an OPK, and was signed by an IK.
// TODO: elsewhere?
#[derive(Clone)]
pub struct Signature(ed25519_dalek::Signature);

impl Signature {
    /// Deserialize the provided bytes into a signature.
    pub fn from_bytes(bytes: [u8; 64]) -> Result<Signature> {
        Ok(Signature(ed25519_dalek::Signature::from_bytes(&bytes)?))
    }

    /// Serialize this signature into a byte array.
    pub fn to_bytes(&self) -> [u8; 64] {
        self.0.to_bytes()
    }

    /// Get a reference to the underlying dalek signature.
    pub fn as_dalek(&self) -> &ed25519_dalek::Signature {
        &self.0
    }
}

impl From<ed25519_dalek::Signature> for Signature {
    fn from(sig: ed25519_dalek::Signature) -> Signature {
        Signature(sig)
    }
}

/// The result of performing a Diffie-Hellman key exchange.
///
/// Some key material.  In X3DH we combine four (or sometimes
/// three) pieces of key material obtained from independent
/// Diffie-Hellman exchanges, and then use the result as the
/// root key for a Double Ratchet chain.
#[derive(Debug, PartialEq, Eq)]
pub struct KeyMaterial([u8; 32]);

impl KeyMaterial {
    pub fn as_bytes(&self) -> &[u8] {
        &self.0
    }
}

impl From<[u8; 32]> for KeyMaterial {
    fn from(bytes: [u8; 32]) -> KeyMaterial { KeyMaterial(bytes) }
}

/// A prekey bundle for a peer, fetched from the keyserver.
pub struct PrekeyBundle {
    pub ik: IdentityKeyPublic,
    pub spk: SignedPrekeyPublic,
    pub spk_sig: Signature,
    pub opk: Option<OneTimePrekeyPublic>,
}

/// A key that can participate in Diffie-Hellman.
pub trait PublicKey {
    fn key(&self) -> &Ed25519KeyPublic;
}

/// An identity pair for a user.
///
/// This is used in X3DH to sign other keys to prove authenticity,
/// as well as incorporated into Diffie-Hellman exchanges to
/// lock the derived session key to the parties.
pub struct IdentityKeyPair(Ed25519KeyPair);

/// The public half of a user's identity key pair.
///
/// In X3DH this is used to identify users publicly.  It is used to
/// request a specific peer's prekey bundle from the keyserver, and
/// to validate out-of-band that the conversation is with the right
/// peer.
#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub struct IdentityKeyPublic(Ed25519KeyPublic);

impl IdentityKeyPair {
    /// Generate a new identity key pair with the provided source of randomness.
    pub fn generate<R: CryptoRng + RngCore>(csprng: &mut R) -> IdentityKeyPair {
        IdentityKeyPair(Ed25519KeyPair::generate(csprng))
    }

    /// Get the public half of this identity key.
    pub fn public(&self) -> IdentityKeyPublic {
        IdentityKeyPublic(self.0.public.clone())
    }

    /// Sign a message using this identity key.
    pub fn sign(&self, msg: &[u8]) -> Signature {
        self.0.sign(msg)
    }

    /// Perform a Diffie-Hellman key exchange with the provided public key.
    pub fn diffie_hellman<K: PublicKey>(&self, pk: &K) -> Result<KeyMaterial> {
        self.0.diffie_hellman(pk.key())
    }
}

impl IdentityKeyPublic {
    /// Deserialize the provided bytes into an identity key.
    pub fn from_bytes(bytes: [u8; 32]) -> Result<IdentityKeyPublic> {
        Ok(IdentityKeyPublic(Ed25519KeyPublic::from_bytes(bytes)?))
    }

    /// Serialize this identity key into a byte array.
    pub fn to_bytes(&self) -> [u8; 32] {
        self.0.to_bytes()
    }

    /// Get a view of this identity key as bytes.
    pub fn as_bytes(&self) -> &[u8] {
        self.0.as_bytes()
    }

    /// Verify a message signed by this identity key.
    pub fn verify(&self, msg: &[u8], sig: &Signature) -> Result<()> {
        self.0.verify(msg, sig)
    }
}

impl PublicKey for IdentityKeyPublic {
    fn key(&self) -> &Ed25519KeyPublic { &self.0 }
}

/// The signed prekey pair for a user.
///
/// In X3DH this provides long-lived, non-identity keying material
/// for a user.  It is always accompanied by a signature proving
/// that the holder of the corresponding identity key was in fact
/// the issuer of this signed prekey.
pub struct SignedPrekeyPair(Ed25519KeyPair);

/// The public half of a signed prekey.
///
/// This half is shared via the keyserver and distributed as a part
/// of a user's prekey bundle.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SignedPrekeyPublic(Ed25519KeyPublic);

impl SignedPrekeyPair {
    /// Generate a new signed prekey pair with the provided source of randomness.
    pub fn generate<R: CryptoRng + RngCore>(csprng: &mut R) -> SignedPrekeyPair {
        SignedPrekeyPair(Ed25519KeyPair::generate(csprng))
    }

    /// Get the public half of this signed prekey.
    pub fn public(&self) -> SignedPrekeyPublic {
        SignedPrekeyPublic(self.0.public.clone())
    }

    /// Perform a Diffie-Hellman key exchange with the provided public key.
    pub fn diffie_hellman<K: PublicKey>(&self, pk: &K) -> Result<KeyMaterial> {
        self.0.diffie_hellman(pk.key())
    }
}

impl SignedPrekeyPublic {
    /// Deserialize the provided bytes into a signed prekey.
    pub fn from_bytes(bytes: [u8; 32]) -> Result<SignedPrekeyPublic> {
        Ok(SignedPrekeyPublic(Ed25519KeyPublic::from_bytes(bytes)?))
    }

    /// Serialize this signed prekey into a byte array.
    pub fn to_bytes(&self) -> [u8; 32] {
        self.0.to_bytes()
    }

    /// Get a view of this signed prekey as bytes.
    pub fn as_bytes(&self) -> &[u8] {
        self.0.as_bytes()
    }
}

impl PublicKey for SignedPrekeyPublic {
    fn key(&self) -> &Ed25519KeyPublic { &self.0 }
}

/// A one-time prekey pair.
///
/// One-time prekeys provide forward secrecy from the very first
/// message sent.  By preregistering these one-time keys, a user is
/// able to participate in an asynchronous Diffie-Hellman exchange
/// that uses one-time keying material on both sides, ensuring
/// forward secrecy.
pub struct OneTimePrekeyPair(u64, Ed25519KeyPair);

/// The public half of a one-time prekey.
///
/// This half is shared via the keyserver and distributed as a part
/// of a user's prekey bundle.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct OneTimePrekeyPublic(u64, Ed25519KeyPublic);

impl OneTimePrekeyPair {
    /// Generate a new one-time prekey pair with the provided source of randomness.
    pub fn generate<R>(csprng: &mut R, index: u64) -> OneTimePrekeyPair
    where R: CryptoRng + RngCore {
        OneTimePrekeyPair(index, Ed25519KeyPair::generate(csprng))
    }

    /// Get the public half of this one-time prekey.
    pub fn public(&self) -> OneTimePrekeyPublic {
        OneTimePrekeyPublic(self.0, self.1.public.clone())
    }

    /// Perform a Diffie-Hellman key exchange with the provided public key.
    pub fn diffie_hellman<K: PublicKey>(&self, pk: &K) -> Result<KeyMaterial> {
        self.1.diffie_hellman(pk.key())
    }
}

impl OneTimePrekeyPublic {
    /// Deserialize the provided bytes into a one-time prekey.
    pub fn from_bytes(
        index: u64,
        bytes: [u8; 32],
    ) -> Result<OneTimePrekeyPublic> {
        Ok(OneTimePrekeyPublic(index, Ed25519KeyPublic::from_bytes(bytes)?))
    }

    /// Get the key index of this one-time prekey.
    pub fn index(&self) -> u64 {
        self.0
    }

    /// Serialize this one-time prekey into a byte array.
    pub fn to_bytes(&self) -> [u8; 32] {
        self.1.to_bytes()
    }

    /// Get a view of this one-time prekey as bytes.
    pub fn as_bytes(&self) -> &[u8] {
        self.1.as_bytes()
    }
}

impl PublicKey for OneTimePrekeyPublic {
    fn key(&self) -> &Ed25519KeyPublic { &self.1 }
}

/// An ephemeral key generated for the X3DH exchange.
///
/// This key is the initiating party's contribution of one-time
/// keying material.  It is used to perform Diffie-Hellman exchanges
/// with all three (two) of the receiving party's keys.
pub struct EphemeralKeyPair(Ed25519KeyPair);

/// The public half of the ephemeral key.
///
/// This half is transmitted as part of the initial message
/// after X3DH, to allow the receiving party to complete the exchange.
#[derive(Clone)]
pub struct EphemeralKeyPublic(Ed25519KeyPublic);

impl EphemeralKeyPair {
    /// Generate a new ephemeral key pair with the provided source of randomness.
    pub fn generate<R: CryptoRng + RngCore>(csprng: &mut R) -> EphemeralKeyPair {
        EphemeralKeyPair(Ed25519KeyPair::generate(csprng))
    }

    /// Get the public half of this ephemeral key.
    pub fn public(&self) -> EphemeralKeyPublic {
        EphemeralKeyPublic(self.0.public.clone())
    }

    /// Perform a Diffie-Hellman key exchange with the provided public key.
    pub fn diffie_hellman<K: PublicKey>(&self, pk: &K) -> Result<KeyMaterial> {
        self.0.diffie_hellman(pk.key())
    }
}

impl EphemeralKeyPublic {
    /// Deserialize the provided bytes into a ephemeral key.
    pub fn from_bytes(bytes: [u8; 32]) -> Result<EphemeralKeyPublic> {
        Ok(EphemeralKeyPublic(Ed25519KeyPublic::from_bytes(bytes)?))
    }

    /// Serialize this ephemeral key into a byte array.
    pub fn to_bytes(&self) -> [u8; 32] {
        self.0.to_bytes()
    }

    /// Get a view of this ephemeral key as bytes.
    pub fn as_bytes(&self) -> &[u8] {
        self.0.as_bytes()
    }
}

impl PublicKey for EphemeralKeyPublic {
    fn key(&self) -> &Ed25519KeyPublic { &self.0 }
}

/// An Ed25519 key pair.
///
/// This is for the internal use of the signal crates.  It is
/// recommended that you use the underlying dalek crates instead.
pub struct Ed25519KeyPair {
    pub public: Ed25519KeyPublic,
    secret: ed25519_dalek::SecretKey,
}

/// The public half of an Ed25519 key pair.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Ed25519KeyPublic(ed25519_dalek::PublicKey);


impl Ed25519KeyPair {
    /// Generate a new Ed25519 key pair with the provided source of randomness.
    pub fn generate<R: CryptoRng + RngCore>(csprng: &mut R) -> Ed25519KeyPair {
        use ed25519_dalek::Keypair;
        let Keypair { public, secret } = Keypair::generate(csprng);
        Ed25519KeyPair {
            public: Ed25519KeyPublic(public),
            secret,
        }
    }

    // TODO: some way to serialize/deserialize secret key for storage

    /// Sign a message using this key.
    pub fn sign(&self, msg: &[u8]) -> Signature {
        ed25519_dalek::ExpandedSecretKey::from(&self.secret)
            .sign(msg, &self.public.0).into()
    }

    /// Perform a Diffie-Hellman key exchange with the provided public key.
    pub fn diffie_hellman(&self, peer: &Ed25519KeyPublic) -> Result<KeyMaterial> {
        use crate::convert::{convert_public_key, convert_secret_key};
        let secret = convert_secret_key(&self.secret)?;
        let public = convert_public_key(&peer.to_bytes())?;
        let public = x25519_dalek::PublicKey::from(public.as_bytes().to_owned());
        let shared = x25519_dalek::StaticSecret::from(secret.0)
            .diffie_hellman(&public);
        Ok(KeyMaterial::from(shared.as_bytes().to_owned()))
    }
}

impl Ed25519KeyPublic {
    /// Deserialize the provided bytes into an Ed25519 public key.
    pub fn from_bytes(bytes: [u8; 32]) -> Result<Ed25519KeyPublic> {
        Ok(Ed25519KeyPublic(ed25519_dalek::PublicKey::from_bytes(&bytes)?))
    }

    /// Serialize this key into a byte array.
    pub fn to_bytes(&self) -> [u8; 32] {
        self.0.to_bytes()
    }

    /// Get a view of this key as bytes.
    pub fn as_bytes(&self) -> &[u8] {
        self.0.as_bytes()
    }

    /// Verify a message signed by this key.
    pub fn verify(&self, msg: &[u8], sig: &Signature) -> Result<()> {
        Ok(self.0.verify(msg, sig.as_dalek())?)
    }
}

impl no_std_compat::hash::Hash for Ed25519KeyPublic {
    fn hash<H: no_std_compat::hash::Hasher>(&self, hasher: &mut H) {
        hasher.write(self.0.as_bytes())
    }
}

#[cfg(test)]
mod x3dh_tests {
    use rand_core::OsRng;

    use super::*;

    #[test]
    fn test_signature() {
        let mut csprng = OsRng;
        let keypair = IdentityKeyPair::generate(&mut csprng);
        let public_key = keypair.public();
        let message = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

        let signature = keypair.sign(&message);

        assert!(public_key.verify(&message, &signature).is_ok());
    }

    #[test]
    fn test_diffie_hellman() {
        let mut csprng = OsRng;
        let alice = IdentityKeyPair::generate(&mut csprng);
        let bob = EphemeralKeyPair::generate(&mut csprng);

        let session_key_alice = alice.diffie_hellman(&bob.public()).unwrap();
        let session_key_bob = bob.diffie_hellman(&alice.public()).unwrap();

        assert_eq!(session_key_alice, session_key_bob);
    }

    #[test]
    fn test_x3dh() {
        let mut csprng = OsRng;

        let alice = IdentityKeyPair::generate(&mut csprng);

        let bob = IdentityKeyPair::generate(&mut csprng);
        let bob_spk = SignedPrekeyPair::generate(&mut csprng);
        let bob_opk = OneTimePrekeyPair::generate(&mut csprng, 42);

        let ek = EphemeralKeyPair::generate(&mut csprng);

        let dh1_a = alice.diffie_hellman(&bob_spk.public()).unwrap();
        let dh2_a = ek.diffie_hellman(&bob.public()).unwrap();
        let dh3_a = ek.diffie_hellman(&bob_spk.public()).unwrap();
        let dh4_a = ek.diffie_hellman(&bob_opk.public()).unwrap();

        let dh1_b = bob_spk.diffie_hellman(&alice.public()).unwrap();
        let dh2_b = bob.diffie_hellman(&ek.public()).unwrap();
        let dh3_b = bob_spk.diffie_hellman(&ek.public()).unwrap();
        let dh4_b = bob_opk.diffie_hellman(&ek.public()).unwrap();

        assert_eq!(dh1_a, dh1_b);
        assert_eq!(dh2_a, dh2_b);
        assert_eq!(dh3_a, dh3_b);
        assert_eq!(dh4_a, dh4_b);
    }
}

/// A key in a double ratchet chain.
///
/// Each of the three chains in the double ratchet is a sequence
/// of chain keys derived from the previous chain key and the next
/// ratchet key.
#[derive(Debug, PartialEq, Eq)]
pub struct ChainKey(pub(crate) [u8; 32]);

impl core::ops::Deref for ChainKey {
    type Target = [u8];

    fn deref(&self) -> &[u8] {
        &self.0
    }
}

impl<'a> From<&'a [u8]> for ChainKey {
    fn from(slice: &[u8]) -> ChainKey {
        let len = if slice.len() < 32 { slice.len() } else { 32 };

        let mut arr = [0; 32];
        for i in 0..len {
            arr[i] = slice[i];
        }

        ChainKey(arr)
    }
}

impl From<KeyMaterial> for ChainKey {
    fn from(bytes: KeyMaterial) -> ChainKey {
        ChainKey(bytes.0)
    }
}

/// The output of the first ratchet is a session key.
///
/// The synchronous Diffie-Hellman ratchet produces a session
/// key, which is used as the next root key for the sending
/// and receiving chains.
#[derive(Debug, PartialEq, Eq)]
pub struct SessionKey(pub(crate) [u8; 32]);

impl core::ops::Deref for SessionKey {
    type Target = [u8];

    fn deref(&self) -> &[u8] {
        &self.0
    }
}

impl<'a> From<&'a [u8]> for SessionKey {
    fn from(slice: &[u8]) -> SessionKey {
        let len = if slice.len() < 32 { slice.len() } else { 32 };

        let mut arr = [0; 32];
        for i in 0..len {
            arr[i] = slice[i];
        }

        SessionKey(arr)
    }
}

/// The output of the second ratchet is a message key.
///
/// The asynchronous ratchet produces message keys, which are
/// each used to encrypt or decrypt one message.
#[derive(Debug, PartialEq, Eq)]
pub struct MessageKey(pub(crate) [u8; 32]);

impl core::ops::Deref for MessageKey {
    type Target = [u8];

    fn deref(&self) -> &[u8] {
        &self.0
    }
}

impl<'a> From<&'a [u8]> for MessageKey {
    fn from(slice: &[u8]) -> MessageKey {
        let len = if slice.len() < 32 { slice.len() } else { 32 };

        let mut arr = [0; 32];
        for i in 0..len {
            arr[i] = slice[i];
        }

        MessageKey(arr)
    }
}

/// A secret key half of a Diffie-Hellman ratchet key pair.
///
/// This is generated, used to ratchet the sending chain, and then
/// thrown away.
#[derive(Debug, PartialEq, Eq)]
pub struct RatchetKeySecret(pub(crate) [u8; 32]);

impl RatchetKeySecret {
    pub fn as_bytes(&self) -> &[u8; 32] {
        &self.0
    }
}

impl core::ops::Deref for RatchetKeySecret {
    type Target = [u8];

    fn deref(&self) -> &[u8] {
        &self.0
    }
}

impl<'a> From<&'a [u8]> for RatchetKeySecret {
    fn from(slice: &[u8]) -> RatchetKeySecret {
        let len = if slice.len() < 32 { slice.len() } else { 32 };

        let mut arr = [0; 32];
        for i in 0..len {
            arr[i] = slice[i];
        }

        RatchetKeySecret(arr)
    }
}

/// The public half of the Diffie-Hellman ratchet key pair.
///
/// This half is sent along with each message to inform the peer
/// that a Diffie-Hellman ratchet is necessary, and to provide the
/// keying material for that ratchet.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct RatchetKeyPublic(pub(crate) MontgomeryPoint);

impl RatchetKeyPublic {
    /// Deserialize the provided bytes into a ratchet public key.
    pub fn from_bytes(bytes: [u8; 32]) -> Result<RatchetKeyPublic> {
        use curve25519_dalek::edwards::CompressedEdwardsY;
        Ok(RatchetKeyPublic(
            CompressedEdwardsY::from_slice(&bytes[..])
                .decompress()
                .ok_or(Error)?
                .to_montgomery()
        ))
    }

    /// Serialize this ratchet public key into a byte array.
    pub fn to_bytes(&self) -> [u8; 32] {
        let ed = match self.0.to_edwards(0) {
            Some(e) => e,
            None => {
                match self.0.to_edwards(1) {
                    Some(e) => e,
                    None => panic!("i hope we can't actually panic here!"),
                }
            },
        };

        ed.compress().to_bytes()
    }
}

impl core::ops::Deref for RatchetKeyPublic {
    type Target = MontgomeryPoint;

    fn deref(&self) -> &MontgomeryPoint {
        &self.0
    }
}

impl Hash for RatchetKeyPublic {
    fn hash<H: Hasher>(&self, hasher: &mut H) {
        self.0.as_bytes().hash(hasher);
    }
}

impl<'a> From<&'a MontgomeryPoint> for RatchetKeyPublic {
    fn from(point: &MontgomeryPoint) -> RatchetKeyPublic {
        RatchetKeyPublic(point.clone())
    }
}

impl<'a> From<&'a SignedPrekeyPublic> for RatchetKeyPublic {
    fn from(spk: &'a SignedPrekeyPublic) -> RatchetKeyPublic {
        use crate::convert::convert_public_key;
        let public = convert_public_key(&spk.to_bytes()).unwrap();
        RatchetKeyPublic(public)
    }
}

/// A key pair used in the Diffie-Hellman ratchet.
///
/// The first ratchet of the Double Ratchet is the synchronous
/// Diffie-Hellman ratchet.  On each half-round-trip, the receiver
/// ratchets this twice: once to initialize the next receiving chain
/// and once to initialize the next sending chain.
#[derive(Debug, PartialEq, Eq)]
pub struct RatchetKeyPair {
    pub public: RatchetKeyPublic,
    pub secret: RatchetKeySecret,
}

impl RatchetKeyPair {
    pub fn generate<R: CryptoRng + RngCore>(csprng: &mut R) -> RatchetKeyPair {
        use crate::convert::{convert_public_key, convert_secret_key};

        let ed_pair = ed25519_dalek::Keypair::generate(csprng);

        // TODO: not unwrap
        let public = convert_public_key(&ed_pair.public.as_bytes()).unwrap();
        let public = RatchetKeyPublic(public);
        let secret = convert_secret_key(&ed_pair.secret).unwrap();
        let secret = RatchetKeySecret(secret.0);

        RatchetKeyPair { public, secret }
    }
}

impl<'a> From<&'a SignedPrekeyPair> for RatchetKeyPair {
    fn from(spk: &'a SignedPrekeyPair) -> RatchetKeyPair {
        use crate::convert::{convert_public_key, convert_secret_key};

        // TODO: not unwrap
        let public = convert_public_key(&spk.0.public.0.to_bytes()).unwrap();
        let public = RatchetKeyPublic(public);
        let secret = convert_secret_key(&spk.0.secret).unwrap();
        let secret = RatchetKeySecret(secret.0);

        RatchetKeyPair { public, secret }
    }
}
