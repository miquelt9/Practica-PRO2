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

  /** brief Aumentar usuarios registrados

      \pre  El curso c existes
      \post Los usuarios registrados del curso c son aumentados en 1
  */
  void alta_registrados(const int& c);

  /** brief Aumentar usuarios registrados

      \pre  El curso c existes
      \post Los usuarios completados del curso c son aumentados en 1
  */
  void alta_completados(const int& c);

  /** brief Aumentar usuarios registrados

      \pre  El curso c existes
      \post Los usuarios registrados del curso c son reducidos en 1
  */
  void baja_registrados(const int& c);

  /** brief Aumentar usuarios registrados

      \pre  El curso c existes
      \post Los usuarios completados del curso c son reducidos en 1
  */
  void baja_completados(const int& c);

  //Consultoras

  /** @brief Existe curso

      \pre  Cierto
      \post Devuelve <em>true</em> si el curso existe sino devuelve <em>false</em>

  */
  bool existe_curso(const int& c);

  /** @brief Numero de cursos

      \pre  Cierto
      \post Devuelve el nº de cursos que forman el parámetro implícito
  */
  int numero_cursos() const;

  /** @brief Consultar sesiones

      \pre  El curso c existe
      \post Se devuelve un lista de strings con los nombres de las sesiones
            que forman el curso c
  */
  list<string> sesiones_curso(const int& c) const;

  /** @brief Primeros problemas

      \pre  El curso c existe
      \post Se devuelve una lista de los primeros problemas de cada una de las
            sesiones que forma el curso c
  */
  list<string> primeros_problemas(const int& c, const Cjt_Sesiones& sesiones) const;

  /** @brief Numero usuarios

      \pre  El curso c existe
      \post Devuelve el nuemro de usuarios del curso c
  */
  int numero_usuarios(const int& c) const;

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

  /** @brief Operación de escritura de curso

      \pre  El curso c existe
      \post Escribe el curso c por el canal estándar de salida, con el formato:
            identificador, nº de usuarios que lo han completado, nº inscritos
            actualmente, nº de sesiones que lo forman y sus identificadores
            respectivos
  */
  void escribir(const int& c) const;

private:
  vector<Curso> cursos;
};

#endif
