module interpolatingFilterOrg (
    input         clk,
    input         clk_enable,
    input         reset,
    input  signed [15:0] input_data,
    output signed [15:0] output_data,
    output        ce_out
);

    // Signal Declarations
    wire signed [15:0] filter_in_stage1;
    wire signed [20:0] filter_out_stage1;
    wire ce_out_stage1, clk_enable_stage1;
    wire signed [20:0] filter_in_stage2;
    wire signed [19:0] filter_out_stage2;
    wire ce_out_stage2, clk_enable_stage2;
    wire signed [19:0] filter_in_stage3;
    wire signed [17:0] filter_out_stage3;
    wire ce_out_stage3, clk_enable_stage3;
    wire signed [17:0] filter_in_stage4;
    wire signed [18:0] filter_out_stage4;
    wire ce_out_stage4, clk_enable_stage4;
    wire signed [18:0] filter_in_stage5;
    wire signed [17:0] filter_out_stage5;
    wire ce_out_stage5, clk_enable_stage5;
    wire signed [17:0] filter_in_stage6;
    wire signed [16:0] filter_out_stage6;
    wire ce_out_stage6, clk_enable_stage6;
    wire signed [16:0] filter_in_stage7;
    wire signed [15:0] filter_out_stage7;
    wire ce_out_stage7, clk_enable_stage7;

    // Instantiate Filter Stages
    halfBandFirstOrg stage1 (
        .clk(clk),
        .clk_enable(clk_enable_stage1),
        .reset(reset),
        .filter_in(filter_in_stage1),
        .filter_out(filter_out_stage1),
        .ce_out(ce_out_stage1)
    );

    halfBandSecondOrg stage2 (
        .clk(clk),
        .clk_enable(clk_enable_stage2),
        .reset(reset),
        .filter_in(filter_in_stage2),
        .filter_out(filter_out_stage2),
        .ce_out(ce_out_stage2)
    );

    inverseSincOrg stage3 (
        .clk(clk),
        .clk_enable(clk_enable_stage3),
        .reset(reset),
        .filter_in(filter_in_stage3),
        .filter_out(filter_out_stage3),
        .ce_out(ce_out_stage3)
    );

    cic1 stage4 (
        .clk(clk),
        .clk_enable(clk_enable_stage4),
        .reset(reset),
        .filter_in(filter_in_stage4),
        .filter_out(filter_out_stage4),
        .ce_out(ce_out_stage4)
    );

    cic2 stage5 (
        .clk(clk),
        .clk_enable(clk_enable_stage5),
        .reset(reset),
        .filter_in(filter_in_stage5),
        .filter_out(filter_out_stage5),
        .ce_out(ce_out_stage5)
    );

    cic3 stage6 (
        .clk(clk),
        .clk_enable(clk_enable_stage6),
        .reset(reset),
        .filter_in(filter_in_stage6),
        .filter_out(filter_out_stage6),
        .ce_out(ce_out_stage6)
    );

    cic4 stage7 (
        .clk(clk),
        .clk_enable(clk_enable_stage7),
        .reset(reset),
        .filter_in(filter_in_stage7),
        .filter_out(filter_out_stage7),
        .ce_out(ce_out_stage7)
    );

    // Wiring Between Stages
    assign filter_in_stage1 = input_data;
    assign filter_in_stage2 = filter_out_stage1;
    assign filter_in_stage3 = filter_out_stage2;
    assign filter_in_stage4 = filter_out_stage3;
    assign filter_in_stage5 = filter_out_stage4;
    assign filter_in_stage6 = filter_out_stage5;
    assign filter_in_stage7 = filter_out_stage6;

    assign output_data = filter_out_stage7;

    // Cascaded clk_enable Signals
    assign clk_enable_stage7 = clk_enable;
    assign clk_enable_stage6 = ce_out_stage7;
    assign clk_enable_stage5 = ce_out_stage6;
    assign clk_enable_stage4 = ce_out_stage5;
    assign clk_enable_stage3 = ce_out_stage4;
    assign clk_enable_stage2 = ce_out_stage3;
    assign clk_enable_stage1 = ce_out_stage2;

    assign ce_out = ce_out_stage1;

endmodule
