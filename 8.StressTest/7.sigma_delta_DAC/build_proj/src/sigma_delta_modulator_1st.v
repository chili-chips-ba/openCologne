module sigma_delta_modulator_1st (
    input wire clk,              // Clock signal
    input wire rst_n,            // Active-low reset
    input wire signed [15:0] in, // 16-bit input from the interpolating filter
    output reg out               // 1-bit PDM output
);

    // Internal signals
    wire [19:0] sd_in;

    reg signed [19:0] s1, y1;

    reg signed [19:0] r, s, y;

    localparam FULLSC = 19'd49152; // Full scale of 16 bit at +-150%

    assign sd_in = {{4{in[15]}}, in};

    always @* begin
        r = sd_in - y1;
        s = r + s1;
        y = (s[19] == 1'b0) ? FULLSC : - FULLSC;
    end

    // Sequential logic
    always @(posedge clk or negedge rst_n) begin
        if (rst_n == 1'b0) begin
            // Reset all registers to zero
            s1 <= 0;
            y1  <= 0;
            out <= 0;
        end else begin
            s1 <= s;
            y1 <= y;
            out <= ~y[19]; // Output '1' if MSB of w is '0', otherwise '0'
        end
    end

endmodule
