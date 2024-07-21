/*
#################################################################################################
#    << CologneChip GateMate ILA - Top-Level >>                                                 #
#    Setup ILA, integration of SUT and controls communication                                   #
# ********************************************************************************************* #
#    Copyright (C) 2023 Cologne Chip AG <support@colognechip.com>                               #
#    Developed by Dave Fohrn                                                                    #
#                                                                                               #
#    This program is free software: you can redistribute it and/or modify                       #
#    it under the terms of the GNU General Public License as published by                       #
#    the Free Software Foundation, either version 3 of the License, or                          #
#    (at your option) any later version.                                                        #
#                                                                                               #
#    This program is distributed in the hope that it will be useful,                            #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#    GNU General Public License for more details.                                               #
#                                                                                               #
#    You should have received a copy of the GNU General Public License                          #
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.                     #
#                                                                                               #
# ********************************************************************************************* #
#################################################################################################
*/

module ila_top#(
    parameter SIGNAL_SYNCHRONISATION = 0,
    parameter USE_USR_RESET = 0, 
    parameter USE_PLL = 1,
    parameter USE_FEATURE_PATTERN = 0,
    parameter samples_count_before_trigger = 64,
    parameter bits_samples_count_before_trigger = 5,
    parameter bits_samples_count = 8,
    parameter sample_width = 1,
    parameter external_clk_freq = "10.0",
    parameter sampling_freq_MHz = "2",
    parameter BRAM_matrix_wide = 1,
    parameter BRAM_matrix_deep = 1,
    parameter BRAM_single_wide = 5,
    parameter BRAM_single_deep = 12,
    parameter clk_delay = 2
)(
    (* clkbuf_inhibit *) input i_sclk_ILA,
    input i_mosi_ILA,
    output o_miso_ILA,
// #################################################################################################
// # ********************************************************************************************* #
// __Place~for~Signals~start__
input clk,
output led,
// __Place~for~Signals~ends__
// #################################################################################################
    // test Signals,
    //  input rst,
    // output [7:0] led,
    // test Signals ends
    input i_ss_ILA

    );

wire [(sample_width-1):0] sample;
wire clk0_2;
wire USR_RSTN;
reg hold_reset;
wire reset_DUT;
wire ILA_clk_src;
// #################################################################################################
// # ********************************************************************************************* #
// __Place~for~SUT~start__
assign ILA_clk_src = clk;
assign reset_DUT = USR_RSTN;
blink DUT (.ILA_rst(reset_DUT), .clk(clk), .led(led), .ila_sample_dut(sample));
// __Place~for~SUT~ends__
// #################################################################################################
//blink DUT ( .clk(i_clk), .rst(rst), .led(led), .ila_sample_dut(sample));
// cc PLL instance
wire clk270, clk180, clk90, clk0, i_clk_ILA, usr_ref_out_1;
wire usr_pll_lock_stdy_1, usr_pll_lock_1;
generate
    if (USE_PLL == 1) begin
        CC_PLL #(
        		.REF_CLK(external_clk_freq),    // reference input in MHz
        		.OUT_CLK(sampling_freq_MHz),   // pll output frequency in MHz
        		.PERF_MD("SPEED"), // LOWPOWER, ECONOMY, SPEED
        		.LOW_JITTER(1),      // 0: disable, 1: enable low jitter mode
        		.CI_FILTER_CONST(2), // optional CI filter constant
        		.CP_FILTER_CONST(4)  // optional CP filter constant
        	) pll_inst_ila (
        		.CLK_REF(ILA_clk_src), .CLK_FEEDBACK(1'b0), .USR_CLK_REF(1'b0),
        		.USR_LOCKED_STDY_RST(1'b0), .USR_PLL_LOCKED_STDY(usr_pll_lock_stdy_1), .USR_PLL_LOCKED(usr_pll_lock_1),
        		.CLK270(clk270), .CLK180(clk180), .CLK90(clk90), .CLK0(clk0), .CLK_REF_OUT(usr_ref_out_1)
        	);
            if (clk_delay == 0) begin
                assign i_clk_ILA = clk0;
            end
            else if (clk_delay == 1) begin
                assign i_clk_ILA = clk90;
            end
            else if (clk_delay == 2) begin
                assign i_clk_ILA = clk180;
            end
            else begin
                assign i_clk_ILA = clk270;
            end
        end else begin
            assign i_clk_ILA = ILA_clk_src;
        end
endgenerate



CC_USR_RSTN usr_rstn_inst (
   .USR_RSTN(USR_RSTN) // reset signal to CPE array
);

// Communication of the ILA

// SPI-Slave

wire [3:0] spi_nib_send, spi_nib_receive;
wire config_ILA;
wire s_s_rec_nib_ready;
reg read_active;
wire write_done;
spi_slave spi_passiv (.i_sclk(i_sclk_ILA), 
                .i_ss(i_ss_ILA), 
                .i_echo(!write_done), 
                .i_mosi(i_mosi_ILA), 
                .o_miso(o_miso_ILA), 
                .i_nib_send(spi_nib_send), 
                .o_rec_nib_ready(s_s_rec_nib_ready), 
                .o_nib_rec(spi_nib_receive));

reg ila_reset_register_clk, ila_reset_register_sclk, clk_reset_check;                                     // Register to reset the ILA from SPI

reg sclk_reset_check = 0;

// Processing of the received commands

wire change_trigger_hold;
wire ready_read;

assign ready_read = ((!config_ILA) & s_s_rec_nib_ready);



// Processing SPI command: ILA reset

wire ila_reset_signal;


rec_cmd_nib #(  .ADDR(4'b0110)) 
ila_restart (   .i_clk(i_sclk_ILA), 
                .i_wr_en(ready_read), 
                .i_nib(spi_nib_receive), 
                .o_hold(ila_reset_signal));

always @(posedge i_clk_ILA) begin
    if (ila_reset_signal | !USR_RSTN) begin
        ila_reset_register_clk <= 0;
    end else if (clk_reset_check) begin
        ila_reset_register_clk <= 1;
    end
end
always @(posedge i_clk_ILA) begin
    if (ila_reset_signal | !USR_RSTN) begin
        ila_reset_register_sclk <= 0;
    end else if (sclk_reset_check) begin
        ila_reset_register_sclk <= 1;
    end
end


always @(posedge i_clk_ILA) begin
    if (!ila_reset_register_clk) begin
        clk_reset_check <= 1;
    end else begin
        clk_reset_check <= 0;
    end
end

always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk) begin
        sclk_reset_check <= 1;
    end else begin
        sclk_reset_check <= 0;
    end
end

wire dut_reset_signal;
reg trigger_active_hold;

generate
    if (USE_USR_RESET == 1) begin
            
        rec_cmd_nib #(.ADDR(4'b1010)) 
        dut_reset ( .i_clk(i_sclk_ILA), 
                    .i_wr_en(ready_read), 
                    .i_nib(spi_nib_receive),
                    .o_hold(dut_reset_signal));

        always @(posedge i_sclk_ILA) begin
            if (!ila_reset_register_sclk | trigger_active_hold) begin
                hold_reset <= 1;
            end else if (dut_reset_signal) begin
                hold_reset <= !hold_reset;
            end 
        end

        assign reset_DUT = (!USR_RSTN) ? 0 : hold_reset;
        end
endgenerate
// Processing SPI command: set Trigger Signal

reg [5:0] trigger_column;
reg [5:0] trigger_row;
reg [1:0] trigger_activation;
reg conf_trigger_start = 0;

// set Trigger and aktivate all

rec_cmd_nib #(  .ADDR(4'b1001)) 
change_trigger (.i_clk(i_sclk_ILA), 
                .i_wr_en(ready_read), 
                .i_nib(spi_nib_receive),
                .o_hold(change_trigger_hold));


always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk | trigger_active_hold) begin
        conf_trigger_start <= 0;
    end else if (change_trigger_hold) begin
        conf_trigger_start <= 1;
    end
end

reg [1:0] state_trigger_conf;

wire conf_trigger_action;

wire conf_trigger_1, conf_trigger_2, conf_trigger_3, conf_trigger_4;

assign conf_trigger_action = conf_trigger_start & s_s_rec_nib_ready;

assign conf_trigger_1 = conf_trigger_action & (state_trigger_conf == 2'b00);
assign conf_trigger_2 = conf_trigger_action & (state_trigger_conf == 2'b01);
assign conf_trigger_3 = conf_trigger_action & (state_trigger_conf == 2'b10);
assign conf_trigger_4 = conf_trigger_action & (state_trigger_conf == 2'b11);

// counter 
always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk ) begin
        state_trigger_conf <= 0;
    end
    else if (conf_trigger_action) begin
        state_trigger_conf <= state_trigger_conf + 1;
    end
end

always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk) begin
        trigger_row <= 0;
    end
    else if (conf_trigger_1) begin
        trigger_row <= {spi_nib_receive, 2'b00};
    end else if (conf_trigger_2) begin
        trigger_row[1:0] <= spi_nib_receive[3:2];
    end
end

always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk) begin
        trigger_column <= 0;
    end
    else if (conf_trigger_2) begin
        trigger_column[5:4] <= spi_nib_receive[1:0];
    end
    else if (conf_trigger_3) begin
        trigger_column[3:0] <= spi_nib_receive;
    end
end

always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk) begin
        trigger_activation <= 0;
        trigger_active_hold <= 0;
    end
    else if (conf_trigger_4) begin
        trigger_activation <= spi_nib_receive[1:0];
        trigger_active_hold <= 1;
    end
end

/*
always @(posedge i_sclk_ILA) begin
if (!ila_reset_register_sclk) begin
    trigger_column <= 0;
        trigger_row <= 0;
        trigger_active_hold <= 0;
        trigger_activation <= 0;
        state_trigger_conf <= 0;
    end
    else if (conf_trigger_start & s_s_rec_nib_ready) begin // drei nibbel reinschiften
        case (state_trigger_conf)
            2'b00: begin
                trigger_row <= {spi_nib_receive, 2'b00};
                state_trigger_conf <= state_trigger_conf + 1;
            end
            2'b01: begin
                trigger_row[1:0] <= spi_nib_receive[3:2];
                trigger_column[5:4] <= spi_nib_receive[1:0];
                state_trigger_conf <= state_trigger_conf + 1;
            end
            2'b10: begin
                trigger_column[3:0] <= spi_nib_receive;
                state_trigger_conf <= state_trigger_conf + 1;
            end
            2'b11 : begin
                trigger_activation <= spi_nib_receive[1:0];
                trigger_active_hold <= 1;
            end
        endcase
    end
end
*/

// Processing SPI command: Starting the reading of the stored samples

wire ready_read_ram;


rec_cmd_nib #( .ADDR(4'b1100)) 
command_read ( .i_clk(i_sclk_ILA), 
               .i_wr_en(ready_read), 
               .i_nib(spi_nib_receive),
                .o_hold(ready_read_ram));
 

reg read_active_pipe;

always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk | read_active) begin
            read_active_pipe <= 0;
    end else if (ready_read_ram) begin
        read_active_pipe <= 1;
    end
end

always @(posedge i_sclk_ILA) begin
    if (!ila_reset_register_sclk) begin
        read_active <= 0;    
    end else if (read_active_pipe & s_s_rec_nib_ready) begin
        read_active <= 1;
    end
end



// Trigger detection

wire [(BRAM_single_wide-1):0] trigger_pipe_out;
reg [(BRAM_single_wide-1):0] trigger_pipe;

reg trigger;

always @(posedge i_clk_ILA) begin
    trigger <= trigger_pipe[trigger_column]; 
end

wire trigger_post_edge_1, trigger_nedge_edge_1;
reg trigger_post_edge, trigger_nedge_edge;


edge_detection trigger_edge (.i_clk(i_clk_ILA), .i_reset(ila_reset_register_clk), .i_signal(trigger), .o_post_edge(trigger_post_edge_1), .o_nedge_edge(trigger_nedge_edge_1));


always @(posedge i_clk_ILA) begin
    if (!ila_reset_register_clk) begin
        trigger_post_edge <= 0;
        trigger_nedge_edge <= 0;
    end
    else begin 
        trigger_post_edge <= trigger_post_edge_1;
        trigger_nedge_edge <= trigger_nedge_edge_1;
    end
end


wire trigger_detect;

// pattern compare

generate
    if (USE_FEATURE_PATTERN == 1) begin
        localparam nibble_sample = ((sample_width-1)/4)+1;
        reg [(sample_width-1):0] sample_source;
        reg trigger_detect_pattern_arrived;
        reg sample_pattern_arrived; 
        reg change_pattern_done;
        wire change_pattern_wire;
        reg change_pattern_hold;
        rec_cmd_nib #(
            .ADDR(4'b0011)
            ) change_pattern (
                .i_clk(i_sclk_ILA),
                .i_wr_en(ready_read), 
                .i_nib(spi_nib_receive),
                .o_hold(change_pattern_wire));

                reg set_pattern_done;
        
        always @(posedge i_sclk_ILA) begin
            if (!ila_reset_register_sclk | set_pattern_done) begin
                change_pattern_hold <= 0;
            end else if (change_pattern_wire) begin
                change_pattern_hold <= 1;
            end
        end

        reg [(nibble_sample*4)-1:0] bit_pattern_fit, bit_mask_fit; 
        reg set_mask;
        localparam rec_nibb_cn = (nibble_sample*2);
        localparam pattern_bit_count = $clog2(rec_nibb_cn); 
        reg [pattern_bit_count:0] counter_rec_pattern_byte;

        always @(posedge i_sclk_ILA) begin
            if (!ila_reset_register_sclk) begin
                set_mask <= 1;
                bit_pattern_fit <= 0;
                bit_mask_fit <= 0;
            end
            if (change_pattern_hold & s_s_rec_nib_ready) begin
                set_mask <= !set_mask;
                if (set_mask) begin
                    bit_pattern_fit <= {bit_pattern_fit[(nibble_sample*4)-5:0], spi_nib_receive};
                end
                else begin 
                    bit_mask_fit <= {bit_mask_fit[(nibble_sample*4)-5:0], spi_nib_receive};
                end
            
            end
        end
        always @(posedge i_sclk_ILA) begin
            if (!change_pattern_hold) begin
                counter_rec_pattern_byte <= 0;
                set_pattern_done <= 0;
            end
            else if (s_s_rec_nib_ready) begin
                if (counter_rec_pattern_byte == rec_nibb_cn) begin
                    set_pattern_done <= 1;
                end else begin
                    counter_rec_pattern_byte <= counter_rec_pattern_byte + 1;
                end
            end
        end



        genvar i;
        localparam pipes = ((sample_width+1)/2);
        localparam pipes_from_pipes = ((pipes+5)/6);
        localparam add_pipe = ((pipes_from_pipes) % 2);
        reg [(pipes_from_pipes+add_pipe-1):0] pattern_match_stage_3;
        reg [(pipes_from_pipes+add_pipe-1):0] pattern_match_stage_3_control = ~0;

        if (add_pipe == 1) begin
            
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_3[pipes_from_pipes] <= 1;
                end
            end 
        end
        reg [((pipes_from_pipes*6)-1):0] pattern_match_stage_1_1, pattern_match_stage_1_2, pattern_match_stage_2;
        reg [1:0] pattern_match_stage_4;
        reg [(pipes*2)-1:0] sample_target_fit;
        if ((sample_width % 2) == 1) begin
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    sample_target_fit <= 0;
                end
                else begin
                    sample_target_fit <= {1'b0, sample};
                end
            end
        end
        else begin
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    sample_target_fit <= 0;
                end
                else begin
                    sample_target_fit <= sample;
                end
            end
        end
        for (i = 0; i < (pipes*2); i = i+2) begin : loop
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_1_1[i/2] <= 0;
                end
                else begin
                    pattern_match_stage_1_1[i/2] <= (bit_mask_fit[i] | (sample_target_fit[i] == bit_pattern_fit[i]));
                end
            end
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_1_2[i/2] <= 0;
                end
                else begin
                    pattern_match_stage_1_2[i/2] <= ((bit_mask_fit[i+1] | (sample_target_fit[i+1] == bit_pattern_fit[i+1])));
                end
            end
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_2[i/2] <= 0;
                end
                else begin
                    pattern_match_stage_2[i/2] <= (pattern_match_stage_1_1[i/2] & pattern_match_stage_1_2[i/2]);
                end
            end
        end
        if ((pipes_from_pipes*6) > pipes) begin
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_2[((pipes_from_pipes*6)-1):pipes] <= ~0;
                    pattern_match_stage_1_1[((pipes_from_pipes*6)-1):pipes] <= ~0;
                    pattern_match_stage_1_2[((pipes_from_pipes*6)-1):pipes] <= ~0;
                end
            end 
        end
        for (i = 0; i < pipes_from_pipes; i = i+1) begin : loop2
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_3[i] <= 0;
                end
                else if (pattern_match_stage_2[((6*(i+1))-1):6*i] == 6'b111111) begin
                    pattern_match_stage_3[i] <= 1;
                end else begin
                    pattern_match_stage_3[i] <= 0;
                end
            end
        end
        for (i = 0; i < 2; i = i+1) begin : loop3
            always @(posedge i_clk_ILA) begin
                if (!ila_reset_register_clk) begin
                    pattern_match_stage_4[i] <= 0;
                end
                else if (pattern_match_stage_3[((((pipes_from_pipes+add_pipe)/2)*(1+i))-1):(((pipes_from_pipes+add_pipe)/2)*i)] == pattern_match_stage_3_control[((((pipes_from_pipes+add_pipe)/2)*(1+i))-1):(((pipes_from_pipes+add_pipe)/2)*i)]) begin
                    pattern_match_stage_4[i] <= 1;
                end else begin
                    pattern_match_stage_4[i] <= 0;
                end
            end
        end

        always @(posedge i_clk_ILA) begin
            if (!ila_reset_register_clk) begin
                trigger_detect_pattern_arrived <= 0;
            end
            else if (pattern_match_stage_4 == 2'b11) begin
                trigger_detect_pattern_arrived <= 1;
            end
            else begin
                trigger_detect_pattern_arrived <= 0;
            end
        end
        assign config_ILA = conf_trigger_start | change_pattern_hold;
        assign trigger_detect = (trigger_activation == 2'b01) ? trigger_post_edge : ((trigger_activation == 2'b00) ? trigger_nedge_edge : trigger_detect_pattern_arrived);
    end
    else begin
        assign config_ILA = conf_trigger_start;
        assign trigger_detect = (trigger_activation == 2'b01) ? trigger_post_edge :  trigger_nedge_edge;
    end

endgenerate

reg trigger_triggered = 0;

wire trigger_triggered_detect;

//always @(posedge i_clk_ILA) begin
//    if (!ila_reset_register_clk) begin
//        trigger_triggered_detect <= 0;
//    else if (trigger_active_hold) begin
//        trigger_triggered_detect <= trigger_detect;
//    end
//end


assign trigger_triggered_detect = trigger_active_hold & trigger_detect;

always @(posedge i_clk_ILA) begin
    if (!ila_reset_register_clk) begin
        trigger_triggered <= 0;
    end
    else if(trigger_triggered_detect) begin
        trigger_triggered <= 1;
    end
end


             
// memory management

wire [3:0] spi_data_send;

always @(posedge i_clk_ILA) begin
    if (!ila_reset_register_clk) begin
        trigger_pipe <= 0;
    end
    else begin 
        trigger_pipe <= trigger_pipe_out;
    end
end

bram_control #(.samples_count_before_trigger(samples_count_before_trigger), 
            .bits_samples_count_before_trigger(bits_samples_count_before_trigger),
            .bits_samples_count(bits_samples_count),
            .sample_width(sample_width),
            .BRAM_matrix_wide(BRAM_matrix_wide),
            .BRAM_matrix_deep(BRAM_matrix_deep),
            .BRAM_single_wide(BRAM_single_wide),
            .BRAM_single_deep(BRAM_single_deep),
            .SIGNAL_SYNCHRONISATION(SIGNAL_SYNCHRONISATION)) mem_control (.i_clk_ILA(i_clk_ILA), 
            .i_sclk(i_sclk_ILA),
            .i_reset(trigger_active_hold),
            .i_read_active(read_active),  
            .i_sample(sample), 
            .i_slave_end_byte_post_edge(s_s_rec_nib_ready), 
            .i_trigger_triggered(trigger_triggered), 
            .o_send_nib(spi_data_send),
            .o_write_done(write_done),
            .trigger_row(trigger_row),
            .trigger_out(trigger_pipe_out));

assign spi_nib_send = read_active ? spi_data_send : (read_active_pipe ? 4'b1110 : 4'b1010);

endmodule