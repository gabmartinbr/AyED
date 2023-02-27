 /*
 AUTOR: Gabriel Martín Broock
 FECHA: 18/02/2023
 EMAIL: alu0101539157@ull.edu.es
 VERSION: 1.0
 ASIGNATURA: Algoritmos y Estructuras de Datos
 PRÁCTICA Nº: 1
 COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
*/

// comentarios multilínea usando "/* */"
#include <iostream>
#include <cmath>

// ficheros de cabecera agrupados y separados por tipo
#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 3), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(4, 3), y(1, 3);
   x.write();
   y.write();
   cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
   cout << "x < y? " << (x.is_less(y) ? "true" : "false") << endl;
   cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << endl;

  // FASE III
   cout << "a + b: ";
   a.add(b).write();
  
   cout << "b - a: ";
   b.substract(a).write();

   cout << "a * b: ";
   a.multiply(b).write();
  
   cout << "a / b: ";
   a.divide(b).write();

   // MODIFICACION
    cout << "x < 1? " << (x.is_less_one() ? "true" : "false") << endl;
    cout << "x > 1? " << (x.is_greater_one() ? "true" : "false") << endl;
    cout << "x = 1? " << (x.is_equal_one() ? "true" : "false")<< endl;

  return 0;
}
