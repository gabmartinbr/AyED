/*
 AUTOR: Gabriel Martín Broock
 FECHA: 02-03-2023
 EMAIL: alu0101539157
 VERSION: 1.0
 ASIGNATURA: Algoritmos y Estructuras de Datos
 PRÁCTICA Nº: 2
 COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
*/

// comentarios multilinea usando /* */

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// macros, si se usan, definir en matusculas y _ en vez de espacios
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // primero "public" y después "private"
public:
  rational_t(const int = 0, const int = 1); // constructor por defecto y constructor
  ~rational_t() {} // destructor por
  
  // indentación a 2 espacios
  
  // getters
  int get_num() const; // metodo para obtener el numerador
  int get_den() const; // metodo para obtener el denominador
  
  // setters
  void set_num(const int); // metodo para definir el numerador
  void set_den(const int); // metodo para definir el denominador

  double value(void) const; // metodo para obtener el resultado del racional
  rational_t opposite(void) const; // metodo para obtener el racional con signo contrario
  rational_t reciprocal(void) const; // metodo para obtener el racional invertido

  // metodos comprobar si es mayor, igual o menor entre dos racionales
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  // metodos de operaciones básicas entre racionales
  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;

  // metodos de entrada y salida
  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private:
  // nombre de los atributos privados seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

