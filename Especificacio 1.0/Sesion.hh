/** @file Sesion.hh
    @brief Especificación de la classe Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Problema.hh"
#ifndef NO_DIAGRAM
#include "BinTreeIO.hh"
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

  /** @brief Buscadora problema en sesiones

      \pre Cierto
      \post Devuelve <em>true</em> si la sesion contiene el problema p
  */
  bool buscar_problema(const string& p) const;

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
            en posorden
  */
  void escribir() const;

private:

};

#endif
