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

void Cjt_Cursos::alta_registrados(const int& c)
{
  cursos[c-1].alta_registrados();
}

void Cjt_Cursos::alta_completados(const int& c)
{
  cursos[c-1].alta_completados();
}

void Cjt_Cursos::baja_registrados(const int& c)
{
  cursos[c-1].baja_registrados();
}

void Cjt_Cursos::baja_completados(const int& c)
{
  cursos[c-1].baja_completados();
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
