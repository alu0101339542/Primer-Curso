--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:37:55 05/01/2020
-- Design Name:   
-- Module Name:   /home/dani/Desktop/Segundo cuatri/Sed/Prac4/contador203/contador203_tb.vhd
-- Project Name:  contador203

--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY contador203_tb IS
END contador203_tb;
 
ARCHITECTURE behavior OF contador203_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT contador
    PORT(
         clk : IN  std_logic;
         reset : IN  std_logic;
         ce : IN  std_logic;
         count : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal ce : std_logic := '0';

 	--Outputs
   signal count : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: contador PORT MAP (
          clk => clk,
          reset => reset,
          ce => ce,
          count => count
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin	
		reset<= '1'; ce<= '1';
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		reset<='0';

      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
