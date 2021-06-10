/** @file Sesion.hh
    @brief Especificación de la classe Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Problema.hh"
#include "BinTreeIO.hh"
#ifndef NO_DIAGRAM
#include <list>
#endif

/** @class Sesion
    @brief Representa una sesion de problemas del <em>Evaluator</em>
*/
class Sesion
{
public:
  //Constructoras

  /** @brief Creadora por defecte

      Se ejecuta automáticamente al declarar una sesion
      \pre Cierto
      \post El resultado és una sesion
  */
  Sesion();

  /** @brief Creadora copiadora

      Permite declarar una nueva sesion como copia de otra ya existente
      \pre Cierto
      \post El resultado és una nueva sesion igual a s
  */
  Sesion(const Sesion& s);

  /** @brief Creadora con nombre

      Permite declarar una nueva sesion con nombre
      \pre Cierto
      \post El resultado és una nueva sesion con nombre n
  */
  Sesion(const string& n);

  //Consultoras

  /** @brief Consultora id

      \pre Cierto
      \post Devuelve el id del Problema
  */
  string consultar_id() const;

  /** @brief Existe problema

      \pre Cierto
      \post Devuelve <em>true</em> si la sesion contiene el problema p
  */
  bool existe_problema(const string& p) const;

  /** @brief Consultar hijos

      \pre  El problema está contenido en el parámetro implícito
      \post Añade los hijos del problema p a la lista ls
  */
  void consultar_hijos(const string& p, list<string>& ls) const;

  /** @brief Numero problemas

      \pre  Cierto
      \post Devuelve el numero de problemas que tiene el parámetro
            implícito
  */
  int numero_problemas() const;

  /** @brief Consultar prerequisitos
      \pre  Cierto
      \post Devuelve el arbol de prerequisitos del parámetro implícito
  */
  BinTree<string> consultar_prerequisitos() const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un string y una seqüència de problemas en preorden
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre  La Sesioni existe
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
            con el formato: nº de problemas de la sesion, identificador y prerequisitos
            en postorden
  */
  void escribir() const;

private:
  BinTree<string> arbol_problemas;
  int n_problemas;
  string id;
};

#endif
