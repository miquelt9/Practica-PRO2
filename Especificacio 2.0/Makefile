OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Problema.o Sesion.o Curso.o Usuario.o Cjt_Problemas.o Cjt_Sesiones.o Cjt_Cursos.o Cjt_Usuarios.o BinTreeIO.o
	g++ $(OPCIONS) -o program.exe program.o Problema.o Sesion.o Usuario.o Curso.o Cjt_Problemas.o Cjt_Sesiones.o Cjt_Cursos.o Cjt_Usuarios.o BinTreeIO.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Usuario.o: Usuario.cc Usuario.hh
	g++ $(OPCIONS) -c Usuario.cc

Problema.o: Problema.cc Problema.hh
	g++ $(OPCIONS) -c Problema.cc

Sesion.o: Sesion.cc Sesion.hh
	g++ $(OPCIONS) -c Sesion.cc

Curso.o: Curso.cc Curso.hh
	g++ $(OPCIONS) -c Curso.cc

Cjt_Problemas: Cjt_Problemas.cc Cjt_Problemas.hh
	g++ $(OPCIONS) -c Cjt_Problemas.cc

Cjt_Sesiones: Cjt_Sesiones.cc Cjt_Sesiones.hh
	g++ $(OPCIONS) -c Cjt_Sesiones.cc

Cjt_Cursos: Cjt_Cursos.cc Cjt_Cursos.hh
	g++ $(OPCIONS) -c Cjt_Cursos.cc

Cjt_Usuarios: Cjt_Usuarios.cc Cjt_Usuarios.hh
	g++ $(OPCIONS) -c Cjt_Usuarios.cc

BinTreeIO: BinTreeIO.cc BinTreeIO.hh
	g++ $(OPCIONS) -c BinTreeIO.cc

clean:
	rm -f *.exe *.o
