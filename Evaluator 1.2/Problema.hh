/** @file Problema.hh
    @brief Especificación de la classe Problema
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#endif
using namespace std;

/** @class Problema
    @brief Representa un problema del <em>Evaluator</em>
*/
class Problema
{
public:
  //Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un problema
      \pre  Cierto
      \post El resultado és un problema con parámetros a 0
  */
  Problema();

  /** @brief Creadora copiadora

      Permite declarar un nuevo probema como copia de otro ya existente
      \pre  Cierto
      \post El resultado és un problema igual a p
  */
  Problema(const Problema& p);

  /** @brief Creadora con nombre

      Permite declarar un nuevo problema con nombre
      \pre  Cierto
      \post El resultado és un problema con nombre n; parámetros a 0
  */
  Problema(const string& n);

  //Modificadoras

  /** @brief Incrementadora de envios realizados

      \pre Cierto
      \post Los envios realizados del problema han aumentado en 1
  */
  void aumentar_envios_totales();

  /** @brief Incrementadora de envios correctos

      \pre Cierto
      \post Los envios correctos del problema han aumentado en 1
  */
  void aumentar_envios_correctos();


  //Consultoras

  /** @brief Consultora id

      \pre Cierto
      \post Devuelve el id del Problema
  */
  string consultar_id() const;

  /** @brief Consultora ratio

      \pre Cierto
      \post Devuelve el ratio (envios realizados+1)/(envios correctos+1) =
      (t+1)/(e+1) del Problema
  */
  double consultar_ratio() const;

  /** @brief Envios realizados

      \pre  Cierto
      \post Devuelve en nº de envios que se han realizado al parámetro implícito
  */
  int consultar_envios_totales() const;

  /** @brief Envios correctos

      \pre  Cierto
      \post Devuelve en nº de envios que se han realizado correctamente
      al parámetro implícito
  */
  int consultar_envios_correctos() const;

  //Lectura

  /** @brief Operación de lectura

      \pre Por el canal estándar de entrada hay un string
      \post El contenido de la entrada es guardado en el parámetro implícito
  */
  void leer();

  //Escriptura

  /** @brief Operación de escritura

      \pre  El Problema existe
      \post Escribe el contenido del parámetro implícito por el canal estándar
            de salida con el formato: identificador, nº de envios totales a ese
            problema, el nº de envios correctos y el ratio (t+1)/(e+1)
  */
  void escribir() const;

private:
  string id;
  int envios_totales;
  int envios_correctos;
  double ratio = (envios_totales+1)/(envios_correctos+1);
};

#endif
