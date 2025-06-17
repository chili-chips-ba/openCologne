
pub enum XadcRegs {
    Temperature = 0x0,
    VccInt = 0x1,
    VccAux = 0x2,
    Dedicated = 0x3,
    VrefP = 4,
    VrefN = 5,
    VccBram = 6,

    Vaux0 = 16,
    Vaux1 = 17,
    Vaux2 = 18,
    Vaux3 = 19,
    Vaux4 = 20,
    Vaux5 = 21,
    Vaux6 = 22,
    Vaux7 = 23,
    Vaux8 = 24,
    Vaux9 = 25,
    Vaux10 = 26,
    Vaux11 = 27,
    Vaux12 = 28,
    Vaux13 = 29,
    Vaux14 = 30,
    Vaux15 = 31,

    // useful to detect glitches
    MaxTemp = 0x20,
    MaxVccInt = 0x21,
    MaxVccAux = 0x22,
    MaxVccBram = 0x23,
    MinTemp = 0x24,
    MinVccInt = 0x25,
    MinVccAux = 0x26,
    MinVccBram = 0x27,

    Flag = 0x3F,

    Config0 = 0x40,
    Config1 = 0x41,
    Config2 = 0x42,
    Seq0 = 0x48,
    Seq1 = 0x49,
    SeqAvg0 = 0x4A,
    SeqAvg1 = 0x4B,
    SeqMode0 = 0x4C,
    SeqMode1 = 0x4D,
    SeqSettling0 = 0x4E,
    SeqSettling1 = 0x4F,

    // auto-alarm thresholds. Alarms allow real time monitoring of supplies without processor intervention.
    AlarmTempUpper = 0x50,
    AlarmVccIntUpper = 0x51,
    AlarmVccAuxUpper = 0x52,
    AlarmOtLimit = 0x53,
    AlarmTempLower = 0x54,
    AlarmVccIntLower = 0x55,
    AlarmVccAuxLower = 0x56,
    AlarmOtReset = 0x57,
    AlarmVccBramUpper = 0x58,

    AlarmVccBramLower = 0x5C,
}

#[allow(dead_code)]
fn xadc_write(p: &betrusted_pac::Peripherals, adr: XadcRegs, data: u16) {
    unsafe{ p.TRNG.xadc_drp_adr.write(|w| w.bits(adr as u32)); }
    unsafe{ p.TRNG.xadc_drp_dat_w.write(|w| w.bits((data & 0xffff) as u32)); }
    unsafe{ p.TRNG.xadc_drp_write.write(|w| w.bits(1)); } // commit the write

    while p.TRNG.xadc_drp_drdy.read().bits() == 0 {} // wait for the write to complete
}

#[allow(dead_code)]
fn xadc_read(p: &betrusted_pac::Peripherals, adr: XadcRegs) -> u16 {
    let ret: u16;
    unsafe{ p.TRNG.xadc_drp_adr.write(|w| w.bits(adr as u32)); }
    unsafe{ p.TRNG.xadc_drp_read.write(|w| w.bits(1)); } // trigger the read

    while p.TRNG.xadc_drp_drdy.read().bits() == 0 {} // wait for the read to complete

    ret = p.TRNG.xadc_drp_dat_r.read().bits() as u16;

    ret
}

#[allow(dead_code)]
fn xadc_enable(p: &betrusted_pac::Peripherals, enable: bool) {
    if enable {
        unsafe{ p.TRNG.xadc_drp_enable.write(|w| w.bits(1)); }
    } else {
        unsafe{ p.TRNG.xadc_drp_enable.write(|w| w.bits(0)); }
    }
}

pub enum XadcSeq {
    Default_ = 0,
    SinglePass = 1,
    Continuous = 2,
    SingleChannel = 3,
    Simultaneous = 4,
    Independent = 8,
}

pub enum XadcPower {
    AllOn = 0,
    AdcbOff = 2,
    AllOff = 3,
}

// channel coding for the control register
pub enum XadcChannel {
    Temperature = 0,
    VccInt = 1,
    VccAux = 2,
    Dedicated = 3,
    VrefP = 4,
    VrefN = 5,
    VccBram = 6,
    Calibrate = 8,
    Vaux0 = 16,
    Vaux1 = 17,
    Vaux2 = 18,
    Vaux3 = 19,
    Vaux4 = 20,
    Vaux5 = 21,
    Vaux6 = 22,
    Vaux7 = 23,
    Vaux8 = 24,
    Vaux9 = 25,
    Vaux10 = 26,
    Vaux11 = 27,
    Vaux12 = 28,
    Vaux13 = 29,
    Vaux14 = 30,
    Vaux15 = 31,
}

// channel coding for the sequence bank of registers
// this is as a bitmask, so that these can be OR'd together
pub enum XadcSeq0Mask {
    Calibration = 0x001,
    Temperature = 0x100,
    VccInt = 0x200,
    VccAux = 0x400,
    Dedicated = 0x800,
    VrefP = 0x1000,
    VrefN = 0x2000,
    VccBram = 0x4000,
}
#[derive(Copy, Clone)]
pub enum XadcSeq1Mask {
    Vaux0 = 0x0001,
    Vaux1 = 0x0002,
    Vaux2 = 0x0004,
    Vaux3 = 0x0008,
    Vaux4 = 0x0010,
    Vaux5 = 0x0020,
    Vaux6 = 0x0040,
    Vaux7 = 0x0080,
    Vaux8 = 0x0100,
    Vaux9 = 0x0200,
    Vaux10 = 0x0400,
    Vaux11 = 0x0800,
    Vaux12 = 0x1000,
    Vaux13 = 0x2000,
    Vaux14 = 0x4000,
    Vaux15 = 0x8000,
}

pub enum XadcFilter {
    None = 0,
    Avg16 = 1,
    Avg64 = 2,
    Avg256 = 3,
}

pub enum XadcCalBitMask {
    AdcOffset = 1,
    AdcOffsetAndGain = 2,
    SupplyOffset = 3,
    SupplyOffsetAndGain = 4,
}

pub enum BtXadcMode {
    RoundRobin, // round robin sampling of active ports
    Stream,     // streaming of just one channel -- TODO
}

pub struct BtXadc {
    p: betrusted_pac::Peripherals,
    mode: BtXadcMode,
}

impl BtXadc {
    pub fn new() -> Self {
        #[allow(non_snake_case)]
        let NOISE0: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let NOISE1: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let CC1: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let CC2: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let VBUS: XadcSeq1Mask;
        if cfg!(feature = "evt") {
            NOISE0 = XadcSeq1Mask::Vaux0;
            NOISE1 = XadcSeq1Mask::Vaux8;
            CC1 = XadcSeq1Mask::Vaux10;
            CC2 = XadcSeq1Mask::Vaux11;
            VBUS = XadcSeq1Mask::Vaux9;
        } else {
            NOISE0 = XadcSeq1Mask::Vaux12;
            NOISE1 = XadcSeq1Mask::Vaux4;
            CC1 = XadcSeq1Mask::Vaux14;
            CC2 = XadcSeq1Mask::Vaux15;
            VBUS = XadcSeq1Mask::Vaux6;
        }

        let ret: BtXadc;
        unsafe {
            ret = BtXadc {
                p: betrusted_pac::Peripherals::steal(),
                mode: BtXadcMode::RoundRobin,
            };
        }
        xadc_enable(&ret.p, true);

        // 0x0EF0 is constant -- disables alarms not present on this gchip, enables calibration, enables all other alarms
        // set to default before updating the sequence table
        xadc_write(&ret.p, XadcRegs::Config1, ((XadcSeq::Default_ as u16) << 12) | 0x0EF0 );

        // do a calibration
        ret.p.TRNG.xadc_eoc.read().bits(); // clear eoc
        xadc_write(&ret.p, XadcRegs::Config0, 0x8000 | (XadcFilter::Avg16 as u16) << 12 | (XadcChannel::Calibrate as u16));
        xadc_write(&ret.p, XadcRegs::Config2, 0x0400 | (XadcPower::AdcbOff as u16) << 4);
        xadc_write(&ret.p, XadcRegs::Config1, ((XadcSeq::SinglePass as u16) << 12) | 0x0EF0 );

        while ret.p.TRNG.xadc_eoc.read().bits() == 0 {}

        // setup the sequencing registers
        xadc_write(&ret.p, XadcRegs::Seq0, XadcSeq0Mask::VccBram as u16 | XadcSeq0Mask::Dedicated as u16 |
            XadcSeq0Mask::VccAux as u16  | XadcSeq0Mask::VccInt as u16 |
            XadcSeq0Mask::Temperature as u16 | XadcSeq0Mask::Calibration as u16 );
        xadc_write(&ret.p, XadcRegs::Seq1, NOISE0 as u16 | NOISE1 as u16 |
            CC1    as u16 | CC2 as u16 |
            VBUS   as u16 );

        xadc_write(&ret.p, XadcRegs::SeqAvg0,
            XadcSeq0Mask::VccBram as u16 | XadcSeq0Mask::Dedicated as u16 |
            XadcSeq0Mask::VccAux as u16  | XadcSeq0Mask::VccInt as u16 |
            XadcSeq0Mask::Temperature as u16);
        xadc_write(&ret.p, XadcRegs::SeqAvg1,
            CC1    as u16 | CC2 as u16 |
            VBUS   as u16 );
        // set the VP/VN input to differential input
        xadc_write(&ret.p, XadcRegs::SeqMode0, XadcSeq0Mask::Dedicated as u16);

        xadc_write(&ret.p, XadcRegs::SeqSettling0, 0);
        xadc_write(&ret.p, XadcRegs::SeqSettling1, 0);

        // once sequence is set, move to continuous mode. XADC is reset upon changing sequence mode
        // 0x0EF0 is constant -- disables alarms not present on this chip, enables calibration, enables all other alarms
        xadc_write(&ret.p, XadcRegs::Config1, ((XadcSeq::Continuous as u16) << 12) | 0x0EF0 );
        // 0x8000 is constant -- disables averaging of cal bit
        xadc_write(&ret.p, XadcRegs::Config0, 0x8000 | (XadcFilter::None as u16) << 12);
        // 0x0400 is constant -- sets DCLK to SYSCLK/4 = 25MHz
        xadc_write(&ret.p, XadcRegs::Config2, 0x0400 | (XadcPower::AdcbOff as u16) << 4);

        ret
    }

    pub fn noise_only(&mut self, noise_on: bool) {
        #[allow(non_snake_case)]
        let NOISE0: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let NOISE1: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let CC1: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let CC2: XadcSeq1Mask;
        #[allow(non_snake_case)]
        let VBUS: XadcSeq1Mask;
        if cfg!(feature = "evt") {
            NOISE0 = XadcSeq1Mask::Vaux0;
            NOISE1 = XadcSeq1Mask::Vaux8;
            CC1 = XadcSeq1Mask::Vaux10;
            CC2 = XadcSeq1Mask::Vaux11;
            VBUS = XadcSeq1Mask::Vaux9;
        } else {
            NOISE0 = XadcSeq1Mask::Vaux12;
            NOISE1 = XadcSeq1Mask::Vaux4;
            CC1 = XadcSeq1Mask::Vaux14;
            CC2 = XadcSeq1Mask::Vaux15;
            VBUS = XadcSeq1Mask::Vaux6;
        }

        // 0x0EF0 is constant -- disables alarms not present on this chip, enables calibration, enables all other alarms
        // set to default before updating the sequence table
        xadc_write(&self.p, XadcRegs::Config1, ((XadcSeq::Default_ as u16) << 12) | 0x0EF0 );

        // setup the sequencing registers
        if noise_on {
            xadc_write(&self.p, XadcRegs::Seq0, 0 );
            xadc_write(&self.p, XadcRegs::Seq1, NOISE0 as u16 | NOISE1 as u16 );
            // disable all averaging
            xadc_write(&self.p, XadcRegs::SeqAvg0, 0);
            xadc_write(&self.p, XadcRegs::SeqAvg1, 0);

            // once sequence is set, move to continuous mode. XADC is reset upon changing sequence mode
            // 0x0EF0 is constant -- disables alarms not present on this chip, enables calibration, enables all other alarms
            xadc_write(&self.p, XadcRegs::Config1, ((XadcSeq::Continuous as u16) << 12) | 0x0EF0 );
            // 0x8000 is constant -- disables averaging of cal bit
            xadc_write(&self.p, XadcRegs::Config0, 0x8000 | (XadcFilter::None as u16) << 12); // don't use averaging when sampling noise!
            // 0x0400 is constant -- sets DCLK to SYSCLK/4 = 25MHz
            xadc_write(&self.p, XadcRegs::Config2, 0x0400 | (XadcPower::AdcbOff as u16) << 4);
        } else {
            xadc_write(&self.p, XadcRegs::Seq0, XadcSeq0Mask::VccBram as u16 | XadcSeq0Mask::Dedicated as u16 |
                XadcSeq0Mask::VccAux as u16  | XadcSeq0Mask::VccInt as u16 |
                XadcSeq0Mask::Temperature as u16 | XadcSeq0Mask::Calibration as u16 );
            xadc_write(&self.p, XadcRegs::Seq1, NOISE0 as u16 | NOISE1 as u16 |
                CC1 as u16 | CC2 as u16 |
                VBUS   as u16 );

            xadc_write(&self.p, XadcRegs::SeqAvg0,
                XadcSeq0Mask::VccBram as u16 | XadcSeq0Mask::Dedicated as u16 |
                XadcSeq0Mask::VccAux as u16  | XadcSeq0Mask::VccInt as u16 |
                XadcSeq0Mask::Temperature as u16);
            xadc_write(&self.p, XadcRegs::SeqAvg1,
                CC1    as u16 | CC2 as u16 |
                VBUS   as u16 );
            // set the VP/VN input to differential input
            xadc_write(&self.p, XadcRegs::SeqMode0, XadcSeq0Mask::Dedicated as u16);

            xadc_write(&self.p, XadcRegs::SeqSettling0, 0);
            xadc_write(&self.p, XadcRegs::SeqSettling1, 0);

            // once sequence is set, move to continuous mode. XADC is reset upon changing sequence mode
            // 0x0EF0 is constant -- disables alarms not present on this chip, enables calibration, enables all other alarms
            xadc_write(&self.p, XadcRegs::Config1, ((XadcSeq::Continuous as u16) << 12) | 0x0EF0 );
            // 0x8000 is constant -- disables averaging of cal bit
            xadc_write(&self.p, XadcRegs::Config0, 0x8000 | (XadcFilter::None as u16) << 12);
            // 0x0400 is constant -- sets DCLK to SYSCLK/4 = 25MHz
            xadc_write(&self.p, XadcRegs::Config2, 0x0400 | (XadcPower::AdcbOff as u16) << 4);
        }
    }

    pub fn audio_only(&mut self) {
        const AUDIO: XadcSeq0Mask = XadcSeq0Mask::Dedicated;

        // 0x0EF0 is constant -- disables alarms not present on this chip, enables calibration, enables all other alarms
        // set to default before updating the sequence table
        xadc_write(&self.p, XadcRegs::Config1, ((XadcSeq::Default_ as u16) << 12) | 0x0EF0 );

        // setup the sequencing registers
        xadc_write(&self.p, XadcRegs::Seq0, AUDIO as u16 );
        xadc_write(&self.p, XadcRegs::Seq1, 0 );

        // once sequence is set, move to continuous mode. XADC is reset upon changing sequence mode
        // 0x0EF0 is constant -- disables alarms not present on this chip, enables calibration, enables all other alarms
        xadc_write(&self.p, XadcRegs::Config1, ((XadcSeq::Continuous as u16) << 12) | 0x0EF0 );
        // 0x8000 is constant -- disables averaging of cal bit
        xadc_write(&self.p, XadcRegs::Config0, 0x8000 | (XadcFilter::Avg16 as u16) << 12);
        // 0x0400 is constant -- sets DCLK to SYSCLK/4 = 25MHz
        xadc_write(&self.p, XadcRegs::Config2, 0x0400 | (XadcPower::AdcbOff as u16) << 4);
    }

    pub fn audio(&mut self) -> u16 {
        xadc_read(&self.p, XadcRegs::Dedicated)
    }

    pub fn set_mode(&mut self, mode: BtXadcMode) {
        self.mode = mode;
    }

    /// blocks until the latest sequence finishes, guarantees the values have been updated
    pub fn wait_update(&mut self) {
        while self.p.TRNG.xadc_eos.read().bits() == 0 {}
    }

    pub fn noise0(&mut self) -> u16 {
        if cfg!(feature = "evt") {
            xadc_read(&self.p, XadcRegs::Vaux0) >> 4
        } else {
            xadc_read(&self.p, XadcRegs::Vaux12) >> 4
        }
    }
    pub fn noise1(&mut self) -> u16 {
        if cfg!(feature = "evt") {
            xadc_read(&self.p, XadcRegs::Vaux8) >> 4
        } else {
            xadc_read(&self.p, XadcRegs::Vaux4) >> 4
        }
    }

    pub fn vbus_mv(&mut self) -> u16 {
        // voltage is 0.0485 * VBUS
        // ADC code is 1/4096 of a volt
        let code: u32;
        if cfg!(feature = "evt") {
            code = xadc_read(&self.p, XadcRegs::Vaux9) as u32 >> 4;
        } else {
            code = xadc_read(&self.p, XadcRegs::Vaux6) as u32 >> 4;
        }

        // e.g., code of 993 = 5V will return 4997mV
        ((code * 5033) / 1000) as u16
    }
    pub fn cc1_mv(&mut self) -> u16 {
        let code: u32;
        if cfg!(feature = "evt") {
            code = xadc_read(&self.p, XadcRegs::Vaux10) as u32 >> 4;
        } else {
            code = xadc_read(&self.p, XadcRegs::Vaux14) as u32 >> 4;
        }

        // voltage is 1.0 * CC level (safely saturates due to HW protection above 1.0V)
        // ADC code is 1/4096 of a volt
        (code * 1000 / 4096) as u16
    }
    pub fn cc2_mv(&mut self) -> u16 {
        let code: u32;
        if cfg!(feature = "evt") {
            code = xadc_read(&self.p, XadcRegs::Vaux11) as u32 >> 4;
        } else {
            code = xadc_read(&self.p, XadcRegs::Vaux15) as u32 >> 4;
        }

        // voltage is 1.0 * CC level (safely saturates due to HW protection above 1.0V)
        // ADC code is 1/4096 of a volt
        (code * 1000 / 4096) as u16
    }
    pub fn vccint(&mut self) -> u16 { xadc_read(&self.p, XadcRegs::VccInt) >> 4 }
    pub fn vccaux(&mut self) -> u16 { xadc_read(&self.p, XadcRegs::VccAux) >> 4 }
    pub fn vccbram(&mut self) -> u16 { xadc_read(&self.p, XadcRegs::VccBram) >> 4 }
    pub fn temp(&mut self) -> u16 { xadc_read(&self.p, XadcRegs::Temperature) >> 4 }
    pub fn audio_sample(&mut self) -> u16 { xadc_read(&self.p, XadcRegs::Dedicated) >> 4 }

    pub fn flags(&mut self) -> u16 { xadc_read(&self.p, XadcRegs::Flag) }
}