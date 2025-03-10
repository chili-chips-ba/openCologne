//Intel 8080 CPU
module i8080(
	input     			i_rst,		//reset
	input	 			i_clk,		//clock 25 MHz
	input  				i_ready,	//ready for next instruction 
	output reg  		o_io, 		//io or memory access
	output reg [15:0] 	o_addr,		//address
	input  [7:0]    	i_dat_r,	//data read
	output reg  		o_read, 	//read strobe
	output reg [7:0] 	o_dat_w,	//data write
	output reg  		o_write, 	//write strobe
	input  				i_int, 		//interrupt	request
	output reg 			o_inta		//interrupt acknoledge
);

// Intel 8080 Instruction set
wire [7:0] r_src = (r_ir[2:0]==3'b000)? r_b:8'h00|
                   (r_ir[2:0]==3'b001)? r_c:8'h00|
                   (r_ir[2:0]==3'b010)? r_d:8'h00|
                   (r_ir[2:0]==3'b011)? r_e:8'h00|
                   (r_ir[2:0]==3'b100)? r_h:8'h00|
                   (r_ir[2:0]==3'b101)? r_l:8'h00|
                   (r_ir[2:0]==3'b111)? r_a:8'h00;

wire [7:0] r_dst = (r_ir[5:3]==3'b000)? r_b:8'h00|
                   (r_ir[5:3]==3'b001)? r_c:8'h00|
                   (r_ir[5:3]==3'b010)? r_d:8'h00|
                   (r_ir[5:3]==3'b011)? r_e:8'h00|
                   (r_ir[5:3]==3'b100)? r_h:8'h00|
                   (r_ir[5:3]==3'b101)? r_l:8'h00|
                   (r_ir[5:3]==3'b111)? r_a:8'h00;

wire [15:0] r_src_ss = (r_ir[5:4] == 2'b00) ? r_bc: 16'h00|
                       (r_ir[5:4] == 2'b01) ? r_de: 16'h00|
                       (r_ir[5:4] == 2'b10) ? r_hl: 16'h00|
                       (r_ir[5:4] == 2'b11) ? r_sp: 16'h00;

//*****************************************************************************
//MOVE, LOAD, AND STORE
//*****************************************************************************

//MOV r1,r2
//move register to register
wire op_mov_b_a = (r_ir == 8'h47);
wire op_mov_b_b = (r_ir == 8'h40);
wire op_mov_b_c = (r_ir == 8'h41);
wire op_mov_b_d = (r_ir == 8'h42);
wire op_mov_b_e = (r_ir == 8'h43);
wire op_mov_b_h = (r_ir == 8'h44);
wire op_mov_b_l = (r_ir == 8'h45);
wire op_mov_b_r = op_mov_b_a|op_mov_b_b|op_mov_b_c|op_mov_b_d|op_mov_b_e|op_mov_b_h|op_mov_b_l|op_mov_b_h;

wire op_mov_c_a = (r_ir == 8'h4F);
wire op_mov_c_b = (r_ir == 8'h48);
wire op_mov_c_c = (r_ir == 8'h49);
wire op_mov_c_d = (r_ir == 8'h4A);
wire op_mov_c_e = (r_ir == 8'h4B);
wire op_mov_c_h = (r_ir == 8'h4C);
wire op_mov_c_l = (r_ir == 8'h4D);
wire op_mov_c_r = op_mov_c_a|op_mov_c_b|op_mov_c_c|op_mov_c_d|op_mov_c_e|op_mov_c_h|op_mov_c_l|op_mov_c_h;

wire op_mov_d_b = (r_ir == 8'h50);
wire op_mov_d_c = (r_ir == 8'h51);
wire op_mov_d_d = (r_ir == 8'h52);
wire op_mov_d_e = (r_ir == 8'h53);
wire op_mov_d_h = (r_ir == 8'h54);
wire op_mov_d_l = (r_ir == 8'h55);
wire op_mov_d_a = (r_ir == 8'h57);
wire op_mov_d_r = op_mov_d_a|op_mov_d_b|op_mov_d_c|op_mov_d_d|op_mov_d_e|op_mov_d_h|op_mov_d_l|op_mov_d_h;

wire op_mov_e_a = (r_ir == 8'h5F);
wire op_mov_e_b = (r_ir == 8'h58);
wire op_mov_e_c = (r_ir == 8'h59);
wire op_mov_e_d = (r_ir == 8'h5A);
wire op_mov_e_e = (r_ir == 8'h5B);
wire op_mov_e_h = (r_ir == 8'h5C);
wire op_mov_e_l = (r_ir == 8'h5D);
wire op_mov_e_r = op_mov_e_a|op_mov_e_b|op_mov_e_c|op_mov_e_d|op_mov_e_e|op_mov_e_h|op_mov_e_l|op_mov_e_h;

wire op_mov_h_b = (r_ir == 8'h60);
wire op_mov_h_c = (r_ir == 8'h61);
wire op_mov_h_d = (r_ir == 8'h62);
wire op_mov_h_e = (r_ir == 8'h63);
wire op_mov_h_h = (r_ir == 8'h64);
wire op_mov_h_l = (r_ir == 8'h65);
wire op_mov_h_a = (r_ir == 8'h67);
wire op_mov_h_r = op_mov_h_a|op_mov_h_b|op_mov_h_c|op_mov_h_d|op_mov_h_e|op_mov_h_h|op_mov_h_l|op_mov_h_h;

wire op_mov_l_a = (r_ir == 8'h6F);
wire op_mov_l_b = (r_ir == 8'h68);
wire op_mov_l_c = (r_ir == 8'h69);
wire op_mov_l_d = (r_ir == 8'h6A);
wire op_mov_l_e = (r_ir == 8'h6B);
wire op_mov_l_h = (r_ir == 8'h6C);
wire op_mov_l_l = (r_ir == 8'h6D);
wire op_mov_l_r = op_mov_l_a|op_mov_l_b|op_mov_l_c|op_mov_l_d|op_mov_l_e|op_mov_l_h|op_mov_l_l|op_mov_l_h;

wire op_mov_a_a = (r_ir == 8'h7F);
wire op_mov_a_b = (r_ir == 8'h78);
wire op_mov_a_c = (r_ir == 8'h79);
wire op_mov_a_d = (r_ir == 8'h7A);
wire op_mov_a_e = (r_ir == 8'h7B);
wire op_mov_a_h = (r_ir == 8'h7C);
wire op_mov_a_l = (r_ir == 8'h7D);
wire op_mov_a_r = op_mov_a_a|op_mov_a_b|op_mov_a_c|op_mov_a_d|op_mov_a_e|op_mov_a_h|op_mov_a_l|op_mov_a_h;

//MOV M,r
//move register to memory
wire op_mov_m_a = (r_ir == 8'h77);
wire op_mov_m_b = (r_ir == 8'h70);
wire op_mov_m_c = (r_ir == 8'h71);
wire op_mov_m_d = (r_ir == 8'h72);
wire op_mov_m_e = (r_ir == 8'h73);
wire op_mov_m_h = (r_ir == 8'h74);
wire op_mov_m_l = (r_ir == 8'h75);
wire op_mov_m_r = op_mov_m_a|op_mov_m_b|op_mov_m_c|op_mov_m_d|op_mov_m_e|op_mov_m_h|op_mov_m_l;

//MOV r,M
//move memory to register
wire op_mov_a_m = (r_ir == 8'h7E);
wire op_mov_b_m = (r_ir == 8'h46);
wire op_mov_c_m = (r_ir == 8'h4E);
wire op_mov_d_m = (r_ir == 8'h56);
wire op_mov_e_m = (r_ir == 8'h5E);
wire op_mov_h_m = (r_ir == 8'h66);
wire op_mov_l_m = (r_ir == 8'h6E);
wire op_mov_r_m = op_mov_a_m|op_mov_b_m|op_mov_c_m|op_mov_d_m|op_mov_e_m|op_mov_h_m|op_mov_l_m;

//MVI r
//move immediate register
wire op_mvi_a = (r_ir == 8'h3E);
wire op_mvi_b = (r_ir == 8'h06);
wire op_mvi_c = (r_ir == 8'h0E);
wire op_mvi_d = (r_ir == 8'h16);
wire op_mvi_e = (r_ir == 8'h1E);
wire op_mvi_h = (r_ir == 8'h26);
wire op_mvi_l = (r_ir == 8'h2E);
wire op_mvi_r = op_mvi_a|op_mvi_b|op_mvi_c|op_mvi_d|op_mvi_e|op_mvi_h|op_mvi_l;

//MVI M
//move immediate memory
wire op_mvi_m   = (r_ir == 8'h36);

//LXI B, LXI D, LXI H
//load register pair BC, DE, HL
wire op_lxi_b  = (r_ir == 8'h01);
wire op_lxi_d  = (r_ir == 8'h11);
wire op_lxi_h  = (r_ir == 8'h21);

//STAX B, STAX D
//store A indirect 
wire op_stax_b = (r_ir == 8'h02);
wire op_stax_d = (r_ir == 8'h12);

//LDAX
//load a from memory location bc or de
wire op_ldax_b = (r_ir == 8'h0A);
wire op_ldax_d = (r_ir == 8'h1A);

//STA
//store A direct
wire op_sta    = (r_ir == 8'h32);

//LDA
//load A direct
wire op_lda    = (r_ir == 8'h3A);

//SHLD, LHLD
//store register pair HL direct
//load register pair HL direct 
wire op_shld = (r_ir == 8'h22);
wire op_lhld = (r_ir == 8'h2A);

//EX DE,HL
//Exchange the HL and DE register
wire op_xchg = (r_ir == 8'hEB);

//*****************************************************************************
//STACK OPS
//*****************************************************************************
wire op_push_b   = (r_ir == 8'hC5);
wire op_push_d   = (r_ir == 8'hD5);
wire op_push_h   = (r_ir == 8'hE5);
wire op_push_psw = (r_ir == 8'hF5);

wire op_pop_b   = (r_ir == 8'hC1);
wire op_pop_d   = (r_ir == 8'hD1);
wire op_pop_h   = (r_ir == 8'hE1);
wire op_pop_psw = (r_ir == 8'hF1);

wire op_xthl = (r_ir == 8'hE3);
wire op_sphl = (r_ir == 8'hF9);

wire op_lxi_sp = (r_ir == 8'h31);

wire op_inx_sp = (r_ir == 8'h33);
wire op_dcx_sp = (r_ir == 8'h3B);

//*****************************************************************************
//JUMP
//*****************************************************************************
wire op_jmp = (r_ir == 8'hC3);

wire op_jc  = (r_ir == 8'hDA);
wire op_jnc = (r_ir == 8'hD2);
wire op_jz  = (r_ir == 8'hCA);
wire op_jnz = (r_ir == 8'hC2);
wire op_jm  = (r_ir == 8'hFA);
wire op_jp  = (r_ir == 8'hF2);
wire op_jpe = (r_ir == 8'hEA);
wire op_jpo = (r_ir == 8'hE2);

wire op_pchl = (r_ir == 8'hE9);

//*****************************************************************************
//CALL
//*****************************************************************************
wire op_call = (r_ir == 8'hCD) || (r_ir == 8'hDD) || (r_ir == 8'hED) ||(r_ir == 8'hFD);

wire op_cc  = (r_ir == 8'hDC);
wire op_cnc = (r_ir == 8'hD4);
wire op_cz  = (r_ir == 8'hCC);
wire op_cnz = (r_ir == 8'hC4);
wire op_cm  = (r_ir == 8'hFC);
wire op_cp  = (r_ir == 8'hF4);
wire op_cpe = (r_ir == 8'hEC);
wire op_cpo = (r_ir == 8'hE4);

//*****************************************************************************
//RETURN
//*****************************************************************************
wire op_ret = ((r_ir == 8'hC9) || (r_ir == 8'hD9));

wire op_rc  = (r_ir == 8'hD8);
wire op_rnc = (r_ir == 8'hD0);
wire op_rz  = (r_ir == 8'hC8);
wire op_rnz = (r_ir == 8'hC0);
wire op_rm  = (r_ir == 8'hF8);
wire op_rp  = (r_ir == 8'hF0);
wire op_rpe = (r_ir == 8'hE8);
wire op_rpo = (r_ir == 8'hE0);

//*****************************************************************************
//RESTART
//*****************************************************************************
wire op_rst_0 = (r_ir == 8'hC7);
wire op_rst_1 = (r_ir == 8'hCF);
wire op_rst_2 = (r_ir == 8'hD7);
wire op_rst_3 = (r_ir == 8'hDF);
wire op_rst_4 = (r_ir == 8'hE7);
wire op_rst_5 = (r_ir == 8'hEF);
wire op_rst_6 = (r_ir == 8'hF7);
wire op_rst_7 = (r_ir == 8'hFF);
wire op_rst = op_rst_0|op_rst_1|op_rst_2|op_rst_3|op_rst_4|op_rst_5|op_rst_6|op_rst_7;

//*****************************************************************************
//INCREMENT AND DECREMENT
//*****************************************************************************
wire op_inr_a = (r_ir == 8'h3C);
wire op_inr_b = (r_ir == 8'h04);
wire op_inr_c = (r_ir == 8'h0C);
wire op_inr_d = (r_ir == 8'h14);
wire op_inr_e = (r_ir == 8'h1C);
wire op_inr_h = (r_ir == 8'h24);
wire op_inr_l = (r_ir == 8'h2C);
wire op_inr   = op_inr_a|op_inr_b|op_inr_c|op_inr_d|op_inr_e|op_inr_h|op_inr_l;

wire op_dcr_a = (r_ir == 8'h3D);
wire op_dcr_b = (r_ir == 8'h05);
wire op_dcr_c = (r_ir == 8'h0D);
wire op_dcr_d = (r_ir == 8'h15);
wire op_dcr_e = (r_ir == 8'h1D);
wire op_dcr_h = (r_ir == 8'h25);
wire op_dcr_l = (r_ir == 8'h2D);
wire op_dcr   = op_dcr_a|op_dcr_b|op_dcr_c|op_dcr_d|op_dcr_e|op_dcr_h|op_dcr_l;

wire op_inr_m = (r_ir == 8'h34);
wire op_dcr_m = (r_ir == 8'h35);

wire op_inx_b = (r_ir == 8'h03);
wire op_inx_d = (r_ir == 8'h13);
wire op_inx_h = (r_ir == 8'h23);
wire op_inx = op_inx_b|op_inx_d|op_inx_h|op_inx_sp;

wire op_dcx_b = (r_ir == 8'h0B);
wire op_dcx_d = (r_ir == 8'h1B);
wire op_dcx_h = (r_ir == 8'h2B);
wire op_dcx = op_dcx_b|op_dcx_d|op_dcx_h|op_dcx_sp;

//*****************************************************************************
//ADD
//*****************************************************************************
wire op_add_a = (r_ir == 8'h87);
wire op_add_b = (r_ir == 8'h80);
wire op_add_c = (r_ir == 8'h81);
wire op_add_d = (r_ir == 8'h82);
wire op_add_e = (r_ir == 8'h83);
wire op_add_h = (r_ir == 8'h84);
wire op_add_l = (r_ir == 8'h85);
wire op_add_r = op_add_a|op_add_b|op_add_c|op_add_d|op_add_e|op_add_h|op_add_l;

wire op_adc_a = (r_ir == 8'h8F);
wire op_adc_b = (r_ir == 8'h88);
wire op_adc_c = (r_ir == 8'h89);
wire op_adc_d = (r_ir == 8'h8A);
wire op_adc_e = (r_ir == 8'h8B);
wire op_adc_h = (r_ir == 8'h8C);
wire op_adc_l = (r_ir == 8'h8D);
wire op_adc_r = op_adc_a|op_adc_b|op_adc_c|op_adc_d|op_adc_e|op_adc_h|op_adc_l;

wire op_add_m = (r_ir == 8'h86);
wire op_adc_m = (r_ir == 8'h8E);

wire op_adi = (r_ir == 8'hC6);
wire op_aci = (r_ir == 8'hCE);

wire op_dad_b  = (r_ir == 8'h09);
wire op_dad_d  = (r_ir == 8'h19);
wire op_dad_h  = (r_ir == 8'h29);
wire op_dad_sp = (r_ir == 8'h39);
wire op_dad    = op_dad_b|op_dad_d|op_dad_h|op_dad_sp;

//*****************************************************************************
//SUB
//*****************************************************************************
wire op_sub_a = (r_ir == 8'h97);
wire op_sub_b = (r_ir == 8'h90);
wire op_sub_c = (r_ir == 8'h91);
wire op_sub_d = (r_ir == 8'h92);
wire op_sub_e = (r_ir == 8'h93);
wire op_sub_h = (r_ir == 8'h94);
wire op_sub_l = (r_ir == 8'h95);
wire op_sub_r = op_sub_a|op_sub_b|op_sub_c|op_sub_d|op_sub_e|op_sub_h|op_sub_l;

wire op_sbb_a = (r_ir == 8'h9F);
wire op_sbb_b = (r_ir == 8'h98);
wire op_sbb_c = (r_ir == 8'h99);
wire op_sbb_d = (r_ir == 8'h9A);
wire op_sbb_e = (r_ir == 8'h9B);
wire op_sbb_h = (r_ir == 8'h9C);
wire op_sbb_l = (r_ir == 8'h9D);
wire op_sbb_r = op_sbb_a|op_sbb_b|op_sbb_c|op_sbb_d|op_sbb_e|op_sbb_h|op_sbb_l;

wire op_sub_m = (r_ir == 8'h96);
wire op_sbb_m = (r_ir == 8'h9E);

wire op_sui = (r_ir == 8'hD6);
wire op_sbi = (r_ir == 8'hDE);

//*****************************************************************************
//LOGICAL
//*****************************************************************************
wire op_ana_a = (r_ir == 8'hA7);
wire op_ana_b = (r_ir == 8'hA0);
wire op_ana_c = (r_ir == 8'hA1);
wire op_ana_d = (r_ir == 8'hA2);
wire op_ana_e = (r_ir == 8'hA3);
wire op_ana_h = (r_ir == 8'hA4);
wire op_ana_l = (r_ir == 8'hA5);
wire op_ana = op_ana_a|op_ana_b|op_ana_c|op_ana_d|op_ana_e|op_ana_h|op_ana_l;

wire op_xra_a = (r_ir == 8'hAF);
wire op_xra_b = (r_ir == 8'hA8);
wire op_xra_c = (r_ir == 8'hA9);
wire op_xra_d = (r_ir == 8'hAA);
wire op_xra_e = (r_ir == 8'hAB);
wire op_xra_h = (r_ir == 8'hAC);
wire op_xra_l = (r_ir == 8'hAD);
wire op_xra = op_xra_a|op_xra_b|op_xra_c|op_xra_d|op_xra_e|op_xra_h|op_xra_l;

wire op_ora_a = (r_ir == 8'hB7);
wire op_ora_b = (r_ir == 8'hB0);
wire op_ora_c = (r_ir == 8'hB1);
wire op_ora_d = (r_ir == 8'hB2);
wire op_ora_e = (r_ir == 8'hB3);
wire op_ora_h = (r_ir == 8'hB4);
wire op_ora_l = (r_ir == 8'hB5);
wire op_ora = op_ora_a|op_ora_b|op_ora_c|op_ora_d|op_ora_e|op_ora_h|op_ora_l;

wire op_cmp_a = (r_ir == 8'hBF);
wire op_cmp_b = (r_ir == 8'hB8);
wire op_cmp_c = (r_ir == 8'hB9);
wire op_cmp_d = (r_ir == 8'hBA);
wire op_cmp_e = (r_ir == 8'hBB);
wire op_cmp_h = (r_ir == 8'hBC);
wire op_cmp_l = (r_ir == 8'hBD);
wire op_cmp = op_cmp_a|op_cmp_b|op_cmp_c|op_cmp_d|op_cmp_e|op_cmp_h|op_cmp_l;

wire op_ana_m = (r_ir == 8'hA6);
wire op_xra_m = (r_ir == 8'hAE);
wire op_ora_m = (r_ir == 8'hB6);
wire op_cmp_m = (r_ir == 8'hBE);

wire op_ani = (r_ir == 8'hE6);
wire op_xri = (r_ir == 8'hEE);
wire op_ori = (r_ir == 8'hF6);
wire op_cpi = (r_ir == 8'hFE);

//*****************************************************************************
//ROTATE
//*****************************************************************************
wire op_rlc = (r_ir == 8'h07);
wire op_rrc = (r_ir == 8'h0F);
wire op_ral = (r_ir == 8'h17);
wire op_rar = (r_ir == 8'h1F);

//*****************************************************************************
//SPECIALS
//*****************************************************************************
wire op_cma = (r_ir == 8'h2F);
wire op_stc = (r_ir == 8'h37);
wire op_cmc = (r_ir == 8'h3F);
wire op_daa = (r_ir == 8'h27);

//*****************************************************************************
//INPUT/OUTPUT
//*****************************************************************************
wire op_in  = (r_ir == 8'hDB);
wire op_out = (r_ir == 8'hD3);

//*****************************************************************************
//CONTROL
//*****************************************************************************
wire op_ei  = (r_ir == 8'hFB);
wire op_di  = (r_ir == 8'hF3);
wire op_nop = ((r_ir == 8'h00) || (r_ir == 8'h10) ||
               (r_ir == 8'h20) || (r_ir == 8'h30) || 
               (r_ir == 8'h08) || (r_ir == 8'h18) || 
               (r_ir == 8'h28) || (r_ir == 8'h38) );
wire op_halt = (r_ir == 8'h76);



// Reset: detect falling edge of rst -> GO!
reg rst=0;
always @(posedge i_clk)
	rst <= i_rst;
wire go = rst & ~i_rst;

//int_a - Interrupt acknoledgment
always @(posedge i_clk)
	if (i_rst|o_inta) o_inta<=0;
	else if (i_int & t_read_op & iff1 & (~i_ready)) o_inta<=1;

//EI - Enable interrupt
reg t_ei1;
always @(posedge i_clk)
	if (i_rst|(t_ei1&t_read_op&i_ready)) t_ei1 <= 0;
	else if (op_ei) t_ei1 <= 1;
reg t_ei2;
always @(posedge i_clk)
	if (i_rst|(t_ei2 & t_read_op & i_ready)) t_ei2 <= 0;
	else if (t_ei1 & t_read_op & i_ready) t_ei2 <= 1;

//IFF - interrupt flag register
reg iff1;
always @(posedge i_clk)
	if (i_rst) iff1 <= 0;
	else if (t_ei1 & t_read_op&i_ready) iff1 <= 1;
	else if (o_inta|op_di) iff1 <= 0;

// read from memory
always @(posedge i_clk)
	if (i_rst | o_read) o_read <= 1'b0;
	else if (op_mov_m_r|op_stax_b|op_stax_d|op_push|op_rst) o_read <= 1'b0;
	else if (i_ready & (t_inr_m1|t_dcr_m1|t_call2|t_call3|t_mvi_m1|t_xthl1|t_xthl3|t_shld2|t_shld3|t_push1|t_out1|t_sta2|t_rst1)) o_read <= 1'b0;
	else if (go | i_ready) o_read <= 1'b1;

// Operation, that take more than one cycle
wire t_1 = (t_out1|t_out2|t_in1|t_in2|t_mov_a_m1|t_mov_b_m1|t_mov_c_m1|t_mov_d_m1|t_mov_e_m1|t_mov_h_m1|t_mov_l_m1|t_mvi_m1|t_mvi_m2|t_lxi_b1|t_lxi_d1|t_lxi_h1|t_lxi_sp1|t_adi1|t_aci1|t_sui1|t_sbi1|t_ani1|t_xri1|t_ori1|t_cpi1|t_push1|t_push2|t_jp1|t_jp_n1|t_ldax1|t_mov_m_r1|t_stax1|t_call1|t_lhld1|t_shld1|t_ret1|t_pop1|t_dcr_m1|t_inr_m1) ;
wire t_2 = t_xthl1|t_xthl2|t_xthl3|t_xthl4|t_shld2|t_shld3|t_shld4|t_lhld2|t_lhld3|t_lhld4|t_rst1|t_rst2|t_sta1|t_sta2|t_sta3|t_lda1|t_lda2|t_lda3|t_lxi_sp2|t_jp2|t_jp_n2|t_call2|t_call3|t_call4|t_ret2|t_pop2|t_dcr_m2|t_inr_m2;
wire t_read_op = ~(t_1|t_2);

//Instruction register
wire [7:0] r_ir = (i_ready & t_read_op)?  i_dat_r : 8'h00;

//MOV A,M
reg t_mov_a_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_a_m1 & i_ready)) t_mov_a_m1 <= 1'b0;
	else if (op_mov_a_m|op_mvi_a) t_mov_a_m1 <= 1'b1;
//MOV B,M
reg t_mov_b_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_b_m1 & i_ready)) t_mov_b_m1 <= 1'b0;
	else if (op_mov_b_m|op_mvi_b) t_mov_b_m1 <= 1'b1;
	else if (i_ready & t_lxi_b1) t_mov_b_m1 <= 1'b1;
//MOV C,M
reg t_mov_c_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_c_m1 & i_ready)) t_mov_c_m1 <= 1'b0;
	else if (op_mov_c_m|op_mvi_c|op_lxi_b) t_mov_c_m1 <= 1'b1;
//MOV D,M
reg t_mov_d_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_d_m1 & i_ready)) t_mov_d_m1 <= 1'b0;
	else if (op_mov_d_m|op_mvi_d) t_mov_d_m1 <= 1'b1;
	else if (i_ready & t_lxi_d1) t_mov_d_m1 <= 1'b1;
//MOV E,M
reg t_mov_e_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_e_m1 & i_ready)) t_mov_e_m1 <= 1'b0;
	else if (op_mov_e_m|op_mvi_e|op_lxi_d) t_mov_e_m1 <= 1'b1;
//MOV H,M
reg t_mov_h_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_h_m1 & i_ready)) t_mov_h_m1 <= 1'b0;
	else if (op_mov_h_m|op_mvi_h) t_mov_h_m1 <= 1'b1;
	else if (i_ready & t_lxi_h1) t_mov_h_m1 <= 1'b1;
//MOV L,M
reg t_mov_l_m1;
always @(posedge i_clk)
	if (i_rst | (t_mov_l_m1 & i_ready)) t_mov_l_m1 <= 1'b0;
	else if (op_mov_l_m|op_mvi_l|op_lxi_h) t_mov_l_m1 <= 1'b1;

//MOV M - move memory
reg t_mov_m_r1;
always @(posedge i_clk)
	if (i_rst | (t_mov_m_r1 & i_ready)) t_mov_m_r1 <= 1'b0;
	else if (op_mov_m_r) t_mov_m_r1 <= 1'b1;

//MVI M - move immediate memory
reg t_mvi_m1;
always @(posedge i_clk)
	if (i_rst | (t_mvi_m1 & i_ready)) t_mvi_m1 <= 1'b0;
	else if (op_mvi_m) t_mvi_m1 <= 1'b1;
reg t_mvi_m2;
always @(posedge i_clk)
	if (i_rst | (t_mvi_m2 & i_ready)) t_mvi_m2 <= 1'b0;
	else if (i_ready & t_mvi_m1) t_mvi_m2 <= 1'b1;

//LHLD - load HL direct
reg t_lhld1;
always @(posedge i_clk)
	if (i_rst | (t_lhld1 & i_ready)) t_lhld1 <= 1'b0;
	else if (op_lhld) t_lhld1 <= 1'b1;
reg t_lhld2;
always @(posedge i_clk)
	if (i_rst | (t_lhld2 & i_ready)) t_lhld2 <= 1'b0;
	else if (i_ready & t_lhld1) t_lhld2 <= 1'b1;
reg t_lhld3;
always @(posedge i_clk)
	if (i_rst | (t_lhld3 & i_ready)) t_lhld3 <= 1'b0;
	else if (i_ready & t_lhld2) t_lhld3 <= 1'b1;
reg t_lhld4;
always @(posedge i_clk)
	if (i_rst | (t_lhld4 & i_ready)) t_lhld4 <= 1'b0;
	else if (i_ready & t_lhld3) t_lhld4 <= 1'b1;

//SHLD - Store HL direct
reg t_shld1;
always @(posedge i_clk)
	if (i_rst | (t_shld1 & i_ready)) t_shld1 <= 1'b0;
	else if (op_shld) t_shld1 <= 1'b1;
reg t_shld2;
always @(posedge i_clk)
	if (i_rst | (t_shld2 & i_ready)) t_shld2 <= 1'b0;
	else if (i_ready & t_shld1) t_shld2 <= 1'b1;
reg t_shld3;
always @(posedge i_clk)
	if (i_rst | (t_shld3 & i_ready)) t_shld3 <= 1'b0;
	else if (i_ready & t_shld2) t_shld3 <= 1'b1;
reg t_shld4;
always @(posedge i_clk)
	if (i_rst | (t_shld4 & i_ready)) t_shld4 <= 1'b0;
	else if (i_ready & t_shld3) t_shld4 <= 1'b1;

//XTHL - exchante top of stack with HL
reg t_xthl1;
always @(posedge i_clk)
	if (i_rst | (t_xthl1 & i_ready)) t_xthl1 <= 1'b0;
	else if (op_xthl) t_xthl1 <= 1'b1;
reg t_xthl2;
always @(posedge i_clk)
	if (i_rst | (t_xthl2 & i_ready)) t_xthl2 <= 1'b0;
	else if (i_ready & t_xthl1) t_xthl2 <= 1'b1;
reg t_xthl3;
always @(posedge i_clk)
	if (i_rst | (t_xthl3 & i_ready)) t_xthl3 <= 1'b0;
	else if (i_ready & t_xthl2) t_xthl3 <= 1'b1;
reg t_xthl4;
always @(posedge i_clk)
	if (i_rst | (t_xthl4 & i_ready)) t_xthl4 <= 1'b0;
	else if (i_ready & t_xthl3) t_xthl4 <= 1'b1;

//DCR - decrement
reg t_dcr_m1;
always @(posedge i_clk)
	if (i_rst | (t_dcr_m1&i_ready)) t_dcr_m1 <= 1'b0;
	else if (op_dcr_m) t_dcr_m1 <= 1'b1;
reg t_dcr_m2;
always @(posedge i_clk)
	if (i_rst | (t_dcr_m2&i_ready)) t_dcr_m2 <= 1'b0;
	else if (i_ready & t_dcr_m1) t_dcr_m2 <= 1'b1;

//INR M - increment memory
reg t_inr_m1;
always @(posedge i_clk)
	if (i_rst | (t_inr_m1&i_ready)) t_inr_m1 <= 1'b0;
	else if (op_inr_m) t_inr_m1 <= 1'b1;
reg t_inr_m2;
always @(posedge i_clk)
	if (i_rst | (t_inr_m2&i_ready)) t_inr_m2 <= 1'b0;
	else if (i_ready & t_inr_m1) t_inr_m2 <= 1'b1;

//LXI B - load register pair B
reg t_lxi_b1;
always @(posedge i_clk)
	if (i_rst | (t_lxi_b1 & i_ready)) t_lxi_b1 <= 1'b0;
	else if (op_lxi_b) t_lxi_b1 <= 1'b1;
reg t_lxi_b2;
always @(posedge i_clk)
	if (i_rst | (t_lxi_b2 & i_ready)) t_lxi_b2 <= 1'b0;
	else if (i_ready & t_lxi_b1) t_lxi_b2 <= 1'b1;

//LXI D - load register pair D
reg t_lxi_d1;
always @(posedge i_clk)
	if (i_rst | (t_lxi_d1 & i_ready)) t_lxi_d1 <= 1'b0;
	else if (op_lxi_d) t_lxi_d1 <= 1'b1;
reg t_lxi_d2;
always @(posedge i_clk)
	if (i_rst | (t_lxi_d2 & i_ready)) t_lxi_d2 <= 1'b0;
	else if (i_ready & t_lxi_d1) t_lxi_d2 <= 1'b1;

//LXI H - load register pair H
reg t_lxi_h1;
always @(posedge i_clk)
	if (i_rst | (t_lxi_h1 & i_ready)) t_lxi_h1 <= 1'b0;
	else if (op_lxi_h) t_lxi_h1 <= 1'b1;
reg t_lxi_h2;
always @(posedge i_clk)
	if (i_rst | (t_lxi_h2 & i_ready)) t_lxi_h2 <= 1'b0;
	else if (i_ready & t_lxi_h1) t_lxi_h2 <= 1'b1;

//LXI SP - load stack pointer
reg t_lxi_sp1;
always @(posedge i_clk)
	if (i_rst | (t_lxi_sp1 & i_ready)) t_lxi_sp1 <= 1'b0;
	else if (op_lxi_sp) t_lxi_sp1 <= 1'b1;
reg t_lxi_sp2;
always @(posedge i_clk)
	if (i_rst | (t_lxi_sp2 & i_ready)) t_lxi_sp2 <= 1'b0;
	else if (t_lxi_sp1 & i_ready) t_lxi_sp2 <= 1'b1;

reg t_stax1;
always @(posedge i_clk)
	if (i_rst | (t_stax1 & i_ready)) t_stax1 <= 1'b0;
	else if (op_stax_b|op_stax_d) t_stax1 <= 1'b1;


//STA - store accumulator
reg t_sta1;
always @(posedge i_clk)
	if (i_rst | (t_sta1 & i_ready)) t_sta1 <= 1'b0;
	else if (op_sta) t_sta1 <= 1'b1;
reg t_sta2;
always @(posedge i_clk)
	if (i_rst | (t_sta2 & i_ready)) t_sta2 <= 1'b0;
	else if (i_ready&t_sta1) t_sta2 <= 1'b1;
reg t_sta3;
always @(posedge i_clk)
	if (i_rst | (t_sta3 & i_ready)) t_sta3 <= 1'b0;
	else if (i_ready&t_sta2) t_sta3 <= 1'b1;

//LDA - load accumulator
reg t_lda1;
always @(posedge i_clk)
	if (i_rst | (t_lda1 & i_ready)) t_lda1 <= 1'b0;
	else if (op_lda) t_lda1 <= 1'b1;
reg t_lda2;
always @(posedge i_clk)
	if (i_rst | (t_lda2 & i_ready)) t_lda2 <= 1'b0;
	else if (i_ready&t_lda1) t_lda2 <= 1'b1;
reg t_lda3;
always @(posedge i_clk)
	if (i_rst | (t_lda3 & i_ready)) t_lda3 <= 1'b0;
	else if (i_ready&t_lda2) t_lda3 <= 1'b1;

reg t_out1;
always @(posedge i_clk)
	if (i_rst | (t_out1 & i_ready)) t_out1 <= 1'b0;
	else if (op_out) t_out1 <= 1'b1;
reg t_out2;
always @(posedge i_clk)
	if (i_rst | (t_out2 & i_ready)) t_out2 <= 1'b0;
	else if (i_ready&t_out1) t_out2 <= 1'b1;
reg t_in1;
always @(posedge i_clk)
	if (i_rst | (t_in1 & i_ready)) t_in1 <= 1'b0;
	else if (op_in) t_in1 <= 1'b1;
reg t_in2;
always @(posedge i_clk)
	if (i_rst | (t_in2 & i_ready)) t_in2 <= 1'b0;
	else if (i_ready&t_in1) t_in2 <= 1'b1;

reg t_jp1;
always @(posedge i_clk)
	if (i_rst | (t_jp1 & i_ready)) t_jp1 <= 1'b0;
	else if (op_jmp |(op_jz&r_f_z)|(op_jnz&~r_f_z)|(op_jc&r_f_c)|(op_jnc&~r_f_c)|(op_jm&r_f_s)|(op_jp&~r_f_s&~r_f_z)|(op_jpe%r_f_p)|(op_jpo&~r_f_p)) t_jp1 <= 1'b1;
reg t_jp2;
always @(posedge i_clk)
	if (i_rst | (t_jp2 & i_ready)) t_jp2 <= 1'b0;
	else if (t_jp1 & i_ready) t_jp2 <= 1'b1;
reg t_jp_n1;
always @(posedge i_clk)
	if (i_rst | (t_jp_n1 & i_ready)) t_jp_n1 <= 1'b0;
	else if (((op_jz|op_cz)&~r_f_z)|((op_jnz|op_cnz)&r_f_z)|((op_jc|op_cc)&~r_f_c)|((op_jnc|op_cnc)&r_f_c)|((op_jm|op_cm)&~r_f_s)|((op_jp|op_cp)&(r_f_s|r_f_z))|((op_jpe|op_cpe)&~r_f_p)|((op_jpo|op_cpo)&r_f_p)) t_jp_n1 <= 1'b1;
reg t_jp_n2;
always @(posedge i_clk)
	if (i_rst | (t_jp_n2 & i_ready)) t_jp_n2 <= 1'b0;
	else if (t_jp_n1 & i_ready) t_jp_n2 <= 1'b1;


reg t_ldax1;
always @(posedge i_clk)
	if (i_rst | (t_ldax1 & i_ready)) t_ldax1 <= 1'b0;
	else if (op_ldax_b|op_ldax_d) t_ldax1 <= 1'b1;

reg t_adi1;
always @(posedge i_clk)
	if (i_rst | (t_adi1 & i_ready)) t_adi1 <= 1'b0;
	else if (op_adi|op_add_m) t_adi1 <= 1'b1;
reg t_aci1;
always @(posedge i_clk)
	if (i_rst | (t_aci1 & i_ready)) t_aci1 <= 1'b0;
	else if (op_aci|op_adc_m) t_aci1 <= 1'b1;

reg t_sui1;
always @(posedge i_clk)
	if (i_rst | (t_sui1 & i_ready)) t_sui1 <= 1'b0;
	else if (op_sui|op_sub_m) t_sui1 <= 1'b1;
reg t_sbi1;
always @(posedge i_clk)
	if (i_rst | (t_sbi1 & i_ready)) t_sbi1 <= 1'b0;
	else if (op_sbi|op_sbb_m) t_sbi1 <= 1'b1;

reg t_ani1;
always @(posedge i_clk)
	if (i_rst | (t_ani1 & i_ready)) t_ani1 <= 1'b0;
	else if (op_ani|op_ana_m) t_ani1 <= 1'b1;
reg t_xri1;
always @(posedge i_clk)
	if (i_rst | (t_xri1 & i_ready)) t_xri1 <= 1'b0;
	else if (op_xri|op_xra_m) t_xri1 <= 1'b1;
reg t_ori1;
always @(posedge i_clk)
	if (i_rst | (t_ori1 & i_ready)) t_ori1 <= 1'b0;
	else if (op_ori|op_ora_m) t_ori1 <= 1'b1;
reg t_cpi1;
always @(posedge i_clk)
	if (i_rst | (t_cpi1 & i_ready)) t_cpi1 <= 1'b0;
	else if (op_cpi|op_cmp_m) t_cpi1 <= 1'b1;

wire op_push= op_push_b|op_push_d|op_push_h|op_push_psw;
reg t_push_psw1;
always @(posedge i_clk)
	if (i_rst | (t_push_psw1 & i_ready)) t_push_psw1 <= 1'b0;
	else if (op_push_psw) t_push_psw1 <= 1'b1;
reg t_push_b1;
always @(posedge i_clk)
	if (i_rst | (t_push_b1 & i_ready)) t_push_b1 <= 1'b0;
	else if (op_push_b) t_push_b1 <= 1'b1;
reg t_push_d1;
always @(posedge i_clk)
	if (i_rst | (t_push_d1 & i_ready)) t_push_d1 <= 1'b0;
	else if (op_push_d) t_push_d1 <= 1'b1;
reg t_push_h1;
always @(posedge i_clk)
	if (i_rst | (t_push_h1 & i_ready)) t_push_h1 <= 1'b0;
	else if (op_push_h) t_push_h1 <= 1'b1;
wire t_push1=t_push_psw1|t_push_b1|t_push_d1|t_push_h1;
reg t_push2;
always @(posedge i_clk)
	if (i_rst | (t_push2 & i_ready)) t_push2 <= 1'b0;
	else if (t_push1 & i_ready) t_push2 <= 1'b1;
wire op_pop=op_pop_b|op_pop_d|op_pop_h|op_pop_psw;
wire t_pop1 = t_pop_b1|t_pop_d1|t_pop_psw1|t_pop_h1;
wire t_pop2 = t_pop_b2|t_pop_d2|t_pop_psw2|t_pop_h2;
reg t_pop_b1;
always @(posedge i_clk)
	if (i_rst | (t_pop_b1 & i_ready)) t_pop_b1 <= 1'b0;
	else if (op_pop_b) t_pop_b1 <= 1'b1;
reg t_pop_b2;
always @(posedge i_clk)
	if (i_rst | (t_pop_b2 & i_ready)) t_pop_b2 <= 1'b0;
	else if (t_pop_b1 & i_ready) t_pop_b2 <= 1'b1;
reg t_pop_d1;
always @(posedge i_clk)
	if (i_rst | (t_pop_d1 & i_ready)) t_pop_d1 <= 1'b0;
	else if (op_pop_d) t_pop_d1 <= 1'b1;
reg t_pop_d2;
always @(posedge i_clk)
	if (i_rst | (t_pop_d2 & i_ready)) t_pop_d2 <= 1'b0;
	else if (t_pop_d1 & i_ready) t_pop_d2 <= 1'b1;
reg t_pop_h1;
always @(posedge i_clk)
	if (i_rst | (t_pop_h1 & i_ready)) t_pop_h1 <= 1'b0;
	else if (op_pop_h) t_pop_h1 <= 1'b1;
reg t_pop_h2;
always @(posedge i_clk)
	if (i_rst | (t_pop_h2 & i_ready)) t_pop_h2 <= 1'b0;
	else if (t_pop_h1 & i_ready) t_pop_h2 <= 1'b1;
reg t_pop_psw1;
always @(posedge i_clk)
	if (i_rst | (t_pop_psw1 & i_ready)) t_pop_psw1 <= 1'b0;
	else if (op_pop_psw) t_pop_psw1 <= 1'b1;
reg t_pop_psw2;
always @(posedge i_clk)
	if (i_rst | (t_pop_psw2 & i_ready)) t_pop_psw2 <= 1'b0;
	else if (t_pop_psw1 & i_ready) t_pop_psw2 <= 1'b1;

reg t_call1;
always @(posedge i_clk)
	if (i_rst | (t_call1 & i_ready)) t_call1 <= 1'b0;
	else if (op_call|(op_cc&r_f_c)|(op_cnc&~r_f_c)|(op_cz&r_f_z)|(op_cnz&~r_f_z)|(op_cm&r_f_s)|(op_cp&~r_f_s&~r_f_z)|(op_cpe&r_f_p)|(op_cpo&~r_f_p)) t_call1 <= 1'b1;
reg t_call2;
always @(posedge i_clk)
	if (i_rst | (t_call2 & i_ready)) t_call2 <= 1'b0;
	else if (t_call1 & i_ready) t_call2 <= 1'b1;
reg t_call3;
always @(posedge i_clk)
	if (i_rst | (t_call3 & i_ready)) t_call3 <= 1'b0;
	else if (t_call2 & i_ready) t_call3 <= 1'b1;
reg t_call4;
always @(posedge i_clk)
	if (i_rst | (t_call4 & i_ready)) t_call4 <= 1'b0;
	else if (t_call3 & i_ready) t_call4 <= 1'b1;

wire is_ret = (op_ret|(op_rz&r_f_z)|(op_rc&r_f_c)|(op_rnc&~r_f_c)|(op_rnz&~r_f_z)|(op_rm&r_f_s)|(op_rp&~r_f_s&~r_f_z)|(op_rpe&r_f_p)|(op_rpo&~r_f_p));
reg t_ret1;
always @(posedge i_clk)
	if (i_rst | (t_ret1 & i_ready)) t_ret1 <= 1'b0;
	else if (is_ret) t_ret1 <= 1'b1;
reg t_ret2;
always @(posedge i_clk)
	if (i_rst | (t_ret2 & i_ready)) t_ret2 <= 1'b0;
	else if (t_ret1 & i_ready) t_ret2 <= 1'b1;

//reset instruction
reg t_rst1;
always @(posedge i_clk)
	if (i_rst | (t_rst1 & i_ready))	t_rst1 <= 1'b0;
	else if (op_rst) 				t_rst1 <= 1'b1;
reg t_rst2;
always @(posedge i_clk)
	if (i_rst | (t_rst2 & i_ready)) t_rst2 <= 1'b0;
	else if (t_rst1 & i_ready) t_rst2 <= 1'b1;

//address of RST instruction
reg [2:0] rst_addr;
always @(posedge i_clk)
	if (i_rst) 			rst_addr <= 3'b0;
	else if (op_rst) 	rst_addr <= r_ir[5:3];


//r_w: 8 bit data of pc
//r_z: 8 bit data of pc-1
wire [7:0]  r_w = i_dat_r;
wire [15:0] r_wz = {r_w,r_z};
reg  [7:0]  r_z;
always @(posedge i_clk)
	if (i_rst) 			r_z <= 8'h00;
	else if (i_ready) 	r_z <= i_dat_r;

//16 bit address of call instruction
reg [15:0] r_call;
always @(posedge i_clk)
	if (i_rst) 					r_call <= 16'h0000;
	else if (i_ready&t_call2) 	r_call <= r_wz;

// Programm Counter
reg [15:0] r_pc;
always @(posedge i_clk)
	if (i_rst)			r_pc <= 16'h0000;
	else if (op_halt) 	r_pc <= r_pc;
	else if (op_pchl) 	r_pc <= r_hl;
	else if (op_xthl|op_rst|t_rst1|op_ldax_b|op_ldax_d|op_mov_r_m|op_mov_m_r|t_mvi_m1|t_call3|t_xthl1|t_xthl2|t_xthl3|t_lhld3|t_lhld2|t_shld3|t_shld2|op_stax_b|op_stax_d|op_push|t_push1|op_add_m|op_adc_m|op_sub_m|op_sbb_m|op_ana_m|op_xra_m|op_ora_m|op_cmp_m|op_pop|t_pop1|t_sta2|t_lda2|t_out1|t_in1|op_dcr_m|op_inr_m|t_inr_m1|t_dcr_m1|is_ret|t_ret1)
						r_pc <= r_pc; //stax b stax d
	else if (i_ready&(t_rst2))  r_pc <= {10'b0000000000,rst_addr,3'b000};
	else if (i_ready&(t_jp2|t_ret2)) 	r_pc <= r_wz;
	else if (i_ready&t_call4) 	r_pc <= r_call;
	else if (i_ready)			r_pc <= r_pc+1;

//output address
always @(posedge i_clk)
	if (i_rst)                       o_addr <= 0;
	else if (op_mov_m_r|op_mov_r_m|op_add_m|op_adc_m|op_sub_m|op_sbb_m|op_dcr_m|op_inr_m|op_ana_m|op_xra_m|op_ora_m|op_cmp_m)  o_addr <= r_hl;
	else if (op_pchl)              o_addr <= r_hl;
	else if (op_stax_b)              o_addr <= r_bc;
	else if (op_stax_d)              o_addr <= r_de;
	else if (i_ready & (t_sta2|t_lda2))       o_addr <= r_wz;
	else if (i_ready & (t_out1|t_in1))              o_addr <={r_a,r_w} ;
	else if (i_ready & (t_mvi_m1|t_dcr_m1|t_inr_m1))     o_addr <= r_hl;
	else if (i_ready&(t_jp2))  o_addr <= r_wz;
	else if (op_push|op_rst)  o_addr <= r_sp-1;
	else if (op_pop|op_xthl)  o_addr <= r_sp;
	else if (i_ready&(t_xthl2|t_xthl3))  o_addr <= r_sp+1;
	else if (i_ready&(t_pop1|t_xthl1))  o_addr <= r_sp;
	else if (i_ready&(t_push1|t_rst1))  o_addr <= r_sp-1;
	else if (i_ready&(t_rst2))  o_addr <= {10'b0000000000,rst_addr,3'b000};
	else if (i_ready&(t_lhld2|t_shld2))  o_addr <= r_wz;
	else if (i_ready&(t_lhld3|t_shld3))  o_addr <= o_addr+1;
	else if (i_ready&t_call2)  o_addr <= r_sp-1;
	else if (i_ready&t_call3)  o_addr <= r_sp-1;
	else if (i_ready&t_call4)  o_addr <= r_call;
	else if (is_ret)  o_addr <= r_sp;
	else if (i_ready&t_ret1)  o_addr <= r_sp;
	else if (i_ready&t_ret2)  o_addr <= r_wz;
	else if (op_ldax_d)  o_addr <= r_de;
	else if (op_ldax_b)  o_addr <= r_bc;
	else if (op_halt)  o_addr <= r_pc;
	else if (i_ready)  o_addr <= r_pc+1;

//Register SP
//Stackpointer
reg [15:0] r_sp;
always @(posedge i_clk)
	if (i_rst) 			r_sp <= 16'h0000;
	else if (op_sphl)  	r_sp <= r_hl;
	else if (i_ready&t_lxi_sp1)  r_sp[7:0]  <= r_w;
	else if (i_ready&t_lxi_sp2)  r_sp[15:8] <= r_w;
	else if (op_dcx_sp)  		r_sp <= alu_dec_ss;
	else if (op_inx_sp)  		r_sp <= alu_inc_ss;
	else if (op_push|op_rst)   	r_sp <= r_sp-1;
	else if (i_ready&(t_push1|t_rst1))   r_sp <= r_sp-1;
	else if (op_pop)   			r_sp <= r_sp+1;
	else if (i_ready&t_pop1)   	r_sp <= r_sp+1;
	else if (i_ready&t_call2)   r_sp <= r_sp-1;
	else if (i_ready&t_call3)   r_sp <= r_sp-1;
	else if (is_ret)   			r_sp <= r_sp+1;
	else if (i_ready&t_ret1)    r_sp <= r_sp+1;


//ALU - Arithmetic and Logic Unit
wire alu_i = t_adi1|t_aci1|t_sui1|t_sbi1|t_ani1|t_xri1|t_ori1|t_cpi1|t_inr_m1|t_dcr_m1;
wire [7:0] alu_out;
alu ALU(.in_a(r_a),.in_dst(alu_i?r_w:((op_inr|op_dcr)?r_dst:r_src)),.in_c(r_f_c),
        .op_inr(op_inr|t_inr_m1),
        .op_dcr(op_dcr|t_dcr_m1),
        .op_add(op_add_r|t_adi1),
        .op_adc(op_adc_r|t_aci1),
        .op_sub(op_sub_r|op_cmp|t_sui1|t_cpi1),
        .op_sbc(op_sbb_r|t_sbi1),
		.op_and(op_ana|t_ani1),
		.op_or (op_ora|t_ori1),
		.op_xor(op_xra|t_xri1),
		.out(alu_out),
		.out_c(alu_out_c),
		.out_a(alu_out_a),
		.out_z(alu_out_z),
		.out_s(alu_out_s),
		.out_p(alu_out_p)
);
wire alu_out_a;
wire alu_out_c;
wire alu_out_s;
wire alu_out_z;
wire alu_out_p;

wire [7:0] daa_1 = (r_f_a|(r_a[3]&(r_a[2]|r_a[1])))? r_a+8'h06 : r_a;
wire [8:0] daa_2 = (r_f_c|(daa_1[7]&(daa_1[6]|daa_1[5]))) ? {1'b0,daa_1}+9'h060 : {1'b0,daa_1};

//Register A - Accumulator
reg [7:0] r_a;
always @(posedge i_clk)
	if (i_rst)           	r_a <= 8'h00;
	else if (op_mov_a_r)    r_a <= r_src;
	else if (i_ready & (t_mov_a_m1|t_lda3|t_in2|t_pop_psw2|t_ldax1))
							r_a <= r_w;
	else if (op_cma)		r_a <= ~r_a;
	else if (alu_a|op_inr_a|op_dcr_a) r_a <= alu_out;
	else if (op_daa)		r_a <= daa_2[7:0];
	else if (op_rrc) 		r_a <= {r_a[0],r_a[7:1]};
	else if (op_rlc) 		r_a <= {r_a[6:0],r_a[7]};
	else if (op_rar) 		r_a <= {r_f_c,r_a[7:1]};
	else if (op_ral) 		r_a <= {r_a[6:0],r_f_c};
	
//Register BC
wire [15:0] r_bc = {r_b,r_c};

reg [7:0] r_b;
always @(posedge i_clk)
	if (i_rst)           		r_b <= 8'h00;
	else if (op_mov_b_r)        r_b <= r_src;
	else if (i_ready & (t_mov_b_m1|t_lxi_b2|t_pop_b2))
								r_b <= r_w;
	else if (op_inr_b|op_dcr_b) r_b <= alu_out;
	else if (op_dcx_b)			r_b <= alu_dec_ss[15:8];
	else if (op_inx_b)  		r_b <= alu_inc_ss[15:8];

reg [7:0] r_c;
always @(posedge i_clk)
	if (i_rst)                 	r_c <= 8'h00;
	else if (op_mov_c_r)        r_c <= r_src;
	else if (i_ready & (t_mov_c_m1|t_lxi_b1|t_pop_b1))
								r_c <= r_w;
	else if (op_inr_c|op_dcr_c) r_c <= alu_out;
	else if (op_dcx_b)  		r_c <= alu_dec_ss[7:0];
	else if (op_inx_b)  		r_c <= alu_inc_ss[7:0];

wire [15:0] alu_dec_ss = r_src_ss - 1;
wire [15:0] alu_inc_ss = r_src_ss + 1;

//Register DE
wire [15:0] r_de = {r_d,r_e};

reg [7:0] r_d;
always @(posedge i_clk)
	if (i_rst)                     	r_d <= 8'h00;
	else if (op_mov_d_r)           	r_d <= r_src;
	else if (i_ready & (t_mov_d_m1|t_lxi_d2|t_pop_d2))
									r_d <= r_w;
	else if (op_xchg) 				r_d <= r_h;
	else if (op_inr_d|op_dcr_d)  	r_d <= alu_out;
	else if (op_dcx_d)  			r_d <= alu_dec_ss[15:8];
	else if (op_inx_d)  			r_d <= alu_inc_ss[15:8];

reg [7:0] r_e;
always @(posedge i_clk)
	if (i_rst)						r_e <= 8'h00;
	else if (op_mov_e_r)           	r_e <= r_src;
	else if (i_ready & (t_mov_e_m1|t_lxi_d1|t_pop_d1))
									r_e <= r_w;
	else if (op_xchg)				r_e <= r_l;
	else if (op_inr_e|op_dcr_e)  	r_e <= alu_out;
	else if (op_dcx_d)  			r_e <= alu_dec_ss[7:0];
	else if (op_inx_d)  			r_e <= alu_inc_ss[7:0];

//Register HL
wire [15:0] r_hl = {r_h,r_l};

reg [7:0] r_l;
always @(posedge i_clk)
	if (i_rst)                     	r_l <= 8'h00;
	else if (op_mov_l_r)           	r_l <= r_src;
	else if (i_ready & (t_pop_h1|t_lhld3|t_xthl1|t_mov_l_m1|t_lxi_h1))
									r_l <= r_w;
	else if (op_xchg) 				r_l <= r_e;
	else if (op_inr_l|op_dcr_l)  	r_l <= alu_out;
	else if (op_dcx_h)  			r_l <= alu_dec_ss[7:0];
	else if (op_inx_h)  			r_l <= alu_inc_ss[7:0];
	else if (op_dad)  				r_l <= alu_dad[7:0];

reg [7:0] r_h;
always @(posedge i_clk)
	if (i_rst)                     	r_h <= 8'h00;
	else if (op_mov_h_r)           	r_h <= r_src;
	else if (i_ready & (t_pop_h2|t_lhld4|t_xthl3|t_mov_h_m1|t_lxi_h2))
									r_h <= r_w;
	else if (op_xchg) 				r_h <= r_d;
	else if (op_inr_h|op_dcr_h)  	r_h <= alu_out;
	else if (op_dcx_h)  			r_h <= alu_dec_ss[15:8];
	else if (op_inx_h)  			r_h <= alu_inc_ss[15:8];
	else if (op_dad)  				r_h <= alu_dad[15:8];

wire [16:0] alu_dad = {1'b0,r_hl} + {1'b0,r_src_ss};


wire alu_a = (i_ready&(t_adi1|t_aci1|t_sui1|t_sbi1|t_ani1|t_xri1|t_ori1))|
             op_add_r|op_adc_r|op_sub_r|op_sbb_r|op_ana|op_xra|op_ora;

//operations that affect the flags
wire alu_f = (i_ready&(t_adi1|t_aci1|t_sui1|t_sbi1|t_inr_m1|t_dcr_m1|t_ani1|t_xri1|t_ori1|t_cpi1))|op_add_r|op_adc_r|op_sub_r|op_sbb_r|op_inr|op_dcr|op_ana|op_xra|op_ora|op_cmp;

//flag A
//auxilliary carry
reg r_f_a;
always @(posedge i_clk)
	if (i_rst) 						r_f_a <= 1'b0;
	else if (i_ready & t_pop_psw1) 	r_f_a <= r_w[4];
	else if (alu_f) 				r_f_a <= alu_out_a; 

//flag Z
//zero
reg r_f_z;
always @(posedge i_clk)
	if (i_rst)						r_f_z <= 1'b0;
	else if (i_ready & t_pop_psw1) 	r_f_z <= r_w[6];
	else if (alu_f) 				r_f_z <= alu_out_z; 

//flag S
//sign
reg r_f_s;
always @(posedge i_clk)
	if (i_rst)						r_f_s <= 1'b0;
	else if (i_ready & t_pop_psw1) 	r_f_s <= r_w[7];
	else if (alu_f) 				r_f_s <= alu_out_s; 

//flag P
//parity
reg r_f_p;
always @(posedge i_clk)
	if (i_rst)						r_f_p <= 1'b0;
	else if (i_ready & t_pop_psw1) 	r_f_p <= r_w[2];
	else if (alu_f) 				r_f_p <= alu_out_p; 

//flag C
//carry
wire alu_c = (i_ready&(t_adi1|t_aci1|t_sui1|t_sbi1|t_ani1|t_xri1|t_ori1|t_cpi1))|
             op_add_r|op_adc_r|op_sub_r|op_sbb_r|op_ana|op_xra|op_ora|op_cmp;
reg r_f_c;
always @(posedge i_clk)
	if (i_rst) r_f_c <= 1'b0;
	else if (i_ready & t_pop_psw1)	r_f_c <= r_w[0];
	else if (alu_c) 				r_f_c <= alu_out_c;
	else if (op_daa)				r_f_c <= daa_2[8];
	else if (op_rrc|op_rar) 		r_f_c <= r_a[0];
	else if (op_rlc|op_ral) 		r_f_c <= r_a[7];
	else if (op_cmc) 				r_f_c <= ~r_f_c;
	else if (op_stc) 				r_f_c <= 1'b1;
	else if (op_dad) 				r_f_c <= alu_dad[16];

wire [7:0] r_f = {r_f_s,r_f_z,1'b0,r_f_a,1'b0,r_f_p,1'b1,r_f_c};

//o_write
//write to memory/io
always @(posedge i_clk)
	if (i_rst | o_write)    									o_write <=0;
	else if (op_mov_m_r|op_stax_b|op_stax_d|op_push|op_rst)    	o_write <= 1'b1;
	else if (i_ready & (t_shld2|t_shld3|t_mvi_m1|t_call2|t_call3|t_push1|t_sta2|t_out1|t_rst1|t_dcr_m1|t_inr_m1|t_xthl1|t_xthl3)) 				o_write <= 1'b1;

//o_io
//0-memory   1-input/output
always @(posedge i_clk)
	if (i_rst | o_io)    o_io <=0;
	else if (i_ready & (t_out1|t_in1)) o_io <= 1'b1;

//o_dat_w (8bit)
//data to be written to memory
wire [15:0] r_pc_p1 = r_pc+1;
always @(posedge i_clk)
	if (i_rst)            							o_dat_w <= 0;
	else if (op_stax_b|op_stax_d|op_push_psw)  		o_dat_w <= r_a;
	else if (i_ready&(t_sta2|t_out1))  				o_dat_w <= r_a;
	else if (op_push_b)  							o_dat_w <= r_b;
	else if (i_ready & t_push_b1)  					o_dat_w <= r_c;
	else if (op_push_d)  							o_dat_w <= r_d;
	else if (i_ready & t_push_d1)  					o_dat_w <= r_e;
	else if (i_ready & t_push_psw1)  				o_dat_w <= r_f;
	else if (op_push_h)  							o_dat_w <= r_h;
	else if (i_ready & (t_shld3|t_xthl3))			o_dat_w <= r_h;
	else if (i_ready & (t_push_h1|t_shld2|t_xthl1))	o_dat_w <= r_l;
	else if (i_ready & t_mvi_m1)  					o_dat_w <= r_w;
	else if (op_mov_m_r)  							o_dat_w <= r_src;
	else if (op_rst)  								o_dat_w <= r_pc[15:8];
	else if (i_ready & t_call2)  					o_dat_w <= r_pc_p1[15:8];
	else if (i_ready & (t_call3|t_rst1))			o_dat_w <= r_pc[7:0];
	else if (i_ready&(t_dcr_m1|t_inr_m1))  			o_dat_w <= alu_out;

endmodule
