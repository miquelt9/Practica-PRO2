/** @file Usuario.hh
    @brief Especificación de la classe Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "Problema.hh"
#ifndef NO_DIAGRAM
#endif

/** @class Usuario
    @brief Representa un usuario de la plataforma
*/
class Usuario
{
public:
  //Constructoras

  /** @brief Creadora por defecte

      Se ejecuta automáticamente al declarar un usuario
      \pre Cierto
      \post El resultado és un usuario sin id i todos los parámetros inicializados a 0 o vacios
  */
  Usuario();

  /** @brief Creadora copiadora

      Permite declarar un nuevo usuario como copia de otro ya existente
      \pre Cierto
      \post El resultado és un usuario igual a u
  */
  Usuario(const Usuario& u);

  /** @brief Creadora con nombre

      Permite declarar un nuevo usuario con nombre
      \pre Cierto
      \post El resultado és un usuario con nombre n
  */
  Usuario(const string& n);

  // Modificadoras

  /** @brief Inscripción de un usuario en un curso

      \pre El usuario está registrado en la plataforma i no está inscrito a ningun curso
      \post El usuario está inscrito al curso n
  */
  void inscribir_curso(const int& n);

  //Consultoras

  /** @brief En un curso

      \pre Cierto
      \post Retorna <em>true</em> si está inscrito en algun curso, o <em>false</em> si no
  */
  bool en_un_curso() const;

  /** brief Curso completado

      \pre  Cierto
      \post Devuelve <em>true</em> si el parámetro implícito ha completado el
            curso, sino devuelve <em>false</em>
  */
  bool curso_completado() const;

  /** @brief Indica el curso al que el usuario está inscrito

      \pre  Cierto
      \post Si el usuario está inscrito a un curso devuelve el nº del curso
            sino devuelve 0
  */
  int curso_usuario() const;

  /** @brief Problemas resueltos

      \pre Cierto
      \post Se listan en orden los problemas solucionados por el usuario al que
            hace referencia el parámetro implícito seguido de el nº de envios
            realizados a cada uno de los problemas listados
  */
  void problemas_resueltos() const;

  /** @brief Problemas resueltos

      \pre Cierto
      \post Se listan en orden los problemas solucionados por el usuario al que
            hace referencia el parámetro implícito seguido de el nº de envios
            realizados a cada uno de los problemas listados
  */
  void problemas_resueltos() const;

  //Escriptura

  /** @brief Operación de escritura

      \pre  El usuario existe
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
            con el formato: identificador, nº envios realizados, nº envios correctos,
            nº problemas intentados y el identificador del curso en que esta inscrito
  */
  void escribir() const;

private:

};

#endif
