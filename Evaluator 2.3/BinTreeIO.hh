#ifndef BINIOPROB_HPP
#define BINIOPROB_HPP

#include "BinTree.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @brief Leer BinTree

    \pre:  El canal estándar de entrada contiene una secuencia
           de strings (problemas) que representa un arbol binario
           de problemas en preordren, donde un "0" indicará el final
           de una rama
    \post: a contiene el árbol que había en el canal estándar de entrada
*/
void leer_bintree_problema(BinTree<string>& a);

/** @brief Escribir BinTree

    \pre: a = A
    \post: se han escrito al canal estandar de salida los elementos
           de a en recorrido postorden, a = A
*/
void escribir_bintree_problema(const BinTree<string>& a);

#endif
