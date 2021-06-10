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
            borrarlo. Además, se borra todo el progreso de u.
  */
  void baja_usuario(const string& u);

  /** @brief Consultar usuario

      \pre  El usuario u existe
      \post Devuelve el Usuario con id u
  */
  Usuario acceder_usuario(const string& u);

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

private:
  map<string,Usuario> usuarios;
};

#endif
