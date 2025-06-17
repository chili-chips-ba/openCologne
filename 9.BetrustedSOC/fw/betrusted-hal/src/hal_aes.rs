use bitflags::*;

bitflags! {
    pub struct AesCtrl: u32 {
        const MODE_MASK   = 0b0000_0111;
        const MODE_ECB    = 0b0000_0001;
        const MODE_CBC    = 0b0000_0010;
        const MODE_CTR    = 0b0000_0100;
        const KEY_LEN_128 = 0b0000_1000;
        const KEY_LEN_192 = 0b0001_0000;
        const KEY_LEN_256 = 0b0010_0000;
        const KEY_LEN_MASK= 0b0011_1000;
        const MANUAL_OP   = 0b0100_0000;
        const OPERATION   = 0b1000_0000;
        const ENC_OPER    = 0b0000_0000;
        const DEC_OPER    = 0b1000_0000;
    }
}

bitflags! {
    pub struct AesStatus: u32 {
        const IDLE         = 0b0000_0001;
        const STALL        = 0b0000_0010;
        const OUTPUT_VALID = 0b0000_0100;
        const INPUT_READY  = 0b0000_1000;
        const OPER_RBK     = 0b0001_0000;
        const MODE_RBK     = 0b0010_0000;
        const LEN_READBACK_MASK = 0b1_1100_0000;
        const LEN_READBACK_128  = 0b0_0100_0000;
        const LEN_READBACK_192  = 0b0_1000_0000;
        const LEN_READBACK_256  = 0b1_0000_0000;
        const MANUAL_OP_RBK = 0b10_0000_0000;
    }
}

bitflags! {
    pub struct AesTrigger: u32 {
        const START          = 0b0000_0001;
        const KEY_CLEAR      = 0b0000_0010;
        const IV_CLEAR       = 0b0000_0100;
        const DATA_IN_CLEAR  = 0b0000_1000;
        const DATA_OUT_CLEAR = 0b0001_0000;
        const PRNG_RESEED    = 0b0010_0000;
    }
}

pub struct BtAes {
    p: betrusted_pac::Peripherals,
    pub control: AesCtrl,
}

impl BtAes {
    pub fn new() -> Self {
        unsafe {
            BtAes {
                p: betrusted_pac::Peripherals::steal(),
                control: (AesCtrl::MODE_ECB | AesCtrl::KEY_LEN_128 | AesCtrl::ENC_OPER),
            }
        }
    }

    /// key is presented in MSB-first octet format array;
    /// hardware is expecting it in little-endian 32-bit format
    pub fn key_put(&mut self, key: &mut &[u8] ) -> bool {
        self.report(0x3000_0000);
        match key.len() {
            16 => unsafe{ self.p.AES.ctrl.modify( |r, w| {w.bits(r.bits() & !AesCtrl::KEY_LEN_MASK.bits() | AesCtrl::KEY_LEN_128.bits())}) },
            24 => unsafe{ self.p.AES.ctrl.modify( |r, w| {w.bits(r.bits() & !AesCtrl::KEY_LEN_MASK.bits() | AesCtrl::KEY_LEN_192.bits())}) },
            32 => unsafe{ self.p.AES.ctrl.modify( |r, w| {w.bits(r.bits() & !AesCtrl::KEY_LEN_MASK.bits() | AesCtrl::KEY_LEN_256.bits())}) },
            _ => return false,
        }
        self.report(0x3000_1000 + key.len() as u32);

        let mut index: usize = 0;
        for (reg, chunk) in key.chunks(4).enumerate() {
            self.report(0x3000_2000 + reg as u32);
            let mut temp: [u8; 4] = Default::default();
            temp.copy_from_slice(chunk);
            let keyword = u32::from_le_bytes(temp);
            match reg {
                0 => unsafe{ self.p.AES.key_0_q.write(|w|{ w.bits(keyword) }); },
                1 => unsafe{ self.p.AES.key_1_q.write(|w|{ w.bits(keyword) }); },
                2 => unsafe{ self.p.AES.key_2_q.write(|w|{ w.bits(keyword) }); },
                3 => unsafe{ self.p.AES.key_3_q.write(|w|{ w.bits(keyword) }); },
                4 => unsafe{ self.p.AES.key_4_q.write(|w|{ w.bits(keyword) }); },
                5 => unsafe{ self.p.AES.key_5_q.write(|w|{ w.bits(keyword) }); },
                6 => unsafe{ self.p.AES.key_6_q.write(|w|{ w.bits(keyword) }); },
                7 => unsafe{ self.p.AES.key_7_q.write(|w|{ w.bits(keyword) }); },
                _ => assert!(false),
            }
            index += 1;
        }

        while index < 8 {
            self.report(0x3000_3000 + index as u32);
            match index {
                0 => unsafe{ self.p.AES.key_0_q.write(|w|{ w.bits(0) }); },
                1 => unsafe{ self.p.AES.key_1_q.write(|w|{ w.bits(0) }); },
                2 => unsafe{ self.p.AES.key_2_q.write(|w|{ w.bits(0) }); },
                3 => unsafe{ self.p.AES.key_3_q.write(|w|{ w.bits(0) }); },
                4 => unsafe{ self.p.AES.key_4_q.write(|w|{ w.bits(0) }); },
                5 => unsafe{ self.p.AES.key_5_q.write(|w|{ w.bits(0) }); },
                6 => unsafe{ self.p.AES.key_6_q.write(|w|{ w.bits(0) }); },
                7 => unsafe{ self.p.AES.key_7_q.write(|w|{ w.bits(0) }); },
                _ => assert!(false),
            }
            index += 1;
        }
        true
    }

    pub fn iv_put(&mut self, iv: &mut &[u8] ) -> bool {
        for (reg, chunk) in iv.chunks(4).enumerate() {
            let mut temp: [u8; 4] = Default::default();
            temp.copy_from_slice(chunk);
            let ivword: u32 = u32::from_le_bytes(temp);
            match reg {
                0 => unsafe{ self.p.AES.iv_0.write(|w|{ w.bits(ivword)}); },
                1 => unsafe{ self.p.AES.iv_1.write(|w|{ w.bits(ivword)}); },
                2 => unsafe{ self.p.AES.iv_2.write(|w|{ w.bits(ivword)}); },
                3 => unsafe{ self.p.AES.iv_3.write(|w|{ w.bits(ivword)}); },
                _ => assert!(false),
            }
        }
        true
    }

    pub fn report(&mut self, _report: u32) {
        // unsafe {self.p.SIMSTATUS.report.write(|w|{w.bits(report)});} // this is only used in simulation
    }

    pub fn aes_init(&mut self, mode: AesCtrl) -> bool {
        unsafe {
            self.p.AES.ctrl.write(|w|{ w.bits(mode.bits()) });
        }
        true
    }

    pub fn aes_reset(&mut self) {
        unsafe{ self.p.AES.trigger.write(|w|{ w.bits((AesTrigger::KEY_CLEAR | AesTrigger::IV_CLEAR | AesTrigger::DATA_IN_CLEAR | AesTrigger::DATA_OUT_CLEAR | AesTrigger::PRNG_RESEED).bits())}); }
    }

    pub fn aes_data_put(&mut self, data: &mut &[u8]) -> bool {
        self.report(0x2000_0000);
        for( reg, chunk) in data.chunks(4).enumerate() {
            self.report(0x2100_0000 + reg as u32);
            let mut temp: [u8; 4] = Default::default();
            temp.copy_from_slice(chunk);
            let dword: u32 = u32::from_le_bytes(temp);
            match reg {
                0 => unsafe{ self.p.AES.datain_0.write(|w|{ w.bits(dword)}); },
                1 => unsafe{ self.p.AES.datain_1.write(|w|{ w.bits(dword)}); },
                2 => unsafe{ self.p.AES.datain_2.write(|w|{ w.bits(dword)}); },
                3 => unsafe{ self.p.AES.datain_3.write(|w|{ w.bits(dword)}); },
                _ => assert!(false),
            }
        }
        true
    }

    pub fn aes_manual_trigger(&mut self) -> bool {
        self.p.AES.trigger.write(|w|{ w.start().set_bit()});
        true
    }

    pub fn aes_data_put_wait(&mut self, data: &mut &[u8]) -> bool {
        while !self.p.AES.status.read().input_ready().bit() {}

        self.aes_data_put(data)
    }

    pub fn aes_data_get(&mut self, data: &mut [u8; 16]) -> bool {
        for reg in 0..4 {
            let dword: u32 = match reg {
                0 => self.p.AES.dataout_0.read().bits(),
                1 => self.p.AES.dataout_1.read().bits(),
                2 => self.p.AES.dataout_2.read().bits(),
                3 => self.p.AES.dataout_3.read().bits(),
                _ => 0,
            };
            let bytes = dword.to_le_bytes();
            data[0 + reg * 4] = bytes[0];
            data[1 + reg * 4] = bytes[1];
            data[2 + reg * 4] = bytes[2];
            data[3 + reg * 4] = bytes[3];
        }
        true
    }

    pub fn aes_data_get_wait(&mut self, data: &mut [u8; 16]) -> bool {
        while !self.p.AES.status.read().output_valid().bit() {}

        self.aes_data_get(data)
    }

    pub fn aes_idle(&mut self) -> bool {
        self.p.AES.status.read().idle().bit()
    }

    pub fn aes_clear(&mut self) -> bool {
        while !self.aes_idle() {}

        // disable autostart
        unsafe{ self.p.AES.ctrl.write(|w|{ w.bits((AesCtrl::MANUAL_OP | self.control).bits())}); }

        // clear internal key and output registers
        unsafe{ self.p.AES.trigger.write(|w|{ w.bits((AesTrigger::KEY_CLEAR |
            AesTrigger::IV_CLEAR |
            AesTrigger::DATA_IN_CLEAR |
            AesTrigger::DATA_OUT_CLEAR).bits())}); }

        // wait for output not valid, and input ready
        while !(!self.p.AES.status.read().output_valid().bit() && self.p.AES.status.read().input_ready().bit()) {}

        true
    }
}