
  void leer_cursos();


  int contar_elementos_bintree(const BinTree<Problema>& a); //Unificar amb leer?

  bool buscar_problema(const BinTree<Problema>& a, const Problema& p);
  // Pre: a = A; s contiene el id_problema del que queremos buscar
  // Post: Se recorre a buscando s, solo se devuelve true si se
  // encuentra i es enviable

// On fiquem el sesion_problema c p , a cjt sesiones o sesion (+ aviat aquest últim)

// On    "      problemas resueltos? A cjt_usuario


--------------------------------------

/** @brief Incrementadora de envios realizados

    \pre Cierto
    \post Los envios realizados del problema han aumentado en 1
*/
void aumentar_envios_realizados();

/** @brief Incrementadora de envios correctos

    \pre Cierto
    \post Los envios correctos del problema han aumentado en 1
*/
void aumentar_envios_correctos();

//Consultoras

/** @brief Consultora de envios realizados

    \pre Cierto
    \post Devuelve el nº de envios realizados del parámetro implicito
*/
int envios_realizados() const;

/** @brief Consultora de envios correctors

    \pre Cierto
    \post Devuelve el nº de envios correctors del parámetro implicito
*/
int envios_correctos() const;
