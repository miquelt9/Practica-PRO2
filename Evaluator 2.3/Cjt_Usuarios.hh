/** @file Cjt_Usuarios.hh
    @brief Especificación de la classe Cjt_Usuarios
*/

#ifndef _CJT_USUARIOS_HH_
#define _CJT_USUARIOS_HH_

#include "Usuario.hh"
#ifndef NO_DIAGRAM
#endif

/** @class Cjt_Usuarios
    @brief Representa un conjunto de usuarios de la plataforma
*/
class Cjt_Usuarios
{
public:
  //Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de usuarios
      \pre Cierto
      \post El resultado és un conjunto de usuarios
  */
  Cjt_Usuarios();

  /** @brief Creadora copiadora

      Permite declarar un nuevo conjunto de usuarios como copia
      de otro ya existente
      \pre Cierto
      \post El resultado és un conjunto de usuarios igual a cjt
  */
  Cjt_Usuarios(const Cjt_Usuarios& cjt);

  //Modificadoras

  /** @brief Alta usuario

      \pre  El usuario con id u no existe
      \post Se imprime el nº de usuarios registrados despues de
            añadirlo
  */
  void alta_usuario(const string& u);

  /** @brief Alta usuario

      \pre  El usuario con u no existe
      \post Se imprime el nº de usuarios registrados despues de
            añadirlo
  */
  void alta_usuario(const Usuario& u);

  /** @brief Alta usuario

      \pre  El usuario con id u existe
      \post Se imprime el nº de usuarios registrados despues de
            borrarlo. Además, se borra todo el progreso de u
  */
  void baja_usuario(const string& u, Cjt_Cursos& cursos);

  /** @brief Inscribir usuario a curso

      \pre  El curso c existe, el usuario u existe y no está inscrito a ningún curso
      \post El usuario u está inscrito al curso c, se añaden problemas enviables
            al usuario segun haya resuelto o no los problemas iniciales
  */
  void inscribir_curso(int c, const string& u,
   Cjt_Cursos& cursos, const Cjt_Sesiones& sesiones);

  /** @brief Envio

      \pre  Cierto
      \post Se actualizan las estadísticas del usuario u i del prolema enviado,
            además el usuario o termina el curso o se añaden nuevos problemas
            enviables
  */
  void envio(const string& u, const string& p, int r, Cjt_Problemas& problemas,
  const Cjt_Sesiones& ses, Cjt_Cursos& cursos);

  //Consultoras

  /** @brief Existe usuario

      \pre  Cierto
      \post Devuelve <em>true</em> si el usuario existe sino devuelve <em>false</em>
  */
  bool existe_usuario(const string& u) const;

  /** @brief Numero usuarios

      \pre  Cierto
      \post Devuelve el numero de usuarios del conjunto
  */
  int numero_usuarios() const;

  /** @brief En un curso

      \pre  El usuario u existe
      \post Devuelve <em>true</em> si está inscrito en algun curso, o <em>false</em> si no
  */
  bool en_un_curso(const string& u) const;

  /** @brief Curso usuario

      \pre  El usuario u existe
      \post Devuelve el curso en que está inscrito u
  */
  int curso_usuario(const string& u) const;

  /** @brief Problemas resueltos

      \pre  El usuario u existe
      \post Se listan en orden los problemas solucionados por el usuario u
            seguido de el nº de envios realizados a cada uno de los problemas
            listados que ha realizado el usuario
  */
  void problemas_resueltos(const string& u) const;

  /** @brief Curso usuario

      \pre  El usuario u existe
      \post Se listan en orden los problemas que el usuario u puede enviar
            seguido del numero de envios que ha hecho el usuario a cada
            uno de los problemas listados
  */
  void problemas_enviables(const string& u) const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un nº n seguido de n usuarios
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre Cierto
      \post Escribe el contenido del parámetro implícito por el canal estándar
            de salida ordenados crecientemente por el nombre de usuario
  */
  void escribir() const;

  /** @brief Operación de escritura de usuario

      \pre  El usuario u existe
      \post Escribe el usuario u por el canal estándar de salida con el formato:
            identificador, nº envios realizados, nº envios correctos, nº problemas
            intentados y el identificador del curso en que esta inscrito
  */
  void escribir(const string& u) const;


private:
  /**@brief Mapa de usuarios con acceso pot id*/
  map<string,Usuario> usuarios;
};

#endif
