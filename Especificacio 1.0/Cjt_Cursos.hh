/** @file Cjt_Cursos.hh
    @brief Especificación de la classe Cjt_Cursos
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#include "Curso.hh"
#ifndef NO_DIAGRAM
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
  void existe_curso(const int& c);

  /** @brief Consultar sesiones

      \pre  Cierto
      \post Se devuelve un vector de strings con los nombres de las sesiones
            que forman el curso c
  */
  vector<string> sesiones_curso(const int& c) const;
  
  /** @brief Consultar curso

      \pre  El curso c existe
      \post Devuelve el Curso con id c
  */
  Curso consultar_curso(const int& c);

private:

};

#endif
