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

void Cjt_Sesiones::contar_problemas(map<string,int>& m, const string& s) const
{
  sesiones.find(s)->second.contar_problemas(m);
}

//Consultoras

bool Cjt_Sesiones::existe_sesion(const string& s) const
{
  return sesiones.find(s) != sesiones.end();
}

int Cjt_Sesiones::numero_sesiones() const
{
  return sesiones.size();
}

void Cjt_Sesiones::agregar_hijos(const string& s, const string& p, list<string>& ls) const
{
  sesiones.find(s)->second.consultar_hijos(p, ls);
}

string Cjt_Sesiones::primer_problema(const string& s) const
{
  return sesiones.find(s)->second.consultar_primer_problema();
}

bool Cjt_Sesiones::existe_problema(const string& s, const string& p) const
{
  return sesiones.find(s)->second.existe_problema(p);
}

void Cjt_Sesiones::primeros_problemas(const list<string>& ls, list<string>&
   primeros_problemas) const
{
  for (list<string>::const_iterator it = ls.begin(); it != ls.end(); ++it)
  {
    primeros_problemas.push_back(primer_problema(*it));
  }
}

void Cjt_Sesiones::problemas_sesion(map<string,string>& m, const string& s) const
{
  sesiones.find(s)->second.problemas_sesion(m);
}

int Cjt_Sesiones::numero_problemas(const string& s) const
{
  return sesiones.find(s)->second.numero_problemas();
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

void Cjt_Sesiones::escribir(const string& s) const
{
  sesiones.find(s)->second.escribir();
}
