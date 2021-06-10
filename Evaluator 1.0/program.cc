#include "Cjt_Usuarios.hh"
#include "Cjt_Cursos.hh"
#include "Cjt_Problemas.hh"
#include "Cjt_Sesiones.hh"

int main()
{
    //Lectura de la coleccion inicial de problemas
    Cjt_Problemas coleccion_problemas;
    coleccion_problemas.leer();
    cerr << "LLEGIT PRBL!!!!!" << endl;

    //Lectura del repositorio inicial de sesiones
    Cjt_Sesiones repositorio_sesiones;
    repositorio_sesiones.leer();
    cerr << "LLEGIT SES!!!!!" << endl;


    //Lectura del conjunto de cursos
    Cjt_Cursos cursos;
    cursos.leer();
    cerr << "LLEGIT CRUS!!!!!" << endl;

    //Lectura de los usuarios iniciales
    Cjt_Usuarios usuarios;
    usuarios.leer();
    cerr << "LLEGIT USEER!!!!!" << endl;

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
        // Curso curso;
        // curso.leer(cursos.numero_cursos());
        // if (not curso.problemas_repetidos(curso.sesiones_curso(), repositorio_sesiones))
        // {
        //   cursos.agregar_curso(curso);
        //   cout << curso.consultar_id() << endl;
        // }
        // else cout << "error: el curso ya existe" << endl;
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
          usuarios.baja_usuario(u);
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
          if(not usuarios.acceder_usuario(u).en_un_curso())
          {
            if(cursos.existe_curso(c))
            {
              usuarios.acceder_usuario(u).inscribir_curso(c);
              cout << cursos.consultar_curso(c).numero_inscritos() << endl;
            }
            else cout << "error: el curso no existe" << endl;
          }
          else cout << "error: usuario inscrito en otro curso" << endl;
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
          cout << usuarios.acceder_usuario(u).curso_usuario() << endl;
        }
        else cout << "error: el usuario no existe";
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
            string sesion = repositorio_sesiones.sesion_problema(cursos.consultar_curso(c).sesiones_curso(), p);
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
        if (usuarios.existe_usuario(u)) usuarios.acceder_usuario(u).problemas_resueltos();
        else cout << "error: el usuario no existe" << endl;
      }
      else if (comando == "problemas_enviables" or comando == "pe")
      {
        string u;
        cin >> u;
        cout << " " << u << endl;
        if (usuarios.existe_usuario(u)) usuarios.acceder_usuario(u).problemas_enviables();
        else cout << "error: el usuario no existe" << endl;
      }
      else if (comando == "envio" or comando == "e")
      {
        string u, p;
        int r;
        cin >> u >> p >> r;
        usuarios.acceder_usuario(u).envio(p, r, coleccion_problemas);
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
          coleccion_problemas.acceder_problema(p).escribir();
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
          repositorio_sesiones.consultar_sesion(s).escribir();
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
          cursos.consultar_curso(c).escribir();
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
          usuarios.acceder_usuario(u).escribir();
        }
        else cout << "error: el usuario no existe" << endl;
      }
      else
      {
        cout << "error: comando no valido" << endl;
      }
      cin >> comando;
    }
}
