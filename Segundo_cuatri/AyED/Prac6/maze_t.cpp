// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "maze_t.hpp"


// constructor
maze_t::maze_t():
matrix_(),
visited_(), 
i_start_(-1),
j_start_(-1), 
i_end_(-1),
j_end_(-1),
contador(0),
pila()
{}


// destructor
maze_t::~maze_t()
{}



// método que resuelve el laberinto invocando al método recursivo
bool
maze_t::solve()
{
  bool output;
  output = solve_(i_start_, j_start_);
  cout<< "contador: "<< contador << endl;
  
  return output;
}



// lee el laberinto en forma de matriz desde la entrada
istream&
maze_t::read(istream& is)
{ 
  int m, n;
  is >> m >> n;
  assert(m > 0 && n > 0);
  
  matrix_.resize(m, n);
  visited_.resize(m, n);
  
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      short s;
      is >> s;
      
      // si el dato es un START_ID -> entrada al laberinto
      if (s == START_ID)
      {
        i_start_ = i;
        j_start_ = j;
      }
      // si el dato es un END_ID -> salida al laberinto
      else if (s == END_ID)
      {
        i_end_ = i;
        j_end_   = j;
      }
      
      matrix_(i, j) = s;
    }
  }

  // comprobamos que se han leído correctamente la entrada y la salida  
  assert (i_start_ != -1 && j_start_ != -1 && i_end_ != -1 && j_end_ != -1);

  return is;
}



// muestra el laberinto por pantalla
ostream&
maze_t::write(ostream& os) const
{
  os << matrix_.get_m() << "x" << matrix_.get_n() << endl;
  for (int i = 1; i <= matrix_.get_m(); i++)
  {
    for (int j = 1; j <= matrix_.get_n(); j++)
      switch (matrix_(i, j))
      { 
        case START_ID: os << START_CHR; break;
        case END_ID:   os << END_CHR;   break;
        case WALL_ID:  os << WALL_CHR;  break;
        case PASS_ID:  os << PASS_CHR;  break;
        case PATH_ID:  os << PATH_CHR;  break;
      }
    os << endl;
  }
  
  return os; 
}

  // [poner código aquí]
  if(matrix_(i, j)== END_ID)
    return true;
  // marcamos la celda como visitada
  visited_(i, j) = true;
///FaseIII
ostream&
maze_t::write_path(ostream& os) 
{
  maze_pos_t dummy;
  while(!pila.empty()){
    
    dummy = pila.top();
    pila.pop();
    
    cout<<" --> ["<< dummy.i<<","<< dummy.j<<"]";
    //os << endl;
  }
  cout<<endl;
  
  return os; 
}

// FASE I
// comprueba que la fila i y columna j son válidas antes de pasar a ellas
bool
maze_t::is_ok_(const int i, const int j) const
{ 
  // retornar true si se cumplen TODAS estas condiciones:
  // - fila i y la columna j están dentro de los límites del laberinto,
  // - la celda en (i, j) no puede ser un muro,
  // - la celda (i, j) no puede haber sido visitada antes.
  if(i>0 && (i<=  matrix_.get_m() && j<= matrix_.get_n())&& j >0){
    if ((matrix_(i,j) != WALL_ID)   &&   !visited_(i,j)){
      return true;
    }
  }
  return false;
}



// FASE II
// método recursivo que resuelve el laberinto

bool
maze_t::solve_(const int i, const int j)
{
  // CASO BASE:
  // retornar 'true' si 'i' y 'j' han llegado a la salida
  //Fase III
  maze_pos_t dummy;
  // [poner código aquí]
  if(matrix_(i, j)== END_ID)
    return true;
  // marcamos la celda como visitada
  visited_(i, j) = true;
  
  // CASO GENERAL:
  // para cada una de las 4 posibles direcciones (N, E, S, W) ver si es posible
  // el desplazamiento (is_ok_) y, en ese caso, intentar resolver el laberinto
  // llamando recursivamente a 'solve'. 
  // Si la llamada devuelve 'true', poner en la celda el valor PATH_ID, y
  // propagarla retornando también 'true'

  // [poner código aquí]
  contador++;
  for(int k = 0; k< 4; k++){
    if (is_ok_( i + i_d[k],j +j_d[k])){
      if(solve_( i + i_d[k],j +j_d[k])){
        matrix_(i, j) = PATH_ID;
        dummy.i = i;
        dummy.j = j;
        //Metemos en la pila el i y j, que almacena las posiciones por las que avanza el camino desde el
        // el final al principio del laberinto
        pila.push(dummy);
      
        return true;
      }
      
    }
    
  }
  
  // desmarcamos la celda como visitada (denominado "backtracking") y
  // retornamos 'false'
  visited_(i, j) = false;
  return false;
}



// operador de entrada sobrecargado
istream&
operator>>(istream& is, maze_t& M)
{
  return M.read(is);
}



// operador de salida sobrecargado
ostream&
operator<<(ostream& os, const maze_t& M)
{
  return M.write(os);
}