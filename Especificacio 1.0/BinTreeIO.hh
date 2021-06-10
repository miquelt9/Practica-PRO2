#ifndef BINIOPROB_HPP
#define BINIOPROB_HPP

#include <iostream>
#include "BinTree.hh"
#include "Problema.hh"

void leer_bintree_problema(BinTree<Problema>& a);
// Pre: a es vacio; el canal estándar de entrada contiene una secuencia
// de Problemas que representa un arbol binario de problemas
// en preordren, donde un (quina serà la nostra marca d'arbre buit!!!!)
// Post: a contiene el árbol que había en el canal estándar de entrada

void escribir_bintree_problema(const BinTree<Problema>& a);
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorreguts en posorden, a = A

#endif
