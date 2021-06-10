#include "Problema.hh"

Problema::Problema()
{
  envios_totales = envios_correctos = 0;
}

Problema::Problema(const Problema& p)
{
  id = p.id;
  envios_totales = p.envios_totales;
  envios_correctos = p.envios_correctos;
}

Problema::Problema(const string& n)
{
  id = n;
  envios_totales = envios_correctos = 0;
}

//Modificadoras

void Problema::aumentar_envios_totales()
{
  ++envios_totales;
}

void Problema::aumentar_envios_correctos()
{
  ++envios_correctos;
}

//Consultoras

//bool Problema::se_puede_enviar() const
//{}

string Problema::consultar_id() const
{
  return id;
}

double Problema::consultar_ratio() const
{
  return (double)(1 + envios_totales)/(1 + envios_correctos);
}

int Problema::consultar_envios_totales() const
{
  return envios_totales;
}

int Problema::consultar_envios_correctos() const
{
  return envios_correctos;
}

//Lectura

void Problema::leer()
{
  cin >> id;
}

//Escriptura

void Problema::escribir() const
{
  cout << id << "(" << envios_totales << "," << envios_correctos << ","
  << consultar_ratio() << ")" << endl;
}
