from migen import *
from migen.genlib.cdc import MultiReg
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex.gen import LiteXModule
from litex.soc.interconnect.csr import CSRStorage, CSRStatus, CSRField
from litex.soc.interconnect import stream
from litex.soc.cores.prbs import PRBSTX, PRBSRX
from litex.soc.cores.code_8b10b import Encoder, Decoder

class SerDesGM(LiteXModule):
    def __init__(self, sys_clk_freq, refclk_freq=125e6, linerate=1.25e9,
                 tx_polarity=0, rx_polarity=0,
                 internal_loopback=False):
        # We use a fixed 20-bit data path (two 10-bit 8b/10b words) at half the line rate.
        data_width = 20
        self.nwords = data_width // 10

        self.tx_enable = Signal(reset=1)
        self.rx_enable = Signal(reset=1)
        self.tx_ready  = Signal()
        self.rx_ready  = Signal()
        self.tx_idle   = Signal()
        self.loopback  = Signal(reset=1 if internal_loopback else 0)  # Loopback mode (fixed at init)

        self.tx_prbs_config = Signal(2)    # PRBS pattern for TX (00: off, 01: PRBS7, 10: PRBS15, 11: PRBS31)
        self.rx_prbs_config = Signal(2)    # PRBS pattern for RX (must match TX)
        self.rx_prbs_pause  = Signal()
        self.rx_prbs_errors = Signal(32)

        self.txoutclk = Signal()
        self.rxoutclk = Signal()

        self.cd_tx      = ClockDomain()
        self.cd_tx_half = ClockDomain(reset_less=True)
        self.cd_rx      = ClockDomain()

        self.tx_clk_freq = linerate / data_width
        self.rx_clk_freq = linerate / data_width

        self.encoder  = ClockDomainsRenamer("tx")(Encoder(self.nwords, True))
        self.decoders = [ClockDomainsRenamer("rx")(Decoder(True)) for _ in range(self.nwords)]

        self.tx_prbs = ClockDomainsRenamer("tx")(PRBSTX(data_width, reverse=True))
        self.rx_prbs = ClockDomainsRenamer("rx")(PRBSRX(data_width, reverse=True))

        tx_data = Signal(data_width)
        rx_data = Signal(data_width)
        tx_bus  = Signal(24)
        rx_bus  = Signal(24)
        
        
        
        _tx_prbs_config = Signal(2)
        _rx_prbs_config = Signal(2)
        _rx_prbs_pause  = Signal()
        self.specials += [
            MultiReg(self.tx_prbs_config, _tx_prbs_config, "tx"),
            MultiReg(self.rx_prbs_config, _rx_prbs_config, "rx"),
            MultiReg(self.rx_prbs_pause,  _rx_prbs_pause,  "rx")
        ]

        _prbs_errors = Signal(32)
        self.specials += MultiReg(self.rx_prbs.errors, _prbs_errors, "sys")
        self.comb += self.rx_prbs_errors.eq(_prbs_errors)

        tx_reset      = Signal()
        rx_reset      = Signal()
        tx_reset_done = Signal()
        rx_reset_done = Signal()
        adpll_reset   = Signal(reset=1)
        tx_detect_rx_done     = Signal()
        tx_detect_rx_present  = Signal()
        rx_buf_err            = Signal()
        tx_buf_err            = Signal()
        rx_prbs_err_flag      = Signal()    # you’ll have to OR–reduce your 32‑bit error count into 1 bit

        tx_half_toggle = Signal(reset=0)
        tx_half_clk    = Signal()
        self.rx_reset_done_n        = rx_reset_done
        self.tx_reset_done_n        = tx_reset_done
        self.tx_detect_rx_done_n    = tx_detect_rx_done
        self.tx_detect_rx_present_n = tx_detect_rx_present
        self.rx_buf_err_n           = rx_buf_err
        self.tx_buf_err_n           = tx_buf_err
        self.comb += rx_prbs_err_flag.eq(self.rx_prbs_errors != 0)
        self.rx_prbs_err_n = rx_prbs_err_flag
        self.specials += [
            Instance("CC_BUFG", i_I=self.txoutclk, o_O=self.cd_tx.clk),      # 125 MHz TX domain
            Instance("CC_BUFG", i_I=self.rxoutclk, o_O=self.cd_rx.clk)       # 62.5 MHz RX domain
        ]

        # Generate 62.5 MHz TX half clock by dividing txoutclk by 2
        self.sync.tx += tx_half_toggle.eq(~tx_half_toggle)
        self.comb += tx_half_clk.eq(tx_half_toggle)
        self.specials += Instance("CC_BUFG", i_I=tx_half_clk, o_O=self.cd_tx_half.clk)

        self.comb += [
            tx_reset.eq(~self.tx_enable | adpll_reset),  # hold TX in reset if disabled or PLL not ready
            rx_reset.eq(~self.rx_enable)                 # hold RX in reset if disabled
        ]
        self.comb += [
            self.tx_prbs.config.eq(_tx_prbs_config),
            self.rx_prbs.config.eq(_rx_prbs_config),
            self.rx_prbs.pause.eq(_rx_prbs_pause)
        ]
        # ** TX Data Path Selection **
        # Feed 8b/10b encoder output into PRBS generator (the PRBS block will pass data through if PRBS is disabled)
        self.comb += self.tx_prbs.i.eq(Cat(*[self.encoder.output[i] for i in range(self.nwords)]))
        # Select transmitted data: PRBS output if PRBS mode is enabled, otherwise 8b/10b encoded data
        self.comb += If(self.tx_prbs_config != 0,
                        tx_data.eq(self.tx_prbs.o)
                    ).Else(
                        tx_data.eq(Cat(*[self.encoder.output[i] for i in range(self.nwords)]))
                    )
        # Map 20-bit tx_data into SERDES TX bus (16 data bits + 4 control bits for disparity/K)
        # Lower 10-bit word: data[0:8] -> TX_DATA bits 0-7, tx_data[8] -> dispval, tx_data[9] -> dispmode
        # Upper 10-bit word: data[10:18] -> TX_DATA bits 8-15, tx_data[18] -> dispval, tx_data[19] -> dispmode
        self.comb += [
            tx_bus[0:8].eq(tx_data[0:8]),     # lower byte of data
            tx_bus[8].eq(0), tx_bus[9].eq(0), # we set all K/disp bits to 0 by default (assuming data already disparity-corrected)
            tx_bus[10:18].eq(tx_data[10:18]), # upper byte of data
            tx_bus[18:24].eq(0)               # upper word K/disp bits also 0
        ]
        # ** RX Data Path **
        # Map SERDES RX bus back to 20-bit data (inverse of TX mapping)
        self.comb += [
            rx_data[0:8].eq(rx_bus[0:8]),     # lower 8 data bits
            rx_data[8].eq(rx_bus[8]),         # (not used in fabric, would indicate K or disparity error)
            rx_data[9].eq(rx_bus[9]),         # (not used in fabric)
            rx_data[10:18].eq(rx_bus[10:18]), # upper 8 data bits
            rx_data[18].eq(rx_bus[18]),
            rx_data[19].eq(rx_bus[19])
        ]
        # Feed RX data into PRBS checker
        self.comb += self.rx_prbs.i.eq(rx_data)
        # Feed RX data into 8b/10b decoders (each decoder handles one 10-bit word)
        for i in range(self.nwords):
            self.sync.rx += self.decoders[i].input.eq(rx_data[10*i:10*(i+1)])
        # ** Reset and Initialization Sequencing **
        pll_reset_cycles = int((30000 * sys_clk_freq) // 1e9)  # ~30 µs at sys_clk_freq
        if pll_reset_cycles < 1: pll_reset_cycles = 1
        reset_counter = Signal(max=pll_reset_cycles+1, reset=0)
        cdr_lock_time = int((sys_clk_freq * 50e3) // linerate)  # ~50,000 UI (bit periods) at sys_clk
        if cdr_lock_time < 1: cdr_lock_time = 1
        cdr_lock_counter = Signal(max=int(cdr_lock_time)+1, reset=0)
        cdr_locked = Signal(reset=0)
        # System clock domain FSM for resets
        self.sync += [
            # ADPLL reset release after `pll_reset_cycles` ticks
            If(reset_counter < pll_reset_cycles,
               reset_counter.eq(reset_counter + 1),
               adpll_reset.eq(1)
            ).Else(
               adpll_reset.eq(0)
            ),
            # CDR lock timer (starts when RX reset is not asserted and PLL is running)
            If(rx_reset | adpll_reset,
               cdr_locked.eq(0),
               cdr_lock_counter.eq(0)
            ).Elif(cdr_lock_counter < cdr_lock_time,
               cdr_lock_counter.eq(cdr_lock_counter + 1)
            ).Else(
               cdr_locked.eq(1)
            )
        ]
        self.comb += [
            self.rx_ready.eq(cdr_locked),
            self.tx_ready.eq(tx_reset_done & cdr_locked)
        ]
        self.specials += AsyncResetSynchronizer(self.cd_rx, ~cdr_locked)
        self.specials += AsyncResetSynchronizer(self.cd_tx, ~tx_reset_done)

        # Select ADPLL parameters for the given reference clock frequency
        adpll_config = {
            100e6: {'fcntrl': 0x0A, 'main_divsel': 0x1B, 'out_divsel': 3},  # for 100 MHz ref
            125e6: {'fcntrl': 0x1A, 'main_divsel': 0x1A, 'out_divsel': 3}   # for 125 MHz ref
        }
        assert refclk_freq in adpll_config, "Unsupported refclk_freq (use 100e6 or 125e6)."
        cfg = adpll_config[refclk_freq]

        serdes_params = dict(
            # Global SERDES configuration
            p_SERDES_ENABLE    = 1,
            p_SERDES_AUTO_INIT = 0,
            p_SERDES_TESTMODE  = 1,
            # ADPLL (PLL) configuration
            p_PLL_EN_ADPLL_CTRL = 1,
            p_PLL_CONFIG_SEL    = 1, #0 :internal, 1: regfile
            p_PLL_REF_SEL       = 1,   # 1 = LVDS reference (expects diff ref clock, or internal calibration if none)
            p_PLL_REF_BYPASS    = 0,
            p_PLL_REF_RTERM     = 1,
            p_PLL_FCNTRL        = cfg['fcntrl'],
            p_PLL_MAIN_DIVSEL   = cfg['main_divsel'],
            p_PLL_OUT_DIVSEL    = cfg['out_divsel'],
            p_PLL_CI            = 3,
            p_PLL_CP            = 80,
            p_PLL_AO            = 0,
            p_PLL_SCAP          = 0,
            p_PLL_FILTER_SHIFT  = 2,
            p_PLL_SAR_LIMIT     = 2,
            p_PLL_FT            = 512,
            p_PLL_OPEN_LOOP     = 0,
            p_PLL_SCAP_AUTO_CAL = 1,
            p_PLL_SET_OP_LOCK  = 0,
            p_PLL_ENFORCE_LOCK  = 0,
            p_PLL_DISABLE_LOCK  = 0,
            p_PLL_LOCK_WINDOW   = 1, 
            p_PLL_FAST_LOCK     = 1, 
            p_PLL_SYNC_BYPASS   = 0,
            p_PLL_PFD_SELECT    = 0,
            p_PLL_REF_RTERM     = 1,
            #TX
            p_TX_SEL_PRE = 0,
            p_TX_SEL_POST = 0,
            p_TX_AMP = 0XF,

            p_TX_BRANCH_EN_PRE  = 0,
            p_TX_BRANCH_EN_MAIN = 0x3F,
            p_TX_BRANCH_EN_POST = 0,
            p_TX_TAIL_CASCODE   = 0x4,
            p_TX_DC_ENABLE      = 0x3F,
            p_TX_DC_OFFSET      = 0x8, # note: set to 8
            p_TX_CM_RAISE       = 0x0,
            p_TX_CM_THRESHOLD_0 = 0xE,
            p_TX_CM_THRESHOLD_1 = 0x10,
            p_TX_SEL_PRE_EI     = 0x0,
            p_TX_SEL_POST_EI    = 0x0,
            p_TX_AMP_EI         = 0xF,
            p_TX_BRANCH_EN_PRE_EI  = 0x0,
            p_TX_BRANCH_EN_MAIN_EI = 0x3F,
            p_TX_BRANCH_EN_POST_EI = 0x0,
            p_TX_TAIL_CASCODE_EI   = 0x4,
            p_TX_DC_ENABLE_EI      = 0x3F,
            p_TX_DC_OFFSET_EI      = 0x0,
            p_TX_CM_RAISE_EI       = 0x0,
            p_TX_CM_THRESHOLD_0_EI = 0xE,
            p_TX_CM_THRESHOLD_1_EI = 0x10,
            p_TX_SEL_PRE_RXDET     = 0x0,
            p_TX_SEL_POST_RXDET    = 0x0,
            p_TX_AMP_RXDET         = 0xF,
            p_TX_BRANCH_EN_PRE_RXDET = 0x0,
            p_TX_BRANCH_EN_MAIN_RXDET = 0x3F,
            p_TX_BRANCH_EN_POST_RXDET = 0x0,
            p_TX_TAIL_CASCODE_RXDET   = 0x4,
            p_TX_DC_ENABLE_RXDET      =0x3F,
            p_TX_DC_OFFSET_RXDET      = 0x0,
            p_TX_CM_RAISE_RXDET       = 0x0,
            p_TX_CM_THRESHOLD_0_RXDET = 0xE,
            p_TX_CM_THRESHOLD_1_RXDET = 0x10,
            p_TX_CALIB_EN  = 0x0,
            p_TX_CALIB_OVR = 0x0,
            p_TX_CALIB_VAL = 0x0,
            p_TX_CM_REG_KI = 0x80,
            p_TX_CM_SAR_EN = 0x0,
            p_TX_CM_REG_EN = 0x1,

            p_TX_PCS_RESET_OVR=0x0,
            p_TX_PCS_RESET=0x0,
            p_TX_PMA_RESET_OVR=0x0,
            p_TX_PMA_RESET=0x0,
            p_TX_RESET_OVR=0x0,
            p_TX_RESET=0x0,
            p_TX_LOOPBACK_OVR=0x0,
            p_TX_DETECT_RX_OVR=0x0,
            p_TX_DETECT_RX=0x0,
            p_TX_DATA_OVR=0x0,
            p_TX_DATA_CNT=0x0,
            p_TX_DATA_VALID=0x0,
            # ADPLL BISC (Background calibration for PLL)
            p_PLL_BISC_MODE         = 5,
            p_PLL_BISC_TIMER_MAX    = 15,
            p_PLL_BISC_OPT_DET_IND  = 0,
            p_PLL_BISC_PFD_SEL      = 0,
            p_PLL_BISC_DLY_DIR      = 0,
            p_PLL_BISC_COR_DLY      = 1,
            p_PLL_BISC_CAL_SIGN     = 0,
            p_PLL_BISC_CAL_AUTO     = 1,
            p_PLL_BISC_CP_MIN       = 6,
            p_PLL_BISC_CP_MAX       = 30,
            p_PLL_BISC_CP_START     = 6,
            p_PLL_BISC_DLY_PFD_MON_REF = 0,
            p_PLL_BISC_DLY_PFD_MON_DIV = 2,
            # 8b/10b settings (bypass internal encoder/decoder)
            p_TX_8B10B_EN_OVR = 0, p_TX_8B10B_EN = 0,
            p_RX_8B10B_EN_OVR = 0, p_RX_8B10B_EN = 0,
            p_RX_8B10B_BYPASS = 0x00,
            # Data path width selection: 0 = 20-bit (1:2 gearbox)
            p_TX_DATAPATH_SEL = 0,
            p_RX_DATAPATH_SEL = 0,
            # Reset timings
            p_TX_PMA_RESET_TIME = 3, p_TX_PCS_RESET_TIME = 3,
            p_RX_PMA_RESET_TIME = 3, p_RX_PCS_RESET_TIME = 3,
            p_RX_RESET_TIMER_PRESC = 0, p_RX_RESET_DONE_GATE = 0,
            # Electrical idle / power-down (TX/RX always on in this test)
            p_TX_POWER_DOWN_OVR = 0, p_TX_POWER_DOWN_N = 1,
            p_RX_POWER_DOWN_OVR = 0, p_RX_POWER_DOWN_N = 1,
            p_TX_ELEC_IDLE_OVR  = 0, p_TX_ELEC_IDLE = 0,
            # Polarity control
            p_TX_POLARITY_OVR = 0, p_TX_POLARITY = 0,
            p_RX_POLARITY_OVR = 0, p_RX_POLARITY = 0,
            # Comma alignment
            p_RX_COMMA_DETECT_EN_OVR = 0,
            p_RX_COMMA_DETECT_EN     = 0,
            p_RX_ALIGN_COMMA_WORD    = 3,
            p_RX_ALIGN_COMMA_ENABLE  = 0x3FF,
            p_RX_ALIGN_MCOMMA_VALUE  = 0x283,
            p_RX_ALIGN_PCOMMA_VALUE  = 0x17C,
            p_RX_MCOMMA_ALIGN_OVR    = 0, p_RX_MCOMMA_ALIGN = 0,
            p_RX_PCOMMA_ALIGN_OVR    = 0, p_RX_PCOMMA_ALIGN = 0,
            p_RX_SLIDE_MODE = 0, p_RX_SLIDE = 0,
            p_RX_BYTE_REALIGN = 1,
            # Clock correction
            p_RX_CLKCOR_USE    = 0,
            p_RX_CLKCOR_MIN_LAT= 32, p_RX_CLKCOR_MAX_LAT = 39,
            p_RX_CLKCOR_SEQ_1_0= 0x1F7, p_RX_CLKCOR_SEQ_1_1=0x1F7,
            p_RX_CLKCOR_SEQ_1_2= 0x1F7, p_RX_CLKCOR_SEQ_1_3=0x1F7,
            # CDR configuration
            p_RX_WAIT_CDR_LOCK = 0,
            p_RX_CDR_FORCE_LOCK= 1,
            p_RX_CDR_RESET_TIME= 3,
            p_RX_CDR_CKP       = 0xF8,
            p_RX_CDR_CKI       = 0x00,
            p_RX_CDR_TRANS_TH  = 128,
            p_RX_CDR_LOCK_CFG  = 0x0B,
            p_RX_CDR_FREQ_ACC  = 0,
            p_RX_CDR_PHASE_ACC = 0,
            p_RX_CDR_SET_ACC_CONFIG = 0,
            p_RX_CDR_RESET_OVR = 0, p_RX_CDR_RESET = 0,
            # RX Equalizer
            p_RX_EN_EI_DETECTOR_OVR = 0, p_RX_EN_EI_DETECTOR = 0,
            p_RX_EI_BIAS = 4, p_RX_EI_BW_SEL = 4,
            p_RX_AFE_PEAK = 0xF, p_RX_AFE_GAIN = 0x8, p_RX_AFE_VCMSEL = 0x4,
            p_RX_CALIB_EN = 1, p_RX_CALIB_OVR = 0, p_RX_CALIB_VAL = 0,
            p_RX_RTERM_VCMSEL = 4, p_RX_RTERM_PD = 0,
            p_RX_EQA_RESET_TIME = 3, p_RX_EQA_RESET_OVR = 0, p_RX_EQA_RESET = 0,
            p_RX_EQA_CKP_LF = 0xA3, p_RX_EQA_CKP_HF = 0xA3,
            p_RX_EQA_CKP_OFFSET = 0x01,
            p_RX_EN_EQA = 0, p_RX_EQA_LOCK_CFG = 0,
            p_RX_TH_MON1 = 8, p_RX_TH_MON2 = 8,
            p_RX_TAPW = 8, p_RX_AFE_OFFSET = 8,
            p_RX_EQA_CONFIG = 0x01C0, p_RX_MON_PH_OFFSET = 0,
            # PRBS
            p_TX_PRBS_OVR = 0, p_TX_PRBS_SEL = 0, p_TX_PRBS_FORCE_ERR = 0,
            p_RX_PRBS_OVR = 0, p_RX_PRBS_SEL = 0, p_RX_PRBS_CNT_RESET = 0,
            # Loopback configuration
            p_TX_PMA_LOOPBACK = 0, p_TX_PCS_LOOPBACK = 0,
            p_RX_PMA_LOOPBACK = 0, p_RX_PCS_LOOPBACK = 0,
            p_RX_BUF_RESET_TIME = 0x3,
            p_RX_EN_EQA_EXT_VALUE = 0x0,
            p_RX_EYE_MEAS_EN =0x0,
            p_RX_EYE_MEAS_CFG = 0,    
            p_RX_DATA_SEL =  0x0,
            p_RX_BUF_BYPASS = 0x0,        
            p_RX_LOOPBACK_OVR= 0x0,        
            p_RX_RESET_OVR= 0x0,
            p_RX_RESET= 0x0,
            p_RX_PMA_RESET_OVR= 0x0,
            p_RX_PMA_RESET= 0x0,
            p_RX_PCS_RESET_OVR=0x0,
            p_RX_PCS_RESET= 0x0,
            p_RX_BUF_RESET_OVR= 0x0,
            p_RX_BUF_RESET= 0x0,
        )
        # SERDES I/O port connections
        serdes_params.update(
            # Clocks & loopback
            i_TX_CLK_I               = ClockSignal("tx_half"),
            i_RX_CLK_I               = ClockSignal("rx"),
            o_PLL_CLK_O              = self.txoutclk,
            o_RX_CLK_O               = self.rxoutclk,
            i_LOOPBACK_I             = 0b010 if internal_loopback else 0b000,

            # Resets
            i_TX_RESET_I             = tx_reset,
            i_RX_RESET_I             = rx_reset,
            i_RX_PMA_RESET_I         = 0,
            i_RX_EQA_RESET_I         = 0,
            i_RX_CDR_RESET_I         = 0,
            i_RX_PCS_RESET_I         = 0,
            i_RX_BUF_RESET_I         = 0,
            i_TX_PCS_RESET_I         = 0,
            i_TX_PMA_RESET_I         = 0,
            i_PLL_RESET_I            = pll_reset,

            # TX data & controls
            i_TX_DATA_I              = Cat(tx_bus[0:8], tx_bus[10:18]),
            i_TX_CHAR_IS_K_I         = 0,
            i_TX_CHAR_DISPMODE_I     = Cat(tx_bus[9], tx_bus[23]),
            i_TX_CHAR_DISPVAL_I      = Cat(tx_bus[8], tx_bus[22]),
            i_TX_POWER_DOWN_N_I      = 1,
            i_TX_POLARITY_I          = tx_polarity,
            i_TX_ELEC_IDLE_I         = 0,
            i_TX_DETECT_RX_I         = 1,
            i_TX_PRBS_SEL_I          = _tx_prbs_config,
            i_TX_PRBS_FORCE_ERR_I    = _tx_prbs_force_err,

            o_TX_RESET_DONE_O        = tx_reset_done,
            o_TX_BUF_ERR_O           = tx_buf_err,
            o_TX_DETECT_RX_DONE_O    = tx_detect_rx_done,
            o_TX_DETECT_RX_PRESENT_O = tx_detect_rx_present,

             # RX data & controls
            i_RX_POWER_DOWN_N_I      = 1,
            i_RX_POLARITY_I          = rx_polarity,
            i_RX_EN_EI_DETECTOR_I    = 0,
            i_RX_COMMA_DETECT_EN_I   = rx_comma_detect_en,
            i_RX_SLIDE_I             = 0,
            i_RX_MCOMMA_ALIGN_I      = rx_comma_detect_en,
            i_RX_PCOMMA_ALIGN_I      = rx_comma_detect_en,
            i_RX_PRBS_SEL_I          = _rx_prbs_config,
            i_RX_PRBS_CNT_RESET_I    = _rx_prbs_pause,
    
            o_RX_DATA_O              = Cat(rx_bus[0:8], rx_bus[10:18]),
            o_RX_PRBS_ERR_O          = rx_prbs_err,
            o_RX_BUF_ERR_O           = rx_buf_err,
            o_RX_RESET_DONE_O        = rx_reset_done,

            # register file
            i_REGFILE_CLK_I          = 0,
            i_REGFILE_WE_I           = 0,
            i_REGFILE_EN_I           = 0,
            i_REGFILE_ADDR_I         = 0,
            i_REGFILE_DI_I           = 0,
            i_REGFILE_MASK_I         = 0,
            o_REGFILE_DO_O           = regfile_do,
            o_REGFILE_RDY_O          = regfile_rdy,
        )

        # Connect SERDES to physical I/O pads if provided
        if tx_pads is not None and hasattr(tx_pads, "p"):
            serdes_params.update({o_TXP: tx_pads.p, o_TXN: tx_pads.n})
        if rx_pads is not None and hasattr(rx_pads, "p"):
            serdes_params.update({i_RXP: rx_pads.p, i_RXN: rx_pads.n})
        # Instantiate the CC_SERDES primitive with all parameters
        self.specials += Instance("CC_SERDES", **serdes_params)
    def add_stream_endpoints(self):

        # Create stream endpoints for data (each with nwords*8 data bits and nwords control bits for K)
        self.sink   = stream.Endpoint([("data", 8*self.nwords), ("ctrl", self.nwords)])
        self.source = stream.Endpoint([("data", 8*self.nwords), ("ctrl", self.nwords)])

        self.comb += self.sink.ready.eq(1)
        self.comb += self.source.valid.eq(1)
        for i in range(self.nwords):
            self.comb += [
                self.encoder.d[i].eq(self.sink.data[8*i:8*(i+1)]),
                self.encoder.k[i].eq(self.sink.ctrl[i])
            ]
            self.sync.rx += [
                self.source.data[8*i:8*(i+1)].eq(self.decoders[i].d),
                self.source.ctrl[i].eq(self.decoders[i].k)
            ]
    def add_controls(self, auto_enable=True):
        self._tx_enable = CSRStorage(fields=[CSRField("enable", size=1, reset=int(auto_enable), description="TX Enable")])
        self._rx_enable = CSRStorage(fields=[CSRField("enable", size=1, reset=int(auto_enable), description="RX Enable")])
        self._tx_ready  = CSRStatus(fields=[CSRField("ready", size=1, description="TX Ready (PLL/SerDes locked)")])
        self._rx_ready  = CSRStatus(fields=[CSRField("ready", size=1, description="RX Ready (CDR locked)")])
        self._tx_prbs_config = CSRStorage(size=2, description="TX PRBS Configuration (0: PRBS off)")
        self._rx_prbs_config = CSRStorage(size=2, description="RX PRBS Configuration (must match TX)")
        self._rx_prbs_pause  = CSRStorage(size=1, description="Pause RX PRBS Checker")
        self._rx_prbs_errors = CSRStatus(32, description="RX PRBS Error Count")
        self.comb += [
            self.tx_enable.eq(self._tx_enable.fields.enable),
            self.rx_enable.eq(self._rx_enable.fields.enable),
            self._tx_ready.fields.ready.eq(self.tx_ready),
            self._rx_ready.fields.ready.eq(self.rx_ready),
            self.tx_prbs_config.eq(self._tx_prbs_config.storage),
            self.rx_prbs_config.eq(self._rx_prbs_config.storage),
            self.rx_prbs_pause.eq(self._rx_prbs_pause.storage),
            self._rx_prbs_errors.status.eq(self.rx_prbs_errors)
        ]
