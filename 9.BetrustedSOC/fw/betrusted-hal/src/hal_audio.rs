use bitflags::*;
use volatile::Volatile;
use crate::hal_i2c::i2c_controller;
use crate::hal_time::delay_ms;
use crate::hal_time::get_time_ms;
use crate::hal_xadc::*;

pub const LM49352_I2C_ADR: u8 = 0b001_1010;
pub const AUDIO_FIFODEPTH: usize = 256; // consider replacing this with the property read from the Rx stat register

pub const LM49352_PMC_SETUP: u8 = 0x00;
bitflags! {
    pub struct PmcSetup: u8 {
        const CHIP_ENABLE      = 0b0000_0001;
        const PLL_ENABLE       = 0b0000_0010;
        const PLL_P2_ENABLE    = 0b0000_0100;
        const OSC_ENABLE       = 0b0000_1000;
        const MCLK_FORCEON     = 0b0001_0000;
        const PORT1CLK_FORCEON = 0b0010_0000;
        const PORT2CLK_FORCEON = 0b0100_0000;
        const CHIP_ACTIVE      = 0b1000_0000;
    }
}

pub const LM49352_PMC_CLOCKS: u8 = 0x01;
bitflags! {
    pub struct PmcClocks: u8 {
        const PMC_CLK_SEL   = 0b0000_0011;
        const PMC_CLK_SEL_MCLK   = 0b00;
        const PMC_CLK_SEL_300KHZ = 0b01;
        const PMC_CLK_SEL_DAC    = 0b10;
        const PMC_CLK_SEL_ADC    = 0b11;
    }
}

pub const LM49352_PMC_CLK_DIV: u8 = 0x02;
bitflags! {
    pub struct PmcClkDiv: u8 {
        const PMC_CLK_DIV_R = 0b1111_1111;
    }
}

pub const LM49352_PLL_CLK_SOURCE: u8 = 0x03;
bitflags! {
    pub struct PllClkSource: u8 {
        const PLL_CLK_SEL      = 0b0000_0011;
        const PLL_CLK_SEL_MCLK      = 0b00;
        const PLL_CLK_SEL_PORT1_CLK = 0b01;
        const PLL_CLK_SEL_PORT2_CLK = 0b10;
    }
}

pub const LM49352_PLL_M: u8 = 0x04;
bitflags! {
    pub struct PllM: u8 {
        const PLL_M = 0b0111_1111;
    }
}

pub const LM49352_PLL_N: u8 = 0x05;
bitflags! {
    pub struct PllN: u8 {
        const PLL_N = 0b1111_1111;
    }
}

pub const LM49352_PLL_N_MOD: u8 = 0x06;
bitflags! {
    pub struct PllNMod: u8 {
        const PLL_N_MOD = 0b0001_1111;
        const PLL_P1    = 0b0010_0000;
        const PLL_P2    = 0b0100_0000;
    }
}

pub const LM49352_PLL_P1: u8 = 0x07;
bitflags! {
    pub struct PllP1: u8 {
        const PLL_P1 = 0b1111_1111;
    }
}

pub const LM49352_PLL_P2: u8 = 0x08;
bitflags! {
    pub struct PllP2: u8 {
        const PLL_P2 = 0b1111_1111;
    }
}

pub const LM49352_ADC_BASIC: u8 = 0x20;
bitflags! {
    pub struct AdcBasic: u8 {
        const MONO         = 0b0000_0001;
        const OSR          = 0b0000_0010;
        const MUTE_L       = 0b0000_0100;
        const MUTE_R       = 0b0000_1000;
        const ADC_CLK_SEL  = 0b0111_0000;
        const ADC_DSP_ONLY = 0b1000_0000;

        const ADC_CLK_SEL_MCLK = 0b0000_0000;
        const ADC_CLK_SEL_P1RX = 0b0001_0000;
        const ADC_CLK_SEL_P2RX = 0b0010_0000;
        const ADC_CLK_SEL_PLL1 = 0b0011_0000;
        const ADC_CLK_SEL_PLL2 = 0b0100_0000;
    }
}

pub const LM49352_ADC_CLK_DIV: u8 = 0x21;
// full-width, no bitmask needed

pub const LM49352_DAC_BASIC: u8 = 0x30;
bitflags! {
    pub struct DacBasic: u8 {
        const MODE            = 0b0000_0011;
        const MODE_125        = 0b0000_0000;
        const MODE_128        = 0b0000_0001;
        const MODE_64         = 0b0000_0010;
        const MUTE_L          = 0b0000_0100;
        const MUTE_R          = 0b0000_1000;
        const DAC_CLK_SEL     = 0b0111_0000;
        const DAC_CLK_SEL_MCLK= 0b0000_0000;
        const DAC_CLK_SEL_P1RX= 0b0001_0000;
        const DAC_CLK_SEL_P2RX= 0b0010_0000;
        const DAC_CLK_SEL_PLL1= 0b0011_0000;
        const DAC_CLK_SEL_PLL2= 0b0100_0000;
    }
}

pub const LM49352_DAC_CLK_DIV: u8 = 0x31;
// full-width, no bitmask needed


pub const LM49352_BASIC_SETUP_P1: u8 = 0x50;
pub const LM49352_BASIC_SETUP_P2: u8 = 0x60;
bitflags! {
    pub struct BasicSetup: u8 {
        const STEREO            = 0b0000_0001;
        const RX_ENABLE         = 0b0000_0010;
        const TX_ENABLE         = 0b0000_0100;
        const CLOCK_MS          = 0b0000_1000;
        const SYNC_MS           = 0b0001_0000;
        const CLOCK_PHASE       = 0b0010_0000;
        const STEREO_SYNC_PHASE = 0b0100_0000;
        const SYNC_INVERT       = 0b1000_0000;
    }
}

pub const LM49352_CLK_GEN1_P1: u8 = 0x51;
pub const LM49352_CLK_GEN1_P2: u8 = 0x61;
bitflags! {
    pub struct ClkGen1: u8 {
        const HALF_CYCLE_CLK_DIV = 0b0011_1111;
        const CLOCK_SEL          = 0b0100_0000;
        const ADC_SOURCE_CLK     = 0b0100_0000;
        const DAC_SOURCE_CLK     = 0b0000_0000;
    }
}

pub const LM49352_CLK_GEN2_P1: u8 = 0x52;
pub const LM49352_CLK_GEN2_P2: u8 = 0x62;
bitflags! {
    pub struct ClkGen2: u8 {
        const SYNTH_NUM          = 0b0000_0111;
        const SYNTH_DENOM        = 0b0000_1000;
    }
}

pub const LM49352_SYNC_GEN_P1: u8 = 0x53;
pub const LM49352_SYNC_GEN_P2: u8 = 0x63;
bitflags! {
    pub struct SyncGen: u8 {
        const SYNC_RATE_STEREO_32  = 0b0000_0010;  // just the most expected modes programmed here
        const SYNC_RATE_STEREO_48  = 0b0000_0101;
        const SYNC_RATE_STEREO_64  = 0b0000_0111;
        const SYNC_WIDTH_MONO      = 0b0011_1000;
    }
}

pub const LM49352_DATA_WIDTH_P1: u8 = 0x54;
pub const LM49352_DATA_WIDTH_P2: u8 = 0x64;
bitflags! {
    pub struct DataWidth: u8 {
        const RX_WIDTH_8         = 0b0000_0111; // just the most common widths, there are more available
        const RX_WIDTH_12        = 0b0000_0110;
        const RX_WIDTH_16        = 0b0000_0011;
        const TX_WIDTH_8         = 0b0011_1000;
        const TX_WIDTH_12        = 0b0011_0000;
        const TX_WIDTH_16        = 0b0001_1000;
        const TX_EXTRA_BITS_0    = 0b0000_0000;
        const TX_EXTRA_BITS_1    = 0b0100_0000;
        const TX_EXTRA_BITS_Z    = 0b1000_0000;
    }
}

pub const LM49352_RX_MODE_P1: u8 = 0x55;
pub const LM49352_RX_MODE_P2: u8 = 0x65;
pub const LM49352_TX_MODE_P1: u8 = 0x56;
pub const LM49352_TX_MODE_P2: u8 = 0x66;
bitflags! {
    pub struct TxRxMode: u8 {
        const MSB_JUSTIFIED          = 0b0000_0000;
        const LSB_JUSTIFIED          = 0b0000_0001;
        const MSB_POSITION           = 0b0011_1110;
        const MSB_POSITION_0         = 0b0000_0000;
        const MSB_POSITION_1         = 0b0000_0010;
        const COMPAND                = 0b0100_0000;
        const MU_LAW                 = 0b0000_0000;
        const A_LAW                  = 0b1000_0000;
    }
}

pub const LM49352_GPIO1: u8 = 0xE0;
bitflags! {
    pub struct Gpio1: u8 {
        const GPIO_MODE            = 0b0011_1111;
        const GPIO_MODE_DISABLED   = 0b0000_0000;
        const GPIO_MODE_HP_SENSE   = 0b0000_0110;
        const GPIO_MODE_HP_SENSE_B = 0b0000_0111;
        const GPIO_TX              = 0b0100_0000;
        const GPIO_RX              = 0b1000_0000;
    }
}

pub const LM49352_HP_SENSE: u8 = 0x1B;
bitflags! {
    pub struct HpSense: u8 {
        const HP_SENSE        = 0b0000_0001;
        const HP_SENSE_D      = 0b0000_0010;
        const HP_SENSE_AUX    = 0b0000_0100;
        const HP_SENSE_AUX_D  = 0b0000_1000;
    }
}

pub const LM49352_AMIX_CLASSD: u8 = 0x10;
pub const LM49352_AMIX_HP_L: u8 = 0x11;
pub const LM49352_AMIX_HP_R: u8 = 0x12;
pub const LM49352_AMIX_AUX: u8 = 0x13;
pub const LM49352_AMIX_ADC: u8 = 0x15;
bitflags! {
    pub struct Amix: u8 {
        const DACR      = 0b0000_0001;
        const DACL      = 0b0000_0010;
        const MONO      = 0b0001_0000;
        const AUX       = 0b0010_0000;
        // aux only
        const MIC_AUX   = 0b0000_0100;
        // adc only
        const MIC_ADC_L = 0b0000_1000;
        const MIC_ADC_R = 0b0000_0100;
    }
}

pub const LM49352_OUTPUT_OPTIONS: u8 = 0x14;
bitflags! {
    pub struct OutputOptions: u8 {
        const LR_HP_LEVEL_0DB    = 0b0000_0000;
        const LR_HP_LEVEL_N1P5DB = 0b0000_0010;
        const LR_HP_LEVEL_N3DB   = 0b0000_0100;
        const LR_HP_LEVEL_N6DB   = 0b0000_0110;
        const LR_HP_LEVEL_N9DB   = 0b0000_1000;
        const LR_HP_LEVEL_N12DB  = 0b0000_1010;
        const LR_HP_LEVEL_N15DB  = 0b0000_1100;
        const LR_HP_LEVEL_N18DB  = 0b0000_1110;

        const AUX_0DB            = 0b0000_0000;
        const AUX_N6DB           = 0b0001_0000;

        const AUX_EARPEACE       = 0b0000_0000;
        const AUX_LINEOUT        = 0b0010_0000;

        const LS_LEVEL_0DB       = 0b0000_0000;
        const LS_LEVEL_4DB       = 0b0100_0000;
        const LS_LEVEL_8DB       = 0b1100_0000;
        const LS_LEVEL_12DB      = 0b1100_0000;
    }
}

pub const LM49352_MIC_INPUT: u8 = 0x16;
bitflags! {
    pub struct MicInput: u8 {
        const MIC_LEVEL_6DB     = 0b0000_0000;  // zero value
        const MIC_LEVEL_2DB_LSB = 0b0000_0001;  // scale factor for each LSB
        const MIC_LEVEL_MAX     = 0b0000_1111;  // also the bit mask

        const MIC_SE            = 0b0001_0000;  // set single-end mode
        const MIC_MUTE          = 0b0010_0000;
    }
}

pub const LM49352_DMIX_PORT1: u8 = 0x42;
pub const LM49352_DMIX_PORT2: u8 = 0x43;
bitflags! {
    pub struct DmixPort: u8 {
        const L_SEL_NONE       = 0b0000_0000;
        const L_SEL_ADC_L      = 0b0000_0001;
        const L_SEL_PORTLOOP_L = 0b0000_0010;
        const L_SEL_INTERP_L   = 0b0000_0011;

        const R_SEL_NONE       = 0b0000_0000;
        const R_SEL_ADC_R      = 0b0000_0100;
        const R_SEL_PORTLOOP_R = 0b0000_1000;
        const R_SEL_INTERP_R   = 0b0000_1100;

        const LR_SWAP          = 0b0001_0000;
        const MONO             = 0b0010_0000; // left channel becomes (L+R)/2
    }
}

pub const LM49352_DMIX_DAC: u8 = 0x44;
bitflags! {
    pub struct DmixDac: u8 {
        const PORT1_L    = 0b0000_0001;
        const PORT2_L    = 0b0000_0010;
        const ADC_L      = 0b0000_0100;
        const PORT1_R    = 0b0000_1000;
        const PORT2_R    = 0b0001_0000;
        const ADC_R      = 0b0010_0000;
        const LR_SWAP    = 0b0100_0001;
    }
}


pub struct BtAudio {
    p: betrusted_pac::Peripherals,
}

/// hal_audio is a quick testing API for the audio interface
///
///

const I2C_TIMEOUT: u32 = 5;
impl BtAudio {

    pub fn new() -> Self {
        unsafe {
            BtAudio {
                p: betrusted_pac::Peripherals::steal(),
            }
        }
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
        let mut txbuf: [u8; 2];

        // power management controller setup
        // power on the chip
        txbuf = [LM49352_PMC_SETUP, (PmcSetup::CHIP_ENABLE | PmcSetup::PLL_ENABLE).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // select MCLK source for the power management controller
        txbuf = [LM49352_PMC_CLOCKS, (PmcClocks::PMC_CLK_SEL_MCLK).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // select divider for PMC - divide by 40.5 (0x50) ~300kHz
        txbuf = [LM49352_PMC_CLK_DIV, 0x50];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // PLL setup
        // setup PLL clock source - MCLK
        txbuf = [LM49352_PLL_CLK_SOURCE, PllClkSource::PLL_CLK_SEL_MCLK.bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // setup M to 2.5
        txbuf = [LM49352_PLL_M, 4]; // 2.5 * 2 -1 = 4
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // setup N to 32
        txbuf = [LM49352_PLL_N, 32];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // setup N_MOD to 0
        txbuf = [LM49352_PLL_N_MOD, 0];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // setup P to 12.5
        txbuf = [LM49352_PLL_P1, 24]; // 12.5 * 2 -1 = 24
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_PLL_P2, 24]; // mirror setting here to create a sane value, but P2 is not used
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // setup ADC clock basics
        txbuf = [LM49352_ADC_BASIC, (AdcBasic::OSR | AdcBasic::ADC_CLK_SEL_PLL1).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // local divider = 12
        txbuf = [LM49352_ADC_CLK_DIV, 23]; // 12 * 2 - 1 = 23
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // not setting ADC_MIXER; leaves default at 0dB levels

        // setup DAC clock basics
        txbuf = [LM49352_DAC_BASIC, (DacBasic::MODE_128 | DacBasic::DAC_CLK_SEL_PLL1).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // local divider = 12
        txbuf = [LM49352_DAC_CLK_DIV, 23]; // 12 * 2 - 1 = 23
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
    }

    /// audio_ports() sets up the digital port bitwidths, modes, and syncs
    ///
    /// From the hardware i2s block as implemented on betrusted-soc:
    /// 16 bits per sample, 24 bit word width, stero, master mode, left-justified, MSB first
    pub fn audio_ports(&mut self) {
        let mut txbuf: [u8; 2];

        // P1 is a duplex audio port
        txbuf = [LM49352_BASIC_SETUP_P1, (BasicSetup::STEREO | BasicSetup::RX_ENABLE | BasicSetup::TX_ENABLE |
                                          BasicSetup::CLOCK_MS | BasicSetup::SYNC_MS).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // Revision: P2 is strictly unused, could eliminate P2 setup code
        // P2 is the speaker-only port, only receives data from betrusted
        // txbuf = [LM49352_BASIC_SETUP_P2, (BasicSetup::STEREO | BasicSetup::RX_ENABLE |
        //                                  BasicSetup::CLOCK_MS | BasicSetup::SYNC_MS).bits()];
        // i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // input clock at points "A" and "B" in figure 57 (page 34) of the datasheet is 12.288 MHz
        // this needs to be divided down to the basic MCLK rate of:
        // 24 bits/word * 2 channels * 8000 samples/s = 384_000
        // 12_288_000 / 384_000 = 32
        txbuf = [LM49352_CLK_GEN1_P1, 63]; // divide by 32, using the DAC clock as the source
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_CLK_GEN1_P2, 63]; // divide by 32, using the DAC clock as the source
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        txbuf = [LM49352_CLK_GEN2_P1, 0]; // 1:1 fractional (disable fractional division)
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_CLK_GEN2_P2, 0]; // 1:1 fractional (disable fractional division)
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // set a sync rate of 48 clock cycles stereo to get 24 bits/word
        txbuf = [LM49352_SYNC_GEN_P1, (SyncGen::SYNC_RATE_STEREO_48).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_SYNC_GEN_P2, (SyncGen::SYNC_RATE_STEREO_48).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // set bit widths to 16 bits
        txbuf = [LM49352_DATA_WIDTH_P1, (DataWidth::RX_WIDTH_16 | DataWidth::TX_WIDTH_16 | DataWidth::TX_EXTRA_BITS_0).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_DATA_WIDTH_P2, (DataWidth::RX_WIDTH_16 | DataWidth::TX_WIDTH_16 | DataWidth::TX_EXTRA_BITS_0).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // MSB justified, no offset
        txbuf = [LM49352_RX_MODE_P1, (TxRxMode::MSB_JUSTIFIED | TxRxMode::MSB_POSITION_0).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_RX_MODE_P2, (TxRxMode::MSB_JUSTIFIED | TxRxMode::MSB_POSITION_0).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_TX_MODE_P1, (TxRxMode::MSB_JUSTIFIED | TxRxMode::MSB_POSITION_0).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        txbuf = [LM49352_TX_MODE_P2, (TxRxMode::MSB_JUSTIFIED | TxRxMode::MSB_POSITION_0).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // enable hp sensing on port2_sdo (gpio1)
        txbuf = [LM49352_GPIO1, (Gpio1::GPIO_MODE_HP_SENSE).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
        // automatically power on the headphone amplifier, but leave the speaker on if the headphone is in
        // use HpSense::HP_SENSE_D if you want to have the speaker turn off autmatically when the headphone is inserted!
        txbuf = [LM49352_HP_SENSE, (HpSense::HP_SENSE).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
    }

    /// set up the audio mixer to sane defaults
    pub fn audio_mixer(&mut self) {
        let mut txbuf: [u8; 2];

        // route DAC L+R to class-d speaker amp
        txbuf = [LM49352_AMIX_CLASSD, (Amix::DACR | Amix::DACL).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // route DAC L to HP L
        txbuf = [LM49352_AMIX_HP_L, (Amix::DACL).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // route DAC R to HP R
        txbuf = [LM49352_AMIX_HP_R, (Amix::DACR).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // route mic to ADC L+R
        txbuf = [LM49352_AMIX_ADC, (Amix::MIC_ADC_L | Amix::MIC_ADC_R).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // set output options
        txbuf = [LM49352_OUTPUT_OPTIONS, (OutputOptions::LR_HP_LEVEL_N6DB | OutputOptions::LS_LEVEL_4DB).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // crank up the gain on the microphone
        txbuf = [LM49352_MIC_INPUT, (MicInput::MIC_LEVEL_MAX).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // route ADC to port 1
        txbuf = [LM49352_DMIX_PORT1, (DmixPort::L_SEL_ADC_L | DmixPort::R_SEL_ADC_R).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);

        // port 1 to DAC
        txbuf = [LM49352_DMIX_DAC, (DmixDac::PORT1_L | DmixDac::PORT1_R).bits()];
        i2c_controller(&self.p, LM49352_I2C_ADR, Some(&txbuf), None, I2C_TIMEOUT);
    }

    /// set up the betrusted-side signals
    pub fn audio_i2s_start(&mut self) {
        const AUDIO_FIFO: *mut u32 = 0xE000_0000 as *mut u32;

        self.p.AUDIO.tx_ctl.write(|w| {w.reset().bit(true)} );
        self.p.AUDIO.rx_ctl.write(|w| {w.reset().bit(true)} );

        // let the FIFOs reset
        delay_ms(&self.p, 2);

        for _ in 0..(AUDIO_FIFODEPTH * 2) {
            unsafe{ (*AUDIO_FIFO) = 0; } // prefill TX fifo with zero's
        }

        // this sets everything running
        self.p.AUDIO.rx_ctl.write(|w| {w.enable().bit(true)} );
        self.p.AUDIO.tx_ctl.write(|w| {w.enable().bit(true)} );
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

    pub fn audio_loopback_xadc(&mut self, xadc: &mut BtXadc) {
        let audio_ptr = 0xE000_0000 as *mut u32;
        let volatile_audio = audio_ptr as *mut Volatile<u32>;

        let mut sample: u32;

        xadc.audio_only();
        let start: u32 = get_time_ms(&self.p);
        while get_time_ms(&self.p) - start < 10000 {
            if self.p.AUDIO.tx_stat.read().free().bit() {
                sample = xadc.audio() as u32;
                unsafe { (*volatile_audio).write(sample | (sample << 16)); }
            }
        }
        // revert xadc settings
        xadc.noise_only(false);
    }
}