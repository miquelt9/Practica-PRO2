#include "Cjt_Usuarios.hh"
#include "Cjt_Cursos.hh"
#include "Cjt_Problemas.hh"
#include "Cjt_Sesiones.hh"

int main()
{
    //Lectura de la coleccion inicial de problemas

    //Lectura del repositorio inicial de sesiones

    //Lectura del conjunto de cursos

    //Lectura de los usuarios iniciales

    string comando;
    cin >> comando;

    while (comando != "fin")
    {
      if (comando == "nuevo_problema" or comando == "np")
      {
        string p;
        cin >> p;
        if (not Cjt_Problemas.existe_problema())
        {
          Cjt_Problemas.agregar_problema(p);
          cout << Cjt_Problemas.numero_problemas() << endl;
        }
        else cout << "ERROR" << endl;
      }
      else if (comando == "nueva_sesion" or comando == "ns")
      {
        Sesion sesion;
        sesion.leer();
        if (not Cjt_Sesiones.existe_sesion(sesion.consultar_id()))
        {
            Cjt_Sesiones.agregar_sesion(sesion);
            cout << Cjt_Sesiones.numero_sesiones() << endl;
        }
        else cout << "ERROR" << endl;
      }
      else if (comando == "nuevo_curso" or comando == "nc")
      {
        Curso curso;
        curso.leer();
        if (not problemas_repetidos(sesiones_curso(curso)))
        {
          Cjt_Cursos.agregar_curso(c);
          cout << curso.consultar_id() << endl;
        }
        else cout << "ERROR" << endl;
      }
      else if (comando == "alta_usuario" or comando == "a")
      {
        string u;
        cin >> u;
        if (not Cjt_Usuarios.existe_usuario(u))
        {
          Cjt_Usuarios.alta_usuario(u);
          cout << Cjt_Usuarios.numero_usuarios() << endl;
        }
        else cout << "ERROR" << endl;

      }
      else if (comando == "baja_usuario" or comando == "b")
      {
        string u;
        cin >> u;
        if (Cjt_Usuarios.existe_usuario(u))
        {
          Cjt_Usuarios.baja_usuario(u);
          cout << Cjt_Usuarios.numero_usuarios() << endl;
        }
        else cout << "ERROR" << endl;
      }
      else if (comando == "inscribir_curso" or comando == "i")
      {
        string u;
        int c;
        cin >> u >> c;
        if (Cjt_Usuarios.existe_usuario(u) and Cjt_Cursos.existe_curso(c)
            Cjt_Usuarios.consultar_usuario(u).curso_usuario() == c)
        {
          Cjt_Usuarios.consultar_usuario(u).inscribir_curso(c);
          cout << Cjt_Cursos.consultar_curso(c).numero_inscritos() << endl;
        }
        else cout << "ERROR" << endl;
      }
      else if (comando == "curso_usuario" or comando == "cu")
      {
        string u;
        cin >> u;
        cout << Cjt_Usuarios.consultar_usuario(u).curso_usuario() << endl;
      }
      else if (comando == "sesion_problema" or comando == "sp")
      {
        string p;
        int c;
        cin >> c >> p;
        if (not Cjt_Cursos.existe_curso(c))
        {
            string sesion = Cjt_Sesiones.sesion_problema(Cjt_Cursos.sesiones_curso(c), p);
            if (sesion != "-1") cout << sesion << endl;
            else cout << "ERROR" << endl;
        }
        else cout << "ERROR" << endl;

      }
      else if (comando == "problemas_resueltos" or comando == "pr")
      {}
      else if (comando == "problemas_enviables" or comando == "pe")
      {}
      else if (comando == "envio" or comando == "e")
      {}
      else if (comando == "listar_problemas" or comando == "lp")
      {
        Cjt_Problemas.escribir();
      }
      else if (comando == "escribir_problema" or comando == "ep")
      {
        string p;
        cin >> p;
        if (Cjt_Problemas.existe_problema(u))
        {
          Cjt_Problemas.consultar_problema(u).escribir();
        }
        else cout << "ERROR" << endl;
      }
      else if (comando == "listar_sesiones" or comando == "ls")
      {}
      else if (comando == "escribir_sesion" or comando == "es")
      {}
      else if (comando == "listar_cursos" or comando == "lc")
      {}
      else if (comando == "escribir_curso" or comando == "ec")
      {}
      else if (comando == "lsitar_usuarios" or comando == "lu")
      {}
      else if (comando == "escribir_usuario" or comando == "eu")
      {}
      else
      {} //Comando no válido
      cin >> comando;
    }
}
