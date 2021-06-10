OPCIONS = -D_GLIBCXX_DEBUG -D_JUDGE_ -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

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

Cjt_Problemas.o: Cjt_Problemas.cc Cjt_Problemas.hh
	g++ $(OPCIONS) -c Cjt_Problemas.cc

Cjt_Sesiones.o: Cjt_Sesiones.cc Cjt_Sesiones.hh
	g++ $(OPCIONS) -c Cjt_Sesiones.cc

Cjt_Cursos.o: Cjt_Cursos.cc Cjt_Cursos.hh
	g++ $(OPCIONS) -c Cjt_Cursos.cc

Cjt_Usuarios.o: Cjt_Usuarios.cc Cjt_Usuarios.hh
	g++ $(OPCIONS) -c Cjt_Usuarios.cc

BinTreeIO.o: BinTreeIO.cc BinTreeIO.hh
	g++ $(OPCIONS) -c BinTreeIO.cc

clean:
	rm -f *.exe *.o

all:
	make clean
	make
	doxygen
	make tar

tar: Makefile Doxyfile program.cc BinTree.hh BinTreeIO.hh BinTreeIO.cc Usuario.hh Usuario.cc Cjt_Usuarios.hh Cjt_Usuarios.cc Curso.hh Curso.cc Cjt_Cursos.hh Cjt_Cursos.cc Sesion.hh Sesion.cc Cjt_Sesiones.hh Cjt_Sesiones.cc Problema.hh Problema.cc Cjt_Problemas.hh Cjt_Problemas.cc
	tar -cvf program.tar Makefile Doxyfile program.cc BinTree.hh BinTreeIO.hh BinTreeIO.cc Usuario.hh Usuario.cc Cjt_Usuarios.hh Cjt_Usuarios.cc Curso.hh Curso.cc Cjt_Cursos.hh Cjt_Cursos.cc Sesion.hh Sesion.cc Cjt_Sesiones.hh Cjt_Sesiones.cc Problema.hh Problema.cc Cjt_Problemas.hh Cjt_Problemas.cc
