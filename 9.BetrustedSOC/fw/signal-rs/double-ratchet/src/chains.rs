#[cfg(not(test))]
use alloc::vec::*;
#[cfg(test)]
use std::vec::*;

use signal_common::keys::{ChainKey, SessionKey, MessageKey};

use crate::util::{hkdf, hmac};

pub trait Kdf {
    type Input;
    type Output;

    fn derive(&self, key: ChainKey, input: Self::Input) -> (ChainKey, Self::Output);
}

struct ChainData<K> {
    key: Option<ChainKey>,
    kdf: K,
    n: u32,
}

impl<K: Kdf> ChainData<K> {
    fn init(kdf: K, key: ChainKey) -> ChainData<K> {
        ChainData { key: Some(key), kdf, n: 0 }
    }

    fn advance(&mut self, input: K::Input) -> (u32, K::Output) {
        let key = self.key.take().unwrap();
        let (key, output) = self.kdf.derive(key, input);
        self.key = Some(key);
        let n = self.n;
        self.n += 1;
        (n, output)
    }

    fn into_kdf(self) -> K {
        self.kdf
    }
}

struct Chainer<K> {
    kdf: K,
}

impl<K: Kdf> Chainer<K> {
    fn with_kdf(kdf: K) -> Chainer<K> {
        Chainer { kdf }
    }

    fn into_chain_data(self, key: ChainKey) -> ChainData<K> {
        ChainData::init(self.kdf, key)
    }
}

enum ChainState<K> {
    Init(Chainer<K>),
    Run(ChainData<K>),
}

pub struct Chain<K> {
    state: Option<ChainState<K>>,
}

impl<K: Kdf> Chain<K> {
    fn with_kdf(kdf: K) -> Chain<K> {
        Chain { state: Some(ChainState::Init(Chainer::with_kdf(kdf))) }
    }


    fn next_chain(&mut self, key: ChainKey) {
        self.state = Some(ChainState::Run(match self.state.take().unwrap() {
            ChainState::Init(chainer) => chainer.into_chain_data(key),
            ChainState::Run(chain) => {
                let kdf = chain.into_kdf();
                ChainData::init(kdf, key)
            },
        }))
    }

    fn advance(&mut self, input: K::Input) -> (u32, K::Output) {
        match self.state {
            Some(ChainState::Run(ref mut chain)) => chain.advance(input),
            // TODO: don't panic
            _ => panic!("Chain not initialized!"),
        }
    }
}

pub struct RootKdf(Vec<u8>);

impl Kdf for RootKdf {
    type Input = SessionKey;
    type Output = ChainKey;

    fn derive(&self, key: ChainKey, input: SessionKey) -> (ChainKey, ChainKey) {
        let bytes = hkdf(&key, &input, &self.0);
        let new_key = ChainKey::from(&bytes[0..32]);
        let output = ChainKey::from(&bytes[32..64]);
        (new_key, output)
    }
}

pub struct ChainKdf;

impl Kdf for ChainKdf {
    type Input = ();
    type Output = MessageKey;

    fn derive(&self, key: ChainKey, _input: ()) -> (ChainKey, MessageKey) {
        let raw_key = hmac(&key, &[0x02]);
        let raw_out = hmac(&key, &[0x01]);

        let new_key = ChainKey::from(&raw_key[..]);
        let output = MessageKey::from(&raw_out[..]);

        (new_key, output)
    }
}

pub struct Chains {
    root: Chain<RootKdf>,
    sending: Chain<ChainKdf>,
    receiving: Chain<ChainKdf>,
}

impl Chains {
    pub fn init<Bytes: core::ops::Deref<Target=[u8]>>(info: Bytes, rk: ChainKey) -> Chains {
        let mut root = Chain::with_kdf(RootKdf((*info).into()));
        root.next_chain(rk);
        let sending = Chain::with_kdf(ChainKdf);
        let receiving = Chain::with_kdf(ChainKdf);
        Chains { root, sending, receiving }
    }

    pub fn next_sending_chain(&mut self, key: SessionKey) {
        let key = self.root.advance(key).1;
        self.sending.next_chain(key);
    }

    pub fn next_receiving_chain(&mut self, key: SessionKey) {
        let key = self.root.advance(key).1;
        self.receiving.next_chain(key);
    }

    pub fn next_sending_key(&mut self) -> (u32, MessageKey) {
        self.sending.advance(())
    }

    pub fn next_receiving_key(&mut self) -> (u32, MessageKey) {
        self.receiving.advance(())
    }
}
