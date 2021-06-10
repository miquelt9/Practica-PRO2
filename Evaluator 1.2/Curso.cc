#include "Curso.hh"

//Adicional

void i_problemas_repetidos(const BinTree<string>& a, map<string,int>& m)
{
  if(not a.empty())
  {
    m[a.value()]++;
    i_problemas_repetidos(a.left(), m);
    i_problemas_repetidos(a.right(), m);
  }
}

//Constructoras

Curso::Curso()
{}

Curso::Curso(const Curso& c)
{
  sesiones_del_curso = c.sesiones_del_curso;
  usuarios_registrados = c.usuarios_registrados;
}

//Modificadoras

void Curso::aumentar_registrados(const string& u)
{
  usuarios_registrados.insert(u);
}

void Curso::aumentar_completados(const string& u)
{
  usuarios_completado.insert(u);
}

void Curso::reducir_registrados(const string& u)
{
  usuarios_registrados.erase(u);
}

void Curso::reducir_completados(const string& u)
{
  usuarios_completado.erase(u);
}

//Consultoras

int Curso::consultar_id() const
{
  return id;
}

int Curso::numero_inscritos() const
{
  return usuarios_registrados.size();
}

// bool Curso::problemas_repetidos(const list<string>& ls, const Cjt_Sesiones& ses) const
// {
//   map<string,int> m;
//   for (list<string>::const_iterator it = ls.begin(); it != ls.end(); ++it)
//   {
//     Sesion s = ses.consultar_sesion(*it);
//     i_problemas_repetidos(s.consultar_prerequisitos(), m);
//   }
//   for (map<string,int>::const_iterator it = m.begin(); it != m.end(); ++it)
//   {
//     if (it->second > 1) return true;
//   }
//   return false;
// }

list<string> Curso::sesiones_curso() const
{
  return sesiones_del_curso;
}

//Lectura

void Curso::leer(const int& id)
{
  sesiones_del_curso.clear();
  usuarios_registrados.clear();
  usuarios_completado.clear();
  this->id = id;
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; ++i)
  {
    cin >> s;
    sesiones_del_curso.push_back(s);
  }
}

//Escriptura

void Curso::escribir() const
{
  cout << " " << usuarios_completado.size() << " " << usuarios_registrados.size()
  << " " << sesiones_del_curso.size() << " (";
  for (list<string>::const_iterator it = sesiones_del_curso.begin();
  it != sesiones_del_curso.end(); ++it)
  {
    if (it != sesiones_del_curso.begin()) cout << " ";
    cout << *it;
  }
  cout << ")" << endl;
}
