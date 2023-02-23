#include <iostream>
using namespace std;

int main(void)
{ int    a = 5;
  double b = 12.6;
 
  int    *a_ptr = NULL; 
  double *b_ptr = NULL;
 		
  a_ptr = &a; 
  b_ptr = &b; 

  cout << "a= " << a;
  cout << "\t a_ptr= " <<  a_ptr;
  cout << "\t *a_ptr= " << *a_ptr << endl; 
  cout << "b= " << b;
  cout << "\t b_ptr= " <<  b_ptr << endl; 

  return 0;
}
