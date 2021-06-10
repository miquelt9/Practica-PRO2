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

void Usuario::envio(const string& p, const int& r, Cjt_Problemas& problemas, const Cjt_Sesiones& ses, Cjt_Cursos& cursos)
{
  enviables[p]++;
  problemas.aumentar_envios_totales(p);

  if (r == 1)
  {
    problemas.aumentar_envios_correctos(p);
    resueltos.insert(make_pair(p, enviables.find(p)->second));
    list<string> t;
    ses.agregar_hijos(ses.sesion_problema(cursos.sesiones_curso(curso),p), p, t);
    agregar_enviables(t, ses, cursos.sesiones_curso(curso));
    enviables.erase(p);
  }
  if (curso_terminado())
  {
    cursos.aumentar_completados(curso, id);
    terminar_curso();
  }
}

void Usuario::agregar_enviables(list<string>& ls, const Cjt_Sesiones& sesiones,
const list<string>& sesiones_curso)
{
  list<string>::const_iterator it = ls.begin();
  while (it != ls.end())
  {
    if (resueltos.find(*it) == resueltos.end()) //No se ha resuelto, ergo lo añadimos a enviables
    {
      enviables.insert(make_pair(*it,0));
    }
    else
    {
      sesiones.agregar_hijos(sesiones.sesion_problema(sesiones_curso, *it), *it, ls);
    }
    ++it;
  }
}

//Consultoras

string Usuario::consultar_id() const
{
  return id;
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

int Usuario::problemas_intentados() const
{
  int r = resueltos.size();
  map<string,int>::const_iterator it = enviables.begin();
  while (it != enviables.end())
  {
    if (it->second > 0) ++r;
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
  << problemas_intentados() << "," << curso << ")" << endl;
}
