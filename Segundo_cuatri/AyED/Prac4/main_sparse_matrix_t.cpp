// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g main_sparse_matrix_t.cpp -o main_sparse_matrix_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "vector_t.hpp"
#include "matrix_t.hpp"
#include "sparse_vector_t.hpp"
#include "sparse_matrix_t.hpp"


using namespace std;

int main()
{
  AED::vector_t<double> v1;
  cin >> v1;
  cout << "v1= " << v1;
  cout << endl;
  
  AED::sparse_vector_t sv1(v1);
  cout << "sv1= " << sv1;
  cout << endl;
  
  AED::matrix_t<double> M1, M2, M3;
  cin >> M1 >> M2;
  cout << "M1= " << M1;
  cout << "M2= " << M2;
  
  // FASE I
  AED::sparse_matrix_t SM1(M1, false);
  cout << "SM1= " << SM1;
  cout << endl;

  // FASE II
  cout << "sv1 * M1(·, 1)= " << sv1.scal_prod(M1, 1) << endl;
  cout << "sv1 * M1(·, 2)= " << sv1.scal_prod(M1, 2) << endl;
  cout << endl;

  AED::sparse_matrix_t SM2(M2);
  cout << "SM2= " << SM2;
  cout << endl;

  // FASE III
  SM2.multiply(M1, M3);
  cout << "M3 = SM2 * M1" << endl;
  cout << M3;
  
  return 0;
}