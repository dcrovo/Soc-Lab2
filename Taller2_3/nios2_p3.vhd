------------------------------------------------------
LIBRARY IEEE;
USE ieee.std_logic_1164.all;
------------------------------------------------------
ENTITY nios2_p3_top IS
PORT (	clk		:	IN STD_LOGIC;
			sw			:	IN STD_LOGIC_VECTOR(6 DOWNTO 0);
			hex_0		:	OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			hex_1		:	OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			hex_2		:	OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			hex_3		:	OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			hex_4		:	OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			hex_5		:	OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END ENTITY nios2_p3_top;
------------------------------------------------------
ARCHITECTURE arch OF nios2_p3_top IS

	COMPONENT nios2_p3 IS
	PORT	(clk_clk			: IN STD_LOGIC;
			hex_0_export	: OUT STD_LOGIC_VECTOR(6 downto 0);						
			hex_1_export	: OUT STD_LOGIC_VECTOR(6 downto 0);
			hex_2_export	: OUT STD_LOGIC_VECTOR(6 downto 0);
			hex_3_export	: OUT STD_LOGIC_VECTOR(6 downto 0);
			hex_4_export	: OUT STD_LOGIC_VECTOR(6 downto 0);
			hex_5_export	: OUT STD_LOGIC_VECTOR(6 downto 0);
			reset_reset_n	: IN STD_LOGIC;
			switch_export	: IN STD_LOGIC_VECTOR(6 downto 0));
			
	END COMPONENT nios2_p3;

BEGIN
	nios_unit:	COMPONENT nios2_p3
					PORT MAP	(clk_clk			=> clk,
								 reset_reset_n => '1',
								 hex_0_export		=> hex_0,
								 hex_1_export		=> hex_1,
								 hex_2_export		=> hex_2,
								 hex_3_export		=> hex_3,
								 hex_4_export		=> hex_4,
								 hex_5_export		=> hex_5,
								 switch_export => sw);
END ARCHITECTURE;