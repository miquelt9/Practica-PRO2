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

void Cjt_Usuarios::baja_usuario(const string& u)
{
  usuarios.erase(u);
}

Usuario Cjt_Usuarios::acceder_usuario(const string& u)
{
  return usuarios.find(u)->second;
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
