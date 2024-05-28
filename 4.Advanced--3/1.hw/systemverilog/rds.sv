//======================================================================== 
// openCologne * NLnet-sponsored open-source design ware for GateMate
//------------------------------------------------------------------------
//                   Copyright (C) 2024 Chili.CHIPS*ba
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
//
// 1. Redistributions of source code must retain the above copyright 
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright 
// notice, this list of conditions and the following disclaimer in the 
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its 
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//              https://opensource.org/license/bsd-3-clause
//------------------------------------------------------------------------
// Description: <your text goes here>
//========================================================================

// -----------------------------------------------------------------------
// Description:
// This module implements an RDS (Radio Data System) encoder with the
// following features:
// - Generates a 1.824 MHz clock strobe for RDS timing based on input
//   clock frequency, multiply and divide parameters.
// - Supports optional stereo mixing with 19 kHz pilot and 38 kHz subcarrier.
// - Optionally applies a low-pass filter to the input audio to cut off
//   frequencies above 17 kHz.
// - Optionally downsamples the input audio to 38 kHz before stereo mixing.
// - Provides debug outputs to check subcarrier phases.
// - Uses DBPSK modulation for the RDS signal at 1187.5 Hz and 57 kHz
//   subcarrier.
// - Allows configuration of RDS message length and fine/coarse subcarrier
//   generation.
//
// Inputs:
// - clk: System clock, typically 25 MHz.
// - reset: System reset signal.
// - rds_msg_len: Length of the RDS message in bytes.
// - data: Memory address for RDS message RAM.
// - pcm_in_left: Input PCM audio signal for the left channel.
// - pcm_in_right: Input PCM audio signal for the right channel.
//
// Outputs:
// - addr: Address for reading data from RDS message RAM.
// - out_l: Filtered output for debugging (left channel).
// - out_r: Filtered output for debugging (right channel).
// - debug: Debug output signal.
// - pcm_out: Mixed audio output to FM transmitter.
//
// Parameters:
// - RDS_CLOCK_MULTIPLY: Clock multiply factor for generating 1.824 MHz strobe.
// - RDS_CLOCK_DIVIDE: Clock divide factor for generating 1.824 MHz strobe.
// - STEREO: Enables stereo mixing if set to true.
// - FILTER: Enables low-pass filtering of input audio if set to true.
// - DOWNSAMPLE: Enables downsampling of input audio to 38 kHz if set to true.
// - DEBUG: Enables debug outputs if set to true.
// - ADDR_BITS: Number of address bits for RDS message RAM.
// - FINE_SUBC: Enables fine subcarrier generation using sine and multiplier.
//
// Notes:
// - This module assumes a system clock of 25 MHz. Adjust the clock multiply
//   and divide parameters accordingly for different clock frequencies.
//========================================================================

module rds #(
   /*c_rds_msg_len: integer range 1 to 512 := 260; -- circlar message length in bytes
   we need to generate 1.824 MHz for RDS clock strobe
   input clock frequency * multiply / divide = 1.824 MHz
   example 25 MHz * 228 / 3125 = 1.824 MHz */
   parameter integer RDS_CLOCK_MULTIPLY = 228,
   parameter integer RDS_CLOCK_DIVIDE = 3125, 
   // 2ch stereo is not yet implemented, only pilot generator
   parameter logic STEREO = 0, //true: use stereo mixing
   /*stereo mixing needs to cut off all input audio frequencies
   above 17kHz. It could be done by enabling:
   1. FILTER: lowpass filter (higer audio quality but more LUTs)
   2. DOWNSAMPLE: 38kHz downsampler before stereo mixer
      It does the job at Nyquist cutoff frequency 38/2=19 kHz
      with less LUTs than lowpass filter but sacrifices audio quality.
      input freqs above 19 kHz are aliased in range below 19 kHz)
   both FILTER and DOWNSAMPLE can be enabled.*/
   parameter logic FILTER = 0, // true: low pass filter (fixme: glitches)
   parameter logic DOWNSAMPLE = 0, // true: downsample to 38kHz before stereo mixing
   parameter logic DEBUG = 0, // output counters to check subcarriers phases
   parameter logic ADDR_BITS = 9, // number of address bits for RDS message RAM
   /*true: spend more LUTs to use 32-point sinewave and multiply
     false: save LUTs, use 4-point multiplexer, no multiply*/
   parameter logic FINE_SUBC = 0 // use sine and multiplier for 57kHz subcarrier (not needed, saving LUTs)
)
(
/* system clock, RDS verified working at 25 MHz
   for different clock change multiply/divide*/
   input logic clk,
   input logic reset,
   input logic [ADDR_BITS-1:0]rds_msg_len, // circular message length in bytes
   input logic [7:0] data, // memory adress
   input logic signed [15:0] pcm_in_left,  // from tone generator
   input logic signed [15:0] pcm_in_right, // from tone generator
   output logic [ADDR_BITS-1:0] addr,  // memory data 8 bit
   output logic out_l, // filtered outputs for debugging
   output logic out_r,
   output logic [31:0] debug, 
   output logic signed [15:0] pcm_out // to FM transmitter
);

/* RDS related registers
   get length of RDS message (file message.vhd)
   constant C_rds_msg_len: integer := rds_msg_map'length;

   DBPSK waveform is used to modulate RDS at 1187.5 Hz
   and to generate sine wave for 57kHz subcarrier
   48 elements of 7 bits (range 1..127) in lookup table 
   provide sufficient resolution for time and amplitude */
   // TODO: DOUBLE CHECK THIS
   // DBPSK parameters
  localparam integer DBPSK_BITS = 7;

  // DBPSK wave integer type and map
  typedef int dbpsk_wav_integer_t[0:47];
  typedef logic signed [DBPSK_BITS-1:0] dbpsk_wav_signed_t[0:47];

  // DBPSK wave integer map
  localparam dbpsk_wav_integer_t dbpsk_wav_integer_map = '{
      7, 19, 30, 39, 46, 51, 53, 53, 51, 47, 42, 38, 33, 30, 28, 28,
      30, 34, 39, 45, 51, 57, 61, 63, 63, 61, 56, 49, 40, 30, 18,  6,
     -6,-18,-30,-40,-49,-56,-61,-63,-63,-61,-56,-49,-40,-30,-18, -6
  };

  // DBPSK wave signed map
  dbpsk_wav_signed_t dbpsk_wav_map;

  // Initialize the DBPSK wave map
  initial begin
    integer i;
    for (i = 0; i < 48; i = i + 1) begin
      dbpsk_wav_map[i] = $signed(dbpsk_wav_integer_map[i]);
    end
  end

   typedef logic[4:0] counter_t;
   typedef logic[2:0] threebit_t; 
   typedef logic[5:0] sixbit_t;
   typedef logic[ADDR_BITS-1:0] addrbit_t;

   sibit_t R_rds_cdiv; // 6 bit divisor 0..47
   logic signed [DBPSK_BITS-1:0] R_rds_pcm; // 7 bit ADC value for RDS waveform 
   addrbit_t R_rds_msg_index; // addr index for message
   localparam addrbit_t C_rds_msg_disable = '0; // message len -1 disables
   logic [7:0] R_rds_byte; // current byte to send
   logic [2:0] R_rds_bit_index; // current bit index 0..7
   logic R_rds_bit; // current bit to send
   logic S_rds_bit; // current bit to send
   logic R_rds_phase; // current phase 0:(+) 1:(-)
   counter_t R_rds_counter;; // 5-bit wav counter 0..31
   logic S_rds_sign; // current sign of waveform 0:(+) 1:(-)
   logic [5:0] S_dbpsk_wav_index; // 6-bit index 0..63
   logic signed [DBPSK_BITS-1:0] S_dbpsk_wav_value;
   logic signed [DBPSK_BITS-1:0] S_rds_pcm; // 7 bit ADC value for RDS waveform
   logic signed [2*DBPSK_BITS-1:0] S_rds_mod_pcm;
   logic signed [2*DBPSK_BITS-1:0] S_rds_coarse_pcm;

   counter_t R_pilot_counter; // 5-bit wav counter 0..31
   logic [1:0] R_pilot_cdiv; // 2-bit divisor 0..2
   logic [5:0] S_pilot_wav_index; // 6-bit index 0..63
   logic signed [DBPSK_BITS-1:0] S_pilot_wav_value;
   logic signed [DBPSK_BITS-1:0] S_pilot_pcm; // 7 bit ADC value
   counter_t S_stereo_counter; // 5-bit wav counter 0..31
   logic [5:0] S_stereo_wav_index; // 6-bit index 0..63
   logic signed [DBPSK_BITS-1:0] S_stereo_wav_value;
   logic signed [DBPSK_BITS-1:0] S_stereo_pcm; // 7 bit ADC value
   logic signed [22:0] S_pcm_stereo;

   counter_t R_subc_counter; // 5-bit wav counter 0..31
   counter_t R_subc_cdiv; // counter for 57kHz coarse subcarrier
   logic [5:0] S_subc_wav_index; // 6-bit index used 0..47, max 63
   logic signed [DBPSK_BITS-1:0] S_subc_wav_value;
   logic signed [DBPSK_BITS-1:0] S_subc_pcm; // 7 bit ADC value for 19kHz pilot sine wave
  
   // debug PWM output for audible test of internal low pass filter
   logic [15:0] R_pcm_unsigned_data_l; 
   logic [15:0] R_pcm_unsigned_data_r;
   logic [16:0] R_dac_acc_l, R_dac_acc_r;

   logic S_filter_strobe;
   logic signed [15:0] S_pcm_in_left_filter;
   logic signed [15:0] S_pcm_in_right_filter; // 16-bit low pass filtered
   logic signed [15:0] R_pcm_in_left_downsample;
   logic signed [15:0] R_pcm_in_right_downsample; // 16-bit low pass filtered

   /* clock multiply must be smaller than clock divide
      calculate number of bits for clock divide counter
      1 bit more than clock divide number */
   localparam integer RDS_CLKDIV_BITS = 1 + $clog2(RDS_CLOCK_DIVIDE);   
   logic [RDS_CLKDIV_BITS-1:0] R_rds_clkdiv; // RDS timer in picoseconds (20 bit max range 1e6 ps)
   logic S_rds_strobe; // 1.824 MHz strobe signal


   always_ff @(posedge clk) begin
      if (reset == 1'b1) begin
         R_rds_counter <= '0;
         R_pilot_counter <= '0;
         S_stereo_counter <= '0;
         R_subc_counter <= '0;
         R_subc_cdiv = 5'b00110;
         S_stereo_pcm <= '0;
         S_pilot_pcm <= '0;
      end
   end

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
   always_ff @(negedge clk) begin
   /* MSB bit is mostly 0 and for one cycle becomes 1
      small number is added each cycle.
      as soon as MSB is detected as 1,
      a large number is subtracted so 
      MSB again becomes 0 */
      if (R_rds_clkdiv[RDS_CLKDIV_BITS-1] == 1'b0) begin
         // add clock multiply 
         R_rds_clkdiv <= R_rds_clkdiv + RDS_CLOCK_MULTIPLY;
      end else begin
         // add clock multiply as always and subtract clock divide
         R_rds_clkdiv <= R_rds_clkdiv + RDS_CLOCK_MULTIPLY - RDS_CLOCK_DIVIDE;
      end
   end

   // MSB is used as output strobe signal
   always_comb S_rds_strobe = R_rds_clkdiv[RDS_CLKDIV_BITS-1];

   //********** STEREO 19 kHz PILOT and 38 kHz SUBCARRIER ***********
   generate 
      if(STEREO == 1'b1) begin: generate_pilot_19khz
         always_ff @(posedge clk) begin
            // clocked at 25 Mhz
            // strobed at 1.824 Mhz
            if (S_rds_strobe == 1'b1) begin
               // pilot 57/3 = 19 khz generation
               if (R_pilot_cdiv == 2'b00) begin
                  R_pilot_cdiv <= 2'b10; 
                  R_pilot_counter <= counter_t'(R_pilot_counter + counter_t'(1));
               end else begin
                  R_pilot_cdiv <= threebit_t'(R_pilot_cdiv - threebit_t'(1));
               end
            end
         end

         always_comb begin

            S_pilot_wav_index = {2'b10, R_pilot_counter[3:0]}; // or 32(sine), 0..15 running
            /*dbpsk_wav_map has range 1..127, need to subtract 64
              phase warning: negative sine values at index 32..47
              pilot should be in phase with 57kHz subcarrier
             (rising slope cross 0 at the same point)*/
            S_pilot_wav_value = dbpsk_wav_map[S_pilot_wav_index];
            if(R_pilot_counter[4] == 1'b1) begin
               S_pilot_pcm =  S_pilot_wav_value;
            end else begin 
               S_pilot_pcm = ~S_pilot_wav_value;
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
            S_stereo_wav_value = dbpsk_wav_map[S_stereo_wav_index];
            if(S_stereo_counter[3] == 1'b1) begin
               S_stereo_pcm =  S_stereo_wav_value;
            end else begin
               S_stereo_pcm = ~S_stereo_wav_value;
            end
         end
      end
      // S_stereo_pcm range: (-63 .. +63)
   endgenerate
   // *********** END PILOT 19kHz and 38kHz SUBCARRIER *************
   
   // **************** FINE SUBCARRIER 57kHz ***********************
   generate 
      if(FINE_SUBC == 1'b1) begin: fine_subcarrier_sine
         always_ff @(posedge clk) begin
            // clocked at 25 MHz
            // strobed at 1.824 MHz
            if (S_rds_strobe == 1'b1) begin
               // 57 kHz subcarrier generation
               // using counter 0..31
               R_subc_counter <= counter_t'(R_subc_counter + counter_t'(1));
            end
         end
         always_comb begin
            S_subc_wav_index = {2'b10, R_subc_counter[3:0]}; // or 32(sine) 0..15 running
            // dbpsk_wav_map has range 1..127 need to subtract 64
            // phase warning: negative sine values at inex 32..47
            S_subc_wav_value = dbpsk_wav_map[S_subc_wav_index];
            if(R_subc_counter[4] == 1'b1) begin
               S_subc_pcm =  S_subc_wav_value;
            end else begin
               S_subc_pcm = ~S_subc_wav_value;
            end
            // S_subc_pcm range: (-63 .. + 63)
         end
      end
   endgenerate
   // *************** END FINE SUBCARRIER 57kHz ********************

   // *********** RDS MODULATOR 57 kHz / 1187.5 Hz *****************
   always_comb addr = R_rds_msg_index; // address of data to read
   always_comb R_rds_bit = R_rds_byte[7];
   always_ff @(posedge clk) begin
      // Clocked at 25 MHz
      // strobed at 1.824 MHz
      if (S_rds_strobe == 1'b1) begin
         // divide by 32 for 57 kHz coarse subcarrier
         R_subc_cdiv <= counter_t'(R_subc_cdiv + counter_t'(1));
         // 0-47: divide by 48 to get 1187.5 Hz from 32 element lookup table
         if (R_rds_cdiv == '0) begin
            R_rds_cdiv <= 6'b101111; // d'47 
            /* RDS works on 1187.5 bit rate 
               57 kHz subcarrier should be AM modulated using RDS
               adjust modulation to obtain
               +- 2kHz FM width on the main carrier*/
            R_rds_counter <= counter_t'(R_rds_counter + counter_t'(1)); // increment counter 0..31
            if (R_rds_counter == '1) begin 
               /* fetch new bit
                  R_rds_bit <= rds_msg_map[R_rds_msg_index][R_rds_bit_index];
                  R_rds_bit <= not(R_rds_bit);
                  R_rds_bit <= '0'; -- test: bit 0 should output 1187.5 kHz
                  change phase if bit was 1 */
                  R_rds_phase <= R_rds_phase ^ R_rds_bit; // change the phase
                  // Take next bit. Send bits from 7 downto bit 0
                  R_rds_bit_index <= threebit_t'(R_rds_bit_index - threebit_t'(1));
                  if(R_rds_bit_index == '0) begin
                 /*when bit index is at LSB bit pos 0
                  for next clock cycle prepare next byte
                 (byte sending start at MSB bit pos 7)*/
                     if(R_rds_msg_index == rds_msg_len-1) begin
                        R_rds_msg_index <= '0;
                     end else begin
                        R_rds_msg_index <= addrbit_t'(R_rds_msg_index + addrbit_t'(1));
                     end
                  end

                  if (R_rds_bit_index == '1) begin 
                     R_rds_byte <= data; // data, new byte
                  end else begin
                     R_rds_byte <= {R_rds_byte[6:0], 1'b0}; // shift 1 bit left
                  end
               end
         end else begin 
            R_rds_cdiv <= sixbit_t'(R_rds_cdiv - sixbit_t'(1)); // countdown from 47 to 0
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
   always_comb begin
      if(R_rds_bit == 1'b1) begin
         S_rds_sign = R_rds_phase;
      end else begin
         S_rds_sign = ~(R_rds_counter[4] ^ R_rds_phase);
      end
   end 

   always_comb begin
      S_dbpsk_wav_index = {~R_rds_bit, (R_rds_counter[4] & R_rds_bit), R_rds_counter[3:0]}; // 32(sine) 0..15 (sine) or 0..31(phase change) 0..15 same for  both
   end

   always_comb begin
    S_dbpsk_wav_value = dbpsk_wav_map[S_dbpsk_wav_index];
   end

   /* AM modulation of subcarrier with DBPSK wave
      do not overmodulate RDS signal
      signed value is passed to fmgen modulator
      transmits value*2Hz carrier frequency shift
      modulated range of cca -4000 ... +4000 works*/
   
   generate 
      if(FINE_SUBC == 1'b1) begin:fine_subcarrier
         always_comb begin
            if(S_rds_sign == 1'b1) begin
               S_rds_pcm =  S_dbpsk_wav_value;
            end else begin
               S_rds_pcm = ~S_dbpsk_wav_value; // TODO: Check if it's okay to use ~
            end
            // S_rds_pcm range: (-63 .. +63)
            if(rds_msg_len != C_rds_msg_disable) begin
               S_rds_mod_pcm = S_subc_pcm * S_rds_pcm;
            end else begin
               S_rds_mod_pcm = '0;
            end
            // S_rds_mod_pcm range: 63*63 = (-3969 .. +3969)
         end
      end
   endgenerate

   /* simple 57kHz mixer with multiplexer
      using 4 points coarse sampled subcarrier at 228 kHz
      no multiplication needed */
   generate 
      if (FINE_SUBC == 1'b0) begin: coarse_subcarrier
       /*sign manipulation with the multiplexer
         xor replaces calculating double minus
         with ( '0' xor R_subc_cdiv(4)) & R_subc_cdiv(3 downto 3) select -- debug*/
         always_comb begin
            case ({S_rds_sign ^ R_subc_cdiv[4], R_subc_cdiv[3]})
               2'b11: S_rds_coarse_pcm =  S_dbpsk_wav_value;
               2'b01: S_rds_coarse_pcm = ~S_dbpsk_wav_value;
               default: S_rds_coarse_pcm = 0;
            endcase
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
      if(FILTER == 1'b0) begin: no_lowpass_filter
      // no filtering, input is only divided by 2 to avoid overflows
      // at stereo mixing
         always_comb begin
            S_pcm_in_left_filter = pcm_in_left >> 1;
            S_pcm_in_right_filter = pcm_in_right >> 1; 
         end
      end
   endgenerate
   /*FM standard requires low pass filter for audio
     channels to cut off frequencies above 17kHz
     we'll try to approximate.
     besides filtering we have to attenuate signal (about x2),
     this is to aviod overflows at stereo mixing*/
     generate
        if(FILTER == 1'b1) begin: lowpass_filter
           always_comb begin
              if(S_rds_strobe == 1'b1 && R_pilot_cdiv == 0 && R_pilot_counter[1:0] == 2'b00)
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
        
        lowpass#(
           .C_bits_in(12),
           .C_attenuation(1), // attenuation 2^1 = 2x
           .C_bits_out(16) // 16-12 = 4-bit difference
        )filter_left(
           .clock(clk),
           .enable(S_filter_strobe), // 152 kHz
           .data_in(pcm_in_left[15:4]),
           .data_out(S_pcm_in_left_filter)
        );

         lowpass#(
           .C_bits_in(12),
           .C_attenuation(1), // attenuation 2^1 = 2x
           .C_bits_out(16) // 16-12 = 4-bit difference
         )filter_right(
           .clock(clk),
           .enable(S_filter_strobe), // 152 kHz
           .data_in(pcm_in_right[15:4]),
           .data_out(S_pcm_in_right_filter)
        );
        end
     endgenerate
     // ************ END LOW PASS FILTER **************

     generate
        if(DOWNSAMPLE == 1'b0) begin: no_downsample_38kHz
           // signal pass-through (direct wire)
           always_comb begin
              R_pcm_in_left_downsample = S_pcm_in_left_filter;
              R_pcm_in_right_downsample = S_pcm_in_right_filter;
           end
        end else if (DOWNSAMPLE == 1'b1) begin: downsample_38kHz
           always_ff @(posedge clk) begin
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
        if(STEREO == 1'b0) begin: mix_mono
        // mixing mono input audio with RDS DBPSK
           always_comb begin
              pcm_out = R_pcm_in_left_downsample + R_pcm_in_right_downsample + S_rds_mod_pcm;
           end
        end else if (STEREO == 1'b1)begin
           always_comb begin
           S_pcm_stereo = (R_pcm_in_left_downsample - R_pcm_in_right_downsample) * S_stereo_pcm;
           /* S_stereo_pcm has range -63 .. +63
              pcm_in_left has range -32767 .. +32767
              stereo mixing: we should divide by 4 because
              we mix L+R + (L-R)*sin(38kHz), that rises max amplitude 4 times
              but we divide by 2 and hope for no clipping*/
            pcm_out = R_pcm_in_left_downsample + R_pcm_in_right_downsample 
                      + (S_pcm_stereo[21:6]) // normalize S_stereo_pcm, shift divide by 64
                      + (S_pilot_pcm << 6)   // 16 is too weak, not sure of correct 19kHz pilot amplitude
                      + (S_rds_mod_pcm);
           end
         end
     endgenerate

     generate
        if(DEBUG == 1'b1) begin: rds_debug_output
           always_ff @(posedge clk) begin
              /*PCM data from RAM normally should have average 0 (removed DC offset)
                for purpose of PCM generation here is
                conversion to unsigned std_logic_vector
                by inverting MSB bit (effectively adding 0x8000)*/
              R_pcm_unsigned_data_l <= {~R_pcm_in_left_downsample[15], R_pcm_in_left_downsample[14:0]};
              R_pcm_unsigned_data_r <= {~R_pcm_in_right_downsample[15], R_pcm_in_right_downsample[14:0]};
              // Output 1-bit DAC
              R_dac_acc_l <= {R_dac_acc_l[16], R_pcm_unsigned_data_l} + R_dac_acc_l;
              R_dac_acc_r <= {R_dac_acc_r[16], R_pcm_unsigned_data_r} + R_dac_acc_r;
        end
        always_comb out_l = R_dac_acc_l[16];
        always_comb out_r = R_dac_acc_r[16];

        // out to check phases of subcarriers
        always_comb debug = {8'h00, 1'b0, S_stereo_pcm, 1'b0, S_pilot_pcm, 1'b0, S_rds_coarse_pcm};
      end
   endgenerate
endmodule

/* todo
   [x] when rds_msg_len = 0 disable RDS (only mono/stereo mixing)
   [x] compare rds with <= when size changes, it will reset if out of range
*/

/*
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/5/27 TH: Initial creation
 2024/5/28 TH: Revision

*/

