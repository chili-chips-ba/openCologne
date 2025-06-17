//! Encrypt and decrypt messages.
//!
//! This module is the workhorse of the Signal protocol.  All the rest
//! of the song and dance is just a complicated way to get a really big
//! number.  Here is where the rubber hits the road: we use that number
//! to scramble up something legible and then unscramble it again later.
#[cfg(not(test))]
use alloc::vec::*;
#[cfg(test)]
use std::vec::*;

use signal_common::error::{Error, Result};
use signal_common::keys::MessageKey;

use crate::util::{
    hkdf_sha512,
    hmac_sha512_two_slices,
    aes256_cbc_pkcs7_encrypt,
    aes256_cbc_pkcs7_decrypt,
};

const HMAC_WIDTH: usize = 64;
const MARGIN: usize = 32;

/// An implementation of Authenticated Encryption with Associated Data.
pub struct AeadCipher<'a> {
    info: &'static [u8],
    key: MessageKey,
    ad: &'a [u8],
}

impl<'a> AeadCipher<'a> {
    /// Initialize the cipher with the given parameters.
    pub fn new(info: &'static [u8], key: MessageKey, ad: &'a [u8]) -> AeadCipher<'a> {
        AeadCipher { info, key, ad }
    }

    /// Encrypt a message with this cipher.
    pub fn encrypt(self, plaintext: &[u8]) -> Vec<u8> {
        let len = plaintext.len();

        let mut buffer: Vec<_> = core::iter::repeat(0)
            .take(len + HMAC_WIDTH + MARGIN)
            .collect();

        let salt = [0; 64];
        let mut keys = [0; 80];
        hkdf_sha512(&salt, &self.key, self.info, &mut keys);

        let encryption_key = &keys[..32];
        let authentication_key = &keys[32..64];
        let iv = &keys[64..];

        buffer[..len].copy_from_slice(plaintext);

        let enc_len = {
            let encrypted = aes256_cbc_pkcs7_encrypt(
                encryption_key, iv, &mut buffer, len,
            );
            encrypted.len()
        };

        let mac = hmac_sha512_two_slices(
            authentication_key, self.ad, &buffer[..enc_len]
        );

        let verify_len = enc_len + HMAC_WIDTH;

        buffer[enc_len..verify_len].copy_from_slice(&mac);

        buffer.split_off(verify_len);
        buffer
    }

    /// Decrypt a message with this cipher.
    pub fn decrypt(self, ciphertext: &[u8]) -> Result<Vec<u8>> {
        use orion::util::secure_cmp;

        let msg_len = ciphertext.len();
        let enc_len = msg_len - HMAC_WIDTH;

        let salt = [0; 64];
        let mut keys = [0; 80];
        hkdf_sha512(&salt, &self.key, self.info, &mut keys);

        let encryption_key = &keys[..32];
        let authentication_key = &keys[32..64];
        let iv = &keys[64..];

        let mac = hmac_sha512_two_slices(
            authentication_key, self.ad, &ciphertext[..enc_len],
        );

        let msg_mac = &ciphertext[enc_len..];

        match secure_cmp(&mac, msg_mac) {
            Ok(()) => {},
            _ => return Err(Error),
        }

        let mut buffer = core::iter::repeat(0).take(enc_len).collect::<Vec<_>>();

        buffer.copy_from_slice(&ciphertext[..enc_len]);

        let msg_len = {
            let msg = aes256_cbc_pkcs7_decrypt(
                encryption_key, iv, &mut buffer,
            )?;
            msg.len()
        };

        buffer.split_off(msg_len);
        Ok(buffer)
    }
}

/*
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_encrypt_roundtrip() {
        let info = &b"application info string"[..];
        let ad = &b"associated data string"[..];

        let plaintext = &b"the quick brown fox jumps over the lazy dog"[..];

        let key = MessageKey::from(&[0x42; 32][..]);
        let cipher = AeadCipher::new(info, key, ad);
        let ciphertext = cipher.encrypt(plaintext);

        let key = MessageKey::from(&[0x42; 32][..]);
        let cipher = AeadCipher::new(info, key, ad);
        let roundtripped = cipher.decrypt(&ciphertext).unwrap();

        assert_eq!(plaintext, &roundtripped[..]);
    }
}
*/