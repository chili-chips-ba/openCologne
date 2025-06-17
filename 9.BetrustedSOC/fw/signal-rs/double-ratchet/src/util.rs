//! Various cryptographic utility functions.
//!
//! These simply wrap the actual implementations, locking
//! in parameters and exposing an interface focused on their
//! use in this project.  You are recommended to use the
//! underlying functions themselves.
use signal_common::error::{Error, Result};

use hkdf::*;
use hmac::{Hmac, Mac, NewMac};
use betrusted_hal::hal_sha512::{Sha512, Sha512Trunc256};
//use sha2::{Sha512, Sha512Trunc256};

pub fn hkdf(
    salt: &[u8],
    input: &[u8],
    info: &[u8],
) -> [u8; 64] {
    let mut key = [0; 64];

    let hkdf_obj = Hkdf::<Sha512>::new(Some(salt), input);

    hkdf_obj.expand(info, &mut key).unwrap();
    key
}

pub fn hkdf_sha512(
    salt: &[u8],
    input: &[u8],
    info: &[u8],
    key: &mut [u8],
) {
    let hkdf_obj = Hkdf::<Sha512>::new(Some(salt), input);

    hkdf_obj.expand(info, key).unwrap();
}

pub fn hmac(
    key: &[u8],
    input: &[u8],
) -> [u8; 32] {

    let mut mac = Hmac::<Sha512Trunc256>::new_varkey(key).expect("HMAC can take key of any size");

    mac.update(input);
    let result = mac.finalize();

    let mut res: [u8; 32] = [0; 32];

    let mut i: usize = 0;
    for byte in result.into_bytes() {
        res[i] = byte as u8;
        i += 1;
    }

    res
}

pub fn hmac_sha512(
    key: &[u8],
    input: &[u8],
) -> [u8; 64] {

    let mut mac = Hmac::<Sha512>::new_varkey(key).expect("HMAC can take key of any size");

    mac.update(input);
    let result = mac.finalize();

    let mut i: usize = 0;
    let mut res: [u8; 64] = [0; 64];
    for byte in result.into_bytes() {
        res[i] = byte as u8;
        i += 1;
    }

    res
}

pub fn hmac_sha512_two_slices(
    key: &[u8],
    input1: &[u8],
    input2: &[u8],
) -> [u8; 64] {
    let mut mac = Hmac::<Sha512>::new_varkey(key).unwrap();

    mac.update(input1);
    mac.update(input2);
    let result = mac.finalize();

    let mut i: usize = 0;
    let mut res: [u8; 64] = [0; 64];
    for byte in result.into_bytes() {
        res[i] = byte as u8;
        i += 1;
    }

    res
}

pub fn aes256_cbc_pkcs7_encrypt<'a>(
    key: &[u8],
    iv: &[u8],
    buffer: &'a mut [u8],
    len: usize,
) -> &'a [u8] {
    use aes::Aes256;
    use aes::block_cipher_trait::generic_array::GenericArray;
    use block_modes::{BlockMode, BlockModeIv, Cbc};
    use block_modes::block_padding::Pkcs7;

    type Aes256Cbc = Cbc<Aes256, Pkcs7>;

    //let key = GenericArray::from_slice(key);
    let iv = GenericArray::from_slice(iv);
    let cipher = Aes256Cbc::new_varkey(key, iv).unwrap();

    // TODO: not unwrap!
    cipher.encrypt_pad(buffer, len).unwrap()
}

pub fn aes256_cbc_pkcs7_decrypt<'a>(
    key: &[u8],
    iv: &[u8],
    buffer: &'a mut [u8],
) -> Result<&'a [u8]> {
    use aes::Aes256;
    use aes::block_cipher_trait::generic_array::GenericArray;
    use block_modes::{BlockMode, BlockModeIv, Cbc};
    use block_modes::block_padding::Pkcs7;

    type Aes256Cbc = Cbc<Aes256, Pkcs7>;

    //let key = GenericArray::from_slice(key);
    let iv = GenericArray::from_slice(iv);
    let cipher = Aes256Cbc::new_varkey(key, iv).unwrap();

    cipher.decrypt_pad(buffer).map_err(|_| Error)
}
