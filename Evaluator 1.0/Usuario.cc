#include "Usuario.hh"

//Constructoras

Usuario::Usuario()
{
  curso = 0;
}

Usuario::Usuario(const Usuario& u)
{
  id = u.id;
  curso = u.curso;
  enviables = u.enviables;
  resueltos = u.resueltos;
}

Usuario::Usuario(const string& n)
{
  id = n;
  curso = 0;
}

// Modificadoras

void Usuario::inscribir_curso(const int& n)
{
  curso = n;
}

void Usuario::terminar_curso()
{
  curso = 0;
}

void Usuario::envio(const string& p, const int& r, Cjt_Problemas& problemas)
{
  if (r == 0)
  {
    enviables[p]++;
    problemas.acceder_problema(p).aumentar_envios_totales();
  }
  else
  {
    problemas.acceder_problema(p).aumentar_envios_totales();
    problemas.acceder_problema(p).aumentar_envios_correctos();
    resueltos.insert(make_pair(p,enviables.find(p)->second));
    enviables.erase(p);
  }
}

//Consultoras

string Usuario::consultar_id() const
{
  return id;
}

bool Usuario::en_un_curso() const
{
  return curso != 0;
}

int Usuario::curso_usuario() const
{
  return curso;
}

void Usuario::problemas_resueltos() const
{
  for (map<string,int>::const_iterator it = resueltos.begin();
  it != resueltos.end(); ++it)
  {
    cout << it->first << "(" << it->second << ")" << endl;
  }
}

void Usuario::problemas_enviables() const
{
  for (map<string,int>::const_iterator it = enviables.begin();
  it != enviables.end(); ++it)
  {
    cout << it->first << "(" << it->second << ")" << endl;
  }
}

bool Usuario::curso_terminado() const
{
  return enviables.size() == 0;
}

int Usuario::envios_totales() const
{
  int r = 0;
  map<string,int>::const_iterator it;
  it = enviables.begin();
  while (it != enviables.end())
  {
    r += it->second;
    ++it;
  }
  it = resueltos.begin();
  while (it != resueltos.end())
  {
    r += it->second;
    ++it;
  }
  return r;
}

//Lectura

void Usuario::leer()
{
  cin >> id;
}

//Escriptura

void Usuario::escribir() const
{
  cout << id << "(" << envios_totales() << "," << resueltos.size() << ","
  << resueltos.size() + enviables.size() << "," << curso << ")" << endl;
}
