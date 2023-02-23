----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:41:55 04/14/2020 
-- Design Name: 
-- Module Name:    sistema - Behavioral 
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

entity sistema203 is
    Port ( clk : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (3 downto 0);
           led : out  STD_LOGIC_VECTOR (6 downto 0));
end sistema203;

architecture Behavioral of sistema203 is

COMPONENT contador203
PORT(
reset: IN std_logic;
ce: IN std_logic;
clk: IN std_logic; 
count: OUT std_logic_vector(3 downto 0)
);
END COMPONENT;

COMPONENT dec7seg
PORT(
bcd: IN std_logic_vector(3 downto 0);
led: OUT std_logic_vector(6 downto 0)
);
END COMPONENT;

signal int: std_logic_vector(3 downto 0);

begin
Inst_contador: contador203 PORT MAP(
reset => reset,
ce => ce,
clk => clk,
count => int
);

Inst_dec7seg: dec7seg PORT MAP(
	bcd =>int,
	led => led
);
count <= int;
end Behavioral;


