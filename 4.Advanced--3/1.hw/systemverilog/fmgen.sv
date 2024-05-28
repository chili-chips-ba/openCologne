module fmgen#(
   parameter logic             USE_PCM_IN = 1,
   parameter int               FM_ACCLEN = 28, 
   /*modulation: how many Hz CW will swing when input changes by 1:
	    by FM standard, max CW swing is 75 kHz. Channels are 100 kHz apart.
	    16-bit signed input values have full range in -32767..+32767, for
	    1Hz/bit it makes 65 kHz swing and assures no overmodulation.
	    2Hz/bit allows full use of 75 kHz band swing but input value must
	    stay in range -18750..+18750 to prevent overmodulation. 
	    When changing c_hz_per_bit,
	    other RDS and pilot tone values must be scaled in rds.vhd*/
   parameter integer            HZ_PER_BIT = 2,
   parameter logic              REMOVE_DC = 1,
   parameter real               FDDS = 0
)(
   input  logic                 clk_pcm,
   input  logic                 clk_dds,
   input  logic                 cw_freq,
   input  logic [15:0]          pcm_in, 
   output logic                 fm_out
);
   typedef logic        [3:0]   fourbit_t;
   typedef logic signed [15:0]  sixteenbitsigned_t;

   logic signed [FM_ACCLEN-1:0] fm_acc;
   logic signed [FM_ACCLEN-1:0] fm_inc;
   logic signed [15:0]          R_pcm_avg;
   logic signed [15:0]          R_pcm_ac;
   integer                      R_cnt;
   logic signed [31:0]          R_dds_mul_x1;
   logic signed [31:0]          R_dds_mul_x2;
   logic signed [31:0]          C_dds_mul_y;
   logic signed [63:0]          R_dds_mul_res;

   initial begin // TODO: Check if this is okay, 2 WARNINGS
      C_dds_mul_y = $signed($floor((2.0**30 / FDDS) * 2.0**28));
   end

   always_comb R_pcm_ac = pcm_in - R_pcm_avg; // subtract average to remove DC offset
   generate
      if(REMOVE_DC) begin: remove_dc_offset
         always_ff @(posedge clk_pcm) begin
            static logic [3:0] R_clk_div = '0;
            R_clk_div <= fourbit_t'(R_clk_div + fourbit_t'(1));
            if (R_clk_div == 4'b0000) begin
               if(R_pcm_ac > '0) begin
                  R_pcm_avg <= sixteenbitsigned_t'(R_pcm_avg + sixteenbitsigned_t'(1));
               end else if (R_pcm_ac < '0) begin
                  R_pcm_avg <= sixteenbitsigned_t'(R_pcm_avg - sixteenbitsigned_t'(1));
               end
            end
         end
      end
   endgenerate

    
   // Calculate current frequency of carrier wave (Frequency modulation)
   // Removing DC offset

   always_ff @(posedge clk_pcm) begin
      R_dds_mul_x1 <= $signed(cw_freq) + R_pcm_ac * HZ_PER_BIT;
   end

   // Generate carrier wave
   
   always_ff@ (posedge clk_dds) begin
      // Cross clock domains
      R_dds_mul_x2 <= R_dds_mul_x1;
      R_dds_mul_res <= R_dds_mul_x2 * C_dds_mul_y;
      fm_inc <= R_dds_mul_res[57:58-FM_ACCLEN];
      fm_acc <= fm_acc + fm_inc;
   end

   always_comb fm_out = fm_acc[FM_ACCLEN-1];
 
endmodule