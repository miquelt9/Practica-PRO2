#include "Cjt_Sesiones.hh"

//Constructoras

Cjt_Sesiones::Cjt_Sesiones()
{}

Cjt_Sesiones::Cjt_Sesiones(const Cjt_Sesiones& cjt)
{
  sesiones = cjt.sesiones;
}

//Modificadoras

void Cjt_Sesiones::agregar_sesion(const Sesion& s)
{
  sesiones.insert(make_pair(s.consultar_id(), s));
}

//Consultoras

bool Cjt_Sesiones::existe_sesion(const string& s)
{
  return sesiones.find(s) != sesiones.end();
}

Sesion Cjt_Sesiones::consultar_sesion(const string& s) const
{
  return sesiones.find(s)->second;
}

int Cjt_Sesiones::numero_sesiones() const
{
  return sesiones.size();
}

string Cjt_Sesiones::sesion_problema(const list<string>& ls, const string& problema) const
{
  for (list<string>::const_iterator it = ls.begin(); it != ls.end(); ++it)
  {
    if (consultar_sesion(*it).existe_problema(problema)) return *it;
  }
  return "-1";
}

//Lectura

void Cjt_Sesiones::leer()
{
  int n;
  cin >> n;
  Sesion s;
  for (int i = 0; i < n; ++i)
  {
    s.leer();
    agregar_sesion(s);
  }
}

//Escriptura

void Cjt_Sesiones::escribir() const
{
  for (map<string,Sesion>::const_iterator it = sesiones.begin();
  it != sesiones.end(); ++it)
  {
    it->second.escribir();
  }
}
