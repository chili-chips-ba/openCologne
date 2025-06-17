use bitflags::*;
use volatile::Volatile;
use crate::hal_i2c::i2c_controller;
use crate::hal_time::delay_ms;

pub const TLV320AIC3100_I2C_ADR: u8 = 0b0011_000;
pub const AUDIO_FIFODEPTH: usize = 256; // consider replacing this with the property read from the Rx stat register

pub struct BtAudio {
    p: betrusted_pac::Peripherals,
}

/// hal_audio is a quick testing API for the audio interface

const I2C_TIMEOUT: u32 = 5;
impl BtAudio {

    pub fn new() -> Self {
        unsafe {
            BtAudio {
                p: betrusted_pac::Peripherals::steal(),
            }
        }
    }

    fn w(&mut self, adr: u8, data: &[u8]) {
        let mut tx = vec![adr];
        tx.extend_from_slice(&data);
        i2c_controller(&self.p, TLV320AIC3100_I2C_ADR, Some(&tx), None, I2C_TIMEOUT);
    }
    #[allow(dead_code)]
    fn r(&mut self, adr: u8, data: &mut[u8]) {
        let tx: [u8; 1] = [adr];
        i2c_controller(&self.p, TLV320AIC3100_I2C_ADR, Some(&tx), Some(&mut data[..]), I2C_TIMEOUT);
    }

    pub fn get_headset_code(&mut self) -> u8 {
        self.w(0, &[0]);
        let mut code: [u8; 1] = [0; 1];
        self.r(67, &mut code);
        code[0]
    }

    pub fn get_dacflag_code(&mut self) -> u8 {
        self.w(0, &[0]);
        let mut code: [u8; 1] = [0; 1];
        self.r(37, &mut code);
        code[0]
    }

    pub fn get_hp_status(&mut self) -> u8 {
        self.w(0, &[1]);
        let mut code: [u8; 1] = [0; 1];
        self.r(31, &mut code);
        code[0]
    }

    pub fn get_i2s_config(&mut self) -> [u8; 4] {
        self.w(0, &[0]);
        let mut code: [u8; 4] = [0; 4];
        self.r(27, &mut code);
        code
    }

    /// audio_clocks() sets up the default clocks for 8kHz sampling rate, assuming a 12MHz MCLK input
    ///
    /// fIN = 12 MHz
    /// M = 2.5
    /// N = 32   (PLL freq = 153.6MHz)
    /// N_MOD = 0
    /// P = 12.5
    /// fOUT = 12_288_000 Hz
    ///
    /// sample rate = 8_000
    /// oversampling rate (OSR) = 128
    /// local divider = 12
    /// 8_000 * 128 * 12 = 12_288_000 Hz
    ///
    pub fn audio_clocks(&mut self) {
        self.w(0, &[0]);  // select page 0
        self.w(1, &[1]);  // software reset
        delay_ms(&self.p, 2); // reset happens in 1 ms; +1 ms due to timing jitter uncertainty

        self.w(0, &[0]);  // select page 0

        // select PLL_CLKIN = MCLK; CODEC_CLKIN = PLL_CLK
        self.w(4, &[0b0000_0011]);

        // fs = 8kHz
        // PLL_CLKIN = 12MHz
        // PLLP = 1, PLLR = 1, PLLJ = 7, PLLD = 1680, NDAC = *12*, MDAC = 7, DOSR = 128, MADC = 2 , NADC = *42*
        // ^^ from page 68 of datasheet, fs=48kHz/12MHz clkin line, with *bold* items multiplied by 6 to get to 8kHz
        self.w(5, &[
            0b1001_0001,  // P, R = 1, 1 and pll powered up
            7,            // PLLJ = 7
            ((1680 >> 8) & 0xFF) as u8, // D MSB of 1680
            (1680 & 0xFF) as u8,        // D LSB of 1680
            ]);

        self.w(11, &[
            0x80 | 12,  // NADC = 12 (set to 2 for 48kHz)
            0x80 | 7,   // MDAC = 7
            0,   // DOSR = MSB of 128
            128, // DOSR = LSB of 128
        ]);

        self.w(18, &[
            0x80 | 42,  // NADC = 42 (set to 7 for 48kHz)
            0x80 | 2,   // MADC = 2
            128, // AOSR = 128
        ]);
    }

    /// audio_ports() sets up the digital port bitwidths, modes, and syncs
    ///
    /// From the hardware i2s block as implemented on betrusted-soc:
    /// 16 bits per sample, 32 bit word width, stero, master mode, left-justified, MSB first
    pub fn audio_ports(&mut self) {
        self.w(0, &[0]); // select page 0

        // 32 bits/word * 2 channels * 8000 samples/s = 512_000 = BCLK
        // pick off of DAC_MOD_CLK = 1.024MHz
        self.w(27, &[
            0b00_00_1_1_0_1, // I2S standard, 16 bits per sample, BCLK output, WCLK output, DOUT is Hi-Z when unused
            0b0,           // no offset on left justification
            0b0000_0_1_01, // BDIV_CLKIN = DAC_MOD_CLK, BCLK active even when powered down
            0b1000_0010    // BCLK_N_VAL = 2, N divider is powered up
            ]);

        // "word width" (WCLK) timing is implied based on the DAC fs computed
        // at the end of the clock tree, and WCLK simply toggles every other sample, so there is no
        // explicit WCLK divider

        // turn on headset detection
        self.w(0, &[0]); // select page 0
        // detection enabled, 64ms glitch reject, 8ms button glitch reject
        self.w(67, &[0b1_00_010_01] );

        // use auto volume control -- DO WE WANT THIS???
        //self.w(116, &[0b1_1_01_0_001] );
    }

    pub fn audio_loopback(&mut self, do_loop:bool) {
        self.w(0, &[1]); // select page 1

        // DAC routing -- route DAC to mixer channel, don't loopback MIC
        if do_loop {
            self.w(35, &[0b01_0_0_01_0_0]);
        } else {
            self.w(35, &[0b01_0_1_01_1_0]);
        }
    }

    /// set up the audio mixer to sane defaults
    pub fn audio_mixer(&mut self) {
        ////////// SETUP DAC -- this is on page 0
        self.w(0, &[0]); // select page 0
        // DAC setup - both channels on, soft-stepping enabled, left-to-left, right-to-right
        self.w(63, &[0b1_1_01_01_00]);
        // DAC volume - neither DACs muted, independent volume controls
        self.w(64, &[0b0000_0_0_00]);
        // DAC left volume control
        self.w(65, &[0b1]); // +0.5dB
        // DAC right volume control
        self.w(66, &[0b1]); // +0.5dB

        ///////// VOLUME, PGA CONTROLS -- PAGE 1
        self.w(0, &[1]); // select page 1

        // DAC routing -- route DAC to mixer channel, don't loopback MIC
        self.w(35, &[0b01_0_0_01_0_0]);
        //self.w(35, &[0b01_0_1_01_1_0]);

        // internal volume control
        self.w(36, &[
            0b1_001_0010, // HPL channel control on, -9dB
            0b1_001_0010, // HPR channel control on, -9dB
            0b1_000_1100, // SPK control on, -6dB
            ]);

        // driver PGA control
        self.w(40, &[
            0b0_0000_111, // HPL driver PGA = 0dB, not muted, all gains applied
            0b0_0000_111, // HPR driver PGA = 0dB, not muted, all gains applied
            0b000_00_1_0_1, // SPK gain = 6 dB, driver not muted, all gains applied
            ]);

            // HP driver control -- 16us short circuit debounce, best DAC performance, HPL/HPR as headphone drivers
        self.w(44, &[0b010_11_0_0_0]);

        // MICBIAS control -- micbias always on, set to 2.5V
        self.w(46, &[0b0_000_1_0_10]);

        // MIC PGA
        self.w(47, &[60]); // target 30dB, code is (target * 2)dB

        // fine-gain input selection for P_terminal -- only MIC1RP selected, with RIN=10kohm
        self.w(48, &[0b00_01_00_00]);
        // M_terminal select -- CM selected with RIN = 10k
        self.w(49, &[0b01_00_00_00]);
        // CM settincgs - MIC1LP/MIC1LM connected to CM; MIC1RP is floating
        self.w(50, &[0b1_0_1_00000]);

        // don't change power control bits on SC
        self.w(30, &[0b1_1]);

        // class D amp is powered on
        self.w(32, &[0b1_0_00011_0]);

        // HPL on, HPR on, OCM = 1.65V, limit on short circuit
        self.w(31, &[0b1_1_0_10_1_0_0]);

        ////////// SETUP ADC & AGC -- this is on page 0
        self.w(0, &[0]); // select page 0
        // ADC setup -- ADC powered on, digital MIC not used
        self.w(81, &[0b1_0_00_0_0_00]);
        // ADC digital volume conrol -- not muted, 0dB gain
        self.w(82, &[0b0_000_0000]);
        // ADC digital volume control coarse adjust
        self.w(83, &[0b0]); // +0.0 dB

        self.w(86, &[
            0b1_011_0000, // AGC enabled, target level = -12dB
            0b00_10001_0, // hysteresis 1dB, noise threshold = -((value-1)*2 + 30), 17 => -64dB
            100, // max gain = code/2 dB
            0b_00101_000, // attack time = 0b_acode_mul = (acode*32*mul)/Fs
            0b_01101_000, // decay time  = 0b_dcode_mul = (dcode*32*mul)/Fs
            0x01, // noise debounce time = code*4 / fs
            0x01, // signal debounce time = code*4 / fs
            ]);

    }

    pub fn reset_fifos(&mut self) {
        unsafe {
        self.p.AUDIO.rx_ctl.write(|w| {w.bits(0)} );
        self.p.AUDIO.tx_ctl.write(|w| {w.bits(0)} );

        self.p.AUDIO.tx_ctl.write(|w| {w.reset().bit(true)} );
        self.p.AUDIO.rx_ctl.write(|w| {w.reset().bit(true)} );

        delay_ms(&self.p, 1);

        self.p.AUDIO.rx_ctl.write(|w| {w.bits(0)} );
        self.p.AUDIO.tx_ctl.write(|w| {w.bits(0)} );
        }
    }

    /// set up the betrusted-side signals
    pub fn audio_i2s_start(&mut self) {
        let audio_ptr = 0xE000_0000 as *mut u32;
        let volatile_audio = audio_ptr as *mut Volatile<u32>;

        self.p.AUDIO.tx_ctl.write(|w| {w.reset().bit(true).enable().bit(false)} );
        self.p.AUDIO.rx_ctl.write(|w| {w.reset().bit(true).enable().bit(false)} );

        // let the FIFOs reset
        delay_ms(&self.p, 1);

        for _ in 0..256 { // 512 is the absolute total size of the fifo, fifodepth is just a high-water-mark off of this
            unsafe { (*volatile_audio).write(0); }  // prefill TX fifo with zero's
        }

        // this sets everything running
        self.p.AUDIO.tx_ctl.write(|w| {w.enable().bit(true).reset().bit(false)} );
        self.p.AUDIO.rx_ctl.write(|w| {w.enable().bit(true).reset().bit(false)} );
    }

    pub fn audio_i2s_stop(&mut self) {
        self.p.AUDIO.rx_ctl.write(|w| {w.enable().bit(false)} );
        self.p.AUDIO.tx_ctl.write(|w| {w.enable().bit(false)} );
    }

    /// this is a testing-only function which does a double-buffered audio loopback
    pub fn audio_loopback_poll(&mut self, buf_a: &mut [u32; AUDIO_FIFODEPTH], buf_b: &mut [u32; AUDIO_FIFODEPTH], toggle: bool) -> bool {
        let audio_ptr = 0xE000_0000 as *mut u32;
        let volatile_audio = audio_ptr as *mut Volatile<u32>;

        if self.p.AUDIO.tx_stat.read().free().bit() & self.p.AUDIO.rx_stat.read().dataready().bit() {
            for i in 0..AUDIO_FIFODEPTH {
                if toggle {
                    unsafe{ buf_a[i] = (*volatile_audio).read(); }
                    unsafe { (*volatile_audio).write(buf_b[i]); }
                } else {
                    unsafe{ buf_b[i] = (*volatile_audio).read(); }
                    unsafe { (*volatile_audio).write(buf_a[i]); }
                }
            }
/*
            for i in 0..AUDIO_FIFODEPTH {
                if toggle {
                    unsafe{ buf_a[i] = (*volatile_audio).read(); }
                } else {
                    unsafe{ buf_b[i] = (*volatile_audio).read(); }
                }
            }
            for i in 0..AUDIO_FIFODEPTH {
                if toggle {
                    unsafe { (*volatile_audio).write(buf_b[i]); }
                } else {
                    unsafe { (*volatile_audio).write(buf_a[i]); }
                }
            }
            */
            // wait for the done flags to clear; with an interrupt-driven system, this isn't necessary
            while self.p.AUDIO.tx_stat.read().free().bit() & self.p.AUDIO.rx_stat.read().dataready().bit()
            {}
            // indicate we had an audio event
            true
        } else {
            false
        }
    }

    /// this is a testing-only function which does a double-buffered audio loopback
    pub fn audio_loopback_quick(&mut self) -> bool {
        let audio_ptr = 0xE000_0000 as *mut u32;
        let volatile_audio = audio_ptr as *mut Volatile<u32>;

        let mut sample: u32;

        if self.p.AUDIO.tx_stat.read().free().bit() & self.p.AUDIO.rx_stat.read().dataready().bit() {
            for _ in 0..AUDIO_FIFODEPTH {
                    unsafe{ sample = (*volatile_audio).read(); }
                    unsafe { (*volatile_audio).write(sample); }
            }
            // wait for the done flags to clear; with an interrupt-driven system, this isn't necessary
            while self.p.AUDIO.tx_stat.read().free().bit() & self.p.AUDIO.rx_stat.read().dataready().bit()
            {}
            // indicate we had an audio event
            true
        } else {
            false
        }
    }

}

/// SCRAP this and try this again later.

pub const PG0_PAGE_SELECT: u8 = 0x00;
pub const PG0_RESET: u8       = 0x01;
bitflags! { pub struct Reset: u8 { const RESET = 0b1; } }
pub const PG0_OT_FLAG: u8     = 0x03;
bitflags! { pub struct OverTemp: u8 { const OT = 0b10; } }

pub const PG0_CLKMUX: u8      = 0x04;
bitflags! {
    pub struct ClkMux: u8 {
        const CODEC_CLKIN_MCLK  = 0b0000_0000;
        const CODEC_CLKIN_BCLK  = 0b0000_0001;
        const CODEC_CLKIN_GPIO1 = 0b0000_0010;
        const CODEC_CLKIN_PLL   = 0b0000_0011;
        const PLL_CLKIN_MCLK    = 0b0000_0000;
        const PLL_CLKIN_BCLK    = 0b0000_0100;
        const PLL_CLKIN_GPIO1   = 0b0000_1000;
        const PLL_CLKIN_DIN     = 0b0000_1100;
    }
}

pub const PG0_PLL_P_R: u8     = 0x05;
bitflags! {
    pub struct PllPR: u8 {
        const PLL_R_MASK = 0b0000_1111;
        const PLL_R_POS  = 0b0000_0001;
        const PLL_P_MASK = 0b0111_0000;
        const PLL_P_POS  = 0b0001_0000;  // note: use by multiplying this by the value to put into P
        const PLL_PWRUP  = 0b1000_0000;
    }
}

pub const PG0_PLL_J: u8       = 0x06;
bitflags! {
    pub struct PllJ: u8 {
        const PLL_J_MASK = 0b0111_1111;
        const PLL_J_POS  = 0b0000_0001;
    }
}

/// NOTE: PG0_PLL_D_MSB must immediately follow a write to PG0_PLL_D_LSB
pub const PG0_PLL_D_MSB: u8   = 0x07;
bitflags! {
    pub struct PllDMsb: u8 {
        const PLL_D_MSB_MASK = 0b0011_1111;
        const PLL_D_MSB_POS  = 0b0000_0001;
    }
}

/// NOTE: PG0_PLL_D_LSB must immediately preceed a write to PG0_PLL_D_MSB
pub const PG0_PLL_D_LSB: u8   = 0x08;
bitflags! {
    pub struct PllDLsb: u8 {
        const PLL_D_LSB_MASK = 0b1111_1111;
        const PLL_D_LSB_POS  = 0b0000_0001;
    }
}