//`timescale 1ns / 1ps

module ps2(
		input clk,
		input rst,
		output isR,
		output isC,
		output is1,
		output is2,
		output isS,
		output isZ,
		output isX,
		output isT,
		input ps2_data,
		input ps2_clk
	);
	
	reg [10:0] dat;
	
	reg[1:0] ps2_clock;
	always @(posedge clk)
		ps2_clock <= {ps2_clock[0],ps2_clk};

	wire flanke = (ps2_clock == 2'b01);
	wire stop = (dat[0]==1'b0);
	
	always @(posedge clk)
		if (rst|stop) //rst
			dat <= 11'b11111111111;
		else if (flanke)
			dat <= {ps2_data,dat[10:1]};

	reg [23:0] bytes;
	always @(posedge clk)
		if (rst)
			bytes<= 0;
		else if (stop)
			bytes <= {bytes[15:0],dat[8:1]};	

	reg isR=0;
	always @(posedge clk)
		if (rst|(bytes[15:0]==16'hF02D)) //rst
			isR <= 0;
		else if (bytes[7:0]==8'h2D) //1C
			isR <= 1;
	
	reg isC=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF021)) //rst
			isC <= 0;
		else if (bytes[7:0]==8'h21) //1C
			isC <= 1;
	
	reg is1=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF016)) //rst
			is1 <= 0;
		else if (bytes[7:0]==8'h16) //1C
			is1 <= 1;
	
	reg is2=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF01E)) //rst
			is2 <= 0;
		else if (bytes[7:0]==8'h1E) //1C
			is2 <= 1;
	
	reg isS=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF029)) //rst
			isS <= 0;
		else if (bytes[7:0]==8'h29) //1C
			isS <= 1;
	reg isZ=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF01A)) //rst
			isZ <= 0;
		else if (bytes[7:0]==8'h1A) //1C
			isZ <= 1;
	reg isX=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF022)) //rst
			isX <= 0;
		else if (bytes[7:0]==8'h22) //1C
			isX <= 1;
	reg isT=0;
	always @(posedge clk)
		if ((bytes[15:0]==16'hF02C)) //rst
			isT <= 0;
		else if (bytes[7:0]==8'h2C) //1C
			isT <= 1;
endmodule
