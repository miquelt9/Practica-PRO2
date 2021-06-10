#include "Cjt_Usuarios.hh"

//Constructoras

Cjt_Usuarios::Cjt_Usuarios()
{}

Cjt_Usuarios::Cjt_Usuarios(const Cjt_Usuarios& cjt)
{
  usuarios = cjt.usuarios;
}

//Modificadoras

void Cjt_Usuarios::alta_usuario(const string& u)
{
  Usuario user(u);
  usuarios.insert(make_pair(u, user));
}

void Cjt_Usuarios::alta_usuario(const Usuario& u)
{
  usuarios.insert(make_pair(u.consultar_id(),u));
}

void Cjt_Usuarios::baja_usuario(const string& u, Cjt_Cursos& cursos)
{
  int c = usuarios.find(u)->second.curso_usuario();
  if (c != 0) cursos.reducir_registrados(u, c);
  usuarios.erase(u);
}

void Cjt_Usuarios::inscribir_curso(int c, const string& u, Cjt_Cursos& cursos,
  const Cjt_Sesiones& sesiones)
{
  Usuario user = usuarios.find(u)->second;
  cursos.aumentar_registrados(c, u);
  user.inscribir_curso(c);

  list<string> ls;
  cursos.sesiones_curso(c, ls);
  vector<string> ses_completadas;
  user.sesiones_completadas(ses_completadas);
  for (int i = 0; i < ses_completadas.size(); ++i) ls.remove(ses_completadas[i]);
  list<string> primeros_problemas;
  sesiones.primeros_problemas(ls, primeros_problemas);
  user.agregar_enviables(primeros_problemas, sesiones, ls);

  if (user.curso_terminado())
  {
    cursos.aumentar_completados(user.curso_usuario(), u);
    user.terminar_curso();
  }
  swap(user, usuarios.find(u)->second);
}

void Cjt_Usuarios::envio(const string& u, const string& p, int r, Cjt_Problemas& problemas,
const Cjt_Sesiones& ses, Cjt_Cursos& cursos)
{
  usuarios.find(u)->second.envio(p, r, problemas, ses, cursos);
}

//Consultoras

bool Cjt_Usuarios::existe_usuario(const string& u) const
{
  return usuarios.find(u) != usuarios.end();
}

int Cjt_Usuarios::numero_usuarios() const
{
  return usuarios.size();
}

bool Cjt_Usuarios::en_un_curso(const string& u) const
{
  return usuarios.find(u)->second.curso_usuario() != 0;
}

int Cjt_Usuarios::curso_usuario(const string& u) const
{
  return usuarios.find(u)->second.curso_usuario();
}

void Cjt_Usuarios::problemas_resueltos(const string& u) const
{
  usuarios.find(u)->second.problemas_resueltos();
}

void Cjt_Usuarios::problemas_enviables(const string& u) const
{
  usuarios.find(u)->second.problemas_enviables();
}

//Lectura

void Cjt_Usuarios::leer()
{
  int n;
  cin >> n;
  Usuario u;
  for (int i = 0; i < n; ++i)
  {
    u.leer();
    alta_usuario(u);
  }
}

//Escriptura

void Cjt_Usuarios::escribir() const
{
  map<string,Usuario>::const_iterator it = usuarios.begin();
  while (it != usuarios.end())
  {
    it->second.escribir();
    ++it;
  }
}

void Cjt_Usuarios::escribir(const string& u) const
{
  usuarios.find(u)->second.escribir();
}
