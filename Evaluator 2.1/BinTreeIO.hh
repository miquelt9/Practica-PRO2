#ifndef BINIOPROB_HPP
#define BINIOPROB_HPP

#include "BinTree.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif

void leer_bintree_problema(BinTree<string>& a);
// Pre: a es vacio; el canal estándar de entrada contiene una secuencia
// de strings (problemas) que representa un arbol binario de problemas
// en preordren, donde un "0" indicará el final de una rama
// Post: a contiene el árbol que había en el canal estándar de entrada

void escribir_bintree_problema(const BinTree<string>& a);
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorreguts en posorden, a = A

#endif
