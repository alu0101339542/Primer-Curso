// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "pair_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"

using namespace std;

typedef AED::pair_t<double>             pair_double_t;
typedef AED::dll_node_t<pair_double_t>  dll_node_pair_t;
typedef AED::dll_t<pair_double_t>       dll_pair_t;

bool is_not_zero(double v, double eps = 1e-6)
{
  return fabs(v) > eps;
}

namespace AED
{
class sparse_vector_t
{
public:
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(void); // constructor por defecto
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  
  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t();
  
  // getters
   int get_nz(void) const;
   int get_n(void) const;
   
   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);
   double scal_prod(const matrix_t<double>&, int);
   
   // E/S
   void write(ostream& = cout) const;

private:
  dll_pair_t lp_; // valores + índices
  int     nz_;    // nº de valores distintos de cero = tamaño del vector
  int     n_;     // tamaño del vector original
};



sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
lp_(),
nz_(0),
n_(0)
{
  n_ = v.get_size();
  
  // copiamos los elementos distintos de cero al vector escaso
  for (int i = 0; i < v.get_size(); ++i)
    if (is_not_zero(v[i])) {
      pair_double_t p(v[i], i);
      dll_node_pair_t* nodo = new dll_node_pair_t(p);
      assert(nodo != NULL);
      lp_.insert_tail(nodo);
      nz_++;
    }
}



sparse_vector_t::sparse_vector_t():
lp_(),
nz_(0),
n_(0)
{}



// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w)
{
  *this = w; // invocamos directamente al operator=
}



// operador de asignación
sparse_vector_t&
sparse_vector_t::operator=(const sparse_vector_t& w)
{
  nz_ = w.get_nz();
  n_ = w.get_n();
  lp_ = w.lp_;

  return *this;
}



sparse_vector_t::~sparse_vector_t()
{}



inline int
sparse_vector_t::get_nz() const
{
  return nz_;
}



inline int
sparse_vector_t::get_n() const
{
  return n_;
}



// operaciones
double
sparse_vector_t::scal_prod(const vector_t<double>& v)
{
  assert(get_n() == v.get_size());
  double s = 0;
  dll_node_pair_t* aux = lp_.get_head();
  while (aux != NULL) {
    s += aux->get_data().get_val() * v[aux->get_data().get_inx()];
    aux = aux->get_next();
  }
  return s;
}



double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  assert(get_n() == sv.get_n());
  double s = 0;
  dll_node_pair_t *i = lp_.get_head(), 
                  *j = sv.lp_.get_head();
  while (i != NULL && j != NULL) {
    if (i->get_data().get_inx() == j->get_data().get_inx()) {
      s += i->get_data().get_val() * j->get_data().get_val();
      i = i->get_next();
      j = j->get_next();
    }
    else if (i->get_data().get_inx() < j->get_data().get_inx()) i = i->get_next();
    else                                                        j = j->get_next();
  }

  return s;
}



// FASE II
double
sparse_vector_t::scal_prod(const matrix_t<double>& M, int j)
{
  assert(get_n() == M.get_m());
  double s = 0;
  // código aquí
  s= scal_prod(M.get_col(j));
  return s;
}



void
sparse_vector_t::write(ostream& os) const
{ 
  os << get_n() << "(" << get_nz() << "): [ ";
  dll_node_pair_t* aux = lp_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
	os << "]" << endl;
}



ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}
//moD
void sparse_vector_t::add(const sparse_matrix_t& ma, int j, vector_t<double>& ve){
  assert(ma.get_m()==get_n());
  ve.resize(get_n());
  pair_t valor;
  double d1, d2;
  //Llamamos al metodo get_col de la clase Sparse_matrix_t que hemos creado.
  sparse_vector_t v1 = ma.get_col(j);
 
  //Llamos al método de esta clase que nos devuelve lp_;

  dll_pair_t lista = v1.get_lp();
  dll_node_pair_t nodo1= lista.extract_head();

      for(int i= 0; i< get_n(); i++){
        for(int j = 0; j< lista.get_size();j++){
          valor = nodo1.get_data();
          if(valor.get_inx()==i){
            d1 = valor.get_val();
            break;
            
          }
          nodo1 =nodo1.get_next();
        }
        dll_pair_t lista2 = lp_;
        dll_node_pair_t nodo2= lista2.extract_head();
        for(j=0; j< get_nz();j++){
          valor = nodo2.get_data();
          if(valor.get_inx()==i){
            d2 = valor.get_val();
            break;
            
          }
          nodo2 =nodo2.get_next();
        }
        ve.set_val(i,d1+d2 );
        d1=0; 
        d2=0;


     }
  
}
double sparse_vector_t::dot_prod(const vector_t<double>& d, const int i = 0){
   assert(get_n() == d.get_size());
   double result;
   dll_node_pair_t dummy;
  /*double s = 0;
  dll_node_pair_t* aux = lp_.get_head();
  while (aux != NULL) {
    s += aux->get_data().get_val() * v[aux->get_data().get_inx()];
    aux = aux->get_next(); */
    if(i== get_nz())
     dummy= lp_.extract_tail();
     int x = dummy.get_inx();
     double val=dummy.get_val();
     result = d.get_val(i) * val;
     return result;
  }
  else{
    result += dot_prod(d,++i);
    
  }
}
} // namespace