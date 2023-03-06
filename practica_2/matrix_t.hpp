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

#include "vector_t.hpp"

using namespace std;

template<class T>class matrix_t {
public:
  matrix_t(const int = 0, const int = 0); // constructor y constructor por defecto
  ~matrix_t(); // destructor
  
  void resize(const int, const int); // metodo para redimensionar una matriz
  
  // getters
  int get_m(void) const; // metodo para obtener fila indexada
  int get_n(void) const; // metodo para obtener columna indexada
  
  // getters-setters
  T& at(const int, const int); // metodo para cambiar el valor de posición indexada (m,n)
  T& operator()(const int, const int); // sobrecarga del operador ()
  
  // getters constantes
  const T& at(const int, const int) const; // metodo para obtener posición indexada (m,n)
  const T& operator()(const int, const int) const; // sobrecarga del operador ()
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&); // metodo para multiplicar matrices

  void write(ostream& = cout) const; // metodo de entrada por teclado
  void read(istream& = cin); // metodo de salida por consola

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const; // atributo de la posición indexada de un elemento de matriz
};


// constructor de matrices
template<class T> matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


// destructor de matrices
template<class T> matrix_t<T>::~matrix_t() {}


// constructor de matriz redimensionada
template<class T> void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


// metodo para obtener numero de filas
template<class T> inline int matrix_t<T>::get_m() const {
  return m_;
}


// metodo para obtener numero de columnas
template<class T> inline int matrix_t<T>::get_n() const {
  return n_;
}


// metodo para introducir contenido en una posicion m,n de una matriz
// at(3,2) = 4
template<class T> T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


// sobrecarga de operador () para asignar un valor en la posicion (m,n) 
template<class T> T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}


// metodo que devuelve la posicion m,n de una matriz y no se puede modificar
template<class T> const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


// sobrecarga del operador () constante
template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}


// metodo de escritura por pantalla de una matriz por filas y columas
template<class T> void matrix_t<T>::write(ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}


// metodo de entrada de datos por consola introduciendo numero de filas y columnas
template<class T> void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


// metodo para obtener el indice en el vector de los elementos de una matriz
template<class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_n() == B.get_m()); // si m =  n se pueden multiplicar
  resize (A.get_m(), B.get_n());// inicializamos matriz resultado de dimensiones Am, Bn
  // calculo de multiplicacion
  for(int i = 1; i <= A.get_m(); i++) {
    for(int j = 1; j <= B.get_n(); j++) {
      T suma = 0; // inicializamos la suma de la multiplicacion a 0
      for(int k = 1; k <= A.get_n(); k++) {
        suma = suma + A(i, k) * B(k, j); // formula de multiplicacion matrices
      }
      at(i, j) = suma;
    }
  }
}
