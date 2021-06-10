#include "Sesion.hh"

//Adicional

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

void insertar_problemas(set<string>& prob, const BinTree<string>& a)
{
  prob.insert(a.value());
  if(not a.left().empty()) insertar_problemas(prob, a.left());
  if(not a.right().empty()) insertar_problemas(prob, a.right());
}

bool i_existe_problema(const string& p, const BinTree<string>& a)
{
  bool found = false;
  if (a.value() == p) found = true;
  bool foundl = false, foundr = false;
  if (not a.left().empty()) foundl = i_existe_problema(p, a.left());
  if (not a.right().empty()) foundr = i_existe_problema(p, a.right());
  return found or foundl or foundr;
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

string Sesion::consultar_primer_problema() const
{
  return arbol_problemas.value();
}

bool Sesion::existe_problema(const string& p) const
{
  //return problemas.find(p) != problemas.end();
  return i_existe_problema(p, arbol_problemas);
}

void Sesion::consultar_hijos(const string& p, list<string>& ls) const
{
  i_consultar_hijos(p, arbol_problemas, ls);
}

int Sesion::numero_problemas(const BinTree<string>& a) const
{
  //return problemas.size();
  if (a.empty()) return 0;
  return 1 + numero_problemas(a.right()) + numero_problemas(a.left());
}

//Lectura

void Sesion::leer()
{
  cin >> id;
  leer_bintree_problema(arbol_problemas);
  //cerr << "hem llegit els problemes" << endl;
  problemas.clear();
  //cerr << "Peta al insertar?" << endl;
  insertar_problemas(problemas, arbol_problemas);
//  cerr << id << " --> ";
//  for(set<string>::const_iterator it = problemas.begin(); it != problemas.end(); ++it) cerr << " " << *it;
//  cerr << "   " << problemas.size() << endl;
  //cerr << "Doncs no xddd" << endl;
}

//Escriptura

void Sesion::escribir() const
{
  cout << id << " " << numero_problemas(arbol_problemas) << " ";
  escribir_bintree_problema(arbol_problemas);
  cout << endl;

  // cerr << id << " --> ";
  // for(set<string>::const_iterator it = problemas.begin(); it != problemas.end(); ++it) cerr << " " << *it;
  // cerr << "   " << problemas.size() << endl;
}
