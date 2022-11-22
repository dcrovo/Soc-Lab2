
module nios_2 (
	button_export,
	clk_clk,
	led_export,
	reset_reset_n,
	switch_export);	

	input		button_export;
	input		clk_clk;
	output	[9:0]	led_export;
	input		reset_reset_n;
	input	[4:0]	switch_export;
endmodule
