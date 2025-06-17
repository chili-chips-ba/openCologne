//! Convert Ed25519 keys to X25519.
//!
//! These functions are for internal use.  You are recommended to use
//! the comparable ones in the dalek crates instead.

// TODO: can we make these really public or gone?

use ed25519_dalek::Keypair;
use curve25519_dalek::edwards::CompressedEdwardsY;
use curve25519_dalek::montgomery::MontgomeryPoint;
use sha2::{Digest, Sha512};

use crate::error::{Error, Result};

pub struct SecretKey(pub(crate) [u8; 32]);

impl SecretKey {
    pub fn from_bytes(bytes: [u8; 32]) -> SecretKey {
        SecretKey(bytes)
    }

    pub fn as_bytes(&self) -> &[u8; 32] {
        &self.0
    }
}

pub struct X25519Keypair {
    pub public: MontgomeryPoint,
    pub secret: SecretKey,
}

pub fn convert_public_key(
    pk: &[u8; 32],
) -> Result<MontgomeryPoint> {
    let ed25519_pk_c = CompressedEdwardsY::from_slice(pk);
    let ed25519_pk = match ed25519_pk_c.decompress() {
        Some(p) => p,
        None => return Err(Error),
    };
    Ok(ed25519_pk.to_montgomery())
}

pub fn convert_secret_key(
    sk: &ed25519_dalek::SecretKey,
) -> Result<SecretKey> {
    let mut hasher = Sha512::new();
    hasher.update(sk.as_bytes());
    let hash = hasher.finalize();

    let mut x25519_sk = [0; 32];

    for i in 0..32 {
        x25519_sk[i] = hash[i];
    }

    x25519_sk[0] &= 248;
    x25519_sk[31] &= 127;
    x25519_sk[31] |= 64;

    Ok(SecretKey(x25519_sk))
}

pub fn convert_ed25519_to_x25519(ed25519: &Keypair) -> Result<X25519Keypair> {
    let public = convert_public_key(&ed25519.public.as_bytes())?;
    let secret = convert_secret_key(&ed25519.secret)?;

    Ok(X25519Keypair { secret, public })
}

#[cfg(test)]
mod tests {
    use rand_core::OsRng;
    use sha2::Sha512;
    use ed25519_dalek::Keypair;
    // use x25519_dalek::generate_public;
    use x25519_dalek::{StaticSecret, EphemeralSecret, PublicKey};

    use super::*;

    // The original test (which presumably worked):
    // fn test_convert_isomorphism() {
    //     let mut csprng = OsRng::new().unwrap();

    //     let pair = Keypair::generate::<Sha512, _>(&mut csprng);
    //     let conv = convert_ed25519_to_x25519(&pair).unwrap();

    //     let regen_pub = generate_public(&conv.secret.as_bytes());

    //     let conv_len = conv.public.as_bytes().len();
    //     let regen_len = regen_pub.as_bytes().len();

    //     assert_eq!(conv_len, regen_len);
    //     for i in 0..conv_len {
    //         assert_eq!(conv.public.as_bytes()[i], regen_pub.as_bytes()[i]);
    //     }
    // }

    #[test]
    fn test_convert_isomorphism() {
        let mut csprng = rand::rngs::OsRng;

        let pair = Keypair::generate(&mut csprng);
        let conv = convert_ed25519_to_x25519(&pair).unwrap();

        let regen_pub = PublicKey::from(*conv.secret.as_bytes());

        let conv_len = conv.public.as_bytes().len();
        let regen_bytes = regen_pub.as_bytes();
        let regen_len = regen_bytes.len();

        println!("conv_len: {}", conv_len);
        println!("conv public: {:?}", conv.public.as_bytes());
        println!("regen len: {}", regen_len);
        println!("regen bytes: {:?}", regen_bytes);
        assert_eq!(conv_len, regen_len);
        for i in 0..conv_len {
            assert_eq!(conv.public.as_bytes()[i], regen_bytes[i]);
        }
    }
}
