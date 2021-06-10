/** @file Curso.hh
    @brief Especificación de la classe Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Cjt_Sesiones.hh"
#ifndef NO_DIAGRAM
#include <list>
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

  //Modificadoras

  /** brief Aumentar usuarios registrados

      \pre  Cierto
      \post Los usuarios registrados del parámetro implícito son aumentados en 1
  */
  void aumentar_registrados();

  /** brief Aumentar usuarios registrados

      \pre  Cierto
      \post Los usuarios completados del parámetro implícito son aumentados en 1
  */
  void aumentar_completados(const string& u);

  /** brief Aumentar usuarios registrados

      \pre  Cierto
      \post Los usuarios registrados del parámetro implícito son reducidos en 1
  */
  void reducir_registrados();

  //Consultoras

  /** @brief Consultora id

      \pre Cierto
      \post Devuelve el id del Curso
  */
  int consultar_id() const;

  /** @brief Numero inscritos

      \pre  Cierto
      \post Devuelve el nº de inscritos de ese curso
  */
  int numero_inscritos() const;

  /** @brief Problemas repetidos

      \pre  Cierto
      \post Devuelve <em>true</em> si hay problemas repetidos en las sesiones
            que se dan en el lista de entrada, sino devuelve <em>false</em>
  */
  bool problemas_repetidos(const Cjt_Sesiones& ses) const;

  /** @brief Consultar sesiones

      \pre  c existe
      \post Se devuelve un lista de strings con los nombres de las sesiones
            que forman el curso c
  */
  void sesiones_curso(list<string>& ls) const;

  /** @brief Sesion problema

      \pre  Cierto
      \post Se devuelve la sesion del curso (parámetro implícito) al que
            pertenece el problema p
  */
  string sesion_problema(const string& problema) const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay int m (nº de sesiones del curso)
           seguido de una sequencia de strings que hacen referencia al nombre
           de las sesiones
      \post El contenido de la entrada es guardado en el parámetro implícito, id = idi
  */
  void leer(int id, const Cjt_Sesiones& ses);

  //Escriptura

  /** @brief Operación de escritura

      \pre  El curso existe
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida,
            con el formato: identificador, nº de usuarios que lo han completado,
            nº inscritos actualmente, nº de sesiones que lo forman y sus identificadores
            respectivos
  */
  void escribir() const;

private:
  int id;
  list<string> sesiones_del_curso;
  map<string,string> corresponedencia;
  int usuarios_registrados;
  set<string> usuarios_completado;
};

#endif
