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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// macros, si se usan, definir en matusculas y _ en vez de espacios
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // orden de proteccion, "public", "protected", "private"
public: // elementos publicos
  rational_t(const int = 0, const int = 1); // constructor con parámetros
  ~rational_t() {} // destructor
  
  // tabulaciones, se usan 2 espacios indentados
  // getters
  int get_num() const; // metodo para obtener numerador
  int get_den() const; // metodo para obtener denominador

  // setters
  void set_num(const int); // metodo para establecer un numerador
  void set_den(const int); // metodo para establecer un denominador

  double value(void) const; // metodo que retorna el valor del racional en doble precision

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const; // metodo para saber si dos racionales son iguales
  bool is_greater(const rational_t&, const double precision = EPSILON) const; // metodo para saber si un racional es mayor que otro
  bool is_less(const rational_t&, const double precision = EPSILON) const; // metodo para saber si un racional es menor que otro
    
    // FASE III
  rational_t add(const rational_t&); // metodo para sumar dos racionales
  rational_t substract(const rational_t&); // metodo para restar dos racionales
  rational_t multiply(const rational_t&); // metodo para multiplicar dos racionales
  rational_t divide(const rational_t&); // metodo para dividir dos racionales

  // MODIFICACION
  // comprobar si un racional es mayor, menor o igual que 1
  bool is_less_one() const;
  bool is_greater_one() const;
  bool is_equal_one() const;

    
  void write(ostream& = cout) const; // metodo de salida de numeros racionales
  void read(istream& = cin); // metodo de entrada de numeros racionales
    
private: // elementos privados
  // nombre de atributos finalizados con "_"
  int num_, den_; //atributos privados del numero racional
};
