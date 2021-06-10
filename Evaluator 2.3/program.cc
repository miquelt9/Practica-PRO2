/** @mainpage program.cc
    @brief Programa principal des de donde se llaman las diferentes funciones
           necessarias para cada uno de los comandos.
           Para implementar cada uno de los comandos se han utilizado diferentes
           modulos para cada uno de los propositos requeriodos.
*/

#include "Cjt_Usuarios.hh"

int main()
{
    Cjt_Problemas coleccion_problemas;
    coleccion_problemas.leer();

    Cjt_Sesiones repositorio_sesiones;
    repositorio_sesiones.leer();

    Cjt_Cursos cursos;
    cursos.leer(repositorio_sesiones);

    Cjt_Usuarios usuarios;
    usuarios.leer();

    string comando;
    cin >> comando;

    while (comando != "fin")
    {
      cout << "#" << comando;

      if (comando == "nuevo_problema" or comando == "np")
      {
        string p;
        cin >> p;
        cout << " " << p << endl;
        if (not coleccion_problemas.existe_problema(p))
        {
          coleccion_problemas.agregar_problema(p);
          cout << coleccion_problemas.numero_problemas() << endl;
        }
        else cout << "error: el problema ya existe" << endl;
      }

      else if (comando == "nueva_sesion" or comando == "ns")
      {
        Sesion sesion;
        sesion.leer();
        cout << " " << sesion.consultar_id() << endl;
        if (not repositorio_sesiones.existe_sesion(sesion.consultar_id()))
        {
            repositorio_sesiones.agregar_sesion(sesion);
            cout << repositorio_sesiones.numero_sesiones() << endl;
        }
        else cout << "error: la sesion ya existe" << endl;
      }

      else if (comando == "nuevo_curso" or comando == "nc")
      {
        Curso curso;
        curso.leer(cursos.numero_cursos(), repositorio_sesiones);
        cout << endl;
        if (not curso.problemas_repetidos(repositorio_sesiones))
        {
          cursos.agregar_curso(curso);
          cout << curso.consultar_id() << endl;
        }
        else cout << "error: curso mal formado" << endl;
      }

      else if (comando == "alta_usuario" or comando == "a")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (not usuarios.existe_usuario(u))
        {
          usuarios.alta_usuario(u);
          cout << usuarios.numero_usuarios() << endl;
        }
        else cout << "error: el usuario ya existe" << endl;
      }

      else if (comando == "baja_usuario" or comando == "b")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (usuarios.existe_usuario(u))
        {
          usuarios.baja_usuario(u, cursos);
          cout << usuarios.numero_usuarios() << endl;
        }
        else cout << "error: el usuario no existe" << endl;
      }

      else if (comando == "inscribir_curso" or comando == "i")
      {
        string u;
        int c;
        cin >> u >> c;
        cout << " " << u << " " << c << endl;
        if (usuarios.existe_usuario(u))
        {
          if (cursos.existe_curso(c))
          {
            if (not usuarios.en_un_curso(u))
            {
              usuarios.inscribir_curso(c, u, cursos, repositorio_sesiones);
              cout << cursos.numero_usuarios(c) << endl;
            }
            else cout << "error: usuario inscrito en otro curso" << endl;
          }
          else cout << "error: el curso no existe" << endl;
        }
        else cout << "error: el usuario no existe" << endl;
      }

      else if (comando == "curso_usuario" or comando == "cu")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (usuarios.existe_usuario(u))
        {
          cout << usuarios.curso_usuario(u) << endl;
        }
        else cout << "error: el usuario no existe" << endl;
      }

      else if (comando == "sesion_problema" or comando == "sp")
      {
        string p;
        int c;
        cin >> c >> p;
        cout << " " << c << " " << p << endl;
        if (cursos.existe_curso(c))
        {
          if(coleccion_problemas.existe_problema(p))
          {
            list<string> sesiones_curso;
            string sesion = cursos.sesion_problema(c, p);
            if (sesion != "-1") cout << sesion << endl;
            else cout << "error: el problema no pertenece al curso" << endl;
          }
          else cout << "error: el problema no existe" << endl;
        }
        else cout << "error: el curso no existe" << endl;
      }

      else if (comando == "problemas_resueltos" or comando == "pr")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (usuarios.existe_usuario(u)) usuarios.problemas_resueltos(u);
        else cout << "error: el usuario no existe" << endl;
      }

      else if (comando == "problemas_enviables" or comando == "pe")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (usuarios.existe_usuario(u))
        {
          if (usuarios.en_un_curso(u))
          {
            usuarios.problemas_enviables(u);
          }
          else cout << "error: usuario no inscrito en ningun curso" << endl;
        }
        else cout << "error: el usuario no existe" << endl;
      }

      else if (comando == "envio" or comando == "e")
      {
        string u, p;
        int r;
        cin >> u >> p >> r;
        cout << " " << u << " " << p << " " << r << endl;
        usuarios.envio(u, p, r, coleccion_problemas, repositorio_sesiones, cursos);
      }

      else if (comando == "listar_problemas" or comando == "lp")
      {
        cout << endl;
        coleccion_problemas.escribir();
      }

      else if (comando == "escribir_problema" or comando == "ep")
      {
        string p;
        cin >> p;
        cout << " " << p << endl;
        if (coleccion_problemas.existe_problema(p))
        {
          coleccion_problemas.escribir(p);
        }
        else cout << "error: el problema no existe" << endl;
      }

      else if (comando == "listar_sesiones" or comando == "ls")
      {
        cout << endl;
        repositorio_sesiones.escribir();
      }
      else if (comando == "escribir_sesion" or comando == "es")
      {
        string s;
        cin >> s;
        cout << " " << s << endl;
        if (repositorio_sesiones.existe_sesion(s))
        {
          repositorio_sesiones.escribir(s);
        }
        else cout << "error: la sesion no existe" << endl;
      }

      else if (comando == "listar_cursos" or comando == "lc")
      {
        cout << endl;
        cursos.escribir();
      }

      else if (comando == "escribir_curso" or comando == "ec")
      {
        int c;
        cin >> c;
        cout << " " << c << endl;
        if (cursos.existe_curso(c))
        {
          cout << c;
          cursos.escribir(c);
        }
        else cout << "error: el curso no existe" << endl;
      }

      else if (comando == "listar_usuarios" or comando == "lu")
      {
        cout << endl;
        usuarios.escribir();
      }

      else if (comando == "escribir_usuario" or comando == "eu")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (usuarios.existe_usuario(u))
        {
          usuarios.escribir(u);
        }
        else cout << "error: el usuario no existe" << endl;
      }
      cin >> comando;
    }
}
