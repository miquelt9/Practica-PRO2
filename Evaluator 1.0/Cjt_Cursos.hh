/** @file Cjt_Cursos.hh
    @brief Especificación de la classe Cjt_Cursos
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#include "Curso.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Cjt_Cursos
    @brief Representa un conjunto de cursos de la plataforma
*/
class Cjt_Cursos
{
public:
  //Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de cursos
      \pre Cierto
      \post El resultado és un conjunto de cursos
  */
  Cjt_Cursos();

  /** @brief Creadora copiadora

      Permite declarar un nuevo conjunto de cursos como copia
      de otro ya existente
      \pre Cierto
      \post El resultado és un conjunto de cursos igual a cjt
  */
  Cjt_Cursos(const Cjt_Cursos& cjt);

  //Modificadoras

  /** @brief Agregadora de curso

      \pre  c no existe
      \post Al parámetro implícito se le ha añadido el curso c
  */
  void agregar_curso(const Curso& c);

  //Consultoras

  /** @brief Existe curso

      \pre  Cierto
      \post Devuelve <em>true</em> si el curso existe sino devuelve <em>false</em>

  */
  bool existe_curso(const int& c);

  /** @brief Consultar curso

      \pre  El curso c existe
      \post Devuelve el Curso con id c
  */
  Curso consultar_curso(const int& c) const;

  /** @brief Numero de cursos

      \pre  Cierto
      \post Devuelve el nº de cursos que forman el parámetro implícito
  */
  int numero_cursos() const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un nº n seguido de n crusos
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre  Cierto
      \post Escribe el contenido del parámetro implícito por el canal estándar
            de salida ordenados crecientemente por el identificador
  */
  void escribir() const;

private:
  vector<Curso> cursos;
};

#endif
