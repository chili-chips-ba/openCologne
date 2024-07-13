`timescale 1 ns/10 ps

//  Simulation der Logik:
//  iverilog -D sim -o ILA_top_tb.vvp sim/blink.v sim/ILA_top_tb.v sim/SPI_master.v src/storage/* src/*.v 
//  vvp ILA_top_tb.vvp -lxt2
//
// Post-Synthse:
// iverilog -Winfloop -g2012 -gspecify -Ttyp -o sim/synth_sim.vvp ../../bin/yosys/share/gatemate/cells_sim.v net/ila_top_synth24-06-26_18-05-41.v.v sim/ILA_top_tb.v sim/SPI_master.v
// vvp sim/synth_sim.vvp -lxt2
//
// Post-Implementation Symulation:
//
//  iverilog -Winfloop -g2012 -gspecify -Ttyp -o sim/impl_sim.vvp sim/fpga_ram/* ../../bin/p_r/cpelib.v p_r_out/ila_top_24-06-26_18-05-41.v sim/ILA_top_tb.v sim/SPI_master.v 
//  vvp sim/impl_sim.vvp -lxt2

// Within the module "cc_pll," the sampling frequency needs to be configured.
module CC_PLL #(
  parameter PLL_CFG = 96'b0,
  parameter REF_CLK = "", // e.g. "10.0"
  parameter OUT_CLK = "", // e.g. "50.0"
  parameter PERF_MD = "", // LOWPOWER, ECONOMY, SPEED
  parameter LOW_JITTER = 1,
  parameter CI_FILTER_CONST = 2,
  parameter CP_FILTER_CONST = 4
  )(
  input CLK_REF, CLK_FEEDBACK, USR_CLK_REF,
  input USR_LOCKED_STDY_RST, USR_SET_SEL,
  output USR_PLL_LOCKED_STDY, USR_PLL_LOCKED,
  output CLK270, CLK180, CLK90, CLK0, CLK_REF_OUT
  );

  //parameter clk_freq = 40000000; // 40 MHz clk 
  reg clk_out;
  always 
  begin  
    clk_out <= 1'b1;
    #25.5;// (1.0/40000000/2);
    clk_out <= 1'b0;
    #25.5;//(1.0/40000000/2);
  end
  assign CLK180 = clk_out;
  assign CLK0 = clk_out;
  endmodule

  `ifdef sim
 module CC_BUFG (
   input I,
   output O);
   assign O = I;
 endmodule
 `endif
 module CC_USR_RSTN (
  output reg USR_RSTN);
  initial
    begin
      USR_RSTN <= 0;
      #2000;
      USR_RSTN <= 1;
    end
endmodule


module ila_top_tb;
// #################################################################################################
// # ********************************************************************************************* #
    // Implement Logik for SUT
	wire  led_w;
// #################################################################################################
    // ILA configuration

  parameter bits_samples_count = 9;
  parameter sampling_freq_MHz = "10.0";
  parameter samples_count = 2**(bits_samples_count+1);
  parameter sample_width = 25;
  parameter PK_PER_DATA = ((sample_width-1)/4)+1;
  parameter all_bytes = PK_PER_DATA*samples_count;
  parameter send_pattern_true = 0;
  parameter BRAM_matrix_wide = 1;
  parameter BRAM_matrix_deep = 1;
  reg clk_ILA, spi_clk, reset_r;
  wire ss_r, miso_r, mosi_r;
  wire rst_sig = 1;

    ila_top 
    #(
      .SIGNAL_SYNCHRONISATION(0),
      .USE_USR_RESET(1),
      .USE_PLL(0),
      .USE_FEATURE_PATTERN(1),
      .samples_count_before_trigger(128),
      .bits_samples_count_before_trigger(6),
      .bits_samples_count(8),
      .sample_width(sample_width), 
      .external_clk_freq("10.0"),
      .sampling_freq_MHz(sampling_freq_MHz),
      .BRAM_matrix_wide(BRAM_matrix_wide),
      .BRAM_matrix_deep(BRAM_matrix_deep),
      .BRAM_single_wide(40),
      .BRAM_single_deep(10),
      .clk_delay(2)
      ) 
      UUT ( 
        .i_sclk_ILA(spi_clk), 
        .i_ss_ILA(ss_r), 
        .i_mosi_ILA(mosi_r), 
        .o_miso_ILA(miso_r), 
// #################################################################################################
// # ********************************************************************************************* #
    // Input and output ports of the SUT 
        .led(led_w),
        .clk(clk_ILA) 
// #################################################################################################        
        );

    reg send_r, spi_receive_byte;
    reg [7:0] byte_to_send;
    wire [7:0] spy_rec_byte;
    wire spi_periode, cnt_end;

    SPI_master spi_m (.i_sclk(spi_clk), .i_reset(reset_r), .o_ss(ss_r), .o_mosi(mosi_r), .i_miso(miso_r), 
                      .i_send(send_r), .i_send_byte(byte_to_send), .i_receive(spi_receive_byte), .o_receive_byte(spy_rec_byte),
                      .o_period(spi_periode), .o_cnt_end(cnt_end));

always   // 10 MHz 
begin  
  clk_ILA = 1'b1;
  #50;
  clk_ILA = 1'b0;
  #50;
end

initial
begin

  $display("All defined samples: %d", samples_count);
  $display("all defined bytes: %d", all_bytes);
  $display("nibble per Sample: %d", PK_PER_DATA);
    reset_r = 0;
    #3000;
    reset_r = 1;
end


always   // 10 MHz SPI_clk
begin  
  spi_clk = 1'b1;
  #50;
  spi_clk = 1'b0;
  #50;
end

// zu senden
// Reset_ILA: 0110
// Reset_DUT: 1010
// trigger und aktive: 1001
// Read_active: 1100
// Change_patterm: 0011

parameter bytes_to_send = ((sample_width-1)/4)+1;
parameter rest = ((bytes_to_send*4)-sample_width);

reg [(bytes_to_send*4)-1:0] bit_pattern = {{rest{1'b1}} ,25'b1111111111111110000010101};
reg [(bytes_to_send*4)-1:0] bit_maske =   {{rest{1'b1}}, 25'b1111111111111110000000000};
parameter [3:0] Reset_ILA = 0,
                Reset_DUT = 1,
                change_pattern_start = 2,
                send_pattern = 3,
                shift_pattern = 4,
                Trigger_signal_1 = 5,
                Trigger_signal_2 = 6,
                Trigger_activarion = 7,
                wait_for_trigger = 8,
                start_receive = 9,
                wait_for_cnt_end = 10,
                st_spi_first_byte = 11,
                s_receive_Signals = 12,
                get_data_1 = 13,
                break_trig = 14,
                get_data_2 = 15
                ;

reg [3:0] st_ila = Reset_ILA;
integer count_shift_pattern = 0;

// drum herum immer ein run und break

reg run_break = 0;
integer count_break;

reg [11:0] trigger_data = 12'b000000000001;
reg [5:0] trigger_row = 6'b00000;
reg [5:0] trigger_column = 6'b000001;

reg [7:0] trigger_activation = 8'b00100000;
integer counter_samples = 0;

integer byte_counter_spi;
integer counter_rec_bytes_spi;
reg start_new;

parameter receive_bits = (PK_PER_DATA*4)-1;
reg [receive_bits:0] rec_data;

always @(posedge spi_clk) begin
  if (!reset_r) begin
    st_ila <= Reset_ILA;
    run_break <= 0;
    count_break <= 0;
  end
  else if (!run_break) begin 
    case (st_ila) 
      Reset_ILA : begin
        send_r <= 1;
        spi_receive_byte <= 1'b0;
        byte_to_send <= 8'b01100110;
        if (spi_periode) begin
          st_ila <= Reset_DUT;
          run_break <= 1;
        end
      end
      Reset_DUT : begin
        byte_to_send <= 8'b10100000;
        send_r <= 1;
        spi_receive_byte <= 1'b0;
        if (spi_periode) begin
          st_ila <= change_pattern_start;
          run_break <= 1;
        end
      end
      change_pattern_start : begin
        byte_to_send <= 8'b00110011;//{4'b0011, bit_maske[(bytes_to_send*4)-1:(bytes_to_send*4)-4]};
        send_r <= 1;
        spi_receive_byte <= 1'b0;
        count_shift_pattern <= 0;
        if (spi_periode) begin
          st_ila <= send_pattern;
        end
      end
      send_pattern : begin
        byte_to_send <= {bit_maske[(bytes_to_send*4)-1:(bytes_to_send*4)-4], bit_pattern[(bytes_to_send*4)-1:(bytes_to_send*4)-4]};
        if (spi_periode) begin
          if (count_shift_pattern < (bytes_to_send)) begin
            st_ila <= shift_pattern;
          end
          else begin
            st_ila <= Trigger_signal_1;
            run_break <= 1;
        end
      end
    end
    shift_pattern : begin
      bit_pattern <= {bit_pattern[(bytes_to_send*4)-5:0], 4'b0000};
      bit_maske <= {bit_maske[(bytes_to_send*4)-5:0], 4'b0000};
      count_shift_pattern <= count_shift_pattern +1;
      st_ila <= send_pattern;
    end
    Trigger_signal_1 : begin
      byte_to_send <= {4'b1001, trigger_row[5:2]};
      send_r <= 1;
      spi_receive_byte <= 1'b0;
      if (spi_periode) begin
        st_ila <= Trigger_signal_2;
      end
    end
    Trigger_signal_2 : begin
      byte_to_send <= {trigger_row[1:0], trigger_column};
      if (spi_periode) begin
        st_ila <= Trigger_activarion; //change_trigger_activation;
      end
    end
    Trigger_activarion : begin
      byte_to_send <= trigger_activation;
      if (spi_periode) begin
        run_break <= 1;
        st_ila <= wait_for_trigger;
      end
    end
    wait_for_trigger : begin
      spi_receive_byte <= 1'b1;
      send_r <= 0;
      if (spi_periode) begin
          if (spy_rec_byte == 8'b01010101) begin 
            st_ila <= start_receive;
            run_break <= 1;
          end
      end
    end
    start_receive : begin
      spi_receive_byte <= 1'b0;
      send_r <= 1;
      byte_to_send <= 8'b11001100;
      counter_rec_bytes_spi <= 0;
        st_ila <= wait_for_cnt_end;
    end
    wait_for_cnt_end : begin
      spi_receive_byte <= 1'b1;
      send_r <= 0;
      byte_to_send <= 0;
      if (cnt_end) begin    // first_byte_start_of
        st_ila <= st_spi_first_byte;
        byte_counter_spi <= 0;
      end
    end
    st_spi_first_byte : begin
      if (cnt_end) begin    // first_byte_start_of
          st_ila <= s_receive_Signals;
          byte_counter_spi <= 0;
          counter_samples <= 0;
        end
      end
    s_receive_Signals : begin
      spi_receive_byte <= 1'b1;
      send_r <= 0;
      if(cnt_end) begin
        st_ila <= get_data_1;
      end
    end
    get_data_1 : begin
        if (byte_counter_spi < (PK_PER_DATA-1)) begin
          byte_counter_spi <= byte_counter_spi +1;
        end
        else begin 
          byte_counter_spi <= 0;
          counter_samples <= counter_samples +1;
          if (PK_PER_DATA > 1) begin
            $display("%d: sample: %h", counter_samples, {spy_rec_byte[7:4], rec_data[receive_bits:4]});
          end else begin
            $display("%d: sample: %h", counter_samples, spy_rec_byte[7:4]);
          end 
        end
        if (PK_PER_DATA > 1) begin
          rec_data <= {spy_rec_byte[7:4], rec_data[receive_bits:4]};
        end 


        if (counter_rec_bytes_spi < all_bytes) begin
          counter_rec_bytes_spi <= counter_rec_bytes_spi +1; 
          st_ila <= get_data_2;
        end
        else begin
          st_ila <= Reset_ILA;
          run_break <= 1;
        end
      end
      get_data_2 : begin
        if (byte_counter_spi < (PK_PER_DATA-1)) begin
          byte_counter_spi <= byte_counter_spi +1;
        end
        else begin 
          byte_counter_spi <= 0;
          counter_samples <= counter_samples +1;
          if (PK_PER_DATA > 1) begin
            $display("%d: sample: %h", counter_samples, {spy_rec_byte[3:0], rec_data[receive_bits:4]});
          end else begin
            $display("%d: sample: %h", counter_samples, spy_rec_byte[3:0]);
          end 
        end
        if (PK_PER_DATA > 1) begin
          rec_data <= {spy_rec_byte[3:0], rec_data[receive_bits:4]};
        end 


        if (counter_rec_bytes_spi < all_bytes) begin
          counter_rec_bytes_spi <= counter_rec_bytes_spi +1; 
          st_ila <= s_receive_Signals;
        end
        else begin
          st_ila <= Reset_ILA;
          run_break <= 1;
        end
      end
    endcase
  end else begin
    send_r <= 0;
    spi_receive_byte <= 1'b0;
    if (count_break < 8) begin 
      count_break <= count_break +1; 
    end
    else begin
      count_break <= 0;
      run_break <= 0;
    end
  end
end


integer idx;
    initial
 begin
    $dumpfile("ila_top_tb.vcd");
    $dumpvars(0,ila_top_tb);
    `ifdef sim
    for (idx = 0; idx < BRAM_matrix_deep; idx = idx + 1) begin
      $dumpvars(0,UUT.mem_control.BRAM_do_tmp[idx]);
    end
    for (idx = 0; idx < BRAM_matrix_wide; idx = idx + 1) begin
      $dumpvars(1,UUT.mem_control.data_in_pipe[idx]);
    end
      
    `endif
 end
 initial begin
    #2000000;
    $finish;
end


endmodule