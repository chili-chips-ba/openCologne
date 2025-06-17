#![no_std]

use signal_common::keys::*;

use super::chains::*;
use super::ratchet::*;
use super::session::*;

fn get_rk() -> ChainKey {
    let key = std::iter::repeat(0x42).take(32).collect::<Vec<u8>>();
    ChainKey::from(key.as_slice())
}

fn get_sk(i: u8) -> SessionKey {
    // just pretend this is Diffie-Hellman
    let key = &std::iter::repeat(i).take(32).collect::<Vec<u8>>();
    SessionKey::from(key.as_slice())
}
/*
#[test]
fn test_mirror_manual() {
    let info = b"foobar!";
    let mut alice = Chains::init(&info[..], get_rk());
    let mut bob = Chains::init(&info[..], get_rk());

    let first_key = get_sk(1);
    alice.next_sending_chain(first_key);
    let m1_a = alice.next_sending_key();
    let m2_a = alice.next_sending_key();
    let first_key = get_sk(1);
    bob.next_receiving_chain(first_key);
    let m1_b = bob.next_receiving_key();
    let m2_b = bob.next_receiving_key();

    let second_key = get_sk(2);
    bob.next_sending_chain(second_key);
    let m3_b = bob.next_sending_key();
    let m4_b = bob.next_sending_key();
    let second_key = get_sk(2);
    alice.next_receiving_chain(second_key);
    let m3_a = alice.next_receiving_key();
    let m4_a = alice.next_receiving_key();

    assert_eq!(m1_a, m1_b);
    assert_eq!(m2_a, m2_b);
    assert_eq!(m3_a, m3_b);
    assert_eq!(m4_a, m4_b);

    assert_eq!(m1_a.0, 0);
    assert_eq!(m2_a.0, 1);
    assert_eq!(m3_a.0, 0);
    assert_eq!(m4_a.0, 1);

    assert!(m1_a.1 != MessageKey::from(&[0; 32][..]));
    assert!(m2_a.1 != MessageKey::from(&[0; 32][..]));
    assert!(m3_a.1 != MessageKey::from(&[0; 32][..]));
    assert!(m4_a.1 != MessageKey::from(&[0; 32][..]));

    assert!(m1_a.1 != m2_a.1);
    assert!(m1_a.1 != m3_a.1);
    assert!(m1_a.1 != m4_a.1);
    assert!(m2_a.1 != m1_a.1);
    assert!(m2_a.1 != m3_a.1);
    assert!(m2_a.1 != m4_a.1);
    assert!(m3_a.1 != m1_a.1);
    assert!(m3_a.1 != m2_a.1);
    assert!(m3_a.1 != m4_a.1);
    assert!(m4_a.1 != m1_a.1);
    assert!(m4_a.1 != m2_a.1);
    assert!(m4_a.1 != m3_a.1);
}
*/
#[test]
fn test_mirror_double_ratchet() {
    use rand_core::OsRng;

    let info = b"foobar!";
    let bob_keys = RatchetKeyPair::generate(&mut OsRng);
    let mut csprng = OsRng;
    let mut alice = DoubleRatchet::with_peer(
        &info[..], get_rk(), &mut csprng, &bob_keys.public
    );
    let mut bob = DoubleRatchet::with_keypair(
        &info[..], get_rk(), bob_keys
    );

    let m1_a = alice.next_sending_key();
    let m2_a = alice.next_sending_key();
    bob.ratchet(&mut csprng, alice.public());
    let m1_b = bob.next_receiving_key();
    let m2_b = bob.next_receiving_key();

    let m3_b = bob.next_sending_key();
    let m4_b = bob.next_sending_key();
    alice.ratchet(&mut csprng, bob.public());
    let m3_a = alice.next_receiving_key();
    let m4_a = alice.next_receiving_key();

    assert_eq!(m1_a, m1_b);
    assert_eq!(m2_a, m2_b);
    assert_eq!(m3_a, m3_b);
    assert_eq!(m4_a, m4_b);

    assert_eq!(m1_a.0, 0);
    assert_eq!(m2_a.0, 1);
    assert_eq!(m3_a.0, 0);
    assert_eq!(m4_a.0, 1);

    assert!(m1_a.1 != MessageKey::from(&[0; 32][..]));
    assert!(m2_a.1 != MessageKey::from(&[0; 32][..]));
    assert!(m3_a.1 != MessageKey::from(&[0; 32][..]));
    assert!(m4_a.1 != MessageKey::from(&[0; 32][..]));

    assert!(m1_a.1 != m2_a.1);
    assert!(m1_a.1 != m3_a.1);
    assert!(m1_a.1 != m4_a.1);
    assert!(m2_a.1 != m1_a.1);
    assert!(m2_a.1 != m3_a.1);
    assert!(m2_a.1 != m4_a.1);
    assert!(m3_a.1 != m1_a.1);
    assert!(m3_a.1 != m2_a.1);
    assert!(m3_a.1 != m4_a.1);
    assert!(m4_a.1 != m1_a.1);
    assert!(m4_a.1 != m2_a.1);
    assert!(m4_a.1 != m3_a.1);

}

#[test]
fn test_mirror_session() {
    use rand_core::OsRng;

    let info = b"foobar!";
    let session = || SessionBuilder::new(&info[..], get_rk());
    let mut csprng = OsRng;

    let bob_keys = RatchetKeyPair::generate(&mut csprng);

    let mut alice = session().connect_to(&bob_keys.public, &mut csprng);
    let mut bob = session().accept_with(bob_keys);

    let (h1, m1_a) = alice.send_key();
    let (h2, m2_a) = alice.send_key();
    let (h3, m3_a) = alice.send_key();
    let (h4, m4_a) = alice.send_key();

    // This receive will ratchet Bob's end.
    let m1_b = bob.receive_key(h1, &mut csprng);

    let (h5, m5_b) = bob.send_key();

    // Receiving out-of-order is no problem.
    let m3_b = bob.receive_key(h3, &mut csprng);
    let m2_b = bob.receive_key(h2, &mut csprng);

    let (h6, m6_b) = bob.send_key();

    // This receive will ratchet Alice's end.
    let m5_a = alice.receive_key(h5, &mut csprng);

    let (h7, m7_a) = alice.send_key();
    let (h8, m8_a) = alice.send_key();

    let m6_a = alice.receive_key(h6, &mut csprng);

    // This receive will ratchet Bob's end, having missed a few messages.
    let m8_b = bob.receive_key(h8, &mut csprng);

    // Let's just receive the others for good measure.
    let m7_b = bob.receive_key(h7, &mut csprng);
    let m4_b = bob.receive_key(h4, &mut csprng);
        assert_eq!(m1_a, m1_b);
        assert_eq!(m2_a, m2_b);
        assert_eq!(m3_a, m3_b);
        assert_eq!(m4_a, m4_b);
        assert_eq!(m5_a, m5_b);
        assert_eq!(m6_a, m6_b);
        assert_eq!(m7_a, m7_b);
        assert_eq!(m8_a, m8_b);

        assert!(m1_a != MessageKey::from(&[0; 32][..]));
        assert!(m2_a != MessageKey::from(&[0; 32][..]));
        assert!(m3_a != MessageKey::from(&[0; 32][..]));
        assert!(m4_a != MessageKey::from(&[0; 32][..]));
        assert!(m5_a != MessageKey::from(&[0; 32][..]));
        assert!(m6_a != MessageKey::from(&[0; 32][..]));
        assert!(m7_a != MessageKey::from(&[0; 32][..]));
        assert!(m8_a != MessageKey::from(&[0; 32][..]));

        assert!(m1_a != m2_a);
        assert!(m1_a != m3_a);
        assert!(m1_a != m4_a);
        assert!(m1_a != m5_a);
        assert!(m1_a != m6_a);
        assert!(m1_a != m7_a);
        assert!(m1_a != m8_a);

        assert!(m2_a != m1_a);
        assert!(m2_a != m3_a);
        assert!(m2_a != m4_a);
        assert!(m2_a != m5_a);
        assert!(m2_a != m6_a);
        assert!(m2_a != m7_a);
        assert!(m2_a != m8_a);

        assert!(m3_a != m1_a);
        assert!(m3_a != m2_a);
        assert!(m3_a != m4_a);
        assert!(m3_a != m5_a);
        assert!(m3_a != m6_a);
        assert!(m3_a != m7_a);
        assert!(m3_a != m8_a);

        assert!(m4_a != m1_a);
        assert!(m4_a != m2_a);
        assert!(m4_a != m3_a);
        assert!(m4_a != m5_a);
        assert!(m4_a != m6_a);
        assert!(m4_a != m7_a);
        assert!(m4_a != m8_a);

        assert!(m5_a != m1_a);
        assert!(m5_a != m2_a);
        assert!(m5_a != m3_a);
        assert!(m5_a != m4_a);
        assert!(m5_a != m6_a);
        assert!(m5_a != m7_a);
        assert!(m5_a != m8_a);

        assert!(m6_a != m1_a);
        assert!(m6_a != m2_a);
        assert!(m6_a != m3_a);
        assert!(m6_a != m4_a);
        assert!(m6_a != m5_a);
        assert!(m6_a != m7_a);
        assert!(m6_a != m8_a);

        assert!(m7_a != m1_a);
        assert!(m7_a != m2_a);
        assert!(m7_a != m3_a);
        assert!(m7_a != m4_a);
        assert!(m7_a != m5_a);
        assert!(m7_a != m6_a);
        assert!(m7_a != m8_a);

        assert!(m8_a != m1_a);
        assert!(m8_a != m2_a);
        assert!(m8_a != m3_a);
        assert!(m8_a != m4_a);
        assert!(m8_a != m5_a);
        assert!(m8_a != m6_a);
        assert!(m8_a != m7_a);

}
/*
#[test]
fn test_unique_sessions() {
    use rand_core::OsRng;

    let info = b"foobar!";
    let session = || SessionBuilder::new(&info[..], get_rk());
    let mut csprng = OsRng;

    let bob_keys = RatchetKeyPair::generate(&mut csprng);

    let mut alice = session().connect_to(&bob_keys.public, &mut csprng);
    let (_, m1_a) = alice.send_key();

    let mut alice = session().connect_to(&bob_keys.public, &mut csprng);
    let (_, m2_a) = alice.send_key();

    assert!(m1_a != m2_a);
}

#[test]
fn test_session_roundtrip_encrypted() {
    use rand_core::OsRng;

    let info = b"foobar!";
    let session = || SessionBuilder::new(&info[..], get_rk());
    let mut csprng = OsRng;

    let bob_keys = RatchetKeyPair::generate(&mut csprng);

    let mut alice = session().connect_to(&bob_keys.public, &mut csprng);
    let mut bob = session().accept_with(bob_keys);

    let m1_p = b"hello bob!";
    let (h1, m1_c) = alice.send(m1_p);
    let m1_r = bob.receive(h1, &m1_c, &mut csprng).unwrap();

    let m2_p = b"hi alice, how are you?";
    let (h2, m2_c) = bob.send(m2_p);
    let m2_r = alice.receive(h2, &m2_c, &mut csprng).unwrap();

    let m3_p = b"oh and can you pick up milk please?";
    let (h3, m3_c) = bob.send(m3_p);
    let m3_r = alice.receive(h3, &m3_c, &mut csprng).unwrap();

    let m4_p = b"i'd be glad to.";
    let (h4, m4_c) = alice.send(m4_p);
    let m4_r = bob.receive(h4, &m4_c, &mut csprng).unwrap();

    assert_eq!(&m1_p[..], &m1_r[..]);
    assert_eq!(&m2_p[..], &m2_r[..]);
    assert_eq!(&m3_p[..], &m3_r[..]);
    assert_eq!(&m4_p[..], &m4_r[..]);
}

#[test]
fn test_authenticated_encryption() {
    use rand_core::OsRng;

    use session::generate_ad;
    use encrypt::AeadCipher;

    let info = b"foobar!";
    let session = || SessionBuilder::new(&info[..], get_rk());
    let mut csprng = OsRng;

    let bob_keys = RatchetKeyPair::generate(&mut csprng);

    let mut alice = session().connect_to(&bob_keys.public, &mut csprng);
    let mut bob = session().accept_with(bob_keys);

    let m1_p = b"hello bob!";
    let (h1, m1_c) = alice.send(m1_p);

    let mut bad_header = h1.clone();
    bad_header.count += 1;

    let key = bob.receive_key(h1, &mut csprng);
    let ad = generate_ad(&b"ad"[..], &bad_header);
    let cipher = AeadCipher::new(&b"another info"[..], key, &ad);
    let res = cipher.decrypt(&m1_c);

    assert!(res.is_err());
}
*/