module top (
    input wire clk_10MHz,
    input wire areset_n,
    output wire led,
    inout wire i2c_scl,
    inout wire i2c_sda
);

//--------------------------------
// Strobe Generator for 100kHz
//--------------------------------
    localparam integer NUM_CLK_FOR_100kHZ = 50;
    localparam integer COUNTER_WIDTH = 24;

    reg [$clog2(NUM_CLK_FOR_100kHZ)-1:0] cnt_100kHz;
    reg strobe_100kHz;

// Strobe generation logic
    always @(posedge clk_10MHz or negedge areset_n) begin
        if (!areset_n) begin
            cnt_100kHz    <= 0;
            strobe_100kHz <= 1'b0;
        end
        else begin
            if (cnt_100kHz == NUM_CLK_FOR_100kHZ-1) begin
                cnt_100kHz    <= 0;
                strobe_100kHz <= 1'b1;
            end
            else begin
                cnt_100kHz    <= cnt_100kHz + 1;
                strobe_100kHz <= 1'b0;
            end
        end
    end

//--------------------------------
// LED Blinking Logic
//--------------------------------
    reg [COUNTER_WIDTH-1:0] counter;

    always @(posedge clk_10MHz or negedge areset_n) begin
        if (!areset_n) begin
            counter <= 0;
        end else begin
            counter <= counter + 1;
        end
    end

    assign led = counter[COUNTER_WIDTH-1];

//--------------------------------
// I2C Top Module Instantiation
//--------------------------------
    i2c_top #(
        .I2C_SLAVE_ADDR(7'd52) // 0x34h
    ) u_i2c_top (
        .clk(clk_10MHz),
        .strobe_100kHz(strobe_100kHz),
        .areset_n(areset_n),
        .i2c_scl(i2c_scl),
        .i2c_sda(i2c_sda)
    );

endmodule // top
