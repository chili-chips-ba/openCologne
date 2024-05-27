module rds #(
   /*c_rds_msg_len: integer range 1 to 512 := 260; -- circlar message length in bytes
   we need to generate 1.824 MHz for RDS clock strobe
   input clock frequency * multiply / divide = 1.824 MHz
   example 25 MHz * 228 / 3125 = 1.824 MHz */
   parameter integer c_rds_clock_multiply = 228,
   parameter integer c_rds_clock_divide = 3125, 
   // 2ch stereo is not yet implemented, only pilot generator
   parameter integer c_stereo = 0 //true: use stereo mixing
   /*stereo mixing needs to cut off all input audio frequencies
   above 17kHz. It could be done by enabling:
   1. C_filter: lowpass filter (higer audio quality but more LUTs)
   2. C_downsample: 38kHz downsampler before stereo mixer
      It does the job at Nyquist cutoff frequency 38/2=19 kHz
      with less LUTs than lowpass filter but sacrifices audio quality.
      input freqs above 19 kHz are aliased in range below 19 kHz)
   both C_filter and C_downsample can be enabled.*/
   parameter integer c_filter = 0; // true: low pass filter (fixme: glitches)
   parameter integer c_downsample = 0; // true: downsample to 38kHz before stereo mixing
   parameter integer c_debug: = 0; // output counters to check subcarriers phases
   parameter integer c_addr_bits 9; // number of address bits for RDS message RAM
   /*true: spend more LUTs to use 32-point sinewave and multiply
     false: save LUTs, use 4-point multiplexer, no multiply*/
   parameter integer c_fine_subc = 0 // use sine and multiplier for 57kHz subcarrier (not needed, saving LUTs)
// TODO: Maybe instead of integers use boolean?
)
(
/* system clock, RDS verified working at 25 MHz
   for different clock change multiply/divide*/
   input wire clk,
   input wire [c_addr_bits-1:0]rds_mgs_len, // circular message length in bytes
   input wire [7:0] data, // memory adress
   input wire signed [15:0] pcm_in_left,  // from tone generator
   input wire signed [15:0] pcm_in_right // from tone generator
   output wire [c_addr_bits-1:0] addr,  // memory data 8 bit
   output wire out_l, // filtered outputs for debugging
   output wire out_r,
   output wire [31:0] debug, 
   output wire signed [15:0] pcm_out // to FM transmitter
);

/* RDS related registers
   get length of RDS message (file message.vhd)
   constant C_rds_msg_len: integer := rds_msg_map'length;

   DBPSK waveform is used to modulate RDS at 1187.5 Hz
   and to generate sine wave for 57kHz subcarrier
   48 elements of 7 bits (range 1..127) in lookup table 
   provide sufficient resolution for time and amplitude */

   localparam integer C_dpsk_bits = 7;
   // DPSK wave lookup table
   localparam integer dpsk_wav_integer_map[0:47] = {
      7, 19, 30, 39, 46, 51, 53, 53, 51, 47, 42, 38, 33, 30, 28, 28,
      30, 34, 39, 45, 51, 57, 61, 63, 63, 61, 56, 49, 40, 30, 18,  6,
     -6,-18,-30,-40,-49,-56,-61,-63,-63,-61,-56,-49,-40,-30,-18, -6
   };
   reg signed [C_dpsk_bits-1:0] dpsk_wav_map [0:47];

   integer i;
   initial begin
      for (i = 0; i < 48; i = i + 1) begin
         dpsk_wav_map[i] = $signed(dpsk_wav_integer_map[i]);
      end
   end

   reg [5:0] R_rds_cdiv; // 6 bit divisor 0..47
   reg signed [C_dpsk_bits-1:0] R_rds_pcm; // 7 bit ADC value for RDS waveform 
   reg [c_addr_bits-1:0] R_rds_msg_index; // addr index for message
   localparam [c_addr_bits-1:0] C_rds_msg_disable = {c_addr_bits{1'b0}}; // message len -1 disables
   reg [7:0] R_rds_byte; // current byte to send
   reg [2:0] R_rds_bit_index; // current bit index 0..7
   reg R_rds_bit; // current bit to send
   reg S_rds_bit; // current bit to send
   reg R_rds_phase; // current phase 0:(+) 1:(-)
   reg [4:0] R_rds_counter = 5'b0; // 5-bit wav counter 0..31
   reg S_rds_sign; // current sign of waveform 0:(+) 1:(-)
   reg [5:0] S_dbpsk_wav_index; // 6-bit index 0..63
   reg signed [C_dpsk_bits-1:0] S_dbpsk_wav_value;
   reg signed [C_dpsk_bits-1:0] S_rds_pcm; // 7 bit ADC value for RDS waveform
   reg signed [2*C_dpsk_bits-1:0] S_rds_mod_pcm;
   reg signed [2*C_dpsk_bits-1:0] S_rds_coarse_pcm;

   reg [4:0] R_pilot_counter = 5'b0; // 5-bit wav counter 0..31
   reg [1:0] R_pilot_cdiv; // 2-bit divisor 0..2
   reg [5:0] S_pilot_wav_index; // 6-bit index 0..63
   reg signed [C_dpsk_bits-1:0] S_pilot_wav_value;
   reg signed [C_dpsk_bits-1:0] S_pilot_pcm = {C_dpsk_bits{1'b0}}; // 7 bit ADC value
   reg [4:0] S_stereo_counter  = 5'b0; // 5-bit wav counter 0..31
   reg [5:0] S_stereo_wav_index; // 6-bit index 0..63
   reg signed [C_dpsk_bits-1:0] S_stereo_wav_value;
   reg signed [C_dpsk_bits-1:0] S_stereo_pcm = {C_dpsk_bits{1'b0}}; // 7 bit ADC value
   reg signed [22:0] S_pcm_stereo;

   reg [4:0] R_subc_counter = 5'b0; // 5-bit wav counter 0..31
   reg [4:0] R_subc_cdiv = 5'b00110; // counter for 57kHz coarse subcarrier
   reg [5:0] S_subc_wav_index; // 6-bit index used 0..47, max 63
   reg signed [C_dpsk_bits-1:0] S_subc_wav_value;
   reg signed [C_dpsk_bits-1:0] S_subc_pcm; // 7 bit ADC value for 19kHz pilot sine wave
  
   // debug PWM output for audible test of internal low pass filter
   reg [15:0] R_pcm_unsigned_data_l; 
   reg [15:0] R_pcm_unsigned_data_r;
   reg [16:0] R_dac_acc_l, R_dac_acc_r;

   reg S_filter_strobe;
   reg signed [15:0] S_pcm_in_left_filter;
   reg signed [15:0] S_pcm_in_right_filter; // 16-bit low pass filtered
   reg signed [15:0] R_pcm_in_left_downsample;
   reg signed [15:0] R_pcm_in_right_downsample; // 16-bit low pass filtered

   /* clock multiply must be smaller than clock divide
      calculate number of bits for clock divide counter
      1 bit more than clock divide number */
   localparam integer C_rds_clkdiv_bits = 1 + $clog2(c_rds_clock_divide);   
   reg [C_rds_clkdiv_bits-1:0] R_rds_clkdiv; // RDS timer in picoseconds (20 bit max range 1e6 ps)
   reg S_rds_strobe; // 1.824 MHz strobe signal

   /* generate 1.824 MHz RDS clock strobe
      from this frequency we can generate
      pilot 19 kHz, stereo 38 kHz,
      RDS fine subcarrier 57 kHz,
      RDS coarse subcarrier base 228 kHz
      for fine sine wave,
      lookup sine table period length is 32 entries
      so we need strobe frequency of 32*57 kHz = 1.824 MHz
      change state on falling edge, so strobe level is
      stable when compared at rising edge */
   always @(negedge clk) begin
   /* MSB bit is mostly 0 and for one cycle becomes 1
      small number is added each cycle.
      as soon as MSB is detected as 1,
      a large number is subtracted so 
      MSB again becomes 0 */
      if (R_rds_clkdiv[C_rds_clkdiv_bits-1] = 1'b0) begin
         // add clock multiply 
         R_rds_clkdiv <= R_rds_clkdiv + C_rds_clock_multiply;
      end else begin
         // add clock multiply as always and subtract clock divide
         R_rds_clkdiv <= R_rds_clkdiv + C_rds_clock_multiply - C_rds_clock_divide;
      end
   end

   // MSB is used as output strobe signal
   assign S_rds_strobe = R_rds_clkdiv[C_rds_clkdiv_bits-1];

   //********** STEREO 19 kHz PILOT and 38 kHz SUBCARRIER ***********
   generate 
      if(c_stereo) begin: generate_pilot_19khz
         always @(posedge clk) begin
            // clocked at 25 Mhz
            // strobed at 1.824 Mhz
            if (S_rds_strobe == 1'b1) begin
               // pilot 57/3 = 19 khz generation
               if (R_pilot_cdiv == 1'b0) begin
                  R_pilot_cdiv <= 2;
                  R_pilot_counter <= R_pilot_counter + 1;
               end else begin
                  R_pilot_cdiv <= R_pilot_cdiv - 1;
               end
            end
         end

         always @(*) begin

            S_pilot_wav_index = {2'b10, R_pilot_counter[3:0]}; // or 32(sine), 0..15 running
            /*dbpsk_wav_map has range 1..127, need to subtract 64
              phase warning: negative sine values at index 32..47
              pilot should be in phase with 57kHz subcarrier
             (rising slope cross 0 at the same point)*/
            S_pilot_wav_value = dpsk_wav_map[S_pilot_wav_index];
            if(R_pilot_counter(4) = 1'b1) begin
               S_pilot_pcm = S_pilot_wav_value;
            end else begin 
               S_pilot_pcm = ~S_pilot_wav_value;
            end
         end
         /* S_pilot_pcm range: (-63 .. +63)
            pilot 19kHz must have 4.5x lower amplitude than stereo 38 kHz

            stereo 38kHz is generated by doubling the 19 kHz counter (shift left)
            every 2nd value of the sine table is used.
            if something better is ever needed
            double strobe frequency can be generated at 3.648 MHz
            S_stereo_counter <= R_pilot_counter + 1; -- +1 to adjust phase of stereo 38kHz*/
         S_stereo_counter = R_pilot_counter; // phase ok
         S_stereo_wav_index = {2'b10, S_stereo_counter[2:0], 1'b0};
         // dbpsk_wav_map has range 1..127, need to subtract 64
         // phase warning: negative sine values at index 32..47
         S_stereo_wav_value = dpsk_wav_map[S_stereo_wav_index];
         if(S_stereo_counter[3] = 1'b1) begin
            S_stereo_pcm = S_stereo_wav_value;
         end else begin
            S_stereo_pcm = ~S_stereo_wav_value;
         end
      end
      // S_stereo_pcm range: (-63 .. +63)
   endgenerate
   // *********** END PILOT 19kHz and 38kHz SUBCARRIER *************
   
   // **************** FINE SUBCARRIER 57kHz ***********************
   generate 
      if(C_fine_subc) begin: fine_subcarrier_sine
         always @(posedge clk) begin
            // clocked at 25 MHz
            // strobed at 1.824 MHz
            if (S_rds_strobe = 1'b1) then
               // 57 kHz subcarrier generation
               // using counter 0..31
               R_subc_counter <= R_subc_counter + 1;
         end
      end
      always @(*) begin
         S_subc_wav_index = {2'b10, R_subc_counter[3:0]}; // or 32(sine) 0..15 running
         // dpsk_wav_map has range 1..127 need to subtract 64
         // phase warning: negative sine values at inex 32..47
         S_subc_wav_value = dpsk_wav_map[S_subc_wav_index];
         if(R_subc_counter[4] == 1'b1) begin
            S_subc_pcm = S_subc_wav_value;
         end else begin
            S_subc_pcm = ~ S_subc_wav_value;
         end
         // S_subc_pcm range: (-63 .. + 63)
      end
   endgenerate
   // *************** END FINE SUBCARRIER 57kHz ********************

   // *********** RDS MODULATOR 57 kHz / 1187.5 Hz *****************
   assign addr = R_rds_msg_index; // address of data to read
   assign R_rds_bit = R_rds_byte[7];
   always @(posedge clk) begin
      // Clocked at 25 MHz
      // strobed at 1.824 MHz
      if (S_rds_strobe = 1'b1) begin
         // divide by 32 for 57 kHz coarse subcarrier
         R_subc_cdiv <= R_subc_cdiv + 1;
         // 0-47: divide by 48 to get 1187.5 Hz from 32 element lookup table
         if (R_rds_cdiv = 0) begin
            R_rds_cdiv <= 47;
            /* RDS works on 1187.5 bit rate 
               57 kHz subcarrier should be AM modulated using RDS
               adjust modulation to obtain
               +- 2kHz FM width on the main carrier*/
            R_rds_counter <= R_rds_counter + 1; // increment counter 0..31
            if (R_rds_counter == 31) begin
               /* fetch new bit
                  R_rds_bit <= rds_msg_map[R_rds_msg_index][R_rds_bit_index];
                  R_rds_bit <= not(R_rds_bit);
                  R_rds_bit <= '0'; -- test: bit 0 should output 1187.5 kHz
                  change phase if bit was 1 */
                  R_rds_phase <= R_rds_phase ^ R_rds_bit; // change the phase
                  // Take next bit. Send bits from 7 downto bit 0
                  R_rds_bit_index <= R_rds_bit_index - 1;
                  if(R_rds_bit_index == 0) begin
                 /*when bit index is at LSB bit pos 0
                  for next clock cycle prepare next byte
                 (byte sending start at MSB bit pos 7)*/
                     if(R_rds_msg_index == rds_msg_len-1) begin
                        R_rds_msg_index <= 0;
                     end else begin
                        R_rds_msg_index <= R_rds_msg_index + 1;
                     end
                  end

                  if (R_rds_bit_index == 7) begin
                     R_rds_byte <= data; // data, new byte
                  end else begin
                     R_rds_byte <= {R_rds_byte[6:0], 1'b0}; // shift 1 bit left
                  end
               end
         end else begin 
            R_rds_cdiv <= R_rds_cdiv - 1; // countdown from 47 to 0
         end
      end
   end
   /* rds bit 0: continuous sine wave
      use lookup table values 32..47
      index = (counter and 15) or 32
      rds bit 1: phase changing sine wave
      use lookup table values 0..31
      index = counter and 31
      this logic has been changed from sequential
      to parallel so some R_rds_bit my be 1 cycle out of time
      we should plot S_dbpsk_wav_value in the logic
      analyzer
   */
   always @(*) begin
      if(R_rds_bit == 1'b1) begin
         S_rds_sign = R_rds_phase;
      end else begin
         S_rds_sign = ~(R_rds_counter[4] ^ R_rds_phase);
      end
   end 

   always @(*)begin
      S_dpsk_wav_index = {~R_rds_bit, (R_rds_counter[4] & R_rds_bit), R_rds_counter[3:0]}; // 32(sine) 0..15 (sine) or 0..31(phase change) 0..15 same for  both
   end

   always @(*) begin
    S_dbpsk_wav_value = dbpsk_wav_map[S_dbpsk_wav_index];
   end

   /* AM modulation of subcarrier with DBPSK wave
      do not overmodulate RDS signal
      signed value is passed to fmgen modulator
      transmits value*2Hz carrier frequency shift
      modulated range of cca -4000 ... +4000 works*/
   
   generate 
      if(c_fine_subc) begin:fine_subcarrier_sine
         always @(*) begin
            if(S_rds_sign = 1'b1) begin
               S_rds_pcm = S_dpsk_wav_value;
            end else begin
               S_rds_pcm = ~S_dpsk_wav_value;
            end
            // S_rds_pcm range: (-63 .. +63)
            if(rds_msg_len != C_rds_msg_disable) begin
               S_rds_mod_pcm = S_subc_pcm * S_rds_pcm;
            end else begin
               S_rds_mod_pcm = 0;
            end
            // S_rds_mod_pcm range: 63*63 = (-3969 .. +3969)
         end
      end
   endgenerate

   /* simple 57kHz mixer with multiplexer
      using 4 points coarse sampled subcarrier at 228 kHz
      no multiplication needed */
   generate 
      if (~c_fine_subc) begin: coarse_subcarrier
       /*sign manipulation with the multiplexer
         xor replaces calculating double minus
         with ( '0' xor R_subc_cdiv(4)) & R_subc_cdiv(3 downto 3) select -- debug*/
         always @(*) begin
            case ({S_rds_sign ^ R_subc_div[4], R_subc_div[3]})
               2'b11: S_rds_coarse_pcm = S_dpsk_wav_value;
               2'b01: S_rds_coarse_pcm = ~S_dpsk_wav_value;
               default: S_rds_coarse_pcm = 0;
            endcase
         end         
         always@(*)begin
            if(rds_msg_len != C_rds_msg_disable) begin
               S_rds_mod_pcm = S_rds_coarse_pcm << 6;
            end else
               S_rds_mod_pcm = 0;
         end
      end
   /*multiply with 2^n because it is
     simple, uses only bit shifting
     for *64: S_rds_mod_pcm range: 63*64 = (-4032 .. +4032)
     experimental results for various RDS modulation levels
     received with redsea RTL-SDR receiver:
     *16 works but RDS reception becomes weaker, CRC errors
     *32, *64, *128 all work mostly the same
     *256 doesn't work (overmodulation)*/
   endgenerate
   // ****************** END RDS MODULATOR **************

   // ************** LOW PASS FILTER **************
   generate
      if(!C_filter): no_lowpass_filter
      // no filtering, input is only divided by 2 to avoid overflows
      // at stereo mixing
      always @(*) begin
         S_pcm_in_left_filter = pcm_in_left >> 1;
         S_pcm_in_right_filter = pcm_in_right >> 1; 
      end
   endgenerate
   /*FM standard requires low pass filter for audio
     channels to cut off frequencies above 17kHz
     we'll try to approximate.
     besides filtering we have to attenuate signal (about x2),
     this is to aviod overflows at stereo mixing*/
     generate
        if(C_filter) begin: lowpass_filter
           always @(*) begin
              if(S_rds_strobe = 1'b1 && R_pilot_cdiv == 0 and R_pilot_counter[1:0] = 2'b00)
                 S_filter_strobe = 1'b1;
               else begin
                 S_filter_strobe = 1'b0;
               end
            /* select S_filter_strobe frequency:
               R_pilot_counter(0 downto 0) = 0 -> 304 kHz
               R_pilot_counter(1 downto 0) = 0 -> 152 kHz
               R_pilot_counter(2 downto 0) = 0 ->  76 kHz
               R_pilot_counter(3 downto 0) = 0 ->  38 kHz
               bit difference and strobe frequecy
               define lowpass cutoff f_lowpass = f_strobe/2^bit_difference
               cutoff at 152/2^4 = 152/16 = 9.5 kHz*/
           end
        end
        
        lowpass#(
           .C_bits_in(12),
           .C_attenuation(1), // attenuation 2^1 = 2x
           .C_bits_out(16) // 16-12 = 4-bit difference
        )filter_left(
           .clock(clk),
           .enable(S_filter_strobe) // 152 kHz
           .data_in(pcm_in_left[15:4])
           .data_out(S_pcm_in_left_filter)
        );

         lowpass#(
           .C_bits_in(12),
           .C_attenuation(1), // attenuation 2^1 = 2x
           .C_bits_out(16) // 16-12 = 4-bit difference
         )filter_right(
           .clock(clk),
           .enable(S_filter_strobe) // 152 kHz
           .data_in(pcm_in_right[15:4])
           .data_out(S_pcm_in_right_filter)
        );
     endgenerate
     // ************ END LOW PASS FILTER **************

     generate
        if(!C_downsample) begin: no_downsample_38kHz
           // signal pass-through (direct wire)
           always @(*) begin
              R_pcm_in_left_downsample = S_pcm_in_left_filter;
              R_pcm_in_right_downsample = S_pcm_in_right_filter;
           end
        end else begin: downsample_38kHz
           always @(posedge clk) begin
              if(S_rds_strobe == 1'b1 && R_pilot_cdiv == 0 && R_pilot_counter[1:0] == 2'b00) begin
              /*pilot counter 4 LSB bits compared to a constant holds true at 38 kHz rate,
                at 38 kHz we downsample input PCM signal.
                effectively this makes a crude low pass filter,
                which aliases frequencies above 19 kHz (nyquist freq)*/   
                R_pcm_in_left_downsample = S_pcm_in_left_filter;
                R_pcm_in_right_downsample = S_pcm_in_right_filter;  
              end
           end
        end
     endgenerate
     // ************ END DOWNSAMPLE ***************

     // output mixing audio and RDS
     generate
        if(!C_stereo) begin: mix_mono
        // mixing mono input audio with RDS DBPSK
           always @(*) begin
              pcm_out = R_pcm_in_left_downsample + R_pcm_in_right_downsample + S_rds_mod_pcm;
           end
        end else begin
           always @(*) begin
           S_pcm_stereo = (R_pcm_in_left_downsample - R_pcm_in_right_downsample) * S_stereo_pcm;
           /* S_stereo_pcm has range -63 .. +63
              pcm_in_left has range -32767 .. +32767
              stereo mixing: we should divide by 4 because
              we mix L+R + (L-R)*sin(38kHz), that rises max amplitude 4 times
              but we divide by 2 and hope for no clipping*/
            pcm_out = R_pcm_in_left_downsample + R_pcm_in_right_downsample 
                      + (S_pcm_stereo >>> 6) // normalize S_stereo_pcm, shift divide by 64
                      + (S_pilot_pcm << 6)   // 16 is too weak, not sure of correct 19kHz pilot amplitude
                      + S_rds_mod_pcm;
           end
         end
     endgenerate

     generate
        if(c_debug) begin: rds_debug_output
           always@(posedge clk) begin
              /*PCM data from RAM normally should have average 0 (removed DC offset)
                for purpose of PCM generation here is
                conversion to unsigned std_logic_vector
                by inverting MSB bit (effectively adding 0x8000)*/
              R_pcm_unsigned_data_l = {~R_pcm_in_left_downsample[15], R_pcm_in_left_downsample[14:0]};
              R_pcm_unsigned_data_r = {~R_pcm_in_right_downsample[15], R_pcm_in_right_downsample[14:0]};
              // Output 1-bit DAC
              R_dac_acc_l = {R_dac_acc_l[16], R_pcm_unsigned_data_l} + R_dac_acc_l;
              R_dac_acc_r = {R_dac_acc_r[16], R_pcm_unsigned_data_r} + R_dac_acc_r;
        end
        assign out_l = R_dac_acc_l[16];
        assign out_r = R_dac_acc_r[16];

        // out to check phases of subcarriers
        assign debug = {8'h00, 1'b0, S_stereo_pcm, 1'b0, S_pilot_pcm, 1'b0, S_rds_coarse_pcm};
      end
   endgenerate
endmodule

/* todo
   [x] when rds_msg_len = 0 disable RDS (only mono/stereo mixing)
   [x] compare rds with <= when size changes, it will reset if out of range
*/