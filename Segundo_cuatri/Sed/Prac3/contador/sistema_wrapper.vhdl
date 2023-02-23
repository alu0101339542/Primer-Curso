library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity sistema_wrapper is
    Port ( V_BT : in STD_LOGIC_VECTOR (1 downto 0);
           V_SW : in STD_LOGIC_VECTOR (0 downto 0);
           G_HEX0: out  STD_LOGIC_VECTOR (6 downto 0);
           G_LEDR: out  STD_LOGIC_VECTOR (3 downto 0));
end sistema_wrapper;

architecture Behavioral of sistema_wrapper is

COMPONENT sistema
    PORT(
        clk : in  STD_LOGIC;
        ce : in  STD_LOGIC;
        reset : in  STD_LOGIC;
        count : out  STD_LOGIC_VECTOR (3 downto 0);
        led : out  STD_LOGIC_VECTOR (6 downto 0));
END COMPONENT;

signal int: std_logic_vector(3 downto 0);

begin
Inst_sistema: sistema PORT MAP(
clk => V_BT(0),
reset => V_BT(1),
ce => V_SW(0),
count => G_LEDR,
led => G_HEX0
);

end Behavioral;
