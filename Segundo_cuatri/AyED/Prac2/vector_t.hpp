// AUTOR: Daniel Prez Lozano
// FECHA: 13-03-20
// EMAIL: alu0101339542@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class vector_t
{
public:
  vector_t(const int = 0);
  ~vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);
  void even_elements(void);

private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};



template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}



template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}



template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}



template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;
  build();
}


//getters
template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}



template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}



template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}



template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void
vector_t<T>::read(istream& is)
{
  cout << "Introduce el tamaño del vector" << endl;
  is >> sz_;
  resize(sz_);
  cout << "Introduce el valor del vector" << endl;
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  
    T scal;
    for (int j = 0; j < v.get_size(); ++j){
      scal += v.at(j)*w.at(j);
    }
    return scal;
  
  
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  double scalar;
  for (int j = 0; j < v.get_size(); ++j){
    scalar= scalar + (v.at(j)*w.at(j)).value();
  }
  return scalar;
}


template<class T>
 T operator*(const vector_t<T>& a, const vector_t<T>& b)
{
  return scal_prod(a, b);
}
//Desarrolla unt método de la clase vector_t que muestre por pantalla sólo los elementos del 
//vector en posiciones cuyo índice sea par. Su cabecera debe ser:
template <class T>
void 
vector_t<T>::even_elements(void){
  for (int k = 0; k < get_size() ; k++)
  if (k % 2 != 0){
    cout<<"par: "<<at(k) << endl;
  }
}