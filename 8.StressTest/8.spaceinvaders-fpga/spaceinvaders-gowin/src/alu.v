//ALU of intel 8080
//Arithmetic: ADD,SUB,INR,DCR
//Logic: AND,OR,XOR
module alu(
	input [7:0]    	in_a, 
	input [7:0]    	in_dst,
	input			in_c, 
	input			op_inr,
	input			op_dcr,
	input			op_add,
	input			op_adc,
	input			op_sub,
	input			op_sbc,
	input			op_and,
	input			op_or,
	input			op_xor,
	output [7:0]	out,
	output			out_c,
	output			out_a,
	output			out_z,
	output			out_s,
	output			out_p
);
wire [7:0] in_1 = (op_inr|op_dcr)? in_dst : in_a;
wire [7:0] in_2 = (op_inr|op_dcr)? 8'h00  : in_dst;
wire in_carry   = (op_inr|op_dcr)? 1'b1 : 1'b0|
				  (op_adc|op_sbc)? in_c : 1'b0; 

wire do_add = op_add|op_adc|op_inr;
wire do_sub = op_sub|op_sbc|op_dcr;

wire [4:0] r_add_l = in_1[3:0]+in_2[3:0]+in_carry;
wire [4:0] r_add_h = in_1[7:4]+in_2[7:4]+r_add_l[4];
wire [4:0] r_sub_l = in_1[3:0]-in_2[3:0]-in_carry;
wire [4:0] r_sub_h = in_1[7:4]-in_2[7:4]-r_sub_l[4];
wire [7:0]  r_and  = in_1 & in_2;
wire [7:0]  r_or   = in_1 | in_2;
wire [7:0]  r_xor  = in_1 ^ in_2;

assign out = do_add ? {r_add_h[3:0],r_add_l[3:0] }: 8'h00|
			 do_sub ? {r_sub_h[3:0],r_sub_l[3:0] }: 8'h00|
			 op_and ? r_and : 8'h00|
			 op_or  ? r_or  : 8'h00|
			 op_xor ? r_xor : 8'h00;

assign out_c = do_add ? r_add_h[4] : 1'b0|
               do_sub ? r_sub_h[4] : 1'b0;

assign out_a = do_add ? r_add_l[4] : 1'b0|
               do_sub ? r_sub_l[4] : 1'b0;

assign out_z = (out==8'h00);
assign out_s = out[7];
assign out_p = ~(out[7]^out[6]^out[5]^out[4]^out[3]^out[2]^out[1]^out[0]);

endmodule
