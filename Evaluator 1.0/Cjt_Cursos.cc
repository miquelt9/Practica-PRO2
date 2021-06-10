#include "Cjt_Cursos.hh"

//Constructoras

Cjt_Cursos::Cjt_Cursos()
{}

Cjt_Cursos::Cjt_Cursos(const Cjt_Cursos& cjt)
{
  cursos = cjt.cursos;
}

//Modificadoras

void Cjt_Cursos::agregar_curso(const Curso& c)
{
  cursos.push_back(c);
}

//Consultoras

bool Cjt_Cursos::existe_curso(const int& c)
{
  return c >= 1 and c < cursos.size();
}

Curso Cjt_Cursos::consultar_curso(const int& c) const
{
  return cursos[c-1];
}

int Cjt_Cursos::numero_cursos() const
{
  return cursos.size();
}

//Lectura

void Cjt_Cursos::leer()
{
  int n;
  cin >> n;
  Curso c;
  cerr << "CURSOS SIZE = " << cursos.size() << endl;
  for (int i = 0; i < n; ++i)
  {
    c.leer(cursos.size()+1);
    cursos.push_back(c);
  }
  cerr << "CURSOS SIZE AFTER = " << cursos.size() << endl;
}

//Escriptura

void Cjt_Cursos::escribir() const
{
  for(int i = 0; i < cursos.size(); ++i) cursos[i].escribir();
}
