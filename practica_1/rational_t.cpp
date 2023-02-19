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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) // constructor por parametros
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// si se usa separacion entre metodos, solo una linea
// llave de apertura en misma linea que el metodo
// tipo retornado en línea del metodo
int rational_t::get_num() const { // metodo que devuelve el numerador
  return num_;
}

int rational_t::get_den() const { // metodo que devuelve el denominador
  return den_;
}

void rational_t::set_num(const int n) { // metodo que establece el numerador
  num_ = n;
}

void rational_t::set_den(const int d) { // metodo que establece el denominador
  assert(d != 0);
  den_ = d;
}

double rational_t::value() const {  // metodo que devuelve el resultado del num racional
  return double(get_num()) / get_den();
}

// comparaciones
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  if (num_ != r.num_) { //convertir a flotante
    double a = static_cast<double>(num_) / static_cast<double>(den_);
    double b = static_cast<double>(r.num_) / static_cast<double>(r.den_);

    //si la diferencia es menor que la precision es true
    return (std::abs(a - b) <= precision); // std::abs hace el valor absoluto 
  } else {
    return num_ == r.num_;
  }
}

bool rational_t::is_greater(const rational_t& r, const double precision) const {
  if (num_ != r.num_) { //convertir a flotante 
    double a = static_cast<double>(num_) / static_cast<double>(den_);
    double b = static_cast<double>(r.num_) / static_cast<double>(r.den_);

    // si la diferencia es mayor que la precision es true
    return ((a - b) < precision); 
  } else {
    return false;
    }
}

bool rational_t::is_less(const rational_t& r, const double precision) const {
  if (num_ != r.num_) { //convertir a flotante
    double a = static_cast<double>(num_) / static_cast<double>(den_);
    double b = static_cast<double>(r.num_) / static_cast<double>(r.den_);

    // si la diferencia es mayor que precision negativa es true
    return ((b - a) < precision);
  } else {
    return false;
  }
}

// operaciones
rational_t rational_t::add(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = ((a * d) + (b * c));
  int new_den = (b * d);
  rational_t add(new_num, new_den);
  return add;
}

rational_t rational_t::substract(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = (c - a);
  int new_den = (d - b);
  rational_t substract(new_num, new_den);
  return substract;
}

rational_t rational_t::multiply(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = (a * c);
  int new_den = (b * d);
  rational_t multiply(new_num, new_den);
  return multiply;
}

rational_t rational_t::divide(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = (a * d);
  int new_den = (b * c);
  rational_t divide(new_num, new_den);
  return divide;
}

// E/S
void rational_t::write(ostream& os) const {// metodo para imprimir un racional
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is) {// metodo para leer por consola un racional
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
