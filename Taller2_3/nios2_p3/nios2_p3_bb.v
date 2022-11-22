
module nios2_p3 (
	clk_clk,
	reset_reset_n,
	hex_0_export,
	switch_export,
	hex_1_export,
	hex_2_export,
	hex_3_export,
	hex_4_export,
	hex_5_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[6:0]	hex_0_export;
	input	[6:0]	switch_export;
	output	[6:0]	hex_1_export;
	output	[6:0]	hex_2_export;
	output	[6:0]	hex_3_export;
	output	[6:0]	hex_4_export;
	output	[6:0]	hex_5_export;
endmodule
