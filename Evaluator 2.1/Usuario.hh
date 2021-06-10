/** @file Usuario.hh
    @brief Especificación de la classe Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "Cjt_Problemas.hh"
#include "Cjt_Cursos.hh"
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

  /** @brief Terminar curso

      \pre  El usuario está en un curso
      \post El usuario ya no está en un curso
  */
  void terminar_curso();

  /** @brief Envio

      \pre  Cierto
      \post Se actualizan las estadísticas del usuario i del problema
  */
  void envio(const string& p, const int& r, Cjt_Problemas& problemas, const Cjt_Sesiones& ses,
  Cjt_Cursos& cursos);

  /** @brief Agregar enviables

      \pre  Cierto
      \post El parámetro implícito puede enviar los problemas de s
  */
  void agregar_enviables(list<string>& ls, const Cjt_Sesiones& sesiones, const list<string>& sesiones_curso);

  //Consultoras

  /** @brief Consultora id

      \pre Cierto
      \post Devuelve el id del Usuario
  */
  string consultar_id() const;

  /** @brief Indica el curso al que el usuario está inscrito

      \pre  Cierto
      \post Si el usuario está inscrito a un curso devuelve el nº del curso
            sino devuelve 0
  */
  int curso_usuario() const;

  /** @brief Problemas resueltos

      \pre  El usuario u existe
      \post Se listan en orden los problemas solucionados por el usuario al que
            hace referencia el parámetro implícito seguido de el nº de envios
            realizados a cada uno de los problemas listados que ha realizado el usuario
  */
  void problemas_resueltos() const;

  /** @brief Problemas enviables

      \pre  El usuario u existe
      \post Se listan en orden los problemas que el parámetro implicito puede
            enviar seguido del numero de envios que ha hecho el usuario a cada
            uno de los problemas listados
  */
  void problemas_enviables() const;

  /** @brief Curso terminado

      \pre  El usuario está en un curso
      \post Devuelve <em>true</em> si el usuario ha terminado el curso en que
            estaba, en caso contrario devuelve <em>false</em>
  */
  bool curso_terminado() const;

  /** @brief Envios totales

      \pre  Cierto
      \post Devuelve el numero de envios que ha realizado el parámetro implícito
  */
  int envios_totales() const;

  /** @brief Problemas intentados

      \pre  Cierto
      \post Devuelve el numero de problemas que el parámetro implícito ha
            intentado resolver
  */
  int problemas_intentados() const;

  /** @brief Sesiones completadas

      \pre  Cierto
      \post El parámetro ses contiene las sesiones completadas por el parámetro
            implicito
  */
  void sesiones_completadas(vector<string>& sesiones);

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un string
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre  El usuario existe
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida
            con el formato: identificador, nº envios realizados, nº envios correctos,
            nº problemas intentados y el identificador del curso en que esta inscrito
  */
  void escribir() const;

private:
  string id;
  int curso;
  map<string,int> enviables;
  map<string,int> resueltos;
  vector<string> ses_completadas;
};

#endif
