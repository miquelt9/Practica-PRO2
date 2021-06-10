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

void Cjt_Cursos::aumentar_registrados(int c)
{
  cursos[c-1].aumentar_registrados();
}

void Cjt_Cursos::aumentar_completados(int c, const string& u)
{
  cursos[c-1].aumentar_completados(u);
}

void Cjt_Cursos::reducir_registrados(int c)
{
  cursos[c-1].reducir_registrados();
}

//Consultoras

bool Cjt_Cursos::existe_curso(int c)
{
  return c <= (int)cursos.size() and c > 0;
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

string Cjt_Cursos::sesion_problema(int c, const string& problema) const
{
  return cursos[c-1].sesion_problema(problema);
}


//Lectura

void Cjt_Cursos::leer(const Cjt_Sesiones& ses)
{
  int n;
  cin >> n;
  Curso c;
  for (int i = 0; i < n; ++i)
  {
    c.leer(cursos.size(), ses);
    cursos.push_back(c);
  }
}

//Escriptura

void Cjt_Cursos::escribir() const
{
  for (int i = 0; i < (int)cursos.size(); ++i) {
    cout << i+1;
    cursos[i].escribir();
  }
}

void Cjt_Cursos::escribir(int c) const
{
  cursos[c-1].escribir();
}
