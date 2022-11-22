	component nios_2 is
		port (
			button_export : in  std_logic                    := 'X';             -- export
			clk_clk       : in  std_logic                    := 'X';             -- clk
			led_export    : out std_logic_vector(9 downto 0);                    -- export
			reset_reset_n : in  std_logic                    := 'X';             -- reset_n
			switch_export : in  std_logic_vector(4 downto 0) := (others => 'X')  -- export
		);
	end component nios_2;

	u0 : component nios_2
		port map (
			button_export => CONNECTED_TO_button_export, -- button.export
			clk_clk       => CONNECTED_TO_clk_clk,       --    clk.clk
			led_export    => CONNECTED_TO_led_export,    --    led.export
			reset_reset_n => CONNECTED_TO_reset_reset_n, --  reset.reset_n
			switch_export => CONNECTED_TO_switch_export  -- switch.export
		);

