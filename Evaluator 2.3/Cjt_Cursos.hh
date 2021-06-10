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

  /** @brief Aumentar usuarios registrados

      \pre  El curso c existes
      \post Los usuarios registrados del curso c son aumentados en 1
  */
  void aumentar_registrados(int c);

  /** @brief Aumentar usuarios completados

      \pre  El curso c existes
      \post Se añade a los usuarios que han completado el curso el usuario u
  */
  void aumentar_completados(int c, const string& u);

  /** @brief Reducir usuarios registrados

      \pre  Cierto
      \post El usuario u se elimina del set de usuarios registrados de
            todos los cursos
  */
  void reducir_registrados(int c);

  //Consultoras

  /** @brief Existe curso

      \pre  Cierto
      \post Devuelve <em>true</em> si el curso existe sino devuelve <em>false</em>

  */
  bool existe_curso(int c);

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
  void sesiones_curso(int c, list<string>& ls) const;

  /** @brief Numero usuarios

      \pre  El curso c existe
      \post Devuelve el nuemro de usuarios del curso c
  */
  int numero_usuarios(int c) const;

  /** @brief Sesion problema

      \pre  El curso c existe
      \post Se devuelve la sesion del curso a la que pertenece el problema p
  */
  string sesion_problema(int c, const string& problema) const;

  //Lectura

  /** @brief Operación de lectura

      \pre  Por el canal estándar de entrada hay un nº n seguido de n crusos
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer(const Cjt_Sesiones& ses);

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
  void escribir(int c) const;

private:
  /**@brief Vector de cursos*/
  vector<Curso> cursos;
};

#endif
