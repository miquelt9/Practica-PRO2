#include "Sesion.hh"

//Adicional

bool i_existe_problema(const string& p, const BinTree<string>& a)
{
  bool found = false;
  if (a.value() == p) found = true;
  return found or i_existe_problema(p, a.left()) or i_existe_problema(p, a.right());
}

void i_consultar_hijos(const string& p, const BinTree<string>& a, list<string>& ls)
{
  if(a.value() == p)
  {
    if (not a.left().empty()) ls.push_back(a.left().value());
    if (not a.right().empty()) ls.push_back(a.right().value());
  }
  else
  {
    i_consultar_hijos(p, a.left(), ls);
    i_consultar_hijos(p, a.right(), ls);
  }
}

int i_numero_problemas(const BinTree<string>& a)
{
  if (a.empty()) return 0;
  return 1 + i_numero_problemas(a.left()) + i_numero_problemas(a.right());
}

//Constructoras

Sesion::Sesion()
{}

Sesion::Sesion(const Sesion& s)
{
  id = s.id;
  arbol_problemas = s.arbol_problemas;
}

Sesion::Sesion(const string& n)
{
  id = n;
}

//Consultoras

string Sesion::consultar_id() const
{
  return id;
}

bool Sesion::existe_problema(const string& p) const
{
  return i_existe_problema(p, arbol_problemas);
}

void Sesion::consultar_hijos(const string& p, list<string>& ls) const
{
  i_consultar_hijos(p, arbol_problemas, ls);
}

int Sesion::numero_problemas() const
{
  return i_numero_problemas(arbol_problemas);
}

BinTree<string> Sesion::consultar_prerequisitos() const
{
  return arbol_problemas;
}

//Lectura

void Sesion::leer()
{
  cin >> id;
  leer_bintree_problema(arbol_problemas); //podriem augmentar l'eficiencia ajuntanet
  n_problemas = numero_problemas();       //la funct de llegir i la de contar
}

//Escriptura

void Sesion::escribir() const
{
  cout << id << " " << n_problemas << " ";
  escribir_bintree_problema(arbol_problemas);
  cout << endl;
}
