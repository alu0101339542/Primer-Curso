----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:15:17 04/14/2020 
-- Design Name: 
-- Module Name:    contador - Behavioral 
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

entity contador_wrapper is
    Port ( V_BT : in STD_LOGIC_VECTOR (1 downto 0);
           V_SW : in STD_LOGIC_VECTOR (0 downto 0);
           G_HEX0 : out  STD_LOGIC_VECTOR (3 downto 0));
end contador_wrapper;

architecture Behavioral of contador_wrapper is

COMPONENT contador
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		CE : IN std_logic;
		count: OUT std_logic_vector(3 downto 0) 
		);
	END COMPONENT;
	
	

begin
Inst_contador: contador PORT MAP(
clk => V_BT(0),
reset => V_BT(1),
ce => V_SW(0),
count => G_HEX0
);

	end Behavioral;