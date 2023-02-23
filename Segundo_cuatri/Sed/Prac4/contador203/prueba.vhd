
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity prueba is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           z : out  STD_LOGIC;
           y : out  STD_LOGIC);
end prueba;

architecture Behavioral of prueba is

begin
y<= a nand b;
z <= a (not b);


end Behavioral;

