library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity prueba2 is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           x : out  STD_LOGIC;
           y : out  STD_LOGIC;
           z : out  STD_LOGIC);
end prueba2;

architecture Behavioral of prueba2 is
signal int1, int2:std_logic;

begin
z<= a xor b xor int1 xor int2;
x<= b nand a;
int2 <= a and int1;
y<= c xnor a;
int1 <= b;
x <= int1 or a;




end Behavioral;

