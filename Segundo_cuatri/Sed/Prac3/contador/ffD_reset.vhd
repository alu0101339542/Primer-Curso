----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:04:23 04/14/2020 
-- Design Name: 
-- Module Name:    ffD_reset - Behavioral 
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

entity ffD_reset is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           CE : in  STD_LOGIC;
           d : in  STD_LOGIC;
           q : out  STD_LOGIC);
end ffD_reset;

architecture Behavioral of ffD_reset is

begin

process(clk, reset)
begin
	if reset = '1' then 
		q<= '0';
	elsif (clk'event and clk='1') then 
		if CE = '1' then
			q<=d;
		end if;
	end if;
end process;
end Behavioral;

