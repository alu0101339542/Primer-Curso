// AUTOR: Daniel Pérez Lozano
// FECHA: 17/02/20
// EMAIL: alu0101339542@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datosmul
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"
//En este método llama al constructor de la clase definido en la librería rational_t.hpp, 
// a este método le pasa dos enteros constantes n y d, a continuación llama 
// al macro assert y lo compara a 0 en caso de "d" (denominador) no ser igual, se le asigna
// a un atributo num el valor de n y a un atributo d el valor de den
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
//este método se limita a simplemente devolverte num_  
int
rational_t::get_num() const
{
  return num_; rational_t ratmult;
  ratmult.set_num(get_num() * r.get_num());
  ratmult.set_den(get_den() * r.get_den());
  return ratmult;
  num_ = n;
}

// Asigna al atributo den_ el valor de d, que se le pasa al método.
// Previamiente se comprueba que d es diferente de 0, en caso opuesto
// la macro assert daría un error y se abortaría el programa
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


//Aquí te devuelve el resultado de la división entre el numerador y el denominador
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}

// comparaciones
//Este método comprueba si los números que se le pasan a través del main son
//iguales, devolviendo un booleano true en caso de ser cierto y false en el caso de ser falso.
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ if(fabs(value() - r.value()) <precision)
    return true;
  else 
    return false;
}


//Este método comprueba si el número con el que se llama al método es mayor que 
//el que se pasa como argumento referenciado por "&r".
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  if((value() - r.value()) > precision) 
    return true;
  else 
    return false;
}


//Este método comprueba si el número con el que se llama al método es menor que 
//el que se pasa como argumento referenciado por "&r".
bool
rational_t::is_less(const rational_t& r, const double precision) const
{ 
  if((r.value() - value()) >precision)
    return true;
  else 
    return false;

}


// operaciones
//Este método hace la suma fraccional de dos objetos de la clase rational_t, esto se hace gracias al método add, del objeto 
//actual y le pasamos al método como parametro otro objeto definido como r. El resultado de la suma será almacenado en otro 
//objeto de la clase que crearemos, en este caso lo hemos llamado ratadd. Para efectuar la suma fraccionaria llamaremos al método 
//set_num y set_den del nuevo objeto, tras las operaciones matemáticas pertinentes se devolverá al método el objeto ratadd que 
//contendrá el numerador y denominador deseados.
rational_t
rational_t::add(const rational_t& r)
{
  rational_t ratadd;

  ratadd.set_num(get_den()*(r.get_num()) +get_num()*r.get_den());
  ratadd.set_den(get_den()*r.get_den());
  return ratadd;
}


//Este método hace la resta fraccional de dos objetos de la clase rational_t, esto se hace gracias al método substract, del objeto 
//actual y le pasamos al método como parametro otro objeto definido como r. El resultado de la resta será almacenado en otro 
//objeto de la clase que crearemos, en este caso lo hemos llamado rationalsubs. Para efectuar la resta fraccionaria llamaremos al método 
//set_num y set_den del nuevo objeto, tras las operaciones matemáticas pertinentes se devolverá al método el objeto rationalsubs que 
//contendrá el numerador y denominador deseados.
rational_t
rational_t::substract(const rational_t& r)
{
  rational_t rationalsubs;

  rationalsubs.set_num(r.get_den()*(get_num()) - r.get_num()*get_den());
  rationalsubs.set_den(get_den()*r.get_den());
  return rationalsubs;
}


//Este método hace la multiplicacion fraccional de dos objetos de la clase rational_t, esto se hace gracias al método multiply, 
//del objeto actual y le pasamos al método como parametro otro objeto definido como r. El resultado de la multipliacion
//será almacenado en otro objeto de la clase que crearemos, en este caso lo hemos llamado ratmult. Para efectuar la multiplicación
//fraccionaria llamaremos al método set_num y set_den del nuevo objeto, tras las operaciones matemáticas pertinentes se devolverá 
//al método el objeto ratmult que contendrá el numerador y denominador deseados.
rational_t
rational_t::multiply(const rational_t& r)
{
  rational_t ratmult;
  ratmult.set_num(get_num() * r.get_num());
  ratmult.set_den(get_den() * r.get_den());
  return ratmult;
}


//Este método hace la multiplicacion fraccional de dos objetos de la clase rational_t, esto se hace gracias al método divide, 
//del objeto actual y le pasamos al método como parametro otro objeto definido como r. El resultado de la divicion
//será almacenado en otro objeto de la clase que crearemos, en este caso lo hemos llamado ratdiv. Para efectuar la divición
//fraccionaria llamaremos al método set_num y set_den del nuevo objeto, tras las operaciones matemáticas pertinentes se devolverá 
//al método el objeto ratdiv que contendrá el numerador y denominador deseados.
rational_t
rational_t::divide(const rational_t& r)
{ 
  rational_t ratdiv;
  ratdiv.set_num(get_num() * r.get_den());
  ratdiv.set_den(get_den() * r.get_num());
  return ratdiv;
  
}



// E/S
// En este metodo se imprime por pantalla la división, junto a su resultado llamando a otros métodos declarados previamente.
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// Aquí se imprime por pantalla Numerador? y se le pasa por teclado un valor, el cual guardará en num_, 
// mismo proceso con el denominador, si el denominador introducido es igual a 0 la macro assert va a dar 
// un error y se abortará la ejecución del programa.
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
