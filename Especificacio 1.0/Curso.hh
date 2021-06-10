/** @file Curso.hh
    @brief Especificación de la classe Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Sesion.hh"
#ifndef NO_DIAGRAM
#endif

/** @class Curso
    @brief Representa un curso de l'<em>Evaluator</em>
*/
class Curso
{
public:
  //Constructoras

  /** @brief Creadora per defecte

      Se ejecuta automáticamente
      \pre Cierto
      \post El resultado és un curso sin id ni sessions
  */
  Curso();

  /** @brief Creadora copiadora

      Permite declarar un nuevo curso como copia de otro ya existente
      \pre Cierto
      \post El resultado és un curso igual a c
  */
  Curso(const Curso& c);

  /** @brief Creadora con nombre

      Permite declarar un nuevo problema con nombre
      \pre Cierto
      \post El resultado és un problema con nombre n
  */
  Curso(const string& n);

  //Consultoras

  /** @brief Consultora id

      \pre Cierto
      \post Devuelve el id del Curso
  */
  string consultar_id() const;

  /** @brief Numero inscritos

      \pre  Cierto
      \post Devuelve el nº de inscritos de ese curso
  */
  int numero_inscritos() const;

  /** @brief Problemas repetidos

      \pre  Cierto
      \post Devuelve <em>true</em> si hay problemas repetidos en las sesiones
            que se dan en el vector de entrada, sino devuelve <em>false</em>
  */
  bool problemas_repetidos(const vector<string>& v) const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay int m (nº de sesiones del curso)
           seguido de una sequencia de strings que hacen referencia al nombre
           de las sesiones
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre  El curso existe
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida,
      con el formato: identificador
  */
  void escribir() const;

private:

};

#endif
