module FemtoRV32 (
	clk,
	mem_addr,
	mem_wdata,
	mem_wmask,
	mem_rdata,
	mem_rstrb,
	mem_rbusy,
	mem_wbusy,
	reset
);
	input clk;
	output wire [31:0] mem_addr;
	output wire [31:0] mem_wdata;
	output wire [3:0] mem_wmask;
	input [31:0] mem_rdata;
	output wire mem_rstrb;
	input mem_rbusy;
	input mem_wbusy;
	input reset;
	parameter RESET_ADDR = 32'h00000000;
	parameter ADDR_WIDTH = 24;
	reg [31:2] instr;
	wire [4:0] rdId = instr[11:7];
	(* onehot *) wire [7:0] funct3Is = 8'b00000001 << instr[14:12];
	wire [31:0] Uimm = {instr[31], instr[30:12], {12 {1'b0}}};
	wire [31:0] Iimm = {{21 {instr[31]}}, instr[30:20]};
	wire [31:0] Simm = {{21 {instr[31]}}, instr[30:25], instr[11:7]};
	wire [31:0] Bimm = {{20 {instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
	wire [31:0] Jimm = {{12 {instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
	wire isLoad = instr[6:2] == 5'b00000;
	wire isALUimm = instr[6:2] == 5'b00100;
	wire isAUIPC = instr[6:2] == 5'b00101;
	wire isStore = instr[6:2] == 5'b01000;
	wire isALUreg = instr[6:2] == 5'b01100;
	wire isLUI = instr[6:2] == 5'b01101;
	wire isBranch = instr[6:2] == 5'b11000;
	wire isJALR = instr[6:2] == 5'b11001;
	wire isJAL = instr[6:2] == 5'b11011;
	wire isSYSTEM = instr[6:2] == 5'b11100;
	wire isALU = isALUimm | isALUreg;
	reg [31:0] rs1;
	reg [31:0] rs2;
	reg [31:0] registerFile [31:0];
	localparam EXECUTE_bit = 2;
	localparam WAIT_ALU_OR_MEM_bit = 3;
	wire writeBack = ~(isBranch | isStore) & (state[EXECUTE_bit] | state[WAIT_ALU_OR_MEM_bit]);
	wire [ADDR_WIDTH - 1:0] loadstore_addr = rs1[ADDR_WIDTH - 1:0] + (instr[5] ? Simm[ADDR_WIDTH - 1:0] : Iimm[ADDR_WIDTH - 1:0]);
	wire [15:0] LOAD_halfword = (loadstore_addr[1] ? mem_rdata[31:16] : mem_rdata[15:0]);
	wire [7:0] LOAD_byte = (loadstore_addr[0] ? LOAD_halfword[15:8] : LOAD_halfword[7:0]);
	wire mem_byteAccess = instr[13:12] == 2'b00;
	wire LOAD_sign = !instr[14] & (mem_byteAccess ? LOAD_byte[7] : LOAD_halfword[15]);
	wire mem_halfwordAccess = instr[13:12] == 2'b01;
	wire [31:0] LOAD_data = (mem_byteAccess ? {{24 {LOAD_sign}}, LOAD_byte} : (mem_halfwordAccess ? {{16 {LOAD_sign}}, LOAD_halfword} : mem_rdata));
	reg [ADDR_WIDTH - 1:0] PC;
	wire [ADDR_WIDTH - 1:0] PCplus4 = PC + 4;
	wire [ADDR_WIDTH - 1:0] PCplusImm = PC + (instr[3] ? Jimm[ADDR_WIDTH - 1:0] : (instr[4] ? Uimm[ADDR_WIDTH - 1:0] : Bimm[ADDR_WIDTH - 1:0]));
	wire [31:0] aluIn1 = rs1;
	wire [31:0] aluIn2 = (isALUreg | isBranch ? rs2 : Iimm);
	wire [32:0] aluMinus = ({1'b1, ~aluIn2} + {1'b0, aluIn1}) + 33'b000000000000000000000000000000001;
	wire LT = (aluIn1[31] ^ aluIn2[31] ? aluIn1[31] : aluMinus[32]);
	wire LTU = aluMinus[32];
	wire [31:0] aluPlus = aluIn1 + aluIn2;
	wire [31:0] shifter_in = (funct3Is[1] ? {aluIn1[0], aluIn1[1], aluIn1[2], aluIn1[3], aluIn1[4], aluIn1[5], aluIn1[6], aluIn1[7], aluIn1[8], aluIn1[9], aluIn1[10], aluIn1[11], aluIn1[12], aluIn1[13], aluIn1[14], aluIn1[15], aluIn1[16], aluIn1[17], aluIn1[18], aluIn1[19], aluIn1[20], aluIn1[21], aluIn1[22], aluIn1[23], aluIn1[24], aluIn1[25], aluIn1[26], aluIn1[27], aluIn1[28], aluIn1[29], aluIn1[30], aluIn1[31]} : aluIn1);
	wire [31:0] shifter = $signed({instr[30] & aluIn1[31], shifter_in}) >>> aluIn2[4:0];
	wire [31:0] leftshift = {shifter[0], shifter[1], shifter[2], shifter[3], shifter[4], shifter[5], shifter[6], shifter[7], shifter[8], shifter[9], shifter[10], shifter[11], shifter[12], shifter[13], shifter[14], shifter[15], shifter[16], shifter[17], shifter[18], shifter[19], shifter[20], shifter[21], shifter[22], shifter[23], shifter[24], shifter[25], shifter[26], shifter[27], shifter[28], shifter[29], shifter[30], shifter[31]};
	wire [31:0] aluOut = (((((((funct3Is[0] ? (instr[30] & instr[5] ? aluMinus[31:0] : aluPlus) : 32'b00000000000000000000000000000000) | (funct3Is[1] ? leftshift : 32'b00000000000000000000000000000000)) | (funct3Is[2] ? {31'b0000000000000000000000000000000, LT} : 32'b00000000000000000000000000000000)) | (funct3Is[3] ? {31'b0000000000000000000000000000000, LTU} : 32'b00000000000000000000000000000000)) | (funct3Is[4] ? aluIn1 ^ aluIn2 : 32'b00000000000000000000000000000000)) | (funct3Is[5] ? shifter : 32'b00000000000000000000000000000000)) | (funct3Is[6] ? aluIn1 | aluIn2 : 32'b00000000000000000000000000000000)) | (funct3Is[7] ? aluIn1 & aluIn2 : 32'b00000000000000000000000000000000);
	reg [31:0] cycles;
	wire [31:0] writeBackData = (((((isSYSTEM ? cycles : 32'b00000000000000000000000000000000) | (isLUI ? Uimm : 32'b00000000000000000000000000000000)) | (isALU ? aluOut : 32'b00000000000000000000000000000000)) | (isAUIPC ? PCplusImm : 32'b00000000000000000000000000000000)) | (isJALR | isJAL ? PCplus4 : 32'b00000000000000000000000000000000)) | (isLoad ? LOAD_data : 32'b00000000000000000000000000000000);
	always @(posedge clk)
		if (writeBack) begin
			if (rdId != 0)
				registerFile[rdId] <= writeBackData;
		end
	wire EQ = aluMinus[31:0] == 0;
	wire predicate = (((((funct3Is[0] & EQ) | (funct3Is[1] & !EQ)) | (funct3Is[4] & LT)) | (funct3Is[5] & !LT)) | (funct3Is[6] & LTU)) | (funct3Is[7] & !LTU);
	wire jumpToPCplusImm = isJAL | (isBranch & predicate);
	wire [ADDR_WIDTH - 1:0] PC_new = (isJALR ? {aluPlus[ADDR_WIDTH - 1:1], 1'b0} : (jumpToPCplusImm ? PCplusImm : PCplus4));
	localparam FETCH_INSTR_bit = 0;
	localparam WAIT_INSTR_bit = 1;
	assign mem_addr = (state[WAIT_INSTR_bit] | state[FETCH_INSTR_bit] ? PC : ((state[EXECUTE_bit] & ~isLoad) & ~isStore ? PC_new : loadstore_addr));
	assign mem_wdata[7:0] = rs2[7:0];
	assign mem_wdata[15:8] = (loadstore_addr[0] ? rs2[7:0] : rs2[15:8]);
	assign mem_wdata[23:16] = (loadstore_addr[1] ? rs2[7:0] : rs2[23:16]);
	assign mem_wdata[31:24] = (loadstore_addr[0] ? rs2[7:0] : (loadstore_addr[1] ? rs2[15:8] : rs2[31:24]));
	wire [3:0] STORE_wmask = (mem_byteAccess ? (loadstore_addr[1] ? (loadstore_addr[0] ? 4'b1000 : 4'b0100) : (loadstore_addr[0] ? 4'b0010 : 4'b0001)) : (mem_halfwordAccess ? (loadstore_addr[1] ? 4'b1100 : 4'b0011) : 4'b1111));
	localparam NB_STATES = 4;
	localparam FETCH_INSTR = 1;
	localparam WAIT_INSTR = 2;
	localparam EXECUTE = 4;
	localparam WAIT_ALU_OR_MEM = 8;
	(* onehot *) reg [3:0] state;
	assign mem_rstrb = (state[EXECUTE_bit] & ~isStore) | state[FETCH_INSTR_bit];
	assign mem_wmask = {4 {state[EXECUTE_bit] & isStore}} & STORE_wmask;
	wire needToWait = isLoad | isStore;
	always @(posedge clk)
		if (!reset) begin
			state <= WAIT_ALU_OR_MEM;
			PC <= RESET_ADDR[ADDR_WIDTH - 1:0];
		end
		else
			(* parallel_case *)
			case (1'b1)
				state[WAIT_INSTR_bit]:
					if (!mem_rbusy) begin
						rs1 <= registerFile[mem_rdata[19:15]];
						rs2 <= registerFile[mem_rdata[24:20]];
						instr <= mem_rdata[31:2];
						state <= EXECUTE;
					end
				state[EXECUTE_bit]: begin
					PC <= PC_new;
					state <= (needToWait ? WAIT_ALU_OR_MEM : WAIT_INSTR);
				end
				state[WAIT_ALU_OR_MEM_bit]:
					if (!mem_rbusy & !mem_wbusy)
						state <= FETCH_INSTR;
				default: state <= WAIT_INSTR;
			endcase
	always @(posedge clk) cycles <= cycles + 1;
endmodule
