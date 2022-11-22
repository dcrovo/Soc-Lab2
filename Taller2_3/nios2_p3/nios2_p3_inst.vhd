	component nios2_p3 is
		port (
			clk_clk       : in  std_logic                    := 'X';             -- clk
			reset_reset_n : in  std_logic                    := 'X';             -- reset_n
			hex_0_export  : out std_logic_vector(6 downto 0);                    -- export
			switch_export : in  std_logic_vector(6 downto 0) := (others => 'X'); -- export
			hex_1_export  : out std_logic_vector(6 downto 0);                    -- export
			hex_2_export  : out std_logic_vector(6 downto 0);                    -- export
			hex_3_export  : out std_logic_vector(6 downto 0);                    -- export
			hex_4_export  : out std_logic_vector(6 downto 0);                    -- export
			hex_5_export  : out std_logic_vector(6 downto 0)                     -- export
		);
	end component nios2_p3;

	u0 : component nios2_p3
		port map (
			clk_clk       => CONNECTED_TO_clk_clk,       --    clk.clk
			reset_reset_n => CONNECTED_TO_reset_reset_n, --  reset.reset_n
			hex_0_export  => CONNECTED_TO_hex_0_export,  --  hex_0.export
			switch_export => CONNECTED_TO_switch_export, -- switch.export
			hex_1_export  => CONNECTED_TO_hex_1_export,  --  hex_1.export
			hex_2_export  => CONNECTED_TO_hex_2_export,  --  hex_2.export
			hex_3_export  => CONNECTED_TO_hex_3_export,  --  hex_3.export
			hex_4_export  => CONNECTED_TO_hex_4_export,  --  hex_4.export
			hex_5_export  => CONNECTED_TO_hex_5_export   --  hex_5.export
		);

