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

void Cjt_Cursos::aumentar_registrados(int c, const string& u)
{
  cursos[c-1].aumentar_registrados(u);
}

void Cjt_Cursos::aumentar_completados(int c, const string& u)
{
  cursos[c-1].aumentar_completados(u);
}

void Cjt_Cursos::reducir_registrados(const string& u, int c)
{
  cursos[c-1].reducir_registrados(u);
}

// void Cjt_Cursos::reducir_completados(const string& u)
// {
//   for (int i = 0; i < cursos.size(); ++i) cursos[i].reducir_completados(u);
// }

//Consultoras

bool Cjt_Cursos::existe_curso(int c)
{
  return c <= cursos.size() and c > 0;
}

int Cjt_Cursos::numero_cursos() const
{
  return cursos.size();
}

void Cjt_Cursos::sesiones_curso(int c, list<string>& ls) const
{
  cursos[c-1].sesiones_curso(ls);
}

int Cjt_Cursos::numero_usuarios(int c) const
{
  return cursos[c-1].numero_inscritos();
}

//Lectura

void Cjt_Cursos::leer()
{
  int n;
  cin >> n;
  Curso c;
  for (int i = 0; i < n; ++i)
  {
    c.leer(cursos.size());
    cursos.push_back(c);
  }
}

//Escriptura

void Cjt_Cursos::escribir() const
{
  for(int i = 0; i < cursos.size(); ++i) {
    cout << i+1;
    cursos[i].escribir();
  }
}

void Cjt_Cursos::escribir(int c) const
{
  cursos[c-1].escribir();
}
