// AUTOR: Daniel Pérez Lozano
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase TAD cola implementada con una lista

#pragma once

#include <iostream>
#include <cassert>

#include "dll_t.hpp"

using namespace std;

namespace AED
{
template <class T>
class queue_l_t
{
private:
	dll_t<T>    l_;

public:
	// constructor y destructor
	queue_l_t(void);
	~queue_l_t(void);

	bool empty(void) const;
	int size(void) const;

	// operaciones
	void push(const T& dato);
	void pop(void);
	const T& front(void) const;
	const T& back(void) const;

	void write(ostream& os = cout) const;
};



template<class T>
queue_l_t<T>::queue_l_t(void):
l_()
{}



template<class T>
queue_l_t<T>::~queue_l_t(void)
{}



template<class T>
bool
queue_l_t<T>::empty(void) const
{
	return l_.empty();
}


template<class T>
int
queue_l_t<T>::size(void) const
{
	return l_.get_size();		
}


template<class T>
void
queue_l_t<T>::push(const T& dato)
{
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
	l_.insert_head(node);
}



template<class T>
void
queue_l_t<T>::pop(void)
{
	assert(!empty());
	delete l_.extract_tail();
}



template<class T>
const T&
queue_l_t<T>::front(void) const
{
	assert(!empty());
	return (l_.get_tail()->get_data());
}



template<class T>
const T&
queue_l_t<T>::back(void) const
{
	assert(!empty());
	return (l_.get_head()->get_data());
}


template<class T>
void
queue_l_t<T>::write(ostream& os) const
{
	dll_node_t<T>* aux = l_.get_head();
	while(aux != NULL)
	{
		os << aux->get_data() << " ";
		aux = aux->get_next();
	}
	os << endl;
}



template<class T>
ostream&
operator<<(ostream& os, const queue_l_t<T>& q)
{
	q.write(os);
	return os;
}

} // namespace