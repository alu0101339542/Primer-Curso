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

entity contador is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           ce : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (3 downto 0));
end contador;

	architecture Behavioral of contador is

COMPONENT ffD_reset
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		ce : IN std_logic;
		d : IN std_logic;          
		q : OUT std_logic
		);
	END COMPONENT;
COMPONENT ffT_reset
	PORT(
		clk : IN std_logic;
		reset : IN std_logic;
		ce : IN std_logic;
		t : IN std_logic;          
		q : OUT std_logic
		);
	END COMPONENT;
	
	signal qa, qb, qc, qd :std_logic;
	signal ta, tb, dc, dd :std_logic;
	

begin
unit_A: ffT_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		t => ta,
		q => qa
	);
	unit_B: ffT_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		t => tb,
		q => qb
	);
	unit_C: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => dc,
		q => qc
	);
	unit_D: ffD_reset PORT MAP(
		clk => clk,
		reset => reset,
		ce => ce,
		d => dd,
		q => qd
	);
	dd <= qa or ((not qc) and (qb xor qd)) or (qc and (not qd));
	dc<= (qa and (not qd)) or (qc and qd) or (qb and (not qc) and (not qd));
	tb <= (qa and (not qd)) or (qb and (not qc) and (not qd));
	ta <=(qa and (not qd)) or ((not qa) and (not qb) and (not qc));
	
	count <= qa & qb & qc & qd; -- concatenación
--  count(0) <= qd;
--  count(1) <= qc;
--  count(2) <= qb;
--  count(3) <= qa;

	end Behavioral;
