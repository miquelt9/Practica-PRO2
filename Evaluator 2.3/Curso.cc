#include "Curso.hh"

//Adicional

// Pre:  m és un map vacio
// Post: Se añaden al mapa el string de cada sesion como "key" i como "value"
//       la sesion a que pertenece
void generar_problema_sesion(map<string,string>& m, const list<string> sesions,
  const Cjt_Sesiones& cjt_ses)
{
  for (list<string>::const_iterator it = sesions.begin(); it != sesions.end(); ++it)
  {
    cjt_ses.problemas_sesion(m, *it);
  }
}

//Constructoras

Curso::Curso()
{}

Curso::Curso(const Curso& c)
{
  sesiones_del_curso = c.sesiones_del_curso;
  usuarios_registrados = c.usuarios_registrados;
  id = c.id;
  map_problema_sesion = c.map_problema_sesion;
  usuarios_completado = c.usuarios_completado;
}

//Modificadoras

void Curso::aumentar_registrados()
{
  ++usuarios_registrados;
}

void Curso::aumentar_completados(const string& u)
{
  usuarios_completado.insert(u);
}

void Curso::reducir_registrados()
{
  --usuarios_registrados;
}

//Consultoras

int Curso::consultar_id() const
{
  return id;
}

int Curso::numero_inscritos() const
{
  return usuarios_registrados;
}

bool Curso::problemas_repetidos(const Cjt_Sesiones& ses) const
{
  int n_prob = 0;
  for (list<string>::const_iterator it = sesiones_del_curso.begin();
  it != sesiones_del_curso.end(); ++it)
  {
    n_prob += ses.numero_problemas(*it);
  }
  return (int)map_problema_sesion.size() != n_prob;
}

void Curso::sesiones_curso(list<string>& ls) const
{
  ls = sesiones_del_curso;
}

string Curso::sesion_problema(const string& problema) const
{
  if (map_problema_sesion.find(problema) != map_problema_sesion.end())
  {
    return map_problema_sesion.find(problema)->second;
  }
  else return "-1";
}

//Lectura

void Curso::leer(int id, const Cjt_Sesiones& ses)
{
  sesiones_del_curso.clear();
  usuarios_registrados = 0;
  usuarios_completado.clear();
  map_problema_sesion.clear();
  this->id = id+1;
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; ++i)
  {
    cin >> s;
    sesiones_del_curso.push_back(s);
  }
  generar_problema_sesion(map_problema_sesion, sesiones_del_curso, ses);
}

//Escriptura

void Curso::escribir() const
{
  cout << " " << usuarios_completado.size() << " " << usuarios_registrados
  << " " << sesiones_del_curso.size() << " (";
  for (list<string>::const_iterator it = sesiones_del_curso.begin();
  it != sesiones_del_curso.end(); ++it)
  {
    if (it != sesiones_del_curso.begin()) cout << " ";
    cout << *it;
  }
  cout << ")" << endl;
}
