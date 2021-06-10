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

  /** @brief Incrementadora de envios realizados

      \pre  El problema p existe
      \post Los envios realizados del problema p han aumentado en 1
  */
  void aumentar_envios_totales(const string& p);

  /** @brief Incrementadora de envios correctos

      \pre  El problema p existe
      \post Los envios correctos del problema p han aumentado en 1
  */
  void aumentar_envios_correctos(const string& p);

  //Consultoras

  /** @brief Existe problema

      \pre  Cierto
      \post Devuelve <em>true</em> si el problema existe sino devuelve <em>false</em>
  */
  bool existe_problema(const string& p) const;

  /** @brief Numero problemas

      \pre  Cierto
      \post Devuelve el numero total de problemas
  */
  int numero_problemas() const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un nº n seguido de n problemas
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre  Cierto
      \post Escribe el contenido del parámetro implícito por el canal estándar
            de salida ordenadors por el ratio (t+1)/(e+1) y el identificador
  */
  void escribir() const;

  /** @brief Operación de escritura de un problema

      \pre  El problema p existe
      \post Escribe el problema p por el canal estándarde salida con el formato:
            identificador, nº de envios totales a ese problema, el nº de envios
            correctos y el ratio (t+1)/(e+1)
  */
  void escribir(const string& p) const;

private:
  map<string,Problema> problemas;
};

#endif
