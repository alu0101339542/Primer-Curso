// AUTOR: // AUTOR: Daniel Pérez Lozano

// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>
#include "queue_l_t.hpp"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void);
  ~rpn_t();

  const int evaluate(queue_l_t<char>&);

private: 
  T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    char c = q.front();
    q.pop();
    cout << "Sacamos de la cola un carácter: " << c;

		if (isdigit(c))
		{
		  int i = c - '0';
		  stack_.push(i);
		  // poner código
		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
		}
		else {
		  cout << " (es un operador)" << endl;
		  // poner código
		  operate_(c);

		}
	}

	// poner código
	//stack_.write();
	return stack_.top();
	
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{

  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c== 'r'|| c == 'l'|| c == 'c');

  // código
  int oper1,oper2;
  oper1 = stack_.top();
  stack_.pop();
  cout << "   Sacamos de la pila un operando: "<<oper1 << endl;
  if(c == '+' || c == '-' || c == '*' || c == '/'|| c == '^'){
  	// código
  	 oper2 = stack_.top();
  	stack_.pop();
  	cout << "   Sacamos de la pila otro operando: " <<oper2<< endl;
  }
  	int resul;	  
 switch (c)
	{
		case '+': 
			resul = oper1 + oper2;
	            break;
	  // resto de operadores
		case '-': // código
			resul = oper2 - oper1;
	            break;
		case '*': // código
			resul = oper1 * oper2;

	            break;
		case '/': // código
			resul = oper2 / oper1;
	            break;
		case 'r': // código
				resul = sqrt(oper1);//Suponemos que el operando que sacamos primero de la pila es la base.
	            break;
		case '^': // código
			resul = pow(oper1, oper2);//Suponemos que el operando que sacamos primero de la pila es la base.
	            break;
		case 'l':
			resul = log2(oper1);
				break;
		case 'c':
			resul = pow(oper1, 2);
				break;

	}
	stack_.push(resul);
	// código
	cout << "   Metemos en la pila el resultado: "<<resul << endl;
}

}
