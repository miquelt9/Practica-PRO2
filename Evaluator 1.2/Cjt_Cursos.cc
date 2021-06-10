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

void Cjt_Cursos::aumentar_registrados(const int& c, const string& u)
{
  cursos[c-1].aumentar_registrados(u);
}

void Cjt_Cursos::aumentar_completados(const int& c, const string& u)
{
  cursos[c-1].aumentar_completados(u);
}

void Cjt_Cursos::reducir_registrados(const string& u)
{
  for (int i = 0; i < cursos.size(); ++i) cursos[i].reducir_registrados(u);
}

void Cjt_Cursos::reducir_completados(const string& u)
{
  for (int i = 0; i < cursos.size(); ++i) cursos[i].reducir_completados(u);
}

//Consultoras

bool Cjt_Cursos::existe_curso(const int& c)
{
  return c <= cursos.size() and c > 0;
}

int Cjt_Cursos::numero_cursos() const
{
  return cursos.size();
}

list<string> Cjt_Cursos::sesiones_curso(const int& c) const
{
  return cursos[c-1].sesiones_curso();
}

list<string> Cjt_Cursos::primeros_problemas(const int& c, const Cjt_Sesiones& sesiones) const
{
  list<string> r;
  list<string> ses = sesiones_curso(c);
  list<string>::const_iterator it = ses.begin();
  while (it != ses.end())
  {
    r.push_back(sesiones.primer_problema(*it));
    ++it;
  }
  return r;
}

int Cjt_Cursos::numero_usuarios(const int& c) const
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
    c.leer(cursos.size()+1);
    //cerr << "COURSE HAS ID: " << c.consultar_id() << endl;
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

void Cjt_Cursos::escribir(const int& c) const
{
  cursos[c-1].escribir();
}
