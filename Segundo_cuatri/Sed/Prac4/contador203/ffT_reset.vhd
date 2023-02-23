----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:23:38 05/01/2020 
-- Design Name: 
-- Module Name:    ffT_reset - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ffT_reset is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           t : in  STD_LOGIC;
           q : out  STD_LOGIC);
end ffT_reset;

architecture Behavioral of ffT_reset is

signal Q_aux: STD_LOGIC;
begin
process(clk, reset)
begin
	if reset = '1' then 
		Q_aux <= '0';
	elsif (clk'event and clk='1') then 
		if ce = '1' then
			if t = '0' then 
				Q_aux <= Q_aux;
			end if;
			if t ='1' then
				Q_aux <= not Q_aux;
			end if;
		end if;
	end if;
end process;
q <= Q_aux;

end Behavioral;


