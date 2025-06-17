const PLAINTEXT_1: [u8;16] =
    [0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
     0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff];

const KEY_1: [u8; 32] =
[0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f];

const CIPHERTEXT_1: [u8; 16] =
[
    0x8e, 0xa2, 0xb7, 0xca, 0x51, 0x67, 0x45, 0xbf,
    0xea, 0xfc, 0x49, 0x90, 0x4b, 0x49, 0x60, 0x89
];

use betrusted_hal::hal_aes::*;

pub fn test_aes_enc(aes: &mut BtAes) -> (bool, [u8; 16]) {
    aes.aes_reset();
    while !aes.aes_idle() {}

    let mut data: [u8; 16] = [0; 16];
    //return (true, data);

    aes.control = AesCtrl::MODE_ECB | AesCtrl::KEY_LEN_256 | AesCtrl::ENC_OPER;
    aes.aes_init(aes.control);

    aes.key_put(&mut &KEY_1[0..32]);

    aes.aes_data_put_wait(&mut &PLAINTEXT_1[0..16]);
    aes.aes_data_get_wait(&mut data);

    let mut pass = true;
    for i in 0..16 {
        if data[i] != CIPHERTEXT_1[i] {
            pass = false;
        }
    }
    (pass, data)
}

pub fn test_aes_dec(aes: &mut BtAes) -> (bool, [u8; 16]) {
    aes.aes_reset();
    while !aes.aes_idle() {}

    let mut data: [u8; 16] = [0; 16];

    aes.control = AesCtrl::MODE_ECB | AesCtrl::KEY_LEN_256 | AesCtrl::DEC_OPER;
    aes.aes_init(aes.control);
    aes.key_put(&mut &KEY_1[0..32]);

    aes.aes_data_put_wait(&mut &CIPHERTEXT_1[0..16]);
    aes.aes_data_get_wait(&mut data);

    let mut pass = true;
    for i in 0..16 {
        if data[i] != PLAINTEXT_1[i] {
            pass = false;
        }
    }
    (pass, data)
}