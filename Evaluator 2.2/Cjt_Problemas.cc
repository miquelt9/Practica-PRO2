#include "Cjt_Problemas.hh"

//Adicional

void actualizar_map(map<pair<double,string>,Problema>& m, const map<string,Problema>& problemas)
{
  m.clear();
  for (map<string,Problema>::const_iterator it = problemas.begin();
  it != problemas.end(); ++it)
  {
    m.insert(make_pair(make_pair(it->second.consultar_ratio(), it->first), it->second));
  }
}

//Constructoras

Cjt_Problemas::Cjt_Problemas()
{
  modificado = true;
}

Cjt_Problemas::Cjt_Problemas(const Cjt_Problemas& cjt)
{
  modificado = true;
  problemas = cjt.problemas;
}

//Modificadoras

void Cjt_Problemas::agregar_problema(const Problema& p)
{
  modificado = true;
  problemas.insert(make_pair(p.consultar_id(), p));
}

void Cjt_Problemas::aumentar_envios_totales(const string& p)
{
  modificado = true;
  problemas.find(p)->second.aumentar_envios_totales();
}

void Cjt_Problemas::aumentar_envios_correctos(const string& p)
{
  modificado = true;
  problemas.find(p)->second.aumentar_envios_correctos();
}

//Consultoras

bool Cjt_Problemas::existe_problema(const string& p) const
{
  return problemas.find(p) != problemas.end();
}

int Cjt_Problemas::numero_problemas() const
{
  return problemas.size();
}

//Lectura

void Cjt_Problemas::leer()
{
  int n;
  cin >> n;
  Problema p;
  for (int i = 0; i < n; ++i)
  {
    p.leer();
    agregar_problema(p);
  }
}

//Escriptura

void Cjt_Problemas::escribir()
{
  if (modificado)
  {
    actualizar_map(ordenados, problemas);
    modificado = false;
  }
  for (map<pair<double,string>,Problema>::const_iterator it = ordenados.begin();
  it != ordenados.end(); ++it) it->second.escribir();
}

void Cjt_Problemas::escribir(const string& p) const
{
  problemas.find(p)->second.escribir();
}
