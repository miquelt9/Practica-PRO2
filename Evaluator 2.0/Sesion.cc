#include "Sesion.hh"

//Adicional

void insertar_problemas(map<string, pair<string,string>>& prob, const BinTree<string>& a)
{
  pair<string,string> fills;
  if (not a.left().empty()) fills.first = a.left().value();
  if (not a.right().empty()) fills.second = a.right().value();

  prob.insert(make_pair(a.value(), fills));
  if(not a.left().empty()) insertar_problemas(prob, a.left());
  if(not a.right().empty()) insertar_problemas(prob, a.right());
}

//Constructoras

Sesion::Sesion()
{}

Sesion::Sesion(const Sesion& s)
{
  id = s.id;
  arbol_problemas = s.arbol_problemas;
  problemas = s.problemas;
}

Sesion::Sesion(const string& n)
{
  id = n;
}

//Modificadoras

void Sesion::contar_problemas(map<string,int>& m) const
{
  for (map<string,pair<string,string>>::const_iterator it = problemas.begin();
  it != problemas.end(); ++it)
  {
    m[it->first]++;
  }
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
  return problemas.find(p) != problemas.end();
}

void Sesion::consultar_hijos(const string& p, list<string>& ls) const
{
  pair<string,string> r = problemas.find(p)->second;
  if(not r.first.empty()) ls.push_back(r.first);
  if(not r.second.empty()) ls.push_back(r.second);
}

int Sesion::numero_problemas() const
{
  return problemas.size();
}

//Lectura

void Sesion::leer()
{
  problemas.clear();
  cin >> id;
  leer_bintree_problema(arbol_problemas);
  insertar_problemas(problemas, arbol_problemas);
}

//Escriptura

void Sesion::escribir() const
{
  cout << id << " " << problemas.size() << " ";
  escribir_bintree_problema(arbol_problemas);
  cout << endl;
}
