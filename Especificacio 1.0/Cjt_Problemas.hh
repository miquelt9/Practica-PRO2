/** @file Cjt_Problemas.hh
    @brief Especificación de la classe Cjt_Problemas
*/

#ifndef _CJT_PROBLEMAS_HH_
#define _CJT_PROBLEMAS_HH_

#include "Problema.hh"
#ifndef NO_DIAGRAM
#endif

/** @class Cjt_Problemas
    @brief Representa un conjunto de problemas de la plataforma
*/
class Cjt_Problemas
{
public:
  //Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de problemas
      \pre Cierto
      \post El resultado és un conjunto de problemas
  */
  Cjt_Problemas();

  /** @brief Creadora copiadora

      Permite declarar un nuevo conjunto de problemas como copia
      de otro ya existente
      \pre Cierto
      \post El resultado és un conjunto de problemas igual a cjt
  */
  Cjt_Problemas(const Cjt_Problemas& cjt);

  //Modificadoras

  /** @brief Agregadora de problema

      \pre  p no existe
      \post Al parámetro implícito se le ha añadido el problema p
  */
  void agregar_problema(const Problema& p);

  //Consultoras

  /** @brief Existe problema

      \pre  Cierto
      \post Devuelve <em>true</em> si el problema existe sino devuelve <em>false</em>
  */
  bool existe_problema(const string& u) const;

  /** @brief Consultar problema

      \pre  El problema u existe
      \post Devuelve el Usuario con id u
  */
  Problema consultar_problema(const string& u) const;

  /** @brief Numero problemas

      \pre  Cierto
      \post Devuelve el numero total de problemas
  */
  int numero_problemas() const;

  //Escriptura

  /** @brief Operación de escritura

      \pre Cierto
      \post Escribe el conenido del parámetro implícito por el canal estándar
            de salida ordenadors por el ratio (t+1)/(e+1) y el identificador
  */
  void escribir() const;

private:

};

#endif
