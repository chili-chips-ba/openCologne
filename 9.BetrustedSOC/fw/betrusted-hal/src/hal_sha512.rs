use bitflags::*;
use volatile::Volatile;

use digest::consts::{U128, U32, U64};
use digest::{BlockInput, FixedOutputDirty, Reset, Update};

bitflags! {
    pub struct Sha512Config: u32 {
        const NONE        = 0b0000_0000;
        const SHA512_EN   = 0b0000_0001;
        const ENDIAN_SWAP = 0b0000_0010;
        const DIGEST_SWAP = 0b0000_0100;
        const SHA512_256  = 0b0000_1000;
    }
}

bitflags! {
    pub struct Sha512Command: u32 {
        const HASH_START  = 0b0000_0001;
        const HASH_DIGEST = 0b0000_0010;
    }
}

bitflags! {
    pub struct Sha512Status: u32 {
        const DONE = 0b0000_0001;
    }
}

bitflags! {
    pub struct Sha512Fifo: u32 {
        const READ_COUNT_MASK  = 0b0000_0000_0000_0000_0001_1111_1111;
        const WRITE_COUNT_MASK = 0b0000_0011_1111_1111_1110_0000_0000;
        const READ_ERROR       = 0b0000_0100_0000_0000_0000_0000_0000;
        const WRITE_ERROR      = 0b0000_1000_0000_0000_0000_0000_0000;
        const ALMOST_FULL      = 0b0001_0000_0000_0000_0000_0000_0000;
        const ALMOST_EMPTY     = 0b0010_0000_0000_0000_0000_0000_0000;
        const ENGINE_RUNNING   = 0b0100_0000_0000_0000_0000_0000_0000;
    }
}

bitflags! {
    pub struct Sha512Event: u32 {
        const ERROR       = 0b0001;
        const FIFO_FULL   = 0b0010;
        const SHA512_DONE = 0b0100;
    }
}

type BlockSize = U128;

pub enum Sha512Type {
    Sha512,
    Sha512Trunc256,
}

struct Engine512 {
    p: betrusted_pac::Peripherals,
    pub config: Sha512Config,
    state: [u64; 8],
}

impl Clone for Engine512 {
    fn clone(&self) -> Engine512 {
        unsafe {
            Engine512 {
                p: betrusted_pac::Peripherals::steal(),
                config: self.config,
                state: self.state,
            }
        }
    }
}

impl Engine512 {
    fn new(which: Sha512Type) -> Engine512 {
        let ret : Engine512 =
            match which {
                Sha512Type::Sha512 => unsafe {
                    Engine512 {
                        p: betrusted_pac::Peripherals::steal(),
                        config: Sha512Config::ENDIAN_SWAP | Sha512Config::DIGEST_SWAP | Sha512Config::SHA512_EN,
                        state: [0; 8],
                    }
                },
                Sha512Type::Sha512Trunc256 => unsafe {
                    Engine512 {
                        p: betrusted_pac::Peripherals::steal(),
                        config: Sha512Config::ENDIAN_SWAP | Sha512Config::DIGEST_SWAP | Sha512Config::SHA512_256 | Sha512Config::SHA512_EN,
                        state: [0; 8],
                    }
                },
            };

        // TODO: add mutex around the SHA engine, for now, just take control

        // if the engine is already running, terminate its current operation and reset it
        if ret.p.SHA512.fifo.read().running().bit() {
            let sha_ptr: *mut u32 = 0xe0002000 as *mut u32;
            let sha = sha_ptr as *mut Volatile<u32>;
            unsafe { (*sha).write(0x0); } // stuff a dummy byte in in case the hash is empty

            // a reset happens only by enabling "process", discarding the output, and then re-initializing
            ret.p.SHA512.command.write(|w|{ w.hash_process().set_bit()});
            while (ret.p.SHA512.ev_pending.read().bits() & (Sha512Event::SHA512_DONE).bits()) == 0 {}
            unsafe{ ret.p.SHA512.ev_pending.write(|w| w.bits((Sha512Event::SHA512_DONE).bits()) ); }

            unsafe{ ret.p.SHA512.config.write(|w|{ w.bits(0) }); } // clear all config bits, including EN, which resets the unit
        }

        // commit the config + enable
        unsafe{ ret.p.SHA512.config.write(|w|{ w.bits(ret.config.bits()) }); }
        // the "hash_start" bit puts us in a mode ready to auto-accept digest data
        ret.p.SHA512.command.write(|w|{ w.hash_start().set_bit() });

        // enable "done" events
        unsafe{ ret.p.SHA512.ev_enable.write(|w| {w.sha512_done().set_bit()}); }
        ret
    }


    fn update(&mut self, input: &[u8]) {
        let sha_ptr: *mut u32 = 0xe0002000 as *mut u32;
        let sha = sha_ptr as *mut Volatile<u32>;
        let sha_byte_ptr: *mut u8 = 0xe0002000 as *mut u8;
        let sha_byte = sha_byte_ptr as *mut Volatile<u8>;

        for (_reg, chunk) in input.chunks(4).enumerate() {
            let mut temp: [u8; 4] = Default::default();
            if chunk.len() == 4 {
                temp.copy_from_slice(chunk);
                let dword: u32 = u32::from_le_bytes(temp);

                while self.p.SHA512.fifo.read().almost_full().bit() {}
                unsafe { (*sha).write(dword); }
            } else {
                for index in 0..chunk.len() {
                    while self.p.SHA512.fifo.read().almost_full().bit() {}
                    unsafe{ (*sha_byte).write(chunk[index]); }
                }
            }
        }
    }

    fn finish(&mut self) {
        self.p.SHA512.command.write(|w|{ w.hash_process().set_bit()});
        while (self.p.SHA512.ev_pending.read().bits() & (Sha512Event::SHA512_DONE).bits()) == 0 {}
        unsafe{ self.p.SHA512.ev_pending.write(|w| w.bits((Sha512Event::SHA512_DONE).bits()) ); }
        for reg in 0..8 {
            match reg {
                0 => self.state[reg] = (self.p.SHA512.digest01.read().bits() as u64) << 32 | self.p.SHA512.digest00.read().bits() as u64,
                1 => self.state[reg] = (self.p.SHA512.digest11.read().bits() as u64) << 32 | self.p.SHA512.digest10.read().bits() as u64,
                2 => self.state[reg] = (self.p.SHA512.digest21.read().bits() as u64) << 32 | self.p.SHA512.digest20.read().bits() as u64,
                3 => self.state[reg] = (self.p.SHA512.digest31.read().bits() as u64) << 32 | self.p.SHA512.digest30.read().bits() as u64,
                4 => self.state[reg] = (self.p.SHA512.digest41.read().bits() as u64) << 32 | self.p.SHA512.digest40.read().bits() as u64,
                5 => self.state[reg] = (self.p.SHA512.digest51.read().bits() as u64) << 32 | self.p.SHA512.digest50.read().bits() as u64,
                6 => self.state[reg] = (self.p.SHA512.digest61.read().bits() as u64) << 32 | self.p.SHA512.digest60.read().bits() as u64,
                7 => self.state[reg] = (self.p.SHA512.digest71.read().bits() as u64) << 32 | self.p.SHA512.digest70.read().bits() as u64,
                _ => assert!(false),
            }
        }
        unsafe{ self.p.SHA512.config.write(|w|{ w.bits(0x0) }); } // this should reset/disable the unit
        // do we need to introduce a delay at all??
        // delay_ms(&self.p, 2);
        unsafe{ self.p.SHA512.config.write(|w|{ w.bits(self.config.bits()) }); }
        // the "hash_start" bit puts us in a mode ready to auto-accept digest data
        self.p.SHA512.command.write(|w|{ w.hash_start().set_bit() });
    }

    fn reset(&mut self, which: Sha512Type) {
        let sha_ptr: *mut u32 = 0xe0002000 as *mut u32;
        let sha = sha_ptr as *mut Volatile<u32>;
        unsafe { (*sha).write(0x0); } // stuff a dummy byte in in case the hash is empty

        // a reset happens only by enabling "process", discarding the output, and then re-initializing
        self.p.SHA512.command.write(|w|{ w.hash_process().set_bit()});
        while (self.p.SHA512.ev_pending.read().bits() & (Sha512Event::SHA512_DONE).bits()) == 0 {}
        unsafe{ self.p.SHA512.ev_pending.write(|w| w.bits((Sha512Event::SHA512_DONE).bits()) ); }

        unsafe{ self.p.SHA512.config.write(|w|{ w.bits(0) }); } // clear all config bits, including EN, which resets the unit
        match which {
            Sha512Type::Sha512 => self.config = Sha512Config::ENDIAN_SWAP | Sha512Config::DIGEST_SWAP,
            Sha512Type::Sha512Trunc256 => self.config = Sha512Config::ENDIAN_SWAP | Sha512Config::DIGEST_SWAP | Sha512Config::SHA512_256,
        }
        // commit the config + enable
        unsafe{ self.p.SHA512.config.write(|w|{ w.bits(self.config.bits()) }); }
        // the "hash_start" bit puts us in a mode ready to auto-accept digest data
        self.p.SHA512.command.write(|w|{ w.hash_start().set_bit() });
    }
}

/// The SHA-512 hash algorithm with the SHA-512 initial hash value.
#[derive(Clone)]
pub struct Sha512 {
    engine: Engine512,
}

impl Default for Sha512 {
    fn default() -> Self {
        Sha512 {
            engine: Engine512::new(Sha512Type::Sha512),
        }
    }
}

impl BlockInput for Sha512 {
    type BlockSize = BlockSize;
}

impl Update for Sha512 {
    fn update(&mut self, input: impl AsRef<[u8]>) {
        self.engine.update(input.as_ref());
    }
}

impl FixedOutputDirty for Sha512 {
    type OutputSize = U64;

    fn finalize_into_dirty(&mut self, out: &mut digest::Output<Self>) {
        self.engine.finish();
        let s = self.engine.state;
        for (chunk, v) in out.chunks_exact_mut(8).zip(s.iter()) {
            chunk.copy_from_slice(&v.to_be_bytes());
        }
    }
}

impl Reset for Sha512 {
    fn reset(&mut self) {
        self.engine.reset(Sha512Type::Sha512);
    }
}

/// The SHA-512 hash algorithm with the SHA-512/256 initial hash value. The
/// result is truncated to 256 bits.
#[derive(Clone)]
pub struct Sha512Trunc256 {
    engine: Engine512,
}

impl Default for Sha512Trunc256 {
    fn default() -> Self {
        Sha512Trunc256 {
            engine: Engine512::new(Sha512Type::Sha512Trunc256),
        }
    }
}

impl BlockInput for Sha512Trunc256 {
    type BlockSize = BlockSize;
}

impl Update for Sha512Trunc256 {
    fn update(&mut self, input: impl AsRef<[u8]>) {
        self.engine.update(input.as_ref());
    }
}

impl FixedOutputDirty for Sha512Trunc256 {
    type OutputSize = U32;

    fn finalize_into_dirty(&mut self, out: &mut digest::Output<Self>) {
        self.engine.finish();
        let s = &self.engine.state[..4];
        for (chunk, v) in out.chunks_exact_mut(8).zip(s.iter()) {
            chunk.copy_from_slice(&v.to_be_bytes());
        }
    }
}

impl Reset for Sha512Trunc256 {
    fn reset(&mut self) {
        self.engine.reset(Sha512Type::Sha512Trunc256);
    }
}
