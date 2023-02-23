// PRÁCTICA Nº: 5
// COMENTARIOS: programa principal para probar la calculadora de expresiones 
//              en notaión polaca inversa (RPN, Reverse Polish Notation)
// Compilar con:
// g++ main_rpn_t.cpp -o main_rpn_t

#include <iostream>

#include "stack_l_t.hpp"
#include "queue_l_t.hpp"
#include "rpn_t.hpp"

using namespace std;
using namespace AED;



int main(void)
{	stack_l_t<int> mod;
	
	queue_l_t<char> cola;
	while (!cin.eof())
	{
		cin >> ws; // lee los espacios en blanco, que dan problemas
		if (!cin.eof())
		{	char c;
		
		  cin >> c;
		  if (isdigit(c))
			mod.push(c-'0');
            
		}
	}
	
	

  cout << "Expresión a evaluar: ";	
	//cola.write();

  int r = mod.sum2_();
	cout << "Resultado: " << r << endl;

	return 0;
}
