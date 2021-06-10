/** @file Cjt_Sesiones.hh
    @brief Especificación de la classe Cjt_Sesiones
*/

#ifndef _CJT_SESIONES_HH_
#define _CJT_SESIONES_HH_

#include "Sesion.hh"
#ifndef NO_DIAGRAM
#endif
using namespace std;

/** @class Cjt_Sesiones
    @brief Representa un conjunto de sesiones de la plataforma
*/
class Cjt_Sesiones
{
public:
  //Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de sesiones
      \pre Cierto
      \post El resultado és un conjunto de sesiones
  */
  Cjt_Sesiones();

  /** @brief Creadora copiadora

      Permite declarar un nuevo conjunto de sesiones como copia
      de otro ya existente
      \pre Cierto
      \post El resultado és un conjunto de sesiones igual a cjt
  */
  Cjt_Sesiones(const Cjt_Sesiones& cjt);

  //Modificadoras

  /** @brief Agregadora de sesion

      \pre  s no existe
      \post Al parámetro implícito se le ha añadido el sesion s
  */
  void agregar_sesion(const Sesion& s);

  //Consultoras

  /** @brief Existe sesion

      \pre  Cierto
      \post Devuelve <em>true</em> si la sesion existe sino devuelve <em>false</em>
  */
  bool existe_sesion(const string& s);

  /** @brief Consultar sesion

      \pre  la sesion u existe
      \post Devuelve la Sesion con id u
  */
  Sesion consultar_sesion(const string& s) const;

  /** @brief Numero sesiones

      \pre  Cierto
      \post Devuelve el numero total de sesiones
  */
  int numero_sesiones() const;

  /** @brief Sesion del problema

      \pre  Cierto
      \post Devuelve el identificador de sesion al que pertenece el problema,
            si el problema no existiera en ninguna de las sesiones se devuelve
            un "-1"
  */
  string sesion_problema(const list<string> v, const string& problema) const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un nº n seguido de n sesiones
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

};

#endif
