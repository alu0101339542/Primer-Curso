// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>


#include "vector_t.hpp"
#include "pair_t.hpp"

#define EPSILON 1e-6
using namespace std;
bool is_equal(const double a, const double b, const double epsilon = EPSILON)
{ // |a - b| < ϵ
  return (fabs(a - b) < epsilon);
}

typedef vector_t<pair_t<double>> pair_vector_t;

class sparse_vector_t
{
public:
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  
  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t();
  
  // getters
   int get_nz(void) const;
   int get_n(void) const;
   
   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);

   // E/S
   void write(ostream& = cout) const;
  //mod
  int search_vals(const double);
  //mod2
  void odd(void);
  //mod3
  sparse_vector_t comp(const sparse_vector_t&);
private:
  pair_vector_t pv_; // valores + índices
  int     nz_;       // nº de valores distintos de cero = tamaño del vector
  int     n_;        // tamaño del vector original
  
  bool is_not_zero(double, double = 1e-6) const;
};



// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
pv_(),
nz_(0),
n_(0)
{
  pair_t<double> par;
   // contamos el número de elementos distintos de cero (nz_)
  for (int i = 0; i < v.get_size(); i++)
    if (is_not_zero(v[i]))
      nz_++;

  pv_.resize(nz_);
  //valor para almacenar el vector 
   
   int j = 0;
  // copiamos los elementos distintos de cero al vector escaso
  for (int i = 0; i < v.get_size(); i++)
    if (is_not_zero(v[i])) {
      par.set(v[i],i);
      pv_.set_val(j, par);
      j++;
    }
  n_ = v.get_size();
  //CREO que hay que paserle el val() y el inx() de la clase pair
  // poner el código aquí
  
}



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
  pv_ = w.pv_;

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



void
sparse_vector_t::write(ostream& os) const
{ 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << endl;
}



ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}



bool
sparse_vector_t::is_not_zero(double v, double eps) const
{
  return fabs(v) > eps;
}



// operaciones
// FASE III
double
sparse_vector_t::scal_prod(const vector_t<double>& v){
  double t;
  int pos;
  pair_t <double> element;
  assert(get_n() == v.get_size());
  for (int i = 0; i < nz_; i++){
    element= pv_.get_val(i);
    pos= element.get_inx();
    pos = element.get_inx();
    t += v.get_val(pos) * element.get_val();
  }
  


  return t;
}



/// FASE IV
double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  double s = 0;
  pair_t <double> ele2;
  pair_t <double> ele1;
  
  assert(get_n() == sv.get_n());

  for (int i = 0;i< sv.get_nz(); i++){
    ele1 = sv.pv_.get_val(i);
    int posi = ele1.get_inx();
    for (int j = 0;j < get_nz(); j++){
      ele2 = pv_.get_val(j);//No hay un metodo que se llame asi para este objeto
      int posit = ele2.get_inx();
      if (posi == posit){
        s += ele2.get_val()*ele1.get_val();
      }
    }

  }
  return s;
}
//Modificacion
int 
sparse_vector_t::search_vals(const double refer){
  int rep=0;
  pair_t <double> disp;

  for(int i=0; i<get_nz(); i++){
    disp= pv_.get_val(i);
    if(is_equal(refer, disp.get_val())){
      rep++;
    }
  }

  return rep;
}
//Mod2
void
sparse_vector_t::odd(void){
  pair_t <double> odd_num;
  cout<<"Indices impares: "<<endl;
  for(int i=0; i<get_nz(); i++){
    odd_num= pv_.get_val(i);
    if(odd_num.get_inx() %2!= 0){
      cout<< " "<< ","<<odd_num.get_inx();
    }
  }
}
//Mod3
sparse_vector_t comp(const sparse_vector_t&sve){
  pair_t <double> parej;
  pair_t <double> parej2;
  double valo, valo2;
  int indi, indi2;

    for(int i=0; i<get_size(); i++){
      parej= pv_.get_val(i);
      indi = parej.get_inx();
      valo = parej.get_val();
      for(int j = 0; j< get_size(); j++){
        parej2 = pv_.get_val(i);
        indi2 = parej2.get_inx();
        valo2 = parej2.get_val();
      }
        

    }

}